/*
 * Transpiled from onecheck.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double USE, OPENING, ABS, J, NEW, POSSIBLE, BOARD, ANSWER, JUMP, INDICATE, JERSEY, THE, SPACES, ON, HOPE, WHEN, T, HAD, IN, OUT, BY, MORRISTOWN, OUTSIDE, AHL, INDICATES, CHECKERS, TURN, TRY, DAVID, PUZZLE, ILLEGAL, HERE, F1, CHECKERBOARD, I, FROM, FUN, M, IS, K, EMPTY, OF, SOLITAIRE, CHECKER, NUMERICAL, OBJECT, S, CREATIVE, EACH, PLEASE, YOU, AS, NO, F2, SQUARE, JUMPS, ONE, QUESTION, PRINTED, T1, PLACED, PIECES, AN, ARE, POSITION, STANDARD, MOVE, WISH, COMPUTING, F, AGAIN, YES, O, MADE, NUMBERED, T2, HAVE, CHECK;
    double A[1000] = {0}; /* Static array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 2 PRINT TAB(30);"ONE CHECK" */
line_2:
    { int _t; for(_t=0; _t<30; _t++) printf(" "); } printf("%s", "ONE CHECK"); printf("\n");
    /* BASIC: 4 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 6 PRINT: PRINT: PRINT */
line_6:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 8 DIM A(64) */
line_8:
    /* DIM A(64) (handled statically) */
    /* BASIC: 10 PRINT "SOLITAIRE CHECKER PUZZLE BY DAVID AHL" */
line_10:
    printf("%s", "SOLITAIRE CHECKER PUZZLE BY DAVID AHL"); printf("\n");
    /* BASIC: 15 PRINT */
line_15:
    printf("\n");
    /* BASIC: 20 PRINT "48 CHECKERS ARE PLACED ON THE 2 OUTSIDE SPACES OF A" */
line_20:
    printf("%s", "48 CHECKERS ARE PLACED ON THE 2 OUTSIDE SPACES OF A"); printf("\n");
    /* BASIC: 25 PRINT "STANDARD 64-SQUARE CHECKERBOARD.  THE OBJECT IS TO" */
line_25:
    printf("%s", "STANDARD 64-SQUARE CHECKERBOARD.  THE OBJECT IS TO"); printf("\n");
    /* BASIC: 30 PRINT "REMOVE AS MANY CHECKERS AS POSSIBLE BY DIAGONAL JUMPS" */
line_30:
    printf("%s", "REMOVE AS MANY CHECKERS AS POSSIBLE BY DIAGONAL JUMPS"); printf("\n");
    /* BASIC: 35 PRINT "(AS IN STANDARD CHECKERS).  USE THE NUMBERED BOARD TO" */
line_35:
    printf("%s", "(AS IN STANDARD CHECKERS).  USE THE NUMBERED BOARD TO"); printf("\n");
    /* BASIC: 40 PRINT "INDICATE THE SQUARE YOU WISH TO JUMP FROM AND TO.  ON" */
line_40:
    printf("%s", "INDICATE THE SQUARE YOU WISH TO JUMP FROM AND TO.  ON"); printf("\n");
    /* BASIC: 45 PRINT "THE BOARD PRINTED OUT ON EACH TURN '1' INDICATES A" */
line_45:
    printf("%s", "THE BOARD PRINTED OUT ON EACH TURN '1' INDICATES A"); printf("\n");
    /* BASIC: 50 PRINT "CHECKER AND '0' AN EMPTY SQUARE.  WHEN YOU HAVE NO" */
line_50:
    printf("%s", "CHECKER AND '0' AN EMPTY SQUARE.  WHEN YOU HAVE NO"); printf("\n");
    /* BASIC: 55 PRINT "POSSIBLE JUMPS REMAINING, INPUT A '0' IN RESPONSE TO" */
line_55:
    printf("%s", "POSSIBLE JUMPS REMAINING, INPUT A '0' IN RESPONSE TO"); printf("\n");
    /* BASIC: 60 PRINT "QUESTION 'JUMP FROM ?'" */
line_60:
    printf("%s", "QUESTION 'JUMP FROM ?'"); printf("\n");
    /* BASIC: 62 PRINT */
line_62:
    printf("\n");
    /* BASIC: 63 PRINT "HERE IS THE NUMERICAL BOARD:" */
line_63:
    printf("%s", "HERE IS THE NUMERICAL BOARD:"); printf("\n");
    /* BASIC: 66 PRINT */
line_66:
    printf("\n");
    /* BASIC: 70 FOR J=1 TO 57 STEP 8 */
