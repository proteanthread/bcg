/*
 * Transpiled from flipflop.bas
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
static double C, M, N, Q, R, X, Z;
static char A_str[256] = {0};
static char X_str[256] = {0};
static char A_str_arr[1000][64] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 2 PRINT TAB(32);"FLIPFLOP" */
line_2:;
    { int _t; for(_t=0; _t<32; _t++) printf(" "); } printf("%s", "FLIPFLOP"); printf("\n");
    /* BASIC: 4 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 6 PRINT */
line_6:;
    printf("\n");
    /* BASIC: 10 REM *** CREATED BY MICHAEL CASS */
line_10:;
    /* REM *** CREATED BY MICHAEL CASS */
    /* BASIC: 15 DIM A$(20) */
line_15:;
    /* DIM A$(20) (handled statically) */
    /* BASIC: 20 PRINT "THE OBJECT OF THIS PUZZLE IS TO CHANGE THIS:" */
line_20:;
    printf("%s", "THE OBJECT OF THIS PUZZLE IS TO CHANGE THIS:"); printf("\n");
    /* BASIC: 30 PRINT */
line_30:;
    printf("\n");
    /* BASIC: 40 PRINT "X X X X X X X X X X" */
line_40:;
    printf("%s", "X X X X X X X X X X"); printf("\n");
    /* BASIC: 50 PRINT */
line_50:;
    printf("\n");
    /* BASIC: 60 PRINT "TO THIS:" */
line_60:;
    printf("%s", "TO THIS:"); printf("\n");
    /* BASIC: 70 PRINT */
line_70:;
    printf("\n");
    /* BASIC: 80 PRINT "O O O O O O O O O O" */
line_80:;
    printf("%s", "O O O O O O O O O O"); printf("\n");
    /* BASIC: 90 PRINT */
line_90:;
    printf("\n");
    /* BASIC: 100 PRINT "BY TYPING THE NUMBER CORRESPONDING TO THE POSITION OF THE" */
line_100:;
    printf("%s", "BY TYPING THE NUMBER CORRESPONDING TO THE POSITION OF THE"); printf("\n");
    /* BASIC: 110 PRINT "LETTER ON SOME NUMBERS, ONE POSITION WILL CHANGE, ON" */
line_110:;
    printf("%s", "LETTER ON SOME NUMBERS, ONE POSITION WILL CHANGE, ON"); printf("\n");
    /* BASIC: 120 PRINT "OTHERS, TWO WILL CHANGE.  TO RESET LINE TO ALL X'S, TYPE 0" */
line_120:;
    printf("%s", "OTHERS, TWO WILL CHANGE.  TO RESET LINE TO ALL X'S, TYPE 0"); printf("\n");
    /* BASIC: 130 PRINT "(ZERO) AND TO START OVER IN THE MIDDLE OF A GAME, TYPE " */
line_130:;
    printf("%s", "(ZERO) AND TO START OVER IN THE MIDDLE OF A GAME, TYPE "); printf("\n");
    /* BASIC: 140 PRINT "11 (ELEVEN)." */
line_140:;
    printf("%s", "11 (ELEVEN)."); printf("\n");
    /* BASIC: 170 PRINT */
line_170:;
    printf("\n");
    /* BASIC: 180 REM */
line_180:;
    /* REM */
    /* BASIC: 190 Q=RND(1) */
line_190:;
    Q = ((double)rand() / (double)RAND_MAX);
    /* BASIC: 200 PRINT "HERE IS THE STARTING LINE OF X'S." */
line_200:;
    printf("%s", "HERE IS THE STARTING LINE OF X'S."); printf("\n");
    /* BASIC: 210 PRINT */
line_210:;
    printf("\n");
    /* BASIC: 220 C=0 */
line_220:;
    C = 0;
    /* BASIC: 230 PRINT "1 2 3 4 5 6 7 8 9 10" */
line_230:;
    printf("%s", "1 2 3 4 5 6 7 8 9 10"); printf("\n");
    /* BASIC: 240 PRINT "X X X X X X X X X X" */
