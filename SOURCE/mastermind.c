/*
 * Transpiled from mastermind.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double BYE, ORANGE, READ, NOW, THAN, P, GAME, CHR, INFORMATION, ROUNDS, NEW, BOARD, ACTUAL, JERSEY, THE, HAVING, A, WHEN, UP, IT, TAN, T, IN, WHITES, NUMBER, BLACKS, OUT, MORRISTOWN, MID, DATA, OFF, WAS, GUESSED, TIME, INCONSISTENT, TRY, GUESS, CAREFUL, MASTERMIND, QUIT, COMBINATION, BAD, FINAL, W1, RED, ALL, I, COLORS, Y, M, MORE, ME, W, R9, H, COLOR, IS, ROUND, OF, Z, B1, BWRGOYPT, SCORE, S, CREATIVE, MY, THINK, COMPUTER, PLEASE, YOU, X, QUITTER, NO, USED, DAY, GREEN, GIVEN, G, P9, GOOD, AN, GOT, PURPLE, BE, YELLOW, B, MOVES, C, MOVE, HUMAN, TOTAL, UNRECOGNIZED, COMPUTING, JUST, READY, GET, HIT, POSITIONS, POSSIBILITIES, BLACK, L, LETTER, WHITE, CPU, F, AGAIN, R, THAT, C9, OVER, RAN, HAVE, THIS;
    double Q[1000] = {0}; /* Static array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 2 PRINT TAB(30);"MASTERMIND" */
line_2:
    { int _t; for(_t=0; _t<30; _t++) printf(" "); } printf("%s", "MASTERMIND"); printf("\n");
    /* BASIC: 4 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 6 PRINT: PRINT: PRINT */
line_6:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 10 REM */
line_10:
    // REM
    /* BASIC: 20 REM     MASTERMIND II */
line_20:
    // REM     MASTERMIND II
    /* BASIC: 30 REM     STEVE NORTH */
line_30:
    // REM     STEVE NORTH
    /* BASIC: 40 REM     CREATIVE COMPUTING */
line_40:
    // REM     CREATIVE COMPUTING
    /* BASIC: 50 REM     PO BOX 789-M MORRISTOWN NEW JERSEY 07960 */
line_50:
    // REM     PO BOX 789-M MORRISTOWN NEW JERSEY 07960
    /* BASIC: 60 REM */
line_60:
    // REM
    /* BASIC: 70 REM */
line_70:
    // REM
    /* BASIC: 80 INPUT "NUMBER OF COLORS";C9 */
line_80:
    printf("%s", "NUMBER OF COLORS"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &C9);
    /* BASIC: 90 IF C9>8 THEN PRINT "NO MORE THAN 8, PLEASE!":GOTO 80 */
line_90:
    if (C9>8) { printf("%s", "NO MORE THAN 8, PLEASE!"); printf("\n"); }
    goto line_80;
    /* BASIC: 100 INPUT "NUMBER OF POSITIONS";P9 */
line_100:
    printf("%s", "NUMBER OF POSITIONS"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &P9);
    /* BASIC: 110 INPUT "NUMBER OF ROUNDS";R9 */
line_110:
    printf("%s", "NUMBER OF ROUNDS"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &R9);
    /* BASIC: 120 P=C9^P9 */
line_120:
    P = C9^P9;
    /* BASIC: 130 PRINT "TOTAL POSSIBILITIES =";P */
line_130:
    printf("%s", "TOTAL POSSIBILITIES ="); printf("%g ", (double)(P)); printf("\n");
    /* BASIC: 140 H=0:C=0 */
line_140:
    H = 0;
    C = 0;
    /* BASIC: 150 DIM Q(P9),S(10,2),S$(10),A$(P9),G$(P9),I(P),H$(P9) */
line_150:
    /* DIM Q(P9),S(10,2),S$(10),A$(P9),G$(P9),I(P),H$(P9) (handled statically) */
    /* BASIC: 160 L$="BWRGOYPT" */
line_160:
    strncpy(L_str, ""BWRGOYPT"", sizeof(L_str)); /* String assign approx */
    /* BASIC: 170 PRINT */
line_170:
    printf("\n");
    /* BASIC: 180 PRINT */
line_180:
    printf("\n");
    /* BASIC: 190 PRINT "COLOR     LETTER" */
line_190:
    printf("%s", "COLOR     LETTER"); printf("\n");
    /* BASIC: 200 PRINT "=====     ======" */
