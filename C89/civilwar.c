/*
 * Transpiled from civilwar.bas
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

static DataItem program_data[84] = {
    { DATA_STR, 0.0, "BULL RUN" },
    { DATA_NUM, 18000.0, NULL },
    { DATA_NUM, 18500.0, NULL },
    { DATA_NUM, 1967.0, NULL },
    { DATA_NUM, 2708.0, NULL },
    { DATA_NUM, 1.0, NULL },
    { DATA_STR, 0.0, "SHILOH" },
    { DATA_NUM, 40000.0, NULL },
    { DATA_NUM, 44894.0, NULL },
    { DATA_NUM, 10699.0, NULL },
    { DATA_NUM, 13047.0, NULL },
    { DATA_NUM, 3.0, NULL },
    { DATA_STR, 0.0, "SEVEN DAYS" },
    { DATA_NUM, 95000.0, NULL },
    { DATA_NUM, 115000.0, NULL },
    { DATA_NUM, 20614.0, NULL },
    { DATA_NUM, 15849.0, NULL },
    { DATA_NUM, 3.0, NULL },
    { DATA_STR, 0.0, "SECOND BULL RUN" },
    { DATA_NUM, 54000.0, NULL },
    { DATA_NUM, 63000.0, NULL },
    { DATA_NUM, 10000.0, NULL },
    { DATA_NUM, 14000.0, NULL },
    { DATA_NUM, 2.0, NULL },
    { DATA_STR, 0.0, "ANTIETAM" },
    { DATA_NUM, 40000.0, NULL },
    { DATA_NUM, 50000.0, NULL },
    { DATA_NUM, 10000.0, NULL },
    { DATA_NUM, 12000.0, NULL },
    { DATA_NUM, 3.0, NULL },
    { DATA_STR, 0.0, "FREDERICKSBURG" },
    { DATA_NUM, 75000.0, NULL },
    { DATA_NUM, 120000.0, NULL },
    { DATA_NUM, 5377.0, NULL },
    { DATA_NUM, 12653.0, NULL },
    { DATA_NUM, 1.0, NULL },
    { DATA_STR, 0.0, "MURFREESBORO" },
    { DATA_NUM, 38000.0, NULL },
    { DATA_NUM, 45000.0, NULL },
    { DATA_NUM, 11000.0, NULL },
    { DATA_NUM, 12000.0, NULL },
    { DATA_NUM, 1.0, NULL },
    { DATA_STR, 0.0, "CHANCELLORSVILLE" },
    { DATA_NUM, 32000.0, NULL },
    { DATA_NUM, 90000.0, NULL },
    { DATA_NUM, 13000.0, NULL },
    { DATA_NUM, 17197.0, NULL },
    { DATA_NUM, 2.0, NULL },
    { DATA_STR, 0.0, "VICKSBURG" },
    { DATA_NUM, 50000.0, NULL },
    { DATA_NUM, 70000.0, NULL },
    { DATA_NUM, 12000.0, NULL },
    { DATA_NUM, 19000.0, NULL },
    { DATA_NUM, 1.0, NULL },
    { DATA_STR, 0.0, "GETTYSBURG" },
    { DATA_NUM, 72500.0, NULL },
    { DATA_NUM, 85000.0, NULL },
    { DATA_NUM, 20000.0, NULL },
    { DATA_NUM, 23000.0, NULL },
    { DATA_NUM, 3.0, NULL },
    { DATA_STR, 0.0, "CHICKAMAUGA" },
    { DATA_NUM, 66000.0, NULL },
    { DATA_NUM, 60000.0, NULL },
    { DATA_NUM, 18000.0, NULL },
    { DATA_NUM, 16000.0, NULL },
    { DATA_NUM, 2.0, NULL },
    { DATA_STR, 0.0, "CHATTANOOGA" },
    { DATA_NUM, 37000.0, NULL },
    { DATA_NUM, 60000.0, NULL },
    { DATA_NUM, 36700.0, NULL },
    { DATA_NUM, 5800.0, NULL },
    { DATA_NUM, 2.0, NULL },
    { DATA_STR, 0.0, "SPOTSYLVANIA" },
    { DATA_NUM, 62000.0, NULL },
    { DATA_NUM, 110000.0, NULL },
    { DATA_NUM, 17723.0, NULL },
    { DATA_NUM, 18000.0, NULL },
    { DATA_NUM, 2.0, NULL },
    { DATA_STR, 0.0, "ATLANTA" },
    { DATA_NUM, 65000.0, NULL },
    { DATA_NUM, 100000.0, NULL },
    { DATA_NUM, 8500.0, NULL },
    { DATA_NUM, 3700.0, NULL },
    { DATA_NUM, 1.0, NULL },
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
static double A, B, C1, C2, C5, C6, D, E, E2, F, F1, H, I, I1, I2, L, LET, M, M1, M2, M3, M4, M5, M6, N, O, O2, ON, P, P1, P2, Q1, Q2, R, R1, R2, S, S0, S2, T1, T2, U, U2, W, W0, Y, Y1, Y2, Z;
static char B_str[256] = {0};
static char C_str[256] = {0};
static char X_str[256] = {0};
static double B_arr[2000] = {0};
static double C1_arr[2000] = {0};
static double C2_arr[2000] = {0};
static double D_arr[2000] = {0};
static double F_arr[2000] = {0};
static double H_arr[2000] = {0};
static double M_arr[2000] = {0};
static double M1_arr[2000] = {0};
static double M2_arr[2000] = {0};
static double O_arr[2000] = {0};
static double S_arr[2000] = {0};
static double S2_arr[2000] = {0};
static char C_str_arr[1000][64] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 2 PRINT TAB(26) "CIVIL WAR" */
line_2:;
    { int _t; for(_t=0; _t<26; _t++) printf(" "); } printf("%s", "CIVIL WAR"); printf("\n");
    /* BASIC: 4 PRINT TAB(15) "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 6 PRINT : PRINT : PRINT */
line_6:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 20 REM OR IGINAL GAME DESIGN: CRAM, GOODIE, HIBBARD LEXING TO N H.S. */
line_20:;
    /* REM OR IGINAL GAME DESIGN */
    /* UNTRANSLATED: CRAM, GOODIE, HIBBARD LEXING TO N H.S. */
    /* BASIC: 30 REM MODIFICATIONS: G. PAUL, R. HESS (TIES), 1973 */
line_30:;
    /* REM MODIFICATIONS */
    /* UNTRANSLATED: G. PAUL, R. HESS (TIES), 1973 */
    /* BASIC: 50 DIM S(4),C$(14),M1(14),M2(14),C1(14),C2(14),M(14) */
line_50:;
    /* DIM S(4),C$(14),M1(14),M2(14),C1(14),C2(14),M(14) (handled statically) */
    /* BASIC: 60 REM UNION INFO ON LIKELY CONFEDERATE STRATEGY */
line_60:;
    /* REM UNION INFO ON LIKELY CONFEDERATE STRATEGY */
    /* BASIC: 70 S(1)=25 : S(2)=25 : S(3)=25 : S(4)=25 */
line_70:;
    S_arr[(int)(1)] = 25;
    S_arr[(int)(2)] = 25;
    S_arr[(int)(3)] = 25;
    S_arr[(int)(4)] = 25;
    /* BASIC: 82 REM READ HIST OR ICAL DATA. */
line_82:;
    /* REM READ HIST OR ICAL DATA. */
    /* BASIC: 84 FOR D=1 TO 14 */
line_84:;
    D = 1; for_loop_D_84: if (((1) >= 0 && D > (14)) || ((1) < 0 && D < (14))) goto end_for_D_84;
    /* BASIC: 86 READ C$(D),M1(D),M2(D),C1(D),C2(D),M(D) */
line_86:;
    read_string(C_str_arr[(int)(D)], sizeof(C_str_arr[(int)(D)])); read_numeric(&(M1_arr[(int)(D)])); read_numeric(&(M2_arr[(int)(D)])); read_numeric(&(C1_arr[(int)(D)])); read_numeric(&(C2_arr[(int)(D)])); read_numeric(&(M_arr[(int)(D)]));
    /* BASIC: 88 NEXT D */
line_88:;
    D += (1); goto for_loop_D_84; end_for_D_84:;
    /* BASIC: 89 LET D=RND(-1) */
line_89:;
    /* UNTRANSLATED: LET D=RND(-1) */
    /* BASIC: 90 PRINT */
line_90:;
    printf("\n");
    /* BASIC: 100 PRINT "DO YOU WANT INSTRUCTIONS"; */
line_100:;
    printf("%s", "DO YOU WANT INSTRUCTIONS");
    /* BASIC: 110 INPUT X$ */
line_110:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", X_str);
    /* BASIC: 120 IF X$="YES" THEN 160 */
line_120:;
    if (strcmp(X_str, "YES") == 0) { goto line_160; }
    /* BASIC: 130 IF X$="NO" THEN 370 */
line_130:;
    if (strcmp(X_str, "NO") == 0) { goto line_370; }
    /* BASIC: 140 PRINT "YES OR NO -- "; */
line_140:;
    printf("%s", "YES OR NO -- ");
    /* BASIC: 150 GOTO 110 */
line_150:;
    goto line_110;
    /* BASIC: 160 PRINT : PRINT : PRINT : PRINT */
line_160:;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 170 PRINT "THIS IS A CIVIL WAR SIMULATION." */
line_170:;
    printf("%s", "THIS IS A CIVIL WAR SIMULATION."); printf("\n");
    /* BASIC: 180 PRINT "TO PLAY TYPE A RESPONSE WHEN THE COMPUTER ASKS." */
