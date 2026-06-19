/*
 * Transpiled from blackjack.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double DEAL, ABS, GAME, L1, J, NEW, TYPE, INSTRUCTIONS, JERSEY, THE, AB, ON, LEFT, A, INSURANCE, PLAYS, D, LOSES, CASE, CARD, BETS, T, WERE, DEALT, HAD, WANTS, IN, L2, NUMBER, DEF, HAND, RECEIVED, MORRISTOWN, MID, ANY, PLAYER, TURN, DOUBLING, PLAY, Q1, DRAWS, C3, C1, RESPONSES, SECOND, WANT, RESHUFFLING, ALL, I, Q2, PERMITTED, HE, RESPONSE, HAS, H1, Y, UNLESS, INITIAL, FNA, H, IS, CONCEALED, K, OF, Z, S, ORDER, PUSHES, C2, WILL, INDICATING, CREATIVE, EACH, PLEASE, HIS, BUSTED, YOU, X, WINS, AA, SHOULD, AS, NO, ANOTHER, AFTER, RECEIVES, ASKED, MAY, I1, DEALER, BE, B, TYPED, C, AC, SPLITTING, TOTAL, WHICH, COMPUTING, SGN, HIT, STANDING, SPLIT, FURTHER, BLACK, MANY, CARDS, COLLECT, PLAYERS, DOWN, X1, HOLE, JACK, DO, FIRST, THAT, AGAIN, D1, N, EITHER, BLACKJACK, THIS, Q, ALLOWED;
    double P[1000] = {0}; /* Static array fallback */
    double R[1000] = {0}; /* Static array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 2 PRINT TAB(31);"BLACK JACK" */
line_2:
    { int _t; for(_t=0; _t<31; _t++) printf(" "); } printf("%s", "BLACK JACK"); printf("\n");
    /* BASIC: 4 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 6 PRINT:PRINT:PRINT */
line_6:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 10 DEF FNA(Q)=Q+11*(Q>=22) */
line_10:
    /* UNTRANSLATED: DEF FNA(Q)=Q+11*(Q>=22) */
    /* BASIC: 20 DIM P(15,12),Q(15),C(52),D(52),T(8),S(7),B(15) */
line_20:
    /* DIM P(15,12),Q(15),C(52),D(52),T(8),S(7),B(15) (handled statically) */
    /* BASIC: 30 DIM R(15) */
line_30:
    /* DIM R(15) (handled statically) */
    /* BASIC: 40 REM--P(I,J) IS THE JTH CARD IN HAND I, Q(I) IS TOTAL OF HAND I */
line_40:
    // REM--P(I,J) IS THE JTH CARD IN HAND I, Q(I) IS TOTAL OF HAND I
    /* BASIC: 50 REM--C IS THE DECK BEING DEALT FROM, D IS THE DISCARD PILE, */
line_50:
    // REM--C IS THE DECK BEING DEALT FROM, D IS THE DISCARD PILE,
    /* BASIC: 60 REM--T(I) IS THE TOTAL FOR PLAYER I, S(I) IS THE TOTAL THIS HAND FOR */
line_60:
    // REM--T(I) IS THE TOTAL FOR PLAYER I, S(I) IS THE TOTAL THIS HAND FOR
    /* BASIC: 70 REM--PLAYER I, B(I) IS TH BET FOR HAND I */
line_70:
    // REM--PLAYER I, B(I) IS TH BET FOR HAND I
    /* BASIC: 80 REM--R(I) IS THE LENGTH OF P(I,*) */
line_80:
    // REM--R(I) IS THE LENGTH OF P(I,*)
    /* BASIC: 90 GOTO 1500 */
line_90:
    goto line_1500;
    /* BASIC: 100 REM--SUBROUTINE TO GET A CARD.  RESULT IS PUT IN X. */
line_100:
    // REM--SUBROUTINE TO GET A CARD.  RESULT IS PUT IN X.
    /* BASIC: 110 IF C<51 THEN 230 */
line_110:
    if (C<51) goto line_230;
    /* BASIC: 120 PRINT "RESHUFFLING" */
line_120:
    printf("%s", "RESHUFFLING"); printf("\n");
    /* BASIC: 130 FOR D=D TO 1 STEP -1 */
line_130:
    D = D; for_loop_D: if ((-1 >= 0 && D > 1) || (-1 < 0 && D < 1)) goto end_for_D;
    /* BASIC: 140 C=C-1 */
line_140:
    C = C-1;
    /* BASIC: 150 C(C)=D(D) */
line_150:
    C(C) = D(D);
    /* BASIC: 160 NEXT D */
line_160:
    D += -1; goto for_loop_D; end_for_D:;
    /* BASIC: 170 FOR C1=52 TO C STEP -1 */
line_170:
    C1 = 52; for_loop_C1: if ((-1 >= 0 && C1 > C) || (-1 < 0 && C1 < C)) goto end_for_C1;
    /* BASIC: 180 C2=INT(RND(1)*(C1-C+1))+C */
line_180:
    C2 = floor(((double)rand() / (double)RAND_MAX)*(C1-C+1))+C;
    /* BASIC: 190 C3=C(C2) */
line_190:
    C3 = C(C2);
    /* BASIC: 200 C(C2)=C(C1) */
line_200:
    C(C2) = C(C1);
    /* BASIC: 210 C(C1)=C3 */
line_210:
    C(C1) = C3;
    /* BASIC: 220 NEXT C1 */
line_220:
    C1 += -1; goto for_loop_C1; end_for_C1:;
    /* BASIC: 230 X=C(C) */
line_230:
    X = C(C);
    /* BASIC: 240 C=C+1 */
line_240:
    C = C+1;
    /* BASIC: 250 RETURN */
line_250:
    /* TODO: RETURN */
    /* BASIC: 300 REM--SUBROUTINE TO EVALUATE HAND I.  TOTAL IS PUT INTO */
line_300:
    // REM--SUBROUTINE TO EVALUATE HAND I.  TOTAL IS PUT INTO
    /* BASIC: 310 REM--Q(I). TOTALS HAVE THE FOLLOWING MEANING: */
