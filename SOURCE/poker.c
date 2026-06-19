/*
 * Transpiled from poker.bas
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
static double A, B, C, D, DEF, G, I, K, LET, M, N, O, P, Q, S, T, U, V, X, Z;
static char H_str[256] = {0};
static char I_str[256] = {0};
static char J_str[256] = {0};
static char K_str[256] = {0};
static double A_arr[20000] = {0};
static double B_arr[20000] = {0};
static char _input_buf[256];

/* User-defined functions forward declarations */
static double FNA(double X);
static double FNB(double X);

/* User-defined functions definitions */
static double FNA(double X) {
    return floor(10*((double)rand() / (double)RAND_MAX));
}

static double FNB(double X) {
    return X-100*floor(X/100);
}

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 2 PRINT TAB(33);"POKER" */
line_2:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "POKER"); printf("\n");
    /* BASIC: 4 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 6 PRINT: PRINT: PRINT */
line_6:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 10 DIM A(50),B(15) */
line_10:;
    /* DIM A(50),B(15) (handled statically) */
    /* BASIC: 20 DEF FNA(X)=INT(10*RND(1)) */
line_20:;
    /* UNTRANSLATED: DEF FNA(X)=INT(10*RND(1)) */
    /* BASIC: 30 DEF FNB(X)=X-100*INT(X/100) */
line_30:;
    /* UNTRANSLATED: DEF FNB(X)=X-100*INT(X/100) */
    /* BASIC: 40 PRINT "WELCOME TO THE CASINO.  WE EACH HAVE $200." */
line_40:;
    printf("%s", "WELCOME TO THE CASINO.  WE EACH HAVE $200."); printf("\n");
    /* BASIC: 50 PRINT "I WILL OPEN THE BETTING BEFORE THE DRAW; YOU OPEN AFTER." */
line_50:;
    printf("%s", "I WILL OPEN THE BETTING BEFORE THE DRAW; YOU OPEN AFTER."); printf("\n");
    /* BASIC: 60 PRINT "TO FOLD BET 0; TO CHECK BET .5." */
line_60:;
    printf("%s", "TO FOLD BET 0; TO CHECK BET .5."); printf("\n");
    /* BASIC: 70 PRINT "ENOUGH TALK -- LET'S GET DOWN TO BUSINESS." */
line_70:;
    printf("%s", "ENOUGH TALK -- LET'S GET DOWN TO BUSINESS."); printf("\n");
    /* BASIC: 80 PRINT */
line_80:;
    printf("\n");
    /* BASIC: 90 LET O=1 */
line_90:;
    /* UNTRANSLATED: LET O=1 */
    /* BASIC: 100 LET C=200 */
line_100:;
    /* UNTRANSLATED: LET C=200 */
    /* BASIC: 110 LET S=200 */
line_110:;
    /* UNTRANSLATED: LET S=200 */
    /* BASIC: 120 LET P=0 */
line_120:;
    /* UNTRANSLATED: LET P=0 */
    /* BASIC: 130 REM */
line_130:;
    // REM
    /* BASIC: 140 PRINT */
line_140:;
    printf("\n");
    /* BASIC: 150 IF C<=5 THEN 3670 */
line_150:;
    if (C<=5) { goto line_3670; }
    /* BASIC: 160 PRINT "THE ANTE IS $5.  I WILL DEAL:" */
line_160:;
    printf("%s", "THE ANTE IS $5.  I WILL DEAL:"); printf("\n");
    /* BASIC: 170 PRINT */
line_170:;
    printf("\n");
    /* BASIC: 180 IF S>5 THEN 200 */
line_180:;
    if (S>5) { goto line_200; }
    /* BASIC: 190 GOSUB 3830 */
line_190:;
    gosub_stack[gosub_sp++] = 1; goto line_3830; line_ret_1:;
    /* BASIC: 200 LET P=P+10 */
line_200:;
    /* UNTRANSLATED: LET P=P+10 */
    /* BASIC: 210 LET S=S-5 */
line_210:;
    /* UNTRANSLATED: LET S=S-5 */
    /* BASIC: 220 LET C=C-5 */
line_220:;
    /* UNTRANSLATED: LET C=C-5 */
    /* BASIC: 230 FOR Z=1 TO 10 */
line_230:;
    Z = 1; for_loop_Z_230: if (((1) >= 0 && Z > (10)) || ((1) < 0 && Z < (10))) goto end_for_Z_230;
    /* BASIC: 240 GOSUB 1740 */
line_240:;
    gosub_stack[gosub_sp++] = 2; goto line_1740; line_ret_2:;
    /* BASIC: 250 NEXT Z */
line_250:;
    Z += (1); goto for_loop_Z_230; end_for_Z_230:;
    /* BASIC: 260 PRINT "YOUR HAND:" */
line_260:;
    printf("%s", "YOUR HAND:"); printf("\n");
    /* BASIC: 270 N=1 */
line_270:;
    N = 1;
    /* BASIC: 280 GOSUB 1850 */
line_280:;
    gosub_stack[gosub_sp++] = 3; goto line_1850; line_ret_3:;
    /* BASIC: 290 N=6 */
line_290:;
    N = 6;
    /* BASIC: 300 I=2 */
line_300:;
    I = 2;
    /* BASIC: 310 GOSUB 2170 */
line_310:;
    gosub_stack[gosub_sp++] = 4; goto line_2170; line_ret_4:;
    /* BASIC: 320 PRINT */
line_320:;
    printf("\n");
    /* BASIC: 330 IF I<>6 THEN 470 */
line_330:;
    if (I!=6) { goto line_470; }
    /* BASIC: 340 IF FNA(0)<=7 THEN 370 */
line_340:;
    if (FNA(0)<=7) { goto line_370; }
    /* BASIC: 350 LET X=11100 */
line_350:;
    /* UNTRANSLATED: LET X=11100 */
    /* BASIC: 360 GOTO 420 */
line_360:;
    goto line_420;
    /* BASIC: 370 IF FNA(0)<=7 THEN 400 */
line_370:;
    if (FNA(0)<=7) { goto line_400; }
    /* BASIC: 380 LET X=11110 */
line_380:;
    /* UNTRANSLATED: LET X=11110 */
    /* BASIC: 390 GOTO 420 */
line_390:;
    goto line_420;
    /* BASIC: 400 IF FNA(0)>=1 THEN 450 */
line_400:;
    if (FNA(0)>=1) { goto line_450; }
    /* BASIC: 410 X=11111 */
line_410:;
    X = 11111;
    /* BASIC: 420 I=7 */
line_420:;
    I = 7;
    /* BASIC: 430 Z=23 */
line_430:;
    Z = 23;
    /* BASIC: 440 GOTO 580 */
