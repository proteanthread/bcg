/*
 * Transpiled from sinewave.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double SIN, WAVE, T, A, MORRISTOWN, B, COMPUTING, CREATIVE, JERSEY, NEW, SINE;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 10 PRINT TAB(30);"SINE WAVE" */
line_10:
    { int _t; for(_t=0; _t<30; _t++) printf(" "); } printf("%s", "SINE WAVE"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT: PRINT: PRINT: PRINT: PRINT */
line_30:
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 40 REMARKABLE PROGRAM BY DAVID AHL */
line_40:
    // REMARKABLE PROGRAM BY DAVID AHL
    /* BASIC: 50 B=0 */
line_50:
    B = 0;
    /* BASIC: 100 REM  START LONG LOOP */
line_100:
    // REM  START LONG LOOP
    /* BASIC: 110 FOR T=0 TO 40 STEP .25 */
line_110:
    T = 0; for_loop_T: if ((.25 >= 0 && T > 40) || (.25 < 0 && T < 40)) goto end_for_T;
    /* BASIC: 120 A=INT(26+25*SIN(T)) */
line_120:
    A = floor(26+25*SIN(T));
    /* BASIC: 130 PRINT TAB(A); */
line_130:
    { int _t; for(_t=0; _t<A; _t++) printf(" "); }
    /* BASIC: 140 IF B=1 THEN 180 */
line_140:
    if (B==1) goto line_180;
    /* BASIC: 150 PRINT "CREATIVE" */
line_150:
    printf("%s", "CREATIVE"); printf("\n");
    /* BASIC: 160 B=1 */
line_160:
    B = 1;
    /* BASIC: 170 GOTO 200 */
line_170:
    goto line_200;
    /* BASIC: 180 PRINT "COMPUTING" */
line_180:
    printf("%s", "COMPUTING"); printf("\n");
    /* BASIC: 190 B=0 */
line_190:
    B = 0;
    /* BASIC: 200 NEXT T */
line_200:
    T += .25; goto for_loop_T; end_for_T:;
    /* BASIC: 999 END */
line_999:
    exit(0);

    return 0;
}
