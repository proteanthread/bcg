/*
 * Transpiled from nicomachus.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double NICOMACHUS, NUMBER, HAS, ARITHMETIC, MOMENT, FROM, BY, MORRISTOWN, ME, B, HOW, C, IS, NEW, ABOUT, OF, NICOMA, WAS, S, COMPUTING, CREATIVE, JERSEY, THINK, PLEASE, DON, TRY, ERROR, PUZZLE, A, ARITHMETICA, DIVIDED, NO, BETWEEN, D, RIGHT, ANOTHER, EH, THAT, YES, BOOMERANG, LET, T, UNDERSTAND, YOUR, I, IN, FEEL;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 2 PRINT TAB(33);"NICOMA" */
line_2:
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "NICOMA"); printf("\n");
    /* BASIC: 4 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 6 PRINT: PRINT: PRINT */
line_6:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 10 PRINT "BOOMERANG PUZZLE FROM ARITHMETICA OF NICOMACHUS -- A.D. 90!" */
line_10:
    printf("%s", "BOOMERANG PUZZLE FROM ARITHMETICA OF NICOMACHUS -- A.D. 90!"); printf("\n");
    /* BASIC: 20 PRINT */
line_20:
    printf("\n");
    /* BASIC: 30 PRINT "PLEASE THINK OF A NUMBER BETWEEN 1 AND 100." */
line_30:
    printf("%s", "PLEASE THINK OF A NUMBER BETWEEN 1 AND 100."); printf("\n");
    /* BASIC: 40 PRINT "YOUR NUMBER DIVIDED BY 3 HAS A REMAINDER OF"; */
line_40:
    printf("%s", "YOUR NUMBER DIVIDED BY 3 HAS A REMAINDER OF");
    /* BASIC: 45 INPUT A */
line_45:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &A);
    /* BASIC: 50 PRINT "YOUR NUMBER DIVIDED BY 5 HAS A REMAINDER OF"; */
line_50:
    printf("%s", "YOUR NUMBER DIVIDED BY 5 HAS A REMAINDER OF");
    /* BASIC: 55 INPUT B */
line_55:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &B);
    /* BASIC: 60 PRINT "YOUR NUMBER DIVIDED BY 7 HAS A REMAINDER OF"; */
line_60:
    printf("%s", "YOUR NUMBER DIVIDED BY 7 HAS A REMAINDER OF");
    /* BASIC: 65 INPUT C */
line_65:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &C);
    /* BASIC: 70 PRINT */
line_70:
    printf("\n");
    /* BASIC: 80 PRINT "LET ME THINK A MOMENT..." */
line_80:
    printf("%s", "LET ME THINK A MOMENT..."); printf("\n");
    /* BASIC: 85 PRINT */
line_85:
    printf("\n");
    /* BASIC: 90 FOR I=1 TO 1500: NEXT I */
line_90:
    I = 1; for_loop_I: if ((1 >= 0 && I > 1500) || (1 < 0 && I < 1500)) goto end_for_I;
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 100 D=70*A+21*B+15*C */
line_100:
    D = 70*A+21*B+15*C;
    /* BASIC: 110 IF D<=105 THEN 140 */
line_110:
    if (D<==105) goto line_140;
    /* BASIC: 120 D=D-105 */
line_120:
    D = D-105;
    /* BASIC: 130 GOTO 110 */
line_130:
    goto line_110;
    /* BASIC: 140 PRINT "YOUR NUMBER WAS";D;", RIGHT"; */
line_140:
    printf("%s", "YOUR NUMBER WAS"); printf("%g ", (double)(D)); printf("%s", ", RIGHT");
    /* BASIC: 160 INPUT A$ */
line_160:
    printf("? "); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    /* BASIC: 165 PRINT */
line_165:
    printf("\n");
    /* BASIC: 170 IF A$="YES" THEN 220 */
line_170:
    if (A$=="YES") goto line_220;
    /* BASIC: 180 IF A$="NO" THEN 240 */
line_180:
    if (A$=="NO") goto line_240;
    /* BASIC: 190 PRINT "EH?  I DON'T UNDERSTAND '";A$;"'  TRY 'YES' OR 'NO'." */
line_190:
    printf("%s", "EH?  I DON'T UNDERSTAND '"); printf("%s", A_str); printf("%s", "'  TRY 'YES' OR 'NO'."); printf("\n");
    /* BASIC: 200 GOTO 160 */
line_200:
    goto line_160;
    /* BASIC: 220 PRINT "HOW ABOUT THAT!!" */
line_220:
    printf("%s", "HOW ABOUT THAT!!"); printf("\n");
    /* BASIC: 230 GOTO 250 */
line_230:
    goto line_250;
    /* BASIC: 240 PRINT "I FEEL YOUR ARITHMETIC IS IN ERROR." */
line_240:
    printf("%s", "I FEEL YOUR ARITHMETIC IS IN ERROR."); printf("\n");
    /* BASIC: 250 PRINT */
line_250:
    printf("\n");
    /* BASIC: 260 PRINT "LET'S TRY ANOTHER." */
line_260:
    printf("%s", "LET'S TRY ANOTHER."); printf("\n");
    /* BASIC: 270 GOTO 20 */
line_270:
    goto line_20;
    /* BASIC: 999 END */
line_999:
    exit(0);

    return 0;
}
