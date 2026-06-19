/*
 * Transpiled from kinema.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double OUT, ABS, BE, MORRISTOWN, UNTIL, GO, HOW, IS, NEW, LONG, OF, ANSWER, ENOUGH, ITS, WILL, COMPUTING, CREATIVE, JERSEY, METERS, SECONDS, BALL, THROWN, A, EVEN, WHAT, AT, BAD, CLOSE, RIGHT, RETURNS, V, IT, SECOND, VELOCITY, UPWARDS, KINEMA, HIGH, PER, AFTER, T, G, Q, IN, CORRECT;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 10 PRINT TAB(33);"KINEMA" */
line_10:
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "KINEMA"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT: PRINT: PRINT */
line_30:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 100 PRINT */
line_100:
    printf("\n");
    /* BASIC: 105 PRINT */
line_105:
    printf("\n");
    /* BASIC: 106 Q=0 */
line_106:
    Q = 0;
    /* BASIC: 110 V=5+INT(35*RND(1)) */
line_110:
    V = 5+floor(35*((double)rand() / (double)RAND_MAX));
    /* BASIC: 111 PRINT "A BALL IS THROWN UPWARDS AT";V;"METERS PER SECOND." */
line_111:
    printf("%s", "A BALL IS THROWN UPWARDS AT"); printf("%g ", (double)(V)); printf("%s", "METERS PER SECOND."); printf("\n");
    /* BASIC: 112 PRINT */
line_112:
    printf("\n");
    /* BASIC: 115 A=.05*V^2 */
line_115:
    A = .05*V^2;
    /* BASIC: 116 PRINT "HOW HIGH WILL IT GO (IN METERS)"; */
line_116:
    printf("%s", "HOW HIGH WILL IT GO (IN METERS)");
    /* BASIC: 117 GOSUB 500 */
line_117:
    /* TODO: GOSUB 500 */
    /* BASIC: 120 A=V/5 */
line_120:
    A = V/5;
    /* BASIC: 122 PRINT "HOW LONG UNTIL IT RETURNS (IN SECONDS)"; */
line_122:
    printf("%s", "HOW LONG UNTIL IT RETURNS (IN SECONDS)");
    /* BASIC: 124 GOSUB 500 */
line_124:
    /* TODO: GOSUB 500 */
    /* BASIC: 130 T=1+INT(2*V*RND(1))/10 */
line_130:
    T = 1+floor(2*V*((double)rand() / (double)RAND_MAX))/10;
    /* BASIC: 132 A=V-10*T */
line_132:
    A = V-10*T;
    /* BASIC: 134 PRINT "WHAT WILL ITS VELOCITY BE AFTER";T;"SECONDS"; */
line_134:
    printf("%s", "WHAT WILL ITS VELOCITY BE AFTER"); printf("%g ", (double)(T)); printf("%s", "SECONDS");
    /* BASIC: 136 GOSUB 500 */
line_136:
    /* TODO: GOSUB 500 */
    /* BASIC: 140 PRINT */
line_140:
    printf("\n");
    /* BASIC: 150 PRINT Q;"RIGHT OUT OF 3."; */
line_150:
    printf("%g ", (double)(Q)); printf("%s", "RIGHT OUT OF 3.");
    /* BASIC: 160 IF Q<2 THEN 100 */
line_160:
    if (Q<2) goto line_100;
    /* BASIC: 170 PRINT "  NOT BAD." */
line_170:
    printf("%s", "  NOT BAD."); printf("\n");
    /* BASIC: 180 GOTO 100 */
line_180:
    goto line_100;
    /* BASIC: 500 INPUT G */
line_500:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &G);
    /* BASIC: 502 IF ABS((G-A)/A)<.15 THEN 510 */
line_502:
    if (fabs((G-A)/A)<.15) goto line_510;
    /* BASIC: 504 PRINT "NOT EVEN CLOSE...." */
line_504:
    printf("%s", "NOT EVEN CLOSE...."); printf("\n");
    /* BASIC: 506 GOTO 512 */
line_506:
    goto line_512;
    /* BASIC: 510 PRINT "CLOSE ENOUGH." */
line_510:
    printf("%s", "CLOSE ENOUGH."); printf("\n");
    /* BASIC: 511 Q=Q+1 */
line_511:
    Q = Q+1;
    /* BASIC: 512 PRINT "CORRECT ANSWER IS ";A */
line_512:
    printf("%s", "CORRECT ANSWER IS "); printf("%g ", (double)(A)); printf("\n");
    /* BASIC: 520 PRINT */
line_520:
    printf("\n");
    /* BASIC: 530 RETURN */
line_530:
    /* TODO: RETURN */
    /* BASIC: 999 END */
line_999:
    exit(0);

    return 0;
}
