/*
 * Transpiled from slalom.bas
 * GW-BASIC to strict C89 (ANSI) / C90 (ISO)
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
    if (n >= 0) sprintf(buf[idx], " %g", n);
    else sprintf(buf[idx], "%g", n);
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
    sprintf(buf[idx], "%s%s", s1, s2);
    return buf[idx];
}

static void str_assign(char *dest, size_t dest_sz, const char *src) {
    strncpy(dest, src, dest_sz - 1);
    dest[dest_sz - 1] = '\0';
}

typedef enum { DATA_NUM, DATA_STR } DataType;
typedef struct {
    DataType type;
    double num;
    const char *str;
} DataItem;

static DataItem program_data[25] = {
    { DATA_NUM, 14.0, NULL },
    { DATA_NUM, 18.0, NULL },
    { DATA_NUM, 26.0, NULL },
    { DATA_NUM, 29.0, NULL },
    { DATA_NUM, 18.0, NULL },
    { DATA_NUM, 25.0, NULL },
    { DATA_NUM, 28.0, NULL },
    { DATA_NUM, 32.0, NULL },
    { DATA_NUM, 29.0, NULL },
    { DATA_NUM, 20.0, NULL },
    { DATA_NUM, 29.0, NULL },
    { DATA_NUM, 29.0, NULL },
    { DATA_NUM, 25.0, NULL },
    { DATA_NUM, 21.0, NULL },
    { DATA_NUM, 26.0, NULL },
    { DATA_NUM, 29.0, NULL },
    { DATA_NUM, 20.0, NULL },
    { DATA_NUM, 21.0, NULL },
    { DATA_NUM, 20.0, NULL },
    { DATA_NUM, 18.0, NULL },
    { DATA_NUM, 26.0, NULL },
    { DATA_NUM, 25.0, NULL },
    { DATA_NUM, 33.0, NULL },
    { DATA_NUM, 31.0, NULL },
    { DATA_NUM, 22.0, NULL },
};
static int data_ptr = 0;

static void read_numeric(double *var) {
    if (data_ptr < sizeof(program_data)/sizeof(program_data[0])) {
        if (program_data[data_ptr].type == DATA_NUM) *var = program_data[data_ptr].num;
        else *var = atof(program_data[data_ptr].str);
        data_ptr++;
    }
}

static void read_string(char *var, size_t max_len) {
    if (data_ptr < sizeof(program_data)/sizeof(program_data[0])) {
        if (program_data[data_ptr].type == DATA_STR) strncpy(var, program_data[data_ptr].str, max_len - 1);
        else sprintf(var, "%g", program_data[data_ptr].num);
        var[max_len - 1] = '\0';
        data_ptr++;
    }
}

/* Global variables */
static int gosub_stack[256];
static int gosub_sp = 0;
static double A, B, G, LET, M, O, O1, ON, P, Q, S, S1, T, V;
static char A_str[256] = {0};
static char B_str[256] = {0};
static double B_arr[2000] = {0};
static double G_arr[2000] = {0};
static double S_arr[2000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(33);"SLALOM" */
line_10:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "SLALOM"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 310 PRINT "HOW MANY GATES DOES THIS COURSE HAVE (1 TO 25)"; */
line_310:;
    printf("%s", "HOW MANY GATES DOES THIS COURSE HAVE (1 TO 25)");
    /* BASIC: 320 INPUT V */
line_320:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &V);
    /* BASIC: 330 IF V>25 THEN 360 */
line_330:;
    if (V>25) { goto line_360; }
    /* BASIC: 340 IF V<1 THEN 390 */
line_340:;
    if (V<1) { goto line_390; }
    /* BASIC: 350 GOTO 1440 */
line_350:;
    goto line_1440;
    /* BASIC: 360 PRINT "25 IS THE LIMIT." */
line_360:;
    printf("%s", "25 IS THE LIMIT."); printf("\n");
    /* BASIC: 370 LET V=25 */
line_370:;
    /* UNTRANSLATED: LET V=25 */
    /* BASIC: 380 GOTO 1440 */
line_380:;
    goto line_1440;
    /* BASIC: 390 PRINT "TRY AGAIN," */
