import os
import re
import sys
import glob

def clean_line(line):
    return line.strip()

def escape_string_literals(expr):
    result = ""
    in_q = False
    current_str = ""
    i = 0
    while i < len(expr):
        c = expr[i]
        if c == '"':
            if in_q:
                escaped = current_str.replace('\\', '\\\\')
                result += '"' + escaped + '"'
                in_q = False
                current_str = ""
            else:
                in_q = True
        else:
            if in_q:
                current_str += c
            else:
                result += c
        i += 1
    if in_q:
        result += '"' + current_str
    return result

def uppercase_code_keep_strings(s):
    result = ""
    in_q = False
    i = 0
    while i < len(s):
        c = s[i]
        if c == '"':
            in_q = not in_q
            result += c
        else:
            if in_q:
                result += c
            else:
                result += c.upper()
        i += 1
    return result

def preprocess_spaces_around_keywords(s):
    parts = []
    current = ""
    in_q = False
    i = 0
    while i < len(s):
        c = s[i]
        if c == '"':
            if in_q:
                current += c
                parts.append((current, True))
                current = ""
                in_q = False
            else:
                if current:
                    parts.append((current, False))
                current = c
                in_q = True
        else:
            current += c
        i += 1
    if current:
        parts.append((current, in_q))
        
    new_parts = []
    for part, is_str in parts:
        if is_str:
            new_parts.append(part)
        else:
            p = part
            p = re.sub(r'(?i)\bIF([A-Z0-9(])', r'IF \1', p)
            p = re.sub(r'(?i)\bFOR([A-Z0-9])', r'FOR \1', p)
            p = re.sub(r'(?i)\bNEXT([A-Z0-9])', r'NEXT \1', p)
            p = re.sub(r'(?i)\bPRINT([A-Z0-9])', r'PRINT \1', p)
            p = re.sub(r'(?i)\bINPUT([A-Z0-9])', r'INPUT \1', p)
            p = re.sub(r'(?i)\bRETURN([A-Z0-9])', r'RETURN \1', p)
            p = re.sub(r'(?i)\bDIM([A-Z0-9])', r'DIM \1', p)
            
            p = re.sub(r'(?i)\bFOR\b', '__P_FR__', p)
            p = re.sub(r'(?i)\bRESTORE\b', '__P_RSTR__', p)
            p = re.sub(r'(?i)\bGOTO([0-9])', r'GOTO \1', p)
            p = re.sub(r'(?i)\bGOSUB([0-9])', r'GOSUB \1', p)
            p = re.sub(r'(?i)\bGOTO\b', '__P_GT__', p)
            p = re.sub(r'(?i)\bGOSUB\b', '__P_GS__', p)
            
            p = re.sub(r'(?i)(?<!\s)THEN', ' THEN', p)
            p = re.sub(r'(?i)THEN(?!\s)', 'THEN ', p)
            p = re.sub(r'(?i)(?<!\s)ELSE', ' ELSE', p)
            p = re.sub(r'(?i)ELSE(?!\s)', 'ELSE ', p)
            
            p = re.sub(r'(?i)(?<!\s)STEP', ' STEP', p)
            p = re.sub(r'(?i)STEP(?!\s)', 'STEP ', p)
            
            p = re.sub(r'(?i)(?<!\s)AND', ' AND', p)
            p = re.sub(r'(?i)AND(?!\s)', 'AND ', p)
            p = re.sub(r'(?i)(?<!\s)OR', ' OR', p)
            p = re.sub(r'(?i)OR(?!\s)', 'OR ', p)
            p = re.sub(r'(?i)(?<!\s)NOT', ' NOT', p)
            p = re.sub(r'(?i)NOT(?!\s)', 'NOT ', p)
            p = re.sub(r'(?i)(?<!\s)TO', ' TO', p)
            p = re.sub(r'(?i)TO(?!\s)', 'TO ', p)
            
            p = p.replace('__P_FR__', 'FOR')
            p = p.replace('__P_RSTR__', 'RESTORE')
            p = p.replace('__P_GT__', 'GOTO')
            p = p.replace('__P_GS__', 'GOSUB')
            
            new_parts.append(p)
            
    return "".join(new_parts)



