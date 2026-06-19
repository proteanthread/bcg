/*
 * Transpiled from chemist.bas
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
static double A, D, R, T, W;
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 3 PRINT TAB(33);"CHEMIST" */
line_3:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "CHEMIST"); printf("\n");
    /* BASIC: 6 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_6:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 8 PRINT:PRINT:PRINT */
line_8:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 10 PRINT "THE FICTITIOUS CHECMICAL KRYPTOCYANIC ACID CAN ONLY BE" */
line_10:;
    printf("%s", "THE FICTITIOUS CHECMICAL KRYPTOCYANIC ACID CAN ONLY BE"); printf("\n");
    /* BASIC: 20 PRINT "DILUTED BY THE RATIO OF 7 PARTS WATER TO 3 PARTS ACID." */
line_20:;
    printf("%s", "DILUTED BY THE RATIO OF 7 PARTS WATER TO 3 PARTS ACID."); printf("\n");
    /* BASIC: 30 PRINT "IF ANY OTHER RATIO IS ATTEMPTED, THE ACID BECOMES UNSTABLE" */
line_30:;
    printf("%s", "IF ANY OTHER RATIO IS ATTEMPTED, THE ACID BECOMES UNSTABLE"); printf("\n");
    /* BASIC: 40 PRINT "AND SOON EXPLODES.  GIVEN THE AMOUNT OF ACID, YOU MUST" */
line_40:;
    printf("%s", "AND SOON EXPLODES.  GIVEN THE AMOUNT OF ACID, YOU MUST"); printf("\n");
    /* BASIC: 50 PRINT "DECIDE WHO MUCH WATER TO ADD FOR DILUTION.  IF YOU MISS" */
line_50:;
    printf("%s", "DECIDE WHO MUCH WATER TO ADD FOR DILUTION.  IF YOU MISS"); printf("\n");
    /* BASIC: 60 PRINT "YOU FACE THE CONSEQUENCES." */
line_60:;
    printf("%s", "YOU FACE THE CONSEQUENCES."); printf("\n");
    /* BASIC: 100 A=INT(RND(1)*50) */
line_100:;
    A = floor(((double)rand() / (double)RAND_MAX)*50);
    /* BASIC: 110 W=7*A/3 */
line_110:;
    W = 7*A/3;
    /* BASIC: 120 PRINT A;"LITERS OF KRYPTOCYANIC ACID.  HOW MUCH WATER"; */
line_120:;
    printf("%g ", (double)(A)); printf("%s", "LITERS OF KRYPTOCYANIC ACID.  HOW MUCH WATER");
    /* BASIC: 130 INPUT R */
line_130:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &R);
    /* BASIC: 140 D=ABS(W-R) */
line_140:;
    D = fabs(W-R);
    /* BASIC: 150 IF D>W/20 THEN 200 */
line_150:;
    if (D>W/20) { goto line_200; }
    /* BASIC: 160 PRINT " GOOD JOB! YOU MAY BREATHE NOW, BUT DON'T INHALE THE FUMES!" */
line_160:;
    printf("%s", " GOOD JOB! YOU MAY BREATHE NOW, BUT DON'T INHALE THE FUMES!"); printf("\n");
    /* BASIC: 170 PRINT */
line_170:;
    printf("\n");
    /* BASIC: 180 GOTO 100 */
line_180:;
    goto line_100;
    /* BASIC: 200 PRINT " SIZZLE!  YOU HAVE JUST BEEN DESALINATED INTO A BLOB" */
line_200:;
    printf("%s", " SIZZLE!  YOU HAVE JUST BEEN DESALINATED INTO A BLOB"); printf("\n");
    /* BASIC: 210 PRINT " OF QUIVERING PROTOPLASM!" */
line_210:;
    printf("%s", " OF QUIVERING PROTOPLASM!"); printf("\n");
    /* BASIC: 220 T=T+1 */
line_220:;
    T = T+1;
    /* BASIC: 230 IF T=9 THEN 260 */
line_230:;
    if (T==9) { goto line_260; }
    /* BASIC: 240 PRINT " HOWEVER, YOU MAY TRY AGAIN WITH ANOTHER LIFE." */
line_240:;
    printf("%s", " HOWEVER, YOU MAY TRY AGAIN WITH ANOTHER LIFE."); printf("\n");
    /* BASIC: 250 GOTO 100 */
line_250:;
    goto line_100;
    /* BASIC: 260 PRINT " YOUR 9 LIVES ARE USED, BUT YOU WILL BE LONG REMEMBERED FOR" */
line_260:;
    printf("%s", " YOUR 9 LIVES ARE USED, BUT YOU WILL BE LONG REMEMBERED FOR"); printf("\n");
    /* BASIC: 270 PRINT " YOUR CONTRIBUTIONS TO THE FIELD OF COMIC BOOK CHEMISTRY." */
line_270:;
    printf("%s", " YOUR CONTRIBUTIONS TO THE FIELD OF COMIC BOOK CHEMISTRY."); printf("\n");
    /* BASIC: 280 END */
line_280:;
    exit(0);

    return 0;
}