line_390:;
    printf("%s", "TRY AGAIN,"); printf("\n");
    /* BASIC: 400 GOTO 310 */
line_400:;
    goto line_310;
    /* BASIC: 410 PRINT "RATE YOURSELF AS A SKIER, (1=WORST, 3=BEST)"; */
line_410:;
    printf("%s", "RATE YOURSELF AS A SKIER, (1=WORST, 3=BEST)");
    /* BASIC: 420 INPUT A */
line_420:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &A);
    /* BASIC: 430 IF A<1 THEN 460 */
line_430:;
    if (A<1) { goto line_460; }
    /* BASIC: 440 IF A>3 THEN 460 */
line_440:;
    if (A>3) { goto line_460; }
    /* BASIC: 450 GOTO 480 */
line_450:;
    goto line_480;
    /* BASIC: 460 PRINT "THE BOUNDS ARE 1-3" */
line_460:;
    printf("%s", "THE BOUNDS ARE 1-3"); printf("\n");
    /* BASIC: 470 GOTO 410 */
line_470:;
    goto line_410;
    /* BASIC: 480 PRINT"THE STARTER COUNTS DOWN...5...4...3...2...1...GO!"; */
line_480:;
    printf("%s", "THE STARTER COUNTS DOWN...5...4...3...2...1...GO!");
    /* BASIC: 490 REM */
line_490:;
    /* REM */
    /* BASIC: 500 LET T=0 */
line_500:;
    /* UNTRANSLATED: LET T=0 */
    /* BASIC: 510 LET S=INT(RND(1)*(18-9)+9) */
line_510:;
    /* UNTRANSLATED: LET S=INT(RND(1)*(18-9)+9) */
    /* BASIC: 520 PRINT */
line_520:;
    printf("\n");
    /* BASIC: 525 PRINT "YOU'RE OFF!" */
line_525:;
    printf("%s", "YOU'RE OFF!"); printf("\n");
    /* BASIC: 530 FOR O=1 TO V */
line_530:;
    O = 1; for_loop_O_530: if (((1) >= 0 && O > (V)) || ((1) < 0 && O < (V))) goto end_for_O_530;
    /* BASIC: 540 READ Q */
line_540:;
    read_numeric(&Q);
    /* BASIC: 550 PRINT */
line_550:;
    printf("\n");
    /* BASIC: 555 PRINT "HERE COMES GATE #";STR$(O);":" */
line_555:;
    printf("%s", "HERE COMES GATE #"); printf("%s", basic_STR(O)); printf("%s", ":"); printf("\n");
    /* BASIC: 560 PRINT S;"M.P.H." */
line_560:;
    printf("%g ", (double)(S)); printf("%s", "M.P.H."); printf("\n");
    /* BASIC: 570 LET S1=S */
line_570:;
    /* UNTRANSLATED: LET S1=S */
    /* BASIC: 580 PRINT "OPTION"; */
line_580:;
    printf("%s", "OPTION");
    /* BASIC: 590 INPUT O1 */
line_590:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &O1);
    /* BASIC: 600 IF O1=0 THEN 970 */
line_600:;
    if (O1==0) { goto line_970; }
    /* BASIC: 610 IF O1>8 THEN 1420 */
line_610:;
    if (O1>8) { goto line_1420; }
    /* BASIC: 620 IF O1<1 THEN 1420 */
line_620:;
    if (O1<1) { goto line_1420; }
    /* BASIC: 630 GOSUB 990 */
line_630:;
    gosub_stack[gosub_sp++] = 1; goto line_990; line_ret_1:;
    /* BASIC: 640 IF S<7 THEN 1390 */
line_640:;
    if (S<7) { goto line_1390; }
    /* BASIC: 650 LET T=T+(Q-S+1) */
line_650:;
    /* UNTRANSLATED: LET T=T+(Q-S+1) */
    /* BASIC: 660 IF S>Q THEN 1630 */
line_660:;
    if (S>Q) { goto line_1630; }
    /* BASIC: 670 NEXT O */
line_670:;
    O += (1); goto for_loop_O_530; end_for_O_530:;
    /* BASIC: 680 PRINT:PRINT "YOU TOOK";(T+RND(1));"SECONDS." */
