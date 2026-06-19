/*
 * Transpiled from roulette.bas
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

static DataItem program_data[18] = {
    { DATA_NUM, 1.0, NULL },
    { DATA_NUM, 3.0, NULL },
    { DATA_NUM, 5.0, NULL },
    { DATA_NUM, 7.0, NULL },
    { DATA_NUM, 9.0, NULL },
    { DATA_NUM, 12.0, NULL },
    { DATA_NUM, 14.0, NULL },
    { DATA_NUM, 16.0, NULL },
    { DATA_NUM, 18.0, NULL },
    { DATA_NUM, 19.0, NULL },
    { DATA_NUM, 21.0, NULL },
    { DATA_NUM, 23.0, NULL },
    { DATA_NUM, 25.0, NULL },
    { DATA_NUM, 27.0, NULL },
    { DATA_NUM, 30.0, NULL },
    { DATA_NUM, 32.0, NULL },
    { DATA_NUM, 34.0, NULL },
    { DATA_NUM, 36.0, NULL },
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
static double A, B, C, D, I, I1, ON, P, R, S, T, X, Y, Z;
static char A_str[256] = {0};
static char B_str[256] = {0};
static char D_str[256] = {0};
static char E_str[256] = {0};
static char M_str[256] = {0};
static char Y_str[256] = {0};
static double A_arr[2000] = {0};
static double B_arr[2000] = {0};
static double C_arr[2000] = {0};
static double T_arr[2000] = {0};
static double X_arr[2000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(32);"ROULETTE" */
line_10:;
    { int _t; for(_t=0; _t<32; _t++) printf(" "); } printf("%s", "ROULETTE"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 40 PRINT "ENTER THE CURRENT DATE (AS IN 'JANUARY 23, 1979') -"; */
line_40:;
    printf("%s", "ENTER THE CURRENT DATE (AS IN 'JANUARY 23, 1979') -");
    /* BASIC: 50 INPUT D$,E$ */
line_50:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s %255s", D_str, E_str);
    /* BASIC: 1000 REM-ROULETTE */
line_1000:;
    /* REM-ROULETTE */
    /* BASIC: 1010 REM-DAVID JOSLIN */
line_1010:;
    /* REM-DAVID JOSLIN */
    /* BASIC: 1020 PRINT "WELCOME TO THE ROULETTE TABLE" */
line_1020:;
    printf("%s", "WELCOME TO THE ROULETTE TABLE"); printf("\n");
    /* BASIC: 1030 PRINT */
line_1030:;
    printf("\n");
    /* BASIC: 1040 PRINT "DO YOU WANT INSTRUCTIONS"; */
line_1040:;
    printf("%s", "DO YOU WANT INSTRUCTIONS");
    /* BASIC: 1050 INPUT Y$ */
line_1050:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", Y_str);
    /* BASIC: 1060 IF LEFT$(Y$,1)="N" THEN 1550 */
line_1060:;
    if (strcmp(basic_LEFT(Y_str,1), "N") == 0) { goto line_1550; }
    /* BASIC: 1070 PRINT */
line_1070:;
    printf("\n");
    /* BASIC: 1080 PRINT "THIS IS THE BETTING LAYOUT" */
line_1080:;
    printf("%s", "THIS IS THE BETTING LAYOUT"); printf("\n");
    /* BASIC: 1090 PRINT "  (*=RED)" */
line_1090:;
    printf("%s", "  (*=RED)"); printf("\n");
    /* BASIC: 1100 PRINT */
line_1100:;
    printf("\n");
    /* BASIC: 1110 PRINT " 1*    2     3*" */
line_1110:;
    printf("%s", " 1*    2     3*"); printf("\n");
    /* BASIC: 1120 PRINT " 4     5*    6 " */
line_1120:;
    printf("%s", " 4     5*    6 "); printf("\n");
    /* BASIC: 1130 PRINT " 7*    8     9*" */
line_1130:;
    printf("%s", " 7*    8     9*"); printf("\n");
    /* BASIC: 1140 PRINT "10    11    12*" */
line_1140:;
    printf("%s", "10    11    12*"); printf("\n");
    /* BASIC: 1150 PRINT "---------------" */
line_1150:;
    printf("%s", "---------------"); printf("\n");
    /* BASIC: 1160 PRINT "13    14*   15 " */
line_1160:;
    printf("%s", "13    14*   15 "); printf("\n");
    /* BASIC: 1170 PRINT "16*   17    18*" */
line_1170:;
    printf("%s", "16*   17    18*"); printf("\n");
    /* BASIC: 1180 PRINT "19*   20    21*" */
line_1180:;
    printf("%s", "19*   20    21*"); printf("\n");
    /* BASIC: 1190 PRINT "22    23*   24 " */
line_1190:;
    printf("%s", "22    23*   24 "); printf("\n");
    /* BASIC: 1200 PRINT "---------------" */
line_1200:;
    printf("%s", "---------------"); printf("\n");
    /* BASIC: 1210 PRINT "25*   26    27*" */
line_1210:;
    printf("%s", "25*   26    27*"); printf("\n");
    /* BASIC: 1220 PRINT "28    29    30*" */
line_1220:;
    printf("%s", "28    29    30*"); printf("\n");
    /* BASIC: 1230 PRINT "31    32*   33 " */
line_1230:;
    printf("%s", "31    32*   33 "); printf("\n");
    /* BASIC: 1240 PRINT "34*   35    36*" */
line_1240:;
    printf("%s", "34*   35    36*"); printf("\n");
    /* BASIC: 1250 PRINT "---------------" */
line_1250:;
    printf("%s", "---------------"); printf("\n");
    /* BASIC: 1260 PRINT "    00    0    " */
line_1260:;
    printf("%s", "    00    0    "); printf("\n");
    /* BASIC: 1270 PRINT */
line_1270:;
    printf("\n");
    /* BASIC: 1280 PRINT "TYPES OF BETS" */
line_1280:;
    printf("%s", "TYPES OF BETS"); printf("\n");
    /* BASIC: 1290 PRINT */
line_1290:;
    printf("\n");
    /* BASIC: 1300 PRINT "THE NUMBERS 1 TO 36 SIGNIFY A STRAIGHT BET" */
line_1300:;
    printf("%s", "THE NUMBERS 1 TO 36 SIGNIFY A STRAIGHT BET"); printf("\n");
    /* BASIC: 1310 PRINT "ON THAT NUMBER." */
line_1310:;
    printf("%s", "ON THAT NUMBER."); printf("\n");
    /* BASIC: 1320 PRINT "THESE PAY OFF 35:1" */
line_1320:;
    printf("%s", "THESE PAY OFF 35:1"); printf("\n");
    /* BASIC: 1330 PRINT */
line_1330:;
    printf("\n");
    /* BASIC: 1340 PRINT "THE 2:1 BETS ARE:" */
line_1340:;
    printf("%s", "THE 2:1 BETS ARE:"); printf("\n");
    /* BASIC: 1350 PRINT " 37) 1-12     40) FIRST COLUMN" */
line_1350:;
    printf("%s", " 37) 1-12     40) FIRST COLUMN"); printf("\n");
    /* BASIC: 1360 PRINT " 38) 13-24    41) SECOND COLUMN" */
line_1360:;
    printf("%s", " 38) 13-24    41) SECOND COLUMN"); printf("\n");
    /* BASIC: 1370 PRINT " 39) 25-36    42) THIRD COLUMN" */
line_1370:;
    printf("%s", " 39) 25-36    42) THIRD COLUMN"); printf("\n");
    /* BASIC: 1380 PRINT */
line_1380:;
    printf("\n");
    /* BASIC: 1390 PRINT "THE EVEN MONEY BETS ARE:" */
line_1390:;
    printf("%s", "THE EVEN MONEY BETS ARE:"); printf("\n");
    /* BASIC: 1400 PRINT " 43) 1-18     46) ODD" */
line_1400:;
    printf("%s", " 43) 1-18     46) ODD"); printf("\n");
    /* BASIC: 1410 PRINT " 44) 19-36    47) RED" */
line_1410:;
    printf("%s", " 44) 19-36    47) RED"); printf("\n");
    /* BASIC: 1420 PRINT " 45) EVEN     48) BLACK" */
line_1420:;
    printf("%s", " 45) EVEN     48) BLACK"); printf("\n");
    /* BASIC: 1430 PRINT */
line_1430:;
    printf("\n");
    /* BASIC: 1440 PRINT " 49)0 AND 50)00 PAY OFF 35:1" */
line_1440:;
    printf("%s", " 49)0 AND 50)00 PAY OFF 35:1"); printf("\n");
    /* BASIC: 1450 PRINT " NOTE: 0 AND 00 DO NOT COUNT UNDER ANY" */
line_1450:;
    printf("%s", " NOTE: 0 AND 00 DO NOT COUNT UNDER ANY"); printf("\n");
    /* BASIC: 1460 PRINT "       BETS EXCEPT THEIR OWN." */
line_1460:;
    printf("%s", "       BETS EXCEPT THEIR OWN."); printf("\n");
    /* BASIC: 1470 PRINT */
line_1470:;
    printf("\n");
    /* BASIC: 1480 PRINT "WHEN I ASK FOR EACH BET, TYPE THE NUMBER" */
line_1480:;
    printf("%s", "WHEN I ASK FOR EACH BET, TYPE THE NUMBER"); printf("\n");
    /* BASIC: 1490 PRINT "AND THE AMOUNT, SEPARATED BY A COMMA." */
line_1490:;
    printf("%s", "AND THE AMOUNT, SEPARATED BY A COMMA."); printf("\n");
    /* BASIC: 1500 PRINT "FOR EXAMPLE: TO BET $500 ON BLACK, TYPE 48,500" */
line_1500:;
    printf("%s", "FOR EXAMPLE: TO BET $500 ON BLACK, TYPE 48,500"); printf("\n");
    /* BASIC: 1510 PRINT "WHEN I ASK FOR A BET." */
line_1510:;
    printf("%s", "WHEN I ASK FOR A BET."); printf("\n");
    /* BASIC: 1520 PRINT */
line_1520:;
    printf("\n");
    /* BASIC: 1530 PRINT "THE MINIMUM BET IS $5, THE MAXIMUM IS $500." */
line_1530:;
    printf("%s", "THE MINIMUM BET IS $5, THE MAXIMUM IS $500."); printf("\n");
    /* BASIC: 1540 PRINT */
line_1540:;
    printf("\n");
    /* BASIC: 1550 REM-PROGRAM BEGINS HERE */
line_1550:;
    /* REM-PROGRAM BEGINS HERE */
    /* BASIC: 1560 REM-TYPE OF BET(NUMBER) ODDS */
line_1560:;
    /* REM-TYPE OF BET(NUMBER) ODDS */
    /* BASIC: 1570 REM  DON'T NEED TO DIM ENSION STRINGS */
line_1570:;
    /* REM  DON'T NEED TO DIM ENSION STRINGS */
    /* BASIC: 1580 DIM B(100),C(100),T(100),X(38) */
line_1580:;
    /* DIM B(100),C(100),T(100),X(38) (handled statically) */
    /* BASIC: 1590 DIM A(50) */
line_1590:;
    /* DIM A(50) (handled statically) */
    /* BASIC: 1600 FOR I=1 TO 38: X(I)=0: NEXT I: REM  MAT X=ZER */
line_1600:;
    I = 1; for_loop_I_1600: if (((1) >= 0 && I > (38)) || ((1) < 0 && I < (38))) goto end_for_I_1600;
    X_arr[(int)(I)] = 0;
    I += (1); goto for_loop_I_1600; end_for_I_1600:;
    /* REM  MAT X=ZER */
    /* BASIC: 1610 P=1000 */
line_1610:;
    P = 1000;
    /* BASIC: 1620 D=100000. */
line_1620:;
    D = 100000.;
    /* BASIC: 1630 PRINT "HOW MANY BETS"; */
line_1630:;
    printf("%s", "HOW MANY BETS");
    /* BASIC: 1640 INPUT Y */
line_1640:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &Y);
    /* BASIC: 1650 IF Y<1 OR Y<>INT(Y) THEN 1630 */
