/*
 * Transpiled from diamond.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double NUMBER, Y, M, MORRISTOWN, MID, C, NEW, TYPE, DIAMOND, Z, COMPUTING, CREATIVE, JERSEY, ODD, PATTERN, X, A, CC, L, BETWEEN, R, N, Q, IN, PRETTY, AN;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 1 PRINT TAB(33);"DIAMOND" */
line_1:
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "DIAMOND"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT:PRINT:PRINT */
line_3:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 4 PRINT "FOR A PRETTY DIAMOND PATTERN," */
line_4:
    printf("%s", "FOR A PRETTY DIAMOND PATTERN,"); printf("\n");
    /* BASIC: 5 INPUT "TYPE IN AN ODD NUMBER BETWEEN 5 AND 21";R:PRINT */
line_5:
    printf("%s", "TYPE IN AN ODD NUMBER BETWEEN 5 AND 21"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &R);
    printf("\n");
    /* BASIC: 6 Q=INT(60/R):A$="CC" */
line_6:
    Q = floor(60/R);
    strncpy(A_str, ""CC"", sizeof(A_str)); /* String assign approx */
    /* BASIC: 8 FOR L=1 TO Q */
line_8:
    L = 1; for_loop_L: if ((1 >= 0 && L > Q) || (1 < 0 && L < Q)) goto end_for_L;
    /* BASIC: 10 X=1:Y=R:Z=2 */
line_10:
    X = 1;
    Y = R;
    Z = 2;
    /* BASIC: 20 FOR N=X TO Y STEP Z */
line_20:
    N = X; for_loop_N: if ((Z >= 0 && N > Y) || (Z < 0 && N < Y)) goto end_for_N;
    /* BASIC: 25 PRINT TAB((R-N)/2); */
line_25:
    { int _t; for(_t=0; _t<(R-N)/2; _t++) printf(" "); }
    /* BASIC: 28 FOR M=1 TO Q */
line_28:
    M = 1; for_loop_M: if ((1 >= 0 && M > Q) || (1 < 0 && M < Q)) goto end_for_M;
    /* BASIC: 29 C=1 */
line_29:
    C = 1;
    /* BASIC: 30 FOR A=1 TO N */
line_30:
    A = 1; for_loop_A: if ((1 >= 0 && A > N) || (1 < 0 && A < N)) goto end_for_A;
    /* BASIC: 32 IF C>LEN(A$) THEN PRINT "!";:GOTO 50 */
line_32:
    if (C>LEN(A$)) { printf("%s", "!"); }
    goto line_50;
    /* BASIC: 34 PRINT MID$(A$,C,1); */
line_34:
    printf("%s", MID$(A_str); printf("\t"); printf("%g ", (double)(C)); printf("\t"); printf("%g ", (double)(1)));
    /* BASIC: 36 C=C+1 */
line_36:
    C = C+1;
    /* BASIC: 50 NEXT A */
line_50:
    A += 1; goto for_loop_A; end_for_A:;
    /* BASIC: 53 IF M=Q THEN 60 */
line_53:
    if (M==Q) goto line_60;
    /* BASIC: 55 PRINT TAB(R*M+(R-N)/2); */
line_55:
    { int _t; for(_t=0; _t<R*M+(R-N)/2; _t++) printf(" "); }
    /* BASIC: 56 NEXT M */
line_56:
    M += 1; goto for_loop_M; end_for_M:;
    /* BASIC: 60 PRINT */
line_60:
    printf("\n");
    /* BASIC: 70 NEXT N */
line_70:
    N += Z; goto for_loop_N; end_for_N:;
    /* BASIC: 83 IF X<>1 THEN 95 */
line_83:
    if (X!=1) goto line_95;
    /* BASIC: 85 X=R-2:Y=1:Z=-2 */
line_85:
    X = R-2;
    Y = 1;
    Z = -2;
    /* BASIC: 90 GOTO 20 */
line_90:
    goto line_20;
    /* BASIC: 95 NEXT L */
line_95:
    L += 1; goto for_loop_L; end_for_L:;
    /* BASIC: 99 END */
line_99:
    exit(0);

    return 0;
}
