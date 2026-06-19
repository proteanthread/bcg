/*
 * Transpiled from slots.bas
 * GW-BASIC to strict C17
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

/* Static library helpers */
static double basic_SGN(double x) { return (x > 0.0) - (x < 0.0); }
static double basic_LEN(const char *s) { return (double)strlen(s); }
static double basic_ASC(const char *s) { return s[0] ? (double)((unsigned char)s[0]) : 0.0; }
static double basic_VAL(const char *s) { return atof(s); }

static const char *basic_CHR(double n) {
    static char buf[4][2];
    static int idx = 0;
    idx = (idx + 1) % 4;
    buf[idx][0] = (char)n;
    buf[idx][1] = '\0';
    return buf[idx];
}

static const char *basic_STR(double n) {
    static char buf[4][64];
    static int idx = 0;
    idx = (idx + 1) % 4;
    if (n >= 0) snprintf(buf[idx], sizeof(buf[idx]), " %g", n);
    else snprintf(buf[idx], sizeof(buf[idx]), "%g", n);
    return buf[idx];
}

static const char *basic_LEFT(const char *s, double n) {
    static char buf[4][256];
    static int idx = 0;
    int len = (int)n;
    idx = (idx + 1) % 4;
    if (len < 0) len = 0;
    if (len > 255) len = 255;
    strncpy(buf[idx], s, len);
    buf[idx][len] = '\0';
    return buf[idx];
}

static const char *basic_RIGHT(const char *s, double n) {
    static char buf[4][256];
    static int idx = 0;
    int len = (int)n;
    int s_len = (int)strlen(s);
    idx = (idx + 1) % 4;
    if (len < 0) len = 0;
    if (len > s_len) len = s_len;
    if (len > 255) len = 255;
    strncpy(buf[idx], s + s_len - len, len);
    buf[idx][len] = '\0';
    return buf[idx];
}

static const char *basic_MID(const char *s, double start_d, double len_d) {
    static char buf[4][256];
    static int idx = 0;
    int start = (int)start_d - 1;
    int len = (int)len_d;
    int s_len = (int)strlen(s);
    idx = (idx + 1) % 4;
    if (start < 0) start = 0;
    if (start > s_len) start = s_len;
    if (len < 0) len = 0;
    if (len > 255) len = 255;
    strncpy(buf[idx], s + start, len);
    buf[idx][len] = '\0';
    return buf[idx];
}

static const char *str_cat_helper(const char *s1, const char *s2) {
    static char buf[4][512];
    static int idx = 0;
    idx = (idx + 1) % 4;
    snprintf(buf[idx], sizeof(buf[idx]), "%s%s", s1, s2);
    return buf[idx];
}

static void str_assign(char *dest, size_t dest_sz, const char *src) {
    strncpy(dest, src, dest_sz - 1);
    dest[dest_sz - 1] = '\0';
}

/* Global variables */
static int gosub_stack[256];
static int gosub_sp = 0;
static double LET, M, P, Q4, S, T8, X, Y, Z;
static char A_str[256] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(30);"SLOTS" */
line_10:;
    { int _t; for(_t=0; _t<30; _t++) printf(" "); } printf("%s", "SLOTS"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT: PRINT: PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 100 REM PRODUCED BY FRED MIRABELLE AND BOB HARPER ON JAN 29, 1973 */
line_100:;
    // REM PRODUCED BY FRED MIRABELLE AND BOB HARPER ON JAN 29, 1973
    /* BASIC: 110 REM IT SIMULATES THE SLOT MACHINE. */
line_110:;
    // REM IT SIMULATES THE SLOT MACHINE.
    /* BASIC: 120 PRINT "YOU ARE IN THE H&M CASINO,IN FRONT OF ONE OF OUR" */
line_120:;
    printf("%s", "YOU ARE IN THE H&M CASINO,IN FRONT OF ONE OF OUR"); printf("\n");
    /* BASIC: 130 PRINT "ONE-ARM BANDITS. BET FROM $1 TO $100." */
line_130:;
    printf("%s", "ONE-ARM BANDITS. BET FROM $1 TO $100."); printf("\n");
    /* BASIC: 140 PRINT "TO PULL THE ARM, PUNCH THE RETURN KEY AFTER MAKING YOUR BET." */
line_140:;
    printf("%s", "TO PULL THE ARM, PUNCH THE RETURN KEY AFTER MAKING YOUR BET."); printf("\n");
    /* BASIC: 150 LET P=0 */
line_150:;
    /* UNTRANSLATED: LET P=0 */
    /* BASIC: 160 PRINT: PRINT"YOUR BET"; */
line_160:;
    printf("\n");
    printf("%s", "YOUR BET");
    /* BASIC: 170 INPUT M */
line_170:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &M);
    /* BASIC: 180 IF M>100 THEN 860 */