line_680:;
    printf("\n");
    printf("%s", "YOU TOOK"); printf("%g ", (double)((T+((double)rand() / (double)RAND_MAX)))); printf("%s", "SECONDS."); printf("\n");
    /* BASIC: 690 LET M=T */
line_690:;
    /* UNTRANSLATED: LET M=T */
    /* BASIC: 700 LET M=M/V */
line_700:;
    /* UNTRANSLATED: LET M=M/V */
    /* BASIC: 710 IF M<1.5-(A*.1) THEN 1650 */
line_710:;
    if (M<1.5-(A*.1)) { goto line_1650; }
    /* BASIC: 720 IF M<2.9-(A*.1) THEN 1680 */
line_720:;
    if (M<2.9-(A*.1)) { goto line_1680; }
    /* BASIC: 730 IF M<4.4-(A*.01) THEN 1710 */
line_730:;
    if (M<4.4-(A*.01)) { goto line_1710; }
    /* BASIC: 740 PRINT:PRINT "DO YOU WANT TO RACE AGAIN"; */
line_740:;
    printf("\n");
    printf("%s", "DO YOU WANT TO RACE AGAIN");
    /* BASIC: 750 INPUT B$ */
line_750:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", B_str);
    /* BASIC: 760 REM */
line_760:;
    /* REM */
    /* BASIC: 770 IF B$="NO" THEN 1740 */
line_770:;
    if (strcmp(B_str, "NO") == 0) { goto line_1740; }
    /* BASIC: 780 IF B$="YES" THEN 480 */
line_780:;
    if (strcmp(B_str, "YES") == 0) { goto line_480; }
    /* BASIC: 790 PRINT "PLEASE TYPE 'YES' OR 'NO'" */
line_790:;
    printf("%s", "PLEASE TYPE 'YES' OR 'NO'"); printf("\n");
    /* BASIC: 800 GOTO 740 */
line_800:;
    goto line_740;
    /* BASIC: 810 S TO P */
line_810:;
    /* UNTRANSLATED: S TO P */
    /* BASIC: 820 PRINT */
line_820:;
    printf("\n");
    /* BASIC: 825 PRINT "*** SLALOM: THIS IS THE 1976 WINTER OLYMPIC GIANT SLALOM.  YOU ARE" */
line_825:;
    printf("%s", "*** SLALOM: THIS IS THE 1976 WINTER OLYMPIC GIANT SLALOM.  YOU ARE"); printf("\n");
    /* BASIC: 830 PRINT "            THE AMERICAN TEAM'S ONLY HOPE OF A GOLD MEDAL." */
line_830:;
    printf("%s", "            THE AMERICAN TEAM'S ONLY HOPE OF A GOLD MEDAL."); printf("\n");
    /* BASIC: 840 PRINT */
line_840:;
    printf("\n");
    /* BASIC: 845 PRINT "     0 -- TYPE THIS IS YOU WANT TO SEE HOW LONG YOU'VE TAKEN." */
line_845:;
    printf("%s", "     0 -- TYPE THIS IS YOU WANT TO SEE HOW LONG YOU'VE TAKEN."); printf("\n");
    /* BASIC: 850 PRINT "     1 -- TYPE THIS IF YOU WANT TO SPEED UP A LOT." */
line_850:;
    printf("%s", "     1 -- TYPE THIS IF YOU WANT TO SPEED UP A LOT."); printf("\n");
    /* BASIC: 860 PRINT "     2 -- TYPE THIS IF YOU WANT TO SPEED UP A LITTLE." */
line_860:;
    printf("%s", "     2 -- TYPE THIS IF YOU WANT TO SPEED UP A LITTLE."); printf("\n");
    /* BASIC: 870 PRINT "     3 -- TYPE THIS IF YOU WANT TO SPEED UP A TEENSY." */
line_870:;
    printf("%s", "     3 -- TYPE THIS IF YOU WANT TO SPEED UP A TEENSY."); printf("\n");
    /* BASIC: 880 PRINT "     4 -- TYPE THIS IF YOU WANT TO KEEP GOING THE SAME SPEED." */
line_880:;
    printf("%s", "     4 -- TYPE THIS IF YOU WANT TO KEEP GOING THE SAME SPEED."); printf("\n");
    /* BASIC: 890 PRINT "     5 -- TYPE THIS IF YOU WANT TO CHECK A TEENSY." */
