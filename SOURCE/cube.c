/*
 * Transpiled from cube.bas
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
static double A, A1, B, B7, C, D, E, F, G, H, I, J, K, L, LET, M, N, O, P, Q, R, S, W, X, Y, Z, Z1, Z2;
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(34);"CUBE" */
line_10:;
    { int _t; for(_t=0; _t<34; _t++) printf(" "); } printf("%s", "CUBE"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT : PRINT : PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 100 PRINT "DO YOU WANT TO SEE THE INSTRUCTIONS? (YES--1,NO--0)" */
line_100:;
    printf("%s", "DO YOU WANT TO SEE THE INSTRUCTIONS? (YES--1,NO--0)"); printf("\n");
    /* BASIC: 110 INPUT B7 */
line_110:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &B7);
    /* BASIC: 120 IF B7=0 THEN 370 */
line_120:;
    if (B7==0) { goto line_370; }
    /* BASIC: 130 PRINT"THIS IS A GAME IN WHICH YOU WILL BE PLAYING AGAINST THE" */
line_130:;
    printf("%s", "THIS IS A GAME IN WHICH YOU WILL BE PLAYING AGAINST THE"); printf("\n");
    /* BASIC: 140 PRINT"RANDOM DECISION OF THE COMPUTER. THE FIELD OF PLAY IS A" */
line_140:;
    printf("%s", "RANDOM DECISION OF THE COMPUTER. THE FIELD OF PLAY IS A"); printf("\n");
    /* BASIC: 150 PRINT"CUBE OF SIDE 3. ANY OF THE 27 LOCATIONS CAN BE DESIGNATED" */
line_150:;
    printf("%s", "CUBE OF SIDE 3. ANY OF THE 27 LOCATIONS CAN BE DESIGNATED"); printf("\n");
    /* BASIC: 160 PRINT"BY INPUTING THREE NUMBERS SUCH AS 2,3,1. AT THE START," */
line_160:;
    printf("%s", "BY INPUTING THREE NUMBERS SUCH AS 2,3,1. AT THE START,"); printf("\n");
    /* BASIC: 170 PRINT"YOU ARE AUTOMATICALLY AT LOCATION 1,1,1. THE OBJECT OF" */
line_170:;
    printf("%s", "YOU ARE AUTOMATICALLY AT LOCATION 1,1,1. THE OBJECT OF"); printf("\n");
    /* BASIC: 180 PRINT"THE GAME IS TO GET TO LOCATION 3,3,3. ONE MINOR DETAIL:" */
line_180:;
    printf("%s", "THE GAME IS TO GET TO LOCATION 3,3,3. ONE MINOR DETAIL:"); printf("\n");
    /* BASIC: 190 PRINT"THE COMPUTER WILL PICK, AT RANDOM, 5 LOCATIONS AT WHICH" */
line_190:;
    printf("%s", "THE COMPUTER WILL PICK, AT RANDOM, 5 LOCATIONS AT WHICH"); printf("\n");
    /* BASIC: 200 PRINT"IT WILL PLANT LAND MINES. IF YOU HIT ONE OF THESE LOCATIONS" */
line_200:;
    printf("%s", "IT WILL PLANT LAND MINES. IF YOU HIT ONE OF THESE LOCATIONS"); printf("\n");
    /* BASIC: 210 PRINT"YOU LOSE. ONE OTHER DETAIL: YOU MAY MOVE ONLY ONE SPACE " */
line_210:;
    printf("%s", "YOU LOSE. ONE OTHER DETAIL: YOU MAY MOVE ONLY ONE SPACE "); printf("\n");
    /* BASIC: 220 PRINT"IN ONE DIRECTION EACH MOVE. FOR  EXAMPLE: FROM 1,1,2 YOU" */
line_220:;
    printf("%s", "IN ONE DIRECTION EACH MOVE. FOR  EXAMPLE: FROM 1,1,2 YOU"); printf("\n");
    /* BASIC: 230 PRINT"MAY MOVE TO 2,1,2 OR 1,1,3. YOU MAY NOT CHANGE" */
