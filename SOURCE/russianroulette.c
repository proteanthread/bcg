/*
 * Transpiled from russianroulette.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double REVOLVER, OUT, BE, MORRISTOWN, GAME, GO, RELATIVES, ELSE, IS, BANG, NEW, TYPE, CHICKEN, OF, BLOW, RE, RUSSIAN, COMPUTING, CREATIVE, JERSEY, ROULETTE, WILL, CONDOLENCES, WIN, CLICK, HIS, YOU, TRIGGER, GIVE, SENT, A, HERE, VICTIM, UP, DEAD, LET, PULL, SPIN, N, YOUR, I, THIS, CHAMBER, SOMEONE, BRAINS;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 1 PRINT TAB(28);"RUSSIAN ROULETTE" */
line_1:
    { int _t; for(_t=0; _t<28; _t++) printf(" "); } printf("%s", "RUSSIAN ROULETTE"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT:PRINT:PRINT */
line_3:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 5 PRINT "THIS IS A GAME OF >>>>>>>>>>RUSSIAN ROULETTE." */
line_5:
    printf("%s", "THIS IS A GAME OF >>>>>>>>>>RUSSIAN ROULETTE."); printf("\n");
    /* BASIC: 10 PRINT:PRINT "HERE IS A REVOLVER." */
line_10:
    printf("\n");
    printf("%s", "HERE IS A REVOLVER."); printf("\n");
    /* BASIC: 20 PRINT "TYPE '1' TO SPIN CHAMBER AND PULL TRIGGER." */
line_20:
    printf("%s", "TYPE '1' TO SPIN CHAMBER AND PULL TRIGGER."); printf("\n");
    /* BASIC: 22 PRINT "TYPE '2' TO GIVE UP." */
line_22:
    printf("%s", "TYPE '2' TO GIVE UP."); printf("\n");
    /* BASIC: 23 PRINT "GO"; */
line_23:
    printf("%s", "GO");
    /* BASIC: 25 N=0 */
line_25:
    N = 0;
    /* BASIC: 30 INPUT I */
line_30:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &I);
    /* BASIC: 31 IF I<>2 THEN 35 */
line_31:
    if (I!=2) goto line_35;
    /* BASIC: 32 PRINT "     CHICKEN!!!!!" */
line_32:
    printf("%s", "     CHICKEN!!!!!"); printf("\n");
    /* BASIC: 33 GOTO 72 */
line_33:
    goto line_72;
    /* BASIC: 35 N=N+1 */
line_35:
    N = N+1;
    /* BASIC: 40 IF RND(1)>.833333 THEN 70 */
line_40:
    if (((double)rand() / (double)RAND_MAX)>.833333) goto line_70;
    /* BASIC: 45 IF N>10 THEN 80 */
line_45:
    if (N>10) goto line_80;
    /* BASIC: 50 PRINT "- CLICK -" */
line_50:
    printf("%s", "- CLICK -"); printf("\n");
    /* BASIC: 60 PRINT: GOTO 30 */
line_60:
    printf("\n");
    goto line_30;
    /* BASIC: 70 PRINT "     BANG!!!!!   YOU'RE DEAD!" */
line_70:
    printf("%s", "     BANG!!!!!   YOU'RE DEAD!"); printf("\n");
    /* BASIC: 71 PRINT "CONDOLENCES WILL BE SENT TO YOUR RELATIVES." */
line_71:
    printf("%s", "CONDOLENCES WILL BE SENT TO YOUR RELATIVES."); printf("\n");
    /* BASIC: 72 PRINT:PRINT:PRINT */
line_72:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 75 PRINT "...NEXT VICTIM...":GOTO 20 */
line_75:
    printf("%s", "...NEXT VICTIM..."); printf("\n");
    goto line_20;
    /* BASIC: 80 PRINT "YOU WIN!!!!!" */
line_80:
    printf("%s", "YOU WIN!!!!!"); printf("\n");
    /* BASIC: 85 PRINT "LET SOMEONE ELSE BLOW HIS BRAINS OUT." */
line_85:
    printf("%s", "LET SOMEONE ELSE BLOW HIS BRAINS OUT."); printf("\n");
    /* BASIC: 90 GOTO 10 */
line_90:
    goto line_10;
    /* BASIC: 99 END */
line_99:
    exit(0);

    return 0;
}