line_200:
    printf("%s", "=====     ======"); printf("\n");
    /* BASIC: 210 FOR X=1 TO C9 */
line_210:
    X = 1; for_loop_X: if ((1 >= 0 && X > C9) || (1 < 0 && X < C9)) goto end_for_X;
    /* BASIC: 220 READ X$ */
line_220:
    /* UNTRANSLATED: READ X$ */
    /* BASIC: 230 PRINT X$;TAB(13);MID$(L$,X,1) */
line_230:
    printf("%s", X_str); { int _t; for(_t=0; _t<13; _t++) printf(" "); } printf("%s", MID$(L_str); printf("\t"); printf("%g ", (double)(X)); printf("\t"); printf("%g ", (double)(1))); printf("\n");
    /* BASIC: 240 NEXT X */
line_240:
    X += 1; goto for_loop_X; end_for_X:;
    /* BASIC: 250 PRINT */
line_250:
    printf("\n");
    /* BASIC: 260 FOR R=1 TO R9 */
line_260:
    R = 1; for_loop_R: if ((1 >= 0 && R > R9) || (1 < 0 && R < R9)) goto end_for_R;
    /* BASIC: 270 PRINT */
line_270:
    printf("\n");
    /* BASIC: 280 PRINT "ROUND NUMBER";R;"----" */
line_280:
    printf("%s", "ROUND NUMBER"); printf("%g ", (double)(R)); printf("%s", "----"); printf("\n");
    /* BASIC: 290 PRINT */
line_290:
    printf("\n");
    /* BASIC: 300 PRINT "GUESS MY COMBINATION.":PRINT */
line_300:
    printf("%s", "GUESS MY COMBINATION."); printf("\n");
    printf("\n");
    /* BASIC: 310 REM     GET A COMBINATION */
line_310:
    // REM     GET A COMBINATION
    /* BASIC: 320 A=INT(P*RND(1)+1) */