line_180:;
    printf("%s", "TO PLAY TYPE A RESPONSE WHEN THE COMPUTER ASKS."); printf("\n");
    /* BASIC: 190 PRINT "REMEMBER THAT ALL FACTORS ARE INTERRELATED AND THAT YOUR" */
line_190:;
    printf("%s", "REMEMBER THAT ALL FACTORS ARE INTERRELATED AND THAT YOUR"); printf("\n");
    /* BASIC: 200 PRINT "RESPONSES COULD CHANGE HISTORY. FACTS AND FIGURES USED ARE" */
line_200:;
    printf("%s", "RESPONSES COULD CHANGE HISTORY. FACTS AND FIGURES USED ARE"); printf("\n");
    /* BASIC: 210 PRINT "BASED ON THE ACTUAL OCCURRENCE. MOST BATTLES TEND TO RESULT" */
line_210:;
    printf("%s", "BASED ON THE ACTUAL OCCURRENCE. MOST BATTLES TEND TO RESULT"); printf("\n");
    /* BASIC: 220 PRINT "AS THEY DID IN THE CIVIL WAR, BUT IT ALL DEPENDS ON YOU!!" */
line_220:;
    printf("%s", "AS THEY DID IN THE CIVIL WAR, BUT IT ALL DEPENDS ON YOU!!"); printf("\n");
    /* BASIC: 230 PRINT */
line_230:;
    printf("\n");
    /* BASIC: 240 PRINT "THE OBJECT OF THE GAME IS TO WIN AS MANY BATTLES AS "; */
line_240:;
    printf("%s", "THE OBJECT OF THE GAME IS TO WIN AS MANY BATTLES AS ");
    /* BASIC: 245 PRINT "POSSIBLE." */
line_245:;
    printf("%s", "POSSIBLE."); printf("\n");
    /* BASIC: 250 PRINT */
line_250:;
    printf("\n");
    /* BASIC: 260 PRINT "YOUR CHOICES FOR DEFENSIVE STRATEGY ARE:" */
line_260:;
    printf("%s", "YOUR CHOICES FOR DEFENSIVE STRATEGY ARE:"); printf("\n");
    /* BASIC: 270 PRINT "        (1) ARTILLERY ATTACK" */
line_270:;
    printf("%s", "        (1) ARTILLERY ATTACK"); printf("\n");
    /* BASIC: 280 PRINT "        (2) FORTIFICATION AGAINST FRONTAL ATTACK" */
line_280:;
    printf("%s", "        (2) FORTIFICATION AGAINST FRONTAL ATTACK"); printf("\n");
    /* BASIC: 290 PRINT "        (3) FORTIFICATION AGAINST FLANKING MANEUVERS" */
line_290:;
    printf("%s", "        (3) FORTIFICATION AGAINST FLANKING MANEUVERS"); printf("\n");
    /* BASIC: 300 PRINT "        (4) FALLING BACK" */
line_300:;
    printf("%s", "        (4) FALLING BACK"); printf("\n");
    /* BASIC: 310 PRINT " YOUR CHOICES FOR OFFENSIVE STRATEGY ARE:" */
line_310:;
    printf("%s", " YOUR CHOICES FOR OFFENSIVE STRATEGY ARE:"); printf("\n");
    /* BASIC: 320 PRINT "        (1) ARTILLERY ATTACK" */
line_320:;
    printf("%s", "        (1) ARTILLERY ATTACK"); printf("\n");
    /* BASIC: 330 PRINT "        (2) FRONTAL ATTACK" */
line_330:;
    printf("%s", "        (2) FRONTAL ATTACK"); printf("\n");
    /* BASIC: 340 PRINT "        (3) FLANKING MANEUVERS" */
line_340:;
    printf("%s", "        (3) FLANKING MANEUVERS"); printf("\n");
    /* BASIC: 350 PRINT "        (4) ENCIRCLEMENT" */
line_350:;
    printf("%s", "        (4) ENCIRCLEMENT"); printf("\n");
    /* BASIC: 360 PRINT "YOU MAY SURRENDER BY TYPING A '5' FOR YOUR STRATEGY." */
line_360:;
    printf("%s", "YOU MAY SURRENDER BY TYPING A '5' FOR YOUR STRATEGY."); printf("\n");
    /* BASIC: 370 PRINT : PRINT : PRINT : PRINT "ARE THERE TWO GENERALS PRESENT "; */
line_370:;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("%s", "ARE THERE TWO GENERALS PRESENT ");
    /* BASIC: 380 PRINT "(ANSWER YES OR NO)"; */
line_380:;
    printf("%s", "(ANSWER YES OR NO)");
    /* BASIC: 390 INPUT B$ */
line_390:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", B_str);
    /* BASIC: 400 IF B$="YES" THEN 430 */
line_400:;
    if (strcmp(B_str, "YES") == 0) { goto line_430; }
    /* BASIC: 410 IF B$ <> "NO" THEN 380 */
line_410:;
    if (strcmp(B_str, "NO") != 0) { goto line_380; }
    /* BASIC: 420 PRINT : PRINT "YOU ARE THE CONFEDERACY.   GOOD LUCK!" */
line_420:;
    printf("\n");
    printf("%s", "YOU ARE THE CONFEDERACY.   GOOD LUCK!"); printf("\n");
    /* BASIC: 425 PRINT */
line_425:;
    printf("\n");
    /* BASIC: 430 LET D=1 */
line_430:;
    /* UNTRANSLATED: LET D=1 */
    /* BASIC: 440 IF B$ <> "YES" THEN 460 */
line_440:;
    if (strcmp(B_str, "YES") != 0) { goto line_460; }
    /* BASIC: 450 LET D=2 */
line_450:;
    /* UNTRANSLATED: LET D=2 */
    /* BASIC: 460 PRINT "SELECT A BATTLE BY TYPING A NUMBER FROM 1 TO 14 ON" */
line_460:;
    printf("%s", "SELECT A BATTLE BY TYPING A NUMBER FROM 1 TO 14 ON"); printf("\n");
    /* BASIC: 470 PRINT "REQUEST.  TYPE ANY OTHER NUMBER TO END THE SIMULATION." */
line_470:;
    printf("%s", "REQUEST.  TYPE ANY OTHER NUMBER TO END THE SIMULATION."); printf("\n");
    /* BASIC: 480 PRINT "BUT '0' BRINGS BACK EXACT PREVIOUS BATTLE SITUATION" */
line_480:;
    printf("%s", "BUT '0' BRINGS BACK EXACT PREVIOUS BATTLE SITUATION"); printf("\n");
    /* BASIC: 490 PRINT "ALLOWING YOU TO REPLAY IT" */
line_490:;
    printf("%s", "ALLOWING YOU TO REPLAY IT"); printf("\n");
    /* BASIC: 500 PRINT */
line_500:;
    printf("\n");
    /* BASIC: 510 PRINT "NOTE: A NEGATIVE FOOD$ ENTRY CAUSES THE PROGRAM TO " */
line_510:;
    printf("%s", "NOTE: A NEGATIVE FOOD$ ENTRY CAUSES THE PROGRAM TO "); printf("\n");
    /* BASIC: 520 PRINT "USE THE ENTRIES FROM THE PREVIOUS BATTLE" */
line_520:;
    printf("%s", "USE THE ENTRIES FROM THE PREVIOUS BATTLE"); printf("\n");
    /* BASIC: 530 PRINT */
line_530:;
    printf("\n");
    /* BASIC: 540 PRINT "AFTER REQUESTING A BATTLE, DO YOU WISH "; */
line_540:;
    printf("%s", "AFTER REQUESTING A BATTLE, DO YOU WISH ");
    /* BASIC: 550 PRINT "BATTLE DESCRIPTIONS "; */
line_550:;
    printf("%s", "BATTLE DESCRIPTIONS ");
    /* BASIC: 560 PRINT "(ANSWER YES OR NO)"; */
line_560:;
    printf("%s", "(ANSWER YES OR NO)");
    /* BASIC: 570 INPUT X$ */
line_570:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", X_str);
    /* BASIC: 580 IF X$="YES" THEN 600 */
line_580:;
    if (strcmp(X_str, "YES") == 0) { goto line_600; }
    /* BASIC: 590 IF X$ <> "NO" THEN 560 */
line_590:;
    if (strcmp(X_str, "NO") != 0) { goto line_560; }
    /* BASIC: 600 L=0:W=0:R1=0:Q1=0:M3=0:M4=0:P1=0:P2=0:T1=0:T2=0 */
line_600:;
    L = 0;
    W = 0;
    R1 = 0;
    Q1 = 0;
    M3 = 0;
    M4 = 0;
    P1 = 0;
    P2 = 0;
    T1 = 0;
    T2 = 0;
    /* BASIC: 610 F(2)=0:H(2)=0:B(2)=0:R2=0:Q2=0:C6=0:F=0:W0=0:Y=0:Y2=0:U=0:U2=0 */
line_610:;
    F_arr[(int)(2)] = 0;
    H_arr[(int)(2)] = 0;
    B_arr[(int)(2)] = 0;
    R2 = 0;
    Q2 = 0;
    C6 = 0;
    F = 0;
    W0 = 0;
    Y = 0;
    Y2 = 0;
    U = 0;
    U2 = 0;
    /* BASIC: 620 PRINT : PRINT : PRINT */
line_620:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 630 PRINT "WHICH BATTLE DO YOU WISH TO SIMULATE"; */
line_630:;
    printf("%s", "WHICH BATTLE DO YOU WISH TO SIMULATE");
    /* BASIC: 640 INPUT A */
line_640:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &A);
    /* BASIC: 650 IF A <> 0 THEN 660 */
