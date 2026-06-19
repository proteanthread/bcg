/*
 * Transpiled from train.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double ABS, CERTAIN, BY, MORRISTOWN, THAN, HOW, C, TAKE, MAKE, PERCENT, IS, NEW, TRAVELING, EXERCISE, LONG, MPH, OFF, CAN, ANSWER, TRIP, SORRY, COMPUTING, CREATIVE, JERSEY, THE, E, TIME, WITHIN, YOU, CAR, A, AT, PROBLEM, NO, D, DOES, V, ANOTHER, HOURS, YES, DISTANCE, SPEED, T, WERE, LESS, TRAIN, GOOD, IN, CORRECT;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 1 PRINT TAB(33);"TRAIN" */
line_1:
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "TRAIN"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT: PRINT: PRINT */
line_3:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 4 PRINT "TIME - SPEED DISTANCE EXERCISE": PRINT */
line_4:
    printf("%s", "TIME - SPEED DISTANCE EXERCISE"); printf("\n");
    printf("\n");
    /* BASIC: 10 C=INT(25*RND(1))+40 */
line_10:
    C = floor(25*((double)rand() / (double)RAND_MAX))+40;
    /* BASIC: 15 D=INT(15*RND(1))+5 */
line_15:
    D = floor(15*((double)rand() / (double)RAND_MAX))+5;
    /* BASIC: 20 T=INT(19*RND(1))+20 */
line_20:
    T = floor(19*((double)rand() / (double)RAND_MAX))+20;
    /* BASIC: 25 PRINT " A CAR TRAVELING";C;"MPH CAN MAKE A CERTAIN TRIP IN" */
line_25:
    printf("%s", " A CAR TRAVELING"); printf("%g ", (double)(C)); printf("%s", "MPH CAN MAKE A CERTAIN TRIP IN"); printf("\n");
    /* BASIC: 30 PRINT D;"HOURS LESS THAN A TRAIN TRAVELING AT";T;"MPH." */
line_30:
    printf("%g ", (double)(D)); printf("%s", "HOURS LESS THAN A TRAIN TRAVELING AT"); printf("%g ", (double)(T)); printf("%s", "MPH."); printf("\n");
    /* BASIC: 35 PRINT "HOW LONG DOES THE TRIP TAKE BY CAR"; */
line_35:
    printf("%s", "HOW LONG DOES THE TRIP TAKE BY CAR");
    /* BASIC: 40 INPUT A */
line_40:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &A);
    /* BASIC: 45 V=D*T/(C-T) */
line_45:
    V = D*T/(C-T);
    /* BASIC: 50 E=INT(ABS((V-A)*100/A)+.5) */
line_50:
    E = floor(fabs((V-A)*100/A)+.5);
    /* BASIC: 55 IF E>5 THEN 70 */
line_55:
    if (E>5) goto line_70;
    /* BASIC: 60 PRINT "GOOD! ANSWER WITHIN";E;"PERCENT." */
line_60:
    printf("%s", "GOOD! ANSWER WITHIN"); printf("%g ", (double)(E)); printf("%s", "PERCENT."); printf("\n");
    /* BASIC: 65 GOTO 80 */
line_65:
    goto line_80;
    /* BASIC: 70 PRINT "SORRY.  YOU WERE OFF BY";E;"PERCENT." */
line_70:
    printf("%s", "SORRY.  YOU WERE OFF BY"); printf("%g ", (double)(E)); printf("%s", "PERCENT."); printf("\n");
    /* BASIC: 80 PRINT "CORRECT ANSWER IS";V;"HOURS." */
line_80:
    printf("%s", "CORRECT ANSWER IS"); printf("%g ", (double)(V)); printf("%s", "HOURS."); printf("\n");
    /* BASIC: 90 PRINT */
line_90:
    printf("\n");
    /* BASIC: 95 PRINT "ANOTHER PROBLEM (YES OR NO)"; */
line_95:
    printf("%s", "ANOTHER PROBLEM (YES OR NO)");
    /* BASIC: 100 INPUT A$ */
line_100:
    printf("? "); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    /* BASIC: 105 PRINT */
line_105:
    printf("\n");
    /* BASIC: 110 IF A$="YES" THEN 10 */
line_110:
    if (A$=="YES") goto line_10;
    /* BASIC: 999 END */
line_999:
    exit(0);

    return 0;
}