line_1650:;
    if (Y<1   ||   Y!=floor(Y)) { goto line_1630; }
    /* BASIC: 1660 FOR I=1 TO 50: A(I)=0: NEXT I: REM  MAT A=ZER */
line_1660:;
    I = 1; for_loop_I_1660: if (((1) >= 0 && I > (50)) || ((1) < 0 && I < (50))) goto end_for_I_1660;
    A_arr[(int)(I)] = 0;
    I += (1); goto for_loop_I_1660; end_for_I_1660:;
    /* REM  MAT A=ZER */
    /* BASIC: 1670 FOR C=1 TO Y */
line_1670:;
    C = 1; for_loop_C_1670: if (((1) >= 0 && C > (Y)) || ((1) < 0 && C < (Y))) goto end_for_C_1670;
    /* BASIC: 1680 PRINT "NUMBER";C; */
line_1680:;
    printf("%s", "NUMBER"); printf("%g ", (double)(C));
    /* BASIC: 1690 INPUT X,Z */
line_1690:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf", &X, &Z);
    /* BASIC: 1700 B(C)=Z */
line_1700:;
    B_arr[(int)(C)] = Z;
    /* BASIC: 1710 T(C)=X */
line_1710:;
    T_arr[(int)(C)] = X;
    /* BASIC: 1720 IF X<1 OR X>50 OR X<>INT(X) THEN 1680 */
