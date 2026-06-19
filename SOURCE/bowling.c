/*
 * Transpiled from bowling.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double MEANS, SKILL, GOING, SCORES, P, GAME, FRAMES, J, NEW, TYPE, INSTRUCTIONS, STRIKE, JERSEY, THE, GUTTER, ON, LEFT, A, D, UP, BOWL, FRAME, DURING, PLAYING, MORRISTOWN, ACQUAINTED, PLAYER, KEEP, ALLEY, MIND, ERROR, BOWLING, WANT, ROLL, LET, ALL, YOUR, I, BRING, SHOW, Y, VERY, M, IS, DIAGRAM, K, OF, Z, SCORE, S, PIN, WILL, CREATIVE, COMPUTER, SPARE, YOU, X, OKAY, WITH, ANOTHER, OTHER, AFTER, GOOD, MAY, BE, ARE, B, HOW, TEN, FRIENDS, FOUR, COMPUTING, GET, WELCOME, BALL, STANDING, MANY, TAKES, PLAYERS, DOWN, F, DO, FIRST, COMPETE, R, O, N, Q;
    double C[1000] = {0}; /* Static array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 10 PRINT TAB(34);"BOWL" */
line_10:
    { int _t; for(_t=0; _t<34; _t++) printf(" "); } printf("%s", "BOWL"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 270 DIM C(15),A(100,6) */
line_270:
    /* DIM C(15),A(100,6) (handled statically) */
    /* BASIC: 360 PRINT "WELCOME TO THE ALLEY" */
line_360:
    printf("%s", "WELCOME TO THE ALLEY"); printf("\n");
    /* BASIC: 450 PRINT "BRING YOUR FRIENDS" */
line_450:
    printf("%s", "BRING YOUR FRIENDS"); printf("\n");
    /* BASIC: 540 PRINT "OKAY LET'S FIRST GET ACQUAINTED" */
line_540:
    printf("%s", "OKAY LET'S FIRST GET ACQUAINTED"); printf("\n");
    /* BASIC: 630 PRINT "" */
line_630:
    printf("%s", ""); printf("\n");
    /* BASIC: 720 PRINT "THE INSTRUCTIONS (Y/N)" */
line_720:
    printf("%s", "THE INSTRUCTIONS (Y/N)"); printf("\n");
    /* BASIC: 810 INPUT Z$ */
line_810:
    printf("? "); fgets(Z_str, sizeof(Z_str), stdin); Z_str[strcspn(Z_str, "\n")] = 0;
    /* BASIC: 900 IF Z$="Y" THEN 990 */
line_900:
    if (Z$=="Y") goto line_990;
    /* BASIC: 960 IF Z$="N" THEN 1530 */
line_960:
    if (Z$=="N") goto line_1530;
    /* BASIC: 990 PRINT "THE GAME OF BOWLING TAKES MIND AND SKILL.DURING THE GAME" */
line_990:
    printf("%s", "THE GAME OF BOWLING TAKES MIND AND SKILL.DURING THE GAME"); printf("\n");
    /* BASIC: 1080 PRINT "THE COMPUTER WILL KEEP SCORE.YOU MAY COMPETE WITH" */
line_1080:
    printf("%s", "THE COMPUTER WILL KEEP SCORE.YOU MAY COMPETE WITH"); printf("\n");
    /* BASIC: 1170 PRINT "OTHER PLAYERS[UP TO FOUR].YOU WILL BE PLAYING TEN FRAMES" */
line_1170:
    printf("%s", "OTHER PLAYERS[UP TO FOUR].YOU WILL BE PLAYING TEN FRAMES"); printf("\n");
    /* BASIC: 1260 PRINT "ON THE PIN DIAGRAM 'O' MEANS THE PIN IS DOWN...'+' MEANS THE" */
line_1260:
    printf("%s", "ON THE PIN DIAGRAM 'O' MEANS THE PIN IS DOWN...'+' MEANS THE"); printf("\n");
    /* BASIC: 1350 PRINT "PIN IS STANDING.AFTER THE GAME THE COMPUTER WILL SHOW YOUR" */
line_1350:
    printf("%s", "PIN IS STANDING.AFTER THE GAME THE COMPUTER WILL SHOW YOUR"); printf("\n");
    /* BASIC: 1440 PRINT "SCORES ." */
line_1440:
    printf("%s", "SCORES ."); printf("\n");
    /* BASIC: 1530 PRINT "FIRST OF ALL...HOW MANY ARE PLAYING"; */
line_1530:
    printf("%s", "FIRST OF ALL...HOW MANY ARE PLAYING");
    /* BASIC: 1620 INPUT R */
line_1620:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &R);
    /* BASIC: 1710 PRINT */
