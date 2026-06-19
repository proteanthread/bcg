/*
 * Transpiled from letter.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double GUESSES, SHOULDN, GUESSING, MORE, MORRISTOWN, THAN, GAME, CLUES, CHR, HOW, TAKE, IS, NEW, LOW, K, HIGHER, OF, Z, LL, START, S, RE, COMPUTING, CREATIVE, JERSEY, THE, LOWER, JOB, MY, THINK, TRY, GIVE, YOU, GUESS, A, ALPHABET, AS, GETTING, L, LETTER, WHAT, CLOSE, BUT, IT, AGAIN, HIGH, O, T, G, LET, TOO, N, HAVE, YOUR, I, GOOD, PLAN, IN, GOT;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 10 PRINT TAB(33);"LETTER" */
line_10:
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "LETTER"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 100 PRINT "LETTER GUESSING GAME": PRINT */
line_100:
    printf("%s", "LETTER GUESSING GAME"); printf("\n");
    printf("\n");
    /* BASIC: 210 PRINT "I'LL THINK OF A LETTER OF THE ALPHABET, A TO Z." */
line_210:
    printf("%s", "I'LL THINK OF A LETTER OF THE ALPHABET, A TO Z."); printf("\n");
    /* BASIC: 220 PRINT "TRY TO GUESS MY LETTER AND I'LL GIVE YOU CLUES" */
line_220:
    printf("%s", "TRY TO GUESS MY LETTER AND I'LL GIVE YOU CLUES"); printf("\n");
    /* BASIC: 230 PRINT "AS TO HOW CLOSE YOU'RE GETTING TO MY LETTER." */
line_230:
    printf("%s", "AS TO HOW CLOSE YOU'RE GETTING TO MY LETTER."); printf("\n");
    /* BASIC: 310 L=65+INT(RND(1)*26) */
line_310:
    L = 65+floor(((double)rand() / (double)RAND_MAX)*26);
    /* BASIC: 320 G=0 */
line_320:
    G = 0;
    /* BASIC: 340 PRINT: PRINT "O.K., I HAVE A LETTER.  START GUESSING." */
line_340:
    printf("\n");
    printf("%s", "O.K., I HAVE A LETTER.  START GUESSING."); printf("\n");
    /* BASIC: 410 PRINT: PRINT "WHAT IS YOUR GUESS"; */
line_410:
    printf("\n");
    printf("%s", "WHAT IS YOUR GUESS");
    /* BASIC: 420 G=G+1 */
line_420:
    G = G+1;
    /* BASIC: 430 INPUT A$: A=ASC(A$): PRINT */
line_430:
    printf("? "); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    A = ASC(A$);
    printf("\n");
    /* BASIC: 440 IF A=L THEN 500 */
line_440:
    if (A==L) goto line_500;
    /* BASIC: 450 IF A>L THEN 480 */
line_450:
    if (A>L) goto line_480;
    /* BASIC: 460 PRINT "TOO LOW.  TRY A HIGHER LETTER.": GOTO 410 */
line_460:
    printf("%s", "TOO LOW.  TRY A HIGHER LETTER."); printf("\n");
    goto line_410;
    /* BASIC: 480 PRINT "TOO HIGH.  TRY A LOWER LETTER.": GOTO 410 */
line_480:
    printf("%s", "TOO HIGH.  TRY A LOWER LETTER."); printf("\n");
    goto line_410;
    /* BASIC: 500 PRINT: PRINT "YOU GOT IT IN";G;"GUESSES!!" */
line_500:
    printf("\n");
    printf("%s", "YOU GOT IT IN"); printf("%g ", (double)(G)); printf("%s", "GUESSES!!"); printf("\n");
    /* BASIC: 504 IF G<=5 THEN 508 */
line_504:
    if (G<==5) goto line_508;
    /* BASIC: 506 PRINT "BUT IT SHOULDN'T TAKE MORE THAN 5 GUESSES!": GOTO 515 */
line_506:
    printf("%s", "BUT IT SHOULDN'T TAKE MORE THAN 5 GUESSES!"); printf("\n");
    goto line_515;
    /* BASIC: 508 PRINT "GOOD JOB !!!!!" */
line_508:
    printf("%s", "GOOD JOB !!!!!"); printf("\n");
    /* BASIC: 510 FOR N=1 TO 15: PRINT CHR$(7);: NEXT N */
line_510:
    N = 1; for_loop_N: if ((1 >= 0 && N > 15) || (1 < 0 && N < 15)) goto end_for_N;
    printf("%g ", (double)(CHR$(7)));
    N += 1; goto for_loop_N; end_for_N:;
    /* BASIC: 515 PRINT */
line_515:
    printf("\n");
    /* BASIC: 520 PRINT "LET'S PLAN AGAIN....." */
line_520:
    printf("%s", "LET'S PLAN AGAIN....."); printf("\n");
    /* BASIC: 530 GOTO 310 */
line_530:
    goto line_310;
    /* BASIC: 999 END */
line_999:
    exit(0);

    return 0;
}
