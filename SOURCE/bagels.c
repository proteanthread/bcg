/*
 * Transpiled from bagels.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double BYE, GUESSES, J, NEW, DIGITS, FORGOT, JERSEY, THE, DIGIT, LEFT, A, HOPE, D, RIGHT, BUT, IT, WRONG, LIKE, T, FOLLOWS, HAD, IN, CORRECT, NUMBER, MORRISTOWN, MID, MIND, WAS, OH, PLAY, TRY, GUESS, WHAT, THREE, I, WELL, THINKING, AM, HAS, FUN, Y, POINT, K, OF, Z, S, SAME, WILL, CREATIVE, MY, YOU, AS, NO, WOULD, ONE, PICO, GOT, GUESSING, POSITION, B, CLUES, C, BAGELS, TELL, TWO, COMPUTING, GIVE, FERMI, BUFF, AGAIN, THAT, YES, O, N, HAVE, TWNETY, RULES;
    double A1[1000] = {0}; /* Static array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 5 PRINT TAB(33);"BAGELS" */
line_5:
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "BAGELS"); printf("\n");
    /* BASIC: 10 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY":PRINT:PRINT */
line_10:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 15 REM *** BAGLES NUMBER GUESSING GAME */
line_15:
    // REM *** BAGLES NUMBER GUESSING GAME
    /* BASIC: 20 REM *** ORIGINAL SOURCE UNKNOWN BUT SUSPECTED TO BE */
line_20:
    // REM *** ORIGINAL SOURCE UNKNOWN BUT SUSPECTED TO BE
    /* BASIC: 25 REM *** LAWRENCE HALL OF SCIENCE, U.C. BERKELY */
line_25:
    // REM *** LAWRENCE HALL OF SCIENCE, U.C. BERKELY
    /* BASIC: 30 DIM A1(6),A(3),B(3) */
line_30:
    /* DIM A1(6),A(3),B(3) (handled statically) */
    /* BASIC: 40 Y=0:T=255 */
line_40:
    Y = 0;
    T = 255;
    /* BASIC: 50 PRINT:PRINT:PRINT */
line_50:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 70 INPUT "WOULD YOU LIKE THE RULES (YES OR NO)";A$ */
line_70:
    printf("%s", "WOULD YOU LIKE THE RULES (YES OR NO)"); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    /* BASIC: 90 IF LEFT$(A$,1)="N" THEN 150 */
line_90:
    if (LEFT$(A$,1)=="N") goto line_150;
    /* BASIC: 100 PRINT:PRINT "I AM THINKING OF A THREE-DIGIT NUMBER.  TRY TO GUESS" */
line_100:
    printf("\n");
    printf("%s", "I AM THINKING OF A THREE-DIGIT NUMBER.  TRY TO GUESS"); printf("\n");
    /* BASIC: 110 PRINT "MY NUMBER AND I WILL GIVE YOU CLUES AS FOLLOWS:" */
line_110:
    printf("%s", "MY NUMBER AND I WILL GIVE YOU CLUES AS FOLLOWS:"); printf("\n");
    /* BASIC: 120 PRINT "   PICO   - ONE DIGIT CORRECT BUT IN THE WRONG POSITION" */
line_120:
    printf("%s", "   PICO   - ONE DIGIT CORRECT BUT IN THE WRONG POSITION"); printf("\n");
    /* BASIC: 130 PRINT "   FERMI  - ONE DIGIT CORRECT AND IN THE RIGHT POSITION" */
line_130:
    printf("%s", "   FERMI  - ONE DIGIT CORRECT AND IN THE RIGHT POSITION"); printf("\n");
    /* BASIC: 140 PRINT "   BAGELS - NO DIGITS CORRECT" */
line_140:
    printf("%s", "   BAGELS - NO DIGITS CORRECT"); printf("\n");
    /* BASIC: 150 FOR I=1 TO 3 */
line_150:
    I = 1; for_loop_I: if ((1 >= 0 && I > 3) || (1 < 0 && I < 3)) goto end_for_I;
    /* BASIC: 160 A(I)=INT(10*RND(1)) */
line_160:
    A(I) = floor(10*((double)rand() / (double)RAND_MAX));
    /* BASIC: 165 IF I-1=0 THEN 200 */
line_165:
    if (I-1==0) goto line_200;
    /* BASIC: 170 FOR J=1 TO I-1 */
line_170:
    J = 1; for_loop_J: if ((1 >= 0 && J > I-1) || (1 < 0 && J < I-1)) goto end_for_J;
    /* BASIC: 180 IF A(I)=A(J) THEN 160 */
