/*
 * Transpiled from banner.bas
 * GW-BASIC to strict C17
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

/* Static library helpers */
static double basic_SGN(double x) { return (x > 0.0) - (x < 0.0); }
static double basic_LEN(const char *s) { return (double)strlen(s); }
static double basic_ASC(const char *s) { return s[0] ? (double)((unsigned char)s[0]) : 0.0; }
static double basic_VAL(const char *s) { return atof(s); }

static const char *basic_CHR(double n) {
    static char buf[4][2];
    static int idx = 0;
    idx = (idx + 1) % 4;
    buf[idx][0] = (char)n;
    buf[idx][1] = '\0';
    return buf[idx];
}

static const char *basic_STR(double n) {
    static char buf[4][64];
    static int idx = 0;
    idx = (idx + 1) % 4;
    if (n >= 0) snprintf(buf[idx], sizeof(buf[idx]), " %g", n);
    else snprintf(buf[idx], sizeof(buf[idx]), "%g", n);
    return buf[idx];
}

static const char *basic_LEFT(const char *s, double n) {
    static char buf[4][256];
    static int idx = 0;
    int len = (int)n;
    idx = (idx + 1) % 4;
    if (len < 0) len = 0;
    if (len > 255) len = 255;
    strncpy(buf[idx], s, len);
    buf[idx][len] = '\0';
    return buf[idx];
}

static const char *basic_RIGHT(const char *s, double n) {
    static char buf[4][256];
    static int idx = 0;
    int len = (int)n;
    int s_len = (int)strlen(s);
    idx = (idx + 1) % 4;
    if (len < 0) len = 0;
    if (len > s_len) len = s_len;
    if (len > 255) len = 255;
    strncpy(buf[idx], s + s_len - len, len);
    buf[idx][len] = '\0';
    return buf[idx];
}

static const char *basic_MID(const char *s, double start_d, double len_d) {
    static char buf[4][256];
    static int idx = 0;
    int start = (int)start_d - 1;
    int len = (int)len_d;
    int s_len = (int)strlen(s);
    idx = (idx + 1) % 4;
    if (start < 0) start = 0;
    if (start > s_len) start = s_len;
    if (len < 0) len = 0;
    if (len > 255) len = 255;
    strncpy(buf[idx], s + start, len);
    buf[idx][len] = '\0';
    return buf[idx];
}

static const char *str_cat_helper(const char *s1, const char *s2) {
    static char buf[4][512];
    static int idx = 0;
    idx = (idx + 1) % 4;
    snprintf(buf[idx], sizeof(buf[idx]), "%s%s", s1, s2);
    return buf[idx];
}

static void str_assign(char *dest, size_t dest_sz, const char *src) {
    strncpy(dest, src, dest_sz - 1);
    dest[dest_sz - 1] = '\0';
}

typedef enum { DATA_NUM, DATA_STR } DataType;
typedef struct {
    DataType type;
    union {
        double num;
        const char *str;
    } u;
} DataItem;

