/*
 * Transpiled from horserace.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double P, DIRECTIONS, TABLE, J, NEW, TYPE, JERSEY, THE, HORSE, CHEVALIER, ON, A, D, UP, WHEN, BETS, KAREN, T, DURING, OWNED, RACETRACK, NUMBER, BY, MORRISTOWN, ANY, UNDER, HORSES, PLAY, XXXXSTARTXXXX, XXXXFINISHXXXX, V, WANT, JOLLY, LET, YOUR, I, MAW, Y, M, RACE, BET, W, H, MIDNIGHT, RESULTS, ODDS, OF, PAPER, ITS, WILL, CREATIVE, YOU, X, WINS, NO, NAME, ONE, HIGH, PRINTED, HORSERACE, SHOWN, MAY, BE, ARE, B, HOW, AMOUNT, C, JELLY, CAN, COMPUTING, WELCOME, WASHBURN, PORTLAND, APPEARS, SOUTH, MANY, JOE, Z9, AT, LAURIE, L, PLACE, DOWN, F, DO, R, THAT, YES, MR, O, N, Q, MISS;
    double S[1000] = {0}; /* Static array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 100 PRINT TAB(31);"HORSERACE" */
line_100:
    { int _t; for(_t=0; _t<31; _t++) printf(" "); } printf("%s", "HORSERACE"); printf("\n");
    /* BASIC: 110 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_110:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 120 PRINT:PRINT:PRINT */
line_120:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 210 DIM S(8) */
line_210:
    /* DIM S(8) (handled statically) */
    /* BASIC: 220 PRINT "WELCOME TO SOUTH PORTLAND HIGH RACETRACK" */
line_220:
    printf("%s", "WELCOME TO SOUTH PORTLAND HIGH RACETRACK"); printf("\n");
    /* BASIC: 230 PRINT "                      ...OWNED BY LAURIE CHEVALIER" */
line_230:
    printf("%s", "                      ...OWNED BY LAURIE CHEVALIER"); printf("\n");
    /* BASIC: 240 PRINT "DO YOU WANT DIRECTIONS"; */
line_240:
    printf("%s", "DO YOU WANT DIRECTIONS");
    /* BASIC: 250 INPUT X$ */
line_250:
    printf("? "); fgets(X_str, sizeof(X_str), stdin); X_str[strcspn(X_str, "\n")] = 0;
    /* BASIC: 260 IF X$="NO" THEN 320 */
line_260:
    if (X$=="NO") goto line_320;
    /* BASIC: 270 PRINT"UP TO 10 MAY PLAY.  A TABLE OF ODDS WILL BE PRINTED.  YOU" */
line_270:
    printf("%s", "UP TO 10 MAY PLAY.  A TABLE OF ODDS WILL BE PRINTED.  YOU"); printf("\n");
    /* BASIC: 280 PRINT"MAY BET ANY + AMOUNT UNDER 100000 ON ONE HORSE." */
line_280:
    printf("%s", "MAY BET ANY + AMOUNT UNDER 100000 ON ONE HORSE."); printf("\n");
    /* BASIC: 290 PRINT "DURING THE RACE, A HORSE WILL BE SHOWN BY ITS" */
line_290:
    printf("%s", "DURING THE RACE, A HORSE WILL BE SHOWN BY ITS"); printf("\n");
    /* BASIC: 300 PRINT"NUMBER.  THE HORSES RACE DOWN THE PAPER!" */
line_300:
    printf("%s", "NUMBER.  THE HORSES RACE DOWN THE PAPER!"); printf("\n");
    /* BASIC: 310 PRINT */
line_310:
    printf("\n");
    /* BASIC: 320 PRINT "HOW MANY WANT TO BET"; */
line_320:
    printf("%s", "HOW MANY WANT TO BET");
    /* BASIC: 330 INPUT C */
line_330:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &C);
    /* BASIC: 340 PRINT "WHEN ? APPEARS,TYPE NAME" */
line_340:
    printf("%s", "WHEN ? APPEARS,TYPE NAME"); printf("\n");
    /* BASIC: 350 FOR A=1 TO C */
