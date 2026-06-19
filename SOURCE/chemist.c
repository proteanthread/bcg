/*
 * Transpiled from chemist.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double ABS, FACE, NOW, QUIVERING, NEW, DECIDE, JERSEY, THE, DON, A, COMIC, BOOK, D, BUT, T, CONTRIBUTIONS, CONSEQUENCES, BY, MORRISTOWN, ANY, SOON, ADD, MUST, HOWEVER, PARTS, TRY, LIFE, CHECMICAL, FUMES, YOUR, CHEMISTRY, BREATHE, BEEN, W, IS, UNSTABLE, LIVES, PROTOPLASM, OF, ONLY, MUCH, WILL, CREATIVE, JOB, CHEMIST, YOU, WATER, FICTITIOUS, BECOMES, USED, WITH, SIZZLE, ANOTHER, GIVEN, OTHER, DILUTION, ACID, GOOD, LITERS, INHALE, MAY, BE, ARE, HOW, AMOUNT, LONG, INTO, KRYPTOCYANIC, CAN, COMPUTING, JUST, DESALINATED, DILUTED, BLOB, EXPLODES, FIELD, AGAIN, R, WHO, ATTEMPTED, HAVE, MISS, RATIO;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 3 PRINT TAB(33);"CHEMIST" */
line_3:
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "CHEMIST"); printf("\n");
    /* BASIC: 6 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_6:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 8 PRINT:PRINT:PRINT */
line_8:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 10 PRINT "THE FICTITIOUS CHECMICAL KRYPTOCYANIC ACID CAN ONLY BE" */
line_10:
    printf("%s", "THE FICTITIOUS CHECMICAL KRYPTOCYANIC ACID CAN ONLY BE"); printf("\n");
    /* BASIC: 20 PRINT "DILUTED BY THE RATIO OF 7 PARTS WATER TO 3 PARTS ACID." */
line_20:
    printf("%s", "DILUTED BY THE RATIO OF 7 PARTS WATER TO 3 PARTS ACID."); printf("\n");
    /* BASIC: 30 PRINT "IF ANY OTHER RATIO IS ATTEMPTED, THE ACID BECOMES UNSTABLE" */
line_30:
    printf("%s", "IF ANY OTHER RATIO IS ATTEMPTED, THE ACID BECOMES UNSTABLE"); printf("\n");
    /* BASIC: 40 PRINT "AND SOON EXPLODES.  GIVEN THE AMOUNT OF ACID, YOU MUST" */
line_40:
    printf("%s", "AND SOON EXPLODES.  GIVEN THE AMOUNT OF ACID, YOU MUST"); printf("\n");
    /* BASIC: 50 PRINT "DECIDE WHO MUCH WATER TO ADD FOR DILUTION.  IF YOU MISS" */
line_50:
    printf("%s", "DECIDE WHO MUCH WATER TO ADD FOR DILUTION.  IF YOU MISS"); printf("\n");
    /* BASIC: 60 PRINT "YOU FACE THE CONSEQUENCES." */
line_60:
    printf("%s", "YOU FACE THE CONSEQUENCES."); printf("\n");
    /* BASIC: 100 A=INT(RND(1)*50) */
line_100:
    A = floor(((double)rand() / (double)RAND_MAX)*50);
    /* BASIC: 110 W=7*A/3 */
line_110:
    W = 7*A/3;
    /* BASIC: 120 PRINT A;"LITERS OF KRYPTOCYANIC ACID.  HOW MUCH WATER"; */
line_120:
    printf("%g ", (double)(A)); printf("%s", "LITERS OF KRYPTOCYANIC ACID.  HOW MUCH WATER");
    /* BASIC: 130 INPUT R */
line_130:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &R);
    /* BASIC: 140 D=ABS(W-R) */
line_140:
    D = fabs(W-R);
    /* BASIC: 150 IF D>W/20 THEN 200 */
line_150:
    if (D>W/20) goto line_200;
    /* BASIC: 160 PRINT " GOOD JOB! YOU MAY BREATHE NOW, BUT DON'T INHALE THE FUMES!" */
line_160:
    printf("%s", " GOOD JOB! YOU MAY BREATHE NOW, BUT DON'T INHALE THE FUMES!"); printf("\n");
    /* BASIC: 170 PRINT */
line_170:
    printf("\n");
    /* BASIC: 180 GOTO 100 */
line_180:
    goto line_100;
    /* BASIC: 200 PRINT " SIZZLE!  YOU HAVE JUST BEEN DESALINATED INTO A BLOB" */
line_200:
    printf("%s", " SIZZLE!  YOU HAVE JUST BEEN DESALINATED INTO A BLOB"); printf("\n");
    /* BASIC: 210 PRINT " OF QUIVERING PROTOPLASM!" */
line_210:
    printf("%s", " OF QUIVERING PROTOPLASM!"); printf("\n");
    /* BASIC: 220 T=T+1 */
line_220:
    T = T+1;
    /* BASIC: 230 IF T=9 THEN 260 */
line_230:
    if (T==9) goto line_260;
    /* BASIC: 240 PRINT " HOWEVER, YOU MAY TRY AGAIN WITH ANOTHER LIFE." */
line_240:
    printf("%s", " HOWEVER, YOU MAY TRY AGAIN WITH ANOTHER LIFE."); printf("\n");
    /* BASIC: 250 GOTO 100 */
line_250:
    goto line_100;
    /* BASIC: 260 PRINT " YOUR 9 LIVES ARE USED, BUT YOU WILL BE LONG REMEMBERED FOR" */
line_260:
    printf("%s", " YOUR 9 LIVES ARE USED, BUT YOU WILL BE LONG REMEMBERED FOR"); printf("\n");
    /* BASIC: 270 PRINT " YOUR CONTRIBUTIONS TO THE FIELD OF COMIC BOOK CHEMISTRY." */
line_270:
    printf("%s", " YOUR CONTRIBUTIONS TO THE FIELD OF COMIC BOOK CHEMISTRY."); printf("\n");
    /* BASIC: 280 END */
line_280:
    exit(0);

    return 0;
}
