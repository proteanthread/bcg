/*
 * Transpiled from life.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double ENTER, Y, MORRISTOWN, MID, P, B, C, J, NEW, GENERATION, COMPUTING, CREATIVE, JERSEY, Y4, Y2, POPULATION, DONE, Y3, PATTERN, I9, LIFE, LEFT, X, Y1, X2, L, RIGHT, X1, G, INVALID, X3, YOUR, I, X4;
    double A[1000] = {0}; /* Static array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 2 PRINT TAB(34);"LIFE" */
line_2:
    { int _t; for(_t=0; _t<34; _t++) printf(" "); } printf("%s", "LIFE"); printf("\n");
    /* BASIC: 4 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 6 PRINT: PRINT: PRINT */
line_6:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 8 PRINT "ENTER YOUR PATTERN:" */
line_8:
    printf("%s", "ENTER YOUR PATTERN:"); printf("\n");
    /* BASIC: 9 X1=1: Y1=1: X2=24: Y2=70 */
line_9:
    X1 = 1;
    Y1 = 1;
    X2 = 24;
    Y2 = 70;
    /* BASIC: 10 DIM A(24,70),B$(24) */
line_10:
    /* DIM A(24,70),B$(24) (handled statically) */
    /* BASIC: 20 C=1 */
line_20:
    C = 1;
    /* BASIC: 30 INPUT B$(C) */
line_30:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &B$(C));
    /* BASIC: 40 IF B$(C)="DONE" THEN B$(C)="": GOTO 80 */
line_40:
    if (B$(C)=="DONE") { B$(C) = ""; }
    goto line_80;
    /* BASIC: 50 IF LEFT$(B$(C),1)="." THEN B$(C)=" "+RIGHT$(B$(C),LEN(B$(C))-1) */
line_50:
    if (LEFT$(B$(C),1)==".") { B$(C) = " "+RIGHT$(B$(C),LEN(B$(C))-1); }
    /* BASIC: 60 C=C+1 */
line_60:
    C = C+1;
    /* BASIC: 70 GOTO 30 */
line_70:
    goto line_30;
    /* BASIC: 80 C=C-1: L=0 */
line_80:
    C = C-1;
    L = 0;
    /* BASIC: 90 FOR X=1 TO C-1 */
line_90:
    X = 1; for_loop_X: if ((1 >= 0 && X > C-1) || (1 < 0 && X < C-1)) goto end_for_X;
    /* BASIC: 100 IF LEN(B$(X))>L THEN L=LEN(B$(X)) */
line_100:
    if (LEN(B$(X))>L) { L = LEN(B$(X)); }
    /* BASIC: 110 NEXT X */
line_110:
    X += 1; goto for_loop_X; end_for_X:;
    /* BASIC: 120 X1=11-C/2 */
line_120:
    X1 = 11-C/2;
    /* BASIC: 130 Y1=33-L/2 */
line_130:
    Y1 = 33-L/2;
    /* BASIC: 140 FOR X=1 TO C */
line_140:
    X = 1; for_loop_X: if ((1 >= 0 && X > C) || (1 < 0 && X < C)) goto end_for_X;
    /* BASIC: 150 FOR Y=1 TO LEN(B$(X)) */
line_150:
    Y = 1; for_loop_Y: if ((1 >= 0 && Y > LEN(B$(X))) || (1 < 0 && Y < LEN(B$(X)))) goto end_for_Y;
    /* BASIC: 160 IF MID$(B$(X),Y,1)<>" " THEN A(X1+X,Y1+Y)=1:P=P+1 */
line_160:
    if (MID$(B$(X),Y,1)!=" ") { A(X1+X,Y1+Y) = 1; }
    P = P+1;
    /* BASIC: 170 NEXT Y */
line_170:
    Y += 1; goto for_loop_Y; end_for_Y:;
    /* BASIC: 180 NEXT X */
line_180:
    X += 1; goto for_loop_X; end_for_X:;
    /* BASIC: 200 PRINT:PRINT:PRINT */
line_200:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 210 PRINT "GENERATION:";G,"POPULATION:";P;: IF I9 THEN PRINT "INVALID!"; */
line_210:
    printf("%s", "GENERATION:"); printf("%g ", (double)(G)); printf("\t"); printf("%s", "POPULATION:"); printf("%g ", (double)(P));
    if (I9) { printf("%s", "INVALID!"); }
    /* BASIC: 215 X3=24:Y3=70:X4=1: Y4=1: P=0 */
line_215:
    X3 = 24;
    Y3 = 70;
    X4 = 1;
    Y4 = 1;
    P = 0;
    /* BASIC: 220 G=G+1 */
line_220:
    G = G+1;
    /* BASIC: 225 FOR X=1 TO X1-1: PRINT: NEXT X */
line_225:
    X = 1; for_loop_X: if ((1 >= 0 && X > X1-1) || (1 < 0 && X < X1-1)) goto end_for_X;
    printf("\n");
    X += 1; goto for_loop_X; end_for_X:;
    /* BASIC: 230 FOR X=X1 TO X2 */
line_230:
    X = X1; for_loop_X: if ((1 >= 0 && X > X2) || (1 < 0 && X < X2)) goto end_for_X;
    /* BASIC: 240 PRINT */
line_240:
    printf("\n");
    /* BASIC: 250 FOR Y=Y1 TO Y2 */
line_250:
    Y = Y1; for_loop_Y: if ((1 >= 0 && Y > Y2) || (1 < 0 && Y < Y2)) goto end_for_Y;
    /* BASIC: 253 IF A(X,Y)=2 THEN A(X,Y)=0:GOTO 270 */
