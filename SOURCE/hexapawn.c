/*
 * Transpiled from hexapawn.bas
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

static DataItem program_data[247] = {
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 24.0 } },
    { DATA_NUM, { .num = 25.0 } },
    { DATA_NUM, { .num = 36.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 14.0 } },
    { DATA_NUM, { .num = 15.0 } },
    { DATA_NUM, { .num = 36.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 15.0 } },
    { DATA_NUM, { .num = 35.0 } },
    { DATA_NUM, { .num = 36.0 } },
    { DATA_NUM, { .num = 47.0 } },
    { DATA_NUM, { .num = 36.0 } },
    { DATA_NUM, { .num = 58.0 } },
    { DATA_NUM, { .num = 59.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 15.0 } },
    { DATA_NUM, { .num = 35.0 } },
    { DATA_NUM, { .num = 36.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 24.0 } },
    { DATA_NUM, { .num = 25.0 } },
    { DATA_NUM, { .num = 26.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 26.0 } },
    { DATA_NUM, { .num = 57.0 } },
    { DATA_NUM, { .num = 58.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 26.0 } },
    { DATA_NUM, { .num = 35.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 47.0 } },
    { DATA_NUM, { .num = 48.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 35.0 } },
    { DATA_NUM, { .num = 36.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 35.0 } },
    { DATA_NUM, { .num = 36.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 36.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 47.0 } },
    { DATA_NUM, { .num = 58.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 15.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 26.0 } },
    { DATA_NUM, { .num = 47.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 47.0 } },
    { DATA_NUM, { .num = 58.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 35.0 } },
    { DATA_NUM, { .num = 36.0 } },
    { DATA_NUM, { .num = 47.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 28.0 } },
    { DATA_NUM, { .num = 58.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 15.0 } },
    { DATA_NUM, { .num = 47.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
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
static double B, DEF, I, J, K, L, M, M1, M2, P, R, S, T, W, X, Y;
static char A_str[256] = {0};
static char P_str[256] = {0};
static double B_arr[20000] = {0};
static double M_arr[20000] = {0};
static double S_arr[20000] = {0};
static double T_arr[20000] = {0};
static char P_str_arr[20000][256] = {0};
static char _input_buf[256];

/* User-defined functions forward declarations */
static double FNR(double X);
static double FNS(double X);
static double FNM(double Y);

/* User-defined functions definitions */
static double FNR(double X) {
    return -3*(X==1)-(X==3)-4*(X==6)-6*(X==4)-7*(X==9)-9*(X==7)+FNS(X);
}

static double FNS(double X) {
    return -X*(X==2  ||  X==5  ||  X==8);
}