line_650:;
    if (A != 0) { goto line_660; }
    /* BASIC: 655 IF R <> 0 THEN 1140 */
line_655:;
    if (R != 0) { goto line_1140; }
    /* BASIC: 660 IF A <=0 THEN 2860 */
line_660:;
    if (A <=0) { goto line_2860; }
    /* BASIC: 665 IF A >= 15 THEN 2860 */
line_665:;
    if (A >= 15) { goto line_2860; }
    /* BASIC: 670 LET C$=C$(A) */
line_670:;
    /* UNTRANSLATED: LET C$=C$(A) */
    /* BASIC: 680 LET M1=M1(A) */
line_680:;
    /* UNTRANSLATED: LET M1=M1(A) */
    /* BASIC: 690 LET M2=M2(A) */
line_690:;
    /* UNTRANSLATED: LET M2=M2(A) */
    /* BASIC: 700 LET C1=C1(A) */
line_700:;
    /* UNTRANSLATED: LET C1=C1(A) */
    /* BASIC: 710 LET C2=C2(A) */
line_710:;
    /* UNTRANSLATED: LET C2=C2(A) */
    /* BASIC: 720 LET M=M(A) */
line_720:;
    /* UNTRANSLATED: LET M=M(A) */
    /* BASIC: 960 LET U=0 */
line_960:;
    /* UNTRANSLATED: LET U=0 */
    /* BASIC: 970 REM  INFLATION CALC */
line_970:;
    /* REM  INFLATION CALC */
    /* BASIC: 980 LET I1=10+(L-W)*2 */
line_980:;
    /* UNTRANSLATED: LET I1=10+(L-W)*2 */
    /* BASIC: 990 LET I2=10+(W-L)*2 */
line_990:;
    /* UNTRANSLATED: LET I2=10+(W-L)*2 */
    /* BASIC: 1000 REM - MONEY AVAILABLE */
line_1000:;
    /* REM - MONEY AVAILABLE */
    /* BASIC: 1010 LET D(1)=100*INT((M1*(100-I1)/2000)*(1+(R1-Q1)/(R1+1))+.5) */
line_1010:;
    /* UNTRANSLATED: LET D(1)=100*INT((M1*(100-I1)/2000)*(1+(R1-Q1)/(R1+1))+.5) */
    /* BASIC: 1020 LET D(2)=100*INT(M2*(100-I2)/2000+.5) */
line_1020:;
    /* UNTRANSLATED: LET D(2)=100*INT(M2*(100-I2)/2000+.5) */
    /* BASIC: 1030 IF B$ <> "YES" THEN 1050 */
line_1030:;
    if (strcmp(B_str, "YES") != 0) { goto line_1050; }
    /* BASIC: 1040 LET D(2)=100*INT((M2*(100-I2)/2000)*(1+(R2-Q2)/(R2+1))+.5) */
line_1040:;
    /* UNTRANSLATED: LET D(2)=100*INT((M2*(100-I2)/2000)*(1+(R2-Q2)/(R2+1))+.5) */
    /* BASIC: 1050 REM - MEN   AVAILABLE */
line_1050:;
    /* REM - MEN   AVAILABLE */
    /* BASIC: 1060 LET M5=INT(M1*(1+(P1-T1)/(M3+1))) */
line_1060:;
    /* UNTRANSLATED: LET M5=INT(M1*(1+(P1-T1)/(M3+1))) */
    /* BASIC: 1070 LET M6=INT(M2*(1+(P2-T2)/(M4+1))) */
line_1070:;
    /* UNTRANSLATED: LET M6=INT(M2*(1+(P2-T2)/(M4+1))) */
    /* BASIC: 1080 LET F1=5*M1/6 */
line_1080:;
    /* UNTRANSLATED: LET F1=5*M1/6 */
    /* BASIC: 1090 PRINT : PRINT : PRINT : PRINT : PRINT */
line_1090:;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 1100 PRINT "THIS IS THE BATTLE OF ";C$ */
line_1100:;
    printf("%s", "THIS IS THE BATTLE OF "); printf("%s", C_str); printf("\n");
    /* BASIC: 1110 IF X$="NO" THEN 1150 */
line_1110:;
    if (strcmp(X_str, "NO") == 0) { goto line_1150; }
    /* BASIC: 1120 IF A>11 THEN 1130 */
line_1120:;
    if (A>11) { goto line_1130; }
    /* BASIC: 1125 ON A GOTO 3580,3620,3650,3690,3720,3750,3780,3800,3830,3860,3890 */
line_1125:;
    switch ((int)(A)) {     case 1: goto line_3580;     case 2: goto line_3620;     case 3: goto line_3650;     case 4: goto line_3690;     case 5: goto line_3720;     case 6: goto line_3750;     case 7: goto line_3780;     case 8: goto line_3800;     case 9: goto line_3830;     case 10: goto line_3860;     case 11: goto line_3890; }
    /* BASIC: 1130 ON A-11 GOTO 3920,3950,3980 */
line_1130:;
    switch ((int)(A-11)) {     case 1: goto line_3920;     case 2: goto line_3950;     case 3: goto line_3980; }
    /* BASIC: 1140 PRINT C$" INSTANT REPLAY" */
line_1140:;
    printf("%s", C_str); printf("%s", " INSTANT REPLAY"); printf("\n");
    /* BASIC: 1150 PRINT */
line_1150:;
    printf("\n");
    /* BASIC: 1160 PRINT " ","CONFEDERACY"," UNION" */
line_1160:;
    printf("%s", " "); printf("\t"); printf("%s", "CONFEDERACY"); printf("\t"); printf("%s", " UNION"); printf("\n");
    /* BASIC: 1170 PRINT "MEN"," "M5," "M6 */
line_1170:;
    printf("%s", "MEN"); printf("\t"); printf("%s", " "); printf("%g ", (double)(M5)); printf("\t"); printf("%s", " "); printf("%g ", (double)(M6)); printf("\n");
    /* BASIC: 1180 PRINT "MONEY","$";D(1),"$";D(2) */
line_1180:;
    printf("%s", "MONEY"); printf("\t"); printf("%s", "$"); printf("%g ", (double)(D_arr[(int)(1)])); printf("\t"); printf("%s", "$"); printf("%g ", (double)(D_arr[(int)(2)])); printf("\n");
    /* BASIC: 1190 PRINT "INFLATION"," ";I1+15;"%"," ";I2;"%" */
line_1190:;
    printf("%s", "INFLATION"); printf("\t"); printf("%s", " "); printf("%g ", (double)(I1+15)); printf("%s", "%"); printf("\t"); printf("%s", " "); printf("%g ", (double)(I2)); printf("%s", "%"); printf("\n");
    /* BASIC: 1195 PRINT */
line_1195:;
    printf("\n");
    /* BASIC: 1200 REM - ONLY IN PRINT OUT IS CONFED INFLATION = I1+15% */
line_1200:;
    /* REM - ONLY IN PRINT OUT IS CONFED INFLATION = I1+15% */
    /* BASIC: 1210 REM - IF TWO GENERALS, INPUT CONFED. FIRST */
line_1210:;
    /* REM - IF TWO GENERALS, INPUT CONFED. FIRST */
    /* BASIC: 1220 FOR I=1 TO D */
line_1220:;
    I = 1; for_loop_I_1220: if (((1) >= 0 && I > (D)) || ((1) < 0 && I < (D))) goto end_for_I_1220;
    /* BASIC: 1230 IF B$ <> "YES" THEN 1260 */
line_1230:;
    if (strcmp(B_str, "YES") != 0) { goto line_1260; }
    /* BASIC: 1240 IF I=2 THEN 1260 */
line_1240:;
    if (I==2) { goto line_1260; }
    /* BASIC: 1250 PRINT "CONFEDERATE GENERAL---"; */
line_1250:;
    printf("%s", "CONFEDERATE GENERAL---");
    /* BASIC: 1260 PRINT "HOW MUCH DO YOU WISH TO SPEND FOR" */
line_1260:;
    printf("%s", "HOW MUCH DO YOU WISH TO SPEND FOR"); printf("\n");
    /* BASIC: 1270 PRINT " - FOOD......"; */
line_1270:;
    printf("%s", " - FOOD......");
    /* BASIC: 1280 INPUT F */
line_1280:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &F);
    /* BASIC: 1290 IF F >= 0 THEN 1360 */
line_1290:;
    if (F >= 0) { goto line_1360; }
    /* BASIC: 1300 IF R1 <> 0 THEN 1330 */
line_1300:;
    if (R1 != 0) { goto line_1330; }
    /* BASIC: 1310 PRINT "NO PREVIOUS ENTRIES" */
line_1310:;
    printf("%s", "NO PREVIOUS ENTRIES"); printf("\n");
    /* BASIC: 1320 GOTO 1270 */
line_1320:;
    goto line_1270;
    /* BASIC: 1330 PRINT "ASSUME YOU WANT TO KEEP SAME ALLOCATIONS" */
line_1330:;
    printf("%s", "ASSUME YOU WANT TO KEEP SAME ALLOCATIONS"); printf("\n");
    /* BASIC: 1340 PRINT */
line_1340:;
    printf("\n");
    /* BASIC: 1350 GOTO 1510 */
line_1350:;
    goto line_1510;
    /* BASIC: 1360 LET F(I)=F */
line_1360:;
    /* UNTRANSLATED: LET F(I)=F */
    /* BASIC: 1370 PRINT " - SALARIES.."; */
line_1370:;
    printf("%s", " - SALARIES..");
    /* BASIC: 1380 INPUT H(I) */
