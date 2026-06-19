import os
import re
import sys
import glob

def clean_line(line):
    # Remove leading/trailing whitespace
    return line.strip()

def extract_variables(lines):
    num_vars = set()
    str_vars = set()
    num_arrays = set()
    str_arrays = set()
    
    # Simple regex to find variable names (A-Z followed by optional number or $)
    # This is a naive extraction, but works for most vintage BASICs
    for line in lines:
        # Ignore comments
        if 'REM' in line.upper():
            line = line[:line.upper().find('REM')]
            
        # Find arrays DIM A(100), DIM B$(50)
        dim_matches = re.findall(r'DIM\s+([A-Z][A-Z0-9]?\$?)\s*\([^\)]+\)', line, re.IGNORECASE)
        for d in dim_matches:
            d = d.upper()
            if d.endswith('$'):
                str_arrays.add(d[:-1])
            else:
                num_arrays.add(d)
                
        # Find regular variables A, A1, B$
        var_matches = re.findall(r'\b([A-Z][A-Z0-9]*\$?)\b', line, re.IGNORECASE)
        for v in var_matches:
            v = v.upper()
            # Ignore keywords
            if v in ['PRINT', 'INPUT', 'IF', 'THEN', 'GOTO', 'GOSUB', 'RETURN', 'FOR', 'TO', 'STEP', 'NEXT', 'DIM', 'REM', 'STOP', 'END', 'INT', 'RND', 'TAB', 'LEN', 'MID$', 'LEFT$', 'RIGHT$', 'CHR$', 'ASC', 'VAL', 'STR$', 'AND', 'OR', 'NOT']:
                continue
            if v.endswith('$'):
                str_vars.add(v[:-1])
            else:
                num_vars.add(v)
                
    # Remove array names from regular vars
    for a in num_arrays:
        if a in num_vars:
            num_vars.remove(a)
    for a in str_arrays:
        if a in str_vars:
            str_vars.remove(a)
            
    return num_vars, str_vars, num_arrays, str_arrays

def parse_expression(expr):
    # Very basic expression translation
    # This won't perfectly parse complex BASIC math but will handle most
    expr = re.sub(r'(?i)\bINT\b', 'floor', expr)
    expr = re.sub(r'(?i)\bRND\(\d*\)', '((double)rand() / (double)RAND_MAX)', expr) # Standard 0 to 1 rand
    expr = re.sub(r'(?i)\bRND\b', '((double)rand() / (double)RAND_MAX)', expr)
    expr = re.sub(r'(?i)\bSQR\b', 'sqrt', expr)
    expr = re.sub(r'(?i)\bABS\b', 'fabs', expr)
    expr = expr.replace('=', '==') # Equality in expressions (naive, breaks assignment if not careful, handled differently below)
    expr = expr.replace('<>', '!=')
    expr = expr.replace(' AND ', ' && ')
    expr = expr.replace(' OR ', ' || ')
    return expr

def translate_print(args):
    if not args:
        return 'printf("\\n");'
    
    # Needs to handle "STR"; V; "STR", TAB(X)
    # A very naive print translator
    c_stmts = []
    
    # Split by ; and , ignoring inside quotes
    # For a robust transpiler, we need a proper state machine, but let's try a simpler approach
    # We will just print the entire thing as a string format if we can, or multiple printf calls
    
    # Let's break args into tokens
    parts = []
    current = ""
    in_str = False
    for char in args:
        if char == '"':
            in_str = not in_str
            current += char
        elif char in [';', ','] and not in_str:
            if current.strip():
                parts.append(current.strip())
            parts.append(char)
            current = ""
        else:
            current += char
    if current.strip():
        parts.append(current.strip())
        
    for p in parts:
        if p == ';':
            continue
        elif p == ',':
            c_stmts.append('printf("\\t");')
        elif p.startswith('"') and p.endswith('"'):
            c_stmts.append(f'printf("%s", {p});')
        elif p.upper().startswith('TAB('):
            # Hack for TAB
            inner = p[4:-1]
            c_stmts.append(f'{{ int _t; for(_t=0; _t<{parse_expression(inner)}; _t++) printf(" "); }}')
        else:
            # Variable or expression
            # If it ends with $, it's a string, else double
            if p.upper().endswith('$'):
                c_stmts.append(f'printf("%s", {p[:-1]}_str);')
            else:
                c_stmts.append(f'printf("%g ", (double)({parse_expression(p)}));')
                
    if not args.endswith(';') and not args.endswith(','):
        c_stmts.append('printf("\\n");')
        
    return ' '.join(c_stmts)

