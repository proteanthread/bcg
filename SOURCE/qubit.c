/*
 * Transpiled from qubit.bas
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

static DataItem program_data[320] = {
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 49.0 } },
    { DATA_NUM, { .num = 52.0 } },
    { DATA_NUM, { .num = 4.0 } },
    { DATA_NUM, { .num = 13.0 } },
    { DATA_NUM, { .num = 61.0 } },
    { DATA_NUM, { .num = 64.0 } },
    { DATA_NUM, { .num = 16.0 } },
    { DATA_NUM, { .num = 22.0 } },
    { DATA_NUM, { .num = 39.0 } },
    { DATA_NUM, { .num = 23.0 } },
    { DATA_NUM, { .num = 38.0 } },
    { DATA_NUM, { .num = 26.0 } },
    { DATA_NUM, { .num = 42.0 } },
    { DATA_NUM, { .num = 27.0 } },
    { DATA_NUM, { .num = 43.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 2.0 } },
    { DATA_NUM, { .num = 3.0 } },
    { DATA_NUM, { .num = 4.0 } },
    { DATA_NUM, { .num = 5.0 } },
    { DATA_NUM, { .num = 6.0 } },
    { DATA_NUM, { .num = 7.0 } },
    { DATA_NUM, { .num = 8.0 } },
    { DATA_NUM, { .num = 9.0 } },
    { DATA_NUM, { .num = 10.0 } },
    { DATA_NUM, { .num = 11.0 } },
    { DATA_NUM, { .num = 12.0 } },
    { DATA_NUM, { .num = 13.0 } },
    { DATA_NUM, { .num = 14.0 } },
    { DATA_NUM, { .num = 15.0 } },
    { DATA_NUM, { .num = 16.0 } },
    { DATA_NUM, { .num = 17.0 } },
    { DATA_NUM, { .num = 18.0 } },
    { DATA_NUM, { .num = 19.0 } },
    { DATA_NUM, { .num = 20.0 } },
    { DATA_NUM, { .num = 21.0 } },
    { DATA_NUM, { .num = 22.0 } },
    { DATA_NUM, { .num = 23.0 } },
    { DATA_NUM, { .num = 24.0 } },
    { DATA_NUM, { .num = 25.0 } },
    { DATA_NUM, { .num = 26.0 } },
    { DATA_NUM, { .num = 27.0 } },
    { DATA_NUM, { .num = 28.0 } },
    { DATA_NUM, { .num = 29.0 } },
    { DATA_NUM, { .num = 30.0 } },
    { DATA_NUM, { .num = 31.0 } },
    { DATA_NUM, { .num = 32.0 } },
    { DATA_NUM, { .num = 33.0 } },
    { DATA_NUM, { .num = 34.0 } },
    { DATA_NUM, { .num = 35.0 } },
    { DATA_NUM, { .num = 36.0 } },
    { DATA_NUM, { .num = 37.0 } },
    { DATA_NUM, { .num = 38.0 } },
    { DATA_NUM, { .num = 39.0 } },
    { DATA_NUM, { .num = 40.0 } },
    { DATA_NUM, { .num = 41.0 } },
    { DATA_NUM, { .num = 42.0 } },
    { DATA_NUM, { .num = 43.0 } },
    { DATA_NUM, { .num = 44.0 } },
    { DATA_NUM, { .num = 45.0 } },
    { DATA_NUM, { .num = 46.0 } },
    { DATA_NUM, { .num = 47.0 } },
    { DATA_NUM, { .num = 48.0 } },
    { DATA_NUM, { .num = 49.0 } },
    { DATA_NUM, { .num = 50.0 } },
    { DATA_NUM, { .num = 51.0 } },
    { DATA_NUM, { .num = 52.0 } },
    { DATA_NUM, { .num = 53.0 } },
    { DATA_NUM, { .num = 54.0 } },
    { DATA_NUM, { .num = 55.0 } },
    { DATA_NUM, { .num = 56.0 } },
    { DATA_NUM, { .num = 57.0 } },
    { DATA_NUM, { .num = 58.0 } },
    { DATA_NUM, { .num = 59.0 } },
    { DATA_NUM, { .num = 60.0 } },
    { DATA_NUM, { .num = 61.0 } },
    { DATA_NUM, { .num = 62.0 } },
    { DATA_NUM, { .num = 63.0 } },
    { DATA_NUM, { .num = 64.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 17.0 } },
    { DATA_NUM, { .num = 33.0 } },
    { DATA_NUM, { .num = 49.0 } },
    { DATA_NUM, { .num = 5.0 } },
    { DATA_NUM, { .num = 21.0 } },
    { DATA_NUM, { .num = 37.0 } },
    { DATA_NUM, { .num = 53.0 } },
    { DATA_NUM, { .num = 9.0 } },
    { DATA_NUM, { .num = 25.0 } },
    { DATA_NUM, { .num = 41.0 } },
    { DATA_NUM, { .num = 57.0 } },
    { DATA_NUM, { .num = 13.0 } },
    { DATA_NUM, { .num = 29.0 } },
    { DATA_NUM, { .num = 45.0 } },
    { DATA_NUM, { .num = 61.0 } },
    { DATA_NUM, { .num = 2.0 } },
    { DATA_NUM, { .num = 18.0 } },
    { DATA_NUM, { .num = 34.0 } },
    { DATA_NUM, { .num = 50.0 } },
    { DATA_NUM, { .num = 6.0 } },
    { DATA_NUM, { .num = 22.0 } },
    { DATA_NUM, { .num = 38.0 } },
    { DATA_NUM, { .num = 54.0 } },
    { DATA_NUM, { .num = 10.0 } },
    { DATA_NUM, { .num = 26.0 } },
    { DATA_NUM, { .num = 42.0 } },
    { DATA_NUM, { .num = 58.0 } },
    { DATA_NUM, { .num = 14.0 } },
    { DATA_NUM, { .num = 30.0 } },
    { DATA_NUM, { .num = 46.0 } },
    { DATA_NUM, { .num = 62.0 } },
    { DATA_NUM, { .num = 3.0 } },
    { DATA_NUM, { .num = 19.0 } },
    { DATA_NUM, { .num = 35.0 } },
    { DATA_NUM, { .num = 51.0 } },
    { DATA_NUM, { .num = 7.0 } },
    { DATA_NUM, { .num = 23.0 } },
    { DATA_NUM, { .num = 39.0 } },
    { DATA_NUM, { .num = 55.0 } },
    { DATA_NUM, { .num = 11.0 } },
    { DATA_NUM, { .num = 27.0 } },
    { DATA_NUM, { .num = 43.0 } },
    { DATA_NUM, { .num = 59.0 } },
    { DATA_NUM, { .num = 15.0 } },
    { DATA_NUM, { .num = 31.0 } },
    { DATA_NUM, { .num = 47.0 } },
    { DATA_NUM, { .num = 63.0 } },
    { DATA_NUM, { .num = 4.0 } },
    { DATA_NUM, { .num = 20.0 } },
    { DATA_NUM, { .num = 36.0 } },
    { DATA_NUM, { .num = 52.0 } },
    { DATA_NUM, { .num = 8.0 } },
    { DATA_NUM, { .num = 24.0 } },
    { DATA_NUM, { .num = 40.0 } },
    { DATA_NUM, { .num = 56.0 } },
    { DATA_NUM, { .num = 12.0 } },
    { DATA_NUM, { .num = 28.0 } },
    { DATA_NUM, { .num = 44.0 } },
    { DATA_NUM, { .num = 60.0 } },
    { DATA_NUM, { .num = 16.0 } },
    { DATA_NUM, { .num = 32.0 } },
    { DATA_NUM, { .num = 48.0 } },
    { DATA_NUM, { .num = 64.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 5.0 } },
    { DATA_NUM, { .num = 9.0 } },
    { DATA_NUM, { .num = 13.0 } },
    { DATA_NUM, { .num = 17.0 } },
    { DATA_NUM, { .num = 21.0 } },
    { DATA_NUM, { .num = 25.0 } },
    { DATA_NUM, { .num = 29.0 } },
    { DATA_NUM, { .num = 33.0 } },
    { DATA_NUM, { .num = 37.0 } },
    { DATA_NUM, { .num = 41.0 } },
    { DATA_NUM, { .num = 45.0 } },
    { DATA_NUM, { .num = 49.0 } },
    { DATA_NUM, { .num = 53.0 } },
    { DATA_NUM, { .num = 57.0 } },
    { DATA_NUM, { .num = 61.0 } },
    { DATA_NUM, { .num = 2.0 } },
    { DATA_NUM, { .num = 6.0 } },
    { DATA_NUM, { .num = 10.0 } },
    { DATA_NUM, { .num = 14.0 } },
    { DATA_NUM, { .num = 18.0 } },
    { DATA_NUM, { .num = 22.0 } },
    { DATA_NUM, { .num = 26.0 } },
    { DATA_NUM, { .num = 30.0 } },
    { DATA_NUM, { .num = 34.0 } },
    { DATA_NUM, { .num = 38.0 } },
    { DATA_NUM, { .num = 42.0 } },
    { DATA_NUM, { .num = 46.0 } },
    { DATA_NUM, { .num = 50.0 } },
    { DATA_NUM, { .num = 54.0 } },
    { DATA_NUM, { .num = 58.0 } },
    { DATA_NUM, { .num = 62.0 } },
    { DATA_NUM, { .num = 3.0 } },
    { DATA_NUM, { .num = 7.0 } },
    { DATA_NUM, { .num = 11.0 } },
    { DATA_NUM, { .num = 15.0 } },
    { DATA_NUM, { .num = 19.0 } },
    { DATA_NUM, { .num = 23.0 } },
    { DATA_NUM, { .num = 27.0 } },
    { DATA_NUM, { .num = 31.0 } },
    { DATA_NUM, { .num = 35.0 } },
    { DATA_NUM, { .num = 39.0 } },
    { DATA_NUM, { .num = 43.0 } },
    { DATA_NUM, { .num = 47.0 } },
    { DATA_NUM, { .num = 51.0 } },
    { DATA_NUM, { .num = 55.0 } },
    { DATA_NUM, { .num = 59.0 } },
    { DATA_NUM, { .num = 63.0 } },
    { DATA_NUM, { .num = 4.0 } },
    { DATA_NUM, { .num = 8.0 } },
    { DATA_NUM, { .num = 12.0 } },
    { DATA_NUM, { .num = 16.0 } },
    { DATA_NUM, { .num = 20.0 } },
    { DATA_NUM, { .num = 24.0 } },
    { DATA_NUM, { .num = 28.0 } },
    { DATA_NUM, { .num = 32.0 } },
    { DATA_NUM, { .num = 36.0 } },
    { DATA_NUM, { .num = 40.0 } },
    { DATA_NUM, { .num = 44.0 } },
    { DATA_NUM, { .num = 48.0 } },
    { DATA_NUM, { .num = 52.0 } },
    { DATA_NUM, { .num = 56.0 } },
    { DATA_NUM, { .num = 60.0 } },
    { DATA_NUM, { .num = 64.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 6.0 } },
    { DATA_NUM, { .num = 11.0 } },
    { DATA_NUM, { .num = 16.0 } },
    { DATA_NUM, { .num = 17.0 } },
    { DATA_NUM, { .num = 22.0 } },
    { DATA_NUM, { .num = 27.0 } },
    { DATA_NUM, { .num = 32.0 } },
    { DATA_NUM, { .num = 33.0 } },
    { DATA_NUM, { .num = 38.0 } },
    { DATA_NUM, { .num = 43.0 } },
    { DATA_NUM, { .num = 48.0 } },
    { DATA_NUM, { .num = 49.0 } },
    { DATA_NUM, { .num = 54.0 } },
    { DATA_NUM, { .num = 59.0 } },
    { DATA_NUM, { .num = 64.0 } },
    { DATA_NUM, { .num = 13.0 } },
    { DATA_NUM, { .num = 10.0 } },
    { DATA_NUM, { .num = 7.0 } },
    { DATA_NUM, { .num = 4.0 } },
    { DATA_NUM, { .num = 29.0 } },
    { DATA_NUM, { .num = 26.0 } },
    { DATA_NUM, { .num = 23.0 } },
    { DATA_NUM, { .num = 20.0 } },
    { DATA_NUM, { .num = 45.0 } },
    { DATA_NUM, { .num = 42.0 } },
    { DATA_NUM, { .num = 39.0 } },
    { DATA_NUM, { .num = 36.0 } },
    { DATA_NUM, { .num = 61.0 } },
    { DATA_NUM, { .num = 58.0 } },
    { DATA_NUM, { .num = 55.0 } },
    { DATA_NUM, { .num = 52.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 21.0 } },
    { DATA_NUM, { .num = 41.0 } },
    { DATA_NUM, { .num = 61.0 } },
    { DATA_NUM, { .num = 2.0 } },
    { DATA_NUM, { .num = 22.0 } },
    { DATA_NUM, { .num = 42.0 } },
    { DATA_NUM, { .num = 62.0 } },
    { DATA_NUM, { .num = 3.0 } },
    { DATA_NUM, { .num = 23.0 } },
    { DATA_NUM, { .num = 43.0 } },
    { DATA_NUM, { .num = 63.0 } },
    { DATA_NUM, { .num = 4.0 } },
    { DATA_NUM, { .num = 24.0 } },
    { DATA_NUM, { .num = 44.0 } },
    { DATA_NUM, { .num = 64.0 } },
    { DATA_NUM, { .num = 49.0 } },
    { DATA_NUM, { .num = 37.0 } },
    { DATA_NUM, { .num = 25.0 } },
    { DATA_NUM, { .num = 13.0 } },
    { DATA_NUM, { .num = 50.0 } },
    { DATA_NUM, { .num = 38.0 } },
    { DATA_NUM, { .num = 26.0 } },
    { DATA_NUM, { .num = 14.0 } },
    { DATA_NUM, { .num = 51.0 } },
    { DATA_NUM, { .num = 39.0 } },
    { DATA_NUM, { .num = 27.0 } },
    { DATA_NUM, { .num = 15.0 } },
    { DATA_NUM, { .num = 52.0 } },
    { DATA_NUM, { .num = 40.0 } },
    { DATA_NUM, { .num = 28.0 } },
    { DATA_NUM, { .num = 16.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 18.0 } },
    { DATA_NUM, { .num = 35.0 } },
    { DATA_NUM, { .num = 52.0 } },
    { DATA_NUM, { .num = 5.0 } },
    { DATA_NUM, { .num = 22.0 } },
    { DATA_NUM, { .num = 39.0 } },
    { DATA_NUM, { .num = 56.0 } },
    { DATA_NUM, { .num = 9.0 } },
    { DATA_NUM, { .num = 26.0 } },
    { DATA_NUM, { .num = 43.0 } },
    { DATA_NUM, { .num = 60.0 } },
    { DATA_NUM, { .num = 13.0 } },
    { DATA_NUM, { .num = 30.0 } },
    { DATA_NUM, { .num = 47.0 } },
    { DATA_NUM, { .num = 64.0 } },
    { DATA_NUM, { .num = 49.0 } },
    { DATA_NUM, { .num = 34.0 } },
    { DATA_NUM, { .num = 19.0 } },
    { DATA_NUM, { .num = 4.0 } },
    { DATA_NUM, { .num = 53.0 } },
    { DATA_NUM, { .num = 38.0 } },
    { DATA_NUM, { .num = 23.0 } },
    { DATA_NUM, { .num = 8.0 } },
    { DATA_NUM, { .num = 57.0 } },
    { DATA_NUM, { .num = 42.0 } },
    { DATA_NUM, { .num = 27.0 } },
    { DATA_NUM, { .num = 12.0 } },
    { DATA_NUM, { .num = 61.0 } },
    { DATA_NUM, { .num = 46.0 } },
    { DATA_NUM, { .num = 31.0 } },
    { DATA_NUM, { .num = 16.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 22.0 } },
    { DATA_NUM, { .num = 43.0 } },
    { DATA_NUM, { .num = 64.0 } },
    { DATA_NUM, { .num = 16.0 } },
    { DATA_NUM, { .num = 27.0 } },
    { DATA_NUM, { .num = 38.0 } },
    { DATA_NUM, { .num = 49.0 } },
    { DATA_NUM, { .num = 4.0 } },
    { DATA_NUM, { .num = 23.0 } },
    { DATA_NUM, { .num = 42.0 } },
    { DATA_NUM, { .num = 61.0 } },
    { DATA_NUM, { .num = 13.0 } },
    { DATA_NUM, { .num = 26.0 } },
    { DATA_NUM, { .num = 39.0 } },
    { DATA_NUM, { .num = 52.0 } },
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
static int gosub_stack[256];
static int gosub_sp = 0;
static double A, I, I1, J, J1, J2, J3, J4, K, K1, K2, K3, L, LET, M, O, P, Q, S, X, XX, Y, Z;
static char C_str[256] = {0};
static char S_str[256] = {0};
static char X_str[256] = {0};
static double L_arr[20000] = {0};
static double M_arr[20000] = {0};
static double X_arr[20000] = {0};
static double Y_arr[20000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 50 PRINT CHR$(26):REM WIDTH 80 */
line_50:;
    printf("%s", basic_CHR(26)); printf("\n");
    // REM WIDTH 80
    /* BASIC: 100 PRINT TAB(33);"QUBIC":PRINT */