line_310:
    // REM--Q(I). TOTALS HAVE THE FOLLOWING MEANING
    /* BASIC: 320 REM--  2-10...HARD 2-10 */
line_320:
    // REM--  2-10...HARD 2-10
    /* BASIC: 330 REM-- 11-21...SOFT 11-21 */
line_330:
    // REM-- 11-21...SOFT 11-21
    /* BASIC: 340 REM-- 22-32...HARD 11-21 */
line_340:
    // REM-- 22-32...HARD 11-21
    /* BASIC: 350 REM--  33+....BUSTED */
line_350:
    // REM--  33+....BUSTED
    /* BASIC: 360 Q=0 */
line_360:
    Q = 0;
    /* BASIC: 370 FOR Q2=1 TO R(I) */
line_370:
    Q2 = 1; for_loop_Q2: if ((1 >= 0 && Q2 > R(I)) || (1 < 0 && Q2 < R(I))) goto end_for_Q2;
    /* BASIC: 380 X=P(I,Q2) */
line_380:
    X = P(I,Q2);
    /* BASIC: 390 GOSUB 500 */
line_390:
    /* TODO: GOSUB 500 */
    /* BASIC: 400 NEXT Q2 */
line_400:
    Q2 += 1; goto for_loop_Q2; end_for_Q2:;
    /* BASIC: 410 Q(I)=Q */
line_410:
    Q(I) = Q;
    /* BASIC: 420 RETURN */
line_420:
    /* TODO: RETURN */
    /* BASIC: 500 REM--SUBROUTINE TO ADD CARD X TO TOTAL Q. */
line_500:
    // REM--SUBROUTINE TO ADD CARD X TO TOTAL Q.
    /* BASIC: 510 X1=X: IF X1>10 THEN X1=10:  REM  SAME AS X1=10 MIN X */
line_510:
    X1 = X;
    if (X1>10) { X1 = 10; }
    // REM  SAME AS X1=10 MIN X
    /* BASIC: 520 Q1=Q+X1 */
line_520:
    Q1 = Q+X1;
    /* BASIC: 530 IF Q>=11 THEN 590 */
line_530:
    if (Q>==11) goto line_590;
    /* BASIC: 540 IF X>1 THEN 570 */
line_540:
    if (X>1) goto line_570;
    /* BASIC: 550 Q=Q+11 */
line_550:
    Q = Q+11;
    /* BASIC: 560 RETURN */
line_560:
    /* TODO: RETURN */
    /* BASIC: 570 Q=Q1-11*(Q1>=11) */
line_570:
    Q = Q1-11*(Q1>==11);
    /* BASIC: 580 RETURN */
line_580:
    /* TODO: RETURN */
    /* BASIC: 590 Q=Q1-(Q<=21 AND Q1>21) */
line_590:
    Q = Q1-(Q<==21 && Q1>21);
    /* BASIC: 600 IF Q<33 THEN 620 */
line_600:
    if (Q<33) goto line_620;
    /* BASIC: 610 Q=-1 */
line_610:
    Q = -1;
    /* BASIC: 620 RETURN */
line_620:
    /* TODO: RETURN */
    /* BASIC: 700 REM--CARD PRINTING SUBROUTINE */
line_700:
    // REM--CARD PRINTING SUBROUTINE
    /* BASIC: 710 REM  D$ DEFINED ELSEWHERE */
line_710:
    // REM  D$ DEFINED ELSEWHERE
    /* BASIC: 720 PRINT MID$(D$,3*X-2,3); */
line_720:
    printf("%s", MID$(D_str); printf("\t"); printf("%g ", (double)(3*X-2)); printf("\t"); printf("%g ", (double)(3)));
    /* BASIC: 730 PRINT "  "; */
line_730:
    printf("%s", "  ");
    /* BASIC: 740 RETURN */
line_740:
    /* TODO: RETURN */
    /* BASIC: 750 REM--ALTERNATIVE PRINTING ROUTINE */
line_750:
    // REM--ALTERNATIVE PRINTING ROUTINE
    /* BASIC: 760 PRINT " ";MID$(D$,3*X-1,2); */
line_760:
    printf("%s", " "); printf("%s", MID$(D_str); printf("\t"); printf("%g ", (double)(3*X-1)); printf("\t"); printf("%g ", (double)(2)));
    /* BASIC: 770 PRINT "   "; */
line_770:
    printf("%s", "   ");
    /* BASIC: 780 RETURN */
line_780:
    /* TODO: RETURN */
    /* BASIC: 800 REM--SUBROUTINE TO PLAY OUT A HAND. */
line_800:
    // REM--SUBROUTINE TO PLAY OUT A HAND.
    /* BASIC: 810 REM--NO SPLITTING OR BLACKJACKS ALLOWED */
line_810:
    // REM--NO SPLITTING OR BLACKJACKS ALLOWED
    /* BASIC: 820 H1=5 */
line_820:
    H1 = 5;
    /* BASIC: 830 GOSUB 1410 */
line_830:
    /* TODO: GOSUB 1410 */
    /* BASIC: 840 H1=3 */
line_840:
    H1 = 3;
    /* BASIC: 850 ON H GOTO 950,930 */
line_850:
    /* UNTRANSLATED: ON H GOTO 950,930 */
    /* BASIC: 860 GOSUB 100 */
line_860:
    /* TODO: GOSUB 100 */
    /* BASIC: 870 B(I)=B(I)*2 */
line_870:
    B(I) = B(I)*2;
    /* BASIC: 880 PRINT "RECEIVED A"; */
line_880:
    printf("%s", "RECEIVED A");
    /* BASIC: 890 GOSUB 700 */
line_890:
    /* TODO: GOSUB 700 */
    /* BASIC: 900 GOSUB 1100 */
line_900:
    /* TODO: GOSUB 1100 */
    /* BASIC: 910 IF Q>0 THEN GOSUB 1300 */
line_910:
    if (Q>0) { /* TODO: GOSUB 1300 */ }
    /* BASIC: 920 RETURN */
line_920:
    /* TODO: RETURN */
    /* BASIC: 930 GOSUB 1320 */
line_930:
    /* TODO: GOSUB 1320 */
    /* BASIC: 940 RETURN */