line_1380:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &(H_arr[(int)(I)]));
    /* BASIC: 1390 LET N=1 */
line_1390:;
    /* UNTRANSLATED: LET N=1 */
    /* BASIC: 1400 IF H(I)<0 THEN 1490 */
line_1400:;
    if (H_arr[(int)(I)]<0) { goto line_1490; }
    /* BASIC: 1410 PRINT " - AMMUNITION"; */
line_1410:;
    printf("%s", " - AMMUNITION");
    /* BASIC: 1420 INPUT B(I) */
line_1420:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &(B_arr[(int)(I)]));
    /* BASIC: 1430 LET N=2 */
line_1430:;
    /* UNTRANSLATED: LET N=2 */
    /* BASIC: 1440 IF B(I)<0 THEN 1490 */
line_1440:;
    if (B_arr[(int)(I)]<0) { goto line_1490; }
    /* BASIC: 1450 PRINT */
line_1450:;
    printf("\n");
    /* BASIC: 1460 IF F(I)+H(I)+B(I) <= D(I) THEN 1510 */
line_1460:;
    if (F_arr[(int)(I)]+H_arr[(int)(I)]+B_arr[(int)(I)] <= D_arr[(int)(I)]) { goto line_1510; }
    /* BASIC: 1470 PRINT "THINK AGAIN! YOU HAVE ONLY $"D(I) */
line_1470:;
    printf("%s", "THINK AGAIN! YOU HAVE ONLY $"); printf("%g ", (double)(D_arr[(int)(I)])); printf("\n");
    /* BASIC: 1480 GOTO 1270 */
line_1480:;
    goto line_1270;
    /* BASIC: 1490 PRINT "NEGATIVE VALUES NOT ALLOWED." */
line_1490:;
    printf("%s", "NEGATIVE VALUES NOT ALLOWED."); printf("\n");
    /* BASIC: 1500 ON N GOTO 1370,1410 */
line_1500:;
    switch ((int)(N)) {     case 1: goto line_1370;     case 2: goto line_1410; }
    /* BASIC: 1510 IF B$ <> "YES" THEN 1550 */
line_1510:;
    if (strcmp(B_str, "YES") != 0) { goto line_1550; }
    /* BASIC: 1520 IF I=2 THEN 1550 */
line_1520:;
    if (I==2) { goto line_1550; }
    /* BASIC: 1530 PRINT "UNION GENERAL---"; */
line_1530:;
    printf("%s", "UNION GENERAL---");
    /* BASIC: 1540 NEXT I */
line_1540:;
    I += (1); goto for_loop_I_1220; end_for_I_1220:;
    /* BASIC: 1550 FOR Z=1 TO D */
line_1550:;
    Z = 1; for_loop_Z_1550: if (((1) >= 0 && Z > (D)) || ((1) < 0 && Z < (D))) goto end_for_Z_1550;
    /* BASIC: 1560 IF B$ <> "YES" THEN 1620 */
line_1560:;
    if (strcmp(B_str, "YES") != 0) { goto line_1620; }
    /* BASIC: 1570 ON Z GOTO 1580,1600 */
line_1570:;
    switch ((int)(Z)) {     case 1: goto line_1580;     case 2: goto line_1600; }
    /* BASIC: 1580 PRINT "CONFEDERATE "; */
line_1580:;
    printf("%s", "CONFEDERATE ");
    /* BASIC: 1590 GOTO 1620 */
line_1590:;
    goto line_1620;
    /* BASIC: 1600 PRINT "      UNION "; */
line_1600:;
    printf("%s", "      UNION ");
    /* BASIC: 1610 REM - FIND M OR ALE */
line_1610:;
    /* REM - FIND M OR ALE */
    /* BASIC: 1620 LET O=((2*F(Z)^2+H(Z)^2)/F1^2+1) */
line_1620:;
    /* UNTRANSLATED: LET O=((2*F(Z)^2+H(Z)^2)/F1^2+1) */
    /* BASIC: 1630 IF O<10 THEN 1660 */
line_1630:;
    if (O<10) { goto line_1660; }
    /* BASIC: 1640 PRINT "MORALE IS HIGH" */
line_1640:;
    printf("%s", "MORALE IS HIGH"); printf("\n");
    /* BASIC: 1650 GOTO 1700 */
line_1650:;
    goto line_1700;
    /* BASIC: 1660 IF O<5 THEN 1690 */
line_1660:;
    if (O<5) { goto line_1690; }
    /* BASIC: 1670 PRINT "MORALE IS FAIR" */
line_1670:;
    printf("%s", "MORALE IS FAIR"); printf("\n");
    /* BASIC: 1680 GOTO 1700 */
line_1680:;
    goto line_1700;
    /* BASIC: 1690 PRINT "MORALE IS POOR" */
line_1690:;
    printf("%s", "MORALE IS POOR"); printf("\n");
    /* BASIC: 1700 IF B$ <> "YES" THEN 1760 */
line_1700:;
    if (strcmp(B_str, "YES") != 0) { goto line_1760; }
    /* BASIC: 1710 LET O(Z)=O */
line_1710:;
    /* UNTRANSLATED: LET O(Z)=O */
    /* BASIC: 1720 NEXT Z */
line_1720:;
    Z += (1); goto for_loop_Z_1550; end_for_Z_1550:;
    /* BASIC: 1730 LET O2=O(2) */
line_1730:;
    /* UNTRANSLATED: LET O2=O(2) */
    /* BASIC: 1740 LET O=O(1) */
line_1740:;
    /* UNTRANSLATED: LET O=O(1) */
    /* BASIC: 1750 PRINT "CONFEDERATE GENERAL---"; */
line_1750:;
    printf("%s", "CONFEDERATE GENERAL---");
    /* BASIC: 1760 REM - ACTUAL OFF/DEF BATTLE SITUATION */
line_1760:;
    /* REM - ACTUAL OFF/DEF BATTLE SITUATION */
    /* BASIC: 1770 IF M <> 3 THEN 1800 */
line_1770:;
    if (M != 3) { goto line_1800; }
    /* BASIC: 1780 PRINT "YOU ARE ON THE OFFENSIVE" */
line_1780:;
    printf("%s", "YOU ARE ON THE OFFENSIVE"); printf("\n");
    /* BASIC: 1790 GOTO 1840 */
line_1790:;
    goto line_1840;
    /* BASIC: 1800 IF M <> 1 THEN 1830 */
line_1800:;
    if (M != 1) { goto line_1830; }
    /* BASIC: 1810 PRINT "YOU ARE ON THE DEFENSIVE" */
line_1810:;
    printf("%s", "YOU ARE ON THE DEFENSIVE"); printf("\n");
    /* BASIC: 1820 GOTO 1840 */
line_1820:;
    goto line_1840;
    /* BASIC: 1830 PRINT "BOTH SIDES ARE ON THE OFFENSIVE " */
line_1830:;
    printf("%s", "BOTH SIDES ARE ON THE OFFENSIVE "); printf("\n");
    /* BASIC: 1840 PRINT */
line_1840:;
    printf("\n");
    /* BASIC: 1850 REM - CHOOSE STRATEGIES */
line_1850:;
    /* REM - CHOOSE STRATEGIES */
    /* BASIC: 1860 IF B$ <> "YES" THEN 1910 */
line_1860:;
    if (strcmp(B_str, "YES") != 0) { goto line_1910; }
    /* BASIC: 1870 FOR I=1 TO 2 */
line_1870:;
    I = 1; for_loop_I_1870: if (((1) >= 0 && I > (2)) || ((1) < 0 && I < (2))) goto end_for_I_1870;
    /* BASIC: 1880 ON I GOTO 1890,1920 */
line_1880:;
    switch ((int)(I)) {     case 1: goto line_1890;     case 2: goto line_1920; }
    /* BASIC: 1890 PRINT "CONFEDERATE STRATEGY "; */
line_1890:;
    printf("%s", "CONFEDERATE STRATEGY ");
    /* BASIC: 1900 GOTO 1920 */
line_1900:;
    goto line_1920;
    /* BASIC: 1910 PRINT "YOUR STRATEGY "; */
line_1910:;
    printf("%s", "YOUR STRATEGY ");
    /* BASIC: 1920 INPUT Y */
line_1920:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &Y);
    /* BASIC: 1930 IF ABS(Y-3)<3 THEN 1960 */
line_1930:;
    if (fabs(Y-3)<3) { goto line_1960; }
    /* BASIC: 1940 PRINT "STRATEGY";Y;"NOT ALLOWED." */
line_1940:;
    printf("%s", "STRATEGY"); printf("%g ", (double)(Y)); printf("%s", "NOT ALLOWED."); printf("\n");
    /* BASIC: 1950 GOTO 1910 */
line_1950:;
    goto line_1910;
    /* BASIC: 1960 IF B$="YES" THEN 2000 */
line_1960:;
    if (strcmp(B_str, "YES") == 0) { goto line_2000; }
    /* BASIC: 1970 IF Y=5 THEN 2830 */
line_1970:;
    if (Y==5) { goto line_2830; }
    /* BASIC: 1980 GOSUB 3110 */
line_1980:;
    gosub_stack[gosub_sp++] = 1; goto line_3110; line_ret_1:;
    /* BASIC: 1990 GOTO 2170 */
line_1990:;
    goto line_2170;
    /* BASIC: 2000 IF I=2 THEN 2040 */
line_2000:;
    if (I==2) { goto line_2040; }
    /* BASIC: 2010 LET Y1=Y */
line_2010:;
    /* UNTRANSLATED: LET Y1=Y */
    /* BASIC: 2020 PRINT "UNION STRATEGY "; */
