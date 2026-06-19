/*
 * Transpiled from digits.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double USE, BETTER, READ, ALWAYS, THAN, GAME, CHR, J, DIGITS, NEW, TYPE, INSTRUCTIONS, JERSEY, THE, WRITE, A, HOPE, RIGHT, BUT, IT, WRONG, BEAT, T, IN, NUMBER, RESULT, BY, MORRISTOWN, THIRTY, TAKE, DATA, Z1, WAS, GUESSED, LUCK, TIMES, THEM, Z2, TIME, TRY, GUESS, LOOK, ARRANGE, THREE, U, NUMBERS, WANT, RANDOM, LET, S1, PIECE, YOUR, I, THANKS, PURE, MORE, ME, W, ELSE, IS, TIE, CONGRATULATIONS, K, OF, Z, ONLY, PAPER, S, WILL, CREATIVE, WIN, MY, EACH, PLEASE, YOU, X, NO, G, LESS, BE, GUESSING, SEE, EXACTLY, B, C, TEN, LINES, COMPUTING, SGN, E, AT, OUGHT, L, DOWN, DO, FIRST, THAT, AGAIN, YES, ASK, N, THIS, Q;
    double M[1000] = {0}; /* Static array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 10 PRINT TAB(33);"DIGITS" */
line_10:
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "DIGITS"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 210 PRINT "THIS IS A GAME OF GUESSING." */
line_210:
    printf("%s", "THIS IS A GAME OF GUESSING."); printf("\n");
    /* BASIC: 220 PRINT "FOR INSTRUCTIONS, TYPE '1', ELSE TYPE '0'"; */
line_220:
    printf("%s", "FOR INSTRUCTIONS, TYPE '1', ELSE TYPE '0'");
    /* BASIC: 230 INPUT E */
line_230:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &E);
    /* BASIC: 240 IF E=0 THEN 360 */
line_240:
    if (E==0) goto line_360;
    /* BASIC: 250 PRINT */
line_250:
    printf("\n");
    /* BASIC: 260 PRINT "PLEASE TAKE A PIECE OF PAPER AND WRITE DOWN" */
line_260:
    printf("%s", "PLEASE TAKE A PIECE OF PAPER AND WRITE DOWN"); printf("\n");
    /* BASIC: 270 PRINT "THE DIGITS '0', '1', OR '2' THIRTY TIMES AT RANDOM." */
line_270:
    printf("%s", "THE DIGITS '0', '1', OR '2' THIRTY TIMES AT RANDOM."); printf("\n");
    /* BASIC: 280 PRINT "ARRANGE THEM IN THREE LINES OF TEN DIGITS EACH." */
line_280:
    printf("%s", "ARRANGE THEM IN THREE LINES OF TEN DIGITS EACH."); printf("\n");
    /* BASIC: 290 PRINT "I WILL ASK FOR THEN TEN AT A TIME." */
line_290:
    printf("%s", "I WILL ASK FOR THEN TEN AT A TIME."); printf("\n");
    /* BASIC: 300 PRINT "I WILL ALWAYS GUESS THEM FIRST AND THEN LOOK AT YOUR" */
line_300:
    printf("%s", "I WILL ALWAYS GUESS THEM FIRST AND THEN LOOK AT YOUR"); printf("\n");
    /* BASIC: 310 PRINT "NEXT NUMBER TO SEE IF I WAS RIGHT. BY PURE LUCK," */
line_310:
    printf("%s", "NEXT NUMBER TO SEE IF I WAS RIGHT. BY PURE LUCK,"); printf("\n");
    /* BASIC: 320 PRINT "I OUGHT TO BE RIGHT TEN TIMES. BUT I HOPE TO DO BETTER" */
line_320:
    printf("%s", "I OUGHT TO BE RIGHT TEN TIMES. BUT I HOPE TO DO BETTER"); printf("\n");
    /* BASIC: 330 PRINT "THAN THAT *****" */
line_330:
    printf("%s", "THAN THAT *****"); printf("\n");
    /* BASIC: 340 PRINT:PRINT */
line_340:
    printf("\n");
    printf("\n");
    /* BASIC: 360 READ A,B,C */
line_360:
    /* UNTRANSLATED: READ A,B,C */
    /* BASIC: 370 DATA 0,1,3 */
line_370:
    /* UNTRANSLATED: DATA 0,1,3 */
    /* BASIC: 380 DIM M(26,2),K(2,2),L(8,2) */
line_380:
    /* DIM M(26,2),K(2,2),L(8,2) (handled statically) */
    /* BASIC: 400 FOR I=0 TO 26: FOR J=0 TO 2: M(I,J)=1: NEXT J: NEXT I */