line_940:
    /* TODO: RETURN */
    /* BASIC: 950 GOSUB 100 */
line_950:
    /* TODO: GOSUB 100 */
    /* BASIC: 960 PRINT "RECEIVED A"; */
line_960:
    printf("%s", "RECEIVED A");
    /* BASIC: 970 GOSUB 700 */
line_970:
    /* TODO: GOSUB 700 */
    /* BASIC: 980 GOSUB 1100 */
line_980:
    /* TODO: GOSUB 1100 */
    /* BASIC: 990 IF Q<0 THEN 940 */
line_990:
    if (Q<0) goto line_940;
    /* BASIC: 1000 PRINT "HIT"; */
line_1000:
    printf("%s", "HIT");
    /* BASIC: 1010 GOTO 830 */
line_1010:
    goto line_830;
    /* BASIC: 1100 REM--SUBROUTINE TO ADD A CARD TO ROW I */
line_1100:
    // REM--SUBROUTINE TO ADD A CARD TO ROW I
    /* BASIC: 1110 R(I)=R(I)+1 */
line_1110:
    R(I) = R(I)+1;
    /* BASIC: 1120 P(I,R(I))=X */
line_1120:
    P(I,R(I)) = X;
    /* BASIC: 1130 Q=Q(I) */
line_1130:
    Q = Q(I);
    /* BASIC: 1140 GOSUB 500 */
line_1140:
    /* TODO: GOSUB 500 */
    /* BASIC: 1150 Q(I)=Q */
line_1150:
    Q(I) = Q;
    /* BASIC: 1160 IF Q>=0 THEN 1190 */
line_1160:
    if (Q>==0) goto line_1190;
    /* BASIC: 1170 PRINT "...BUSTED" */
line_1170:
    printf("%s", "...BUSTED"); printf("\n");
    /* BASIC: 1180 GOSUB 1200 */
line_1180:
    /* TODO: GOSUB 1200 */
    /* BASIC: 1190 RETURN */
line_1190:
    /* TODO: RETURN */
    /* BASIC: 1200 REM--SUBROUTINE TO DISCARD ROW I */
line_1200:
    // REM--SUBROUTINE TO DISCARD ROW I
    /* BASIC: 1210 IF R(I)<>0 THEN 1230 */
line_1210:
    if (R(I)!=0) goto line_1230;
    /* BASIC: 1220 RETURN */
line_1220:
    /* TODO: RETURN */
    /* BASIC: 1230 D=D+1 */
line_1230:
    D = D+1;
    /* BASIC: 1240 D(D)=P(I,R(I)) */
line_1240:
    D(D) = P(I,R(I));
    /* BASIC: 1250 R(I)=R(I)-1 */
line_1250:
    R(I) = R(I)-1;
    /* BASIC: 1260 GOTO 1210 */
line_1260:
    goto line_1210;
    /* BASIC: 1300 REM--PRINTS TOTAL OF HAND I */
line_1300:
    // REM--PRINTS TOTAL OF HAND I
    /* BASIC: 1310 PRINT */
line_1310:
    printf("\n");
    /* BASIC: 1320 AA=Q(I): GOSUB 3400 */
line_1320:
    AA = Q(I);
    /* TODO: GOSUB 3400 */
    /* BASIC: 1325 PRINT "TOTAL IS";AA */
line_1325:
    printf("%s", "TOTAL IS"); printf("%g ", (double)(AA)); printf("\n");
    /* BASIC: 1330 RETURN */
line_1330:
    /* TODO: RETURN */
    /* BASIC: 1400 REM--SUBROUTINE TO READ REPLY */
line_1400:
    // REM--SUBROUTINE TO READ REPLY
    /* BASIC: 1410 REM  I$ DEFINED ELSEWHERE */
line_1410:
    // REM  I$ DEFINED ELSEWHERE
    /* BASIC: 1420 INPUT H$: H$=LEFT$(H$,1) */
line_1420:
    printf("? "); fgets(H_str, sizeof(H_str), stdin); H_str[strcspn(H_str, "\n")] = 0;
    strncpy(H_str, "LEFT$(H$,1)", sizeof(H_str)); /* String assign approx */
    /* BASIC: 1430 FOR H=1 TO H1 STEP 2 */
line_1430:
    H = 1; for_loop_H: if ((2 >= 0 && H > H1) || (2 < 0 && H < H1)) goto end_for_H;
    /* BASIC: 1440 IF H$=MID$(I$,H,1) THEN 1480 */
line_1440:
    if (H$==MID$(I$,H,1)) goto line_1480;
    /* BASIC: 1450 NEXT H */
line_1450:
    H += 2; goto for_loop_H; end_for_H:;
    /* BASIC: 1460 PRINT "TYPE ";MID$(I$,1,H1-1);" OR ";MID$(I$,H1,2);" PLEASE"; */
line_1460:
    printf("%s", "TYPE "); printf("%s", MID$(I_str); printf("\t"); printf("%g ", (double)(1)); printf("\t"); printf("%g ", (double)(H1-1))); printf("%s", " OR "); printf("%s", MID$(I_str); printf("\t"); printf("%g ", (double)(H1)); printf("\t"); printf("%g ", (double)(2))); printf("%s", " PLEASE");
    /* BASIC: 1470 GOTO 1420 */
line_1470:
    goto line_1420;
    /* BASIC: 1480 H=(H+1)/2 */
line_1480:
    H = (H+1)/2;
    /* BASIC: 1490 RETURN */
line_1490:
    /* TODO: RETURN */
    /* BASIC: 1500 REM--PROGRAM STARTS HERE */
line_1500:
    // REM--PROGRAM STARTS HERE
    /* BASIC: 1510 REM--INITIALIZE */
line_1510:
    // REM--INITIALIZE
    /* BASIC: 1520 D$="N A  2  3  4  5  6  7N 8  9 10  J  Q  K" */
line_1520:
    strncpy(D_str, ""N A  2  3  4  5  6  7N 8  9 10  J  Q  K"", sizeof(D_str)); /* String assign approx */
    /* BASIC: 1530 I$="H,S,D,/," */
