/*
 * Transpiled from hurkle.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double NUMBER, ABS, GUESSES, FOUND, Y, WEST, BY, POSITION, MORRISTOWN, GO, ANY, B, POINT, IS, NEW, PAIR, K, HURKLE, TELL, MUST, HIDING, OF, GRID, SORRY, SOUTHWEST, S, WILL, COMPUTING, CREATIVE, JERSEY, THE, CORNER, GET, DIRECTION, PLAY, EACH, APPROXIMATE, YOU, TRY, ON, GUESS, X, LOOK, SOUTH, A, WHOLE, GRIDPOINT, AT, COMMA, NUMBERS, SECOND, EAST, AGAIN, FIRST, THAT, DESIGNATED, AFTER, LET, G, SEPERATED, NORTH, N, VERTICAL, TRIES, I, HOMEBASE, IN, HIM, HORIZONTAL;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 10 PRINT TAB(33);"HURKLE" */
line_10:
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "HURKLE"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 110 N=5 */
line_110:
    N = 5;
    /* BASIC: 120 G=10 */
line_120:
    G = 10;
    /* BASIC: 210 PRINT */
line_210:
    printf("\n");
    /* BASIC: 220 PRINT "A HURKLE IS HIDING ON A";G;"BY";G;"GRID. HOMEBASE" */
line_220:
    printf("%s", "A HURKLE IS HIDING ON A"); printf("%g ", (double)(G)); printf("%s", "BY"); printf("%g ", (double)(G)); printf("%s", "GRID. HOMEBASE"); printf("\n");
    /* BASIC: 230 PRINT "ON THE GRID IS POINT 0,0 IN THE SOUTHWEST CORNER," */
line_230:
    printf("%s", "ON THE GRID IS POINT 0,0 IN THE SOUTHWEST CORNER,"); printf("\n");
    /* BASIC: 235 PRINT "AND ANY POINT ON THE GRID IS DESIGNATED BY A" */
line_235:
    printf("%s", "AND ANY POINT ON THE GRID IS DESIGNATED BY A"); printf("\n");
    /* BASIC: 240 PRINT "PAIR OF WHOLE NUMBERS SEPERATED BY A COMMA. THE FIRST" */
line_240:
    printf("%s", "PAIR OF WHOLE NUMBERS SEPERATED BY A COMMA. THE FIRST"); printf("\n");
    /* BASIC: 245 PRINT "NUMBER IS THE HORIZONTAL POSITION AND THE SECOND NUMBER" */
line_245:
    printf("%s", "NUMBER IS THE HORIZONTAL POSITION AND THE SECOND NUMBER"); printf("\n");
    /* BASIC: 246 PRINT "IS THE VERTICAL POSITION. YOU MUST TRY TO" */
line_246:
    printf("%s", "IS THE VERTICAL POSITION. YOU MUST TRY TO"); printf("\n");
    /* BASIC: 250 PRINT "GUESS THE HURKLE'S GRIDPOINT. YOU GET";N;"TRIES." */
line_250:
    printf("%s", "GUESS THE HURKLE'S GRIDPOINT. YOU GET"); printf("%g ", (double)(N)); printf("%s", "TRIES."); printf("\n");
    /* BASIC: 260 PRINT "AFTER EACH TRY, I WILL TELL YOU THE APPROXIMATE" */
line_260:
    printf("%s", "AFTER EACH TRY, I WILL TELL YOU THE APPROXIMATE"); printf("\n");
    /* BASIC: 270 PRINT "DIRECTION TO GO TO LOOK FOR THE HURKLE." */
line_270:
    printf("%s", "DIRECTION TO GO TO LOOK FOR THE HURKLE."); printf("\n");
    /* BASIC: 280 PRINT */
line_280:
    printf("\n");
    /* BASIC: 285 A=INT(G*RND(1)) */
line_285:
    A = floor(G*((double)rand() / (double)RAND_MAX));
    /* BASIC: 286 B=INT(G*RND(1)) */
