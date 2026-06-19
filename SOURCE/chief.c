/*
 * Transpiled from chief.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double BYE, FACE, NOW, LIGHTNING, TEST, J, NEW, SO, RE, JERSEY, THE, WATCH, MINUS, XXX, BOLT, SUBTRACT, A, HOPE, D, RIGHT, UP, NUMBER, OUT, BY, MORRISTOWN, TAKE, XX, ADD, CHIEF, MUST, INDIAN, GREAT, WAS, TIMES, WHAT, NUMBERS, SHUT, LET, YOUR, I, MAD, BELIEVE, AM, THERE, Y, ME, BET, H, K, Z, GOD, SAME, CREATIVE, TONGUE, THINK, YOU, X, WISE, WITH, MATH, EH, WE, G, SAKE, SMART, ARE, BE, B, PLUS, C, WHICH, MULTIPLY, FREEK, ORIGINAL, COMPUTING, READY, GET, CALLED, DIVIDED, EQUALS, F, DIVIDE, DO, YES, MADE, PALE, HAVE, THIS;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 2 PRINT TAB(30) "CHIEF" */
line_2:
    { int _t; for(_t=0; _t<30) "CHIEF; _t++) printf(" "); } printf("\n");
    /* BASIC: 4 PRINT TAB(15) "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:
    { int _t; for(_t=0; _t<15) "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY; _t++) printf(" "); } printf("\n");
    /* BASIC: 6 PRINT:PRINT:PRINT */
line_6:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 10 PRINT "I AM CHIEF NUMBERS FREEK, THE GREAT INDIAN MATH GOD." */
line_10:
    printf("%s", "I AM CHIEF NUMBERS FREEK, THE GREAT INDIAN MATH GOD."); printf("\n");
    /* BASIC: 20 PRINT "ARE YOU READY TO TAKE THE TEST YOU CALLED ME OUT FOR"; */
line_20:
    printf("%s", "ARE YOU READY TO TAKE THE TEST YOU CALLED ME OUT FOR");
    /* BASIC: 30 INPUT A$ */
line_30:
    printf("? "); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    /* BASIC: 40 IF A$="YES" THEN 60 */
line_40:
    if (A$=="YES") goto line_60;
    /* BASIC: 50 PRINT "SHUT UP, PALE FACE WITH WISE TONGUE." */
line_50:
    printf("%s", "SHUT UP, PALE FACE WITH WISE TONGUE."); printf("\n");
    /* BASIC: 60 PRINT " TAKE A NUMBER AND ADD 3. DIVIDE THIS NUMBER BY 5 AND" */
line_60:
    printf("%s", " TAKE A NUMBER AND ADD 3. DIVIDE THIS NUMBER BY 5 AND"); printf("\n");
    /* BASIC: 70 PRINT "MULTIPLY BY 8. DIVIDE BY 5 AND ADD THE SAME. SUBTRACT 1." */
line_70:
    printf("%s", "MULTIPLY BY 8. DIVIDE BY 5 AND ADD THE SAME. SUBTRACT 1."); printf("\n");
    /* BASIC: 80 PRINT "  WHAT DO YOU HAVE"; */
line_80:
    printf("%s", "  WHAT DO YOU HAVE");
    /* BASIC: 90 INPUT B */
line_90:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &B);
    /* BASIC: 100 LET C = (B+1-5)*5/8*5-3 */
line_100:
    /* UNTRANSLATED: LET C = (B+1-5)*5/8*5-3 */
    /* BASIC: 110 PRINT "I BET YOUR NUMBER WAS" C". AM I RIGHT"; */
line_110:
    printf("%s", "I BET YOUR NUMBER WAS" C". AM I RIGHT");
    /* BASIC: 120 INPUT D$ */
line_120:
    printf("? "); fgets(D_str, sizeof(D_str), stdin); D_str[strcspn(D_str, "\n")] = 0;
    /* BASIC: 130 IF D$="YES" THEN 500 */
line_130:
    if (D$=="YES") goto line_500;
    /* BASIC: 140 PRINT "WHAT WAS YOUR ORIGINAL NUMBER"; */
line_140:
    printf("%s", "WHAT WAS YOUR ORIGINAL NUMBER");
    /* BASIC: 150 INPUT K */
line_150:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &K);
    /* BASIC: 155 LET F=K+3 */
line_155:
    /* UNTRANSLATED: LET F=K+3 */
    /* BASIC: 160 LET G=F/5 */
line_160:
    /* UNTRANSLATED: LET G=F/5 */
    /* BASIC: 170 LET H=G*8 */
line_170:
    /* UNTRANSLATED: LET H=G*8 */
    /* BASIC: 180 LET I=H/5+5 */
line_180:
    /* UNTRANSLATED: LET I=H/5+5 */
    /* BASIC: 190 LET J=I-1 */
line_190:
    /* UNTRANSLATED: LET J=I-1 */
    /* BASIC: 200 PRINT "SO YOU THINK YOU'RE SO SMART, EH?" */