line_100:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "QUBIC"); printf("\n");
    printf("\n");
    /* BASIC: 110 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_110:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 120 PRINT:PRINT:PRINT */
line_120:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 210 PRINT "DO YOU WANT INSTRUCTIONS"; */
line_210:;
    printf("%s", "DO YOU WANT INSTRUCTIONS");
    /* BASIC: 220 INPUT C$ */
line_220:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", C_str);
    /* BASIC: 230 IF LEFT$(C$,1)="N" THEN 315 */
line_230:;
    if (strcmp(basic_LEFT(C_str,1), "N") == 0) { goto line_315; }
    /* BASIC: 240 IF LEFT$(C$,1)="Y" THEN 265 */
line_240:;
    if (strcmp(basic_LEFT(C_str,1), "Y") == 0) { goto line_265; }
    /* BASIC: 250 PRINT "INCORRECT ANSWER.  PLEASE TYPE 'YES' OR 'NO'"; */
line_250:;
    printf("%s", "INCORRECT ANSWER.  PLEASE TYPE 'YES' OR 'NO'");
    /* BASIC: 260 GOTO 220 */
line_260:;
    goto line_220;
    /* BASIC: 265 PRINT */
line_265:;
    printf("\n");
    /* BASIC: 270 PRINT "THE GAME IS TIC-TAC-TOE IN A 4 X 4 X 4 CUBE." */
