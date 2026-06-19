/*
 * Transpiled from hockey.bas
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
static double A, A1, A2, B1, C, G, G1, G2, H, I, J, L, LET, N, ON, P, S, S1, S2, S3, T, T1, T2, T3, T6, X, Z, Z1;
static char A_str[256] = {0};
static char B_str[256] = {0};
static char C_str[256] = {0};
static char R_str[256] = {0};
static double H_arr[2000] = {0};
static double J_arr[2000] = {0};
static double T_arr[2000] = {0};
static double T1_arr[2000] = {0};
static double T2_arr[2000] = {0};
static double T3_arr[2000] = {0};
static char A_str_arr[1000][64] = {0};
static char B_str_arr[1000][64] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 2 PRINT TAB(33);"HOCKEY" */
line_2:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "HOCKEY"); printf("\n");
    /* BASIC: 4 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 6 PRINT:PRINT:PRINT */
line_6:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 10 REM ROBERT PUOPOLO ALG. 1 140 MCCOWAN 6/7/73 HOCKEY */
line_10:;
    /* REM ROBERT PUOPOLO ALG. 1 140 MCCOWAN 6/7/73 HOCKEY */
    /* BASIC: 30 LET X=1 */
line_30:;
    /* UNTRANSLATED: LET X=1 */
    /* BASIC: 40 PRINT:PRINT:PRINT */
line_40:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 50 PRINT "WOULD YOU LIKE THE INSTRUCTIONS";:INPUT C$ */
line_50:;
    printf("%s", "WOULD YOU LIKE THE INSTRUCTIONS");
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", C_str);
    /* BASIC: 55 PRINT */
line_55:;
    printf("\n");
    /* BASIC: 60 IF C$="NO" THEN 90 */
line_60:;
    if (strcmp(C_str, "NO") == 0) { goto line_90; }
    /* BASIC: 65 IF C$="YES" THEN 80 */
line_65:;
    if (strcmp(C_str, "YES") == 0) { goto line_80; }
    /* BASIC: 70 PRINT "ANSWER YES OR NO!!":GOTO 50 */
line_70:;
    printf("%s", "ANSWER YES OR NO!!"); printf("\n");
    goto line_50;
    /* BASIC: 80 GOTO 1720 */
line_80:;
    goto line_1720;
    /* BASIC: 90 DIM A$(7),B$(7),H(20),T(5),T1(5),T2(5),T3(5) */
line_90:;
    /* DIM A$(7),B$(7),H(20),T(5),T1(5),T2(5),T3(5) (handled statically) */
    /* BASIC: 100 PRINT "ENTER THE TWO TEAMS";:INPUT A$(7),B$(7) */
line_100:;
    printf("%s", "ENTER THE TWO TEAMS");
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s %255s", A_str_arr[(int)(7)], B_str_arr[(int)(7)]);
    /* BASIC: 105 PRINT */
line_105:;
    printf("\n");
    /* BASIC: 110 PRINT "ENTER THE NUMBER OF MINUTES IN A GAME";:INPUT T6 */
line_110:;
    printf("%s", "ENTER THE NUMBER OF MINUTES IN A GAME");
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &T6);
    /* BASIC: 115 PRINT */
line_115:;
    printf("\n");
    /* BASIC: 120 IF T6<1 THEN 110:PRINT */
line_120:;
    if (T6<1) { goto line_110; printf("\n"); }
    /* BASIC: 130 PRINT "WOULD THE " A$(7) " COACH ENTER HIS TEAM" */
line_130:;
    printf("%s", "WOULD THE "); printf("%s", A_str_arr[(int)(7)]); printf("%s", " COACH ENTER HIS TEAM"); printf("\n");
    /* BASIC: 135 PRINT */
line_135:;
    printf("\n");
    /* BASIC: 140 FOR I=1 TO 6:PRINT "PLAYER"I;:INPUT A$(I):NEXT I:PRINT */
line_140:;
    I = 1; for_loop_I_140: if (((1) >= 0 && I > (6)) || ((1) < 0 && I < (6))) goto end_for_I_140;
    printf("%s", "PLAYER"); printf("%g ", (double)(I));
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str_arr[(int)(I)]);
    I += (1); goto for_loop_I_140; end_for_I_140:;
    printf("\n");
    /* BASIC: 150 PRINT "WOULD THE " B$(7) " COACH DO THE SAME" */
line_150:;
    printf("%s", "WOULD THE "); printf("%s", B_str_arr[(int)(7)]); printf("%s", " COACH DO THE SAME"); printf("\n");
    /* BASIC: 155 PRINT */
line_155:;
    printf("\n");
    /* BASIC: 160 FOR T=1 TO 6:PRINT "PLAYER"T;:INPUT B$(T):NEXT T:PRINT */
line_160:;
    T = 1; for_loop_T_160: if (((1) >= 0 && T > (6)) || ((1) < 0 && T < (6))) goto end_for_T_160;
    printf("%s", "PLAYER"); printf("%g ", (double)(T));
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", B_str_arr[(int)(T)]);
    T += (1); goto for_loop_T_160; end_for_T_160:;
    printf("\n");
    /* BASIC: 170 PRINT "INPUT THE REFEREE FOR THIS GAME";:INPUT R$ */
line_170:;
    printf("%s", "INPUT THE REFEREE FOR THIS GAME");
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", R_str);
    /* BASIC: 180 PRINT:PRINT TAB(10);A$(7) " STARTING LINEUP" */
line_180:;
    printf("\n");
    { int _t; for(_t=0; _t<10; _t++) printf(" "); } printf("%s", A_str_arr[(int)(7)]); printf("%s", " STARTING LINEUP"); printf("\n");
    /* BASIC: 190 FOR T=1 TO 6:PRINT A$(T):NEXT T */
line_190:;
    T = 1; for_loop_T_190: if (((1) >= 0 && T > (6)) || ((1) < 0 && T < (6))) goto end_for_T_190;
    printf("%s", A_str_arr[(int)(T)]); printf("\n");
    T += (1); goto for_loop_T_190; end_for_T_190:;
    /* BASIC: 200 PRINT:PRINT TAB(10);B$(7)" STARTING LINEUP" */
line_200:;
    printf("\n");
    { int _t; for(_t=0; _t<10; _t++) printf(" "); } printf("%s", B_str_arr[(int)(7)]); printf("%s", " STARTING LINEUP"); printf("\n");
    /* BASIC: 210 FOR T=1 TO 6:PRINT B$(T):NEXT T:PRINT */
