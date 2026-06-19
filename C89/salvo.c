/*
 * Transpiled from salvo.bas
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

static DataItem program_data[12] = {
    { DATA_NUM, 1.0, NULL },
    { DATA_NUM, 1.0, NULL },
    { DATA_NUM, -1.0, NULL },
    { DATA_NUM, 1.0, NULL },
    { DATA_NUM, 1.0, NULL },
    { DATA_NUM, -3.0, NULL },
    { DATA_NUM, 1.0, NULL },
    { DATA_NUM, 1.0, NULL },
    { DATA_NUM, 0.0, NULL },
    { DATA_NUM, 2.0, NULL },
    { DATA_NUM, -1.0, NULL },
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
static double A, B, C, D, DEF, E, F, G, H, K, M, M2, M3, N, P, P3, Q, Q9, R, R2, R3, S, U, U6, U8, V, V2, W, X, X1, Y, Y1, Z, Z2, Z3, Z5, Z8;
static char J_str[256] = {0};
static char K_str[256] = {0};
static double A_arr[2000] = {0};
static double B_arr[2000] = {0};
static double C_arr[2000] = {0};
static double D_arr[2000] = {0};
static double E_arr[2000] = {0};
static double F_arr[2000] = {0};
static double G_arr[2000] = {0};
static double H_arr[2000] = {0};
static double K_arr[2000] = {0};
static char _input_buf[256];

/* User-defined functions forward declarations */
static double FNA(double K);
static double FNB(double K);

/* User-defined functions definitions */
static double FNA(double K) {
    return (5-K)*3-2*floor(K/4)+basic_SGN(K-1)-1;
}

static double FNB(double K) {
    return K+floor(K/4)-basic_SGN(K-1);
}

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 1000 PRINT TAB(33);"SALVO" */
line_1000:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "SALVO"); printf("\n");
    /* BASIC: 1010 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_1010:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 1020 PRINT:PRINT:PRINT */
line_1020:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 1030 REM */
line_1030:;
    /* REM */
    /* BASIC: 1040 DIM A(10,10),B(10,10),C(7),D(7),E(12),F(12),G(12),H(12),K(10,10) */
line_1040:;
    /* DIM A(10,10),B(10,10),C(7),D(7),E(12),F(12),G(12),H(12),K(10,10) (handled statically) */
    /* BASIC: 1050 Z8=0 */
line_1050:;
    Z8 = 0;
    /* BASIC: 1060 FOR W=1 TO 12 */
line_1060:;
    W = 1; for_loop_W_1060: if (((1) >= 0 && W > (12)) || ((1) < 0 && W < (12))) goto end_for_W_1060;
    /* BASIC: 1070 E(W)=-1 */
line_1070:;
    E_arr[(int)(W)] = -1;
    /* BASIC: 1080 H(W)=-1 */
line_1080:;
    H_arr[(int)(W)] = -1;
    /* BASIC: 1090 NEXT W */
line_1090:;
    W += (1); goto for_loop_W_1060; end_for_W_1060:;
    /* BASIC: 1100 FOR X=1 TO 10 */
line_1100:;
    X = 1; for_loop_X_1100: if (((1) >= 0 && X > (10)) || ((1) < 0 && X < (10))) goto end_for_X_1100;
    /* BASIC: 1110 FOR Y=1 TO 10 */
line_1110:;
    Y = 1; for_loop_Y_1110: if (((1) >= 0 && Y > (10)) || ((1) < 0 && Y < (10))) goto end_for_Y_1110;
    /* BASIC: 1120 B(X,Y)=0 */
line_1120:;
    B_arr[(int)(X) * 100 + (int)(Y)] = 0;
    /* BASIC: 1130 NEXT Y */
line_1130:;
    Y += (1); goto for_loop_Y_1110; end_for_Y_1110:;
    /* BASIC: 1140 NEXT X */
line_1140:;
    X += (1); goto for_loop_X_1100; end_for_X_1100:;
    /* BASIC: 1150 FOR X=1 TO 12 */
line_1150:;
    X = 1; for_loop_X_1150: if (((1) >= 0 && X > (12)) || ((1) < 0 && X < (12))) goto end_for_X_1150;
    /* BASIC: 1160 F(X)=0 */
line_1160:;
    F_arr[(int)(X)] = 0;
    /* BASIC: 1170 G(X)=0 */
line_1170:;
    G_arr[(int)(X)] = 0;
    /* BASIC: 1180 NEXT X */
line_1180:;
    X += (1); goto for_loop_X_1150; end_for_X_1150:;
    /* BASIC: 1190 FOR X=1 TO 10 */
line_1190:;
    X = 1; for_loop_X_1190: if (((1) >= 0 && X > (10)) || ((1) < 0 && X < (10))) goto end_for_X_1190;
    /* BASIC: 1200 FOR Y=1 TO 10 */
line_1200:;
    Y = 1; for_loop_Y_1200: if (((1) >= 0 && Y > (10)) || ((1) < 0 && Y < (10))) goto end_for_Y_1200;
    /* BASIC: 1210 A(X,Y)=0 */
line_1210:;
    A_arr[(int)(X) * 100 + (int)(Y)] = 0;
    /* BASIC: 1220 NEXT Y */
line_1220:;
    Y += (1); goto for_loop_Y_1200; end_for_Y_1200:;
    /* BASIC: 1230 NEXT X */
line_1230:;
    X += (1); goto for_loop_X_1190; end_for_X_1190:;
    /* BASIC: 1240 FOR K=4 TO 1 STEP -1 */
line_1240:;
    K = 4; for_loop_K_1240: if (((-1) >= 0 && K > (1)) || ((-1) < 0 && K < (1))) goto end_for_K_1240;
    /* BASIC: 1250 U6=0 */
line_1250:;
    U6 = 0;
    /* BASIC: 1260 GOSUB 2910 */
line_1260:;
    gosub_stack[gosub_sp++] = 1; goto line_2910; line_ret_1:;
    /* BASIC: 1270 DEF FNA(K)=(5-K)*3-2*INT(K/4)+SGN(K-1)-1 */
line_1270:;
    /* UNTRANSLATED: DEF FNA(K)=(5-K)*3-2*INT(K/4)+SGN(K-1)-1 */
    /* BASIC: 1280 DEF FNB(K)=K+INT(K/4)-SGN(K-1) */
line_1280:;
    /* UNTRANSLATED: DEF FNB(K)=K+INT(K/4)-SGN(K-1) */
    /* BASIC: 1290 IF V+V2+V*V2=0 THEN 1260 */
line_1290:;
    if (V+V2+V*V2==0) { goto line_1260; }
    /* BASIC: 1300 IF Y+V*FNB(K)>10 THEN 1260 */
line_1300:;
    if (Y+V*FNB(K)>10) { goto line_1260; }
    /* BASIC: 1310 IF Y+V*FNB(K)<1 THEN 1260 */
line_1310:;
    if (Y+V*FNB(K)<1) { goto line_1260; }
    /* BASIC: 1320 IF X+V2*FNB(K)>10 THEN 1260 */
