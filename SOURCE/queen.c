/*
 * Transpiled from queen.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double GOING, READ, ALTERNATE, P, GAME, DIRECTIONS, GO, PRESS, LOOKS, NEW, NICE, INSTRUCTIONS, ANSWER, OK, JERSEY, THE, PLAYED, M1, ON, LEFT, TOP, A, FORFEIT, RIGHT, BUT, IT, WON, LIKE, T, ANYONE, IN, HAND, BY, PLAYING, MORRISTOWN, ANY, DATA, ROW, START, PLAY, BASED, TIME, TRY, WHAT, BETWEEN, U, SURE, WANT, ALL, YOUR, I, SQUARES, THANKS, WELL, RESPONSE, THERE, Y, M, VERY, W, ELSE, H, IS, U1, K, KEY, OUR, OF, Z, ONLY, ABLE, MET, OBJECT, WILL, CREATIVE, WIN, LOWER, MY, COMPUTER, EACH, PLEASE, QUEEN, YOU, WINS, AS, NO, SQUARE, WOULD, ONE, WE, AFTER, ILLEGALLY, G, T1, MAY, CHESS, ARE, BE, MOVES, B, C, MOVE, ALTERNATING, MATCH, TYPING, CAN, COMPUTING, E, WHERE, COLUMN, BEGUN, L, PLACE, DIAGONALLY, DOWN, CARE, DO, AGAIN, R, YES, FIRST, THAT, O, N, HAVE, Q;
    double S[1000] = {0}; /* Static array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 1 PRINT TAB(33);"QUEEN" */
line_1:
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "QUEEN"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT:PRINT:PRINT */
line_3:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 10 DIM S(64) */
line_10:
    /* DIM S(64) (handled statically) */
    /* BASIC: 11 FOR I=1 TO 64 */
line_11:
    I = 1; for_loop_I: if ((1 >= 0 && I > 64) || (1 < 0 && I < 64)) goto end_for_I;
    /* BASIC: 12 READ S(I) */
line_12:
    /* UNTRANSLATED: READ S(I) */
    /* BASIC: 13 NEXT I */
line_13:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 14 DATA  81,  71,  61,  51,  41,  31,  21,  11 */
line_14:
    /* UNTRANSLATED: DATA  81,  71,  61,  51,  41,  31,  21,  11 */
    /* BASIC: 15 DATA  92,  82,  72,  62,  52,  42,  32,  22 */
line_15:
    /* UNTRANSLATED: DATA  92,  82,  72,  62,  52,  42,  32,  22 */
    /* BASIC: 16 DATA 103,  93,  83,  73,  63,  53,  43,  33 */
line_16:
    /* UNTRANSLATED: DATA 103,  93,  83,  73,  63,  53,  43,  33 */
    /* BASIC: 17 DATA 114, 104,  94,  84,  74,  64,  54,  44 */
line_17:
    /* UNTRANSLATED: DATA 114, 104,  94,  84,  74,  64,  54,  44 */
    /* BASIC: 18 DATA 125, 115, 105,  95,  85,  75,  65,  55 */
line_18:
    /* UNTRANSLATED: DATA 125, 115, 105,  95,  85,  75,  65,  55 */
    /* BASIC: 19 DATA 136, 126, 116, 106,  96,  86,  76,  66 */
line_19:
    /* UNTRANSLATED: DATA 136, 126, 116, 106,  96,  86,  76,  66 */
    /* BASIC: 20 DATA 147, 137, 127, 117, 107,  97,  87,  77 */
line_20:
    /* UNTRANSLATED: DATA 147, 137, 127, 117, 107,  97,  87,  77 */
    /* BASIC: 21 DATA 158, 148, 138, 128, 118, 108,  98,  88 */
line_21:
    /* UNTRANSLATED: DATA 158, 148, 138, 128, 118, 108,  98,  88 */
    /* BASIC: 22 INPUT "DO YOU WANT INSTRUCTIONS";W$ */
