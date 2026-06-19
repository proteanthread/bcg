/*
 * Transpiled from evenwins.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double OBJECTS, ALTERNATE, THAN, GAME, GO, TABLE, INTEGER, NEW, TYPE, TRIED, OK, JERSEY, THE, SKIP, M1, ON, LEFT, A, PERSON, WHEN, UP, WON, A1, T, NEED, NUMBER, MORRISTOWN, TAKE, PLAYER, POSITIVE, MUST, TURN, PLAY, TRY, WHAT, BETWEEN, LATER, WANT, CANNOT, ALL, YOUR, I, THERE, Y, MORE, ME, IS, OF, ONLY, CREATIVE, MY, EACH, YOU, WINS, Y1, NO, WITH, ONE, TURNS, WINNER, PICK, OTHER, AN, ENDS, ARE, BE, SEE, C, MOVE, TWO, TOTAL, COMPUTING, EVEN, CALLED, PLAYERS, AGAIN, FIRST, THAT, R, DO, YES, MARBLES, HAVE, THIS, RULES;
    double M[1000] = {0}; /* Static array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 1 PRINT TAB(31);"EVEN WINS" */
line_1:
    { int _t; for(_t=0; _t<31; _t++) printf(" "); } printf("%s", "EVEN WINS"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT:PRINT */
line_3:
    printf("\n");
    printf("\n");
    /* BASIC: 4 Y1=0 */
line_4:
    Y1 = 0;
    /* BASIC: 10 M1=0 */
line_10:
    M1 = 0;
    /* BASIC: 20 DIM M(20),Y(20) */
line_20:
    /* DIM M(20),Y(20) (handled statically) */
    /* BASIC: 30 PRINT "     THIS IS A TWO PERSON GAME CALLED 'EVEN WINS.'" */
line_30:
    printf("%s", "     THIS IS A TWO PERSON GAME CALLED 'EVEN WINS.'"); printf("\n");
    /* BASIC: 40 PRINT "TO PLAY THE GAME, THE PLAYERS NEED 27 MARBLES OR" */
line_40:
    printf("%s", "TO PLAY THE GAME, THE PLAYERS NEED 27 MARBLES OR"); printf("\n");
    /* BASIC: 50 PRINT "OTHER OBJECTS ON A TABLE." */
line_50:
    printf("%s", "OTHER OBJECTS ON A TABLE."); printf("\n");
    /* BASIC: 60 PRINT */
line_60:
    printf("\n");
    /* BASIC: 70 PRINT */
line_70:
    printf("\n");
    /* BASIC: 80 PRINT "     THE 2 PLAYERS ALTERNATE TURNS, WITH EACH PLAYER" */
line_80:
    printf("%s", "     THE 2 PLAYERS ALTERNATE TURNS, WITH EACH PLAYER"); printf("\n");
    /* BASIC: 90 PRINT "REMOVING FROM 1 TO 4 MARBLES ON EACH MOVE.  THE GAME" */
line_90:
    printf("%s", "REMOVING FROM 1 TO 4 MARBLES ON EACH MOVE.  THE GAME"); printf("\n");
    /* BASIC: 100 PRINT "ENDS WHEN THERE ARE NO MARBLES LEFT, AND THE WINNER" */
line_100:
    printf("%s", "ENDS WHEN THERE ARE NO MARBLES LEFT, AND THE WINNER"); printf("\n");
    /* BASIC: 110 PRINT "IS THE ONE WITH AN EVEN NUMBER OF MARBLES." */
line_110:
    printf("%s", "IS THE ONE WITH AN EVEN NUMBER OF MARBLES."); printf("\n");
    /* BASIC: 120 PRINT */
line_120:
    printf("\n");
    /* BASIC: 130 PRINT */
line_130:
    printf("\n");
    /* BASIC: 140 PRINT "     THE ONLY RULES ARE THAT (1) YOU MUST ALTERNATE TURNS," */
line_140:
    printf("%s", "     THE ONLY RULES ARE THAT (1) YOU MUST ALTERNATE TURNS,"); printf("\n");
    /* BASIC: 150 PRINT "(2) YOU MUST TAKE BETWEEN 1 AND 4 MARBLES EACH TURN," */
line_150:
    printf("%s", "(2) YOU MUST TAKE BETWEEN 1 AND 4 MARBLES EACH TURN,"); printf("\n");
    /* BASIC: 160 PRINT "AND (3) YOU CANNOT SKIP A TURN." */
line_160:
    printf("%s", "AND (3) YOU CANNOT SKIP A TURN."); printf("\n");
    /* BASIC: 170 PRINT */
line_170:
    printf("\n");
    /* BASIC: 180 PRINT */
line_180:
    printf("\n");
    /* BASIC: 190 PRINT */
line_190:
    printf("\n");
    /* BASIC: 200 PRINT "     TYPE A '1' IF YOU WANT TO GO FIRST, AND TYPE" */
line_200:
    printf("%s", "     TYPE A '1' IF YOU WANT TO GO FIRST, AND TYPE"); printf("\n");
    /* BASIC: 210 PRINT "A '0' IF YOU WANT ME TO GO FIRST." */
line_210:
    printf("%s", "A '0' IF YOU WANT ME TO GO FIRST."); printf("\n");
    /* BASIC: 220 INPUT C */
line_220:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &C);
    /* BASIC: 225 PRINT */