line_400:
    I = 0; for_loop_I: if ((1 >= 0 && I > 26) || (1 < 0 && I < 26)) goto end_for_I;
    J = 0; for_loop_J: if ((1 >= 0 && J > 2) || (1 < 0 && J < 2)) goto end_for_J;
    M(I,J) = 1;
    J += 1; goto for_loop_J; end_for_J:;
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 410 FOR I=0 TO 2: FOR J=0 TO 2: K(I,J)=9: NEXT J: NEXT I */
line_410:
    I = 0; for_loop_I: if ((1 >= 0 && I > 2) || (1 < 0 && I < 2)) goto end_for_I;
    J = 0; for_loop_J: if ((1 >= 0 && J > 2) || (1 < 0 && J < 2)) goto end_for_J;
    K(I,J) = 9;
    J += 1; goto for_loop_J; end_for_J:;
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 420 FOR I=0 TO 8: FOR J=0 TO 2: L(I,J)=3: NEXT J: NEXT I */
line_420:
    I = 0; for_loop_I: if ((1 >= 0 && I > 8) || (1 < 0 && I < 8)) goto end_for_I;
    J = 0; for_loop_J: if ((1 >= 0 && J > 2) || (1 < 0 && J < 2)) goto end_for_J;
    L(I,J) = 3;
    J += 1; goto for_loop_J; end_for_J:;
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 450 L(0,0)=2: L(4,1)=2: L(8,2)=2 */
line_450:
    L(0,0) = 2;
    L(4,1) = 2;
    L(8,2) = 2;
    /* BASIC: 480 Z=26: Z1=8: Z2=2 */
line_480:
    Z = 26;
    Z1 = 8;
    Z2 = 2;
    /* BASIC: 510 X=0 */
line_510:
    X = 0;
    /* BASIC: 520 FOR T=1 TO 3 */
line_520:
    T = 1; for_loop_T: if ((1 >= 0 && T > 3) || (1 < 0 && T < 3)) goto end_for_T;
    /* BASIC: 530 PRINT */
line_530:
    printf("\n");
    /* BASIC: 540 PRINT "TEN NUMBERS, PLEASE"; */
line_540:
    printf("%s", "TEN NUMBERS, PLEASE");
    /* BASIC: 550 INPUT N(1),N(2),N(3),N(4),N(5),N(6),N(7),N(8),N(9),N(10) */
line_550:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &N(1),N(2),N(3),N(4),N(5),N(6),N(7),N(8),N(9),N(10));
    /* BASIC: 560 FOR I=1 TO 10 */
line_560:
    I = 1; for_loop_I: if ((1 >= 0 && I > 10) || (1 < 0 && I < 10)) goto end_for_I;
    /* BASIC: 570 W=N(I)-1 */
line_570:
    W = N(I)-1;
    /* BASIC: 580 IF W=SGN(W) THEN 620 */
line_580:
    if (W==SGN(W)) goto line_620;
    /* BASIC: 590 PRINT "ONLY USE THE DIGITS '0', '1', OR '2'." */
line_590:
    printf("%s", "ONLY USE THE DIGITS '0', '1', OR '2'."); printf("\n");
    /* BASIC: 600 PRINT "LET'S TRY AGAIN.":GOTO 530 */
line_600:
    printf("%s", "LET'S TRY AGAIN."); printf("\n");
    goto line_530;
    /* BASIC: 620 NEXT I */
line_620:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 630 PRINT: PRINT "MY GUESS","YOUR NO.","RESULT","NO. RIGHT":PRINT */
line_630:
    printf("\n");
    printf("%s", "MY GUESS"); printf("\t"); printf("%s", "YOUR NO."); printf("\t"); printf("%s", "RESULT"); printf("\t"); printf("%s", "NO. RIGHT"); printf("\n");
    printf("\n");
    /* BASIC: 660 FOR U=1 TO 10 */
line_660:
    U = 1; for_loop_U: if ((1 >= 0 && U > 10) || (1 < 0 && U < 10)) goto end_for_U;
    /* BASIC: 670 N=N(U): S=0 */
line_670:
    N = N(U);
    S = 0;
    /* BASIC: 690 FOR J=0 TO 2 */
line_690:
    J = 0; for_loop_J: if ((1 >= 0 && J > 2) || (1 < 0 && J < 2)) goto end_for_J;
    /* BASIC: 700 S1=A*K(Z2,J)+B*L(Z1,J)+C*M(Z,J) */
line_700:
    S1 = A*K(Z2,J)+B*L(Z1,J)+C*M(Z,J);
    /* BASIC: 710 IF S>S1 THEN 760 */
line_710:
    if (S>S1) goto line_760;
    /* BASIC: 720 IF S<S1 THEN 740 */
line_720:
    if (S<S1) goto line_740;
    /* BASIC: 730 IF RND(1)<.5 THEN 760 */
line_730:
    if (((double)rand() / (double)RAND_MAX)<.5) goto line_760;
    /* BASIC: 740 S=S1: G=J */
line_740:
    S = S1;
    G = J;
    /* BASIC: 760 NEXT J */
line_760:
    J += 1; goto for_loop_J; end_for_J:;
    /* BASIC: 770 PRINT "  ";G,"   ";N(U), */