line_440:;
    goto line_580;
    /* BASIC: 450 Z=1 */
line_450:;
    Z = 1;
    /* BASIC: 460 GOTO 510 */
line_460:;
    goto line_510;
    /* BASIC: 470 IF U>=13 THEN 540 */
line_470:;
    if (U>=13) { goto line_540; }
    /* BASIC: 480 IF FNA(0)>=2 THEN 500 */
line_480:;
    if (FNA(0)>=2) { goto line_500; }
    /* BASIC: 490 GOTO 420 */
line_490:;
    goto line_420;
    /* BASIC: 500 Z=0 */
line_500:;
    Z = 0;
    /* BASIC: 510 K=0 */
line_510:;
    K = 0;
    /* BASIC: 520 PRINT "I CHECK." */
line_520:;
    printf("%s", "I CHECK."); printf("\n");
    /* BASIC: 530 GOTO 620 */
line_530:;
    goto line_620;
    /* BASIC: 540 IF U<=16 THEN 570 */
line_540:;
    if (U<=16) { goto line_570; }
    /* BASIC: 550 Z=2 */
line_550:;
    Z = 2;
    /* BASIC: 560 IF FNA(0)>=1 THEN 580 */
line_560:;
    if (FNA(0)>=1) { goto line_580; }
    /* BASIC: 570 Z=35 */
line_570:;
    Z = 35;
    /* BASIC: 580 V=Z+FNA(0) */
line_580:;
    V = Z+FNA(0);
    /* BASIC: 590 GOSUB 3480 */
line_590:;
    gosub_stack[gosub_sp++] = 5; goto line_3480; line_ret_5:;
    /* BASIC: 600 PRINT "I'LL OPEN WITH $"V */
line_600:;
    printf("%s", "I'LL OPEN WITH $"); printf("%g ", (double)(V)); printf("\n");
    /* BASIC: 610 K=V */
line_610:;
    K = V;
    /* BASIC: 620 GOSUB 3050 */
line_620:;
    gosub_stack[gosub_sp++] = 6; goto line_3050; line_ret_6:;
    /* BASIC: 630 GOSUB 650 */
line_630:;
    gosub_stack[gosub_sp++] = 7; goto line_650; line_ret_7:;
    /* BASIC: 640 GOTO 820 */
line_640:;
    goto line_820;
    /* BASIC: 650 IF I<>3 THEN 760 */
line_650:;
    if (I!=3) { goto line_760; }
    /* BASIC: 660 PRINT */
line_660:;
    printf("\n");
    /* BASIC: 670 PRINT "I WIN." */
line_670:;
    printf("%s", "I WIN."); printf("\n");
    /* BASIC: 680 C=C+P */
line_680:;
    C = C+P;
    /* BASIC: 690 PRINT "NOW I HAVE $"C"AND YOU HAVE $"S */
line_690:;
    printf("%s", "NOW I HAVE $"); printf("%g ", (double)(C)); printf("%s", "AND YOU HAVE $"); printf("%g ", (double)(S)); printf("\n");
    /* BASIC: 700 PRINT "DO YOU WISH TO CONTINUE"; */
line_700:;
    printf("%s", "DO YOU WISH TO CONTINUE");
    /* BASIC: 710 INPUT H$ */
line_710:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", H_str);
    /* BASIC: 720 IF H$="YES" THEN 120 */
line_720:;
    if (strcmp(H_str, "YES") == 0) { goto line_120; }
    /* BASIC: 730 IF H$="NO" THEN 4100 */
line_730:;
    if (strcmp(H_str, "NO") == 0) { goto line_4100; }
    /* BASIC: 740 PRINT "ANSWER YES OR NO, PLEASE." */
line_740:;
    printf("%s", "ANSWER YES OR NO, PLEASE."); printf("\n");
    /* BASIC: 750 GOTO 700 */
line_750:;
    goto line_700;
    /* BASIC: 760 IF I<>4 THEN 810 */
line_760:;
    if (I!=4) { goto line_810; }
    /* BASIC: 770 PRINT */
line_770:;
    printf("\n");
    /* BASIC: 780 PRINT "YOU WIN." */
line_780:;
    printf("%s", "YOU WIN."); printf("\n");
    /* BASIC: 790 S=S+P */
line_790:;
    S = S+P;
    /* BASIC: 800 GOTO 690 */
line_800:;
    goto line_690;
    /* BASIC: 810 RETURN */
line_810:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 820 PRINT */
line_820:;
    printf("\n");
    /* BASIC: 830 PRINT "NOW WE DRAW -- HOW MANY CARDS DO YOU WANT"; */
line_830:;
    printf("%s", "NOW WE DRAW -- HOW MANY CARDS DO YOU WANT");
    /* BASIC: 840 INPUT T */
line_840:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &T);
    /* BASIC: 850 IF T=0 THEN 980 */
line_850:;
    if (T==0) { goto line_980; }
    /* BASIC: 860 Z=10 */
line_860:;
    Z = 10;
    /* BASIC: 870 IF T<4 THEN 900 */
line_870:;
    if (T<4) { goto line_900; }
    /* BASIC: 880 PRINT "YOU CAN'T DRAW MORE THAN THREE CARDS." */
line_880:;
    printf("%s", "YOU CAN'T DRAW MORE THAN THREE CARDS."); printf("\n");
    /* BASIC: 890 GOTO 840 */
line_890:;
    goto line_840;
    /* BASIC: 900 PRINT "WHAT ARE THEIR NUMBERS:" */
line_900:;
    printf("%s", "WHAT ARE THEIR NUMBERS:"); printf("\n");
    /* BASIC: 910 FOR Q=1 TO T */
line_910:;
    Q = 1; for_loop_Q_910: if (((1) >= 0 && Q > (T)) || ((1) < 0 && Q < (T))) goto end_for_Q_910;
    /* BASIC: 920 INPUT U */
line_920:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &U);
    /* BASIC: 930 GOSUB 1730 */
line_930:;
    gosub_stack[gosub_sp++] = 8; goto line_1730; line_ret_8:;
    /* BASIC: 940 NEXT Q */
line_940:;
    Q += (1); goto for_loop_Q_910; end_for_Q_910:;
    /* BASIC: 950 PRINT "YOUR NEW HAND:" */
line_950:;
    printf("%s", "YOUR NEW HAND:"); printf("\n");
    /* BASIC: 960 N=1 */
line_960:;
    N = 1;
    /* BASIC: 970 GOSUB 1850 */
line_970:;
    gosub_stack[gosub_sp++] = 9; goto line_1850; line_ret_9:;
    /* BASIC: 980 Z=10+T */
line_980:;
    Z = 10+T;
    /* BASIC: 990 FOR U=6 TO 10 */
