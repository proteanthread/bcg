/*
 * Transpiled from bullseye.bas
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
static double B, I, M, N, ON, P1, P2, P3, P4, R, S, T, U, W;
static char A_str[256] = {0};
static double S_arr[2000] = {0};
static double W_arr[2000] = {0};
static char A_str_arr[1000][64] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 5 PRINT TAB(32);"BULLSEYE" */
line_5:;
    { int _t; for(_t=0; _t<32; _t++) printf(" "); } printf("%s", "BULLSEYE"); printf("\n");
    /* BASIC: 10 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_10:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 20 PRINT:PRINT:PRINT */
line_20:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 30 PRINT "IN THIS GAME, UP TO 20 PLAYERS THROW DARTS AT A TARGET" */
line_30:;
    printf("%s", "IN THIS GAME, UP TO 20 PLAYERS THROW DARTS AT A TARGET"); printf("\n");
    /* BASIC: 40 PRINT "WITH 10, 20, 30, AND 40 POINT ZONES.  THE OBJECTIVE IS" */
line_40:;
    printf("%s", "WITH 10, 20, 30, AND 40 POINT ZONES.  THE OBJECTIVE IS"); printf("\n");
    /* BASIC: 50 PRINT "TO GET 200 POINTS.": PRINT */
line_50:;
    printf("%s", "TO GET 200 POINTS."); printf("\n");
    printf("\n");
    /* BASIC: 60 PRINT "THROW",TAB(20);"DESCRIPTION";TAB(45);"PROBABLE SCORE" */
line_60:;
    printf("%s", "THROW"); printf("\t"); { int _t; for(_t=0; _t<20; _t++) printf(" "); } printf("%s", "DESCRIPTION"); { int _t; for(_t=0; _t<45; _t++) printf(" "); } printf("%s", "PROBABLE SCORE"); printf("\n");
    /* BASIC: 70 PRINT" 1";TAB(20);"FAST OVERARM";TAB(45);"BULLSEYE OR COMPLETE MISS" */
line_70:;
    printf("%s", " 1"); { int _t; for(_t=0; _t<20; _t++) printf(" "); } printf("%s", "FAST OVERARM"); { int _t; for(_t=0; _t<45; _t++) printf(" "); } printf("%s", "BULLSEYE OR COMPLETE MISS"); printf("\n");
    /* BASIC: 80 PRINT" 2";TAB(20);"CONTROLLED OVERARM";TAB(45);"10, 20 OR 30 POINTS" */
line_80:;
    printf("%s", " 2"); { int _t; for(_t=0; _t<20; _t++) printf(" "); } printf("%s", "CONTROLLED OVERARM"); { int _t; for(_t=0; _t<45; _t++) printf(" "); } printf("%s", "10, 20 OR 30 POINTS"); printf("\n");
    /* BASIC: 90 PRINT" 3";TAB(20);"UNDERARM";TAB(45);"ANYTHING":PRINT */
line_90:;
    printf("%s", " 3"); { int _t; for(_t=0; _t<20; _t++) printf(" "); } printf("%s", "UNDERARM"); { int _t; for(_t=0; _t<45; _t++) printf(" "); } printf("%s", "ANYTHING"); printf("\n");
    printf("\n");
    /* BASIC: 100 DIM A$(20),S(20),W(10): M=0: R=0: FOR I=1 TO 20: S(I)=0: NEXT I */
line_100:;
    /* DIM A$(20),S(20),W(10) (handled statically) */
    M = 0;
    R = 0;
    I = 1; for_loop_I_100: if (((1) >= 0 && I > (20)) || ((1) < 0 && I < (20))) goto end_for_I_100;
    S_arr[(int)(I)] = 0;
    I += (1); goto for_loop_I_100; end_for_I_100:;
    /* BASIC: 110 INPUT "HOW MANY PLAYERS";N: PRINT */
line_110:;
    printf("%s", "HOW MANY PLAYERS"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &N);
    printf("\n");
    /* BASIC: 120 FOR I=1 TO N */
line_120:;
    I = 1; for_loop_I_120: if (((1) >= 0 && I > (N)) || ((1) < 0 && I < (N))) goto end_for_I_120;
    /* BASIC: 130 PRINT "NAME OF PLAYER #";I;:INPUT A$(I) */
line_130:;
    printf("%s", "NAME OF PLAYER #"); printf("%g ", (double)(I));
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str_arr[(int)(I)]);
    /* BASIC: 140 NEXT I */
line_140:;
    I += (1); goto for_loop_I_120; end_for_I_120:;
    /* BASIC: 150 R=R+1: PRINT: PRINT "ROUND";R:PRINT "---------" */
line_150:;
    R = R+1;
    printf("\n");
    printf("%s", "ROUND"); printf("%g ", (double)(R)); printf("\n");
    printf("%s", "---------"); printf("\n");
    /* BASIC: 160 FOR I=1 TO N */
line_160:;
    I = 1; for_loop_I_160: if (((1) >= 0 && I > (N)) || ((1) < 0 && I < (N))) goto end_for_I_160;
    /* BASIC: 170 PRINT: PRINT A$(I)"'S THROW";: INPUT T */
