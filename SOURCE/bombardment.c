/*
 * Transpiled from bombardment.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double USE, GOING, BETTER, US, NOW, P, GAME, GO, PLATOONS, NEW, HA, OUTPOSTS, RAT, RE, THEY, JERSEY, THE, ON, LEFT, A, D, BUT, WHEN, IT, WON, PICKED, T, DESTROYS, MORRISTOWN, ANY, TEAR, BOMBARDMENT, TRANSISTO, OFF, WAS, TURN, LUCK, TIME, WHAT, THREE, NUMBERS, WANT, ALL, YOUR, I, FAST, BODIES, MISSLES, POST, Y, ME, OUTPOST, H, IS, K, OF, ONLY, Z, LL, OBJECT, SAME, ITS, S, WILL, CREATIVE, MY, COMPUTER, YOU, MATRIX, X, ENEMY, MISSED, WITH, ONE, WINNER, RECUP, G, LAST, GOOD, AVAILABLE, PLACED, GOT, MAY, ARE, BE, BATTLEFIELD, C, LONG, WISH, TELL, FIRE, CAN, TWO, FOUR, COMPUTING, GET, HIT, POSITIONS, E, WHERE, DIRTY, MISSLE, AT, L, PLACE, DOES, F, DOWN, RA, DEAD, DO, FIRST, R, WHO, N, HAVE, PLATOON, Q, CHECK, SENT;
    double M[1000] = {0}; /* Static array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 10 PRINT TAB(33);"BOMBARDMENT" */
line_10:
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "BOMBARDMENT"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 100 PRINT "YOU ARE ON A BATTLEFIELD WITH 4 PLATOONS AND YOU" */
line_100:
    printf("%s", "YOU ARE ON A BATTLEFIELD WITH 4 PLATOONS AND YOU"); printf("\n");
    /* BASIC: 110 PRINT "HAVE 25 OUTPOSTS AVAILABLE WHERE THEY MAY BE PLACED." */
line_110:
    printf("%s", "HAVE 25 OUTPOSTS AVAILABLE WHERE THEY MAY BE PLACED."); printf("\n");
    /* BASIC: 120 PRINT "YOU CAN ONLY PLACE ONE PLATOON AT ANY ONE OUTPOST." */
line_120:
    printf("%s", "YOU CAN ONLY PLACE ONE PLATOON AT ANY ONE OUTPOST."); printf("\n");
    /* BASIC: 130 PRINT "THE COMPUTER DOES THE SAME WITH ITS FOUR PLATOONS." */
line_130:
    printf("%s", "THE COMPUTER DOES THE SAME WITH ITS FOUR PLATOONS."); printf("\n");
    /* BASIC: 135 PRINT */
line_135:
    printf("\n");
    /* BASIC: 140 PRINT "THE OBJECT OF THE GAME IS TO FIRE MISSLES AT THE" */
line_140:
    printf("%s", "THE OBJECT OF THE GAME IS TO FIRE MISSLES AT THE"); printf("\n");
    /* BASIC: 150 PRINT "OUTPOSTS OF THE COMPUTER.  IT WILL DO THE SAME TO YOU." */
line_150:
    printf("%s", "OUTPOSTS OF THE COMPUTER.  IT WILL DO THE SAME TO YOU."); printf("\n");
    /* BASIC: 160 PRINT "THE ONE WHO DESTROYS ALL FOUR OF THE ENEMY'S PLATOONS" */
line_160:
    printf("%s", "THE ONE WHO DESTROYS ALL FOUR OF THE ENEMY'S PLATOONS"); printf("\n");
    /* BASIC: 170 PRINT "FIRST IS THE WINNER." */
line_170:
    printf("%s", "FIRST IS THE WINNER."); printf("\n");
    /* BASIC: 180 PRINT */
line_180:
    printf("\n");
    /* BASIC: 190 PRINT "GOOD LUCK... AND TELL US WHERE YOU WANT THE BODIES SENT!" */
