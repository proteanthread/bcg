/*
 * Transpiled from number.bas
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
static double DEF, G, P, R, S, T, U, V, X;
static char _input_buf[256];

/* User-defined functions forward declarations */
static double FNR(double X);

/* User-defined functions definitions */
static double FNR(double X) {
    return floor(5*((double)rand() / (double)RAND_MAX)+1);
}

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 1 PRINT TAB(33);"NUMBER" */
line_1:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "NUMBER"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT:PRINT:PRINT */
line_3:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 4 PRINT "YOU HAVE 100 POINTS.  BY GUESSING NUMBERS FROM 1 TO 5, YOU" */
line_4:;
    printf("%s", "YOU HAVE 100 POINTS.  BY GUESSING NUMBERS FROM 1 TO 5, YOU"); printf("\n");
    /* BASIC: 5 PRINT "CAN GAIN OR LOSE POINTS DEPENDING UPON HOW CLOSE YOU GET TO" */
line_5:;
    printf("%s", "CAN GAIN OR LOSE POINTS DEPENDING UPON HOW CLOSE YOU GET TO"); printf("\n");
    /* BASIC: 6 PRINT "A RANDOM NUMBER SELECTED BY THE COMPUTER.": PRINT */
line_6:;
    printf("%s", "A RANDOM NUMBER SELECTED BY THE COMPUTER."); printf("\n");
    printf("\n");
    /* BASIC: 7 PRINT "YOU OCCASIONALLY WILL GET A JACKPOT WHICH WILL DOUBLE(!)" */
line_7:;
    printf("%s", "YOU OCCASIONALLY WILL GET A JACKPOT WHICH WILL DOUBLE(!)"); printf("\n");
    /* BASIC: 8 PRINT "YOUR POINT COUNT.  YOU WIN WHEN YOU GET 500 POINTS." */
line_8:;
    printf("%s", "YOUR POINT COUNT.  YOU WIN WHEN YOU GET 500 POINTS."); printf("\n");
    /* BASIC: 9 PRINT: P=100 */
line_9:;
    printf("\n");
    P = 100;
    /* BASIC: 10 DEF FNR(X)=INT(5*RND(1)+1) */
line_10:;
    /* UNTRANSLATED: DEF FNR(X)=INT(5*RND(1)+1) */
    /* BASIC: 12 INPUT "GUESS A NUMBER FROM 1 TO 5";G */
line_12:;
    printf("%s", "GUESS A NUMBER FROM 1 TO 5"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &G);
    /* BASIC: 15 R=FNR(1) */
line_15:;
    R = FNR(1);
    /* BASIC: 16 S=FNR(1) */
line_16:;
    S = FNR(1);
    /* BASIC: 17 T=FNR(1) */
line_17:;
    T = FNR(1);
    /* BASIC: 18 U=FNR(1) */
line_18:;
    U = FNR(1);
    /* BASIC: 19 V=FNR(1) */
line_19:;
    V = FNR(1);
    /* BASIC: 20 IF G=R THEN 30 */
line_20:;
    if (G==R) { goto line_30; }
    /* BASIC: 21 IF G=S THEN 40 */
line_21:;
    if (G==S) { goto line_40; }
    /* BASIC: 22 IF G=T THEN 50 */
line_22:;
    if (G==T) { goto line_50; }
    /* BASIC: 23 IF G=U THEN 60 */
line_23:;
    if (G==U) { goto line_60; }
    /* BASIC: 24 IF G=V THEN 70 */
line_24:;
    if (G==V) { goto line_70; }
    /* BASIC: 25 IF G>5 THEN 12 */
line_25:;
    if (G>5) { goto line_12; }
    /* BASIC: 30 P=P-5 */
line_30:;
    P = P-5;
    /* BASIC: 35 GOTO 80 */
line_35:;
    goto line_80;
    /* BASIC: 40 P=P+5 */
line_40:;
    P = P+5;
    /* BASIC: 45 GOTO 80 */
line_45:;
    goto line_80;
    /* BASIC: 50 P=P+P */
line_50:;
    P = P+P;
    /* BASIC: 53 PRINT "YOU HIT THE JACKPOT!!!" */
line_53:;
    printf("%s", "YOU HIT THE JACKPOT!!!"); printf("\n");
    /* BASIC: 55 GOTO 80 */
line_55:;
    goto line_80;
    /* BASIC: 60 P=P+1 */
line_60:;
    P = P+1;
    /* BASIC: 65 GOTO 80 */
line_65:;
    goto line_80;
    /* BASIC: 70 P=P-(P*.5) */
line_70:;
    P = P-(P*.5);
    /* BASIC: 80 IF P>500 THEN 90 */
line_80:;
    if (P>500) { goto line_90; }
    /* BASIC: 82 PRINT "YOU HAVE";P;"POINTS.":PRINT */
line_82:;
    printf("%s", "YOU HAVE"); printf("%g ", (double)(P)); printf("%s", "POINTS."); printf("\n");
    printf("\n");
    /* BASIC: 85 GOTO 12 */
line_85:;
    goto line_12;
    /* BASIC: 90 PRINT "!!!!YOU WIN!!!! WITH ";P;"POINTS." */
line_90:;
    printf("%s", "!!!!YOU WIN!!!! WITH "); printf("%g ", (double)(P)); printf("%s", "POINTS."); printf("\n");
    /* BASIC: 99 END */
line_99:;
    exit(0);

    return 0;
}