line_1530:
    strncpy(I_str, ""H,S,D,/,"", sizeof(I_str)); /* String assign approx */
    /* BASIC: 1540 FOR I=1 TO 13 */
line_1540:
    I = 1; for_loop_I: if ((1 >= 0 && I > 13) || (1 < 0 && I < 13)) goto end_for_I;
    /* BASIC: 1550 FOR J=4*I-3 TO 4*I */
line_1550:
    J = 4*I-3; for_loop_J: if ((1 >= 0 && J > 4*I) || (1 < 0 && J < 4*I)) goto end_for_J;
    /* BASIC: 1560 D(J)=I */
line_1560:
    D(J) = I;
    /* BASIC: 1570 NEXT J */
line_1570:
    J += 1; goto for_loop_J; end_for_J:;
    /* BASIC: 1580 NEXT I */
line_1580:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 1590 D=52 */
line_1590:
    D = 52;
    /* BASIC: 1600 C=53 */
line_1600:
    C = 53;
    /* BASIC: 1610 PRINT "DO YOU WANT INSTRUCTIONS"; */
line_1610:
    printf("%s", "DO YOU WANT INSTRUCTIONS");
    /* BASIC: 1620 INPUT H$ */
line_1620:
    printf("? "); fgets(H_str, sizeof(H_str), stdin); H_str[strcspn(H_str, "\n")] = 0;
    /* BASIC: 1630 IF LEFT$(H$,1)="N" OR LEFT$(H$,1)="n" THEN 1760 */
line_1630:
    if (LEFT$(H$,1)=="N" || LEFT$(H$,1)=="n") goto line_1760;
    /* BASIC: 1640 PRINT "THIS IS THE GAME OF 21. AS MANY AS 7 PLAYERS MAY PLAY THE" */
line_1640:
    printf("%s", "THIS IS THE GAME OF 21. AS MANY AS 7 PLAYERS MAY PLAY THE"); printf("\n");
    /* BASIC: 1650 PRINT "GAME. ON EACH DEAL, BETS WILL BE ASKED FOR, AND THE" */
line_1650:
    printf("%s", "GAME. ON EACH DEAL, BETS WILL BE ASKED FOR, AND THE"); printf("\n");
    /* BASIC: 1660 PRINT "PLAYERS' BETS SHOULD BE TYPED IN. THE CARDS WILL THEN BE" */
line_1660:
    printf("%s", "PLAYERS' BETS SHOULD BE TYPED IN. THE CARDS WILL THEN BE"); printf("\n");
    /* BASIC: 1670 PRINT "DEALT, AND EACH PLAYER IN TURN PLAYS HIS HAND. THE" */
line_1670:
    printf("%s", "DEALT, AND EACH PLAYER IN TURN PLAYS HIS HAND. THE"); printf("\n");
    /* BASIC: 1680 PRINT "FIRST RESPONSE SHOULD BE EITHER 'D', INDICATING THAT THE" */
line_1680:
    printf("%s", "FIRST RESPONSE SHOULD BE EITHER 'D', INDICATING THAT THE"); printf("\n");
    /* BASIC: 1690 PRINT "PLAYER IS DOUBLING DOWN, 'S', INDICATING THAT HE IS" */
line_1690:
    printf("%s", "PLAYER IS DOUBLING DOWN, 'S', INDICATING THAT HE IS"); printf("\n");
    /* BASIC: 1700 PRINT "STANDING, 'H', INDICATING HE WANTS ANOTHER CARD, OR '/'," */
line_1700:
    printf("%s", "STANDING, 'H', INDICATING HE WANTS ANOTHER CARD, OR '/',"); printf("\n");
    /* BASIC: 1710 PRINT "INDICATING THAT HE WANTS TO SPLIT HIS CARDS. AFTER THE" */
line_1710:
    printf("%s", "INDICATING THAT HE WANTS TO SPLIT HIS CARDS. AFTER THE"); printf("\n");
    /* BASIC: 1720 PRINT "INITIAL RESPONSE, ALL FURTHER RESPONSES SHOULD BE 'S' OR" */
line_1720:
    printf("%s", "INITIAL RESPONSE, ALL FURTHER RESPONSES SHOULD BE 'S' OR"); printf("\n");
    /* BASIC: 1730 PRINT "'H', UNLESS THE CARDS WERE SPLIT, IN WHICH CASE DOUBLING" */
line_1730:
    printf("%s", "'H', UNLESS THE CARDS WERE SPLIT, IN WHICH CASE DOUBLING"); printf("\n");
    /* BASIC: 1740 PRINT "DOWN IS AGAIN PERMITTED. IN ORDER TO COLLECT FOR" */
line_1740:
    printf("%s", "DOWN IS AGAIN PERMITTED. IN ORDER TO COLLECT FOR"); printf("\n");
    /* BASIC: 1750 PRINT "BLACKJACK, THE INITIAL RESPONSE SHOULD BE 'S'." */
line_1750:
    printf("%s", "BLACKJACK, THE INITIAL RESPONSE SHOULD BE 'S'."); printf("\n");
    /* BASIC: 1760 PRINT "NUMBER OF PLAYERS"; */
line_1760:
    printf("%s", "NUMBER OF PLAYERS");
    /* BASIC: 1770 INPUT N */
line_1770:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &N);
    /* BASIC: 1775 PRINT */
line_1775:
    printf("\n");
    /* BASIC: 1780 IF N<1 OR N>7 OR N>INT(N) THEN 1760 */
line_1780:
    if (N<1 || N>7 || N>floor(N)) goto line_1760;
    /* BASIC: 1790 FOR I=1 TO 8: T(I)=0: NEXT I */
line_1790:
    I = 1; for_loop_I: if ((1 >= 0 && I > 8) || (1 < 0 && I < 8)) goto end_for_I;
    T(I) = 0;
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 1800 D1=N+1 */
line_1800:
    D1 = N+1;
    /* BASIC: 1810 IF 2*D1+C>=52 THEN GOSUB 120 */
line_1810:
    if (2*D1+C>==52) { /* TODO: GOSUB 120 */ }
    /* BASIC: 1820 IF C=2 THEN C=C-1 */
line_1820:
    if (C==2) { C = C-1; }
    /* BASIC: 1830 FOR I=1 TO N: Z(I)=0: NEXT I */