line_190:
    printf("%s", "GOOD LUCK... AND TELL US WHERE YOU WANT THE BODIES SENT!"); printf("\n");
    /* BASIC: 200 PRINT */
line_200:
    printf("\n");
    /* BASIC: 210 PRINT "TEAR OFF MATRIX AND USE IT TO CHECK OFF THE NUMBERS." */
line_210:
    printf("%s", "TEAR OFF MATRIX AND USE IT TO CHECK OFF THE NUMBERS."); printf("\n");
    /* BASIC: 220 FOR R=1 TO 5: PRINT: NEXT R */
line_220:
    R = 1; for_loop_R: if ((1 >= 0 && R > 5) || (1 < 0 && R < 5)) goto end_for_R;
    printf("\n");
    R += 1; goto for_loop_R; end_for_R:;
    /* BASIC: 260 DIM M(100) */
line_260:
    /* DIM M(100) (handled statically) */
    /* BASIC: 270 FOR R=1 TO 5 */
line_270:
    R = 1; for_loop_R: if ((1 >= 0 && R > 5) || (1 < 0 && R < 5)) goto end_for_R;
    /* BASIC: 280 I=(R-1)*5+1 */
line_280:
    I = (R-1)*5+1;
    /* BASIC: 290 PRINT I,I+1,I+2,I+3,I+4 */
line_290:
    printf("%g ", (double)(I)); printf("\t"); printf("%g ", (double)(I+1)); printf("\t"); printf("%g ", (double)(I+2)); printf("\t"); printf("%g ", (double)(I+3)); printf("\t"); printf("%g ", (double)(I+4)); printf("\n");
    /* BASIC: 300 NEXT R */
line_300:
    R += 1; goto for_loop_R; end_for_R:;
    /* BASIC: 350 FOR R=1 TO 10: PRINT: NEXT R */
line_350:
    R = 1; for_loop_R: if ((1 >= 0 && R > 10) || (1 < 0 && R < 10)) goto end_for_R;
    printf("\n");
    R += 1; goto for_loop_R; end_for_R:;
    /* BASIC: 380 C=INT(RND(1)*25)+1 */
line_380:
    C = floor(((double)rand() / (double)RAND_MAX)*25)+1;
    /* BASIC: 390 D=INT(RND(1)*25)+1 */
line_390:
    D = floor(((double)rand() / (double)RAND_MAX)*25)+1;
    /* BASIC: 400 E=INT(RND(1)*25)+1 */
line_400:
    E = floor(((double)rand() / (double)RAND_MAX)*25)+1;
    /* BASIC: 410 F=INT(RND(1)*25)+1 */
line_410:
    F = floor(((double)rand() / (double)RAND_MAX)*25)+1;
    /* BASIC: 420 IF C=D THEN 390 */
line_420:
    if (C==D) goto line_390;
    /* BASIC: 430 IF C=E THEN 400 */
line_430:
    if (C==E) goto line_400;
    /* BASIC: 440 IF C=F THEN 410 */
line_440:
    if (C==F) goto line_410;
    /* BASIC: 450 IF D=E THEN 400 */
line_450:
    if (D==E) goto line_400;
    /* BASIC: 460 IF D=F THEN 410 */
line_460:
    if (D==F) goto line_410;
    /* BASIC: 470 IF E=F THEN 410 */
line_470:
    if (E==F) goto line_410;
    /* BASIC: 480 PRINT "WHAT ARE YOUR FOUR POSITIONS"; */
line_480:
    printf("%s", "WHAT ARE YOUR FOUR POSITIONS");
    /* BASIC: 490 INPUT G,H,K,L */
line_490:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &G,H,K,L);
    /* BASIC: 495 PRINT */
line_495:
    printf("\n");
    /* BASIC: 500 PRINT "WHERE DO YOU WISH TO FIRE YOUR MISSLE"; */
line_500:
    printf("%s", "WHERE DO YOU WISH TO FIRE YOUR MISSLE");
    /* BASIC: 510 INPUT Y */
line_510:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &Y);
    /* BASIC: 520 IF Y=C THEN 710 */
