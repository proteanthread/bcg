/*
 * Transpiled from tower.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double BYE, SHALL, SHOT, NOW, THAN, DISKS, GAME, GO, J, NEW, TYPE, CODE, SO, BELOW, TRIED, JERSEY, THE, WATCH, HANOI, ON, LEFT, TOP, TRANSFER, A, D, RIGHT, BUT, UP, IT, WRONG, PROGRAM, LIKE, IN, HOME, BY, MORRISTOWN, NEVER, TAKE, CHOICE, WOULDN, MUST, START, PUTTING, LISTEN, LUCK, PLAY, THEM, REPRESENT, TIME, BIG, ASSUME, TRY, PUZZLE, REFER, ILLEGAL, U, V, WANT, ENTRY, MIGHT, ALL, I, THANKS, ALLOW, CRUSH, NEEDLE, FROM, Y, M, MORE, W, ELSE, IS, MISTAKE, CONGRATULATIONS, BOTHER, SMALLER, K, KEY, TASK, NUMERICAL, OF, ONLY, Z, LL, SORRY, S, WILL, WARN, CREATIVE, JOB, MY, PLEASE, YOU, X, WISE, NO, WASTING, WOULD, GUY, WITH, TOWER, ETC, ONE, ANOTHER, WE, TOWERS, SIZE, DISK, GOOD, SOMEONE, MAY, THEIR, LARGER, BE, ARE, NEEDLES, MAX, MOVES, HOW, C, MAKE, MOVE, LONG, PERFORMED, CAN, ORDERS, WHICH, COMPUTING, JUST, HIT, E, ATTEMPT, MANY, AT, PLACE, DO, AGAIN, THAT, R, YES, NUMBERED, N, HAVE, SMALLEST, THIS, Q, NAMES;
    double T[1000] = {0}; /* Static array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 10 PRINT TAB(33);"TOWERS" */
line_10:
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "TOWERS"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 90 PRINT */
line_90:
    printf("\n");
    /* BASIC: 100 REM*** INITIALIZE */
line_100:
    // REM*** INITIALIZE
    /* BASIC: 110 DIM T(7,3) */
line_110:
    /* DIM T(7,3) (handled statically) */
    /* BASIC: 120 E=0 */
line_120:
    E = 0;
    /* BASIC: 130 FOR D=1 TO 7 */
line_130:
    D = 1; for_loop_D: if ((1 >= 0 && D > 7) || (1 < 0 && D < 7)) goto end_for_D;
    /* BASIC: 140 FOR N=1 TO 3 */
line_140:
    N = 1; for_loop_N: if ((1 >= 0 && N > 3) || (1 < 0 && N < 3)) goto end_for_N;
    /* BASIC: 150 T(D,N)=0 */
line_150:
    T(D,N) = 0;
    /* BASIC: 160 NEXT N */
line_160:
    N += 1; goto for_loop_N; end_for_N:;
    /* BASIC: 170 NEXT D */
line_170:
    D += 1; goto for_loop_D; end_for_D:;
    /* BASIC: 180 PRINT "TOWERS OF HANOI PUZZLE.": PRINT */
line_180:
    printf("%s", "TOWERS OF HANOI PUZZLE."); printf("\n");
    printf("\n");
    /* BASIC: 200 PRINT "YOU MUST TRANSFER THE DISKS FROM THE LEFT TO THE RIGHT" */
line_200:
    printf("%s", "YOU MUST TRANSFER THE DISKS FROM THE LEFT TO THE RIGHT"); printf("\n");
    /* BASIC: 205 PRINT "TOWER, ONE AT A TIME, NEVER PUTTING A LARGER DISK ON A" */
line_205:
    printf("%s", "TOWER, ONE AT A TIME, NEVER PUTTING A LARGER DISK ON A"); printf("\n");
    /* BASIC: 210 PRINT "SMALLER DISK.": PRINT */
line_210:
    printf("%s", "SMALLER DISK."); printf("\n");
    printf("\n");
    /* BASIC: 215 INPUT "HOW MANY DISKS DO YOU WANT TO MOVE (7 IS MAX)";S */