line_2020:;
    printf("%s", "UNION STRATEGY ");
    /* BASIC: 2030 NEXT I */
line_2030:;
    I += (1); goto for_loop_I_1870; end_for_I_1870:;
    /* BASIC: 2040 LET Y2=Y */
line_2040:;
    /* UNTRANSLATED: LET Y2=Y */
    /* BASIC: 2050 LET Y=Y1 */
line_2050:;
    /* UNTRANSLATED: LET Y=Y1 */
    /* BASIC: 2060 IF Y2=5 THEN 2020 */
line_2060:;
    if (Y2==5) { goto line_2020; }
    /* BASIC: 2070 REM : SIMULATED LOSSES-N OR TH */
line_2070:;
    /* REM */
    /* UNTRANSLATED: SIMULATED LOSSES-N OR TH */
    /* BASIC: 2080 LET C6=(2*C2/5)*(1+1/(2*(ABS(Y2-Y)+1))) */
line_2080:;
    /* UNTRANSLATED: LET C6=(2*C2/5)*(1+1/(2*(ABS(Y2-Y)+1))) */
    /* BASIC: 2090 LET C6=C6*(1.28+(5*M2/6)/(B(2)+1)) */
line_2090:;
    /* UNTRANSLATED: LET C6=C6*(1.28+(5*M2/6)/(B(2)+1)) */
    /* BASIC: 2100 LET C6=INT(C6*(1+1/O2)+.5) */
line_2100:;
    /* UNTRANSLATED: LET C6=INT(C6*(1+1/O2)+.5) */
    /* BASIC: 2110 REM - IF LOSS > MEN PRESENT, RESCALE LOSSES */
line_2110:;
    /* REM - IF LOSS > MEN PRESENT, RESCALE LOSSES */
    /* BASIC: 2120 LET E2=100/O2 */
line_2120:;
    /* UNTRANSLATED: LET E2=100/O2 */
    /* BASIC: 2130 IF INT(C6+E2)<M6 THEN 2190 */
line_2130:;
    if (floor(C6+E2)<M6) { goto line_2190; }
    /* BASIC: 2140 LET C6=INT(13*M6/20) */
line_2140:;
    /* UNTRANSLATED: LET C6=INT(13*M6/20) */
    /* BASIC: 2150 LET E2=7*C6/13 */
line_2150:;
    /* UNTRANSLATED: LET E2=7*C6/13 */
    /* BASIC: 2160 LET U2=1 */
line_2160:;
    /* UNTRANSLATED: LET U2=1 */
    /* BASIC: 2170 REM - CALCULATE SIMULATED LOSSES */
line_2170:;
    /* REM - CALCULATE SIMULATED LOSSES */
    /* BASIC: 2180 PRINT */
line_2180:;
    printf("\n");
    /* BASIC: 2190 PRINT : PRINT : PRINT ,"CONFEDERACY","UNION" */
line_2190:;
    printf("\n");
    printf("\n");
    printf("\t"); printf("%s", "CONFEDERACY"); printf("\t"); printf("%s", "UNION"); printf("\n");
    /* BASIC: 2200 LET C5=(2*C1/5)*(1+1/(2*(ABS(Y2-Y)+1))) */
line_2200:;
    /* UNTRANSLATED: LET C5=(2*C1/5)*(1+1/(2*(ABS(Y2-Y)+1))) */
    /* BASIC: 2210 LET C5=INT(C5*(1+1/O)*(1.28+F1/(B(1)+1))+.5) */
line_2210:;
    /* UNTRANSLATED: LET C5=INT(C5*(1+1/O)*(1.28+F1/(B(1)+1))+.5) */
    /* BASIC: 2220 LET E=100/O */
line_2220:;
    /* UNTRANSLATED: LET E=100/O */
    /* BASIC: 2230 IF C5+100/O<M1*(1+(P1-T1)/(M3+1)) THEN 2270 */
line_2230:;
    if (C5+100/O<M1*(1+(P1-T1)/(M3+1))) { goto line_2270; }
    /* BASIC: 2240 LET C5=INT(13*M1/20*(1+(P1-T1)/(M3+1))) */
line_2240:;
    /* UNTRANSLATED: LET C5=INT(13*M1/20*(1+(P1-T1)/(M3+1))) */
    /* BASIC: 2250 LET E=7*C5/13 */
line_2250:;
    /* UNTRANSLATED: LET E=7*C5/13 */
    /* BASIC: 2260 LET U=1 */
line_2260:;
    /* UNTRANSLATED: LET U=1 */
    /* BASIC: 2270 IF D=1 THEN 2500 */
line_2270:;
    if (D==1) { goto line_2500; }
    /* BASIC: 2280 PRINT "CASUALTIES",C5,C6 */
line_2280:;
    printf("%s", "CASUALTIES"); printf("\t"); printf("%g ", (double)(C5)); printf("\t"); printf("%g ", (double)(C6)); printf("\n");
    /* BASIC: 2290 PRINT "DESERTIONS",INT(E),INT(E2) */
line_2290:;
    printf("%s", "DESERTIONS"); printf("\t"); printf("%g ", (double)(floor(E))); printf("\t"); printf("%g ", (double)(floor(E2))); printf("\n");
    /* BASIC: 2300 PRINT */
line_2300:;
    printf("\n");
    /* BASIC: 2310 IF B$ <> "YES" THEN 2350 */
line_2310:;
    if (strcmp(B_str, "YES") != 0) { goto line_2350; }
    /* BASIC: 2320 PRINT "COMPARED TO THE ACTUAL CASUALTIES AT "C$ */
line_2320:;
    printf("%s", "COMPARED TO THE ACTUAL CASUALTIES AT "); printf("%s", C_str); printf("\n");
    /* BASIC: 2330 PRINT "CONFEDERATE:"INT(100*(C5/C1)+.5)"% OF THE ORIGINAL" */
line_2330:;
    printf("%s", "CONFEDERATE:"); printf("%g ", (double)(floor(100*(C5/C1)+.5))); printf("%s", "% OF THE ORIGINAL"); printf("\n");
    /* BASIC: 2340 PRINT "UNION:      "INT(100*(C6/C2)+.5)"% OF THE ORIGINAL" */
line_2340:;
    printf("%s", "UNION:      "); printf("%g ", (double)(floor(100*(C6/C2)+.5))); printf("%s", "% OF THE ORIGINAL"); printf("\n");
    /* BASIC: 2350 PRINT */
line_2350:;
    printf("\n");
    /* BASIC: 2360 REM - 1 WHO ONE */
line_2360:;
    /* REM - 1 WHO ONE */
    /* BASIC: 2370 IF U <> 1 THEN 2380 */
line_2370:;
    if (U != 1) { goto line_2380; }
    /* BASIC: 2375 IF U2=1 THEN 2460 */
line_2375:;
    if (U2==1) { goto line_2460; }
    /* BASIC: 2380 IF U=1 THEN 2420 */
line_2380:;
    if (U==1) { goto line_2420; }
    /* BASIC: 2390 IF U2=1 THEN 2440 */
line_2390:;
    if (U2==1) { goto line_2440; }
    /* BASIC: 2400 IF C5+E=C6+E2 THEN 2460 */
line_2400:;
    if (C5+E==C6+E2) { goto line_2460; }
    /* BASIC: 2410 IF C5+E<C6+E2 THEN 2440 */
line_2410:;
    if (C5+E<C6+E2) { goto line_2440; }
    /* BASIC: 2420 PRINT "THE UNION WINS "C$ */
line_2420:;
    printf("%s", "THE UNION WINS "); printf("%s", C_str); printf("\n");
    /* BASIC: 2430 GOTO 2600 */
line_2430:;
    goto line_2600;
    /* BASIC: 2440 PRINT "THE CONFEDERACY WINS "C$ */
line_2440:;
    printf("%s", "THE CONFEDERACY WINS "); printf("%s", C_str); printf("\n");
    /* BASIC: 2450 GOTO 2660 */
line_2450:;
    goto line_2660;
    /* BASIC: 2460 PRINT "BATTLE OUTCOME UNRESOLVED" */
line_2460:;
    printf("%s", "BATTLE OUTCOME UNRESOLVED"); printf("\n");
    /* BASIC: 2470 LET W0=W0+1 */
line_2470:;
    /* UNTRANSLATED: LET W0=W0+1 */
    /* BASIC: 2480 IF A=0 THEN 2790 */
line_2480:;
    if (A==0) { goto line_2790; }
    /* BASIC: 2490 GOTO 2680 */
line_2490:;
    goto line_2680;
    /* BASIC: 2500 LET C6=INT(17*C2*C1/(C5*20)) */
line_2500:;
    /* UNTRANSLATED: LET C6=INT(17*C2*C1/(C5*20)) */
    /* BASIC: 2510 LET E2=5*O */
line_2510:;
    /* UNTRANSLATED: LET E2=5*O */
    /* BASIC: 2520 GOTO 2280 */
line_2520:;
    goto line_2280;
    /* BASIC: 2530 PRINT "YOUR CASUALTIES WERE "INT(100*(C5/C1)+.5)"% OF " */
line_2530:;
    printf("%s", "YOUR CASUALTIES WERE "); printf("%g ", (double)(floor(100*(C5/C1)+.5))); printf("%s", "% OF "); printf("\n");
    /* BASIC: 2540 PRINT "THE ACTUAL CASUALTIES AT ";C$ */
line_2540:;
    printf("%s", "THE ACTUAL CASUALTIES AT "); printf("%s", C_str); printf("\n");
    /* BASIC: 2550 PRINT */
line_2550:;
    printf("\n");
    /* BASIC: 2560 REM - FIND WHO WON */
