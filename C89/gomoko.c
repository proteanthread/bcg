/*
 * Transpiled from gomoko.bas
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
static double A, E, F, I, J, L, N, Q, X, Y;
static double A_arr[2000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 2 PRINT TAB(33);"GOMOKO" */
line_2:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "GOMOKO"); printf("\n");
    /* BASIC: 4 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 6 PRINT:PRINT:PRINT */
line_6:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 8 DIM A(19,19) */
line_8:;
    /* DIM A(19,19) (handled statically) */
    /* BASIC: 10 PRINT "WELCOME TO THE ORIENTAL GAME OF GOMOKO." */
line_10:;
    printf("%s", "WELCOME TO THE ORIENTAL GAME OF GOMOKO."); printf("\n");
    /* BASIC: 20 PRINT: PRINT "THE GAME IS PLAYED ON AN N BY N GRID OF A SIZE" */
line_20:;
    printf("\n");
    printf("%s", "THE GAME IS PLAYED ON AN N BY N GRID OF A SIZE"); printf("\n");
    /* BASIC: 30 PRINT "THAT YOU SPECIFY.  DURING YOUR PLAY, YOU MAY COVER ONE GRID" */
line_30:;
    printf("%s", "THAT YOU SPECIFY.  DURING YOUR PLAY, YOU MAY COVER ONE GRID"); printf("\n");
    /* BASIC: 40 PRINT "INTERSECTION WITH A MARKER. THE OBJECT OF THE GAME IS TO GET" */
line_40:;
    printf("%s", "INTERSECTION WITH A MARKER. THE OBJECT OF THE GAME IS TO GET"); printf("\n");
    /* BASIC: 50 PRINT "5 ADJACENT MARKERS IN A ROW -- HORIZONTALLY, VERTICALLY, OR" */
line_50:;
    printf("%s", "5 ADJACENT MARKERS IN A ROW -- HORIZONTALLY, VERTICALLY, OR"); printf("\n");
    /* BASIC: 60 PRINT "DIAGONALLY.  ON THE BOARD DIAGRAM, YOUR MOVES ARE MARKED" */
line_60:;
    printf("%s", "DIAGONALLY.  ON THE BOARD DIAGRAM, YOUR MOVES ARE MARKED"); printf("\n");
    /* BASIC: 70 PRINT "WITH A '1' AND THE COMPUTER MOVES WITH A '2'." */
line_70:;
    printf("%s", "WITH A '1' AND THE COMPUTER MOVES WITH A '2'."); printf("\n");
    /* BASIC: 80 PRINT: PRINT "THE COMPUTER DOES NOT KEEP TRACK OF WHO HAS WON." */
line_80:;
    printf("\n");
    printf("%s", "THE COMPUTER DOES NOT KEEP TRACK OF WHO HAS WON."); printf("\n");
    /* BASIC: 90 PRINT "TO END THE GAME, TYPE -1,-1 FOR YOUR MOVE.": PRINT */
line_90:;
    printf("%s", "TO END THE GAME, TYPE -1,-1 FOR YOUR MOVE."); printf("\n");
    printf("\n");
    /* BASIC: 110 PRINT "WHAT IS YOUR BOARD SIZE (MIN 7/ MAX 19)";: INPUT N */
line_110:;
    printf("%s", "WHAT IS YOUR BOARD SIZE (MIN 7/ MAX 19)");
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &N);
    /* BASIC: 115 IF N>6 THEN 117 */
line_115:;
    if (N>6) { goto line_117; }
    /* BASIC: 116 GOTO 120 */
line_116:;
    goto line_120;
    /* BASIC: 117 IF N<20 THEN 210 */
line_117:;
    if (N<20) { goto line_210; }
    /* BASIC: 120 PRINT "I SAID, THE MINIMUM IS 7, THE MAXIMUM IS 19.": GOTO 110 */