line_890:;
    printf("%s", "     5 -- TYPE THIS IF YOU WANT TO CHECK A TEENSY."); printf("\n");
    /* BASIC: 900 PRINT "     6 -- TYPE THIS IF YOU WANT TO CHECK A LITTLE." */
line_900:;
    printf("%s", "     6 -- TYPE THIS IF YOU WANT TO CHECK A LITTLE."); printf("\n");
    /* BASIC: 910 PRINT "     7 -- TYPE THIS IF YOU WANT TO CHECK A LOT." */
line_910:;
    printf("%s", "     7 -- TYPE THIS IF YOU WANT TO CHECK A LOT."); printf("\n");
    /* BASIC: 920 PRINT "     8 -- TYPE THIS IF YOU WANT TO CHEAT AND TRY TO SKIP A GATE." */
line_920:;
    printf("%s", "     8 -- TYPE THIS IF YOU WANT TO CHEAT AND TRY TO SKIP A GATE."); printf("\n");
    /* BASIC: 930 PRINT */
line_930:;
    printf("\n");
    /* BASIC: 935 PRINT " THE PLACE TO USE THESE OPTIONS IS WHEN THE COMPUTER ASKS:" */
line_935:;
    printf("%s", " THE PLACE TO USE THESE OPTIONS IS WHEN THE COMPUTER ASKS:"); printf("\n");
    /* BASIC: 940 PRINT */
line_940:;
    printf("\n");
    /* BASIC: 945 PRINT "OPTION?" */
line_945:;
    printf("%s", "OPTION?"); printf("\n");
    /* BASIC: 950 PRINT */
line_950:;
    printf("\n");
    /* BASIC: 955 PRINT "                GOOD LUCK!" */
line_955:;
    printf("%s", "                GOOD LUCK!"); printf("\n");
    /* BASIC: 957 PRINT */
line_957:;
    printf("\n");
    /* BASIC: 960 GOTO 1470 */
line_960:;
    goto line_1470;
    /* BASIC: 970 PRINT "YOU'VE TAKEN";(T+RND(1));"SECONDS." */
line_970:;
    printf("%s", "YOU'VE TAKEN"); printf("%g ", (double)((T+((double)rand() / (double)RAND_MAX)))); printf("%s", "SECONDS."); printf("\n");
    /* BASIC: 980 GOTO 580 */
line_980:;
    goto line_580;
    /* BASIC: 990 ON O1 GOTO 1130,1010,1170,1080,1190,1100,1150,1210 */
line_990:;
    switch ((int)(O1)) {     case 1: goto line_1130;     case 2: goto line_1010;     case 3: goto line_1170;     case 4: goto line_1080;     case 5: goto line_1190;     case 6: goto line_1100;     case 7: goto line_1150;     case 8: goto line_1210; }
    /* BASIC: 1000 S TO P */
line_1000:;
    /* UNTRANSLATED: S TO P */
    /* BASIC: 1010 LET S=S+INT(RND(1)*(5-3)+3) */
line_1010:;
    /* UNTRANSLATED: LET S=S+INT(RND(1)*(5-3)+3) */
    /* BASIC: 1020 PRINT S;"M.P.H." */
line_1020:;
    printf("%g ", (double)(S)); printf("%s", "M.P.H."); printf("\n");
    /* BASIC: 1030 IF S>Q THEN 1290 */
line_1030:;
    if (S>Q) { goto line_1290; }
    /* BASIC: 1040 IF S>Q-1 THEN 1060 */
line_1040:;
    if (S>Q-1) { goto line_1060; }
    /* BASIC: 1050 RETURN */
line_1050:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1060 PRINT "CLOSE ONE!" */
line_1060:;
    printf("%s", "CLOSE ONE!"); printf("\n");
    /* BASIC: 1070 RETURN */
line_1070:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1080 PRINT S;"M.P.H." */
line_1080:;
    printf("%g ", (double)(S)); printf("%s", "M.P.H."); printf("\n");
    /* BASIC: 1090 GOTO 1030 */
