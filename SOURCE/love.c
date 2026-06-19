/*
 * Transpiled from love.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double LOVE, MESSAGE, BE, READ, AMERICAN, MORRISTOWN, MID, ARTIST, WORD, P, C, DATA, J, NEW, TYPE, CHOICE, GREATEST, OF, CAN, CHARACTERS, GREAT, WILL, COMPUTING, CREATIVE, JERSEY, THE, THINK, HIS, PLEASE, YOU, INDIANA, A, L, ROBERT, TRIBUTE, WORK, WITH, UP, A1, SIMPLE, T, REPRODUCED, YOUR, I;
    char T_str[1000][256] = {0}; /* Static string array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 2 PRINT TAB(33);"LOVE" */
line_2:
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "LOVE"); printf("\n");
    /* BASIC: 4 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 6 PRINT: PRINT: PRINT */
line_6:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 20 PRINT "A TRIBUTE TO THE GREAT AMERICAN ARTIST, ROBERT INDIANA." */
line_20:
    printf("%s", "A TRIBUTE TO THE GREAT AMERICAN ARTIST, ROBERT INDIANA."); printf("\n");
    /* BASIC: 30 PRINT "HIS GREATEST WORK WILL BE REPRODUCED WITH A MESSAGE OF" */
line_30:
    printf("%s", "HIS GREATEST WORK WILL BE REPRODUCED WITH A MESSAGE OF"); printf("\n");
    /* BASIC: 40 PRINT "YOUR CHOICE UP TO 60 CHARACTERS.  IF YOU CAN'T THINK OF" */
line_40:
    printf("%s", "YOUR CHOICE UP TO 60 CHARACTERS.  IF YOU CAN'T THINK OF"); printf("\n");
    /* BASIC: 50 PRINT "A MESSAGE, SIMPLE TYPE THE WORD 'LOVE'": PRINT */
line_50:
    printf("%s", "A MESSAGE, SIMPLE TYPE THE WORD 'LOVE'"); printf("\n");
    printf("\n");
    /* BASIC: 60 INPUT "YOUR MESSAGE, PLEASE";A$: L=LEN(A$) */
line_60:
    printf("%s", "YOUR MESSAGE, PLEASE"); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    L = LEN(A$);
    /* BASIC: 70 DIM T$(120): FOR I=1 TO 10: PRINT: NEXT I */
line_70:
    /* DIM T$(120) (handled statically) */
    I = 1; for_loop_I: if ((1 >= 0 && I > 10) || (1 < 0 && I < 10)) goto end_for_I;
    printf("\n");
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 100 FOR J=0 TO INT(60/L) */
line_100:
    J = 0; for_loop_J: if ((1 >= 0 && J > floor(60/L)) || (1 < 0 && J < floor(60/L))) goto end_for_J;
    /* BASIC: 110 FOR I=1 TO L */
line_110:
    I = 1; for_loop_I: if ((1 >= 0 && I > L) || (1 < 0 && I < L)) goto end_for_I;
    /* BASIC: 120 T$(J*L+I)=MID$(A$,I,1) */
line_120:
    T$(J*L+I) = MID$(A$,I,1);
    /* BASIC: 130 NEXT I: NEXT J */
line_130:
    I += 1; goto for_loop_I; end_for_I:;
    J += 1; goto for_loop_J; end_for_J:;
    /* BASIC: 140 C=0 */
line_140:
    C = 0;
    /* BASIC: 200 A1=1: P=1: C=C+1: IF C=37 THEN 999 */
line_200:
    A1 = 1;
    P = 1;
    C = C+1;
    if (C==37) goto line_999;
    /* BASIC: 205 PRINT */
line_205:
    printf("\n");
    /* BASIC: 210 READ A: A1=A1+A: IF P=1 THEN 300 */
line_210:
    /* UNTRANSLATED: READ A */
    A1 = A1+A;
    if (P==1) goto line_300;
    /* BASIC: 240 FOR I=1 TO A: PRINT " ";: NEXT I: P=1: GOTO 400 */
line_240:
    I = 1; for_loop_I: if ((1 >= 0 && I > A) || (1 < 0 && I < A)) goto end_for_I;
    printf("%s", " ");
    I += 1; goto for_loop_I; end_for_I:;
    P = 1;
    goto line_400;
    /* BASIC: 300 FOR I=A1-A TO A1-1: PRINT T$(I);: NEXT I: P=0 */