line_1320:;
    if (X+V2*FNB(K)>10) { goto line_1260; }
    /* BASIC: 1330 IF X+V2*FNB(K)<1 THEN 1260 */
line_1330:;
    if (X+V2*FNB(K)<1) { goto line_1260; }
    /* BASIC: 1340 U6=U6+1 */
line_1340:;
    U6 = U6+1;
    /* BASIC: 1350 IF U6>25 THEN 1190 */
line_1350:;
    if (U6>25) { goto line_1190; }
    /* BASIC: 1360 FOR Z=0 TO FNB(K) */
line_1360:;
    Z = 0; for_loop_Z_1360: if (((1) >= 0 && Z > (FNB(K))) || ((1) < 0 && Z < (FNB(K)))) goto end_for_Z_1360;
    /* BASIC: 1370 F(Z+FNA(K))=X+V2*Z */
line_1370:;
    F_arr[(int)(Z+FNA(K))] = X+V2*Z;
    /* BASIC: 1380 G(Z+FNA(K))=Y+V*Z */
line_1380:;
    G_arr[(int)(Z+FNA(K))] = Y+V*Z;
    /* BASIC: 1390 NEXT Z */
line_1390:;
    Z += (1); goto for_loop_Z_1360; end_for_Z_1360:;
    /* BASIC: 1400 U8=FNA(K) */
line_1400:;
    U8 = FNA(K);
    /* BASIC: 1405 IF U8>U8+FNB(K) THEN 1460 */
line_1405:;
    if (U8>U8+FNB(K)) { goto line_1460; }
    /* BASIC: 1410 FOR Z2= U8 TO U8+FNB(K) */
line_1410:;
    Z2 = U8; for_loop_Z2_1410: if (((1) >= 0 && Z2 > (U8+FNB(K))) || ((1) < 0 && Z2 < (U8+FNB(K)))) goto end_for_Z2_1410;
    /* BASIC: 1415 IF U8<2 THEN 1450 */
line_1415:;
    if (U8<2) { goto line_1450; }
    /* BASIC: 1420 FOR Z3=1 TO U8-1 */
line_1420:;
    Z3 = 1; for_loop_Z3_1420: if (((1) >= 0 && Z3 > (U8-1)) || ((1) < 0 && Z3 < (U8-1))) goto end_for_Z3_1420;
    /* BASIC: 1430 IF SQR((F(Z3)-F(Z2))^2 + (G(Z3)-G(Z2))^2) < 3.59 THEN 1260 */
line_1430:;
    if (sqrt(pow((F_arr[(int)(Z3)]-F_arr[(int)(Z2)]), 2)+ pow((G_arr[(int)(Z3)]-G_arr[(int)(Z2)]), 2)) < 3.59) { goto line_1260; }
    /* BASIC: 1440 NEXT Z3 */
line_1440:;
    Z3 += (1); goto for_loop_Z3_1420; end_for_Z3_1420:;
    /* BASIC: 1450 NEXT Z2 */
line_1450:;
    Z2 += (1); goto for_loop_Z2_1410; end_for_Z2_1410:;
    /* BASIC: 1460 FOR Z=0 TO FNB(K) */
line_1460:;
    Z = 0; for_loop_Z_1460: if (((1) >= 0 && Z > (FNB(K))) || ((1) < 0 && Z < (FNB(K)))) goto end_for_Z_1460;
    /* BASIC: 1470 A(F(Z+U8),G(Z+U8))=.5+SGN(K-1)*(K-1.5) */
line_1470:;
    A_arr[(int)(F_arr[(int)(Z+U8)]) * 100 + (int)(G_arr[(int)(Z+U8)])] = .5+basic_SGN(K-1)*(K-1.5);
    /* BASIC: 1480 NEXT Z */
line_1480:;
    Z += (1); goto for_loop_Z_1460; end_for_Z_1460:;
    /* BASIC: 1490 NEXT K */
line_1490:;
    K += (-1); goto for_loop_K_1240; end_for_K_1240:;
    /* BASIC: 1500 PRINT "ENTER COORDINATES FOR..." */
line_1500:;
    printf("%s", "ENTER COORDINATES FOR..."); printf("\n");
    /* BASIC: 1510 PRINT "BATTLESHIP" */
line_1510:;
    printf("%s", "BATTLESHIP"); printf("\n");
    /* BASIC: 1520 FOR X=1 TO 5 */
line_1520:;
    X = 1; for_loop_X_1520: if (((1) >= 0 && X > (5)) || ((1) < 0 && X < (5))) goto end_for_X_1520;
    /* BASIC: 1530 INPUT Y,Z */
line_1530:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf", &Y, &Z);
    /* BASIC: 1540 B(Y,Z)=3 */
line_1540:;
    B_arr[(int)(Y) * 100 + (int)(Z)] = 3;
    /* BASIC: 1550 NEXT X */
line_1550:;
    X += (1); goto for_loop_X_1520; end_for_X_1520:;
    /* BASIC: 1560 PRINT "CRUISER" */
line_1560:;
    printf("%s", "CRUISER"); printf("\n");
    /* BASIC: 1570 FOR X=1 TO 3 */
line_1570:;
    X = 1; for_loop_X_1570: if (((1) >= 0 && X > (3)) || ((1) < 0 && X < (3))) goto end_for_X_1570;
    /* BASIC: 1580 INPUT Y,Z */
line_1580:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf", &Y, &Z);
    /* BASIC: 1590 B(Y,Z)=2 */
line_1590:;
    B_arr[(int)(Y) * 100 + (int)(Z)] = 2;
    /* BASIC: 1600 NEXT X */
line_1600:;
    X += (1); goto for_loop_X_1570; end_for_X_1570:;
    /* BASIC: 1610 PRINT "DESTROYER<A>" */
line_1610:;
    printf("%s", "DESTROYER<A>"); printf("\n");
    /* BASIC: 1620 FOR X=1 TO 2 */
line_1620:;
    X = 1; for_loop_X_1620: if (((1) >= 0 && X > (2)) || ((1) < 0 && X < (2))) goto end_for_X_1620;
    /* BASIC: 1630 INPUT Y,Z */
line_1630:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf", &Y, &Z);
    /* BASIC: 1640 B(Y,Z)=1 */
line_1640:;
    B_arr[(int)(Y) * 100 + (int)(Z)] = 1;
    /* BASIC: 1650 NEXT X */
line_1650:;
    X += (1); goto for_loop_X_1620; end_for_X_1620:;
    /* BASIC: 1660 PRINT "DESTROYER<B>" */
line_1660:;
    printf("%s", "DESTROYER<B>"); printf("\n");
    /* BASIC: 1670 FOR X=1 TO 2 */
line_1670:;
    X = 1; for_loop_X_1670: if (((1) >= 0 && X > (2)) || ((1) < 0 && X < (2))) goto end_for_X_1670;
    /* BASIC: 1680 INPUT Y,Z */
line_1680:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf", &Y, &Z);
    /* BASIC: 1690 B(Y,Z)=.5 */
