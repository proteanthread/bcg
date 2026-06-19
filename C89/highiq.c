/*
 * Transpiled from highiq.bas
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

static DataItem program_data[33] = {
    { DATA_NUM, 13.0, NULL },
    { DATA_NUM, 14.0, NULL },
    { DATA_NUM, 15.0, NULL },
    { DATA_NUM, 22.0, NULL },
    { DATA_NUM, 23.0, NULL },
    { DATA_NUM, 24.0, NULL },
    { DATA_NUM, 29.0, NULL },
    { DATA_NUM, 30.0, NULL },
    { DATA_NUM, 31.0, NULL },
    { DATA_NUM, 32.0, NULL },
    { DATA_NUM, 33.0, NULL },
    { DATA_NUM, 34.0, NULL },
    { DATA_NUM, 35.0, NULL },
    { DATA_NUM, 38.0, NULL },
    { DATA_NUM, 39.0, NULL },
    { DATA_NUM, 40.0, NULL },
    { DATA_NUM, 41.0, NULL },
    { DATA_NUM, 42.0, NULL },
    { DATA_NUM, 43.0, NULL },
    { DATA_NUM, 44.0, NULL },
    { DATA_NUM, 47.0, NULL },
    { DATA_NUM, 48.0, NULL },
    { DATA_NUM, 49.0, NULL },
    { DATA_NUM, 50.0, NULL },
    { DATA_NUM, 51.0, NULL },
    { DATA_NUM, 52.0, NULL },
    { DATA_NUM, 53.0, NULL },
    { DATA_NUM, 58.0, NULL },
    { DATA_NUM, 59.0, NULL },
    { DATA_NUM, 60.0, NULL },
    { DATA_NUM, 67.0, NULL },
    { DATA_NUM, 68.0, NULL },
    { DATA_NUM, 69.0, NULL },
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
static double A, B, C, F, M, P, R, S, T, W, X, Y, Z;
static char A_str[256] = {0};
static double B_arr[2000] = {0};
static double T_arr[2000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 1 PRINT TAB(33);"H-I-Q" */
line_1:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "H-I-Q"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT:PRINT:PRINT */
line_3:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 4 DIM B(70),T(9,9) */
line_4:;
    /* DIM B(70),T(9,9) (handled statically) */
    /* BASIC: 5 PRINT "HERE IS THE BOARD:": PRINT */
line_5:;
    printf("%s", "HERE IS THE BOARD:"); printf("\n");
    printf("\n");
    /* BASIC: 6 PRINT "          !    !    !" */
line_6:;
    printf("%s", "          !    !    !"); printf("\n");
    /* BASIC: 7 PRINT "         13   14   15": PRINT */
line_7:;
    printf("%s", "         13   14   15"); printf("\n");
    printf("\n");
    /* BASIC: 8 PRINT "          !    !    !" */
line_8:;
    printf("%s", "          !    !    !"); printf("\n");
    /* BASIC: 9 PRINT "         22   23   24": PRINT */
line_9:;
    printf("%s", "         22   23   24"); printf("\n");
    printf("\n");
    /* BASIC: 10 PRINT "!    !    !    !    !    !    !" */
line_10:;
    printf("%s", "!    !    !    !    !    !    !"); printf("\n");
    /* BASIC: 11 PRINT "29   30   31   32   33   34   35": PRINT */
line_11:;
    printf("%s", "29   30   31   32   33   34   35"); printf("\n");
    printf("\n");
    /* BASIC: 12 PRINT "!    !    !    !    !    !    !" */
line_12:;
    printf("%s", "!    !    !    !    !    !    !"); printf("\n");
    /* BASIC: 13 PRINT "38   39   40   41   42   43   44": PRINT */
line_13:;
    printf("%s", "38   39   40   41   42   43   44"); printf("\n");
    printf("\n");
    /* BASIC: 14 PRINT "!    !    !    !    !    !    !" */
line_14:;
    printf("%s", "!    !    !    !    !    !    !"); printf("\n");
    /* BASIC: 15 PRINT "47   48   49   50   51   52   53": PRINT */
