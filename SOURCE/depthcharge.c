/*
 * Transpiled from depthcharge.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double ABS, SHOT, WEST, GAME, REPORTS, SUB, NEW, DESTROYER, DIMENSION, TRIO, OK, JERSEY, THE, A, HOPE, D, IT, SHOTS, EAST, IN, FOUND, CHARGE, SEARCH, MORRISTOWN, LOG, LOW, DESTROY, AREA, CAUSING, SUBMARINE, WAS, LUCK, NUMBERS, ENJOYED, NORTH, TOO, YOUR, DEPTH, EXPLOSION, HAS, TROUBLE, Y, SURFACE, M, TRIAL, BEEN, POINT, IS, COORDINATES, OF, Z, CREATIVE, COMPUTER, YOU, X, ENEMY, SHIP, WITH, ANOTHER, CAPTAIN, HIGH, USS, G, GOOD, SPECIFY, AN, TORPEDOED, ARE, B, THIRD, C, TWO, YOURSELF, COMPUTING, ABANDON, MISSION, SOUTH, AT, FIRST, O, N, TRIES, HAVE, SONAR;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 2 PRINT TAB(30);"DEPTH CHARGE" */
line_2:
    { int _t; for(_t=0; _t<30; _t++) printf(" "); } printf("%s", "DEPTH CHARGE"); printf("\n");
    /* BASIC: 4 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 6 PRINT: PRINT: PRINT */
line_6:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 20 INPUT "DIMENSION OF SEARCH AREA";G: PRINT */
line_20:
    printf("%s", "DIMENSION OF SEARCH AREA"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &G);
    printf("\n");
    /* BASIC: 30 N=INT(LOG(G)/LOG(2))+1 */
line_30:
    N = floor(LOG(G)/LOG(2))+1;
    /* BASIC: 40 PRINT "YOU ARE THE CAPTAIN OF THE DESTROYER USS COMPUTER" */
line_40:
    printf("%s", "YOU ARE THE CAPTAIN OF THE DESTROYER USS COMPUTER"); printf("\n");
    /* BASIC: 50 PRINT "AN ENEMY SUB HAS BEEN CAUSING YOU TROUBLE.  YOUR" */
line_50:
    printf("%s", "AN ENEMY SUB HAS BEEN CAUSING YOU TROUBLE.  YOUR"); printf("\n");
    /* BASIC: 60 PRINT "MISSION IS TO DESTROY IT.  YOU HAVE";N;"SHOTS." */
line_60:
    printf("%s", "MISSION IS TO DESTROY IT.  YOU HAVE"); printf("%g ", (double)(N)); printf("%s", "SHOTS."); printf("\n");
    /* BASIC: 70 PRINT "SPECIFY DEPTH CHARGE EXPLOSION POINT WITH A" */
line_70:
    printf("%s", "SPECIFY DEPTH CHARGE EXPLOSION POINT WITH A"); printf("\n");
    /* BASIC: 80 PRINT "TRIO OF NUMBERS -- THE FIRST TWO ARE THE" */
line_80:
    printf("%s", "TRIO OF NUMBERS -- THE FIRST TWO ARE THE"); printf("\n");
    /* BASIC: 90 PRINT "SURFACE COORDINATES; THE THIRD IS THE DEPTH." */
line_90:
    printf("%s", "SURFACE COORDINATES; THE THIRD IS THE DEPTH."); printf("\n");
    /* BASIC: 100 PRINT : PRINT "GOOD LUCK !": PRINT */
line_100:
    printf("\n");
    printf("%s", "GOOD LUCK !"); printf("\n");
    printf("\n");
    /* BASIC: 110 A=INT(G*RND(1)) : B=INT(G*RND(1)) : C=INT(G*RND(1)) */
line_110:
    A = floor(G*((double)rand() / (double)RAND_MAX));
    B = floor(G*((double)rand() / (double)RAND_MAX));
    C = floor(G*((double)rand() / (double)RAND_MAX));
    /* BASIC: 120 FOR D=1 TO N : PRINT : PRINT "TRIAL #";D; : INPUT X,Y,Z */