line_1090:;
    goto line_1030;
    /* BASIC: 1100 LET S=S-INT(RND(1)*(5-3)+3) */
line_1100:;
    /* UNTRANSLATED: LET S=S-INT(RND(1)*(5-3)+3) */
    /* BASIC: 1110 PRINT S;"M.P.H." */
line_1110:;
    printf("%g ", (double)(S)); printf("%s", "M.P.H."); printf("\n");
    /* BASIC: 1120 GOTO 1030 */
line_1120:;
    goto line_1030;
    /* BASIC: 1130 LET S=S+INT(RND(1)*(10-5)+5) */
line_1130:;
    /* UNTRANSLATED: LET S=S+INT(RND(1)*(10-5)+5) */
    /* BASIC: 1140 GOTO 1080 */
line_1140:;
    goto line_1080;
    /* BASIC: 1150 LET S=S-INT(RND(1)*(10-5)+5) */
line_1150:;
    /* UNTRANSLATED: LET S=S-INT(RND(1)*(10-5)+5) */
    /* BASIC: 1160 GOTO 1110 */
line_1160:;
    goto line_1110;
    /* BASIC: 1170 LET S=S+INT(RND(1)*(4-1)+1) */
line_1170:;
    /* UNTRANSLATED: LET S=S+INT(RND(1)*(4-1)+1) */
    /* BASIC: 1180 GOTO 1110 */
line_1180:;
    goto line_1110;
    /* BASIC: 1190 LET S=S-INT(RND(1)*(4-1)+1) */
line_1190:;
    /* UNTRANSLATED: LET S=S-INT(RND(1)*(4-1)+1) */
    /* BASIC: 1200 GOTO 1110 */
line_1200:;
    goto line_1110;
    /* BASIC: 1210 PRINT "***CHEAT" */
line_1210:;
    printf("%s", "***CHEAT"); printf("\n");
    /* BASIC: 1220 IF RND(1)<.7 THEN 1260 */
line_1220:;
    if (((double)rand() / (double)RAND_MAX)<.7) { goto line_1260; }
    /* BASIC: 1230 PRINT "YOU MADE IT!" */
line_1230:;
    printf("%s", "YOU MADE IT!"); printf("\n");
    /* BASIC: 1240 LET T=T+1.5 */
line_1240:;
    /* UNTRANSLATED: LET T=T+1.5 */
    /* BASIC: 1250 RETURN */
line_1250:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1260 PRINT "AN OFFICIAL CAUGHT YOU!" */
line_1260:;
    printf("%s", "AN OFFICIAL CAUGHT YOU!"); printf("\n");
    /* BASIC: 1270 PRINT "YOU TOOK";(T+RND(1));"SECONDS." */
line_1270:;
    printf("%s", "YOU TOOK"); printf("%g ", (double)((T+((double)rand() / (double)RAND_MAX)))); printf("%s", "SECONDS."); printf("\n");
    /* BASIC: 1280 GOTO 740 */
line_1280:;
    goto line_740;
    /* BASIC: 1290 IF RND(1)<((S-Q)*.1)+.2 THEN 1320 */
line_1290:;
    if (((double)rand() / (double)RAND_MAX)<((S-Q)*.1)+.2) { goto line_1320; }
    /* BASIC: 1300 PRINT "YOU WENT OVER THE NAXIMUM SPEED AND MADE IT!" */
line_1300:;
    printf("%s", "YOU WENT OVER THE NAXIMUM SPEED AND MADE IT!"); printf("\n");
    /* BASIC: 1310 RETURN */
line_1310:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1320 PRINT "YOU WENT OVER THE MAXIMUM SPEED AND "; */
line_1320:;
    printf("%s", "YOU WENT OVER THE MAXIMUM SPEED AND ");
    /* BASIC: 1330 IF RND(1)<.5 THEN 1370 */
line_1330:;
    if (((double)rand() / (double)RAND_MAX)<.5) { goto line_1370; }
    /* BASIC: 1340 PRINT "WIPED OUT!" */
line_1340:;
    printf("%s", "WIPED OUT!"); printf("\n");
    /* BASIC: 1350 PRINT "YOU TOOK";(T+RND(1));"SECONDS" */