line_22:
    printf("%s", "DO YOU WANT INSTRUCTIONS"); fgets(W_str, sizeof(W_str), stdin); W_str[strcspn(W_str, "\n")] = 0;
    /* BASIC: 23 IF W$="NO" THEN 30 */
line_23:
    if (W$=="NO") goto line_30;
    /* BASIC: 24 IF W$="YES" THEN 28 */
line_24:
    if (W$=="YES") goto line_28;
    /* BASIC: 25 PRINT "PLEASE ANSWER 'YES' OR 'NO'." */
line_25:
    printf("%s", "PLEASE ANSWER 'YES' OR 'NO'."); printf("\n");
    /* BASIC: 26 GOTO 22 */
line_26:
    goto line_22;
    /* BASIC: 28 GOSUB 5000 */
line_28:
    /* TODO: GOSUB 5000 */
    /* BASIC: 29 GOTO 100 */
line_29:
    goto line_100;
    /* BASIC: 30 GOSUB 5160 */
line_30:
    /* TODO: GOSUB 5160 */
    /* BASIC: 90 REM     ERROR CHECKS */
line_90:
    // REM     ERROR CHECKS
    /* BASIC: 100 PRINT "WHERE WOULD YOU LIKE TO START"; */
line_100:
    printf("%s", "WHERE WOULD YOU LIKE TO START");
    /* BASIC: 110 INPUT M1 */
line_110:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &M1);
    /* BASIC: 115 IF M1=0 THEN 232 */
line_115:
    if (M1==0) goto line_232;
    /* BASIC: 120 T1=INT(M1/10) */
line_120:
    T1 = floor(M1/10);
    /* BASIC: 130 U1=M1-10*T1 */
line_130:
    U1 = M1-10*T1;
    /* BASIC: 140 IF U1=1 THEN 200 */
line_140:
    if (U1==1) goto line_200;
    /* BASIC: 150 IF U1=T1 THEN 200 */
line_150:
    if (U1==T1) goto line_200;
    /* BASIC: 160 PRINT "PLEASE READ THE DIRECTIONS AGAIN." */
line_160:
    printf("%s", "PLEASE READ THE DIRECTIONS AGAIN."); printf("\n");
    /* BASIC: 170 PRINT "YOU HAVE BEGUN ILLEGALLY." */
line_170:
    printf("%s", "YOU HAVE BEGUN ILLEGALLY."); printf("\n");
    /* BASIC: 175 PRINT */
line_175:
    printf("\n");
    /* BASIC: 180 GOTO 100 */
line_180:
    goto line_100;
    /* BASIC: 200 GOSUB 2000 */
line_200:
    /* TODO: GOSUB 2000 */
    /* BASIC: 210 PRINT "COMPUTER MOVES TO SQUARE";M */
line_210:
    printf("%s", "COMPUTER MOVES TO SQUARE"); printf("%g ", (double)(M)); printf("\n");
    /* BASIC: 215 IF M=158 THEN 3400 */
line_215:
    if (M==158) goto line_3400;
    /* BASIC: 220 PRINT "WHAT IS YOUR MOVE"; */
line_220:
    printf("%s", "WHAT IS YOUR MOVE");
    /* BASIC: 230 INPUT M1 */
line_230:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &M1);
    /* BASIC: 231 IF M1<>0 THEN 239 */
line_231:
    if (M1!=0) goto line_239;
    /* BASIC: 232 PRINT */
line_232:
    printf("\n");
    /* BASIC: 233 PRINT "IT LOOKS LIKE I HAVE WON BY FORFEIT." */
line_233:
    printf("%s", "IT LOOKS LIKE I HAVE WON BY FORFEIT."); printf("\n");
    /* BASIC: 234 PRINT */
line_234:
    printf("\n");
    /* BASIC: 235 GOTO 4000 */
line_235:
    goto line_4000;
    /* BASIC: 239 IF M1<=M THEN 3200 */
line_239:
    if (M1<==M) goto line_3200;
    /* BASIC: 240 T1=INT(M1/10) */