line_286:
    B = floor(G*((double)rand() / (double)RAND_MAX));
    /* BASIC: 310 FOR K=1 TO N */
line_310:
    K = 1; for_loop_K: if ((1 >= 0 && K > N) || (1 < 0 && K < N)) goto end_for_K;
    /* BASIC: 320 PRINT "GUESS #";K; */
line_320:
    printf("%s", "GUESS #"); printf("%g ", (double)(K));
    /* BASIC: 330 INPUT X,Y */
line_330:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &X,Y);
    /* BASIC: 340 IF ABS(X-A)+ABS(Y-B)=0 THEN 500 */
line_340:
    if (fabs(X-A)+fabs(Y-B)==0) goto line_500;
    /* BASIC: 350 REM PRINT INFO */
line_350:
    // REM PRINT INFO
    /* BASIC: 360 GOSUB 610 */
line_360:
    /* TODO: GOSUB 610 */
    /* BASIC: 370 PRINT */
line_370:
    printf("\n");
    /* BASIC: 380 NEXT K */
line_380:
    K += 1; goto for_loop_K; end_for_K:;
    /* BASIC: 410 PRINT */
line_410:
    printf("\n");
    /* BASIC: 420 PRINT "SORRY, THAT'S";N;"GUESSES." */
line_420:
    printf("%s", "SORRY, THAT'S"); printf("%g ", (double)(N)); printf("%s", "GUESSES."); printf("\n");
    /* BASIC: 430 PRINT "THE HURKLE IS AT ";A;",";B */
line_430:
    printf("%s", "THE HURKLE IS AT "); printf("%g ", (double)(A)); printf("%s", ","); printf("%g ", (double)(B)); printf("\n");
    /* BASIC: 440 PRINT */
line_440:
    printf("\n");
    /* BASIC: 450 PRINT "LET'S PLAY AGAIN, HURKLE IS HIDING." */
line_450:
    printf("%s", "LET'S PLAY AGAIN, HURKLE IS HIDING."); printf("\n");
    /* BASIC: 460 PRINT */
line_460:
    printf("\n");
    /* BASIC: 470 GOTO 285 */
line_470:
    goto line_285;
    /* BASIC: 500 REM */
line_500:
    // REM
    /* BASIC: 510 PRINT */
line_510:
    printf("\n");
    /* BASIC: 520 PRINT "YOU FOUND HIM IN";K;"GUESSES!" */
line_520:
    printf("%s", "YOU FOUND HIM IN"); printf("%g ", (double)(K)); printf("%s", "GUESSES!"); printf("\n");
    /* BASIC: 540 GOTO 440 */
line_540:
    goto line_440;
    /* BASIC: 610 PRINT "GO "; */
line_610:
    printf("%s", "GO ");
    /* BASIC: 620 IF Y=B THEN 670 */
line_620:
    if (Y==B) goto line_670;
    /* BASIC: 630 IF Y<B THEN 660 */
line_630:
    if (Y<B) goto line_660;
    /* BASIC: 640 PRINT "SOUTH"; */
line_640:
    printf("%s", "SOUTH");
    /* BASIC: 650 GOTO 670 */
line_650:
    goto line_670;
    /* BASIC: 660 PRINT "NORTH"; */
line_660:
    printf("%s", "NORTH");
    /* BASIC: 670 IF X=A THEN 720 */
line_670:
    if (X==A) goto line_720;
    /* BASIC: 680 IF X<A THEN 710 */
line_680:
    if (X<A) goto line_710;
    /* BASIC: 690 PRINT "WEST"; */
line_690:
    printf("%s", "WEST");
    /* BASIC: 700 GOTO 720 */
line_700:
    goto line_720;
    /* BASIC: 710 PRINT "EAST"; */
line_710:
    printf("%s", "EAST");
    /* BASIC: 720 PRINT */
line_720:
    printf("\n");
    /* BASIC: 730 RETURN */
line_730:
    /* TODO: RETURN */
    /* BASIC: 999 END */
line_999:
    exit(0);

    return 0;
}