line_990:;
    U = 6; for_loop_U_990: if (((1) >= 0 && U > (10)) || ((1) < 0 && U < (10))) goto end_for_U_990;
    /* BASIC: 1000 IF INT(X/10^(U-6))<>10*INT(X/10^(U-5)) THEN 1020 */
line_1000:;
    if (floor(X/pow(10, (U-6)))!=10*floor(X/pow(10, (U-5)))) { goto line_1020; }
    /* BASIC: 1010 GOSUB 1730 */
line_1010:;
    gosub_stack[gosub_sp++] = 10; goto line_1730; line_ret_10:;
    /* BASIC: 1020 NEXT U */
line_1020:;
    U += (1); goto for_loop_U_990; end_for_U_990:;
    /* BASIC: 1030 PRINT */
line_1030:;
    printf("\n");
    /* BASIC: 1040 PRINT "I AM TAKING"Z-10-T"CARD"; */
line_1040:;
    printf("%s", "I AM TAKING"); printf("%g ", (double)(Z-10-T)); printf("%s", "CARD");
    /* BASIC: 1050 IF Z=11+T THEN 1090 */
line_1050:;
    if (Z==11+T) { goto line_1090; }
    /* BASIC: 1060 PRINT "S" */
line_1060:;
    printf("%s", "S"); printf("\n");
    /* BASIC: 1070 PRINT */
line_1070:;
    printf("\n");
    /* BASIC: 1080 GOTO 1100 */
line_1080:;
    goto line_1100;
    /* BASIC: 1090 PRINT */
line_1090:;
    printf("\n");
    /* BASIC: 1100 N=6 */
line_1100:;
    N = 6;
    /* BASIC: 1110 V=I */
line_1110:;
    V = I;
    /* BASIC: 1120 I=1 */
line_1120:;
    I = 1;
    /* BASIC: 1130 GOSUB 2170 */
line_1130:;
    gosub_stack[gosub_sp++] = 11; goto line_2170; line_ret_11:;
    /* BASIC: 1140 B=U */
line_1140:;
    B = U;
    /* BASIC: 1150 M=D */
line_1150:;
    M = D;
    /* BASIC: 1160 IF V<>7 THEN 1190 */
line_1160:;
    if (V!=7) { goto line_1190; }
    /* BASIC: 1170 Z=28 */
line_1170:;
    Z = 28;
    /* BASIC: 1180 GOTO 1330 */
line_1180:;
    goto line_1330;
    /* BASIC: 1190 IF I<>6 THEN 1220 */
line_1190:;
    if (I!=6) { goto line_1220; }
    /* BASIC: 1200 Z=1 */
line_1200:;
    Z = 1;
    /* BASIC: 1210 GOTO 1330 */
line_1210:;
    goto line_1330;
    /* BASIC: 1220 IF U>=13 THEN 1270 */
line_1220:;
    if (U>=13) { goto line_1270; }
    /* BASIC: 1230 Z=2 */
line_1230:;
    Z = 2;
    /* BASIC: 1240 IF FNA(0)<>6 THEN 1260 */
line_1240:;
    if (FNA(0)!=6) { goto line_1260; }
    /* BASIC: 1250 Z=19 */
line_1250:;
    Z = 19;
    /* BASIC: 1260 GOTO 1330 */
line_1260:;
    goto line_1330;
    /* BASIC: 1270 IF U>=16 THEN 1320 */
line_1270:;
    if (U>=16) { goto line_1320; }
    /* BASIC: 1280 Z=19 */
line_1280:;
    Z = 19;
    /* BASIC: 1290 IF FNA(0)<>8 THEN 1310 */
line_1290:;
    if (FNA(0)!=8) { goto line_1310; }
    /* BASIC: 1300 Z=11 */
line_1300:;
    Z = 11;
    /* BASIC: 1310 GOTO 1330 */
line_1310:;
    goto line_1330;
    /* BASIC: 1320 Z=2 */
line_1320:;
    Z = 2;
    /* BASIC: 1330 K=0 */
line_1330:;
    K = 0;
    /* BASIC: 1340 GOSUB 3050 */
line_1340:;
    gosub_stack[gosub_sp++] = 12; goto line_3050; line_ret_12:;
    /* BASIC: 1350 IF T<>.5 THEN 1450 */
line_1350:;
    if (T!=.5) { goto line_1450; }
    /* BASIC: 1360 IF V=7 THEN 1400 */
line_1360:;
    if (V==7) { goto line_1400; }
    /* BASIC: 1370 IF I<>6 THEN 1400 */
line_1370:;
    if (I!=6) { goto line_1400; }
    /* BASIC: 1380 PRINT "I'LL CHECK" */
line_1380:;
    printf("%s", "I'LL CHECK"); printf("\n");
    /* BASIC: 1390 GOTO 1460 */
line_1390:;
    goto line_1460;
    /* BASIC: 1400 V=Z+FNA(0) */
line_1400:;
    V = Z+FNA(0);
    /* BASIC: 1410 GOSUB 3480 */
line_1410:;
    gosub_stack[gosub_sp++] = 13; goto line_3480; line_ret_13:;
    /* BASIC: 1420 PRINT "I'LL BET $"V */
line_1420:;
    printf("%s", "I'LL BET $"); printf("%g ", (double)(V)); printf("\n");
    /* BASIC: 1430 K=V */
line_1430:;
    K = V;
    /* BASIC: 1440 GOSUB 3060 */
line_1440:;
    gosub_stack[gosub_sp++] = 14; goto line_3060; line_ret_14:;
    /* BASIC: 1450 GOSUB 650 */
line_1450:;
    gosub_stack[gosub_sp++] = 15; goto line_650; line_ret_15:;
    /* BASIC: 1460 PRINT */
line_1460:;
    printf("\n");
    /* BASIC: 1470 PRINT "NOW WE COMPARE HANDS:" */
line_1470:;
    printf("%s", "NOW WE COMPARE HANDS:"); printf("\n");
    /* BASIC: 1480 J$=H$ */
line_1480:;
    str_assign(J_str, sizeof(J_str), H_str);
    /* BASIC: 1490 K$=I$ */
line_1490:;
    str_assign(K_str, sizeof(K_str), I_str);
    /* BASIC: 1500 PRINT "MY HAND:" */
line_1500:;
    printf("%s", "MY HAND:"); printf("\n");
    /* BASIC: 1510 N=6 */
line_1510:;
    N = 6;
    /* BASIC: 1520 GOSUB 1850 */
line_1520:;
    gosub_stack[gosub_sp++] = 16; goto line_1850; line_ret_16:;
    /* BASIC: 1530 N=1 */
line_1530:;
    N = 1;
    /* BASIC: 1540 GOSUB 2170 */
