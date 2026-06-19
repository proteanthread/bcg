/*
 * Transpiled from batnum.bas
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
static double A, B, C, I, M, N, P, Q, S, W;
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(33);"BATNUM" */
line_10:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "BATNUM"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 110 PRINT "THIS PROGRAM IS A 'BATTLE OF NUMBERS' GAME, WHERE THE" */
line_110:;
    printf("%s", "THIS PROGRAM IS A 'BATTLE OF NUMBERS' GAME, WHERE THE"); printf("\n");
    /* BASIC: 120 PRINT "COMPUTER IS YOUR OPPONENT." */
line_120:;
    printf("%s", "COMPUTER IS YOUR OPPONENT."); printf("\n");
    /* BASIC: 130 PRINT */
line_130:;
    printf("\n");
    /* BASIC: 140 PRINT "THE GAME STARTS WITH AN ASSUMED PILE OF OBJECTS. YOU" */
line_140:;
    printf("%s", "THE GAME STARTS WITH AN ASSUMED PILE OF OBJECTS. YOU"); printf("\n");
    /* BASIC: 150 PRINT "AND YOUR OPPONENT ALTERNATELY REMOVE OBJECTS FROM THE PILE." */
line_150:;
    printf("%s", "AND YOUR OPPONENT ALTERNATELY REMOVE OBJECTS FROM THE PILE."); printf("\n");
    /* BASIC: 160 PRINT "WINNING IS DEFINED IN ADVANCE AS TAKING THE LAST OBJECT OR" */
line_160:;
    printf("%s", "WINNING IS DEFINED IN ADVANCE AS TAKING THE LAST OBJECT OR"); printf("\n");
    /* BASIC: 170 PRINT "NOT. YOU CAN ALSO SPECIFY SOME OTHER BEGINNING CONDITIONS." */
line_170:;
    printf("%s", "NOT. YOU CAN ALSO SPECIFY SOME OTHER BEGINNING CONDITIONS."); printf("\n");
    /* BASIC: 180 PRINT "DON'T USE ZERO, HOWEVER, IN PLAYING THE GAME." */
line_180:;
    printf("%s", "DON'T USE ZERO, HOWEVER, IN PLAYING THE GAME."); printf("\n");
    /* BASIC: 190 PRINT "ENTER A NEGATIVE NUMBER FOR NEW PILE SIZE TO STOP PLAYING." */
line_190:;
    printf("%s", "ENTER A NEGATIVE NUMBER FOR NEW PILE SIZE TO STOP PLAYING."); printf("\n");
    /* BASIC: 200 PRINT */
line_200:;
    printf("\n");
    /* BASIC: 210 GOTO 330 */
line_210:;
    goto line_330;
    /* BASIC: 220 FOR I=1 TO 10 */
line_220:;
    I = 1; for_loop_I_220: if (((1) >= 0 && I > (10)) || ((1) < 0 && I < (10))) goto end_for_I_220;
    /* BASIC: 230 PRINT */
line_230:;
    printf("\n");
    /* BASIC: 240 NEXT I */
line_240:;
    I += (1); goto for_loop_I_220; end_for_I_220:;
    /* BASIC: 330 INPUT "ENTER PILE SIZE";N */
line_330:;
    printf("%s", "ENTER PILE SIZE"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &N);
    /* BASIC: 350 IF N>=1 THEN 370 */
line_350:;
    if (N>=1) { goto line_370; }
    /* BASIC: 360 GOTO 330 */
line_360:;
    goto line_330;
    /* BASIC: 370 IF N<>INT(N) THEN 220 */
line_370:;
    if (N!=floor(N)) { goto line_220; }
    /* BASIC: 380 IF N<1 THEN 220 */
line_380:;
    if (N<1) { goto line_220; }
    /* BASIC: 390 INPUT "ENTER WIN OPTION - 1 TO TAKE LAST, 2 TO AVOID LAST: ";M */
