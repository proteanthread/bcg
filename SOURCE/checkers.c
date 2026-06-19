/*
 * Transpiled from checkers.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double ABS, REFERRED, FROM, ARE, Y, READ, BY, M, MORRISTOWN, GAME, B, CHR, C, IS, DATA, H, J, MOVE, NEW, TYPE, OF, Z, B1, TWO, CHECKERS, JUMP, S, UPPER, WILL, NEGATIVE, COMPUTING, CREATIVE, JERSEY, THE, CORNER, LOWER, WIN, COMPUTER, E, YOU, X, LEFT, A, L, RIGHT, WHEN, U, V, NUMBERS, COORDINATE, ANOTHER, A1, FIRST, CANNOT, O, T, G, RESTORE, HAVE, SQUARES, I, THIS, SYSTEM, Q;
    double R[1000] = {0}; /* Static array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 5 PRINT TAB(32);"CHECKERS" */
line_5:
    { int _t; for(_t=0; _t<32; _t++) printf(" "); } printf("%s", "CHECKERS"); printf("\n");
    /* BASIC: 10 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_10:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 15 PRINT:PRINT:PRINT */
line_15:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 20 PRINT "THIS IS THE GAME OF CHECKERS.  THE COMPUTER IS X," */
line_20:
    printf("%s", "THIS IS THE GAME OF CHECKERS.  THE COMPUTER IS X,"); printf("\n");
    /* BASIC: 25 PRINT "AND YOU ARE O.  THE COMPUTER WILL MOVE FIRST." */
line_25:
    printf("%s", "AND YOU ARE O.  THE COMPUTER WILL MOVE FIRST."); printf("\n");
    /* BASIC: 30 PRINT "SQUARES ARE REFERRED TO BY A COORDINATE SYSTEM." */
line_30:
    printf("%s", "SQUARES ARE REFERRED TO BY A COORDINATE SYSTEM."); printf("\n");
    /* BASIC: 35 PRINT "(0,0) IS THE LOWER LEFT CORNER" */
line_35:
    printf("%s", "(0,0) IS THE LOWER LEFT CORNER"); printf("\n");
    /* BASIC: 40 PRINT "(0,7) IS THE UPPER LEFT CORNER" */
line_40:
    printf("%s", "(0,7) IS THE UPPER LEFT CORNER"); printf("\n");
    /* BASIC: 45 PRINT "(7,0) IS THE LOWER RIGHT CORNER" */
line_45:
    printf("%s", "(7,0) IS THE LOWER RIGHT CORNER"); printf("\n");
    /* BASIC: 50 PRINT "(7,7) IS THE UPPER RIGHT CORNER" */
line_50:
    printf("%s", "(7,7) IS THE UPPER RIGHT CORNER"); printf("\n");
    /* BASIC: 55 PRINT "THE COMPUTER WILL TYPE '+TO' WHEN YOU HAVE ANOTHER" */
line_55:
    printf("%s", "THE COMPUTER WILL TYPE '+TO' WHEN YOU HAVE ANOTHER"); printf("\n");
    /* BASIC: 60 PRINT "JUMP.  TYPE TWO NEGATIVE NUMBERS IF YOU CANNOT JUMP." */
line_60:
    printf("%s", "JUMP.  TYPE TWO NEGATIVE NUMBERS IF YOU CANNOT JUMP."); printf("\n");
    /* BASIC: 65 PRINT:PRINT:PRINT */
line_65:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 80 DIM R(4),S(7,7):G=-1:R(0)=-99 */
line_80:
    /* DIM R(4),S(7,7) (handled statically) */
    G = -1;
    R(0) = -99;
    /* BASIC: 90 DATA 1,0,1,0,0,0,-1,0,0,1,0,0,0,-1,0,-1,15 */
line_90:
    /* UNTRANSLATED: DATA 1,0,1,0,0,0,-1,0,0,1,0,0,0,-1,0,-1,15 */
    /* BASIC: 120 FOR X=0 TO 7:FOR Y=0 TO 7:READ J:IF J=15 THEN 180 */