line_1690:;
    B_arr[(int)(Y) * 100 + (int)(Z)] = .5;
    /* BASIC: 1700 NEXT X */
line_1700:;
    X += (1); goto for_loop_X_1670; end_for_X_1670:;
    /* BASIC: 1710 PRINT "DO YOU WANT TO START"; */
line_1710:;
    printf("%s", "DO YOU WANT TO START");
    /* BASIC: 1720 INPUT J$ */
line_1720:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", J_str);
    /* BASIC: 1730 IF J$<>"WHERE ARE YOUR SHIPS?" THEN 1890 */
line_1730:;
    if (strcmp(J_str, "WHERE ARE YOUR SHIPS?") != 0) { goto line_1890; }
    /* BASIC: 1740 PRINT "BATTLESHIP" */
line_1740:;
    printf("%s", "BATTLESHIP"); printf("\n");
    /* BASIC: 1750 FOR Z=1 TO 5 */
line_1750:;
    Z = 1; for_loop_Z_1750: if (((1) >= 0 && Z > (5)) || ((1) < 0 && Z < (5))) goto end_for_Z_1750;
    /* BASIC: 1760 PRINT F(Z);G(Z) */
line_1760:;
    printf("%g ", (double)(F_arr[(int)(Z)])); printf("%g ", (double)(G_arr[(int)(Z)])); printf("\n");
    /* BASIC: 1770 NEXT Z */
line_1770:;
    Z += (1); goto for_loop_Z_1750; end_for_Z_1750:;
    /* BASIC: 1780 PRINT "CRUISER" */
line_1780:;
    printf("%s", "CRUISER"); printf("\n");
    /* BASIC: 1790 PRINT F(6);G(6) */
line_1790:;
    printf("%g ", (double)(F_arr[(int)(6)])); printf("%g ", (double)(G_arr[(int)(6)])); printf("\n");
    /* BASIC: 1800 PRINT F(7);G(7) */
line_1800:;
    printf("%g ", (double)(F_arr[(int)(7)])); printf("%g ", (double)(G_arr[(int)(7)])); printf("\n");
    /* BASIC: 1810 PRINT F(8);G(8) */
line_1810:;
    printf("%g ", (double)(F_arr[(int)(8)])); printf("%g ", (double)(G_arr[(int)(8)])); printf("\n");
    /* BASIC: 1820 PRINT "DESTROYER<A>" */
line_1820:;
    printf("%s", "DESTROYER<A>"); printf("\n");
    /* BASIC: 1830 PRINT F(9);G(9) */
line_1830:;
    printf("%g ", (double)(F_arr[(int)(9)])); printf("%g ", (double)(G_arr[(int)(9)])); printf("\n");
    /* BASIC: 1840 PRINT F(10);G(10) */
line_1840:;
    printf("%g ", (double)(F_arr[(int)(10)])); printf("%g ", (double)(G_arr[(int)(10)])); printf("\n");
    /* BASIC: 1850 PRINT "DESTROYER<B>" */
line_1850:;
    printf("%s", "DESTROYER<B>"); printf("\n");
    /* BASIC: 1860 PRINT F(11);G(11) */
line_1860:;
    printf("%g ", (double)(F_arr[(int)(11)])); printf("%g ", (double)(G_arr[(int)(11)])); printf("\n");
    /* BASIC: 1870 PRINT F(12);G(12) */
line_1870:;
    printf("%g ", (double)(F_arr[(int)(12)])); printf("%g ", (double)(G_arr[(int)(12)])); printf("\n");
    /* BASIC: 1880 GOTO 1710 */
line_1880:;
    goto line_1710;
    /* BASIC: 1890 C=0 */
line_1890:;
    C = 0;
    /* BASIC: 1900 PRINT "DO YOU WANT TO SEE MY SHOTS"; */
line_1900:;
    printf("%s", "DO YOU WANT TO SEE MY SHOTS");
    /* BASIC: 1910 INPUT K$ */
line_1910:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", K_str);
    /* BASIC: 1920 PRINT */
line_1920:;
    printf("\n");
    /* BASIC: 1930 IF J$<>"YES" THEN 2620 */
line_1930:;
    if (strcmp(J_str, "YES") != 0) { goto line_2620; }
    /* BASIC: 1940 REM*******************START */
line_1940:;
    /* REM*******************START */
    /* BASIC: 1950 IF J$<>"YES" THEN 1990 */
line_1950:;
    if (strcmp(J_str, "YES") != 0) { goto line_1990; }
    /* BASIC: 1960 C=C+1 */
line_1960:;
    C = C+1;
    /* BASIC: 1970 PRINT */
line_1970:;
    printf("\n");
    /* BASIC: 1980 PRINT "TURN";C */
line_1980:;
    printf("%s", "TURN"); printf("%g ", (double)(C)); printf("\n");
    /* BASIC: 1990 A=0 */
line_1990:;
    A = 0;
    /* BASIC: 2000 FOR W=.5 TO 3 STEP .5 */
line_2000:;
    W = .5; for_loop_W_2000: if (((.5) >= 0 && W > (3)) || ((.5) < 0 && W < (3))) goto end_for_W_2000;
    /* BASIC: 2010 FOR X=1 TO 10 */
line_2010:;
    X = 1; for_loop_X_2010: if (((1) >= 0 && X > (10)) || ((1) < 0 && X < (10))) goto end_for_X_2010;
    /* BASIC: 2020 FOR Y=1 TO 10 */
line_2020:;
    Y = 1; for_loop_Y_2020: if (((1) >= 0 && Y > (10)) || ((1) < 0 && Y < (10))) goto end_for_Y_2020;
    /* BASIC: 2030 IF B(X,Y)=W THEN 2070 */
line_2030:;
    if (B_arr[(int)(X) * 100 + (int)(Y)]==W) { goto line_2070; }
    /* BASIC: 2040 NEXT Y */
line_2040:;
    Y += (1); goto for_loop_Y_2020; end_for_Y_2020:;
    /* BASIC: 2050 NEXT X */
line_2050:;
    X += (1); goto for_loop_X_2010; end_for_X_2010:;
    /* BASIC: 2060 GOTO 2080 */
line_2060:;
    goto line_2080;
    /* BASIC: 2070 A=A+INT(W+.5) */
line_2070:;
    A = A+floor(W+.5);
    /* BASIC: 2080 NEXT W */
line_2080:;
    W += (.5); goto for_loop_W_2000; end_for_W_2000:;
    /* BASIC: 2090 FOR W=1 TO 7 */
line_2090:;
    W = 1; for_loop_W_2090: if (((1) >= 0 && W > (7)) || ((1) < 0 && W < (7))) goto end_for_W_2090;
    /* BASIC: 2100 C(W)=0 */
line_2100:;
    C_arr[(int)(W)] = 0;
    /* BASIC: 2110 D(W)=0 */
line_2110:;
    D_arr[(int)(W)] = 0;
    /* BASIC: 2120 F(W)=0 */