line_1720:;
    if (X<1   ||   X>50   ||   X!=floor(X)) { goto line_1680; }
    /* BASIC: 1730 IF Z<1 OR Z<>INT(Z) THEN 1680 */
line_1730:;
    if (Z<1   ||   Z!=floor(Z)) { goto line_1680; }
    /* BASIC: 1740 IF Z<5 OR Z>500 THEN 1680 */
line_1740:;
    if (Z<5   ||   Z>500) { goto line_1680; }
    /* BASIC: 1750 IF A(X)=0 THEN 1780 */
line_1750:;
    if (A_arr[(int)(X)]==0) { goto line_1780; }
    /* BASIC: 1760 PRINT "YOU MADE THAT BET ONCE ALREADY,DUM-DUM" */
line_1760:;
    printf("%s", "YOU MADE THAT BET ONCE ALREADY,DUM-DUM"); printf("\n");
    /* BASIC: 1770 GOTO 1680 */
line_1770:;
    goto line_1680;
    /* BASIC: 1780 A(X)=1 */
line_1780:;
    A_arr[(int)(X)] = 1;
    /* BASIC: 1790 NEXT C */
line_1790:;
    C += (1); goto for_loop_C_1670; end_for_C_1670:;
    /* BASIC: 1800 PRINT "SPINNING" */
