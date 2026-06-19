/*
 * Transpiled from aceyducey.bas
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

/* Global variables */
static double A, B, C, M, N, Q;
static char A_str[256] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(26);"ACEY DUCEY CARD GAME" */
line_10:;
    { int _t; for(_t=0; _t<26; _t++) printf(" "); } printf("%s", "ACEY DUCEY CARD GAME"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 21 PRINT */
line_21:;
    printf("\n");
    /* BASIC: 22 PRINT */
line_22:;
    printf("\n");
    /* BASIC: 30 PRINT"ACEY-DUCEY IS PLAYED IN THE FOLLOWING MANNER " */
line_30:;
    printf("%s", "ACEY-DUCEY IS PLAYED IN THE FOLLOWING MANNER "); printf("\n");
    /* BASIC: 40 PRINT"THE DEALER (COMPUTER) DEALS TWO CARDS FACE UP" */
line_40:;
    printf("%s", "THE DEALER (COMPUTER) DEALS TWO CARDS FACE UP"); printf("\n");
    /* BASIC: 50 PRINT"YOU HAVE AN OPTION TO BET OR NOT BET DEPENDING" */
line_50:;
    printf("%s", "YOU HAVE AN OPTION TO BET OR NOT BET DEPENDING"); printf("\n");
    /* BASIC: 60 PRINT"ON WHETHER OR NOT YOU FEEL THE CARD WILL HAVE" */
line_60:;
    printf("%s", "ON WHETHER OR NOT YOU FEEL THE CARD WILL HAVE"); printf("\n");
    /* BASIC: 70 PRINT"A VALUE BETWEEN THE FIRST TWO." */
line_70:;
    printf("%s", "A VALUE BETWEEN THE FIRST TWO."); printf("\n");
    /* BASIC: 80 PRINT"IF YOU DO NOT WANT TO BET, INPUT A 0" */
line_80:;
    printf("%s", "IF YOU DO NOT WANT TO BET, INPUT A 0"); printf("\n");
    /* BASIC: 100 N=100 */
line_100:;
    N = 100;
    /* BASIC: 110 Q=100 */
line_110:;
    Q = 100;
    /* BASIC: 120 PRINT "YOU NOW HAVE";Q;"DOLLARS." */
line_120:;
    printf("%s", "YOU NOW HAVE"); printf("%g ", (double)(Q)); printf("%s", "DOLLARS."); printf("\n");
    /* BASIC: 130 PRINT */
line_130:;
    printf("\n");
    /* BASIC: 140 GOTO 260 */
line_140:;
    goto line_260;
    /* BASIC: 210 Q=Q+M */
line_210:;
    Q = Q+M;
    /* BASIC: 220 GOTO 120 */
line_220:;
    goto line_120;
    /* BASIC: 240 Q=Q-M */
line_240:;
    Q = Q-M;
    /* BASIC: 250 GOTO 120 */
line_250:;
    goto line_120;
    /* BASIC: 260 PRINT"HERE ARE YOUR NEXT TWO CARDS: " */
line_260:;
    printf("%s", "HERE ARE YOUR NEXT TWO CARDS: "); printf("\n");
    /* BASIC: 270 A=INT(14*RND(1))+2 */
line_270:;
    A = floor(14*((double)rand() / (double)RAND_MAX))+2;
    /* BASIC: 280 IF A<2 THEN 270 */
line_280:;
    if (A<2) { goto line_270; }
    /* BASIC: 290 IF A>14 THEN 270 */
line_290:;
    if (A>14) { goto line_270; }
    /* BASIC: 300 B=INT(14*RND(1))+2 */
line_300:;
    B = floor(14*((double)rand() / (double)RAND_MAX))+2;
    /* BASIC: 310 IF B<2 THEN 300 */
line_310:;
    if (B<2) { goto line_300; }
    /* BASIC: 320 IF B>14 THEN 300 */
line_320:;
    if (B>14) { goto line_300; }
    /* BASIC: 330 IF A>=B THEN 270 */
line_330:;
    if (A>=B) { goto line_270; }
    /* BASIC: 350 IF A<11 THEN 400 */
line_350:;
    if (A<11) { goto line_400; }
    /* BASIC: 360 IF A=11 THEN 420 */
line_360:;
    if (A==11) { goto line_420; }
    /* BASIC: 370 IF A=12 THEN 440 */
line_370:;
    if (A==12) { goto line_440; }
    /* BASIC: 380 IF A=13 THEN 460 */
line_380:;
    if (A==13) { goto line_460; }
    /* BASIC: 390 IF A=14 THEN 480 */
line_390:;
    if (A==14) { goto line_480; }
    /* BASIC: 400 PRINT A */
line_400:;
    printf("%g ", (double)(A)); printf("\n");
    /* BASIC: 410 GOTO 500 */
line_410:;
    goto line_500;
    /* BASIC: 420 PRINT"JACK" */
line_420:;
    printf("%s", "JACK"); printf("\n");
    /* BASIC: 430 GOTO 500 */
line_430:;
    goto line_500;
    /* BASIC: 440 PRINT"QUEEN" */
line_440:;
    printf("%s", "QUEEN"); printf("\n");
    /* BASIC: 450 GOTO 500 */
line_450:;
    goto line_500;
    /* BASIC: 460 PRINT"KING" */
line_460:;
    printf("%s", "KING"); printf("\n");
    /* BASIC: 470 GOTO 500 */
line_470:;
    goto line_500;
    /* BASIC: 480 PRINT"ACE" */
line_480:;
    printf("%s", "ACE"); printf("\n");
    /* BASIC: 500 IF B<11 THEN 550 */
line_500:;
    if (B<11) { goto line_550; }
    /* BASIC: 510 IF B=11 THEN 570 */
line_510:;
    if (B==11) { goto line_570; }
    /* BASIC: 520 IF B=12 THEN 590 */
line_520:;
    if (B==12) { goto line_590; }
    /* BASIC: 530 IF B=13 THEN 610 */
line_530:;
    if (B==13) { goto line_610; }
    /* BASIC: 540 IF B=14 THEN 630 */
line_540:;
    if (B==14) { goto line_630; }
    /* BASIC: 550 PRINT B */
line_550:;
    printf("%g ", (double)(B)); printf("\n");
    /* BASIC: 560 GOTO 650 */
line_560:;
    goto line_650;
    /* BASIC: 570 PRINT"JACK" */
line_570:;
    printf("%s", "JACK"); printf("\n");
    /* BASIC: 580 GOTO 650 */
line_580:;
    goto line_650;
    /* BASIC: 590 PRINT"QUEEN" */
line_590:;
    printf("%s", "QUEEN"); printf("\n");
    /* BASIC: 600 GOTO 650 */
line_600:;
    goto line_650;
    /* BASIC: 610 PRINT"KING" */
line_610:;
    printf("%s", "KING"); printf("\n");
    /* BASIC: 620 GOTO 650 */
line_620:;
    goto line_650;
    /* BASIC: 630 PRINT"ACE" */
line_630:;
    printf("%s", "ACE"); printf("\n");
    /* BASIC: 640 PRINT */
line_640:;
    printf("\n");
    /* BASIC: 650 PRINT */
line_650:;
    printf("\n");
    /* BASIC: 660 INPUT"WHAT IS YOUR BET";M */
line_660:;
    printf("%s", "WHAT IS YOUR BET"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &M);
    /* BASIC: 670 IF M<>0 THEN 680 */
line_670:;
    if (M!=0) { goto line_680; }
    /* BASIC: 675 PRINT"CHICKEN!!" */
line_675:;
    printf("%s", "CHICKEN!!"); printf("\n");
    /* BASIC: 676 PRINT */
line_676:;
    printf("\n");
    /* BASIC: 677 GOTO 260 */
line_677:;
    goto line_260;
    /* BASIC: 680 IF M<=Q THEN 730 */
line_680:;
    if (M<=Q) { goto line_730; }
    /* BASIC: 690 PRINT"SORRY, MY FRIEND, BUT YOU BET TOO MUCH." */
line_690:;
    printf("%s", "SORRY, MY FRIEND, BUT YOU BET TOO MUCH."); printf("\n");
    /* BASIC: 700 PRINT"YOU HAVE ONLY ";Q;" DOLLARS TO BET." */
line_700:;
    printf("%s", "YOU HAVE ONLY "); printf("%g ", (double)(Q)); printf("%s", " DOLLARS TO BET."); printf("\n");
    /* BASIC: 710 GOTO 650 */
line_710:;
    goto line_650;
    /* BASIC: 730 C=INT(14*RND(1))+2 */
line_730:;
    C = floor(14*((double)rand() / (double)RAND_MAX))+2;
    /* BASIC: 740 IF C<2 THEN 730 */
line_740:;
    if (C<2) { goto line_730; }
    /* BASIC: 750 IF C>14 THEN 730 */
line_750:;
    if (C>14) { goto line_730; }
    /* BASIC: 760 IF C<11 THEN 810 */
line_760:;
    if (C<11) { goto line_810; }
    /* BASIC: 770 IF C=11 THEN 830 */
line_770:;
    if (C==11) { goto line_830; }
    /* BASIC: 780 IF C=12 THEN 850 */
line_780:;
    if (C==12) { goto line_850; }
    /* BASIC: 790 IF C=13 THEN 870 */
line_790:;
    if (C==13) { goto line_870; }
    /* BASIC: 800 IF C=14 THEN 890 */
line_800:;
    if (C==14) { goto line_890; }
    /* BASIC: 810 PRINT C */
line_810:;
    printf("%g ", (double)(C)); printf("\n");
    /* BASIC: 820 GOTO 910 */
line_820:;
    goto line_910;
    /* BASIC: 830 PRINT"JACK" */
line_830:;
    printf("%s", "JACK"); printf("\n");
    /* BASIC: 840 GOTO 910 */
line_840:;
    goto line_910;
    /* BASIC: 850 PRINT"QUEEN" */
line_850:;
    printf("%s", "QUEEN"); printf("\n");
    /* BASIC: 860 GOTO 910 */
line_860:;
    goto line_910;
    /* BASIC: 870 PRINT"KING" */
line_870:;
    printf("%s", "KING"); printf("\n");
    /* BASIC: 880 GOTO 910 */
line_880:;
    goto line_910;
    /* BASIC: 890 PRINT "ACE" */
line_890:;
    printf("%s", "ACE"); printf("\n");
    /* BASIC: 900 PRINT */
line_900:;
    printf("\n");
    /* BASIC: 910 IF C>A THEN 930 */
line_910:;
    if (C>A) { goto line_930; }
    /* BASIC: 920 GOTO 970 */
line_920:;
    goto line_970;
    /* BASIC: 930 IF C>=B THEN 970 */
line_930:;
    if (C>=B) { goto line_970; }
    /* BASIC: 950 PRINT"YOU WIN!!!" */
line_950:;
    printf("%s", "YOU WIN!!!"); printf("\n");
    /* BASIC: 960 GOTO 210 */
line_960:;
    goto line_210;
    /* BASIC: 970 PRINT"SORRY, YOU LOSE" */
line_970:;
    printf("%s", "SORRY, YOU LOSE"); printf("\n");
    /* BASIC: 980 IF M<Q THEN 240 */
line_980:;
    if (M<Q) { goto line_240; }
    /* BASIC: 990 PRINT */
line_990:;
    printf("\n");
    /* BASIC: 1000 PRINT */
line_1000:;
    printf("\n");
    /* BASIC: 1010 PRINT"SORRY, FRIEND, BUT YOU BLEW YOUR WAD." */
line_1010:;
    printf("%s", "SORRY, FRIEND, BUT YOU BLEW YOUR WAD."); printf("\n");
    /* BASIC: 1015 PRINT:PRINT */
line_1015:;
    printf("\n");
    printf("\n");
    /* BASIC: 1020 INPUT"TRY AGAIN (YES OR NO)";A$ */
line_1020:;
    printf("%s", "TRY AGAIN (YES OR NO)"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    /* BASIC: 1025 PRINT:PRINT */
line_1025:;
    printf("\n");
    printf("\n");
    /* BASIC: 1030 IF A$="YES" THEN 110 */
line_1030:;
    if (strcmp(A_str, "YES") == 0) { goto line_110; }
    /* BASIC: 1040 PRINT"O.K., HOPE YOU HAD FUN!" */
line_1040:;
    printf("%s", "O.K., HOPE YOU HAD FUN!"); printf("\n");
    /* BASIC: 1050 END */
line_1050:;
    exit(0);

    return 0;
}