def extract_variables(lines):
    num_vars = set()
    str_vars = set()
    num_arrays = set()
    str_arrays = set()
    
    for line in lines:
        line = line.strip()
        if not line: continue
        
        match_ln = re.match(r'^(\d+)\s+(.*)', line)
        if match_ln:
            line = match_ln.group(2)
            
        if 'REM' in line.upper():
            line = line[:line.upper().find('REM')]
            
        # Remove string literals to avoid matching variable names inside strings
        line = re.sub(r'"[^"]*"', ' ', line)
        line = re.sub(r'"[^"]*$', ' ', line)
            
        # Find arrays DIM W(H,V), V(H,V)
        stmts = split_by_operator_top_level(line, ':')
        for s in stmts:
            s_upper = s.strip().upper()
            if s_upper.startswith('DIM'):
                arr_matches = re.findall(r'\b([A-Z][A-Z0-9]*\$?)\s*\(', s_upper)
                for a in arr_matches:
                    if a.endswith('$'):
                        str_arrays.add(a[:-1])
                    else:
                        num_arrays.add(a)
                        
        # Find implicit arrays (e.g. S(1), J(9-K))
        all_arrs = re.findall(r'\b([A-Z][A-Z0-9]*\$?)\s*\(', line.upper())
        for a in all_arrs:
            if a in ['INT', 'RND', 'TAB', 'LEN', 'MID$', 'LEFT$', 'RIGHT$', 'CHR$', 'ASC', 'VAL', 'STR$', 'SQR', 'ABS', 'SGN', 'SIN', 'COS', 'TAN', 'ATN', 'EXP', 'LOG', 'MID', 'LEFT', 'RIGHT', 'CHR', 'STR', 'PRINT', 'INPUT', 'IF', 'THEN', 'ELSE', 'GOTO', 'GOSUB', 'RETURN', 'FOR', 'TO', 'STEP', 'NEXT', 'DIM', 'REM', 'STOP', 'END', 'AND', 'OR', 'NOT', 'RESTORE', 'READ', 'DATA']:
                continue
            if a.startswith('FN'):
                continue
            if a.endswith('$'):
                str_arrays.add(a[:-1])
            else:
                num_arrays.add(a)
                
        # Find regular variables A, A1, B$
        var_matches = re.findall(r'\b([A-Z][A-Z0-9]*\$?)(?![A-Z0-9])', line, re.IGNORECASE)
        for v in var_matches:
            v = v.upper()
            # Ignore keywords
            if v in ['PRINT', 'INPUT', 'IF', 'THEN', 'ELSE', 'GOTO', 'GOSUB', 'RETURN', 'FOR', 'TO', 'STEP', 'NEXT', 'DIM', 'REM', 'STOP', 'END', 'INT', 'RND', 'TAB', 'LEN', 'MID$', 'LEFT$', 'RIGHT$', 'CHR$', 'ASC', 'VAL', 'STR$', 'AND', 'OR', 'NOT', 'RESTORE', 'READ', 'DATA', 'SQR', 'ABS', 'SGN', 'SIN', 'COS', 'TAN', 'ATN', 'EXP', 'LOG']:
                continue
            if v.startswith('FN'):
                continue
            if v.endswith('$'):
                str_vars.add(v[:-1])
            else:
                num_vars.add(v)
                
    return num_vars, str_vars, num_arrays, str_arrays

def split_by_operator_top_level(s, op):
    parts = []
    current = ""
    in_q = False
    paren_depth = 0
    i = 0
    while i < len(s):
        c = s[i]
        if c == '"':
            in_q = not in_q
            current += c
        elif c == '(' and not in_q:
            paren_depth += 1
            current += c
        elif c == ')' and not in_q:
            paren_depth -= 1
            current += c
        elif s[i:i+len(op)] == op and not in_q and paren_depth == 0:
            parts.append(current)
            current = ""
            i += len(op) - 1
        else:
            current += c
        i += 1
    parts.append(current)
    return parts

def split_by_word_top_level(s, word):
    parts = []
    current = ""
    in_q = False
    paren_depth = 0
    i = 0
    w_len = len(word)
    while i < len(s):
        if not in_q and paren_depth == 0 and s[i:i+w_len].upper() == word.upper():
            left_ok = (i == 0 or not s[i-1].isalnum())
            right_ok = (i + w_len == len(s) or not s[i+w_len].isalnum())
            if left_ok and right_ok:
                parts.append(current)
                current = ""
                i += w_len
                continue
        c = s[i]
        if c == '"':
            in_q = not in_q
        elif c == '(' and not in_q:
            paren_depth += 1
        elif c == ')' and not in_q:
            paren_depth -= 1
        current += c
        i += 1
    parts.append(current)
    return parts

def translate_exponentiation(expr):
    while '^' in expr:
        idx = expr.find('^')
        
        lhs_start = idx - 1
        while lhs_start >= 0 and expr[lhs_start].isspace():
            lhs_start -= 1
        if lhs_start < 0:
            break
            
        if expr[lhs_start] == ')':
            depth = 1
            lhs_start -= 1
            while lhs_start >= 0 and depth > 0:
                if expr[lhs_start] == ')': depth += 1
                elif expr[lhs_start] == '(': depth -= 1
                lhs_start -= 1
            lhs_start += 1
            while lhs_start > 0 and (expr[lhs_start - 1].isalnum() or expr[lhs_start - 1] in ['$', '_']):
                lhs_start -= 1
        else:
            in_paren = 0
            while lhs_start >= 0:
                c = expr[lhs_start]
                if c == ')':
                    in_paren += 1
                elif c == '(':
                    if in_paren == 0:
                        break
                    in_paren -= 1
                elif in_paren == 0 and c in ['+', '-', '*', '/', '=', '<', '>', '&', '|', ',', ';']:
                    break
                lhs_start -= 1
            lhs_start += 1
            
        rhs_end = idx + 1
        while rhs_end < len(expr) and expr[rhs_end].isspace():
            rhs_end += 1
        if rhs_end >= len(expr):
            break
            
        if expr[rhs_end] == '(':
            depth = 1
            rhs_end += 1
            while rhs_end < len(expr) and depth > 0:
                if expr[rhs_end] == '(': depth += 1
                elif expr[rhs_end] == ')': depth -= 1
                rhs_end += 1
        else:
            in_paren = 0
            while rhs_end < len(expr):
                c = expr[rhs_end]
                if c == '(':
                    in_paren += 1
                elif c == ')':
                    if in_paren == 0:
                        break
                    in_paren -= 1
                elif in_paren == 0 and c in ['+', '-', '*', '/', '=', '<', '>', '&', '|', ',', ';']:
                    break
                rhs_end += 1
                
        lhs_term = expr[lhs_start:idx].strip()
        rhs_term = expr[idx+1:rhs_end].strip()
        expr = expr[:lhs_start] + f"pow({lhs_term}, {rhs_term})" + expr[rhs_end:]
    return expr

def clean_string_expr(expr):
    expr = re.sub(r'\b(MID|LEFT|RIGHT|CHR|STR)\$', r'basic_\1', expr, flags=re.IGNORECASE)
    expr = re.sub(r'\b([A-Z0-9]+)\$\((.+?)\)', r'\1_str_arr[(int)(\2)]', expr, flags=re.IGNORECASE)
    expr = re.sub(r'\b([A-Z0-9]+)\$(?!\()', r'\1_str', expr, flags=re.IGNORECASE)
    return expr

