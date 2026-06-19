/*
 * Transpiled from 23matches.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double TOSS, BYE, AROUND, NOW, GAME, GO, NEW, HA, TAILS, RE, JERSEY, THE, MEATBALL, A, WHEN, UP, IT, WON, BEAT, BOOB, NUMBER, MORRISTOWN, TAKE, OFF, GOES, TURN, PLAY, THREE, DUMMY, WANT, LET, HEADS, YOUR, I, TOOK, THERE, VERY, IS, FUNNY, K, OF, Z, LL, FLIP, OBJECT, POOR, S, WILL, CREATIVE, WIN, MY, THINK, YOU, LOSE, COMES, EARS, NOSE, ONE, LETS, LOSER, FLOPPY, LAST, GOOD, PREPARE, SMART, MAY, GOTCHA, ARE, SEE, HOW, WISH, MATCH, TWO, BLOW, COMPUTING, COIN, MATCHES, MANY, CALLED, DO, FIRST, AGAIN, GOOF, WHO, N, HAVE, THIS, Q, SHOES, PRETTY;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 20 PRINT TAB(31);"23 MATCHES" */
line_20:
    { int _t; for(_t=0; _t<31; _t++) printf(" "); } printf("%s", "23 MATCHES"); printf("\n");
    /* BASIC: 30 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_30:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 40 PRINT:PRINT:PRINT */
line_40:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 80 PRINT " THIS IS A GAME CALLED '23 MATCHES'." */
line_80:
    printf("%s", " THIS IS A GAME CALLED '23 MATCHES'."); printf("\n");
    /* BASIC: 90 PRINT */
line_90:
    printf("\n");
    /* BASIC: 100 PRINT "WHEN IT IS YOUR TURN, YOU MAY TAKE ONE, TWO, OR THREE" */
line_100:
    printf("%s", "WHEN IT IS YOUR TURN, YOU MAY TAKE ONE, TWO, OR THREE"); printf("\n");
    /* BASIC: 110 PRINT "MATCHES. THE OBJECT OF THE GAME IS NOT TO HAVE TO TAKE" */
line_110:
    printf("%s", "MATCHES. THE OBJECT OF THE GAME IS NOT TO HAVE TO TAKE"); printf("\n");
    /* BASIC: 120 PRINT "THE LAST MATCH." */
line_120:
    printf("%s", "THE LAST MATCH."); printf("\n");
    /* BASIC: 130 PRINT */
line_130:
    printf("\n");
    /* BASIC: 140 PRINT "LET'S FLIP A COIN TO SEE WHO GOES FIRST." */
line_140:
    printf("%s", "LET'S FLIP A COIN TO SEE WHO GOES FIRST."); printf("\n");
    /* BASIC: 150 PRINT "IF IT COMES UP HEADS, I WILL WIN THE TOSS." */
line_150:
    printf("%s", "IF IT COMES UP HEADS, I WILL WIN THE TOSS."); printf("\n");
    /* BASIC: 155 PRINT */
line_155:
    printf("\n");
    /* BASIC: 160 REM */
line_160:
    // REM
    /* BASIC: 165 N = 23 */
line_165:
    N = 23;
    /* BASIC: 170 Q = INT(2*RND(5)) */
line_170:
    Q = floor(2*((double)rand() / (double)RAND_MAX));
    /* BASIC: 180 IF Q = 1 THEN 210 */
line_180:
    if (Q == 1) goto line_210;
    /* BASIC: 190 PRINT "TAILS! YOU GO FIRST. " */
line_190:
    printf("%s", "TAILS! YOU GO FIRST. "); printf("\n");
    /* BASIC: 195 PRINT */
line_195:
    printf("\n");
    /* BASIC: 200 GOTO 300 */
line_200:
    goto line_300;
    /* BASIC: 210 PRINT "HEADS! I WIN! HA! HA!" */
line_210:
    printf("%s", "HEADS! I WIN! HA! HA!"); printf("\n");
    /* BASIC: 220 PRINT "PREPARE TO LOSE, MEATBALL-NOSE!!" */
line_220:
    printf("%s", "PREPARE TO LOSE, MEATBALL-NOSE!!"); printf("\n");
    /* BASIC: 230 PRINT */
line_230:
    printf("\n");
    /* BASIC: 250 PRINT "I TAKE 2 MATCHES" */
line_250:
    printf("%s", "I TAKE 2 MATCHES"); printf("\n");
    /* BASIC: 260 N = N -2 */
line_260:
    N = N -2;
    /* BASIC: 270 PRINT "THE NUMBER OF MATCHES IS NOW" N */
line_270:
    printf("%g ", (double)("THE NUMBER OF MATCHES IS NOW" N)); printf("\n");
    /* BASIC: 280 PRINT */
line_280:
    printf("\n");
    /* BASIC: 290 PRINT "YOUR TURN -- YOU MAY TAKE 1, 2 OR 3 MATCHES." */