line_210:;
    T = 1; for_loop_T_210: if (((1) >= 0 && T > (6)) || ((1) < 0 && T < (6))) goto end_for_T_210;
    printf("%s", B_str_arr[(int)(T)]); printf("\n");
    T += (1); goto for_loop_T_210; end_for_T_210:;
    printf("\n");
    /* BASIC: 220 PRINT "WE'RE READY FOR TONIGHTS OPENING FACE-OFF." */
line_220:;
    printf("%s", "WE'RE READY FOR TONIGHTS OPENING FACE-OFF."); printf("\n");
    /* BASIC: 230 PRINT R$ " WILL DROP THE PUCK BETWEEN " A$(2) " AND " B$(2) */
line_230:;
    printf("%s", R_str); printf("%s", " WILL DROP THE PUCK BETWEEN "); printf("%s", A_str_arr[(int)(2)]); printf("%s", " AND "); printf("%s", B_str_arr[(int)(2)]); printf("\n");
    /* BASIC: 240 FOR L=1 TO T6:IF L=1 THEN 260 */
line_240:;
    L = 1; for_loop_L_240: if (((1) >= 0 && L > (T6)) || ((1) < 0 && L < (T6))) goto end_for_L_240;
    if (L==1) { goto line_260; }
    /* BASIC: 250 PRINT "AND WE'RE READY FOR THE FACE-OFF" */
line_250:;
    printf("%s", "AND WE'RE READY FOR THE FACE-OFF"); printf("\n");
    /* BASIC: 260 C=INT(2*RND(X))+1:ON C GOTO 270,280 */
line_260:;
    C = floor(2*((double)rand() / (double)RAND_MAX))+1;
    switch ((int)(C)) {     case 1: goto line_270;     case 2: goto line_280; }
    /* BASIC: 270 PRINT A$(7) " HAS CONTROL OF THE PUCK":GOTO 290 */
line_270:;
    printf("%s", A_str_arr[(int)(7)]); printf("%s", " HAS CONTROL OF THE PUCK"); printf("\n");
    goto line_290;
    /* BASIC: 280 PRINT B$(7) " HAS CONTROL." */
line_280:;
    printf("%s", B_str_arr[(int)(7)]); printf("%s", " HAS CONTROL."); printf("\n");
    /* BASIC: 290 PRINT "PASS";:INPUT P:FOR N=1 TO 3:H(N)=0:NEXT N */
line_290:;
    printf("%s", "PASS");
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &P);
    N = 1; for_loop_N_290: if (((1) >= 0 && N > (3)) || ((1) < 0 && N < (3))) goto end_for_N_290;
    H_arr[(int)(N)] = 0;
    N += (1); goto for_loop_N_290; end_for_N_290:;
    /* BASIC: 300 IF P<0 THEN 290 */
line_300:;
    if (P<0) { goto line_290; }
    /* BASIC: 305 IF P>3 THEN 290 */
line_305:;
    if (P>3) { goto line_290; }
    /* BASIC: 310 FOR J=1 TO (P+2) */
line_310:;
    J = 1; for_loop_J_310: if (((1) >= 0 && J > ((P+2))) || ((1) < 0 && J < ((P+2)))) goto end_for_J_310;
    /* BASIC: 320 H(J)=INT(5*RND(X))+1 */
line_320:;
    H_arr[(int)(J)] = floor(5*((double)rand() / (double)RAND_MAX))+1;
    /* BASIC: 330 NEXT J:IF H(J-1)=H(J-2) THEN 310 */
line_330:;
    J += (1); goto for_loop_J_310; end_for_J_310:;
    if (H_arr[(int)(J-1)]==H_arr[(int)(J-2)]) { goto line_310; }
    /* BASIC: 331 IF P+2<3 THEN 350 */
line_331:;
    if (P+2<3) { goto line_350; }
    /* BASIC: 335 IF H(J-1)=H(J-3) THEN 310 */
line_335:;
    if (H_arr[(int)(J-1)]==H_arr[(int)(J-3)]) { goto line_310; }
    /* BASIC: 340 IF H(J-2)=H(J-3) THEN 310 */
line_340:;
    if (H_arr[(int)(J-2)]==H_arr[(int)(J-3)]) { goto line_310; }
    /* BASIC: 350 IF P=0 THEN 360 */
line_350:;
    if (P==0) { goto line_360; }
    /* BASIC: 355 GOTO 490 */
line_355:;
    goto line_490;
    /* BASIC: 360 INPUT "SHOT";S:IF S<1 THEN 360 */
line_360:;
    printf("%s", "SHOT"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &S);
    if (S<1) { goto line_360; }
    /* BASIC: 365 IF S>4 THEN 360 */
line_365:;
    if (S>4) { goto line_360; }
    /* BASIC: 370 ON C GOTO 380,480 */
line_370:;
    switch ((int)(C)) {     case 1: goto line_380;     case 2: goto line_480; }
    /* BASIC: 380 PRINT A$(H(J-1));:G=H(J-1):G1=0:G2=0 */
line_380:;
    printf("%s", A_str_arr[(int)(H_arr[(int)(J-1)])]);
    G = H_arr[(int)(J-1)];
    G1 = 0;
    G2 = 0;
    /* BASIC: 390 ON S GOTO 400,420,440,460 */
line_390:;
    switch ((int)(S)) {     case 1: goto line_400;     case 2: goto line_420;     case 3: goto line_440;     case 4: goto line_460; }
    /* BASIC: 400 PRINT " LET'S A BOOMER GO FROM THE RED LINE!!" */
line_400:;
    printf("%s", " LET'S A BOOMER GO FROM THE RED LINE!!"); printf("\n");
    /* BASIC: 410 Z=10:GOTO 890 */
line_410:;
    Z = 10;
    goto line_890;
    /* BASIC: 420 PRINT " FLIPS A WRISTSHOT DOWN THE ICE" */
line_420:;
    printf("%s", " FLIPS A WRISTSHOT DOWN THE ICE"); printf("\n");
    /* BASIC: 440 PRINT " BACKHANDS ONE IN ON THE GOALTENDER" */
line_440:;
    printf("%s", " BACKHANDS ONE IN ON THE GOALTENDER"); printf("\n");
    /* BASIC: 450 Z=25:GOTO 890 */
line_450:;
    Z = 25;
    goto line_890;
    /* BASIC: 460 PRINT " SNAPS A LONG FLIP SHOT" */
line_460:;
    printf("%s", " SNAPS A LONG FLIP SHOT"); printf("\n");
    /* BASIC: 470 Z=17:GOTO 890 */
line_470:;
    Z = 17;
    goto line_890;
    /* BASIC: 480 PRINT B$(H(J-1));:G1=0:G2=0:G=H(J-1):GOTO 390 */