line_230:;
    printf("%s", "MAY MOVE TO 2,1,2 OR 1,1,3. YOU MAY NOT CHANGE"); printf("\n");
    /* BASIC: 240 PRINT"TWO OF THE NUMBERS ON THE SAME MOVE. IF YOU MAKE AN ILLEGAL" */
line_240:;
    printf("%s", "TWO OF THE NUMBERS ON THE SAME MOVE. IF YOU MAKE AN ILLEGAL"); printf("\n");
    /* BASIC: 250 PRINT"MOVE, YOU LOSE AND THE COMPUTER TAKES THE MONEY YOU MAY" */
line_250:;
    printf("%s", "MOVE, YOU LOSE AND THE COMPUTER TAKES THE MONEY YOU MAY"); printf("\n");
    /* BASIC: 260 PRINT"HAVE BET ON THAT ROUND." */
line_260:;
    printf("%s", "HAVE BET ON THAT ROUND."); printf("\n");
    /* BASIC: 270 PRINT */
line_270:;
    printf("\n");
    /* BASIC: 280 PRINT */
line_280:;
    printf("\n");
    /* BASIC: 290 PRINT"ALL YES OR NO QUESTIONS WILL BE ANSWERED BY A 1 FOR YES" */
line_290:;
    printf("%s", "ALL YES OR NO QUESTIONS WILL BE ANSWERED BY A 1 FOR YES"); printf("\n");
    /* BASIC: 300 PRINT"OR A 0 (ZERO) FOR NO." */
line_300:;
    printf("%s", "OR A 0 (ZERO) FOR NO."); printf("\n");
    /* BASIC: 310 PRINT */
line_310:;
    printf("\n");
    /* BASIC: 320 PRINT"WHEN STATING THE AMOUNT OF A WAGER, PRINT ONLY THE NUMBER" */
line_320:;
    printf("%s", "WHEN STATING THE AMOUNT OF A WAGER, PRINT ONLY THE NUMBER"); printf("\n");
    /* BASIC: 330 PRINT"OF DOLLARS (EXAMPLE: 250)  YOU ARE AUTOMATICALLY STARTED WITH" */
line_330:;
    printf("%s", "OF DOLLARS (EXAMPLE: 250)  YOU ARE AUTOMATICALLY STARTED WITH"); printf("\n");
    /* BASIC: 340 PRINT"500 DOLLARS IN YOUR ACCOUNT." */
line_340:;
    printf("%s", "500 DOLLARS IN YOUR ACCOUNT."); printf("\n");
    /* BASIC: 350 PRINT */
line_350:;
    printf("\n");
    /* BASIC: 360 PRINT "GOOD LUCK!" */
line_360:;
    printf("%s", "GOOD LUCK!"); printf("\n");
    /* BASIC: 370 LET A1=500 */
line_370:;
    /* UNTRANSLATED: LET A1=500 */
    /* BASIC: 380 LET A=INT(3*(RND(X))) */
line_380:;
    /* UNTRANSLATED: LET A=INT(3*(RND(X))) */
    /* BASIC: 390 IF A<>0 THEN 410 */
line_390:;
    if (A!=0) { goto line_410; }
    /* BASIC: 400 LET A=3 */
line_400:;
    /* UNTRANSLATED: LET A=3 */
    /* BASIC: 410 LET B=INT(3*(RND(X))) */
line_410:;
    /* UNTRANSLATED: LET B=INT(3*(RND(X))) */
    /* BASIC: 420 IF B<>0 THEN 440 */
line_420:;
    if (B!=0) { goto line_440; }
    /* BASIC: 430 LET B=2 */
line_430:;
    /* UNTRANSLATED: LET B=2 */
    /* BASIC: 440 LET C=INT(3*(RND(X))) */
line_440:;
    /* UNTRANSLATED: LET C=INT(3*(RND(X))) */
    /* BASIC: 450 IF C<>0 THEN 470 */