line_1540:;
    gosub_stack[gosub_sp++] = 17; goto line_2170; line_ret_17:;
    /* BASIC: 1550 PRINT */
line_1550:;
    printf("\n");
    /* BASIC: 1560 PRINT "YOU HAVE "; */
line_1560:;
    printf("%s", "YOU HAVE ");
    /* BASIC: 1570 K=D */
line_1570:;
    K = D;
    /* BASIC: 1580 GOSUB 3690 */
line_1580:;
    gosub_stack[gosub_sp++] = 18; goto line_3690; line_ret_18:;
    /* BASIC: 1590 H$=J$ */
line_1590:;
    str_assign(H_str, sizeof(H_str), J_str);
    /* BASIC: 1600 I$=K$ */
line_1600:;
    str_assign(I_str, sizeof(I_str), K_str);
    /* BASIC: 1610 K=M */
line_1610:;
    K = M;
    /* BASIC: 1620 PRINT "AND I HAVE "; */
line_1620:;
    printf("%s", "AND I HAVE ");
    /* BASIC: 1630 GOSUB 3690 */
line_1630:;
    gosub_stack[gosub_sp++] = 19; goto line_3690; line_ret_19:;
    /* BASIC: 1640 IF B>U THEN 670 */
line_1640:;
    if (B>U) { goto line_670; }
    /* BASIC: 1650 IF U>B THEN 780 */
line_1650:;
    if (U>B) { goto line_780; }
    /* BASIC: 1660 IF H$="A FLUS" THEN 1700 */
line_1660:;
    if (strcmp(H_str, "A FLUS") == 0) { goto line_1700; }
    /* BASIC: 1662 IF FNB(M)<FNB(D) THEN 780 */
line_1662:;
    if (FNB(M)<FNB(D)) { goto line_780; }
    /* BASIC: 1664 IF FNB(M)>FNB(D) THEN 670 */
line_1664:;
    if (FNB(M)>FNB(D)) { goto line_670; }
    /* BASIC: 1670 PRINT "THE HAND IS DRAWN." */
line_1670:;
    printf("%s", "THE HAND IS DRAWN."); printf("\n");
    /* BASIC: 1680 PRINT "ALL $"P"REMAINS IN THE POT." */
line_1680:;
    printf("%s", "ALL $"); printf("%g ", (double)(P)); printf("%s", "REMAINS IN THE POT."); printf("\n");
    /* BASIC: 1690 GOTO 140 */
line_1690:;
    goto line_140;
    /* BASIC: 1700 IF FNB(M)>FNB(D) THEN 670 */
line_1700:;
    if (FNB(M)>FNB(D)) { goto line_670; }
    /* BASIC: 1710 IF FNB(D)>FNB(M) THEN 780 */
line_1710:;
    if (FNB(D)>FNB(M)) { goto line_780; }
    /* BASIC: 1720 GOTO 1670 */
line_1720:;
    goto line_1670;
    /* BASIC: 1730 Z=Z+1 */
line_1730:;
    Z = Z+1;
    /* BASIC: 1740 A(Z)=100*INT(4*RND(1))+INT(100*RND(1)) */
line_1740:;
    A_arr[(int)(Z)] = 100*floor(4*((double)rand() / (double)RAND_MAX))+floor(100*((double)rand() / (double)RAND_MAX));
    /* BASIC: 1750 IF INT(A(Z)/100)>3 THEN 1740 */
line_1750:;
    if (floor(A_arr[(int)(Z)]/100)>3) { goto line_1740; }
    /* BASIC: 1760 IF A(Z)-100*INT(A(Z)/100)>12 THEN 1740 */
line_1760:;
    if (A_arr[(int)(Z)]-100*floor(A_arr[(int)(Z)]/100)>12) { goto line_1740; }
    /* BASIC: 1765 IF Z=1 THEN 1840 */
line_1765:;
    if (Z==1) { goto line_1840; }
    /* BASIC: 1770 FOR K=1 TO Z-1 */
line_1770:;
    K = 1; for_loop_K_1770: if (((1) >= 0 && K > (Z-1)) || ((1) < 0 && K < (Z-1))) goto end_for_K_1770;
    /* BASIC: 1780 IF A(Z)=A(K) THEN 1740 */
line_1780:;
    if (A_arr[(int)(Z)]==A_arr[(int)(K)]) { goto line_1740; }
    /* BASIC: 1790 NEXT K */
line_1790:;
    K += (1); goto for_loop_K_1770; end_for_K_1770:;
    /* BASIC: 1800 IF Z<=10 THEN 1840 */
line_1800:;
    if (Z<=10) { goto line_1840; }
    /* BASIC: 1810 N=A(U) */
line_1810:;
    N = A_arr[(int)(U)];
    /* BASIC: 1820 A(U)=A(Z) */
line_1820:;
    A_arr[(int)(U)] = A_arr[(int)(Z)];
    /* BASIC: 1830 A(Z)=N */
line_1830:;
    A_arr[(int)(Z)] = N;
    /* BASIC: 1840 RETURN */
line_1840:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1850 FOR Z=N TO N+4 */
line_1850:;
    Z = N; for_loop_Z_1850: if (((1) >= 0 && Z > (N+4)) || ((1) < 0 && Z < (N+4))) goto end_for_Z_1850;
    /* BASIC: 1860 PRINT Z"--  "; */
line_1860:;
    printf("%g ", (double)(Z)); printf("%s", "--  ");
    /* BASIC: 1870 GOSUB 1950 */
line_1870:;
    gosub_stack[gosub_sp++] = 20; goto line_1950; line_ret_20:;
    /* BASIC: 1880 PRINT " OF"; */
line_1880:;
    printf("%s", " OF");
    /* BASIC: 1890 GOSUB 2070 */
line_1890:;
    gosub_stack[gosub_sp++] = 21; goto line_2070; line_ret_21:;
    /* BASIC: 1900 IF Z/2<>INT(Z/2) THEN 1920 */
line_1900:;
    if (Z/2!=floor(Z/2)) { goto line_1920; }
    /* BASIC: 1910 PRINT */
line_1910:;
    printf("\n");
    /* BASIC: 1920 NEXT Z */
line_1920:;
    Z += (1); goto for_loop_Z_1850; end_for_Z_1850:;
    /* BASIC: 1930 PRINT */
line_1930:;
    printf("\n");
    /* BASIC: 1940 RETURN */
line_1940:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1950 K=FNB(A(Z)) */
line_1950:;
    K = FNB(A_arr[(int)(Z)]);
    /* BASIC: 1960 IF K<>9 THEN 1980 */
line_1960:;
    if (K!=9) { goto line_1980; }
    /* BASIC: 1970 PRINT "JACK"; */
line_1970:;
    printf("%s", "JACK");
    /* BASIC: 1980 IF K<>10 THEN 2000 */