line_480:;
    printf("%s", B_str_arr[(int)(H_arr[(int)(J-1)])]);
    G1 = 0;
    G2 = 0;
    G = H_arr[(int)(J-1)];
    goto line_390;
    /* BASIC: 490 ON C GOTO 500,640 */
line_490:;
    switch ((int)(C)) {     case 1: goto line_500;     case 2: goto line_640; }
    /* BASIC: 500 ON P GOTO 510,540,570 */
line_500:;
    switch ((int)(P)) {     case 1: goto line_510;     case 2: goto line_540;     case 3: goto line_570; }
    /* BASIC: 510 PRINT A$(H(J-2)) " LEADS " A$(H(J-1)) " WITH A PERFECT PASS." */
line_510:;
    printf("%s", A_str_arr[(int)(H_arr[(int)(J-2)])]); printf("%s", " LEADS "); printf("%s", A_str_arr[(int)(H_arr[(int)(J-1)])]); printf("%s", " WITH A PERFECT PASS."); printf("\n");
    /* BASIC: 520 PRINT A$(H(J-1)) " CUTTING IN!!!" */
line_520:;
    printf("%s", A_str_arr[(int)(H_arr[(int)(J-1)])]); printf("%s", " CUTTING IN!!!"); printf("\n");
    /* BASIC: 530 G=H(J-1):G1=H(J-2):G2=0:Z1=3:GOTO 770 */
line_530:;
    G = H_arr[(int)(J-1)];
    G1 = H_arr[(int)(J-2)];
    G2 = 0;
    Z1 = 3;
    goto line_770;
    /* BASIC: 540 PRINT A$(H(J-2)) " GIVES TO A STREAKING " A$(H(J-1)) */
line_540:;
    printf("%s", A_str_arr[(int)(H_arr[(int)(J-2)])]); printf("%s", " GIVES TO A STREAKING "); printf("%s", A_str_arr[(int)(H_arr[(int)(J-1)])]); printf("\n");
    /* BASIC: 550 PRINT A$(H(J-3)) " COMES DOWN ON " B$(5) " AND " B$(4) */
line_550:;
    printf("%s", A_str_arr[(int)(H_arr[(int)(J-3)])]); printf("%s", " COMES DOWN ON "); printf("%s", B_str_arr[(int)(5)]); printf("%s", " AND "); printf("%s", B_str_arr[(int)(4)]); printf("\n");
    /* BASIC: 560 G=H(J-3):G1=H(J-1):G2=H(J-2):Z1=2:GOTO 770 */
line_560:;
    G = H_arr[(int)(J-3)];
    G1 = H_arr[(int)(J-1)];
    G2 = H_arr[(int)(J-2)];
    Z1 = 2;
    goto line_770;
    /* BASIC: 570 PRINT "OH MY GOD!! A ' 4 ON 2 ' SITUATION" */
line_570:;
    printf("%s", "OH MY GOD!! A ' 4 ON 2 ' SITUATION"); printf("\n");
    /* BASIC: 580 PRINT A$(H(J-3)) " LEADS " A$(H(J-2)) */
line_580:;
    printf("%s", A_str_arr[(int)(H_arr[(int)(J-3)])]); printf("%s", " LEADS "); printf("%s", A_str_arr[(int)(H_arr[(int)(J-2)])]); printf("\n");
    /* BASIC: 590 PRINT A$(H(J-2)) " IS WHEEELING THROUGH CENTER." */
line_590:;
    printf("%s", A_str_arr[(int)(H_arr[(int)(J-2)])]); printf("%s", " IS WHEEELING THROUGH CENTER."); printf("\n");
    /* BASIC: 600 PRINT A$(H(J-2)) " GIVES AND GOES WITH " A$(H(J-1)) */
line_600:;
    printf("%s", A_str_arr[(int)(H_arr[(int)(J-2)])]); printf("%s", " GIVES AND GOES WITH "); printf("%s", A_str_arr[(int)(H_arr[(int)(J-1)])]); printf("\n");
    /* BASIC: 610 PRINT "PRETTY PASSING!" */
line_610:;
    printf("%s", "PRETTY PASSING!"); printf("\n");
    /* BASIC: 620 PRINT A$(H(J-1)) " DROPS IT TO " A$(H(J-4)) */
line_620:;
    printf("%s", A_str_arr[(int)(H_arr[(int)(J-1)])]); printf("%s", " DROPS IT TO "); printf("%s", A_str_arr[(int)(H_arr[(int)(J-4)])]); printf("\n");
    /* BASIC: 630 G=H(J-4):G1=J(J-1):G2=H(J-2):Z1=1:GOTO 770 */
line_630:;
    G = H_arr[(int)(J-4)];
    G1 = J_arr[(int)(J-1)];
    G2 = H_arr[(int)(J-2)];
    Z1 = 1;
    goto line_770;
    /* BASIC: 640 ON P GOTO 650,670,720 */
line_640:;
    switch ((int)(P)) {     case 1: goto line_650;     case 2: goto line_670;     case 3: goto line_720; }
    /* BASIC: 650 PRINT B$(H(J-1)) " HITS " B$(H(J-2)) " FLYING DOWN THE LEFT SIDE" */
line_650:;
    printf("%s", B_str_arr[(int)(H_arr[(int)(J-1)])]); printf("%s", " HITS "); printf("%s", B_str_arr[(int)(H_arr[(int)(J-2)])]); printf("%s", " FLYING DOWN THE LEFT SIDE"); printf("\n");
    /* BASIC: 660 G=H(J-2):G1=H(J-1):G2=0:Z1=3:GOTO 770 */
line_660:;
    G = H_arr[(int)(J-2)];
    G1 = H_arr[(int)(J-1)];
    G2 = 0;
    Z1 = 3;
    goto line_770;
    /* BASIC: 670 PRINT "IT'S A ' 3 ON 2 '!" */
line_670:;
    printf("%s", "IT'S A ' 3 ON 2 '!"); printf("\n");
    /* BASIC: 680 PRINT "ONLY " A$(4) " AND " A$(5) " ARE BACK." */
line_680:;
    printf("%s", "ONLY "); printf("%s", A_str_arr[(int)(4)]); printf("%s", " AND "); printf("%s", A_str_arr[(int)(5)]); printf("%s", " ARE BACK."); printf("\n");
    /* BASIC: 690 PRINT B$(H(J-2)) " GIVES OFF TO " B$(H(J-1)) */
line_690:;
    printf("%s", B_str_arr[(int)(H_arr[(int)(J-2)])]); printf("%s", " GIVES OFF TO "); printf("%s", B_str_arr[(int)(H_arr[(int)(J-1)])]); printf("\n");
    /* BASIC: 700 PRINT B$(H(J-1)) " DROPS TO " B$(H(J-3)) */