line_120:
    X = 0; for_loop_X: if ((1 >= 0 && X > 7) || (1 < 0 && X < 7)) goto end_for_X;
    Y = 0; for_loop_Y: if ((1 >= 0 && Y > 7) || (1 < 0 && Y < 7)) goto end_for_Y;
    /* UNTRANSLATED: READ J */
    if (J==15) goto line_180;
    /* BASIC: 160 S(X,Y)=J:GOTO 200 */
line_160:
    S(X,Y) = J;
    goto line_200;
    /* BASIC: 180 RESTORE:READ S(X,Y) */
line_180:
    /* UNTRANSLATED: RESTORE */
    /* UNTRANSLATED: READ S(X,Y) */
    /* BASIC: 200 NEXT Y,X */
line_200:
    /* TODO: NEXT (unmatched) */
    /* BASIC: 230 FOR X=0 TO 7:FOR Y=0 TO 7:IF S(X,Y)>-1 THEN 350 */
line_230:
    X = 0; for_loop_X: if ((1 >= 0 && X > 7) || (1 < 0 && X < 7)) goto end_for_X;
    Y = 0; for_loop_Y: if ((1 >= 0 && Y > 7) || (1 < 0 && Y < 7)) goto end_for_Y;
    if (S(X,Y)>-1) goto line_350;
    /* BASIC: 310 IF S(X,Y)=-1 THEN FOR A=-1 TO 1 STEP 2:B=G:GOSUB 650:NEXT A */
line_310:
    if (S(X,Y)==-1) { A = -1; for_loop_A: if ((2 >= 0 && A > 1) || (2 < 0 && A < 1)) goto end_for_A; }
    B = G;
    /* TODO: GOSUB 650 */
    A += 2; goto for_loop_A; end_for_A:;
    /* BASIC: 330 IF S(X,Y)=-2 THEN FOR A=-1 TO 1 STEP 2:FOR B=-1 TO 1 STEP 2:GOSUB 650:NEXT B,A */
line_330:
    if (S(X,Y)==-2) { A = -1; for_loop_A: if ((2 >= 0 && A > 1) || (2 < 0 && A < 1)) goto end_for_A; }
    B = -1; for_loop_B: if ((2 >= 0 && B > 1) || (2 < 0 && B < 1)) goto end_for_B;
    /* TODO: GOSUB 650 */
    /* TODO: NEXT (unmatched) */
    /* BASIC: 350 NEXT Y,X:GOTO 1140 */
line_350:
    /* TODO: NEXT (unmatched) */
    goto line_1140;
    /* BASIC: 650 U=X+A:V=Y+B:IF U<0 OR U>7 OR V<0 OR V>7 THEN 870 */
line_650:
    U = X+A;
    V = Y+B;
    if (U<0 || U>7 || V<0 || V>7) goto line_870;
    /* BASIC: 740 IF S(U,V)=0 THEN GOSUB 910:GOTO 870 */
line_740:
    if (S(U,V)==0) { /* TODO: GOSUB 910 */ }
    goto line_870;
    /* BASIC: 770 IF S(U,V)<0 THEN 870 */
line_770:
    if (S(U,V)<0) goto line_870;
    /* BASIC: 790 U=U+A:V=V+B:IF U<0 OR V<0 OR U>7 OR V>7 THEN 870 */
line_790:
    U = U+A;
    V = V+B;
    if (U<0 || V<0 || U>7 || V>7) goto line_870;
    /* BASIC: 850 IF S(U,V)=0 THEN GOSUB 910 */
line_850:
    if (S(U,V)==0) { /* TODO: GOSUB 910 */ }
    /* BASIC: 870 RETURN */
line_870:
    /* TODO: RETURN */
    /* BASIC: 910 IF V=0 AND S(X,Y)=-1 THEN Q=Q+2 */
line_910:
    if (V==0 && S(X,Y)==-1) { Q = Q+2; }
    /* BASIC: 920 IF ABS(Y-V)=2 THEN Q=Q+5 */