line_1980:;
    if (K!=10) { goto line_2000; }
    /* BASIC: 1990 PRINT "QUEEN"; */
line_1990:;
    printf("%s", "QUEEN");
    /* BASIC: 2000 IF K<>11 THEN 2020 */
line_2000:;
    if (K!=11) { goto line_2020; }
    /* BASIC: 2010 PRINT "KING"; */
line_2010:;
    printf("%s", "KING");
    /* BASIC: 2020 IF K<>12 THEN 2040 */
line_2020:;
    if (K!=12) { goto line_2040; }
    /* BASIC: 2030 PRINT "ACE"; */
line_2030:;
    printf("%s", "ACE");
    /* BASIC: 2040 IF K>=9 THEN 2060 */
line_2040:;
    if (K>=9) { goto line_2060; }
    /* BASIC: 2050 PRINT K+2; */
line_2050:;
    printf("%g ", (double)(K+2));
    /* BASIC: 2060 RETURN */
line_2060:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 2070 K=INT(A(Z)/100) */
line_2070:;
    K = floor(A_arr[(int)(Z)]/100);
    /* BASIC: 2080 IF K<>0 THEN 2100 */
line_2080:;
    if (K!=0) { goto line_2100; }
    /* BASIC: 2090 PRINT " CLUBS", */
line_2090:;
    printf("%s", " CLUBS"); printf("\t");
    /* BASIC: 2100 IF K<>1 THEN 2120 */
line_2100:;
    if (K!=1) { goto line_2120; }
    /* BASIC: 2110 PRINT " DIAMONDS", */
line_2110:;
    printf("%s", " DIAMONDS"); printf("\t");
    /* BASIC: 2120 IF K<>2 THEN 2140 */
line_2120:;
    if (K!=2) { goto line_2140; }
    /* BASIC: 2130 PRINT " HEARTS", */
line_2130:;
    printf("%s", " HEARTS"); printf("\t");
    /* BASIC: 2140 IF K<>3 THEN 2160 */
line_2140:;
    if (K!=3) { goto line_2160; }
    /* BASIC: 2150 PRINT " SPADES", */
line_2150:;
    printf("%s", " SPADES"); printf("\t");
    /* BASIC: 2160 RETURN */
line_2160:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 2170 U=0 */
line_2170:;
    U = 0;
    /* BASIC: 2180 FOR Z=N TO N+4 */
line_2180:;
    Z = N; for_loop_Z_2180: if (((1) >= 0 && Z > (N+4)) || ((1) < 0 && Z < (N+4))) goto end_for_Z_2180;
    /* BASIC: 2190 B(Z)=FNB(A(Z)) */
line_2190:;
    B_arr[(int)(Z)] = FNB(A_arr[(int)(Z)]);
    /* BASIC: 2200 IF Z=N+4 THEN 2230 */
line_2200:;
    if (Z==N+4) { goto line_2230; }
    /* BASIC: 2210 IF INT(A(Z)/100)<>INT(A(Z+1)/100) THEN 2230 */
line_2210:;
    if (floor(A_arr[(int)(Z)]/100)!=floor(A_arr[(int)(Z+1)]/100)) { goto line_2230; }
    /* BASIC: 2220 U=U+1 */
line_2220:;
    U = U+1;
    /* BASIC: 2230 NEXT Z */
line_2230:;
    Z += (1); goto for_loop_Z_2180; end_for_Z_2180:;
    /* BASIC: 2240 IF U<>4 THEN 2310 */
line_2240:;
    if (U!=4) { goto line_2310; }
    /* BASIC: 2250 X=11111 */
line_2250:;
    X = 11111;
    /* BASIC: 2260 D=A(N) */
line_2260:;
    D = A_arr[(int)(N)];
    /* BASIC: 2270 H$="A FLUS" */
line_2270:;
    str_assign(H_str, sizeof(H_str), "A FLUS");
    /* BASIC: 2280 I$="H IN" */
line_2280:;
    str_assign(I_str, sizeof(I_str), "H IN");
    /* BASIC: 2290 U=15 */
line_2290:;
    U = 15;
    /* BASIC: 2300 RETURN */
line_2300:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 2310 FOR Z=N TO N+3 */
line_2310:;
    Z = N; for_loop_Z_2310: if (((1) >= 0 && Z > (N+3)) || ((1) < 0 && Z < (N+3))) goto end_for_Z_2310;
    /* BASIC: 2320 FOR K=Z+1 TO N+4 */
line_2320:;
    K = Z+1; for_loop_K_2320: if (((1) >= 0 && K > (N+4)) || ((1) < 0 && K < (N+4))) goto end_for_K_2320;
    /* BASIC: 2330 IF B(Z)<=B(K) THEN 2390 */
line_2330:;
    if (B_arr[(int)(Z)]<=B_arr[(int)(K)]) { goto line_2390; }
    /* BASIC: 2340 X=A(Z) */
line_2340:;
    X = A_arr[(int)(Z)];
    /* BASIC: 2350 A(Z)=A(K) */
line_2350:;
    A_arr[(int)(Z)] = A_arr[(int)(K)];
    /* BASIC: 2360 B(Z)=B(K) */
line_2360:;
    B_arr[(int)(Z)] = B_arr[(int)(K)];
    /* BASIC: 2370 A(K)=X */
line_2370:;
    A_arr[(int)(K)] = X;
    /* BASIC: 2380 B(K)=A(K)-100*INT(A(K)/100) */
line_2380:;
    B_arr[(int)(K)] = A_arr[(int)(K)]-100*floor(A_arr[(int)(K)]/100);
    /* BASIC: 2390 NEXT K */
line_2390:;
    K += (1); goto for_loop_K_2320; end_for_K_2320:;
    /* BASIC: 2400 NEXT Z */
line_2400:;
    Z += (1); goto for_loop_Z_2310; end_for_Z_2310:;
    /* BASIC: 2410 X=0 */
line_2410:;
    X = 0;
    /* BASIC: 2420 FOR Z=N TO N+3 */
line_2420:;
    Z = N; for_loop_Z_2420: if (((1) >= 0 && Z > (N+3)) || ((1) < 0 && Z < (N+3))) goto end_for_Z_2420;
    /* BASIC: 2430 IF B(Z)<>B(Z+1) THEN 2470 */
line_2430:;
    if (B_arr[(int)(Z)]!=B_arr[(int)(Z+1)]) { goto line_2470; }
    /* BASIC: 2440 X=X+11*10^(Z-N) */
line_2440:;
    X = X+11*pow(10, (Z-N));
    /* BASIC: 2450 D=A(Z) */
line_2450:;
    D = A_arr[(int)(Z)];
    /* BASIC: 2460 GOSUB 2760 */