line_180:;
    if (M>100) { goto line_860; }
    /* BASIC: 190 IF M<1 THEN 880 */
line_190:;
    if (M<1) { goto line_880; }
    /* BASIC: 200 M=INT(M) */
line_200:;
    M = floor(M);
    /* BASIC: 210 GOSUB 1270 */
line_210:;
    gosub_stack[gosub_sp++] = 1; goto line_1270; line_ret_1:;
    /* BASIC: 220 PRINT */
line_220:;
    printf("\n");
    /* BASIC: 230 LET X=INT(6*RND(1)+1) */
line_230:;
    /* UNTRANSLATED: LET X=INT(6*RND(1)+1) */
    /* BASIC: 240 LET Y=INT(6*RND(1)+1) */
line_240:;
    /* UNTRANSLATED: LET Y=INT(6*RND(1)+1) */
    /* BASIC: 250 LET Z=INT(6*RND(1)+1) */
line_250:;
    /* UNTRANSLATED: LET Z=INT(6*RND(1)+1) */
    /* BASIC: 260 PRINT */
line_260:;
    printf("\n");
    /* BASIC: 270 IF X=1 THEN 910 */
line_270:;
    if (X==1) { goto line_910; }
    /* BASIC: 280 IF X=2 THEN 930 */
line_280:;
    if (X==2) { goto line_930; }
    /* BASIC: 290 IF X=3 THEN 950 */
line_290:;
    if (X==3) { goto line_950; }
    /* BASIC: 300 IF X=4 THEN 970 */
line_300:;
    if (X==4) { goto line_970; }
    /* BASIC: 310 IF X=5 THEN 990 */
line_310:;
    if (X==5) { goto line_990; }
    /* BASIC: 320 IF X=6 THEN 1010 */
line_320:;
    if (X==6) { goto line_1010; }
    /* BASIC: 330 IF Y=1 THEN 1030 */
line_330:;
    if (Y==1) { goto line_1030; }
    /* BASIC: 340 IF Y=2 THEN 1050 */
line_340:;
    if (Y==2) { goto line_1050; }
    /* BASIC: 350 IF Y=3 THEN 1070 */
line_350:;
    if (Y==3) { goto line_1070; }
    /* BASIC: 360 IF Y=4 THEN 1090 */
line_360:;
    if (Y==4) { goto line_1090; }
    /* BASIC: 370 IF Y=5 THEN 1110 */
line_370:;
    if (Y==5) { goto line_1110; }
    /* BASIC: 380 IF Y=6 THEN 1130 */
line_380:;
    if (Y==6) { goto line_1130; }
    /* BASIC: 390 IF Z=1 THEN 1150 */
line_390:;
    if (Z==1) { goto line_1150; }
    /* BASIC: 400 IF Z=2 THEN 1170 */
line_400:;
    if (Z==2) { goto line_1170; }
    /* BASIC: 410 IF Z=3 THEN 1190 */
line_410:;
    if (Z==3) { goto line_1190; }
    /* BASIC: 420 IF Z=4 THEN 1210 */
line_420:;
    if (Z==4) { goto line_1210; }
    /* BASIC: 430 IF Z=5 THEN 1230 */
line_430:;
    if (Z==5) { goto line_1230; }
    /* BASIC: 440 IF Z=6 THEN 1250 */
line_440:;
    if (Z==6) { goto line_1250; }
    /* BASIC: 450 IF X=Y THEN 600 */
line_450:;
    if (X==Y) { goto line_600; }
    /* BASIC: 460 IF X=Z THEN 630 */
line_460:;
    if (X==Z) { goto line_630; }
    /* BASIC: 470 IF Y=Z THEN 650 */