line_1800:;
    printf("%s", "SPINNING"); printf("\n");
    /* BASIC: 1810 PRINT */
line_1810:;
    printf("\n");
    /* BASIC: 1820 PRINT */
line_1820:;
    printf("\n");
    /* BASIC: 1830 S=INT(RND(1)*100) */
line_1830:;
    S = floor(((double)rand() / (double)RAND_MAX)*100);
    /* BASIC: 1840 IF S=0 OR S>38 THEN 1830 */
line_1840:;
    if (S==0   ||   S>38) { goto line_1830; }
    /* BASIC: 1850 X(S)=X(S)+1 */
line_1850:;
    X_arr[(int)(S)] = X_arr[(int)(S)]+1;
    /* BASIC: 1860 IF S<37 THEN 1920 */
line_1860:;
    if (S<37) { goto line_1920; }
    /* BASIC: 1870 IF S=37 THEN 1900 */
line_1870:;
    if (S==37) { goto line_1900; }
    /* BASIC: 1880 PRINT "00" */
line_1880:;
    printf("%s", "00"); printf("\n");
    /* BASIC: 1890 GOTO 2020 */
line_1890:;
    goto line_2020;
    /* BASIC: 1900 PRINT "0" */
line_1900:;
    printf("%s", "0"); printf("\n");
    /* BASIC: 1910 GOTO 2020 */
line_1910:;
    goto line_2020;
    /* BASIC: 1920 RESTORE */
line_1920:;
    data_ptr = 0;
    /* BASIC: 1930 FOR I1=1 TO 18 */
line_1930:;
    I1 = 1; for_loop_I1_1930: if (((1) >= 0 && I1 > (18)) || ((1) < 0 && I1 < (18))) goto end_for_I1_1930;
    /* BASIC: 1940 READ R */
line_1940:;
    read_numeric(&R);
    /* BASIC: 1950 IF R=S THEN 2000 */
line_1950:;
    if (R==S) { goto line_2000; }
    /* BASIC: 1960 NEXT I1 */
line_1960:;
    I1 += (1); goto for_loop_I1_1930; end_for_I1_1930:;
    /* BASIC: 1970 A$="BLACK" */
line_1970:;
    str_assign(A_str, sizeof(A_str), "BLACK");
    /* BASIC: 1980 PRINT S;A$ */
line_1980:;
    printf("%g ", (double)(S)); printf("%s", A_str); printf("\n");
    /* BASIC: 1990 GOTO 2020 */
line_1990:;
    goto line_2020;
    /* BASIC: 2000 A$="RED" */
line_2000:;
    str_assign(A_str, sizeof(A_str), "RED");
    /* BASIC: 2010 GOTO 1980 */
line_2010:;
    goto line_1980;
    /* BASIC: 2020 PRINT */
line_2020:;
    printf("\n");
    /* BASIC: 2030 FOR C=1 TO Y */
line_2030:;
    C = 1; for_loop_C_2030: if (((1) >= 0 && C > (Y)) || ((1) < 0 && C < (Y))) goto end_for_C_2030;
    /* BASIC: 2040 IF T(C)<37 THEN 2710 */
line_2040:;
    if (T_arr[(int)(C)]<37) { goto line_2710; }
    /* BASIC: 2050 ON T(C)-36 GOTO 2090,2190,2220,2250,2300,2350,2400,2470,2500 */
line_2050:;
    switch ((int)(T_arr[(int)(C)]-36)) {     case 1: goto line_2090;     case 2: goto line_2190;     case 3: goto line_2220;     case 4: goto line_2250;     case 5: goto line_2300;     case 6: goto line_2350;     case 7: goto line_2400;     case 8: goto line_2470;     case 9: goto line_2500; }
    /* BASIC: 2060 ON T(C)-45 GOTO 2530,2560,2630 */
line_2060:;
    switch ((int)(T_arr[(int)(C)]-45)) {     case 1: goto line_2530;     case 2: goto line_2560;     case 3: goto line_2630; }
    /* BASIC: 2070 GOTO 2710 */
line_2070:;
    goto line_2710;
    /* BASIC: 2080 S TO P */
line_2080:;
    /* UNTRANSLATED: S TO P */
    /* BASIC: 2090 REM  1-12(37) 2:1 */
line_2090:;
    /* REM  1-12(37) 2 */
    /* UNTRANSLATED: 1 */
    /* BASIC: 2100 IF S <= 12 THEN 2150 */