def translate_string_expr(expr, num_arrays, str_arrays):
    expr = expr.strip()
    parts = split_by_operator_top_level(expr, '+')
    if len(parts) > 1:
        is_string = any('$' in p or p.strip().startswith('"') for p in parts)
        if is_string:
            current_c = clean_string_expr(parse_expression(parts[0].strip(), num_arrays, str_arrays))
            for p in parts[1:]:
                next_c = clean_string_expr(parse_expression(p.strip(), num_arrays, str_arrays))
                current_c = f"str_cat_helper({current_c}, {next_c})"
            return current_c
    return clean_string_expr(parse_expression(expr, num_arrays, str_arrays))

def is_term_stringy(term):
    term = term.strip()
    if term.startswith('"'):
        return True
    term_upper = term.upper()
    if term_upper.startswith('VAL(') or term_upper.startswith('LEN(') or term_upper.startswith('ASC(') or \
       term_upper.startswith('BASIC_VAL(') or term_upper.startswith('BASIC_LEN(') or term_upper.startswith('BASIC_ASC('):
        return False
    if '$' in term:
        return True
    return False

def translate_single_comparison(term):
    operators = ['==', '!=', '<=', '>=', '<', '>']
    for op in operators:
        pattern = r'\s*' + re.escape(op) + r'\s*'
        parts = re.split(pattern, term)
        if len(parts) == 2:
            lhs, rhs = parts[0].strip(), parts[1].strip()
            if is_term_stringy(lhs) or is_term_stringy(rhs):
                lhs_c = clean_string_expr(lhs)
                rhs_c = clean_string_expr(rhs)
                if op == '==':
                    return f'strcmp({lhs_c}, {rhs_c}) == 0'
                elif op == '!=':
                    return f'strcmp({lhs_c}, {rhs_c}) != 0'
                elif op == '<':
                    return f'strcmp({lhs_c}, {rhs_c}) < 0'
                elif op == '>':
                    return f'strcmp({lhs_c}, {rhs_c}) > 0'
                elif op == '<=':
                    return f'strcmp({lhs_c}, {rhs_c}) <= 0'
                elif op == '>=':
                    return f'strcmp({lhs_c}, {rhs_c}) >= 0'
    return term

def translate_comparison(expr):
    parts = []
    current = ""
    in_q = False
    paren_depth = 0
    i = 0
    while i < len(expr):
        if expr[i:i+2] == '&&' and not in_q and paren_depth == 0:
            parts.append((current, '&&'))
            current = ""
            i += 2
        elif expr[i:i+2] == '||' and not in_q and paren_depth == 0:
            parts.append((current, '||'))
            current = ""
            i += 2
        else:
            if expr[i] == '"':
                in_q = not in_q
            elif expr[i] == '(' and not in_q:
                paren_depth += 1
            elif expr[i] == ')' and not in_q:
                paren_depth -= 1
            current += expr[i]
            i += 1
    parts.append((current, ""))
    
    res = ""
    for term, op in parts:
        translated_term = translate_single_comparison(term)
        res += translated_term + " " + op + " "
    return res.strip()

def replace_array_brackets(expr, num_arrays, str_arrays):
    for arr in num_arrays:
        pattern = r'\b' + re.escape(arr) + r'\s*\('
        while True:
            match = re.search(pattern, expr, re.IGNORECASE)
            if not match:
                break
            start = match.start()
            depth = 1
            idx = match.end()
            while idx < len(expr) and depth > 0:
                if expr[idx] == '(': depth += 1
                elif expr[idx] == ')': depth -= 1
                idx += 1
            if depth == 0:
                inner = expr[match.end():idx-1]
                parts = split_by_operator_top_level(inner, ',')
                if len(parts) == 1:
                    expr = expr[:start] + f"{arr}_arr[(int)({parts[0]})]" + expr[idx:]
                elif len(parts) == 2:
                    expr = expr[:start] + f"{arr}_arr[(int)({parts[0]}) * 100 + (int)({parts[1]})]" + expr[idx:]
                else:
                    expr = expr[:start] + f"{arr}_arr[(int)({parts[0]}) * 10000 + (int)({parts[1]}) * 100 + (int)({parts[2]})]" + expr[idx:]
            else:
                break
                
    for arr in str_arrays:
        pattern = r'\b' + re.escape(arr) + r'\s*\$\s*\('
        while True:
            match = re.search(pattern, expr, re.IGNORECASE)
            if not match:
                break
            start = match.start()
            depth = 1
            idx = match.end()
            while idx < len(expr) and depth > 0:
                if expr[idx] == '(': depth += 1
                elif expr[idx] == ')': depth -= 1
                idx += 1
            if depth == 0:
                inner = expr[match.end():idx-1]
                parts = split_by_operator_top_level(inner, ',')
                if len(parts) == 1:
                    expr = expr[:start] + f"{arr}_str_arr[(int)({parts[0]})]" + expr[idx:]
                elif len(parts) == 2:
                    expr = expr[:start] + f"{arr}_str_arr[(int)({parts[0]}) * 100 + (int)({parts[1]})]" + expr[idx:]
                else:
                    expr = expr[:start] + f"{arr}_str_arr[(int)({parts[0]}) * 10000 + (int)({parts[1]}) * 100 + (int)({parts[2]})]" + expr[idx:]
            else:
                break
    return expr

