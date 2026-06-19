/*
 * Transpiled from diamond.bas
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

/* Global variables */
static double A, C, L, M, N, Q, R, X, Y, Z;
static char A_str[256] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 1 PRINT TAB(33);"DIAMOND" */
line_1:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "DIAMOND"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT:PRINT:PRINT */
line_3:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 4 PRINT "FOR A PRETTY DIAMOND PATTERN," */
line_4:;
    printf("%s", "FOR A PRETTY DIAMOND PATTERN,"); printf("\n");
    /* BASIC: 5 INPUT "TYPE IN AN ODD NUMBER BETWEEN 5 AND 21";R:PRINT */
line_5:;
    printf("%s", "TYPE IN AN ODD NUMBER BETWEEN 5 AND 21"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &R);
    printf("\n");
    /* BASIC: 6 Q=INT(60/R):A$="CC" */
line_6:;
    Q = floor(60/R);
    str_assign(A_str, sizeof(A_str), "CC");
    /* BASIC: 8 FOR L=1 TO Q */
line_8:;
    L = 1; for_loop_L_8: if (((1) >= 0 && L > (Q)) || ((1) < 0 && L < (Q))) goto end_for_L_8;
    /* BASIC: 10 X=1:Y=R:Z=2 */
line_10:;
    X = 1;
    Y = R;
    Z = 2;
    /* BASIC: 20 FOR N=X TO Y STEP Z */
line_20:;
    N = X; for_loop_N_20: if (((Z) >= 0 && N > (Y)) || ((Z) < 0 && N < (Y))) goto end_for_N_20;
    /* BASIC: 25 PRINT TAB((R-N)/2); */
line_25:;
    { int _t; for(_t=0; _t<(R-N)/2; _t++) printf(" "); }
    /* BASIC: 28 FOR M=1 TO Q */
line_28:;
    M = 1; for_loop_M_28: if (((1) >= 0 && M > (Q)) || ((1) < 0 && M < (Q))) goto end_for_M_28;
    /* BASIC: 29 C=1 */
line_29:;
    C = 1;
    /* BASIC: 30 FOR A=1 TO N */
line_30:;
    A = 1; for_loop_A_30: if (((1) >= 0 && A > (N)) || ((1) < 0 && A < (N))) goto end_for_A_30;
    /* BASIC: 32 IF C>LEN(A$) THEN PRINT "!";:GOTO 50 */
line_32:;
    if (C>basic_LEN(A_str)) { printf("%s", "!"); goto line_50; }
    /* BASIC: 34 PRINT MID$(A$,C,1); */
line_34:;
    printf("%s", basic_MID(A_str,C,1));
    /* BASIC: 36 C=C+1 */
line_36:;
    C = C+1;
    /* BASIC: 50 NEXT A */
line_50:;
    A += (1); goto for_loop_A_30; end_for_A_30:;
    /* BASIC: 53 IF M=Q THEN 60 */
line_53:;
    if (M==Q) { goto line_60; }
    /* BASIC: 55 PRINT TAB(R*M+(R-N)/2); */
line_55:;
    { int _t; for(_t=0; _t<R*M+(R-N)/2; _t++) printf(" "); }
    /* BASIC: 56 NEXT M */
line_56:;
    M += (1); goto for_loop_M_28; end_for_M_28:;
    /* BASIC: 60 PRINT */
line_60:;
    printf("\n");
    /* BASIC: 70 NEXT N */
line_70:;
    N += (Z); goto for_loop_N_20; end_for_N_20:;
    /* BASIC: 83 IF X<>1 THEN 95 */
line_83:;
    if (X!=1) { goto line_95; }
    /* BASIC: 85 X=R-2:Y=1:Z=-2 */
line_85:;
    X = R-2;
    Y = 1;
    Z = -2;
    /* BASIC: 90 GOTO 20 */
line_90:;
    goto line_20;
    /* BASIC: 95 NEXT L */
line_95:;
    L += (1); goto for_loop_L_8; end_for_L_8:;
    /* BASIC: 99 END */
line_99:;
    exit(0);

    return 0;
}