line_450:;
    if (C!=0) { goto line_470; }
    /* BASIC: 460 LET C=3 */
line_460:;
    /* UNTRANSLATED: LET C=3 */
    /* BASIC: 470 LET D=INT(3*(RND(X))) */
line_470:;
    /* UNTRANSLATED: LET D=INT(3*(RND(X))) */
    /* BASIC: 480 IF D<>0 THEN 500 */
line_480:;
    if (D!=0) { goto line_500; }
    /* BASIC: 490 LET D=1 */
line_490:;
    /* UNTRANSLATED: LET D=1 */
    /* BASIC: 500 LET E=INT(3*(RND(X))) */
line_500:;
    /* UNTRANSLATED: LET E=INT(3*(RND(X))) */
    /* BASIC: 510 IF E<>0 THEN 530 */
line_510:;
    if (E!=0) { goto line_530; }
    /* BASIC: 520 LET E=3 */
line_520:;
    /* UNTRANSLATED: LET E=3 */
    /* BASIC: 530 LET F=INT(3*(RND(X))) */
line_530:;
    /* UNTRANSLATED: LET F=INT(3*(RND(X))) */
    /* BASIC: 540 IF F<>0 THEN 560 */
line_540:;
    if (F!=0) { goto line_560; }
    /* BASIC: 550 LET F=3 */
line_550:;
    /* UNTRANSLATED: LET F=3 */
    /* BASIC: 560 LET G=INT(3*(RND(X))) */
line_560:;
    /* UNTRANSLATED: LET G=INT(3*(RND(X))) */
    /* BASIC: 570 IF G<>0 THEN 590 */
line_570:;
    if (G!=0) { goto line_590; }
    /* BASIC: 580 LET G=3 */
line_580:;
    /* UNTRANSLATED: LET G=3 */
    /* BASIC: 590 LET H=INT(3*(RND(X))) */
line_590:;
    /* UNTRANSLATED: LET H=INT(3*(RND(X))) */
    /* BASIC: 600 IF H<>0 THEN 620 */
line_600:;
    if (H!=0) { goto line_620; }
    /* BASIC: 610 LET H=3 */
line_610:;
    /* UNTRANSLATED: LET H=3 */
    /* BASIC: 620 LET I=INT(3*(RND(X))) */
line_620:;
    /* UNTRANSLATED: LET I=INT(3*(RND(X))) */
    /* BASIC: 630 IF I<>0 THEN 650 */
line_630:;
    if (I!=0) { goto line_650; }
    /* BASIC: 640 LET I=2 */
line_640:;
    /* UNTRANSLATED: LET I=2 */
    /* BASIC: 650 LET J=INT(3*(RND(X))) */
line_650:;
    /* UNTRANSLATED: LET J=INT(3*(RND(X))) */
    /* BASIC: 660 IF J<>0 THEN 680 */
line_660:;
    if (J!=0) { goto line_680; }
    /* BASIC: 670 LET J=3 */
line_670:;
    /* UNTRANSLATED: LET J=3 */
    /* BASIC: 680 LET K=INT(3*(RND(X))) */
line_680:;
    /* UNTRANSLATED: LET K=INT(3*(RND(X))) */
    /* BASIC: 690 IF K<>0 THEN 710 */
line_690:;
    if (K!=0) { goto line_710; }
    /* BASIC: 700 LET K=2 */
line_700:;
    /* UNTRANSLATED: LET K=2 */
    /* BASIC: 710 LET L=INT(3*(RND(X))) */
line_710:;
    /* UNTRANSLATED: LET L=INT(3*(RND(X))) */
    /* BASIC: 720 IF L<>0 THEN 740 */
line_720:;
    if (L!=0) { goto line_740; }
    /* BASIC: 730 LET L=3 */
line_730:;
    /* UNTRANSLATED: LET L=3 */
    /* BASIC: 740 LET M=INT(3*(RND(X))) */
