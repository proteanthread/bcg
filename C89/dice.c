/*
 * Transpiled from dice.bas
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
static double A, B, F, Q, R, S, V, X;
static char Z_str[256] = {0};
static double F_arr[2000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 2 PRINT TAB(34);"DICE" */
line_2:;
    { int _t; for(_t=0; _t<34; _t++) printf(" "); } printf("%s", "DICE"); printf("\n");
    /* BASIC: 4 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 6 PRINT:PRINT:PRINT */
line_6:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 10 DIM F(12) */
line_10:;
    /* DIM F(12) (handled statically) */
    /* BASIC: 20 REM  DANNY FREIDUS */
line_20:;
    /* REM  DANNY FREIDUS */
    /* BASIC: 30 PRINT "THIS PROGRAM SIMULATES THE ROLLING OF A" */
line_30:;
    printf("%s", "THIS PROGRAM SIMULATES THE ROLLING OF A"); printf("\n");
    /* BASIC: 40 PRINT "PAIR OF DICE." */
line_40:;
    printf("%s", "PAIR OF DICE."); printf("\n");
    /* BASIC: 50 PRINT "YOU ENTER THE NUMBER OF TIMES YOU WANT THE COMPUTER TO" */
line_50:;
    printf("%s", "YOU ENTER THE NUMBER OF TIMES YOU WANT THE COMPUTER TO"); printf("\n");
    /* BASIC: 60 PRINT "'ROLL' THE DICE.  WATCH OUT, VERY LARGE NUMBERS TAKE" */
line_60:;
    printf("%s", "'ROLL' THE DICE.  WATCH OUT, VERY LARGE NUMBERS TAKE"); printf("\n");
    /* BASIC: 70 PRINT "A LONG TIME.  IN PARTICULAR, NUMBERS OVER 5000." */
line_70:;
    printf("%s", "A LONG TIME.  IN PARTICULAR, NUMBERS OVER 5000."); printf("\n");
    /* BASIC: 80 FOR Q=1 TO 12 */
line_80:;
    Q = 1; for_loop_Q_80: if (((1) >= 0 && Q > (12)) || ((1) < 0 && Q < (12))) goto end_for_Q_80;
    /* BASIC: 90 F(Q)=0 */
line_90:;
    F_arr[(int)(Q)] = 0;
    /* BASIC: 100 NEXT Q */
line_100:;
    Q += (1); goto for_loop_Q_80; end_for_Q_80:;
    /* BASIC: 110 PRINT:PRINT "HOW MANY ROLLS"; */
line_110:;
    printf("\n");
    printf("%s", "HOW MANY ROLLS");
    /* BASIC: 120 INPUT X */
line_120:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &X);
    /* BASIC: 130 FOR S=1 TO X */
line_130:;
    S = 1; for_loop_S_130: if (((1) >= 0 && S > (X)) || ((1) < 0 && S < (X))) goto end_for_S_130;
    /* BASIC: 140 A=INT(6*RND(1)+1) */
line_140:;
    A = floor(6*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 150 B=INT(6*RND(1)+1) */
line_150:;
    B = floor(6*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 160 R=A+B */
line_160:;
    R = A+B;
    /* BASIC: 170 F(R)=F(R)+1 */
line_170:;
    F_arr[(int)(R)] = F_arr[(int)(R)]+1;
    /* BASIC: 180 NEXT S */
line_180:;
    S += (1); goto for_loop_S_130; end_for_S_130:;
    /* BASIC: 185 PRINT */
line_185:;
    printf("\n");
    /* BASIC: 190 PRINT "TOTAL SPOTS","NUMBER OF TIMES" */
line_190:;
    printf("%s", "TOTAL SPOTS"); printf("\t"); printf("%s", "NUMBER OF TIMES"); printf("\n");
    /* BASIC: 200 FOR V=2 TO 12 */
line_200:;
    V = 2; for_loop_V_200: if (((1) >= 0 && V > (12)) || ((1) < 0 && V < (12))) goto end_for_V_200;
    /* BASIC: 210 PRINT V,F(V) */
line_210:;
    printf("%g ", (double)(V)); printf("\t"); printf("%g ", (double)(F_arr[(int)(V)])); printf("\n");
    /* BASIC: 220 NEXT V */
line_220:;
    V += (1); goto for_loop_V_200; end_for_V_200:;
    /* BASIC: 221 PRINT */
line_221:;
    printf("\n");
    /* BASIC: 222 PRINT:PRINT "TRY AGAIN"; */
line_222:;
    printf("\n");
    printf("%s", "TRY AGAIN");
    /* BASIC: 223 INPUT Z$ */
line_223:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", Z_str);
    /* BASIC: 224 IF Z$="YES" THEN 80 */
line_224:;
    if (strcmp(Z_str, "YES") == 0) { goto line_80; }
    /* BASIC: 240 END */
line_240:;
    exit(0);

    return 0;
}
