/*
 * Transpiled from guess.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double NUMBER, VERY, M, GUESSING, NOW, MORRISTOWN, L1, GAME, ANY, LOG, BEEN, H, IS, NEW, LOW, SMALLER, OF, ONLY, LL, ABLE, ANSWER, S, COMPUTING, CREATIVE, JERSEY, GET, THINK, YOU, TRY, GUESS, A, SHOULD, WHAT, L, BETWEEN, IT, WANT, DO, HIGH, THAT, G, LIMIT, TOO, N, TRIES, HAVE, I, THIS, GOOD, IN, BIGGER, THINKING, GOT;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 1 PRINT TAB(33);"GUESS" */
line_1:
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "GUESS"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT:PRINT:PRINT */
line_3:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 4 PRINT "THIS IS A NUMBER GUESSING GAME. I'LL THINK" */
line_4:
    printf("%s", "THIS IS A NUMBER GUESSING GAME. I'LL THINK"); printf("\n");
    /* BASIC: 5 PRINT "OF A NUMBER BETWEEN 1 AND ANY LIMIT YOU WANT." */
line_5:
    printf("%s", "OF A NUMBER BETWEEN 1 AND ANY LIMIT YOU WANT."); printf("\n");
    /* BASIC: 6 PRINT "THEN YOU HAVE TO GUESS WHAT IT IS." */
line_6:
    printf("%s", "THEN YOU HAVE TO GUESS WHAT IT IS."); printf("\n");
    /* BASIC: 7 PRINT */
line_7:
    printf("\n");
    /* BASIC: 8 PRINT "WHAT LIMIT DO YOU WANT"; */
line_8:
    printf("%s", "WHAT LIMIT DO YOU WANT");
    /* BASIC: 9 INPUT L */
line_9:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &L);
    /* BASIC: 10 PRINT */
line_10:
    printf("\n");
    /* BASIC: 11 L1=INT(LOG(L)/LOG(2))+1 */
line_11:
    L1 = floor(LOG(L)/LOG(2))+1;
    /* BASIC: 12 PRINT "I'M THINKING OF A NUMBER BETWEEN 1 AND";L */
line_12:
    printf("%s", "I'M THINKING OF A NUMBER BETWEEN 1 AND"); printf("%g ", (double)(L)); printf("\n");
    /* BASIC: 13 G=1 */
line_13:
    G = 1;
    /* BASIC: 14 PRINT "NOW YOU TRY TO GUESS WHAT IT IS." */
line_14:
    printf("%s", "NOW YOU TRY TO GUESS WHAT IT IS."); printf("\n");
    /* BASIC: 15 M=INT(L*RND(1)+1) */
line_15:
    M = floor(L*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 20 INPUT N */
line_20:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &N);
    /* BASIC: 21 IF N>0 THEN 25 */
line_21:
    if (N>0) goto line_25;
    /* BASIC: 22 GOSUB 70 */
line_22:
    /* TODO: GOSUB 70 */
    /* BASIC: 23 GOTO 1 */
line_23:
    goto line_1;
    /* BASIC: 25 IF N=M THEN 50 */
line_25:
    if (N==M) goto line_50;
    /* BASIC: 30 G=G+1 */
line_30:
    G = G+1;
    /* BASIC: 31 IF N>M THEN 40 */
line_31:
    if (N>M) goto line_40;
    /* BASIC: 32 PRINT "TOO LOW. TRY A BIGGER ANSWER." */
line_32:
    printf("%s", "TOO LOW. TRY A BIGGER ANSWER."); printf("\n");
    /* BASIC: 33 GOTO 20 */
line_33:
    goto line_20;
    /* BASIC: 40 PRINT "TOO HIGH. TRY A SMALLER ANSWER." */
line_40:
    printf("%s", "TOO HIGH. TRY A SMALLER ANSWER."); printf("\n");
    /* BASIC: 42 GOTO 20 */
line_42:
    goto line_20;
    /* BASIC: 50 PRINT "THAT'S IT! YOU GOT IT IN";G;"TRIES." */
line_50:
    printf("%s", "THAT'S IT! YOU GOT IT IN"); printf("%g ", (double)(G)); printf("%s", "TRIES."); printf("\n");
    /* BASIC: 52 IF G<L1 THEN 58 */
line_52:
    if (G<L1) goto line_58;
    /* BASIC: 54 IF G=L1 THEN 60 */
line_54:
    if (G==L1) goto line_60;
    /* BASIC: 56 PRINT "YOU SHOULD HAVE BEEN ABLE TO GET IT IN ONLY";L1 */
line_56:
    printf("%s", "YOU SHOULD HAVE BEEN ABLE TO GET IT IN ONLY"); printf("%g ", (double)(L1)); printf("\n");
    /* BASIC: 57 GOTO 65 */
line_57:
    goto line_65;
    /* BASIC: 58 PRINT "VERY "; */
line_58:
    printf("%s", "VERY ");
    /* BASIC: 60 PRINT "GOOD." */
line_60:
    printf("%s", "GOOD."); printf("\n");
    /* BASIC: 65 GOSUB 70 */
line_65:
    /* TODO: GOSUB 70 */
    /* BASIC: 66 GOTO 12 */
line_66:
    goto line_12;
    /* BASIC: 70 FOR H=1 TO 5 */
line_70:
    H = 1; for_loop_H: if ((1 >= 0 && H > 5) || (1 < 0 && H < 5)) goto end_for_H;
    /* BASIC: 71 PRINT */
line_71:
    printf("\n");
    /* BASIC: 72 NEXT H */
line_72:
    H += 1; goto for_loop_H; end_for_H:;
    /* BASIC: 73 RETURN */
line_73:
    /* TODO: RETURN */
    /* BASIC: 99 END */
line_99:
    exit(0);

    return 0;
}