line_350:
    A = 1; for_loop_A: if ((1 >= 0 && A > C) || (1 < 0 && A < C)) goto end_for_A;
    /* BASIC: 360 INPUT W$(A) */
line_360:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &W$(A));
    /* BASIC: 370 NEXT A */
line_370:
    A += 1; goto for_loop_A; end_for_A:;
    /* BASIC: 380 PRINT */
line_380:
    printf("\n");
    /* BASIC: 390 PRINT"HORSE",,"NUMBER","ODDS" */
line_390:
    printf("%s", "HORSE"); printf("\t"); printf("\t"); printf("%s", "NUMBER"); printf("\t"); printf("%s", "ODDS"); printf("\n");
    /* BASIC: 400 PRINT */
line_400:
    printf("\n");
    /* BASIC: 410 FOR I=1 TO 8: S(I)=0: NEXT I */
line_410:
    I = 1; for_loop_I: if ((1 >= 0 && I > 8) || (1 < 0 && I < 8)) goto end_for_I;
    S(I) = 0;
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 420 LET R=0 */
line_420:
    /* UNTRANSLATED: LET R=0 */
    /* BASIC: 430 FOR A=1 TO 8 */
line_430:
    A = 1; for_loop_A: if ((1 >= 0 && A > 8) || (1 < 0 && A < 8)) goto end_for_A;
    /* BASIC: 440 LET D(A)=INT(10*RND(1)+1) */
line_440:
    /* UNTRANSLATED: LET D(A)=INT(10*RND(1)+1) */
    /* BASIC: 450 NEXT A */
line_450:
    A += 1; goto for_loop_A; end_for_A:;
    /* BASIC: 460 FOR A=1 TO 8 */
line_460:
    A = 1; for_loop_A: if ((1 >= 0 && A > 8) || (1 < 0 && A < 8)) goto end_for_A;
    /* BASIC: 470 LET R=R+D(A) */
line_470:
    /* UNTRANSLATED: LET R=R+D(A) */
    /* BASIC: 480 NEXT A */
line_480:
    A += 1; goto for_loop_A; end_for_A:;
    /* BASIC: 490 LET V$(1)="JOE MAW" */
line_490:
    /* UNTRANSLATED: LET V$(1)="JOE MAW" */
    /* BASIC: 500 LET V$(2)="L.B.J." */
line_500:
    /* UNTRANSLATED: LET V$(2)="L.B.J." */
    /* BASIC: 510 LET V$(3)="MR.WASHBURN" */
line_510:
    /* UNTRANSLATED: LET V$(3)="MR.WASHBURN" */
    /* BASIC: 520 LET V$(4)="MISS KAREN" */
line_520:
    /* UNTRANSLATED: LET V$(4)="MISS KAREN" */
    /* BASIC: 530 LET V$(5)="JOLLY" */
line_530:
    /* UNTRANSLATED: LET V$(5)="JOLLY" */
    /* BASIC: 540 LET V$(6)="HORSE" */
line_540:
    /* UNTRANSLATED: LET V$(6)="HORSE" */
    /* BASIC: 550 LET V$(7)="JELLY DO NOT" */
line_550:
    /* UNTRANSLATED: LET V$(7)="JELLY DO NOT" */
    /* BASIC: 560 LET V$(8)="MIDNIGHT" */
line_560:
    /* UNTRANSLATED: LET V$(8)="MIDNIGHT" */
    /* BASIC: 570 FOR N=1 TO 8 */
line_570:
    N = 1; for_loop_N: if ((1 >= 0 && N > 8) || (1 < 0 && N < 8)) goto end_for_N;
    /* BASIC: 580 PRINT V$(N),,N,R/D(N);":1" */
line_580:
    printf("%g ", (double)(V$(N))); printf("\t"); printf("\t"); printf("%g ", (double)(N)); printf("\t"); printf("%g ", (double)(R/D(N))); printf("%s", ":1"); printf("\n");
    /* BASIC: 590 NEXT N */
line_590:
    N += 1; goto for_loop_N; end_for_N:;
    /* BASIC: 600 PRINT"--------------------------------------------------" */