line_1710:
    printf("\n");
    /* BASIC: 1800 PRINT "VERY GOOD..." */
line_1800:
    printf("%s", "VERY GOOD..."); printf("\n");
    /* BASIC: 1890 FOR I=1 TO 100: FOR J=1 TO 6: A(I,J)=0: NEXT J: NEXT I */
line_1890:
    I = 1; for_loop_I: if ((1 >= 0 && I > 100) || (1 < 0 && I < 100)) goto end_for_I;
    J = 1; for_loop_J: if ((1 >= 0 && J > 6) || (1 < 0 && J < 6)) goto end_for_J;
    A(I,J) = 0;
    J += 1; goto for_loop_J; end_for_J:;
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 1980 F=1 */
line_1980:
    F = 1;
    /* BASIC: 2070 FOR P=1 TO R */
line_2070:
    P = 1; for_loop_P: if ((1 >= 0 && P > R) || (1 < 0 && P < R)) goto end_for_P;
    /* BASIC: 2160 M=0 */
line_2160:
    M = 0;
    /* BASIC: 2250 B=1 */
line_2250:
    B = 1;
    /* BASIC: 2340 M=0: Q=0 */
line_2340:
    M = 0;
    Q = 0;
    /* BASIC: 2430 FOR I=1 TO 15: C(I)=0: NEXT I */
line_2430:
    I = 1; for_loop_I: if ((1 >= 0 && I > 15) || (1 < 0 && I < 15)) goto end_for_I;
    C(I) = 0;
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 2520 REM ARK BALL GENERATOR USING MOD '15' SYSTEM */
line_2520:
    // REM ARK BALL GENERATOR USING MOD '15' SYSTEM
    /* BASIC: 2610 PRINT "TYPE ROLL TO GET THE BALL GOING." */
line_2610:
    printf("%s", "TYPE ROLL TO GET THE BALL GOING."); printf("\n");
    /* BASIC: 2700 INPUT N$ */
line_2700:
    printf("? "); fgets(N_str, sizeof(N_str), stdin); N_str[strcspn(N_str, "\n")] = 0;
    /* BASIC: 2790 K=0: D=0 */
line_2790:
    K = 0;
    D = 0;
    /* BASIC: 2880 FOR I=1 TO 20 */
line_2880:
    I = 1; for_loop_I: if ((1 >= 0 && I > 20) || (1 < 0 && I < 20)) goto end_for_I;
    /* BASIC: 2970 X=INT(RND(1)*100) */
line_2970:
    X = floor(((double)rand() / (double)RAND_MAX)*100);
    /* BASIC: 3060 FOR J=1 TO 10 */
line_3060:
    J = 1; for_loop_J: if ((1 >= 0 && J > 10) || (1 < 0 && J < 10)) goto end_for_J;
    /* BASIC: 3150 IF X<15*J THEN 3330 */
line_3150:
    if (X<15*J) goto line_3330;
    /* BASIC: 3240 NEXT J */
line_3240:
    J += 1; goto for_loop_J; end_for_J:;
    /* BASIC: 3330 C(15*J-X)=1 */
line_3330:
    C(15*J-X) = 1;
    /* BASIC: 3420 NEXT I */