line_15:;
    printf("%s", "47   48   49   50   51   52   53"); printf("\n");
    printf("\n");
    /* BASIC: 16 PRINT "          !    !    !" */
line_16:;
    printf("%s", "          !    !    !"); printf("\n");
    /* BASIC: 17 PRINT "         58   59   60": PRINT */
line_17:;
    printf("%s", "         58   59   60"); printf("\n");
    printf("\n");
    /* BASIC: 18 PRINT "          !    !    !" */
line_18:;
    printf("%s", "          !    !    !"); printf("\n");
    /* BASIC: 19 PRINT "         67   68   69": PRINT */
line_19:;
    printf("%s", "         67   68   69"); printf("\n");
    printf("\n");
    /* BASIC: 20 PRINT "TO SAVE TYPING TIME, A COMPRESSED VERSION OF THE GAME BOARD" */
line_20:;
    printf("%s", "TO SAVE TYPING TIME, A COMPRESSED VERSION OF THE GAME BOARD"); printf("\n");
    /* BASIC: 22 PRINT "WILL BE USED DURING PLAY.  REFER TO THE ABOVE ONE FOR PEG" */
line_22:;
    printf("%s", "WILL BE USED DURING PLAY.  REFER TO THE ABOVE ONE FOR PEG"); printf("\n");
    /* BASIC: 24 PRINT "NUMBERS.  OK, LET'S BEGIN." */
line_24:;
    printf("%s", "NUMBERS.  OK, LET'S BEGIN."); printf("\n");
    /* BASIC: 28 REM *** SET UP BOARD */
line_28:;
    /* REM *** SET UP BOARD */
    /* BASIC: 29 FOR R=1 TO 9 */
line_29:;
    R = 1; for_loop_R_29: if (((1) >= 0 && R > (9)) || ((1) < 0 && R < (9))) goto end_for_R_29;
    /* BASIC: 30 FOR C=1 TO 9 */
line_30:;
    C = 1; for_loop_C_30: if (((1) >= 0 && C > (9)) || ((1) < 0 && C < (9))) goto end_for_C_30;
    /* BASIC: 31 IF (R-4)*(R-5)*(R-6)=0 THEN 40 */
line_31:;
    if ((R-4)*(R-5)*(R-6)==0) { goto line_40; }
    /* BASIC: 32 IF (C-4)*(C-5)*(C-6)=0 THEN 40 */
line_32:;
    if ((C-4)*(C-5)*(C-6)==0) { goto line_40; }
    /* BASIC: 35 T(R,C)=-5 */
line_35:;
    T_arr[(int)(R) * 100 + (int)(C)] = -5;
    /* BASIC: 36 GOTO 50 */
line_36:;
    goto line_50;
    /* BASIC: 40 IF (R-1)*(C-1)*(R-9)*(C-9)=0 THEN 35 */
line_40:;
    if ((R-1)*(C-1)*(R-9)*(C-9)==0) { goto line_35; }
    /* BASIC: 42 T(R,C)=5 */
line_42:;
    T_arr[(int)(R) * 100 + (int)(C)] = 5;
    /* BASIC: 50 NEXT C */
line_50:;
    C += (1); goto for_loop_C_30; end_for_C_30:;
    /* BASIC: 60 NEXT R */
line_60:;
    R += (1); goto for_loop_R_29; end_for_R_29:;
    /* BASIC: 65 T(5,5)=0: GOSUB 500 */
line_65:;
    T_arr[(int)(5) * 100 + (int)(5)] = 0;
    gosub_stack[gosub_sp++] = 1; goto line_500; line_ret_1:;
    /* BASIC: 70 REM *** INPUT MOVE AND CHECK ON LEGALITY */
line_70:;
    /* REM *** INPUT MOVE AND CHECK ON LEGALITY */
    /* BASIC: 75 FOR W=1 TO 33 */
line_75:;
    W = 1; for_loop_W_75: if (((1) >= 0 && W > (33)) || ((1) < 0 && W < (33))) goto end_for_W_75;
    /* BASIC: 77 READ M */
line_77:;
    read_numeric(&M);
    /* BASIC: 79 DATA 13,14,15,22,23,24,29,30,31,32,33,34,35,38,39,40,41 */
