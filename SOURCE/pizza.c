/*
 * Transpiled from pizza.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double DRIVER, READ, NOW, P, GAME, DIRECTIONS, J, NEW, ANYWAY, ANSWER, JERSEY, THE, DELIVERY, A, EXAMPLE, HYATTSVILLE, D, DIFFICULT, T, HELLO, NEED, IN, HOME, MORRISTOWN, TAKE, DATA, START, LUCK, ORDERED, WHAT, ORDERING, DEFINITELY, LATER, WANT, S1, TOO, YOUR, I, TRUCK, THANKS, OUTPUT, DELIVERED, CITY, M, MORE, H, IS, LOCATION, K, COORDINATES, OF, SOMEBODY, PIZZA, S, ORDER, WILL, CREATIVE, JOB, PLEASE, YOU, LIVE, NO, NAME, WOULD, MAP, DELIVER, TAKING, G, UNDERSTAND, GOOD, ARE, BE, SEE, B, C, TELL, ORDERS, COMPUTING, READY, HOMES, E, WHERE, GIVE, SEND, AT, L, DOES, PIZZAS, HI, F, DID, DO, FIRST, YES, BOY, O, ASK, N, THIS;
    char S_str[1000][256] = {0}; /* Static string array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 5 PRINT TAB(33);"PIZZA" */
line_5:
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "PIZZA"); printf("\n");
    /* BASIC: 10 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_10:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 15 PRINT: PRINT: PRINT */
line_15:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 20 DIM S$(16),M$(4) */
line_20:
    /* DIM S$(16),M$(4) (handled statically) */
    /* BASIC: 30 PRINT "PIZZA DELIVERY GAME": PRINT */
line_30:
    printf("%s", "PIZZA DELIVERY GAME"); printf("\n");
    printf("\n");
    /* BASIC: 50 INPUT "WHAT IS YOUR FIRST NAME";N$: PRINT */
line_50:
    printf("%s", "WHAT IS YOUR FIRST NAME"); fgets(N_str, sizeof(N_str), stdin); N_str[strcspn(N_str, "\n")] = 0;
    printf("\n");
    /* BASIC: 80 PRINT "HI, ";N$;".  IN THIS GAME YOU ARE TO TAKE ORDERS" */
line_80:
    printf("%s", "HI, "); printf("%s", N_str); printf("%s", ".  IN THIS GAME YOU ARE TO TAKE ORDERS"); printf("\n");
    /* BASIC: 90 PRINT "FOR PIZZAS.  THEN YOU ARE TO TELL A DELIVERY BOY" */
line_90:
    printf("%s", "FOR PIZZAS.  THEN YOU ARE TO TELL A DELIVERY BOY"); printf("\n");
    /* BASIC: 100 PRINT "WHERE TO DELIVER THE ORDERED PIZZAS.": PRINT: PRINT */
line_100:
    printf("%s", "WHERE TO DELIVER THE ORDERED PIZZAS."); printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 140 FOR I=1 TO 16 */
line_140:
    I = 1; for_loop_I: if ((1 >= 0 && I > 16) || (1 < 0 && I < 16)) goto end_for_I;
    /* BASIC: 150 READ S$(I) */
line_150:
    /* UNTRANSLATED: READ S$(I) */
    /* BASIC: 160 NEXT I */
line_160:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 170 FOR I=1 TO 4 */
line_170:
    I = 1; for_loop_I: if ((1 >= 0 && I > 4) || (1 < 0 && I < 4)) goto end_for_I;
    /* BASIC: 180 READ M$(I) */
line_180:
    /* UNTRANSLATED: READ M$(I) */
    /* BASIC: 190 NEXT I */
line_190:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 200 DATA "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O" */
line_200:
    /* UNTRANSLATED: DATA "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O" */
    /* BASIC: 210 DATA "P","1","2","3","4" */
line_210:
    /* UNTRANSLATED: DATA "P","1","2","3","4" */
    /* BASIC: 230 PRINT "MAP OF THE CITY OF HYATTSVILLE": PRINT */
line_230:
    printf("%s", "MAP OF THE CITY OF HYATTSVILLE"); printf("\n");
    printf("\n");
    /* BASIC: 250 PRINT " -----1-----2-----3-----4-----" */
line_250:
    printf("%s", " -----1-----2-----3-----4-----"); printf("\n");
    /* BASIC: 260 K=4 */
line_260:
    K = 4;
    /* BASIC: 270 FOR I=1 TO 4 */
line_270:
    I = 1; for_loop_I: if ((1 >= 0 && I > 4) || (1 < 0 && I < 4)) goto end_for_I;
    /* BASIC: 280 PRINT "-": PRINT "-": PRINT"-": PRINT "-" */
