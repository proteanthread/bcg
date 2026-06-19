/*
 * Transpiled from sinewave.bas
 * GW-BASIC to strict C89 (ANSI) / C90 (ISO)
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
    if (n >= 0) sprintf(buf[idx], " %g", n);
    else sprintf(buf[idx], "%g", n);
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
    sprintf(buf[idx], "%s%s", s1, s2);
    return buf[idx];
}

static void str_assign(char *dest, size_t dest_sz, const char *src) {
    strncpy(dest, src, dest_sz - 1);
    dest[dest_sz - 1] = '\0';
}

/* Global variables */
static double A, B, T;
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(30);"SINE WAVE" */
line_10:;
    { int _t; for(_t=0; _t<30; _t++) printf(" "); } printf("%s", "SINE WAVE"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT: PRINT: PRINT: PRINT: PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 40 REMARKABLE PROGRAM BY DAVID AHL */
line_40:;
    /* REMARKABLE PROGRAM BY DAVID AHL */
    /* BASIC: 50 B=0 */
line_50:;
    B = 0;
    /* BASIC: 100 REM  START LONG LOOP */
line_100:;
    /* REM  START LONG LOOP */
    /* BASIC: 110 FOR T=0 TO 40 STEP .25 */
line_110:;
    T = 0; for_loop_T_110: if (((.25) >= 0 && T > (40)) || ((.25) < 0 && T < (40))) goto end_for_T_110;
    /* BASIC: 120 A=INT(26+25*SIN(T)) */
line_120:;
    A = floor(26+25*sin(T));
    /* BASIC: 130 PRINT TAB(A); */
line_130:;
    { int _t; for(_t=0; _t<A; _t++) printf(" "); }
    /* BASIC: 140 IF B=1 THEN 180 */
line_140:;
    if (B==1) { goto line_180; }
    /* BASIC: 150 PRINT "CREATIVE" */
line_150:;
    printf("%s", "CREATIVE"); printf("\n");
    /* BASIC: 160 B=1 */
line_160:;
    B = 1;
    /* BASIC: 170 GOTO 200 */
line_170:;
    goto line_200;
    /* BASIC: 180 PRINT "COMPUTING" */
line_180:;
    printf("%s", "COMPUTING"); printf("\n");
    /* BASIC: 190 B=0 */
line_190:;
    B = 0;
    /* BASIC: 200 NEXT T */
line_200:;
    T += (.25); goto for_loop_T_110; end_for_T_110:;
    /* BASIC: 999 END */
line_999:;
    exit(0);

    return 0;
}