line_600:
    printf("%s", "--------------------------------------------------"); printf("\n");
    /* BASIC: 610 PRINT "PLACE YOUR BETS...HORSE # THEN AMOUNT" */
line_610:
    printf("%s", "PLACE YOUR BETS...HORSE # THEN AMOUNT"); printf("\n");
    /* BASIC: 620 FOR J=1 TO C */
line_620:
    J = 1; for_loop_J: if ((1 >= 0 && J > C) || (1 < 0 && J < C)) goto end_for_J;
    /* BASIC: 630 PRINT W$(J); */
line_630:
    printf("%g ", (double)(W$(J)));
    /* BASIC: 640 INPUT Q(J),P(J) */
line_640:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &Q(J),P(J));
    /* BASIC: 650 IF P(J)<1 THEN 670 */
line_650:
    if (P(J)<1) goto line_670;
    /* BASIC: 660 IF P(J)<100000 THEN 690 */
line_660:
    if (P(J)<100000) goto line_690;
    /* BASIC: 670 PRINT"  YOU CAN'T DO THAT!" */
line_670:
    printf("%s", "  YOU CAN'T DO THAT!"); printf("\n");
    /* BASIC: 680 GOTO 630 */
line_680:
    goto line_630;
    /* BASIC: 690 NEXT J */
line_690:
    J += 1; goto for_loop_J; end_for_J:;
    /* BASIC: 700 PRINT */
line_700:
    printf("\n");
    /* BASIC: 710 PRINT"1 2 3 4 5 6 7 8" */
line_710:
    printf("%s", "1 2 3 4 5 6 7 8"); printf("\n");
    /* BASIC: 720 PRINT"XXXXSTARTXXXX" */
line_720:
    printf("%s", "XXXXSTARTXXXX"); printf("\n");
    /* BASIC: 730 FOR I=1 TO 8 */
line_730:
    I = 1; for_loop_I: if ((1 >= 0 && I > 8) || (1 < 0 && I < 8)) goto end_for_I;
    /* BASIC: 740 LET M=I */
line_740:
    /* UNTRANSLATED: LET M=I */
    /* BASIC: 750 LET M(I)=M */
line_750:
    /* UNTRANSLATED: LET M(I)=M */
    /* BASIC: 760 LET Y(M(I))=INT(100*RND(1)+1) */
line_760:
    /* UNTRANSLATED: LET Y(M(I))=INT(100*RND(1)+1) */
    /* BASIC: 770 IF Y(M(I))<10 THEN 860 */
line_770:
    if (Y(M(I))<10) goto line_860;
    /* BASIC: 780 LET S=INT(R/D(I)+.5) */
line_780:
    /* UNTRANSLATED: LET S=INT(R/D(I)+.5) */
    /* BASIC: 790 IF Y(M(I))<S+17 THEN 880 */
line_790:
    if (Y(M(I))<S+17) goto line_880;
    /* BASIC: 800 IF Y(M(I))<S+37 THEN 900 */
line_800:
    if (Y(M(I))<S+37) goto line_900;
    /* BASIC: 810 IF Y(M(I))<S+57 THEN 920 */
line_810:
    if (Y(M(I))<S+57) goto line_920;
    /* BASIC: 820 IF Y(M(I))<77+S THEN 940 */
line_820:
    if (Y(M(I))<77+S) goto line_940;
    /* BASIC: 830 IF Y(M(I))<S+92 THEN 960 */
line_830:
    if (Y(M(I))<S+92) goto line_960;
    /* BASIC: 840 LET Y(M(I))=7 */
line_840:
    /* UNTRANSLATED: LET Y(M(I))=7 */
    /* BASIC: 850 GOTO 970 */
line_850:
    goto line_970;
    /* BASIC: 860 LET Y(M(I))=1 */
line_860:
    /* UNTRANSLATED: LET Y(M(I))=1 */
    /* BASIC: 870 GOTO 970 */
line_870:
    goto line_970;
    /* BASIC: 880 LET Y(M(I))=2 */
line_880:
    /* UNTRANSLATED: LET Y(M(I))=2 */
    /* BASIC: 890 GOTO 970 */
line_890:
    goto line_970;
    /* BASIC: 900 LET Y(M(I))=3 */