line_2560:;
    /* REM - FIND WHO WON */
    /* BASIC: 2570 IF U=1 THEN 2590 */
line_2570:;
    if (U==1) { goto line_2590; }
    /* BASIC: 2580 IF C5+E<17*C2*C1/(C5*20)+5*O THEN 2630 */
line_2580:;
    if (C5+E<17*C2*C1/(C5*20)+5*O) { goto line_2630; }
    /* BASIC: 2590 PRINT "YOU LOSE ";C$ */
line_2590:;
    printf("%s", "YOU LOSE "); printf("%s", C_str); printf("\n");
    /* BASIC: 2600 IF A=0 THEN 2790 */
line_2600:;
    if (A==0) { goto line_2790; }
    /* BASIC: 2610 LET L=L+1 */
line_2610:;
    /* UNTRANSLATED: LET L=L+1 */
    /* BASIC: 2620 GOTO 2680 */
line_2620:;
    goto line_2680;
    /* BASIC: 2630 PRINT "YOU WIN ";C$ */
line_2630:;
    printf("%s", "YOU WIN "); printf("%s", C_str); printf("\n");
    /* BASIC: 2640 REM - CUMULATIVE BATTLE FACT OR S WHICH ALTER HIST OR ICAL */
line_2640:;
    /* REM - CUMULATIVE BATTLE FACT OR S WHICH ALTER HIST OR ICAL */
    /* BASIC: 2650 REM  RESOURCES AVAILABLE.IF A REPLAY DON'T UPDATE. */
line_2650:;
    /* REM  RESOURCES AVAILABLE.IF A REPLAY DON'T UPDATE. */
    /* BASIC: 2660 IF A=0 THEN 2790 */
line_2660:;
    if (A==0) { goto line_2790; }
    /* BASIC: 2670 LET W=W+1 */
line_2670:;
    /* UNTRANSLATED: LET W=W+1 */
    /* BASIC: 2680 LET T1=T1+C5+E */
line_2680:;
    /* UNTRANSLATED: LET T1=T1+C5+E */
    /* BASIC: 2690 LET T2=T2+C6+E2 */
line_2690:;
    /* UNTRANSLATED: LET T2=T2+C6+E2 */
    /* BASIC: 2700 LET P1=P1+C1 */
line_2700:;
    /* UNTRANSLATED: LET P1=P1+C1 */
    /* BASIC: 2710 LET P2=P2+C2 */
line_2710:;
    /* UNTRANSLATED: LET P2=P2+C2 */
    /* BASIC: 2720 LET Q1=Q1+(F(1)+H(1)+B(1)) */
line_2720:;
    /* UNTRANSLATED: LET Q1=Q1+(F(1)+H(1)+B(1)) */
    /* BASIC: 2730 LET Q2=Q2+(F(2)+H(2)+B(2)) */
line_2730:;
    /* UNTRANSLATED: LET Q2=Q2+(F(2)+H(2)+B(2)) */
    /* BASIC: 2740 LET R1=R1+M1*(100-I1)/20 */
line_2740:;
    /* UNTRANSLATED: LET R1=R1+M1*(100-I1)/20 */
    /* BASIC: 2750 LET R2=R2+M2*(100-I2)/20 */
line_2750:;
    /* UNTRANSLATED: LET R2=R2+M2*(100-I2)/20 */
    /* BASIC: 2760 LET M3=M3+M1 */
line_2760:;
    /* UNTRANSLATED: LET M3=M3+M1 */
    /* BASIC: 2770 LET M4=M4+M2 */
line_2770:;
    /* UNTRANSLATED: LET M4=M4+M2 */
    /* BASIC: 2780 GOSUB 3300 */
line_2780:;
    gosub_stack[gosub_sp++] = 2; goto line_3300; line_ret_2:;
    /* BASIC: 2790 U=0:U2=0 */
line_2790:;
    U = 0;
    U2 = 0;
    /* BASIC: 2800 PRINT "---------------" */
line_2800:;
    printf("%s", "---------------"); printf("\n");
    /* BASIC: 2810 GOTO 620 */
line_2810:;
    goto line_620;
    /* BASIC: 2820 REM------FINISH OFF */
line_2820:;
    /* REM------FINISH OFF */
    /* BASIC: 2830 PRINT "THE CONFEDERACY HAS SURRENDERED" */
line_2830:;
    printf("%s", "THE CONFEDERACY HAS SURRENDERED"); printf("\n");
    /* BASIC: 2840 GOTO 2860 */
line_2840:;
    goto line_2860;
    /* BASIC: 2850 PRINT "THE UNION HAS SURRENDERED." */
line_2850:;
    printf("%s", "THE UNION HAS SURRENDERED."); printf("\n");
    /* BASIC: 2860 PRINT : PRINT : PRINT : PRINT : PRINT : PRINT */
line_2860:;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 2870 PRINT "THE CONFEDERACY "; */
line_2870:;
    printf("%s", "THE CONFEDERACY ");
    /* BASIC: 2880 PRINT "HAS WON "W" BATTLES AND LOST "L */
line_2880:;
    printf("%s", "HAS WON "); printf("%g ", (double)(W)); printf("%s", " BATTLES AND LOST "); printf("%g ", (double)(L)); printf("\n");
    /* BASIC: 2890 IF Y=5 THEN 2940 */
line_2890:;
    if (Y==5) { goto line_2940; }
    /* BASIC: 2900 IF Y2=5 THEN 2920 */
line_2900:;
    if (Y2==5) { goto line_2920; }
    /* BASIC: 2910 IF W <= L THEN 2940 */
line_2910:;
    if (W <= L) { goto line_2940; }
    /* BASIC: 2915 IF Y=5 THEN 2940 */
line_2915:;
    if (Y==5) { goto line_2940; }
    /* BASIC: 2920 PRINT "THE CONFEDERACY HAS WON THE WAR" */
line_2920:;
    printf("%s", "THE CONFEDERACY HAS WON THE WAR"); printf("\n");
    /* BASIC: 2930 GOTO 2950 */
line_2930:;
    goto line_2950;
    /* BASIC: 2940 PRINT "THE UNION HAS WON THE WAR" */
line_2940:;
    printf("%s", "THE UNION HAS WON THE WAR"); printf("\n");
    /* BASIC: 2950 PRINT */
line_2950:;
    printf("\n");
    /* BASIC: 2960 IF R1=0 THEN 3100 */
line_2960:;
    if (R1==0) { goto line_3100; }
    /* BASIC: 2970 PRINT "FOR THE "W+L+W0" BATTLES FOUGHT (EXCUDING RERUNS)" */
line_2970:;
    printf("%s", "FOR THE "); printf("%g ", (double)(W+L+W0)); printf("%s", " BATTLES FOUGHT (EXCUDING RERUNS)"); printf("\n");
    /* BASIC: 2980 PRINT " "," "," "; */
line_2980:;
    printf("%s", " "); printf("\t"); printf("%s", " "); printf("\t"); printf("%s", " ");
    /* BASIC: 2990 PRINT "CONFEDERACY"," UNION" */
line_2990:;
    printf("%s", "CONFEDERACY"); printf("\t"); printf("%s", " UNION"); printf("\n");
    /* BASIC: 3000 PRINT "HISTORICAL LOSSES",INT(P1+.5),INT(P2+.5) */
line_3000:;
    printf("%s", "HISTORICAL LOSSES"); printf("\t"); printf("%g ", (double)(floor(P1+.5))); printf("\t"); printf("%g ", (double)(floor(P2+.5))); printf("\n");
    /* BASIC: 3010 PRINT "SIMULATED LOSSES",INT(T1+.5),INT(T2+.5) */
line_3010:;
    printf("%s", "SIMULATED LOSSES"); printf("\t"); printf("%g ", (double)(floor(T1+.5))); printf("\t"); printf("%g ", (double)(floor(T2+.5))); printf("\n");
    /* BASIC: 3020 PRINT */
line_3020:;
    printf("\n");
    /* BASIC: 3030 PRINT "    % OF ORIGINAL",INT(100*(T1/P1)+.5),INT(100*(T2/P2)+.5) */
line_3030:;
    printf("%s", "    % OF ORIGINAL"); printf("\t"); printf("%g ", (double)(floor(100*(T1/P1)+.5))); printf("\t"); printf("%g ", (double)(floor(100*(T2/P2)+.5))); printf("\n");
    /* BASIC: 3040 IF B$="YES" THEN 3100 */
line_3040:;
    if (strcmp(B_str, "YES") == 0) { goto line_3100; }
    /* BASIC: 3050 PRINT */
line_3050:;
    printf("\n");
    /* BASIC: 3060 PRINT "UNION INTELLIGENCE SUGGESTS THAT THE SOUTH USED " */
line_3060:;
    printf("%s", "UNION INTELLIGENCE SUGGESTS THAT THE SOUTH USED "); printf("\n");
    /* BASIC: 3070 PRINT "STRATEGIES 1, 2, 3, 4 IN THE FOLLOWING PERCENTAGES" */
line_3070:;
    printf("%s", "STRATEGIES 1, 2, 3, 4 IN THE FOLLOWING PERCENTAGES"); printf("\n");
    /* BASIC: 3080 PRINT S(1);S2(2);S(3);S(4) */
line_3080:;
    printf("%g ", (double)(S_arr[(int)(1)])); printf("%g ", (double)(S2_arr[(int)(2)])); printf("%g ", (double)(S_arr[(int)(3)])); printf("%g ", (double)(S_arr[(int)(4)])); printf("\n");
    /* BASIC: 3090 REM--------------------------------- */
line_3090:;
    /* REM--------------------------------- */
    /* BASIC: 3100 S TO P */