line_1830:
    I = 1; for_loop_I: if ((1 >= 0 && I > N) || (1 < 0 && I < N)) goto end_for_I;
    Z(I) = 0;
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 1840 FOR I=1 TO 15: B(I)=0: NEXT I */
line_1840:
    I = 1; for_loop_I: if ((1 >= 0 && I > 15) || (1 < 0 && I < 15)) goto end_for_I;
    B(I) = 0;
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 1850 FOR I=1 TO 15: Q(I)=0: NEXT I */
line_1850:
    I = 1; for_loop_I: if ((1 >= 0 && I > 15) || (1 < 0 && I < 15)) goto end_for_I;
    Q(I) = 0;
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 1860 FOR I=1 TO 7: S(I)=0: NEXT I */
line_1860:
    I = 1; for_loop_I: if ((1 >= 0 && I > 7) || (1 < 0 && I < 7)) goto end_for_I;
    S(I) = 0;
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 1870 FOR I=1 TO 15: R(I)=0: NEXT I */
line_1870:
    I = 1; for_loop_I: if ((1 >= 0 && I > 15) || (1 < 0 && I < 15)) goto end_for_I;
    R(I) = 0;
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 1880 PRINT "BETS:" */
line_1880:
    printf("%s", "BETS:"); printf("\n");
    /* BASIC: 1890 FOR I=1 TO N: PRINT "#";I;: INPUT Z(I): NEXT I */
line_1890:
    I = 1; for_loop_I: if ((1 >= 0 && I > N) || (1 < 0 && I < N)) goto end_for_I;
    printf("%s", "#"); printf("%g ", (double)(I));
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &Z(I));
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 1900 FOR I=1 TO N */
line_1900:
    I = 1; for_loop_I: if ((1 >= 0 && I > N) || (1 < 0 && I < N)) goto end_for_I;
    /* BASIC: 1910 IF Z(I)<=0 OR Z(I)>500 THEN 1880 */
line_1910:
    if (Z(I)<==0 || Z(I)>500) goto line_1880;
    /* BASIC: 1920 B(I)=Z(I) */
line_1920:
    B(I) = Z(I);
    /* BASIC: 1930 NEXT I */
line_1930:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 1940 PRINT "PLAYER"; */
line_1940:
    printf("%s", "PLAYER");
    /* BASIC: 1950 FOR I=1 TO N */
line_1950:
    I = 1; for_loop_I: if ((1 >= 0 && I > N) || (1 < 0 && I < N)) goto end_for_I;
    /* BASIC: 1960 PRINT I;"   "; */
line_1960:
    printf("%g ", (double)(I)); printf("%s", "   ");
    /* BASIC: 1970 NEXT I */
line_1970:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 1980 PRINT "DEALER" */
line_1980:
    printf("%s", "DEALER"); printf("\n");
    /* BASIC: 1990 FOR J=1 TO 2 */
line_1990:
    J = 1; for_loop_J: if ((1 >= 0 && J > 2) || (1 < 0 && J < 2)) goto end_for_J;
    /* BASIC: 2000 PRINT TAB(5); */
line_2000:
    { int _t; for(_t=0; _t<5; _t++) printf(" "); }
    /* BASIC: 2010 FOR I=1 TO D1 */
line_2010:
    I = 1; for_loop_I: if ((1 >= 0 && I > D1) || (1 < 0 && I < D1)) goto end_for_I;
    /* BASIC: 2020 GOSUB 100 */
line_2020:
    /* TODO: GOSUB 100 */
    /* BASIC: 2030 P(I,J)=X */
line_2030:
    P(I,J) = X;
    /* BASIC: 2040 IF J=1 OR I<=N THEN GOSUB 750 */
line_2040:
    if (J==1 || I<==N) { /* TODO: GOSUB 750 */ }
    /* BASIC: 2050 NEXT I */
line_2050:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 2060 PRINT */
line_2060:
    printf("\n");
    /* BASIC: 2070 NEXT J */
line_2070:
    J += 1; goto for_loop_J; end_for_J:;
    /* BASIC: 2080 FOR I=1 TO D1 */
line_2080:
    I = 1; for_loop_I: if ((1 >= 0 && I > D1) || (1 < 0 && I < D1)) goto end_for_I;
    /* BASIC: 2090 R(I)=2 */
line_2090:
    R(I) = 2;
    /* BASIC: 2100 NEXT I */
line_2100:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 2110 REM--TEST FOR INSURANCE */
line_2110:
    // REM--TEST FOR INSURANCE
    /* BASIC: 2120 IF P(D1,1)>1 THEN 2240 */
line_2120:
    if (P(D1,1)>1) goto line_2240;
    /* BASIC: 2130 PRINT "ANY INSURANCE"; */
line_2130:
    printf("%s", "ANY INSURANCE");
    /* BASIC: 2140 INPUT H$ */
line_2140:
    printf("? "); fgets(H_str, sizeof(H_str), stdin); H_str[strcspn(H_str, "\n")] = 0;
    /* BASIC: 2150 IF LEFT$(H$,1)<>"Y" THEN 2240 */
line_2150:
    if (LEFT$(H$,1)!="Y") goto line_2240;
    /* BASIC: 2160 PRINT "INSURANCE BETS" */
line_2160:
    printf("%s", "INSURANCE BETS"); printf("\n");
    /* BASIC: 2170 FOR I=1 TO N: PRINT "#";I;: INPUT Z(I): NEXT I */
line_2170:
    I = 1; for_loop_I: if ((1 >= 0 && I > N) || (1 < 0 && I < N)) goto end_for_I;
    printf("%s", "#"); printf("%g ", (double)(I));
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &Z(I));
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 2180 FOR I=1 TO N */
line_2180:
    I = 1; for_loop_I: if ((1 >= 0 && I > N) || (1 < 0 && I < N)) goto end_for_I;
    /* BASIC: 2190 IF Z(I)<0 OR Z(I)>B(I)/2 THEN 2160 */
line_2190:
    if (Z(I)<0 || Z(I)>B(I)/2) goto line_2160;
    /* BASIC: 2200 NEXT I */