line_79:;
    /* UNTRANSLATED: DATA 13,14,15,22,23,24,29,30,31,32,33,34,35,38,39,40,41 */
    /* BASIC: 81 DATA 42,43,44,47,48,49,50,51,52,53,58,59,60,67,68,69 */
line_81:;
    /* UNTRANSLATED: DATA 42,43,44,47,48,49,50,51,52,53,58,59,60,67,68,69 */
    /* BASIC: 83 B(M)=-7: NEXT W */
line_83:;
    B_arr[(int)(M)] = -7;
    W += (1); goto for_loop_W_75; end_for_W_75:;
    /* BASIC: 86 B(41)=-3 */
line_86:;
    B_arr[(int)(41)] = -3;
    /* BASIC: 100 INPUT "MOVE WHICH PIECE";Z */
line_100:;
    printf("%s", "MOVE WHICH PIECE"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &Z);
    /* BASIC: 110 IF B(Z)=-7 THEN 140 */
line_110:;
    if (B_arr[(int)(Z)]==-7) { goto line_140; }
    /* BASIC: 120 PRINT "ILLEGAL MOVE, TRY AGAIN...": GOTO 100 */
line_120:;
    printf("%s", "ILLEGAL MOVE, TRY AGAIN..."); printf("\n");
    goto line_100;
    /* BASIC: 140 INPUT "TO WHERE";P */
line_140:;
    printf("%s", "TO WHERE"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &P);
    /* BASIC: 150 IF B(P)=0 THEN 120 */
line_150:;
    if (B_arr[(int)(P)]==0) { goto line_120; }
    /* BASIC: 153 IF B(P)=-7 THEN 120 */
line_153:;
    if (B_arr[(int)(P)]==-7) { goto line_120; }
    /* BASIC: 156 IF Z=P THEN 100 */
line_156:;
    if (Z==P) { goto line_100; }
    /* BASIC: 160 IF ((Z+P)/2)=INT((Z+P)/2) THEN 180 */
line_160:;
    if (((Z+P)/2)==floor((Z+P)/2)) { goto line_180; }
    /* BASIC: 170 GOTO 120 */
line_170:;
    goto line_120;
    /* BASIC: 180 IF (ABS(Z-P)-2)*(ABS(Z-P)-18)<>0 THEN 120 */
line_180:;
    if ((fabs(Z-P)-2)*(fabs(Z-P)-18)!=0) { goto line_120; }
    /* BASIC: 190 GOSUB 1000 */
line_190:;
    gosub_stack[gosub_sp++] = 2; goto line_1000; line_ret_2:;
    /* BASIC: 200 GOSUB 500 */
line_200:;
    gosub_stack[gosub_sp++] = 3; goto line_500; line_ret_3:;
    /* BASIC: 210 GOSUB 1500 */
line_210:;
    gosub_stack[gosub_sp++] = 4; goto line_1500; line_ret_4:;
    /* BASIC: 220 GOTO 100 */
line_220:;
    goto line_100;
    /* BASIC: 500 REM *** PRINT BOARD */
line_500:;
    /* REM *** PRINT BOARD */
    /* BASIC: 510 FOR X=1 TO 9 */
line_510:;
    X = 1; for_loop_X_510: if (((1) >= 0 && X > (9)) || ((1) < 0 && X < (9))) goto end_for_X_510;
    /* BASIC: 520 FOR Y=1 TO 9 */
line_520:;
    Y = 1; for_loop_Y_520: if (((1) >= 0 && Y > (9)) || ((1) < 0 && Y < (9))) goto end_for_Y_520;
    /* BASIC: 525 IF (X-1)*(X-9)*(Y-1)*(Y-9)=0 THEN 550 */
line_525:;
    if ((X-1)*(X-9)*(Y-1)*(Y-9)==0) { goto line_550; }
    /* BASIC: 530 IF (X-4)*(X-5)*(X-6)=0 THEN 570 */
line_530:;
    if ((X-4)*(X-5)*(X-6)==0) { goto line_570; }
    /* BASIC: 540 IF (Y-4)*(Y-5)*(Y-6)=0 THEN 570 */