line_270:;
    printf("%s", "THE GAME IS TIC-TAC-TOE IN A 4 X 4 X 4 CUBE."); printf("\n");
    /* BASIC: 280 PRINT "EACH MOVE IS INDICATED BY A 3 DIGIT NUMBER, WITH EACH" */
line_280:;
    printf("%s", "EACH MOVE IS INDICATED BY A 3 DIGIT NUMBER, WITH EACH"); printf("\n");
    /* BASIC: 290 PRINT "DIGIT BETWEEN 1 AND 4 INCLUSIVE.  THE DIGITS INDICATE THE" */
line_290:;
    printf("%s", "DIGIT BETWEEN 1 AND 4 INCLUSIVE.  THE DIGITS INDICATE THE"); printf("\n");
    /* BASIC: 300 PRINT "LEVEL, ROW, AND COLUMN, RESPECTIVELY, OF THE OCCUPIED" */
line_300:;
    printf("%s", "LEVEL, ROW, AND COLUMN, RESPECTIVELY, OF THE OCCUPIED"); printf("\n");
    /* BASIC: 305 PRINT "PLACE.  " */
line_305:;
    printf("%s", "PLACE.  "); printf("\n");
    /* BASIC: 306 PRINT */
line_306:;
    printf("\n");
    /* BASIC: 307 PRINT "TO PRINT THE PLAYING BOARD, TYPE 0 (ZERO) AS YOUR MOVE." */
line_307:;
    printf("%s", "TO PRINT THE PLAYING BOARD, TYPE 0 (ZERO) AS YOUR MOVE."); printf("\n");
    /* BASIC: 308 PRINT "THE PROGRAM WILL PRINT THE BOARD WITH YOUR MOVES INDI-" */
line_308:;
    printf("%s", "THE PROGRAM WILL PRINT THE BOARD WITH YOUR MOVES INDI-"); printf("\n");
    /* BASIC: 309 PRINT "CATED WITH A (Y), THE MACHINE'S MOVES WITH AN (M), AND" */
line_309:;
    printf("%s", "CATED WITH A (Y), THE MACHINE'S MOVES WITH AN (M), AND"); printf("\n");
    /* BASIC: 310 PRINT "UNUSED SQUARES WITH A ( ).  OUTPUT IS ON PAPER." */
line_310:;
    printf("%s", "UNUSED SQUARES WITH A ( ).  OUTPUT IS ON PAPER."); printf("\n");
    /* BASIC: 311 PRINT */
line_311:;
    printf("\n");
    /* BASIC: 312 PRINT "TO STOP THE PROGRAM RUN, TYPE 1 AS YOUR MOVE." */
line_312:;
    printf("%s", "TO STOP THE PROGRAM RUN, TYPE 1 AS YOUR MOVE."); printf("\n");
    /* BASIC: 313 PRINT:PRINT */
line_313:;
    printf("\n");
    printf("\n");
    /* BASIC: 315 DIM X(64),L(76),M(76,4),Y(16) */
line_315:;
    /* DIM X(64),L(76),M(76,4),Y(16) (handled statically) */
    /* BASIC: 320 FOR I = 1 TO 16 */
line_320:;
    I = 1; for_loop_I_320: if (((1) >= 0 && I > (16)) || ((1) < 0 && I < (16))) goto end_for_I_320;
    /* BASIC: 330 READ Y(I) */
line_330:;
    read_numeric(&(Y_arr[(int)(I)]));
    /* BASIC: 340 NEXT I */
line_340:;
    I += (1); goto for_loop_I_320; end_for_I_320:;
    /* BASIC: 350 FOR I=1 TO 76 */
line_350:;
    I = 1; for_loop_I_350: if (((1) >= 0 && I > (76)) || ((1) < 0 && I < (76))) goto end_for_I_350;
    /* BASIC: 360 FOR J = 1 TO 4 */
line_360:;
    J = 1; for_loop_J_360: if (((1) >= 0 && J > (4)) || ((1) < 0 && J < (4))) goto end_for_J_360;
    /* BASIC: 370 READ M(I,J) */
line_370:;
    read_numeric(&(M_arr[(int)(I) * 100 + (int)(J)]));
    /* BASIC: 380 NEXT J */
line_380:;
    J += (1); goto for_loop_J_360; end_for_J_360:;
    /* BASIC: 390 NEXT I */
line_390:;
    I += (1); goto for_loop_I_350; end_for_I_350:;
    /* BASIC: 400 FOR I = 1 TO 64 */