line_120:;
    printf("%s", "I SAID, THE MINIMUM IS 7, THE MAXIMUM IS 19."); printf("\n");
    goto line_110;
    /* BASIC: 210 FOR I=1 TO N:FOR J=1 TO N: A(I,J)=0: NEXT J: NEXT I */
line_210:;
    I = 1; for_loop_I_210: if (((1) >= 0 && I > (N)) || ((1) < 0 && I < (N))) goto end_for_I_210;
    J = 1; for_loop_J_210: if (((1) >= 0 && J > (N)) || ((1) < 0 && J < (N))) goto end_for_J_210;
    A_arr[(int)(I) * 100 + (int)(J)] = 0;
    J += (1); goto for_loop_J_210; end_for_J_210:;
    I += (1); goto for_loop_I_210; end_for_I_210:;
    /* BASIC: 300 PRINT: PRINT "WE ALTERNATE MOVES.  YOU GO FIRST...": PRINT */
line_300:;
    printf("\n");
    printf("%s", "WE ALTERNATE MOVES.  YOU GO FIRST..."); printf("\n");
    printf("\n");
    /* BASIC: 310 PRINT "YOUR PLAY (I,J)";: INPUT I,J */
line_310:;
    printf("%s", "YOUR PLAY (I,J)");
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf", &I, &J);
    /* BASIC: 315 PRINT */
line_315:;
    printf("\n");
    /* BASIC: 320 IF I=-1 THEN 980 */
line_320:;
    if (I==-1) { goto line_980; }
    /* BASIC: 330 X=I: Y=J: GOSUB 910: IF L=1 THEN 410 */
line_330:;
    X = I;
    Y = J;
    gosub_stack[gosub_sp++] = 1; goto line_910; line_ret_1:;
    if (L==1) { goto line_410; }
    /* BASIC: 340 PRINT "ILLEGAL MOVE.  TRY AGAIN...": GOTO 310 */
line_340:;
    printf("%s", "ILLEGAL MOVE.  TRY AGAIN..."); printf("\n");
    goto line_310;
    /* BASIC: 410 IF A(I,J)=0 THEN 440 */
line_410:;
    if (A_arr[(int)(I) * 100 + (int)(J)]==0) { goto line_440; }
    /* BASIC: 420 PRINT "SQUARE OCCUPIED.  TRY AGAIN...": GOTO 310 */
line_420:;
    printf("%s", "SQUARE OCCUPIED.  TRY AGAIN..."); printf("\n");
    goto line_310;
    /* BASIC: 440 A(I,J)=1 */
line_440:;
    A_arr[(int)(I) * 100 + (int)(J)] = 1;
    /* BASIC: 500 REM *** COMPUTER TRIES AN INTELLIGENT MOVE *** */
line_500:;
    /* REM *** COMPUTER TRIES AN INTELLIGENT MOVE *** */
    /* BASIC: 510 FOR E=-1 TO 1: FOR F=-1 TO 1: IF E+F-E*F=0 THEN 590 */
line_510:;
    E = -1; for_loop_E_510: if (((1) >= 0 && E > (1)) || ((1) < 0 && E < (1))) goto end_for_E_510;
    F = -1; for_loop_F_510: if (((1) >= 0 && F > (1)) || ((1) < 0 && F < (1))) goto end_for_F_510;
    if (E+F-E*F==0) { goto line_590; }
    /* BASIC: 540 X=I+F: Y=J+F: GOSUB 910 */
line_540:;
    X = I+F;
    Y = J+F;
    gosub_stack[gosub_sp++] = 2; goto line_910; line_ret_2:;
    /* BASIC: 570 IF L=0 THEN 590 */
line_570:;
    if (L==0) { goto line_590; }
    /* BASIC: 580 IF A(X,Y)=1 THEN 710 */
line_580:;
    if (A_arr[(int)(X) * 100 + (int)(Y)]==1) { goto line_710; }
    /* BASIC: 590 NEXT F: NEXT E */