line_240:
    T1 = floor(M1/10);
    /* BASIC: 250 U1=M1-10*T1 */
line_250:
    U1 = M1-10*T1;
    /* BASIC: 260 P=U1-U */
line_260:
    P = U1-U;
    /* BASIC: 270 IF P<>0 THEN 300 */
line_270:
    if (P!=0) goto line_300;
    /* BASIC: 280 L=T1-T */
line_280:
    L = T1-T;
    /* BASIC: 290 IF L<=0 THEN 3200 */
line_290:
    if (L<==0) goto line_3200;
    /* BASIC: 295 GOTO 200 */
line_295:
    goto line_200;
    /* BASIC: 300 IF T1-T <>P THEN 320 */
line_300:
    if (T1-T !=P) goto line_320;
    /* BASIC: 310 GOTO 200 */
line_310:
    goto line_200;
    /* BASIC: 320 IF T1-T <>2*P THEN 3200 */
line_320:
    if (T1-T !=2*P) goto line_3200;
    /* BASIC: 330 GOTO 200 */
line_330:
    goto line_200;
    /* BASIC: 1990 REM     LOCATE MOVE FOR COMPUTER */
line_1990:
    // REM     LOCATE MOVE FOR COMPUTER
    /* BASIC: 2000 IF M1=41 THEN 2180 */
line_2000:
    if (M1==41) goto line_2180;
    /* BASIC: 2010 IF M1=44 THEN 2180 */
line_2010:
    if (M1==44) goto line_2180;
    /* BASIC: 2020 IF M1=73 THEN 2180 */
line_2020:
    if (M1==73) goto line_2180;
    /* BASIC: 2030 IF M1=75 THEN 2180 */
line_2030:
    if (M1==75) goto line_2180;
    /* BASIC: 2040 IF M1=126 THEN 2180 */
line_2040:
    if (M1==126) goto line_2180;
    /* BASIC: 2050 IF M1=127 THEN 2180 */
line_2050:
    if (M1==127) goto line_2180;
    /* BASIC: 2060 IF M1=158 THEN 3300 */
line_2060:
    if (M1==158) goto line_3300;
    /* BASIC: 2065 C=0 */
line_2065:
    C = 0;
    /* BASIC: 2070 FOR K=7 TO 1 STEP -1 */
line_2070:
    K = 7; for_loop_K: if ((-1 >= 0 && K > 1) || (-1 < 0 && K < 1)) goto end_for_K;
    /* BASIC: 2080 U=U1 */
line_2080:
    U = U1;
    /* BASIC: 2090 T=T1+K */
line_2090:
    T = T1+K;
    /* BASIC: 2100 GOSUB 3500 */
line_2100:
    /* TODO: GOSUB 3500 */
    /* BASIC: 2105 IF C=1 THEN 2160 */
line_2105:
    if (C==1) goto line_2160;
    /* BASIC: 2110 U=U+K */
line_2110:
    U = U+K;
    /* BASIC: 2120 GOSUB 3500 */
line_2120:
    /* TODO: GOSUB 3500 */
    /* BASIC: 2125 IF C=1 THEN 2160 */
line_2125:
    if (C==1) goto line_2160;
    /* BASIC: 2130 T=T+K */
line_2130:
    T = T+K;
    /* BASIC: 2140 GOSUB 3500 */
line_2140:
    /* TODO: GOSUB 3500 */
    /* BASIC: 2145 IF C=1 THEN 2160 */
line_2145:
    if (C==1) goto line_2160;
    /* BASIC: 2150 NEXT K */
line_2150:
    K += -1; goto for_loop_K; end_for_K:;
    /* BASIC: 2155 GOTO 2180 */
line_2155:
    goto line_2180;
    /* BASIC: 2160 C=0 */
line_2160:
    C = 0;
    /* BASIC: 2170 RETURN */
line_2170:
    /* TODO: RETURN */
    /* BASIC: 2180 GOSUB 3000 */
line_2180:
    /* TODO: GOSUB 3000 */
    /* BASIC: 2190 RETURN */