line_390:;
    printf("%s", "ENTER WIN OPTION - 1 TO TAKE LAST, 2 TO AVOID LAST: "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &M);
    /* BASIC: 410 IF M=1 THEN 430 */
line_410:;
    if (M==1) { goto line_430; }
    /* BASIC: 420 IF M<>2 THEN 390 */
line_420:;
    if (M!=2) { goto line_390; }
    /* BASIC: 430 INPUT "ENTER MIN AND MAX ";A,B */
line_430:;
    printf("%s", "ENTER MIN AND MAX "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf", &A, &B);
    /* BASIC: 450 IF A>B THEN 430 */
line_450:;
    if (A>B) { goto line_430; }
    /* BASIC: 460 IF A<1 THEN 430 */
line_460:;
    if (A<1) { goto line_430; }
    /* BASIC: 470 IF A<>INT(A) THEN 430 */
line_470:;
    if (A!=floor(A)) { goto line_430; }
    /* BASIC: 480 IF B<>INT(B) THEN 430 */
line_480:;
    if (B!=floor(B)) { goto line_430; }
    /* BASIC: 490 INPUT "ENTER START OPTION - 1 COMPUTER FIRST, 2 YOU FIRST ";S */
line_490:;
    printf("%s", "ENTER START OPTION - 1 COMPUTER FIRST, 2 YOU FIRST "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &S);
    /* BASIC: 500 PRINT:PRINT */
line_500:;
    printf("\n");
    printf("\n");
    /* BASIC: 510 IF S=1 THEN 530 */
line_510:;
    if (S==1) { goto line_530; }
    /* BASIC: 520 IF S<>2 THEN 490 */
line_520:;
    if (S!=2) { goto line_490; }
    /* BASIC: 530 C=A+B */
line_530:;
    C = A+B;
    /* BASIC: 540 IF S=2 THEN 570 */
line_540:;
    if (S==2) { goto line_570; }
    /* BASIC: 550 GOSUB 600 */
line_550:;
    gosub_stack[gosub_sp++] = 1; goto line_600; line_ret_1:;
    /* BASIC: 560 IF W=1 THEN 220 */
line_560:;
    if (W==1) { goto line_220; }
    /* BASIC: 570 GOSUB 810 */
line_570:;
    gosub_stack[gosub_sp++] = 2; goto line_810; line_ret_2:;
    /* BASIC: 580 IF W=1 THEN 220 */
line_580:;
    if (W==1) { goto line_220; }
    /* BASIC: 590 GOTO 550 */
line_590:;
    goto line_550;
    /* BASIC: 600 Q=N */
line_600:;
    Q = N;
    /* BASIC: 610 IF M=1 THEN 630 */
line_610:;
    if (M==1) { goto line_630; }
    /* BASIC: 620 Q=Q-1 */
line_620:;
    Q = Q-1;
    /* BASIC: 630 IF M=1 THEN 680 */
line_630:;
    if (M==1) { goto line_680; }
    /* BASIC: 640 IF N>A THEN 720 */
line_640:;
    if (N>A) { goto line_720; }
    /* BASIC: 650 W=1 */
line_650:;
    W = 1;
    /* BASIC: 660 PRINT "COMPUTER TAKES";N;"AND LOSES." */
line_660:;
    printf("%s", "COMPUTER TAKES"); printf("%g ", (double)(N)); printf("%s", "AND LOSES."); printf("\n");
    /* BASIC: 670 RETURN */
line_670:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 680 IF N>B THEN 720 */
line_680:;
    if (N>B) { goto line_720; }
    /* BASIC: 690 W=1 */
line_690:;
    W = 1;
    /* BASIC: 700 PRINT "COMPUTER TAKES";N;"AND WINS." */
line_700:;
    printf("%s", "COMPUTER TAKES"); printf("%g ", (double)(N)); printf("%s", "AND WINS."); printf("\n");
    /* BASIC: 710 RETURN */
line_710:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 720 P=Q-C*INT(Q/C) */
line_720:;
    P = Q-C*floor(Q/C);
    /* BASIC: 730 IF P>=A THEN 750 */
line_730:;
    if (P>=A) { goto line_750; }
    /* BASIC: 740 P=A */
line_740:;
    P = A;
    /* BASIC: 750 IF P<=B THEN 770 */
line_750:;
    if (P<=B) { goto line_770; }
    /* BASIC: 760 P=B */
line_760:;
    P = B;
    /* BASIC: 770 N=N-P */
line_770:;
    N = N-P;
    /* BASIC: 780 PRINT "COMPUTER TAKES";P;"AND LEAVES";N */
line_780:;
    printf("%s", "COMPUTER TAKES"); printf("%g ", (double)(P)); printf("%s", "AND LEAVES"); printf("%g ", (double)(N)); printf("\n");
    /* BASIC: 790 W=0 */
line_790:;
    W = 0;
    /* BASIC: 800 RETURN */
line_800:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 810 PRINT:PRINT "YOUR MOVE "; */
line_810:;
    printf("\n");
    printf("%s", "YOUR MOVE ");
    /* BASIC: 820 INPUT P */
line_820:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &P);
    /* BASIC: 830 IF P<>0 THEN 870 */
