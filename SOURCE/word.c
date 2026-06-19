/*
 * Transpiled from word.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double EXACT, GUESSES, READ, WORD, P, GAME, CHR, J, NEW, TYPE, CLUMP, JERSEY, THE, A, STARTING, D, UP, IT, KNOW, WERE, TRAIN, MORRISTOWN, MID, DATA, LETTERS, MUST, START, DOPEY, GUESSED, LUCK, PLAY, GUESS, WANT, GRASS, RESTORE, MIGHT, YOUR, I, TOOK, CANDY, SMOKE, THINKING, AM, THERE, FROM, M, IS, OF, WILL, DINKY, CREATIVE, YOU, WATER, WOULD, G, GOOD, ARE, CLUES, C, SECRET, COMMON, COMPUTING, HELP, GET, CHAMP, GIVE, MATCHES, L, LETTER, AGAIN, FIRST, YES, FIVE, N, HAVE, Q;
    double S[1000] = {0}; /* Static array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 2 PRINT TAB(33);"WORD" */
line_2:
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "WORD"); printf("\n");
    /* BASIC: 3 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_3:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 4 PRINT: PRINT: PRINT */
line_4:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 5 DIM S(7),A(7),L(7),D(7),P(7) */
line_5:
    /* DIM S(7),A(7),L(7),D(7),P(7) (handled statically) */
    /* BASIC: 10 PRINT "I AM THINKING OF A WORD -- YOU GUESS IT.  I WILL GIVE YOU" */
line_10:
    printf("%s", "I AM THINKING OF A WORD -- YOU GUESS IT.  I WILL GIVE YOU"); printf("\n");
    /* BASIC: 15 PRINT "CLUES TO HELP YOU GET IT.  GOOD LUCK!!": PRINT: PRINT */
line_15:
    printf("%s", "CLUES TO HELP YOU GET IT.  GOOD LUCK!!"); printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 20 REM */
line_20:
    // REM
    /* BASIC: 30 PRINT: PRINT: PRINT "YOU ARE STARTING A NEW GAME..." */
line_30:
    printf("\n");
    printf("\n");
    printf("%s", "YOU ARE STARTING A NEW GAME..."); printf("\n");
    /* BASIC: 35 RESTORE */
line_35:
    /* UNTRANSLATED: RESTORE */
    /* BASIC: 40 READ N */
line_40:
    /* UNTRANSLATED: READ N */
    /* BASIC: 50 C=INT(RND(1)*N+1) */
line_50:
    C = floor(((double)rand() / (double)RAND_MAX)*N+1);
    /* BASIC: 60 FOR I=1 TO C */
line_60:
    I = 1; for_loop_I: if ((1 >= 0 && I > C) || (1 < 0 && I < C)) goto end_for_I;
    /* BASIC: 70 READ S$ */
line_70:
    /* UNTRANSLATED: READ S$ */
    /* BASIC: 80 NEXT I */
line_80:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 90 G=0 */
line_90:
    G = 0;
    /* BASIC: 95 S(0)=LEN(S$) */
line_95:
    S(0) = LEN(S$);
    /* BASIC: 100 FOR I=1 TO LEN(S$): S(I)=ASC(MID$(S$,I,1)): NEXT I */
line_100:
    I = 1; for_loop_I: if ((1 >= 0 && I > LEN(S$)) || (1 < 0 && I < LEN(S$))) goto end_for_I;
    S(I) = ASC(MID$(S$,I,1));
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 110 FOR I=1 TO 5 */
line_110:
    I = 1; for_loop_I: if ((1 >= 0 && I > 5) || (1 < 0 && I < 5)) goto end_for_I;
    /* BASIC: 120 A(I)=45 */
line_120:
    A(I) = 45;
    /* BASIC: 130 NEXT I */
line_130:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 140 FOR J=1 TO 5 */
line_140:
    J = 1; for_loop_J: if ((1 >= 0 && J > 5) || (1 < 0 && J < 5)) goto end_for_J;
    /* BASIC: 144 P(J)=0 */