line_2190:
    /* TODO: RETURN */
    /* BASIC: 2990 REM     RANDOM MOVE */
line_2990:
    // REM     RANDOM MOVE
    /* BASIC: 3000 Z=RND(1) */
line_3000:
    Z = ((double)rand() / (double)RAND_MAX);
    /* BASIC: 3010 IF Z>.6 THEN 3110 */
line_3010:
    if (Z>.6) goto line_3110;
    /* BASIC: 3020 IF Z>.3 THEN 3070 */
line_3020:
    if (Z>.3) goto line_3070;
    /* BASIC: 3030 U=U1 */
line_3030:
    U = U1;
    /* BASIC: 3040 T=T1+1 */
line_3040:
    T = T1+1;
    /* BASIC: 3050 M=10*T+U */
line_3050:
    M = 10*T+U;
    /* BASIC: 3060 RETURN */
line_3060:
    /* TODO: RETURN */
    /* BASIC: 3070 U=U1+1 */
line_3070:
    U = U1+1;
    /* BASIC: 3080 T=T1+2 */
line_3080:
    T = T1+2;
    /* BASIC: 3090 M=10*T+U */
line_3090:
    M = 10*T+U;
    /* BASIC: 3100 RETURN */
line_3100:
    /* TODO: RETURN */
    /* BASIC: 3110 U=U1+1 */
line_3110:
    U = U1+1;
    /* BASIC: 3120 T=T1+1 */
line_3120:
    T = T1+1;
    /* BASIC: 3130 M=10*T+U */
line_3130:
    M = 10*T+U;
    /* BASIC: 3140 RETURN */
line_3140:
    /* TODO: RETURN */
    /* BASIC: 3190 REM     ILLEGAL MOVE MESSAGE */
line_3190:
    // REM     ILLEGAL MOVE MESSAGE
    /* BASIC: 3200 PRINT */
line_3200:
    printf("\n");
    /* BASIC: 3210 PRINT "Y O U   C H E A T . . .  TRY AGAIN"; */
line_3210:
    printf("%s", "Y O U   C H E A T . . .  TRY AGAIN");
    /* BASIC: 3220 GOTO 230 */
line_3220:
    goto line_230;
    /* BASIC: 3290 REM     PLAYER WINS */
line_3290:
    // REM     PLAYER WINS
    /* BASIC: 3300 PRINT */
line_3300:
    printf("\n");
    /* BASIC: 3310 PRINT "C O N G R A T U L A T I O N S . . ." */
line_3310:
    printf("%s", "C O N G R A T U L A T I O N S . . ."); printf("\n");
    /* BASIC: 3320 PRINT */
line_3320:
    printf("\n");
    /* BASIC: 3330 PRINT "YOU HAVE WON--VERY WELL PLAYED." */
line_3330:
    printf("%s", "YOU HAVE WON--VERY WELL PLAYED."); printf("\n");
    /* BASIC: 3340 PRINT "IT LOOKS LIKE I HAVE MET MY MATCH." */
line_3340:
    printf("%s", "IT LOOKS LIKE I HAVE MET MY MATCH."); printf("\n");
    /* BASIC: 3350 PRINT "THANKS FOR PLAYING---I CAN'T WIN ALL THE TIME." */
line_3350:
    printf("%s", "THANKS FOR PLAYING---I CAN'T WIN ALL THE TIME."); printf("\n");
    /* BASIC: 3360 PRINT */
line_3360:
    printf("\n");
    /* BASIC: 3370 GOTO 4000 */
line_3370:
    goto line_4000;
    /* BASIC: 3390 REM     COMPUTER WINS */
line_3390:
    // REM     COMPUTER WINS
    /* BASIC: 3400 PRINT */
line_3400:
    printf("\n");
    /* BASIC: 3410 PRINT "NICE TRY, BUT IT LOOKS LIKE I HAVE WON." */
line_3410:
    printf("%s", "NICE TRY, BUT IT LOOKS LIKE I HAVE WON."); printf("\n");
    /* BASIC: 3420 PRINT "THANKS FOR PLAYING." */