line_2100:;
    if (S <= 12) { goto line_2150; }
    /* BASIC: 2110 PRINT "YOU LOSE";B(C);"DOLLARS ON BET";C */
line_2110:;
    printf("%s", "YOU LOSE"); printf("%g ", (double)(B_arr[(int)(C)])); printf("%s", "DOLLARS ON BET"); printf("%g ", (double)(C)); printf("\n");
    /* BASIC: 2120 D=D+B(C) */
line_2120:;
    D = D+B_arr[(int)(C)];
    /* BASIC: 2130 P=P-B(C) */
line_2130:;
    P = P-B_arr[(int)(C)];
    /* BASIC: 2140 GOTO 2180 */
line_2140:;
    goto line_2180;
    /* BASIC: 2150 PRINT "YOU WIN";B(C)*2;"DOLLARS ON BET"C */
line_2150:;
    printf("%s", "YOU WIN"); printf("%g ", (double)(B_arr[(int)(C)]*2)); printf("%s", "DOLLARS ON BET"); printf("%g ", (double)(C)); printf("\n");
    /* BASIC: 2160 D=D-B(C)*2 */
line_2160:;
    D = D-B_arr[(int)(C)]*2;
    /* BASIC: 2170 P=P+B(C)*2 */
line_2170:;
    P = P+B_arr[(int)(C)]*2;
    /* BASIC: 2180 GOTO 2810 */
line_2180:;
    goto line_2810;
    /* BASIC: 2190 REM  13-24(38) 2:1 */
line_2190:;
    /* REM  13-24(38) 2 */
    /* UNTRANSLATED: 1 */
    /* BASIC: 2200 IF S>12 AND S<25 THEN 2150 */
line_2200:;
    if (S>12   &&   S<25) { goto line_2150; }
    /* BASIC: 2210 GOTO 2110 */
line_2210:;
    goto line_2110;
    /* BASIC: 2220 REM  25-36(39) 2:1 */
line_2220:;
    /* REM  25-36(39) 2 */
    /* UNTRANSLATED: 1 */
    /* BASIC: 2230 IF S>24 AND S<37 THEN 2150 */
line_2230:;
    if (S>24   &&   S<37) { goto line_2150; }
    /* BASIC: 2240 GOTO 2110 */
line_2240:;
    goto line_2110;
    /* BASIC: 2250 REM  FIRST COLUMN(40) 2:1 */
line_2250:;
    /* REM  FIRST COLUMN(40) 2 */
    /* UNTRANSLATED: 1 */
    /* BASIC: 2260 FOR I=1 TO 34 STEP 3 */
line_2260:;
    I = 1; for_loop_I_2260: if (((3) >= 0 && I > (34)) || ((3) < 0 && I < (34))) goto end_for_I_2260;
    /* BASIC: 2270 IF S=I THEN 2150 */
line_2270:;
    if (S==I) { goto line_2150; }
    /* BASIC: 2280 NEXT I */
line_2280:;
    I += (3); goto for_loop_I_2260; end_for_I_2260:;
    /* BASIC: 2290 GOTO 2110 */
line_2290:;
    goto line_2110;
    /* BASIC: 2300 REM  SECOND COLUMN(41) 2:1 */
line_2300:;
    /* REM  SECOND COLUMN(41) 2 */
    /* UNTRANSLATED: 1 */
    /* BASIC: 2310 FOR I=2 TO 35 STEP 3 */
line_2310:;
    I = 2; for_loop_I_2310: if (((3) >= 0 && I > (35)) || ((3) < 0 && I < (35))) goto end_for_I_2310;
    /* BASIC: 2320 IF S=I THEN 2150 */
line_2320:;
    if (S==I) { goto line_2150; }
    /* BASIC: 2330 NEXT I */
line_2330:;
    I += (3); goto for_loop_I_2310; end_for_I_2310:;
    /* BASIC: 2340 GOTO 2110 */
line_2340:;
    goto line_2110;
    /* BASIC: 2350 REM  THIRD COLUMN(42) 2:1 */
line_2350:;
    /* REM  THIRD COLUMN(42) 2 */
    /* UNTRANSLATED: 1 */
    /* BASIC: 2360 FOR I=3 TO 36 STEP 3 */
line_2360:;
    I = 3; for_loop_I_2360: if (((3) >= 0 && I > (36)) || ((3) < 0 && I < (36))) goto end_for_I_2360;
    /* BASIC: 2370 IF S=I THEN 2150 */
line_2370:;
    if (S==I) { goto line_2150; }
    /* BASIC: 2380 NEXT I */
line_2380:;
    I += (3); goto for_loop_I_2360; end_for_I_2360:;
    /* BASIC: 2390 GOTO 2110 */
line_2390:;
    goto line_2110;
    /* BASIC: 2400 REM  1-18(43) 1:1 */
line_2400:;
    /* REM  1-18(43) 1 */
    /* UNTRANSLATED: 1 */
    /* BASIC: 2410 IF S<19 THEN 2430 */