line_120:
    D = 1; for_loop_D: if ((1 >= 0 && D > N) || (1 < 0 && D < N)) goto end_for_D;
    printf("\n");
    printf("%s", "TRIAL #"); printf("%g ", (double)(D));
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &X,Y,Z);
    /* BASIC: 130 IF ABS(X-A)+ABS(Y-B)+ABS(Z-C)=0 THEN 300 */
line_130:
    if (fabs(X-A)+fabs(Y-B)+fabs(Z-C)==0) goto line_300;
    /* BASIC: 140 GOSUB 500 : PRINT : NEXT D */
line_140:
    /* TODO: GOSUB 500 */
    printf("\n");
    D += 1; goto for_loop_D; end_for_D:;
    /* BASIC: 200 PRINT : PRINT "YOU HAVE BEEN TORPEDOED!  ABANDON SHIP!" */
line_200:
    printf("\n");
    printf("%s", "YOU HAVE BEEN TORPEDOED!  ABANDON SHIP!"); printf("\n");
    /* BASIC: 210 PRINT "THE SUBMARINE WAS AT";A;",";B;",";C : GOTO 400 */
line_210:
    printf("%s", "THE SUBMARINE WAS AT"); printf("%g ", (double)(A)); printf("%s", ","); printf("%g ", (double)(B)); printf("%s", ","); printf("%g ", (double)(C)); printf("\n");
    goto line_400;
    /* BASIC: 300 PRINT : PRINT "B O O M ! ! YOU FOUND IT IN";D;"TRIES!" */
line_300:
    printf("\n");
    printf("%s", "B O O M ! ! YOU FOUND IT IN"); printf("%g ", (double)(D)); printf("%s", "TRIES!"); printf("\n");
    /* BASIC: 400 PRINT : PRINT: INPUT "ANOTHER GAME (Y OR N)";A$ */
line_400:
    printf("\n");
    printf("\n");
    printf("%s", "ANOTHER GAME (Y OR N)"); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    /* BASIC: 410 IF A$="Y" THEN 100 */
line_410:
    if (A$=="Y") goto line_100;
    /* BASIC: 420 PRINT "OK.  HOPE YOU ENJOYED YOURSELF." : GOTO 600 */
line_420:
    printf("%s", "OK.  HOPE YOU ENJOYED YOURSELF."); printf("\n");
    goto line_600;
    /* BASIC: 500 PRINT "SONAR REPORTS SHOT WAS "; */
line_500:
    printf("%s", "SONAR REPORTS SHOT WAS ");
    /* BASIC: 510 IF Y>B THEN PRINT "NORTH"; */
line_510:
    if (Y>B) { printf("%s", "NORTH"); }
    /* BASIC: 520 IF Y<B THEN PRINT "SOUTH"; */
line_520:
    if (Y<B) { printf("%s", "SOUTH"); }
    /* BASIC: 530 IF X>A THEN PRINT "EAST"; */
line_530:
    if (X>A) { printf("%s", "EAST"); }
    /* BASIC: 540 IF X<A THEN PRINT "WEST"; */
line_540:
    if (X<A) { printf("%s", "WEST"); }
    /* BASIC: 550 IF Y<>B OR X<>A THEN PRINT " AND"; */
line_550:
    if (Y!=B || X!=A) { printf("%s", " AND"); }
    /* BASIC: 560 IF Z>C THEN PRINT " TOO LOW." */
line_560:
    if (Z>C) { printf("%s", " TOO LOW."); printf("\n"); }
    /* BASIC: 570 IF Z<C THEN PRINT " TOO HIGH." */
line_570:
    if (Z<C) { printf("%s", " TOO HIGH."); printf("\n"); }
    /* BASIC: 580 IF Z=C THEN PRINT " DEPTH OK." */
line_580:
    if (Z==C) { printf("%s", " DEPTH OK."); printf("\n"); }
    /* BASIC: 590 RETURN */
line_590:
    /* TODO: RETURN */
    /* BASIC: 600 END */
line_600:
    exit(0);

    return 0;
}