line_770:
    printf("%s", "  "); printf("%g ", (double)(G)); printf("\t"); printf("%s", "   "); printf("%g ", (double)(N(U))); printf("\t");
    /* BASIC: 780 IF G=N(U) THEN 810 */
line_780:
    if (G==N(U)) goto line_810;
    /* BASIC: 790 PRINT " WRONG",X */
line_790:
    printf("%s", " WRONG"); printf("\t"); printf("%g ", (double)(X)); printf("\n");
    /* BASIC: 800 GOTO 880 */
line_800:
    goto line_880;
    /* BASIC: 810 X=X+1 */
line_810:
    X = X+1;
    /* BASIC: 820 PRINT " RIGHT",X */
line_820:
    printf("%s", " RIGHT"); printf("\t"); printf("%g ", (double)(X)); printf("\n");
    /* BASIC: 830 M(Z,N)=M(Z,N)+1 */
line_830:
    M(Z,N) = M(Z,N)+1;
    /* BASIC: 840 L(Z1,N)=L(Z1,N)+1 */
line_840:
    L(Z1,N) = L(Z1,N)+1;
    /* BASIC: 850 K(Z2,N)=K(Z2,N)+1 */
line_850:
    K(Z2,N) = K(Z2,N)+1;
    /* BASIC: 860 Z=Z-INT(Z/9)*9 */
line_860:
    Z = Z-floor(Z/9)*9;
    /* BASIC: 870 Z=3*Z+N(U) */
line_870:
    Z = 3*Z+N(U);
    /* BASIC: 880 Z1=Z-INT(Z/9)*9 */
line_880:
    Z1 = Z-floor(Z/9)*9;
    /* BASIC: 890 Z2=N(U) */
line_890:
    Z2 = N(U);
    /* BASIC: 900 NEXT U */
line_900:
    U += 1; goto for_loop_U; end_for_U:;
    /* BASIC: 910 NEXT T */
line_910:
    T += 1; goto for_loop_T; end_for_T:;
    /* BASIC: 920 PRINT */
line_920:
    printf("\n");
    /* BASIC: 930 IF X>10 THEN 980 */
line_930:
    if (X>10) goto line_980;
    /* BASIC: 940 IF X<10 THEN 1010 */
line_940:
    if (X<10) goto line_1010;
    /* BASIC: 950 PRINT "I GUESSED EXACTLY 1/3 OF YOUR NUMBERS." */
line_950:
    printf("%s", "I GUESSED EXACTLY 1/3 OF YOUR NUMBERS."); printf("\n");
    /* BASIC: 960 PRINT "IT'S A TIE GAME." */
line_960:
    printf("%s", "IT'S A TIE GAME."); printf("\n");
    /* BASIC: 970 GOTO 1030 */
line_970:
    goto line_1030;
    /* BASIC: 980 PRINT "I GUESSED MORE THAN 1/3 OF YOUR NUMBERS." */
line_980:
    printf("%s", "I GUESSED MORE THAN 1/3 OF YOUR NUMBERS."); printf("\n");
    /* BASIC: 990 PRINT "I WIN.": FOR Q=1 TO 10: PRINT CHR$(7);: NEXT Q */
line_990:
    printf("%s", "I WIN."); printf("\n");
    Q = 1; for_loop_Q: if ((1 >= 0 && Q > 10) || (1 < 0 && Q < 10)) goto end_for_Q;
    printf("%g ", (double)(CHR$(7)));
    Q += 1; goto for_loop_Q; end_for_Q:;
    /* BASIC: 1000 GOTO 1030 */
line_1000:
    goto line_1030;
    /* BASIC: 1010 PRINT "I GUESSED LESS THAN 1/3 OF YOUR NUMBERS." */
line_1010:
    printf("%s", "I GUESSED LESS THAN 1/3 OF YOUR NUMBERS."); printf("\n");
    /* BASIC: 1020 PRINT "YOU BEAT ME.  CONGRATULATIONS *****" */
line_1020:
    printf("%s", "YOU BEAT ME.  CONGRATULATIONS *****"); printf("\n");
    /* BASIC: 1030 PRINT */
line_1030:
    printf("\n");
    /* BASIC: 1040 PRINT "DO YOU WANT TO TRY AGAIN (1 FOR YES, 0 FOR NO)"; */
line_1040:
    printf("%s", "DO YOU WANT TO TRY AGAIN (1 FOR YES, 0 FOR NO)");
    /* BASIC: 1060 INPUT X */
line_1060:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &X);
    /* BASIC: 1070 IF X=1 THEN 400 */
line_1070:
    if (X==1) goto line_400;
    /* BASIC: 1080 PRINT:PRINT "THANKS FOR THE GAME." */
line_1080:
    printf("\n");
    printf("%s", "THANKS FOR THE GAME."); printf("\n");
    /* BASIC: 1090 END */
line_1090:
    exit(0);

    return 0;
}
