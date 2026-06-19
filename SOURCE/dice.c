/*
 * Transpiled from dice.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double NUMBER, OUT, ENTER, VERY, MORRISTOWN, B, HOW, TAKE, NEW, LONG, PAIR, OF, LARGE, DICE, Z, TOTAL, PARTICULAR, ROLLING, S, SPOTS, COMPUTING, CREATIVE, THE, JERSEY, TIMES, WATCH, ROLLS, COMPUTER, TIME, YOU, SIMULATES, TRY, X, A, MANY, NUMBERS, V, PROGRAM, WANT, AGAIN, ROLL, R, YES, OVER, THIS, Q, IN;
    double F[1000] = {0}; /* Static array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 2 PRINT TAB(34);"DICE" */
line_2:
    { int _t; for(_t=0; _t<34; _t++) printf(" "); } printf("%s", "DICE"); printf("\n");
    /* BASIC: 4 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 6 PRINT:PRINT:PRINT */
line_6:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 10 DIM F(12) */
line_10:
    /* DIM F(12) (handled statically) */
    /* BASIC: 20 REM  DANNY FREIDUS */
line_20:
    // REM  DANNY FREIDUS
    /* BASIC: 30 PRINT "THIS PROGRAM SIMULATES THE ROLLING OF A" */
line_30:
    printf("%s", "THIS PROGRAM SIMULATES THE ROLLING OF A"); printf("\n");
    /* BASIC: 40 PRINT "PAIR OF DICE." */
line_40:
    printf("%s", "PAIR OF DICE."); printf("\n");
    /* BASIC: 50 PRINT "YOU ENTER THE NUMBER OF TIMES YOU WANT THE COMPUTER TO" */
line_50:
    printf("%s", "YOU ENTER THE NUMBER OF TIMES YOU WANT THE COMPUTER TO"); printf("\n");
    /* BASIC: 60 PRINT "'ROLL' THE DICE.  WATCH OUT, VERY LARGE NUMBERS TAKE" */
line_60:
    printf("%s", "'ROLL' THE DICE.  WATCH OUT, VERY LARGE NUMBERS TAKE"); printf("\n");
    /* BASIC: 70 PRINT "A LONG TIME.  IN PARTICULAR, NUMBERS OVER 5000." */
line_70:
    printf("%s", "A LONG TIME.  IN PARTICULAR, NUMBERS OVER 5000."); printf("\n");
    /* BASIC: 80 FOR Q=1 TO 12 */
line_80:
    Q = 1; for_loop_Q: if ((1 >= 0 && Q > 12) || (1 < 0 && Q < 12)) goto end_for_Q;
    /* BASIC: 90 F(Q)=0 */
line_90:
    F(Q) = 0;
    /* BASIC: 100 NEXT Q */
line_100:
    Q += 1; goto for_loop_Q; end_for_Q:;
    /* BASIC: 110 PRINT:PRINT "HOW MANY ROLLS"; */
line_110:
    printf("\n");
    printf("%s", "HOW MANY ROLLS");
    /* BASIC: 120 INPUT X */
line_120:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &X);
    /* BASIC: 130 FOR S=1 TO X */
line_130:
    S = 1; for_loop_S: if ((1 >= 0 && S > X) || (1 < 0 && S < X)) goto end_for_S;
    /* BASIC: 140 A=INT(6*RND(1)+1) */
line_140:
    A = floor(6*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 150 B=INT(6*RND(1)+1) */
line_150:
    B = floor(6*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 160 R=A+B */
line_160:
    R = A+B;
    /* BASIC: 170 F(R)=F(R)+1 */
line_170:
    F(R) = F(R)+1;
    /* BASIC: 180 NEXT S */
line_180:
    S += 1; goto for_loop_S; end_for_S:;
    /* BASIC: 185 PRINT */
line_185:
    printf("\n");
    /* BASIC: 190 PRINT "TOTAL SPOTS","NUMBER OF TIMES" */
line_190:
    printf("%s", "TOTAL SPOTS"); printf("\t"); printf("%s", "NUMBER OF TIMES"); printf("\n");
    /* BASIC: 200 FOR V=2 TO 12 */
line_200:
    V = 2; for_loop_V: if ((1 >= 0 && V > 12) || (1 < 0 && V < 12)) goto end_for_V;
    /* BASIC: 210 PRINT V,F(V) */
line_210:
    printf("%g ", (double)(V)); printf("\t"); printf("%g ", (double)(F(V))); printf("\n");
    /* BASIC: 220 NEXT V */
line_220:
    V += 1; goto for_loop_V; end_for_V:;
    /* BASIC: 221 PRINT */
line_221:
    printf("\n");
    /* BASIC: 222 PRINT:PRINT "TRY AGAIN"; */
line_222:
    printf("\n");
    printf("%s", "TRY AGAIN");
    /* BASIC: 223 INPUT Z$ */
line_223:
    printf("? "); fgets(Z_str, sizeof(Z_str), stdin); Z_str[strcspn(Z_str, "\n")] = 0;
    /* BASIC: 224 IF Z$="YES" THEN 80 */
line_224:
    if (Z$=="YES") goto line_80;
    /* BASIC: 240 END */
line_240:
    exit(0);

    return 0;
}