line_920:
    if (fabs(Y-V)==2) { Q = Q+5; }
    /* BASIC: 960 IF Y=7 THEN Q=Q-2 */
line_960:
    if (Y==7) { Q = Q-2; }
    /* BASIC: 980 IF U=0 OR U=7 THEN Q=Q+1 */
line_980:
    if (U==0 || U==7) { Q = Q+1; }
    /* BASIC: 1030 FOR C=-1 TO 1 STEP 2:IF U+C<0 OR U+C>7 OR V+G<0 THEN 1080 */
line_1030:
    C = -1; for_loop_C: if ((2 >= 0 && C > 1) || (2 < 0 && C < 1)) goto end_for_C;
    if (U+C<0 || U+C>7 || V+G<0) goto line_1080;
    /* BASIC: 1035 IF S(U+C,V+G)<0 THEN Q=Q+1:GOTO 1080 */
line_1035:
    if (S(U+C,V+G)<0) { Q = Q+1; }
    goto line_1080;
    /* BASIC: 1040 IF U-C<0 OR U-C>7 OR V-G>7 THEN 1080 */
line_1040:
    if (U-C<0 || U-C>7 || V-G>7) goto line_1080;
    /* BASIC: 1045 IF S(U+C,V+G)>0 AND(S(U-C,V-G)=0 OR(U-C=X AND V-G=Y))THEN Q=Q-2 */
line_1045:
    /* UNTRANSLATED: IF S(U+C,V+G)>0 AND(S(U-C,V-G)=0 OR(U-C=X AND V-G=Y))THEN Q=Q-2 */
    /* BASIC: 1080 NEXT C:IF Q>R(0)THEN R(0)=Q:R(1)=X:R(2)=Y:R(3)=U:R(4)=V */
line_1080:
    C += 2; goto for_loop_C; end_for_C:;
    /* UNTRANSLATED: IF Q>R(0)THEN R(0)=Q */
    R(1) = X;
    R(2) = Y;
    R(3) = U;
    R(4) = V;
    /* BASIC: 1100 Q=0:RETURN */
line_1100:
    Q = 0;
    /* TODO: RETURN */
    /* BASIC: 1140 IF R(0)=-99 THEN 1880 */
line_1140:
    if (R(0)==-99) goto line_1880;
    /* BASIC: 1230 PRINT CHR$(30)"FROM"R(1);R(2)"TO"R(3);R(4);:R(0)=-99 */
line_1230:
    printf("%g ", (double)(CHR$(30)"FROM"R(1))); printf("%g ", (double)(R(2)"TO"R(3))); printf("%g ", (double)(R(4)));
    R(0) = -99;
    /* BASIC: 1240 IF R(4)=0 THEN S(R(3),R(4))=-2:GOTO 1420 */
line_1240:
    if (R(4)==0) { S(R(3),R(4)) = -2; }
    goto line_1420;
    /* BASIC: 1250 S(R(3),R(4))=S(R(1),R(2)) */
line_1250:
    S(R(3),R(4)) = S(R(1),R(2));
    /* BASIC: 1310 S(R(1),R(2))=0:IF ABS(R(1)-R(3))<>2 THEN 1420 */
line_1310:
    S(R(1),R(2)) = 0;
    if (fabs(R(1)-R(3))!=2) goto line_1420;
    /* BASIC: 1330 S((R(1)+R(3))/2,(R(2)+R(4))/2)=0 */
line_1330:
    S((R(1)+R(3))/2,(R(2)+R(4))/2) = 0;
    /* BASIC: 1340 X=R(3):Y=R(4):IF S(X,Y)=-1 THEN B=-2:FOR A=-2 TO 2 STEP 4:GOSUB 1370 */
line_1340:
    X = R(3);
    Y = R(4);
    if (S(X,Y)==-1) { B = -2; }
    A = -2; for_loop_A: if ((4 >= 0 && A > 2) || (4 < 0 && A < 2)) goto end_for_A;
    /* TODO: GOSUB 1370 */
    /* BASIC: 1350 IF S(X,Y)=-2 THEN FOR A=-2 TO 2 STEP 4:FOR B=-2 TO 2 STEP 4:GOSUB 1370:NEXT B */