line_3100:;
    /* UNTRANSLATED: S TO P */
    /* BASIC: 3110 REM - UNION STRATEGY IS COMPUTER CHOSEN */
line_3110:;
    /* REM - UNION STRATEGY IS COMPUTER CHOSEN */
    /* BASIC: 3120 PRINT "UNION STRATEGY IS "; */
line_3120:;
    printf("%s", "UNION STRATEGY IS ");
    /* BASIC: 3130 IF A <> 0 THEN 3180 */
line_3130:;
    if (A != 0) { goto line_3180; }
    /* BASIC: 3140 INPUT Y2 */
line_3140:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &Y2);
    /* BASIC: 3150 IF Y2 <=0 THEN 3160 */
line_3150:;
    if (Y2 <=0) { goto line_3160; }
    /* BASIC: 3155 IF Y2<5 THEN 3290 */
line_3155:;
    if (Y2<5) { goto line_3290; }
    /* BASIC: 3160 PRINT "ENTER 1 , 2 ,3 , OR 4 (USUALLY PREVIOUS UNION STRATEGY)" */
line_3160:;
    printf("%s", "ENTER 1 , 2 ,3 , OR 4 (USUALLY PREVIOUS UNION STRATEGY)"); printf("\n");
    /* BASIC: 3170 GOTO 3140 */
line_3170:;
    goto line_3140;
    /* BASIC: 3180 LET S0=0 */
line_3180:;
    /* UNTRANSLATED: LET S0=0 */
    /* BASIC: 3190 LET R=100*RND(0) */
line_3190:;
    /* UNTRANSLATED: LET R=100*RND(0) */
    /* BASIC: 3200 FOR I=1 TO 4 */
line_3200:;
    I = 1; for_loop_I_3200: if (((1) >= 0 && I > (4)) || ((1) < 0 && I < (4))) goto end_for_I_3200;
    /* BASIC: 3210 LET S0=S0+S(I) */
line_3210:;
    /* UNTRANSLATED: LET S0=S0+S(I) */
    /* BASIC: 3220 REM - IF ACTUAL STRATEGY INFO IS IN PROGRAM DATA STATEMENTS */
line_3220:;
    /* REM - IF ACTUAL STRATEGY INFO IS IN PROGRAM DATA STATEMENTS */
    /* BASIC: 3230 REM   THEN R-100 IS EXTRA WEIGHT GIVEN TO THAT STATEGY. */
line_3230:;
    /* REM   THEN R-100 IS EXTRA WEIGHT GIVEN TO THAT STATEGY. */
    /* BASIC: 3240 IF R<S0 THEN 3270 */
line_3240:;
    if (R<S0) { goto line_3270; }
    /* BASIC: 3250 NEXT I */
line_3250:;
    I += (1); goto for_loop_I_3200; end_for_I_3200:;
    /* BASIC: 3260 REM - IF ACTUAL STRAT. IN, THEN HERE IS Y2= HIST. STRAT. */
line_3260:;
    /* REM - IF ACTUAL STRAT. IN, THEN HERE IS Y2= HIST. STRAT. */
    /* BASIC: 3270 LET Y2=I */
line_3270:;
    /* UNTRANSLATED: LET Y2=I */
    /* BASIC: 3280 PRINT Y2 */
line_3280:;
    printf("%g ", (double)(Y2)); printf("\n");
    /* BASIC: 3290 RETURN */
line_3290:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 3300 REM LEARN  PRESENT STRATEGY, START FOR GETTING OLD ONES */
line_3300:;
    /* REM LEARN  PRESENT STRATEGY, START FOR GETTING OLD ONES */
    /* BASIC: 3310 REM - PRESENT STRATEGY OF SOUTH GAINS 3*S, OTHERS LOSE S */
line_3310:;
    /* REM - PRESENT STRATEGY OF SOUTH GAINS 3*S, OTHERS LOSE S */
    /* BASIC: 3320 REM   PROBABILITY POINTS, UNLESS A STRATEGY FALLS BELOW 5%. */
line_3320:;
    /* REM   PROBABILITY POINTS, UNLESS A STRATEGY FALLS BELOW 5%. */
    /* BASIC: 3330 LET S=3 */
line_3330:;
    /* UNTRANSLATED: LET S=3 */
    /* BASIC: 3340 LET S0=0 */
line_3340:;
    /* UNTRANSLATED: LET S0=0 */
    /* BASIC: 3350 FOR I=1 TO 4 */
line_3350:;
    I = 1; for_loop_I_3350: if (((1) >= 0 && I > (4)) || ((1) < 0 && I < (4))) goto end_for_I_3350;
    /* BASIC: 3360 IF S(I) <= 5 THEN 3390 */
line_3360:;
    if (S_arr[(int)(I)] <= 5) { goto line_3390; }
    /* BASIC: 3370 LET S(I)=S(I)-S */
line_3370:;
    /* UNTRANSLATED: LET S(I)=S(I)-S */
    /* BASIC: 3380 LET S0=S0+S */
line_3380:;
    /* UNTRANSLATED: LET S0=S0+S */
    /* BASIC: 3390 NEXT I */
line_3390:;
    I += (1); goto for_loop_I_3350; end_for_I_3350:;
    /* BASIC: 3400 LET S(Y)=S(Y)+S0 */
line_3400:;
    /* UNTRANSLATED: LET S(Y)=S(Y)+S0 */
    /* BASIC: 3410 RETURN */
line_3410:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 3420 REM - HIST OR ICAL DATA...CAN ADD M OR E (STRAT.,ETC) BY INSERTING */
line_3420:;
    /* REM - HIST OR ICAL DATA...CAN ADD M OR E (STRAT.,ETC) BY INSERTING */
    /* BASIC: 3430 REM   DATA STATEMENTS AFTER APPRO. INFO, AND ADJUSTING READ */
line_3430:;
    /* REM   DATA STATEMENTS AFTER APPRO. INFO, AND ADJUSTING READ */
    /* BASIC: 3440 DATA "BULL RUN",18000,18500,1967,2708,1 */
line_3440:;
    /* UNTRANSLATED: DATA "BULL RUN",18000,18500,1967,2708,1 */
    /* BASIC: 3450 DATA "SHILOH",40000.,44894.,10699,13047,3 */
line_3450:;
    /* UNTRANSLATED: DATA "SHILOH",40000.,44894.,10699,13047,3 */
    /* BASIC: 3460 DATA "SEVEN DAYS",95000.,115000.,20614,15849,3 */
line_3460:;
    /* UNTRANSLATED: DATA "SEVEN DAYS",95000.,115000.,20614,15849,3 */
    /* BASIC: 3470 DATA "SECOND BULL RUN",54000.,63000.,10000,14000,2 */
line_3470:;
    /* UNTRANSLATED: DATA "SECOND BULL RUN",54000.,63000.,10000,14000,2 */
    /* BASIC: 3480 DATA "ANTIETAM",40000.,50000.,10000,12000,3 */
line_3480:;
    /* UNTRANSLATED: DATA "ANTIETAM",40000.,50000.,10000,12000,3 */
    /* BASIC: 3490 DATA "FREDERICKSBURG",75000.,120000.,5377,12653,1 */
line_3490:;
    /* UNTRANSLATED: DATA "FREDERICKSBURG",75000.,120000.,5377,12653,1 */
    /* BASIC: 3500 DATA "MURFREESBORO",38000.,45000.,11000,12000,1 */
line_3500:;
    /* UNTRANSLATED: DATA "MURFREESBORO",38000.,45000.,11000,12000,1 */
    /* BASIC: 3510 DATA "CHANCELLORSVILLE",32000,90000.,13000,17197,2 */
line_3510:;
    /* UNTRANSLATED: DATA "CHANCELLORSVILLE",32000,90000.,13000,17197,2 */
    /* BASIC: 3520 DATA "VICKSBURG",50000.,70000.,12000,19000,1 */
line_3520:;
    /* UNTRANSLATED: DATA "VICKSBURG",50000.,70000.,12000,19000,1 */
    /* BASIC: 3530 DATA "GETTYSBURG",72500.,85000.,20000,23000,3 */
line_3530:;
    /* UNTRANSLATED: DATA "GETTYSBURG",72500.,85000.,20000,23000,3 */
    /* BASIC: 3540 DATA "CHICKAMAUGA",66000.,60000.,18000,16000,2 */
line_3540:;
    /* UNTRANSLATED: DATA "CHICKAMAUGA",66000.,60000.,18000,16000,2 */
    /* BASIC: 3550 DATA "CHATTANOOGA",37000.,60000.,36700.,5800,2 */
line_3550:;
    /* UNTRANSLATED: DATA "CHATTANOOGA",37000.,60000.,36700.,5800,2 */
    /* BASIC: 3560 DATA "SPOTSYLVANIA",62000.,110000.,17723,18000,2 */
line_3560:;
    /* UNTRANSLATED: DATA "SPOTSYLVANIA",62000.,110000.,17723,18000,2 */
    /* BASIC: 3570 DATA "ATLANTA",65000.,100000.,8500,3700,1 */
line_3570:;
    /* UNTRANSLATED: DATA "ATLANTA",65000.,100000.,8500,3700,1 */
    /* BASIC: 3580 PRINT "JULY 21, 1861.  GEN. BEAUREGARD, COMMANDING THE SOUTH, MET" */
line_3580:;
    printf("%s", "JULY 21, 1861.  GEN. BEAUREGARD, COMMANDING THE SOUTH, MET"); printf("\n");
    /* BASIC: 3590 PRINT "UNION FORCES WITH GEN. MCDOWELL IN A PREMATURE BATTLE AT" */