line_280:
    printf("%s", "-"); printf("\n");
    printf("%s", "-"); printf("\n");
    printf("%s", "-"); printf("\n");
    printf("%s", "-"); printf("\n");
    /* BASIC: 320 PRINT M$(K); */
line_320:
    printf("%g ", (double)(M$(K)));
    /* BASIC: 330 S1=16-4*I+1 */
line_330:
    S1 = 16-4*I+1;
    /* BASIC: 340 PRINT "     ";S$(S1);"     ";S$(S1+1);"     ";S$(S1+2);"     "; */
line_340:
    printf("%s", "     "); printf("%g ", (double)(S$(S1))); printf("%s", "     "); printf("%g ", (double)(S$(S1+1))); printf("%s", "     "); printf("%g ", (double)(S$(S1+2))); printf("%s", "     ");
    /* BASIC: 350 PRINT S$(S1+3);"     ";M$(K) */
line_350:
    printf("%g ", (double)(S$(S1+3))); printf("%s", "     "); printf("%g ", (double)(M$(K))); printf("\n");
    /* BASIC: 380 K=K-1 */
line_380:
    K = K-1;
    /* BASIC: 390 NEXT I */
line_390:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 400 PRINT "-": PRINT "-": PRINT "-": PRINT "-" */
line_400:
    printf("%s", "-"); printf("\n");
    printf("%s", "-"); printf("\n");
    printf("%s", "-"); printf("\n");
    printf("%s", "-"); printf("\n");
    /* BASIC: 440 PRINT " -----1-----2-----3-----4-----": PRINT */
line_440:
    printf("%s", " -----1-----2-----3-----4-----"); printf("\n");
    printf("\n");
    /* BASIC: 460 PRINT "THE OUTPUT IS A MAP OF THE HOMES WHERE" */
line_460:
    printf("%s", "THE OUTPUT IS A MAP OF THE HOMES WHERE"); printf("\n");
    /* BASIC: 470 PRINT "YOU ARE TO SEND PIZZAS.": PRINT */
line_470:
    printf("%s", "YOU ARE TO SEND PIZZAS."); printf("\n");
    printf("\n");
    /* BASIC: 490 PRINT "YOUR JOB IS TO GIVE A TRUCK DRIVER" */
line_490:
    printf("%s", "YOUR JOB IS TO GIVE A TRUCK DRIVER"); printf("\n");
    /* BASIC: 500 PRINT "THE LOCATION OR COORDINATES OF THE" */
line_500:
    printf("%s", "THE LOCATION OR COORDINATES OF THE"); printf("\n");
    /* BASIC: 510 PRINT "HOME ORDERING THE PIZZA.": PRINT */
line_510:
    printf("%s", "HOME ORDERING THE PIZZA."); printf("\n");
    printf("\n");
    /* BASIC: 520 INPUT "DO YOU NEED MORE DIRECTIONS";A$ */
line_520:
    printf("%s", "DO YOU NEED MORE DIRECTIONS"); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    /* BASIC: 530 IF A$="YES" THEN 590 */
line_530:
    if (A$=="YES") goto line_590;
    /* BASIC: 540 IF A$="NO" THEN 750 */
line_540:
    if (A$=="NO") goto line_750;
    /* BASIC: 550 PRINT "'YES' OR 'NO' PLEASE, NOW THEN,": GOTO 520 */
line_550:
    printf("%s", "'YES' OR 'NO' PLEASE, NOW THEN,"); printf("\n");
    goto line_520;
    /* BASIC: 590 PRINT: PRINT "SOMEBODY WILL ASK FOR A PIZZA TO BE" */
line_590:
    printf("\n");
    printf("%s", "SOMEBODY WILL ASK FOR A PIZZA TO BE"); printf("\n");
    /* BASIC: 600 PRINT "DELIVERED.  THEN A DELIVERY BOY WILL" */
line_600:
    printf("%s", "DELIVERED.  THEN A DELIVERY BOY WILL"); printf("\n");
    /* BASIC: 610 PRINT "ASK YOU FOR THE LOCATION.":PRINT "     EXAMPLE:" */
line_610:
    printf("%s", "ASK YOU FOR THE LOCATION."); printf("\n");
    printf("%s", "     EXAMPLE:"); printf("\n");
    /* BASIC: 620 PRINT "THIS IS J.  PLEASE SEND A PIZZA." */
line_620:
    printf("%s", "THIS IS J.  PLEASE SEND A PIZZA."); printf("\n");
    /* BASIC: 640 PRINT "DRIVER TO ";N$;".  WHERE DOES J LIVE?" */
line_640:
    printf("%s", "DRIVER TO "); printf("%s", N_str); printf("%s", ".  WHERE DOES J LIVE?"); printf("\n");
    /* BASIC: 650 PRINT "YOUR ANSWER WOULD BE 2,3": PRINT */