line_2200:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 2210 FOR I=1 TO N */
line_2210:
    I = 1; for_loop_I: if ((1 >= 0 && I > N) || (1 < 0 && I < N)) goto end_for_I;
    /* BASIC: 2220 S(I)=Z(I)*(3*(-(P(D1,2)>=10))-1) */
line_2220:
    S(I) = Z(I)*(3*(-(P(D1,2)>==10))-1);
    /* BASIC: 2230 NEXT I */
line_2230:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 2240 REM--TEST FOR DEALER BLACKJACK */
line_2240:
    // REM--TEST FOR DEALER BLACKJACK
    /* BASIC: 2250 L1=1: L2=1 */
line_2250:
    L1 = 1;
    L2 = 1;
    /* BASIC: 2252 IF P(D1,1)=1 AND P(D1,2)>9 THEN L1=0: L2=0 */
line_2252:
    if (P(D1,1)==1 && P(D1,2)>9) { L1 = 0; }
    L2 = 0;
    /* BASIC: 2253 IF P(D1,2)=1 AND P(D1,1)>9 THEN L1=0: L2=0 */
line_2253:
    if (P(D1,2)==1 && P(D1,1)>9) { L1 = 0; }
    L2 = 0;
    /* BASIC: 2254 IF L1<>0 OR L2<>0 THEN 2320 */
line_2254:
    if (L1!=0 || L2!=0) goto line_2320;
    /* BASIC: 2260 PRINT:PRINT "DEALER HAS A";MID$(D$,3*P(D1,2)-2,3);" IN THE HOLE "; */
line_2260:
    printf("\n");
    printf("%s", "DEALER HAS A"); printf("%s", MID$(D_str); printf("\t"); printf("%g ", (double)(3*P(D1)); printf("\t"); printf("%g ", (double)(2)-2)); printf("\t"); printf("%g ", (double)(3))); printf("%s", " IN THE HOLE ");
    /* BASIC: 2270 PRINT "FOR BLACKJACK" */
line_2270:
    printf("%s", "FOR BLACKJACK"); printf("\n");
    /* BASIC: 2280 FOR I=1 TO D1 */
line_2280:
    I = 1; for_loop_I: if ((1 >= 0 && I > D1) || (1 < 0 && I < D1)) goto end_for_I;
    /* BASIC: 2290 GOSUB 300 */
line_2290:
    /* TODO: GOSUB 300 */
    /* BASIC: 2300 NEXT I */
line_2300:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 2310 GOTO 3140 */
line_2310:
    goto line_3140;
    /* BASIC: 2320 REM--NO DEALER BLACKJACK */
line_2320:
    // REM--NO DEALER BLACKJACK
    /* BASIC: 2330 IF P(D1,1)>1 AND P(D1,1)<10 THEN 2350 */
line_2330:
    if (P(D1,1)>1 && P(D1,1)<10) goto line_2350;
    /* BASIC: 2340 PRINT:PRINT "NO DEALER BLACKJACK." */
line_2340:
    printf("\n");
    printf("%s", "NO DEALER BLACKJACK."); printf("\n");
    /* BASIC: 2350 REM--NOW PLAY THE HANDS */
line_2350:
    // REM--NOW PLAY THE HANDS
    /* BASIC: 2360 FOR I=1 TO N */
line_2360:
    I = 1; for_loop_I: if ((1 >= 0 && I > N) || (1 < 0 && I < N)) goto end_for_I;
    /* BASIC: 2370 PRINT "PLAYER";I; */
line_2370:
    printf("%s", "PLAYER"); printf("%g ", (double)(I));
    /* BASIC: 2380 H1=7 */
line_2380:
    H1 = 7;
    /* BASIC: 2390 GOSUB 1410 */
line_2390:
    /* TODO: GOSUB 1410 */
    /* BASIC: 2400 ON H GOTO 2550,2410,2510,2600 */
line_2400:
    /* UNTRANSLATED: ON H GOTO 2550,2410,2510,2600 */
    /* BASIC: 2410 REM--PLAYER WANTS TO STAND */
line_2410:
    // REM--PLAYER WANTS TO STAND
    /* BASIC: 2420 GOSUB 300 */
line_2420:
    /* TODO: GOSUB 300 */
    /* BASIC: 2430 IF Q(I)<>21 THEN 2490 */
line_2430:
    if (Q(I)!=21) goto line_2490;
    /* BASIC: 2440 PRINT "BLACKJACK" */
line_2440:
    printf("%s", "BLACKJACK"); printf("\n");
    /* BASIC: 2450 S(I)=S(I)+1.5*B(I) */
line_2450:
    S(I) = S(I)+1.5*B(I);
    /* BASIC: 2460 B(I)=0 */
line_2460:
    B(I) = 0;
    /* BASIC: 2470 GOSUB 1200 */
line_2470:
    /* TODO: GOSUB 1200 */
    /* BASIC: 2480 GOTO 2900 */
line_2480:
    goto line_2900;
    /* BASIC: 2490 GOSUB 1320 */
line_2490:
    /* TODO: GOSUB 1320 */
    /* BASIC: 2500 GOTO 2900 */
line_2500:
    goto line_2900;
    /* BASIC: 2510 REM--PLAYER WANTS TO DOUBLE DOWN */
line_2510:
    // REM--PLAYER WANTS TO DOUBLE DOWN
    /* BASIC: 2520 GOSUB 300 */
line_2520:
    /* TODO: GOSUB 300 */
    /* BASIC: 2530 GOSUB 860 */
line_2530:
    /* TODO: GOSUB 860 */
    /* BASIC: 2540 GOTO 2900 */
line_2540:
    goto line_2900;
    /* BASIC: 2550 REM--PLAYER WANTS TO BE HIT */
line_2550:
    // REM--PLAYER WANTS TO BE HIT
    /* BASIC: 2560 GOSUB 300 */
line_2560:
    /* TODO: GOSUB 300 */
    /* BASIC: 2570 H1=3 */
line_2570:
    H1 = 3;
    /* BASIC: 2580 GOSUB 950 */
line_2580:
    /* TODO: GOSUB 950 */
    /* BASIC: 2590 GOTO 2900 */