line_900:
    /* UNTRANSLATED: LET Y(M(I))=3 */
    /* BASIC: 910 GOTO 970 */
line_910:
    goto line_970;
    /* BASIC: 920 LET Y(M(I))=4 */
line_920:
    /* UNTRANSLATED: LET Y(M(I))=4 */
    /* BASIC: 930 GOTO 970 */
line_930:
    goto line_970;
    /* BASIC: 940 LET Y(M(I))=5 */
line_940:
    /* UNTRANSLATED: LET Y(M(I))=5 */
    /* BASIC: 950 GOTO 970 */
line_950:
    goto line_970;
    /* BASIC: 960 LET Y(M(I))=6 */
line_960:
    /* UNTRANSLATED: LET Y(M(I))=6 */
    /* BASIC: 970 NEXT I */
line_970:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 980 LET M=I */
line_980:
    /* UNTRANSLATED: LET M=I */
    /* BASIC: 990 FOR I=1 TO 8 */
line_990:
    I = 1; for_loop_I: if ((1 >= 0 && I > 8) || (1 < 0 && I < 8)) goto end_for_I;
    /* BASIC: 1000 LET S(M(I))=S(M(I))+Y(M(I)) */
line_1000:
    /* UNTRANSLATED: LET S(M(I))=S(M(I))+Y(M(I)) */
    /* BASIC: 1010 NEXT I */
line_1010:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 1020 LET I=1 */
line_1020:
    /* UNTRANSLATED: LET I=1 */
    /* BASIC: 1030 FOR L=1 TO 8 */
line_1030:
    L = 1; for_loop_L: if ((1 >= 0 && L > 8) || (1 < 0 && L < 8)) goto end_for_L;
    /* BASIC: 1040 FOR I=1 TO 8-L */
line_1040:
    I = 1; for_loop_I: if ((1 >= 0 && I > 8-L) || (1 < 0 && I < 8-L)) goto end_for_I;
    /* BASIC: 1050 IF S(M(I))<S(M(I+1))THEN 1090 */
line_1050:
    /* UNTRANSLATED: IF S(M(I))<S(M(I+1))THEN 1090 */
    /* BASIC: 1060 LET H=M(I) */
line_1060:
    /* UNTRANSLATED: LET H=M(I) */
    /* BASIC: 1070 LET M(I)=M(I+1) */
line_1070:
    /* UNTRANSLATED: LET M(I)=M(I+1) */
    /* BASIC: 1080 LET M(I+1)=H */
line_1080:
    /* UNTRANSLATED: LET M(I+1)=H */
    /* BASIC: 1090 NEXT I */
line_1090:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 1100 NEXT L */
line_1100:
    L += 1; goto for_loop_L; end_for_L:;
    /* BASIC: 1110 LET T=S(M(8)) */
line_1110:
    /* UNTRANSLATED: LET T=S(M(8)) */
    /* BASIC: 1120 FOR I=1 TO 8 */
line_1120:
    I = 1; for_loop_I: if ((1 >= 0 && I > 8) || (1 < 0 && I < 8)) goto end_for_I;
    /* BASIC: 1130 LET B=S(M(I))-S(M(I-1)) */
line_1130:
    /* UNTRANSLATED: LET B=S(M(I))-S(M(I-1)) */
    /* BASIC: 1140 IF B=0 THEN 1190 */
line_1140:
    if (B==0) goto line_1190;
    /* BASIC: 1150 FOR A=1 TO B */
line_1150:
    A = 1; for_loop_A: if ((1 >= 0 && A > B) || (1 < 0 && A < B)) goto end_for_A;
    /* BASIC: 1160 PRINT */
line_1160:
    printf("\n");
    /* BASIC: 1170 IF S(M(I))>27 THEN 1240 */
line_1170:
    if (S(M(I))>27) goto line_1240;
    /* BASIC: 1180 NEXT A */
line_1180:
    A += 1; goto for_loop_A; end_for_A:;
    /* BASIC: 1190 PRINT M(I); */
line_1190:
    printf("%g ", (double)(M(I)));
    /* BASIC: 1200 NEXT I */
