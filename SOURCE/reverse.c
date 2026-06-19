/*
 * Transpiled from reverse.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double SKILL, THROUGH, RESULT, SHALL, FUN, FROM, BE, NOW, MORRISTOWN, ME, GAME, GO, MOVES, HOW, IS, J, NEW, MOVE, CURRENT, K, TELL, NUMERICAL, OF, Z, CAN, ORDER, WILL, COMPUTING, CREATIVE, JERSEY, THE, MOST, WIN, LIST, COUNTING, YOU, TRY, LEFT, HERE, MANY, ARRANGE, HOPE, AT, EXAMPLE, NO, DOUBT, QUIT, RIGHT, BUT, WON, IT, REVERSE, OOPS, NUMBERS, WE, WANT, DO, AGAIN, R, YES, LIKE, O, T, TOO, N, ALL, HAVE, HAD, I, THIS, RULES, IN, ZERO;
    double A[1000] = {0}; /* Static array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 10 PRINT TAB(32);"REVERSE" */
line_10:
    { int _t; for(_t=0; _t<32; _t++) printf(" "); } printf("%s", "REVERSE"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 100 PRINT "REVERSE -- A GAME OF SKILL": PRINT */
line_100:
    printf("%s", "REVERSE -- A GAME OF SKILL"); printf("\n");
    printf("\n");
    /* BASIC: 130 DIM A(20) */
line_130:
    /* DIM A(20) (handled statically) */
    /* BASIC: 140 REM *** N=NUMBER OF NUMBERS */
line_140:
    // REM *** N=NUMBER OF NUMBERS
    /* BASIC: 150 N=9 */
line_150:
    N = 9;
    /* BASIC: 160 PRINT "DO YOU WANT THE RULES"; */
line_160:
    printf("%s", "DO YOU WANT THE RULES");
    /* BASIC: 170 INPUT A$ */
line_170:
    printf("? "); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    /* BASIC: 180 IF A$="NO" THEN 210 */
line_180:
    if (A$=="NO") goto line_210;
    /* BASIC: 190 GOSUB 710 */
line_190:
    /* TODO: GOSUB 710 */
    /* BASIC: 200 REM *** MAKE A RANDOM LIST A(1) TO A(N) */
line_200:
    // REM *** MAKE A RANDOM LIST A(1) TO A(N)
    /* BASIC: 210 A(1)=INT((N-1)*RND(1)+2) */
line_210:
    A(1) = floor((N-1)*((double)rand() / (double)RAND_MAX)+2);
    /* BASIC: 220 FOR K=2 TO N */
line_220:
    K = 2; for_loop_K: if ((1 >= 0 && K > N) || (1 < 0 && K < N)) goto end_for_K;
    /* BASIC: 230 A(K)=INT(N*RND(1)+1) */
line_230:
    A(K) = floor(N*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 240 FOR J=1 TO K-1 */
line_240:
    J = 1; for_loop_J: if ((1 >= 0 && J > K-1) || (1 < 0 && J < K-1)) goto end_for_J;
    /* BASIC: 250 IF A(K)=A(J) THEN 230 */
line_250:
    if (A(K)==A(J)) goto line_230;
    /* BASIC: 260 NEXT J:NEXT K */
line_260:
    J += 1; goto for_loop_J; end_for_J:;
    K += 1; goto for_loop_K; end_for_K:;
    /* BASIC: 280 REM *** PRINT ORIGINAL LIST AND START GAME */
line_280:
    // REM *** PRINT ORIGINAL LIST AND START GAME
    /* BASIC: 290 PRINT: PRINT "HERE WE GO ... THE LIST IS:" */
line_290:
    printf("\n");
    printf("%s", "HERE WE GO ... THE LIST IS:"); printf("\n");
    /* BASIC: 310 T=0 */
line_310:
    T = 0;
    /* BASIC: 320 GOSUB 610 */
line_320:
    /* TODO: GOSUB 610 */
    /* BASIC: 330 PRINT "HOW MANY SHALL I REVERSE"; */
line_330:
    printf("%s", "HOW MANY SHALL I REVERSE");
    /* BASIC: 340 INPUT R */
line_340:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &R);
    /* BASIC: 350 IF R=0 THEN 520 */
line_350:
    if (R==0) goto line_520;
    /* BASIC: 360 IF R<=N THEN 390 */
line_360:
    if (R<==N) goto line_390;
    /* BASIC: 370 PRINT "OOPS! TOO MANY! I CAN REVERSE AT MOST";N:GOTO 330 */
line_370:
    printf("%s", "OOPS! TOO MANY! I CAN REVERSE AT MOST"); printf("%g ", (double)(N)); printf("\n");
    goto line_330;
    /* BASIC: 390 T=T+1 */
line_390:
    T = T+1;
    /* BASIC: 400 REM *** REVERSE R NUMBERS AND PRINT NEW LIST */
line_400:
    // REM *** REVERSE R NUMBERS AND PRINT NEW LIST
    /* BASIC: 410 FOR K=1 TO INT(R/2) */
line_410:
    K = 1; for_loop_K: if ((1 >= 0 && K > floor(R/2)) || (1 < 0 && K < floor(R/2))) goto end_for_K;
    /* BASIC: 420 Z=A(K) */
line_420:
    Z = A(K);
    /* BASIC: 430 A(K)=A(R-K+1) */
line_430:
    A(K) = A(R-K+1);
    /* BASIC: 440 A(R-K+1)=Z */
line_440:
    A(R-K+1) = Z;
    /* BASIC: 450 NEXT K */
line_450:
    K += 1; goto for_loop_K; end_for_K:;
    /* BASIC: 460 GOSUB 610 */
line_460:
    /* TODO: GOSUB 610 */
    /* BASIC: 470 REM *** CHECK FOR A WIN */
line_470:
    // REM *** CHECK FOR A WIN
    /* BASIC: 480 FOR K=1 TO N */
line_480:
    K = 1; for_loop_K: if ((1 >= 0 && K > N) || (1 < 0 && K < N)) goto end_for_K;
    /* BASIC: 490 IF A(K)<>K THEN 330 */
line_490:
    if (A(K)!=K) goto line_330;
    /* BASIC: 500 NEXT K */
line_500:
    K += 1; goto for_loop_K; end_for_K:;
    /* BASIC: 510 PRINT "YOU WON IT IN";T;"MOVES!!!":PRINT */
line_510:
    printf("%s", "YOU WON IT IN"); printf("%g ", (double)(T)); printf("%s", "MOVES!!!"); printf("\n");
    printf("\n");
    /* BASIC: 520 PRINT */
line_520:
    printf("\n");
    /* BASIC: 530 PRINT "TRY AGAIN (YES OR NO)"; */
line_530:
    printf("%s", "TRY AGAIN (YES OR NO)");
    /* BASIC: 540 INPUT A$ */
line_540:
    printf("? "); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    /* BASIC: 550 IF A$="YES" THEN 210 */
line_550:
    if (A$=="YES") goto line_210;
    /* BASIC: 560 PRINT: PRINT "O.K. HOPE YOU HAD FUN!!":GOTO 999 */
line_560:
    printf("\n");
    printf("%s", "O.K. HOPE YOU HAD FUN!!"); printf("\n");
    goto line_999;
    /* BASIC: 600 REM *** SUBROUTINE TO PRINT LIST */
line_600:
    // REM *** SUBROUTINE TO PRINT LIST
    /* BASIC: 610 PRINT:FOR K=1 TO N:PRINT A(K);:NEXT K */
line_610:
    printf("\n");
    K = 1; for_loop_K: if ((1 >= 0 && K > N) || (1 < 0 && K < N)) goto end_for_K;
    printf("%g ", (double)(A(K)));
    K += 1; goto for_loop_K; end_for_K:;
    /* BASIC: 650 PRINT:PRINT:RETURN */
line_650:
    printf("\n");
    printf("\n");
    /* TODO: RETURN */
    /* BASIC: 700 REM *** SUBROUTINE TO PRINT THE RULES */
line_700:
    // REM *** SUBROUTINE TO PRINT THE RULES
    /* BASIC: 710 PRINT:PRINT "THIS IS THE GAME OF 'REVERSE'.  TO WIN, ALL YOU HAVE" */
line_710:
    printf("\n");
    printf("%s", "THIS IS THE GAME OF 'REVERSE'.  TO WIN, ALL YOU HAVE"); printf("\n");
    /* BASIC: 720 PRINT "TO DO IS ARRANGE A LIST OF NUMBERS (1 THROUGH";N;")" */
line_720:
    printf("%s", "TO DO IS ARRANGE A LIST OF NUMBERS (1 THROUGH"); printf("%g ", (double)(N)); printf("%s", ")"); printf("\n");
    /* BASIC: 730 PRINT "IN NUMERICAL ORDER FROM LEFT TO RIGHT.  TO MOVE, YOU" */
line_730:
    printf("%s", "IN NUMERICAL ORDER FROM LEFT TO RIGHT.  TO MOVE, YOU"); printf("\n");
    /* BASIC: 740 PRINT "TELL ME HOW MANY NUMBERS (COUNTING FROM THE LEFT) TO" */
line_740:
    printf("%s", "TELL ME HOW MANY NUMBERS (COUNTING FROM THE LEFT) TO"); printf("\n");
    /* BASIC: 750 PRINT "REVERSE.  FOR EXAMPLE, IF THE CURRENT LIST IS:" */
line_750:
    printf("%s", "REVERSE.  FOR EXAMPLE, IF THE CURRENT LIST IS:"); printf("\n");
    /* BASIC: 760 PRINT:PRINT "2 3 4 5 1 6 7 8 9" */
line_760:
    printf("\n");
    printf("%s", "2 3 4 5 1 6 7 8 9"); printf("\n");
    /* BASIC: 770 PRINT:PRINT "AND YOU REVERSE 4, THE RESULT WILL BE:" */
line_770:
    printf("\n");
    printf("%s", "AND YOU REVERSE 4, THE RESULT WILL BE:"); printf("\n");
    /* BASIC: 780 PRINT:PRINT "5 4 3 2 1 6 7 8 9" */
line_780:
    printf("\n");
    printf("%s", "5 4 3 2 1 6 7 8 9"); printf("\n");
    /* BASIC: 790 PRINT:PRINT "NOW IF YOU REVERSE 5, YOU WIN!" */
line_790:
    printf("\n");
    printf("%s", "NOW IF YOU REVERSE 5, YOU WIN!"); printf("\n");
    /* BASIC: 800 PRINT:PRINT "1 2 3 4 5 6 7 8 9":PRINT */
line_800:
    printf("\n");
    printf("%s", "1 2 3 4 5 6 7 8 9"); printf("\n");
    printf("\n");
    /* BASIC: 810 PRINT "NO DOUBT YOU WILL LIKE THIS GAME, BUT" */
line_810:
    printf("%s", "NO DOUBT YOU WILL LIKE THIS GAME, BUT"); printf("\n");
    /* BASIC: 820 PRINT "IF YOU WANT TO QUIT, REVERSE 0 (ZERO).":PRINT: RETURN */
line_820:
    printf("%s", "IF YOU WANT TO QUIT, REVERSE 0 (ZERO)."); printf("\n");
    printf("\n");
    /* TODO: RETURN */
    /* BASIC: 999 END */
line_999:
    exit(0);

    return 0;
}