line_1350:;
    printf("%s", "YOU TOOK"); printf("%g ", (double)((T+((double)rand() / (double)RAND_MAX)))); printf("%s", "SECONDS"); printf("\n");
    /* BASIC: 1360 GOTO 740 */
line_1360:;
    goto line_740;
    /* BASIC: 1370 PRINT "SNAGGED A FLAG!" */
line_1370:;
    printf("%s", "SNAGGED A FLAG!"); printf("\n");
    /* BASIC: 1380 GOTO 1350 */
line_1380:;
    goto line_1350;
    /* BASIC: 1390 PRINT "LET'S BE REALISTIC, OK?  LET'S GO BACK AND TRY AGAIN..." */
line_1390:;
    printf("%s", "LET'S BE REALISTIC, OK?  LET'S GO BACK AND TRY AGAIN..."); printf("\n");
    /* BASIC: 1400 LET S=S1 */
line_1400:;
    /* UNTRANSLATED: LET S=S1 */
    /* BASIC: 1410 GOTO 550 */
line_1410:;
    goto line_550;
    /* BASIC: 1420 PRINT "WHAT?" */
line_1420:;
    printf("%s", "WHAT?"); printf("\n");
    /* BASIC: 1430 GOTO 580 */
line_1430:;
    goto line_580;
    /* BASIC: 1440 PRINT */
line_1440:;
    printf("\n");
    /* BASIC: 1445 PRINT "TYPE ";CHR$(34);"INS";CHR$(34);" FOR INSTRUCTIONS" */
line_1445:;
    printf("%s", "TYPE "); printf("%s", basic_CHR(34)); printf("%s", "INS"); printf("%s", basic_CHR(34)); printf("%s", " FOR INSTRUCTIONS"); printf("\n");
    /* BASIC: 1450 PRINT "TYPE ";CHR$(34);"MAX";CHR$(34);" FOR APPROXIMATE MAXIMUM SPEEDS" */
line_1450:;
    printf("%s", "TYPE "); printf("%s", basic_CHR(34)); printf("%s", "MAX"); printf("%s", basic_CHR(34)); printf("%s", " FOR APPROXIMATE MAXIMUM SPEEDS"); printf("\n");
    /* BASIC: 1460 PRINT "TYPE ";CHR$(34);"RUN";CHR$(34);" FOR THE BEGINNING OF THE RACE" */
line_1460:;
    printf("%s", "TYPE "); printf("%s", basic_CHR(34)); printf("%s", "RUN"); printf("%s", basic_CHR(34)); printf("%s", " FOR THE BEGINNING OF THE RACE"); printf("\n");
    /* BASIC: 1470 PRINT "COMMAND--"; */
line_1470:;
    printf("%s", "COMMAND--");
    /* BASIC: 1480 INPUT A$ */
line_1480:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    /* BASIC: 1490 REM */
line_1490:;
    /* REM */
    /* BASIC: 1500 IF A$="INS" THEN 820 */
line_1500:;
    if (strcmp(A_str, "INS") == 0) { goto line_820; }
    /* BASIC: 1510 IF A$="MAX" THEN 1550 */
line_1510:;
    if (strcmp(A_str, "MAX") == 0) { goto line_1550; }
    /* BASIC: 1520 IF A$="RUN" THEN 410 */
line_1520:;
    if (strcmp(A_str, "RUN") == 0) { goto line_410; }
    /* BASIC: 1530 PRINT CHR$(34);A$;CHR$(34);" IS AN ILLEGAL COMMAND--RETRY"; */
line_1530:;
    printf("%s", basic_CHR(34)); printf("%s", A_str); printf("%s", basic_CHR(34)); printf("%s", " IS AN ILLEGAL COMMAND--RETRY");
    /* BASIC: 1540 GOTO 1480 */
line_1540:;
    goto line_1480;
    /* BASIC: 1550 PRINT "GATE MAX" */
line_1550:;
    printf("%s", "GATE MAX"); printf("\n");
    /* BASIC: 1560 PRINT " #  M.P.H." */
line_1560:;
    printf("%s", " #  M.P.H."); printf("\n");
    /* BASIC: 1570 PRINT"----------" */
line_1570:;
    printf("%s", "----------"); printf("\n");
    /* BASIC: 1580 FOR B=1 TO V */