line_3420:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 3510 REM ARK PIN DIAGRAM */
line_3510:
    // REM ARK PIN DIAGRAM
    /* BASIC: 3600 PRINT "PLAYER:"P;"FRAME:";F"BALL:"B */
line_3600:
    printf("%g ", (double)("PLAYER:"P)); printf("%s", "FRAME:"); printf("%g ", (double)(F"BALL:"B)); printf("\n");
    /* BASIC: 3690 FOR I=0 TO 3 */
line_3690:
    I = 0; for_loop_I: if ((1 >= 0 && I > 3) || (1 < 0 && I < 3)) goto end_for_I;
    /* BASIC: 3780 PRINT */
line_3780:
    printf("\n");
    /* BASIC: 3870 FOR J=1 TO 4-I */
line_3870:
    J = 1; for_loop_J: if ((1 >= 0 && J > 4-I) || (1 < 0 && J < 4-I)) goto end_for_J;
    /* BASIC: 3960 K=K+1 */
line_3960:
    K = K+1;
    /* BASIC: 4050 IF C(K)=1 THEN 4320 */
line_4050:
    if (C(K)==1) goto line_4320;
    /* BASIC: 4140 PRINT TAB(I);"+ "; */
line_4140:
    { int _t; for(_t=0; _t<I; _t++) printf(" "); } printf("%s", "+ ");
    /* BASIC: 4230 GOTO 4410 */
line_4230:
    goto line_4410;
    /* BASIC: 4320 PRINT TAB(I);"O "; */
line_4320:
    { int _t; for(_t=0; _t<I; _t++) printf(" "); } printf("%s", "O ");
    /* BASIC: 4410 NEXT J */
line_4410:
    J += 1; goto for_loop_J; end_for_J:;
    /* BASIC: 4500 NEXT I */
line_4500:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 4590 PRINT "" */
line_4590:
    printf("%s", ""); printf("\n");
    /* BASIC: 4680 REM ARK ROLL ANALYSIS */
line_4680:
    // REM ARK ROLL ANALYSIS
    /* BASIC: 4770 FOR I=1 TO 10 */
line_4770:
    I = 1; for_loop_I: if ((1 >= 0 && I > 10) || (1 < 0 && I < 10)) goto end_for_I;
    /* BASIC: 4860 D=D+C(I) */
line_4860:
    D = D+C(I);
    /* BASIC: 4950 NEXT I */
line_4950:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 5040 IF D-M <> 0 THEN 5220 */
line_5040:
    if (D-M != 0) goto line_5220;
    /* BASIC: 5130 PRINT "GUTTER!!" */
line_5130:
    printf("%s", "GUTTER!!"); printf("\n");
    /* BASIC: 5220 IF B<>1 OR D<>10 THEN 5490 */
line_5220:
    if (B!=1 || D!=10) goto line_5490;
    /* BASIC: 5310 PRINT "STRIKE!!!!!" */
line_5310:
    printf("%s", "STRIKE!!!!!"); printf("\n");
    /* BASIC: 5400 Q=3 */
line_5400:
    Q = 3;
    /* BASIC: 5490 IF B<>2 OR D<>10 THEN 5760 */
line_5490:
    if (B!=2 || D!=10) goto line_5760;
    /* BASIC: 5580 PRINT "SPARE!!!!" */
line_5580:
    printf("%s", "SPARE!!!!"); printf("\n");
    /* BASIC: 5670 Q=2 */
line_5670:
    Q = 2;
    /* BASIC: 5760 IF B<>2 OR D>=10 THEN 6030 */
line_5760:
    if (B!=2 || D>==10) goto line_6030;
    /* BASIC: 5850 PRINT "ERROR!!!" */
line_5850:
    printf("%s", "ERROR!!!"); printf("\n");
    /* BASIC: 5940 Q=1 */
line_5940:
    Q = 1;
    /* BASIC: 6030 IF B<>1 OR D>=10 THEN 6210 */
line_6030:
    if (B!=1 || D>==10) goto line_6210;
    /* BASIC: 6120 PRINT "ROLL YOUR 2ND BALL" */