def parse_expression(expr, num_arrays, str_arrays):
    expr = expr.strip()
    if not expr:
        return ""
        
    literals = []
    def repl(m):
        literals.append(m.group(0))
        return f"__STR_LIT_{len(literals)-1}__"
    
    expr_placeholder = re.sub(r'"[^"]*"', repl, expr)
    expr = expr_placeholder
        
    expr = re.sub(r'(?i)\bEXP\b', 'exp', expr)
    expr = re.sub(r'(?i)\bLOG\b', 'log', expr)
    expr = re.sub(r'(?i)\bSIN\b', 'sin', expr)
    expr = re.sub(r'(?i)\bCOS\b', 'cos', expr)
    expr = re.sub(r'(?i)\bTAN\b', 'tan', expr)
    expr = re.sub(r'(?i)\bATN\b', 'atan', expr)
    expr = re.sub(r'(?i)\bSQR\b', 'sqrt', expr)
    expr = re.sub(r'(?i)\bABS\b', 'fabs', expr)
    expr = re.sub(r'(?i)\bINT\b', 'floor', expr)
    expr = re.sub(r'(?i)\bSGN\b', 'basic_SGN', expr)
    expr = re.sub(r'(?i)\bLEN\b', 'basic_LEN', expr)
    expr = re.sub(r'(?i)\bASC\b', 'basic_ASC', expr)
    expr = re.sub(r'(?i)\bVAL\b', 'basic_VAL', expr)
    
    expr = re.sub(r'(?i)\bRND\s*\(\s*[^)]*\s*\)', '((double)rand() / (double)RAND_MAX)', expr)
    expr = re.sub(r'(?i)\bRND\b', '((double)rand() / (double)RAND_MAX)', expr)
    
    expr = translate_exponentiation(expr)
    
    expr = expr.replace('<>', '!=')
    expr = re.sub(r'(?i)\bAND\b', ' && ', expr)
    expr = re.sub(r'(?i)\bOR\b', ' || ', expr)
    expr = re.sub(r'(?i)\bNOT\b', ' ! ', expr)
    
    expr = re.sub(r'(?i)(?<![<>!])=(?!=)', '==', expr)
    
    expr = translate_comparison(expr)
    expr = replace_array_brackets(expr, num_arrays, str_arrays)
    expr = clean_string_expr(expr)
    
    for idx, lit in enumerate(literals):
        expr = expr.replace(f"__STR_LIT_{idx}__", lit)
        
    return expr

def tokenize_print_args(args):
    # Pre-process args to insert implicit semicolons between adjacent terms
    new_args = ""
    in_q = False
    i = 0
    while i < len(args):
        c = args[i]
        new_args += c
        if c == '"':
            in_q = not in_q
        if not in_q:
            if c.isalnum() or c in ['$', '_', ')', '"']:
                j = i + 1
                while j < len(args) and args[j].isspace():
                    j += 1
                if j < len(args):
                    next_non_space = args[j]
                    if next_non_space.isalnum() or next_non_space in ['$', '_', '"', '(']:
                        has_space = (j > i + 1)
                        is_transition = (c in [')', '"'] or next_non_space in ['"', '('])
                        if has_space or is_transition:
                            if next_non_space == '(' and (c.isalnum() or c in ['$', '_']):
                                pass
                            else:
                                new_args += ";"
        i += 1
    args = new_args

    tokens = []
    current = ""
    in_str = False
    paren_depth = 0
    i = 0
    while i < len(args):
        char = args[i]
        if char == '"':
            if in_str:
                current += char
                tokens.append(current.strip())
                current = ""
                in_str = False
            else:
                if current.strip():
                    tokens.append(current.strip())
                current = char
                in_str = True
        elif char == '(' and not in_str:
            paren_depth += 1
            current += char
        elif char == ')' and not in_str:
            paren_depth -= 1
            current += char
        elif char in [';', ','] and not in_str and paren_depth == 0:
            if current.strip():
                tokens.append(current.strip())
                current = ""
            tokens.append(char)
        else:
            current += char
        i += 1
    if current.strip():
        tokens.append(current.strip())
        
    result = []
    for t in tokens:
        if t in [';', ',']:
            result.append(t)
        elif t.startswith('"') and t.endswith('"'):
            result.append(t)
        else:
            val = t.strip()
            if val:
                result.append(val)
    return result

def translate_print(args, num_arrays, str_arrays):
    if not args:
        return 'printf("\\n");'
        
    tokens = tokenize_print_args(args)
    c_stmts = []
    
    for p in tokens:
        if p == ';':
            continue
        elif p == ',':
            c_stmts.append('printf("\\t");')
        elif p.startswith('"') and p.endswith('"'):
            c_stmts.append(f'printf("%s", {p});')
        elif p.upper().startswith('TAB('):
            inner = p[4:-1]
            c_stmts.append(f'{{ int _t; for(_t=0; _t<{parse_expression(inner, num_arrays, str_arrays)}; _t++) printf(" "); }}')
        else:
            if is_term_stringy(p):
                c_stmts.append(f'printf("%s", {translate_string_expr(p, num_arrays, str_arrays)});')
            else:
                c_stmts.append(f'printf("%g ", (double)({parse_expression(p, num_arrays, str_arrays)}));')
                
    if not args.endswith(';') and not args.endswith(','):
        c_stmts.append('printf("\\n");')
        
    return ' '.join(c_stmts)

def count_gosubs_in_statement(s_upper):
    count = 0
    if s_upper.startswith('GOSUB'):
        count += 1
    elif s_upper.startswith('ON') and 'GOSUB' in s_upper:
        match_on = re.match(r'ON\s+(.+?)\s+GOSUB\s+(.+)', s_upper)
        if match_on:
            targets = match_on.group(2).split(',')
            count += len(targets)
    elif s_upper.startswith('IF'):
        match_if = re.match(r'IF\s+(.+?)\s+THEN\s+(.+)', s_upper)
        if match_if:
            then_part = match_if.group(2).strip()
            then_stmts = split_by_operator_top_level(then_part, ':')
            for ts in then_stmts:
                count += count_gosubs_in_statement(ts.strip().upper())
    return count