line_1350:
    if (S(X,Y)==-2) { A = -2; for_loop_A: if ((4 >= 0 && A > 2) || (4 < 0 && A < 2)) goto end_for_A; }
    B = -2; for_loop_B: if ((4 >= 0 && B > 2) || (4 < 0 && B < 2)) goto end_for_B;
    /* TODO: GOSUB 1370 */
    B += 4; goto for_loop_B; end_for_B:;
    /* BASIC: 1360 NEXT A:IF R(0)<>-99 THEN PRINT"TO"R(3);R(4);:R(0)=-99:GOTO 1240 */
line_1360:
    A += 4; goto for_loop_A; end_for_A:;
    if (R(0)!=-99) { printf("%g ", (double)("TO"R(3))); printf("%g ", (double)(R(4))); }
    R(0) = -99;
    goto line_1240;
    /* BASIC: 1365 GOTO 1420 */
line_1365:
    goto line_1420;
    /* BASIC: 1370 U=X+A:V=Y+B:IF U<0 OR U>7 OR V<0 OR V>7 THEN 1400 */
line_1370:
    U = X+A;
    V = Y+B;
    if (U<0 || U>7 || V<0 || V>7) goto line_1400;
    /* BASIC: 1380 IF S(U,V)=0 AND S(X+A/2,Y+B/2)>0 THEN GOSUB 910 */
line_1380:
    if (S(U,V)==0 && S(X+A/2,Y+B/2)>0) { /* TODO: GOSUB 910 */ }
    /* BASIC: 1400 RETURN */
line_1400:
    /* TODO: RETURN */
    /* BASIC: 1420 PRINT:PRINT:PRINT:FOR Y=7 TO 0 STEP-1:FOR X=0 TO 7:I=5*X:PRINT TAB(I); */
line_1420:
    printf("\n");
    printf("\n");
    printf("\n");
    Y = 7; for_loop_Y: if ((1 >= 0 && Y > 0 STEP-1) || (1 < 0 && Y < 0 STEP-1)) goto end_for_Y;
    X = 0; for_loop_X: if ((1 >= 0 && X > 7) || (1 < 0 && X < 7)) goto end_for_X;
    I = 5*X;
    { int _t; for(_t=0; _t<I; _t++) printf(" "); }
    /* BASIC: 1430 IF S(X,Y)=0 THEN PRINT"."; */
line_1430:
    if (S(X,Y)==0) { printf("%s", "."); }
    /* BASIC: 1470 IF S(X,Y)=1 THEN PRINT"O"; */
line_1470:
    if (S(X,Y)==1) { printf("%s", "O"); }
    /* BASIC: 1490 IF S(X,Y)=-1 THEN PRINT"X"; */
line_1490:
    if (S(X,Y)==-1) { printf("%s", "X"); }
    /* BASIC: 1510 IF S(X,Y)=-2 THEN PRINT"X*"; */
line_1510:
    if (S(X,Y)==-2) { printf("%s", "X*"); }
    /* BASIC: 1530 IF S(X,Y)=2 THEN PRINT"O*"; */
line_1530:
    if (S(X,Y)==2) { printf("%s", "O*"); }
    /* BASIC: 1550 NEXT X:PRINT" ":PRINT:NEXT Y:PRINT */
line_1550:
    X += 1; goto for_loop_X; end_for_X:;
    printf("%s", " "); printf("\n");
    printf("\n");
    Y += 1; goto for_loop_Y; end_for_Y:;
    printf("\n");
    /* BASIC: 1552 FOR L=0 TO 7 */
line_1552:
    L = 0; for_loop_L: if ((1 >= 0 && L > 7) || (1 < 0 && L < 7)) goto end_for_L;
    /* BASIC: 1554 FOR M=0 TO 7 */