line_700:;
    printf("%s", B_str_arr[(int)(H_arr[(int)(J-1)])]); printf("%s", " DROPS TO "); printf("%s", B_str_arr[(int)(H_arr[(int)(J-3)])]); printf("\n");
    /* BASIC: 710 G=H(J-3):G1=H(J-1):G2=H(J-2):Z1=2:GOTO 770 */
line_710:;
    G = H_arr[(int)(J-3)];
    G1 = H_arr[(int)(J-1)];
    G2 = H_arr[(int)(J-2)];
    Z1 = 2;
    goto line_770;
    /* BASIC: 720 PRINT " A ' 3 ON 2 ' WITH A ' TRAILER '!" */
line_720:;
    printf("%s", " A ' 3 ON 2 ' WITH A ' TRAILER '!"); printf("\n");
    /* BASIC: 730 PRINT B$(H(J-4)) " GIVES TO " B$(H(J-2)) " WHO SHUFFLES IT OFF TO" */
line_730:;
    printf("%s", B_str_arr[(int)(H_arr[(int)(J-4)])]); printf("%s", " GIVES TO "); printf("%s", B_str_arr[(int)(H_arr[(int)(J-2)])]); printf("%s", " WHO SHUFFLES IT OFF TO"); printf("\n");
    /* BASIC: 740 PRINT B$(H(J-1)) " WHO FIRES A WING TO WING PASS TO " */
line_740:;
    printf("%s", B_str_arr[(int)(H_arr[(int)(J-1)])]); printf("%s", " WHO FIRES A WING TO WING PASS TO "); printf("\n");
    /* BASIC: 750 PRINT B$(H(J-3)) " AS HE CUTS IN ALONE!!" */
line_750:;
    printf("%s", B_str_arr[(int)(H_arr[(int)(J-3)])]); printf("%s", " AS HE CUTS IN ALONE!!"); printf("\n");
    /* BASIC: 760 G=H(J-3):G1=H(J-1):G2=H(J-2):Z1=1:GOTO 770 */
line_760:;
    G = H_arr[(int)(J-3)];
    G1 = H_arr[(int)(J-1)];
    G2 = H_arr[(int)(J-2)];
    Z1 = 1;
    goto line_770;
    /* BASIC: 770 PRINT "SHOT";:INPUT S:IF S>4 THEN 770:IF S<1 THEN 770 */
line_770:;
    printf("%s", "SHOT");
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &S);
    if (S>4) { goto line_770; }
    if (S<1) { goto line_770; }
    /* BASIC: 780 ON C GOTO 790,880 */
line_780:;
    switch ((int)(C)) {     case 1: goto line_790;     case 2: goto line_880; }
    /* BASIC: 790 PRINT A$(G);:ON S GOTO 800,820,840,860 */
line_790:;
    printf("%s", A_str_arr[(int)(G)]);
    switch ((int)(S)) {     case 1: goto line_800;     case 2: goto line_820;     case 3: goto line_840;     case 4: goto line_860; }
    /* BASIC: 800 PRINT " LET'S A BIG SLAP SHOT GO!!" */
line_800:;
    printf("%s", " LET'S A BIG SLAP SHOT GO!!"); printf("\n");
    /* BASIC: 810 Z=4:Z=Z+Z1:GOTO 890 */
line_810:;
    Z = 4;
    Z = Z+Z1;
    goto line_890;
    /* BASIC: 820 PRINT " RIPS A WRIST SHOT OFF" */
line_820:;
    printf("%s", " RIPS A WRIST SHOT OFF"); printf("\n");
    /* BASIC: 830 Z=2:Z=Z+Z1:GOTO 890 */
line_830:;
    Z = 2;
    Z = Z+Z1;
    goto line_890;
    /* BASIC: 840 PRINT " GETS A BACKHAND OFF" */
line_840:;
    printf("%s", " GETS A BACKHAND OFF"); printf("\n");
    /* BASIC: 850 Z=3:Z=Z+Z1:GOTO 890 */
line_850:;
    Z = 3;
    Z = Z+Z1;
    goto line_890;
    /* BASIC: 860 PRINT " SNAPS OFF A SNAP SHOT" */
line_860:;
    printf("%s", " SNAPS OFF A SNAP SHOT"); printf("\n");
    /* BASIC: 870 Z=2:Z=Z+Z1:GOTO 890 */
line_870:;
    Z = 2;
    Z = Z+Z1;
    goto line_890;
    /* BASIC: 880 PRINT B$(G);:ON S GOTO 800,820,840,860 */
line_880:;
    printf("%s", B_str_arr[(int)(G)]);
    switch ((int)(S)) {     case 1: goto line_800;     case 2: goto line_820;     case 3: goto line_840;     case 4: goto line_860; }
    /* BASIC: 890 PRINT "AREA";:INPUT A:IF A<1 THEN 890 */
line_890:;
    printf("%s", "AREA");
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &A);
    if (A<1) { goto line_890; }
    /* BASIC: 895 IF A>4 THEN 890 */
line_895:;
    if (A>4) { goto line_890; }
    /* BASIC: 900 ON C GOTO 910,920 */
line_900:;
    switch ((int)(C)) {     case 1: goto line_910;     case 2: goto line_920; }
    /* BASIC: 910 S2=S2+1:GOTO 930 */
line_910:;
    S2 = S2+1;
    goto line_930;
    /* BASIC: 920 S3=S3+1 */
line_920:;
    S3 = S3+1;
    /* BASIC: 930 A1=INT(4*RND(X))+1:IF A<>A1 THEN 1200 */
line_930:;
    A1 = floor(4*((double)rand() / (double)RAND_MAX))+1;
    if (A!=A1) { goto line_1200; }
    /* BASIC: 940 H(20)=INT(100*RND(X))+1 */
line_940:;
    H_arr[(int)(20)] = floor(100*((double)rand() / (double)RAND_MAX))+1;
    /* BASIC: 950 IF INT(H(20)/Z)=H(20)/Z THEN 1160 */
line_950:;
    if (floor(H_arr[(int)(20)]/Z)==H_arr[(int)(20)]/Z) { goto line_1160; }
    /* BASIC: 960 ON C GOTO 970,980 */
line_960:;
    switch ((int)(C)) {     case 1: goto line_970;     case 2: goto line_980; }
    /* BASIC: 970 PRINT "GOAL " A$(7):H(9)=H(9)+1:GOTO 990 */