line_740:;
    /* UNTRANSLATED: LET M=INT(3*(RND(X))) */
    /* BASIC: 750 IF M<>0 THEN 770 */
line_750:;
    if (M!=0) { goto line_770; }
    /* BASIC: 760 LET M=3 */
line_760:;
    /* UNTRANSLATED: LET M=3 */
    /* BASIC: 770 LET N=INT(3*(RND(X))) */
line_770:;
    /* UNTRANSLATED: LET N=INT(3*(RND(X))) */
    /* BASIC: 780 IF N<>0 THEN 800 */
line_780:;
    if (N!=0) { goto line_800; }
    /* BASIC: 790 LET N=1 */
line_790:;
    /* UNTRANSLATED: LET N=1 */
    /* BASIC: 800 LET O=INT (3*(RND(X))) */
line_800:;
    /* UNTRANSLATED: LET O=INT (3*(RND(X))) */
    /* BASIC: 810 IF O <>0 THEN 830 */
line_810:;
    if (O !=0) { goto line_830; }
    /* BASIC: 820 LET O=3 */
line_820:;
    /* UNTRANSLATED: LET O=3 */
    /* BASIC: 830 PRINT "WANT TO MAKE A WAGER?" */
line_830:;
    printf("%s", "WANT TO MAKE A WAGER?"); printf("\n");
    /* BASIC: 840 INPUT Z */
line_840:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &Z);
    /* BASIC: 850 IF Z=0 THEN 920 */
line_850:;
    if (Z==0) { goto line_920; }
    /* BASIC: 860 PRINT "HOW MUCH "; */
line_860:;
    printf("%s", "HOW MUCH ");
    /* BASIC: 870 INPUT Z1 */
line_870:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &Z1);
    /* BASIC: 876 IF A1<Z1 THEN 1522 */
line_876:;
    if (A1<Z1) { goto line_1522; }
    /* BASIC: 880 LET W=1 */
line_880:;
    /* UNTRANSLATED: LET W=1 */
    /* BASIC: 890 LET X=1 */
line_890:;
    /* UNTRANSLATED: LET X=1 */
    /* BASIC: 900 LET Y=1 */
line_900:;
    /* UNTRANSLATED: LET Y=1 */
    /* BASIC: 910 PRINT */
line_910:;
    printf("\n");
    /* BASIC: 920 PRINT "IT'S YOUR MOVE:  "; */
line_920:;
    printf("%s", "IT'S YOUR MOVE:  ");
    /* BASIC: 930 INPUT P,Q,R */
line_930:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf %lf", &P, &Q, &R);
    /* BASIC: 940 IF P>W+1 THEN 1030 */
line_940:;
    if (P>W+1) { goto line_1030; }
    /* BASIC: 950 IF P=W+1 THEN 1000 */
line_950:;
    if (P==W+1) { goto line_1000; }
    /* BASIC: 960 IF Q>X+1 THEN 1030 */
line_960:;
    if (Q>X+1) { goto line_1030; }
    /* BASIC: 970 IF Q=(X+1) THEN 1010 */
line_970:;
    if (Q==(X+1)) { goto line_1010; }
    /* BASIC: 980 IF R >(Y+1)  THEN 1030 */
line_980:;
    if (R >(Y+1)) { goto line_1030; }
    /* BASIC: 990 GOTO 1050 */
line_990:;
    goto line_1050;
    /* BASIC: 1000 IF Q>= X+1 THEN 1030 */
line_1000:;
    if (Q>= X+1) { goto line_1030; }
    /* BASIC: 1010 IF R>=Y+1 THEN 1030 */
line_1010:;
    if (R>=Y+1) { goto line_1030; }
    /* BASIC: 1020 GOTO 1050 */
line_1020:;
    goto line_1050;
    /* BASIC: 1030 PRINT:PRINT "ILLEGAL MOVE. YOU LOSE." */
