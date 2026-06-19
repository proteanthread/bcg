/*
 * Transpiled from trap.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double NUMBER, AM, LARGER, ENTER, Y, ARE, GUESSES, MORRISTOWN, THAN, B, IS, NEW, TYPE, SMALLER, TELL, OF, Z, INSTRUCTIONS, TWO, TRAP, TRAPPED, SORRY, S, WAS, WILL, SINGLE, COMPUTING, CREATIVE, JERSEY, THE, GET, MY, EACH, TRY, YOU, ON, GUESS, LEFT, X, A, BETWEEN, IT, NUMBERS, ONE, WANT, AGAIN, BOTH, THAT, R, TRYING, G, N, HAVE, YOUR, I, Q, THINKING, GOT;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 1 PRINT TAB(34);"TRAP" */
line_1:
    { int _t; for(_t=0; _t<34; _t++) printf(" "); } printf("%s", "TRAP"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT:PRINT:PRINT */
line_3:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 10 G=6 */
line_10:
    G = 6;
    /* BASIC: 20 N=100 */
line_20:
    N = 100;
    /* BASIC: 30 REM-TRAP */
line_30:
    // REM-TRAP
    /* BASIC: 40 REM-STEVE ULLMAN, 8-1-72 */
line_40:
    // REM-STEVE ULLMAN, 8-1-72
    /* BASIC: 50 PRINT "INSTRUCTIONS"; */
line_50:
    printf("%s", "INSTRUCTIONS");
    /* BASIC: 60 INPUT Z$ */
line_60:
    printf("? "); fgets(Z_str, sizeof(Z_str), stdin); Z_str[strcspn(Z_str, "\n")] = 0;
    /* BASIC: 70 IF LEFT$(Z$,1)<>"Y" THEN 180 */
line_70:
    if (LEFT$(Z$,1)!="Y") goto line_180;
    /* BASIC: 80 PRINT "I AM THINKING OF A NUMBER BETWEEN 1 AND";N */
line_80:
    printf("%s", "I AM THINKING OF A NUMBER BETWEEN 1 AND"); printf("%g ", (double)(N)); printf("\n");
    /* BASIC: 90 PRINT "TRY TO GUESS MY NUMBER. ON EACH GUESS," */
line_90:
    printf("%s", "TRY TO GUESS MY NUMBER. ON EACH GUESS,"); printf("\n");
    /* BASIC: 100 PRINT "YOU ARE TO ENTER 2 NUMBERS, TRYING TO TRAP" */
line_100:
    printf("%s", "YOU ARE TO ENTER 2 NUMBERS, TRYING TO TRAP"); printf("\n");
    /* BASIC: 110 PRINT "MY NUMBER BETWEEN THE TWO NUMBERS. I WILL" */
line_110:
    printf("%s", "MY NUMBER BETWEEN THE TWO NUMBERS. I WILL"); printf("\n");
    /* BASIC: 120 PRINT "TELL YOU IF YOU HAVE TRAPPED MY NUMBER, IF MY" */
line_120:
    printf("%s", "TELL YOU IF YOU HAVE TRAPPED MY NUMBER, IF MY"); printf("\n");
    /* BASIC: 130 PRINT "NUMBER IS LARGER THAN YOUR TWO NUMBERS, OR IF" */
line_130:
    printf("%s", "NUMBER IS LARGER THAN YOUR TWO NUMBERS, OR IF"); printf("\n");
    /* BASIC: 140 PRINT "MY NUMBER IS SMALLER THAN YOUR TWO NUMBERS." */
line_140:
    printf("%s", "MY NUMBER IS SMALLER THAN YOUR TWO NUMBERS."); printf("\n");
    /* BASIC: 150 PRINT "IF YOU WANT TO GUESS ONE SINGLE NUMBER, TYPE" */
line_150:
    printf("%s", "IF YOU WANT TO GUESS ONE SINGLE NUMBER, TYPE"); printf("\n");
    /* BASIC: 160 PRINT "YOUR GUESS FOR BOTH YOUR TRAP NUMBERS." */
line_160:
    printf("%s", "YOUR GUESS FOR BOTH YOUR TRAP NUMBERS."); printf("\n");
    /* BASIC: 170 PRINT "YOU GET";G;"GUESSES TO GET MY NUMBER." */
line_170:
    printf("%s", "YOU GET"); printf("%g ", (double)(G)); printf("%s", "GUESSES TO GET MY NUMBER."); printf("\n");
    /* BASIC: 180 X=INT(N*RND(1))+1 */
line_180:
    X = floor(N*((double)rand() / (double)RAND_MAX))+1;
    /* BASIC: 190 FOR Q=1 TO G */
line_190:
    Q = 1; for_loop_Q: if ((1 >= 0 && Q > G) || (1 < 0 && Q < G)) goto end_for_Q;
    /* BASIC: 200 PRINT */
line_200:
    printf("\n");
    /* BASIC: 210 PRINT "GUESS #";Q; */
line_210:
    printf("%s", "GUESS #"); printf("%g ", (double)(Q));
    /* BASIC: 220 INPUT A,B */
line_220:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &A,B);
    /* BASIC: 230 IF A=B AND X=A THEN 400 */