line_400:;
    I = 1; for_loop_I_400: if (((1) >= 0 && I > (64)) || ((1) < 0 && I < (64))) goto end_for_I_400;
    /* BASIC: 410 LET X (I) =0 */
line_410:;
    /* UNTRANSLATED: LET X (I) =0 */
    /* BASIC: 420 NEXT I */
line_420:;
    I += (1); goto for_loop_I_400; end_for_I_400:;
    /* BASIC: 430 LET Z=1 */
line_430:;
    /* UNTRANSLATED: LET Z=1 */
    /* BASIC: 440 PRINT "DO YOU WANT TO MOVE FIRST"; */
line_440:;
    printf("%s", "DO YOU WANT TO MOVE FIRST");
    /* BASIC: 450 INPUT S$ */
line_450:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", S_str);
    /* BASIC: 460 IF LEFT$(S$,1)="N" THEN 630 */
line_460:;
    if (strcmp(basic_LEFT(S_str,1), "N") == 0) { goto line_630; }
    /* BASIC: 470 IF LEFT$(S$,1)="Y" THEN 500 */
line_470:;
    if (strcmp(basic_LEFT(S_str,1), "Y") == 0) { goto line_500; }
    /* BASIC: 480 PRINT "INCORRECT ANSWER.  PLEASE TYPE 'YES' OR 'NO'."; */
line_480:;
    printf("%s", "INCORRECT ANSWER.  PLEASE TYPE 'YES' OR 'NO'.");
    /* BASIC: 490 GOTO 450 */
line_490:;
    goto line_450;
    /* BASIC: 500 PRINT " " */
line_500:;
    printf("%s", " "); printf("\n");
    /* BASIC: 510 PRINT "YOUR MOVE"; */
line_510:;
    printf("%s", "YOUR MOVE");
    /* BASIC: 520 INPUT J1 */
line_520:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &J1);
    /* BASIC: 521 IF J1=1 THEN 2770 */
line_521:;
    if (J1==1) { goto line_2770; }
    /* BASIC: 522 IF J1<>0 THEN 525 */
line_522:;
    if (J1!=0) { goto line_525; }
    /* BASIC: 523 GOSUB 2550 */
line_523:;
    gosub_stack[gosub_sp++] = 1; goto line_2550; line_ret_1:;
    /* BASIC: 524 GOTO 500 */
line_524:;
    goto line_500;
    /* BASIC: 525 IF J1<111 THEN 2750 */
line_525:;
    if (J1<111) { goto line_2750; }
    /* BASIC: 526 IF J1>444 THEN 2750 */
line_526:;
    if (J1>444) { goto line_2750; }
    /* BASIC: 530 GOSUB 2500 */
line_530:;
    gosub_stack[gosub_sp++] = 2; goto line_2500; line_ret_2:;
    /* BASIC: 540 LET K1=INT(J1/100) */
line_540:;
    /* UNTRANSLATED: LET K1=INT(J1/100) */
    /* BASIC: 550 LET J2=(J1-K1*100) */
line_550:;
    /* UNTRANSLATED: LET J2=(J1-K1*100) */
    /* BASIC: 560 LET K2=INT(J2/10) */
line_560:;
    /* UNTRANSLATED: LET K2=INT(J2/10) */
    /* BASIC: 570 LET K3= J1 - K1*100 -K2*10 */
line_570:;
    /* UNTRANSLATED: LET K3= J1 - K1*100 -K2*10 */
    /* BASIC: 580 LET M=16*K1+4*K2+K3-20 */
line_580:;
    /* UNTRANSLATED: LET M=16*K1+4*K2+K3-20 */
    /* BASIC: 590 IF X(M)=0 THEN 620 */
line_590:;
    if (X_arr[(int)(M)]==0) { goto line_620; }
    /* BASIC: 600 PRINT "THAT SQUARE IS USED, TRY AGAIN." */
line_600:;
    printf("%s", "THAT SQUARE IS USED, TRY AGAIN."); printf("\n");
    /* BASIC: 610 GOTO 500 */
line_610:;
    goto line_500;
    /* BASIC: 620 LET X(M)=1 */
line_620:;
    /* UNTRANSLATED: LET X(M)=1 */
    /* BASIC: 630 GOSUB 1640 */
line_630:;
    gosub_stack[gosub_sp++] = 3; goto line_1640; line_ret_3:;
    /* BASIC: 640 J=1 */
line_640:;
    J = 1;
    /* BASIC: 650 I=1 */
line_650:;
    I = 1;
    /* BASIC: 660 IF J=1 THEN 720 */
line_660:;
    if (J==1) { goto line_720; }
    /* BASIC: 670 IF J=2 THEN 790 */
line_670:;
    if (J==2) { goto line_790; }
    /* BASIC: 680 IF J=3 THEN 930 */
line_680:;
    if (J==3) { goto line_930; }
    /* BASIC: 690 I=I+1: IF I<=76 THEN 660 */
line_690:;
    I = I+1;
    if (I<=76) { goto line_660; }
    /* BASIC: 700 J=J+1: IF J<=3 THEN 650 */
line_700:;
    J = J+1;
    if (J<=3) { goto line_650; }
    /* BASIC: 710 GOTO 1300 */
line_710:;
    goto line_1300;
    /* BASIC: 720 IF L(I)<>4 THEN 690 */
line_720:;
    if (L_arr[(int)(I)]!=4) { goto line_690; }
    /* BASIC: 730 PRINT "YOU WIN AS FOLLOWS"; */
line_730:;
    printf("%s", "YOU WIN AS FOLLOWS");
    /* BASIC: 740 FOR J=1 TO 4 */
line_740:;
    J = 1; for_loop_J_740: if (((1) >= 0 && J > (4)) || ((1) < 0 && J < (4))) goto end_for_J_740;
    /* BASIC: 750 LET M=M(I,J) */
line_750:;
    /* UNTRANSLATED: LET M=M(I,J) */
    /* BASIC: 760 GOSUB 1570 */
line_760:;
    gosub_stack[gosub_sp++] = 4; goto line_1570; line_ret_4:;
    /* BASIC: 770 NEXT J */
line_770:;
    J += (1); goto for_loop_J_740; end_for_J_740:;
    /* BASIC: 780 GOTO 1490 */
line_780:;
    goto line_1490;
    /* BASIC: 790 IF L(I)<>15 THEN 690 */
line_790:;
    if (L_arr[(int)(I)]!=15) { goto line_690; }
    /* BASIC: 800 FOR J=1 TO 4 */
line_800:;
    J = 1; for_loop_J_800: if (((1) >= 0 && J > (4)) || ((1) < 0 && J < (4))) goto end_for_J_800;
    /* BASIC: 810 LET M=M(I,J) */
line_810:;
    /* UNTRANSLATED: LET M=M(I,J) */
    /* BASIC: 820 IF X(M)<>0 THEN 860 */
line_820:;
    if (X_arr[(int)(M)]!=0) { goto line_860; }
    /* BASIC: 830 LET X(M)=5 */
line_830:;
    /* UNTRANSLATED: LET X(M)=5 */
    /* BASIC: 840 PRINT "MACHINE MOVES TO"; */
line_840:;
    printf("%s", "MACHINE MOVES TO");
    /* BASIC: 850 GOSUB 1570 */
line_850:;
    gosub_stack[gosub_sp++] = 5; goto line_1570; line_ret_5:;
    /* BASIC: 860 NEXT J */
line_860:;
    J += (1); goto for_loop_J_800; end_for_J_800:;
    /* BASIC: 870 PRINT ", AND WINS AS FOLLOWS" */
line_870:;
    printf("%s", ", AND WINS AS FOLLOWS"); printf("\n");
    /* BASIC: 880 FOR J=1 TO 4 */