line_650:
    printf("%s", "YOUR ANSWER WOULD BE 2,3"); printf("\n");
    printf("\n");
    /* BASIC: 660 INPUT "UNDERSTAND";A$ */
line_660:
    printf("%s", "UNDERSTAND"); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    /* BASIC: 670 IF A$="YES" THEN 690 */
line_670:
    if (A$=="YES") goto line_690;
    /* BASIC: 680 PRINT "THIS JOB IS DEFINITELY TOO DIFFICULT FOR YOU. THANKS ANYWAY" */
line_680:
    printf("%s", "THIS JOB IS DEFINITELY TOO DIFFICULT FOR YOU. THANKS ANYWAY"); printf("\n");
    /* BASIC: 685 GOTO 999 */
line_685:
    goto line_999;
    /* BASIC: 690 PRINT "GOOD.  YOU ARE NOW READY TO START TAKING ORDERS.": PRINT */
line_690:
    printf("%s", "GOOD.  YOU ARE NOW READY TO START TAKING ORDERS."); printf("\n");
    printf("\n");
    /* BASIC: 700 PRINT "GOOD LUCK!!": PRINT */
line_700:
    printf("%s", "GOOD LUCK!!"); printf("\n");
    printf("\n");
    /* BASIC: 750 FOR I=1 TO 5 */
line_750:
    I = 1; for_loop_I: if ((1 >= 0 && I > 5) || (1 < 0 && I < 5)) goto end_for_I;
    /* BASIC: 760 S=INT(RND(1)*16+1): PRINT */
line_760:
    S = floor(((double)rand() / (double)RAND_MAX)*16+1);
    printf("\n");
    /* BASIC: 770 PRINT "HELLO ";N$;"'S PIZZA.  THIS IS ";S$(S);"."; */
line_770:
    printf("%s", "HELLO "); printf("%s", N_str); printf("%s", "'S PIZZA.  THIS IS "); printf("%g ", (double)(S$(S))); printf("%s", ".");
    /* BASIC: 775 PRINT "  PLEASE SEND A PIZZA." */
line_775:
    printf("%s", "  PLEASE SEND A PIZZA."); printf("\n");
    /* BASIC: 780 PRINT "  DRIVER TO ";N$;":  WHERE DOES ";S$(S);" LIVE"; */
line_780:
    printf("%s", "  DRIVER TO "); printf("%s", N_str); printf("%s", ":  WHERE DOES "); printf("%g ", (double)(S$(S))); printf("%s", " LIVE");
    /* BASIC: 790 INPUT A(1),A(2) */
line_790:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &A(1),A(2));
    /* BASIC: 870 T=A(1)+(A(2)-1)*4 */
line_870:
    T = A(1)+(A(2)-1)*4;
    /* BASIC: 880 IF T=S THEN 920 */
line_880:
    if (T==S) goto line_920;
    /* BASIC: 890 PRINT "THIS IS ";S$(T);".  I DID NOT ORDER A PIZZA." */
line_890:
    printf("%s", "THIS IS "); printf("%g ", (double)(S$(T))); printf("%s", ".  I DID NOT ORDER A PIZZA."); printf("\n");
    /* BASIC: 900 PRINT "I LIVE AT ";A(1);",";A(2) */
line_900:
    printf("%s", "I LIVE AT "); printf("%g ", (double)(A(1))); printf("%s", ","); printf("%g ", (double)(A(2))); printf("\n");
    /* BASIC: 910 GOTO 780 */
line_910:
    goto line_780;
    /* BASIC: 920 PRINT "HELLO "N$;".  THIS IS ";S$(S);", THANKS FOR THE PIZZA." */
line_920:
    printf("%s", "HELLO "N_str); printf("%s", ".  THIS IS "); printf("%g ", (double)(S$(S))); printf("%s", ", THANKS FOR THE PIZZA."); printf("\n");
    /* BASIC: 930 NEXT I */
line_930:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 940 PRINT: INPUT "DO YOU WANT TO DELIVER MORE PIZZAS";A$ */
line_940:
    printf("\n");
    printf("%s", "DO YOU WANT TO DELIVER MORE PIZZAS"); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    /* BASIC: 960 IF A$="YES" THEN 750 */
line_960:
    if (A$=="YES") goto line_750;
    /* BASIC: 970 PRINT: PRINT "O.K. ";N$;", SEE YOU LATER!":PRINT */
line_970:
    printf("\n");
    printf("%s", "O.K. "); printf("%s", N_str); printf("%s", ", SEE YOU LATER!"); printf("\n");
    printf("\n");
    /* BASIC: 999 END */
line_999:
    exit(0);

    return 0;
}