line_225:
    printf("\n");
    /* BASIC: 230 IF C=0 THEN 250 */
line_230:
    if (C==0) goto line_250;
    /* BASIC: 240 GOTO 1060 */
line_240:
    goto line_1060;
    /* BASIC: 250 T=27 */
line_250:
    T = 27;
    /* BASIC: 260 M=2 */
line_260:
    M = 2;
    /* BASIC: 270 PRINT:PRINT "TOTAL=";T:PRINT */
line_270:
    printf("\n");
    printf("%s", "TOTAL="); printf("%g ", (double)(T)); printf("\n");
    printf("\n");
    /* BASIC: 280 M1=M1+M */
line_280:
    M1 = M1+M;
    /* BASIC: 290 T=T-M */
line_290:
    T = T-M;
    /* BASIC: 300 PRINT "I PICK UP";M;"MARBLES." */
line_300:
    printf("%s", "I PICK UP"); printf("%g ", (double)(M)); printf("%s", "MARBLES."); printf("\n");
    /* BASIC: 310 IF T=0 THEN 880 */
line_310:
    if (T==0) goto line_880;
    /* BASIC: 320 PRINT:PRINT "TOTAL=";T */
line_320:
    printf("\n");
    printf("%s", "TOTAL="); printf("%g ", (double)(T)); printf("\n");
    /* BASIC: 330 PRINT */
line_330:
    printf("\n");
    /* BASIC: 340 PRINT "     AND WHAT IS YOUR NEXT MOVE, MY TOTAL IS";M1 */
line_340:
    printf("%s", "     AND WHAT IS YOUR NEXT MOVE, MY TOTAL IS"); printf("%g ", (double)(M1)); printf("\n");
    /* BASIC: 350 INPUT Y */
line_350:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &Y);
    /* BASIC: 360 PRINT */
line_360:
    printf("\n");
    /* BASIC: 370 IF Y<1 THEN 1160 */
line_370:
    if (Y<1) goto line_1160;
    /* BASIC: 380 IF Y>4 THEN 1160 */
line_380:
    if (Y>4) goto line_1160;
    /* BASIC: 390 IF Y<=T THEN 430 */
line_390:
    if (Y<==T) goto line_430;
    /* BASIC: 400 PRINT "     YOU HAVE TRIED TO TAKE MORE MARBLES THAN THERE ARE" */
line_400:
    printf("%s", "     YOU HAVE TRIED TO TAKE MORE MARBLES THAN THERE ARE"); printf("\n");
    /* BASIC: 410 PRINT "LEFT.  TRY AGAIN." */
line_410:
    printf("%s", "LEFT.  TRY AGAIN."); printf("\n");
    /* BASIC: 420 GOTO 350 */
line_420:
    goto line_350;
    /* BASIC: 430 Y1=Y1+Y */
line_430:
    Y1 = Y1+Y;
    /* BASIC: 440 T=T-Y */
line_440:
    T = T-Y;
    /* BASIC: 450 IF T=0 THEN 880 */
line_450:
    if (T==0) goto line_880;
    /* BASIC: 460 PRINT "TOTAL=";T */
line_460:
    printf("%s", "TOTAL="); printf("%g ", (double)(T)); printf("\n");
    /* BASIC: 470 PRINT */
line_470:
    printf("\n");
    /* BASIC: 480 PRINT "YOUR TOTAL IS";Y1 */
line_480:
    printf("%s", "YOUR TOTAL IS"); printf("%g ", (double)(Y1)); printf("\n");
    /* BASIC: 490 IF T<.5 THEN 880 */