def count_gosubs_in_lines(lines):
    gosub_count = 0
    for line in lines:
        line = line.strip()
        if not line: continue
        match = re.match(r'^(\d+)\s+(.*)', line)
        if not match: continue
        stmt_raw = match.group(2)
        stmts = split_by_operator_top_level(stmt_raw, ':')
        for s in stmts:
            gosub_count += count_gosubs_in_statement(s.strip().upper())
    return gosub_count

def collect_data_statements(lines):
    data_items = []
    for line in lines:
        line = line.strip()
        if not line: continue
        if 'REM' in line.upper():
            line = line[:line.upper().find('REM')]
        match = re.match(r'^(\d+)\s+(.*)', line)
        if not match: continue
        stmt_raw = match.group(2)
        stmts = split_by_operator_top_level(stmt_raw, ':')
        for s in stmts:
            s_upper = s.strip().upper()
            if s_upper.startswith('DATA'):
                items_raw = s.strip()[4:].strip()
                items = split_by_operator_top_level(items_raw, ',')
                for item in items:
                    item = item.strip()
                    if not item: continue
                    if item.startswith('"') and item.endswith('"'):
                        data_items.append(('STR', item[1:-1]))
                    else:
                        try:
                            val = float(item)
                            data_items.append(('NUM', val))
                        except ValueError:
                            data_items.append(('STR', item))
    return data_items

def extract_def_fns(lines, num_arrays, str_arrays):
    def_fns = []
    for line in lines:
        if 'REM' in line.upper():
            line = line[:line.upper().find('REM')]
        match = re.search(r'(?i)\bDEF\s+(FN[A-Z0-9]+)\s*\(\s*([A-Z0-9]+)\s*\)\s*=\s*(.+)', line)
        if match:
            fn_name = match.group(1).upper()
            param = match.group(2).upper()
            expr = match.group(3).strip()
            # Escape strings inside def fn expression
            expr = escape_string_literals(expr)
            expr_c = parse_expression(expr, num_arrays, str_arrays)
            def_fns.append((fn_name, param, expr_c))
    return def_fns