static DataItem program_data[336] = {
    { DATA_STR, { .str = " " } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_STR, { .str = "A" } },
    { DATA_NUM, { .num = 505.0 } },
    { DATA_NUM, { .num = 37.0 } },
    { DATA_NUM, { .num = 35.0 } },
    { DATA_NUM, { .num = 34.0 } },
    { DATA_NUM, { .num = 35.0 } },
    { DATA_NUM, { .num = 37.0 } },
    { DATA_NUM, { .num = 505.0 } },
    { DATA_STR, { .str = "G" } },
    { DATA_NUM, { .num = 125.0 } },
    { DATA_NUM, { .num = 131.0 } },
    { DATA_NUM, { .num = 258.0 } },
    { DATA_NUM, { .num = 258.0 } },
    { DATA_NUM, { .num = 290.0 } },
    { DATA_NUM, { .num = 163.0 } },
    { DATA_NUM, { .num = 101.0 } },
    { DATA_STR, { .str = "E" } },
    { DATA_NUM, { .num = 512.0 } },
    { DATA_NUM, { .num = 274.0 } },
    { DATA_NUM, { .num = 274.0 } },
    { DATA_NUM, { .num = 274.0 } },
    { DATA_NUM, { .num = 274.0 } },
    { DATA_NUM, { .num = 258.0 } },
    { DATA_NUM, { .num = 258.0 } },
    { DATA_STR, { .str = "T" } },
    { DATA_NUM, { .num = 2.0 } },
    { DATA_NUM, { .num = 2.0 } },
    { DATA_NUM, { .num = 2.0 } },
    { DATA_NUM, { .num = 512.0 } },
    { DATA_NUM, { .num = 2.0 } },
    { DATA_NUM, { .num = 2.0 } },
    { DATA_NUM, { .num = 2.0 } },
    { DATA_STR, { .str = "W" } },
    { DATA_NUM, { .num = 256.0 } },
    { DATA_NUM, { .num = 257.0 } },
    { DATA_NUM, { .num = 129.0 } },
    { DATA_NUM, { .num = 65.0 } },
    { DATA_NUM, { .num = 129.0 } },
    { DATA_NUM, { .num = 257.0 } },
    { DATA_NUM, { .num = 256.0 } },
    { DATA_STR, { .str = "L" } },
    { DATA_NUM, { .num = 512.0 } },
    { DATA_NUM, { .num = 257.0 } },
    { DATA_NUM, { .num = 257.0 } },
    { DATA_NUM, { .num = 257.0 } },
    { DATA_NUM, { .num = 257.0 } },
    { DATA_NUM, { .num = 257.0 } },
    { DATA_NUM, { .num = 257.0 } },
    { DATA_STR, { .str = "S" } },
    { DATA_NUM, { .num = 69.0 } },
    { DATA_NUM, { .num = 139.0 } },
    { DATA_NUM, { .num = 274.0 } },
    { DATA_NUM, { .num = 274.0 } },
    { DATA_NUM, { .num = 274.0 } },
    { DATA_NUM, { .num = 163.0 } },
    { DATA_NUM, { .num = 69.0 } },
    { DATA_STR, { .str = "O" } },
    { DATA_NUM, { .num = 125.0 } },
    { DATA_NUM, { .num = 131.0 } },
    { DATA_NUM, { .num = 258.0 } },
    { DATA_NUM, { .num = 258.0 } },
    { DATA_NUM, { .num = 258.0 } },
    { DATA_NUM, { .num = 131.0 } },
    { DATA_NUM, { .num = 125.0 } },
    { DATA_STR, { .str = "N" } },
    { DATA_NUM, { .num = 512.0 } },
    { DATA_NUM, { .num = 7.0 } },
    { DATA_NUM, { .num = 9.0 } },
    { DATA_NUM, { .num = 17.0 } },
    { DATA_NUM, { .num = 33.0 } },
    { DATA_NUM, { .num = 193.0 } },
    { DATA_NUM, { .num = 512.0 } },
    { DATA_STR, { .str = "F" } },
    { DATA_NUM, { .num = 512.0 } },
    { DATA_NUM, { .num = 18.0 } },
    { DATA_NUM, { .num = 18.0 } },
    { DATA_NUM, { .num = 18.0 } },
    { DATA_NUM, { .num = 18.0 } },
    { DATA_NUM, { .num = 2.0 } },
    { DATA_NUM, { .num = 2.0 } },
    { DATA_STR, { .str = "K" } },
    { DATA_NUM, { .num = 512.0 } },
    { DATA_NUM, { .num = 17.0 } },
    { DATA_NUM, { .num = 17.0 } },
    { DATA_NUM, { .num = 41.0 } },
    { DATA_NUM, { .num = 69.0 } },
    { DATA_NUM, { .num = 131.0 } },
    { DATA_NUM, { .num = 258.0 } },
    { DATA_STR, { .str = "B" } },
    { DATA_NUM, { .num = 512.0 } },
    { DATA_NUM, { .num = 274.0 } },
    { DATA_NUM, { .num = 274.0 } },
    { DATA_NUM, { .num = 274.0 } },
    { DATA_NUM, { .num = 274.0 } },
    { DATA_NUM, { .num = 274.0 } },
    { DATA_NUM, { .num = 239.0 } },
    { DATA_STR, { .str = "D" } },
    { DATA_NUM, { .num = 512.0 } },
    { DATA_NUM, { .num = 258.0 } },
    { DATA_NUM, { .num = 258.0 } },
    { DATA_NUM, { .num = 258.0 } },
    { DATA_NUM, { .num = 258.0 } },
    { DATA_NUM, { .num = 131.0 } },
    { DATA_NUM, { .num = 125.0 } },
    { DATA_STR, { .str = "H" } },
    { DATA_NUM, { .num = 512.0 } },
    { DATA_NUM, { .num = 17.0 } },
    { DATA_NUM, { .num = 17.0 } },
    { DATA_NUM, { .num = 17.0 } },
    { DATA_NUM, { .num = 17.0 } },
    { DATA_NUM, { .num = 17.0 } },
    { DATA_NUM, { .num = 512.0 } },
    { DATA_STR, { .str = "M" } },
    { DATA_NUM, { .num = 512.0 } },
    { DATA_NUM, { .num = 7.0 } },
    { DATA_NUM, { .num = 13.0 } },
    { DATA_NUM, { .num = 25.0 } },
    { DATA_NUM, { .num = 13.0 } },
    { DATA_NUM, { .num = 7.0 } },
    { DATA_NUM, { .num = 512.0 } },
    { DATA_STR, { .str = "?" } },
    { DATA_NUM, { .num = 5.0 } },
    { DATA_NUM, { .num = 3.0 } },
    { DATA_NUM, { .num = 2.0 } },
    { DATA_NUM, { .num = 354.0 } },
    { DATA_NUM, { .num = 18.0 } },
    { DATA_NUM, { .num = 11.0 } },
    { DATA_NUM, { .num = 5.0 } },
    { DATA_STR, { .str = "U" } },
    { DATA_NUM, { .num = 128.0 } },
    { DATA_NUM, { .num = 129.0 } },
    { DATA_NUM, { .num = 257.0 } },
    { DATA_NUM, { .num = 257.0 } },
    { DATA_NUM, { .num = 257.0 } },
    { DATA_NUM, { .num = 129.0 } },
    { DATA_NUM, { .num = 128.0 } },
    { DATA_STR, { .str = "R" } },
    { DATA_NUM, { .num = 512.0 } },
    { DATA_NUM, { .num = 18.0 } },
    { DATA_NUM, { .num = 18.0 } },
    { DATA_NUM, { .num = 50.0 } },
    { DATA_NUM, { .num = 82.0 } },
    { DATA_NUM, { .num = 146.0 } },
    { DATA_NUM, { .num = 271.0 } },
    { DATA_STR, { .str = "P" } },
    { DATA_NUM, { .num = 512.0 } },
    { DATA_NUM, { .num = 18.0 } },
    { DATA_NUM, { .num = 18.0 } },
    { DATA_NUM, { .num = 18.0 } },
    { DATA_NUM, { .num = 18.0 } },
    { DATA_NUM, { .num = 18.0 } },
    { DATA_NUM, { .num = 15.0 } },
    { DATA_STR, { .str = "Q" } },
    { DATA_NUM, { .num = 125.0 } },
    { DATA_NUM, { .num = 131.0 } },
    { DATA_NUM, { .num = 258.0 } },
    { DATA_NUM, { .num = 258.0 } },
    { DATA_NUM, { .num = 322.0 } },
    { DATA_NUM, { .num = 131.0 } },
    { DATA_NUM, { .num = 381.0 } },
    { DATA_STR, { .str = "Y" } },
    { DATA_NUM, { .num = 8.0 } },
    { DATA_NUM, { .num = 9.0 } },
    { DATA_NUM, { .num = 17.0 } },
    { DATA_NUM, { .num = 481.0 } },
    { DATA_NUM, { .num = 17.0 } },
    { DATA_NUM, { .num = 9.0 } },
    { DATA_NUM, { .num = 8.0 } },
    { DATA_STR, { .str = "V" } },
    { DATA_NUM, { .num = 64.0 } },
    { DATA_NUM, { .num = 65.0 } },
    { DATA_NUM, { .num = 129.0 } },
    { DATA_NUM, { .num = 257.0 } },
    { DATA_NUM, { .num = 129.0 } },
    { DATA_NUM, { .num = 65.0 } },
    { DATA_NUM, { .num = 64.0 } },
    { DATA_STR, { .str = "X" } },
    { DATA_NUM, { .num = 388.0 } },
    { DATA_NUM, { .num = 69.0 } },
    { DATA_NUM, { .num = 41.0 } },
    { DATA_NUM, { .num = 17.0 } },
    { DATA_NUM, { .num = 41.0 } },
    { DATA_NUM, { .num = 69.0 } },
    { DATA_NUM, { .num = 388.0 } },
    { DATA_STR, { .str = "Z" } },
    { DATA_NUM, { .num = 386.0 } },
    { DATA_NUM, { .num = 322.0 } },
    { DATA_NUM, { .num = 290.0 } },
    { DATA_NUM, { .num = 274.0 } },
    { DATA_NUM, { .num = 266.0 } },
    { DATA_NUM, { .num = 262.0 } },
    { DATA_NUM, { .num = 260.0 } },
    { DATA_STR, { .str = "I" } },
    { DATA_NUM, { .num = 258.0 } },
    { DATA_NUM, { .num = 258.0 } },
    { DATA_NUM, { .num = 258.0 } },
    { DATA_NUM, { .num = 512.0 } },
    { DATA_NUM, { .num = 258.0 } },
    { DATA_NUM, { .num = 258.0 } },
    { DATA_NUM, { .num = 258.0 } },
    { DATA_STR, { .str = "C" } },
    { DATA_NUM, { .num = 125.0 } },
    { DATA_NUM, { .num = 131.0 } },
    { DATA_NUM, { .num = 258.0 } },
    { DATA_NUM, { .num = 258.0 } },
    { DATA_NUM, { .num = 258.0 } },
    { DATA_NUM, { .num = 131.0 } },
    { DATA_NUM, { .num = 69.0 } },
    { DATA_STR, { .str = "J" } },
    { DATA_NUM, { .num = 65.0 } },
    { DATA_NUM, { .num = 129.0 } },
    { DATA_NUM, { .num = 257.0 } },
    { DATA_NUM, { .num = 257.0 } },
    { DATA_NUM, { .num = 257.0 } },
    { DATA_NUM, { .num = 129.0 } },
    { DATA_NUM, { .num = 128.0 } },
    { DATA_STR, { .str = "1" } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 261.0 } },
    { DATA_NUM, { .num = 259.0 } },
    { DATA_NUM, { .num = 512.0 } },
    { DATA_NUM, { .num = 257.0 } },
    { DATA_NUM, { .num = 257.0 } },
    { DATA_STR, { .str = "2" } },
    { DATA_NUM, { .num = 261.0 } },
    { DATA_NUM, { .num = 387.0 } },
    { DATA_NUM, { .num = 322.0 } },
    { DATA_NUM, { .num = 290.0 } },
    { DATA_NUM, { .num = 274.0 } },
    { DATA_NUM, { .num = 267.0 } },
    { DATA_NUM, { .num = 261.0 } },
    { DATA_STR, { .str = "*" } },
    { DATA_NUM, { .num = 69.0 } },
    { DATA_NUM, { .num = 41.0 } },
    { DATA_NUM, { .num = 17.0 } },
    { DATA_NUM, { .num = 512.0 } },
    { DATA_NUM, { .num = 17.0 } },
    { DATA_NUM, { .num = 41.0 } },
    { DATA_NUM, { .num = 69.0 } },
    { DATA_STR, { .str = "3" } },
    { DATA_NUM, { .num = 66.0 } },
    { DATA_NUM, { .num = 130.0 } },
    { DATA_NUM, { .num = 258.0 } },
    { DATA_NUM, { .num = 274.0 } },
    { DATA_NUM, { .num = 266.0 } },
    { DATA_NUM, { .num = 150.0 } },
    { DATA_NUM, { .num = 100.0 } },
    { DATA_STR, { .str = "4" } },
    { DATA_NUM, { .num = 33.0 } },
    { DATA_NUM, { .num = 49.0 } },
    { DATA_NUM, { .num = 41.0 } },
    { DATA_NUM, { .num = 37.0 } },
    { DATA_NUM, { .num = 35.0 } },
    { DATA_NUM, { .num = 512.0 } },
    { DATA_NUM, { .num = 33.0 } },
    { DATA_STR, { .str = "5" } },
    { DATA_NUM, { .num = 160.0 } },
    { DATA_NUM, { .num = 274.0 } },
    { DATA_NUM, { .num = 274.0 } },
    { DATA_NUM, { .num = 274.0 } },
    { DATA_NUM, { .num = 274.0 } },
    { DATA_NUM, { .num = 274.0 } },
    { DATA_NUM, { .num = 226.0 } },
    { DATA_STR, { .str = "6" } },
    { DATA_NUM, { .num = 194.0 } },
    { DATA_NUM, { .num = 291.0 } },
    { DATA_NUM, { .num = 293.0 } },
    { DATA_NUM, { .num = 297.0 } },
    { DATA_NUM, { .num = 305.0 } },
    { DATA_NUM, { .num = 289.0 } },
    { DATA_NUM, { .num = 193.0 } },
    { DATA_STR, { .str = "7" } },
    { DATA_NUM, { .num = 258.0 } },
    { DATA_NUM, { .num = 130.0 } },
    { DATA_NUM, { .num = 66.0 } },
    { DATA_NUM, { .num = 34.0 } },
    { DATA_NUM, { .num = 18.0 } },
    { DATA_NUM, { .num = 10.0 } },
    { DATA_NUM, { .num = 8.0 } },
    { DATA_STR, { .str = "8" } },
    { DATA_NUM, { .num = 69.0 } },
    { DATA_NUM, { .num = 171.0 } },
    { DATA_NUM, { .num = 274.0 } },
    { DATA_NUM, { .num = 274.0 } },
    { DATA_NUM, { .num = 274.0 } },
    { DATA_NUM, { .num = 171.0 } },
    { DATA_NUM, { .num = 69.0 } },
    { DATA_STR, { .str = "9" } },
    { DATA_NUM, { .num = 263.0 } },
    { DATA_NUM, { .num = 138.0 } },
    { DATA_NUM, { .num = 74.0 } },
    { DATA_NUM, { .num = 42.0 } },
    { DATA_NUM, { .num = 26.0 } },
    { DATA_NUM, { .num = 10.0 } },
    { DATA_NUM, { .num = 7.0 } },
    { DATA_STR, { .str = "=" } },
    { DATA_NUM, { .num = 41.0 } },
    { DATA_NUM, { .num = 41.0 } },
    { DATA_NUM, { .num = 41.0 } },
    { DATA_NUM, { .num = 41.0 } },
    { DATA_NUM, { .num = 41.0 } },
    { DATA_NUM, { .num = 41.0 } },
    { DATA_NUM, { .num = 41.0 } },
    { DATA_STR, { .str = "!" } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 384.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_STR, { .str = "0" } },
    { DATA_NUM, { .num = 57.0 } },
    { DATA_NUM, { .num = 69.0 } },
    { DATA_NUM, { .num = 131.0 } },
    { DATA_NUM, { .num = 258.0 } },
    { DATA_NUM, { .num = 131.0 } },
    { DATA_NUM, { .num = 69.0 } },
    { DATA_NUM, { .num = 57.0 } },
    { DATA_STR, { .str = "." } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 129.0 } },
    { DATA_NUM, { .num = 449.0 } },
    { DATA_NUM, { .num = 129.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 1.0 } },
};
static int data_ptr = 0;

