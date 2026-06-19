/*
 * Transpiled from lunar.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double FALL, CRATER, RETRO, BETTER, J, NEW, L5, SURVIVORS, SO, BOARD, RE, SQR, FUEL, JERSEY, THE, FACT, IMPACT, ON, A, HOPE, D, IT, MANUALLY, T, OXYGEN, IN, ARRIVES, DEEP, STRANDED, OUT, FT, SIMULATION, BY, PARTY, MORRISTOWN, MOON, ANY, POUNDS, MPH, WAS, LUCK, SECONDS, TRY, BURN, HERE, BETWEEN, V, VELOCITY, SECOND, NERE, RESCUE, LBS, COULD, I, HAS, THERE, M, UNTIL, VALUE, W, IS, K, FEET, LB, OF, Z, LUNAR, EVERY, ENOUGH, SET, SORRY, S, FREE, CREATIVE, CRAFT, ROCKETS, COMPUTER, YOU, DAMAGE, NO, LANDING, CAPSULE, MI, G, APOLLO, GOOD, AN, WEIGHT, FAILED, XEROX, BLOW, LAND, PERFECT, SEC, COMPUTING, AT, L, AGAIN, PER, O, MAXIMUM, MADE, RATE, N, HAVE, THIS, BLASTED, Q;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 10 PRINT TAB(33);"LUNAR" */
line_10:
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "LUNAR"); printf("\n");
    /* BASIC: 20 PRINT TAB(l5);"CREATIVE COMPUTING MORRISTOWN, NEW JERSEY" */