line_215:
    printf("%s", "HOW MANY DISKS DO YOU WANT TO MOVE (7 IS MAX)"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &S);
    /* BASIC: 220 PRINT */
line_220:
    printf("\n");
    /* BASIC: 230 M=0 */
line_230:
    M = 0;
    /* BASIC: 240 FOR Q=1 TO 7 */
line_240:
    Q = 1; for_loop_Q: if ((1 >= 0 && Q > 7) || (1 < 0 && Q < 7)) goto end_for_Q;
    /* BASIC: 250 IF Q=S THEN 350 */
line_250:
    if (Q==S) goto line_350;
    /* BASIC: 260 NEXT Q */
line_260:
    Q += 1; goto for_loop_Q; end_for_Q:;
    /* BASIC: 270 E=E+1 */
line_270:
    E = E+1;
    /* BASIC: 280 IF E>2 THEN 310 */
line_280:
    if (E>2) goto line_310;
    /* BASIC: 290 PRINT "SORRY, BUT I CAN'T DO THAT JOB FOR YOU.": GOTO 215 */
line_290:
    printf("%s", "SORRY, BUT I CAN'T DO THAT JOB FOR YOU."); printf("\n");
    goto line_215;
    /* BASIC: 310 PRINT "ALL RIGHT, WISE GUY, IF YOU CAN'T PLAY THE GAME RIGHT, I'LL" */
line_310:
    printf("%s", "ALL RIGHT, WISE GUY, IF YOU CAN'T PLAY THE GAME RIGHT, I'LL"); printf("\n");
    /* BASIC: 320 PRINT "JUST TAKE MY PUZZLE AND GO HOME.  SO LONG.": STOP */
line_320:
    printf("%s", "JUST TAKE MY PUZZLE AND GO HOME.  SO LONG."); printf("\n");
    exit(0);
    /* BASIC: 340 REM *** STORE DISKS FROM SMALLEST TO LARGEST */
line_340:
    // REM *** STORE DISKS FROM SMALLEST TO LARGEST
    /* BASIC: 350 PRINT "IN THIS PROGRAM, WE SHALL REFER TO DISKS BY NUMERICAL CODE." */
line_350:
    printf("%s", "IN THIS PROGRAM, WE SHALL REFER TO DISKS BY NUMERICAL CODE."); printf("\n");
    /* BASIC: 355 PRINT "3 WILL REPRESENT THE SMALLEST DISK, 5 THE NEXT SIZE," */
line_355:
    printf("%s", "3 WILL REPRESENT THE SMALLEST DISK, 5 THE NEXT SIZE,"); printf("\n");
    /* BASIC: 360 PRINT "7 THE NEXT, AND SO ON, UP TO 15.  IF YOU DO THE PUZZLE WITH" */
line_360:
    printf("%s", "7 THE NEXT, AND SO ON, UP TO 15.  IF YOU DO THE PUZZLE WITH"); printf("\n");
    /* BASIC: 365 PRINT "2 DISKS, THEIR CODE NAMES WOULD BE 13 AND 15.  WITH 3 DISKS" */
line_365:
    printf("%s", "2 DISKS, THEIR CODE NAMES WOULD BE 13 AND 15.  WITH 3 DISKS"); printf("\n");
    /* BASIC: 370 PRINT "THE CODE NAMES WOULD BE 11, 13 AND 15, ETC.  THE NEEDLES" */
line_370:
    printf("%s", "THE CODE NAMES WOULD BE 11, 13 AND 15, ETC.  THE NEEDLES"); printf("\n");
    /* BASIC: 375 PRINT "ARE NUMBERED FROM LEFT TO RIGHT, 1 TO 3.  WE WILL" */
line_375:
    printf("%s", "ARE NUMBERED FROM LEFT TO RIGHT, 1 TO 3.  WE WILL"); printf("\n");
    /* BASIC: 380 PRINT "START WITH THE DISKS ON NEEDLE 1, AND ATTEMPT TO MOVE THEM" */