line_520:
    if (Y==C) goto line_710;
    /* BASIC: 530 IF Y=D THEN 710 */
line_530:
    if (Y==D) goto line_710;
    /* BASIC: 540 IF Y=E THEN 710 */
line_540:
    if (Y==E) goto line_710;
    /* BASIC: 550 IF Y=F THEN 710 */
line_550:
    if (Y==F) goto line_710;
    /* BASIC: 560 GOTO 630 */
line_560:
    goto line_630;
    /* BASIC: 570 M=INT(RND(1)*25)+1 */
line_570:
    M = floor(((double)rand() / (double)RAND_MAX)*25)+1;
    /* BASIC: 575 GOTO 1160 */
line_575:
    goto line_1160;
    /* BASIC: 580 IF X=G THEN 920 */
line_580:
    if (X==G) goto line_920;
    /* BASIC: 590 IF X=H THEN 920 */
line_590:
    if (X==H) goto line_920;
    /* BASIC: 600 IF X=L THEN 920 */
line_600:
    if (X==L) goto line_920;
    /* BASIC: 610 IF X=K THEN 920 */
line_610:
    if (X==K) goto line_920;
    /* BASIC: 620 GOTO 670 */
line_620:
    goto line_670;
    /* BASIC: 630 PRINT "HA, HA YOU MISSED. MY TURN NOW:" */
line_630:
    printf("%s", "HA, HA YOU MISSED. MY TURN NOW:"); printf("\n");
    /* BASIC: 640 PRINT: PRINT: GOTO 570 */
line_640:
    printf("\n");
    printf("\n");
    goto line_570;
    /* BASIC: 670 PRINT "I MISSED YOU, YOU DIRTY RAT. I PICKED";M". YOUR TURN:" */
line_670:
    printf("%s", "I MISSED YOU, YOU DIRTY RAT. I PICKED"); printf("%g ", (double)(M". YOUR TURN:")); printf("\n");
    /* BASIC: 680 PRINT: PRINT: GOTO 500 */
line_680:
    printf("\n");
    printf("\n");
    goto line_500;
    /* BASIC: 710 Q=Q+1 */
line_710:
    Q = Q+1;
    /* BASIC: 720 IF Q=4 THEN 890 */
line_720:
    if (Q==4) goto line_890;
    /* BASIC: 730 PRINT "YOU GOT ONE OF MY OUTPOSTS!" */
line_730:
    printf("%s", "YOU GOT ONE OF MY OUTPOSTS!"); printf("\n");
    /* BASIC: 740 IF Q=1 THEN 770 */
line_740:
    if (Q==1) goto line_770;
    /* BASIC: 750 IF Q=2 THEN 810 */
line_750:
    if (Q==2) goto line_810;
    /* BASIC: 760 IF Q=3 THEN 850 */
line_760:
    if (Q==3) goto line_850;
    /* BASIC: 770 PRINT "ONE DOWN, THREE TO GO." */
line_770:
    printf("%s", "ONE DOWN, THREE TO GO."); printf("\n");
    /* BASIC: 780 PRINT: PRINT: GOTO 570 */
line_780:
    printf("\n");
    printf("\n");
    goto line_570;
    /* BASIC: 810 PRINT "TWO DOWN, TWO TO GO." */
line_810:
    printf("%s", "TWO DOWN, TWO TO GO."); printf("\n");
    /* BASIC: 820 PRINT: PRINT: GOTO 570 */
line_820:
    printf("\n");
    printf("\n");
    goto line_570;
    /* BASIC: 850 PRINT "THREE DOWN, ONE TO GO." */
line_850:
    printf("%s", "THREE DOWN, ONE TO GO."); printf("\n");
    /* BASIC: 860 PRINT: PRINT: GOTO 570 */
line_860:
    printf("\n");
    printf("\n");
    goto line_570;
    /* BASIC: 890 PRINT "YOU GOT ME, I'M GOING FAST. BUT I'LL GET YOU WHEN" */
