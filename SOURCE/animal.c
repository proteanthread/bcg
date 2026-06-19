/*
 * Transpiled from animal.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double FROM, QDOES, ARE, Y, READ, BE, ANIMALS, MORRISTOWN, MID, B, C, IS, DATA, NEW, TYPE, ANIMAL, K, Z1, OF, Z, ANSWER, WAS, WILL, COMPUTING, CREATIVE, JERSEY, THE, SWIM, PLAY, Y2, COMPUTER, THINK, LIST, PLEASE, TRY, YOU, GUESS, LEFT, X, A, STR, ALREADY, RIGHT, WOULD, N3, IT, V, ANOTHER, AFISH, THAT, KNOW, QUESTION, WHY, T, WERE, ABIRD, N, DISTINGUISH, I, Q, IN, THINKING, AN;
    char A_str[1000][256] = {0}; /* Static string array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 10 PRINT TAB(32);"ANIMAL" */
line_10:
    { int _t; for(_t=0; _t<32; _t++) printf(" "); } printf("%s", "ANIMAL"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT: PRINT: PRINT */
line_30:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 40 PRINT "PLAY 'GUESS THE ANIMAL'" */
line_40:
    printf("%s", "PLAY 'GUESS THE ANIMAL'"); printf("\n");
    /* BASIC: 45 PRINT */
line_45:
    printf("\n");
    /* BASIC: 50 PRINT "THINK OF AN ANIMAL AND THE COMPUTER WILL TRY TO GUESS IT." */
line_50:
    printf("%s", "THINK OF AN ANIMAL AND THE COMPUTER WILL TRY TO GUESS IT."); printf("\n");
    /* BASIC: 60 PRINT */
line_60:
    printf("\n");
    /* BASIC: 70 DIM A$(200) */
line_70:
    /* DIM A$(200) (handled statically) */
    /* BASIC: 80 FOR I=0 TO 3 */
line_80:
    I = 0; for_loop_I: if ((1 >= 0 && I > 3) || (1 < 0 && I < 3)) goto end_for_I;
    /* BASIC: 90 READ A$(I) */
line_90:
    /* UNTRANSLATED: READ A$(I) */
    /* BASIC: 100 NEXT I */
line_100:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 110 N=VAL(A$(0)) */
line_110:
    N = VAL(A$(0));
    /* BASIC: 120 REM          MAIN CONTROL SECTION */
line_120:
    // REM          MAIN CONTROL SECTION
    /* BASIC: 130 INPUT "ARE YOU THINKING OF AN ANIMAL";A$ */
line_130:
    printf("%s", "ARE YOU THINKING OF AN ANIMAL"); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    /* BASIC: 140 IF A$="LIST" THEN 600 */
line_140:
    if (A$=="LIST") goto line_600;
    /* BASIC: 150 IF LEFT$(A$,1)<>"Y" THEN 120 */
line_150:
    if (LEFT$(A$,1)!="Y") goto line_120;
    /* BASIC: 160 K=1 */
line_160:
    K = 1;
    /* BASIC: 170 GOSUB 390 */
line_170:
    /* TODO: GOSUB 390 */
    /* BASIC: 180 IF LEN(A$(K))=0 THEN 999 */
line_180:
    if (LEN(A$(K))==0) goto line_999;
    /* BASIC: 190 IF LEFT$(A$(K),2)="\Q" THEN 170 */
line_190:
    if (LEFT$(A$(K),2)=="\Q") goto line_170;
    /* BASIC: 200 PRINT "IS IT A ";RIGHT$(A$(K),LEN(A$(K))-2); */
line_200:
    printf("%s", "IS IT A "); printf("%g ", (double)(RIGHT$(A$(K))); printf("\t"); printf("%g ", (double)(LEN(A$(K))-2)));
    /* BASIC: 210 INPUT A$ */
line_210:
    printf("? "); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    /* BASIC: 220 A$=LEFT$(A$,1) */
line_220:
    strncpy(A_str, "LEFT$(A$,1)", sizeof(A_str)); /* String assign approx */
    /* BASIC: 230 IF LEFT$(A$,1)="Y" THEN PRINT "WHY NOT TRY ANOTHER ANIMAL?": GOTO 120 */
line_230:
    if (LEFT$(A$,1)=="Y") { printf("%s", "WHY NOT TRY ANOTHER ANIMAL?"); printf("\n"); }
    goto line_120;
    /* BASIC: 240 INPUT "THE ANIMAL YOU WERE THINKING OF WAS A ";V$ */
line_240:
    printf("%s", "THE ANIMAL YOU WERE THINKING OF WAS A "); fgets(V_str, sizeof(V_str), stdin); V_str[strcspn(V_str, "\n")] = 0;
    /* BASIC: 250 PRINT "PLEASE TYPE IN A QUESTION THAT WOULD DISTINGUISH A" */
line_250:
    printf("%s", "PLEASE TYPE IN A QUESTION THAT WOULD DISTINGUISH A"); printf("\n");
    /* BASIC: 260 PRINT V$;" FROM A ";RIGHT$(A$(K),LEN(A$(K))-2) */
line_260:
    printf("%s", V_str); printf("%s", " FROM A "); printf("%g ", (double)(RIGHT$(A$(K))); printf("\t"); printf("%g ", (double)(LEN(A$(K))-2))); printf("\n");
    /* BASIC: 270 INPUT X$ */
line_270:
    printf("? "); fgets(X_str, sizeof(X_str), stdin); X_str[strcspn(X_str, "\n")] = 0;
    /* BASIC: 280 PRINT "FOR A ";V$;" THE ANSWER WOULD BE "; */
line_280:
    printf("%s", "FOR A "); printf("%s", V_str); printf("%s", " THE ANSWER WOULD BE ");
    /* BASIC: 290 INPUT A$ */
line_290:
    printf("? "); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    /* BASIC: 300 A$=LEFT$(A$,1): IF A$<>"Y" AND A$<>"N" THEN 280 */
line_300:
    strncpy(A_str, "LEFT$(A$,1)", sizeof(A_str)); /* String assign approx */
    if (A$!="Y" && A$!="N") goto line_280;
    /* BASIC: 310 IF A$="Y" THEN B$="N" */
line_310:
    if (A$=="Y") { strncpy(B_str, ""N"", sizeof(B_str)); /* String assign approx */ }
    /* BASIC: 320 IF A$="N" THEN B$="Y" */
line_320:
    if (A$=="N") { strncpy(B_str, ""Y"", sizeof(B_str)); /* String assign approx */ }
    /* BASIC: 330 Z1=VAL(A$(0)) */
line_330:
    Z1 = VAL(A$(0));
    /* BASIC: 340 A$(0)=STR$(Z1+2) */
line_340:
    A$(0) = STR$(Z1+2);
    /* BASIC: 350 A$(Z1)=A$(K) */
line_350:
    A$(Z1) = A$(K);
    /* BASIC: 360 A$(Z1+1)="\A"+V$ */
line_360:
    A$(Z1+1) = "\A"+V$;
    /* BASIC: 370 A$(K)="\Q"+X$+"\"+A$+STR$(Z1+1)+"\"+B$+STR$(Z1)+"\" */
line_370:
    A$(K) = "\Q"+X$+"\"+A$+STR$(Z1+1)+"\"+B$+STR$(Z1)+"\";
    /* BASIC: 380 GOTO 120 */
line_380:
    goto line_120;
    /* BASIC: 390 REM     SUBROUTINE TO PRINT QUESTIONS */
line_390:
    // REM     SUBROUTINE TO PRINT QUESTIONS
    /* BASIC: 400 Q$=A$(K) */
line_400:
    strncpy(Q_str, "A$(K)", sizeof(Q_str)); /* String assign approx */
    /* BASIC: 410 FOR Z=3 TO LEN(Q$) */
line_410:
    Z = 3; for_loop_Z: if ((1 >= 0 && Z > LEN(Q$)) || (1 < 0 && Z < LEN(Q$))) goto end_for_Z;
    /* BASIC: 415 IF MID$(Q$,Z,1)<>"\" THEN PRINT MID$(Q$,Z,1);: NEXT Z */
line_415:
    if (MID$(Q$,Z,1)!="\") { printf("%s", MID$(Q_str); printf("\t"); printf("%g ", (double)(Z)); printf("\t"); printf("%g ", (double)(1))); }
    Z += 1; goto for_loop_Z; end_for_Z:;
    /* BASIC: 420 INPUT C$ */
line_420:
    printf("? "); fgets(C_str, sizeof(C_str), stdin); C_str[strcspn(C_str, "\n")] = 0;
    /* BASIC: 430 C$=LEFT$(C$,1) */
line_430:
    strncpy(C_str, "LEFT$(C$,1)", sizeof(C_str)); /* String assign approx */
    /* BASIC: 440 IF C$<>"Y" AND C$<>"N" THEN 410 */
line_440:
    if (C$!="Y" && C$!="N") goto line_410;
    /* BASIC: 450 T$="\"+C$ */
line_450:
    strncpy(T_str, ""\"+C$", sizeof(T_str)); /* String assign approx */
    /* BASIC: 455 FOR X=3 TO LEN(Q$)-1 */
line_455:
    X = 3; for_loop_X: if ((1 >= 0 && X > LEN(Q$)-1) || (1 < 0 && X < LEN(Q$)-1)) goto end_for_X;
    /* BASIC: 460 IF MID$(Q$,X,2)=T$ THEN 480 */
line_460:
    if (MID$(Q$,X,2)==T$) goto line_480;
    /* BASIC: 470 NEXT X */
line_470:
    X += 1; goto for_loop_X; end_for_X:;
    /* BASIC: 475 STOP */
line_475:
    exit(0);
    /* BASIC: 480 FOR Y=X+1 TO LEN(Q$) */
line_480:
    Y = X+1; for_loop_Y: if ((1 >= 0 && Y > LEN(Q$)) || (1 < 0 && Y < LEN(Q$))) goto end_for_Y;
    /* BASIC: 490 IF MID$(Q$,Y,1)="\" THEN 510 */
line_490:
    if (MID$(Q$,Y,1)=="\") goto line_510;
    /* BASIC: 500 NEXT Y */
line_500:
    Y += 1; goto for_loop_Y; end_for_Y:;
    /* BASIC: 505 STOP */
line_505:
    exit(0);
    /* BASIC: 510 K=VAL(MID$(Q$,X+2,Y-X-2)) */
line_510:
    K = VAL(MID$(Q$,X+2,Y-X-2));
    /* BASIC: 520 RETURN */
line_520:
    /* TODO: RETURN */
    /* BASIC: 530 DATA "4","\QDOES IT SWIM\Y2\N3\","\AFISH","\ABIRD" */
line_530:
    /* UNTRANSLATED: DATA "4","\QDOES IT SWIM\Y2\N3\","\AFISH","\ABIRD" */
    /* BASIC: 600 PRINT:PRINT "ANIMALS I ALREADY KNOW ARE:" */
line_600:
    printf("\n");
    printf("%s", "ANIMALS I ALREADY KNOW ARE:"); printf("\n");
    /* BASIC: 605 X=0 */
line_605:
    X = 0;
    /* BASIC: 610 FOR I=1 TO 200 */
line_610:
    I = 1; for_loop_I: if ((1 >= 0 && I > 200) || (1 < 0 && I < 200)) goto end_for_I;
    /* BASIC: 620 IF LEFT$(A$(I),2)<>"\A" THEN 650 */
line_620:
    if (LEFT$(A$(I),2)!="\A") goto line_650;
    /* BASIC: 624 PRINT TAB(15*X); */
line_624:
    { int _t; for(_t=0; _t<15*X; _t++) printf(" "); }
    /* BASIC: 630 FOR Z=3 TO LEN(A$(I)) */
line_630:
    Z = 3; for_loop_Z: if ((1 >= 0 && Z > LEN(A$(I))) || (1 < 0 && Z < LEN(A$(I)))) goto end_for_Z;
    /* BASIC: 640 IF MID$(A$(I),Z,1)<>"\" THEN PRINT MID$(A$(I),Z,1);: NEXT Z */
line_640:
    if (MID$(A$(I),Z,1)!="\") { printf("%g ", (double)(MID$(A$(I))); printf("\t"); printf("%g ", (double)(Z)); printf("\t"); printf("%g ", (double)(1))); }
    Z += 1; goto for_loop_Z; end_for_Z:;
    /* BASIC: 645 X=X+1: IF X=4 THEN X=0: PRINT */
line_645:
    X = X+1;
    if (X==4) { X = 0; }
    printf("\n");
    /* BASIC: 650 NEXT I */
line_650:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 660 PRINT */
line_660:
    printf("\n");
    /* BASIC: 670 PRINT */
line_670:
    printf("\n");
    /* BASIC: 680 GOTO 120 */
line_680:
    goto line_120;
    /* BASIC: 999 END */
line_999:
    exit(0);

    return 0;
}