line_2120:;
    F_arr[(int)(W)] = 0;
    /* BASIC: 2130 G(W)=0 */
line_2130:;
    G_arr[(int)(W)] = 0;
    /* BASIC: 2140 NEXT W */
line_2140:;
    W += (1); goto for_loop_W_2090; end_for_W_2090:;
    /* BASIC: 2150 P3=0 */
line_2150:;
    P3 = 0;
    /* BASIC: 2160 FOR X=1 TO 10 */
line_2160:;
    X = 1; for_loop_X_2160: if (((1) >= 0 && X > (10)) || ((1) < 0 && X < (10))) goto end_for_X_2160;
    /* BASIC: 2170 FOR Y=1 TO 10 */
line_2170:;
    Y = 1; for_loop_Y_2170: if (((1) >= 0 && Y > (10)) || ((1) < 0 && Y < (10))) goto end_for_Y_2170;
    /* BASIC: 2180 IF A(X,Y)>10 THEN 2200 */
line_2180:;
    if (A_arr[(int)(X) * 100 + (int)(Y)]>10) { goto line_2200; }
    /* BASIC: 2190 P3=P3+1 */
line_2190:;
    P3 = P3+1;
    /* BASIC: 2200 NEXT Y */
line_2200:;
    Y += (1); goto for_loop_Y_2170; end_for_Y_2170:;
    /* BASIC: 2210 NEXT X */
line_2210:;
    X += (1); goto for_loop_X_2160; end_for_X_2160:;
    /* BASIC: 2220 PRINT "YOU HAVE";A;"SHOTS." */
line_2220:;
    printf("%s", "YOU HAVE"); printf("%g ", (double)(A)); printf("%s", "SHOTS."); printf("\n");
    /* BASIC: 2230 IF P3>=A THEN 2260 */
line_2230:;
    if (P3>=A) { goto line_2260; }
    /* BASIC: 2240 PRINT "YOU HAVE MORE SHOTS THAN THERE ARE BLANK SQUARES." */
line_2240:;
    printf("%s", "YOU HAVE MORE SHOTS THAN THERE ARE BLANK SQUARES."); printf("\n");
    /* BASIC: 2250 GOTO 2890 */
line_2250:;
    goto line_2890;
    /* BASIC: 2260 IF A<>0 THEN 2290 */
line_2260:;
    if (A!=0) { goto line_2290; }
    /* BASIC: 2270 PRINT "I HAVE WON." */
line_2270:;
    printf("%s", "I HAVE WON."); printf("\n");
    /* BASIC: 2280 S TO P */
line_2280:;
    /* UNTRANSLATED: S TO P */
    /* BASIC: 2290 FOR W=1 TO A */
line_2290:;
    W = 1; for_loop_W_2290: if (((1) >= 0 && W > (A)) || ((1) < 0 && W < (A))) goto end_for_W_2290;
    /* BASIC: 2300 INPUT X,Y */
line_2300:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf", &X, &Y);
    /* BASIC: 2310 IF X<>INT(X) THEN 2370 */
line_2310:;
    if (X!=floor(X)) { goto line_2370; }
    /* BASIC: 2320 IF X>10 THEN 2370 */
line_2320:;
    if (X>10) { goto line_2370; }
    /* BASIC: 2330 IF X<1 THEN 2370 */
line_2330:;
    if (X<1) { goto line_2370; }
    /* BASIC: 2340 IF Y<>INT(Y) THEN 2370 */
line_2340:;
    if (Y!=floor(Y)) { goto line_2370; }
    /* BASIC: 2350 IF Y>10 THEN 2370 */
line_2350:;
    if (Y>10) { goto line_2370; }
    /* BASIC: 2360 IF Y>=1 THEN 2390 */
line_2360:;
    if (Y>=1) { goto line_2390; }
    /* BASIC: 2370 PRINT "ILLEGAL, ENTER AGAIN." */
line_2370:;
    printf("%s", "ILLEGAL, ENTER AGAIN."); printf("\n");
    /* BASIC: 2380 GOTO 2300 */
line_2380:;
    goto line_2300;
    /* BASIC: 2390 IF A(X,Y)>10 THEN 2440 */
line_2390:;
    if (A_arr[(int)(X) * 100 + (int)(Y)]>10) { goto line_2440; }
    /* BASIC: 2400 C(W)=X */
line_2400:;
    C_arr[(int)(W)] = X;
    /* BASIC: 2410 D(W)=Y */
line_2410:;
    D_arr[(int)(W)] = Y;
    /* BASIC: 2420 NEXT W */
line_2420:;
    W += (1); goto for_loop_W_2290; end_for_W_2290:;
    /* BASIC: 2430 GOTO 2460 */
line_2430:;
    goto line_2460;
    /* BASIC: 2440 PRINT "YOU SHOT THERE BEFORE ON TURN";A(X,Y)-10 */
line_2440:;
    printf("%s", "YOU SHOT THERE BEFORE ON TURN"); printf("%g ", (double)(A_arr[(int)(X) * 100 + (int)(Y)]-10)); printf("\n");
    /* BASIC: 2450 GOTO 2300 */
line_2450:;
    goto line_2300;
    /* BASIC: 2460 FOR W=1 TO A */
line_2460:;
    W = 1; for_loop_W_2460: if (((1) >= 0 && W > (A)) || ((1) < 0 && W < (A))) goto end_for_W_2460;
    /* BASIC: 2470 IF A(C(W),D(W))=3 THEN 2540 */
line_2470:;
    if (A_arr[(int)(C_arr[(int)(W)]) * 100 + (int)(D_arr[(int)(W)])]==3) { goto line_2540; }
    /* BASIC: 2480 IF A(C(W),D(W))=2 THEN 2560 */
line_2480:;
    if (A_arr[(int)(C_arr[(int)(W)]) * 100 + (int)(D_arr[(int)(W)])]==2) { goto line_2560; }
    /* BASIC: 2490 IF A(C(W),D(W))=1 THEN 2580 */
line_2490:;
    if (A_arr[(int)(C_arr[(int)(W)]) * 100 + (int)(D_arr[(int)(W)])]==1) { goto line_2580; }
    /* BASIC: 2500 IF A(C(W),D(W))=.5 THEN 2600 */
line_2500:;
    if (A_arr[(int)(C_arr[(int)(W)]) * 100 + (int)(D_arr[(int)(W)])]==.5) { goto line_2600; }
    /* BASIC: 2510 A(C(W),D(W))=10+C */
line_2510:;
    A_arr[(int)(C_arr[(int)(W)]) * 100 + (int)(D_arr[(int)(W)])] = 10+C;
    /* BASIC: 2520 NEXT W */
line_2520:;
    W += (1); goto for_loop_W_2460; end_for_W_2460:;
    /* BASIC: 2530 GOTO 2620 */
line_2530:;
    goto line_2620;
    /* BASIC: 2540 PRINT "YOU HIT MY BATTLESHIP." */
line_2540:;
    printf("%s", "YOU HIT MY BATTLESHIP."); printf("\n");
    /* BASIC: 2550 GOTO 2510 */