line_830:;
    if (P!=0) { goto line_870; }
    /* BASIC: 840 PRINT "I TOLD YOU NOT TO USE ZERO! COMPUTER WINS BY FORFEIT." */
line_840:;
    printf("%s", "I TOLD YOU NOT TO USE ZERO! COMPUTER WINS BY FORFEIT."); printf("\n");
    /* BASIC: 850 W=1 */
line_850:;
    W = 1;
    /* BASIC: 860 RETURN */
line_860:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 870 IF P<>INT(P) THEN 920 */
line_870:;
    if (P!=floor(P)) { goto line_920; }
    /* BASIC: 880 IF P>=A THEN 910 */
line_880:;
    if (P>=A) { goto line_910; }
    /* BASIC: 890 IF P=N THEN 960 */
line_890:;
    if (P==N) { goto line_960; }
    /* BASIC: 900 GOTO 920 */
line_900:;
    goto line_920;
    /* BASIC: 910 IF P<=B THEN 940 */
line_910:;
    if (P<=B) { goto line_940; }
    /* BASIC: 920 PRINT "ILLEGAL MOVE, REENTER IT "; */
line_920:;
    printf("%s", "ILLEGAL MOVE, REENTER IT ");
    /* BASIC: 930 GOTO 820 */
line_930:;
    goto line_820;
    /* BASIC: 940 N=N-P */
line_940:;
    N = N-P;
    /* BASIC: 950 IF N<>0 THEN 1030 */
line_950:;
    if (N!=0) { goto line_1030; }
    /* BASIC: 960 IF M=1 THEN 1000 */
line_960:;
    if (M==1) { goto line_1000; }
    /* BASIC: 970 PRINT "TOUGH LUCK, YOU LOSE." */
line_970:;
    printf("%s", "TOUGH LUCK, YOU LOSE."); printf("\n");
    /* BASIC: 980 W=1 */
line_980:;
    W = 1;
    /* BASIC: 990 RETURN */
line_990:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1000 PRINT "CONGRATULATIONS, YOU WIN." */
line_1000:;
    printf("%s", "CONGRATULATIONS, YOU WIN."); printf("\n");
    /* BASIC: 1010 W=1 */
line_1010:;
    W = 1;
    /* BASIC: 1020 RETURN */
line_1020:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1030 IF N>=0 THEN 1060 */
line_1030:;
    if (N>=0) { goto line_1060; }
    /* BASIC: 1040 N=N+P */
line_1040:;
    N = N+P;
    /* BASIC: 1050 GOTO 920 */
line_1050:;
    goto line_920;
    /* BASIC: 1060 W=0 */
line_1060:;
    W = 0;
    /* BASIC: 1070 RETURN */
line_1070:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1080 END */
line_1080:;
    exit(0);

    return 0;
}
