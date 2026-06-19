/*
 * Transpiled from war.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double CHOOSE, HAS, OUT, FUN, ENDS, Q, READ, BY, PLAYING, MORRISTOWN, P, GAME, DIRECTIONS, B, H, IS, N2, TIE, J, NEW, DATA, C, K, SUIT, HIGHER, OF, B1, SCORE, FINISHED, S, WAS, COMPUTING, CREATIVE, JERSEY, THE, SPADE, N1, WIN, COMPUTER, EACH, WAR, PLEASE, YOU, M1, NUMERICALLY, WINS, A, GIVES, CARDS, AS, CHANGE, L, NO, D, WHEN, IT, V, A1, WE, GIVEN, DO, WANT, RUN, YES, FINAL, CARD, CONTINUE, LET, M2, HAVE, PACK, I, THIS, THANKS;
    char A_str[1000][256] = {0}; /* Static string array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 10 PRINT TAB(33);"WAR" */
line_10:
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "WAR"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT: PRINT: PRINT */
line_30:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 100 PRINT "THIS IS THE CARD GAME OF WAR.  EACH CARD IS GIVEN BY SUIT-#" */
line_100:
    printf("%s", "THIS IS THE CARD GAME OF WAR.  EACH CARD IS GIVEN BY SUIT-#"); printf("\n");
    /* BASIC: 110 PRINT "AS S-7 FOR SPADE 7.  "; */
line_110:
    printf("%s", "AS S-7 FOR SPADE 7.  ");
    /* BASIC: 120 PRINT "DO YOU WANT DIRECTIONS"; */
line_120:
    printf("%s", "DO YOU WANT DIRECTIONS");
    /* BASIC: 130 INPUT B$ */
line_130:
    printf("? "); fgets(B_str, sizeof(B_str), stdin); B_str[strcspn(B_str, "\n")] = 0;
    /* BASIC: 140 IF B$="NO" THEN 210 */
line_140:
    if (B$=="NO") goto line_210;
    /* BASIC: 150 IF B$="YES" THEN 180 */
line_150:
    if (B$=="YES") goto line_180;
    /* BASIC: 160 PRINT "YES OR NO, PLEASE.  "; */
line_160:
    printf("%s", "YES OR NO, PLEASE.  ");
    /* BASIC: 170 GOTO 120 */
line_170:
    goto line_120;
    /* BASIC: 180 PRINT "THE COMPUTER GIVES YOU AND IT A 'CARD'.  THE HIGHER CARD" */
line_180:
    printf("%s", "THE COMPUTER GIVES YOU AND IT A 'CARD'.  THE HIGHER CARD"); printf("\n");
    /* BASIC: 190 PRINT "(NUMERICALLY) WINS.  THE GAME ENDS WHEN YOU CHOOSE NOT TO" */
line_190:
    printf("%s", "(NUMERICALLY) WINS.  THE GAME ENDS WHEN YOU CHOOSE NOT TO"); printf("\n");
    /* BASIC: 200 PRINT "CONTINUE OR WHEN YOU HAVE FINISHED THE PACK." */
line_200:
    printf("%s", "CONTINUE OR WHEN YOU HAVE FINISHED THE PACK."); printf("\n");
    /* BASIC: 210 PRINT */
line_210:
    printf("\n");
    /* BASIC: 220 PRINT */
line_220:
    printf("\n");
    /* BASIC: 230 DIM A$(52),L(54) */
line_230:
    /* DIM A$(52),L(54) (handled statically) */
    /* BASIC: 240 FOR I=1 TO 52 */
line_240:
    I = 1; for_loop_I: if ((1 >= 0 && I > 52) || (1 < 0 && I < 52)) goto end_for_I;
    /* BASIC: 250 READ A$(I) */
line_250:
    /* UNTRANSLATED: READ A$(I) */
    /* BASIC: 260 NEXT I */
line_260:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 270 REM */
line_270:
    // REM
    /* BASIC: 280 FOR J=1 TO 52 */
line_280:
    J = 1; for_loop_J: if ((1 >= 0 && J > 52) || (1 < 0 && J < 52)) goto end_for_J;
    /* BASIC: 290 LET L(J)=INT(52*RND(1))+1 */
line_290:
    /* UNTRANSLATED: LET L(J)=INT(52*RND(1))+1 */
    /* BASIC: 295 IF J=1 THEN 350 */
line_295:
    if (J==1) goto line_350;
    /* BASIC: 300 FOR K=1 TO J-1 */
line_300:
    K = 1; for_loop_K: if ((1 >= 0 && K > J-1) || (1 < 0 && K < J-1)) goto end_for_K;
    /* BASIC: 310 IF L(K)<>L(J) THEN 340 */
line_310:
    if (L(K)!=L(J)) goto line_340;
    /* BASIC: 320 REM */
line_320:
    // REM
    /* BASIC: 330 GOTO 290 */
line_330:
    goto line_290;
    /* BASIC: 340 NEXT K */
line_340:
    K += 1; goto for_loop_K; end_for_K:;
    /* BASIC: 350 NEXT J */
line_350:
    J += 1; goto for_loop_J; end_for_J:;
    /* BASIC: 360 P=P+1 */
line_360:
    P = P+1;
    /* BASIC: 370 M1=L(P) */
line_370:
    M1 = L(P);
    /* BASIC: 380 P=P+1 */
line_380:
    P = P+1;
    /* BASIC: 390 M2=L(P) */
line_390:
    M2 = L(P);
    /* BASIC: 400 PRINT */
line_400:
    printf("\n");
    /* BASIC: 420 PRINT "YOU: ";A$(M1),"COMPUTER: ";A$(M2) */