line_970:;
    printf("%s", "GOAL "); printf("%s", A_str_arr[(int)(7)]); printf("\n");
    H_arr[(int)(9)] = H_arr[(int)(9)]+1;
    goto line_990;
    /* BASIC: 980 PRINT "SCORE " B$(7):H(8)=H(8)+1 */
line_980:;
    printf("%s", "SCORE "); printf("%s", B_str_arr[(int)(7)]); printf("\n");
    H_arr[(int)(8)] = H_arr[(int)(8)]+1;
    /* BASIC: 990 FOR B1=1 TO 25:PRINT CHR$(7);:NEXT B1:PRINT */
line_990:;
    B1 = 1; for_loop_B1_990: if (((1) >= 0 && B1 > (25)) || ((1) < 0 && B1 < (25))) goto end_for_B1_990;
    printf("%s", basic_CHR(7));
    B1 += (1); goto for_loop_B1_990; end_for_B1_990:;
    printf("\n");
    /* BASIC: 1000 PRINT "SCORE: ";:IF H(8)>H(9) THEN 1020 */
line_1000:;
    printf("%s", "SCORE: ");
    if (H_arr[(int)(8)]>H_arr[(int)(9)]) { goto line_1020; }
    /* BASIC: 1010 PRINT A$(7)":";H(9),B$(7)":";H(8):GOTO 1030 */
line_1010:;
    printf("%s", A_str_arr[(int)(7)]); printf("%s", ":"); printf("%g ", (double)(H_arr[(int)(9)])); printf("\t"); printf("%s", B_str_arr[(int)(7)]); printf("%s", ":"); printf("%g ", (double)(H_arr[(int)(8)])); printf("\n");
    goto line_1030;
    /* BASIC: 1020 PRINT B$(7)":";H(8),A$(7)":";H(9) */
line_1020:;
    printf("%s", B_str_arr[(int)(7)]); printf("%s", ":"); printf("%g ", (double)(H_arr[(int)(8)])); printf("\t"); printf("%s", A_str_arr[(int)(7)]); printf("%s", ":"); printf("%g ", (double)(H_arr[(int)(9)])); printf("\n");
    /* BASIC: 1030 ON C GOTO 1040,1100 */
line_1030:;
    switch ((int)(C)) {     case 1: goto line_1040;     case 2: goto line_1100; }
    /* BASIC: 1040 PRINT "GOAL SCORED BY: " A$(G):IF G1=0 THEN 1070 */
line_1040:;
    printf("%s", "GOAL SCORED BY: "); printf("%s", A_str_arr[(int)(G)]); printf("\n");
    if (G1==0) { goto line_1070; }
    /* BASIC: 1050 IF G2=0 THEN 1080 */
line_1050:;
    if (G2==0) { goto line_1080; }
    /* BASIC: 1060 PRINT " ASSISTED BY: " A$(G1) " AND " A$(G2):GOTO 1090 */
line_1060:;
    printf("%s", " ASSISTED BY: "); printf("%s", A_str_arr[(int)(G1)]); printf("%s", " AND "); printf("%s", A_str_arr[(int)(G2)]); printf("\n");
    goto line_1090;
    /* BASIC: 1070 PRINT " UNASSISTED.":GOTO 1090 */
line_1070:;
    printf("%s", " UNASSISTED."); printf("\n");
    goto line_1090;
    /* BASIC: 1080 PRINT " ASSISTED BY: " A$(G1) */
line_1080:;
    printf("%s", " ASSISTED BY: "); printf("%s", A_str_arr[(int)(G1)]); printf("\n");
    /* BASIC: 1090 T(G)=T(G)+1:T1(G1)=T1(G1)+1:T1(G2)=T1(G2)+1:GOTO 1540 */
line_1090:;
    T_arr[(int)(G)] = T_arr[(int)(G)]+1;
    T1_arr[(int)(G1)] = T1_arr[(int)(G1)]+1;
    T1_arr[(int)(G2)] = T1_arr[(int)(G2)]+1;
    goto line_1540;
    /* BASIC: 1100 PRINT "GOAL SCORED BY: " B$(G); */
line_1100:;
    printf("%s", "GOAL SCORED BY: "); printf("%s", B_str_arr[(int)(G)]);
    /* BASIC: 1110 IF G1=0 THEN 1130 */
line_1110:;
    if (G1==0) { goto line_1130; }
    /* BASIC: 1115 IF G2=0 THEN 1140 */
line_1115:;
    if (G2==0) { goto line_1140; }
    /* BASIC: 1120 PRINT " ASSISTED BY: " B$(G1) " AND " B$(G2):GOTO 1150 */
line_1120:;
    printf("%s", " ASSISTED BY: "); printf("%s", B_str_arr[(int)(G1)]); printf("%s", " AND "); printf("%s", B_str_arr[(int)(G2)]); printf("\n");
    goto line_1150;
    /* BASIC: 1130 PRINT " UNASSISTED":GOTO 1150 */
line_1130:;
    printf("%s", " UNASSISTED"); printf("\n");
    goto line_1150;
    /* BASIC: 1140 PRINT " ASSISTED BY: " B$(G1):GOTO 1150 */
line_1140:;
    printf("%s", " ASSISTED BY: "); printf("%s", B_str_arr[(int)(G1)]); printf("\n");
    goto line_1150;
    /* BASIC: 1150 T2(G)=T2(G)+1:T3(G1)=T3(G1)+1:T3(G2)=T3(G2)+1:GOTO 1540 */
line_1150:;
    T2_arr[(int)(G)] = T2_arr[(int)(G)]+1;
    T3_arr[(int)(G1)] = T3_arr[(int)(G1)]+1;
    T3_arr[(int)(G2)] = T3_arr[(int)(G2)]+1;
    goto line_1540;
    /* BASIC: 1160 A2=INT(100*RND(X))+1:IF INT(A2/4)=A2/4 THEN 1170 */
line_1160:;
    A2 = floor(100*((double)rand() / (double)RAND_MAX))+1;
    if (floor(A2/4)==A2/4) { goto line_1170; }
    /* BASIC: 1165 GOTO 1200 */
line_1165:;
    goto line_1200;
    /* BASIC: 1170 ON C GOTO 1180,1190 */
line_1170:;
    switch ((int)(C)) {     case 1: goto line_1180;     case 2: goto line_1190; }
    /* BASIC: 1180 PRINT "SAVE " B$(6) " --  REBOUND":GOTO 940 */
line_1180:;
    printf("%s", "SAVE "); printf("%s", B_str_arr[(int)(6)]); printf("%s", " --  REBOUND"); printf("\n");
    goto line_940;
    /* BASIC: 1190 PRINT "SAVE " A$(6) " --  FOLLOW UP":GOTO 940 */