line_380:
    printf("%s", "START WITH THE DISKS ON NEEDLE 1, AND ATTEMPT TO MOVE THEM"); printf("\n");
    /* BASIC: 385 PRINT "TO NEEDLE 3." */
line_385:
    printf("%s", "TO NEEDLE 3."); printf("\n");
    /* BASIC: 390 PRINT: PRINT "GOOD LUCK!": PRINT */
line_390:
    printf("\n");
    printf("%s", "GOOD LUCK!"); printf("\n");
    printf("\n");
    /* BASIC: 400 Y=7: D=15 */
line_400:
    Y = 7;
    D = 15;
    /* BASIC: 420 FOR X=S TO 1 STEP -1 */
line_420:
    X = S; for_loop_X: if ((-1 >= 0 && X > 1) || (-1 < 0 && X < 1)) goto end_for_X;
    /* BASIC: 430 T(Y,1)=D: D=D-2: Y=Y-1 */
line_430:
    T(Y,1) = D;
    D = D-2;
    Y = Y-1;
    /* BASIC: 460 NEXT X */
line_460:
    X += -1; goto for_loop_X; end_for_X:;
    /* BASIC: 470 GOSUB 1230 */
line_470:
    /* TODO: GOSUB 1230 */
    /* BASIC: 480 PRINT "WHICH DISK WOULD YOU LIKE TO MOVE";:E=0 */
line_480:
    printf("%s", "WHICH DISK WOULD YOU LIKE TO MOVE");
    E = 0;
    /* BASIC: 500 INPUT D */
line_500:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &D);
    /* BASIC: 510 IF (D-3)*(D-5)*(D-7)*(D-9)*(D-11)*(D-13)*(D-15)=0 THEN 580 */
line_510:
    if ((D-3)*(D-5)*(D-7)*(D-9)*(D-11)*(D-13)*(D-15)==0) goto line_580;
    /* BASIC: 520 PRINT "ILLEGAL ENTRY... YOU MAY ONLY TYPE 3,5,7,9,11,13, OR 15." */
line_520:
    printf("%s", "ILLEGAL ENTRY... YOU MAY ONLY TYPE 3,5,7,9,11,13, OR 15."); printf("\n");
    /* BASIC: 530 E=E+1: IF E>1 THEN 560 */
line_530:
    E = E+1;
    if (E>1) goto line_560;
    /* BASIC: 550 GOTO 500 */
line_550:
    goto line_500;
    /* BASIC: 560 PRINT "STOP WASTING MY TIME.  GO BOTHER SOMEONE ELSE.": STOP */
line_560:
    printf("%s", "STOP WASTING MY TIME.  GO BOTHER SOMEONE ELSE."); printf("\n");
    exit(0);
    /* BASIC: 580 REM *** CHECK IF REQUESTED DISK IS BELOW ANOTHER */
line_580:
    // REM *** CHECK IF REQUESTED DISK IS BELOW ANOTHER
    /* BASIC: 590 FOR R=1 TO 7 */
line_590:
    R = 1; for_loop_R: if ((1 >= 0 && R > 7) || (1 < 0 && R < 7)) goto end_for_R;
    /* BASIC: 600 FOR C=1 TO 3 */
line_600:
    C = 1; for_loop_C: if ((1 >= 0 && C > 3) || (1 < 0 && C < 3)) goto end_for_C;
    /* BASIC: 610 IF T(R,C)=D THEN 640 */
line_610:
    if (T(R,C)==D) goto line_640;
    /* BASIC: 620 NEXT C: NEXT R */
line_620:
    C += 1; goto for_loop_C; end_for_C:;
    R += 1; goto for_loop_R; end_for_R:;
    /* BASIC: 640 FOR Q=R TO 1 STEP -1 */
line_640:
    Q = R; for_loop_Q: if ((-1 >= 0 && Q > 1) || (-1 < 0 && Q < 1)) goto end_for_Q;
    /* BASIC: 645 IF T(Q,C)=0 THEN 660 */
