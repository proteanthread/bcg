import os
import re
import glob

def convert_to_c89(text):
    # 1. State machine to convert // comments to /* ... */, preserving quotes and existing block comments
    out = []
    i = 0
    n = len(text)
    while i < n:
        if i + 1 < n and text[i] == '/' and text[i+1] == '*':
            # Inside a block comment: copy until the closing */
            out.append('/*')
            i += 2
            while i < n:
                if i + 1 < n and text[i] == '*' and text[i+1] == '/':
                    out.append('*/')
                    i += 2
                    break
                else:
                    out.append(text[i])
                    i += 1
        elif i + 1 < n and text[i] == '/' and text[i+1] == '/':
            # Inside a line comment: convert to block comment
            comment_content = ""
            i += 2
            while i < n and text[i] != '\n' and text[i] != '\r':
                comment_content += text[i]
                i += 1
            # Prevent nested block comments
            comment_content = comment_content.replace('*/', '* /')
            out.append('/* ' + comment_content.strip() + ' */')
        elif text[i] == '"':
            # Inside a string literal: skip over string content, preserving backslash escapes
            out.append('"')
            i += 1
            while i < n:
                if text[i] == '\\':
                    out.append(text[i])
                    if i + 1 < n:
                        out.append(text[i+1])
                    i += 2
                elif text[i] == '"':
                    out.append('"')
                    i += 1
                    break
                else:
                    out.append(text[i])
                    i += 1
        elif text[i] == "'":
            # Inside a character literal
            out.append("'")
            i += 1
            while i < n:
                if text[i] == '\\':
                    out.append(text[i])
                    if i + 1 < n:
                        out.append(text[i+1])
                    i += 2
                elif text[i] == "'":
                    out.append("'")
                    i += 1
                    break
                else:
                    out.append(text[i])
                    i += 1
        else:
            out.append(text[i])
            i += 1
            
    result = "".join(out)
    
    # 2. Replace C99 snprintf calls with C89 sprintf
    result = re.sub(r'\bsnprintf\s*\(\s*([^,]+)\s*,\s*[^,]+\s*,', r'sprintf(\1,', result)
    
    # 3. Downsize array dimensions to prevent breaking the 512KB DOS conventional memory barrier
    #    double A_arr[20000] -> double A_arr[2000] (16 KB)
    #    char A_str_arr[20000][256] -> char A_str_arr[1000][64] (64 KB)
    result = re.sub(r'static\s+double\s+([a-zA-Z_0-9]+)_arr\s*\[\s*20000\s*\]\s*=\s*\{\s*0\s*\}\s*;', r'static double \1_arr[2000] = {0};', result)
    result = re.sub(r'static\s+char\s+([a-zA-Z_0-9]+)_str_arr\s*\[\s*20000\s*\]\s*\[\s*256\s*\]\s*=\s*\{\s*0\s*\}\s*;', r'static char \1_str_arr[1000][64] = {0};', result)
    
    # 4. Convert DataItem union to struct (to avoid C99 designated initializers in union)
    result = re.sub(
        r'typedef\s+struct\s*\{\s*DataType\s+type\s*;\s*union\s*\{\s*double\s+num\s*;\s*const\s+char\s*\*\s*str\s*;\s*\}\s*u\s*;\s*\}\s*DataItem\s*;',
        'typedef struct {\n    DataType type;\n    double num;\n    const char *str;\n} DataItem;',
        result
    )
    
    # Replace .u.num with .num and .u.str with .str in usage
    result = result.replace('program_data[data_ptr].u.num', 'program_data[data_ptr].num')
    result = result.replace('program_data[data_ptr].u.str', 'program_data[data_ptr].str')
    
    # Replace designated initializers:
    # { DATA_NUM, { .num = VALUE } } -> { DATA_NUM, VALUE, NULL }
    result = re.sub(r'\{\s*DATA_NUM\s*,\s*\{\s*\.num\s*=\s*([-+0-9.eE]+)\s*\}\s*\}', r'{ DATA_NUM, \1, NULL }', result)
    # { DATA_STR, { .str = "VALUE" } } -> { DATA_STR, 0.0, "VALUE" }
    result = re.sub(r'\{\s*DATA_STR\s*,\s*\{\s*\.str\s*=\s*("(?:[^"\\]|\\.)*")\s*\}\s*\}', r'{ DATA_STR, 0.0, \1 }', result)
    
    # 5. Update header documentation
    result = result.replace('strict C17', 'strict C89 (ANSI) / C90 (ISO)')
    
    return result

def main():
    base_dir = os.path.dirname(os.path.abspath(__file__))
    src_dir = os.path.join(base_dir, "SOURCE")
    c89_dir = os.path.join(base_dir, "C89")
    
    os.makedirs(c89_dir, exist_ok=True)
    c_files = glob.glob(os.path.join(src_dir, "*.c"))
    print(f"Found {len(c_files)} source files in {src_dir}")
    
    for f in c_files:
        basename = os.path.basename(f)
        out_path = os.path.join(c89_dir, basename)
        with open(f, 'r', encoding='ascii', errors='ignore') as infile:
            content = infile.read()
        converted = convert_to_c89(content)
        with open(out_path, 'w', encoding='ascii') as outfile:
            outfile.write(converted)
    print(f"Successfully converted all source files to C89 in {c89_dir}")

if __name__ == '__main__':
    main()