line_1554:
    M = 0; for_loop_M: if ((1 >= 0 && M > 7) || (1 < 0 && M < 7)) goto end_for_M;
    /* BASIC: 1556 IF S(L,M)=1 OR S(L,M)=2 THEN Z=1 */
line_1556:
    if (S(L,M)==1 || S(L,M)==2) { Z = 1; }
    /* BASIC: 1558 IF S(L,M)=-1 OR S(L,M)=-2 THEN T=1 */
line_1558:
    if (S(L,M)==-1 || S(L,M)==-2) { T = 1; }
    /* BASIC: 1560 NEXT M */
line_1560:
    M += 1; goto for_loop_M; end_for_M:;
    /* BASIC: 1562 NEXT L */
line_1562:
    L += 1; goto for_loop_L; end_for_L:;
    /* BASIC: 1564 IF Z<>1 THEN 1885 */
line_1564:
    if (Z!=1) goto line_1885;
    /* BASIC: 1566 IF T<>1 THEN 1880 */
line_1566:
    if (T!=1) goto line_1880;
    /* BASIC: 1570 Z=0: T=0 */
line_1570:
    Z = 0;
    T = 0;
    /* BASIC: 1590 INPUT "FROM";E,H:X=E:Y=H:IF S(X,Y)<=0 THEN 1590 */
line_1590:
    printf("%s", "FROM"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &E,H);
    X = E;
    Y = H;
    if (S(X,Y)<==0) goto line_1590;
    /* BASIC: 1670 INPUT "TO";A,B:X=A:Y=B */
line_1670:
    printf("%s", "TO"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &A,B);
    X = A;
    Y = B;
    /* BASIC: 1680 IF S(X,Y)=0 AND ABS(A-E)<=2 AND ABS(A-E)=ABS(B-H)THEN 1700 */
line_1680:
    /* UNTRANSLATED: IF S(X,Y)=0 AND ABS(A-E)<=2 AND ABS(A-E)=ABS(B-H)THEN 1700 */
    /* BASIC: 1690 PRINT CHR$(7)CHR$(11);:GOTO 1670 */
line_1690:
    printf("%g ", (double)(CHR$(7)CHR$(11)));
    goto line_1670;
    /* BASIC: 1700 I=46 */
line_1700:
    I = 46;
    /* BASIC: 1750 S(A,B)=S(E,H):S(E,H)=0:IF ABS(E-A)<>2 THEN 1810 */
line_1750:
    S(A,B) = S(E,H);
    S(E,H) = 0;
    if (fabs(E-A)!=2) goto line_1810;
    /* BASIC: 1800 S((E+A)/2,(H+B)/2)=0 */
line_1800:
    S((E+A)/2,(H+B)/2) = 0;
    /* BASIC: 1802 INPUT "+TO";A1,B1:IF A1<0 THEN 1810 */
line_1802:
    printf("%s", "+TO"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &A1,B1);
    if (A1<0) goto line_1810;
    /* BASIC: 1804 IF S(A1,B1)<>0 OR ABS(A1-A)<>2 OR ABS(B1-B)<>2 THEN 1802 */
line_1804:
    if (S(A1,B1)!=0 || fabs(A1-A)!=2 || fabs(B1-B)!=2) goto line_1802;
    /* BASIC: 1806 E=A:H=B:A=A1:B=B1:I=I+15:GOTO 1750 */
line_1806:
    E = A;
    H = B;
    A = A1;
    B = B1;
    I = I+15;
    goto line_1750;
    /* BASIC: 1810 IF B=7 THEN S(A,B)=2 */
line_1810:
    if (B==7) { S(A,B) = 2; }
    /* BASIC: 1830 GOTO 230 */
line_1830:
    goto line_230;
    /* BASIC: 1880 PRINT: PRINT "YOU WIN.": END */
line_1880:
    printf("\n");
    printf("%s", "YOU WIN."); printf("\n");
    exit(0);
    /* BASIC: 1885 PRINT: PRINT "I WIN.": END */
line_1885:
    printf("\n");
    printf("%s", "I WIN."); printf("\n");
    exit(0);

    return 0;
}