line_645:
    if (T(Q,C)==0) goto line_660;
    /* BASIC: 650 IF T(Q,C)<D THEN 680 */
line_650:
    if (T(Q,C)<D) goto line_680;
    /* BASIC: 660 NEXT Q */
line_660:
    Q += -1; goto for_loop_Q; end_for_Q:;
    /* BASIC: 670 GOTO 700 */
line_670:
    goto line_700;
    /* BASIC: 680 PRINT "THAT DISK IS BELOW ANOTHER ONE.  MAKE ANOTHER CHOICE." */
line_680:
    printf("%s", "THAT DISK IS BELOW ANOTHER ONE.  MAKE ANOTHER CHOICE."); printf("\n");
    /* BASIC: 690 GOTO 480 */
line_690:
    goto line_480;
    /* BASIC: 700 E=0 */
line_700:
    E = 0;
    /* BASIC: 705 INPUT "PLACE DISK ON WHICH NEEDLE";N */
line_705:
    printf("%s", "PLACE DISK ON WHICH NEEDLE"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &N);
    /* BASIC: 730 IF (N-1)*(N-2)*(N-3)=0 THEN 800 */
line_730:
    if ((N-1)*(N-2)*(N-3)==0) goto line_800;
    /* BASIC: 735 E=E+1 */
line_735:
    E = E+1;
    /* BASIC: 740 IF E>1 THEN 780 */
line_740:
    if (E>1) goto line_780;
    /* BASIC: 750 PRINT "I'LL ASSUME YOU HIT THE WRONG KEY THIS TIME.  BUT WATCH IT," */
line_750:
    printf("%s", "I'LL ASSUME YOU HIT THE WRONG KEY THIS TIME.  BUT WATCH IT,"); printf("\n");
    /* BASIC: 760 PRINT "I ONLY ALLOW ONE MISTAKE.": GOTO 705 */
line_760:
    printf("%s", "I ONLY ALLOW ONE MISTAKE."); printf("\n");
    goto line_705;
    /* BASIC: 780 PRINT "I TRIED TO WARN YOU, BUT YOU WOULDN'T LISTEN." */
line_780:
    printf("%s", "I TRIED TO WARN YOU, BUT YOU WOULDN'T LISTEN."); printf("\n");
    /* BASIC: 790 PRINT "BYE BYE, BIG SHOT.":STOP */
line_790:
    printf("%s", "BYE BYE, BIG SHOT."); printf("\n");
    exit(0);
    /* BASIC: 800 FOR R=1 TO 7 */
line_800:
    R = 1; for_loop_R: if ((1 >= 0 && R > 7) || (1 < 0 && R < 7)) goto end_for_R;
    /* BASIC: 810 IF T(R,N)<>0 THEN 840 */
line_810:
    if (T(R,N)!=0) goto line_840;
    /* BASIC: 820 NEXT R */
line_820:
    R += 1; goto for_loop_R; end_for_R:;
    /* BASIC: 830 GOTO 880 */
line_830:
    goto line_880;
    /* BASIC: 835 REM *** CHECK IF DISK TO BE PLACED ON A LARGER ONE */
line_835:
    // REM *** CHECK IF DISK TO BE PLACED ON A LARGER ONE
    /* BASIC: 840 IF D<T(R,N) THEN 880 */
line_840:
    if (D<T(R,N)) goto line_880;
    /* BASIC: 850 PRINT "YOU CAN'T PLACE A LARGER DISK ON TOP OF A SMALLER ONE," */
line_850:
    printf("%s", "YOU CAN'T PLACE A LARGER DISK ON TOP OF A SMALLER ONE,"); printf("\n");
    /* BASIC: 860 PRINT "IT MIGHT CRUSH IT!": PRINT "NOW THEN, ";:GOTO 480 */
line_860:
    printf("%s", "IT MIGHT CRUSH IT!"); printf("\n");
    printf("%s", "NOW THEN, ");
    goto line_480;
    /* BASIC: 875 REM *** MOVE RELOCATED DISK */