line_490:
    if (T<.5) goto line_880;
    /* BASIC: 500 R=T-6*INT(T/6) */
line_500:
    R = T-6*floor(T/6);
    /* BASIC: 510 IF INT(Y1/2)=Y1/2 THEN 700 */
line_510:
    if (floor(Y1/2)==Y1/2) goto line_700;
    /* BASIC: 520 IF T<4.2 THEN 580 */
line_520:
    if (T<4.2) goto line_580;
    /* BASIC: 530 IF R>3.4 THEN 620 */
line_530:
    if (R>3.4) goto line_620;
    /* BASIC: 540 M=R+1 */
line_540:
    M = R+1;
    /* BASIC: 550 M1=M1+M */
line_550:
    M1 = M1+M;
    /* BASIC: 560 T=T-M */
line_560:
    T = T-M;
    /* BASIC: 570 GOTO 300 */
line_570:
    goto line_300;
    /* BASIC: 580 M=T */
line_580:
    M = T;
    /* BASIC: 590 T=T-M */
line_590:
    T = T-M;
    /* BASIC: 600 GOTO 830 */
line_600:
    goto line_830;
    /* BASIC: 610 REM     250 IS WHERE I WIN. */
line_610:
    // REM     250 IS WHERE I WIN.
    /* BASIC: 620 IF R<4.7 THEN 660 */
line_620:
    if (R<4.7) goto line_660;
    /* BASIC: 630 IF R>3.5 THEN 660 */
line_630:
    if (R>3.5) goto line_660;
    /* BASIC: 640 M=1 */
line_640:
    M = 1;
    /* BASIC: 650 GOTO 670 */
line_650:
    goto line_670;
    /* BASIC: 660 M=4 */
line_660:
    M = 4;
    /* BASIC: 670 T=T-M */
line_670:
    T = T-M;
    /* BASIC: 680 M1=M1+M */
line_680:
    M1 = M1+M;
    /* BASIC: 690 GOTO 300 */
line_690:
    goto line_300;
    /* BASIC: 700 REM     I AM READY TO ENCODE THE STRAT FOR WHEN OPP TOT IS EVEN */
line_700:
    // REM     I AM READY TO ENCODE THE STRAT FOR WHEN OPP TOT IS EVEN
    /* BASIC: 710 IF R<1.5 THEN 1020 */
line_710:
    if (R<1.5) goto line_1020;
    /* BASIC: 720 IF R>5.3 THEN 1020 */
line_720:
    if (R>5.3) goto line_1020;
    /* BASIC: 730 M=R-1 */
line_730:
    M = R-1;
    /* BASIC: 740 M1=M1+M */
line_740:
    M1 = M1+M;
    /* BASIC: 750 T=T-M */
line_750:
    T = T-M;
    /* BASIC: 760 IF T<.2 THEN 790 */
line_760:
    if (T<.2) goto line_790;
    /* BASIC: 770 REM     IS # ZERO HERE */
line_770:
    // REM     IS # ZERO HERE
    /* BASIC: 780 GOTO 300 */
line_780:
    goto line_300;
    /* BASIC: 790 REM     IS = ZERO HERE */
line_790:
    // REM     IS = ZERO HERE
    /* BASIC: 800 PRINT "I PICK UP";M;"MARBLES." */
line_800:
    printf("%s", "I PICK UP"); printf("%g ", (double)(M)); printf("%s", "MARBLES."); printf("\n");
    /* BASIC: 810 PRINT */
line_810:
    printf("\n");
    /* BASIC: 820 GOTO 880 */
line_820:
    goto line_880;
    /* BASIC: 830 REM    THIS IS WHERE I WIN */
line_830:
    // REM    THIS IS WHERE I WIN
    /* BASIC: 840 PRINT "I PICK UP";M;"MARBLES." */
line_840:
    printf("%s", "I PICK UP"); printf("%g ", (double)(M)); printf("%s", "MARBLES."); printf("\n");
    /* BASIC: 850 PRINT */
line_850:
    printf("\n");
    /* BASIC: 860 PRINT "TOTAL = 0" */
line_860:
    printf("%s", "TOTAL = 0"); printf("\n");
    /* BASIC: 870 M1=M1+M */
line_870:
    M1 = M1+M;
    /* BASIC: 880 PRINT "THAT IS ALL OF THE MARBLES." */