line_290:
    printf("%s", "YOUR TURN -- YOU MAY TAKE 1, 2 OR 3 MATCHES."); printf("\n");
    /* BASIC: 300 PRINT "HOW MANY DO YOU WISH TO REMOVE", */
line_300:
    printf("%s", "HOW MANY DO YOU WISH TO REMOVE"); printf("\t");
    /* BASIC: 310 INPUT K */
line_310:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &K);
    /* BASIC: 320 IF K > 3 THEN 430 */
line_320:
    if (K > 3) goto line_430;
    /* BASIC: 330 IF K <= 0 THEN 430 */
line_330:
    if (K <== 0) goto line_430;
    /* BASIC: 340 N = N - K */
line_340:
    N = N - K;
    /* BASIC: 350 PRINT "THERE ARE NOW";N;"MATCHES REMAINING." */
line_350:
    printf("%s", "THERE ARE NOW"); printf("%g ", (double)(N)); printf("%s", "MATCHES REMAINING."); printf("\n");
    /* BASIC: 351 IF N = 4 THEN 381 */
line_351:
    if (N == 4) goto line_381;
    /* BASIC: 352 IF N = 3 THEN 383 */
line_352:
    if (N == 3) goto line_383;
    /* BASIC: 353 IF N = 2 THEN 385 */
line_353:
    if (N == 2) goto line_385;
    /* BASIC: 360 IF N <= 1 THEN  530 */
line_360:
    if (N <== 1) goto line_530;
    /* BASIC: 370 Z = 4 - K */
line_370:
    Z = 4 - K;
    /* BASIC: 372 GOTO 390 */
line_372:
    goto line_390;
    /* BASIC: 380 PRINT */
line_380:
    printf("\n");
    /* BASIC: 381 Z = 3 */
line_381:
    Z = 3;
    /* BASIC: 382 GOTO 390 */
line_382:
    goto line_390;
    /* BASIC: 383 Z = 2 */
line_383:
    Z = 2;
    /* BASIC: 384 GOTO 390 */
line_384:
    goto line_390;
    /* BASIC: 385 Z = 1 */
line_385:
    Z = 1;
    /* BASIC: 390 PRINT "MY TURN ! I REMOVE" Z "MATCHES" */
line_390:
    printf("%s", "MY TURN ! I REMOVE" Z "MATCHES"); printf("\n");
    /* BASIC: 400 N = N - Z */
line_400:
    N = N - Z;
    /* BASIC: 410 IF N <= 1 THEN 470 */
line_410:
    if (N <== 1) goto line_470;
    /* BASIC: 420 GOTO 270 */
line_420:
    goto line_270;
    /* BASIC: 430 PRINT "VERY FUNNY! DUMMY!" */
line_430:
    printf("%s", "VERY FUNNY! DUMMY!"); printf("\n");
    /* BASIC: 440 PRINT "DO YOU WANT TO PLAY OR GOOF AROUND?" */
line_440:
    printf("%s", "DO YOU WANT TO PLAY OR GOOF AROUND?"); printf("\n");
    /* BASIC: 450 PRINT "NOW, HOW MANY MATCHES DO YOU WANT", */
line_450:
    printf("%s", "NOW, HOW MANY MATCHES DO YOU WANT"); printf("\t");
    /* BASIC: 460 GOTO 310 */
line_460:
    goto line_310;
    /* BASIC: 470 PRINT */
line_470:
    printf("\n");
    /* BASIC: 480 PRINT"YOU POOR BOOB! YOU TOOK THE LAST MATCH! I GOTCHA!!" */
line_480:
    printf("%s", "YOU POOR BOOB! YOU TOOK THE LAST MATCH! I GOTCHA!!"); printf("\n");
    /* BASIC: 490 PRINT "HA ! HA ! I BEAT YOU !!!" */
line_490:
    printf("%s", "HA ! HA ! I BEAT YOU !!!"); printf("\n");
    /* BASIC: 500 PRINT */
line_500:
    printf("\n");
    /* BASIC: 510 PRINT "GOOD BYE LOSER!" */
line_510:
    printf("%s", "GOOD BYE LOSER!"); printf("\n");
    /* BASIC: 520 GOTO 560 */
line_520:
    goto line_560;
    /* BASIC: 530 PRINT "YOU WON, FLOPPY EARS !" */
line_530:
    printf("%s", "YOU WON, FLOPPY EARS !"); printf("\n");
    /* BASIC: 540 PRINT "THINK YOU'RE PRETTY SMART !" */
line_540:
    printf("%s", "THINK YOU'RE PRETTY SMART !"); printf("\n");
    /* BASIC: 550 PRINT "LETS PLAY AGAIN AND I'LL BLOW YOUR SHOES OFF !!" */
line_550:
    printf("%s", "LETS PLAY AGAIN AND I'LL BLOW YOUR SHOES OFF !!"); printf("\n");
    /* BASIC: 560 STOP */
line_560:
    exit(0);
    /* BASIC: 570 END */
line_570:
    exit(0);

    return 0;
}