line_880:;
    J = 1; for_loop_J_880: if (((1) >= 0 && J > (4)) || ((1) < 0 && J < (4))) goto end_for_J_880;
    /* BASIC: 890 LET M=M(I,J) */
line_890:;
    /* UNTRANSLATED: LET M=M(I,J) */
    /* BASIC: 900 GOSUB 1570 */
line_900:;
    gosub_stack[gosub_sp++] = 6; goto line_1570; line_ret_6:;
    /* BASIC: 910 NEXT J */
line_910:;
    J += (1); goto for_loop_J_880; end_for_J_880:;
    /* BASIC: 920 GOTO 1490 */
line_920:;
    goto line_1490;
    /* BASIC: 930 IF L(I)<>3 THEN 690 */
line_930:;
    if (L_arr[(int)(I)]!=3) { goto line_690; }
    /* BASIC: 940 PRINT "NICE TRY. MACHINE MOVES TO"; */
line_940:;
    printf("%s", "NICE TRY. MACHINE MOVES TO");
    /* BASIC: 950 FOR J=1 TO 4 */
line_950:;
    J = 1; for_loop_J_950: if (((1) >= 0 && J > (4)) || ((1) < 0 && J < (4))) goto end_for_J_950;
    /* BASIC: 960 LET M=M(I,J) */
line_960:;
    /* UNTRANSLATED: LET M=M(I,J) */
    /* BASIC: 970 IF X(M)<>0 THEN 1010 */
line_970:;
    if (X_arr[(int)(M)]!=0) { goto line_1010; }
    /* BASIC: 980 LET X(M)=5 */
line_980:;
    /* UNTRANSLATED: LET X(M)=5 */
    /* BASIC: 990 GOSUB 1570 */
line_990:;
    gosub_stack[gosub_sp++] = 7; goto line_1570; line_ret_7:;
    /* BASIC: 1000 GOTO 500 */
line_1000:;
    goto line_500;
    /* BASIC: 1010 NEXT J */
line_1010:;
    J += (1); goto for_loop_J_950; end_for_J_950:;
    /* BASIC: 1020 GOTO 1300 */
line_1020:;
    goto line_1300;
    /* BASIC: 1030 I=1 */
line_1030:;
    I = 1;
    /* BASIC: 1040 LET L(I)=X(M(I,1))+X(M(I,2))+X(M(I,3))+X(M(I,4)) */
line_1040:;
    /* UNTRANSLATED: LET L(I)=X(M(I,1))+X(M(I,2))+X(M(I,3))+X(M(I,4)) */
    /* BASIC: 1050 LET L = L(I) */
line_1050:;
    /* UNTRANSLATED: LET L = L(I) */
    /* BASIC: 1060 IF L <2 THEN 1130 */
line_1060:;
    if (L <2) { goto line_1130; }
    /* BASIC: 1070 IF L>=3 THEN 1130 */
line_1070:;
    if (L>=3) { goto line_1130; }
    /* BASIC: 1080 IF L>2 THEN 2230 */
line_1080:;
    if (L>2) { goto line_2230; }
    /* BASIC: 1090 FOR J = 1 TO 4 */
line_1090:;
    J = 1; for_loop_J_1090: if (((1) >= 0 && J > (4)) || ((1) < 0 && J < (4))) goto end_for_J_1090;
    /* BASIC: 1100 IF X(M(I,J))<>0 THEN 1120 */
line_1100:;
    if (X_arr[(int)(M_arr[(int)(I) * 100 + (int)(J)])]!=0) { goto line_1120; }
    /* BASIC: 1110 LET X(M(I,J))=1/8 */
line_1110:;
    /* UNTRANSLATED: LET X(M(I,J))=1/8 */
    /* BASIC: 1120 NEXT J */
line_1120:;
    J += (1); goto for_loop_J_1090; end_for_J_1090:;
    /* BASIC: 1130 I=I+1: IF I<=76 THEN 1040 */
line_1130:;
    I = I+1;
    if (I<=76) { goto line_1040; }
    /* BASIC: 1140 GOSUB 1640 */
line_1140:;
    gosub_stack[gosub_sp++] = 8; goto line_1640; line_ret_8:;
    /* BASIC: 1150 I=1 */
line_1150:;
    I = 1;
    /* BASIC: 1160 IF L(I)=1/2 THEN 2360 */
line_1160:;
    if (L_arr[(int)(I)]==1/2) { goto line_2360; }
    /* BASIC: 1170 IF L(I)=1+3/8 THEN 2360 */
line_1170:;
    if (L_arr[(int)(I)]==1+3/8) { goto line_2360; }
    /* BASIC: 1180 I=I+1: IF I<=76 THEN 1160 */
line_1180:;
    I = I+1;
    if (I<=76) { goto line_1160; }
    /* BASIC: 1190 GOTO 1830 */
line_1190:;
    goto line_1830;
    /* BASIC: 1200 LET Z = 1 */
line_1200:;
    /* UNTRANSLATED: LET Z = 1 */
    /* BASIC: 1210 IF X(Y(Z))=0 THEN 1250 */
line_1210:;
    if (X_arr[(int)(Y_arr[(int)(Z)])]==0) { goto line_1250; }
    /* BASIC: 1220 LET Z=Z+1 */
line_1220:;
    /* UNTRANSLATED: LET Z=Z+1 */
    /* BASIC: 1230 IF Z<>17 THEN 1210 */
line_1230:;
    if (Z!=17) { goto line_1210; }
    /* BASIC: 1240 GOTO 1720 */
line_1240:;
    goto line_1720;
    /* BASIC: 1250 LET M=Y(Z) */
line_1250:;
    /* UNTRANSLATED: LET M=Y(Z) */
    /* BASIC: 1260 LET X(M)=5 */
line_1260:;
    /* UNTRANSLATED: LET X(M)=5 */
    /* BASIC: 1270 PRINT "MACHINE MOVES TO"; */
line_1270:;
    printf("%s", "MACHINE MOVES TO");
    /* BASIC: 1280 GOSUB 1570 */
line_1280:;
    gosub_stack[gosub_sp++] = 9; goto line_1570; line_ret_9:;
    /* BASIC: 1290 GOTO 500 */
line_1290:;
    goto line_500;
    /* BASIC: 1300 LET X=X */
line_1300:;
    /* UNTRANSLATED: LET X=X */
    /* BASIC: 1310 I=1 */
line_1310:;
    I = 1;
    /* BASIC: 1320 LET L(I)=X(M(I,1))+X(M(I,2))+X(M(I,3))+X(M(I,4)) */
line_1320:;
    /* UNTRANSLATED: LET L(I)=X(M(I,1))+X(M(I,2))+X(M(I,3))+X(M(I,4)) */
    /* BASIC: 1330 LET L=L(I) */
line_1330:;
    /* UNTRANSLATED: LET L=L(I) */
    /* BASIC: 1340 IF L<10 THEN 1410 */
line_1340:;
    if (L<10) { goto line_1410; }
    /* BASIC: 1350 IF L>=11 THEN 1410 */
line_1350:;
    if (L>=11) { goto line_1410; }
    /* BASIC: 1360 IF L>10 THEN 2230 */
line_1360:;
    if (L>10) { goto line_2230; }
    /* BASIC: 1370 FOR J=1 TO 4 */
line_1370:;
    J = 1; for_loop_J_1370: if (((1) >= 0 && J > (4)) || ((1) < 0 && J < (4))) goto end_for_J_1370;
    /* BASIC: 1380 IF X(M(I,J))<>0 THEN 1400 */
line_1380:;
    if (X_arr[(int)(M_arr[(int)(I) * 100 + (int)(J)])]!=0) { goto line_1400; }
    /* BASIC: 1390 LET X(M(I,J))=1/8 */
line_1390:;
    /* UNTRANSLATED: LET X(M(I,J))=1/8 */
    /* BASIC: 1400 NEXT J */
