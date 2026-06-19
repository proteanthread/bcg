/*
 * Transpiled from amazing.bas
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
static double C, H, I, J, ON, Q, R, S, V, W, X, Z;
static double V_arr[2000] = {0};
static double W_arr[2000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(28);"AMAZING PROGRAM" */
line_10:;
    { int _t; for(_t=0; _t<28; _t++) printf(" "); } printf("%s", "AMAZING PROGRAM"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT:PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 100 INPUT "WHAT ARE YOUR WIDTH AND LENGTH";H,V */
line_100:;
    printf("%s", "WHAT ARE YOUR WIDTH AND LENGTH"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf", &H, &V);
    /* BASIC: 102 IF H<>1 AND V<>1 THEN 110 */
line_102:;
    if (H!=1   &&   V!=1) { goto line_110; }
    /* BASIC: 104 PRINT "MEANINGLESS DIMENSIONS.  TRY AGAIN.":GOTO 100 */
line_104:;
    printf("%s", "MEANINGLESS DIMENSIONS.  TRY AGAIN."); printf("\n");
    goto line_100;
    /* BASIC: 110 DIM W(H,V),V(H,V) */
line_110:;
    /* DIM W(H,V),V(H,V) (handled statically) */
    /* BASIC: 120 PRINT */
line_120:;
    printf("\n");
    /* BASIC: 130 PRINT */
line_130:;
    printf("\n");
    /* BASIC: 140 PRINT */
line_140:;
    printf("\n");
    /* BASIC: 150 PRINT */
line_150:;
    printf("\n");
    /* BASIC: 160 Q=0:Z=0:X=INT(RND(1)*H+1) */
line_160:;
    Q = 0;
    Z = 0;
    X = floor(((double)rand() / (double)RAND_MAX)*H+1);
    /* BASIC: 165 FOR I=1 TO H */
line_165:;
    I = 1; for_loop_I_165: if (((1) >= 0 && I > (H)) || ((1) < 0 && I < (H))) goto end_for_I_165;
    /* BASIC: 170 IF I=X THEN 173 */
line_170:;
    if (I==X) { goto line_173; }
    /* BASIC: 171 PRINT ".--";:GOTO 180 */
line_171:;
    printf("%s", ".--");
    goto line_180;
    /* BASIC: 173 PRINT ".  "; */
line_173:;
    printf("%s", ".  ");
    /* BASIC: 180 NEXT I */
line_180:;
    I += (1); goto for_loop_I_165; end_for_I_165:;
    /* BASIC: 190 PRINT "." */
line_190:;
    printf("%s", "."); printf("\n");
    /* BASIC: 195 C=1:W(X,1)=C:C=C+1 */
line_195:;
    C = 1;
    W_arr[(int)(X) * 100 + (int)(1)] = C;
    C = C+1;
    /* BASIC: 200 R=X:S=1:GOTO 260 */
line_200:;
    R = X;
    S = 1;
    goto line_260;
    /* BASIC: 210 IF R<>H THEN 240 */
line_210:;
    if (R!=H) { goto line_240; }
    /* BASIC: 215 IF S<>V THEN 230 */
line_215:;
    if (S!=V) { goto line_230; }
    /* BASIC: 220 R=1:S=1:GOTO 250 */
line_220:;
    R = 1;
    S = 1;
    goto line_250;
    /* BASIC: 230 R=1:S=S+1:GOTO 250 */
line_230:;
    R = 1;
    S = S+1;
    goto line_250;
    /* BASIC: 240 R=R+1 */
line_240:;
    R = R+1;
    /* BASIC: 250 IF W(R,S)=0 THEN 210 */
line_250:;
    if (W_arr[(int)(R) * 100 + (int)(S)]==0) { goto line_210; }
    /* BASIC: 260 IF R-1=0 THEN 530 */
line_260:;
    if (R-1==0) { goto line_530; }
    /* BASIC: 265 IF W(R-1,S)<>0 THEN 530 */
line_265:;
    if (W_arr[(int)(R-1) * 100 + (int)(S)]!=0) { goto line_530; }
    /* BASIC: 270 IF S-1=0 THEN 390 */
line_270:;
    if (S-1==0) { goto line_390; }
    /* BASIC: 280 IF W(R,S-1)<>0 THEN 390 */
line_280:;
    if (W_arr[(int)(R) * 100 + (int)(S-1)]!=0) { goto line_390; }
    /* BASIC: 290 IF R=H THEN 330 */
line_290:;
    if (R==H) { goto line_330; }
    /* BASIC: 300 IF W(R+1,S)<>0 THEN 330 */
line_300:;
    if (W_arr[(int)(R+1) * 100 + (int)(S)]!=0) { goto line_330; }
    /* BASIC: 310 X=INT(RND(1)*3+1) */
line_310:;
    X = floor(((double)rand() / (double)RAND_MAX)*3+1);
    /* BASIC: 320 ON X GOTO 790,820,860 */
line_320:;
    switch ((int)(X)) {     case 1: goto line_790;     case 2: goto line_820;     case 3: goto line_860; }
    /* BASIC: 330 IF S<>V THEN 340 */
line_330:;
    if (S!=V) { goto line_340; }
    /* BASIC: 334 IF Z=1 THEN 370 */
line_334:;
    if (Z==1) { goto line_370; }
    /* BASIC: 338 Q=1:GOTO 350 */
line_338:;
    Q = 1;
    goto line_350;
    /* BASIC: 340 IF W(R,S+1)<>0 THEN 370 */
line_340:;
    if (W_arr[(int)(R) * 100 + (int)(S+1)]!=0) { goto line_370; }
    /* BASIC: 350 X=INT(RND(1)*3+1) */
line_350:;
    X = floor(((double)rand() / (double)RAND_MAX)*3+1);
    /* BASIC: 360 ON X GOTO 790,820,910 */
line_360:;
    switch ((int)(X)) {     case 1: goto line_790;     case 2: goto line_820;     case 3: goto line_910; }
    /* BASIC: 370 X=INT(RND(1)*2+1) */
line_370:;
    X = floor(((double)rand() / (double)RAND_MAX)*2+1);
    /* BASIC: 380 ON X GOTO 790,820 */
line_380:;
    switch ((int)(X)) {     case 1: goto line_790;     case 2: goto line_820; }
    /* BASIC: 390 IF R=H THEN 470 */
line_390:;
    if (R==H) { goto line_470; }
    /* BASIC: 400 IF W(R+1,S)<>0 THEN 470 */
line_400:;
    if (W_arr[(int)(R+1) * 100 + (int)(S)]!=0) { goto line_470; }
    /* BASIC: 405 IF S<>V THEN 420 */
line_405:;
    if (S!=V) { goto line_420; }
    /* BASIC: 410 IF Z=1 THEN 450 */
line_410:;
    if (Z==1) { goto line_450; }
    /* BASIC: 415 Q=1:GOTO 430 */
line_415:;
    Q = 1;
    goto line_430;
    /* BASIC: 420 IF W(R,S+1)<>0 THEN 450 */
line_420:;
    if (W_arr[(int)(R) * 100 + (int)(S+1)]!=0) { goto line_450; }
    /* BASIC: 430 X=INT(RND(1)*3+1) */
line_430:;
    X = floor(((double)rand() / (double)RAND_MAX)*3+1);
    /* BASIC: 440 ON X GOTO 790,860,910 */
line_440:;
    switch ((int)(X)) {     case 1: goto line_790;     case 2: goto line_860;     case 3: goto line_910; }
    /* BASIC: 450 X=INT(RND(1)*2+1) */
line_450:;
    X = floor(((double)rand() / (double)RAND_MAX)*2+1);
    /* BASIC: 460 ON X GOTO 790,860 */
line_460:;
    switch ((int)(X)) {     case 1: goto line_790;     case 2: goto line_860; }
    /* BASIC: 470 IF S<>V THEN 490 */
line_470:;
    if (S!=V) { goto line_490; }
    /* BASIC: 480 IF Z=1 THEN 520 */
line_480:;
    if (Z==1) { goto line_520; }
    /* BASIC: 485 Q=1:GOTO 500 */
line_485:;
    Q = 1;
    goto line_500;
    /* BASIC: 490 IF W(R,S+1)<>0 THEN 520 */
line_490:;
    if (W_arr[(int)(R) * 100 + (int)(S+1)]!=0) { goto line_520; }
    /* BASIC: 500 X=INT(RND(1)*2+1) */
line_500:;
    X = floor(((double)rand() / (double)RAND_MAX)*2+1);
    /* BASIC: 510 ON X GOTO 790,910 */
line_510:;
    switch ((int)(X)) {     case 1: goto line_790;     case 2: goto line_910; }
    /* BASIC: 520 GOTO 790 */
line_520:;
    goto line_790;
    /* BASIC: 530 IF S-1=0 THEN 670 */
line_530:;
    if (S-1==0) { goto line_670; }
    /* BASIC: 540 IF W(R,S-1)<>0 THEN 670 */
line_540:;
    if (W_arr[(int)(R) * 100 + (int)(S-1)]!=0) { goto line_670; }
    /* BASIC: 545 IF R=H THEN 610 */
line_545:;
    if (R==H) { goto line_610; }
    /* BASIC: 547 IF W(R+1,S)<>0 THEN 610 */
line_547:;
    if (W_arr[(int)(R+1) * 100 + (int)(S)]!=0) { goto line_610; }
    /* BASIC: 550 IF S<>V THEN 560 */
line_550:;
    if (S!=V) { goto line_560; }
    /* BASIC: 552 IF Z=1 THEN 590 */
line_552:;
    if (Z==1) { goto line_590; }
    /* BASIC: 554 Q=1:GOTO 570 */
line_554:;
    Q = 1;
    goto line_570;
    /* BASIC: 560 IF W(R,S+1)<>0 THEN 590 */
line_560:;
    if (W_arr[(int)(R) * 100 + (int)(S+1)]!=0) { goto line_590; }
    /* BASIC: 570 X=INT(RND(1)*3+1) */
line_570:;
    X = floor(((double)rand() / (double)RAND_MAX)*3+1);
    /* BASIC: 580 ON X GOTO 820,860,910 */
line_580:;
    switch ((int)(X)) {     case 1: goto line_820;     case 2: goto line_860;     case 3: goto line_910; }
    /* BASIC: 590 X=INT(RND(1)*2+1) */
line_590:;
    X = floor(((double)rand() / (double)RAND_MAX)*2+1);
    /* BASIC: 600 ON X GOTO 820,860 */
line_600:;
    switch ((int)(X)) {     case 1: goto line_820;     case 2: goto line_860; }
    /* BASIC: 610 IF S<>V THEN 630 */
line_610:;
    if (S!=V) { goto line_630; }
    /* BASIC: 620 IF Z=1 THEN 660 */
line_620:;
    if (Z==1) { goto line_660; }
    /* BASIC: 625 Q=1:GOTO 640 */
line_625:;
    Q = 1;
    goto line_640;
    /* BASIC: 630 IF W(R,S+1)<>0 THEN 660 */
line_630:;
    if (W_arr[(int)(R) * 100 + (int)(S+1)]!=0) { goto line_660; }
    /* BASIC: 640 X=INT(RND(1)*2+1) */
line_640:;
    X = floor(((double)rand() / (double)RAND_MAX)*2+1);
    /* BASIC: 650 ON X GOTO 820,910 */
line_650:;
    switch ((int)(X)) {     case 1: goto line_820;     case 2: goto line_910; }
    /* BASIC: 660 GOTO 820 */
line_660:;
    goto line_820;
    /* BASIC: 670 IF R=H THEN 740 */
line_670:;
    if (R==H) { goto line_740; }
    /* BASIC: 680 IF W(R+1,S)<>0 THEN 740 */
line_680:;
    if (W_arr[(int)(R+1) * 100 + (int)(S)]!=0) { goto line_740; }
    /* BASIC: 685 IF S<>V THEN 700 */
line_685:;
    if (S!=V) { goto line_700; }
    /* BASIC: 690 IF Z=1 THEN 730 */
line_690:;
    if (Z==1) { goto line_730; }
    /* BASIC: 695 Q=1:GOTO 830 */
line_695:;
    Q = 1;
    goto line_830;
    /* BASIC: 700 IF W(R,S+1)<>0 THEN 730 */
line_700:;
    if (W_arr[(int)(R) * 100 + (int)(S+1)]!=0) { goto line_730; }
    /* BASIC: 710 X=INT(RND(1)*2+1) */
line_710:;
    X = floor(((double)rand() / (double)RAND_MAX)*2+1);
    /* BASIC: 720 ON X GOTO 860,910 */
line_720:;
    switch ((int)(X)) {     case 1: goto line_860;     case 2: goto line_910; }
    /* BASIC: 730 GOTO 860 */
line_730:;
    goto line_860;
    /* BASIC: 740 IF S<>V THEN 760 */
line_740:;
    if (S!=V) { goto line_760; }
    /* BASIC: 750 IF Z=1 THEN 780 */
line_750:;
    if (Z==1) { goto line_780; }
    /* BASIC: 755 Q=1:GOTO 770 */
line_755:;
    Q = 1;
    goto line_770;
    /* BASIC: 760 IF W(R,S+1)<>0 THEN 780 */
line_760:;
    if (W_arr[(int)(R) * 100 + (int)(S+1)]!=0) { goto line_780; }
    /* BASIC: 770 GOTO 910 */
line_770:;
    goto line_910;
    /* BASIC: 780 GOTO 1000 */
line_780:;
    goto line_1000;
    /* BASIC: 790 W(R-1,S)=C */
line_790:;
    W_arr[(int)(R-1) * 100 + (int)(S)] = C;
    /* BASIC: 800 C=C+1:V(R-1,S)=2:R=R-1 */
line_800:;
    C = C+1;
    V_arr[(int)(R-1) * 100 + (int)(S)] = 2;
    R = R-1;
    /* BASIC: 810 IF C=H*V+1 THEN 1010 */
line_810:;
    if (C==H*V+1) { goto line_1010; }
    /* BASIC: 815 Q=0:GOTO 260 */
line_815:;
    Q = 0;
    goto line_260;
    /* BASIC: 820 W(R,S-1)=C */
line_820:;
    W_arr[(int)(R) * 100 + (int)(S-1)] = C;
    /* BASIC: 830 C=C+1 */
line_830:;
    C = C+1;
    /* BASIC: 840 V(R,S-1)=1:S=S-1:IF C=H*V+1 THEN 1010 */
line_840:;
    V_arr[(int)(R) * 100 + (int)(S-1)] = 1;
    S = S-1;
    if (C==H*V+1) { goto line_1010; }
    /* BASIC: 850 Q=0:GOTO 260 */
line_850:;
    Q = 0;
    goto line_260;
    /* BASIC: 860 W(R+1,S)=C */
line_860:;
    W_arr[(int)(R+1) * 100 + (int)(S)] = C;
    /* BASIC: 870 C=C+1:IF V(R,S)=0 THEN 880 */
line_870:;
    C = C+1;
    if (V_arr[(int)(R) * 100 + (int)(S)]==0) { goto line_880; }
    /* BASIC: 875 V(R,S)=3:GOTO 890 */
line_875:;
    V_arr[(int)(R) * 100 + (int)(S)] = 3;
    goto line_890;
    /* BASIC: 880 V(R,S)=2 */
line_880:;
    V_arr[(int)(R) * 100 + (int)(S)] = 2;
    /* BASIC: 890 R=R+1 */
line_890:;
    R = R+1;
    /* BASIC: 900 IF C=H*V+1 THEN 1010 */
line_900:;
    if (C==H*V+1) { goto line_1010; }
    /* BASIC: 905 GOTO 530 */
line_905:;
    goto line_530;
    /* BASIC: 910 IF Q=1 THEN 960 */
line_910:;
    if (Q==1) { goto line_960; }
    /* BASIC: 920 W(R,S+1)=C:C=C+1:IF V(R,S)=0 THEN 940 */
line_920:;
    W_arr[(int)(R) * 100 + (int)(S+1)] = C;
    C = C+1;
    if (V_arr[(int)(R) * 100 + (int)(S)]==0) { goto line_940; }
    /* BASIC: 930 V(R,S)=3:GOTO 950 */
line_930:;
    V_arr[(int)(R) * 100 + (int)(S)] = 3;
    goto line_950;
    /* BASIC: 940 V(R,S)=1 */
line_940:;
    V_arr[(int)(R) * 100 + (int)(S)] = 1;
    /* BASIC: 950 S=S+1:IF C=H*V+1 THEN 1010 */
line_950:;
    S = S+1;
    if (C==H*V+1) { goto line_1010; }
    /* BASIC: 955 GOTO 260 */
line_955:;
    goto line_260;
    /* BASIC: 960 Z=1 */
line_960:;
    Z = 1;
    /* BASIC: 970 IF V(R,S)=0 THEN 980 */
line_970:;
    if (V_arr[(int)(R) * 100 + (int)(S)]==0) { goto line_980; }
    /* BASIC: 975 V(R,S)=3:Q=0:GOTO 1000 */
line_975:;
    V_arr[(int)(R) * 100 + (int)(S)] = 3;
    Q = 0;
    goto line_1000;
    /* BASIC: 980 V(R,S)=1:Q=0:R=1:S=1:GOTO 250 */
line_980:;
    V_arr[(int)(R) * 100 + (int)(S)] = 1;
    Q = 0;
    R = 1;
    S = 1;
    goto line_250;
    /* BASIC: 1000 GOTO 210 */
line_1000:;
    goto line_210;
    /* BASIC: 1010 FOR J=1 TO V */
line_1010:;
    J = 1; for_loop_J_1010: if (((1) >= 0 && J > (V)) || ((1) < 0 && J < (V))) goto end_for_J_1010;
    /* BASIC: 1011 PRINT "I"; */
line_1011:;
    printf("%s", "I");
    /* BASIC: 1012 FOR I=1 TO H */
line_1012:;
    I = 1; for_loop_I_1012: if (((1) >= 0 && I > (H)) || ((1) < 0 && I < (H))) goto end_for_I_1012;
    /* BASIC: 1013 IF V(I,J)<2 THEN 1030 */
line_1013:;
    if (V_arr[(int)(I) * 100 + (int)(J)]<2) { goto line_1030; }
    /* BASIC: 1020 PRINT "   "; */
line_1020:;
    printf("%s", "   ");
    /* BASIC: 1021 GOTO 1040 */
line_1021:;
    goto line_1040;
    /* BASIC: 1030 PRINT "  I"; */
line_1030:;
    printf("%s", "  I");
    /* BASIC: 1040 NEXT I */
line_1040:;
    I += (1); goto for_loop_I_1012; end_for_I_1012:;
    /* BASIC: 1041 PRINT */
line_1041:;
    printf("\n");
    /* BASIC: 1043 FOR I=1 TO H */
line_1043:;
    I = 1; for_loop_I_1043: if (((1) >= 0 && I > (H)) || ((1) < 0 && I < (H))) goto end_for_I_1043;
    /* BASIC: 1045 IF V(I,J)=0 THEN 1060 */
line_1045:;
    if (V_arr[(int)(I) * 100 + (int)(J)]==0) { goto line_1060; }
    /* BASIC: 1050 IF V(I,J)=2 THEN 1060 */
line_1050:;
    if (V_arr[(int)(I) * 100 + (int)(J)]==2) { goto line_1060; }
    /* BASIC: 1051 PRINT ":  "; */
line_1051:;
    printf("%s", ":  ");
    /* BASIC: 1052 GOTO 1070 */
line_1052:;
    goto line_1070;
    /* BASIC: 1060 PRINT ":--"; */
line_1060:;
    printf("%s", ":--");
    /* BASIC: 1070 NEXT I */
line_1070:;
    I += (1); goto for_loop_I_1043; end_for_I_1043:;
    /* BASIC: 1071 PRINT "." */
line_1071:;
    printf("%s", "."); printf("\n");
    /* BASIC: 1072 NEXT J */
line_1072:;
    J += (1); goto for_loop_J_1010; end_for_J_1010:;
    /* BASIC: 1073 END */
line_1073:;
    exit(0);

    return 0;
}