line_320:
    A = floor(P*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 330 GOSUB 3000 */
line_330:
    /* TODO: GOSUB 3000 */
    /* BASIC: 340 FOR X=1 TO A */
line_340:
    X = 1; for_loop_X: if ((1 >= 0 && X > A) || (1 < 0 && X < A)) goto end_for_X;
    /* BASIC: 350 GOSUB 3500 */
line_350:
    /* TODO: GOSUB 3500 */
    /* BASIC: 360 NEXT X */
line_360:
    X += 1; goto for_loop_X; end_for_X:;
    /* BASIC: 370 FOR M=1 TO 10 */
line_370:
    M = 1; for_loop_M: if ((1 >= 0 && M > 10) || (1 < 0 && M < 10)) goto end_for_M;
    /* BASIC: 380 PRINT "MOVE # ";M;" GUESS ";:INPUT X$ */
line_380:
    printf("%s", "MOVE # "); printf("%g ", (double)(M)); printf("%s", " GUESS ");
    printf("? "); fgets(X_str, sizeof(X_str), stdin); X_str[strcspn(X_str, "\n")] = 0;
    /* BASIC: 390 IF X$="BOARD" THEN 2000 */
line_390:
    if (X$=="BOARD") goto line_2000;
    /* BASIC: 400 IF X$="QUIT" THEN 2500 */
line_400:
    if (X$=="QUIT") goto line_2500;
    /* BASIC: 410 IF LEN(X$)<>P9 THEN PRINT "BAD NUMBER OF POSITIONS.":GOTO 380 */
line_410:
    if (LEN(X$)!=P9) { printf("%s", "BAD NUMBER OF POSITIONS."); printf("\n"); }
    goto line_380;
    /* BASIC: 420 REM     UNPACK X$ INTO G$(1-P9) */
line_420:
    // REM     UNPACK X$ INTO G$(1-P9)
    /* BASIC: 430 FOR X=1 TO P9 */
line_430:
    X = 1; for_loop_X: if ((1 >= 0 && X > P9) || (1 < 0 && X < P9)) goto end_for_X;
    /* BASIC: 440 FOR Y=1 TO C9 */
line_440:
    Y = 1; for_loop_Y: if ((1 >= 0 && Y > C9) || (1 < 0 && Y < C9)) goto end_for_Y;
    /* BASIC: 450 IF MID$(X$,X,1)=MID$(L$,Y,1) THEN 480 */
line_450:
    if (MID$(X$,X,1)==MID$(L$,Y,1)) goto line_480;
    /* BASIC: 460 NEXT Y */
line_460:
    Y += 1; goto for_loop_Y; end_for_Y:;
    /* BASIC: 470 PRINT "'"; MID$(X$,X,1); "' IS UNRECOGNIZED.":GOTO 380 */
line_470:
    printf("%s", "'"); printf("%s", MID$(X_str); printf("\t"); printf("%g ", (double)(X)); printf("\t"); printf("%g ", (double)(1))); printf("%s", "' IS UNRECOGNIZED."); printf("\n");
    goto line_380;
    /* BASIC: 480 G$(X)=MID$(X$,X,1) */
line_480:
    G$(X) = MID$(X$,X,1);
    /* BASIC: 490 NEXT X */
line_490:
    X += 1; goto for_loop_X; end_for_X:;
    /* BASIC: 500 REM     NOW WE CONVERT Q(1-P9) INTO A$(1-P9) [ACTUAL GUESS] */
line_500:
    // REM     NOW WE CONVERT Q(1-P9) INTO A$(1-P9) [ACTUAL GUESS]
    /* BASIC: 510 GOSUB 4000 */
line_510:
    /* TODO: GOSUB 4000 */
    /* BASIC: 520 REM     AND GET NUMBER OF BLACKS AND WHITES */
line_520:
    // REM     AND GET NUMBER OF BLACKS AND WHITES
    /* BASIC: 530 GOSUB 4500 */
line_530:
    /* TODO: GOSUB 4500 */
    /* BASIC: 540 IF B=P9 THEN 630 */
line_540:
    if (B==P9) goto line_630;
    /* BASIC: 550 REM     TELL HUMAN RESULTS */
line_550:
    // REM     TELL HUMAN RESULTS
    /* BASIC: 560 PRINT "YOU HAVE ";B;" BLACKS AND ";W;" WHITES." */
line_560:
    printf("%s", "YOU HAVE "); printf("%g ", (double)(B)); printf("%s", " BLACKS AND "); printf("%g ", (double)(W)); printf("%s", " WHITES."); printf("\n");
    /* BASIC: 570 REM     SAVE ALL THIS STUFF FOR BOARD PRINTOUT LATER */
line_570:
    // REM     SAVE ALL THIS STUFF FOR BOARD PRINTOUT LATER
    /* BASIC: 580 S$(M)=X$ */
line_580:
    S$(M) = X$;
    /* BASIC: 590 S(M,1)=B */
line_590:
    S(M,1) = B;
    /* BASIC: 600 S(M,2)=W */
line_600:
    S(M,2) = W;
    /* BASIC: 610 NEXT M */
line_610:
    M += 1; goto for_loop_M; end_for_M:;
    /* BASIC: 620 PRINT "YOU RAN OUT OF MOVES!  THAT'S ALL YOU GET!":GOTO 640 */
line_620:
    printf("%s", "YOU RAN OUT OF MOVES!  THAT'S ALL YOU GET!"); printf("\n");
    goto line_640;
    /* BASIC: 622 GOSUB 4000 */
line_622:
    /* TODO: GOSUB 4000 */
    /* BASIC: 623 PRINT "THE ACTUAL COMBINATION WAS: "; */
line_623:
    printf("%s", "THE ACTUAL COMBINATION WAS: ");
    /* BASIC: 624 FOR X=1 TO P9 */
line_624:
    X = 1; for_loop_X: if ((1 >= 0 && X > P9) || (1 < 0 && X < P9)) goto end_for_X;
    /* BASIC: 625 PRINT A$(X); */
line_625:
    printf("%g ", (double)(A$(X)));
    /* BASIC: 626 NEXT X */
line_626:
    X += 1; goto for_loop_X; end_for_X:;
    /* BASIC: 627 PRINT */
line_627:
    printf("\n");
    /* BASIC: 630 PRINT "YOU GUESSED IT IN ";M;" MOVES!" */
line_630:
    printf("%s", "YOU GUESSED IT IN "); printf("%g ", (double)(M)); printf("%s", " MOVES!"); printf("\n");
    /* BASIC: 640 H=H+M */
line_640:
    H = H+M;
    /* BASIC: 650 GOSUB 5000 */
line_650:
    /* TODO: GOSUB 5000 */
    /* BASIC: 660 REM */
line_660:
    // REM
    /* BASIC: 670 REM     NOW COMPUTER GUESSES */
line_670:
    // REM     NOW COMPUTER GUESSES
    /* BASIC: 680 REM */
line_680:
    // REM
    /* BASIC: 690 FOR X=1 TO P */
line_690:
    X = 1; for_loop_X: if ((1 >= 0 && X > P) || (1 < 0 && X < P)) goto end_for_X;
    /* BASIC: 700 I(X)=1 */
line_700:
    I(X) = 1;
    /* BASIC: 710 NEXT X */
line_710:
    X += 1; goto for_loop_X; end_for_X:;
    /* BASIC: 720 PRINT "NOW I GUESS.  THINK OF A COMBINATION." */
line_720:
    printf("%s", "NOW I GUESS.  THINK OF A COMBINATION."); printf("\n");
    /* BASIC: 730 INPUT "HIT RETURN WHEN READY:";X$ */
line_730:
    printf("%s", "HIT RETURN WHEN READY:"); fgets(X_str, sizeof(X_str), stdin); X_str[strcspn(X_str, "\n")] = 0;
    /* BASIC: 740 FOR M=1 TO 10 */
line_740:
    M = 1; for_loop_M: if ((1 >= 0 && M > 10) || (1 < 0 && M < 10)) goto end_for_M;
    /* BASIC: 750 GOSUB 3000 */
line_750:
    /* TODO: GOSUB 3000 */
    /* BASIC: 760 REM     FIND A GUESS */
line_760:
    // REM     FIND A GUESS
    /* BASIC: 770 G=INT(P*RND(1)+1) */
line_770:
    G = floor(P*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 780 IF I(G)=1 THEN 890 */
line_780:
    if (I(G)==1) goto line_890;
    /* BASIC: 790 FOR X=G TO P */
line_790:
    X = G; for_loop_X: if ((1 >= 0 && X > P) || (1 < 0 && X < P)) goto end_for_X;
    /* BASIC: 800 IF I(X)=1 THEN 880 */
line_800:
    if (I(X)==1) goto line_880;
    /* BASIC: 810 NEXT X */
line_810:
    X += 1; goto for_loop_X; end_for_X:;
    /* BASIC: 820 FOR X=1 TO G */
line_820:
    X = 1; for_loop_X: if ((1 >= 0 && X > G) || (1 < 0 && X < G)) goto end_for_X;
    /* BASIC: 830 IF I(X)=1 THEN 880 */
line_830:
    if (I(X)==1) goto line_880;
    /* BASIC: 840 NEXT X */
line_840:
    X += 1; goto for_loop_X; end_for_X:;
    /* BASIC: 850 PRINT "YOU HAVE GIVEN ME INCONSISTENT INFORMATION." */
line_850:
    printf("%s", "YOU HAVE GIVEN ME INCONSISTENT INFORMATION."); printf("\n");
    /* BASIC: 860 PRINT "TRY AGAIN, AND THIS TIME PLEASE BE MORE CAREFUL." */
line_860:
    printf("%s", "TRY AGAIN, AND THIS TIME PLEASE BE MORE CAREFUL."); printf("\n");
    /* BASIC: 870 GOTO 660 */
line_870:
    goto line_660;
    /* BASIC: 880 G=X */
line_880:
    G = X;
    /* BASIC: 890 REM     NOW WE CONVERT GUESS #G INTO G$ */
line_890:
    // REM     NOW WE CONVERT GUESS #G INTO G$
    /* BASIC: 900 FOR X=1 TO G */
line_900:
    X = 1; for_loop_X: if ((1 >= 0 && X > G) || (1 < 0 && X < G)) goto end_for_X;
    /* BASIC: 910 GOSUB 3500 */
line_910:
    /* TODO: GOSUB 3500 */
    /* BASIC: 920 NEXT X */
line_920:
    X += 1; goto for_loop_X; end_for_X:;
    /* BASIC: 930 GOSUB 6000 */
line_930:
    /* TODO: GOSUB 6000 */
    /* BASIC: 940 PRINT "MY GUESS IS: "; */
line_940:
    printf("%s", "MY GUESS IS: ");
    /* BASIC: 950 FOR X=1 TO P9 */
line_950:
    X = 1; for_loop_X: if ((1 >= 0 && X > P9) || (1 < 0 && X < P9)) goto end_for_X;
    /* BASIC: 960 PRINT H$(X); */
line_960:
    printf("%g ", (double)(H$(X)));
    /* BASIC: 970 NEXT X */
line_970:
    X += 1; goto for_loop_X; end_for_X:;
    /* BASIC: 980 INPUT "  BLACKS, WHITES ";B1,W1 */
line_980:
    printf("%s", "  BLACKS, WHITES "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &B1,W1);
    /* BASIC: 990 IF B1=P9 THEN 1120 */
line_990:
    if (B1==P9) goto line_1120;
    /* BASIC: 1000 GOSUB 3000 */
line_1000:
    /* TODO: GOSUB 3000 */
    /* BASIC: 1010 FOR X=1 TO P */
line_1010:
    X = 1; for_loop_X: if ((1 >= 0 && X > P) || (1 < 0 && X < P)) goto end_for_X;
    /* BASIC: 1020 GOSUB 3500 */
line_1020:
    /* TODO: GOSUB 3500 */
    /* BASIC: 1030 IF I(X)=0 THEN 1070 */
line_1030:
    if (I(X)==0) goto line_1070;
    /* BASIC: 1035 GOSUB 6500 */
line_1035:
    /* TODO: GOSUB 6500 */
    /* BASIC: 1040 GOSUB 4000 */
line_1040:
    /* TODO: GOSUB 4000 */
    /* BASIC: 1050 GOSUB 4500 */
line_1050:
    /* TODO: GOSUB 4500 */
    /* BASIC: 1060 IF B1<>B OR W1<>W THEN I(X)=0 */
line_1060:
    if (B1!=B || W1!=W) { I(X) = 0; }
    /* BASIC: 1070 NEXT X */
line_1070:
    X += 1; goto for_loop_X; end_for_X:;
    /* BASIC: 1080 NEXT M */
line_1080:
    M += 1; goto for_loop_M; end_for_M:;
    /* BASIC: 1090 PRINT "I USED UP ALL MY MOVES!" */
line_1090:
    printf("%s", "I USED UP ALL MY MOVES!"); printf("\n");
    /* BASIC: 1100 PRINT "I GUESS MY CPU IS JUST HAVING AN OFF DAY." */
line_1100:
    printf("%s", "I GUESS MY CPU IS JUST HAVING AN OFF DAY."); printf("\n");
    /* BASIC: 1110 GOTO 1130 */
line_1110:
    goto line_1130;
    /* BASIC: 1120 PRINT "I GOT IT IN ";M;" MOVES!" */
line_1120:
    printf("%s", "I GOT IT IN "); printf("%g ", (double)(M)); printf("%s", " MOVES!"); printf("\n");
    /* BASIC: 1130 C=C+M */
line_1130:
    C = C+M;
    /* BASIC: 1140 GOSUB 5000 */
line_1140:
    /* TODO: GOSUB 5000 */
    /* BASIC: 1150 NEXT R */
line_1150:
    R += 1; goto for_loop_R; end_for_R:;
    /* BASIC: 1160 PRINT "GAME OVER" */
line_1160:
    printf("%s", "GAME OVER"); printf("\n");
    /* BASIC: 1170 PRINT "FINAL SCORE:" */
line_1170:
    printf("%s", "FINAL SCORE:"); printf("\n");
    /* BASIC: 1180 GOSUB 5040 */
line_1180:
    /* TODO: GOSUB 5040 */
    /* BASIC: 1190 STOP */
line_1190:
    exit(0);
    /* BASIC: 2000 REM */
line_2000:
    // REM
    /* BASIC: 2010 REM     BOARD PRINTOUT ROUTINE */
line_2010:
    // REM     BOARD PRINTOUT ROUTINE
    /* BASIC: 2020 REM */
line_2020:
    // REM
    /* BASIC: 2025 PRINT */
line_2025:
    printf("\n");
    /* BASIC: 2030 PRINT "BOARD" */
line_2030:
    printf("%s", "BOARD"); printf("\n");
    /* BASIC: 2040 PRINT "MOVE     GUESS          BLACK     WHITE" */
line_2040:
    printf("%s", "MOVE     GUESS          BLACK     WHITE"); printf("\n");
    /* BASIC: 2050 FOR Z=1 TO M-1 */
line_2050:
    Z = 1; for_loop_Z: if ((1 >= 0 && Z > M-1) || (1 < 0 && Z < M-1)) goto end_for_Z;
    /* BASIC: 2060 PRINT Z;TAB(9);S$(Z);TAB(25);S(Z,1);TAB(35);S(Z,2) */
line_2060:
    printf("%g ", (double)(Z)); { int _t; for(_t=0; _t<9; _t++) printf(" "); } printf("%g ", (double)(S$(Z))); { int _t; for(_t=0; _t<25; _t++) printf(" "); } printf("%g ", (double)(S(Z)); printf("\t"); printf("%g ", (double)(1))); { int _t; for(_t=0; _t<35; _t++) printf(" "); } printf("%g ", (double)(S(Z)); printf("\t"); printf("%g ", (double)(2))); printf("\n");
    /* BASIC: 2070 NEXT Z */
line_2070:
    Z += 1; goto for_loop_Z; end_for_Z:;
    /* BASIC: 2075 PRINT */
line_2075:
    printf("\n");
    /* BASIC: 2080 GOTO 380 */
line_2080:
    goto line_380;
    /* BASIC: 2500 REM */
line_2500:
    // REM
    /* BASIC: 2510 REM     QUIT ROUTINE */
line_2510:
    // REM     QUIT ROUTINE
    /* BASIC: 2520 REM */
line_2520:
    // REM
    /* BASIC: 2530 PRINT "QUITTER!  MY COMBINATION WAS: "; */
line_2530:
    printf("%s", "QUITTER!  MY COMBINATION WAS: ");
    /* BASIC: 2535 GOSUB 4000 */
line_2535:
    /* TODO: GOSUB 4000 */
    /* BASIC: 2540 FOR X=1 TO P9 */
line_2540:
    X = 1; for_loop_X: if ((1 >= 0 && X > P9) || (1 < 0 && X < P9)) goto end_for_X;
    /* BASIC: 2550 PRINT A$(X); */
line_2550:
    printf("%g ", (double)(A$(X)));
    /* BASIC: 2560 NEXT X */
line_2560:
    X += 1; goto for_loop_X; end_for_X:;
    /* BASIC: 2565 PRINT */
line_2565:
    printf("\n");
    /* BASIC: 2570 PRINT "GOOD BYE" */
line_2570:
    printf("%s", "GOOD BYE"); printf("\n");
    /* BASIC: 2580 STOP */
line_2580:
    exit(0);
    /* BASIC: 3000 REM */
line_3000:
    // REM
    /* BASIC: 3010 REM     INITIALIZE Q(1-P9) TO ZEROS */
line_3010:
    // REM     INITIALIZE Q(1-P9) TO ZEROS
    /* BASIC: 3020 REM */
line_3020:
    // REM
    /* BASIC: 3030 FOR S=1 TO P9 */
line_3030:
    S = 1; for_loop_S: if ((1 >= 0 && S > P9) || (1 < 0 && S < P9)) goto end_for_S;
    /* BASIC: 3040 Q(S)=0 */
line_3040:
    Q(S) = 0;
    /* BASIC: 3050 NEXT S */
line_3050:
    S += 1; goto for_loop_S; end_for_S:;
    /* BASIC: 3060 RETURN */
line_3060:
    /* TODO: RETURN */
    /* BASIC: 3500 REM */
line_3500:
    // REM
    /* BASIC: 3510 REM     INCREMENT Q(1-P9) */
line_3510:
    // REM     INCREMENT Q(1-P9)
    /* BASIC: 3520 REM */
line_3520:
    // REM
    /* BASIC: 3522 IF Q(1)>0 THEN 3530 */
line_3522:
    if (Q(1)>0) goto line_3530;
    /* BASIC: 3524 REM  IF ZERO, THIS IS OUR FIRST INCREMENT: MAKE ALL ONES */
line_3524:
    // REM  IF ZERO, THIS IS OUR FIRST INCREMENT
    /* UNTRANSLATED: MAKE ALL ONES */
    /* BASIC: 3526 FOR S=1 TO P9 */
line_3526:
    S = 1; for_loop_S: if ((1 >= 0 && S > P9) || (1 < 0 && S < P9)) goto end_for_S;
    /* BASIC: 3527 Q(S)=1 */
line_3527:
    Q(S) = 1;
    /* BASIC: 3528 NEXT S */
line_3528:
    S += 1; goto for_loop_S; end_for_S:;
    /* BASIC: 3529 RETURN */
line_3529:
    /* TODO: RETURN */
    /* BASIC: 3530 Q=1 */
line_3530:
    Q = 1;
    /* BASIC: 3540 Q(Q)=Q(Q)+1 */
line_3540:
    Q(Q) = Q(Q)+1;
    /* BASIC: 3550 IF Q(Q)<=C9 THEN RETURN */
line_3550:
    if (Q(Q)<==C9) { /* TODO: RETURN */ }
    /* BASIC: 3560 Q(Q)=1 */
line_3560:
    Q(Q) = 1;
    /* BASIC: 3570 Q=Q+1 */
line_3570:
    Q = Q+1;
    /* BASIC: 3580 GOTO 3540 */
line_3580:
    goto line_3540;
    /* BASIC: 4000 REM */
line_4000:
    // REM
    /* BASIC: 4010 REM     CONVERT Q(1-P9) TO A$(1-P9) */
line_4010:
    // REM     CONVERT Q(1-P9) TO A$(1-P9)
    /* BASIC: 4020 REM */
line_4020:
    // REM
    /* BASIC: 4030 FOR S=1 TO P9 */
line_4030:
    S = 1; for_loop_S: if ((1 >= 0 && S > P9) || (1 < 0 && S < P9)) goto end_for_S;
    /* BASIC: 4040 A$(S)=MID$(L$,Q(S),1) */
line_4040:
    A$(S) = MID$(L$,Q(S),1);
    /* BASIC: 4050 NEXT S */
line_4050:
    S += 1; goto for_loop_S; end_for_S:;
    /* BASIC: 4060 RETURN */
line_4060:
    /* TODO: RETURN */
    /* BASIC: 4500 REM */
line_4500:
    // REM
    /* BASIC: 4510 REM     GET NUMBER OF BLACKS (B) AND WHITES (W) */
line_4510:
    // REM     GET NUMBER OF BLACKS (B) AND WHITES (W)
    /* BASIC: 4520 REM     MASHES G$ AND A$ IN THE PROCESS */
line_4520:
    // REM     MASHES G$ AND A$ IN THE PROCESS
    /* BASIC: 4530 REM */
line_4530:
    // REM
    /* BASIC: 4540 B=0:W=0:F=0 */
line_4540:
    B = 0;
    W = 0;
    F = 0;
    /* BASIC: 4550 FOR S=1 TO P9 */
line_4550:
    S = 1; for_loop_S: if ((1 >= 0 && S > P9) || (1 < 0 && S < P9)) goto end_for_S;
    /* BASIC: 4560 IF G$(S)<>A$(S) THEN 4620 */
line_4560:
    if (G$(S)!=A$(S)) goto line_4620;
    /* BASIC: 4570 B=B+1 */
line_4570:
    B = B+1;
    /* BASIC: 4580 G$(S)=CHR$(F) */
line_4580:
    G$(S) = CHR$(F);
    /* BASIC: 4590 A$(S)=CHR$(F+1) */
line_4590:
    A$(S) = CHR$(F+1);
    /* BASIC: 4600 F=F+2 */
line_4600:
    F = F+2;
    /* BASIC: 4610 GOTO 4660 */
line_4610:
    goto line_4660;
    /* BASIC: 4620 FOR T=1 TO P9 */
line_4620:
    T = 1; for_loop_T: if ((1 >= 0 && T > P9) || (1 < 0 && T < P9)) goto end_for_T;
    /* BASIC: 4630 IF G$(S)<>A$(T) THEN 4650 */
line_4630:
    if (G$(S)!=A$(T)) goto line_4650;
    /* BASIC: 4640 IF G$(T)=A$(T) THEN 4650 */
line_4640:
    if (G$(T)==A$(T)) goto line_4650;
    /* BASIC: 4645 W=W+1:A$(T)=CHR$(F):G$(S)=CHR$(F+1):F=F+2:GOTO 4660 */
line_4645:
    W = W+1;
    A$(T) = CHR$(F);
    G$(S) = CHR$(F+1);
    F = F+2;
    goto line_4660;
    /* BASIC: 4650 NEXT T */
line_4650:
    T += 1; goto for_loop_T; end_for_T:;
    /* BASIC: 4660 NEXT S */
line_4660:
    S += 1; goto for_loop_S; end_for_S:;
    /* BASIC: 4670 RETURN */
line_4670:
    /* TODO: RETURN */
    /* BASIC: 5000 REM */
line_5000:
    // REM
    /* BASIC: 5010 REM     PRINT SCORE */
line_5010:
    // REM     PRINT SCORE
    /* BASIC: 5020 REM */
line_5020:
    // REM
    /* BASIC: 5030 PRINT "SCORE:" */
line_5030:
    printf("%s", "SCORE:"); printf("\n");
    /* BASIC: 5040 PRINT "     COMPUTER ";C */
line_5040:
    printf("%s", "     COMPUTER "); printf("%g ", (double)(C)); printf("\n");
    /* BASIC: 5050 PRINT "     HUMAN    ";H */
line_5050:
    printf("%s", "     HUMAN    "); printf("%g ", (double)(H)); printf("\n");
    /* BASIC: 5060 PRINT */
line_5060:
    printf("\n");
    /* BASIC: 5070 RETURN */
line_5070:
    /* TODO: RETURN */
    /* BASIC: 5500 REM */
line_5500:
    // REM
    /* BASIC: 5510 REM     CONVERT Q(1-P9) INTO G$(1-P9) */
line_5510:
    // REM     CONVERT Q(1-P9) INTO G$(1-P9)
    /* BASIC: 5520 REM */
line_5520:
    // REM
    /* BASIC: 5530 FOR S=1 TO P9 */
line_5530:
    S = 1; for_loop_S: if ((1 >= 0 && S > P9) || (1 < 0 && S < P9)) goto end_for_S;
    /* BASIC: 5540 G$(S)=MID$(L$,Q(S),1) */
line_5540:
    G$(S) = MID$(L$,Q(S),1);
    /* BASIC: 5550 NEXT S */
line_5550:
    S += 1; goto for_loop_S; end_for_S:;
    /* BASIC: 5560 RETURN */
line_5560:
    /* TODO: RETURN */
    /* BASIC: 6000 REM */
line_6000:
    // REM
    /* BASIC: 6010 REM     CONVERT Q(1-P9) TO H$(1-P9) */
line_6010:
    // REM     CONVERT Q(1-P9) TO H$(1-P9)
    /* BASIC: 6020 REM */
line_6020:
    // REM
    /* BASIC: 6030 FOR S=1 TO P9 */
line_6030:
    S = 1; for_loop_S: if ((1 >= 0 && S > P9) || (1 < 0 && S < P9)) goto end_for_S;
    /* BASIC: 6040 H$(S)=MID$(L$,Q(S),1) */
line_6040:
    H$(S) = MID$(L$,Q(S),1);
    /* BASIC: 6050 NEXT S */
line_6050:
    S += 1; goto for_loop_S; end_for_S:;
    /* BASIC: 6060 RETURN */
line_6060:
    /* TODO: RETURN */
    /* BASIC: 6500 REM */
line_6500:
    // REM
    /* BASIC: 6510 REM     COPY H$ INTO G$ */
line_6510:
    // REM     COPY H$ INTO G$
    /* BASIC: 6520 REM */
line_6520:
    // REM
    /* BASIC: 6530 FOR S=1 TO P9 */
line_6530:
    S = 1; for_loop_S: if ((1 >= 0 && S > P9) || (1 < 0 && S < P9)) goto end_for_S;
    /* BASIC: 6540 G$(S)=H$(S) */
line_6540:
    G$(S) = H$(S);
    /* BASIC: 6550 NEXT S */
line_6550:
    S += 1; goto for_loop_S; end_for_S:;
    /* BASIC: 6560 RETURN */
line_6560:
    /* TODO: RETURN */
    /* BASIC: 8000 REM     PROGRAM DATA FOR COLOR NAMES */
line_8000:
    // REM     PROGRAM DATA FOR COLOR NAMES
    /* BASIC: 8010 DATA BLACK,WHITE,RED,GREEN,ORANGE,YELLOW,PURPLE,TAN */
line_8010:
    /* UNTRANSLATED: DATA BLACK,WHITE,RED,GREEN,ORANGE,YELLOW,PURPLE,TAN */
    /* BASIC: 9998 REM   ...WE'RE SORRY BUT IT'S TIME TO GO... */
line_9998:
    // REM   ...WE'RE SORRY BUT IT'S TIME TO GO...
    /* BASIC: 9999 END */
line_9999:
    exit(0);

    return 0;
}
