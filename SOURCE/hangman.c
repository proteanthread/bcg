/*
 * Transpiled from hangman.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double BYE, ISN, GUESSES, READ, NOW, P, WORD, J, NEW, HUNG, TYPE, BUDGET, ESCORT, SPIRIT, FIEND, RE, PHYTOTOXIC, JERSEY, THE, ON, PUT, LEFT, A, EXAMPLE, FLY, D, RIGHT, UP, DRAW, IT, WORK, WRONG, PROGRAM, QUAINT, MAHOGANY, DIFFERENT, T, ARM, IN, FAULT, HAND, FOUND, CRY, SELF, MORRISTOWN, MID, FOOT, DATA, PICKAX, BODY, LETTERS, QUININE, TALK, GUESSED, WAS, PARASYMPATHOMIMETIC, TIME, SIN, KANGAROO, TRY, GUESS, ERROR, HERE, WHAT, U, THING, MAGISTRATE, WANT, LET, RESTORE, ALL, YOUR, I, TOOK, FUN, FROM, Y, M, LEG, BEEN, W, IS, SCIENTIST, PIZZA, SORRY, LOUDSPEAKER, S, CREATIVE, WORDS, EACH, YOU, LOSE, X, ERRONEOUSLY, MATRIMONIAL, NO, USED, MISSED, WITH, THIGMOTROPISM, ONE, ANOTHER, WE, REPLICA, OTHER, RUN, KIDNEY, G, T1, ELBOW, AN, ARE, B, C, FEIGN, HEAD, SLEEPER, QUIESCENT, COMPUTING, TENSION, TRIANGLE, HANGMAN, GUM, UGLY, DIRTY, BEFORE, L, LETTER, DID, SERGEANT, AGAIN, FIRST, R, THAT, YES, DO, LUG, MOUSTACHE, DANGEROUS, MAIDEN, N, THIS, Q, SEQUENCE;
    char P_str[1000][256] = {0}; /* Static string array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 10 PRINT TAB(32);"HANGMAN" */
