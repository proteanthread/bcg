/*
 * Transpiled from change.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double SHORT, CHANGED, THANK, M, DIME, COST, MORRISTOWN, ME, P, NICKEL, AMOUNT, C, H, J, FRIENDLY, NEW, DOLLARS, K, QUARTER, BILL, TEN, OF, SORRY, S, ITEM, WILL, COMPUTING, CREATIVE, JERSEY, THE, DETERMINE, E, HALF, YOU, A, CHANGE, D, COME, UP, F, ITEMS, ONE, PENNY, AGAIN, MICROCOMPUTER, PAYMENT, FIVE, G, N, HAVE, YOUR, I, DOLLAR, COSTING, CORRECT;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 2 PRINT TAB(33);"CHANGE" */
line_2:
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "CHANGE"); printf("\n");
    /* BASIC: 4 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 5 PRINT:PRINT:PRINT */
line_5:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 6 PRINT "I, YOUR FRIENDLY MICROCOMPUTER, WILL DETERMINE" */
line_6:
    printf("%s", "I, YOUR FRIENDLY MICROCOMPUTER, WILL DETERMINE"); printf("\n");
    /* BASIC: 8 PRINT "THE CORRECT CHANGE FOR ITEMS COSTING UP TO $100." */
line_8:
    printf("%s", "THE CORRECT CHANGE FOR ITEMS COSTING UP TO $100."); printf("\n");
    /* BASIC: 9 PRINT:PRINT */
line_9:
    printf("\n");
    printf("\n");
    /* BASIC: 10 PRINT "COST OF ITEM";:INPUT A:PRINT "AMOUNT OF PAYMENT";:INPUT P */
line_10:
    printf("%s", "COST OF ITEM");
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &A);
    printf("%s", "AMOUNT OF PAYMENT");
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &P);
    /* BASIC: 20 C=P-A:M=C:IF C<>0 THEN 90 */
line_20:
    C = P-A;
    M = C;
    if (C!=0) goto line_90;
    /* BASIC: 25 PRINT "CORRECT AMOUNT, THANK YOU." */
line_25:
    printf("%s", "CORRECT AMOUNT, THANK YOU."); printf("\n");
    /* BASIC: 30 GOTO 400 */
line_30:
    goto line_400;
    /* BASIC: 90 IF C>0 THEN 120 */
line_90:
    if (C>0) goto line_120;
    /* BASIC: 95 PRINT "SORRY, YOU HAVE SHORT-CHANGED ME $";A-P */
line_95:
    printf("%s", "SORRY, YOU HAVE SHORT-CHANGED ME $"); printf("%g ", (double)(A-P)); printf("\n");
    /* BASIC: 100 GOTO 10 */
line_100:
    goto line_10;
    /* BASIC: 120 PRINT "YOUR CHANGE, $";C */
line_120:
    printf("%s", "YOUR CHANGE, $"); printf("%g ", (double)(C)); printf("\n");
    /* BASIC: 130 D=INT(C/10) */
line_130:
    D = floor(C/10);
    /* BASIC: 140 IF D=0 THEN 155 */
line_140:
    if (D==0) goto line_155;
    /* BASIC: 150 PRINT D;"TEN DOLLAR BILL(S)" */
line_150:
    printf("%g ", (double)(D)); printf("%s", "TEN DOLLAR BILL(S)"); printf("\n");
    /* BASIC: 155 C=M-(D*10) */
line_155:
    C = M-(D*10);
    /* BASIC: 160 E=INT(C/5) */
line_160:
    E = floor(C/5);
    /* BASIC: 170 IF E=0 THEN 185 */
line_170:
    if (E==0) goto line_185;
    /* BASIC: 180 PRINT E;"FIVE DOLLARS BILL(S)" */
line_180:
    printf("%g ", (double)(E)); printf("%s", "FIVE DOLLARS BILL(S)"); printf("\n");
    /* BASIC: 185 C=M-(D*10+E*5) */
line_185:
    C = M-(D*10+E*5);
    /* BASIC: 190 F=INT(C) */
line_190:
    F = floor(C);
    /* BASIC: 200 IF F=0 THEN 215 */
line_200:
    if (F==0) goto line_215;
    /* BASIC: 210 PRINT F;"ONE DOLLAR BILL(S)" */
line_210:
    printf("%g ", (double)(F)); printf("%s", "ONE DOLLAR BILL(S)"); printf("\n");
    /* BASIC: 215 C=M-(D*10+E*5+F) */
line_215:
    C = M-(D*10+E*5+F);
    /* BASIC: 220 C=C*100 */
line_220:
    C = C*100;
    /* BASIC: 225 N=C */
line_225:
    N = C;
    /* BASIC: 230 G=INT(C/50) */
line_230:
    G = floor(C/50);
    /* BASIC: 240 IF G=0 THEN 255 */
line_240:
    if (G==0) goto line_255;
    /* BASIC: 250 PRINT G;"ONE HALF DOLLAR(S)" */
line_250:
    printf("%g ", (double)(G)); printf("%s", "ONE HALF DOLLAR(S)"); printf("\n");
    /* BASIC: 255 C=N-(G*50) */
line_255:
    C = N-(G*50);
    /* BASIC: 260 H=INT(C/25) */
line_260:
    H = floor(C/25);
    /* BASIC: 270 IF H=0 THEN 285 */
line_270:
    if (H==0) goto line_285;
    /* BASIC: 280 PRINT H;"QUARTER(S)" */
line_280:
    printf("%g ", (double)(H)); printf("%s", "QUARTER(S)"); printf("\n");
    /* BASIC: 285 C=N-(G*50+H*25) */
line_285:
    C = N-(G*50+H*25);
    /* BASIC: 290 I=INT(C/10) */
line_290:
    I = floor(C/10);
    /* BASIC: 300 IF I=0 THEN 315 */
line_300:
    if (I==0) goto line_315;
    /* BASIC: 310 PRINT I;"DIME(S)" */
line_310:
    printf("%g ", (double)(I)); printf("%s", "DIME(S)"); printf("\n");
    /* BASIC: 315 C=N-(G*50+H*25+I*10) */
line_315:
    C = N-(G*50+H*25+I*10);
    /* BASIC: 320 J=INT(C/5) */
line_320:
    J = floor(C/5);
    /* BASIC: 330 IF J=0 THEN 345 */
line_330:
    if (J==0) goto line_345;
    /* BASIC: 340 PRINT J;"NICKEL(S)" */
line_340:
    printf("%g ", (double)(J)); printf("%s", "NICKEL(S)"); printf("\n");
    /* BASIC: 345 C=N-(G*50+H*25+I*10+J*5) */
line_345:
    C = N-(G*50+H*25+I*10+J*5);
    /* BASIC: 350 K=INT(C+.5) */
line_350:
    K = floor(C+.5);
    /* BASIC: 360 IF K=0 THEN 380 */
line_360:
    if (K==0) goto line_380;
    /* BASIC: 370 PRINT K;"PENNY(S)" */
line_370:
    printf("%g ", (double)(K)); printf("%s", "PENNY(S)"); printf("\n");
    /* BASIC: 380 PRINT "THANK YOU, COME AGAIN." */
line_380:
    printf("%s", "THANK YOU, COME AGAIN."); printf("\n");
    /* BASIC: 390 PRINT:PRINT */
line_390:
    printf("\n");
    printf("\n");
    /* BASIC: 400 GOTO 10 */
line_400:
    goto line_10;
    /* BASIC: 410 END */
line_410:
    exit(0);

    return 0;
}