line_880:
    printf("%s", "THAT IS ALL OF THE MARBLES."); printf("\n");
    /* BASIC: 890 PRINT */
line_890:
    printf("\n");
    /* BASIC: 900 PRINT " MY TOTAL IS";M1;", YOUR TOTAL IS";Y1 */
line_900:
    printf("%s", " MY TOTAL IS"); printf("%g ", (double)(M1)); printf("%s", ", YOUR TOTAL IS"); printf("%g ", (double)(Y1)); printf("\n");
    /* BASIC: 910 PRINT */
line_910:
    printf("\n");
    /* BASIC: 920 IF INT(M1/2)=M1/2 THEN 950 */
line_920:
    if (floor(M1/2)==M1/2) goto line_950;
    /* BASIC: 930 PRINT "     YOU WON.  DO YOU WANT TO PLAY" */
line_930:
    printf("%s", "     YOU WON.  DO YOU WANT TO PLAY"); printf("\n");
    /* BASIC: 940 GOTO 960 */
line_940:
    goto line_960;
    /* BASIC: 950 PRINT "     I WON.  DO YOU WANT TO PLAY" */
line_950:
    printf("%s", "     I WON.  DO YOU WANT TO PLAY"); printf("\n");
    /* BASIC: 960 PRINT "AGAIN?  TYPE 1 FOR YES AND 0 FOR NO." */
line_960:
    printf("%s", "AGAIN?  TYPE 1 FOR YES AND 0 FOR NO."); printf("\n");
    /* BASIC: 970 INPUT A1 */
line_970:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &A1);
    /* BASIC: 980 IF A1=0 THEN 1030 */
line_980:
    if (A1==0) goto line_1030;
    /* BASIC: 990 M1=0 */
line_990:
    M1 = 0;
    /* BASIC: 1000 Y1=0 */
line_1000:
    Y1 = 0;
    /* BASIC: 1010 GOTO 200 */
line_1010:
    goto line_200;
    /* BASIC: 1020 GOTO 640 */
line_1020:
    goto line_640;
    /* BASIC: 1030 PRINT */
line_1030:
    printf("\n");
    /* BASIC: 1040 PRINT "OK.  SEE YOU LATER." */
line_1040:
    printf("%s", "OK.  SEE YOU LATER."); printf("\n");
    /* BASIC: 1050 GOTO 1230 */
line_1050:
    goto line_1230;
    /* BASIC: 1060 T=27 */
line_1060:
    T = 27;
    /* BASIC: 1070 PRINT */
line_1070:
    printf("\n");
    /* BASIC: 1080 PRINT */
line_1080:
    printf("\n");
    /* BASIC: 1090 PRINT */
line_1090:
    printf("\n");
    /* BASIC: 1100 PRINT "TOTAL=";T */
line_1100:
    printf("%s", "TOTAL="); printf("%g ", (double)(T)); printf("\n");
    /* BASIC: 1110 PRINT */
line_1110:
    printf("\n");
    /* BASIC: 1120 PRINT */
line_1120:
    printf("\n");
    /* BASIC: 1130 PRINT "WHAT IS YOUR FIRST MOVE"; */
line_1130:
    printf("%s", "WHAT IS YOUR FIRST MOVE");
    /* BASIC: 1140 INPUT Y */
line_1140:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &Y);
    /* BASIC: 1150 GOTO 360 */
line_1150:
    goto line_360;
    /* BASIC: 1160 PRINT */
line_1160:
    printf("\n");
    /* BASIC: 1170 PRINT "THE NUMBER OF MARBLES YOU TAKE MUST BE A POSITIVE" */
line_1170:
    printf("%s", "THE NUMBER OF MARBLES YOU TAKE MUST BE A POSITIVE"); printf("\n");
    /* BASIC: 1180 PRINT "INTEGER BETWEEN 1 AND 4." */
line_1180:
    printf("%s", "INTEGER BETWEEN 1 AND 4."); printf("\n");
    /* BASIC: 1190 PRINT */
line_1190:
    printf("\n");
    /* BASIC: 1200 PRINT "     WHAT IS YOUR NEXT MOVE?" */
line_1200:
    printf("%s", "     WHAT IS YOUR NEXT MOVE?"); printf("\n");
    /* BASIC: 1210 PRINT */
line_1210:
    printf("\n");
    /* BASIC: 1220 GOTO 350 */
line_1220:
    goto line_350;
    /* BASIC: 1230 END */
line_1230:
    exit(0);

    return 0;
}
