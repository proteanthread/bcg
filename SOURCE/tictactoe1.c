/*
 * Transpiled from tictactoe1.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double DEF, M, MORRISTOWN, P, GAME, B, MOVES, C, IS, NEW, MOVE, TOE, BOARD, S, COMPUTING, CREATIVE, JERSEY, THE, E, COMPUTER, X, WINS, A, FNM, D, DRAW, R, NUMBERED, TAC, YOUR, Q, TIC;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 10 PRINT TAB(30);"TIC TAC TOE" */
line_10:
    { int _t; for(_t=0; _t<30; _t++) printf(" "); } printf("%s", "TIC TAC TOE"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 50 REM */
line_50:
    // REM
    /* BASIC: 100 REM   THIS PROGRAM PLAYS TIC TAC TOE */
line_100:
    // REM   THIS PROGRAM PLAYS TIC TAC TOE
    /* BASIC: 110 REM   THE MACHINE GOES FIRST */
line_110:
    // REM   THE MACHINE GOES FIRST
    /* BASIC: 120 PRINT "THE GAME BOARD IS NUMBERED:": PRINT */
line_120:
    printf("%s", "THE GAME BOARD IS NUMBERED:"); printf("\n");
    printf("\n");
    /* BASIC: 130 PRINT "1  2  3": PRINT "8  9  4": PRINT "7  6  5" */
line_130:
    printf("%s", "1  2  3"); printf("\n");
    printf("%s", "8  9  4"); printf("\n");
    printf("%s", "7  6  5"); printf("\n");
    /* BASIC: 140 PRINT */
line_140:
    printf("\n");
    /* BASIC: 150 REM */
line_150:
    // REM
    /* BASIC: 160 REM */
line_160:
    // REM
    /* BASIC: 170 REM */
line_170:
    // REM
    /* BASIC: 180 DEF FNM(X)=X-8*INT((X-1)/8) */
line_180:
    /* UNTRANSLATED: DEF FNM(X)=X-8*INT((X-1)/8) */
    /* BASIC: 190 REM */
line_190:
    // REM
    /* BASIC: 200 REM  MAIN PROGRAM */
line_200:
    // REM  MAIN PROGRAM
    /* BASIC: 210 PRINT */
line_210:
    printf("\n");
    /* BASIC: 220 PRINT */
line_220:
    printf("\n");
    /* BASIC: 230 A=9 */
line_230:
    A = 9;
    /* BASIC: 240 M=A */
line_240:
    M = A;
    /* BASIC: 250 GOSUB 650 */
line_250:
    /* TODO: GOSUB 650 */
    /* BASIC: 260 P=M */
line_260:
    P = M;
    /* BASIC: 270 B=FNM(P+1) */
line_270:
    B = FNM(P+1);
    /* BASIC: 280 M=B */
line_280:
    M = B;
    /* BASIC: 290 GOSUB 650 */
line_290:
    /* TODO: GOSUB 650 */
    /* BASIC: 300 Q=M */
line_300:
    Q = M;
    /* BASIC: 310 IF Q=FNM(B+4) THEN 360 */
line_310:
    if (Q==FNM(B+4)) goto line_360;
    /* BASIC: 320 C=FNM(B+4) */
line_320:
    C = FNM(B+4);
    /* BASIC: 330 M=C */
line_330:
    M = C;
    /* BASIC: 340 GOSUB 700 */
line_340:
    /* TODO: GOSUB 700 */
    /* BASIC: 350 GOTO 730 */
line_350:
    goto line_730;
    /* BASIC: 360 C=FNM(B+2) */
line_360:
    C = FNM(B+2);
    /* BASIC: 370 M=C */
line_370:
    M = C;
    /* BASIC: 380 GOSUB 650 */
line_380:
    /* TODO: GOSUB 650 */
    /* BASIC: 390 R=M */
line_390:
    R = M;
    /* BASIC: 400 IF R=FNM(C+4) THEN 450 */
line_400:
    if (R==FNM(C+4)) goto line_450;
    /* BASIC: 410 D=FNM(C+4) */
line_410:
    D = FNM(C+4);
    /* BASIC: 420 M=D */
line_420:
    M = D;
    /* BASIC: 430 GOSUB 700 */
line_430:
    /* TODO: GOSUB 700 */
    /* BASIC: 440 GOTO 730 */
line_440:
    goto line_730;
    /* BASIC: 450 IF P/2<>INT(P/2) THEN 500 */
line_450:
    if (P/2!=floor(P/2)) goto line_500;
    /* BASIC: 460 D=FNM(C+7) */
line_460:
    D = FNM(C+7);
    /* BASIC: 470 M=D */
line_470:
    M = D;
    /* BASIC: 480 GOSUB 700 */
line_480:
    /* TODO: GOSUB 700 */
    /* BASIC: 490 GOTO 730 */
line_490:
    goto line_730;
    /* BASIC: 500 D=FNM(C+3) */
line_500:
    D = FNM(C+3);
    /* BASIC: 510 M=D */
line_510:
    M = D;
    /* BASIC: 520 GOSUB 650 */
line_520:
    /* TODO: GOSUB 650 */
    /* BASIC: 530 S=M */
line_530:
    S = M;
    /* BASIC: 540 IF S=FNM(D+4) THEN 590 */
line_540:
    if (S==FNM(D+4)) goto line_590;
    /* BASIC: 550 E=FNM(D+4) */
line_550:
    E = FNM(D+4);
    /* BASIC: 560 M=E */
line_560:
    M = E;
    /* BASIC: 570 GOSUB 700 */
line_570:
    /* TODO: GOSUB 700 */
    /* BASIC: 580 REM */
line_580:
    // REM
    /* BASIC: 590 E=FNM(D+6) */
line_590:
    E = FNM(D+6);
    /* BASIC: 600 M=E */
line_600:
    M = E;
    /* BASIC: 610 GOSUB 700 */
line_610:
    /* TODO: GOSUB 700 */
    /* BASIC: 620 PRINT "THE GAME IS A DRAW." */
line_620:
    printf("%s", "THE GAME IS A DRAW."); printf("\n");
    /* BASIC: 630 GOTO 210 */
line_630:
    goto line_210;
    /* BASIC: 640 REM */
line_640:
    // REM
    /* BASIC: 650 GOSUB 700 */
line_650:
    /* TODO: GOSUB 700 */
    /* BASIC: 660 PRINT "YOUR MOVE"; */
line_660:
    printf("%s", "YOUR MOVE");
    /* BASIC: 670 INPUT M */
line_670:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &M);
    /* BASIC: 680 RETURN */
line_680:
    /* TODO: RETURN */
    /* BASIC: 700 PRINT "COMPUTER MOVES";M */
line_700:
    printf("%s", "COMPUTER MOVES"); printf("%g ", (double)(M)); printf("\n");
    /* BASIC: 710 RETURN */
line_710:
    /* TODO: RETURN */
    /* BASIC: 720 REM */
line_720:
    // REM
    /* BASIC: 730 PRINT "AND WINS ********" */
line_730:
    printf("%s", "AND WINS ********"); printf("\n");
    /* BASIC: 740 GOTO 210 */
line_740:
    goto line_210;
    /* BASIC: 750 END */
line_750:
    exit(0);

    return 0;
}