line_253:
    if (A(X,Y)==2) { A(X,Y) = 0; }
    goto line_270;
    /* BASIC: 256 IF A(X,Y)=3 THEN A(X,Y)=1:GOTO 261 */
line_256:
    if (A(X,Y)==3) { A(X,Y) = 1; }
    goto line_261;
    /* BASIC: 260 IF A(X,Y)<>1 THEN 270 */
line_260:
    if (A(X,Y)!=1) goto line_270;
    /* BASIC: 261 PRINT TAB(Y);"*"; */
line_261:
    { int _t; for(_t=0; _t<Y; _t++) printf(" "); } printf("%s", "*");
    /* BASIC: 262 IF X<X3 THEN X3=X */
line_262:
    if (X<X3) { X3 = X; }
    /* BASIC: 264 IF X>X4 THEN X4=X */
line_264:
    if (X>X4) { X4 = X; }
    /* BASIC: 266 IF Y<Y3 THEN Y3=Y */
line_266:
    if (Y<Y3) { Y3 = Y; }
    /* BASIC: 268 IF Y>Y4 THEN Y4=Y */
line_268:
    if (Y>Y4) { Y4 = Y; }
    /* BASIC: 270 NEXT Y */
line_270:
    Y += 1; goto for_loop_Y; end_for_Y:;
    /* BASIC: 290 NEXT X */
line_290:
    X += 1; goto for_loop_X; end_for_X:;
    /* BASIC: 295 FOR X=X2+1 TO 24: PRINT: NEXT X */
line_295:
    X = X2+1; for_loop_X: if ((1 >= 0 && X > 24) || (1 < 0 && X < 24)) goto end_for_X;
    printf("\n");
    X += 1; goto for_loop_X; end_for_X:;
    /* BASIC: 299 X1=X3: X2=X4: Y1=Y3: Y2=Y4 */
line_299:
    X1 = X3;
    X2 = X4;
    Y1 = Y3;
    Y2 = Y4;
    /* BASIC: 301 IF X1<3 THEN X1=3:I9=-1 */
line_301:
    if (X1<3) { X1 = 3; }
    I9 = -1;
    /* BASIC: 303 IF X2>22 THEN X2=22:I9=-1 */
line_303:
    if (X2>22) { X2 = 22; }
    I9 = -1;
    /* BASIC: 305 IF Y1<3 THEN Y1=3:I9=-1 */
line_305:
    if (Y1<3) { Y1 = 3; }
    I9 = -1;
    /* BASIC: 307 IF Y2>68 THEN Y2=68:I9=-1 */
line_307:
    if (Y2>68) { Y2 = 68; }
    I9 = -1;
    /* BASIC: 309 P=0 */
line_309:
    P = 0;
    /* BASIC: 500 FOR X=X1-1 TO X2+1 */
line_500:
    X = X1-1; for_loop_X: if ((1 >= 0 && X > X2+1) || (1 < 0 && X < X2+1)) goto end_for_X;
    /* BASIC: 510 FOR Y=Y1-1 TO Y2+1 */
line_510:
    Y = Y1-1; for_loop_Y: if ((1 >= 0 && Y > Y2+1) || (1 < 0 && Y < Y2+1)) goto end_for_Y;
    /* BASIC: 520 C=0 */
line_520:
    C = 0;
    /* BASIC: 530 FOR I=X-1 TO X+1 */
line_530:
    I = X-1; for_loop_I: if ((1 >= 0 && I > X+1) || (1 < 0 && I < X+1)) goto end_for_I;
    /* BASIC: 540 FOR J=Y-1 TO Y+1 */
line_540:
    J = Y-1; for_loop_J: if ((1 >= 0 && J > Y+1) || (1 < 0 && J < Y+1)) goto end_for_J;
    /* BASIC: 550 IF A(I,J)=1 OR A(I,J)=2 THEN C=C+1 */
line_550:
    if (A(I,J)==1 || A(I,J)==2) { C = C+1; }
    /* BASIC: 560 NEXT J */
line_560:
    J += 1; goto for_loop_J; end_for_J:;
    /* BASIC: 570 NEXT I */
line_570:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 580 IF A(X,Y)=0 THEN 610 */
line_580:
    if (A(X,Y)==0) goto line_610;
    /* BASIC: 590 IF C<3 OR C>4 THEN A(X,Y)=2: GOTO 600 */
line_590:
    if (C<3 || C>4) { A(X,Y) = 2; }
    goto line_600;
    /* BASIC: 595 P=P+1 */
line_595:
    P = P+1;
    /* BASIC: 600 GOTO 620 */
line_600:
    goto line_620;
    /* BASIC: 610 IF C=3 THEN A(X,Y)=3:P=P+1 */
line_610:
    if (C==3) { A(X,Y) = 3; }
    P = P+1;
    /* BASIC: 620 NEXT Y */
line_620:
    Y += 1; goto for_loop_Y; end_for_Y:;
    /* BASIC: 630 NEXT X */
line_630:
    X += 1; goto for_loop_X; end_for_X:;
    /* BASIC: 635 X1=X1-1:Y1=Y1-1:X2=X2+1:Y2=Y2+1 */
line_635:
    X1 = X1-1;
    Y1 = Y1-1;
    X2 = X2+1;
    Y2 = Y2+1;
    /* BASIC: 640 GOTO 210 */
line_640:
    goto line_210;
    /* BASIC: 650 END */
line_650:
    exit(0);

    return 0;
}