line_1030:;
    printf("\n");
    printf("%s", "ILLEGAL MOVE. YOU LOSE."); printf("\n");
    /* BASIC: 1040 GOTO 1440 */
line_1040:;
    goto line_1440;
    /* BASIC: 1050 LET W=P */
line_1050:;
    /* UNTRANSLATED: LET W=P */
    /* BASIC: 1060 LET X=Q */
line_1060:;
    /* UNTRANSLATED: LET X=Q */
    /* BASIC: 1070 LET Y=R */
line_1070:;
    /* UNTRANSLATED: LET Y=R */
    /* BASIC: 1080 IF P=3 THEN 1100 */
line_1080:;
    if (P==3) { goto line_1100; }
    /* BASIC: 1090 GOTO 1130 */
line_1090:;
    goto line_1130;
    /* BASIC: 1100 IF  Q=3 THEN 1120 */
line_1100:;
    if (Q==3) { goto line_1120; }
    /* BASIC: 1110 GOTO 1130 */
line_1110:;
    goto line_1130;
    /* BASIC: 1120 IF R=3 THEN 1530 */
line_1120:;
    if (R==3) { goto line_1530; }
    /* BASIC: 1130 IF P=A THEN 1150 */
line_1130:;
    if (P==A) { goto line_1150; }
    /* BASIC: 1140 GOTO 1180 */
line_1140:;
    goto line_1180;
    /* BASIC: 1150 IF Q=B THEN 1170 */
line_1150:;
    if (Q==B) { goto line_1170; }
    /* BASIC: 1160 GOTO 1180 */
line_1160:;
    goto line_1180;
    /* BASIC: 1170 IF R=C THEN 1400 */
line_1170:;
    if (R==C) { goto line_1400; }
    /* BASIC: 1180 IF P=D THEN 1200 */
line_1180:;
    if (P==D) { goto line_1200; }
    /* BASIC: 1190 GOTO 1230 */
line_1190:;
    goto line_1230;
    /* BASIC: 1200 IF Q=E THEN 1220 */
line_1200:;
    if (Q==E) { goto line_1220; }
    /* BASIC: 1210 GOTO 1230 */
line_1210:;
    goto line_1230;
    /* BASIC: 1220 IF  R=F THEN 1400 */
line_1220:;
    if (R==F) { goto line_1400; }
    /* BASIC: 1230 IF P=G THEN 1250 */
line_1230:;
    if (P==G) { goto line_1250; }
    /* BASIC: 1240 GOTO 1280 */
line_1240:;
    goto line_1280;
    /* BASIC: 1250 IF Q=H THEN 1270 */
line_1250:;
    if (Q==H) { goto line_1270; }
    /* BASIC: 1260 GOTO 1280 */
line_1260:;
    goto line_1280;
    /* BASIC: 1270 IF R=I THEN 1400 */
line_1270:;
    if (R==I) { goto line_1400; }
    /* BASIC: 1280 IF P=J THEN 1300 */
line_1280:;
    if (P==J) { goto line_1300; }
    /* BASIC: 1290 GOTO 1330 */
line_1290:;
    goto line_1330;
    /* BASIC: 1300 IF Q=K THEN 1320 */
line_1300:;
    if (Q==K) { goto line_1320; }
    /* BASIC: 1310 GOTO 1330 */
line_1310:;
    goto line_1330;
    /* BASIC: 1320 IF R=L THEN 1440 */
line_1320:;
    if (R==L) { goto line_1440; }
    /* BASIC: 1330 IF P=M THEN 1350 */
line_1330:;
    if (P==M) { goto line_1350; }
    /* BASIC: 1340 GOTO 1380 */
line_1340:;
    goto line_1380;
    /* BASIC: 1350 IF Q=N THEN 1370 */
line_1350:;
    if (Q==N) { goto line_1370; }
    /* BASIC: 1360 GOTO 1380 */
line_1360:;
    goto line_1380;
    /* BASIC: 1370 IF R=O THEN 1400 */