line_2410:;
    if (S<19) { goto line_2430; }
    /* BASIC: 2420 GOTO 2110 */
line_2420:;
    goto line_2110;
    /* BASIC: 2430 PRINT "YOU WIN";B(C);"DOLLARS ON BET";C */
line_2430:;
    printf("%s", "YOU WIN"); printf("%g ", (double)(B_arr[(int)(C)])); printf("%s", "DOLLARS ON BET"); printf("%g ", (double)(C)); printf("\n");
    /* BASIC: 2440 D=D-B(C) */
line_2440:;
    D = D-B_arr[(int)(C)];
    /* BASIC: 2450 P=P+B(C) */
line_2450:;
    P = P+B_arr[(int)(C)];
    /* BASIC: 2460 GOTO 2810 */
line_2460:;
    goto line_2810;
    /* BASIC: 2470 REM  19-36(44) 1:1 */
line_2470:;
    /* REM  19-36(44) 1 */
    /* UNTRANSLATED: 1 */
    /* BASIC: 2480 IF S<37 AND S>18 THEN 2430 */
line_2480:;
    if (S<37   &&   S>18) { goto line_2430; }
    /* BASIC: 2490 GOTO 2110 */
line_2490:;
    goto line_2110;
    /* BASIC: 2500 REM  EVEN(45) 1:1 */
line_2500:;
    /* REM  EVEN(45) 1 */
    /* UNTRANSLATED: 1 */
    /* BASIC: 2510 IF S/2=INT(S/2) AND S<37 THEN 2430 */
line_2510:;
    if (S/2==floor(S/2)   &&   S<37) { goto line_2430; }
    /* BASIC: 2520 GOTO 2110 */
line_2520:;
    goto line_2110;
    /* BASIC: 2530 REM  ODD(46) 1:1 */
line_2530:;
    /* REM  ODD(46) 1 */
    /* UNTRANSLATED: 1 */
    /* BASIC: 2540 IF S/2<>INT(S/2) AND S<37 THEN 2430 */
line_2540:;
    if (S/2!=floor(S/2)   &&   S<37) { goto line_2430; }
    /* BASIC: 2550 GOTO 2110 */
line_2550:;
    goto line_2110;
    /* BASIC: 2560 REM  RED(47) 1:1 */
line_2560:;
    /* REM  RED(47) 1 */
    /* UNTRANSLATED: 1 */
    /* BASIC: 2570 RESTORE */
line_2570:;
    data_ptr = 0;
    /* BASIC: 2580 FOR I=1 TO 18 */
line_2580:;
    I = 1; for_loop_I_2580: if (((1) >= 0 && I > (18)) || ((1) < 0 && I < (18))) goto end_for_I_2580;
    /* BASIC: 2590 READ R */
line_2590:;
    read_numeric(&R);
    /* BASIC: 2600 IF S=R THEN 2430 */
line_2600:;
    if (S==R) { goto line_2430; }
    /* BASIC: 2610 NEXT I */
line_2610:;
    I += (1); goto for_loop_I_2580; end_for_I_2580:;
    /* BASIC: 2620 GOTO 2110 */
line_2620:;
    goto line_2110;
    /* BASIC: 2630 REM  BLACK(48) 1:1 */
line_2630:;
    /* REM  BLACK(48) 1 */
    /* UNTRANSLATED: 1 */
    /* BASIC: 2640 RESTORE */
line_2640:;
    data_ptr = 0;
    /* BASIC: 2650 FOR I=1 TO 18 */
line_2650:;
    I = 1; for_loop_I_2650: if (((1) >= 0 && I > (18)) || ((1) < 0 && I < (18))) goto end_for_I_2650;
    /* BASIC: 2660 READ R */
line_2660:;
    read_numeric(&R);
    /* BASIC: 2670 IF S=R THEN 2110 */
line_2670:;
    if (S==R) { goto line_2110; }
    /* BASIC: 2680 NEXT I */
line_2680:;
    I += (1); goto for_loop_I_2650; end_for_I_2650:;
    /* BASIC: 2690 IF S>36 THEN 2110 */
line_2690:;
    if (S>36) { goto line_2110; }
    /* BASIC: 2700 GOTO 2430 */
line_2700:;
    goto line_2430;
    /* BASIC: 2710 REM--1 TO 36,0,00(1-36,49,50)35:1 */
line_2710:;
    /* REM--1 TO 36,0,00(1-36,49,50)35 */
    /* UNTRANSLATED: 1 */
    /* BASIC: 2720 IF T(C)<49 THEN 2760 */
line_2720:;
    if (T_arr[(int)(C)]<49) { goto line_2760; }
    /* BASIC: 2730 IF T(C)=49 AND S=37 THEN 2780 */
