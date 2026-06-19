/*
 * Transpiled from 3dplot.bas
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
static double DEF, L, X, Y, Y1, Z;
static char _input_buf[256];

/* User-defined functions forward declarations */
static double FNA(double Z);

/* User-defined functions definitions */
static double FNA(double Z) {
    return 30*exp(-Z*Z/100);
}

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 1 PRINT TAB(32);"3D PLOT" */
line_1:;
    { int _t; for(_t=0; _t<32; _t++) printf(" "); } printf("%s", "3D PLOT"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT:PRINT:PRINT */
line_3:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 5 DEF FNA(Z)=30*EXP(-Z*Z/100) */
line_5:;
    /* UNTRANSLATED: DEF FNA(Z)=30*EXP(-Z*Z/100) */
    /* BASIC: 100 PRINT */
line_100:;
    printf("\n");
    /* BASIC: 110 FOR X=-30 TO 30 STEP 1.5 */
line_110:;
    X = -30; for_loop_X_110: if (((1.5) >= 0 && X > (30)) || ((1.5) < 0 && X < (30))) goto end_for_X_110;
    /* BASIC: 120 L=0 */
line_120:;
    L = 0;
    /* BASIC: 130 Y1=5*INT(SQR(900-X*X)/5) */
line_130:;
    Y1 = 5*floor(sqrt(900-X*X)/5);
    /* BASIC: 140 FOR Y=Y1 TO -Y1 STEP -5 */
line_140:;
    Y = Y1; for_loop_Y_140: if (((-5) >= 0 && Y > (-Y1)) || ((-5) < 0 && Y < (-Y1))) goto end_for_Y_140;
    /* BASIC: 150 Z=INT(25+FNA(SQR(X*X+Y*Y))-.7*Y) */
line_150:;
    Z = floor(25+FNA(sqrt(X*X+Y*Y))-.7*Y);
    /* BASIC: 160 IF Z<=L THEN 190 */
line_160:;
    if (Z<=L) { goto line_190; }
    /* BASIC: 170 L=Z */
line_170:;
    L = Z;
    /* BASIC: 180 PRINT TAB(Z);"*"; */
line_180:;
    { int _t; for(_t=0; _t<Z; _t++) printf(" "); } printf("%s", "*");
    /* BASIC: 190 NEXT Y */
line_190:;
    Y += (-5); goto for_loop_Y_140; end_for_Y_140:;
    /* BASIC: 200 PRINT */
line_200:;
    printf("\n");
    /* BASIC: 210 NEXT X */
line_210:;
    X += (1.5); goto for_loop_X_110; end_for_X_110:;
    /* BASIC: 300 END */
line_300:;
    exit(0);

    return 0;
}