line_170:;
    printf("\n");
    printf("%s", A_str_arr[(int)(I)]); printf("%s", "'S THROW");
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &T);
    /* BASIC: 180 IF T<0 OR T>3 THEN PRINT "INPUT 1, 2, OR 3!": GOTO 170 */
line_180:;
    if (T<0   ||   T>3) { printf("%s", "INPUT 1, 2, OR 3!"); printf("\n"); goto line_170; }
    /* BASIC: 190 ON T GOTO 200, 210, 200 */
line_190:;
    switch ((int)(T)) {     case 1: goto line_200;     case 2: goto line_210;     case 3: goto line_200; }
    /* BASIC: 200 P1=.65: P2=.55: P3=.5: P4=.5: GOTO 230 */
line_200:;
    P1 = .65;
    P2 = .55;
    P3 = .5;
    P4 = .5;
    goto line_230;
    /* BASIC: 210 P1=.99: P2=.77: P3=.43: P4=.01: GOTO 230 */
line_210:;
    P1 = .99;
    P2 = .77;
    P3 = .43;
    P4 = .01;
    goto line_230;
    /* BASIC: 220 P1=.95: P2=.75: P3=.45: P4=.05 */
line_220:;
    P1 = .95;
    P2 = .75;
    P3 = .45;
    P4 = .05;
    /* BASIC: 230 U=RND(1) */
line_230:;
    U = ((double)rand() / (double)RAND_MAX);
    /* BASIC: 240 IF U>=P1 THEN PRINT "BULLSEYE!!  40 POINTS!":B=40: GOTO 290 */
line_240:;
    if (U>=P1) { printf("%s", "BULLSEYE!!  40 POINTS!"); printf("\n"); B = 40; goto line_290; }
    /* BASIC: 250 IF U>=P2 THEN PRINT "30-POINT ZONE!":B=30: GOTO 290 */
line_250:;
    if (U>=P2) { printf("%s", "30-POINT ZONE!"); printf("\n"); B = 30; goto line_290; }
    /* BASIC: 260 IF U>=P3 THEN PRINT "20-POINT ZONE":B=20: GOTO 290 */
line_260:;
    if (U>=P3) { printf("%s", "20-POINT ZONE"); printf("\n"); B = 20; goto line_290; }
    /* BASIC: 270 IF U>=P4 THEN PRINT "WHEW!  10 POINTS.":B=10: GOTO 290 */
line_270:;
    if (U>=P4) { printf("%s", "WHEW!  10 POINTS."); printf("\n"); B = 10; goto line_290; }
    /* BASIC: 280 PRINT "MISSED THE TARGET!  TOO BAD.": B=0 */
line_280:;
    printf("%s", "MISSED THE TARGET!  TOO BAD."); printf("\n");
    B = 0;
    /* BASIC: 290 S(I)=S(I)+B: PRINT "TOTAL SCORE =";S(I): NEXT I */
line_290:;
    S_arr[(int)(I)] = S_arr[(int)(I)]+B;
    printf("%s", "TOTAL SCORE ="); printf("%g ", (double)(S_arr[(int)(I)])); printf("\n");
    I += (1); goto for_loop_I_160; end_for_I_160:;
    /* BASIC: 300 FOR I=1 TO N */
line_300:;
    I = 1; for_loop_I_300: if (((1) >= 0 && I > (N)) || ((1) < 0 && I < (N))) goto end_for_I_300;
    /* BASIC: 310 IF S(I)>=200 THEN M=M+1: W(M)=I */
line_310:;
    if (S_arr[(int)(I)]>=200) { M = M+1; W_arr[(int)(M)] = I; }
    /* BASIC: 320 NEXT I */
line_320:;
    I += (1); goto for_loop_I_300; end_for_I_300:;
    /* BASIC: 330 IF M=0 THEN 150 */
line_330:;
    if (M==0) { goto line_150; }
    /* BASIC: 340 PRINT: PRINT "WE HAVE A WINNER!!": PRINT */
line_340:;
    printf("\n");
    printf("%s", "WE HAVE A WINNER!!"); printf("\n");
    printf("\n");
    /* BASIC: 350 FOR I=1 TO M: PRINT A$(W(I));" SCORED";S(W(I));"POINTS.": NEXT I */
line_350:;
    I = 1; for_loop_I_350: if (((1) >= 0 && I > (M)) || ((1) < 0 && I < (M))) goto end_for_I_350;
    printf("%s", A_str_arr[(int)(W_arr[(int)(I)])]); printf("%s", " SCORED"); printf("%g ", (double)(S_arr[(int)(W_arr[(int)(I)])])); printf("%s", "POINTS."); printf("\n");
    I += (1); goto for_loop_I_350; end_for_I_350:;
    /* BASIC: 360 PRINT: PRINT "THANKS FOR THE GAME.": END */
line_360:;
    printf("\n");
    printf("%s", "THANKS FOR THE GAME."); printf("\n");
    exit(0);

    return 0;
}