line_2730:;
    if (T_arr[(int)(C)]==49   &&   S==37) { goto line_2780; }
    /* BASIC: 2740 IF T(C)=50 AND S=38 THEN 2780 */
line_2740:;
    if (T_arr[(int)(C)]==50   &&   S==38) { goto line_2780; }
    /* BASIC: 2750 GOTO 2110 */
line_2750:;
    goto line_2110;
    /* BASIC: 2760 IF T(C)=S THEN 2780 */
line_2760:;
    if (T_arr[(int)(C)]==S) { goto line_2780; }
    /* BASIC: 2770 GOTO 2110 */
line_2770:;
    goto line_2110;
    /* BASIC: 2780 PRINT "YOU WIN";B(C)*35;"DOLLARS ON BET";C */
line_2780:;
    printf("%s", "YOU WIN"); printf("%g ", (double)(B_arr[(int)(C)]*35)); printf("%s", "DOLLARS ON BET"); printf("%g ", (double)(C)); printf("\n");
    /* BASIC: 2790 D=D-B(C)*35 */
line_2790:;
    D = D-B_arr[(int)(C)]*35;
    /* BASIC: 2800 P=P+B(C)*35 */
line_2800:;
    P = P+B_arr[(int)(C)]*35;
    /* BASIC: 2810 NEXT C */
line_2810:;
    C += (1); goto for_loop_C_2030; end_for_C_2030:;
    /* BASIC: 2820 PRINT */
line_2820:;
    printf("\n");
    /* BASIC: 2830 PRINT "TOTALS:","ME","YOU" */
line_2830:;
    printf("%s", "TOTALS:"); printf("\t"); printf("%s", "ME"); printf("\t"); printf("%s", "YOU"); printf("\n");
    /* BASIC: 2840 PRINT " ",D,P */
line_2840:;
    printf("%s", " "); printf("\t"); printf("%g ", (double)(D)); printf("\t"); printf("%g ", (double)(P)); printf("\n");
    /* BASIC: 2850 IF P>0 THEN 2880 */
line_2850:;
    if (P>0) { goto line_2880; }
    /* BASIC: 2860 PRINT "OOPS! YOU JUST SPENT YOUR LAST DOLLAR!" */
line_2860:;
    printf("%s", "OOPS! YOU JUST SPENT YOUR LAST DOLLAR!"); printf("\n");
    /* BASIC: 2870 GOTO 3190 */
line_2870:;
    goto line_3190;
    /* BASIC: 2880 IF D>0 THEN 2920 */
line_2880:;
    if (D>0) { goto line_2920; }
    /* BASIC: 2890 PRINT "YOU BROKE THE HOUSE!" */
line_2890:;
    printf("%s", "YOU BROKE THE HOUSE!"); printf("\n");
    /* BASIC: 2900 P=101000. */
line_2900:;
    P = 101000.;
    /* BASIC: 2910 GOTO 2960 */
line_2910:;
    goto line_2960;
    /* BASIC: 2920 PRINT "AGAIN"; */
line_2920:;
    printf("%s", "AGAIN");
    /* BASIC: 2930 INPUT Y$ */
line_2930:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", Y_str);
    /* BASIC: 2940 IF LEFT$(Y$,1)="Y" THEN 1630 */
line_2940:;
    if (strcmp(basic_LEFT(Y_str,1), "Y") == 0) { goto line_1630; }
    /* BASIC: 2950 DATA 1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36 */
line_2950:;
    /* UNTRANSLATED: DATA 1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36 */
    /* BASIC: 2960 IF P<1 THEN 3190 */
line_2960:;
    if (P<1) { goto line_3190; }
    /* BASIC: 2970 PRINT "TO WHOM SHALL I MAKE THE CHECK"; */
line_2970:;
    printf("%s", "TO WHOM SHALL I MAKE THE CHECK");
    /* BASIC: 2980 INPUT B$ */
line_2980:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", B_str);
    /* BASIC: 2990 PRINT */
line_2990:;
    printf("\n");
    /* BASIC: 3000 FOR I=1 TO 72: PRINT "-";: NEXT I: REM PRINT 72 DASHES */
line_3000:;
    I = 1; for_loop_I_3000: if (((1) >= 0 && I > (72)) || ((1) < 0 && I < (72))) goto end_for_I_3000;
    printf("%s", "-");
    I += (1); goto for_loop_I_3000; end_for_I_3000:;
    /* REM PRINT 72 DASHES */
    /* BASIC: 3010 PRINT TAB(50);"CHECK NO. ";INT(RND(1)*100) */
line_3010:;
    { int _t; for(_t=0; _t<50; _t++) printf(" "); } printf("%s", "CHECK NO. "); printf("%g ", (double)(floor(((double)rand() / (double)RAND_MAX)*100))); printf("\n");
    /* BASIC: 3020 PRINT */
line_3020:;
    printf("\n");
    /* BASIC: 3030 GOSUB 3230 */
