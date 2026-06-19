/*
 * Transpiled from bug.bas
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
static double A, B, C, DELAY, H, L, N, ON, P, Q, R, S, T, U, V, X, Y, Z;
static char Z_str[256] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(34);"BUG" */
line_10:;
    { int _t; for(_t=0; _t<34; _t++) printf(" "); } printf("%s", "BUG"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 40 REM */
line_40:;
    // REM
    /* BASIC: 50 A=0: B=0: H=0: L=0: N=0: P=0: Q=0: R=0: S=0: T=0: U=0: V=0: Y=0 */
line_50:;
    A = 0;
    B = 0;
    H = 0;
    L = 0;
    N = 0;
    P = 0;
    Q = 0;
    R = 0;
    S = 0;
    T = 0;
    U = 0;
    V = 0;
    Y = 0;
    /* BASIC: 60 PRINT "THE GAME BUG" */
line_60:;
    printf("%s", "THE GAME BUG"); printf("\n");
    /* BASIC: 70 PRINT "I HOPE YOU ENJOY THIS GAME." */
line_70:;
    printf("%s", "I HOPE YOU ENJOY THIS GAME."); printf("\n");
    /* BASIC: 80 PRINT */
line_80:;
    printf("\n");
    /* BASIC: 90 PRINT "DO YOU WANT INSTRUCTIONS"; */
line_90:;
    printf("%s", "DO YOU WANT INSTRUCTIONS");
    /* BASIC: 100 INPUT Z$ */
line_100:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", Z_str);
    /* BASIC: 110 IF Z$="NO" THEN 300 */
line_110:;
    if (strcmp(Z_str, "NO") == 0) { goto line_300; }
    /* BASIC: 120 PRINT "THE OBJECT OF BUG IS TO FINISH YOUR BUG BEFORE I FINISH" */
line_120:;
    printf("%s", "THE OBJECT OF BUG IS TO FINISH YOUR BUG BEFORE I FINISH"); printf("\n");
    /* BASIC: 130 PRINT "MINE. EACH NUMBER STANDS FOR A PART OF THE BUG BODY." */
line_130:;
    printf("%s", "MINE. EACH NUMBER STANDS FOR A PART OF THE BUG BODY."); printf("\n");
    /* BASIC: 140 PRINT "I WILL ROLL THE DIE FOR YOU, TELL YOU WHAT I ROLLED FOR YOU" */
line_140:;
    printf("%s", "I WILL ROLL THE DIE FOR YOU, TELL YOU WHAT I ROLLED FOR YOU"); printf("\n");
    /* BASIC: 150 PRINT "WHAT THE NUMBER STANDS FOR, AND IF YOU CAN GET THE PART." */
line_150:;
    printf("%s", "WHAT THE NUMBER STANDS FOR, AND IF YOU CAN GET THE PART."); printf("\n");
    /* BASIC: 160 PRINT "IF YOU CAN GET THE PART I WILL GIVE IT TO YOU." */
line_160:;
    printf("%s", "IF YOU CAN GET THE PART I WILL GIVE IT TO YOU."); printf("\n");
    /* BASIC: 170 PRINT "THE SAME WILL HAPPEN ON MY TURN." */
line_170:;
    printf("%s", "THE SAME WILL HAPPEN ON MY TURN."); printf("\n");
    /* BASIC: 180 PRINT "IF THERE IS A CHANGE IN EITHER BUG I WILL GIVE YOU THE" */
line_180:;
    printf("%s", "IF THERE IS A CHANGE IN EITHER BUG I WILL GIVE YOU THE"); printf("\n");
    /* BASIC: 190 PRINT "OPTION OF SEEING THE PICTURES OF THE BUGS." */
line_190:;
    printf("%s", "OPTION OF SEEING THE PICTURES OF THE BUGS."); printf("\n");
    /* BASIC: 200 PRINT "THE NUMBERS STAND FOR PARTS AS FOLLOWS:" */
line_200:;
    printf("%s", "THE NUMBERS STAND FOR PARTS AS FOLLOWS:"); printf("\n");
    /* BASIC: 210 PRINT "NUMBER","PART","NUMBER OF PART NEEDED" */
line_210:;
    printf("%s", "NUMBER"); printf("\t"); printf("%s", "PART"); printf("\t"); printf("%s", "NUMBER OF PART NEEDED"); printf("\n");
    /* BASIC: 220 PRINT "1","BODY","1" */
line_220:;
    printf("%s", "1"); printf("\t"); printf("%s", "BODY"); printf("\t"); printf("%s", "1"); printf("\n");
    /* BASIC: 230 PRINT "2","NECK","1" */
line_230:;
    printf("%s", "2"); printf("\t"); printf("%s", "NECK"); printf("\t"); printf("%s", "1"); printf("\n");
    /* BASIC: 240 PRINT "3","HEAD","1" */
line_240:;
    printf("%s", "3"); printf("\t"); printf("%s", "HEAD"); printf("\t"); printf("%s", "1"); printf("\n");
    /* BASIC: 250 PRINT "4","FEELERS","2" */
line_250:;
    printf("%s", "4"); printf("\t"); printf("%s", "FEELERS"); printf("\t"); printf("%s", "2"); printf("\n");
    /* BASIC: 260 PRINT "5","TAIL","1" */
line_260:;
    printf("%s", "5"); printf("\t"); printf("%s", "TAIL"); printf("\t"); printf("%s", "1"); printf("\n");
    /* BASIC: 270 PRINT "6","LEGS","6" */
line_270:;
    printf("%s", "6"); printf("\t"); printf("%s", "LEGS"); printf("\t"); printf("%s", "6"); printf("\n");
    /* BASIC: 280 PRINT */
line_280:;
    printf("\n");
    /* BASIC: 290 PRINT */
line_290:;
    printf("\n");
    /* BASIC: 300 IF Y>0 THEN 2480 */
line_300:;
    if (Y>0) { goto line_2480; }
    /* BASIC: 310 Z=INT(6*RND(1)+1) */
line_310:;
    Z = floor(6*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 320 C=1 */
line_320:;
    C = 1;
    /* BASIC: 330 PRINT "YOU ROLLED A";Z */
line_330:;
    printf("%s", "YOU ROLLED A"); printf("%g ", (double)(Z)); printf("\n");
    /* BASIC: 340 ON Z GOTO 350,430,540,650,760,870 */
line_340:;
    switch ((int)(Z)) {     case 1: goto line_350;     case 2: goto line_430;     case 3: goto line_540;     case 4: goto line_650;     case 5: goto line_760;     case 6: goto line_870; }
    /* BASIC: 350 PRINT "1=BODY" */
line_350:;
    printf("%s", "1=BODY"); printf("\n");
    /* BASIC: 360 IF B=1 THEN 410 */
line_360:;
    if (B==1) { goto line_410; }
    /* BASIC: 370 PRINT "YOU NOW HAVE A BODY." */
line_370:;
    printf("%s", "YOU NOW HAVE A BODY."); printf("\n");
    /* BASIC: 380 B=1 */
line_380:;
    B = 1;
    /* BASIC: 390 C=0 */
line_390:;
    C = 0;
    /* BASIC: 400 GOTO 970 */
line_400:;
    goto line_970;
    /* BASIC: 410 PRINT "YOU DO NOT NEED A BODY." */
line_410:;
    printf("%s", "YOU DO NOT NEED A BODY."); printf("\n");
    /* BASIC: 420 GOTO 970 */
line_420:;
    goto line_970;
    /* BASIC: 430 PRINT "2=NECK" */
line_430:;
    printf("%s", "2=NECK"); printf("\n");
    /* BASIC: 440 IF N=1 THEN 500 */
line_440:;
    if (N==1) { goto line_500; }
    /* BASIC: 450 IF B=0 THEN 520 */
line_450:;
    if (B==0) { goto line_520; }
    /* BASIC: 460 PRINT "YOU NOW HAVE A NECK." */
line_460:;
    printf("%s", "YOU NOW HAVE A NECK."); printf("\n");
    /* BASIC: 470 N=1 */
line_470:;
    N = 1;
    /* BASIC: 480 C=0 */
line_480:;
    C = 0;
    /* BASIC: 490 GOTO 970 */
line_490:;
    goto line_970;
    /* BASIC: 500 PRINT "YOU DO NOT NEED A NECK." */
line_500:;
    printf("%s", "YOU DO NOT NEED A NECK."); printf("\n");
    /* BASIC: 510 GOTO 970 */
line_510:;
    goto line_970;
    /* BASIC: 520 PRINT "YOU DO NOT HAVE A BODY." */
line_520:;
    printf("%s", "YOU DO NOT HAVE A BODY."); printf("\n");
    /* BASIC: 530 GOTO 970 */
line_530:;
    goto line_970;
    /* BASIC: 540 PRINT "3=HEAD" */
line_540:;
    printf("%s", "3=HEAD"); printf("\n");
    /* BASIC: 550 IF N=0 THEN 610 */
line_550:;
    if (N==0) { goto line_610; }
    /* BASIC: 560 IF H=1 THEN 630 */
line_560:;
    if (H==1) { goto line_630; }
    /* BASIC: 570 PRINT "YOU NEEDED A HEAD." */
line_570:;
    printf("%s", "YOU NEEDED A HEAD."); printf("\n");
    /* BASIC: 580 H=1 */
line_580:;
    H = 1;
    /* BASIC: 590 C=0 */
line_590:;
    C = 0;
    /* BASIC: 600 GOTO 970 */
line_600:;
    goto line_970;
    /* BASIC: 610 PRINT "YOU DO NOT HAVE A NECK." */
line_610:;
    printf("%s", "YOU DO NOT HAVE A NECK."); printf("\n");
    /* BASIC: 620 GOTO 970 */
line_620:;
    goto line_970;
    /* BASIC: 630 PRINT "YOU HAVE A HEAD." */
line_630:;
    printf("%s", "YOU HAVE A HEAD."); printf("\n");
    /* BASIC: 640 GOTO 970 */
line_640:;
    goto line_970;
    /* BASIC: 650 PRINT "4=FEELERS" */
line_650:;
    printf("%s", "4=FEELERS"); printf("\n");
    /* BASIC: 660 IF H=0 THEN 740 */
line_660:;
    if (H==0) { goto line_740; }
    /* BASIC: 670 IF A=2 THEN 720 */
line_670:;
    if (A==2) { goto line_720; }
    /* BASIC: 680 PRINT "I NOW GIVE YOU A FEELER." */
line_680:;
    printf("%s", "I NOW GIVE YOU A FEELER."); printf("\n");
    /* BASIC: 690 A=A+1 */
line_690:;
    A = A+1;
    /* BASIC: 700 C=0 */
line_700:;
    C = 0;
    /* BASIC: 710 GOTO 970 */
line_710:;
    goto line_970;
    /* BASIC: 720 PRINT "YOU HAVE TWO FEELERS ALREADY." */
line_720:;
    printf("%s", "YOU HAVE TWO FEELERS ALREADY."); printf("\n");
    /* BASIC: 730 GOTO 970 */
line_730:;
    goto line_970;
    /* BASIC: 740 PRINT "YOU DO NOT HAVE A HEAD." */
line_740:;
    printf("%s", "YOU DO NOT HAVE A HEAD."); printf("\n");
    /* BASIC: 750 GOTO 970 */
line_750:;
    goto line_970;
    /* BASIC: 760 PRINT "5=TAIL" */
line_760:;
    printf("%s", "5=TAIL"); printf("\n");
    /* BASIC: 770 IF B=0 THEN 830 */
line_770:;
    if (B==0) { goto line_830; }
    /* BASIC: 780 IF T=1 THEN 850 */
line_780:;
    if (T==1) { goto line_850; }
    /* BASIC: 790 PRINT "I NOW GIVE YOU A TAIL." */
line_790:;
    printf("%s", "I NOW GIVE YOU A TAIL."); printf("\n");
    /* BASIC: 800 T=T+1 */
line_800:;
    T = T+1;
    /* BASIC: 810 C=0 */
line_810:;
    C = 0;
    /* BASIC: 820 GOTO 970 */
line_820:;
    goto line_970;
    /* BASIC: 830 PRINT "YOU DO NOT HAVE A BODY." */
line_830:;
    printf("%s", "YOU DO NOT HAVE A BODY."); printf("\n");
    /* BASIC: 840 GOTO 970 */
line_840:;
    goto line_970;
    /* BASIC: 850 PRINT "YOU ALREADY HAVE A TAIL." */
line_850:;
    printf("%s", "YOU ALREADY HAVE A TAIL."); printf("\n");
    /* BASIC: 860 GOTO 970 */
line_860:;
    goto line_970;
    /* BASIC: 870 PRINT "6=LEG" */
line_870:;
    printf("%s", "6=LEG"); printf("\n");
    /* BASIC: 880 IF L=6 THEN 940 */
line_880:;
    if (L==6) { goto line_940; }
    /* BASIC: 890 IF B=0 THEN 960 */
line_890:;
    if (B==0) { goto line_960; }
    /* BASIC: 900 L=L+1 */
line_900:;
    L = L+1;
    /* BASIC: 910 C=0 */
line_910:;
    C = 0;
    /* BASIC: 920 PRINT "YOU NOW HAVE";L;"LEGS." */
line_920:;
    printf("%s", "YOU NOW HAVE"); printf("%g ", (double)(L)); printf("%s", "LEGS."); printf("\n");
    /* BASIC: 930 GOTO 970 */
line_930:;
    goto line_970;
    /* BASIC: 940 PRINT "YOU HAVE 6 FEET ALREADY." */
line_940:;
    printf("%s", "YOU HAVE 6 FEET ALREADY."); printf("\n");
    /* BASIC: 950 GOTO 970 */
line_950:;
    goto line_970;
    /* BASIC: 960 PRINT "YOU DO NOT HAVE A BODY." */
line_960:;
    printf("%s", "YOU DO NOT HAVE A BODY."); printf("\n");
    /* BASIC: 970 X=INT(6*RND(1)+1) */
line_970:;
    X = floor(6*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 971 PRINT */
line_971:;
    printf("\n");
    /* BASIC: 975 FOR DELAY=1 TO 2000:NEXT DELAY */
line_975:;
    DELAY = 1; for_loop_DELAY_975: if (((1) >= 0 && DELAY > (2000)) || ((1) < 0 && DELAY < (2000))) goto end_for_DELAY_975;
    DELAY += (1); goto for_loop_DELAY_975; end_for_DELAY_975:;
    /* BASIC: 980 PRINT "I ROLLED A";X */
line_980:;
    printf("%s", "I ROLLED A"); printf("%g ", (double)(X)); printf("\n");
    /* BASIC: 990 ON X GOTO 1000,1080,1190,1300,1410,1520 */
line_990:;
    switch ((int)(X)) {     case 1: goto line_1000;     case 2: goto line_1080;     case 3: goto line_1190;     case 4: goto line_1300;     case 5: goto line_1410;     case 6: goto line_1520; }
    /* BASIC: 1000 PRINT "1=BODY" */
line_1000:;
    printf("%s", "1=BODY"); printf("\n");
    /* BASIC: 1010 IF P=1 THEN 1060 */
line_1010:;
    if (P==1) { goto line_1060; }
    /* BASIC: 1020 PRINT "I NOW HAVE A BODY." */
line_1020:;
    printf("%s", "I NOW HAVE A BODY."); printf("\n");
    /* BASIC: 1030 C=0 */
line_1030:;
    C = 0;
    /* BASIC: 1040 P=1 */
line_1040:;
    P = 1;
    /* BASIC: 1050 GOTO 1630 */
line_1050:;
    goto line_1630;
    /* BASIC: 1060 PRINT "I DO NOT NEED A BODY." */
line_1060:;
    printf("%s", "I DO NOT NEED A BODY."); printf("\n");
    /* BASIC: 1070 GOTO 1630 */
line_1070:;
    goto line_1630;
    /* BASIC: 1080 PRINT "2=NECK" */
line_1080:;
    printf("%s", "2=NECK"); printf("\n");
    /* BASIC: 1090 IF Q=1 THEN 1150 */
line_1090:;
    if (Q==1) { goto line_1150; }
    /* BASIC: 1100 IF P=0 THEN 1170 */
line_1100:;
    if (P==0) { goto line_1170; }
    /* BASIC: 1110 PRINT "I NOW HAVE A NECK." */
line_1110:;
    printf("%s", "I NOW HAVE A NECK."); printf("\n");
    /* BASIC: 1120 Q=1 */
line_1120:;
    Q = 1;
    /* BASIC: 1130 C=0 */
line_1130:;
    C = 0;
    /* BASIC: 1140 GOTO 1630 */
line_1140:;
    goto line_1630;
    /* BASIC: 1150 PRINT "I DO NOT NEED A NECK." */
line_1150:;
    printf("%s", "I DO NOT NEED A NECK."); printf("\n");
    /* BASIC: 1160 GOTO 1630 */
line_1160:;
    goto line_1630;
    /* BASIC: 1170 PRINT "I DO NOT HAVE A BODY." */
line_1170:;
    printf("%s", "I DO NOT HAVE A BODY."); printf("\n");
    /* BASIC: 1180 GOTO 1630 */
line_1180:;
    goto line_1630;
    /* BASIC: 1190 PRINT "3=HEAD" */
line_1190:;
    printf("%s", "3=HEAD"); printf("\n");
    /* BASIC: 1200 IF Q=0 THEN 1260 */
line_1200:;
    if (Q==0) { goto line_1260; }
    /* BASIC: 1210 IF R=1 THEN 1280 */
line_1210:;
    if (R==1) { goto line_1280; }
    /* BASIC: 1220 PRINT "I NEEDED A HEAD." */
line_1220:;
    printf("%s", "I NEEDED A HEAD."); printf("\n");
    /* BASIC: 1230 R=1 */
line_1230:;
    R = 1;
    /* BASIC: 1240 C=0 */
line_1240:;
    C = 0;
    /* BASIC: 1250 GOTO 1630 */
line_1250:;
    goto line_1630;
    /* BASIC: 1260 PRINT "I DO NOT HAVE A NECK." */
line_1260:;
    printf("%s", "I DO NOT HAVE A NECK."); printf("\n");
    /* BASIC: 1270 GOTO 1630 */
line_1270:;
    goto line_1630;
    /* BASIC: 1280 PRINT "I DO NOT NEED A HEAD." */
line_1280:;
    printf("%s", "I DO NOT NEED A HEAD."); printf("\n");
    /* BASIC: 1290 GOTO 1630 */
line_1290:;
    goto line_1630;
    /* BASIC: 1300 PRINT "4=FEELERS" */
line_1300:;
    printf("%s", "4=FEELERS"); printf("\n");
    /* BASIC: 1310 IF R=0 THEN 1390 */
line_1310:;
    if (R==0) { goto line_1390; }
    /* BASIC: 1320 IF S=2 THEN 1370 */
line_1320:;
    if (S==2) { goto line_1370; }
    /* BASIC: 1330 PRINT "I GET A FEELER." */
line_1330:;
    printf("%s", "I GET A FEELER."); printf("\n");
    /* BASIC: 1340 S=S+1 */
line_1340:;
    S = S+1;
    /* BASIC: 1350 C=0 */
line_1350:;
    C = 0;
    /* BASIC: 1360 GOTO 1630 */
line_1360:;
    goto line_1630;
    /* BASIC: 1370 PRINT "I HAVE 2 FEELERS ALREADY." */
line_1370:;
    printf("%s", "I HAVE 2 FEELERS ALREADY."); printf("\n");
    /* BASIC: 1380 GOTO 1630 */
line_1380:;
    goto line_1630;
    /* BASIC: 1390 PRINT "I DO NOT HAVE A HEAD." */
line_1390:;
    printf("%s", "I DO NOT HAVE A HEAD."); printf("\n");
    /* BASIC: 1400 GOTO 1630 */
line_1400:;
    goto line_1630;
    /* BASIC: 1410 PRINT "5=TAIL" */
line_1410:;
    printf("%s", "5=TAIL"); printf("\n");
    /* BASIC: 1420 IF P=0 THEN 1480 */
line_1420:;
    if (P==0) { goto line_1480; }
    /* BASIC: 1430 IF U=1 THEN 1500 */
line_1430:;
    if (U==1) { goto line_1500; }
    /* BASIC: 1440 PRINT "I NOW HAVE A TAIL." */
line_1440:;
    printf("%s", "I NOW HAVE A TAIL."); printf("\n");
    /* BASIC: 1450 U=1 */
line_1450:;
    U = 1;
    /* BASIC: 1460 C=0 */
line_1460:;
    C = 0;
    /* BASIC: 1470 GOTO 1630 */
line_1470:;
    goto line_1630;
    /* BASIC: 1480 PRINT "I DO NOT HAVE A BODY." */
line_1480:;
    printf("%s", "I DO NOT HAVE A BODY."); printf("\n");
    /* BASIC: 1490 GOTO 1630 */
line_1490:;
    goto line_1630;
    /* BASIC: 1500 PRINT "I DO NOT NEED A TAIL." */
line_1500:;
    printf("%s", "I DO NOT NEED A TAIL."); printf("\n");
    /* BASIC: 1510 GOTO 1630 */
line_1510:;
    goto line_1630;
    /* BASIC: 1520 PRINT "6=LEGS" */
line_1520:;
    printf("%s", "6=LEGS"); printf("\n");
    /* BASIC: 1530 IF V=6 THEN 1590 */
line_1530:;
    if (V==6) { goto line_1590; }
    /* BASIC: 1540 IF P=0 THEN 1610 */
line_1540:;
    if (P==0) { goto line_1610; }
    /* BASIC: 1550 V=V+1 */
line_1550:;
    V = V+1;
    /* BASIC: 1560 C=0 */
line_1560:;
    C = 0;
    /* BASIC: 1570 PRINT "I NOW HAVE";V;"LEGS." */
line_1570:;
    printf("%s", "I NOW HAVE"); printf("%g ", (double)(V)); printf("%s", "LEGS."); printf("\n");
    /* BASIC: 1580 GOTO 1630 */
line_1580:;
    goto line_1630;
    /* BASIC: 1590 PRINT,"I HAVE 6 FEET." */
line_1590:;
    printf("\t"); printf("%s", "I HAVE 6 FEET."); printf("\n");
    /* BASIC: 1600 GOTO 1630 */
line_1600:;
    goto line_1630;
    /* BASIC: 1610 PRINT "I DO NOT HAVE A BODY." */
line_1610:;
    printf("%s", "I DO NOT HAVE A BODY."); printf("\n");
    /* BASIC: 1620 GOTO 1630 */
line_1620:;
    goto line_1630;
    /* BASIC: 1630 IF A=2 AND T=1 AND L=6 THEN 1650 */
line_1630:;
    if (A==2   &&   T==1   &&   L==6) { goto line_1650; }
    /* BASIC: 1640 GOTO 1670 */
line_1640:;
    goto line_1670;
    /* BASIC: 1650 PRINT "YOUR BUG IS FINISHED." */
line_1650:;
    printf("%s", "YOUR BUG IS FINISHED."); printf("\n");
    /* BASIC: 1660 Y=Y+1 */
line_1660:;
    Y = Y+1;
    /* BASIC: 1670 IF S=2 AND P=1 AND V=6 THEN 1690 */
line_1670:;
    if (S==2   &&   P==1   &&   V==6) { goto line_1690; }
    /* BASIC: 1680 GOTO 1710 */
line_1680:;
    goto line_1710;
    /* BASIC: 1690 PRINT "MY BUG IS FINISHED." */
line_1690:;
    printf("%s", "MY BUG IS FINISHED."); printf("\n");
    /* BASIC: 1700 Y=Y+2 */
line_1700:;
    Y = Y+2;
    /* BASIC: 1710 IF C=1 THEN 300 */
line_1710:;
    if (C==1) { goto line_300; }
    /* BASIC: 1720 PRINT "DO YOU WANT THE PICTURES"; */
line_1720:;
    printf("%s", "DO YOU WANT THE PICTURES");
    /* BASIC: 1730 INPUT Z$ */
line_1730:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", Z_str);
    /* BASIC: 1740 IF Z$="NO" THEN 300 */
line_1740:;
    if (strcmp(Z_str, "NO") == 0) { goto line_300; }
    /* BASIC: 1750 PRINT "*****YOUR BUG*****" */
line_1750:;
    printf("%s", "*****YOUR BUG*****"); printf("\n");
    /* BASIC: 1760 PRINT */
line_1760:;
    printf("\n");
    /* BASIC: 1770 PRINT */
line_1770:;
    printf("\n");
    /* BASIC: 1780 IF A=0 THEN 1860 */
line_1780:;
    if (A==0) { goto line_1860; }
    /* BASIC: 1790 FOR Z=1 TO 4 */
line_1790:;
    Z = 1; for_loop_Z_1790: if (((1) >= 0 && Z > (4)) || ((1) < 0 && Z < (4))) goto end_for_Z_1790;
    /* BASIC: 1800 FOR X=1 TO A */
line_1800:;
    X = 1; for_loop_X_1800: if (((1) >= 0 && X > (A)) || ((1) < 0 && X < (A))) goto end_for_X_1800;
    /* BASIC: 1810 PRINT TAB(10); */
line_1810:;
    { int _t; for(_t=0; _t<10; _t++) printf(" "); }
    /* BASIC: 1820 PRINT "A "; */
line_1820:;
    printf("%s", "A ");
    /* BASIC: 1830 NEXT X */
line_1830:;
    X += (1); goto for_loop_X_1800; end_for_X_1800:;
    /* BASIC: 1840 PRINT */
line_1840:;
    printf("\n");
    /* BASIC: 1850 NEXT Z */
line_1850:;
    Z += (1); goto for_loop_Z_1790; end_for_Z_1790:;
    /* BASIC: 1860 IF H=0 THEN 1880 */
line_1860:;
    if (H==0) { goto line_1880; }
    /* BASIC: 1870 GOSUB 2470 */
line_1870:;
    gosub_stack[gosub_sp++] = 1; goto line_2470; line_ret_1:;
    /* BASIC: 1880 IF N=0 THEN 1920 */
line_1880:;
    if (N==0) { goto line_1920; }
    /* BASIC: 1890 FOR Z=1 TO 2 */
line_1890:;
    Z = 1; for_loop_Z_1890: if (((1) >= 0 && Z > (2)) || ((1) < 0 && Z < (2))) goto end_for_Z_1890;
    /* BASIC: 1900 PRINT "          N N" */
line_1900:;
    printf("%s", "          N N"); printf("\n");
    /* BASIC: 1910 NEXT Z */
line_1910:;
    Z += (1); goto for_loop_Z_1890; end_for_Z_1890:;
    /* BASIC: 1920 IF B=0 THEN 2000 */
line_1920:;
    if (B==0) { goto line_2000; }
    /* BASIC: 1930 PRINT "     BBBBBBBBBBBB" */
line_1930:;
    printf("%s", "     BBBBBBBBBBBB"); printf("\n");
    /* BASIC: 1940 FOR Z=1 TO 2 */
line_1940:;
    Z = 1; for_loop_Z_1940: if (((1) >= 0 && Z > (2)) || ((1) < 0 && Z < (2))) goto end_for_Z_1940;
    /* BASIC: 1950 PRINT "     B          B" */
line_1950:;
    printf("%s", "     B          B"); printf("\n");
    /* BASIC: 1960 NEXT Z */
line_1960:;
    Z += (1); goto for_loop_Z_1940; end_for_Z_1940:;
    /* BASIC: 1970 IF T<>1 THEN 1990 */
line_1970:;
    if (T!=1) { goto line_1990; }
    /* BASIC: 1980 PRINT "TTTTTB          B" */
line_1980:;
    printf("%s", "TTTTTB          B"); printf("\n");
    /* BASIC: 1990 PRINT "     BBBBBBBBBBBB" */
line_1990:;
    printf("%s", "     BBBBBBBBBBBB"); printf("\n");
    /* BASIC: 2000 IF L=0 THEN 2080 */
line_2000:;
    if (L==0) { goto line_2080; }
    /* BASIC: 2010 FOR Z=1 TO 2 */
line_2010:;
    Z = 1; for_loop_Z_2010: if (((1) >= 0 && Z > (2)) || ((1) < 0 && Z < (2))) goto end_for_Z_2010;
    /* BASIC: 2020 PRINT TAB(5); */
line_2020:;
    { int _t; for(_t=0; _t<5; _t++) printf(" "); }
    /* BASIC: 2030 FOR X=1 TO L */
line_2030:;
    X = 1; for_loop_X_2030: if (((1) >= 0 && X > (L)) || ((1) < 0 && X < (L))) goto end_for_X_2030;
    /* BASIC: 2040 PRINT " L"; */
line_2040:;
    printf("%s", " L");
    /* BASIC: 2050 NEXT X */
line_2050:;
    X += (1); goto for_loop_X_2030; end_for_X_2030:;
    /* BASIC: 2060 PRINT */
line_2060:;
    printf("\n");
    /* BASIC: 2070 NEXT Z */
line_2070:;
    Z += (1); goto for_loop_Z_2010; end_for_Z_2010:;
    /* BASIC: 2080 FOR Z=1 TO 4 */
line_2080:;
    Z = 1; for_loop_Z_2080: if (((1) >= 0 && Z > (4)) || ((1) < 0 && Z < (4))) goto end_for_Z_2080;
    /* BASIC: 2090 PRINT */
line_2090:;
    printf("\n");
    /* BASIC: 2100 NEXT Z */
line_2100:;
    Z += (1); goto for_loop_Z_2080; end_for_Z_2080:;
    /* BASIC: 2110 PRINT "*****MY BUG*****" */
line_2110:;
    printf("%s", "*****MY BUG*****"); printf("\n");
    /* BASIC: 2120 PRINT */
line_2120:;
    printf("\n");
    /* BASIC: 2130 PRINT */
line_2130:;
    printf("\n");
    /* BASIC: 2140 PRINT */
line_2140:;
    printf("\n");
    /* BASIC: 2150 IF S=0 THEN 2230 */
line_2150:;
    if (S==0) { goto line_2230; }
    /* BASIC: 2160 FOR Z=1 TO 4 */
line_2160:;
    Z = 1; for_loop_Z_2160: if (((1) >= 0 && Z > (4)) || ((1) < 0 && Z < (4))) goto end_for_Z_2160;
    /* BASIC: 2170 PRINT TAB(10); */
line_2170:;
    { int _t; for(_t=0; _t<10; _t++) printf(" "); }
    /* BASIC: 2180 FOR X=1 TO S */
line_2180:;
    X = 1; for_loop_X_2180: if (((1) >= 0 && X > (S)) || ((1) < 0 && X < (S))) goto end_for_X_2180;
    /* BASIC: 2190 PRINT "F "; */
line_2190:;
    printf("%s", "F ");
    /* BASIC: 2200 NEXT X */
line_2200:;
    X += (1); goto for_loop_X_2180; end_for_X_2180:;
    /* BASIC: 2210 PRINT */
line_2210:;
    printf("\n");
    /* BASIC: 2220 NEXT Z */
line_2220:;
    Z += (1); goto for_loop_Z_2160; end_for_Z_2160:;
    /* BASIC: 2230 IF R<>1 THEN 2250 */
line_2230:;
    if (R!=1) { goto line_2250; }
    /* BASIC: 2240 GOSUB 2470 */
line_2240:;
    gosub_stack[gosub_sp++] = 2; goto line_2470; line_ret_2:;
    /* BASIC: 2250 IF Q=0 THEN 2280 */
line_2250:;
    if (Q==0) { goto line_2280; }
    /* BASIC: 2260 PRINT "          N N" */
line_2260:;
    printf("%s", "          N N"); printf("\n");
    /* BASIC: 2270 PRINT "          N N" */
line_2270:;
    printf("%s", "          N N"); printf("\n");
    /* BASIC: 2280 IF P=0 THEN 2360 */
line_2280:;
    if (P==0) { goto line_2360; }
    /* BASIC: 2290 PRINT "     BBBBBBBBBBBB" */
line_2290:;
    printf("%s", "     BBBBBBBBBBBB"); printf("\n");
    /* BASIC: 2300 FOR Z=1 TO 2 */
line_2300:;
    Z = 1; for_loop_Z_2300: if (((1) >= 0 && Z > (2)) || ((1) < 0 && Z < (2))) goto end_for_Z_2300;
    /* BASIC: 2310 PRINT "     B          B" */
line_2310:;
    printf("%s", "     B          B"); printf("\n");
    /* BASIC: 2320 NEXT Z */
line_2320:;
    Z += (1); goto for_loop_Z_2300; end_for_Z_2300:;
    /* BASIC: 2330 IF U<>1 THEN 2350 */
line_2330:;
    if (U!=1) { goto line_2350; }
    /* BASIC: 2340 PRINT "TTTTTB          B" */
line_2340:;
    printf("%s", "TTTTTB          B"); printf("\n");
    /* BASIC: 2350 PRINT "     BBBBBBBBBBBB" */
line_2350:;
    printf("%s", "     BBBBBBBBBBBB"); printf("\n");
    /* BASIC: 2360 IF V=0 THEN 2450 */
line_2360:;
    if (V==0) { goto line_2450; }
    /* BASIC: 2370 FOR Z=1 TO 2 */
line_2370:;
    Z = 1; for_loop_Z_2370: if (((1) >= 0 && Z > (2)) || ((1) < 0 && Z < (2))) goto end_for_Z_2370;
    /* BASIC: 2380 PRINT TAB(5); */
line_2380:;
    { int _t; for(_t=0; _t<5; _t++) printf(" "); }
    /* BASIC: 2390 FOR X=1 TO V */
line_2390:;
    X = 1; for_loop_X_2390: if (((1) >= 0 && X > (V)) || ((1) < 0 && X < (V))) goto end_for_X_2390;
    /* BASIC: 2400 PRINT " L"; */
line_2400:;
    printf("%s", " L");
    /* BASIC: 2410 NEXT X */
line_2410:;
    X += (1); goto for_loop_X_2390; end_for_X_2390:;
    /* BASIC: 2420 PRINT */
line_2420:;
    printf("\n");
    /* BASIC: 2430 NEXT Z */
line_2430:;
    Z += (1); goto for_loop_Z_2370; end_for_Z_2370:;
    /* BASIC: 2450 IF Y<>0 THEN 2540 */
line_2450:;
    if (Y!=0) { goto line_2540; }
    /* BASIC: 2460 GOTO 300 */
line_2460:;
    goto line_300;
    /* BASIC: 2470 PRINT "        HHHHHHH" */
line_2470:;
    printf("%s", "        HHHHHHH"); printf("\n");
    /* BASIC: 2480 PRINT "        H     H" */
line_2480:;
    printf("%s", "        H     H"); printf("\n");
    /* BASIC: 2490 PRINT "        H O O H" */
line_2490:;
    printf("%s", "        H O O H"); printf("\n");
    /* BASIC: 2500 PRINT "        H     H" */
line_2500:;
    printf("%s", "        H     H"); printf("\n");
    /* BASIC: 2510 PRINT "        H  V  H" */
line_2510:;
    printf("%s", "        H  V  H"); printf("\n");
    /* BASIC: 2520 PRINT "        HHHHHHH" */
line_2520:;
    printf("%s", "        HHHHHHH"); printf("\n");
    /* BASIC: 2530 RETURN */
line_2530:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 2540 PRINT "I HOPE YOU ENJOYED THE GAME, PLAY IT AGAIN SOON!!" */
line_2540:;
    printf("%s", "I HOPE YOU ENJOYED THE GAME, PLAY IT AGAIN SOON!!"); printf("\n");
    /* BASIC: 2550 END */
line_2550:;
    exit(0);

    return 0;
}