line_420:
    printf("%s", "YOU: "); printf("%g ", (double)(A$(M1))); printf("\t"); printf("%s", "COMPUTER: "); printf("%g ", (double)(A$(M2))); printf("\n");
    /* BASIC: 430 N1=INT((M1-.5)/4) */
line_430:
    N1 = floor((M1-.5)/4);
    /* BASIC: 440 N2=INT((M2-.5)/4) */
line_440:
    N2 = floor((M2-.5)/4);
    /* BASIC: 450 IF N1>=N2 THEN 490 */
line_450:
    if (N1>==N2) goto line_490;
    /* BASIC: 460 A1=A1+1 */
line_460:
    A1 = A1+1;
    /* BASIC: 470 PRINT "THE COMPUTER WINS!!! YOU HAVE";B1;"AND THE COMPUTER HAS";A1 */
line_470:
    printf("%s", "THE COMPUTER WINS!!! YOU HAVE"); printf("%g ", (double)(B1)); printf("%s", "AND THE COMPUTER HAS"); printf("%g ", (double)(A1)); printf("\n");
    /* BASIC: 480 GOTO 540 */
line_480:
    goto line_540;
    /* BASIC: 490 IF N1=N2 THEN 530 */
line_490:
    if (N1==N2) goto line_530;
    /* BASIC: 500 B1=B1+1 */
line_500:
    B1 = B1+1;
    /* BASIC: 510 PRINT "YOU WIN. YOU HAVE";B1;"AND THE COMPUTER HAS";A1 */
line_510:
    printf("%s", "YOU WIN. YOU HAVE"); printf("%g ", (double)(B1)); printf("%s", "AND THE COMPUTER HAS"); printf("%g ", (double)(A1)); printf("\n");
    /* BASIC: 520 GOTO 540 */
line_520:
    goto line_540;
    /* BASIC: 530 PRINT "TIE.  NO SCORE CHANGE." */
line_530:
    printf("%s", "TIE.  NO SCORE CHANGE."); printf("\n");
    /* BASIC: 540 IF L(P+1)=0 THEN 610 */
line_540:
    if (L(P+1)==0) goto line_610;
    /* BASIC: 550 PRINT "DO YOU WANT TO CONTINUE"; */
line_550:
    printf("%s", "DO YOU WANT TO CONTINUE");
    /* BASIC: 560 INPUT V$ */
line_560:
    printf("? "); fgets(V_str, sizeof(V_str), stdin); V_str[strcspn(V_str, "\n")] = 0;
    /* BASIC: 570 IF V$="YES" THEN 360 */
line_570:
    if (V$=="YES") goto line_360;
    /* BASIC: 580 IF V$="NO" THEN 650 */
line_580:
    if (V$=="NO") goto line_650;
    /* BASIC: 590 PRINT "YES OR NO, PLEASE.  "; */
line_590:
    printf("%s", "YES OR NO, PLEASE.  ");
    /* BASIC: 600 GOTO 540 */
line_600:
    goto line_540;
    /* BASIC: 610 PRINT */
line_610:
    printf("\n");
    /* BASIC: 620 PRINT */
line_620:
    printf("\n");
    /* BASIC: 630 PRINT "WE HAVE RUN OUT OF CARDS.  FINAL SCORE:  YOU: ";B1; */
line_630:
    printf("%s", "WE HAVE RUN OUT OF CARDS.  FINAL SCORE:  YOU: "); printf("%g ", (double)(B1));
    /* BASIC: 640 PRINT "  THE COMPUTER: ";A1:PRINT */
line_640:
    printf("%s", "  THE COMPUTER: "); printf("%g ", (double)(A1)); printf("\n");
    printf("\n");
    /* BASIC: 650 PRINT "THANKS FOR PLAYING.  IT WAS FUN." */
line_650:
    printf("%s", "THANKS FOR PLAYING.  IT WAS FUN."); printf("\n");
    /* BASIC: 655 PRINT */
line_655:
    printf("\n");
    /* BASIC: 660 DATA "S-2","H-2","C-2","D-2","S-3","H-3","C-3","D-3" */
line_660:
    /* UNTRANSLATED: DATA "S-2","H-2","C-2","D-2","S-3","H-3","C-3","D-3" */
    /* BASIC: 670 DATA "S-4","H-4","C-4","D-4","S-5","H-5","C-5","D-5" */
line_670:
    /* UNTRANSLATED: DATA "S-4","H-4","C-4","D-4","S-5","H-5","C-5","D-5" */
    /* BASIC: 680 DATA "S-6","H-6","C-6","D-6","S-7","H-7","C-7","D-7" */
line_680:
    /* UNTRANSLATED: DATA "S-6","H-6","C-6","D-6","S-7","H-7","C-7","D-7" */
    /* BASIC: 690 DATA "S-8","H-8","C-8","D-8","S-9","H-9","C-9","D-9" */
line_690:
    /* UNTRANSLATED: DATA "S-8","H-8","C-8","D-8","S-9","H-9","C-9","D-9" */
    /* BASIC: 700 DATA "S-10","H-10","C-10","D-10","S-J","H-J","C-J","D-J" */
line_700:
    /* UNTRANSLATED: DATA "S-10","H-10","C-10","D-10","S-J","H-J","C-J","D-J" */
    /* BASIC: 710 DATA "S-Q","H-Q","C-Q","D-Q","S-K","H-K","C-K","D-K" */
line_710:
    /* UNTRANSLATED: DATA "S-Q","H-Q","C-Q","D-Q","S-K","H-K","C-K","D-K" */
    /* BASIC: 720 DATA "S-A","H-A","C-A","D-A" */
line_720:
    /* UNTRANSLATED: DATA "S-A","H-A","C-A","D-A" */
    /* BASIC: 999 END */
line_999:
    exit(0);

    return 0;
}