line_6120:
    printf("%s", "ROLL YOUR 2ND BALL"); printf("\n");
    /* BASIC: 6210 REM ARK STORAGE OF THE SCORES */
line_6210:
    // REM ARK STORAGE OF THE SCORES
    /* BASIC: 6300 PRINT */
line_6300:
    printf("\n");
    /* BASIC: 6390 A(F*P,B)=D */
line_6390:
    A(F*P,B) = D;
    /* BASIC: 6480 IF B=2 THEN 7020 */
line_6480:
    if (B==2) goto line_7020;
    /* BASIC: 6570 B=2 */
line_6570:
    B = 2;
    /* BASIC: 6660 M=D */
line_6660:
    M = D;
    /* BASIC: 6750 IF Q=3 THEN 6210 */
line_6750:
    if (Q==3) goto line_6210;
    /* BASIC: 6840 A(F*P,B)=D-M */
line_6840:
    A(F*P,B) = D-M;
    /* BASIC: 6930 IF Q=0 THEN 2520 */
line_6930:
    if (Q==0) goto line_2520;
    /* BASIC: 7020 A(F*P,3)=Q */
line_7020:
    A(F*P,3) = Q;
    /* BASIC: 7110 NEXT P */
line_7110:
    P += 1; goto for_loop_P; end_for_P:;
    /* BASIC: 7200 F=F+1 */
line_7200:
    F = F+1;
    /* BASIC: 7290 IF F<11 THEN 2070 */
line_7290:
    if (F<11) goto line_2070;
    /* BASIC: 7295 PRINT "FRAMES" */
line_7295:
    printf("%s", "FRAMES"); printf("\n");
    /* BASIC: 7380 FOR I=1 TO 10 */
line_7380:
    I = 1; for_loop_I: if ((1 >= 0 && I > 10) || (1 < 0 && I < 10)) goto end_for_I;
    /* BASIC: 7470 PRINT I; */
line_7470:
    printf("%g ", (double)(I));
    /* BASIC: 7560 NEXT I */
line_7560:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 7650 PRINT */
line_7650:
    printf("\n");
    /* BASIC: 7740 FOR P=1 TO R */
line_7740:
    P = 1; for_loop_P: if ((1 >= 0 && P > R) || (1 < 0 && P < R)) goto end_for_P;
    /* BASIC: 7830 FOR I=1 TO 3 */
line_7830:
    I = 1; for_loop_I: if ((1 >= 0 && I > 3) || (1 < 0 && I < 3)) goto end_for_I;
    /* BASIC: 7920 FOR J=1 TO 10 */
line_7920:
    J = 1; for_loop_J: if ((1 >= 0 && J > 10) || (1 < 0 && J < 10)) goto end_for_J;
    /* BASIC: 8010 PRINT A(J*P,I); */
line_8010:
    printf("%g ", (double)(A(J*P)); printf("\t"); printf("%g ", (double)(I)));
    /* BASIC: 8100 NEXT J */
line_8100:
    J += 1; goto for_loop_J; end_for_J:;
    /* BASIC: 8105 PRINT */
line_8105:
    printf("\n");
    /* BASIC: 8190 NEXT I */
line_8190:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 8280 PRINT */
line_8280:
    printf("\n");
    /* BASIC: 8370 NEXT P */
line_8370:
    P += 1; goto for_loop_P; end_for_P:;
    /* BASIC: 8460 PRINT "DO YOU WANT ANOTHER GAME" */
line_8460:
    printf("%s", "DO YOU WANT ANOTHER GAME"); printf("\n");
    /* BASIC: 8550 INPUT A$ */
line_8550:
    printf("? "); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    /* BASIC: 8640 IF LEFT$(A$,1)="Y" THEN 2610 */
line_8640:
    if (LEFT$(A$,1)=="Y") goto line_2610;
    /* BASIC: 8730 END */
line_8730:
    exit(0);

    return 0;
}