line_1400:;
    J += (1); goto for_loop_J_1370; end_for_J_1370:;
    /* BASIC: 1410 I=I+1: IF I<=76 THEN 1320 */
line_1410:;
    I = I+1;
    if (I<=76) { goto line_1320; }
    /* BASIC: 1420 GOSUB 1640 */
line_1420:;
    gosub_stack[gosub_sp++] = 10; goto line_1640; line_ret_10:;
    /* BASIC: 1430 I=1 */
line_1430:;
    I = 1;
    /* BASIC: 1440 IF L(I)=.5 THEN 2360 */
line_1440:;
    if (L_arr[(int)(I)]==.5) { goto line_2360; }
    /* BASIC: 1450 IF L(I)=5+3/8 THEN 2360 */
line_1450:;
    if (L_arr[(int)(I)]==5+3/8) { goto line_2360; }
    /* BASIC: 1460 I=I+1: IF I<=76 THEN 1440 */
line_1460:;
    I = I+1;
    if (I<=76) { goto line_1440; }
    /* BASIC: 1470 GOSUB 2500 */
line_1470:;
    gosub_stack[gosub_sp++] = 11; goto line_2500; line_ret_11:;
    /* BASIC: 1480 GOTO 1030 */
line_1480:;
    goto line_1030;
    /* BASIC: 1490 PRINT " " */
line_1490:;
    printf("%s", " "); printf("\n");
    /* BASIC: 1500 PRINT "DO YOU WANT TO TRY ANOTHER GAME"; */
line_1500:;
    printf("%s", "DO YOU WANT TO TRY ANOTHER GAME");
    /* BASIC: 1510 INPUT X$ */
line_1510:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", X_str);
    /* BASIC: 1520 IF LEFT$(X$,1)="Y" THEN 400 */
line_1520:;
    if (strcmp(basic_LEFT(X_str,1), "Y") == 0) { goto line_400; }
    /* BASIC: 1530 IF LEFT$(X$,1)="N" THEN 1560 */
line_1530:;
    if (strcmp(basic_LEFT(X_str,1), "N") == 0) { goto line_1560; }
    /* BASIC: 1540 PRINT "INCORRECT ANSWER. PLEASE TYPE 'YES' OR 'NO'"; */
line_1540:;
    printf("%s", "INCORRECT ANSWER. PLEASE TYPE 'YES' OR 'NO'");
    /* BASIC: 1550 GOTO 1510 */
line_1550:;
    goto line_1510;
    /* BASIC: 1560 END */
line_1560:;
    exit(0);
    /* BASIC: 1570 LET K1=INT((M-1)/16)+1 */
line_1570:;
    /* UNTRANSLATED: LET K1=INT((M-1)/16)+1 */
    /* BASIC: 1580 LET J2=M-16*(K1-1) */
line_1580:;
    /* UNTRANSLATED: LET J2=M-16*(K1-1) */
    /* BASIC: 1590 LET K2=INT((J2-1)/4)+1 */
line_1590:;
    /* UNTRANSLATED: LET K2=INT((J2-1)/4)+1 */
    /* BASIC: 1600 LET K3=M-(K1-1)*16-(K2-1)*4 */
line_1600:;
    /* UNTRANSLATED: LET K3=M-(K1-1)*16-(K2-1)*4 */
    /* BASIC: 1610 LET M=K1*100+K2*10+K3 */
line_1610:;
    /* UNTRANSLATED: LET M=K1*100+K2*10+K3 */
    /* BASIC: 1620 PRINT M; */
line_1620:;
    printf("%g ", (double)(M));
    /* BASIC: 1630 RETURN */
line_1630:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1640 FOR S=1 TO 76 */
line_1640:;
    S = 1; for_loop_S_1640: if (((1) >= 0 && S > (76)) || ((1) < 0 && S < (76))) goto end_for_S_1640;
    /* BASIC: 1650 LET J1 = M(S,1) */
line_1650:;
    /* UNTRANSLATED: LET J1 = M(S,1) */
    /* BASIC: 1660 LET J2=M(S,2) */
line_1660:;
    /* UNTRANSLATED: LET J2=M(S,2) */
    /* BASIC: 1670 LET J3=M(S,3) */
line_1670:;
    /* UNTRANSLATED: LET J3=M(S,3) */
    /* BASIC: 1680 LET J4=M(S,4) */
line_1680:;
    /* UNTRANSLATED: LET J4=M(S,4) */
    /* BASIC: 1690 LET L(S)=X(J1)+X(J2)+X(J3)+X(J4) */
line_1690:;
    /* UNTRANSLATED: LET L(S)=X(J1)+X(J2)+X(J3)+X(J4) */
    /* BASIC: 1700 NEXT S */
line_1700:;
    S += (1); goto for_loop_S_1640; end_for_S_1640:;
    /* BASIC: 1710 RETURN */
line_1710:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1720 FOR I=1 TO 64 */
line_1720:;
    I = 1; for_loop_I_1720: if (((1) >= 0 && I > (64)) || ((1) < 0 && I < (64))) goto end_for_I_1720;
    /* BASIC: 1730 IF X(I)<>0 THEN 1800 */
line_1730:;
    if (X_arr[(int)(I)]!=0) { goto line_1800; }
    /* BASIC: 1740 LET X(I)=5 */
line_1740:;
    /* UNTRANSLATED: LET X(I)=5 */
    /* BASIC: 1750 LET M=I */
line_1750:;
    /* UNTRANSLATED: LET M=I */
    /* BASIC: 1760 PRINT "MACHINE LIKES"; */
line_1760:;
    printf("%s", "MACHINE LIKES");
    /* BASIC: 1770 GOSUB 1570 */
line_1770:;
    gosub_stack[gosub_sp++] = 12; goto line_1570; line_ret_12:;
    /* BASIC: 1780 PRINT " " */
line_1780:;
    printf("%s", " "); printf("\n");
    /* BASIC: 1790 GOTO 500 */
line_1790:;
    goto line_500;
    /* BASIC: 1800 NEXT I */
line_1800:;
    I += (1); goto for_loop_I_1720; end_for_I_1720:;
    /* BASIC: 1810 PRINT "THE GAME IS A DRAW." */
line_1810:;
    printf("%s", "THE GAME IS A DRAW."); printf("\n");
    /* BASIC: 1820 GOTO 1490 */
line_1820:;
    goto line_1490;
    /* BASIC: 1830 FOR K=1 TO 18 */
line_1830:;
    K = 1; for_loop_K_1830: if (((1) >= 0 && K > (18)) || ((1) < 0 && K < (18))) goto end_for_K_1830;
    /* BASIC: 1840 LET P=0 */
line_1840:;
    /* UNTRANSLATED: LET P=0 */
    /* BASIC: 1850 FOR I=4*K-3 TO 4*K */
line_1850:;
    I = 4*K-3; for_loop_I_1850: if (((1) >= 0 && I > (4*K)) || ((1) < 0 && I < (4*K))) goto end_for_I_1850;
    /* BASIC: 1860 FOR J=1 TO 4 */
line_1860:;
    J = 1; for_loop_J_1860: if (((1) >= 0 && J > (4)) || ((1) < 0 && J < (4))) goto end_for_J_1860;
    /* BASIC: 1870 LET P=P+X(M(I,J)) */
line_1870:;
    /* UNTRANSLATED: LET P=P+X(M(I,J)) */
    /* BASIC: 1880 NEXT J */
line_1880:;
    J += (1); goto for_loop_J_1860; end_for_J_1860:;
    /* BASIC: 1890 NEXT I */
line_1890:;
    I += (1); goto for_loop_I_1850; end_for_I_1850:;
    /* BASIC: 1900 IF P<4 THEN 1940 */