line_2550:;
    goto line_2510;
    /* BASIC: 2560 PRINT "YOU HIT MY CRUISER." */
line_2560:;
    printf("%s", "YOU HIT MY CRUISER."); printf("\n");
    /* BASIC: 2570 GOTO 2510 */
line_2570:;
    goto line_2510;
    /* BASIC: 2580 PRINT "YOU HIT MY DESTROYER<A>." */
line_2580:;
    printf("%s", "YOU HIT MY DESTROYER<A>."); printf("\n");
    /* BASIC: 2590 GOTO 2510 */
line_2590:;
    goto line_2510;
    /* BASIC: 2600 PRINT "YOU HIT MY DESTROYER<B>." */
line_2600:;
    printf("%s", "YOU HIT MY DESTROYER<B>."); printf("\n");
    /* BASIC: 2610 GOTO 2510 */
line_2610:;
    goto line_2510;
    /* BASIC: 2620 A=0 */
line_2620:;
    A = 0;
    /* BASIC: 2630 IF J$="YES" THEN 2670 */
line_2630:;
    if (strcmp(J_str, "YES") == 0) { goto line_2670; }
    /* BASIC: 2640 C=C+1 */
line_2640:;
    C = C+1;
    /* BASIC: 2650 PRINT */
line_2650:;
    printf("\n");
    /* BASIC: 2660 PRINT "TURN";C */
line_2660:;
    printf("%s", "TURN"); printf("%g ", (double)(C)); printf("\n");
    /* BASIC: 2670 A=0 */
line_2670:;
    A = 0;
    /* BASIC: 2680 FOR W=.5 TO 3 STEP .5 */
line_2680:;
    W = .5; for_loop_W_2680: if (((.5) >= 0 && W > (3)) || ((.5) < 0 && W < (3))) goto end_for_W_2680;
    /* BASIC: 2690 FOR X=1 TO 10 */
line_2690:;
    X = 1; for_loop_X_2690: if (((1) >= 0 && X > (10)) || ((1) < 0 && X < (10))) goto end_for_X_2690;
    /* BASIC: 2700 FOR Y=1 TO 10 */
line_2700:;
    Y = 1; for_loop_Y_2700: if (((1) >= 0 && Y > (10)) || ((1) < 0 && Y < (10))) goto end_for_Y_2700;
    /* BASIC: 2710 IF A(X,Y)=W THEN 2750 */
line_2710:;
    if (A_arr[(int)(X) * 100 + (int)(Y)]==W) { goto line_2750; }
    /* BASIC: 2720 NEXT Y */
line_2720:;
    Y += (1); goto for_loop_Y_2700; end_for_Y_2700:;
    /* BASIC: 2730 NEXT X */
line_2730:;
    X += (1); goto for_loop_X_2690; end_for_X_2690:;
    /* BASIC: 2740 GOTO 2760 */
line_2740:;
    goto line_2760;
    /* BASIC: 2750 A=A+INT(W+.5) */
line_2750:;
    A = A+floor(W+.5);
    /* BASIC: 2760 NEXT W */
line_2760:;
    W += (.5); goto for_loop_W_2680; end_for_W_2680:;
    /* BASIC: 2770 P3=0 */
line_2770:;
    P3 = 0;
    /* BASIC: 2780 FOR X=1 TO 10 */
line_2780:;
    X = 1; for_loop_X_2780: if (((1) >= 0 && X > (10)) || ((1) < 0 && X < (10))) goto end_for_X_2780;
    /* BASIC: 2790 FOR Y=1 TO 10 */
line_2790:;
    Y = 1; for_loop_Y_2790: if (((1) >= 0 && Y > (10)) || ((1) < 0 && Y < (10))) goto end_for_Y_2790;
    /* BASIC: 2800 IF A(X,Y)>10 THEN 2820 */
line_2800:;
    if (A_arr[(int)(X) * 100 + (int)(Y)]>10) { goto line_2820; }
    /* BASIC: 2810 P3=P3+1 */
line_2810:;
    P3 = P3+1;
    /* BASIC: 2820 NEXT Y */
line_2820:;
    Y += (1); goto for_loop_Y_2790; end_for_Y_2790:;
    /* BASIC: 2830 NEXT X */
line_2830:;
    X += (1); goto for_loop_X_2780; end_for_X_2780:;
    /* BASIC: 2840 PRINT "I HAVE";A;"SHOTS." */
line_2840:;
    printf("%s", "I HAVE"); printf("%g ", (double)(A)); printf("%s", "SHOTS."); printf("\n");
    /* BASIC: 2850 IF P3>A THEN 2880 */
line_2850:;
    if (P3>A) { goto line_2880; }
    /* BASIC: 2860 PRINT "I HAVE MORE SHOTS THAN BLANK SQUARES." */
line_2860:;
    printf("%s", "I HAVE MORE SHOTS THAN BLANK SQUARES."); printf("\n");
    /* BASIC: 2870 GOTO 2270 */
line_2870:;
    goto line_2270;
    /* BASIC: 2880 IF A<>0 THEN 2960 */
line_2880:;
    if (A!=0) { goto line_2960; }
    /* BASIC: 2890 PRINT "YOU HAVE WON." */
line_2890:;
    printf("%s", "YOU HAVE WON."); printf("\n");
    /* BASIC: 2900 S TO P */
line_2900:;
    /* UNTRANSLATED: S TO P */
    /* BASIC: 2910 X=INT(RND(1)*10+1) */
line_2910:;
    X = floor(((double)rand() / (double)RAND_MAX)*10+1);
    /* BASIC: 2920 Y=INT(RND(1)*10+1) */
line_2920:;
    Y = floor(((double)rand() / (double)RAND_MAX)*10+1);
    /* BASIC: 2930 V=INT(3*RND(1)-1) */
line_2930:;
    V = floor(3*((double)rand() / (double)RAND_MAX)-1);
    /* BASIC: 2940 V2=INT(3*RND(1)-1) */
line_2940:;
    V2 = floor(3*((double)rand() / (double)RAND_MAX)-1);
    /* BASIC: 2950 RETURN */
line_2950:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 2960 FOR W=1 TO 12 */
line_2960:;
    W = 1; for_loop_W_2960: if (((1) >= 0 && W > (12)) || ((1) < 0 && W < (12))) goto end_for_W_2960;
    /* BASIC: 2970 IF H(W)>0 THEN 3800 */
line_2970:;
    if (H_arr[(int)(W)]>0) { goto line_3800; }
    /* BASIC: 2980 NEXT W */
line_2980:;
    W += (1); goto for_loop_W_2960; end_for_W_2960:;
    /* BASIC: 2990 REM*******************R AND OM */
line_2990:;
    /* REM*******************R AND OM */
    /* BASIC: 3000 W=0 */
line_3000:;
    W = 0;
    /* BASIC: 3010 R3=0 */
line_3010:;
    R3 = 0;
    /* BASIC: 3020 GOSUB 2910 */