line_3420:
    printf("%s", "THANKS FOR PLAYING."); printf("\n");
    /* BASIC: 3430 PRINT */
line_3430:
    printf("\n");
    /* BASIC: 3440 GOTO 4000 */
line_3440:
    goto line_4000;
    /* BASIC: 3490 REM     TEST FOR COMPUTER MOVE */
line_3490:
    // REM     TEST FOR COMPUTER MOVE
    /* BASIC: 3500 M=10*T+U */
line_3500:
    M = 10*T+U;
    /* BASIC: 3510 IF M=158 THEN 3570 */
line_3510:
    if (M==158) goto line_3570;
    /* BASIC: 3520 IF M=127 THEN 3570 */
line_3520:
    if (M==127) goto line_3570;
    /* BASIC: 3530 IF M=126 THEN 3570 */
line_3530:
    if (M==126) goto line_3570;
    /* BASIC: 3540 IF M=75 THEN 3570 */
line_3540:
    if (M==75) goto line_3570;
    /* BASIC: 3550 IF M=73 THEN 3570 */
line_3550:
    if (M==73) goto line_3570;
    /* BASIC: 3560 RETURN */
line_3560:
    /* TODO: RETURN */
    /* BASIC: 3570 C=1 */
line_3570:
    C = 1;
    /* BASIC: 3580 GOTO 3560 */
line_3580:
    goto line_3560;
    /* BASIC: 3990 REM     ANOTHER GAME??? */
line_3990:
    // REM     ANOTHER GAME???
    /* BASIC: 4000 PRINT "ANYONE ELSE CARE TO TRY"; */
line_4000:
    printf("%s", "ANYONE ELSE CARE TO TRY");
    /* BASIC: 4010 INPUT Q$ */
line_4010:
    printf("? "); fgets(Q_str, sizeof(Q_str), stdin); Q_str[strcspn(Q_str, "\n")] = 0;
    /* BASIC: 4020 PRINT */
line_4020:
    printf("\n");
    /* BASIC: 4030 IF Q$="YES" THEN 30 */
line_4030:
    if (Q$=="YES") goto line_30;
    /* BASIC: 4040 IF Q$="NO" THEN 4050 */
line_4040:
    if (Q$=="NO") goto line_4050;
    /* BASIC: 4042 PRINT "PLEASE ANSWER 'YES' OR 'NO'." */
line_4042:
    printf("%s", "PLEASE ANSWER 'YES' OR 'NO'."); printf("\n");
    /* BASIC: 4045 GOTO 4000 */
line_4045:
    goto line_4000;
    /* BASIC: 4050 PRINT:PRINT "OK --- THANKS AGAIN." */
line_4050:
    printf("\n");
    printf("%s", "OK --- THANKS AGAIN."); printf("\n");
    /* BASIC: 4060 STOP */
line_4060:
    exit(0);
    /* BASIC: 4990 REM     DIRECTIONS */
line_4990:
    // REM     DIRECTIONS
    /* BASIC: 5000 PRINT "WE ARE GOING TO PLAY A GAME BASED ON ONE OF THE CHESS" */
line_5000:
    printf("%s", "WE ARE GOING TO PLAY A GAME BASED ON ONE OF THE CHESS"); printf("\n");
    /* BASIC: 5010 PRINT "MOVES.  OUR QUEEN WILL BE ABLE TO MOVE ONLY TO THE LEFT," */
line_5010:
    printf("%s", "MOVES.  OUR QUEEN WILL BE ABLE TO MOVE ONLY TO THE LEFT,"); printf("\n");
    /* BASIC: 5020 PRINT "DOWN, OR DIAGONALLY DOWN AND TO THE LEFT." */
line_5020:
    printf("%s", "DOWN, OR DIAGONALLY DOWN AND TO THE LEFT."); printf("\n");
    /* BASIC: 5030 PRINT */