line_300:
    I = A1-A; for_loop_I: if ((1 >= 0 && I > A1-1) || (1 < 0 && I < A1-1)) goto end_for_I;
    printf("%g ", (double)(T$(I)));
    I += 1; goto for_loop_I; end_for_I:;
    P = 0;
    /* BASIC: 400 IF A1>60 THEN 200 */
line_400:
    if (A1>60) goto line_200;
    /* BASIC: 410 GOTO 210 */
line_410:
    goto line_210;
    /* BASIC: 600 DATA 60,1,12,26,9,12,3,8,24,17,8,4,6,23,21,6,4,6,22,12,5,6,5 */
line_600:
    /* UNTRANSLATED: DATA 60,1,12,26,9,12,3,8,24,17,8,4,6,23,21,6,4,6,22,12,5,6,5 */
    /* BASIC: 610 DATA 4,6,21,11,8,6,4,4,6,21,10,10,5,4,4,6,21,9,11,5,4 */
line_610:
    /* UNTRANSLATED: DATA 4,6,21,11,8,6,4,4,6,21,10,10,5,4,4,6,21,9,11,5,4 */
    /* BASIC: 620 DATA 4,6,21,8,11,6,4,4,6,21,7,11,7,4,4,6,21,6,11,8,4 */
line_620:
    /* UNTRANSLATED: DATA 4,6,21,8,11,6,4,4,6,21,7,11,7,4,4,6,21,6,11,8,4 */
    /* BASIC: 630 DATA 4,6,19,1,1,5,11,9,4,4,6,19,1,1,5,10,10,4,4,6,18,2,1,6,8,11,4 */
line_630:
    /* UNTRANSLATED: DATA 4,6,19,1,1,5,11,9,4,4,6,19,1,1,5,10,10,4,4,6,18,2,1,6,8,11,4 */
    /* BASIC: 640 DATA 4,6,17,3,1,7,5,13,4,4,6,15,5,2,23,5,1,29,5,17,8 */
line_640:
    /* UNTRANSLATED: DATA 4,6,17,3,1,7,5,13,4,4,6,15,5,2,23,5,1,29,5,17,8 */
    /* BASIC: 650 DATA 1,29,9,9,12,1,13,5,40,1,1,13,5,40,1,4,6,13,3,10,6,12,5,1 */
line_650:
    /* UNTRANSLATED: DATA 1,29,9,9,12,1,13,5,40,1,1,13,5,40,1,4,6,13,3,10,6,12,5,1 */
    /* BASIC: 660 DATA 5,6,11,3,11,6,14,3,1,5,6,11,3,11,6,15,2,1 */
line_660:
    /* UNTRANSLATED: DATA 5,6,11,3,11,6,14,3,1,5,6,11,3,11,6,15,2,1 */
    /* BASIC: 670 DATA 6,6,9,3,12,6,16,1,1,6,6,9,3,12,6,7,1,10 */
line_670:
    /* UNTRANSLATED: DATA 6,6,9,3,12,6,16,1,1,6,6,9,3,12,6,7,1,10 */
    /* BASIC: 680 DATA 7,6,7,3,13,6,6,2,10,7,6,7,3,13,14,10,8,6,5,3,14,6,6,2,10 */
line_680:
    /* UNTRANSLATED: DATA 7,6,7,3,13,6,6,2,10,7,6,7,3,13,14,10,8,6,5,3,14,6,6,2,10 */
    /* BASIC: 690 DATA 8,6,5,3,14,6,7,1,10,9,6,3,3,15,6,16,1,1 */
line_690:
    /* UNTRANSLATED: DATA 8,6,5,3,14,6,7,1,10,9,6,3,3,15,6,16,1,1 */
    /* BASIC: 700 DATA 9,6,3,3,15,6,15,2,1,10,6,1,3,16,6,14,3,1,10,10,16,6,12,5,1 */
line_700:
    /* UNTRANSLATED: DATA 9,6,3,3,15,6,15,2,1,10,6,1,3,16,6,14,3,1,10,10,16,6,12,5,1 */
    /* BASIC: 710 DATA 11,8,13,27,1,11,8,13,27,1,60 */
line_710:
    /* UNTRANSLATED: DATA 11,8,13,27,1,11,8,13,27,1,60 */
    /* BASIC: 999 FOR I=1 TO 10: PRINT: NEXT I: END */
line_999:
    I = 1; for_loop_I: if ((1 >= 0 && I > 10) || (1 < 0 && I < 10)) goto end_for_I;
    printf("\n");
    I += 1; goto for_loop_I; end_for_I:;
    exit(0);

    return 0;
}