line_1580:;
    B = 1; for_loop_B_1580: if (((1) >= 0 && B > (V)) || ((1) < 0 && B < (V))) goto end_for_B_1580;
    /* BASIC: 1590 READ Q */
line_1590:;
    read_numeric(&Q);
    /* BASIC: 1600 PRINT B;"  ";Q */
line_1600:;
    printf("%g ", (double)(B)); printf("%s", "  "); printf("%g ", (double)(Q)); printf("\n");
    /* BASIC: 1610 NEXT B */
line_1610:;
    B += (1); goto for_loop_B_1580; end_for_B_1580:;
    /* BASIC: 1620 GOTO 1470 */
line_1620:;
    goto line_1470;
    /* BASIC: 1630 LET T=T+.5 */
line_1630:;
    /* UNTRANSLATED: LET T=T+.5 */
    /* BASIC: 1640 GOTO 670 */
line_1640:;
    goto line_670;
    /* BASIC: 1650 PRINT "YOU WON A GOLD MEDAL!" */
line_1650:;
    printf("%s", "YOU WON A GOLD MEDAL!"); printf("\n");
    /* BASIC: 1660 LET G(1)=G(1)+1 */
line_1660:;
    /* UNTRANSLATED: LET G(1)=G(1)+1 */
    /* BASIC: 1670 GOTO 1730 */
line_1670:;
    goto line_1730;
    /* BASIC: 1680 PRINT "YOU WON A SILVER MEDAL" */
line_1680:;
    printf("%s", "YOU WON A SILVER MEDAL"); printf("\n");
    /* BASIC: 1690 LET S(1)=S(1)+1 */
line_1690:;
    /* UNTRANSLATED: LET S(1)=S(1)+1 */
    /* BASIC: 1700 GOTO 1730 */
line_1700:;
    goto line_1730;
    /* BASIC: 1710 PRINT "YOU WON A BRONZE MEDAL" */
line_1710:;
    printf("%s", "YOU WON A BRONZE MEDAL"); printf("\n");
    /* BASIC: 1720 LET B(1)=B(1)+1 */
line_1720:;
    /* UNTRANSLATED: LET B(1)=B(1)+1 */
    /* BASIC: 1730 GOTO 740 */
line_1730:;
    goto line_740;
    /* BASIC: 1740 PRINT "THANKS FOR THE RACE" */
line_1740:;
    printf("%s", "THANKS FOR THE RACE"); printf("\n");
    /* BASIC: 1750 IF G(1)<1 THEN 1770 */
line_1750:;
    if (G_arr[(int)(1)]<1) { goto line_1770; }
    /* BASIC: 1760 PRINT "GOLD MEDALS:";G(1) */
line_1760:;
    printf("%s", "GOLD MEDALS:"); printf("%g ", (double)(G_arr[(int)(1)])); printf("\n");
    /* BASIC: 1770 IF S(1)<1 THEN 1790 */
line_1770:;
    if (S_arr[(int)(1)]<1) { goto line_1790; }
    /* BASIC: 1780 PRINT "SILVER MEDALS:";S(1) */
line_1780:;
    printf("%s", "SILVER MEDALS:"); printf("%g ", (double)(S_arr[(int)(1)])); printf("\n");
    /* BASIC: 1790 IF B(1)<1 THEN 1830 */
line_1790:;
    if (B_arr[(int)(1)]<1) { goto line_1830; }
    /* BASIC: 1800 PRINT "BRONZE MEDALS:";B(1) */
line_1800:;
    printf("%s", "BRONZE MEDALS:"); printf("%g ", (double)(B_arr[(int)(1)])); printf("\n");
    /* BASIC: 1810 DATA 14,18,26,29,18,25,28,32,29,20,29,29,25,21,26,29,20,21,20 */
line_1810:;
    /* UNTRANSLATED: DATA 14,18,26,29,18,25,28,32,29,20,29,29,25,21,26,29,20,21,20 */
    /* BASIC: 1820 DATA 18,26,25,33,31,22 */
line_1820:;
    /* UNTRANSLATED: DATA 18,26,25,33,31,22 */
    /* BASIC: 1830 END */
line_1830:;
    exit(0);

    return 0;
}
