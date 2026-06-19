/*
 * Transpiled from stars.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double NUMBER, MEANS, AM, ABS, FROM, GUESSES, ARE, M, GUESSING, MORE, MORRISTOWN, NEW, TYPE, K, OF, INSTRUCTIONS, START, SORRY, S, OK, WAS, WILL, COMPUTING, CREATIVE, JERSEY, THE, GET, PLAY, MY, AWAY, YOU, TRY, GUESS, LEFT, X, A, WHOLE, CLOSE, D, IT, ONE, STAR, REALLY, WANT, DO, AGAIN, THAT, AFTER, STARS, CLOSER, G, LET, N, SEVEN, FAR, I, YOUR, IN, THINKING, GOT;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 10 PRINT TAB(34);"STARS" */
line_10:
    { int _t; for(_t=0; _t<34; _t++) printf(" "); } printf("%s", "STARS"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 100 REM *** STARS - PEOPLE'S COMPUTER CENTER, MENLO PARK, CA */
line_100:
    // REM *** STARS - PEOPLE'S COMPUTER CENTER, MENLO PARK, CA
    /* BASIC: 140 REM *** A IS LIMIT ON NUMBER, M IS NUMBER OF GUESSES */
line_140:
    // REM *** A IS LIMIT ON NUMBER, M IS NUMBER OF GUESSES
    /* BASIC: 150 A=100:M=7 */
line_150:
    A = 100;
    M = 7;
    /* BASIC: 170 INPUT "DO YOU WANT INSTRUCTIONS";A$ */
line_170:
    printf("%s", "DO YOU WANT INSTRUCTIONS"); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    /* BASIC: 190 IF LEFT$(A$,1)="N" THEN 280 */
line_190:
    if (LEFT$(A$,1)=="N") goto line_280;
    /* BASIC: 200 REM *** INSTRUCTIONS ON HOW TO PLAY */
line_200:
    // REM *** INSTRUCTIONS ON HOW TO PLAY
    /* BASIC: 210 PRINT "I AM THINKING OF A WHOLE NUMBER FROM 1 TO";A */
line_210:
    printf("%s", "I AM THINKING OF A WHOLE NUMBER FROM 1 TO"); printf("%g ", (double)(A)); printf("\n");
    /* BASIC: 220 PRINT "TRY TO GUESS MY NUMBER.  AFTER YOU GUESS, I" */
line_220:
    printf("%s", "TRY TO GUESS MY NUMBER.  AFTER YOU GUESS, I"); printf("\n");
    /* BASIC: 230 PRINT "WILL TYPE ONE OR MORE STARS (*).  THE MORE" */
line_230:
    printf("%s", "WILL TYPE ONE OR MORE STARS (*).  THE MORE"); printf("\n");
    /* BASIC: 240 PRINT "STARS I TYPE, THE CLOSER YOU ARE TO MY NUMBER." */
line_240:
    printf("%s", "STARS I TYPE, THE CLOSER YOU ARE TO MY NUMBER."); printf("\n");
    /* BASIC: 250 PRINT "ONE STAR (*) MEANS FAR AWAY, SEVEN STARS (*******)" */
line_250:
    printf("%s", "ONE STAR (*) MEANS FAR AWAY, SEVEN STARS (*******)"); printf("\n");
    /* BASIC: 260 PRINT "MEANS REALLY CLOSE!  YOU GET";M;"GUESSES." */
line_260:
    printf("%s", "MEANS REALLY CLOSE!  YOU GET"); printf("%g ", (double)(M)); printf("%s", "GUESSES."); printf("\n");
    /* BASIC: 270 REM *** COMPUTER THINKS OF A NUMBER */
line_270:
    // REM *** COMPUTER THINKS OF A NUMBER
    /* BASIC: 280 PRINT */
line_280:
    printf("\n");
    /* BASIC: 290 PRINT */
line_290:
    printf("\n");
    /* BASIC: 300 X=INT(A*RND(1)+1) */
line_300:
    X = floor(A*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 310 PRINT "OK, I AM THINKING OF A NUMBER, START GUESSING." */
line_310:
    printf("%s", "OK, I AM THINKING OF A NUMBER, START GUESSING."); printf("\n");
    /* BASIC: 320 REM *** GUESSING BEGINS, HUMAN GETS M GUESSES */
line_320:
    // REM *** GUESSING BEGINS, HUMAN GETS M GUESSES
    /* BASIC: 330 FOR K=1 TO M */
line_330:
    K = 1; for_loop_K: if ((1 >= 0 && K > M) || (1 < 0 && K < M)) goto end_for_K;
    /* BASIC: 340 PRINT */
line_340:
    printf("\n");
    /* BASIC: 350 PRINT "YOUR GUESS"; */
line_350:
    printf("%s", "YOUR GUESS");
    /* BASIC: 360 INPUT G */
line_360:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &G);
    /* BASIC: 370 IF G=X THEN 600 */
line_370:
    if (G==X) goto line_600;
    /* BASIC: 380 D=ABS(G-X) */
line_380:
    D = fabs(G-X);
    /* BASIC: 390 IF D>=64 THEN 510 */
line_390:
    if (D>==64) goto line_510;
    /* BASIC: 400 IF D>=32 THEN 500 */
line_400:
    if (D>==32) goto line_500;
    /* BASIC: 410 IF D>=16 THEN 490 */
line_410:
    if (D>==16) goto line_490;
    /* BASIC: 420 IF D>=8 THEN 480 */
line_420:
    if (D>==8) goto line_480;
    /* BASIC: 430 IF D>=4 THEN 470 */
line_430:
    if (D>==4) goto line_470;
    /* BASIC: 440 IF D>=2 THEN 460 */
line_440:
    if (D>==2) goto line_460;
    /* BASIC: 450 PRINT "*"; */
line_450:
    printf("%s", "*");
    /* BASIC: 460 PRINT "*"; */
line_460:
    printf("%s", "*");
    /* BASIC: 470 PRINT "*"; */
line_470:
    printf("%s", "*");
    /* BASIC: 480 PRINT "*"; */
line_480:
    printf("%s", "*");
    /* BASIC: 490 PRINT "*"; */
line_490:
    printf("%s", "*");
    /* BASIC: 500 PRINT "*"; */
line_500:
    printf("%s", "*");
    /* BASIC: 510 PRINT "*"; */
line_510:
    printf("%s", "*");
    /* BASIC: 520 PRINT */
line_520:
    printf("\n");
    /* BASIC: 530 NEXT K */
line_530:
    K += 1; goto for_loop_K; end_for_K:;
    /* BASIC: 540 REM *** DID NOT GUESS IN M GUESSES */
line_540:
    // REM *** DID NOT GUESS IN M GUESSES
    /* BASIC: 550 PRINT */
line_550:
    printf("\n");
    /* BASIC: 560 PRINT "SORRY, THAT'S";M;"GUESSES. THE NUMBER WAS";X */
line_560:
    printf("%s", "SORRY, THAT'S"); printf("%g ", (double)(M)); printf("%s", "GUESSES. THE NUMBER WAS"); printf("%g ", (double)(X)); printf("\n");
    /* BASIC: 580 GOTO 650 */
line_580:
    goto line_650;
    /* BASIC: 590 REM *** WE HAVE A WINNER */
line_590:
    // REM *** WE HAVE A WINNER
    /* BASIC: 600 PRINT:FOR N=1 TO 79 */
line_600:
    printf("\n");
    N = 1; for_loop_N: if ((1 >= 0 && N > 79) || (1 < 0 && N < 79)) goto end_for_N;
    /* BASIC: 610 PRINT "*"; */
line_610:
    printf("%s", "*");
    /* BASIC: 620 NEXT N */
line_620:
    N += 1; goto for_loop_N; end_for_N:;
    /* BASIC: 630 PRINT:PRINT */
line_630:
    printf("\n");
    printf("\n");
    /* BASIC: 640 PRINT "YOU GOT IT IN";K;"GUESSES!!!  LET'S PLAY AGAIN..." */
line_640:
    printf("%s", "YOU GOT IT IN"); printf("%g ", (double)(K)); printf("%s", "GUESSES!!!  LET'S PLAY AGAIN..."); printf("\n");
    /* BASIC: 650 GOTO 280 */
line_650:
    goto line_280;
    /* BASIC: 660 END */
line_660:
    exit(0);

    return 0;
}
