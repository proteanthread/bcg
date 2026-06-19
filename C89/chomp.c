/*
 * Transpiled from chomp.bas
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
static double A, C, C1, F, I, I1, J, LET, P, P1, R, R1;
static char R_str[256] = {0};
static double A_arr[2000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(33);"CHOMP" */
line_10:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "CHOMP"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 40 DIM A(10,10) */
line_40:;
    /* DIM A(10,10) (handled statically) */
    /* BASIC: 100 REM *** THE GAME OF CHOMP *** COPYRIGHT PCC 1973 *** */
line_100:;
    /* REM *** THE GAME OF CHOMP *** COPYRIGHT PCC 1973 *** */
    /* BASIC: 110 PRINT */
line_110:;
    printf("\n");
    /* BASIC: 120 PRINT "THIS IS THE GAME OF CHOMP (SCIENTIFIC AMERICAN, JAN 1973)" */
line_120:;
    printf("%s", "THIS IS THE GAME OF CHOMP (SCIENTIFIC AMERICAN, JAN 1973)"); printf("\n");
    /* BASIC: 130 PRINT "DO YOU WANT THE RULES (1=YES, 0=NO!)"; */
line_130:;
    printf("%s", "DO YOU WANT THE RULES (1=YES, 0=NO!)");
    /* BASIC: 140 INPUT R */
line_140:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &R);
    /* BASIC: 150 IF R=0 THEN 340 */
line_150:;
    if (R==0) { goto line_340; }
    /* BASIC: 160 F=1 */
line_160:;
    F = 1;
    /* BASIC: 170 R=5 */
line_170:;
    R = 5;
    /* BASIC: 180 C=7 */
line_180:;
    C = 7;
    /* BASIC: 190 PRINT "CHOMP IS FOR 1 OR MORE PLAYERS (HUMANS ONLY)." */
line_190:;
    printf("%s", "CHOMP IS FOR 1 OR MORE PLAYERS (HUMANS ONLY)."); printf("\n");
    /* BASIC: 200 PRINT */
line_200:;
    printf("\n");
    /* BASIC: 210 PRINT "HERE'S HOW A BOARD LOOKS (THIS ONE IS 5 BY 7):" */
line_210:;
    printf("%s", "HERE'S HOW A BOARD LOOKS (THIS ONE IS 5 BY 7):"); printf("\n");
    /* BASIC: 220 GOSUB 540 */
line_220:;
    gosub_stack[gosub_sp++] = 1; goto line_540; line_ret_1:;
    /* BASIC: 230 PRINT */
line_230:;
    printf("\n");
    /* BASIC: 240 PRINT "THE BOARD IS A BIG COOKIE - R ROWS HIGH AND C COLUMNS" */
line_240:;
    printf("%s", "THE BOARD IS A BIG COOKIE - R ROWS HIGH AND C COLUMNS"); printf("\n");
    /* BASIC: 250 PRINT "WIDE. YOU INPUT R AND C AT THE START. IN THE UPPER LEFT" */
line_250:;
    printf("%s", "WIDE. YOU INPUT R AND C AT THE START. IN THE UPPER LEFT"); printf("\n");
    /* BASIC: 260 PRINT "CORNER OF THE COOKIE IS A POISON SQUARE (P). THE ONE WHO" */
line_260:;
    printf("%s", "CORNER OF THE COOKIE IS A POISON SQUARE (P). THE ONE WHO"); printf("\n");
    /* BASIC: 270 PRINT "CHOMPS THE POISON SQUARE LOSES. TO TAKE A CHOMP, TYPE THE" */
line_270:;
    printf("%s", "CHOMPS THE POISON SQUARE LOSES. TO TAKE A CHOMP, TYPE THE"); printf("\n");
    /* BASIC: 280 PRINT "ROW AND COLUMN OF ONE OF THE SQUARES ON THE COOKIE." */