line_2590:
    goto line_2900;
    /* BASIC: 2600 REM--PLAYER WANTS TO SPLIT */
line_2600:
    // REM--PLAYER WANTS TO SPLIT
    /* BASIC: 2610 L1=P(I,1): IF P(I,1)>10 THEN L1=10 */
line_2610:
    L1 = P(I,1);
    if (P(I,1)>10) { L1 = 10; }
    /* BASIC: 2612 L2=P(I,2): IF P(I,2)>10 THEN L2=10 */
line_2612:
    L2 = P(I,2);
    if (P(I,2)>10) { L2 = 10; }
    /* BASIC: 2614 IF L1=L2 THEN 2640 */
line_2614:
    if (L1==L2) goto line_2640;
    /* BASIC: 2620 PRINT "SPLITTING NOT ALLOWED." */
line_2620:
    printf("%s", "SPLITTING NOT ALLOWED."); printf("\n");
    /* BASIC: 2630 GOTO 2370 */
line_2630:
    goto line_2370;
    /* BASIC: 2640 REM--PLAY OUT SPLIT */
line_2640:
    // REM--PLAY OUT SPLIT
    /* BASIC: 2650 I1=I+D1 */
line_2650:
    I1 = I+D1;
    /* BASIC: 2660 R(I1)=2 */
line_2660:
    R(I1) = 2;
    /* BASIC: 2670 P(I1,1)=P(I,2) */
line_2670:
    P(I1,1) = P(I,2);
    /* BASIC: 2680 B(I+D1)=B(I) */
line_2680:
    B(I+D1) = B(I);
    /* BASIC: 2690 GOSUB 100 */
line_2690:
    /* TODO: GOSUB 100 */
    /* BASIC: 2700 PRINT "FIRST HAND RECEIVES A"; */
line_2700:
    printf("%s", "FIRST HAND RECEIVES A");
    /* BASIC: 2710 GOSUB 700 */
line_2710:
    /* TODO: GOSUB 700 */
    /* BASIC: 2720 P(I,2)=X */
line_2720:
    P(I,2) = X;
    /* BASIC: 2730 GOSUB 300 */
line_2730:
    /* TODO: GOSUB 300 */
    /* BASIC: 2740 PRINT */
line_2740:
    printf("\n");
    /* BASIC: 2750 GOSUB 100 */
line_2750:
    /* TODO: GOSUB 100 */
    /* BASIC: 2760 PRINT "SECOND HAND RECEIVES A"; */
line_2760:
    printf("%s", "SECOND HAND RECEIVES A");
    /* BASIC: 2770 I=I1 */
line_2770:
    I = I1;
    /* BASIC: 2780 GOSUB 700 */
line_2780:
    /* TODO: GOSUB 700 */
    /* BASIC: 2790 P(I,2)=X */
line_2790:
    P(I,2) = X;
    /* BASIC: 2800 GOSUB 300 */
line_2800:
    /* TODO: GOSUB 300 */
    /* BASIC: 2810 PRINT */
line_2810:
    printf("\n");
    /* BASIC: 2820 I=I1-D1 */
line_2820:
    I = I1-D1;
    /* BASIC: 2830 IF P(I,1)=1 THEN 2900 */
line_2830:
    if (P(I,1)==1) goto line_2900;
    /* BASIC: 2840 REM--NOW PLAY THE TWO HANDS */
line_2840:
    // REM--NOW PLAY THE TWO HANDS
    /* BASIC: 2850 PRINT "HAND";1-(I>D1); */
line_2850:
    printf("%s", "HAND"); printf("%g ", (double)(1-(I>D1)));
    /* BASIC: 2860 GOSUB 800 */
line_2860:
    /* TODO: GOSUB 800 */
    /* BASIC: 2870 I=I+D1 */
line_2870:
    I = I+D1;
    /* BASIC: 2880 IF I=I1 THEN 2850 */
line_2880:
    if (I==I1) goto line_2850;
    /* BASIC: 2890 I=I1-D1 */
line_2890:
    I = I1-D1;
    /* BASIC: 2900 NEXT I */
line_2900:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 2910 GOSUB 300 */
line_2910:
    /* TODO: GOSUB 300 */
    /* BASIC: 2920 REM--TEST FOR PLAYING DEALER'S HAND */
line_2920:
    // REM--TEST FOR PLAYING DEALER'S HAND
    /* BASIC: 2930 FOR I=1 TO N */
line_2930:
    I = 1; for_loop_I: if ((1 >= 0 && I > N) || (1 < 0 && I < N)) goto end_for_I;
    /* BASIC: 2940 IF R(I)>0 OR R(I+D1)>0 THEN 3010 */
line_2940:
    if (R(I)>0 || R(I+D1)>0) goto line_3010;
    /* BASIC: 2950 NEXT I */
line_2950:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 2960 PRINT "DEALER HAD A"; */
line_2960:
    printf("%s", "DEALER HAD A");
    /* BASIC: 2970 X=P(D1,2) */
line_2970:
    X = P(D1,2);
    /* BASIC: 2980 GOSUB 700 */
line_2980:
    /* TODO: GOSUB 700 */
    /* BASIC: 2990 PRINT " CONCEALED." */
line_2990:
    printf("%s", " CONCEALED."); printf("\n");
    /* BASIC: 3000 GOTO 3140 */
line_3000:
    goto line_3140;
    /* BASIC: 3010 PRINT "DEALER HAS A";MID$(D$,3*P(D1,2)-2,3);" CONCEALED "; */
line_3010:
    printf("%s", "DEALER HAS A"); printf("%s", MID$(D_str); printf("\t"); printf("%g ", (double)(3*P(D1)); printf("\t"); printf("%g ", (double)(2)-2)); printf("\t"); printf("%g ", (double)(3))); printf("%s", " CONCEALED ");
    /* BASIC: 3020 I=D1 */
line_3020:
    I = D1;
    /* BASIC: 3030 AA=Q(I): GOSUB 3400 */
line_3030:
    AA = Q(I);
    /* TODO: GOSUB 3400 */
    /* BASIC: 3035 PRINT "FOR A TOTAL OF";AA */