line_1900:;
    if (P<4) { goto line_1940; }
    /* BASIC: 1910 IF P<5 THEN 1970 */
line_1910:;
    if (P<5) { goto line_1970; }
    /* BASIC: 1920 IF P<9 THEN 1940 */
line_1920:;
    if (P<9) { goto line_1940; }
    /* BASIC: 1930 IF P<10 THEN 1970 */
line_1930:;
    if (P<10) { goto line_1970; }
    /* BASIC: 1940 NEXT K */
line_1940:;
    K += (1); goto for_loop_K_1830; end_for_K_1830:;
    /* BASIC: 1950 GOSUB 2500 */
line_1950:;
    gosub_stack[gosub_sp++] = 13; goto line_2500; line_ret_13:;
    /* BASIC: 1960 GOTO 1200 */
line_1960:;
    goto line_1200;
    /* BASIC: 1970 LET S=1/8 */
line_1970:;
    /* UNTRANSLATED: LET S=1/8 */
    /* BASIC: 1980 FOR I=4*K-3 TO 4*K */
line_1980:;
    I = 4*K-3; for_loop_I_1980: if (((1) >= 0 && I > (4*K)) || ((1) < 0 && I < (4*K))) goto end_for_I_1980;
    /* BASIC: 1990 GOTO 2370 */
line_1990:;
    goto line_2370;
    /* BASIC: 2000 NEXT I */
line_2000:;
    I += (1); goto for_loop_I_1980; end_for_I_1980:;
    /* BASIC: 2010 LET S=0 */
line_2010:;
    /* UNTRANSLATED: LET S=0 */
    /* BASIC: 2020 GOTO 1980 */
line_2020:;
    goto line_1980;
    /* BASIC: 2030 DATA 1,49,52,4,13,61,64,16,22,39,23,38,26,42,27,43 */
line_2030:;
    /* UNTRANSLATED: DATA 1,49,52,4,13,61,64,16,22,39,23,38,26,42,27,43 */
    /* BASIC: 2040 DATA 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 */
line_2040:;
    /* UNTRANSLATED: DATA 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 */
    /* BASIC: 2050 DATA 21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38 */
line_2050:;
    /* UNTRANSLATED: DATA 21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38 */
    /* BASIC: 2060 DATA 39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56 */
line_2060:;
    /* UNTRANSLATED: DATA 39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56 */
    /* BASIC: 2070 DATA 57,58,59,60,61,62,63,64 */
line_2070:;
    /* UNTRANSLATED: DATA 57,58,59,60,61,62,63,64 */
    /* BASIC: 2080 DATA 1,17,33,49,5,21,37,53,9,25,41,57,13,29,45,61 */
line_2080:;
    /* UNTRANSLATED: DATA 1,17,33,49,5,21,37,53,9,25,41,57,13,29,45,61 */
    /* BASIC: 2090 DATA 2,18,34,50,6,22,38,54,10,26,42,58,14,30,46,62 */
line_2090:;
    /* UNTRANSLATED: DATA 2,18,34,50,6,22,38,54,10,26,42,58,14,30,46,62 */
    /* BASIC: 2100 DATA 3,19,35,51,7,23,39,55,11,27,43,59,15,31,47,63 */
line_2100:;
    /* UNTRANSLATED: DATA 3,19,35,51,7,23,39,55,11,27,43,59,15,31,47,63 */
    /* BASIC: 2110 DATA 4,20,36,52,8,24,40,56,12,28,44,60,16,32,48,64 */
line_2110:;
    /* UNTRANSLATED: DATA 4,20,36,52,8,24,40,56,12,28,44,60,16,32,48,64 */
    /* BASIC: 2120 DATA 1,5,9,13,17,21,25,29,33,37,41,45,49,53,57,61 */
line_2120:;
    /* UNTRANSLATED: DATA 1,5,9,13,17,21,25,29,33,37,41,45,49,53,57,61 */
    /* BASIC: 2130 DATA 2,6,10,14,18,22,26,30,34,38,42,46,50,54,58,62 */
line_2130:;
    /* UNTRANSLATED: DATA 2,6,10,14,18,22,26,30,34,38,42,46,50,54,58,62 */
    /* BASIC: 2140 DATA 3,7,11,15,19,23,27,31,35,39,43,47,51,55,59,63 */
line_2140:;
    /* UNTRANSLATED: DATA 3,7,11,15,19,23,27,31,35,39,43,47,51,55,59,63 */
    /* BASIC: 2150 DATA 4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64 */
line_2150:;
    /* UNTRANSLATED: DATA 4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64 */
    /* BASIC: 2160 DATA 1,6,11,16,17,22,27,32,33,38,43,48,49,54,59,64 */
line_2160:;
    /* UNTRANSLATED: DATA 1,6,11,16,17,22,27,32,33,38,43,48,49,54,59,64 */
    /* BASIC: 2170 DATA 13,10,7,4,29,26,23,20,45,42,39,36,61,58,55,52 */
line_2170:;
    /* UNTRANSLATED: DATA 13,10,7,4,29,26,23,20,45,42,39,36,61,58,55,52 */
    /* BASIC: 2180 DATA 1,21,41,61,2,22,42,62,3,23,43,63,4,24,44,64 */
line_2180:;
    /* UNTRANSLATED: DATA 1,21,41,61,2,22,42,62,3,23,43,63,4,24,44,64 */
    /* BASIC: 2190 DATA 49,37,25,13,50,38,26,14,51,39,27,15,52,40,28,16 */
line_2190:;
    /* UNTRANSLATED: DATA 49,37,25,13,50,38,26,14,51,39,27,15,52,40,28,16 */
    /* BASIC: 2200 DATA 1,18,35,52,5,22,39,56,9,26,43,60,13,30,47,64 */
line_2200:;
    /* UNTRANSLATED: DATA 1,18,35,52,5,22,39,56,9,26,43,60,13,30,47,64 */
    /* BASIC: 2210 DATA 49,34,19,4,53,38,23,8,57,42,27,12,61,46,31,16 */
line_2210:;
    /* UNTRANSLATED: DATA 49,34,19,4,53,38,23,8,57,42,27,12,61,46,31,16 */
    /* BASIC: 2220 DATA 1,22,43,64,16,27,38,49,4,23,42,61,13,26,39,52 */
line_2220:;
    /* UNTRANSLATED: DATA 1,22,43,64,16,27,38,49,4,23,42,61,13,26,39,52 */
    /* BASIC: 2230 FOR J=1 TO 4 */
line_2230:;
    J = 1; for_loop_J_2230: if (((1) >= 0 && J > (4)) || ((1) < 0 && J < (4))) goto end_for_J_2230;
    /* BASIC: 2240 IF X(M(I,J))<>1/8 THEN 2330 */
line_2240:;
    if (X_arr[(int)(M_arr[(int)(I) * 100 + (int)(J)])]!=1/8) { goto line_2330; }
    /* BASIC: 2250 LET X(M(I,J))=5 */
line_2250:;
    /* UNTRANSLATED: LET X(M(I,J))=5 */
    /* BASIC: 2260 IF L(I)<5 THEN 2290 */
line_2260:;
    if (L_arr[(int)(I)]<5) { goto line_2290; }
    /* BASIC: 2270 PRINT "LET'S SEE YOU GET OUT OF THIS:  MACHINE MOVES TO"; */
line_2270:;
    printf("%s", "LET'S SEE YOU GET OUT OF THIS:  MACHINE MOVES TO");
    /* BASIC: 2280 GOTO 2300 */
line_2280:;
    goto line_2300;
    /* BASIC: 2290 PRINT "YOU FOX.  JUST IN THE NICK OF TIME, MACHINE MOVES TO"; */
line_2290:;
    printf("%s", "YOU FOX.  JUST IN THE NICK OF TIME, MACHINE MOVES TO");
    /* BASIC: 2300 LET M=M(I,J) */