line_1190:;
    printf("%s", "SAVE "); printf("%s", A_str_arr[(int)(6)]); printf("%s", " --  FOLLOW UP"); printf("\n");
    goto line_940;
    /* BASIC: 1200 S1=INT(6*RND(X))+1 */
line_1200:;
    S1 = floor(6*((double)rand() / (double)RAND_MAX))+1;
    /* BASIC: 1210 ON C GOTO 1220,1380 */
line_1210:;
    switch ((int)(C)) {     case 1: goto line_1220;     case 2: goto line_1380; }
    /* BASIC: 1220 ON S1 GOTO 1230,1260,1290,1300,1330,1350 */
line_1220:;
    switch ((int)(S1)) {     case 1: goto line_1230;     case 2: goto line_1260;     case 3: goto line_1290;     case 4: goto line_1300;     case 5: goto line_1330;     case 6: goto line_1350; }
    /* BASIC: 1230 PRINT "KICK SAVE AND A BEAUTY BY " B$(6) */
line_1230:;
    printf("%s", "KICK SAVE AND A BEAUTY BY "); printf("%s", B_str_arr[(int)(6)]); printf("\n");
    /* BASIC: 1240 PRINT "CLEARED OUT BY " B$(3) */
line_1240:;
    printf("%s", "CLEARED OUT BY "); printf("%s", B_str_arr[(int)(3)]); printf("\n");
    /* BASIC: 1250 GOTO 260 */
line_1250:;
    goto line_260;
    /* BASIC: 1260 PRINT "WHAT A SPECTACULAR GLOVE SAVE BY " B$(6) */
line_1260:;
    printf("%s", "WHAT A SPECTACULAR GLOVE SAVE BY "); printf("%s", B_str_arr[(int)(6)]); printf("\n");
    /* BASIC: 1270 PRINT "AND " B$(6) " GOLFS IT INTO THE CROWD" */
line_1270:;
    printf("%s", "AND "); printf("%s", B_str_arr[(int)(6)]); printf("%s", " GOLFS IT INTO THE CROWD"); printf("\n");
    /* BASIC: 1280 GOTO 1540 */
line_1280:;
    goto line_1540;
    /* BASIC: 1290 PRINT "SKATE SAVE ON A LOW STEAMER BY " B$(6):GOTO 260 */
line_1290:;
    printf("%s", "SKATE SAVE ON A LOW STEAMER BY "); printf("%s", B_str_arr[(int)(6)]); printf("\n");
    goto line_260;
    /* BASIC: 1300 PRINT "PAD SAVE BY " B$(6) " OFF THE STICK" */
line_1300:;
    printf("%s", "PAD SAVE BY "); printf("%s", B_str_arr[(int)(6)]); printf("%s", " OFF THE STICK"); printf("\n");
    /* BASIC: 1310 PRINT "OF "A$(G) " AND " B$(6) " COVERS UP" */
line_1310:;
    printf("%s", "OF "); printf("%s", A_str_arr[(int)(G)]); printf("%s", " AND "); printf("%s", B_str_arr[(int)(6)]); printf("%s", " COVERS UP"); printf("\n");
    /* BASIC: 1320 GOTO 1540 */
line_1320:;
    goto line_1540;
    /* BASIC: 1330 PRINT "WHISTLES ONE OVER THE HEAD OF " B$(6) */
line_1330:;
    printf("%s", "WHISTLES ONE OVER THE HEAD OF "); printf("%s", B_str_arr[(int)(6)]); printf("\n");
    /* BASIC: 1340 GOTO 260 */
line_1340:;
    goto line_260;
    /* BASIC: 1350 PRINT B$(6) " MAKES A FACE SAVE!! AND HE IS HURT" */
line_1350:;
    printf("%s", B_str_arr[(int)(6)]); printf("%s", " MAKES A FACE SAVE!! AND HE IS HURT"); printf("\n");
    /* BASIC: 1360 PRINT "THE DEFENSEMAN " B$(5) " COVERS UP FOR HIM" */
line_1360:;
    printf("%s", "THE DEFENSEMAN "); printf("%s", B_str_arr[(int)(5)]); printf("%s", " COVERS UP FOR HIM"); printf("\n");
    /* BASIC: 1370 GOTO 1540 */
line_1370:;
    goto line_1540;
    /* BASIC: 1380 ON S1 GOTO 1390,1410,1440,1470,1490,1520 */
line_1380:;
    switch ((int)(S1)) {     case 1: goto line_1390;     case 2: goto line_1410;     case 3: goto line_1440;     case 4: goto line_1470;     case 5: goto line_1490;     case 6: goto line_1520; }
    /* BASIC: 1390 PRINT "STICK SAVE BY " A$(6) */
line_1390:;
    printf("%s", "STICK SAVE BY "); printf("%s", A_str_arr[(int)(6)]); printf("\n");
    /* BASIC: 1400 PRINT "AND CLEARED OUT BY " A$(4):GOTO 260 */
line_1400:;
    printf("%s", "AND CLEARED OUT BY "); printf("%s", A_str_arr[(int)(4)]); printf("\n");
    goto line_260;
    /* BASIC: 1410 PRINT "OH MY GOD!! " B$(G) " RATTLES ONE OFF THE POST" */
line_1410:;
    printf("%s", "OH MY GOD!! "); printf("%s", B_str_arr[(int)(G)]); printf("%s", " RATTLES ONE OFF THE POST"); printf("\n");
    /* BASIC: 1420 PRINT "TO THE RIGHT OF " A$(6) " AND " A$(6) " COVERS "; */
line_1420:;
    printf("%s", "TO THE RIGHT OF "); printf("%s", A_str_arr[(int)(6)]); printf("%s", " AND "); printf("%s", A_str_arr[(int)(6)]); printf("%s", " COVERS ");
    /* BASIC: 1430 PRINT "ON THE LOOSE PUCK!":GOTO 1540 */
line_1430:;
    printf("%s", "ON THE LOOSE PUCK!"); printf("\n");
    goto line_1540;
    /* BASIC: 1440 PRINT "SKATE SAVE BY " A$(6) */
line_1440:;
    printf("%s", "SKATE SAVE BY "); printf("%s", A_str_arr[(int)(6)]); printf("\n");
    /* BASIC: 1450 PRINT A$(6) " WHACKS THE LOOSE PUCK INTO THE STANDS" */
line_1450:;
    printf("%s", A_str_arr[(int)(6)]); printf("%s", " WHACKS THE LOOSE PUCK INTO THE STANDS"); printf("\n");
    /* BASIC: 1460 GOTO 1540 */
line_1460:;
    goto line_1540;
    /* BASIC: 1470 PRINT "STICK SAVE BY " A$(6) " AND HE CLEARS IT OUT HIMSELF" */