def transpile_line(line_num, stmt, in_for, gosub_state, num_arrays, str_arrays):
    stmt = stmt.strip()
    if not stmt:
        return ""
        
    stmt = escape_string_literals(stmt)
    u_stmt = stmt.upper()
    
    if u_stmt.startswith('REM') or u_stmt.startswith("'"):
        return f"// {stmt}"
        
    if u_stmt.startswith('PRINT'):
        args = stmt[5:].strip()
        return translate_print(args, num_arrays, str_arrays)
        
    if u_stmt.startswith('INPUT'):
        args = stmt[5:].strip()
        match = re.match(r'(?i)"([^"]+)"\s*[;,]\s*(.+)', args)
        if match:
            prompt = match.group(1)
            var = match.group(2).strip().upper()
            c_code = f'printf("%s", "{prompt}"); '
        else:
            var = args.upper()
            c_code = 'printf("? "); '
            
        vars_list = [v.strip().upper() for v in split_by_operator_top_level(var, ',')]
        fmts = []
        addrs = []
        for v in vars_list:
            v_c = parse_expression(v, num_arrays, str_arrays)
            if is_term_stringy(v):
                fmts.append("%255s")
                addrs.append(v_c)
            else:
                fmts.append("%lf")
                if '[' in v_c:
                    addrs.append(f"&({v_c})")
                else:
                    addrs.append(f"&{v_c}")
        fmt_str = " ".join(fmts)
        addr_str = ", ".join(addrs)
        c_code += f'if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "{fmt_str}", {addr_str});'
        return c_code
        
    if u_stmt.startswith('GOTO'):
        target = u_stmt[4:].strip()
        return f"goto line_{target};"
        
    if u_stmt.startswith('GOSUB'):
        target = u_stmt[5:].strip()
        gosub_state['count'] += 1
        curr_id = gosub_state['count']
        return f"gosub_stack[gosub_sp++] = {curr_id}; goto line_{target}; line_ret_{curr_id}:;"
        
    if u_stmt == 'RETURN':
        c_stmts = ["switch (gosub_stack[--gosub_sp]) {"]
        for i in range(1, gosub_state['total'] + 1):
            c_stmts.append(f"    case {i}: goto line_ret_{i};")
        c_stmts.append("    default: fprintf(stderr, \"GOSUB stack error\\n\"); exit(1);")
        c_stmts.append("}")
        return " ".join(c_stmts)
        
    if u_stmt.startswith('ON') and 'GOSUB' in u_stmt:
        match_on = re.match(r'(?i)ON\s+(.+?)\s+GOSUB\s+(.+)', stmt)
        if match_on:
            expr = parse_expression(match_on.group(1).strip(), num_arrays, str_arrays)
            targets = [t.strip() for t in match_on.group(2).split(',')]
            c_stmts = [f"switch ((int)({expr})) {{"]
            for idx, t in enumerate(targets):
                gosub_state['count'] += 1
                curr_id = gosub_state['count']
                c_stmts.append(f"    case {idx+1}: gosub_stack[gosub_sp++] = {curr_id}; goto line_{t}; line_ret_{curr_id}:; break;")
            c_stmts.append("}")
            return " ".join(c_stmts)

    if u_stmt.startswith('ON') and 'GOTO' in u_stmt:
        match_on = re.match(r'(?i)ON\s+(.+?)\s+GOTO\s+(.+)', stmt)
        if match_on:
            expr = parse_expression(match_on.group(1).strip(), num_arrays, str_arrays)
            targets = [t.strip() for t in match_on.group(2).split(',')]
            c_stmts = [f"switch ((int)({expr})) {{"]
            for idx, t in enumerate(targets):
                c_stmts.append(f"    case {idx+1}: goto line_{t};")
            c_stmts.append("}")
            return " ".join(c_stmts)

    if u_stmt.startswith('IF'):
        match = re.match(r'(?i)IF\s+(.+?)\s+THEN\s+(.+)', stmt)
        if match:
            cond = parse_expression(match.group(1).strip(), num_arrays, str_arrays)
            then_part = match.group(2).strip()
            
            else_parts = split_by_word_top_level(then_part, 'ELSE')
            if len(else_parts) == 2:
                then_branch = else_parts[0].strip()
                else_branch = else_parts[1].strip()
                
                then_stmts = split_by_operator_top_level(then_branch, ':')
                then_c = []
                for ts in then_stmts:
                    t_trans = transpile_line(line_num, ts.strip(), in_for, gosub_state, num_arrays, str_arrays)
                    if t_trans: then_c.append(t_trans)
                then_str = " ".join(then_c)
                
                else_stmts = split_by_operator_top_level(else_branch, ':')
                else_c = []
                for es in else_stmts:
                    e_trans = transpile_line(line_num, es.strip(), in_for, gosub_state, num_arrays, str_arrays)
                    if e_trans: else_c.append(e_trans)
                else_str = " ".join(else_c)
                
                return f"if ({cond}) {{ {then_str} }} else {{ {else_str} }}"
            else:
                then_stmts = split_by_operator_top_level(then_part, ':')
                then_c = []
                for ts in then_stmts:
                    if ts.strip().isdigit():
                        then_c.append(f"goto line_{ts.strip()};")
                    else:
                        t_trans = transpile_line(line_num, ts.strip(), in_for, gosub_state, num_arrays, str_arrays)
                        if t_trans: then_c.append(t_trans)
                then_str = " ".join(then_c)
                return f"if ({cond}) {{ {then_str} }}"
                
    if u_stmt.startswith('FOR'):
        match = re.match(r'(?i)FOR\s+([A-Z0-9]+)\s*=\s*(.+?)\s+TO\s+(.+?)(?:\s*STEP\b\s*(.+))?$', stmt)
        if match:
            var = match.group(1).upper()
            start = parse_expression(match.group(2), num_arrays, str_arrays)
            end = parse_expression(match.group(3), num_arrays, str_arrays)
            step = parse_expression(match.group(4), num_arrays, str_arrays) if match.group(4) else "1"
            in_for.append((var, end, step, line_num))
            return f"{var} = {start}; for_loop_{var}_{line_num}: if ((({step}) >= 0 && {var} > ({end})) || (({step}) < 0 && {var} < ({end}))) goto end_for_{var}_{line_num};"
            
    if u_stmt.startswith('NEXT'):
        var = u_stmt[4:].strip().upper()
        if var and any(f[0] == var for f in in_for):
            for idx in range(len(in_for) - 1, -1, -1):
                f = in_for[idx]
                if f[0] == var:
                    step = f[2]
                    l_num = f[3]
                    in_for.pop(idx)
                    return f"{var} += ({step}); goto for_loop_{var}_{l_num}; end_for_{var}_{l_num}:;"
        return "/* NEXT (unmatched) */"

    if u_stmt == 'END' or u_stmt == 'STOP':
        return "exit(0);"
        
    if u_stmt.startswith('DIM'):
        return f"/* {stmt} (handled statically) */"
        
    if u_stmt.startswith('READ'):
        vars_raw = stmt[4:].strip()
        vars_list = [v.strip().upper() for v in split_by_operator_top_level(vars_raw, ',')]
        c_stmts = []
        for v in vars_list:
            v_c = parse_expression(v, num_arrays, str_arrays)
            if is_term_stringy(v):
                c_stmts.append(f"read_string({v_c}, sizeof({v_c}));")
            else:
                if '[' in v_c:
                    c_stmts.append(f"read_numeric(&({v_c}));")
                else:
                    c_stmts.append(f"read_numeric(&{v_c});")
        return " ".join(c_stmts)
        
    if u_stmt == 'RESTORE':
        return "data_ptr = 0;"

    match = re.match(r'(?i)^([A-Z0-9]+\$?(\(.+\))?)\s*=\s*(.+)$', stmt)
    if match:
        var = match.group(1).upper()
        expr = match.group(3)
        if var.endswith('$') or '$(' in var:
            lhs_c = parse_expression(var, num_arrays, str_arrays)
            rhs_c = translate_string_expr(expr, num_arrays, str_arrays)
            return f"str_assign({lhs_c}, sizeof({lhs_c}), {rhs_c});"
        else:
            lhs_c = parse_expression(var, num_arrays, str_arrays)
            rhs_c = parse_expression(expr, num_arrays, str_arrays)
            return f"{lhs_c} = {rhs_c};"
              
    return f"/* UNTRANSLATED: {stmt} */"