line_144:
    P(J) = 0;
    /* BASIC: 146 NEXT J */
line_146:
    J += 1; goto for_loop_J; end_for_J:;
    /* BASIC: 150 PRINT "GUESS A FIVE LETTER WORD"; */
line_150:
    printf("%s", "GUESS A FIVE LETTER WORD");
    /* BASIC: 160 INPUT L$ */
line_160:
    printf("? "); fgets(L_str, sizeof(L_str), stdin); L_str[strcspn(L_str, "\n")] = 0;
    /* BASIC: 170 G=G+1 */
line_170:
    G = G+1;
    /* BASIC: 172 IF S$=G$ THEN 500 */
line_172:
    if (S$==G$) goto line_500;
    /* BASIC: 173 FOR I=1 TO 7: P(I)=0: NEXT I */
line_173:
    I = 1; for_loop_I: if ((1 >= 0 && I > 7) || (1 < 0 && I < 7)) goto end_for_I;
    P(I) = 0;
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 175 L(0)=LEN(L$) */
line_175:
    L(0) = LEN(L$);
    /* BASIC: 180 FOR I=1 TO LEN(L$): L(I)=ASC(MID$(L$,I,1)): NEXT I */
line_180:
    I = 1; for_loop_I: if ((1 >= 0 && I > LEN(L$)) || (1 < 0 && I < LEN(L$))) goto end_for_I;
    L(I) = ASC(MID$(L$,I,1));
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 190 IF L(1)=63 THEN 300 */
line_190:
    if (L(1)==63) goto line_300;
    /* BASIC: 200 IF L(0)<>5 THEN 400 */
line_200:
    if (L(0)!=5) goto line_400;
    /* BASIC: 205 M=0: Q=1 */
line_205:
    M = 0;
    Q = 1;
    /* BASIC: 210 FOR I=1 TO 5 */
line_210:
    I = 1; for_loop_I: if ((1 >= 0 && I > 5) || (1 < 0 && I < 5)) goto end_for_I;
    /* BASIC: 220 FOR J=1 TO 5 */
line_220:
    J = 1; for_loop_J: if ((1 >= 0 && J > 5) || (1 < 0 && J < 5)) goto end_for_J;
    /* BASIC: 230 IF S(I)<>L(J) THEN 260 */
line_230:
    if (S(I)!=L(J)) goto line_260;
    /* BASIC: 231 P(Q)=L(J) */
line_231:
    P(Q) = L(J);
    /* BASIC: 232 Q=Q+1 */
line_232:
    Q = Q+1;
    /* BASIC: 233 IF I<>J THEN 250 */
line_233:
    if (I!=J) goto line_250;
    /* BASIC: 240 A(J)=L(J) */
line_240:
    A(J) = L(J);
    /* BASIC: 250 M=M+1 */
line_250:
    M = M+1;
    /* BASIC: 260 NEXT J */
line_260:
    J += 1; goto for_loop_J; end_for_J:;
    /* BASIC: 265 NEXT I */
line_265:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 270 A(0)=5 */
line_270:
    A(0) = 5;
    /* BASIC: 272 P(0)=M */
line_272:
    P(0) = M;
    /* BASIC: 275 A$="": FOR I=1 TO A(0): A$=A$+CHR$(A(I)): NEXT I */