line_3020:;
    gosub_stack[gosub_sp++] = 2; goto line_2910; line_ret_2:;
    /* BASIC: 3030 RESTORE */
line_3030:;
    data_ptr = 0;
    /* BASIC: 3040 R2=0 */
line_3040:;
    R2 = 0;
    /* BASIC: 3050 R3=R3+1 */
line_3050:;
    R3 = R3+1;
    /* BASIC: 3060 IF R3>100 THEN 3010 */
line_3060:;
    if (R3>100) { goto line_3010; }
    /* BASIC: 3070 IF X>10 THEN 3110 */
line_3070:;
    if (X>10) { goto line_3110; }
    /* BASIC: 3080 IF X>0 THEN 3120 */
line_3080:;
    if (X>0) { goto line_3120; }
    /* BASIC: 3090 X=1+INT(RND(1)*2.5) */
line_3090:;
    X = 1+floor(((double)rand() / (double)RAND_MAX)*2.5);
    /* BASIC: 3100 GOTO 3120 */
line_3100:;
    goto line_3120;
    /* BASIC: 3110 X=10-INT(RND(1)*2.5) */
line_3110:;
    X = 10-floor(((double)rand() / (double)RAND_MAX)*2.5);
    /* BASIC: 3120 IF Y>10 THEN 3160 */
line_3120:;
    if (Y>10) { goto line_3160; }
    /* BASIC: 3130 IF Y>0 THEN 3270 */
line_3130:;
    if (Y>0) { goto line_3270; }
    /* BASIC: 3140 Y=1+INT(RND(1)*2.5) */
line_3140:;
    Y = 1+floor(((double)rand() / (double)RAND_MAX)*2.5);
    /* BASIC: 3150 GOTO 3270 */
line_3150:;
    goto line_3270;
    /* BASIC: 3160 Y=10-INT(RND(1)*2.5) */
line_3160:;
    Y = 10-floor(((double)rand() / (double)RAND_MAX)*2.5);
    /* BASIC: 3170 GOTO 3270 */
line_3170:;
    goto line_3270;
    /* BASIC: 3180 F(W)=X */
line_3180:;
    F_arr[(int)(W)] = X;
    /* BASIC: 3190 G(W)=Y */
line_3190:;
    G_arr[(int)(W)] = Y;
    /* BASIC: 3200 IF W=A THEN 3380 */
line_3200:;
    if (W==A) { goto line_3380; }
    /* BASIC: 3210 IF R2=6 THEN 3030 */
line_3210:;
    if (R2==6) { goto line_3030; }
    /* BASIC: 3220 READ X1,Y1 */
line_3220:;
    read_numeric(&X1); read_numeric(&Y1);
    /* BASIC: 3230 R2=R2+1 */
line_3230:;
    R2 = R2+1;
    /* BASIC: 3240 DATA 1,1,-1,1,1,-3,1,1,0,2,-1,1 */
line_3240:;
    /* UNTRANSLATED: DATA 1,1,-1,1,1,-3,1,1,0,2,-1,1 */
    /* BASIC: 3250 X=X+X1 */
line_3250:;
    X = X+X1;
    /* BASIC: 3260 Y=Y+Y1 */
line_3260:;
    Y = Y+Y1;
    /* BASIC: 3270 IF X>10 THEN 3210 */
line_3270:;
    if (X>10) { goto line_3210; }
    /* BASIC: 3280 IF X<1 THEN 3210 */
line_3280:;
    if (X<1) { goto line_3210; }
    /* BASIC: 3290 IF Y>10 THEN 3210 */
line_3290:;
    if (Y>10) { goto line_3210; }
    /* BASIC: 3300 IF Y<1 THEN 3210 */
line_3300:;
    if (Y<1) { goto line_3210; }
    /* BASIC: 3310 IF B(X,Y)>10 THEN 3210 */
line_3310:;
    if (B_arr[(int)(X) * 100 + (int)(Y)]>10) { goto line_3210; }
    /* BASIC: 3320 FOR Q9=1 TO W */
line_3320:;
    Q9 = 1; for_loop_Q9_3320: if (((1) >= 0 && Q9 > (W)) || ((1) < 0 && Q9 < (W))) goto end_for_Q9_3320;
    /* BASIC: 3330 IF F(Q9)<>X THEN 3350 */
line_3330:;
    if (F_arr[(int)(Q9)]!=X) { goto line_3350; }
    /* BASIC: 3340 IF G(Q9)=Y THEN 3210 */
line_3340:;
    if (G_arr[(int)(Q9)]==Y) { goto line_3210; }
    /* BASIC: 3350 NEXT Q9 */
line_3350:;
    Q9 += (1); goto for_loop_Q9_3320; end_for_Q9_3320:;
    /* BASIC: 3360 W=W+1 */
line_3360:;
    W = W+1;
    /* BASIC: 3370 GOTO 3180 */
line_3370:;
    goto line_3180;
    /* BASIC: 3380 IF K$<>"YES" THEN 3420 */
line_3380:;
    if (strcmp(K_str, "YES") != 0) { goto line_3420; }
    /* BASIC: 3390 FOR Z5=1 TO A */
line_3390:;
    Z5 = 1; for_loop_Z5_3390: if (((1) >= 0 && Z5 > (A)) || ((1) < 0 && Z5 < (A))) goto end_for_Z5_3390;
    /* BASIC: 3400 PRINT F(Z5);G(Z5) */
line_3400:;
    printf("%g ", (double)(F_arr[(int)(Z5)])); printf("%g ", (double)(G_arr[(int)(Z5)])); printf("\n");
    /* BASIC: 3410 NEXT Z5 */
line_3410:;
    Z5 += (1); goto for_loop_Z5_3390; end_for_Z5_3390:;
    /* BASIC: 3420 FOR W=1 TO A */
line_3420:;
    W = 1; for_loop_W_3420: if (((1) >= 0 && W > (A)) || ((1) < 0 && W < (A))) goto end_for_W_3420;
    /* BASIC: 3430 IF B(F(W),G(W))=3 THEN 3500 */
line_3430:;
    if (B_arr[(int)(F_arr[(int)(W)]) * 100 + (int)(G_arr[(int)(W)])]==3) { goto line_3500; }
    /* BASIC: 3440 IF B(F(W),G(W))=2 THEN 3520 */
line_3440:;
    if (B_arr[(int)(F_arr[(int)(W)]) * 100 + (int)(G_arr[(int)(W)])]==2) { goto line_3520; }
    /* BASIC: 3450 IF B(F(W),G(W))=1 THEN 3560 */
line_3450:;
    if (B_arr[(int)(F_arr[(int)(W)]) * 100 + (int)(G_arr[(int)(W)])]==1) { goto line_3560; }
    /* BASIC: 3460 IF B(F(W),G(W))=.5 THEN 3540 */
line_3460:;
    if (B_arr[(int)(F_arr[(int)(W)]) * 100 + (int)(G_arr[(int)(W)])]==.5) { goto line_3540; }
    /* BASIC: 3470 B(F(W),G(W))=10+C */