line_2460:;
    gosub_stack[gosub_sp++] = 22; goto line_2760; line_ret_22:;
    /* BASIC: 2470 NEXT Z */
line_2470:;
    Z += (1); goto for_loop_Z_2420; end_for_Z_2420:;
    /* BASIC: 2480 IF X<>0 THEN 2620 */
line_2480:;
    if (X!=0) { goto line_2620; }
    /* BASIC: 2490 IF B(N)+3<>B(N+3) THEN 2520 */
line_2490:;
    if (B_arr[(int)(N)]+3!=B_arr[(int)(N+3)]) { goto line_2520; }
    /* BASIC: 2500 X=1111 */
line_2500:;
    X = 1111;
    /* BASIC: 2510 U=10 */
line_2510:;
    U = 10;
    /* BASIC: 2520 IF B(N+1)+3<>B(N+4) THEN 2620 */
line_2520:;
    if (B_arr[(int)(N+1)]+3!=B_arr[(int)(N+4)]) { goto line_2620; }
    /* BASIC: 2530 IF U<>10 THEN 2600 */
line_2530:;
    if (U!=10) { goto line_2600; }
    /* BASIC: 2540 U=14 */
line_2540:;
    U = 14;
    /* BASIC: 2550 H$="STRAIG" */
line_2550:;
    str_assign(H_str, sizeof(H_str), "STRAIG");
    /* BASIC: 2560 I$="HT" */
line_2560:;
    str_assign(I_str, sizeof(I_str), "HT");
    /* BASIC: 2570 X=11111 */
line_2570:;
    X = 11111;
    /* BASIC: 2580 D=A(N+4) */
line_2580:;
    D = A_arr[(int)(N+4)];
    /* BASIC: 2590 RETURN */
line_2590:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 2600 U=10 */
line_2600:;
    U = 10;
    /* BASIC: 2610 X=11110 */
line_2610:;
    X = 11110;
    /* BASIC: 2620 IF U>=10 THEN 2690 */
line_2620:;
    if (U>=10) { goto line_2690; }
    /* BASIC: 2630 D=A(N+4) */
line_2630:;
    D = A_arr[(int)(N+4)];
    /* BASIC: 2640 H$="SCHMAL" */
line_2640:;
    str_assign(H_str, sizeof(H_str), "SCHMAL");
    /* BASIC: 2650 I$="TZ, " */
line_2650:;
    str_assign(I_str, sizeof(I_str), "TZ, ");
    /* BASIC: 2660 U=9 */
line_2660:;
    U = 9;
    /* BASIC: 2670 X=11000 */
line_2670:;
    X = 11000;
    /* BASIC: 2680 GOTO 2740 */
line_2680:;
    goto line_2740;
    /* BASIC: 2690 IF U<>10 THEN 2720 */
line_2690:;
    if (U!=10) { goto line_2720; }
    /* BASIC: 2700 IF I=1 THEN 2740 */
line_2700:;
    if (I==1) { goto line_2740; }
    /* BASIC: 2710 GOTO 2750 */
line_2710:;
    goto line_2750;
    /* BASIC: 2720 IF U>12 THEN 2750 */
line_2720:;
    if (U>12) { goto line_2750; }
    /* BASIC: 2730 IF FNB(D)>6 THEN 2750 */
line_2730:;
    if (FNB(D)>6) { goto line_2750; }
    /* BASIC: 2740 I=6 */
line_2740:;
    I = 6;
    /* BASIC: 2750 RETURN */
line_2750:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 2760 IF U>=11 THEN 2810 */
line_2760:;
    if (U>=11) { goto line_2810; }
    /* BASIC: 2770 U=11 */
line_2770:;
    U = 11;
    /* BASIC: 2780 H$="A PAIR" */
line_2780:;
    str_assign(H_str, sizeof(H_str), "A PAIR");
    /* BASIC: 2790 I$=" OF " */
line_2790:;
    str_assign(I_str, sizeof(I_str), " OF ");
    /* BASIC: 2800 RETURN */
line_2800:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 2810 IF U<>11 THEN 2910 */
line_2810:;
    if (U!=11) { goto line_2910; }
    /* BASIC: 2820 IF B(Z)<>B(Z-1) THEN 2870 */
line_2820:;
    if (B_arr[(int)(Z)]!=B_arr[(int)(Z-1)]) { goto line_2870; }
    /* BASIC: 2830 H$="THREE" */
line_2830:;
    str_assign(H_str, sizeof(H_str), "THREE");
    /* BASIC: 2840 I$=" " */
line_2840:;
    str_assign(I_str, sizeof(I_str), " ");
    /* BASIC: 2850 U=13 */
line_2850:;
    U = 13;
    /* BASIC: 2860 RETURN */
line_2860:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 2870 H$="TWO P" */
line_2870:;
    str_assign(H_str, sizeof(H_str), "TWO P");
    /* BASIC: 2880 I$="AIR, " */
line_2880:;
    str_assign(I_str, sizeof(I_str), "AIR, ");
    /* BASIC: 2890 U=12 */
line_2890:;
    U = 12;
    /* BASIC: 2900 RETURN */
line_2900:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 2910 IF U>12 THEN 2960 */
line_2910:;
    if (U>12) { goto line_2960; }
    /* BASIC: 2920 U=16 */
line_2920:;
    U = 16;
    /* BASIC: 2930 H$="FULL H" */
line_2930:;
    str_assign(H_str, sizeof(H_str), "FULL H");
    /* BASIC: 2940 I$="OUSE, " */
line_2940:;
    str_assign(I_str, sizeof(I_str), "OUSE, ");
    /* BASIC: 2950 RETURN */
line_2950:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 2960 IF B(Z)<>B(Z-1) THEN 3010 */
line_2960:;
    if (B_arr[(int)(Z)]!=B_arr[(int)(Z-1)]) { goto line_3010; }
    /* BASIC: 2970 U=17 */
line_2970:;
    U = 17;
    /* BASIC: 2980 H$="FOUR" */
line_2980:;
    str_assign(H_str, sizeof(H_str), "FOUR");
    /* BASIC: 2990 I$=" " */
line_2990:;
    str_assign(I_str, sizeof(I_str), " ");
    /* BASIC: 3000 RETURN */
line_3000:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 3010 U=16 */
line_3010:;
    U = 16;
    /* BASIC: 3020 H$="FULL H" */
line_3020:;
    str_assign(H_str, sizeof(H_str), "FULL H");
    /* BASIC: 3030 I$="OUSE, " */
line_3030:;
    str_assign(I_str, sizeof(I_str), "OUSE, ");
    /* BASIC: 3040 RETURN */
line_3040:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 3050 G=0 */
line_3050:;
    G = 0;
    /* BASIC: 3060 PRINT:PRINT "WHAT IS YOUR BET"; */
