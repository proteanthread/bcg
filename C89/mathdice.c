/*
 * Transpiled from mathdice.bas
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
static double A, D, N, T, T1, T2;
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(31);"MATH DICE" */
line_10:;
    { int _t; for(_t=0; _t<31; _t++) printf(" "); } printf("%s", "MATH DICE"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 40 PRINT "THIS PROGRAM GENERATES SUCCESIVE PICTURES OF TWO DICE." */
line_40:;
    printf("%s", "THIS PROGRAM GENERATES SUCCESIVE PICTURES OF TWO DICE."); printf("\n");
    /* BASIC: 50 PRINT "WHEN TWO DICE AND AN EQUAL SIGN FOLLOWED BY A QUESTION" */
line_50:;
    printf("%s", "WHEN TWO DICE AND AN EQUAL SIGN FOLLOWED BY A QUESTION"); printf("\n");
    /* BASIC: 60 PRINT "MARK HAVE BEEN PRINTED, TYPE YOUR ANSWER AND THE RETURN KEY." */
line_60:;
    printf("%s", "MARK HAVE BEEN PRINTED, TYPE YOUR ANSWER AND THE RETURN KEY."); printf("\n");
    /* BASIC: 70 PRINT "TO CONCLUDE THE LESSON, TYPE CONTROL-C AS YOUR ANSWER." */
line_70:;
    printf("%s", "TO CONCLUDE THE LESSON, TYPE CONTROL-C AS YOUR ANSWER."); printf("\n");
    /* BASIC: 80 PRINT */
line_80:;
    printf("\n");
    /* BASIC: 90 PRINT */
line_90:;
    printf("\n");
    /* BASIC: 100 N=N+1 */
line_100:;
    N = N+1;
    /* BASIC: 110 D=INT(6*RND(1)+1) */
line_110:;
    D = floor(6*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 120 PRINT" ----- " */
line_120:;
    printf("%s", " ----- "); printf("\n");
    /* BASIC: 130 IF D=1 THEN 200 */
line_130:;
    if (D==1) { goto line_200; }
    /* BASIC: 140 IF D=2 THEN 180 */
line_140:;
    if (D==2) { goto line_180; }
    /* BASIC: 150 IF D=3 THEN 180 */
line_150:;
    if (D==3) { goto line_180; }
    /* BASIC: 160 PRINT "I * * I" */
line_160:;
    printf("%s", "I * * I"); printf("\n");
    /* BASIC: 170 GOTO 210 */
line_170:;
    goto line_210;
    /* BASIC: 180 PRINT "I *   I" */
line_180:;
    printf("%s", "I *   I"); printf("\n");
    /* BASIC: 190 GOTO 210 */
line_190:;
    goto line_210;
    /* BASIC: 200 PRINT "I     I" */
line_200:;
    printf("%s", "I     I"); printf("\n");
    /* BASIC: 210 IF D=2 THEN 260 */
line_210:;
    if (D==2) { goto line_260; }
    /* BASIC: 220 IF D=4 THEN 260 */
line_220:;
    if (D==4) { goto line_260; }
    /* BASIC: 230 IF D=6 THEN 270 */
line_230:;
    if (D==6) { goto line_270; }
    /* BASIC: 240 PRINT "I  *  I" */
line_240:;
    printf("%s", "I  *  I"); printf("\n");
    /* BASIC: 250 GOTO 280 */
line_250:;
    goto line_280;
    /* BASIC: 260 PRINT "I     I" */
line_260:;
    printf("%s", "I     I"); printf("\n");
    /* BASIC: 265 GOTO 280 */
line_265:;
    goto line_280;
    /* BASIC: 270 PRINT "I * * I" */
line_270:;
    printf("%s", "I * * I"); printf("\n");
    /* BASIC: 280 IF D=1 THEN 350 */
line_280:;
    if (D==1) { goto line_350; }
    /* BASIC: 290 IF D=2 THEN 330 */
line_290:;
    if (D==2) { goto line_330; }
    /* BASIC: 300 IF D=3 THEN 330 */
line_300:;
    if (D==3) { goto line_330; }
    /* BASIC: 310 PRINT "I * * I" */
line_310:;
    printf("%s", "I * * I"); printf("\n");
    /* BASIC: 320 GOTO 360 */
line_320:;
    goto line_360;
    /* BASIC: 330 PRINT "I   * I" */
line_330:;
    printf("%s", "I   * I"); printf("\n");
    /* BASIC: 340 GOTO 360 */
line_340:;
    goto line_360;
    /* BASIC: 350 PRINT "I     I" */
line_350:;
    printf("%s", "I     I"); printf("\n");
    /* BASIC: 360 PRINT " ----- " */
line_360:;
    printf("%s", " ----- "); printf("\n");
    /* BASIC: 370 PRINT */
line_370:;
    printf("\n");
    /* BASIC: 375 IF N=2 THEN 500 */
line_375:;
    if (N==2) { goto line_500; }
    /* BASIC: 380 PRINT "   +" */
line_380:;
    printf("%s", "   +"); printf("\n");
    /* BASIC: 381 PRINT */
line_381:;
    printf("\n");
    /* BASIC: 400 A=D */
line_400:;
    A = D;
    /* BASIC: 410 GOTO 100 */
line_410:;
    goto line_100;
    /* BASIC: 500 T=D+A */
line_500:;
    T = D+A;
    /* BASIC: 510 PRINT "      ="; */
line_510:;
    printf("%s", "      =");
    /* BASIC: 520 INPUT T1 */
line_520:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &T1);
    /* BASIC: 530 IF T1=T THEN 590 */
line_530:;
    if (T1==T) { goto line_590; }
    /* BASIC: 540 PRINT "NO, COUNT THE SPOTS AND GIVE ANOTHER ANSWER." */
line_540:;
    printf("%s", "NO, COUNT THE SPOTS AND GIVE ANOTHER ANSWER."); printf("\n");
    /* BASIC: 541 PRINT "      ="; */
line_541:;
    printf("%s", "      =");
    /* BASIC: 550 INPUT T2 */
line_550:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &T2);
    /* BASIC: 560 IF T2=T THEN 590 */
line_560:;
    if (T2==T) { goto line_590; }
    /* BASIC: 570 PRINT "NO, THE ANSWER IS";T */
line_570:;
    printf("%s", "NO, THE ANSWER IS"); printf("%g ", (double)(T)); printf("\n");
    /* BASIC: 580 GOTO 600 */
line_580:;
    goto line_600;
    /* BASIC: 590 PRINT "RIGHT!" */
line_590:;
    printf("%s", "RIGHT!"); printf("\n");
    /* BASIC: 600 PRINT */
line_600:;
    printf("\n");
    /* BASIC: 601 PRINT "THE DICE ROLL AGAIN..." */
line_601:;
    printf("%s", "THE DICE ROLL AGAIN..."); printf("\n");
    /* BASIC: 610 PRINT */
line_610:;
    printf("\n");
    /* BASIC: 615 N=0 */
line_615:;
    N = 0;
    /* BASIC: 620 GOTO 100 */
line_620:;
    goto line_100;
    /* BASIC: 999 END */
line_999:;
    exit(0);

    return 0;
}