line_3470:;
    B_arr[(int)(F_arr[(int)(W)]) * 100 + (int)(G_arr[(int)(W)])] = 10+C;
    /* BASIC: 3480 NEXT W */
line_3480:;
    W += (1); goto for_loop_W_3420; end_for_W_3420:;
    /* BASIC: 3490 GOTO 1950 */
line_3490:;
    goto line_1950;
    /* BASIC: 3500 PRINT "I HIT YOUR BATTLESHIP" */
line_3500:;
    printf("%s", "I HIT YOUR BATTLESHIP"); printf("\n");
    /* BASIC: 3510 GOTO 3570 */
line_3510:;
    goto line_3570;
    /* BASIC: 3520 PRINT "I HIT YOUR CRUISER" */
line_3520:;
    printf("%s", "I HIT YOUR CRUISER"); printf("\n");
    /* BASIC: 3530 GOTO 3570 */
line_3530:;
    goto line_3570;
    /* BASIC: 3540 PRINT "I HIT YOUR DESTROYER<B>" */
line_3540:;
    printf("%s", "I HIT YOUR DESTROYER<B>"); printf("\n");
    /* BASIC: 3550 GOTO 3570 */
line_3550:;
    goto line_3570;
    /* BASIC: 3560 PRINT "I HIT YOUR DESTROYER<A>" */
line_3560:;
    printf("%s", "I HIT YOUR DESTROYER<A>"); printf("\n");
    /* BASIC: 3570 FOR Q=1 TO 12 */
line_3570:;
    Q = 1; for_loop_Q_3570: if (((1) >= 0 && Q > (12)) || ((1) < 0 && Q < (12))) goto end_for_Q_3570;
    /* BASIC: 3580 IF E(Q)<>-1 THEN 3730 */
line_3580:;
    if (E_arr[(int)(Q)]!=-1) { goto line_3730; }
    /* BASIC: 3590 E(Q)=10+C */
line_3590:;
    E_arr[(int)(Q)] = 10+C;
    /* BASIC: 3600 H(Q)=B(F(W),G(W)) */
line_3600:;
    H_arr[(int)(Q)] = B_arr[(int)(F_arr[(int)(W)]) * 100 + (int)(G_arr[(int)(W)])];
    /* BASIC: 3610 M3=0 */
line_3610:;
    M3 = 0;
    /* BASIC: 3620 FOR M2=1 TO 12 */
line_3620:;
    M2 = 1; for_loop_M2_3620: if (((1) >= 0 && M2 > (12)) || ((1) < 0 && M2 < (12))) goto end_for_M2_3620;
    /* BASIC: 3630 IF H(M2)<>H(Q) THEN 3650 */
line_3630:;
    if (H_arr[(int)(M2)]!=H_arr[(int)(Q)]) { goto line_3650; }
    /* BASIC: 3640 M3=M3+1 */
line_3640:;
    M3 = M3+1;
    /* BASIC: 3650 NEXT M2 */
line_3650:;
    M2 += (1); goto for_loop_M2_3620; end_for_M2_3620:;
    /* BASIC: 3660 IF M3<>INT(H(Q)+.5)+1+INT(INT(H(Q)+.5)/3) THEN 3470 */
line_3660:;
    if (M3!=floor(H_arr[(int)(Q)]+.5)+1+floor(floor(H_arr[(int)(Q)]+.5)/3)) { goto line_3470; }
    /* BASIC: 3670 FOR M2=1 TO 12 */
line_3670:;
    M2 = 1; for_loop_M2_3670: if (((1) >= 0 && M2 > (12)) || ((1) < 0 && M2 < (12))) goto end_for_M2_3670;
    /* BASIC: 3680 IF H(M2)<>H(Q) THEN 3710 */
line_3680:;
    if (H_arr[(int)(M2)]!=H_arr[(int)(Q)]) { goto line_3710; }
    /* BASIC: 3690 E(M2)=-1 */
line_3690:;
    E_arr[(int)(M2)] = -1;
    /* BASIC: 3700 H(M2)=-1 */
line_3700:;
    H_arr[(int)(M2)] = -1;
    /* BASIC: 3710 NEXT M2 */
line_3710:;
    M2 += (1); goto for_loop_M2_3670; end_for_M2_3670:;
    /* BASIC: 3720 GOTO 3470 */
line_3720:;
    goto line_3470;
    /* BASIC: 3730 NEXT Q */
line_3730:;
    Q += (1); goto for_loop_Q_3570; end_for_Q_3570:;
    /* BASIC: 3740 PRINT "PROGRAM ABORT:" */
line_3740:;
    printf("%s", "PROGRAM ABORT:"); printf("\n");
    /* BASIC: 3750 FOR Q=1 TO 12 */
line_3750:;
    Q = 1; for_loop_Q_3750: if (((1) >= 0 && Q > (12)) || ((1) < 0 && Q < (12))) goto end_for_Q_3750;
    /* BASIC: 3760 PRINT "E(";Q;") =";E(Q) */
line_3760:;
    printf("%s", "E("); printf("%g ", (double)(Q)); printf("%s", ") ="); printf("%g ", (double)(E_arr[(int)(Q)])); printf("\n");
    /* BASIC: 3770 PRINT "H(";Q;") =";H(Q) */
line_3770:;
    printf("%s", "H("); printf("%g ", (double)(Q)); printf("%s", ") ="); printf("%g ", (double)(H_arr[(int)(Q)])); printf("\n");
    /* BASIC: 3780 NEXT Q */
line_3780:;
    Q += (1); goto for_loop_Q_3750; end_for_Q_3750:;
    /* BASIC: 3790 S TO P */
line_3790:;
    /* UNTRANSLATED: S TO P */
    /* BASIC: 3800 REM************************USINGEARRAY */
line_3800:;
    /* REM************************USINGEARRAY */
    /* BASIC: 3810 FOR R=1 TO 10 */
line_3810:;
    R = 1; for_loop_R_3810: if (((1) >= 0 && R > (10)) || ((1) < 0 && R < (10))) goto end_for_R_3810;
    /* BASIC: 3820 FOR S=1 TO 10 */
line_3820:;
    S = 1; for_loop_S_3820: if (((1) >= 0 && S > (10)) || ((1) < 0 && S < (10))) goto end_for_S_3820;
    /* BASIC: 3830 K(R,S)=0 */
line_3830:;
    K_arr[(int)(R) * 100 + (int)(S)] = 0;
    /* BASIC: 3840 NEXT S */
line_3840:;
    S += (1); goto for_loop_S_3820; end_for_S_3820:;
    /* BASIC: 3850 NEXT R */
line_3850:;
    R += (1); goto for_loop_R_3810; end_for_R_3810:;
    /* BASIC: 3860 FOR U=1 TO 12 */
line_3860:;
    U = 1; for_loop_U_3860: if (((1) >= 0 && U > (12)) || ((1) < 0 && U < (12))) goto end_for_U_3860;
    /* BASIC: 3870 IF E(U)<10 THEN 4020 */