line_890:
    printf("%s", "YOU GOT ME, I'M GOING FAST. BUT I'LL GET YOU WHEN"); printf("\n");
    /* BASIC: 900 PRINT "MY TRANSISTO&S RECUP%RA*E!" */
line_900:
    printf("%s", "MY TRANSISTO&S RECUP%RA*E!"); printf("\n");
    /* BASIC: 910 GOTO 1235 */
line_910:
    goto line_1235;
    /* BASIC: 920 Z=Z+1 */
line_920:
    Z = Z+1;
    /* BASIC: 930 IF Z=4 THEN 1110 */
line_930:
    if (Z==4) goto line_1110;
    /* BASIC: 940 PRINT "I GOT YOU. IT WON'T BE LONG NOW. POST";X;"WAS HIT." */
line_940:
    printf("%s", "I GOT YOU. IT WON'T BE LONG NOW. POST"); printf("%g ", (double)(X)); printf("%s", "WAS HIT."); printf("\n");
    /* BASIC: 950 IF Z=1 THEN 990 */
line_950:
    if (Z==1) goto line_990;
    /* BASIC: 960 IF Z=2 THEN 1030 */
line_960:
    if (Z==2) goto line_1030;
    /* BASIC: 970 IF Z=3 THEN 1070 */
line_970:
    if (Z==3) goto line_1070;
    /* BASIC: 990 PRINT "YOU HAVE ONLY THREE OUTPOSTS LEFT." */
line_990:
    printf("%s", "YOU HAVE ONLY THREE OUTPOSTS LEFT."); printf("\n");
    /* BASIC: 1000 PRINT: PRINT: GOTO 500 */
line_1000:
    printf("\n");
    printf("\n");
    goto line_500;
    /* BASIC: 1030 PRINT "YOU HAVE ONLY TWO OUTPOSTS LEFT." */
line_1030:
    printf("%s", "YOU HAVE ONLY TWO OUTPOSTS LEFT."); printf("\n");
    /* BASIC: 1040 PRINT: PRINT: GOTO 500 */
line_1040:
    printf("\n");
    printf("\n");
    goto line_500;
    /* BASIC: 1070 PRINT "YOU HAVE ONLY ONE OUTPOST LEFT." */
line_1070:
    printf("%s", "YOU HAVE ONLY ONE OUTPOST LEFT."); printf("\n");
    /* BASIC: 1080 PRINT: PRINT: GOTO 500 */
line_1080:
    printf("\n");
    printf("\n");
    goto line_500;
    /* BASIC: 1110 PRINT "YOU'RE DEAD. YOUR LAST OUTPOST WAS AT";X;". HA, HA, HA." */
line_1110:
    printf("%s", "YOU'RE DEAD. YOUR LAST OUTPOST WAS AT"); printf("%g ", (double)(X)); printf("%s", ". HA, HA, HA."); printf("\n");
    /* BASIC: 1120 PRINT "BETTER LUCK NEXT TIME." */
line_1120:
    printf("%s", "BETTER LUCK NEXT TIME."); printf("\n");
    /* BASIC: 1150 GOTO 1235 */
line_1150:
    goto line_1235;
    /* BASIC: 1160 P=P+1 */
line_1160:
    P = P+1;
    /* BASIC: 1170 N=P-1 */
line_1170:
    N = P-1;
    /* BASIC: 1180 FOR T=1 TO N */
line_1180:
    T = 1; for_loop_T: if ((1 >= 0 && T > N) || (1 < 0 && T < N)) goto end_for_T;
    /* BASIC: 1190 IF M=M(T) THEN 570 */
line_1190:
    if (M==M(T)) goto line_570;
    /* BASIC: 1200 NEXT T */
line_1200:
    T += 1; goto for_loop_T; end_for_T:;
    /* BASIC: 1210 X=M */
line_1210:
    X = M;
    /* BASIC: 1220 M(P)=M */
line_1220:
    M(P) = M;
    /* BASIC: 1230 GOTO 580 */
line_1230:
    goto line_580;
    /* BASIC: 1235 END */
line_1235:
    exit(0);

    return 0;
}
