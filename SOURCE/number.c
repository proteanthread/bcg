/*
 * Transpiled from number.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double NUMBER, DEF, FROM, DEPENDING, GUESSING, BY, GAIN, MORRISTOWN, P, HOW, POINT, NEW, DOUBLE, SELECTED, UPON, CAN, WHICH, S, OCCASIONALLY, WILL, COMPUTING, CREATIVE, JERSEY, THE, GET, JACKPOT, WIN, FNR, COMPUTER, HIT, YOU, LOSE, GUESS, X, A, POINTS, CLOSE, WHEN, U, V, NUMBERS, WITH, R, RANDOM, T, G, HAVE, YOUR, COUNT;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 1 PRINT TAB(33);"NUMBER" */
line_1:
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "NUMBER"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT:PRINT:PRINT */
line_3:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 4 PRINT "YOU HAVE 100 POINTS.  BY GUESSING NUMBERS FROM 1 TO 5, YOU" */
line_4:
    printf("%s", "YOU HAVE 100 POINTS.  BY GUESSING NUMBERS FROM 1 TO 5, YOU"); printf("\n");
    /* BASIC: 5 PRINT "CAN GAIN OR LOSE POINTS DEPENDING UPON HOW CLOSE YOU GET TO" */
line_5:
    printf("%s", "CAN GAIN OR LOSE POINTS DEPENDING UPON HOW CLOSE YOU GET TO"); printf("\n");
    /* BASIC: 6 PRINT "A RANDOM NUMBER SELECTED BY THE COMPUTER.": PRINT */
line_6:
    printf("%s", "A RANDOM NUMBER SELECTED BY THE COMPUTER."); printf("\n");
    printf("\n");
    /* BASIC: 7 PRINT "YOU OCCASIONALLY WILL GET A JACKPOT WHICH WILL DOUBLE(!)" */
line_7:
    printf("%s", "YOU OCCASIONALLY WILL GET A JACKPOT WHICH WILL DOUBLE(!)"); printf("\n");
    /* BASIC: 8 PRINT "YOUR POINT COUNT.  YOU WIN WHEN YOU GET 500 POINTS." */
line_8:
    printf("%s", "YOUR POINT COUNT.  YOU WIN WHEN YOU GET 500 POINTS."); printf("\n");
    /* BASIC: 9 PRINT: P=100 */
line_9:
    printf("\n");
    P = 100;
    /* BASIC: 10 DEF FNR(X)=INT(5*RND(1)+1) */
line_10:
    /* UNTRANSLATED: DEF FNR(X)=INT(5*RND(1)+1) */
    /* BASIC: 12 INPUT "GUESS A NUMBER FROM 1 TO 5";G */
line_12:
    printf("%s", "GUESS A NUMBER FROM 1 TO 5"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &G);
    /* BASIC: 15 R=FNR(1) */
line_15:
    R = FNR(1);
    /* BASIC: 16 S=FNR(1) */
line_16:
    S = FNR(1);
    /* BASIC: 17 T=FNR(1) */
line_17:
    T = FNR(1);
    /* BASIC: 18 U=FNR(1) */
line_18:
    U = FNR(1);
    /* BASIC: 19 V=FNR(1) */
line_19:
    V = FNR(1);
    /* BASIC: 20 IF G=R THEN 30 */
line_20:
    if (G==R) goto line_30;
    /* BASIC: 21 IF G=S THEN 40 */
line_21:
    if (G==S) goto line_40;
    /* BASIC: 22 IF G=T THEN 50 */
line_22:
    if (G==T) goto line_50;
    /* BASIC: 23 IF G=U THEN 60 */
line_23:
    if (G==U) goto line_60;
    /* BASIC: 24 IF G=V THEN 70 */
line_24:
    if (G==V) goto line_70;
    /* BASIC: 25 IF G>5 THEN 12 */
line_25:
    if (G>5) goto line_12;
    /* BASIC: 30 P=P-5 */
line_30:
    P = P-5;
    /* BASIC: 35 GOTO 80 */
line_35:
    goto line_80;
    /* BASIC: 40 P=P+5 */
line_40:
    P = P+5;
    /* BASIC: 45 GOTO 80 */
line_45:
    goto line_80;
    /* BASIC: 50 P=P+P */
line_50:
    P = P+P;
    /* BASIC: 53 PRINT "YOU HIT THE JACKPOT!!!" */
line_53:
    printf("%s", "YOU HIT THE JACKPOT!!!"); printf("\n");
    /* BASIC: 55 GOTO 80 */
line_55:
    goto line_80;
    /* BASIC: 60 P=P+1 */
line_60:
    P = P+1;
    /* BASIC: 65 GOTO 80 */
line_65:
    goto line_80;
    /* BASIC: 70 P=P-(P*.5) */
line_70:
    P = P-(P*.5);
    /* BASIC: 80 IF P>500 THEN 90 */
line_80:
    if (P>500) goto line_90;
    /* BASIC: 82 PRINT "YOU HAVE";P;"POINTS.":PRINT */
line_82:
    printf("%s", "YOU HAVE"); printf("%g ", (double)(P)); printf("%s", "POINTS."); printf("\n");
    printf("\n");
    /* BASIC: 85 GOTO 12 */
line_85:
    goto line_12;
    /* BASIC: 90 PRINT "!!!!YOU WIN!!!! WITH ";P;"POINTS." */
line_90:
    printf("%s", "!!!!YOU WIN!!!! WITH "); printf("%g ", (double)(P)); printf("%s", "POINTS."); printf("\n");
    /* BASIC: 99 END */
line_99:
    exit(0);

    return 0;
}