line_240:;
    printf("%s", "X X X X X X X X X X"); printf("\n");
    /* BASIC: 250 PRINT */
line_250:;
    printf("\n");
    /* BASIC: 260 REM */
line_260:;
    /* REM */
    /* BASIC: 270 FOR X=1 TO 10 */
line_270:;
    X = 1; for_loop_X_270: if (((1) >= 0 && X > (10)) || ((1) < 0 && X < (10))) goto end_for_X_270;
    /* BASIC: 280 A$(X)="X" */
line_280:;
    str_assign(A_str_arr[(int)(X)], sizeof(A_str_arr[(int)(X)]), "X");
    /* BASIC: 290 NEXT X */
line_290:;
    X += (1); goto for_loop_X_270; end_for_X_270:;
    /* BASIC: 300 GOTO 320 */
line_300:;
    goto line_320;
    /* BASIC: 310 PRINT "ILLEGAL ENTRY--TRY AGAIN." */
line_310:;
    printf("%s", "ILLEGAL ENTRY--TRY AGAIN."); printf("\n");
    /* BASIC: 320 PRINT "INPUT THE NUMBER"; */
line_320:;
    printf("%s", "INPUT THE NUMBER");
    /* BASIC: 330 INPUT N */
line_330:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &N);
    /* BASIC: 340 IF N<>INT(N) THEN 310 */
line_340:;
    if (N!=floor(N)) { goto line_310; }
    /* BASIC: 350 IF N=11 THEN 180 */
line_350:;
    if (N==11) { goto line_180; }
    /* BASIC: 360 IF N>11 THEN 310 */
line_360:;
    if (N>11) { goto line_310; }
    /* BASIC: 370 IF N=0 THEN 230 */
line_370:;
    if (N==0) { goto line_230; }
    /* BASIC: 380 IF M=N THEN 510 */
line_380:;
    if (M==N) { goto line_510; }
    /* BASIC: 390 M=N */
line_390:;
    M = N;
    /* BASIC: 400 IF A$(N)="O" THEN 480 */
line_400:;
    if (strcmp(A_str_arr[(int)(N)], "O") == 0) { goto line_480; }
    /* BASIC: 410 A$(N)="O" */
line_410:;
    str_assign(A_str_arr[(int)(N)], sizeof(A_str_arr[(int)(N)]), "O");
    /* BASIC: 420 R=TAN(Q+N/Q-N)-SIN(Q/N)+336*SIN(8*N) */
line_420:;
    R = tan(Q+N/Q-N)-sin(Q/N)+336*sin(8*N);
    /* BASIC: 430 N=R-INT(R) */
line_430:;
    N = R-floor(R);
    /* BASIC: 440 N=INT(10*N) */
line_440:;
    N = floor(10*N);
    /* BASIC: 450 IF A$(N)="O" THEN 480 */
line_450:;
    if (strcmp(A_str_arr[(int)(N)], "O") == 0) { goto line_480; }
    /* BASIC: 460 A$(N)="O" */
line_460:;
    str_assign(A_str_arr[(int)(N)], sizeof(A_str_arr[(int)(N)]), "O");
    /* BASIC: 470 GOTO 610 */
line_470:;
    goto line_610;
    /* BASIC: 480 A$(N)="X" */
line_480:;
    str_assign(A_str_arr[(int)(N)], sizeof(A_str_arr[(int)(N)]), "X");
    /* BASIC: 490 IF M=N THEN 420 */
line_490:;
    if (M==N) { goto line_420; }
    /* BASIC: 500 GOTO 610 */
line_500:;
    goto line_610;
    /* BASIC: 510 IF A$(N)="O" THEN 590 */
line_510:;
    if (strcmp(A_str_arr[(int)(N)], "O") == 0) { goto line_590; }
    /* BASIC: 520 A$(N)="O" */
line_520:;
    str_assign(A_str_arr[(int)(N)], sizeof(A_str_arr[(int)(N)]), "O");
    /* BASIC: 530 R=.592*(1/TAN(Q/N+Q))/SIN(N*2+Q)-COS(N) */
