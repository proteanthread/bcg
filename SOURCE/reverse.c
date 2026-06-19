/*
 * Transpiled from reverse.bas
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
static int gosub_stack[256];
static int gosub_sp = 0;
static double A, J, K, N, R, T, Z;
static char A_str[256] = {0};
static double A_arr[20000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(32);"REVERSE" */
line_10:;
    { int _t; for(_t=0; _t<32; _t++) printf(" "); } printf("%s", "REVERSE"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 100 PRINT "REVERSE -- A GAME OF SKILL": PRINT */
line_100:;
    printf("%s", "REVERSE -- A GAME OF SKILL"); printf("\n");
    printf("\n");
    /* BASIC: 130 DIM A(20) */
line_130:;
    /* DIM A(20) (handled statically) */
    /* BASIC: 140 REM *** N=NUMBER OF NUMBERS */
line_140:;
    // REM *** N=NUMBER OF NUMBERS
    /* BASIC: 150 N=9 */
line_150:;
    N = 9;
    /* BASIC: 160 PRINT "DO YOU WANT THE RULES"; */
line_160:;
    printf("%s", "DO YOU WANT THE RULES");
    /* BASIC: 170 INPUT A$ */
line_170:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    /* BASIC: 180 IF A$="NO" THEN 210 */
line_180:;
    if (strcmp(A_str, "NO") == 0) { goto line_210; }
    /* BASIC: 190 GOSUB 710 */
line_190:;
    gosub_stack[gosub_sp++] = 1; goto line_710; line_ret_1:;
    /* BASIC: 200 REM *** MAKE A R AND OM LIST A(1) TO A(N) */
line_200:;
    // REM *** MAKE A R AND OM LIST A(1) TO A(N)
    /* BASIC: 210 A(1)=INT((N-1)*RND(1)+2) */
line_210:;
    A_arr[(int)(1)] = floor((N-1)*((double)rand() / (double)RAND_MAX)+2);
    /* BASIC: 220 FOR K=2 TO N */
line_220:;
    K = 2; for_loop_K_220: if (((1) >= 0 && K > (N)) || ((1) < 0 && K < (N))) goto end_for_K_220;
    /* BASIC: 230 A(K)=INT(N*RND(1)+1) */
line_230:;
    A_arr[(int)(K)] = floor(N*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 240 FOR J=1 TO K-1 */
line_240:;
    J = 1; for_loop_J_240: if (((1) >= 0 && J > (K-1)) || ((1) < 0 && J < (K-1))) goto end_for_J_240;
    /* BASIC: 250 IF A(K)=A(J) THEN 230 */
line_250:;
    if (A_arr[(int)(K)]==A_arr[(int)(J)]) { goto line_230; }
    /* BASIC: 260 NEXT J:NEXT K */
line_260:;
    J += (1); goto for_loop_J_240; end_for_J_240:;
    K += (1); goto for_loop_K_220; end_for_K_220:;
    /* BASIC: 280 REM *** PRINT OR IGINAL LIST AND START GAME */
line_280:;
    // REM *** PRINT OR IGINAL LIST AND START GAME
    /* BASIC: 290 PRINT: PRINT "HERE WE GO ... THE LIST IS:" */
line_290:;
    printf("\n");
    printf("%s", "HERE WE GO ... THE LIST IS:"); printf("\n");
    /* BASIC: 310 T=0 */
line_310:;
    T = 0;
    /* BASIC: 320 GOSUB 610 */
line_320:;
    gosub_stack[gosub_sp++] = 2; goto line_610; line_ret_2:;
    /* BASIC: 330 PRINT "HOW MANY SHALL I REVERSE"; */
line_330:;
    printf("%s", "HOW MANY SHALL I REVERSE");
    /* BASIC: 340 INPUT R */
line_340:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &R);
    /* BASIC: 350 IF R=0 THEN 520 */
line_350:;
    if (R==0) { goto line_520; }
    /* BASIC: 360 IF R<=N THEN 390 */
line_360:;
    if (R<=N) { goto line_390; }
    /* BASIC: 370 PRINT "OOPS! TOO MANY! I CAN REVERSE AT MOST";N:GOTO 330 */
line_370:;
    printf("%s", "OOPS! TOO MANY! I CAN REVERSE AT MOST"); printf("%g ", (double)(N)); printf("\n");
    goto line_330;
    /* BASIC: 390 T=T+1 */
line_390:;
    T = T+1;
    /* BASIC: 400 REM *** REVERSE R NUMBERS AND PRINT NEW LIST */
line_400:;
    // REM *** REVERSE R NUMBERS AND PRINT NEW LIST
    /* BASIC: 410 FOR K=1 TO INT(R/2) */
line_410:;
    K = 1; for_loop_K_410: if (((1) >= 0 && K > (floor(R/2))) || ((1) < 0 && K < (floor(R/2)))) goto end_for_K_410;
    /* BASIC: 420 Z=A(K) */
line_420:;
    Z = A_arr[(int)(K)];
    /* BASIC: 430 A(K)=A(R-K+1) */
line_430:;
    A_arr[(int)(K)] = A_arr[(int)(R-K+1)];
    /* BASIC: 440 A(R-K+1)=Z */
line_440:;
    A_arr[(int)(R-K+1)] = Z;
    /* BASIC: 450 NEXT K */
line_450:;
    K += (1); goto for_loop_K_410; end_for_K_410:;
    /* BASIC: 460 GOSUB 610 */
line_460:;
    gosub_stack[gosub_sp++] = 3; goto line_610; line_ret_3:;
    /* BASIC: 470 REM *** CHECK FOR A WIN */
line_470:;
    // REM *** CHECK FOR A WIN
    /* BASIC: 480 FOR K=1 TO N */
line_480:;
    K = 1; for_loop_K_480: if (((1) >= 0 && K > (N)) || ((1) < 0 && K < (N))) goto end_for_K_480;
    /* BASIC: 490 IF A(K)<>K THEN 330 */
line_490:;
    if (A_arr[(int)(K)]!=K) { goto line_330; }
    /* BASIC: 500 NEXT K */
line_500:;
    K += (1); goto for_loop_K_480; end_for_K_480:;
    /* BASIC: 510 PRINT "YOU WON IT IN";T;"MOVES!!!":PRINT */
line_510:;
    printf("%s", "YOU WON IT IN"); printf("%g ", (double)(T)); printf("%s", "MOVES!!!"); printf("\n");
    printf("\n");
    /* BASIC: 520 PRINT */
line_520:;
    printf("\n");
    /* BASIC: 530 PRINT "TRY AGAIN (YES OR NO)"; */
line_530:;
    printf("%s", "TRY AGAIN (YES OR NO)");
    /* BASIC: 540 INPUT A$ */
line_540:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    /* BASIC: 550 IF A$="YES" THEN 210 */
line_550:;
    if (strcmp(A_str, "YES") == 0) { goto line_210; }
    /* BASIC: 560 PRINT: PRINT "O.K. HOPE YOU HAD FUN!!":GOTO 999 */
line_560:;
    printf("\n");
    printf("%s", "O.K. HOPE YOU HAD FUN!!"); printf("\n");
    goto line_999;
    /* BASIC: 600 REM *** SUBROUTINE TO PRINT LIST */
line_600:;
    // REM *** SUBROUTINE TO PRINT LIST
    /* BASIC: 610 PRINT:FOR K=1 TO N:PRINT A(K);:NEXT K */
line_610:;
    printf("\n");
    K = 1; for_loop_K_610: if (((1) >= 0 && K > (N)) || ((1) < 0 && K < (N))) goto end_for_K_610;
    printf("%g ", (double)(A_arr[(int)(K)]));
    K += (1); goto for_loop_K_610; end_for_K_610:;
    /* BASIC: 650 PRINT:PRINT:RETURN */
line_650:;
    printf("\n");
    printf("\n");
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 700 REM *** SUBROUTINE TO PRINT THE RULES */
line_700:;
    // REM *** SUBROUTINE TO PRINT THE RULES
    /* BASIC: 710 PRINT:PRINT "THIS IS THE GAME OF 'REVERSE'.  TO WIN, ALL YOU HAVE" */
line_710:;
    printf("\n");
    printf("%s", "THIS IS THE GAME OF 'REVERSE'.  TO WIN, ALL YOU HAVE"); printf("\n");
    /* BASIC: 720 PRINT "TO DO IS ARRANGE A LIST OF NUMBERS (1 THROUGH";N;")" */
line_720:;
    printf("%s", "TO DO IS ARRANGE A LIST OF NUMBERS (1 THROUGH"); printf("%g ", (double)(N)); printf("%s", ")"); printf("\n");
    /* BASIC: 730 PRINT "IN NUMERICAL ORDER FROM LEFT TO RIGHT.  TO MOVE, YOU" */
line_730:;
    printf("%s", "IN NUMERICAL ORDER FROM LEFT TO RIGHT.  TO MOVE, YOU"); printf("\n");
    /* BASIC: 740 PRINT "TELL ME HOW MANY NUMBERS (COUNTING FROM THE LEFT) TO" */
line_740:;
    printf("%s", "TELL ME HOW MANY NUMBERS (COUNTING FROM THE LEFT) TO"); printf("\n");
    /* BASIC: 750 PRINT "REVERSE.  FOR EXAMPLE, IF THE CURRENT LIST IS:" */
line_750:;
    printf("%s", "REVERSE.  FOR EXAMPLE, IF THE CURRENT LIST IS:"); printf("\n");
    /* BASIC: 760 PRINT:PRINT "2 3 4 5 1 6 7 8 9" */
line_760:;
    printf("\n");
    printf("%s", "2 3 4 5 1 6 7 8 9"); printf("\n");
    /* BASIC: 770 PRINT:PRINT "AND YOU REVERSE 4, THE RESULT WILL BE:" */
line_770:;
    printf("\n");
    printf("%s", "AND YOU REVERSE 4, THE RESULT WILL BE:"); printf("\n");
    /* BASIC: 780 PRINT:PRINT "5 4 3 2 1 6 7 8 9" */
line_780:;
    printf("\n");
    printf("%s", "5 4 3 2 1 6 7 8 9"); printf("\n");
    /* BASIC: 790 PRINT:PRINT "NOW IF YOU REVERSE 5, YOU WIN!" */
line_790:;
    printf("\n");
    printf("%s", "NOW IF YOU REVERSE 5, YOU WIN!"); printf("\n");
    /* BASIC: 800 PRINT:PRINT "1 2 3 4 5 6 7 8 9":PRINT */
line_800:;
    printf("\n");
    printf("%s", "1 2 3 4 5 6 7 8 9"); printf("\n");
    printf("\n");
    /* BASIC: 810 PRINT "NO DOUBT YOU WILL LIKE THIS GAME, BUT" */
line_810:;
    printf("%s", "NO DOUBT YOU WILL LIKE THIS GAME, BUT"); printf("\n");
    /* BASIC: 820 PRINT "IF YOU WANT TO QUIT, REVERSE 0 (ZERO).":PRINT: RETURN */
line_820:;
    printf("%s", "IF YOU WANT TO QUIT, REVERSE 0 (ZERO)."); printf("\n");
    printf("\n");
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 999 END */
line_999:;
    exit(0);

    return 0;
}