line_230:
    if (A==B && X==A) goto line_400;
    /* BASIC: 240 IF A <= B THEN 260 */
line_240:
    if (A <== B) goto line_260;
    /* BASIC: 250 GOSUB 360 */
line_250:
    /* TODO: GOSUB 360 */
    /* BASIC: 260 IF A <= X AND X <= B THEN 320 */
line_260:
    if (A <== X && X <== B) goto line_320;
    /* BASIC: 270 IF X<A THEN 300 */
line_270:
    if (X<A) goto line_300;
    /* BASIC: 280 PRINT "MY NUMBER IS LARGER THAN YOUR TRAP NUMBERS." */
line_280:
    printf("%s", "MY NUMBER IS LARGER THAN YOUR TRAP NUMBERS."); printf("\n");
    /* BASIC: 290 GOTO 330 */
line_290:
    goto line_330;
    /* BASIC: 300 PRINT "MY NUMBER IS SMALLER THAN YOUR TRAP NUMBERS." */
line_300:
    printf("%s", "MY NUMBER IS SMALLER THAN YOUR TRAP NUMBERS."); printf("\n");
    /* BASIC: 310 GOTO 330 */
line_310:
    goto line_330;
    /* BASIC: 320 PRINT "YOU HAVE TRAPPED MY NUMBER." */
line_320:
    printf("%s", "YOU HAVE TRAPPED MY NUMBER."); printf("\n");
    /* BASIC: 330 NEXT Q */
line_330:
    Q += 1; goto for_loop_Q; end_for_Q:;
    /* BASIC: 340 PRINT "SORRY, THAT'S";G;"GUESSES. THE NUMBER WAS";X */
line_340:
    printf("%s", "SORRY, THAT'S"); printf("%g ", (double)(G)); printf("%s", "GUESSES. THE NUMBER WAS"); printf("%g ", (double)(X)); printf("\n");
    /* BASIC: 345 PRINT */
line_345:
    printf("\n");
    /* BASIC: 350 GOTO 410 */
line_350:
    goto line_410;
    /* BASIC: 360 R=A */
line_360:
    R = A;
    /* BASIC: 370 A=B */
line_370:
    A = B;
    /* BASIC: 380 B=R */
line_380:
    B = R;
    /* BASIC: 390 RETURN */
line_390:
    /* TODO: RETURN */
    /* BASIC: 400 PRINT "YOU GOT IT!!!" */
line_400:
    printf("%s", "YOU GOT IT!!!"); printf("\n");
    /* BASIC: 410 PRINT */
line_410:
    printf("\n");
    /* BASIC: 420 PRINT "TRY AGAIN." */
line_420:
    printf("%s", "TRY AGAIN."); printf("\n");
    /* BASIC: 430 PRINT */
line_430:
    printf("\n");
    /* BASIC: 440 GOTO 180 */
line_440:
    goto line_180;
    /* BASIC: 450 END */
line_450:
    exit(0);

    return 0;
}