line_590:;
    F += (1); goto for_loop_F_510; end_for_F_510:;
    E += (1); goto for_loop_E_510; end_for_E_510:;
    /* BASIC: 600 REM *** COMPUTER TRIES A R AND OM MOVE *** */
line_600:;
    /* REM *** COMPUTER TRIES A R AND OM MOVE *** */
    /* BASIC: 610 X=INT(N*RND(1)+1): Y=INT(N*RND(1)+1): GOSUB 910: IF L=0 THEN 610 */
line_610:;
    X = floor(N*((double)rand() / (double)RAND_MAX)+1);
    Y = floor(N*((double)rand() / (double)RAND_MAX)+1);
    gosub_stack[gosub_sp++] = 3; goto line_910; line_ret_3:;
    if (L==0) { goto line_610; }
    /* BASIC: 650 IF A(X,Y)<>0 THEN 610 */
line_650:;
    if (A_arr[(int)(X) * 100 + (int)(Y)]!=0) { goto line_610; }
    /* BASIC: 660 A(X,Y)=2: GOSUB 810: GOTO 310 */
line_660:;
    A_arr[(int)(X) * 100 + (int)(Y)] = 2;
    gosub_stack[gosub_sp++] = 4; goto line_810; line_ret_4:;
    goto line_310;
    /* BASIC: 710 X=I-E: Y=J-F: GOSUB 910 */
line_710:;
    X = I-E;
    Y = J-F;
    gosub_stack[gosub_sp++] = 5; goto line_910; line_ret_5:;
    /* BASIC: 750 IF L=0 THEN 610 */
line_750:;
    if (L==0) { goto line_610; }
    /* BASIC: 760 GOTO 650 */
line_760:;
    goto line_650;
    /* BASIC: 800 REM *** PRINT THE BOARD *** */
line_800:;
    /* REM *** PRINT THE BOARD *** */
    /* BASIC: 810 FOR I=1 TO N: FOR J=1 TO N: PRINT A(I,J); */
line_810:;
    I = 1; for_loop_I_810: if (((1) >= 0 && I > (N)) || ((1) < 0 && I < (N))) goto end_for_I_810;
    J = 1; for_loop_J_810: if (((1) >= 0 && J > (N)) || ((1) < 0 && J < (N))) goto end_for_J_810;
    printf("%g ", (double)(A_arr[(int)(I) * 100 + (int)(J)]));
    /* BASIC: 840 NEXT J: PRINT: NEXT I: PRINT: RETURN */
line_840:;
    J += (1); goto for_loop_J_810; end_for_J_810:;
    printf("\n");
    I += (1); goto for_loop_I_810; end_for_I_810:;
    printf("\n");
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 910 L=1: IF X<1 THEN 970 */
line_910:;
    L = 1;
    if (X<1) { goto line_970; }
    /* BASIC: 920 IF X>N THEN 970 */
line_920:;
    if (X>N) { goto line_970; }
    /* BASIC: 930 IF Y<1 THEN 970 */
line_930:;
    if (Y<1) { goto line_970; }
    /* BASIC: 940 IF Y>N THEN 970 */
line_940:;
    if (Y>N) { goto line_970; }
    /* BASIC: 950 RETURN */
line_950:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 970 L=0: RETURN */
line_970:;
    L = 0;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 980 PRINT: PRINT "THANKS FOR THE GAME!!" */
line_980:;
    printf("\n");
    printf("%s", "THANKS FOR THE GAME!!"); printf("\n");
    /* BASIC: 985 PRINT "PLAY AGAIN (1 FOR YES, 0 FOR NO)";: INPUT Q */
line_985:;
    printf("%s", "PLAY AGAIN (1 FOR YES, 0 FOR NO)");
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &Q);
    /* BASIC: 990 IF Q=1 THEN 110 */
line_990:;
    if (Q==1) { goto line_110; }
    /* BASIC: 999 END */
line_999:;
    exit(0);

    return 0;
}