line_275:
    strncpy(A_str, """", sizeof(A_str)); /* String assign approx */
    I = 1; for_loop_I: if ((1 >= 0 && I > A(0)) || (1 < 0 && I < A(0))) goto end_for_I;
    strncpy(A_str, "A$+CHR$(A(I))", sizeof(A_str)); /* String assign approx */
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 277 P$="": FOR I=1 TO P(0): P$=P$+CHR$(P(I)): NEXT I */
line_277:
    strncpy(P_str, """", sizeof(P_str)); /* String assign approx */
    I = 1; for_loop_I: if ((1 >= 0 && I > P(0)) || (1 < 0 && I < P(0))) goto end_for_I;
    strncpy(P_str, "P$+CHR$(P(I))", sizeof(P_str)); /* String assign approx */
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 280 PRINT "THERE WERE";M;"MATCHES AND THE COMMON LETTERS WERE...";P$ */
line_280:
    printf("%s", "THERE WERE"); printf("%g ", (double)(M)); printf("%s", "MATCHES AND THE COMMON LETTERS WERE..."); printf("%s", P_str); printf("\n");
    /* BASIC: 285 PRINT "FROM THE EXACT LETTER MATCHES, YOU KNOW................";A$ */
line_285:
    printf("%s", "FROM THE EXACT LETTER MATCHES, YOU KNOW................"); printf("%s", A_str); printf("\n");
    /* BASIC: 286 IF A$=S$ THEN 500 */
line_286:
    if (A$==S$) goto line_500;
    /* BASIC: 287 IF M>1 THEN 289 */
line_287:
    if (M>1) goto line_289;
    /* BASIC: 288 PRINT: PRINT "IF YOU GIVE UP, TYPE '?' FOR YOUR NEXT GUESS." */
line_288:
    printf("\n");
    printf("%s", "IF YOU GIVE UP, TYPE '?' FOR YOUR NEXT GUESS."); printf("\n");
    /* BASIC: 289 PRINT */
line_289:
    printf("\n");
    /* BASIC: 290 GOTO 150 */
line_290:
    goto line_150;
    /* BASIC: 300 S$="": FOR I=1 TO 7: S$=S$+CHR$(S(I)): NEXT I */
line_300:
    strncpy(S_str, """", sizeof(S_str)); /* String assign approx */
    I = 1; for_loop_I: if ((1 >= 0 && I > 7) || (1 < 0 && I < 7)) goto end_for_I;
    strncpy(S_str, "S$+CHR$(S(I))", sizeof(S_str)); /* String assign approx */
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 310 PRINT "THE SECRET WORD IS ";S$: PRINT */
line_310:
    printf("%s", "THE SECRET WORD IS "); printf("%s", S_str); printf("\n");
    printf("\n");
    /* BASIC: 320 GOTO 30 */
line_320:
    goto line_30;
    /* BASIC: 400 PRINT "YOU MUST GUESS A 5 LETTER WORD.  START AGAIN." */
line_400:
    printf("%s", "YOU MUST GUESS A 5 LETTER WORD.  START AGAIN."); printf("\n");
    /* BASIC: 410 PRINT: G=G-1: GOTO 150 */
line_410:
    printf("\n");
    G = G-1;
    goto line_150;
    /* BASIC: 500 PRINT "YOU HAVE GUESSED THE WORD.  IT TOOK";G;"GUESSES!": PRINT */
line_500:
    printf("%s", "YOU HAVE GUESSED THE WORD.  IT TOOK"); printf("%g ", (double)(G)); printf("%s", "GUESSES!"); printf("\n");
    printf("\n");
    /* BASIC: 510 INPUT "WANT TO PLAY AGAIN";Q$ */
line_510:
    printf("%s", "WANT TO PLAY AGAIN"); fgets(Q_str, sizeof(Q_str), stdin); Q_str[strcspn(Q_str, "\n")] = 0;
    /* BASIC: 520 IF Q$="YES" THEN 30 */
line_520:
    if (Q$=="YES") goto line_30;
    /* BASIC: 530 DATA 12,"DINKY","SMOKE","WATER","GRASS","TRAIN","MIGHT","FIRST" */
line_530:
    /* UNTRANSLATED: DATA 12,"DINKY","SMOKE","WATER","GRASS","TRAIN","MIGHT","FIRST" */
    /* BASIC: 540 DATA "CANDY","CHAMP","WOULD","CLUMP","DOPEY" */
line_540:
    /* UNTRANSLATED: DATA "CANDY","CHAMP","WOULD","CLUMP","DOPEY" */
    /* BASIC: 999 END */
line_999:
    exit(0);

    return 0;
}