def transpile_line(line_num, stmt, in_for):
    stmt = stmt.strip()
    if not stmt:
        return ""
    
    u_stmt = stmt.upper()
    
    if u_stmt.startswith('REM') or u_stmt.startswith("'"):
        return f"// {stmt}"
        
    if u_stmt.startswith('PRINT'):
        args = stmt[5:].strip()
        return translate_print(args)
        
    if u_stmt.startswith('INPUT'):
        args = stmt[5:].strip()
        # INPUT "PROMPT"; VAR
        match = re.match(r'(?i)"([^"]+)"\s*[;,]\s*(.+)', args)
        if match:
            prompt = match.group(1)
            var = match.group(2).strip().upper()
            c_code = f'printf("%s", "{prompt}"); '
        else:
            var = args.upper()
            c_code = 'printf("? "); '
            
        if var.endswith('$'):
            c_code += f'fgets({var[:-1]}_str, sizeof({var[:-1]}_str), stdin); '
            c_code += f'{var[:-1]}_str[strcspn({var[:-1]}_str, "\\n")] = 0;'
        else:
            c_code += f'if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &{var});'
        return c_code
        
    if u_stmt.startswith('GOTO'):
        target = u_stmt[4:].strip()
        return f"goto line_{target};"
        
    if u_stmt.startswith('GOSUB'):
        target = u_stmt[5:].strip()
        # Fake GOSUB with a switch/stack. For simplicity in C89, we'll use a hack or just complain.
        # A simple hack: assign return label to a variable and goto.
        # But C doesn't have computed gotos in ANSI C89.
        # We will use a _gosub_target and a switch in the main loop if needed, or a manual translation.
        # For this basic transpiler, we will just put a comment since perfect GOSUB requires restructuring.
        return f"/* TODO: GOSUB {target} */"
        
    if u_stmt == 'RETURN':
        return f"/* TODO: RETURN */"
        
    if u_stmt.startswith('IF'):
        # IF cond THEN stmt
        match = re.match(r'(?i)IF\s+(.+?)\s+THEN\s+(.+)', stmt)
        if match:
            cond = parse_expression(match.group(1))
            then_part = match.group(2)
            # If THEN is just a number, it's a GOTO
            if then_part.strip().isdigit():
                return f"if ({cond}) goto line_{then_part.strip()};"
            else:
                return f"if ({cond}) {{ {transpile_line('', then_part, in_for)} }}"
                
    if u_stmt.startswith('FOR'):
        # FOR I = A TO B STEP C
        match = re.match(r'(?i)FOR\s+([A-Z0-9]+)\s*=\s*(.+?)\s+TO\s+(.+?)(?:\s+STEP\s+(.+))?$', stmt)
        if match:
            var = match.group(1).upper()
            start = parse_expression(match.group(2))
            end = parse_expression(match.group(3))
            step = parse_expression(match.group(4)) if match.group(4) else "1"
            in_for.append((var, end, step))
            return f"{var} = {start}; for_loop_{var}: if (({step} >= 0 && {var} > {end}) || ({step} < 0 && {var} < {end})) goto end_for_{var};"
            
    if u_stmt.startswith('NEXT'):
        var = u_stmt[4:].strip().upper()
        if var and any(f[0] == var for f in in_for):
            # Find the loop
            for f in reversed(in_for):
                if f[0] == var:
                    step = f[2]
                    return f"{var} += {step}; goto for_loop_{var}; end_for_{var}:;"
        return "/* TODO: NEXT (unmatched) */"

    if u_stmt == 'END' or u_stmt == 'STOP':
        return "exit(0);"
        
    if u_stmt.startswith('DIM'):
        return f"/* {stmt} (handled statically) */"
        
    # Assignment A = B
    match = re.match(r'(?i)^([A-Z0-9]+\$?(\(.+\))?)\s*=\s*(.+)$', stmt)
    if match:
        var = match.group(1).upper()
        expr = match.group(3)
        if var.endswith('$'):
             # String assignment (naive)
             return f"strncpy({var[:-1]}_str, \"{expr}\", sizeof({var[:-1]}_str)); /* String assign approx */"
        else:
             return f"{var} = {parse_expression(expr)};"
             
    # Default fallback
    return f"/* UNTRANSLATED: {stmt} */"