line_5030:
    printf("\n");
    /* BASIC: 5040 PRINT "THE OBJECT OF THE GAME IS TO PLACE THE QUEEN IN THE LOWER" */
line_5040:
    printf("%s", "THE OBJECT OF THE GAME IS TO PLACE THE QUEEN IN THE LOWER"); printf("\n");
    /* BASIC: 5050 PRINT "LEFT HAND SQUARE BY ALTERNATING MOVES BETWEEN YOU AND THE" */
line_5050:
    printf("%s", "LEFT HAND SQUARE BY ALTERNATING MOVES BETWEEN YOU AND THE"); printf("\n");
    /* BASIC: 5060 PRINT "COMPUTER.  THE FIRST ONE TO PLACE THE QUEEN THERE WINS." */
line_5060:
    printf("%s", "COMPUTER.  THE FIRST ONE TO PLACE THE QUEEN THERE WINS."); printf("\n");
    /* BASIC: 5070 PRINT */
line_5070:
    printf("\n");
    /* BASIC: 5080 PRINT "YOU GO FIRST AND PLACE THE QUEEN IN ANY ONE OF THE SQUARES" */
line_5080:
    printf("%s", "YOU GO FIRST AND PLACE THE QUEEN IN ANY ONE OF THE SQUARES"); printf("\n");
    /* BASIC: 5090 PRINT "ON THE TOP ROW OR RIGHT HAND COLUMN." */
line_5090:
    printf("%s", "ON THE TOP ROW OR RIGHT HAND COLUMN."); printf("\n");
    /* BASIC: 5100 PRINT "THAT WILL BE YOUR FIRST MOVE." */
line_5100:
    printf("%s", "THAT WILL BE YOUR FIRST MOVE."); printf("\n");
    /* BASIC: 5110 PRINT "WE ALTERNATE MOVES." */
line_5110:
    printf("%s", "WE ALTERNATE MOVES."); printf("\n");
    /* BASIC: 5120 PRINT "YOU MAY FORFEIT BY TYPING '0' AS YOUR MOVE." */
line_5120:
    printf("%s", "YOU MAY FORFEIT BY TYPING '0' AS YOUR MOVE."); printf("\n");
    /* BASIC: 5130 PRINT "BE SURE TO PRESS THE RETURN KEY AFTER EACH RESPONSE." */
line_5130:
    printf("%s", "BE SURE TO PRESS THE RETURN KEY AFTER EACH RESPONSE."); printf("\n");
    /* BASIC: 5140 PRINT */
line_5140:
    printf("\n");
    /* BASIC: 5150 PRINT */
line_5150:
    printf("\n");
    /* BASIC: 5160 PRINT */
line_5160:
    printf("\n");
    /* BASIC: 5170 FOR A=0 TO 7 */
line_5170:
    A = 0; for_loop_A: if ((1 >= 0 && A > 7) || (1 < 0 && A < 7)) goto end_for_A;
    /* BASIC: 5180 FOR B=1 TO 8 */
line_5180:
    B = 1; for_loop_B: if ((1 >= 0 && B > 8) || (1 < 0 && B < 8)) goto end_for_B;
    /* BASIC: 5185 I=8*A+B */
line_5185:
    I = 8*A+B;
    /* BASIC: 5190 PRINT S(I); */
line_5190:
    printf("%g ", (double)(S(I)));
    /* BASIC: 5200 NEXT B */
line_5200:
    B += 1; goto for_loop_B; end_for_B:;
    /* BASIC: 5210 PRINT */
line_5210:
    printf("\n");
    /* BASIC: 5220 PRINT */
line_5220:
    printf("\n");
    /* BASIC: 5230 PRINT */
line_5230:
    printf("\n");
    /* BASIC: 5240 NEXT A */
line_5240:
    A += 1; goto for_loop_A; end_for_A:;
    /* BASIC: 5250 PRINT */
line_5250:
    printf("\n");
    /* BASIC: 5260 RETURN */
line_5260:
    /* TODO: RETURN */
    /* BASIC: 9999 END */
line_9999:
    exit(0);

    return 0;
}