line_3035:
    printf("%s", "FOR A TOTAL OF"); printf("%g ", (double)(AA)); printf("\n");
    /* BASIC: 3040 IF AA>16 THEN 3130 */
line_3040:
    if (AA>16) goto line_3130;
    /* BASIC: 3050 PRINT "DRAWS"; */
line_3050:
    printf("%s", "DRAWS");
    /* BASIC: 3060 GOSUB 100 */
line_3060:
    /* TODO: GOSUB 100 */
    /* BASIC: 3070 GOSUB 750 */
line_3070:
    /* TODO: GOSUB 750 */
    /* BASIC: 3080 GOSUB 1100 */
line_3080:
    /* TODO: GOSUB 1100 */
    /* BASIC: 3090 AA=Q: GOSUB 3400 */
line_3090:
    AA = Q;
    /* TODO: GOSUB 3400 */
    /* BASIC: 3095 IF Q>0 AND AA<17 THEN 3060 */
line_3095:
    if (Q>0 && AA<17) goto line_3060;
    /* BASIC: 3100 Q(I)=Q-(Q<0)/2 */
line_3100:
    Q(I) = Q-(Q<0)/2;
    /* BASIC: 3110 IF Q<0 THEN 3140 */
line_3110:
    if (Q<0) goto line_3140;
    /* BASIC: 3120 AA=Q: GOSUB 3400 */
line_3120:
    AA = Q;
    /* TODO: GOSUB 3400 */
    /* BASIC: 3125 PRINT "---TOTAL IS";AA */
line_3125:
    printf("%s", "---TOTAL IS"); printf("%g ", (double)(AA)); printf("\n");
    /* BASIC: 3130 PRINT */
line_3130:
    printf("\n");
    /* BASIC: 3140 REM--TALLY THE RESULT */
line_3140:
    // REM--TALLY THE RESULT
    /* BASIC: 3150 REM */
line_3150:
    // REM
    /* BASIC: 3160 Z$="LOSES PUSHES WINS " */
line_3160:
    strncpy(Z_str, ""LOSES PUSHES WINS "", sizeof(Z_str)); /* String assign approx */
    /* BASIC: 3165 PRINT */
line_3165:
    printf("\n");
    /* BASIC: 3170 FOR I=1 TO N */
line_3170:
    I = 1; for_loop_I: if ((1 >= 0 && I > N) || (1 < 0 && I < N)) goto end_for_I;
    /* BASIC: 3180 AA=Q(I): GOSUB 3400 */
line_3180:
    AA = Q(I);
    /* TODO: GOSUB 3400 */
    /* BASIC: 3182 AB=Q(I+D1): GOSUB 3410 */
line_3182:
    AB = Q(I+D1);
    /* TODO: GOSUB 3410 */
    /* BASIC: 3184 AC=Q(D1): GOSUB 3420 */
line_3184:
    AC = Q(D1);
    /* TODO: GOSUB 3420 */
    /* BASIC: 3186 S(I)=S(I)+B(I)*SGN(AA-AC)+B(I+D1)*SGN(AB-AC) */
line_3186:
    S(I) = S(I)+B(I)*SGN(AA-AC)+B(I+D1)*SGN(AB-AC);
    /* BASIC: 3188 B(I+D1)=0 */
line_3188:
    B(I+D1) = 0;
    /* BASIC: 3200 PRINT "PLAYER";I; */
line_3200:
    printf("%s", "PLAYER"); printf("%g ", (double)(I));
    /* BASIC: 3210 PRINT MID$(Z$,SGN(S(I))*6+7,6);" "; */
line_3210:
    printf("%s", MID$(Z_str); printf("\t"); printf("%g ", (double)(SGN(S(I))*6+7)); printf("\t"); printf("%g ", (double)(6))); printf("%s", " ");
    /* BASIC: 3220 IF S(I)<>0 THEN 3250 */
line_3220:
    if (S(I)!=0) goto line_3250;
    /* BASIC: 3230 PRINT "      "; */
line_3230:
    printf("%s", "      ");
    /* BASIC: 3240 GOTO 3260 */
line_3240:
    goto line_3260;
    /* BASIC: 3250 PRINT ABS(S(I)); */
line_3250:
    printf("%g ", (double)(fabs(S(I))));
    /* BASIC: 3260 T(I)=T(I)+S(I) */
line_3260:
    T(I) = T(I)+S(I);
    /* BASIC: 3270 PRINT "TOTAL=";T(I) */
line_3270:
    printf("%s", "TOTAL="); printf("%g ", (double)(T(I))); printf("\n");
    /* BASIC: 3280 GOSUB 1200 */
line_3280:
    /* TODO: GOSUB 1200 */
    /* BASIC: 3290 T(D1)=T(D1)-S(I) */
line_3290:
    T(D1) = T(D1)-S(I);
    /* BASIC: 3300 I=I+D1 */
line_3300:
    I = I+D1;
    /* BASIC: 3310 GOSUB 1200 */
line_3310:
    /* TODO: GOSUB 1200 */
    /* BASIC: 3320 I=I-D1 */
line_3320:
    I = I-D1;
    /* BASIC: 3330 NEXT I */
line_3330:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 3340 PRINT "DEALER'S TOTAL=";T(D1) */
line_3340:
    printf("%s", "DEALER'S TOTAL="); printf("%g ", (double)(T(D1))); printf("\n");
    /* BASIC: 3345 PRINT */
line_3345:
    printf("\n");
    /* BASIC: 3350 GOSUB 1200 */
line_3350:
    /* TODO: GOSUB 1200 */
    /* BASIC: 3360 GOTO 1810 */
line_3360:
    goto line_1810;
    /* BASIC: 3400 AA=AA+11*(AA>=22): RETURN */
line_3400:
    AA = AA+11*(AA>==22);
    /* TODO: RETURN */
    /* BASIC: 3410 AB=AB+11*(AB>=22): RETURN */
line_3410:
    AB = AB+11*(AB>==22);
    /* TODO: RETURN */
    /* BASIC: 3420 AC=AC+11*(AC>=22): RETURN */
line_3420:
    AC = AC+11*(AC>==22);
    /* TODO: RETURN */

    return 0;
}