def transpile_file(input_path, output_path):
    with open(input_path, 'r', encoding='ascii', errors='ignore') as f:
        content = f.read()
        
    lines = content.splitlines()
    
    # 1. Extract variables
    num_vars, str_vars, num_arrays, str_arrays = extract_variables(lines)
    
    c_code = []
    c_code.append("/*")
    c_code.append(f" * Transpiled from {os.path.basename(input_path)}")
    c_code.append(" * GW-BASIC to strict C89 (ANSI)")
    c_code.append(" */")
    c_code.append("#include <stdio.h>")
    c_code.append("#include <stdlib.h>")
    c_code.append("#include <string.h>")
    c_code.append("#include <math.h>")
    c_code.append("#include <time.h>")
    c_code.append("")
    c_code.append("int main(int argc, char **argv) {")
    c_code.append("    /* Variable declarations */")
    
    if num_vars:
        c_code.append("    double " + ", ".join(num_vars) + ";")
    if str_vars:
        for sv in str_vars:
            c_code.append(f"    char {sv}_str[256] = {{0}};")
    if num_arrays:
        for na in num_arrays:
            c_code.append(f"    double {na}[1000] = {{0}}; /* Static array fallback */")
    if str_arrays:
        for sa in str_arrays:
            c_code.append(f"    char {sa}_str[1000][256] = {{0}}; /* Static string array fallback */")
            
    c_code.append("    char _input_buf[256];")
    c_code.append("    srand((unsigned int)time(NULL));")
    c_code.append("")
    
    in_for = []
    
    for original_line in lines:
        original_line = original_line.strip()
        if not original_line:
            continue
            
        # Parse line number
        match = re.match(r'^(\d+)\s+(.*)', original_line)
        if match:
            line_num = match.group(1)
            stmt_raw = match.group(2)
            
            c_code.append(f"    /* BASIC: {original_line} */")
            c_code.append(f"line_{line_num}:")
            
            # Split multiple statements separated by : (outside quotes)
            # A simplistic split
            stmts = []
            cur = ""
            in_q = False
            for c in stmt_raw:
                if c == '"': in_q = not in_q
                if c == ':' and not in_q:
                    stmts.append(cur)
                    cur = ""
                else:
                    cur += c
            stmts.append(cur)
            
            for s in stmts:
                t = transpile_line(line_num, s, in_for)
                if t:
                    c_code.append("    " + t)
                    
        else:
            # No line number (maybe continued line or strange format)
            pass
            
    c_code.append("")
    c_code.append("    return 0;")
    c_code.append("}")
    
    os.makedirs(os.path.dirname(output_path), exist_ok=True)
    with open(output_path, 'w', encoding='ascii') as f:
        f.write("\n".join(c_code))
        f.write("\n")

def main():
    base_dir = r"C:\Users\rtdos\GitHub\bcg"
    src_dir = os.path.join(base_dir, "src")
    
    bas_files = glob.glob(os.path.join(base_dir, "*.bas"))
    
    print(f"Found {len(bas_files)} .bas files to transpile.")
    
    for f in bas_files:
        basename = os.path.basename(f)
        c_name = os.path.splitext(basename)[0] + ".c"
        out_path = os.path.join(src_dir, c_name)
        transpile_file(f, out_path)
        print(f"Transpiled {basename} -> src/{c_name}")

if __name__ == "__main__":
    main()