line_180:
    if (A(I)==A(J)) goto line_160;
    /* BASIC: 190 NEXT J */
line_190:
    J += 1; goto for_loop_J; end_for_J:;
    /* BASIC: 200 NEXT I */
line_200:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 210 PRINT:PRINT "O.K.  I HAVE A NUMBER IN MIND." */
line_210:
    printf("\n");
    printf("%s", "O.K.  I HAVE A NUMBER IN MIND."); printf("\n");
    /* BASIC: 220 FOR I=1 TO 20 */
line_220:
    I = 1; for_loop_I: if ((1 >= 0 && I > 20) || (1 < 0 && I < 20)) goto end_for_I;
    /* BASIC: 230 PRINT "GUESS #";I, */
line_230:
    printf("%s", "GUESS #"); printf("%g ", (double)(I)); printf("\t");
    /* BASIC: 240 INPUT A$ */
line_240:
    printf("? "); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    /* BASIC: 245 IF LEN(A$)<>3 THEN 630 */
line_245:
    if (LEN(A$)!=3) goto line_630;
    /* BASIC: 250 FOR Z=1 TO 3:A1(Z)=ASC(MID$(A$,Z,1)):NEXT Z */
line_250:
    Z = 1; for_loop_Z: if ((1 >= 0 && Z > 3) || (1 < 0 && Z < 3)) goto end_for_Z;
    A1(Z) = ASC(MID$(A$,Z,1));
    Z += 1; goto for_loop_Z; end_for_Z:;
    /* BASIC: 260 FOR J=1 TO 3 */
line_260:
    J = 1; for_loop_J: if ((1 >= 0 && J > 3) || (1 < 0 && J < 3)) goto end_for_J;
    /* BASIC: 270 IF A1(J)<48 THEN 300 */
line_270:
    if (A1(J)<48) goto line_300;
    /* BASIC: 280 IF A1(J)>57 THEN 300 */
line_280:
    if (A1(J)>57) goto line_300;
    /* BASIC: 285 B(J)=A1(J)-48 */
line_285:
    B(J) = A1(J)-48;
    /* BASIC: 290 NEXT J */
line_290:
    J += 1; goto for_loop_J; end_for_J:;
    /* BASIC: 295 GOTO 320 */
line_295:
    goto line_320;
    /* BASIC: 300 PRINT "WHAT?" */
line_300:
    printf("%s", "WHAT?"); printf("\n");
    /* BASIC: 310 GOTO 230 */
line_310:
    goto line_230;
    /* BASIC: 320 IF B(1)=B(2) THEN 650 */
line_320:
    if (B(1)==B(2)) goto line_650;
    /* BASIC: 330 IF B(2)=B(3) THEN 650 */
line_330:
    if (B(2)==B(3)) goto line_650;
    /* BASIC: 340 IF B(3)=B(1) THEN 650 */
line_340:
    if (B(3)==B(1)) goto line_650;
    /* BASIC: 350 C=0:D=0 */
line_350:
    C = 0;
    D = 0;
    /* BASIC: 360 FOR J=1 TO 2 */
line_360:
    J = 1; for_loop_J: if ((1 >= 0 && J > 2) || (1 < 0 && J < 2)) goto end_for_J;
    /* BASIC: 370 IF A(J)<>B(J+1) THEN 390 */
line_370:
    if (A(J)!=B(J+1)) goto line_390;
    /* BASIC: 380 C=C+1 */
line_380:
    C = C+1;
    /* BASIC: 390 IF A(J+1)<>B(J) THEN 410 */
line_390:
    if (A(J+1)!=B(J)) goto line_410;
    /* BASIC: 400 C=C+1 */
line_400:
    C = C+1;
    /* BASIC: 410 NEXT J */
line_410:
    J += 1; goto for_loop_J; end_for_J:;
    /* BASIC: 420 IF A(1)<>B(3) THEN 440 */
line_420:
    if (A(1)!=B(3)) goto line_440;
    /* BASIC: 430 C=C+1 */
line_430:
    C = C+1;
    /* BASIC: 440 IF A(3)<>B(1) THEN 460 */
line_440:
    if (A(3)!=B(1)) goto line_460;
    /* BASIC: 450 C=C+1 */
line_450:
    C = C+1;
    /* BASIC: 460 FOR J=1 TO 3 */
line_460:
    J = 1; for_loop_J: if ((1 >= 0 && J > 3) || (1 < 0 && J < 3)) goto end_for_J;
    /* BASIC: 470 IF A(J)<>B(J) THEN 490 */
