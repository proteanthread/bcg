/*
 * Transpiled from 3dplot.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double DEF, Z, PLOT, X, Y, MORRISTOWN, FNA, EXP, L, Y1, COMPUTING, CREATIVE, JERSEY, SQR, NEW;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 1 PRINT TAB(32);"3D PLOT" */
line_1:
    { int _t; for(_t=0; _t<32; _t++) printf(" "); } printf("%s", "3D PLOT"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT:PRINT:PRINT */
line_3:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 5 DEF FNA(Z)=30*EXP(-Z*Z/100) */
line_5:
    /* UNTRANSLATED: DEF FNA(Z)=30*EXP(-Z*Z/100) */
    /* BASIC: 100 PRINT */
line_100:
    printf("\n");
    /* BASIC: 110 FOR X=-30 TO 30 STEP 1.5 */
line_110:
    X = -30; for_loop_X: if ((1.5 >= 0 && X > 30) || (1.5 < 0 && X < 30)) goto end_for_X;
    /* BASIC: 120 L=0 */
line_120:
    L = 0;
    /* BASIC: 130 Y1=5*INT(SQR(900-X*X)/5) */
line_130:
    Y1 = 5*floor(sqrt(900-X*X)/5);
    /* BASIC: 140 FOR Y=Y1 TO -Y1 STEP -5 */
line_140:
    Y = Y1; for_loop_Y: if ((-5 >= 0 && Y > -Y1) || (-5 < 0 && Y < -Y1)) goto end_for_Y;
    /* BASIC: 150 Z=INT(25+FNA(SQR(X*X+Y*Y))-.7*Y) */
line_150:
    Z = floor(25+FNA(sqrt(X*X+Y*Y))-.7*Y);
    /* BASIC: 160 IF Z<=L THEN 190 */
line_160:
    if (Z<==L) goto line_190;
    /* BASIC: 170 L=Z */
line_170:
    L = Z;
    /* BASIC: 180 PRINT TAB(Z);"*"; */
line_180:
    { int _t; for(_t=0; _t<Z; _t++) printf(" "); } printf("%s", "*");
    /* BASIC: 190 NEXT Y */
line_190:
    Y += -5; goto for_loop_Y; end_for_Y:;
    /* BASIC: 200 PRINT */
line_200:
    printf("\n");
    /* BASIC: 210 NEXT X */
line_210:
    X += 1.5; goto for_loop_X; end_for_X:;
    /* BASIC: 300 END */
line_300:
    exit(0);

    return 0;
}