line_70:
    J = 1; for_loop_J: if ((8 >= 0 && J > 57) || (8 < 0 && J < 57)) goto end_for_J;
    /* BASIC: 74 PRINT J;TAB(4);J+1;TAB(8);J+2;TAB(12);J+3;TAB(16);J+4;TAB(20);J+5; */
line_74:
    printf("%g ", (double)(J)); { int _t; for(_t=0; _t<4; _t++) printf(" "); } printf("%g ", (double)(J+1)); { int _t; for(_t=0; _t<8; _t++) printf(" "); } printf("%g ", (double)(J+2)); { int _t; for(_t=0; _t<12; _t++) printf(" "); } printf("%g ", (double)(J+3)); { int _t; for(_t=0; _t<16; _t++) printf(" "); } printf("%g ", (double)(J+4)); { int _t; for(_t=0; _t<20; _t++) printf(" "); } printf("%g ", (double)(J+5));
    /* BASIC: 75 PRINT TAB(24);J+6;TAB(28);J+7 */
line_75:
    { int _t; for(_t=0; _t<24; _t++) printf(" "); } printf("%g ", (double)(J+6)); { int _t; for(_t=0; _t<28; _t++) printf(" "); } printf("%g ", (double)(J+7)); printf("\n");
    /* BASIC: 76 NEXT J */
line_76:
    J += 8; goto for_loop_J; end_for_J:;
    /* BASIC: 77 PRINT */
line_77:
    printf("\n");
    /* BASIC: 78 PRINT "AND HERE IS THE OPENING POSITION OF THE CHECKERS." */
line_78:
    printf("%s", "AND HERE IS THE OPENING POSITION OF THE CHECKERS."); printf("\n");
    /* BASIC: 79 PRINT */
line_79:
    printf("\n");
    /* BASIC: 80 FOR J=1 TO 64 */
line_80:
    J = 1; for_loop_J: if ((1 >= 0 && J > 64) || (1 < 0 && J < 64)) goto end_for_J;
    /* BASIC: 82 A(J)=1 */
line_82:
    A(J) = 1;
    /* BASIC: 84 NEXT J */
line_84:
    J += 1; goto for_loop_J; end_for_J:;
    /* BASIC: 86 FOR J=19 TO 43 STEP 8 */
line_86:
    J = 19; for_loop_J: if ((8 >= 0 && J > 43) || (8 < 0 && J < 43)) goto end_for_J;
    /* BASIC: 88 FOR I=J TO J+3 */
line_88:
    I = J; for_loop_I: if ((1 >= 0 && I > J+3) || (1 < 0 && I < J+3)) goto end_for_I;
    /* BASIC: 90 A(I)=0 */
line_90:
    A(I) = 0;
    /* BASIC: 92 NEXT I */
line_92:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 94 NEXT J */
line_94:
    J += 8; goto for_loop_J; end_for_J:;
    /* BASIC: 96 M=0 */
line_96:
    M = 0;
    /* BASIC: 98 GOTO 340 */
line_98:
    goto line_340;
    /* BASIC: 100 INPUT "JUMP FROM";F */
line_100:
    printf("%s", "JUMP FROM"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &F);
    /* BASIC: 105 IF F=0 THEN 500 */
line_105:
    if (F==0) goto line_500;
    /* BASIC: 110 INPUT "TO";T */
line_110:
    printf("%s", "TO"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &T);
    /* BASIC: 112 PRINT */
line_112:
    printf("\n");
    /* BASIC: 118 REM *** CHECK LEGALITY OF MOVE */
line_118:
    // REM *** CHECK LEGALITY OF MOVE
    /* BASIC: 120 F1=INT((F-1)/8) */
line_120:
    F1 = floor((F-1)/8);
    /* BASIC: 130 F2=F-8*F1 */
line_130:
    F2 = F-8*F1;
    /* BASIC: 140 T1=INT((T-1)/8) */
line_140:
    T1 = floor((T-1)/8);
    /* BASIC: 150 T2=T-8*T1 */
line_150:
    T2 = T-8*T1;
    /* BASIC: 160 IF F1>7 THEN 230 */
line_160:
    if (F1>7) goto line_230;
    /* BASIC: 170 IF T1>7 THEN 230 */
line_170:
    if (T1>7) goto line_230;
    /* BASIC: 180 IF F2>8 THEN 230 */
line_180:
    if (F2>8) goto line_230;
    /* BASIC: 190 IF T2>8 THEN 230 */
line_190:
    if (T2>8) goto line_230;
    /* BASIC: 200 IF ABS(F1-T1)<>2 THEN 230 */
line_200:
    if (fabs(F1-T1)!=2) goto line_230;
    /* BASIC: 210 IF ABS(F2-T2)<>2 THEN 230 */