line_470:;
    if (Y==Z) { goto line_650; }
    /* BASIC: 480 PRINT */
line_480:;
    printf("\n");
    /* BASIC: 490 PRINT "YOU LOST." */
line_490:;
    printf("%s", "YOU LOST."); printf("\n");
    /* BASIC: 500 LET P=P-M */
line_500:;
    /* UNTRANSLATED: LET P=P-M */
    /* BASIC: 510 PRINT "YOUR STANDINGS ARE $"P */
line_510:;
    printf("%s", "YOUR STANDINGS ARE $"); printf("%g ", (double)(P)); printf("\n");
    /* BASIC: 520 PRINT "AGAIN"; */
line_520:;
    printf("%s", "AGAIN");
    /* BASIC: 530 INPUT A$ */
line_530:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    /* BASIC: 540 IF A$="Y" THEN 160 */
line_540:;
    if (strcmp(A_str, "Y") == 0) { goto line_160; }
    /* BASIC: 550 PRINT */
line_550:;
    printf("\n");
    /* BASIC: 560 IF P<0 THEN 670 */
line_560:;
    if (P<0) { goto line_670; }
    /* BASIC: 570 IF P=0 THEN 690 */
line_570:;
    if (P==0) { goto line_690; }
    /* BASIC: 580 IF P>0 THEN 710 */
line_580:;
    if (P>0) { goto line_710; }
    /* BASIC: 590 GOTO 1350 */
line_590:;
    goto line_1350;
    /* BASIC: 600 IF Y=Z THEN 730 */
line_600:;
    if (Y==Z) { goto line_730; }
    /* BASIC: 610 IF Y=1 THEN 820 */
line_610:;
    if (Y==1) { goto line_820; }
    /* BASIC: 620 GOTO 1341 */
line_620:;
    goto line_1341;
    /* BASIC: 630 IF Z=1 THEN 820 */
line_630:;
    if (Z==1) { goto line_820; }
    /* BASIC: 640 GOTO 470 */
line_640:;
    goto line_470;
    /* BASIC: 650 IF Z=1 THEN 820 */
line_650:;
    if (Z==1) { goto line_820; }
    /* BASIC: 660 GOTO 1341 */
line_660:;
    goto line_1341;
    /* BASIC: 670 PRINT "PAY UP!  PLEASE LEAVE YOUR MONEY ON THE TERMINAL." */
line_670:;
    printf("%s", "PAY UP!  PLEASE LEAVE YOUR MONEY ON THE TERMINAL."); printf("\n");
    /* BASIC: 680 GOTO 1350 */
line_680:;
    goto line_1350;
    /* BASIC: 690 PRINT"HEY, YOU BROKE EVEN." */
line_690:;
    printf("%s", "HEY, YOU BROKE EVEN."); printf("\n");
    /* BASIC: 700 GOTO 1350 */
line_700:;
    goto line_1350;
    /* BASIC: 710 PRINT "COLLECT YOUR WINNINGS FROM THE H&M CASHIER." */
line_710:;
    printf("%s", "COLLECT YOUR WINNINGS FROM THE H&M CASHIER."); printf("\n");
    /* BASIC: 720 GOTO 1350 */
line_720:;
    goto line_1350;
    /* BASIC: 730 IF Z=1 THEN 780 */
line_730:;
    if (Z==1) { goto line_780; }
    /* BASIC: 740 PRINT: PRINT"**TOP DOLLAR**" */
line_740:;
    printf("\n");
    printf("%s", "**TOP DOLLAR**"); printf("\n");
    /* BASIC: 750 PRINT "YOU WON!" */
line_750:;
    printf("%s", "YOU WON!"); printf("\n");
    /* BASIC: 760 P=(((10*M)+M)+P) */
line_760:;
    P = (((10*M)+M)+P);
    /* BASIC: 770 GOTO 510 */
line_770:;
    goto line_510;
    /* BASIC: 780 PRINT:PRINT"***JACKPOT***" */
line_780:;
    printf("\n");
    printf("%s", "***JACKPOT***"); printf("\n");
    /* BASIC: 790 PRINT "YOU WON!" */