line_3030:;
    gosub_stack[gosub_sp++] = 1; goto line_3230; line_ret_1:;
    /* BASIC: 3040 PRINT TAB(40);M$ */
line_3040:;
    { int _t; for(_t=0; _t<40; _t++) printf(" "); } printf("%s", M_str); printf("\n");
    /* BASIC: 3050 PRINT */
line_3050:;
    printf("\n");
    /* BASIC: 3060 PRINT */
line_3060:;
    printf("\n");
    /* BASIC: 3070 PRINT "PAY TO THE ORDER OF-----";B$;"-----$ "; */
line_3070:;
    printf("%s", "PAY TO THE ORDER OF-----"); printf("%s", B_str); printf("%s", "-----$ ");
    /* BASIC: 3080 PRINT P */
line_3080:;
    printf("%g ", (double)(P)); printf("\n");
    /* BASIC: 3090 PRINT */
line_3090:;
    printf("\n");
    /* BASIC: 3100 PRINT */
line_3100:;
    printf("\n");
    /* BASIC: 3110 PRINT TAB(10),"THE MEMORY BANK OF NEW YORK" */
line_3110:;
    { int _t; for(_t=0; _t<10; _t++) printf(" "); } printf("\t"); printf("%s", "THE MEMORY BANK OF NEW YORK"); printf("\n");
    /* BASIC: 3120 PRINT */
line_3120:;
    printf("\n");
    /* BASIC: 3130 PRINT TAB(40),"THE COMPUTER" */
line_3130:;
    { int _t; for(_t=0; _t<40; _t++) printf(" "); } printf("\t"); printf("%s", "THE COMPUTER"); printf("\n");
    /* BASIC: 3140 PRINT TAB(40)"----------X-----" */
line_3140:;
    { int _t; for(_t=0; _t<40; _t++) printf(" "); } printf("%s", "----------X-----"); printf("\n");
    /* BASIC: 3150 PRINT */
line_3150:;
    printf("\n");
    /* BASIC: 3160 FOR I=1 TO 62: PRINT "-";: NEXT I */
line_3160:;
    I = 1; for_loop_I_3160: if (((1) >= 0 && I > (62)) || ((1) < 0 && I < (62))) goto end_for_I_3160;
    printf("%s", "-");
    I += (1); goto for_loop_I_3160; end_for_I_3160:;
    /* BASIC: 3170 PRINT "COME BACK SOON!" */
line_3170:;
    printf("%s", "COME BACK SOON!"); printf("\n");
    /* BASIC: 3180 GOTO 3210 */
line_3180:;
    goto line_3210;
    /* BASIC: 3190 PRINT "THANKS FOR YOUR MONEY." */
line_3190:;
    printf("%s", "THANKS FOR YOUR MONEY."); printf("\n");
    /* BASIC: 3200 PRINT "I'LL USE IT TO BUY A SOLID GOLD ROULETTE WHEEL" */
line_3200:;
    printf("%s", "I'LL USE IT TO BUY A SOLID GOLD ROULETTE WHEEL"); printf("\n");
    /* BASIC: 3210 PRINT */
line_3210:;
    printf("\n");
    /* BASIC: 3220 GOTO 3420 */
line_3220:;
    goto line_3420;
    /* BASIC: 3230 REM */
line_3230:;
    /* REM */
    /* BASIC: 3240 REM     THIS ROUTINE RETURN S THE CURRENT DATE IN M$ */
line_3240:;
    /* REM     THIS ROUTINE RETURN S THE CURRENT DATE IN M$ */
    /* BASIC: 3250 REM     IF YOU HAVE SYSTEM FUNCTIONS TO H AND LE THIS */
line_3250:;
    /* REM     IF YOU HAVE SYSTEM FUNCTIONS TO H AND LE THIS */
    /* BASIC: 3260 REM     THEY CAN BE USED HERE.  HOWEVER IN THIS */
line_3260:;
    /* REM     THEY CAN BE USED HERE.  HOWEVER IN THIS */
    /* BASIC: 3270 REM     PROGRAM, WE JUST INPUT THE DATE AT THE START */
line_3270:;
    /* REM     PROGRAM, WE JUST INPUT THE DATE AT THE START */
    /* BASIC: 3280 REM     THE GAME */
line_3280:;
    /* REM     THE GAME */
    /* BASIC: 3290 REM */
line_3290:;
    /* REM */
    /* BASIC: 3300 REM     THE DATE IS RETURN ED IN VARIABLE M$ */
line_3300:;
    /* REM     THE DATE IS RETURN ED IN VARIABLE M$ */
    /* BASIC: 3310 M$=D$+", "+E$ */
line_3310:;
    str_assign(M_str, sizeof(M_str), str_cat_helper(str_cat_helper(D_str, ", "), E_str));
    /* BASIC: 3320 RETURN */
line_3320:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 3420 END */
line_3420:;
    exit(0);

    return 0;
}