line_1470:;
    printf("%s", "STICK SAVE BY "); printf("%s", A_str_arr[(int)(6)]); printf("%s", " AND HE CLEARS IT OUT HIMSELF"); printf("\n");
    /* BASIC: 1480 GOTO 260 */
line_1480:;
    goto line_260;
    /* BASIC: 1490 PRINT "KICKED OUT BY " A$(6) */
line_1490:;
    printf("%s", "KICKED OUT BY "); printf("%s", A_str_arr[(int)(6)]); printf("\n");
    /* BASIC: 1500 PRINT "AND IT REBOUNDS ALL THE WAY TO CENTER ICE" */
line_1500:;
    printf("%s", "AND IT REBOUNDS ALL THE WAY TO CENTER ICE"); printf("\n");
    /* BASIC: 1510 GOTO 260 */
line_1510:;
    goto line_260;
    /* BASIC: 1520 PRINT "GLOVE SAVE " A$(6) " AND HE HANGS ON" */
line_1520:;
    printf("%s", "GLOVE SAVE "); printf("%s", A_str_arr[(int)(6)]); printf("%s", " AND HE HANGS ON"); printf("\n");
    /* BASIC: 1530 GOTO 1540 */
line_1530:;
    goto line_1540;
    /* BASIC: 1540 NEXT L:FOR N=1 TO 30:PRINT CHR$(7);:NEXT N:PRINT "THAT'S THE SIREN" */
line_1540:;
    L += (1); goto for_loop_L_240; end_for_L_240:;
    N = 1; for_loop_N_1540: if (((1) >= 0 && N > (30)) || ((1) < 0 && N < (30))) goto end_for_N_1540;
    printf("%s", basic_CHR(7));
    N += (1); goto for_loop_N_1540; end_for_N_1540:;
    printf("%s", "THAT'S THE SIREN"); printf("\n");
    /* BASIC: 1550 PRINT:PRINT TAB(15);"FINAL SCORE:" */
line_1550:;
    printf("\n");
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "FINAL SCORE:"); printf("\n");
    /* BASIC: 1560 IF H(8)>H(9) THEN 1580 */
line_1560:;
    if (H_arr[(int)(8)]>H_arr[(int)(9)]) { goto line_1580; }
    /* BASIC: 1570 PRINT A$(7)":";H(9),B$(7)":";H(8):GOTO 1590 */
line_1570:;
    printf("%s", A_str_arr[(int)(7)]); printf("%s", ":"); printf("%g ", (double)(H_arr[(int)(9)])); printf("\t"); printf("%s", B_str_arr[(int)(7)]); printf("%s", ":"); printf("%g ", (double)(H_arr[(int)(8)])); printf("\n");
    goto line_1590;
    /* BASIC: 1580 PRINT B$(7)":";H(8),A$(7)":";H(9) */
line_1580:;
    printf("%s", B_str_arr[(int)(7)]); printf("%s", ":"); printf("%g ", (double)(H_arr[(int)(8)])); printf("\t"); printf("%s", A_str_arr[(int)(7)]); printf("%s", ":"); printf("%g ", (double)(H_arr[(int)(9)])); printf("\n");
    /* BASIC: 1590 PRINT: PRINT TAB(10);"SCORING SUMMARY":PRINT */
line_1590:;
    printf("\n");
    { int _t; for(_t=0; _t<10; _t++) printf(" "); } printf("%s", "SCORING SUMMARY"); printf("\n");
    printf("\n");
    /* BASIC: 1600 PRINT TAB(25);A$(7) */
line_1600:;
    { int _t; for(_t=0; _t<25; _t++) printf(" "); } printf("%s", A_str_arr[(int)(7)]); printf("\n");
    /* BASIC: 1610 PRINT TAB(5);"NAME";TAB(20);"GOALS";TAB(35);"ASSISTS" */
line_1610:;
    { int _t; for(_t=0; _t<5; _t++) printf(" "); } printf("%s", "NAME"); { int _t; for(_t=0; _t<20; _t++) printf(" "); } printf("%s", "GOALS"); { int _t; for(_t=0; _t<35; _t++) printf(" "); } printf("%s", "ASSISTS"); printf("\n");
    /* BASIC: 1620 PRINT TAB(5);"----";TAB(20);"-----";TAB(35);"-------" */
line_1620:;
    { int _t; for(_t=0; _t<5; _t++) printf(" "); } printf("%s", "----"); { int _t; for(_t=0; _t<20; _t++) printf(" "); } printf("%s", "-----"); { int _t; for(_t=0; _t<35; _t++) printf(" "); } printf("%s", "-------"); printf("\n");
    /* BASIC: 1630 FOR I=1 TO 5:PRINT TAB(5);A$(I);TAB(21);T(I);TAB(36);T1(I) */
line_1630:;
    I = 1; for_loop_I_1630: if (((1) >= 0 && I > (5)) || ((1) < 0 && I < (5))) goto end_for_I_1630;
    { int _t; for(_t=0; _t<5; _t++) printf(" "); } printf("%s", A_str_arr[(int)(I)]); { int _t; for(_t=0; _t<21; _t++) printf(" "); } printf("%g ", (double)(T_arr[(int)(I)])); { int _t; for(_t=0; _t<36; _t++) printf(" "); } printf("%g ", (double)(T1_arr[(int)(I)])); printf("\n");
    /* BASIC: 1640 NEXT I:PRINT */
line_1640:;
    I += (1); goto for_loop_I_1630; end_for_I_1630:;
    printf("\n");
    /* BASIC: 1650 PRINT TAB(25);B$(7) */
line_1650:;
    { int _t; for(_t=0; _t<25; _t++) printf(" "); } printf("%s", B_str_arr[(int)(7)]); printf("\n");
    /* BASIC: 1660 PRINT TAB(5);"NAME";TAB(20);"GOALS";TAB(35);"ASSISTS" */
line_1660:;
    { int _t; for(_t=0; _t<5; _t++) printf(" "); } printf("%s", "NAME"); { int _t; for(_t=0; _t<20; _t++) printf(" "); } printf("%s", "GOALS"); { int _t; for(_t=0; _t<35; _t++) printf(" "); } printf("%s", "ASSISTS"); printf("\n");
    /* BASIC: 1670 PRINT TAB(5);"----";TAB(20);"-----";TAB(35);"-------" */