static void read_numeric(double *var) {
    if (data_ptr < sizeof(program_data)/sizeof(program_data[0])) {
        if (program_data[data_ptr].type == DATA_NUM) *var = program_data[data_ptr].u.num;
        else *var = atof(program_data[data_ptr].u.str);
        data_ptr++;
    }
}

static void read_string(char *var, size_t max_len) {
    if (data_ptr < sizeof(program_data)/sizeof(program_data[0])) {
        if (program_data[data_ptr].type == DATA_STR) strncpy(var, program_data[data_ptr].u.str, max_len - 1);
        else snprintf(var, max_len, "%g", program_data[data_ptr].u.num);
        var[max_len - 1] = '\0';
        data_ptr++;
    }
}

/* Global variables */
static double A, B, F, G1, H, I, I1, J, K, O, P, S, T, T1, U, X, Y;
static char A_str[256] = {0};
static char L_str[256] = {0};
static char M_str[256] = {0};
static char O_str[256] = {0};
static char P_str[256] = {0};
static char S_str[256] = {0};
static char X_str[256] = {0};
static double F_arr[20000] = {0};
static double J_arr[20000] = {0};
static double S_arr[20000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 INPUT "HORIZONTAL";X */
line_10:;
    printf("%s", "HORIZONTAL"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &X);
    /* BASIC: 20 INPUT "VERTICAL";Y */
line_20:;
    printf("%s", "VERTICAL"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &Y);
    /* BASIC: 21 INPUT "CENTERED";L$ */
line_21:;
    printf("%s", "CENTERED"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", L_str);
    /* BASIC: 22 G1=0:IF L$>"P" THEN G1=1 */
line_22:;
    G1 = 0;
    if (strcmp(L_str, "P") > 0) { G1 = 1; }
    /* BASIC: 23 INPUT "CHARACTER (TYPE 'ALL' IF YOU WANT CHARACTER BEING PRINTED)";M$ */
line_23:;
    printf("%s", "CHARACTER (TYPE 'ALL' IF YOU WANT CHARACTER BEING PRINTED)"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", M_str);
    /* BASIC: 29 PRINT "STATEMENT"; */
line_29:;
    printf("%s", "STATEMENT");
    /* BASIC: 30 INPUT A$ */
line_30:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    /* BASIC: 35 INPUT "SET PAGE";O$ */
line_35:;
    printf("%s", "SET PAGE"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", O_str);
    /* BASIC: 40 A=ASC(LEFT$(A$,1)) */
line_40:;
    A = basic_ASC(basic_LEFT(A_str,1));
    /* BASIC: 50 REM */
line_50:;
    // REM
    /* BASIC: 60 REM */
line_60:;
    // REM
    /* BASIC: 70 FOR T=1 TO LEN(A$) */
line_70:;
    T = 1; for_loop_T_70: if (((1) >= 0 && T > (basic_LEN(A_str))) || ((1) < 0 && T < (basic_LEN(A_str)))) goto end_for_T_70;
    /* BASIC: 80 P$=MID$(A$,T,1) */
line_80:;
    str_assign(P_str, sizeof(P_str), basic_MID(A_str,T,1));
    /* BASIC: 90 FOR O=1 TO 50 */
line_90:;
    O = 1; for_loop_O_90: if (((1) >= 0 && O > (50)) || ((1) < 0 && O < (50))) goto end_for_O_90;
    /* BASIC: 95 READ S$,S(1),S(2),S(3),S(4),S(5),S(6),S(7) */
line_95:;
    read_string(S_str, sizeof(S_str)); read_numeric(&(S_arr[(int)(1)])); read_numeric(&(S_arr[(int)(2)])); read_numeric(&(S_arr[(int)(3)])); read_numeric(&(S_arr[(int)(4)])); read_numeric(&(S_arr[(int)(5)])); read_numeric(&(S_arr[(int)(6)])); read_numeric(&(S_arr[(int)(7)]));
    /* BASIC: 96 IF P$=" " THEN 812 */
line_96:;
    if (strcmp(P_str, " ") == 0) { goto line_812; }
    /* BASIC: 100 IF P$=S$ THEN 200 */
line_100:;
    if (strcmp(P_str, S_str) == 0) { goto line_200; }
    /* BASIC: 120 NEXT O */
line_120:;
    O += (1); goto for_loop_O_90; end_for_O_90:;
    /* BASIC: 200 RESTORE */
line_200:;
    data_ptr = 0;
    /* BASIC: 201 X$=M$ */
line_201:;
    str_assign(X_str, sizeof(X_str), M_str);
    /* BASIC: 202 IF M$="ALL" THEN X$=S$ */
line_202:;
    if (strcmp(M_str, "ALL") == 0) { str_assign(X_str, sizeof(X_str), S_str); }
    /* BASIC: 205 FOR U=1 TO 7 */
line_205:;
    U = 1; for_loop_U_205: if (((1) >= 0 && U > (7)) || ((1) < 0 && U < (7))) goto end_for_U_205;
    /* BASIC: 210 FOR K=8 TO 0 STEP -1 */
line_210:;
    K = 8; for_loop_K_210: if (((-1) >= 0 && K > (0)) || ((-1) < 0 && K < (0))) goto end_for_K_210;
    /* BASIC: 230 IF 2^K<S(U) THEN 270 */
line_230:;
    if (pow(2, K)<S_arr[(int)(U)]) { goto line_270; }
    /* BASIC: 240 J(9-K)=0 */
line_240:;
    J_arr[(int)(9-K)] = 0;
    /* BASIC: 250 GOTO 280 */
line_250:;
    goto line_280;
    /* BASIC: 270 J(9-K)=1: S(U)=S(U)-2^K */
line_270:;
    J_arr[(int)(9-K)] = 1;
    S_arr[(int)(U)] = S_arr[(int)(U)]-pow(2, K);
    /* BASIC: 272 IF S(U)=1 THEN 815 */
line_272:;
    if (S_arr[(int)(U)]==1) { goto line_815; }
    /* BASIC: 280 NEXT K */
line_280:;
    K += (-1); goto for_loop_K_210; end_for_K_210:;
    /* BASIC: 445 FOR T1=1 TO X */
line_445:;
    T1 = 1; for_loop_T1_445: if (((1) >= 0 && T1 > (X)) || ((1) < 0 && T1 < (X))) goto end_for_T1_445;
    /* BASIC: 447 PRINT TAB((63-4.5*Y)*G1/(LEN(X$))+1); */
line_447:;
    { int _t; for(_t=0; _t<(63-4.5*Y)*G1/(basic_LEN(X_str))+1; _t++) printf(" "); }
    /* BASIC: 450 FOR B=1 TO F(U) */
line_450:;
    B = 1; for_loop_B_450: if (((1) >= 0 && B > (F_arr[(int)(U)])) || ((1) < 0 && B < (F_arr[(int)(U)]))) goto end_for_B_450;
    /* BASIC: 460 IF J(B)=0 THEN 500 */
line_460:;
    if (J_arr[(int)(B)]==0) { goto line_500; }
    /* BASIC: 465 FOR I=1 TO Y: PRINT X$;: NEXT I */
line_465:;
    I = 1; for_loop_I_465: if (((1) >= 0 && I > (Y)) || ((1) < 0 && I < (Y))) goto end_for_I_465;
    printf("%s", X_str);
    I += (1); goto for_loop_I_465; end_for_I_465:;
    /* BASIC: 470 GOTO 600 */
line_470:;
    goto line_600;
    /* BASIC: 500 FOR I=1 TO Y */
line_500:;
    I = 1; for_loop_I_500: if (((1) >= 0 && I > (Y)) || ((1) < 0 && I < (Y))) goto end_for_I_500;
    /* BASIC: 510 FOR I1=1 TO LEN(X$) */
line_510:;
    I1 = 1; for_loop_I1_510: if (((1) >= 0 && I1 > (basic_LEN(X_str))) || ((1) < 0 && I1 < (basic_LEN(X_str)))) goto end_for_I1_510;
    /* BASIC: 520 PRINT " ";: NEXT I1 */
line_520:;
    printf("%s", " ");
    I1 += (1); goto for_loop_I1_510; end_for_I1_510:;
    /* BASIC: 530 NEXT I */
line_530:;
    I += (1); goto for_loop_I_500; end_for_I_500:;
    /* BASIC: 600 NEXT B */
line_600:;
    B += (1); goto for_loop_B_450; end_for_B_450:;
    /* BASIC: 620 PRINT */
line_620:;
    printf("\n");
    /* BASIC: 630 NEXT T1 */
line_630:;
    T1 += (1); goto for_loop_T1_445; end_for_T1_445:;
    /* BASIC: 700 NEXT U */
line_700:;
    U += (1); goto for_loop_U_205; end_for_U_205:;
    /* BASIC: 750 FOR H=1 TO 2*X: PRINT: NEXT H */
line_750:;
    H = 1; for_loop_H_750: if (((1) >= 0 && H > (2*X)) || ((1) < 0 && H < (2*X))) goto end_for_H_750;
    printf("\n");
    H += (1); goto for_loop_H_750; end_for_H_750:;
    /* BASIC: 800 NEXT T */
line_800:;
    T += (1); goto for_loop_T_70; end_for_T_70:;
    /* BASIC: 806 FOR H=1 TO 75: PRINT: NEXT H */
line_806:;
    H = 1; for_loop_H_806: if (((1) >= 0 && H > (75)) || ((1) < 0 && H < (75))) goto end_for_H_806;
    printf("\n");
    H += (1); goto for_loop_H_806; end_for_H_806:;
    /* BASIC: 810 END */
line_810:;
    exit(0);
    /* BASIC: 812 FOR H=1 TO 7*X: PRINT: NEXT H */
line_812:;
    H = 1; for_loop_H_812: if (((1) >= 0 && H > (7*X)) || ((1) < 0 && H < (7*X))) goto end_for_H_812;
    printf("\n");
    H += (1); goto for_loop_H_812; end_for_H_812:;
    /* BASIC: 813 GOTO 800 */
line_813:;
    goto line_800;
    /* BASIC: 815 F(U)=9-K: GOTO 445 */
line_815:;
    F_arr[(int)(U)] = 9-K;
    goto line_445;
    /* BASIC: 899 DATA " ",0,0,0,0,0,0,0 */
line_899:;
    /* UNTRANSLATED: DATA " ",0,0,0,0,0,0,0 */
    /* BASIC: 900 DATA "A",505,37,35,34,35,37,505 */
line_900:;
    /* UNTRANSLATED: DATA "A",505,37,35,34,35,37,505 */
    /* BASIC: 901 DATA "G",125,131,258,258,290,163,101 */
line_901:;
    /* UNTRANSLATED: DATA "G",125,131,258,258,290,163,101 */
    /* BASIC: 902 DATA "E",512,274,274,274,274,258,258 */
line_902:;
    /* UNTRANSLATED: DATA "E",512,274,274,274,274,258,258 */
    /* BASIC: 903 DATA "T",2,2,2,512,2,2,2 */
line_903:;
    /* UNTRANSLATED: DATA "T",2,2,2,512,2,2,2 */
    /* BASIC: 904 DATA "W",256,257,129,65,129,257,256 */
line_904:;
    /* UNTRANSLATED: DATA "W",256,257,129,65,129,257,256 */
    /* BASIC: 905 DATA "L",512,257,257,257,257,257,257 */
line_905:;
    /* UNTRANSLATED: DATA "L",512,257,257,257,257,257,257 */
    /* BASIC: 906 DATA "S",69,139,274,274,274,163,69 */
line_906:;
    /* UNTRANSLATED: DATA "S",69,139,274,274,274,163,69 */
    /* BASIC: 907 DATA "O",125,131,258,258,258,131,125 */
line_907:;
    /* UNTRANSLATED: DATA "O",125,131,258,258,258,131,125 */
    /* BASIC: 908 DATA "N",512,7,9,17,33,193,512 */
line_908:;
    /* UNTRANSLATED: DATA "N",512,7,9,17,33,193,512 */
    /* BASIC: 909 DATA "F",512,18,18,18,18,2,2 */
line_909:;
    /* UNTRANSLATED: DATA "F",512,18,18,18,18,2,2 */
    /* BASIC: 910 DATA "K",512,17,17,41,69,131,258 */
line_910:;
    /* UNTRANSLATED: DATA "K",512,17,17,41,69,131,258 */
    /* BASIC: 911 DATA "B",512,274,274,274,274,274,239 */
line_911:;
    /* UNTRANSLATED: DATA "B",512,274,274,274,274,274,239 */
    /* BASIC: 912 DATA "D",512,258,258,258,258,131,125 */
line_912:;
    /* UNTRANSLATED: DATA "D",512,258,258,258,258,131,125 */
    /* BASIC: 913 DATA "H",512,17,17,17,17,17,512 */
line_913:;
    /* UNTRANSLATED: DATA "H",512,17,17,17,17,17,512 */
    /* BASIC: 914 DATA "M",512,7,13,25,13,7,512 */
line_914:;
    /* UNTRANSLATED: DATA "M",512,7,13,25,13,7,512 */
    /* BASIC: 915 DATA "?",5,3,2,354,18,11,5 */
line_915:;
    /* UNTRANSLATED: DATA "?",5,3,2,354,18,11,5 */
    /* BASIC: 916 DATA "U",128,129,257,257,257,129,128 */
line_916:;
    /* UNTRANSLATED: DATA "U",128,129,257,257,257,129,128 */
    /* BASIC: 917 DATA "R",512,18,18,50,82,146,271 */
line_917:;
    /* UNTRANSLATED: DATA "R",512,18,18,50,82,146,271 */
    /* BASIC: 918 DATA "P",512,18,18,18,18,18,15 */
line_918:;
    /* UNTRANSLATED: DATA "P",512,18,18,18,18,18,15 */
    /* BASIC: 919 DATA "Q",125,131,258,258,322,131,381 */
line_919:;
    /* UNTRANSLATED: DATA "Q",125,131,258,258,322,131,381 */
    /* BASIC: 920 DATA "Y",8,9,17,481,17,9,8 */
line_920:;
    /* UNTRANSLATED: DATA "Y",8,9,17,481,17,9,8 */
    /* BASIC: 921 DATA "V",64,65,129,257,129,65,64 */
line_921:;
    /* UNTRANSLATED: DATA "V",64,65,129,257,129,65,64 */
    /* BASIC: 922 DATA "X",388,69,41,17,41,69,388 */
line_922:;
    /* UNTRANSLATED: DATA "X",388,69,41,17,41,69,388 */
    /* BASIC: 923 DATA "Z",386,322,290,274,266,262,260 */
line_923:;
    /* UNTRANSLATED: DATA "Z",386,322,290,274,266,262,260 */
    /* BASIC: 924 DATA "I",258,258,258,512,258,258,258 */
line_924:;
    /* UNTRANSLATED: DATA "I",258,258,258,512,258,258,258 */
    /* BASIC: 925 DATA "C",125,131,258,258,258,131,69 */
line_925:;
    /* UNTRANSLATED: DATA "C",125,131,258,258,258,131,69 */
    /* BASIC: 926 DATA "J",65,129,257,257,257,129,128 */
line_926:;
    /* UNTRANSLATED: DATA "J",65,129,257,257,257,129,128 */
    /* BASIC: 927 DATA "1",0,0,261,259,512,257,257 */
line_927:;
    /* UNTRANSLATED: DATA "1",0,0,261,259,512,257,257 */
    /* BASIC: 928 DATA "2",261,387,322,290,274,267,261 */
line_928:;
    /* UNTRANSLATED: DATA "2",261,387,322,290,274,267,261 */
    /* BASIC: 929 DATA "*",69,41,17,512,17,41,69 */
line_929:;
    /* UNTRANSLATED: DATA "*",69,41,17,512,17,41,69 */
    /* BASIC: 930 DATA "3",66,130,258,274,266,150,100 */
line_930:;
    /* UNTRANSLATED: DATA "3",66,130,258,274,266,150,100 */
    /* BASIC: 931 DATA "4",33,49,41,37,35,512,33 */
line_931:;
    /* UNTRANSLATED: DATA "4",33,49,41,37,35,512,33 */
    /* BASIC: 932 DATA "5",160,274,274,274,274,274,226 */
line_932:;
    /* UNTRANSLATED: DATA "5",160,274,274,274,274,274,226 */
    /* BASIC: 933 DATA "6",194,291,293,297,305,289,193 */
line_933:;
    /* UNTRANSLATED: DATA "6",194,291,293,297,305,289,193 */
    /* BASIC: 934 DATA "7",258,130,66,34,18,10,8 */
line_934:;
    /* UNTRANSLATED: DATA "7",258,130,66,34,18,10,8 */
    /* BASIC: 935 DATA "8",69,171,274,274,274,171,69 */
line_935:;
    /* UNTRANSLATED: DATA "8",69,171,274,274,274,171,69 */
    /* BASIC: 936 DATA "9",263,138,74,42,26,10,7 */
line_936:;
    /* UNTRANSLATED: DATA "9",263,138,74,42,26,10,7 */
    /* BASIC: 937 DATA "=",41,41,41,41,41,41,41 */
line_937:;
    /* UNTRANSLATED: DATA "=",41,41,41,41,41,41,41 */
    /* BASIC: 938 DATA "!",1,1,1,384,1,1,1 */
line_938:;
    /* UNTRANSLATED: DATA "!",1,1,1,384,1,1,1 */
    /* BASIC: 939 DATA "0",57,69,131,258,131,69,57 */
line_939:;
    /* UNTRANSLATED: DATA "0",57,69,131,258,131,69,57 */
    /* BASIC: 940 DATA ".",1,1,129,449,129,1,1 */
line_940:;
    /* UNTRANSLATED: DATA ".",1,1,129,449,129,1,1 */
    /* BASIC: 1000 S TO P */
line_1000:;
    /* UNTRANSLATED: S TO P */
    /* BASIC: 1002 END */
line_1002:;
    exit(0);

    return 0;
}