line_280:;
    printf("%s", "ROW AND COLUMN OF ONE OF THE SQUARES ON THE COOKIE."); printf("\n");
    /* BASIC: 290 PRINT "ALL OF THE SQUARES BELOW AND TO THE RIGHT OF THAT SQUARE" */
line_290:;
    printf("%s", "ALL OF THE SQUARES BELOW AND TO THE RIGHT OF THAT SQUARE"); printf("\n");
    /* BASIC: 300 PRINT "(INCLUDING THAT SQUARE, TOO) DISAPPEAR -- CHOMP!!" */
line_300:;
    printf("%s", "(INCLUDING THAT SQUARE, TOO) DISAPPEAR -- CHOMP!!"); printf("\n");
    /* BASIC: 310 PRINT "NO FAIR CHOMPING SQUARES THAT HAVE ALREADY BEEN CHOMPED," */
line_310:;
    printf("%s", "NO FAIR CHOMPING SQUARES THAT HAVE ALREADY BEEN CHOMPED,"); printf("\n");
    /* BASIC: 320 PRINT "OR THAT ARE OUTSIDE THE ORIGINAL DIMENSIONS OF THE COOKIE." */
line_320:;
    printf("%s", "OR THAT ARE OUTSIDE THE ORIGINAL DIMENSIONS OF THE COOKIE."); printf("\n");
    /* BASIC: 330 PRINT */
line_330:;
    printf("\n");
    /* BASIC: 340 PRINT "HERE WE GO..." */
line_340:;
    printf("%s", "HERE WE GO..."); printf("\n");
    /* BASIC: 350 REM */
line_350:;
    /* REM */
    /* BASIC: 360 F=0 */
line_360:;
    F = 0;
    /* BASIC: 370 FOR I=1 TO 10 */
line_370:;
    I = 1; for_loop_I_370: if (((1) >= 0 && I > (10)) || ((1) < 0 && I < (10))) goto end_for_I_370;
    /* BASIC: 372 FOR J=1 TO 10 */
line_372:;
    J = 1; for_loop_J_372: if (((1) >= 0 && J > (10)) || ((1) < 0 && J < (10))) goto end_for_J_372;
    /* BASIC: 375 A(I,J)=0 */
line_375:;
    A_arr[(int)(I) * 100 + (int)(J)] = 0;
    /* BASIC: 377 NEXT J */
line_377:;
    J += (1); goto for_loop_J_372; end_for_J_372:;
    /* BASIC: 379 NEXT I */
line_379:;
    I += (1); goto for_loop_I_370; end_for_I_370:;
    /* BASIC: 380 PRINT */
line_380:;
    printf("\n");
    /* BASIC: 390 PRINT "HOW MANY PLAYERS"; */
line_390:;
    printf("%s", "HOW MANY PLAYERS");
    /* BASIC: 400 INPUT P */
line_400:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &P);
    /* BASIC: 410 I1=0 */
line_410:;
    I1 = 0;
    /* BASIC: 420 PRINT "HOW MANY ROWS"; */
line_420:;
    printf("%s", "HOW MANY ROWS");
    /* BASIC: 430 INPUT R */
line_430:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &R);
    /* BASIC: 440 IF R <= 9 THEN 470 */
line_440:;
    if (R <= 9) { goto line_470; }
    /* BASIC: 450 PRINT "TOO MANY ROWS (9 IS MAXIMUM). NOW, "; */
line_450:;
    printf("%s", "TOO MANY ROWS (9 IS MAXIMUM). NOW, ");
    /* BASIC: 460 GOTO 420 */
line_460:;
    goto line_420;
    /* BASIC: 470 PRINT "HOW MANY COLUMNS"; */
line_470:;
    printf("%s", "HOW MANY COLUMNS");
    /* BASIC: 480 INPUT C */
line_480:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &C);
    /* BASIC: 490 IF C <= 9 THEN 530 */
line_490:;
    if (C <= 9) { goto line_530; }
    /* BASIC: 500 PRINT "TOO MANY COLUMNS (9 IS MAXIMUM). NOW, "; */