line_875:
    // REM *** MOVE RELOCATED DISK
    /* BASIC: 880 FOR V=1 TO 7: FOR W=1 TO 3 */
line_880:
    V = 1; for_loop_V: if ((1 >= 0 && V > 7) || (1 < 0 && V < 7)) goto end_for_V;
    W = 1; for_loop_W: if ((1 >= 0 && W > 3) || (1 < 0 && W < 3)) goto end_for_W;
    /* BASIC: 900 IF T(V,W)=D THEN 930 */
line_900:
    if (T(V,W)==D) goto line_930;
    /* BASIC: 910 NEXT W: NEXT V */
line_910:
    W += 1; goto for_loop_W; end_for_W:;
    V += 1; goto for_loop_V; end_for_V:;
    /* BASIC: 925 REM *** LOCATE EMPTY SPACE ON NEEDLE N */
line_925:
    // REM *** LOCATE EMPTY SPACE ON NEEDLE N
    /* BASIC: 930 FOR U=1 TO 7 */
line_930:
    U = 1; for_loop_U: if ((1 >= 0 && U > 7) || (1 < 0 && U < 7)) goto end_for_U;
    /* BASIC: 940 IF T(U,N)<>0 THEN 970 */
line_940:
    if (T(U,N)!=0) goto line_970;
    /* BASIC: 950 NEXT U */
line_950:
    U += 1; goto for_loop_U; end_for_U:;
    /* BASIC: 960 U=7: GOTO 980 */
line_960:
    U = 7;
    goto line_980;
    /* BASIC: 965 REM *** MOVE DISK AND SET OLD LOCATION TO 0 */
line_965:
    // REM *** MOVE DISK AND SET OLD LOCATION TO 0
    /* BASIC: 970 U=U-1 */
line_970:
    U = U-1;
    /* BASIC: 980 T(U,N)=T(V,W): T(V,W)=0 */
line_980:
    T(U,N) = T(V,W);
    T(V,W) = 0;
    /* BASIC: 995 REM *** PRINT OUT CURRENT STATUS */
line_995:
    // REM *** PRINT OUT CURRENT STATUS
    /* BASIC: 1000 GOSUB 1230 */
line_1000:
    /* TODO: GOSUB 1230 */
    /* BASIC: 1018 REM *** CHECK IF DONE */
line_1018:
    // REM *** CHECK IF DONE
    /* BASIC: 1020 M=M+1 */
line_1020:
    M = M+1;
    /* BASIC: 1030 FOR R=1 TO 7: FOR C=1 TO 2 */
line_1030:
    R = 1; for_loop_R: if ((1 >= 0 && R > 7) || (1 < 0 && R < 7)) goto end_for_R;
    C = 1; for_loop_C: if ((1 >= 0 && C > 2) || (1 < 0 && C < 2)) goto end_for_C;
    /* BASIC: 1050 IF T(R,C)<>0 THEN 1090 */
line_1050:
    if (T(R,C)!=0) goto line_1090;
    /* BASIC: 1060 NEXT C: NEXT R */
line_1060:
    C += 1; goto for_loop_C; end_for_C:;
    R += 1; goto for_loop_R; end_for_R:;
    /* BASIC: 1080 GOTO 1120 */
line_1080:
    goto line_1120;
    /* BASIC: 1090 IF M<=128 THEN 480 */
line_1090:
    if (M<==128) goto line_480;
    /* BASIC: 1100 PRINT "SORRY, BUT I HAVE ORDERS TO STOP IF YOU MAKE MORE THAN" */
line_1100:
    printf("%s", "SORRY, BUT I HAVE ORDERS TO STOP IF YOU MAKE MORE THAN"); printf("\n");
    /* BASIC: 1110 PRINT "128 MOVES.": STOP */
line_1110:
    printf("%s", "128 MOVES."); printf("\n");
    exit(0);
    /* BASIC: 1120 IF M<>2^S-1 THEN 1140 */