line_530:;
    R = .592*(1/tan(Q/N+Q))/sin(N*2+Q)-cos(N);
    /* BASIC: 540 N=R-INT(R) */
line_540:;
    N = R-floor(R);
    /* BASIC: 550 N=INT(10*N) */
line_550:;
    N = floor(10*N);
    /* BASIC: 560 IF A$(N)="O" THEN 590 */
line_560:;
    if (strcmp(A_str_arr[(int)(N)], "O") == 0) { goto line_590; }
    /* BASIC: 570 A$(N)="O" */
line_570:;
    str_assign(A_str_arr[(int)(N)], sizeof(A_str_arr[(int)(N)]), "O");
    /* BASIC: 580 GOTO 610 */
line_580:;
    goto line_610;
    /* BASIC: 590 A$(N)="X" */
line_590:;
    str_assign(A_str_arr[(int)(N)], sizeof(A_str_arr[(int)(N)]), "X");
    /* BASIC: 600 IF M=N THEN 530 */
line_600:;
    if (M==N) { goto line_530; }
    /* BASIC: 610 PRINT "1 2 3 4 5 6 7 8 9 10" */
line_610:;
    printf("%s", "1 2 3 4 5 6 7 8 9 10"); printf("\n");
    /* BASIC: 620 FOR Z=1 TO 10: PRINT A$(Z);" ";: NEXT Z */
line_620:;
    Z = 1; for_loop_Z_620: if (((1) >= 0 && Z > (10)) || ((1) < 0 && Z < (10))) goto end_for_Z_620;
    printf("%s", A_str_arr[(int)(Z)]); printf("%s", " ");
    Z += (1); goto for_loop_Z_620; end_for_Z_620:;
    /* BASIC: 630 C=C+1 */
line_630:;
    C = C+1;
    /* BASIC: 640 PRINT */
line_640:;
    printf("\n");
    /* BASIC: 650 FOR Z=1 TO 10 */
line_650:;
    Z = 1; for_loop_Z_650: if (((1) >= 0 && Z > (10)) || ((1) < 0 && Z < (10))) goto end_for_Z_650;
    /* BASIC: 660 IF A$(Z)<>"O" THEN 320 */
line_660:;
    if (strcmp(A_str_arr[(int)(Z)], "O") != 0) { goto line_320; }
    /* BASIC: 670 NEXT Z */
line_670:;
    Z += (1); goto for_loop_Z_650; end_for_Z_650:;
    /* BASIC: 680 IF C>12 THEN 710 */
line_680:;
    if (C>12) { goto line_710; }
    /* BASIC: 690 PRINT "VERY GOOD.  YOU GUESSED IT IN ONLY";C;"GUESSES." */
line_690:;
    printf("%s", "VERY GOOD.  YOU GUESSED IT IN ONLY"); printf("%g ", (double)(C)); printf("%s", "GUESSES."); printf("\n");
    /* BASIC: 700 GOTO 720 */
line_700:;
    goto line_720;
    /* BASIC: 710 PRINT "TRY HARDER NEXT TIME.  IT TOOK YOU";C;"GUESSES." */
line_710:;
    printf("%s", "TRY HARDER NEXT TIME.  IT TOOK YOU"); printf("%g ", (double)(C)); printf("%s", "GUESSES."); printf("\n");
    /* BASIC: 720 PRINT "DO YOU WANT TO TRY ANOTHER PUZZLE"; */
line_720:;
    printf("%s", "DO YOU WANT TO TRY ANOTHER PUZZLE");
    /* BASIC: 730 INPUT X$ */
line_730:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", X_str);
    /* BASIC: 740 IF LEFT$(X$,1)="N" THEN 780 */
line_740:;
    if (strcmp(basic_LEFT(X_str,1), "N") == 0) { goto line_780; }
    /* BASIC: 760 PRINT */
line_760:;
    printf("\n");
    /* BASIC: 770 GOTO 180 */
line_770:;
    goto line_180;
    /* BASIC: 780 END */
line_780:;
    exit(0);

    return 0;
}