line_500:;
    printf("%s", "TOO MANY COLUMNS (9 IS MAXIMUM). NOW, ");
    /* BASIC: 510 GOTO 470 */
line_510:;
    goto line_470;
    /* BASIC: 530 PRINT */
line_530:;
    printf("\n");
    /* BASIC: 540 FOR I=1 TO R */
line_540:;
    I = 1; for_loop_I_540: if (((1) >= 0 && I > (R)) || ((1) < 0 && I < (R))) goto end_for_I_540;
    /* BASIC: 550 FOR J=1 TO C */
line_550:;
    J = 1; for_loop_J_550: if (((1) >= 0 && J > (C)) || ((1) < 0 && J < (C))) goto end_for_J_550;
    /* BASIC: 560 A(I,J)=1 */
line_560:;
    A_arr[(int)(I) * 100 + (int)(J)] = 1;
    /* BASIC: 570 NEXT J */
line_570:;
    J += (1); goto for_loop_J_550; end_for_J_550:;
    /* BASIC: 580 NEXT I */
line_580:;
    I += (1); goto for_loop_I_540; end_for_I_540:;
    /* BASIC: 590 A(1,1)=-1 */
line_590:;
    A_arr[(int)(1) * 100 + (int)(1)] = -1;
    /* BASIC: 600 REM PRINT THE BOARD */
line_600:;
    /* REM PRINT THE BOARD */
    /* BASIC: 610 PRINT */
line_610:;
    printf("\n");
    /* BASIC: 620 PRINT TAB(7);"1 2 3 4 5 6 7 8 9" */
line_620:;
    { int _t; for(_t=0; _t<7; _t++) printf(" "); } printf("%s", "1 2 3 4 5 6 7 8 9"); printf("\n");
    /* BASIC: 630 FOR I=1 TO R */
line_630:;
    I = 1; for_loop_I_630: if (((1) >= 0 && I > (R)) || ((1) < 0 && I < (R))) goto end_for_I_630;
    /* BASIC: 640 PRINT I;TAB(7); */
line_640:;
    printf("%g ", (double)(I)); { int _t; for(_t=0; _t<7; _t++) printf(" "); }
    /* BASIC: 650 FOR J=1 TO C */
line_650:;
    J = 1; for_loop_J_650: if (((1) >= 0 && J > (C)) || ((1) < 0 && J < (C))) goto end_for_J_650;
    /* BASIC: 660 IF A(I,J)=-1 THEN 700 */
line_660:;
    if (A_arr[(int)(I) * 100 + (int)(J)]==-1) { goto line_700; }
    /* BASIC: 670 IF A(I,J)=0 THEN 720 */
line_670:;
    if (A_arr[(int)(I) * 100 + (int)(J)]==0) { goto line_720; }
    /* BASIC: 680 PRINT "* "; */
line_680:;
    printf("%s", "* ");
    /* BASIC: 690 GOTO 710 */
line_690:;
    goto line_710;
    /* BASIC: 700 PRINT "P "; */
line_700:;
    printf("%s", "P ");
    /* BASIC: 710 NEXT J */
line_710:;
    J += (1); goto for_loop_J_650; end_for_J_650:;
    /* BASIC: 720 PRINT */
line_720:;
    printf("\n");
    /* BASIC: 730 NEXT I */
line_730:;
    I += (1); goto for_loop_I_630; end_for_I_630:;
    /* BASIC: 740 PRINT */
line_740:;
    printf("\n");
    /* BASIC: 750 IF F=0 THEN 770 */
line_750:;
    if (F==0) { goto line_770; }
    /* BASIC: 760 RETURN */
line_760:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 770 REM GET CHOMPS FOR EACH PLAYER IN TURN */
line_770:;
    /* REM GET CHOMPS FOR EACH PLAYER IN TURN */
    /* BASIC: 780 LET I1=I1+1 */
line_780:;
    /* UNTRANSLATED: LET I1=I1+1 */
    /* BASIC: 790 LET P1=I1-INT(I1/P)*P */