line_3870:;
    if (E_arr[(int)(U)]<10) { goto line_4020; }
    /* BASIC: 3880 FOR R=1 TO 10 */
line_3880:;
    R = 1; for_loop_R_3880: if (((1) >= 0 && R > (10)) || ((1) < 0 && R < (10))) goto end_for_R_3880;
    /* BASIC: 3890 FOR S=1 TO 10 */
line_3890:;
    S = 1; for_loop_S_3890: if (((1) >= 0 && S > (10)) || ((1) < 0 && S < (10))) goto end_for_S_3890;
    /* BASIC: 3900 IF B(R,S)<10 THEN 3930 */
line_3900:;
    if (B_arr[(int)(R) * 100 + (int)(S)]<10) { goto line_3930; }
    /* BASIC: 3910 K(R,S)=-10000000 */
line_3910:;
    K_arr[(int)(R) * 100 + (int)(S)] = -10000000;
    /* BASIC: 3920 GOTO 4000 */
line_3920:;
    goto line_4000;
    /* BASIC: 3930 FOR M=SGN(1-R) TO SGN(10-R) */
line_3930:;
    M = basic_SGN(1-R); for_loop_M_3930: if (((1) >= 0 && M > (basic_SGN(10-R))) || ((1) < 0 && M < (basic_SGN(10-R)))) goto end_for_M_3930;
    /* BASIC: 3940 FOR N=SGN(1-S) TO SGN(10-S) */
line_3940:;
    N = basic_SGN(1-S); for_loop_N_3940: if (((1) >= 0 && N > (basic_SGN(10-S))) || ((1) < 0 && N < (basic_SGN(10-S)))) goto end_for_N_3940;
    /* BASIC: 3950 IF N+M+N*M=0 THEN 3980 */
line_3950:;
    if (N+M+N*M==0) { goto line_3980; }
    /* BASIC: 3960 IF B(R+M,S+N)<>E(U) THEN 3980 */
line_3960:;
    if (B_arr[(int)(R+M) * 100 + (int)(S+N)]!=E_arr[(int)(U)]) { goto line_3980; }
    /* BASIC: 3970 K(R,S)=K(R,S)+E(U)-S*INT(H(U)+.5) */
line_3970:;
    K_arr[(int)(R) * 100 + (int)(S)] = K_arr[(int)(R) * 100 + (int)(S)]+E_arr[(int)(U)]-S*floor(H_arr[(int)(U)]+.5);
    /* BASIC: 3980 NEXT N */
line_3980:;
    N += (1); goto for_loop_N_3940; end_for_N_3940:;
    /* BASIC: 3990 NEXT M */
line_3990:;
    M += (1); goto for_loop_M_3930; end_for_M_3930:;
    /* BASIC: 4000 NEXT S */
line_4000:;
    S += (1); goto for_loop_S_3890; end_for_S_3890:;
    /* BASIC: 4010 NEXT R */
line_4010:;
    R += (1); goto for_loop_R_3880; end_for_R_3880:;
    /* BASIC: 4020 NEXT U */
line_4020:;
    U += (1); goto for_loop_U_3860; end_for_U_3860:;
    /* BASIC: 4030 FOR R=1 TO A */
line_4030:;
    R = 1; for_loop_R_4030: if (((1) >= 0 && R > (A)) || ((1) < 0 && R < (A))) goto end_for_R_4030;
    /* BASIC: 4040 F(R)=R */
line_4040:;
    F_arr[(int)(R)] = R;
    /* BASIC: 4050 G(R)=R */
line_4050:;
    G_arr[(int)(R)] = R;
    /* BASIC: 4060 NEXT R */
line_4060:;
    R += (1); goto for_loop_R_4030; end_for_R_4030:;
    /* BASIC: 4070 FOR R=1 TO 10 */
line_4070:;
    R = 1; for_loop_R_4070: if (((1) >= 0 && R > (10)) || ((1) < 0 && R < (10))) goto end_for_R_4070;
    /* BASIC: 4080 FOR S=1 TO 10 */
line_4080:;
    S = 1; for_loop_S_4080: if (((1) >= 0 && S > (10)) || ((1) < 0 && S < (10))) goto end_for_S_4080;
    /* BASIC: 4090 Q9=1 */
line_4090:;
    Q9 = 1;
    /* BASIC: 4100 FOR M=1 TO A */
line_4100:;
    M = 1; for_loop_M_4100: if (((1) >= 0 && M > (A)) || ((1) < 0 && M < (A))) goto end_for_M_4100;
    /* BASIC: 4110 IF K(F(M),G(M))>=K(F(Q9),G(Q9)) THEN 4130 */
line_4110:;
    if (K_arr[(int)(F_arr[(int)(M)]) * 100 + (int)(G_arr[(int)(M)])]>=K_arr[(int)(F_arr[(int)(Q9)]) * 100 + (int)(G_arr[(int)(Q9)])]) { goto line_4130; }
    /* BASIC: 4120 Q9=M */
line_4120:;
    Q9 = M;
    /* BASIC: 4130 NEXT M */
line_4130:;
    M += (1); goto for_loop_M_4100; end_for_M_4100:;
    /* BASIC: 4131 IF R>A THEN 4140 */
line_4131:;
    if (R>A) { goto line_4140; }
    /* BASIC: 4132 IF R=S THEN 4210 */
line_4132:;
    if (R==S) { goto line_4210; }
    /* BASIC: 4140 IF K(R,S)<K(F(Q9),G(Q9)) THEN 4210 */
line_4140:;
    if (K_arr[(int)(R) * 100 + (int)(S)]<K_arr[(int)(F_arr[(int)(Q9)]) * 100 + (int)(G_arr[(int)(Q9)])]) { goto line_4210; }
    /* BASIC: 4150 FOR M=1 TO A */
line_4150:;
    M = 1; for_loop_M_4150: if (((1) >= 0 && M > (A)) || ((1) < 0 && M < (A))) goto end_for_M_4150;
    /* BASIC: 4160 IF F(M)<>R THEN 4190 */
line_4160:;
    if (F_arr[(int)(M)]!=R) { goto line_4190; }
    /* BASIC: 4170 IF G(M)=S THEN 4210 */
line_4170:;
    if (G_arr[(int)(M)]==S) { goto line_4210; }
    /* BASIC: 4180 NEXT M */
line_4180:;
    M += (1); goto for_loop_M_4150; end_for_M_4150:;
    /* BASIC: 4190 F(Q9)=R */
line_4190:;
    F_arr[(int)(Q9)] = R;
    /* BASIC: 4200 G(Q9)=S */
line_4200:;
    G_arr[(int)(Q9)] = S;
    /* BASIC: 4210 NEXT S */
line_4210:;
    S += (1); goto for_loop_S_4080; end_for_S_4080:;
    /* BASIC: 4220 NEXT R */
line_4220:;
    R += (1); goto for_loop_R_4070; end_for_R_4070:;
    /* BASIC: 4230 GOTO 3380 */
line_4230:;
    goto line_3380;
    /* BASIC: 4240 END */
line_4240:;
    exit(0);

    return 0;
}