line_210:
    if (fabs(F2-T2)!=2) goto line_230;
    /* BASIC: 212 IF A((T+F)/2)=0 THEN 230 */
line_212:
    if (A((T+F)/2)==0) goto line_230;
    /* BASIC: 215 IF A(F)=0 THEN 230 */
line_215:
    if (A(F)==0) goto line_230;
    /* BASIC: 220 IF A(T)=1 THEN 230 */
line_220:
    if (A(T)==1) goto line_230;
    /* BASIC: 225 GOTO 250 */
line_225:
    goto line_250;
    /* BASIC: 230 PRINT "ILLEGAL MOVE.  TRY AGAIN..." */
line_230:
    printf("%s", "ILLEGAL MOVE.  TRY AGAIN..."); printf("\n");
    /* BASIC: 240 GOTO 100 */
line_240:
    goto line_100;
    /* BASIC: 245 REM *** UPDATE BOARD */
line_245:
    // REM *** UPDATE BOARD
    /* BASIC: 250 A(T)=1 */
line_250:
    A(T) = 1;
    /* BASIC: 260 A(F)=0 */
line_260:
    A(F) = 0;
    /* BASIC: 270 A((T+F)/2)=0 */
line_270:
    A((T+F)/2) = 0;
    /* BASIC: 290 M=M+1 */
line_290:
    M = M+1;
    /* BASIC: 310 REM *** PRINT BOARD */
line_310:
    // REM *** PRINT BOARD
    /* BASIC: 340 FOR J=1 TO 57 STEP 8 */
line_340:
    J = 1; for_loop_J: if ((8 >= 0 && J > 57) || (8 < 0 && J < 57)) goto end_for_J;
    /* BASIC: 350 FOR I=J TO J+7 */
line_350:
    I = J; for_loop_I: if ((1 >= 0 && I > J+7) || (1 < 0 && I < J+7)) goto end_for_I;
    /* BASIC: 360 PRINT A(I); */
line_360:
    printf("%g ", (double)(A(I)));
    /* BASIC: 370 NEXT I */
line_370:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 380 PRINT */
line_380:
    printf("\n");
    /* BASIC: 390 NEXT J */
line_390:
    J += 8; goto for_loop_J; end_for_J:;
    /* BASIC: 400 PRINT */
line_400:
    printf("\n");
    /* BASIC: 410 GOTO 100 */
line_410:
    goto line_100;
    /* BASIC: 490 REM *** END GAME SUMMARY */
line_490:
    // REM *** END GAME SUMMARY
    /* BASIC: 500 S=0 */
line_500:
    S = 0;
    /* BASIC: 510 FOR I=1 TO 64 */
line_510:
    I = 1; for_loop_I: if ((1 >= 0 && I > 64) || (1 < 0 && I < 64)) goto end_for_I;
    /* BASIC: 520 S=S+A(I) */
line_520:
    S = S+A(I);
    /* BASIC: 530 NEXT I */
line_530:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 540 PRINT:PRINT "YOU MADE";M;"JUMPS AND HAD";S;"PIECES" */
line_540:
    printf("\n");
    printf("%s", "YOU MADE"); printf("%g ", (double)(M)); printf("%s", "JUMPS AND HAD"); printf("%g ", (double)(S)); printf("%s", "PIECES"); printf("\n");
    /* BASIC: 550 PRINT "REMAINING ON THE BOARD." */
line_550:
    printf("%s", "REMAINING ON THE BOARD."); printf("\n");
    /* BASIC: 560 PRINT */
line_560:
    printf("\n");
    /* BASIC: 562 INPUT "TRY AGAIN";A$ */
line_562:
    printf("%s", "TRY AGAIN"); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    /* BASIC: 570 IF A$="YES" THEN 70 */
line_570:
    if (A$=="YES") goto line_70;
    /* BASIC: 575 IF A$="NO" THEN 600 */
line_575:
    if (A$=="NO") goto line_600;
    /* BASIC: 580 PRINT "PLEASE ANSWER 'YES' OR 'NO'." */
line_580:
    printf("%s", "PLEASE ANSWER 'YES' OR 'NO'."); printf("\n");
    /* BASIC: 590 GOTO 562 */
line_590:
    goto line_562;
    /* BASIC: 600 PRINT */
line_600:
    printf("\n");
    /* BASIC: 610 PRINT "O.K.  HOPE YOU HAD FUN!!" */
line_610:
    printf("%s", "O.K.  HOPE YOU HAD FUN!!"); printf("\n");
    /* BASIC: 999 END */
line_999:
    exit(0);

    return 0;
}