static double FNM(double Y) {
    return Y-floor(Y/10)*10;
}

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 1 PRINT TAB(32);"HEXAPAWN" */
line_1:;
    { int _t; for(_t=0; _t<32; _t++) printf(" "); } printf("%s", "HEXAPAWN"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT:PRINT:PRINT */
line_3:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 4 REM  HEXAPAWN:  INTERPRETATION OF HEXAPAWN GAME AS PRESENTED IN */
line_4:;
    // REM  HEXAPAWN
    /* UNTRANSLATED: INTERPRETATION OF HEXAPAWN GAME AS PRESENTED IN */
    /* BASIC: 5 REM  MARTIN GARDNER'S "THE UNEXPECTED HANGING AND OTHER MATHEMATIC- */
line_5:;
    // REM  MARTIN GARDNER'S "THE UNEXPECTED HANGING AND OTHER MATHEMATIC-
    /* BASIC: 6 REM  AL DIVERSIONS", CHAPTER EIGHT:  A MATCHBOX GAME-LEARNING MACHINE */
line_6:;
    // REM  AL DIVERSIONS", CHAPTER EIGHT:  A MATCHBOX GAME-LEARNING MACHINE
    /* BASIC: 7 REM  OR IGINAL VERSION FOR H-P TIMESHARE SYSTEM BY R.A. KAAPKE 5/5/76 */
line_7:;
    // REM  OR IGINAL VERSION FOR H-P TIMESHARE SYSTEM BY R.A. KAAPKE 5/5/76
    /* BASIC: 8 REM  INSTRUCTIONS BY JEFF DAL TO N */
line_8:;
    // REM  INSTRUCTIONS BY JEFF DAL TO N
    /* BASIC: 9 REM  CONVERSION TO MITS BASIC BY STEVE N OR TH */
line_9:;
    // REM  CONVERSION TO MITS BASIC BY STEVE N OR TH
    /* BASIC: 10 DIM B(19,9),M(19,4),S(9),P$(3) */
line_10:;
    /* DIM B(19,9),M(19,4),S(9),P$(3) (handled statically) */
    /* BASIC: 15 W=0: L=0 */
line_15:;
    W = 0;
    L = 0;
    /* BASIC: 20 DEF FNR(X)=-3*(X=1)-(X=3)-4*(X=6)-6*(X=4)-7*(X=9)-9*(X=7)+FNS(X) */
line_20:;
    /* UNTRANSLATED: DEF FNR(X)=-3*(X=1)-(X=3)-4*(X=6)-6*(X=4)-7*(X=9)-9*(X=7)+FNS(X) */
    /* BASIC: 25 DEF FNS(X)=-X*(X=2 OR X=5 OR X=8) */
line_25:;
    /* UNTRANSLATED: DEF FNS(X)=-X*(X=2 OR X=5 OR X=8) */
    /* BASIC: 30 DEF FNM(Y)=Y-INT(Y/10)*10 */
line_30:;
    /* UNTRANSLATED: DEF FNM(Y)=Y-INT(Y/10)*10 */
    /* BASIC: 35 P$="X.O" */
line_35:;
    str_assign(P_str, sizeof(P_str), "X.O");
    /* BASIC: 40 FOR I=1 TO 19: FOR J=1 TO 9: READ B(I,J): NEXT J: NEXT I */
line_40:;
    I = 1; for_loop_I_40: if (((1) >= 0 && I > (19)) || ((1) < 0 && I < (19))) goto end_for_I_40;
    J = 1; for_loop_J_40: if (((1) >= 0 && J > (9)) || ((1) < 0 && J < (9))) goto end_for_J_40;
    read_numeric(&(B_arr[(int)(I) * 100 + (int)(J)]));
    J += (1); goto for_loop_J_40; end_for_J_40:;
    I += (1); goto for_loop_I_40; end_for_I_40:;
    /* BASIC: 45 FOR I=1 TO 19: FOR J=1 TO 4: READ M(I,J): NEXT J: NEXT I */
line_45:;
    I = 1; for_loop_I_45: if (((1) >= 0 && I > (19)) || ((1) < 0 && I < (19))) goto end_for_I_45;
    J = 1; for_loop_J_45: if (((1) >= 0 && J > (4)) || ((1) < 0 && J < (4))) goto end_for_J_45;
    read_numeric(&(M_arr[(int)(I) * 100 + (int)(J)]));
    J += (1); goto for_loop_J_45; end_for_J_45:;
    I += (1); goto for_loop_I_45; end_for_I_45:;
    /* BASIC: 50 PRINT "INSTRUCTIONS (Y-N)"; */
line_50:;
    printf("%s", "INSTRUCTIONS (Y-N)");
    /* BASIC: 60 INPUT A$ */
line_60:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    /* BASIC: 70 A$=LEFT$(A$,1) */
line_70:;
    str_assign(A_str, sizeof(A_str), basic_LEFT(A_str,1));
    /* BASIC: 80 IF A$="Y" THEN 2000 */
line_80:;
    if (strcmp(A_str, "Y") == 0) { goto line_2000; }
    /* BASIC: 90 IF A$<>"N" THEN 50 */
line_90:;
    if (strcmp(A_str, "N") != 0) { goto line_50; }
    /* BASIC: 100 X=0: Y=0 */
line_100:;
    X = 0;
    Y = 0;
    /* BASIC: 111 S(4)=0: S(5)=0: S(6)=0 */
line_111:;
    S_arr[(int)(4)] = 0;
    S_arr[(int)(5)] = 0;
    S_arr[(int)(6)] = 0;
    /* BASIC: 112 S(1)=-1: S(2)=-1: S(3)=-1 */
line_112:;
    S_arr[(int)(1)] = -1;
    S_arr[(int)(2)] = -1;
    S_arr[(int)(3)] = -1;
    /* BASIC: 113 S(7)=1: S(8)=1: S(9)=1 */
line_113:;
    S_arr[(int)(7)] = 1;
    S_arr[(int)(8)] = 1;
    S_arr[(int)(9)] = 1;
    /* BASIC: 115 GOSUB 1000 */
line_115:;
    gosub_stack[gosub_sp++] = 1; goto line_1000; line_ret_1:;
    /* BASIC: 120 PRINT "YOUR MOVE"; */
line_120:;
    printf("%s", "YOUR MOVE");
    /* BASIC: 121 INPUT M1,M2 */
line_121:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf", &M1, &M2);
    /* BASIC: 122 IF M1=INT(M1) AND M2=INT(M2) AND M1>0 AND M1<10 AND M2>0 AND M2<10 THEN 130 */
line_122:;
    if (M1==floor(M1)   &&   M2==floor(M2)   &&   M1>0   &&   M1<10   &&   M2>0   &&   M2<10) { goto line_130; }
    /* BASIC: 123 PRINT "ILLEGAL CO-ORDINATES." */
line_123:;
    printf("%s", "ILLEGAL CO-ORDINATES."); printf("\n");
    /* BASIC: 124 GOTO 120 */
line_124:;
    goto line_120;
    /* BASIC: 130 IF S(M1)=1 THEN 150 */
line_130:;
    if (S_arr[(int)(M1)]==1) { goto line_150; }
    /* BASIC: 140 PRINT "ILLEGAL MOVE.": GOTO 120 */
line_140:;
    printf("%s", "ILLEGAL MOVE."); printf("\n");
    goto line_120;
    /* BASIC: 150 IF S(M2)=1 THEN 140 */
line_150:;
    if (S_arr[(int)(M2)]==1) { goto line_140; }
    /* BASIC: 160 IF M2-M1<>-3 AND S(M2)<>-1 THEN 140 */
line_160:;
    if (M2-M1!=-3   &&   S_arr[(int)(M2)]!=-1) { goto line_140; }
    /* BASIC: 170 IF M2>M1 THEN 140 */
line_170:;
    if (M2>M1) { goto line_140; }
    /* BASIC: 180 IF M2-M1=-3 AND (S(M2)<>0) THEN 140 */
line_180:;
    if (M2-M1==-3   &&   (S_arr[(int)(M2)]!=0)) { goto line_140; }
    /* BASIC: 185 IF M2-M1<-4 THEN 140 */
line_185:;
    if (M2-M1<-4) { goto line_140; }
    /* BASIC: 186 IF M1=7 AND M2=3 THEN 140 */
line_186:;
    if (M1==7   &&   M2==3) { goto line_140; }
    /* BASIC: 190 S(M1)=0 */
line_190:;
    S_arr[(int)(M1)] = 0;
    /* BASIC: 200 S(M2)=1 */
line_200:;
    S_arr[(int)(M2)] = 1;
    /* BASIC: 205 GOSUB 1000 */
line_205:;
    gosub_stack[gosub_sp++] = 2; goto line_1000; line_ret_2:;
    /* BASIC: 210 IF S(1)=1 OR S(2)=1 OR S(3)=1 THEN 820 */
line_210:;
    if (S_arr[(int)(1)]==1   ||   S_arr[(int)(2)]==1   ||   S_arr[(int)(3)]==1) { goto line_820; }
    /* BASIC: 220 FOR I=1 TO 9 */
line_220:;
    I = 1; for_loop_I_220: if (((1) >= 0 && I > (9)) || ((1) < 0 && I < (9))) goto end_for_I_220;
    /* BASIC: 221 IF S(I)=-1 THEN 230 */
line_221:;
    if (S_arr[(int)(I)]==-1) { goto line_230; }
    /* BASIC: 222 NEXT I */
line_222:;
    I += (1); goto for_loop_I_220; end_for_I_220:;
    /* BASIC: 223 GOTO 820 */
line_223:;
    goto line_820;
    /* BASIC: 230 FOR I=1 TO 9 */
line_230:;
    I = 1; for_loop_I_230: if (((1) >= 0 && I > (9)) || ((1) < 0 && I < (9))) goto end_for_I_230;
    /* BASIC: 240 IF S(I)<>-1 THEN 330 */
line_240:;
    if (S_arr[(int)(I)]!=-1) { goto line_330; }
    /* BASIC: 250 IF S(I+3)=0 THEN 350 */
line_250:;
    if (S_arr[(int)(I+3)]==0) { goto line_350; }
    /* BASIC: 260 IF FNR(I)=I THEN 320 */
line_260:;
    if (FNR(I)==I) { goto line_320; }
    /* BASIC: 270 IF I>3 THEN 300 */
line_270:;
    if (I>3) { goto line_300; }
    /* BASIC: 280 IF S(5)=1 THEN 350 */
line_280:;
    if (S_arr[(int)(5)]==1) { goto line_350; }
    /* BASIC: 290 GOTO 330 */
line_290:;
    goto line_330;
    /* BASIC: 300 IF S(8)=1 THEN 350 */
line_300:;
    if (S_arr[(int)(8)]==1) { goto line_350; }
    /* BASIC: 310 GOTO 330 */
line_310:;
    goto line_330;
    /* BASIC: 320 IF S(I+2)=1 OR S(I+4)=1 THEN 350 */
line_320:;
    if (S_arr[(int)(I+2)]==1   ||   S_arr[(int)(I+4)]==1) { goto line_350; }
    /* BASIC: 330 NEXT I */
line_330:;
    I += (1); goto for_loop_I_230; end_for_I_230:;
    /* BASIC: 340 GOTO 820 */
line_340:;
    goto line_820;
    /* BASIC: 350 FOR I=1 TO 19 */
line_350:;
    I = 1; for_loop_I_350: if (((1) >= 0 && I > (19)) || ((1) < 0 && I < (19))) goto end_for_I_350;
    /* BASIC: 360 FOR J=1 TO 3 */
line_360:;
    J = 1; for_loop_J_360: if (((1) >= 0 && J > (3)) || ((1) < 0 && J < (3))) goto end_for_J_360;
    /* BASIC: 370 FOR K=3 TO 1 STEP -1 */
line_370:;
    K = 3; for_loop_K_370: if (((-1) >= 0 && K > (1)) || ((-1) < 0 && K < (1))) goto end_for_K_370;
    /* BASIC: 380 T((J-1)*3+K)=B(I,(J-1)*3+4-K) */
line_380:;
    T_arr[(int)((J-1)*3+K)] = B_arr[(int)(I) * 100 + (int)((J-1)*3+4-K)];
    /* BASIC: 390 NEXT K */
line_390:;
    K += (-1); goto for_loop_K_370; end_for_K_370:;
    /* BASIC: 400 NEXT J */
line_400:;
    J += (1); goto for_loop_J_360; end_for_J_360:;
    /* BASIC: 410 FOR J=1 TO 9 */
line_410:;
    J = 1; for_loop_J_410: if (((1) >= 0 && J > (9)) || ((1) < 0 && J < (9))) goto end_for_J_410;
    /* BASIC: 420 IF S(J)<>B(I,J) THEN 460 */
line_420:;
    if (S_arr[(int)(J)]!=B_arr[(int)(I) * 100 + (int)(J)]) { goto line_460; }
    /* BASIC: 430 NEXT J */
line_430:;
    J += (1); goto for_loop_J_410; end_for_J_410:;
    /* BASIC: 440 R=0 */
line_440:;
    R = 0;
    /* BASIC: 450 GOTO 540 */
line_450:;
    goto line_540;
    /* BASIC: 460 FOR J=1 TO 9 */
line_460:;
    J = 1; for_loop_J_460: if (((1) >= 0 && J > (9)) || ((1) < 0 && J < (9))) goto end_for_J_460;
    /* BASIC: 470 IF S(J)<>T(J) THEN 510 */
line_470:;
    if (S_arr[(int)(J)]!=T_arr[(int)(J)]) { goto line_510; }
    /* BASIC: 480 NEXT J */
line_480:;
    J += (1); goto for_loop_J_460; end_for_J_460:;
    /* BASIC: 490 R=1 */
line_490:;
    R = 1;
    /* BASIC: 500 GOTO 540 */
line_500:;
    goto line_540;
    /* BASIC: 510 NEXT I */
line_510:;
    I += (1); goto for_loop_I_350; end_for_I_350:;
    /* BASIC: 511 REMEMBER THE TERMINATION OF THIS LOOP IS IMPOSSIBLE */
line_511:;
    // REMEMBER THE TERMINATION OF THIS LOOP IS IMPOSSIBLE
    /* BASIC: 512 PRINT "ILLEGAL BOARD PATTERN." */
line_512:;
    printf("%s", "ILLEGAL BOARD PATTERN."); printf("\n");
    /* BASIC: 530 S TO P */
line_530:;
    /* UNTRANSLATED: S TO P */
    /* BASIC: 540 X=I */
line_540:;
    X = I;
    /* BASIC: 550 FOR I=1 TO 4 */
line_550:;
    I = 1; for_loop_I_550: if (((1) >= 0 && I > (4)) || ((1) < 0 && I < (4))) goto end_for_I_550;
    /* BASIC: 560 IF M(X,I)<>0 THEN 600 */
line_560:;
    if (M_arr[(int)(X) * 100 + (int)(I)]!=0) { goto line_600; }
    /* BASIC: 570 NEXT I */
line_570:;
    I += (1); goto for_loop_I_550; end_for_I_550:;
    /* BASIC: 580 PRINT "I RESIGN." */
line_580:;
    printf("%s", "I RESIGN."); printf("\n");
    /* BASIC: 590 GOTO 820 */
line_590:;
    goto line_820;
    /* BASIC: 600 Y=INT(RND(1)*4+1) */
line_600:;
    Y = floor(((double)rand() / (double)RAND_MAX)*4+1);
    /* BASIC: 601 IF M(X,Y)=0 THEN 600 */
line_601:;
    if (M_arr[(int)(X) * 100 + (int)(Y)]==0) { goto line_600; }
    /* BASIC: 610 IF R<>0 THEN 630 */
line_610:;
    if (R!=0) { goto line_630; }
    /* BASIC: 620 PRINT "I MOVE FROM ";STR$(INT(M(X,Y)/10));" TO ";STR$(FNM(M(X,Y))) */
line_620:;
    printf("%s", "I MOVE FROM "); printf("%s", basic_STR(floor(M_arr[(int)(X) * 100 + (int)(Y)]/10))); printf("%s", " TO "); printf("%s", basic_STR(FNM(M_arr[(int)(X) * 100 + (int)(Y)]))); printf("\n");
    /* BASIC: 622 S(INT(M(X,Y)/10))=0 */
line_622:;
    S_arr[(int)(floor(M_arr[(int)(X) * 100 + (int)(Y)]/10))] = 0;
    /* BASIC: 623 S(FNM(M(X,Y)))=-1 */
line_623:;
    S_arr[(int)(FNM(M_arr[(int)(X) * 100 + (int)(Y)]))] = -1;
    /* BASIC: 624 GOTO 640 */
line_624:;
    goto line_640;
    /* BASIC: 630 PRINT "I MOVE FROM ";STR$(FNR(INT(M(X,Y)/10)));" TO "; */
line_630:;
    printf("%s", "I MOVE FROM "); printf("%s", basic_STR(FNR(floor(M_arr[(int)(X) * 100 + (int)(Y)]/10)))); printf("%s", " TO ");
    /* BASIC: 631 PRINT STR$(FNR(FNM(M(X,Y)))) */
line_631:;
    printf("%s", basic_STR(FNR(FNM(M_arr[(int)(X) * 100 + (int)(Y)])))); printf("\n");
    /* BASIC: 632 S(FNR(INT(M(X,Y)/10)))=0 */
line_632:;
    S_arr[(int)(FNR(floor(M_arr[(int)(X) * 100 + (int)(Y)]/10)))] = 0;
    /* BASIC: 633 S(FNR(FNM(M(X,Y))))=-1 */
line_633:;
    S_arr[(int)(FNR(FNM(M_arr[(int)(X) * 100 + (int)(Y)])))] = -1;
    /* BASIC: 640 GOSUB 1000 */
line_640:;
    gosub_stack[gosub_sp++] = 3; goto line_1000; line_ret_3:;
    /* BASIC: 641 IF S(7)=-1 OR S(8)=-1 OR S(9)=-1 THEN 870 */
line_641:;
    if (S_arr[(int)(7)]==-1   ||   S_arr[(int)(8)]==-1   ||   S_arr[(int)(9)]==-1) { goto line_870; }
    /* BASIC: 650 FOR I=1 TO 9 */
line_650:;
    I = 1; for_loop_I_650: if (((1) >= 0 && I > (9)) || ((1) < 0 && I < (9))) goto end_for_I_650;
    /* BASIC: 660 IF S(I)=1 THEN 690 */
line_660:;
    if (S_arr[(int)(I)]==1) { goto line_690; }
    /* BASIC: 670 NEXT I */
line_670:;
    I += (1); goto for_loop_I_650; end_for_I_650:;
    /* BASIC: 680 GOTO 870 */
line_680:;
    goto line_870;
    /* BASIC: 690 FOR I=1 TO 9 */
line_690:;
    I = 1; for_loop_I_690: if (((1) >= 0 && I > (9)) || ((1) < 0 && I < (9))) goto end_for_I_690;
    /* BASIC: 700 IF S(I)<>1 THEN 790 */
line_700:;
    if (S_arr[(int)(I)]!=1) { goto line_790; }
    /* BASIC: 710 IF S(I-3)=0 THEN 120 */
line_710:;
    if (S_arr[(int)(I-3)]==0) { goto line_120; }
    /* BASIC: 720 IF FNR(I)=I THEN 780 */
line_720:;
    if (FNR(I)==I) { goto line_780; }
    /* BASIC: 730 IF I<7 THEN 760 */
line_730:;
    if (I<7) { goto line_760; }
    /* BASIC: 740 IF S(5)=-1 THEN 120 */
line_740:;
    if (S_arr[(int)(5)]==-1) { goto line_120; }
    /* BASIC: 750 GOTO 790 */
line_750:;
    goto line_790;
    /* BASIC: 760 IF S(2)=-1 THEN 120 */
line_760:;
    if (S_arr[(int)(2)]==-1) { goto line_120; }
    /* BASIC: 770 GOTO 790 */
line_770:;
    goto line_790;
    /* BASIC: 780 IF S(I-2)=-1 OR S(I-4)=-1 THEN 120 */
line_780:;
    if (S_arr[(int)(I-2)]==-1   ||   S_arr[(int)(I-4)]==-1) { goto line_120; }
    /* BASIC: 790 NEXT I */
line_790:;
    I += (1); goto for_loop_I_690; end_for_I_690:;
    /* BASIC: 800 PRINT "YOU CAN'T MOVE, SO "; */
line_800:;
    printf("%s", "YOU CAN'T MOVE, SO ");
    /* BASIC: 810 GOTO 870 */
line_810:;
    goto line_870;
    /* BASIC: 820 PRINT "YOU WIN." */
line_820:;
    printf("%s", "YOU WIN."); printf("\n");
    /* BASIC: 830 M(X,Y)=0 */
line_830:;
    M_arr[(int)(X) * 100 + (int)(Y)] = 0;
    /* BASIC: 840 L=L+1 */
line_840:;
    L = L+1;
    /* BASIC: 850 PRINT "I HAVE WON";W;"AND YOU";L;"OUT OF";L+W;"GAMES." */
line_850:;
    printf("%s", "I HAVE WON"); printf("%g ", (double)(W)); printf("%s", "AND YOU"); printf("%g ", (double)(L)); printf("%s", "OUT OF"); printf("%g ", (double)(L+W)); printf("%s", "GAMES."); printf("\n");
    /* BASIC: 851 PRINT */
line_851:;
    printf("\n");
    /* BASIC: 860 GOTO 100 */
line_860:;
    goto line_100;
    /* BASIC: 870 PRINT "I WIN." */
line_870:;
    printf("%s", "I WIN."); printf("\n");
    /* BASIC: 880 W=W+1 */
line_880:;
    W = W+1;
    /* BASIC: 890 GOTO 850 */
line_890:;
    goto line_850;
    /* BASIC: 900 DATA -1,-1,-1,1,0,0,0,1,1,-1,-1,-1,0,1,0,1,0,1 */
line_900:;
    /* UNTRANSLATED: DATA -1,-1,-1,1,0,0,0,1,1,-1,-1,-1,0,1,0,1,0,1 */
    /* BASIC: 905 DATA -1,0,-1,-1,1,0,0,0,1,0,-1,-1,1,-1,0,0,0,1 */
line_905:;
    /* UNTRANSLATED: DATA -1,0,-1,-1,1,0,0,0,1,0,-1,-1,1,-1,0,0,0,1 */
    /* BASIC: 910 DATA -1,0,-1,1,1,0,0,1,0,-1,-1,0,1,0,1,0,0,1 */
line_910:;
    /* UNTRANSLATED: DATA -1,0,-1,1,1,0,0,1,0,-1,-1,0,1,0,1,0,0,1 */
    /* BASIC: 915 DATA 0,-1,-1,0,-1,1,1,0,0,0,-1,-1,-1,1,1,1,0,0 */
line_915:;
    /* UNTRANSLATED: DATA 0,-1,-1,0,-1,1,1,0,0,0,-1,-1,-1,1,1,1,0,0 */
    /* BASIC: 920 DATA -1,0,-1,-1,0,1,0,1,0,0,-1,-1,0,1,0,0,0,1 */
line_920:;
    /* UNTRANSLATED: DATA -1,0,-1,-1,0,1,0,1,0,0,-1,-1,0,1,0,0,0,1 */
    /* BASIC: 925 DATA 0,-1,-1,0,1,0,1,0,0,-1,0,-1,1,0,0,0,0,1 */
line_925:;
    /* UNTRANSLATED: DATA 0,-1,-1,0,1,0,1,0,0,-1,0,-1,1,0,0,0,0,1 */
    /* BASIC: 930 DATA 0,0,-1,-1,-1,1,0,0,0,-1,0,0,1,1,1,0,0,0 */
line_930:;
    /* UNTRANSLATED: DATA 0,0,-1,-1,-1,1,0,0,0,-1,0,0,1,1,1,0,0,0 */
    /* BASIC: 935 DATA 0,-1,0,-1,1,1,0,0,0,-1,0,0,-1,-1,1,0,0,0 */
line_935:;
    /* UNTRANSLATED: DATA 0,-1,0,-1,1,1,0,0,0,-1,0,0,-1,-1,1,0,0,0 */
    /* BASIC: 940 DATA 0,0,-1,-1,1,0,0,0,0,0,-1,0,1,-1,0,0,0,0 */
line_940:;
    /* UNTRANSLATED: DATA 0,0,-1,-1,1,0,0,0,0,0,-1,0,1,-1,0,0,0,0 */
    /* BASIC: 945 DATA -1,0,0,-1,1,0,0,0,0 */
line_945:;
    /* UNTRANSLATED: DATA -1,0,0,-1,1,0,0,0,0 */
    /* BASIC: 950 DATA 24,25,36,0,14,15,36,0,15,35,36,47,36,58,59,0 */
line_950:;
    /* UNTRANSLATED: DATA 24,25,36,0,14,15,36,0,15,35,36,47,36,58,59,0 */
    /* BASIC: 955 DATA 15,35,36,0,24,25,26,0,26,57,58,0 */
line_955:;
    /* UNTRANSLATED: DATA 15,35,36,0,24,25,26,0,26,57,58,0 */
    /* BASIC: 960 DATA 26,35,0,0,47,48,0,0,35,36,0,0,35,36,0,0 */
line_960:;
    /* UNTRANSLATED: DATA 26,35,0,0,47,48,0,0,35,36,0,0,35,36,0,0 */
    /* BASIC: 965 DATA 36,0,0,0,47,58,0,0,15,0,0,0 */
line_965:;
    /* UNTRANSLATED: DATA 36,0,0,0,47,58,0,0,15,0,0,0 */
    /* BASIC: 970 DATA 26,47,0,0,47,58,0,0,35,36,47,0,28,58,0,0,15,47,0,0 */
line_970:;
    /* UNTRANSLATED: DATA 26,47,0,0,47,58,0,0,35,36,47,0,28,58,0,0,15,47,0,0 */
    /* BASIC: 1000 PRINT */
line_1000:;
    printf("\n");
    /* BASIC: 1010 FOR I=1 TO 3 */
line_1010:;
    I = 1; for_loop_I_1010: if (((1) >= 0 && I > (3)) || ((1) < 0 && I < (3))) goto end_for_I_1010;
    /* BASIC: 1020 FOR J=1 TO 3 */
line_1020:;
    J = 1; for_loop_J_1020: if (((1) >= 0 && J > (3)) || ((1) < 0 && J < (3))) goto end_for_J_1020;
    /* BASIC: 1030 PRINT TAB(10);MID$(P$,S((I-1)*3+J)+2,1); */
line_1030:;
    { int _t; for(_t=0; _t<10; _t++) printf(" "); } printf("%s", basic_MID(P_str,S_arr[(int)((I-1)*3+J)]+2,1));
    /* BASIC: 1040 NEXT J */
line_1040:;
    J += (1); goto for_loop_J_1020; end_for_J_1020:;
    /* BASIC: 1050 PRINT */
line_1050:;
    printf("\n");
    /* BASIC: 1060 NEXT I */
line_1060:;
    I += (1); goto for_loop_I_1010; end_for_I_1010:;
    /* BASIC: 1070 PRINT */
line_1070:;
    printf("\n");
    /* BASIC: 1080 RETURN */
line_1080:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 2000 PRINT: PRINT "THIS PROGRAM PLAYS THE GAME OF HEXAPAWN." */
line_2000:;
    printf("\n");
    printf("%s", "THIS PROGRAM PLAYS THE GAME OF HEXAPAWN."); printf("\n");
    /* BASIC: 2010 PRINT "HEXAPAWN IS PLAYED WITH CHESS PAWNS ON A 3 BY 3 BOARD." */
line_2010:;
    printf("%s", "HEXAPAWN IS PLAYED WITH CHESS PAWNS ON A 3 BY 3 BOARD."); printf("\n");
    /* BASIC: 2020 PRINT "THE PAWNS ARE MOVED AS IN CHESS - ONE SPACE FORWARD TO" */
line_2020:;
    printf("%s", "THE PAWNS ARE MOVED AS IN CHESS - ONE SPACE FORWARD TO"); printf("\n");
    /* BASIC: 2030 PRINT "AN EMPTY SPACE OR ONE SPACE FORWARD AND DIAGONALLY TO" */
line_2030:;
    printf("%s", "AN EMPTY SPACE OR ONE SPACE FORWARD AND DIAGONALLY TO"); printf("\n");
    /* BASIC: 2040 PRINT "CAPTURE AN OPPOSING MAN.  ON THE BOARD, YOUR PAWNS" */
line_2040:;
    printf("%s", "CAPTURE AN OPPOSING MAN.  ON THE BOARD, YOUR PAWNS"); printf("\n");
    /* BASIC: 2050 PRINT "ARE 'O', THE COMPUTER'S PAWNS ARE 'X', AND EMPTY " */
line_2050:;
    printf("%s", "ARE 'O', THE COMPUTER'S PAWNS ARE 'X', AND EMPTY "); printf("\n");
    /* BASIC: 2060 PRINT "SQUARES ARE '.'.  TO ENTER A MOVE, TYPE THE NUMBER OF" */
line_2060:;
    printf("%s", "SQUARES ARE '.'.  TO ENTER A MOVE, TYPE THE NUMBER OF"); printf("\n");
    /* BASIC: 2070 PRINT "THE SQUARE YOU ARE MOVING FROM, FOLLOWED BY THE NUMBER" */
line_2070:;
    printf("%s", "THE SQUARE YOU ARE MOVING FROM, FOLLOWED BY THE NUMBER"); printf("\n");
    /* BASIC: 2080 PRINT "OF THE SQUARE YOU WILL MOVE TO.  THE NUMBERS MUST BE" */
line_2080:;
    printf("%s", "OF THE SQUARE YOU WILL MOVE TO.  THE NUMBERS MUST BE"); printf("\n");
    /* BASIC: 2090 PRINT "SEPERATED BY A COMMA.": PRINT */
line_2090:;
    printf("%s", "SEPERATED BY A COMMA."); printf("\n");
    printf("\n");
    /* BASIC: 2100 PRINT "THE COMPUTER STARTS A SERIES OF GAMES KNOWING ONLY WHEN" */
line_2100:;
    printf("%s", "THE COMPUTER STARTS A SERIES OF GAMES KNOWING ONLY WHEN"); printf("\n");
    /* BASIC: 2105 PRINT "THE GAME IS WON (A DRAW IS IMPOSSIBLE) AND HOW TO MOVE." */
line_2105:;
    printf("%s", "THE GAME IS WON (A DRAW IS IMPOSSIBLE) AND HOW TO MOVE."); printf("\n");
    /* BASIC: 2110 PRINT "IT HAS NO STRATEGY AT FIRST AND JUST MOVES RANDOMLY." */
line_2110:;
    printf("%s", "IT HAS NO STRATEGY AT FIRST AND JUST MOVES RANDOMLY."); printf("\n");
    /* BASIC: 2120 PRINT "HOWEVER, IT LEARNS FROM EACH GAME.  THUS, WINNING BECOMES" */
line_2120:;
    printf("%s", "HOWEVER, IT LEARNS FROM EACH GAME.  THUS, WINNING BECOMES"); printf("\n");
    /* BASIC: 2130 PRINT "MORE AND MORE DIFFICULT.  ALSO, TO HELP OFFSET YOUR" */
line_2130:;
    printf("%s", "MORE AND MORE DIFFICULT.  ALSO, TO HELP OFFSET YOUR"); printf("\n");
    /* BASIC: 2140 PRINT "INITIAL ADVANTAGE, YOU WILL NOT BE TOLD HOW TO WIN THE" */
line_2140:;
    printf("%s", "INITIAL ADVANTAGE, YOU WILL NOT BE TOLD HOW TO WIN THE"); printf("\n");
    /* BASIC: 2150 PRINT "GAME BUT MUST LEARN THIS BY PLAYING." */
line_2150:;
    printf("%s", "GAME BUT MUST LEARN THIS BY PLAYING."); printf("\n");
    /* BASIC: 2160 PRINT: PRINT "THE NUMBERING OF THE BOARD IS AS FOLLOWS:" */
line_2160:;
    printf("\n");
    printf("%s", "THE NUMBERING OF THE BOARD IS AS FOLLOWS:"); printf("\n");
    /* BASIC: 2170 PRINT TAB(10);"123": PRINT TAB(10);"456": PRINT TAB(10);"789" */
line_2170:;
    { int _t; for(_t=0; _t<10; _t++) printf(" "); } printf("%s", "123"); printf("\n");
    { int _t; for(_t=0; _t<10; _t++) printf(" "); } printf("%s", "456"); printf("\n");
    { int _t; for(_t=0; _t<10; _t++) printf(" "); } printf("%s", "789"); printf("\n");
    /* BASIC: 2180 PRINT: PRINT "FOR EXAMPLE, TO MOVE YOUR RIGHTMOST PAWN FORWARD," */
line_2180:;
    printf("\n");
    printf("%s", "FOR EXAMPLE, TO MOVE YOUR RIGHTMOST PAWN FORWARD,"); printf("\n");
    /* BASIC: 2190 PRINT "YOU WOULD TYPE 9,6 IN RESPONSE TO THE QUESTION" */
line_2190:;
    printf("%s", "YOU WOULD TYPE 9,6 IN RESPONSE TO THE QUESTION"); printf("\n");
    /* BASIC: 2200 PRINT "'YOUR MOVE ?'.  SINCE I'M A GOOD SPORT, YOU'LL ALWAYS" */
line_2200:;
    printf("%s", "'YOUR MOVE ?'.  SINCE I'M A GOOD SPORT, YOU'LL ALWAYS"); printf("\n");
    /* BASIC: 2210 PRINT "GO FIRST.": PRINT */
line_2210:;
    printf("%s", "GO FIRST."); printf("\n");
    printf("\n");
    /* BASIC: 2220 GOTO 100 */
line_2220:;
    goto line_100;
    /* BASIC: 9999 END */
line_9999:;
    exit(0);

    return 0;
}
