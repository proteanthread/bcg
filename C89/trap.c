/*
 * Transpiled from trap.bas
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
static int gosub_stack[256];
static int gosub_sp = 0;
static double A, B, G, N, Q, R, X;
static char Z_str[256] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 1 PRINT TAB(34);"TRAP" */
line_1:;
    { int _t; for(_t=0; _t<34; _t++) printf(" "); } printf("%s", "TRAP"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT:PRINT:PRINT */
line_3:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 10 G=6 */
line_10:;
    G = 6;
    /* BASIC: 20 N=100 */
line_20:;
    N = 100;
    /* BASIC: 30 REM-TRAP */
line_30:;
    /* REM-TRAP */
    /* BASIC: 40 REM-STEVE ULLMAN, 8-1-72 */
line_40:;
    /* REM-STEVE ULLMAN, 8-1-72 */
    /* BASIC: 50 PRINT "INSTRUCTIONS"; */
line_50:;
    printf("%s", "INSTRUCTIONS");
    /* BASIC: 60 INPUT Z$ */
line_60:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", Z_str);
    /* BASIC: 70 IF LEFT$(Z$,1)<>"Y" THEN 180 */
line_70:;
    if (strcmp(basic_LEFT(Z_str,1), "Y") != 0) { goto line_180; }
    /* BASIC: 80 PRINT "I AM THINKING OF A NUMBER BETWEEN 1 AND";N */
line_80:;
    printf("%s", "I AM THINKING OF A NUMBER BETWEEN 1 AND"); printf("%g ", (double)(N)); printf("\n");
    /* BASIC: 90 PRINT "TRY TO GUESS MY NUMBER. ON EACH GUESS," */
line_90:;
    printf("%s", "TRY TO GUESS MY NUMBER. ON EACH GUESS,"); printf("\n");
    /* BASIC: 100 PRINT "YOU ARE TO ENTER 2 NUMBERS, TRYING TO TRAP" */
line_100:;
    printf("%s", "YOU ARE TO ENTER 2 NUMBERS, TRYING TO TRAP"); printf("\n");
    /* BASIC: 110 PRINT "MY NUMBER BETWEEN THE TWO NUMBERS. I WILL" */
line_110:;
    printf("%s", "MY NUMBER BETWEEN THE TWO NUMBERS. I WILL"); printf("\n");
    /* BASIC: 120 PRINT "TELL YOU IF YOU HAVE TRAPPED MY NUMBER, IF MY" */
line_120:;
    printf("%s", "TELL YOU IF YOU HAVE TRAPPED MY NUMBER, IF MY"); printf("\n");
    /* BASIC: 130 PRINT "NUMBER IS LARGER THAN YOUR TWO NUMBERS, OR IF" */
line_130:;
    printf("%s", "NUMBER IS LARGER THAN YOUR TWO NUMBERS, OR IF"); printf("\n");
    /* BASIC: 140 PRINT "MY NUMBER IS SMALLER THAN YOUR TWO NUMBERS." */
line_140:;
    printf("%s", "MY NUMBER IS SMALLER THAN YOUR TWO NUMBERS."); printf("\n");
    /* BASIC: 150 PRINT "IF YOU WANT TO GUESS ONE SINGLE NUMBER, TYPE" */
line_150:;
    printf("%s", "IF YOU WANT TO GUESS ONE SINGLE NUMBER, TYPE"); printf("\n");
    /* BASIC: 160 PRINT "YOUR GUESS FOR BOTH YOUR TRAP NUMBERS." */
line_160:;
    printf("%s", "YOUR GUESS FOR BOTH YOUR TRAP NUMBERS."); printf("\n");
    /* BASIC: 170 PRINT "YOU GET";G;"GUESSES TO GET MY NUMBER." */
line_170:;
    printf("%s", "YOU GET"); printf("%g ", (double)(G)); printf("%s", "GUESSES TO GET MY NUMBER."); printf("\n");
    /* BASIC: 180 X=INT(N*RND(1))+1 */
line_180:;
    X = floor(N*((double)rand() / (double)RAND_MAX))+1;
    /* BASIC: 190 FOR Q=1 TO G */
line_190:;
    Q = 1; for_loop_Q_190: if (((1) >= 0 && Q > (G)) || ((1) < 0 && Q < (G))) goto end_for_Q_190;
    /* BASIC: 200 PRINT */
line_200:;
    printf("\n");
    /* BASIC: 210 PRINT "GUESS #";Q; */
line_210:;
    printf("%s", "GUESS #"); printf("%g ", (double)(Q));
    /* BASIC: 220 INPUT A,B */
line_220:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf", &A, &B);
    /* BASIC: 230 IF A=B AND X=A THEN 400 */
line_230:;
    if (A==B   &&   X==A) { goto line_400; }
    /* BASIC: 240 IF A <= B THEN 260 */
line_240:;
    if (A <= B) { goto line_260; }
    /* BASIC: 250 GOSUB 360 */
line_250:;
    gosub_stack[gosub_sp++] = 1; goto line_360; line_ret_1:;
    /* BASIC: 260 IF A <= X AND X <= B THEN 320 */
line_260:;
    if (A <= X   &&   X <= B) { goto line_320; }
    /* BASIC: 270 IF X<A THEN 300 */
line_270:;
    if (X<A) { goto line_300; }
    /* BASIC: 280 PRINT "MY NUMBER IS LARGER THAN YOUR TRAP NUMBERS." */
line_280:;
    printf("%s", "MY NUMBER IS LARGER THAN YOUR TRAP NUMBERS."); printf("\n");
    /* BASIC: 290 GOTO 330 */
line_290:;
    goto line_330;
    /* BASIC: 300 PRINT "MY NUMBER IS SMALLER THAN YOUR TRAP NUMBERS." */
line_300:;
    printf("%s", "MY NUMBER IS SMALLER THAN YOUR TRAP NUMBERS."); printf("\n");
    /* BASIC: 310 GOTO 330 */
line_310:;
    goto line_330;
    /* BASIC: 320 PRINT "YOU HAVE TRAPPED MY NUMBER." */
line_320:;
    printf("%s", "YOU HAVE TRAPPED MY NUMBER."); printf("\n");
    /* BASIC: 330 NEXT Q */
line_330:;
    Q += (1); goto for_loop_Q_190; end_for_Q_190:;
    /* BASIC: 340 PRINT "SORRY, THAT'S";G;"GUESSES. THE NUMBER WAS";X */
line_340:;
    printf("%s", "SORRY, THAT'S"); printf("%g ", (double)(G)); printf("%s", "GUESSES. THE NUMBER WAS"); printf("%g ", (double)(X)); printf("\n");
    /* BASIC: 345 PRINT */
line_345:;
    printf("\n");
    /* BASIC: 350 GOTO 410 */
line_350:;
    goto line_410;
    /* BASIC: 360 R=A */
line_360:;
    R = A;
    /* BASIC: 370 A=B */
line_370:;
    A = B;
    /* BASIC: 380 B=R */
line_380:;
    B = R;
    /* BASIC: 390 RETURN */
line_390:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 400 PRINT "YOU GOT IT!!!" */
line_400:;
    printf("%s", "YOU GOT IT!!!"); printf("\n");
    /* BASIC: 410 PRINT */
line_410:;
    printf("\n");
    /* BASIC: 420 PRINT "TRY AGAIN." */
line_420:;
    printf("%s", "TRY AGAIN."); printf("\n");
    /* BASIC: 430 PRINT */
line_430:;
    printf("\n");
    /* BASIC: 440 GOTO 180 */
line_440:;
    goto line_180;
    /* BASIC: 450 END */
line_450:;
    exit(0);

    return 0;
}