line_3590:;
    printf("%s", "UNION FORCES WITH GEN. MCDOWELL IN A PREMATURE BATTLE AT"); printf("\n");
    /* BASIC: 3600 PRINT "BULL RUN. GEN. JACKSON HELPED PUSH BACK THE UNION ATTACK." */
line_3600:;
    printf("%s", "BULL RUN. GEN. JACKSON HELPED PUSH BACK THE UNION ATTACK."); printf("\n");
    /* BASIC: 3610 GOTO 1150 */
line_3610:;
    goto line_1150;
    /* BASIC: 3620 PRINT "APRIL 6-7, 1862.  THE CONFEDERATE SURPRISE ATTACK AT" */
line_3620:;
    printf("%s", "APRIL 6-7, 1862.  THE CONFEDERATE SURPRISE ATTACK AT"); printf("\n");
    /* BASIC: 3630 PRINT "SHILOH FAILED DUE TO POOR ORGANIZATION." */
line_3630:;
    printf("%s", "SHILOH FAILED DUE TO POOR ORGANIZATION."); printf("\n");
    /* BASIC: 3640 GOTO 1150 */
line_3640:;
    goto line_1150;
    /* BASIC: 3650 PRINT "JUNE 25-JULY 1, 1862.  GENERAL LEE (CSA) UPHELD THE" */
line_3650:;
    printf("%s", "JUNE 25-JULY 1, 1862.  GENERAL LEE (CSA) UPHELD THE"); printf("\n");
    /* BASIC: 3660 PRINT "OFFENSIVE THROUGHOUT THE BATTLE AND FORCED GEN. MCCLELLAN" */
line_3660:;
    printf("%s", "OFFENSIVE THROUGHOUT THE BATTLE AND FORCED GEN. MCCLELLAN"); printf("\n");
    /* BASIC: 3670 PRINT "AND THE UNION FORCES AWAY FROM RICHMOND." */
line_3670:;
    printf("%s", "AND THE UNION FORCES AWAY FROM RICHMOND."); printf("\n");
    /* BASIC: 3680 GOTO 1150 */
line_3680:;
    goto line_1150;
    /* BASIC: 3690 PRINT "AUG 29-30, 1862.  THE COMBINED CONFEDERATE FORCES UNDER"; */
line_3690:;
    printf("%s", "AUG 29-30, 1862.  THE COMBINED CONFEDERATE FORCES UNDER");
    /* BASIC: 3695 PRINT " LEE" */
line_3695:;
    printf("%s", " LEE"); printf("\n");
    /* BASIC: 3700 PRINT "AND JACKSON DROVE THE UNION FORCES BACK INTO WASHINGTON." */
line_3700:;
    printf("%s", "AND JACKSON DROVE THE UNION FORCES BACK INTO WASHINGTON."); printf("\n");
    /* BASIC: 3710 GOTO 1150 */
line_3710:;
    goto line_1150;
    /* BASIC: 3720 PRINT "SEPT 17, 1862.  THE SOUTH FAILED TO INCORPORATE MARYLAND" */
line_3720:;
    printf("%s", "SEPT 17, 1862.  THE SOUTH FAILED TO INCORPORATE MARYLAND"); printf("\n");
    /* BASIC: 3730 PRINT "INTO THE CONFEDERACY." */
line_3730:;
    printf("%s", "INTO THE CONFEDERACY."); printf("\n");
    /* BASIC: 3740 GOTO 1150 */
line_3740:;
    goto line_1150;
    /* BASIC: 3750 PRINT "DEC 13, 1862.  THE CONFEDERACY UNDER LEE SUCCESSFULLY" */
line_3750:;
    printf("%s", "DEC 13, 1862.  THE CONFEDERACY UNDER LEE SUCCESSFULLY"); printf("\n");
    /* BASIC: 3760 PRINT "REPULSED AN ATTACK BY THE UNION UNDER GEN. BURNSIDE." */
line_3760:;
    printf("%s", "REPULSED AN ATTACK BY THE UNION UNDER GEN. BURNSIDE."); printf("\n");
    /* BASIC: 3770 GOTO 1150 */
line_3770:;
    goto line_1150;
    /* BASIC: 3780 PRINT "DEC 31, 1862.  THE SOUTH UNDER GEN. BRAGG WON A CLOSE "; */
line_3780:;
    printf("%s", "DEC 31, 1862.  THE SOUTH UNDER GEN. BRAGG WON A CLOSE ");
    /* BASIC: 3785 PRINT "BATTLE." */
line_3785:;
    printf("%s", "BATTLE."); printf("\n");
    /* BASIC: 3790 GOTO 1150 */
line_3790:;
    goto line_1150;
    /* BASIC: 3800 PRINT "MAY 1-6, 1863.  THE SOUTH HAD A COSTLY VICTORY AND LOST" */
line_3800:;
    printf("%s", "MAY 1-6, 1863.  THE SOUTH HAD A COSTLY VICTORY AND LOST"); printf("\n");
    /* BASIC: 3810 PRINT "ONE OF THEIR OUTSTANDING GENERALS, 'STONEWALL' JACKSON." */
line_3810:;
    printf("%s", "ONE OF THEIR OUTSTANDING GENERALS, 'STONEWALL' JACKSON."); printf("\n");
    /* BASIC: 3820 GOTO 1150 */
line_3820:;
    goto line_1150;
    /* BASIC: 3830 PRINT "JULY 4, 1863.  VICKSBURG WAS A COSTLY DEFEAT FOR THE SOUTH" */
line_3830:;
    printf("%s", "JULY 4, 1863.  VICKSBURG WAS A COSTLY DEFEAT FOR THE SOUTH"); printf("\n");
    /* BASIC: 3840 PRINT "BECAUSE IT GAVE THE UNION ACCESS TO THE MISSISSIPPI." */
line_3840:;
    printf("%s", "BECAUSE IT GAVE THE UNION ACCESS TO THE MISSISSIPPI."); printf("\n");
    /* BASIC: 3850 GOTO 1150 */
line_3850:;
    goto line_1150;
    /* BASIC: 3860 PRINT "JULY 1-3, 1863.  A SOUTHERN MISTAKE BY GEN. LEE AT "; */
line_3860:;
    printf("%s", "JULY 1-3, 1863.  A SOUTHERN MISTAKE BY GEN. LEE AT ");
    /* BASIC: 3865 PRINT "GETTYSBURG" */
line_3865:;
    printf("%s", "GETTYSBURG"); printf("\n");
    /* BASIC: 3870 PRINT "COST THEM ONE OF THE MOST CRUCIAL BATTLES OF THE WAR." */
line_3870:;
    printf("%s", "COST THEM ONE OF THE MOST CRUCIAL BATTLES OF THE WAR."); printf("\n");
    /* BASIC: 3880 GOTO 1150 */
line_3880:;
    goto line_1150;
    /* BASIC: 3890 PRINT "SEPT. 15, 1863. CONFUSION IN A FOREST NEAR CHICKAMAUGA LED" */
line_3890:;
    printf("%s", "SEPT. 15, 1863. CONFUSION IN A FOREST NEAR CHICKAMAUGA LED"); printf("\n");
    /* BASIC: 3900 PRINT "TO A COSTLY SOUTHERN VICTORY." */
line_3900:;
    printf("%s", "TO A COSTLY SOUTHERN VICTORY."); printf("\n");
    /* BASIC: 3910 GOTO 1150 */
line_3910:;
    goto line_1150;
    /* BASIC: 3920 PRINT "NOV. 25, 1863. AFTER THE SOUTH HAD SIEGED GEN. ROSENCRANS'" */
line_3920:;
    printf("%s", "NOV. 25, 1863. AFTER THE SOUTH HAD SIEGED GEN. ROSENCRANS'"); printf("\n");
    /* BASIC: 3930 PRINT "ARMY FOR THREE MONTHS, GEN. GRANT BROKE THE SIEGE." */
line_3930:;
    printf("%s", "ARMY FOR THREE MONTHS, GEN. GRANT BROKE THE SIEGE."); printf("\n");
    /* BASIC: 3940 GOTO 1150 */
line_3940:;
    goto line_1150;
    /* BASIC: 3950 PRINT "MAY 5, 1864.  GRANT'S PLAN TO KEEP LEE ISOLATED BEGAN TO" */
line_3950:;
    printf("%s", "MAY 5, 1864.  GRANT'S PLAN TO KEEP LEE ISOLATED BEGAN TO"); printf("\n");
    /* BASIC: 3960 PRINT "FAIL HERE, AND CONTINUED AT COLD HARBOR AND PETERSBURG." */
line_3960:;
    printf("%s", "FAIL HERE, AND CONTINUED AT COLD HARBOR AND PETERSBURG."); printf("\n");
    /* BASIC: 3970 GOTO 1150 */
line_3970:;
    goto line_1150;
    /* BASIC: 3980 PRINT "AUGUST, 1864.  SHERMAN AND THREE VETERAN ARMIES CONVERGED" */
line_3980:;
    printf("%s", "AUGUST, 1864.  SHERMAN AND THREE VETERAN ARMIES CONVERGED"); printf("\n");
    /* BASIC: 3990 PRINT "ON ATLANTA AND DEALT THE DEATH BLOW TO THE CONFEDERACY." */
line_3990:;
    printf("%s", "ON ATLANTA AND DEALT THE DEATH BLOW TO THE CONFEDERACY."); printf("\n");
    /* BASIC: 4000 GOTO 1150 */
line_4000:;
    goto line_1150;
    /* BASIC: 4010 END */
line_4010:;
    exit(0);

    return 0;
}
