/*
 * Transpiled from name.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double NOTICED, OUT, BETTER, THANK, SHOULDN, ARE, M, MORRISTOWN, MID, ME, B, IS, MAKE, MISTAKE, J, NEW, LETTERS, NICE, OF, KNEW, SORRY, S, ORDER, COMPUTING, CREATIVE, JERSEY, JUST, MY, COMPUTER, THEM, BACKWARDS, DON, MEETING, YOU, PUT, GUESS, WAY, A, WHAT, L, D, NAME, BUT, DAY, IT, ENJOYED, AGREE, OOPS, REALLY, FIRST, LIKE, THAT, YES, T, LET, HELLO, LAST, YOUR, I, THIS, HAVE, IN, SMART, GOT;
    char B_str[1000][256] = {0}; /* Static string array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 1 PRINT TAB(34);"NAME" */
line_1:
    { int _t; for(_t=0; _t<34; _t++) printf(" "); } printf("%s", "NAME"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT: PRINT: PRINT */
line_3:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 5 DIM B$(40) */
line_5:
    /* DIM B$(40) (handled statically) */
    /* BASIC: 10 PRINT "HELLO.": PRINT "MY NAME IS CREATIVE COMPUTER." */
line_10:
    printf("%s", "HELLO."); printf("\n");
    printf("%s", "MY NAME IS CREATIVE COMPUTER."); printf("\n");
    /* BASIC: 20 PRINT "WHAT'S YOUR NAME (FIRST AND LAST";: INPUT A$: L=LEN(A$) */
line_20:
    printf("%s", "WHAT'S YOUR NAME (FIRST AND LAST");
    printf("? "); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    L = LEN(A$);
    /* BASIC: 30 PRINT: PRINT "THANK YOU, "; */
line_30:
    printf("\n");
    printf("%s", "THANK YOU, ");
    /* BASIC: 40 FOR I=1 TO L: B$(I)=MID$(A$,I,1): NEXT I */
line_40:
    I = 1; for_loop_I: if ((1 >= 0 && I > L) || (1 < 0 && I < L)) goto end_for_I;
    B$(I) = MID$(A$,I,1);
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 50 FOR I=L TO 1 STEP -1: PRINT B$(I);: NEXT I */
line_50:
    I = L; for_loop_I: if ((-1 >= 0 && I > 1) || (-1 < 0 && I < 1)) goto end_for_I;
    printf("%g ", (double)(B$(I)));
    I += -1; goto for_loop_I; end_for_I:;
    /* BASIC: 60 PRINT ".": PRINT "OOPS!  I GUESS I GOT IT BACKWARDS.  A SMART" */
line_60:
    printf("%s", "."); printf("\n");
    printf("%s", "OOPS!  I GUESS I GOT IT BACKWARDS.  A SMART"); printf("\n");
    /* BASIC: 70 PRINT "COMPUTER LIKE ME SHOULDN'T MAKE A MISTAKE LIKE THAT!": PRINT */
line_70:
    printf("%s", "COMPUTER LIKE ME SHOULDN'T MAKE A MISTAKE LIKE THAT!"); printf("\n");
    printf("\n");
    /* BASIC: 80 PRINT "BUT I JUST NOTICED YOUR LETTERS ARE OUT OF ORDER." */
line_80:
    printf("%s", "BUT I JUST NOTICED YOUR LETTERS ARE OUT OF ORDER."); printf("\n");
    /* BASIC: 90 PRINT "LET'S PUT THEM IN ORDER LIKE THIS: "; */
line_90:
    printf("%s", "LET'S PUT THEM IN ORDER LIKE THIS: ");
    /* BASIC: 100 FOR J=2 TO L: I=J-1: T$=B$(J) */
line_100:
    J = 2; for_loop_J: if ((1 >= 0 && J > L) || (1 < 0 && J < L)) goto end_for_J;
    I = J-1;
    strncpy(T_str, "B$(J)", sizeof(T_str)); /* String assign approx */
    /* BASIC: 110 IF T$>B$(I) THEN 130 */
line_110:
    if (T$>B$(I)) goto line_130;
    /* BASIC: 120 B$(I+1)=B$(I): I=I-1: IF I>0 THEN 110 */
line_120:
    B$(I+1) = B$(I);
    I = I-1;
    if (I>0) goto line_110;
    /* BASIC: 130 B$(I+1)=T$: NEXT J */
line_130:
    B$(I+1) = T$;
    J += 1; goto for_loop_J; end_for_J:;
    /* BASIC: 140 FOR I=1 TO L: PRINT B$(I);: NEXT I: PRINT: PRINT */
line_140:
    I = 1; for_loop_I: if ((1 >= 0 && I > L) || (1 < 0 && I < L)) goto end_for_I;
    printf("%g ", (double)(B$(I)));
    I += 1; goto for_loop_I; end_for_I:;
    printf("\n");
    printf("\n");
    /* BASIC: 150 PRINT "DON'T YOU LIKE THAT BETTER";: INPUT D$ */
line_150:
    printf("%s", "DON'T YOU LIKE THAT BETTER");
    printf("? "); fgets(D_str, sizeof(D_str), stdin); D_str[strcspn(D_str, "\n")] = 0;
    /* BASIC: 160 IF D$="YES" THEN 180 */
line_160:
    if (D$=="YES") goto line_180;
    /* BASIC: 170 PRINT: PRINT "I'M SORRY YOU DON'T LIKE IT THAT WAY.": GOTO 200 */
line_170:
    printf("\n");
    printf("%s", "I'M SORRY YOU DON'T LIKE IT THAT WAY."); printf("\n");
    goto line_200;
    /* BASIC: 180 PRINT: PRINT "I KNEW YOU'D AGREE!!" */
line_180:
    printf("\n");
    printf("%s", "I KNEW YOU'D AGREE!!"); printf("\n");
    /* BASIC: 200 PRINT: PRINT "I REALLY ENJOYED MEETING YOU ";A$;"." */
line_200:
    printf("\n");
    printf("%s", "I REALLY ENJOYED MEETING YOU "); printf("%s", A_str); printf("%s", "."); printf("\n");
    /* BASIC: 210 PRINT "HAVE A NICE DAY!" */
line_210:
    printf("%s", "HAVE A NICE DAY!"); printf("\n");
    /* BASIC: 999 END */
line_999:
    exit(0);

    return 0;
}