line_1370:;
    if (R==O) { goto line_1400; }
    /* BASIC: 1380 PRINT "NEXT MOVE: "; */
line_1380:;
    printf("%s", "NEXT MOVE: ");
    /* BASIC: 1390 GOTO 930 */
line_1390:;
    goto line_930;
    /* BASIC: 1400 PRINT"******BANG******" */
line_1400:;
    printf("%s", "******BANG******"); printf("\n");
    /* BASIC: 1410 PRINT "YOU LOSE!" */
line_1410:;
    printf("%s", "YOU LOSE!"); printf("\n");
    /* BASIC: 1420 PRINT */
line_1420:;
    printf("\n");
    /* BASIC: 1430 PRINT */
line_1430:;
    printf("\n");
    /* BASIC: 1440 IF   Z=0 THEN 1580 */
line_1440:;
    if (Z==0) { goto line_1580; }
    /* BASIC: 1450 PRINT */
line_1450:;
    printf("\n");
    /* BASIC: 1460 LET Z2=A1-Z1 */
line_1460:;
    /* UNTRANSLATED: LET Z2=A1-Z1 */
    /* BASIC: 1470 IF Z2>0 THEN 1500 */
line_1470:;
    if (Z2>0) { goto line_1500; }
    /* BASIC: 1480 PRINT "YOU BUST." */
line_1480:;
    printf("%s", "YOU BUST."); printf("\n");
    /* BASIC: 1490 GOTO 1610 */
line_1490:;
    goto line_1610;
    /* BASIC: 1500 PRINT " YOU NOW HAVE"; Z2; "DOLLARS." */
line_1500:;
    printf("%s", " YOU NOW HAVE"); printf("%g ", (double)(Z2)); printf("%s", "DOLLARS."); printf("\n");
    /* BASIC: 1510 LET A1=Z2 */
line_1510:;
    /* UNTRANSLATED: LET A1=Z2 */
    /* BASIC: 1520 GOTO 1580 */
line_1520:;
    goto line_1580;
    /* BASIC: 1522 PRINT"TRIED TO FOOL ME; BET AGAIN"; */
line_1522:;
    printf("%s", "TRIED TO FOOL ME; BET AGAIN");
    /* BASIC: 1525 GOTO 870 */
line_1525:;
    goto line_870;
    /* BASIC: 1530 PRINT"CONGRATULATIONS!" */
line_1530:;
    printf("%s", "CONGRATULATIONS!"); printf("\n");
    /* BASIC: 1540 IF Z=0 THEN 1580 */
line_1540:;
    if (Z==0) { goto line_1580; }
    /* BASIC: 1550 LET Z2=A1+Z1 */
line_1550:;
    /* UNTRANSLATED: LET Z2=A1+Z1 */
    /* BASIC: 1560 PRINT "YOU NOW HAVE"; Z2;"DOLLARS." */
line_1560:;
    printf("%s", "YOU NOW HAVE"); printf("%g ", (double)(Z2)); printf("%s", "DOLLARS."); printf("\n");
    /* BASIC: 1570 LET A1=Z2 */
line_1570:;
    /* UNTRANSLATED: LET A1=Z2 */
    /* BASIC: 1580 PRINT"DO YOU WANT TO TRY AGAIN "; */
line_1580:;
    printf("%s", "DO YOU WANT TO TRY AGAIN ");
    /* BASIC: 1590 INPUT S */
line_1590:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &S);
    /* BASIC: 1600 IF S=1 THEN 380 */
line_1600:;
    if (S==1) { goto line_380; }
    /* BASIC: 1610 PRINT "TOUGH LUCK!" */
line_1610:;
    printf("%s", "TOUGH LUCK!"); printf("\n");
    /* BASIC: 1620 PRINT */
line_1620:;
    printf("\n");
    /* BASIC: 1630 PRINT "GOODBYE." */
line_1630:;
    printf("%s", "GOODBYE."); printf("\n");
    /* BASIC: 1640 END */
line_1640:;
    exit(0);

    return 0;
}