line_20:
    { int _t; for(_t=0; _t<l5; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 25 PRINT:PRINT:PRINT */
line_25:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 30 PRINT "THIS IS A COMPUTER SIMULATION OF AN APOLLO LUNAR" */
line_30:
    printf("%s", "THIS IS A COMPUTER SIMULATION OF AN APOLLO LUNAR"); printf("\n");
    /* BASIC: 40 PRINT "LANDING CAPSULE.": PRINT: PRINT */
line_40:
    printf("%s", "LANDING CAPSULE."); printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 50 PRINT "THE ON-BOARD COMPUTER HAS FAILED (IT WAS MADE BY" */
line_50:
    printf("%s", "THE ON-BOARD COMPUTER HAS FAILED (IT WAS MADE BY"); printf("\n");
    /* BASIC: 60 PRINT "XEROX) SO YOU HAVE TO LAND THE CAPSULE MANUALLY." */
line_60:
    printf("%s", "XEROX) SO YOU HAVE TO LAND THE CAPSULE MANUALLY."); printf("\n");
    /* BASIC: 70 PRINT: PRINT "SET BURN RATE OF RETRO ROCKETS TO ANY VALUE BETWEEN" */
line_70:
    printf("\n");
    printf("%s", "SET BURN RATE OF RETRO ROCKETS TO ANY VALUE BETWEEN"); printf("\n");
    /* BASIC: 80 PRINT "0 (FREE FALL) AND 200 (MAXIMUM BURN) POUNDS PER SECOND." */
line_80:
    printf("%s", "0 (FREE FALL) AND 200 (MAXIMUM BURN) POUNDS PER SECOND."); printf("\n");
    /* BASIC: 90 PRINT "SET NEW BURN RATE EVERY 10 SECONDS.": PRINT */
line_90:
    printf("%s", "SET NEW BURN RATE EVERY 10 SECONDS."); printf("\n");
    printf("\n");
    /* BASIC: 100 PRINT "CAPSULE WEIGHT 32,500 LBS; FUEL WEIGHT 16,500 LBS." */
line_100:
    printf("%s", "CAPSULE WEIGHT 32,500 LBS; FUEL WEIGHT 16,500 LBS."); printf("\n");
    /* BASIC: 110 PRINT: PRINT: PRINT: PRINT "GOOD LUCK" */
line_110:
    printf("\n");
    printf("\n");
    printf("\n");
    printf("%s", "GOOD LUCK"); printf("\n");
    /* BASIC: 120 L=0 */
line_120:
    L = 0;
    /* BASIC: 130 PRINT: PRINT "SEC","MI + FT","MPH","LB FUEL","BURN RATE":PRINT */
line_130:
    printf("\n");
    printf("%s", "SEC"); printf("\t"); printf("%s", "MI + FT"); printf("\t"); printf("%s", "MPH"); printf("\t"); printf("%s", "LB FUEL"); printf("\t"); printf("%s", "BURN RATE"); printf("\n");
    printf("\n");
    /* BASIC: 140 A=120:V=1:M=33000:N=16500:G=1E-03:Z=1.8 */
line_140:
    A = 120;
    V = 1;
    M = 33000;
    N = 16500;
    G = 1E-03;
    Z = 1.8;
    /* BASIC: 150 PRINT L,INT(A);INT(5280*(A-INT(A))),3600*V,M-N,:INPUT K:T=10 */
line_150:
    printf("%g ", (double)(L)); printf("\t"); printf("%g ", (double)(floor(A))); printf("%g ", (double)(floor(5280*(A-floor(A))))); printf("\t"); printf("%g ", (double)(3600*V)); printf("\t"); printf("%g ", (double)(M-N)); printf("\t");
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &K);
    T = 10;
    /* BASIC: 160 IF M-N<1E-03 THEN 240 */
line_160:
    if (M-N<1E-03) goto line_240;
    /* BASIC: 170 IF T<1E-03 THEN 150 */
line_170:
    if (T<1E-03) goto line_150;
    /* BASIC: 180 S=T: IF M>=N+S*K THEN 200 */
line_180:
    S = T;
    if (M>==N+S*K) goto line_200;
    /* BASIC: 190 S=(M-N)/K */
line_190:
    S = (M-N)/K;
    /* BASIC: 200 GOSUB 420: IF I<=O THEN 340 */
line_200:
    /* TODO: GOSUB 420 */
    if (I<==O) goto line_340;
    /* BASIC: 210 IF V<=0 THEN 230 */
line_210:
    if (V<==0) goto line_230;
    /* BASIC: 220 IF J<0 THEN 370 */
line_220:
    if (J<0) goto line_370;
    /* BASIC: 230 GOSUB 330: GOTO 160 */
line_230:
    /* TODO: GOSUB 330 */
    goto line_160;
    /* BASIC: 240 PRINT "FUEL OUT AT";L;"SECONDS":S=(-V+SQR(V*V+2*A*G))/G */
line_240:
    printf("%s", "FUEL OUT AT"); printf("%g ", (double)(L)); printf("%s", "SECONDS"); printf("\n");
    S = (-V+sqrt(V*V+2*A*G))/G;
    /* BASIC: 250 V=V+G*S: L=L+S */
line_250:
    V = V+G*S;
    L = L+S;
    /* BASIC: 260 W=3600*V: PRINT "ON MOON AT";L;"SECONDS - IMPACT VELOCITY";W;"MPH" */
line_260:
    W = 3600*V;
    printf("%s", "ON MOON AT"); printf("%g ", (double)(L)); printf("%s", "SECONDS - IMPACT VELOCITY"); printf("%g ", (double)(W)); printf("%s", "MPH"); printf("\n");
    /* BASIC: 274 IF W<=1.2 THEN PRINT "PERFECT LANDING!": GOTO 440 */
line_274:
    if (W<==1.2) { printf("%s", "PERFECT LANDING!"); printf("\n"); }
    goto line_440;
    /* BASIC: 280 IF W<=10 THEN PRINT "GOOD LANDING (COULD RE BETTER)":GOTO 440 */
line_280:
    if (W<==10) { printf("%s", "GOOD LANDING (COULD RE BETTER)"); printf("\n"); }
    goto line_440;
    /* BASIC: 282 IF W>60 THEN 300 */
line_282:
    if (W>60) goto line_300;
    /* BASIC: 284 PRINT "CRAFT DAMAGE... YOU'RE STRANDED HERE UNTIL A RESCUE" */
line_284:
    printf("%s", "CRAFT DAMAGE... YOU'RE STRANDED HERE UNTIL A RESCUE"); printf("\n");
    /* BASIC: 286 PRINT "PARTY ARRIVES. HOPE YOU HAVE ENOUGH OXYGEN!" */
line_286:
    printf("%s", "PARTY ARRIVES. HOPE YOU HAVE ENOUGH OXYGEN!"); printf("\n");
    /* BASIC: 288 GOTO 440 */
line_288:
    goto line_440;
    /* BASIC: 300 PRINT "SORRY THERE NERE NO SURVIVORS. YOU BLOW IT!" */
line_300:
    printf("%s", "SORRY THERE NERE NO SURVIVORS. YOU BLOW IT!"); printf("\n");
    /* BASIC: 310 PRINT "IN FACT, YOU BLASTED A NEW LUNAR CRATER";W*.227;"FEET DEEP!" */
line_310:
    printf("%s", "IN FACT, YOU BLASTED A NEW LUNAR CRATER"); printf("%g ", (double)(W*.227)); printf("%s", "FEET DEEP!"); printf("\n");
    /* BASIC: 320 GOTO 440 */
line_320:
    goto line_440;
    /* BASIC: 330 L=L+S: T=T-S: M=M-S*K: A=I: V=J: RETURN */
line_330:
    L = L+S;
    T = T-S;
    M = M-S*K;
    A = I;
    V = J;
    /* TODO: RETURN */
    /* BASIC: 340 IF S<5E-03 THEN 260 */
line_340:
    if (S<5E-03) goto line_260;
    /* BASIC: 350 D=V+SQR(V*V+2*A*(G-Z*K/M)):S=2*A/D */
line_350:
    D = V+sqrt(V*V+2*A*(G-Z*K/M));
    S = 2*A/D;
    /* BASIC: 360 GOSUB 420: GOSUB 330: GOTO 340 */
line_360:
    /* TODO: GOSUB 420 */
    /* TODO: GOSUB 330 */
    goto line_340;
    /* BASIC: 370 W=(1-M*G/(Z*K))/2: S=M*V/(Z*K*(W+SQR(W*W+V/Z)))+.05:GOSUB 420 */
line_370:
    W = (1-M*G/(Z*K))/2;
    S = M*V/(Z*K*(W+sqrt(W*W+V/Z)))+.05;
    /* TODO: GOSUB 420 */
    /* BASIC: 380 IF I<=0 THEN 340 */
line_380:
    if (I<==0) goto line_340;
    /* BASIC: 390 GOSUB 330: IF J>0 THEN 160 */
line_390:
    /* TODO: GOSUB 330 */
    if (J>0) goto line_160;
    /* BASIC: 400 IF V>0 THEN 370 */
line_400:
    if (V>0) goto line_370;
    /* BASIC: 410 GOTO 160 */
line_410:
    goto line_160;
    /* BASIC: 420 Q=S*K/M: J=V+G*S+Z*(-Q-Q*Q/2-Q^3/3-Q^4/4-Q^5/5) */
line_420:
    Q = S*K/M;
    J = V+G*S+Z*(-Q-Q*Q/2-Q^3/3-Q^4/4-Q^5/5);
    /* BASIC: 430 I=A-G*S*S/2-V*S+Z*S*(Q/2+Q^2/6+Q^3/12+Q^4/20+Q^5/30):RETURN */
line_430:
    I = A-G*S*S/2-V*S+Z*S*(Q/2+Q^2/6+Q^3/12+Q^4/20+Q^5/30);
    /* TODO: RETURN */
    /* BASIC: 440 PRINT:PRINT:PRINT:PRINT "TRY AGAIN??": GOTO 70 */
line_440:
    printf("\n");
    printf("\n");
    printf("\n");
    printf("%s", "TRY AGAIN??"); printf("\n");
    goto line_70;

    return 0;
}