line_540:;
    if ((Y-4)*(Y-5)*(Y-6)==0) { goto line_570; }
    /* BASIC: 550 REM */
line_550:;
    /* REM */
    /* BASIC: 560 GOTO 610 */
line_560:;
    goto line_610;
    /* BASIC: 570 IF T(X,Y)<>5 THEN 600 */
line_570:;
    if (T_arr[(int)(X) * 100 + (int)(Y)]!=5) { goto line_600; }
    /* BASIC: 580 PRINT TAB(Y*2);"!"; */
line_580:;
    { int _t; for(_t=0; _t<Y*2; _t++) printf(" "); } printf("%s", "!");
    /* BASIC: 590 GOTO 610 */
line_590:;
    goto line_610;
    /* BASIC: 600 PRINT TAB(Y*2);"O"; */
line_600:;
    { int _t; for(_t=0; _t<Y*2; _t++) printf(" "); } printf("%s", "O");
    /* BASIC: 610 REM */
line_610:;
    /* REM */
    /* BASIC: 615 NEXT Y */
line_615:;
    Y += (1); goto for_loop_Y_520; end_for_Y_520:;
    /* BASIC: 620 PRINT */
line_620:;
    printf("\n");
    /* BASIC: 630 NEXT X */
line_630:;
    X += (1); goto for_loop_X_510; end_for_X_510:;
    /* BASIC: 640 RETURN */
line_640:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1000 REM *** UPDATE BOARD */
line_1000:;
    /* REM *** UPDATE BOARD */
    /* BASIC: 1005 C=1: FOR X=1 TO 9 */
line_1005:;
    C = 1;
    X = 1; for_loop_X_1005: if (((1) >= 0 && X > (9)) || ((1) < 0 && X < (9))) goto end_for_X_1005;
    /* BASIC: 1020 FOR Y=1 TO 9 */
line_1020:;
    Y = 1; for_loop_Y_1020: if (((1) >= 0 && Y > (9)) || ((1) < 0 && Y < (9))) goto end_for_Y_1020;
    /* BASIC: 1030 IF C<>Z THEN 1220 */
line_1030:;
    if (C!=Z) { goto line_1220; }
    /* BASIC: 1040 IF C+2<>P THEN 1080 */
line_1040:;
    if (C+2!=P) { goto line_1080; }
    /* BASIC: 1045 IF T(X,Y+1)=0 THEN 120 */
line_1045:;
    if (T_arr[(int)(X) * 100 + (int)(Y+1)]==0) { goto line_120; }
    /* BASIC: 1050 T(X,Y+2)=5 */
line_1050:;
    T_arr[(int)(X) * 100 + (int)(Y+2)] = 5;
    /* BASIC: 1060 T(X,Y+1)=0: B(C+1)=-3 */
line_1060:;
    T_arr[(int)(X) * 100 + (int)(Y+1)] = 0;
    B_arr[(int)(C+1)] = -3;
    /* BASIC: 1070 GOTO 1200 */
line_1070:;
    goto line_1200;
    /* BASIC: 1080 IF C+18<>P THEN 1130 */
line_1080:;
    if (C+18!=P) { goto line_1130; }
    /* BASIC: 1085 IF T(X+1,Y)=0 THEN 120 */
line_1085:;
    if (T_arr[(int)(X+1) * 100 + (int)(Y)]==0) { goto line_120; }
    /* BASIC: 1090 T(X+2,Y)=5: T(X+1,Y)=0: B(C+9)=-3 */
line_1090:;
    T_arr[(int)(X+2) * 100 + (int)(Y)] = 5;
    T_arr[(int)(X+1) * 100 + (int)(Y)] = 0;
    B_arr[(int)(C+9)] = -3;
    /* BASIC: 1120 GOTO 1200 */
line_1120:;
    goto line_1200;
    /* BASIC: 1130 IF C-2<>P THEN 1170 */
line_1130:;
    if (C-2!=P) { goto line_1170; }
    /* BASIC: 1135 IF T(X,Y-1)=0 THEN 120 */
