/*
 * Transpiled from rockscissors.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double NUMBER, PLAYING, MORRISTOWN, GAME, ENDED, HOW, H, IS, C, TIE, NEW, K, CHOICE, OF, PAPER, SCORE, SORRY, ROCK, S, COMPUTING, CREATIVE, JERSEY, WIN, THE, GAMES, PLAY, MY, YOU, ON, X, MANY, HERE, A, WHAT, NO, AREN, BUT, WOW, WON, WE, WINNER, FINAL, THAT, SCISSORS, T, G, INVALID, THANKS, HAVE, YOUR, I, THIS, Q, IN, ALLOWED;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 10 PRINT TAB(21);"GAME OF ROCK, SCISSORS, PAPER" */
line_10:
    { int _t; for(_t=0; _t<21; _t++) printf(" "); } printf("%s", "GAME OF ROCK, SCISSORS, PAPER"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 25 PRINT:PRINT:PRINT */
line_25:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 30 INPUT "HOW MANY GAMES";Q */
line_30:
    printf("%s", "HOW MANY GAMES"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &Q);
    /* BASIC: 40 IF Q<11 THEN 60 */
line_40:
    if (Q<11) goto line_60;
    /* BASIC: 50 PRINT "SORRY, BUT WE AREN'T ALLOWED TO PLAY THAT MANY.": GOTO 30 */
line_50:
    printf("%s", "SORRY, BUT WE AREN'T ALLOWED TO PLAY THAT MANY."); printf("\n");
    goto line_30;
    /* BASIC: 60 FOR G=1 TO Q */
line_60:
    G = 1; for_loop_G: if ((1 >= 0 && G > Q) || (1 < 0 && G < Q)) goto end_for_G;
    /* BASIC: 70 PRINT: PRINT "GAME NUMBER";G */
line_70:
    printf("\n");
    printf("%s", "GAME NUMBER"); printf("%g ", (double)(G)); printf("\n");
    /* BASIC: 80 X=INT(RND(1)*3+1) */
line_80:
    X = floor(((double)rand() / (double)RAND_MAX)*3+1);
    /* BASIC: 90 PRINT "3=ROCK...2=SCISSORS...1=PAPER" */
line_90:
    printf("%s", "3=ROCK...2=SCISSORS...1=PAPER"); printf("\n");
    /* BASIC: 100 INPUT "1...2...3...WHAT'S YOUR CHOICE";K */
line_100:
    printf("%s", "1...2...3...WHAT'S YOUR CHOICE"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &K);
    /* BASIC: 110 IF (K-1)*(K-2)*(K-3)<>0 THEN PRINT "INVALID.": GOTO 90 */
line_110:
    if ((K-1)*(K-2)*(K-3)!=0) { printf("%s", "INVALID."); printf("\n"); }
    goto line_90;
    /* BASIC: 120 PRINT "THIS IS MY CHOICE..." */
line_120:
    printf("%s", "THIS IS MY CHOICE..."); printf("\n");
    /* BASIC: 130 ON X GOTO 140,150,160 */
line_130:
    /* UNTRANSLATED: ON X GOTO 140,150,160 */
    /* BASIC: 140 PRINT "...PAPER": GOTO 170 */
line_140:
    printf("%s", "...PAPER"); printf("\n");
    goto line_170;
    /* BASIC: 150 PRINT "...SCISSORS": GOTO 170 */
line_150:
    printf("%s", "...SCISSORS"); printf("\n");
    goto line_170;
    /* BASIC: 160 PRINT "...ROCK" */
line_160:
    printf("%s", "...ROCK"); printf("\n");
    /* BASIC: 170 IF X=K THEN 250 */
line_170:
    if (X==K) goto line_250;
    /* BASIC: 180 IF X>K THEN 230 */
line_180:
    if (X>K) goto line_230;
    /* BASIC: 190 IF X=1 THEN 210 */
line_190:
    if (X==1) goto line_210;
    /* BASIC: 200 PRINT "YOU WIN!!!":H=H+1: GOTO 260 */
line_200:
    printf("%s", "YOU WIN!!!"); printf("\n");
    H = H+1;
    goto line_260;
    /* BASIC: 210 IF K<>3 THEN 200 */
line_210:
    if (K!=3) goto line_200;
    /* BASIC: 220 PRINT "WOW!  I WIN!!!":C=C+1:GOTO 260 */
line_220:
    printf("%s", "WOW!  I WIN!!!"); printf("\n");
    C = C+1;
    goto line_260;
    /* BASIC: 230 IF K<>1 OR X<>3 THEN 220 */
line_230:
    if (K!=1 || X!=3) goto line_220;
    /* BASIC: 240 GOTO 200 */
line_240:
    goto line_200;
    /* BASIC: 250 PRINT "TIE GAME.  NO WINNER." */
line_250:
    printf("%s", "TIE GAME.  NO WINNER."); printf("\n");
    /* BASIC: 260 NEXT G */
line_260:
    G += 1; goto for_loop_G; end_for_G:;
    /* BASIC: 270 PRINT: PRINT "HERE IS THE FINAL GAME SCORE:" */
line_270:
    printf("\n");
    printf("%s", "HERE IS THE FINAL GAME SCORE:"); printf("\n");
    /* BASIC: 280 PRINT "I HAVE WON";C;"GAME(S)." */
line_280:
    printf("%s", "I HAVE WON"); printf("%g ", (double)(C)); printf("%s", "GAME(S)."); printf("\n");
    /* BASIC: 290 PRINT "YOU HAVE WON";H;"GAME(S)." */
line_290:
    printf("%s", "YOU HAVE WON"); printf("%g ", (double)(H)); printf("%s", "GAME(S)."); printf("\n");
    /* BASIC: 300 PRINT "AND";Q-(C+H);"GAME(S) ENDED IN A TIE." */
line_300:
    printf("%s", "AND"); printf("%g ", (double)(Q-(C+H))); printf("%s", "GAME(S) ENDED IN A TIE."); printf("\n");
    /* BASIC: 310 PRINT: PRINT "THANKS FOR PLAYING!!" */
line_310:
    printf("\n");
    printf("%s", "THANKS FOR PLAYING!!"); printf("\n");
    /* BASIC: 320 END */
line_320:
    exit(0);

    return 0;
}
