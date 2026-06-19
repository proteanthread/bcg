/*
 * Transpiled from hi-lo.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double NUMBER, ENDS, Y, ARE, MORE, NOW, MORRISTOWN, GAME, B, AMOUNT, IS, BLEW, NEW, LOW, DOLLARS, LONG, OF, SO, TOTAL, HOWEVER, WHICH, WAS, YOURSELF, WILL, COMPUTING, CREATIVE, JERSEY, MONEY, THE, JACKPOT, WIN, GET, PLAY, YOU, WINNINGS, GUESS, A, CHANCE, BAD, HOPE, NO, BETWEEN, IT, HI, ENJOYED, LO, ANOTHER, DO, HIGH, R, AGAIN, YES, TOO, TRIES, ALL, HAVE, YOUR, THIS, IN, GOT;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 10 PRINT TAB(34);"HI LO" */
line_10:
    { int _t; for(_t=0; _t<34; _t++) printf(" "); } printf("%s", "HI LO"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 100 PRINT "THIS IS THE GAME OF HI LO.":PRINT */
line_100:
    printf("%s", "THIS IS THE GAME OF HI LO."); printf("\n");
    printf("\n");
    /* BASIC: 110 PRINT "YOU WILL HAVE 6 TRIES TO GUESS THE AMOUNT OF MONEY IN THE" */
line_110:
    printf("%s", "YOU WILL HAVE 6 TRIES TO GUESS THE AMOUNT OF MONEY IN THE"); printf("\n");
    /* BASIC: 120 PRINT "HI LO JACKPOT, WHICH IS BETWEEN 1 AND 100 DOLLARS.  IF YOU" */
line_120:
    printf("%s", "HI LO JACKPOT, WHICH IS BETWEEN 1 AND 100 DOLLARS.  IF YOU"); printf("\n");
    /* BASIC: 130 PRINT "GUESS THE AMOUNT, YOU WIN ALL THE MONEY IN THE JACKPOT!" */
line_130:
    printf("%s", "GUESS THE AMOUNT, YOU WIN ALL THE MONEY IN THE JACKPOT!"); printf("\n");
    /* BASIC: 140 PRINT "THEN YOU GET ANOTHER CHANCE TO WIN MORE MONEY.  HOWEVER," */
line_140:
    printf("%s", "THEN YOU GET ANOTHER CHANCE TO WIN MORE MONEY.  HOWEVER,"); printf("\n");
    /* BASIC: 150 PRINT "IF YOU DO NOT GUESS THE AMOUNT, THE GAME ENDS.":PRINT */
line_150:
    printf("%s", "IF YOU DO NOT GUESS THE AMOUNT, THE GAME ENDS."); printf("\n");
    printf("\n");
    /* BASIC: 160 R=0 */
line_160:
    R = 0;
    /* BASIC: 170 B=0:PRINT */
line_170:
    B = 0;
    printf("\n");
    /* BASIC: 180 Y=INT(100*RND(1)) */
line_180:
    Y = floor(100*((double)rand() / (double)RAND_MAX));
    /* BASIC: 200 PRINT "YOUR GUESS"; */
line_200:
    printf("%s", "YOUR GUESS");
    /* BASIC: 210 INPUT A */
line_210:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &A);
    /* BASIC: 220 B=B+1 */
line_220:
    B = B+1;
    /* BASIC: 230 IF A=Y THEN 300 */
line_230:
    if (A==Y) goto line_300;
    /* BASIC: 240 IF A>Y THEN 270 */
line_240:
    if (A>Y) goto line_270;
    /* BASIC: 250 PRINT "YOUR GUESS IS TOO LOW.":GOTO 280 */
line_250:
    printf("%s", "YOUR GUESS IS TOO LOW."); printf("\n");
    goto line_280;
    /* BASIC: 270 PRINT "YOUR GUESS IS TOO HIGH." */
line_270:
    printf("%s", "YOUR GUESS IS TOO HIGH."); printf("\n");
    /* BASIC: 280 PRINT:IF B<6 THEN 200 */
line_280:
    printf("\n");
    if (B<6) goto line_200;
    /* BASIC: 290 PRINT "YOU BLEW IT...TOO BAD...THE NUMBER WAS";Y */
line_290:
    printf("%s", "YOU BLEW IT...TOO BAD...THE NUMBER WAS"); printf("%g ", (double)(Y)); printf("\n");
    /* BASIC: 295 R=0:GOTO 350 */
line_295:
    R = 0;
    goto line_350;
    /* BASIC: 300 PRINT "GOT IT!!!!!!!!!!   YOU WIN";Y;"DOLLARS." */
line_300:
    printf("%s", "GOT IT!!!!!!!!!!   YOU WIN"); printf("%g ", (double)(Y)); printf("%s", "DOLLARS."); printf("\n");
    /* BASIC: 310 R=R+Y */
line_310:
    R = R+Y;
    /* BASIC: 320 PRINT "YOUR TOTAL WINNINGS ARE NOW";R;"DOLLARS." */
line_320:
    printf("%s", "YOUR TOTAL WINNINGS ARE NOW"); printf("%g ", (double)(R)); printf("%s", "DOLLARS."); printf("\n");
    /* BASIC: 350 PRINT:PRINT "PLAY AGAIN (YES OR NO)"; */
line_350:
    printf("\n");
    printf("%s", "PLAY AGAIN (YES OR NO)");
    /* BASIC: 360 INPUT A$:IF A$="YES" THEN 170 */
line_360:
    printf("? "); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    if (A$=="YES") goto line_170;
    /* BASIC: 380 PRINT:PRINT "SO LONG.  HOPE YOU ENJOYED YOURSELF!!!" */
line_380:
    printf("\n");
    printf("%s", "SO LONG.  HOPE YOU ENJOYED YOURSELF!!!"); printf("\n");
    /* BASIC: 390 END */
line_390:
    exit(0);

    return 0;
}