line_790:;
    /* UNTRANSLATED: LET P1=I1-INT(I1/P)*P */
    /* BASIC: 800 IF P1 <> 0 THEN 820 */
line_800:;
    if (P1 != 0) { goto line_820; }
    /* BASIC: 810 P1=P */
line_810:;
    P1 = P;
    /* BASIC: 820 PRINT "PLAYER";P1 */
line_820:;
    printf("%s", "PLAYER"); printf("%g ", (double)(P1)); printf("\n");
    /* BASIC: 830 PRINT "COORDINATES OF CHOMP (ROW,COLUMN)"; */
line_830:;
    printf("%s", "COORDINATES OF CHOMP (ROW,COLUMN)");
    /* BASIC: 840 INPUT R1,C1 */
line_840:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf", &R1, &C1);
    /* BASIC: 850 IF R1<1 THEN 920 */
line_850:;
    if (R1<1) { goto line_920; }
    /* BASIC: 860 IF R1>R THEN 920 */
line_860:;
    if (R1>R) { goto line_920; }
    /* BASIC: 870 IF C1<1 THEN 920 */
line_870:;
    if (C1<1) { goto line_920; }
    /* BASIC: 880 IF C1>C THEN 920 */
line_880:;
    if (C1>C) { goto line_920; }
    /* BASIC: 890 IF A(R1,C1)=0 THEN 920 */
line_890:;
    if (A_arr[(int)(R1) * 100 + (int)(C1)]==0) { goto line_920; }
    /* BASIC: 900 IF A(R1,C1)=-1 THEN 1010 */
line_900:;
    if (A_arr[(int)(R1) * 100 + (int)(C1)]==-1) { goto line_1010; }
    /* BASIC: 910 GOTO 940 */
line_910:;
    goto line_940;
    /* BASIC: 920 PRINT "NO FAIR. YOU'RE TRYING TO CHOMP ON EMPTY SPACE!" */
line_920:;
    printf("%s", "NO FAIR. YOU'RE TRYING TO CHOMP ON EMPTY SPACE!"); printf("\n");
    /* BASIC: 930 GOTO 820 */
line_930:;
    goto line_820;
    /* BASIC: 940 FOR I=R1 TO R */
line_940:;
    I = R1; for_loop_I_940: if (((1) >= 0 && I > (R)) || ((1) < 0 && I < (R))) goto end_for_I_940;
    /* BASIC: 950 FOR J=C1 TO C */
line_950:;
    J = C1; for_loop_J_950: if (((1) >= 0 && J > (C)) || ((1) < 0 && J < (C))) goto end_for_J_950;
    /* BASIC: 960 A(I,J)=0 */
line_960:;
    A_arr[(int)(I) * 100 + (int)(J)] = 0;
    /* BASIC: 970 NEXT J */
line_970:;
    J += (1); goto for_loop_J_950; end_for_J_950:;
    /* BASIC: 980 NEXT I */
line_980:;
    I += (1); goto for_loop_I_940; end_for_I_940:;
    /* BASIC: 990 GOTO 610 */
line_990:;
    goto line_610;
    /* BASIC: 1000 REM END OF GAME DETECTED IN LINE 900 */
line_1000:;
    /* REM END OF GAME DETECTED IN LINE 900 */
    /* BASIC: 1010 PRINT "YOU LOSE, PLAYER";P1 */
line_1010:;
    printf("%s", "YOU LOSE, PLAYER"); printf("%g ", (double)(P1)); printf("\n");
    /* BASIC: 1020 PRINT */
line_1020:;
    printf("\n");
    /* BASIC: 1030 PRINT "AGAIN (1=YES, 0=NO!)"; */
line_1030:;
    printf("%s", "AGAIN (1=YES, 0=NO!)");
    /* BASIC: 1040 INPUT R$ */
line_1040:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", R_str);
    /* BASIC: 1050 IF R=1 THEN 340 */
line_1050:;
    if (R==1) { goto line_340; }
    /* BASIC: 1060 END */
line_1060:;
    exit(0);

    return 0;
}