line_790:;
    printf("%s", "YOU WON!"); printf("\n");
    /* BASIC: 800 P=(((100*M)+M)+P) */
line_800:;
    P = (((100*M)+M)+P);
    /* BASIC: 810 GOTO 510 */
line_810:;
    goto line_510;
    /* BASIC: 820 PRINT:PRINT"*DOUBLE BAR*" */
line_820:;
    printf("\n");
    printf("%s", "*DOUBLE BAR*"); printf("\n");
    /* BASIC: 830 PRINT"YOU WON!" */
line_830:;
    printf("%s", "YOU WON!"); printf("\n");
    /* BASIC: 840 P=(((5*M)+M)+P) */
line_840:;
    P = (((5*M)+M)+P);
    /* BASIC: 850 GOTO 510 */
line_850:;
    goto line_510;
    /* BASIC: 860 PRINT"HOUSE LIMITS ARE $100" */
line_860:;
    printf("%s", "HOUSE LIMITS ARE $100"); printf("\n");
    /* BASIC: 870 GOTO 160 */
line_870:;
    goto line_160;
    /* BASIC: 880 PRINT"MINIMUM BET IS $1" */
line_880:;
    printf("%s", "MINIMUM BET IS $1"); printf("\n");
    /* BASIC: 890 GOTO 160 */
line_890:;
    goto line_160;
    /* BASIC: 900 GOTO 220 */
line_900:;
    goto line_220;
    /* BASIC: 910 PRINT"BAR";:GOSUB 1310 */
line_910:;
    printf("%s", "BAR");
    gosub_stack[gosub_sp++] = 2; goto line_1310; line_ret_2:;
    /* BASIC: 920 GOTO 330 */
line_920:;
    goto line_330;
    /* BASIC: 930 PRINT"BELL";:GOSUB 1310 */
line_930:;
    printf("%s", "BELL");
    gosub_stack[gosub_sp++] = 3; goto line_1310; line_ret_3:;
    /* BASIC: 940 GOTO 330 */
line_940:;
    goto line_330;
    /* BASIC: 950 PRINT"ORANGE";:GOSUB 1310 */
line_950:;
    printf("%s", "ORANGE");
    gosub_stack[gosub_sp++] = 4; goto line_1310; line_ret_4:;
    /* BASIC: 960 GOTO 330 */
line_960:;
    goto line_330;
    /* BASIC: 970 PRINT"LEMON";:GOSUB 1310 */
line_970:;
    printf("%s", "LEMON");
    gosub_stack[gosub_sp++] = 5; goto line_1310; line_ret_5:;
    /* BASIC: 980 GOTO 330 */
line_980:;
    goto line_330;
    /* BASIC: 990 PRINT"PLUM";:GOSUB 1310 */
line_990:;
    printf("%s", "PLUM");
    gosub_stack[gosub_sp++] = 6; goto line_1310; line_ret_6:;
    /* BASIC: 1000 GOTO 330 */
line_1000:;
    goto line_330;
    /* BASIC: 1010 PRINT"CHERRY";:GOSUB 1310 */
line_1010:;
    printf("%s", "CHERRY");
    gosub_stack[gosub_sp++] = 7; goto line_1310; line_ret_7:;
    /* BASIC: 1020 GOTO 330 */
line_1020:;
    goto line_330;
    /* BASIC: 1030 PRINT" BAR";:GOSUB 1310 */
line_1030:;
    printf("%s", " BAR");
    gosub_stack[gosub_sp++] = 8; goto line_1310; line_ret_8:;
    /* BASIC: 1040 GOTO 390 */
line_1040:;
    goto line_390;
    /* BASIC: 1050 PRINT" BELL";:GOSUB 1310 */
line_1050:;
    printf("%s", " BELL");
    gosub_stack[gosub_sp++] = 9; goto line_1310; line_ret_9:;
    /* BASIC: 1060 GOTO 390 */
line_1060:;
    goto line_390;
    /* BASIC: 1070 PRINT" ORANGE";:GOSUB 1310 */
line_1070:;
    printf("%s", " ORANGE");
    gosub_stack[gosub_sp++] = 10; goto line_1310; line_ret_10:;
    /* BASIC: 1080 GOTO 390 */