line_3060:;
    printf("\n");
    printf("%s", "WHAT IS YOUR BET");
    /* BASIC: 3070 INPUT T */
line_3070:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &T);
    /* BASIC: 3080 IF T-INT(T)=0 THEN 3140 */
line_3080:;
    if (T-floor(T)==0) { goto line_3140; }
    /* BASIC: 3090 IF K<>0 THEN 3120 */
line_3090:;
    if (K!=0) { goto line_3120; }
    /* BASIC: 3100 IF G<>0 THEN 3120 */
line_3100:;
    if (G!=0) { goto line_3120; }
    /* BASIC: 3110 IF T=.5 THEN 3410 */
line_3110:;
    if (T==.5) { goto line_3410; }
    /* BASIC: 3120 PRINT "NO SMALL CHANGE, PLEASE." */
line_3120:;
    printf("%s", "NO SMALL CHANGE, PLEASE."); printf("\n");
    /* BASIC: 3130 GOTO 3060 */
line_3130:;
    goto line_3060;
    /* BASIC: 3140 IF S-G-T>=0 THEN 3170 */
line_3140:;
    if (S-G-T>=0) { goto line_3170; }
    /* BASIC: 3150 GOSUB 3830 */
line_3150:;
    gosub_stack[gosub_sp++] = 23; goto line_3830; line_ret_23:;
    /* BASIC: 3160 GOTO 3060 */
line_3160:;
    goto line_3060;
    /* BASIC: 3170 IF T<>0 THEN 3200 */
line_3170:;
    if (T!=0) { goto line_3200; }
    /* BASIC: 3180 I=3 */
line_3180:;
    I = 3;
    /* BASIC: 3190 GOTO 3380 */
line_3190:;
    goto line_3380;
    /* BASIC: 3200 IF G+T>=K THEN 3230 */
line_3200:;
    if (G+T>=K) { goto line_3230; }
    /* BASIC: 3210 PRINT "IF YOU CAN'T SEE MY BET, THEN FOLD." */
line_3210:;
    printf("%s", "IF YOU CAN'T SEE MY BET, THEN FOLD."); printf("\n");
    /* BASIC: 3220 GOTO 3060 */
line_3220:;
    goto line_3060;
    /* BASIC: 3230 G=G+T */
line_3230:;
    G = G+T;
    /* BASIC: 3240 IF G=K THEN 3380 */
line_3240:;
    if (G==K) { goto line_3380; }
    /* BASIC: 3250 IF Z<>1 THEN 3420 */
line_3250:;
    if (Z!=1) { goto line_3420; }
    /* BASIC: 3260 IF G>5 THEN 3300 */
line_3260:;
    if (G>5) { goto line_3300; }
    /* BASIC: 3270 IF Z>=2 THEN 3350 */
line_3270:;
    if (Z>=2) { goto line_3350; }
    /* BASIC: 3280 V=5 */
line_3280:;
    V = 5;
    /* BASIC: 3290 GOTO 3420 */
line_3290:;
    goto line_3420;
    /* BASIC: 3300 IF Z=1 THEN 3320 */
line_3300:;
    if (Z==1) { goto line_3320; }
    /* BASIC: 3310 IF T<=25 THEN 3350 */
line_3310:;
    if (T<=25) { goto line_3350; }
    /* BASIC: 3320 I=4 */
line_3320:;
    I = 4;
    /* BASIC: 3330 PRINT "I FOLD." */
line_3330:;
    printf("%s", "I FOLD."); printf("\n");
    /* BASIC: 3340 RETURN */
line_3340:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 3350 IF Z=2 THEN 3430 */
line_3350:;
    if (Z==2) { goto line_3430; }
    /* BASIC: 3360 PRINT "I'LL SEE YOU." */
line_3360:;
    printf("%s", "I'LL SEE YOU."); printf("\n");
    /* BASIC: 3370 K=G */
line_3370:;
    K = G;
    /* BASIC: 3380 S=S-G */
line_3380:;
    S = S-G;
    /* BASIC: 3390 C=C-K */
line_3390:;
    C = C-K;
    /* BASIC: 3400 P=P+G+K */
line_3400:;
    P = P+G+K;
    /* BASIC: 3410 RETURN */
line_3410:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 3420 IF G>3*Z THEN 3350 */
line_3420:;
    if (G>3*Z) { goto line_3350; }
    /* BASIC: 3430 V=G-K+FNA(0) */
line_3430:;
    V = G-K+FNA(0);
    /* BASIC: 3440 GOSUB 3480 */
line_3440:;
    gosub_stack[gosub_sp++] = 24; goto line_3480; line_ret_24:;
    /* BASIC: 3450 PRINT "I'LL SEE YOU, AND RAISE YOU"V */
line_3450:;
    printf("%s", "I'LL SEE YOU, AND RAISE YOU"); printf("%g ", (double)(V)); printf("\n");
    /* BASIC: 3460 K=G+V */
line_3460:;
    K = G+V;
    /* BASIC: 3470 GOTO 3060 */
line_3470:;
    goto line_3060;
    /* BASIC: 3480 IF C-G-V>=0 THEN 3660 */
line_3480:;
    if (C-G-V>=0) { goto line_3660; }
    /* BASIC: 3490 IF G<>0 THEN 3520 */
line_3490:;
    if (G!=0) { goto line_3520; }
    /* BASIC: 3500 V=C */
line_3500:;
    V = C;
    /* BASIC: 3510 RETURN */
line_3510:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 3520 IF C-G>=0 THEN 3360 */
line_3520:;
    if (C-G>=0) { goto line_3360; }
    /* BASIC: 3530 IF (O/2)<>INT(O/2) THEN 3600 */
line_3530:;
    if ((O/2)!=floor(O/2)) { goto line_3600; }
    /* BASIC: 3540 PRINT "WOULD YOU LIKE TO BUY BACK YOUR WATCH FOR $50"; */
line_3540:;
    printf("%s", "WOULD YOU LIKE TO BUY BACK YOUR WATCH FOR $50");
    /* BASIC: 3550 INPUT J$ */
line_3550:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", J_str);
    /* BASIC: 3560 IF LEFT$(J$,1)="N" THEN 3600 */
line_3560:;
    if (strcmp(basic_LEFT(J_str,1), "N") == 0) { goto line_3600; }
    /* BASIC: 3570 C=C+50 */
line_3570:;
    C = C+50;
    /* BASIC: 3580 O=O/2 */
line_3580:;
    O = O/2;
    /* BASIC: 3590 RETURN */
line_3590:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 3600 IF O/3<>INT(O/3) THEN 3670 */
line_3600:;
    if (O/3!=floor(O/3)) { goto line_3670; }
    /* BASIC: 3610 PRINT "WOULD YOU LIKE TO BUY BACK YOUR TIE TACK FOR $50"; */