line_1200:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 1210 FOR A=1 TO 28-T */
line_1210:
    A = 1; for_loop_A: if ((1 >= 0 && A > 28-T) || (1 < 0 && A < 28-T)) goto end_for_A;
    /* BASIC: 1220 PRINT */
line_1220:
    printf("\n");
    /* BASIC: 1230 NEXT A */
line_1230:
    A += 1; goto for_loop_A; end_for_A:;
    /* BASIC: 1240 PRINT "XXXXFINISHXXXX"; */
line_1240:
    printf("%s", "XXXXFINISHXXXX");
    /* BASIC: 1242 PRINT */
line_1242:
    printf("\n");
    /* BASIC: 1243 PRINT */
line_1243:
    printf("\n");
    /* BASIC: 1244 PRINT "---------------------------------------------" */
line_1244:
    printf("%s", "---------------------------------------------"); printf("\n");
    /* BASIC: 1245 PRINT */
line_1245:
    printf("\n");
    /* BASIC: 1250 IF T<28 THEN 720 */
line_1250:
    if (T<28) goto line_720;
    /* BASIC: 1270 PRINT "THE RACE RESULTS ARE:" */
line_1270:
    printf("%s", "THE RACE RESULTS ARE:"); printf("\n");
    /* BASIC: 1272 LET Z9=1 */
line_1272:
    /* UNTRANSLATED: LET Z9=1 */
    /* BASIC: 1280 FOR I=8 TO 1 STEP-1 */
line_1280:
    I = 8; for_loop_I: if ((1 >= 0 && I > 1 STEP-1) || (1 < 0 && I < 1 STEP-1)) goto end_for_I;
    /* BASIC: 1290 LET F=M(I) */
line_1290:
    /* UNTRANSLATED: LET F=M(I) */
    /* BASIC: 1300 PRINT */
line_1300:
    printf("\n");
    /* BASIC: 1310 PRINT Z9;"PLACE HORSE NO.";F,"AT ";R/D(F);":1" */
line_1310:
    printf("%g ", (double)(Z9)); printf("%s", "PLACE HORSE NO."); printf("%g ", (double)(F)); printf("\t"); printf("%s", "AT "); printf("%g ", (double)(R/D(F))); printf("%s", ":1"); printf("\n");
    /* BASIC: 1312 LET Z9=Z9+1 */
line_1312:
    /* UNTRANSLATED: LET Z9=Z9+1 */
    /* BASIC: 1320  NEXT I */
line_1320:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 1330 FOR J=1 TO C */
line_1330:
    J = 1; for_loop_J: if ((1 >= 0 && J > C) || (1 < 0 && J < C)) goto end_for_J;
    /* BASIC: 1340 IF Q(J)<>M(8) THEN 1370 */
line_1340:
    if (Q(J)!=M(8)) goto line_1370;
    /* BASIC: 1350 LET N=Q(J) */
line_1350:
    /* UNTRANSLATED: LET N=Q(J) */
    /* BASIC: 1355 PRINT */
line_1355:
    printf("\n");
    /* BASIC: 1360 PRINT W$(J);" WINS $";(R/D(N))*P(J) */
line_1360:
    printf("%g ", (double)(W$(J))); printf("%s", " WINS $"); printf("%g ", (double)((R/D(N))*P(J))); printf("\n");
    /* BASIC: 1370 NEXT J */
line_1370:
    J += 1; goto for_loop_J; end_for_J:;
    /* BASIC: 1372 PRINT "DO YOU WANT TO BET ON THE NEXT RACE ?" */
line_1372:
    printf("%s", "DO YOU WANT TO BET ON THE NEXT RACE ?"); printf("\n");
    /* BASIC: 1374 INPUT "YES OR NO"; O$ */
line_1374:
    printf("%s", "YES OR NO"); fgets(O_str, sizeof(O_str), stdin); O_str[strcspn(O_str, "\n")] = 0;
    /* BASIC: 1376 IF O$="YES" THEN 380 */
line_1376:
    if (O$=="YES") goto line_380;
    /* BASIC: 1380 END */
line_1380:
    exit(0);

    return 0;
}