line_1080:;
    goto line_390;
    /* BASIC: 1090 PRINT" LEMON";:GOSUB 1310 */
line_1090:;
    printf("%s", " LEMON");
    gosub_stack[gosub_sp++] = 11; goto line_1310; line_ret_11:;
    /* BASIC: 1100 GOTO 390 */
line_1100:;
    goto line_390;
    /* BASIC: 1110 PRINT" PLUM";:GOSUB 1310 */
line_1110:;
    printf("%s", " PLUM");
    gosub_stack[gosub_sp++] = 12; goto line_1310; line_ret_12:;
    /* BASIC: 1120 GOTO 390 */
line_1120:;
    goto line_390;
    /* BASIC: 1130 PRINT" CHERRY";:GOSUB 1310 */
line_1130:;
    printf("%s", " CHERRY");
    gosub_stack[gosub_sp++] = 13; goto line_1310; line_ret_13:;
    /* BASIC: 1140 GOTO 390 */
line_1140:;
    goto line_390;
    /* BASIC: 1150 PRINT" BAR" */
line_1150:;
    printf("%s", " BAR"); printf("\n");
    /* BASIC: 1160 GOTO 450 */
line_1160:;
    goto line_450;
    /* BASIC: 1170 PRINT" BELL" */
line_1170:;
    printf("%s", " BELL"); printf("\n");
    /* BASIC: 1180 GOTO 450 */
line_1180:;
    goto line_450;
    /* BASIC: 1190 PRINT" ORANGE" */
line_1190:;
    printf("%s", " ORANGE"); printf("\n");
    /* BASIC: 1200 GOTO 450 */
line_1200:;
    goto line_450;
    /* BASIC: 1210 PRINT" LEMON" */
line_1210:;
    printf("%s", " LEMON"); printf("\n");
    /* BASIC: 1220 GOTO 450 */
line_1220:;
    goto line_450;
    /* BASIC: 1230 PRINT" PLUM" */
line_1230:;
    printf("%s", " PLUM"); printf("\n");
    /* BASIC: 1240 GOTO 450 */
line_1240:;
    goto line_450;
    /* BASIC: 1250 PRINT" CHERRY" */
line_1250:;
    printf("%s", " CHERRY"); printf("\n");
    /* BASIC: 1260 GOTO 450 */
line_1260:;
    goto line_450;
    /* BASIC: 1270 FOR Q4=1 TO 10 */
line_1270:;
    Q4 = 1; for_loop_Q4_1270: if (((1) >= 0 && Q4 > (10)) || ((1) < 0 && Q4 < (10))) goto end_for_Q4_1270;
    /* BASIC: 1280 PRINT CHR$(7); */
line_1280:;
    printf("%s", basic_CHR(7));
    /* BASIC: 1290 NEXT Q4 */
line_1290:;
    Q4 += (1); goto for_loop_Q4_1270; end_for_Q4_1270:;
    /* BASIC: 1300 RETURN */
line_1300:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1310 FOR T8=1 TO 5 */
line_1310:;
    T8 = 1; for_loop_T8_1310: if (((1) >= 0 && T8 > (5)) || ((1) < 0 && T8 < (5))) goto end_for_T8_1310;
    /* BASIC: 1320 PRINT CHR$(7); */
line_1320:;
    printf("%s", basic_CHR(7));
    /* BASIC: 1330 NEXT T8 */
line_1330:;
    T8 += (1); goto for_loop_T8_1310; end_for_T8_1310:;
    /* BASIC: 1340 RETURN */
line_1340:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1341 PRINT: PRINT "DOUBLE!!" */
line_1341:;
    printf("\n");
    printf("%s", "DOUBLE!!"); printf("\n");
    /* BASIC: 1342 PRINT"YOU WON!" */
line_1342:;
    printf("%s", "YOU WON!"); printf("\n");
    /* BASIC: 1343 P=(((2*M)+M)+P) */
line_1343:;
    P = (((2*M)+M)+P);
    /* BASIC: 1344 GOTO 510 */
line_1344:;
    goto line_510;
    /* BASIC: 1350 S TO P */
line_1350:;
    /* UNTRANSLATED: S TO P */
    /* BASIC: 9999 END */
line_9999:;
    exit(0);

    return 0;
}