line_2300:;
    /* UNTRANSLATED: LET M=M(I,J) */
    /* BASIC: 2310 GOSUB 1570 */
line_2310:;
    gosub_stack[gosub_sp++] = 14; goto line_1570; line_ret_14:;
    /* BASIC: 2320 GOTO 500 */
line_2320:;
    goto line_500;
    /* BASIC: 2330 NEXT J */
line_2330:;
    J += (1); goto for_loop_J_2230; end_for_J_2230:;
    /* BASIC: 2340 PRINT "MACHINE CONCEDES THIS GAME." */
line_2340:;
    printf("%s", "MACHINE CONCEDES THIS GAME."); printf("\n");
    /* BASIC: 2350 GOTO 1490 */
line_2350:;
    goto line_1490;
    /* BASIC: 2360 LET S=1/8 */
line_2360:;
    /* UNTRANSLATED: LET S=1/8 */
    /* BASIC: 2370 IF I-INT(I/4)*4>1 THEN 2400 */
line_2370:;
    if (I-floor(I/4)*4>1) { goto line_2400; }
    /* BASIC: 2380 LET A=1 */
line_2380:;
    /* UNTRANSLATED: LET A=1 */
    /* BASIC: 2390 GOTO 2410 */
line_2390:;
    goto line_2410;
    /* BASIC: 2400 LET A=2 */
line_2400:;
    /* UNTRANSLATED: LET A=2 */
    /* BASIC: 2410 FOR J=A TO 5-A STEP 5-2*A */
line_2410:;
    J = A; for_loop_J_2410: if (((5-2*A) >= 0 && J > (5-A)) || ((5-2*A) < 0 && J < (5-A))) goto end_for_J_2410;
    /* BASIC: 2420 IF X(M(I,J))=S THEN 2450 */
line_2420:;
    if (X_arr[(int)(M_arr[(int)(I) * 100 + (int)(J)])]==S) { goto line_2450; }
    /* BASIC: 2430 NEXT J */
line_2430:;
    J += (5-2*A); goto for_loop_J_2410; end_for_J_2410:;
    /* BASIC: 2440 GOTO 2000 */
line_2440:;
    goto line_2000;
    /* BASIC: 2450 LET X(M(I,J))=5 */
line_2450:;
    /* UNTRANSLATED: LET X(M(I,J))=5 */
    /* BASIC: 2460 LET M=M(I,J) */
line_2460:;
    /* UNTRANSLATED: LET M=M(I,J) */
    /* BASIC: 2470 PRINT "MACHINE TAKES"; */
line_2470:;
    printf("%s", "MACHINE TAKES");
    /* BASIC: 2480 GOSUB 1570 */
line_2480:;
    gosub_stack[gosub_sp++] = 15; goto line_1570; line_ret_15:;
    /* BASIC: 2490 GOTO 500 */
line_2490:;
    goto line_500;
    /* BASIC: 2500 FOR I=1 TO 64 */
line_2500:;
    I = 1; for_loop_I_2500: if (((1) >= 0 && I > (64)) || ((1) < 0 && I < (64))) goto end_for_I_2500;
    /* BASIC: 2510 IF X(I)<>1/8 THEN 2530 */
line_2510:;
    if (X_arr[(int)(I)]!=1/8) { goto line_2530; }
    /* BASIC: 2520 LET X(I)=0 */
line_2520:;
    /* UNTRANSLATED: LET X(I)=0 */
    /* BASIC: 2530 NEXT I */
line_2530:;
    I += (1); goto for_loop_I_2500; end_for_I_2500:;
    /* BASIC: 2540 RETURN */
line_2540:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 2550 FOR XX=1 TO 9:PRINT:NEXT:FOR I=1 TO 4 */
line_2550:;
    XX = 1; for_loop_XX_2550: if (((1) >= 0 && XX > (9)) || ((1) < 0 && XX < (9))) goto end_for_XX_2550;
    printf("\n");
    /* NEXT (unmatched) */
    I = 1; for_loop_I_2550: if (((1) >= 0 && I > (4)) || ((1) < 0 && I < (4))) goto end_for_I_2550;
    /* BASIC: 2560 FOR J=1 TO 4 */
line_2560:;
    J = 1; for_loop_J_2560: if (((1) >= 0 && J > (4)) || ((1) < 0 && J < (4))) goto end_for_J_2560;
    /* BASIC: 2562 FOR I1=1 TO J */
line_2562:;
    I1 = 1; for_loop_I1_2562: if (((1) >= 0 && I1 > (J)) || ((1) < 0 && I1 < (J))) goto end_for_I1_2562;
    /* BASIC: 2564 PRINT"   "; */
line_2564:;
    printf("%s", "   ");
    /* BASIC: 2566 NEXT I1 */
line_2566:;
    I1 += (1); goto for_loop_I1_2562; end_for_I1_2562:;
    /* BASIC: 2570 FOR K=1 TO 4 */
line_2570:;
    K = 1; for_loop_K_2570: if (((1) >= 0 && K > (4)) || ((1) < 0 && K < (4))) goto end_for_K_2570;
    /* BASIC: 2600 LET Q=16*I+4*J+K-20 */
line_2600:;
    /* UNTRANSLATED: LET Q=16*I+4*J+K-20 */
    /* BASIC: 2610 IF X(Q)<>O THEN 2630 */
line_2610:;
    if (X_arr[(int)(Q)]!=O) { goto line_2630; }
    /* BASIC: 2620 PRINT"( )      "; */
line_2620:;
    printf("%s", "( )      ");
    /* BASIC: 2630 IF X(Q)<>5 THEN 2650 */
line_2630:;
    if (X_arr[(int)(Q)]!=5) { goto line_2650; }
    /* BASIC: 2640 PRINT"(M)      "; */
line_2640:;
    printf("%s", "(M)      ");
    /* BASIC: 2650 IF X(Q)<>1 THEN 2660 */
line_2650:;
    if (X_arr[(int)(Q)]!=1) { goto line_2660; }
    /* BASIC: 2655 PRINT"(Y)      "; */
line_2655:;
    printf("%s", "(Y)      ");
    /* BASIC: 2660 IF X(Q)<>1/8 THEN 2670 */
line_2660:;
    if (X_arr[(int)(Q)]!=1/8) { goto line_2670; }
    /* BASIC: 2665 PRINT"( )      "; */
line_2665:;
    printf("%s", "( )      ");
    /* BASIC: 2670 NEXT K */
line_2670:;
    K += (1); goto for_loop_K_2570; end_for_K_2570:;
    /* BASIC: 2680 PRINT */
line_2680:;
    printf("\n");
    /* BASIC: 2690 PRINT */
line_2690:;
    printf("\n");
    /* BASIC: 2700 NEXT J */
line_2700:;
    J += (1); goto for_loop_J_2560; end_for_J_2560:;
    /* BASIC: 2710 PRINT */
line_2710:;
    printf("\n");
    /* BASIC: 2720 PRINT */
line_2720:;
    printf("\n");
    /* BASIC: 2730 NEXT I */
line_2730:;
    I += (1); goto for_loop_I_2550; end_for_I_2550:;
    /* BASIC: 2735 REM PRINT CHR$(12) */
line_2735:;
    // REM PRINT CHR$(12)
    /* BASIC: 2740 RETURN */
line_2740:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 2750 PRINT"INCORRECT MOVE, RETYPE IT--"; */
line_2750:;
    printf("%s", "INCORRECT MOVE, RETYPE IT--");
    /* BASIC: 2760 GOTO 520 */
line_2760:;
    goto line_520;
    /* BASIC: 2770 END */
line_2770:;
    exit(0);
    /* Undefined labels declared here to compile cleanly */
    end_for_XX_2550:;

    return 0;
}