line_200:
    printf("%s", "SO YOU THINK YOU'RE SO SMART, EH?"); printf("\n");
    /* BASIC: 210 PRINT "NOW WATCH." */
line_210:
    printf("%s", "NOW WATCH."); printf("\n");
    /* BASIC: 230 PRINT K"PLUS 3 EQUALS"F". THIS DIVIDED BY 5 EQUALS"G";" */
line_230:
    printf("%g ", (double)(K"PLUS 3 EQUALS"F". THIS DIVIDED BY 5 EQUALS"G";")); printf("\n");
    /* BASIC: 240 PRINT "THIS TIMES 8 EQUALS"H". IF WE DIVIDE BY 5 AND ADD 5," */
line_240:
    printf("%s", "THIS TIMES 8 EQUALS"H". IF WE DIVIDE BY 5 AND ADD 5,"); printf("\n");
    /* BASIC: 250 PRINT "WE GET"I", WHICH, MINUS 1, EQUALS"J"." */
line_250:
    printf("%s", "WE GET"I", WHICH, MINUS 1, EQUALS"J"."); printf("\n");
    /* BASIC: 260 PRINT "NOW DO YOU BELIEVE ME"; */
line_260:
    printf("%s", "NOW DO YOU BELIEVE ME");
    /* BASIC: 270 INPUT Z$ */
line_270:
    printf("? "); fgets(Z_str, sizeof(Z_str), stdin); Z_str[strcspn(Z_str, "\n")] = 0;
    /* BASIC: 290 IF Z$="YES" THEN 500 */
line_290:
    if (Z$=="YES") goto line_500;
    /* BASIC: 295 PRINT "YOU HAVE MADE ME MAD!!!" */
line_295:
    printf("%s", "YOU HAVE MADE ME MAD!!!"); printf("\n");
    /* BASIC: 300 PRINT "THERE MUST BE A GREAT LIGHTNING BOLT!" */
line_300:
    printf("%s", "THERE MUST BE A GREAT LIGHTNING BOLT!"); printf("\n");
    /* BASIC: 310 PRINT:PRINT */
line_310:
    printf("\n");
    printf("\n");
    /* BASIC: 330 FOR X=30 TO 22 STEP -1 */
line_330:
    X = 30; for_loop_X: if ((-1 >= 0 && X > 22) || (-1 < 0 && X < 22)) goto end_for_X;
    /* BASIC: 340 PRINT TAB(X) "X X" */
line_340:
    { int _t; for(_t=0; _t<X) "X X; _t++) printf(" "); } printf("\n");
    /* BASIC: 350 NEXT X */
line_350:
    X += -1; goto for_loop_X; end_for_X:;
    /* BASIC: 360 PRINT TAB(21) "X XXX" */
line_360:
    { int _t; for(_t=0; _t<21) "X XXX; _t++) printf(" "); } printf("\n");
    /* BASIC: 370 PRINT TAB(20) "X   X" */
line_370:
    { int _t; for(_t=0; _t<20) "X   X; _t++) printf(" "); } printf("\n");
    /* BASIC: 380 PRINT TAB(19) "XX X" */
line_380:
    { int _t; for(_t=0; _t<19) "XX X; _t++) printf(" "); } printf("\n");
    /* BASIC: 390 FOR Y=20 TO 13 STEP -1 */
line_390:
    Y = 20; for_loop_Y: if ((-1 >= 0 && Y > 13) || (-1 < 0 && Y < 13)) goto end_for_Y;
    /* BASIC: 400 PRINT TAB(Y) "X X" */
line_400:
    { int _t; for(_t=0; _t<Y) "X X; _t++) printf(" "); } printf("\n");
    /* BASIC: 410 NEXT Y */
line_410:
    Y += -1; goto for_loop_Y; end_for_Y:;
    /* BASIC: 420 PRINT TAB(12) "XX" */
line_420:
    { int _t; for(_t=0; _t<12) "XX; _t++) printf(" "); } printf("\n");
    /* BASIC: 430 PRINT TAB(11) "X" */
line_430:
    { int _t; for(_t=0; _t<11) "X; _t++) printf(" "); } printf("\n");
    /* BASIC: 440 PRINT TAB(10) "*" */
line_440:
    { int _t; for(_t=0; _t<10) "*; _t++) printf(" "); } printf("\n");
    /* BASIC: 450 PRINT:PRINT"#########################":PRINT */
line_450:
    printf("\n");
    printf("%s", "#########################"); printf("\n");
    printf("\n");
    /* BASIC: 470 PRINT "I HOPE YOU BELIEVE ME NOW, FOR YOUR SAKE!!" */
line_470:
    printf("%s", "I HOPE YOU BELIEVE ME NOW, FOR YOUR SAKE!!"); printf("\n");
    /* BASIC: 480 GOTO 520 */
line_480:
    goto line_520;
    /* BASIC: 510 PRINT "BYE!!!" */
line_510:
    printf("%s", "BYE!!!"); printf("\n");
    /* BASIC: 520 END */
line_520:
    exit(0);

    return 0;
}