line_1120:
    if (M!=2^S-1) goto line_1140;
    /* BASIC: 1130 PRINT:PRINT "CONGRATULATIONS!!":PRINT */
line_1130:
    printf("\n");
    printf("%s", "CONGRATULATIONS!!"); printf("\n");
    printf("\n");
    /* BASIC: 1140 PRINT "YOU HAVE PERFORMED THE TASK IN";M;"MOVES." */
line_1140:
    printf("%s", "YOU HAVE PERFORMED THE TASK IN"); printf("%g ", (double)(M)); printf("%s", "MOVES."); printf("\n");
    /* BASIC: 1150 PRINT: PRINT "TRY AGAIN (YES OR NO)";: INPUT A$ */
line_1150:
    printf("\n");
    printf("%s", "TRY AGAIN (YES OR NO)");
    printf("? "); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    /* BASIC: 1160 IF A$="NO" THEN 1390 */
line_1160:
    if (A$=="NO") goto line_1390;
    /* BASIC: 1170 IF A$="YES" THEN 90 */
line_1170:
    if (A$=="YES") goto line_90;
    /* BASIC: 1180 PRINT: PRINT "'YES' OR 'NO' PLEASE";: INPUT A$: GOTO 1160 */
line_1180:
    printf("\n");
    printf("%s", "'YES' OR 'NO' PLEASE");
    printf("? "); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    goto line_1160;
    /* BASIC: 1230 REM *** PRINT SUBROUTINE */
line_1230:
    // REM *** PRINT SUBROUTINE
    /* BASIC: 1240 FOR K=1 TO 7 */
line_1240:
    K = 1; for_loop_K: if ((1 >= 0 && K > 7) || (1 < 0 && K < 7)) goto end_for_K;
    /* BASIC: 1250 Z=10 */
line_1250:
    Z = 10;
    /* BASIC: 1260 FOR J=1 TO 3 */
line_1260:
    J = 1; for_loop_J: if ((1 >= 0 && J > 3) || (1 < 0 && J < 3)) goto end_for_J;
    /* BASIC: 1270 IF T(K,J)=0 THEN 1330 */
line_1270:
    if (T(K,J)==0) goto line_1330;
    /* BASIC: 1280 PRINT TAB(Z-INT(T(K,J)/2)); */
line_1280:
    { int _t; for(_t=0; _t<Z-floor(T(; _t++) printf(" "); } printf("\t"); printf("%g ", (double)(J)/2))));
    /* BASIC: 1290 FOR V=1 TO T(K,J) */
line_1290:
    V = 1; for_loop_V: if ((1 >= 0 && V > T(K,J)) || (1 < 0 && V < T(K,J))) goto end_for_V;
    /* BASIC: 1300 PRINT "*"; */
line_1300:
    printf("%s", "*");
    /* BASIC: 1310 NEXT V */
line_1310:
    V += 1; goto for_loop_V; end_for_V:;
    /* BASIC: 1320 GOTO 1340 */
line_1320:
    goto line_1340;
    /* BASIC: 1330 PRINT TAB(Z);"*"; */
line_1330:
    { int _t; for(_t=0; _t<Z; _t++) printf(" "); } printf("%s", "*");
    /* BASIC: 1340 Z=Z+21 */
line_1340:
    Z = Z+21;
    /* BASIC: 1350 NEXT J */
line_1350:
    J += 1; goto for_loop_J; end_for_J:;
    /* BASIC: 1360 PRINT */
line_1360:
    printf("\n");
    /* BASIC: 1370 NEXT K */
line_1370:
    K += 1; goto for_loop_K; end_for_K:;
    /* BASIC: 1380 RETURN */
line_1380:
    /* TODO: RETURN */
    /* BASIC: 1390 PRINT: PRINT "THANKS FOR THE GAME!": PRINT: END */
line_1390:
    printf("\n");
    printf("%s", "THANKS FOR THE GAME!"); printf("\n");
    printf("\n");
    exit(0);

    return 0;
}