line_470:
    if (A(J)!=B(J)) goto line_490;
    /* BASIC: 480 D=D+1 */
line_480:
    D = D+1;
    /* BASIC: 490 NEXT J */
line_490:
    J += 1; goto for_loop_J; end_for_J:;
    /* BASIC: 500 IF D=3 THEN 680 */
line_500:
    if (D==3) goto line_680;
    /* BASIC: 505 IF C=0 THEN 545 */
line_505:
    if (C==0) goto line_545;
    /* BASIC: 520 FOR J=1 TO C */
line_520:
    J = 1; for_loop_J: if ((1 >= 0 && J > C) || (1 < 0 && J < C)) goto end_for_J;
    /* BASIC: 530 PRINT "PICO "; */
line_530:
    printf("%s", "PICO ");
    /* BASIC: 540 NEXT J */
line_540:
    J += 1; goto for_loop_J; end_for_J:;
    /* BASIC: 545 IF D=0 THEN 580 */
line_545:
    if (D==0) goto line_580;
    /* BASIC: 550 FOR J=1 TO D */
line_550:
    J = 1; for_loop_J: if ((1 >= 0 && J > D) || (1 < 0 && J < D)) goto end_for_J;
    /* BASIC: 560 PRINT "FERMI "; */
line_560:
    printf("%s", "FERMI ");
    /* BASIC: 570 NEXT J */
line_570:
    J += 1; goto for_loop_J; end_for_J:;
    /* BASIC: 580 IF C+D<>0 THEN 600 */
line_580:
    if (C+D!=0) goto line_600;
    /* BASIC: 590 PRINT "BAGELS"; */
line_590:
    printf("%s", "BAGELS");
    /* BASIC: 600 PRINT */
line_600:
    printf("\n");
    /* BASIC: 605 NEXT I */
line_605:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 610 PRINT "OH WELL." */
line_610:
    printf("%s", "OH WELL."); printf("\n");
    /* BASIC: 615 PRINT "THAT'S TWNETY GUESSES.  MY NUMBER WAS";100*A(1)+10*A(2)+A(3) */
line_615:
    printf("%s", "THAT'S TWNETY GUESSES.  MY NUMBER WAS"); printf("%g ", (double)(100*A(1)+10*A(2)+A(3))); printf("\n");
    /* BASIC: 620 GOTO 700 */
line_620:
    goto line_700;
    /* BASIC: 630 PRINT "TRY GUESSING A THREE-DIGIT NUMBER.":GOTO 230 */
line_630:
    printf("%s", "TRY GUESSING A THREE-DIGIT NUMBER."); printf("\n");
    goto line_230;
    /* BASIC: 650 PRINT "OH, I FORGOT TO TELL YOU THAT THE NUMBER I HAVE IN MIND" */
line_650:
    printf("%s", "OH, I FORGOT TO TELL YOU THAT THE NUMBER I HAVE IN MIND"); printf("\n");
    /* BASIC: 660 PRINT "HAS NO TWO DIGITS THE SAME.":GOTO 230 */
line_660:
    printf("%s", "HAS NO TWO DIGITS THE SAME."); printf("\n");
    goto line_230;
    /* BASIC: 680 PRINT "YOU GOT IT!!!":PRINT */
line_680:
    printf("%s", "YOU GOT IT!!!"); printf("\n");
    printf("\n");
    /* BASIC: 690 Y=Y+1 */
line_690:
    Y = Y+1;
    /* BASIC: 700 INPUT "PLAY AGAIN (YES OR NO)";A$ */
line_700:
    printf("%s", "PLAY AGAIN (YES OR NO)"); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    /* BASIC: 720 IF LEFT$(A$,1)="YES" THEN 150 */
line_720:
    if (LEFT$(A$,1)=="YES") goto line_150;
    /* BASIC: 730 IF Y=0 THEN 750 */
line_730:
    if (Y==0) goto line_750;
    /* BASIC: 740 PRINT:PRINT "A";Y;"POINT BAGELS BUFF!!" */
line_740:
    printf("\n");
    printf("%s", "A"); printf("%g ", (double)(Y)); printf("%s", "POINT BAGELS BUFF!!"); printf("\n");
    /* BASIC: 750 PRINT "HOPE YOU HAD FUN.  BYE." */
line_750:
    printf("%s", "HOPE YOU HAD FUN.  BYE."); printf("\n");
    /* BASIC: 999 END */
line_999:
    exit(0);

    return 0;
}