line_3610:;
    printf("%s", "WOULD YOU LIKE TO BUY BACK YOUR TIE TACK FOR $50");
    /* BASIC: 3620 INPUT J$ */
line_3620:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", J_str);
    /* BASIC: 3630 IF LEFT$(J$,1)="N" THEN 3670 */
line_3630:;
    if (strcmp(basic_LEFT(J_str,1), "N") == 0) { goto line_3670; }
    /* BASIC: 3640 C=C+50 */
line_3640:;
    C = C+50;
    /* BASIC: 3650 O=O/3 */
line_3650:;
    O = O/3;
    /* BASIC: 3660 RETURN */
line_3660:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 3670 PRINT "I'M BUSTED.  CONGRATULATIONS!" */
line_3670:;
    printf("%s", "I'M BUSTED.  CONGRATULATIONS!"); printf("\n");
    /* BASIC: 3680 S TO P */
line_3680:;
    /* UNTRANSLATED: S TO P */
    /* BASIC: 3690 PRINT H$;I$; */
line_3690:;
    printf("%s", H_str); printf("%s", I_str);
    /* BASIC: 3700 IF H$<>"A FLUS" THEN 3750 */
line_3700:;
    if (strcmp(H_str, "A FLUS") != 0) { goto line_3750; }
    /* BASIC: 3710 K=INT(K/100) */
line_3710:;
    K = floor(K/100);
    /* BASIC: 3720 GOSUB 2080 */
line_3720:;
    gosub_stack[gosub_sp++] = 25; goto line_2080; line_ret_25:;
    /* BASIC: 3730 PRINT */
line_3730:;
    printf("\n");
    /* BASIC: 3740 RETURN */
line_3740:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 3750 K=FNB(K) */
line_3750:;
    K = FNB(K);
    /* BASIC: 3760 GOSUB 1960 */
line_3760:;
    gosub_stack[gosub_sp++] = 26; goto line_1960; line_ret_26:;
    /* BASIC: 3770 IF H$="SCHMAL" THEN 3790 */
line_3770:;
    if (strcmp(H_str, "SCHMAL") == 0) { goto line_3790; }
    /* BASIC: 3780 IF H$<>"STRAIG" THEN 3810 */
line_3780:;
    if (strcmp(H_str, "STRAIG") != 0) { goto line_3810; }
    /* BASIC: 3790 PRINT " HIGH" */
line_3790:;
    printf("%s", " HIGH"); printf("\n");
    /* BASIC: 3800 RETURN */
line_3800:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 3810 PRINT "'S" */
line_3810:;
    printf("%s", "'S"); printf("\n");
    /* BASIC: 3820 RETURN */
line_3820:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 3830 PRINT */
line_3830:;
    printf("\n");
    /* BASIC: 3840 PRINT "YOU CAN'T BET WITH WHAT YOU HAVEN'T GOT." */
line_3840:;
    printf("%s", "YOU CAN'T BET WITH WHAT YOU HAVEN'T GOT."); printf("\n");
    /* BASIC: 3850 IF O/2=INT(O/2) THEN 3970 */
line_3850:;
    if (O/2==floor(O/2)) { goto line_3970; }
    /* BASIC: 3860 PRINT "WOULD YOU LIKE TO SELL YOUR WATCH"; */
line_3860:;
    printf("%s", "WOULD YOU LIKE TO SELL YOUR WATCH");
    /* BASIC: 3870 INPUT J$ */
line_3870:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", J_str);
    /* BASIC: 3880 IF LEFT$(J$,1)="N" THEN 3970 */
line_3880:;
    if (strcmp(basic_LEFT(J_str,1), "N") == 0) { goto line_3970; }
    /* BASIC: 3890 IF FNA(0)>=7 THEN 3930 */
line_3890:;
    if (FNA(0)>=7) { goto line_3930; }
    /* BASIC: 3900 PRINT "I'LL GIVE YOU $75 FOR IT." */
line_3900:;
    printf("%s", "I'LL GIVE YOU $75 FOR IT."); printf("\n");
    /* BASIC: 3910 S=S+75 */
line_3910:;
    S = S+75;
    /* BASIC: 3920 GOTO 3950 */
line_3920:;
    goto line_3950;
    /* BASIC: 3930 PRINT "THAT'S A PRETTY CRUMMY WATCH - I'LL GIVE YOU $25." */
line_3930:;
    printf("%s", "THAT'S A PRETTY CRUMMY WATCH - I'LL GIVE YOU $25."); printf("\n");
    /* BASIC: 3940 S=S+25 */
line_3940:;
    S = S+25;
    /* BASIC: 3950 O=O*2 */
line_3950:;
    O = O*2;
    /* BASIC: 3960 RETURN */
line_3960:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 3970 IF O/3<>INT(O/3) THEN 4090 */
line_3970:;
    if (O/3!=floor(O/3)) { goto line_4090; }
    /* BASIC: 3980 PRINT "WILL YOU PART WITH THAT DIAMOND TIE TACK": */
line_3980:;
    printf("%s", "WILL YOU PART WITH THAT DIAMOND TIE TACK"); printf("\n");
    /* BASIC: 3990 INPUT J$ */
line_3990:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", J_str);
    /* BASIC: 4000 IF LEFT$(J$,1)="N" THEN 4080 */
line_4000:;
    if (strcmp(basic_LEFT(J_str,1), "N") == 0) { goto line_4080; }
    /* BASIC: 4010 IF FNA(0)>=6 THEN 4050 */
line_4010:;
    if (FNA(0)>=6) { goto line_4050; }
    /* BASIC: 4020 PRINT "YOU ARE NOW $100 RICHER." */
line_4020:;
    printf("%s", "YOU ARE NOW $100 RICHER."); printf("\n");
    /* BASIC: 4030 S=S+100 */
line_4030:;
    S = S+100;
    /* BASIC: 4040 GOTO 4070 */
line_4040:;
    goto line_4070;
    /* BASIC: 4050 PRINT "IT'S PASTE.  $25." */
line_4050:;
    printf("%s", "IT'S PASTE.  $25."); printf("\n");
    /* BASIC: 4060 S=S+25 */
line_4060:;
    S = S+25;
    /* BASIC: 4070 O=O*3 */
line_4070:;
    O = O*3;
    /* BASIC: 4080 RETURN */
line_4080:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 4090 PRINT "YOUR WAD IS SHOT.  SO LONG, SUCKER!" */
line_4090:;
    printf("%s", "YOUR WAD IS SHOT.  SO LONG, SUCKER!"); printf("\n");
    /* BASIC: 4100 END */
line_4100:;
    exit(0);

    return 0;
}