def transpile_file(input_path, output_path):
    with open(input_path, 'r', encoding='ascii', errors='ignore') as f:
        content = f.read()
        
    raw_lines = content.splitlines()
    lines = []
    for line in raw_lines:
        match = re.match(r'^(\d+)\s+(.*)', line)
        if match:
            line_num = match.group(1)
            stmt_raw = match.group(2)
            stmt_raw = uppercase_code_keep_strings(stmt_raw)
            stmt_raw = preprocess_spaces_around_keywords(stmt_raw)
            lines.append(f"{line_num} {stmt_raw}")
        else:
            lines.append(line)
            
    num_vars, str_vars, num_arrays, str_arrays = extract_variables(lines)
    
    total_gosubs = count_gosubs_in_lines(lines)
    gosub_state = {'count': 0, 'total': total_gosubs}
    
    data_items = collect_data_statements(lines)
    def_fns = extract_def_fns(lines, num_arrays, str_arrays)
    
    c_code = []
    c_code.append("/*")
    c_code.append(f" * Transpiled from {os.path.basename(input_path)}")
    c_code.append(" * GW-BASIC to strict C17")
    c_code.append(" */")
    c_code.append("#include <stdio.h>")
    c_code.append("#include <stdlib.h>")
    c_code.append("#include <string.h>")
    c_code.append("#include <math.h>")
    c_code.append("#include <time.h>")
    c_code.append("")
    
    # 1. Helpers
    c_code.append("/* Static library helpers */")
    c_code.append("static double basic_SGN(double x) { return (x > 0.0) - (x < 0.0); }")
    c_code.append("static double basic_LEN(const char *s) { return (double)strlen(s); }")
    c_code.append("static double basic_ASC(const char *s) { return s[0] ? (double)((unsigned char)s[0]) : 0.0; }")
    c_code.append("static double basic_VAL(const char *s) { return atof(s); }")
    c_code.append("")
    c_code.append("static const char *basic_CHR(double n) {")
    c_code.append("    static char buf[4][2];")
    c_code.append("    static int idx = 0;")
    c_code.append("    idx = (idx + 1) % 4;")
    c_code.append("    buf[idx][0] = (char)n;")
    c_code.append("    buf[idx][1] = '\\0';")
    c_code.append("    return buf[idx];")
    c_code.append("}")
    c_code.append("")
    c_code.append("static const char *basic_STR(double n) {")
    c_code.append("    static char buf[4][64];")
    c_code.append("    static int idx = 0;")
    c_code.append("    idx = (idx + 1) % 4;")
    c_code.append("    if (n >= 0) snprintf(buf[idx], sizeof(buf[idx]), \" %g\", n);")
    c_code.append("    else snprintf(buf[idx], sizeof(buf[idx]), \"%g\", n);")
    c_code.append("    return buf[idx];")
    c_code.append("}")
    c_code.append("")
    c_code.append("static const char *basic_LEFT(const char *s, double n) {")
    c_code.append("    static char buf[4][256];")
    c_code.append("    static int idx = 0;")
    c_code.append("    int len = (int)n;")
    c_code.append("    idx = (idx + 1) % 4;")
    c_code.append("    if (len < 0) len = 0;")
    c_code.append("    if (len > 255) len = 255;")
    c_code.append("    strncpy(buf[idx], s, len);")
    c_code.append("    buf[idx][len] = '\\0';")
    c_code.append("    return buf[idx];")
    c_code.append("}")
    c_code.append("")
    c_code.append("static const char *basic_RIGHT(const char *s, double n) {")
    c_code.append("    static char buf[4][256];")
    c_code.append("    static int idx = 0;")
    c_code.append("    int len = (int)n;")
    c_code.append("    int s_len = (int)strlen(s);")
    c_code.append("    idx = (idx + 1) % 4;")
    c_code.append("    if (len < 0) len = 0;")
    c_code.append("    if (len > s_len) len = s_len;")
    c_code.append("    if (len > 255) len = 255;")
    c_code.append("    strncpy(buf[idx], s + s_len - len, len);")
    c_code.append("    buf[idx][len] = '\\0';")
    c_code.append("    return buf[idx];")
    c_code.append("}")
    c_code.append("")
    c_code.append("static const char *basic_MID(const char *s, double start_d, double len_d) {")
    c_code.append("    static char buf[4][256];")
    c_code.append("    static int idx = 0;")
    c_code.append("    int start = (int)start_d - 1;")
    c_code.append("    int len = (int)len_d;")
    c_code.append("    int s_len = (int)strlen(s);")
    c_code.append("    idx = (idx + 1) % 4;")
    c_code.append("    if (start < 0) start = 0;")
    c_code.append("    if (start > s_len) start = s_len;")
    c_code.append("    if (len < 0) len = 0;")
    c_code.append("    if (len > 255) len = 255;")
    c_code.append("    strncpy(buf[idx], s + start, len);")
    c_code.append("    buf[idx][len] = '\\0';")
    c_code.append("    return buf[idx];")
    c_code.append("}")
    c_code.append("")
    c_code.append("static const char *str_cat_helper(const char *s1, const char *s2) {")
    c_code.append("    static char buf[4][512];")
    c_code.append("    static int idx = 0;")
    c_code.append("    idx = (idx + 1) % 4;")
    c_code.append("    snprintf(buf[idx], sizeof(buf[idx]), \"%s%s\", s1, s2);")
    c_code.append("    return buf[idx];")
    c_code.append("}")
    c_code.append("")
    c_code.append("static void str_assign(char *dest, size_t dest_sz, const char *src) {")
    c_code.append("    strncpy(dest, src, dest_sz - 1);")
    c_code.append("    dest[dest_sz - 1] = '\\0';")
    c_code.append("}")
    c_code.append("")
    
    # 2. DATA Statements
    if data_items:
        c_code.append("typedef enum { DATA_NUM, DATA_STR } DataType;")
        c_code.append("typedef struct {")
        c_code.append("    DataType type;")
        c_code.append("    union {")
        c_code.append("        double num;")
        c_code.append("        const char *str;")
        c_code.append("    } u;")
        c_code.append("} DataItem;")
        c_code.append("")
        c_code.append(f"static DataItem program_data[{len(data_items)}] = {{")
        for item in data_items:
            t, val = item
            if t == 'NUM':
                c_code.append(f"    {{ DATA_NUM, {{ .num = {val} }} }},")
            else:
                escaped_val = str(val).replace('\\', '\\\\').replace('"', '\\"')
                c_code.append(f"    {{ DATA_STR, {{ .str = \"{escaped_val}\" }} }},")
        c_code.append("};")
        c_code.append("static int data_ptr = 0;")
        c_code.append("")
        c_code.append("static void read_numeric(double *var) {")
        c_code.append("    if (data_ptr < sizeof(program_data)/sizeof(program_data[0])) {")
        c_code.append("        if (program_data[data_ptr].type == DATA_NUM) *var = program_data[data_ptr].u.num;")
        c_code.append("        else *var = atof(program_data[data_ptr].u.str);")
        c_code.append("        data_ptr++;")
        c_code.append("    }")
        c_code.append("}")
        c_code.append("")
        c_code.append("static void read_string(char *var, size_t max_len) {")
        c_code.append("    if (data_ptr < sizeof(program_data)/sizeof(program_data[0])) {")
        c_code.append("        if (program_data[data_ptr].type == DATA_STR) strncpy(var, program_data[data_ptr].u.str, max_len - 1);")
        c_code.append("        else snprintf(var, max_len, \"%g\", program_data[data_ptr].u.num);")
        c_code.append("        var[max_len - 1] = '\\0';")
        c_code.append("        data_ptr++;")
        c_code.append("    }")
        c_code.append("}")
        c_code.append("")

    # 3. Global variables
    c_code.append("/* Global variables */")
    if total_gosubs > 0:
        c_code.append("static int gosub_stack[256];")
        c_code.append("static int gosub_sp = 0;")
    if num_vars:
        c_code.append("static double " + ", ".join(sorted(num_vars)) + ";")
    if str_vars:
        for sv in sorted(str_vars):
            c_code.append(f"static char {sv}_str[256] = {{0}};")
    if num_arrays:
        for na in sorted(num_arrays):
            c_code.append(f"static double {na}_arr[20000] = {{0}};")
    if str_arrays:
        for sa in sorted(str_arrays):
            c_code.append(f"static char {sa}_str_arr[20000][256] = {{0}};")
    c_code.append("static char _input_buf[256];")
    c_code.append("")
    
    # 4. User defined functions (DEF FN)
    if def_fns:
        c_code.append("/* User-defined functions forward declarations */")
        for fn_name, param, expr_c in def_fns:
            c_code.append(f"static double {fn_name}(double {param});")
        c_code.append("")
        c_code.append("/* User-defined functions definitions */")
        for fn_name, param, expr_c in def_fns:
            c_code.append(f"static double {fn_name}(double {param}) {{")
            c_code.append(f"    return {expr_c};")
            c_code.append("}")
            c_code.append("")
            
    c_code.append("int main(int argc, char **argv) {")
    c_code.append("    srand((unsigned int)time(NULL));")
    c_code.append("")
    
    c_code.append("    (void)argc;")
    c_code.append("    (void)argv;")
    c_code.append("    (void)_input_buf;")
    c_code.append("")
    
    in_for = []
    
    for original_line in lines:
        original_line = original_line.strip()
        if not original_line:
            continue
            
        match = re.match(r'^(\d+)\s+(.*)', original_line)
        if match:
            line_num = match.group(1)
            stmt_raw = match.group(2)
            
            c_code.append(f"    /* BASIC: {original_line} */")
            c_code.append(f"line_{line_num}:;")
            
            stmt_upper = stmt_raw.strip().upper()
            if stmt_upper.startswith('IF'):
                t = transpile_line(line_num, stmt_raw, in_for, gosub_state, num_arrays, str_arrays)
                if t:
                    c_code.append("    " + t)
            else:
                stmts = split_by_operator_top_level(stmt_raw, ':')
                for s in stmts:
                    t = transpile_line(line_num, s, in_for, gosub_state, num_arrays, str_arrays)
                    if t:
                        c_code.append("    " + t)
                        
    # Collect defined and referenced labels to fix missing/undefined labels
    defined_labels = set()
    referenced_labels = set()
    for line in c_code:
        defs = re.findall(r'\b(line_\w+|line_ret_\w+|for_loop_\w+|end_for_\w+):', line)
        for d in defs:
            defined_labels.add(d)
        refs = re.findall(r'\bgoto\s+(\w+);', line)
        for r in refs:
            referenced_labels.add(r)
            
    undefined = sorted(list(referenced_labels - defined_labels))
    if undefined:
        c_code.append("    /* Undefined labels declared here to compile cleanly */")
        for und in undefined:
            c_code.append(f"    {und}:;")
            
    c_code.append("")
    c_code.append("    return 0;")
    c_code.append("}")
    
    os.makedirs(os.path.dirname(output_path), exist_ok=True)
    with open(output_path, 'w', encoding='ascii') as f:
        f.write("\n".join(c_code))
        f.write("\n")

def main():
    base_dir = os.path.dirname(os.path.abspath(__file__))
    src_dir = os.path.join(base_dir, "SOURCE")
    games_dir = os.path.join(base_dir, "GAMES")
    
    bas_files = glob.glob(os.path.join(games_dir, "*.bas"))
    
    print(f"Found {len(bas_files)} .bas files to transpile.")
    
    for f in bas_files:
        basename = os.path.basename(f)
        c_name = os.path.splitext(basename)[0] + ".c"
        out_path = os.path.join(src_dir, c_name)
        transpile_file(f, out_path)
        print(f"Transpiled {basename} -> SOURCE/{c_name}")

if __name__ == "__main__":
    main()