line_1135:;
    if (T_arr[(int)(X) * 100 + (int)(Y-1)]==0) { goto line_120; }
    /* BASIC: 1140 T(X,Y-2)=5: T(X,Y-1)=0: B(C-1)=-3 */
line_1140:;
    T_arr[(int)(X) * 100 + (int)(Y-2)] = 5;
    T_arr[(int)(X) * 100 + (int)(Y-1)] = 0;
    B_arr[(int)(C-1)] = -3;
    /* BASIC: 1160 GOTO 1200 */
line_1160:;
    goto line_1200;
    /* BASIC: 1170 IF C-18<>P THEN 1220 */
line_1170:;
    if (C-18!=P) { goto line_1220; }
    /* BASIC: 1175 IF T(X-1,Y)=0 THEN 120 */
line_1175:;
    if (T_arr[(int)(X-1) * 100 + (int)(Y)]==0) { goto line_120; }
    /* BASIC: 1180 T(X-2,Y)=5: T(X-1,Y)=0: B(C-9)=-3 */
line_1180:;
    T_arr[(int)(X-2) * 100 + (int)(Y)] = 5;
    T_arr[(int)(X-1) * 100 + (int)(Y)] = 0;
    B_arr[(int)(C-9)] = -3;
    /* BASIC: 1200 B(Z)=-3: B(P)=-7 */
line_1200:;
    B_arr[(int)(Z)] = -3;
    B_arr[(int)(P)] = -7;
    /* BASIC: 1210 T(X,Y)=0: GOTO 1240 */
line_1210:;
    T_arr[(int)(X) * 100 + (int)(Y)] = 0;
    goto line_1240;
    /* BASIC: 1220 C=C+1 */
line_1220:;
    C = C+1;
    /* BASIC: 1225 NEXT Y */
line_1225:;
    Y += (1); goto for_loop_Y_1020; end_for_Y_1020:;
    /* BASIC: 1230 NEXT X */
line_1230:;
    X += (1); goto for_loop_X_1005; end_for_X_1005:;
    /* BASIC: 1240 RETURN */
line_1240:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1500 REM*** CHECK IF GAME IS OVER */
line_1500:;
    /* REM*** CHECK IF GAME IS OVER */
    /* BASIC: 1505 F=0 */
line_1505:;
    F = 0;
    /* BASIC: 1510 FOR R=2 TO 8 */
line_1510:;
    R = 2; for_loop_R_1510: if (((1) >= 0 && R > (8)) || ((1) < 0 && R < (8))) goto end_for_R_1510;
    /* BASIC: 1520 FOR C=2 TO 8 */
line_1520:;
    C = 2; for_loop_C_1520: if (((1) >= 0 && C > (8)) || ((1) < 0 && C < (8))) goto end_for_C_1520;
    /* BASIC: 1530 IF T(R,C)<>5 THEN 1580 */
line_1530:;
    if (T_arr[(int)(R) * 100 + (int)(C)]!=5) { goto line_1580; }
    /* BASIC: 1535 F=F+1 */
line_1535:;
    F = F+1;
    /* BASIC: 1540 FOR A=R-1 TO R+1 */
line_1540:;
    A = R-1; for_loop_A_1540: if (((1) >= 0 && A > (R+1)) || ((1) < 0 && A < (R+1))) goto end_for_A_1540;
    /* BASIC: 1545 T=0 */
line_1545:;
    T = 0;
    /* BASIC: 1550 FOR B=C-1 TO C+1 */
line_1550:;
    B = C-1; for_loop_B_1550: if (((1) >= 0 && B > (C+1)) || ((1) < 0 && B < (C+1))) goto end_for_B_1550;
    /* BASIC: 1560 T=T+T(A,B) */
line_1560:;
    T = T+T_arr[(int)(A) * 100 + (int)(B)];
    /* BASIC: 1561 NEXT B */
line_1561:;
    B += (1); goto for_loop_B_1550; end_for_B_1550:;
    /* BASIC: 1564 IF T<>10 THEN 1567 */
line_1564:;
    if (T!=10) { goto line_1567; }
    /* BASIC: 1565 IF T(A,C)<>0 THEN 1630 */