line_10:
    { int _t; for(_t=0; _t<32; _t++) printf(" "); } printf("%s", "HANGMAN"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 25 PRINT:PRINT:PRINT */
line_25:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 30 DIM P$(12,12),L$(20),D$(20),N$(26),U(50) */
line_30:
    /* DIM P$(12,12),L$(20),D$(20),N$(26),U(50) (handled statically) */
    /* BASIC: 40 C=1: N=50 */
line_40:
    C = 1;
    N = 50;
    /* BASIC: 50 FOR I=1 TO 20: D$(I)="-": NEXT I: M=0 */
line_50:
    I = 1; for_loop_I: if ((1 >= 0 && I > 20) || (1 < 0 && I < 20)) goto end_for_I;
    D$(I) = "-";
    I += 1; goto for_loop_I; end_for_I:;
    M = 0;
    /* BASIC: 60 FOR I=1 TO 26: N$(I)="": NEXT I */
line_60:
    I = 1; for_loop_I: if ((1 >= 0 && I > 26) || (1 < 0 && I < 26)) goto end_for_I;
    N$(I) = "";
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 70 FOR I=1 TO 12: FOR J=1 TO 12: P$(I,J)=" ": NEXT J: NEXT I */
line_70:
    I = 1; for_loop_I: if ((1 >= 0 && I > 12) || (1 < 0 && I < 12)) goto end_for_I;
    J = 1; for_loop_J: if ((1 >= 0 && J > 12) || (1 < 0 && J < 12)) goto end_for_J;
    P$(I,J) = " ";
    J += 1; goto for_loop_J; end_for_J:;
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 80 FOR I=1 TO 12: P$(I,1)="X": NEXT I */
line_80:
    I = 1; for_loop_I: if ((1 >= 0 && I > 12) || (1 < 0 && I < 12)) goto end_for_I;
    P$(I,1) = "X";
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 90 FOR I=1 TO 7: P$(1,I)="X": NEXT: P$(2,7)="X" */
line_90:
    I = 1; for_loop_I: if ((1 >= 0 && I > 7) || (1 < 0 && I < 7)) goto end_for_I;
    P$(1,I) = "X";
    /* TODO: NEXT (unmatched) */
    P$(2,7) = "X";
    /* BASIC: 95 IF C<N THEN 100 */
line_95:
    if (C<N) goto line_100;
    /* BASIC: 97 PRINT "YOU DID ALL THE WORDS!!": STOP */
line_97:
    printf("%s", "YOU DID ALL THE WORDS!!"); printf("\n");
    exit(0);
    /* BASIC: 100 Q=INT(N*RND(1))+1 */
line_100:
    Q = floor(N*((double)rand() / (double)RAND_MAX))+1;
    /* BASIC: 110 IF U(Q)=1 THEN 100 */
line_110:
    if (U(Q)==1) goto line_100;
    /* BASIC: 115 U(Q)=1: C=C+1: RESTORE: T1=0 */
line_115:
    U(Q) = 1;
    C = C+1;
    /* UNTRANSLATED: RESTORE */
    T1 = 0;
    /* BASIC: 150 FOR I=1 TO Q: READ A$: NEXT I */
line_150:
    I = 1; for_loop_I: if ((1 >= 0 && I > Q) || (1 < 0 && I < Q)) goto end_for_I;
    /* UNTRANSLATED: READ A$ */
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 160 L=LEN(A$): FOR I=1 TO LEN(A$): L$(I)=MID$(A$,I,1): NEXT I */
line_160:
    L = LEN(A$);
    I = 1; for_loop_I: if ((1 >= 0 && I > LEN(A$)) || (1 < 0 && I < LEN(A$))) goto end_for_I;
    L$(I) = MID$(A$,I,1);
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 170 PRINT "HERE ARE THE LETTERS YOU USED:" */
line_170:
    printf("%s", "HERE ARE THE LETTERS YOU USED:"); printf("\n");
    /* BASIC: 180 FOR I=1 TO 26: PRINT N$(I);: IF N$(I+1)="" THEN 200 */
line_180:
    I = 1; for_loop_I: if ((1 >= 0 && I > 26) || (1 < 0 && I < 26)) goto end_for_I;
    printf("%g ", (double)(N$(I)));
    if (N$(I+1)=="") goto line_200;
    /* BASIC: 190 PRINT ",";: NEXT I */
line_190:
    printf("%s", ",");
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 200 PRINT: PRINT: FOR I=1 TO L: PRINT D$(I);: NEXT I: PRINT: PRINT */
line_200:
    printf("\n");
    printf("\n");
    I = 1; for_loop_I: if ((1 >= 0 && I > L) || (1 < 0 && I < L)) goto end_for_I;
    printf("%g ", (double)(D$(I)));
    I += 1; goto for_loop_I; end_for_I:;
    printf("\n");
    printf("\n");
    /* BASIC: 210 INPUT "WHAT IS YOUR GUESS";G$: R=0 */
line_210:
    printf("%s", "WHAT IS YOUR GUESS"); fgets(G_str, sizeof(G_str), stdin); G_str[strcspn(G_str, "\n")] = 0;
    R = 0;
    /* BASIC: 220 FOR I=1 TO 26: IF N$(I)="" THEN 250 */
line_220:
    I = 1; for_loop_I: if ((1 >= 0 && I > 26) || (1 < 0 && I < 26)) goto end_for_I;
    if (N$(I)=="") goto line_250;
    /* BASIC: 230 IF G$=N$(I) THEN PRINT "YOU GUESSED THAT LETTER BEFORE!": GOTO 170 */
line_230:
    if (G$==N$(I)) { printf("%s", "YOU GUESSED THAT LETTER BEFORE!"); printf("\n"); }
    goto line_170;
    /* BASIC: 240 NEXT I: PRINT "PROGRAM ERROR.  RUN AGAIN.": STOP */
line_240:
    I += 1; goto for_loop_I; end_for_I:;
    printf("%s", "PROGRAM ERROR.  RUN AGAIN."); printf("\n");
    exit(0);
    /* BASIC: 250 N$(I)=G$: T1=T1+1 */
line_250:
    N$(I) = G$;
    T1 = T1+1;
    /* BASIC: 260 FOR I=1 TO L: IF L$(I)=G$ THEN 280 */
line_260:
    I = 1; for_loop_I: if ((1 >= 0 && I > L) || (1 < 0 && I < L)) goto end_for_I;
    if (L$(I)==G$) goto line_280;
    /* BASIC: 270 NEXT I: IF R=0 THEN 290 */
line_270:
    I += 1; goto for_loop_I; end_for_I:;
    if (R==0) goto line_290;
    /* BASIC: 275 GOTO 300 */
line_275:
    goto line_300;
    /* BASIC: 280 D$(I)=G$: R=R+1: GOTO 270 */
line_280:
    D$(I) = G$;
    R = R+1;
    goto line_270;
    /* BASIC: 290 M=M+1: GOTO 400 */
line_290:
    M = M+1;
    goto line_400;
    /* BASIC: 300 FOR I=1 TO L: IF D$(I)="-" THEN 320 */
line_300:
    I = 1; for_loop_I: if ((1 >= 0 && I > L) || (1 < 0 && I < L)) goto end_for_I;
    if (D$(I)=="-") goto line_320;
    /* BASIC: 310 NEXT I: GOTO 390 */
line_310:
    I += 1; goto for_loop_I; end_for_I:;
    goto line_390;
    /* BASIC: 320 PRINT: FOR I=1 TO L: PRINT D$(I);: NEXT I: PRINT: PRINT */
line_320:
    printf("\n");
    I = 1; for_loop_I: if ((1 >= 0 && I > L) || (1 < 0 && I < L)) goto end_for_I;
    printf("%g ", (double)(D$(I)));
    I += 1; goto for_loop_I; end_for_I:;
    printf("\n");
    printf("\n");
    /* BASIC: 330 INPUT "WHAT IS YOUR GUESS FOR THE WORD";B$ */
line_330:
    printf("%s", "WHAT IS YOUR GUESS FOR THE WORD"); fgets(B_str, sizeof(B_str), stdin); B_str[strcspn(B_str, "\n")] = 0;
    /* BASIC: 340 IF A$=B$ THEN 360 */
line_340:
    if (A$==B$) goto line_360;
    /* BASIC: 350 PRINT "WRONG.  TRY ANOTHER LETTER.": PRINT: GOTO 170 */
line_350:
    printf("%s", "WRONG.  TRY ANOTHER LETTER."); printf("\n");
    printf("\n");
    goto line_170;
    /* BASIC: 360 PRINT "RIGHT!!  IT TOOK YOU";T1;"GUESSES!" */
line_360:
    printf("%s", "RIGHT!!  IT TOOK YOU"); printf("%g ", (double)(T1)); printf("%s", "GUESSES!"); printf("\n");
    /* BASIC: 370 INPUT "WANT ANOTHER WORD";W$: IF W$="YES" THEN 50 */
line_370:
    printf("%s", "WANT ANOTHER WORD"); fgets(W_str, sizeof(W_str), stdin); W_str[strcspn(W_str, "\n")] = 0;
    if (W$=="YES") goto line_50;
    /* BASIC: 380 PRINT: PRINT "IT'S BEEN FUN!  BYE FOR NOW.": GOTO 999 */
line_380:
    printf("\n");
    printf("%s", "IT'S BEEN FUN!  BYE FOR NOW."); printf("\n");
    goto line_999;
    /* BASIC: 390 PRINT "YOU FOUND THE WORD!": GOTO 370 */
line_390:
    printf("%s", "YOU FOUND THE WORD!"); printf("\n");
    goto line_370;
    /* BASIC: 400 PRINT: PRINT: PRINT"SORRY, THAT LETTER ISN'T IN THE WORD." */
line_400:
    printf("\n");
    printf("\n");
    printf("%s", "SORRY, THAT LETTER ISN'T IN THE WORD."); printf("\n");
    /* BASIC: 410 ON M GOTO 415,420,425,430,435,440,445,450,455,460 */
line_410:
    /* UNTRANSLATED: ON M GOTO 415,420,425,430,435,440,445,450,455,460 */
    /* BASIC: 415 PRINT "FIRST, WE DRAW A HEAD": GOTO 470 */
line_415:
    printf("%s", "FIRST, WE DRAW A HEAD"); printf("\n");
    goto line_470;
    /* BASIC: 420 PRINT "NOW WE DRAW A BODY.": GOTO 470 */
line_420:
    printf("%s", "NOW WE DRAW A BODY."); printf("\n");
    goto line_470;
    /* BASIC: 425 PRINT "NEXT WE DRAW AN ARM.": GOTO 470 */
line_425:
    printf("%s", "NEXT WE DRAW AN ARM."); printf("\n");
    goto line_470;
    /* BASIC: 430 PRINT "THIS TIME IT'S THE OTHER ARM.": GOTO 470 */
line_430:
    printf("%s", "THIS TIME IT'S THE OTHER ARM."); printf("\n");
    goto line_470;
    /* BASIC: 435 PRINT "NOW, LET'S DRAW THE RIGHT LEG.": GOTO 470 */
line_435:
    printf("%s", "NOW, LET'S DRAW THE RIGHT LEG."); printf("\n");
    goto line_470;
    /* BASIC: 440 PRINT "THIS TIME WE DRAW THE LEFT LEG.": GOTO 470 */
line_440:
    printf("%s", "THIS TIME WE DRAW THE LEFT LEG."); printf("\n");
    goto line_470;
    /* BASIC: 445 PRINT "NOW WE PUT UP A HAND.": GOTO 470 */
line_445:
    printf("%s", "NOW WE PUT UP A HAND."); printf("\n");
    goto line_470;
    /* BASIC: 450 PRINT "NEXT THE OTHER HAND.": GOTO 470 */
line_450:
    printf("%s", "NEXT THE OTHER HAND."); printf("\n");
    goto line_470;
    /* BASIC: 455 PRINT "NOW WE DRAW ONE FOOT": GOTO 470 */
line_455:
    printf("%s", "NOW WE DRAW ONE FOOT"); printf("\n");
    goto line_470;
    /* BASIC: 460 PRINT "HERE'S THE OTHER FOOT -- YOU'RE HUNG!!" */
line_460:
    printf("%s", "HERE'S THE OTHER FOOT -- YOU'RE HUNG!!"); printf("\n");
    /* BASIC: 470 ON M GOTO 480,490,500,510,520,530,540,550,560,570 */
line_470:
    /* UNTRANSLATED: ON M GOTO 480,490,500,510,520,530,540,550,560,570 */
    /* BASIC: 480 P$(3,6)="-": P$(3,7)="-": P$(3,8)="-": P$(4,5)="(": P$(4,6)="." */
line_480:
    P$(3,6) = "-";
    P$(3,7) = "-";
    P$(3,8) = "-";
    P$(4,5) = "(";
    P$(4,6) = ".";
    /* BASIC: 481 P$(4,8)=".":P$(4,9)=")":P$(5,6)="-":P$(5,7)="-":P$(5,8)="-":GOTO 580 */
line_481:
    P$(4,8) = ".";
    P$(4,9) = ")";
    P$(5,6) = "-";
    P$(5,7) = "-";
    P$(5,8) = "-";
    goto line_580;
    /* BASIC: 490 FOR I=6 TO 9: P$(I,7)="X": NEXT I: GOTO 580 */
line_490:
    I = 6; for_loop_I: if ((1 >= 0 && I > 9) || (1 < 0 && I < 9)) goto end_for_I;
    P$(I,7) = "X";
    I += 1; goto for_loop_I; end_for_I:;
    goto line_580;
    /* BASIC: 500 FOR I=4 TO 7: P$(I,I-1)="\": NEXT I: GOTO 580 */
line_500:
    I = 4; for_loop_I: if ((1 >= 0 && I > 7) || (1 < 0 && I < 7)) goto end_for_I;
    P$(I,I-1) = "\";
    I += 1; goto for_loop_I; end_for_I:;
    goto line_580;
    /* BASIC: 510 P$(4,11)="/": P$(5,10)="/": P$(6,9)="/": P$(7,8)="/": GOTO 580 */
line_510:
    P$(4,11) = "/";
    P$(5,10) = "/";
    P$(6,9) = "/";
    P$(7,8) = "/";
    goto line_580;
    /* BASIC: 520 P$(10,6)="/": P$(11,5)="/": GOTO 580 */
line_520:
    P$(10,6) = "/";
    P$(11,5) = "/";
    goto line_580;
    /* BASIC: 530 P$(10,8)="\": P$(11,9)="\": GOTO 580 */
line_530:
    P$(10,8) = "\";
    P$(11,9) = "\";
    goto line_580;
    /* BASIC: 540 P$(3,11)="\": GOTO 580 */
line_540:
    P$(3,11) = "\";
    goto line_580;
    /* BASIC: 550 P$(3,3)="/": GOTO 580 */
line_550:
    P$(3,3) = "/";
    goto line_580;
    /* BASIC: 560 P$(12,10)="\": P$(12,11)="-": GOTO 580 */
line_560:
    P$(12,10) = "\";
    P$(12,11) = "-";
    goto line_580;
    /* BASIC: 570 P$(12,3)="-": P$(12,4)="/" */
line_570:
    P$(12,3) = "-";
    P$(12,4) = "/";
    /* BASIC: 580 FOR I=1 TO 12: FOR J=1 TO 12: PRINT P$(I,J);: NEXT J */
line_580:
    I = 1; for_loop_I: if ((1 >= 0 && I > 12) || (1 < 0 && I < 12)) goto end_for_I;
    J = 1; for_loop_J: if ((1 >= 0 && J > 12) || (1 < 0 && J < 12)) goto end_for_J;
    printf("%g ", (double)(P$(I)); printf("\t"); printf("%g ", (double)(J)));
    J += 1; goto for_loop_J; end_for_J:;
    /* BASIC: 590 PRINT: NEXT I: PRINT: PRINT: IF M<>10 THEN 170 */
line_590:
    printf("\n");
    I += 1; goto for_loop_I; end_for_I:;
    printf("\n");
    printf("\n");
    if (M!=10) goto line_170;
    /* BASIC: 600 PRINT "SORRY, YOU LOSE.  THE WORD WAS ";A$ */
line_600:
    printf("%s", "SORRY, YOU LOSE.  THE WORD WAS "); printf("%s", A_str); printf("\n");
    /* BASIC: 610 PRINT "YOU MISSED THAT ONE.  DO YOU ";: GOTO 370 */
line_610:
    printf("%s", "YOU MISSED THAT ONE.  DO YOU ");
    goto line_370;
    /* BASIC: 620 INPUT "TYPE YES OR NO";Y$: IF LEFT$(Y$,1)="Y" THEN 50 */
line_620:
    printf("%s", "TYPE YES OR NO"); fgets(Y_str, sizeof(Y_str), stdin); Y_str[strcspn(Y_str, "\n")] = 0;
    if (LEFT$(Y$,1)=="Y") goto line_50;
    /* BASIC: 700 DATA "GUM","SIN","FOR","CRY","LUG","BYE","FLY" */
line_700:
    /* UNTRANSLATED: DATA "GUM","SIN","FOR","CRY","LUG","BYE","FLY" */
    /* BASIC: 710 DATA "UGLY","EACH","FROM","WORK","TALK","WITH","SELF" */
line_710:
    /* UNTRANSLATED: DATA "UGLY","EACH","FROM","WORK","TALK","WITH","SELF" */
    /* BASIC: 720 DATA "PIZZA","THING","FEIGN","FIEND","ELBOW","FAULT","DIRTY" */
line_720:
    /* UNTRANSLATED: DATA "PIZZA","THING","FEIGN","FIEND","ELBOW","FAULT","DIRTY" */
    /* BASIC: 730 DATA "BUDGET","SPIRIT","QUAINT","MAIDEN","ESCORT","PICKAX" */
line_730:
    /* UNTRANSLATED: DATA "BUDGET","SPIRIT","QUAINT","MAIDEN","ESCORT","PICKAX" */
    /* BASIC: 740 DATA "EXAMPLE","TENSION","QUININE","KIDNEY","REPLICA","SLEEPER" */
line_740:
    /* UNTRANSLATED: DATA "EXAMPLE","TENSION","QUININE","KIDNEY","REPLICA","SLEEPER" */
    /* BASIC: 750 DATA "TRIANGLE","KANGAROO","MAHOGANY","SERGEANT","SEQUENCE" */
line_750:
    /* UNTRANSLATED: DATA "TRIANGLE","KANGAROO","MAHOGANY","SERGEANT","SEQUENCE" */
    /* BASIC: 760 DATA "MOUSTACHE","DANGEROUS","SCIENTIST","DIFFERENT","QUIESCENT" */
line_760:
    /* UNTRANSLATED: DATA "MOUSTACHE","DANGEROUS","SCIENTIST","DIFFERENT","QUIESCENT" */
    /* BASIC: 770 DATA "MAGISTRATE","ERRONEOUSLY","LOUDSPEAKER","PHYTOTOXIC" */
line_770:
    /* UNTRANSLATED: DATA "MAGISTRATE","ERRONEOUSLY","LOUDSPEAKER","PHYTOTOXIC" */
    /* BASIC: 780 DATA "MATRIMONIAL","PARASYMPATHOMIMETIC","THIGMOTROPISM" */
line_780:
    /* UNTRANSLATED: DATA "MATRIMONIAL","PARASYMPATHOMIMETIC","THIGMOTROPISM" */
    /* BASIC: 990 PRINT "BYE NOW" */
line_990:
    printf("%s", "BYE NOW"); printf("\n");
    /* BASIC: 999 END */
line_999:
    exit(0);

    return 0;
}