line_1670:;
    { int _t; for(_t=0; _t<5; _t++) printf(" "); } printf("%s", "----"); { int _t; for(_t=0; _t<20; _t++) printf(" "); } printf("%s", "-----"); { int _t; for(_t=0; _t<35; _t++) printf(" "); } printf("%s", "-------"); printf("\n");
    /* BASIC: 1680 FOR T=1 TO 5:PRINT TAB(5);B$(T);TAB(21);T2(T);TAB(36);T3(T) */
line_1680:;
    T = 1; for_loop_T_1680: if (((1) >= 0 && T > (5)) || ((1) < 0 && T < (5))) goto end_for_T_1680;
    { int _t; for(_t=0; _t<5; _t++) printf(" "); } printf("%s", B_str_arr[(int)(T)]); { int _t; for(_t=0; _t<21; _t++) printf(" "); } printf("%g ", (double)(T2_arr[(int)(T)])); { int _t; for(_t=0; _t<36; _t++) printf(" "); } printf("%g ", (double)(T3_arr[(int)(T)])); printf("\n");
    /* BASIC: 1690 NEXT T:PRINT */
line_1690:;
    T += (1); goto for_loop_T_1680; end_for_T_1680:;
    printf("\n");
    /* BASIC: 1700 PRINT "SHOTS ON NET":PRINT A$(7)":";S2:PRINT B$(7)":";S3 */
line_1700:;
    printf("%s", "SHOTS ON NET"); printf("\n");
    printf("%s", A_str_arr[(int)(7)]); printf("%s", ":"); printf("%g ", (double)(S2)); printf("\n");
    printf("%s", B_str_arr[(int)(7)]); printf("%s", ":"); printf("%g ", (double)(S3)); printf("\n");
    /* BASIC: 1710 END */
line_1710:;
    exit(0);
    /* BASIC: 1720 PRINT: PRINT "THIS IS A SIMULATED HOCKEY GAME." */
line_1720:;
    printf("\n");
    printf("%s", "THIS IS A SIMULATED HOCKEY GAME."); printf("\n");
    /* BASIC: 1730 PRINT "QUESTION     RESPONSE" */
line_1730:;
    printf("%s", "QUESTION     RESPONSE"); printf("\n");
    /* BASIC: 1740 PRINT "PASS         TYPE IN THE NUMBER OF PASSES YOU WOULD" */
line_1740:;
    printf("%s", "PASS         TYPE IN THE NUMBER OF PASSES YOU WOULD"); printf("\n");
    /* BASIC: 1750 PRINT "             LIKE TO MAKE, FROM 0 TO 3." */
line_1750:;
    printf("%s", "             LIKE TO MAKE, FROM 0 TO 3."); printf("\n");
    /* BASIC: 1760 PRINT "SHOT         TYPE THE NUMBER CORRESPONDING TO THE SHOT" */
line_1760:;
    printf("%s", "SHOT         TYPE THE NUMBER CORRESPONDING TO THE SHOT"); printf("\n");
    /* BASIC: 1770 PRINT "             YOU WANT TO MAKE.  ENTER:" */
line_1770:;
    printf("%s", "             YOU WANT TO MAKE.  ENTER:"); printf("\n");
    /* BASIC: 1780 PRINT "             1 FOR A SLAPSHOT" */
line_1780:;
    printf("%s", "             1 FOR A SLAPSHOT"); printf("\n");
    /* BASIC: 1790 PRINT "             2 FOR A WRISTSHOT" */
line_1790:;
    printf("%s", "             2 FOR A WRISTSHOT"); printf("\n");
    /* BASIC: 1800 PRINT "             3 FOR A BACKHAND" */
line_1800:;
    printf("%s", "             3 FOR A BACKHAND"); printf("\n");
    /* BASIC: 1810 PRINT "             4 FOR A SNAP SHOT" */
line_1810:;
    printf("%s", "             4 FOR A SNAP SHOT"); printf("\n");
    /* BASIC: 1820 PRINT "AREA         TYPE IN THE NUMBER CORRESPONDING TO" */
line_1820:;
    printf("%s", "AREA         TYPE IN THE NUMBER CORRESPONDING TO"); printf("\n");
    /* BASIC: 1830 PRINT "             THE AREA YOU ARE AIMING AT.  ENTER:" */
line_1830:;
    printf("%s", "             THE AREA YOU ARE AIMING AT.  ENTER:"); printf("\n");
    /* BASIC: 1840 PRINT "             1 FOR UPPER LEFT HAND CORNER" */
line_1840:;
    printf("%s", "             1 FOR UPPER LEFT HAND CORNER"); printf("\n");
    /* BASIC: 1850 PRINT "             2 FOR UPPER RIGHT HAND CORNER" */
line_1850:;
    printf("%s", "             2 FOR UPPER RIGHT HAND CORNER"); printf("\n");
    /* BASIC: 1860 PRINT "             3 FOR LOWER LEFT HAND CORNER" */
line_1860:;
    printf("%s", "             3 FOR LOWER LEFT HAND CORNER"); printf("\n");
    /* BASIC: 1870 PRINT "             4 FOR LOWER RIGHT HAND CORNER" */
line_1870:;
    printf("%s", "             4 FOR LOWER RIGHT HAND CORNER"); printf("\n");
    /* BASIC: 1880 PRINT */
line_1880:;
    printf("\n");
    /* BASIC: 1890 PRINT "AT THE START OF THE GAME, YOU WILL BE ASKED FOR THE NAMES" */
line_1890:;
    printf("%s", "AT THE START OF THE GAME, YOU WILL BE ASKED FOR THE NAMES"); printf("\n");
    /* BASIC: 1900 PRINT "OF YOUR PLAYERS.  THEY ARE ENTERED IN THE ORDER: " */
line_1900:;
    printf("%s", "OF YOUR PLAYERS.  THEY ARE ENTERED IN THE ORDER: "); printf("\n");
    /* BASIC: 1910 PRINT "LEFT WING, CENTER, RIGHT WING, LEFT DEFENSE," */
line_1910:;
    printf("%s", "LEFT WING, CENTER, RIGHT WING, LEFT DEFENSE,"); printf("\n");
    /* BASIC: 1920 PRINT "RIGHT DEFENSE, GOALKEEPER.  ANY OTHER INPUT REQUIRED WILL" */
line_1920:;
    printf("%s", "RIGHT DEFENSE, GOALKEEPER.  ANY OTHER INPUT REQUIRED WILL"); printf("\n");
    /* BASIC: 1930 PRINT "HAVE EXPLANATORY INSTRUCTIONS." */
line_1930:;
    printf("%s", "HAVE EXPLANATORY INSTRUCTIONS."); printf("\n");
    /* BASIC: 1940 GOTO 90 */
line_1940:;
    goto line_90;
    /* BASIC: 1950 END */
line_1950:;
    exit(0);

    return 0;
}