line_1565:;
    if (T_arr[(int)(A) * 100 + (int)(C)]!=0) { goto line_1630; }
    /* BASIC: 1567 NEXT A */
line_1567:;
    A += (1); goto for_loop_A_1540; end_for_A_1540:;
    /* BASIC: 1568 FOR X=C-1 TO C+1 */
line_1568:;
    X = C-1; for_loop_X_1568: if (((1) >= 0 && X > (C+1)) || ((1) < 0 && X < (C+1))) goto end_for_X_1568;
    /* BASIC: 1569 T=0 */
line_1569:;
    T = 0;
    /* BASIC: 1570 FOR Y=R-1 TO R+1 */
line_1570:;
    Y = R-1; for_loop_Y_1570: if (((1) >= 0 && Y > (R+1)) || ((1) < 0 && Y < (R+1))) goto end_for_Y_1570;
    /* BASIC: 1571 T=T+T(Y,X) */
line_1571:;
    T = T+T_arr[(int)(Y) * 100 + (int)(X)];
    /* BASIC: 1572 NEXT Y */
line_1572:;
    Y += (1); goto for_loop_Y_1570; end_for_Y_1570:;
    /* BASIC: 1573 IF T<>10 THEN 1575 */
line_1573:;
    if (T!=10) { goto line_1575; }
    /* BASIC: 1574 IF T(R,X)<>0 THEN 1630 */
line_1574:;
    if (T_arr[(int)(R) * 100 + (int)(X)]!=0) { goto line_1630; }
    /* BASIC: 1575 NEXT X */
line_1575:;
    X += (1); goto for_loop_X_1568; end_for_X_1568:;
    /* BASIC: 1580 NEXT C */
line_1580:;
    C += (1); goto for_loop_C_1520; end_for_C_1520:;
    /* BASIC: 1590 NEXT R */
line_1590:;
    R += (1); goto for_loop_R_1510; end_for_R_1510:;
    /* BASIC: 1600 REM *** GAME IS OVER */
line_1600:;
    /* REM *** GAME IS OVER */
    /* BASIC: 1605 PRINT "THE GAME IS OVER." */
line_1605:;
    printf("%s", "THE GAME IS OVER."); printf("\n");
    /* BASIC: 1610 PRINT "YOU HAD";F;"PIECES REMAINING." */
line_1610:;
    printf("%s", "YOU HAD"); printf("%g ", (double)(F)); printf("%s", "PIECES REMAINING."); printf("\n");
    /* BASIC: 1611 IF F<>1 THEN 1615 */
line_1611:;
    if (F!=1) { goto line_1615; }
    /* BASIC: 1612 PRINT "BRAVO!  YOU MADE A PERFECT SCORE!" */
line_1612:;
    printf("%s", "BRAVO!  YOU MADE A PERFECT SCORE!"); printf("\n");
    /* BASIC: 1613 PRINT "SAVE THIS PAPER AS A RECORD OF YOUR ACCOMPLISHMENT!" */
line_1613:;
    printf("%s", "SAVE THIS PAPER AS A RECORD OF YOUR ACCOMPLISHMENT!"); printf("\n");
    /* BASIC: 1615 PRINT: INPUT "PLAY AGAIN (YES OR NO)";A$ */
line_1615:;
    printf("\n");
    printf("%s", "PLAY AGAIN (YES OR NO)"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    /* BASIC: 1617 IF A$="NO" THEN 2000 */
line_1617:;
    if (strcmp(A_str, "NO") == 0) { goto line_2000; }
    /* BASIC: 1618 RESTORE: GOTO 28 */
line_1618:;
    data_ptr = 0;
    goto line_28;
    /* BASIC: 1620 S TO P */
line_1620:;
    /* UNTRANSLATED: S TO P */
    /* BASIC: 1630 RETURN */
line_1630:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 2000 PRINT: PRINT "SO LONG FOR NOW.": PRINT */
line_2000:;
    printf("\n");
    printf("%s", "SO LONG FOR NOW."); printf("\n");
    printf("\n");
    /* BASIC: 2010 END */
line_2010:;
    exit(0);

    return 0;
}
