/*
 * Transpiled from checkers.bas
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

typedef enum { DATA_NUM, DATA_STR } DataType;
typedef struct {
    DataType type;
    union {
        double num;
        const char *str;
    } u;
} DataItem;

static DataItem program_data[17] = {
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 15.0 } },
};
static int data_ptr = 0;

static void read_numeric(double *var) {
    if (data_ptr < sizeof(program_data)/sizeof(program_data[0])) {
        if (program_data[data_ptr].type == DATA_NUM) *var = program_data[data_ptr].u.num;
        else *var = atof(program_data[data_ptr].u.str);
        data_ptr++;
    }
}

static void read_string(char *var, size_t max_len) {
    if (data_ptr < sizeof(program_data)/sizeof(program_data[0])) {
        if (program_data[data_ptr].type == DATA_STR) strncpy(var, program_data[data_ptr].u.str, max_len - 1);
        else snprintf(var, max_len, "%g", program_data[data_ptr].u.num);
        var[max_len - 1] = '\0';
        data_ptr++;
    }
}

/* Global variables */
static int gosub_stack[256];
static int gosub_sp = 0;
static double A, A1, B, B1, C, E, G, H, I, J, L, M, Q, R, S, T, U, V, X, Y, Z;
static double R_arr[20000] = {0};
static double S_arr[20000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 5 PRINT TAB(32);"CHECKERS" */
line_5:;
    { int _t; for(_t=0; _t<32; _t++) printf(" "); } printf("%s", "CHECKERS"); printf("\n");
    /* BASIC: 10 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_10:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 15 PRINT:PRINT:PRINT */
line_15:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 20 PRINT "THIS IS THE GAME OF CHECKERS.  THE COMPUTER IS X," */
line_20:;
    printf("%s", "THIS IS THE GAME OF CHECKERS.  THE COMPUTER IS X,"); printf("\n");
    /* BASIC: 25 PRINT "AND YOU ARE O.  THE COMPUTER WILL MOVE FIRST." */
line_25:;
    printf("%s", "AND YOU ARE O.  THE COMPUTER WILL MOVE FIRST."); printf("\n");
    /* BASIC: 30 PRINT "SQUARES ARE REFERRED TO BY A COORDINATE SYSTEM." */
line_30:;
    printf("%s", "SQUARES ARE REFERRED TO BY A COORDINATE SYSTEM."); printf("\n");
    /* BASIC: 35 PRINT "(0,0) IS THE LOWER LEFT CORNER" */
line_35:;
    printf("%s", "(0,0) IS THE LOWER LEFT CORNER"); printf("\n");
    /* BASIC: 40 PRINT "(0,7) IS THE UPPER LEFT CORNER" */
line_40:;
    printf("%s", "(0,7) IS THE UPPER LEFT CORNER"); printf("\n");
    /* BASIC: 45 PRINT "(7,0) IS THE LOWER RIGHT CORNER" */
line_45:;
    printf("%s", "(7,0) IS THE LOWER RIGHT CORNER"); printf("\n");
    /* BASIC: 50 PRINT "(7,7) IS THE UPPER RIGHT CORNER" */
line_50:;
    printf("%s", "(7,7) IS THE UPPER RIGHT CORNER"); printf("\n");
    /* BASIC: 55 PRINT "THE COMPUTER WILL TYPE '+TO' WHEN YOU HAVE ANOTHER" */
line_55:;
    printf("%s", "THE COMPUTER WILL TYPE '+TO' WHEN YOU HAVE ANOTHER"); printf("\n");
    /* BASIC: 60 PRINT "JUMP.  TYPE TWO NEGATIVE NUMBERS IF YOU CANNOT JUMP." */
line_60:;
    printf("%s", "JUMP.  TYPE TWO NEGATIVE NUMBERS IF YOU CANNOT JUMP."); printf("\n");
    /* BASIC: 65 PRINT:PRINT:PRINT */
line_65:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 80 DIM R(4),S(7,7):G=-1:R(0)=-99 */
line_80:;
    /* DIM R(4),S(7,7) (handled statically) */
    G = -1;
    R_arr[(int)(0)] = -99;
    /* BASIC: 90 DATA 1,0,1,0,0,0,-1,0,0,1,0,0,0,-1,0,-1,15 */
line_90:;
    /* UNTRANSLATED: DATA 1,0,1,0,0,0,-1,0,0,1,0,0,0,-1,0,-1,15 */
    /* BASIC: 120 FOR X=0 TO 7:FOR Y=0 TO 7:READ J:IF J=15 THEN 180 */
line_120:;
    X = 0; for_loop_X_120: if (((1) >= 0 && X > (7)) || ((1) < 0 && X < (7))) goto end_for_X_120;
    Y = 0; for_loop_Y_120: if (((1) >= 0 && Y > (7)) || ((1) < 0 && Y < (7))) goto end_for_Y_120;
    read_numeric(&J);
    if (J==15) { goto line_180; }
    /* BASIC: 160 S(X,Y)=J:GOTO 200 */
line_160:;
    S_arr[(int)(X) * 100 + (int)(Y)] = J;
    goto line_200;
    /* BASIC: 180 RESTORE:READ S(X,Y) */
line_180:;
    data_ptr = 0;
    read_numeric(&(S_arr[(int)(X) * 100 + (int)(Y)]));
    /* BASIC: 200 NEXT Y,X */
line_200:;
    /* NEXT (unmatched) */
    /* BASIC: 230 FOR X=0 TO 7:FOR Y=0 TO 7:IF S(X,Y)>-1 THEN 350 */
line_230:;
    X = 0; for_loop_X_230: if (((1) >= 0 && X > (7)) || ((1) < 0 && X < (7))) goto end_for_X_230;
    Y = 0; for_loop_Y_230: if (((1) >= 0 && Y > (7)) || ((1) < 0 && Y < (7))) goto end_for_Y_230;
    if (S_arr[(int)(X) * 100 + (int)(Y)]>-1) { goto line_350; }
    /* BASIC: 310 IF S(X,Y)=-1 THEN FOR A=-1 TO 1 STEP 2:B=G:GOSUB 650:NEXT A */
line_310:;
    if (S_arr[(int)(X) * 100 + (int)(Y)]==-1) { A = -1; for_loop_A_310: if (((2) >= 0 && A > (1)) || ((2) < 0 && A < (1))) goto end_for_A_310; B = G; gosub_stack[gosub_sp++] = 1; goto line_650; line_ret_1:; A += (2); goto for_loop_A_310; end_for_A_310:; }
    /* BASIC: 330 IF S(X,Y)=-2 THEN FOR A=-1 TO 1 STEP 2:FOR B=-1 TO 1 STEP 2:GOSUB 650:NEXT B,A */
line_330:;
    if (S_arr[(int)(X) * 100 + (int)(Y)]==-2) { A = -1; for_loop_A_330: if (((2) >= 0 && A > (1)) || ((2) < 0 && A < (1))) goto end_for_A_330; B = -1; for_loop_B_330: if (((2) >= 0 && B > (1)) || ((2) < 0 && B < (1))) goto end_for_B_330; gosub_stack[gosub_sp++] = 2; goto line_650; line_ret_2:; /* NEXT (unmatched) */ }
    /* BASIC: 350 NEXT Y,X:GOTO 1140 */
line_350:;
    /* NEXT (unmatched) */
    goto line_1140;
    /* BASIC: 650 U=X+A:V=Y+B:IF U<0 OR U>7 OR V<0 OR V>7 THEN 870 */
line_650:;
    U = X+A;
    V = Y+B;
    if (U<0   ||   U>7   ||   V<0   ||   V>7) { goto line_870; }
    /* BASIC: 740 IF S(U,V)=0 THEN GOSUB 910:GOTO 870 */
line_740:;
    if (S_arr[(int)(U) * 100 + (int)(V)]==0) { gosub_stack[gosub_sp++] = 3; goto line_910; line_ret_3:; goto line_870; }
    /* BASIC: 770 IF S(U,V)<0 THEN 870 */
line_770:;
    if (S_arr[(int)(U) * 100 + (int)(V)]<0) { goto line_870; }
    /* BASIC: 790 U=U+A:V=V+B:IF U<0 OR V<0 OR U>7 OR V>7 THEN 870 */
line_790:;
    U = U+A;
    V = V+B;
    if (U<0   ||   V<0   ||   U>7   ||   V>7) { goto line_870; }
    /* BASIC: 850 IF S(U,V)=0 THEN GOSUB 910 */
line_850:;
    if (S_arr[(int)(U) * 100 + (int)(V)]==0) { gosub_stack[gosub_sp++] = 4; goto line_910; line_ret_4:; }
    /* BASIC: 870 RETURN */
line_870:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 910 IF V=0 AND S(X,Y)=-1 THEN Q=Q+2 */
line_910:;
    if (V==0   &&   S_arr[(int)(X) * 100 + (int)(Y)]==-1) { Q = Q+2; }
    /* BASIC: 920 IF ABS(Y-V)=2 THEN Q=Q+5 */
line_920:;
    if (fabs(Y-V)==2) { Q = Q+5; }
    /* BASIC: 960 IF Y=7 THEN Q=Q-2 */
line_960:;
    if (Y==7) { Q = Q-2; }
    /* BASIC: 980 IF U=0 OR U=7 THEN Q=Q+1 */
line_980:;
    if (U==0   ||   U==7) { Q = Q+1; }
    /* BASIC: 1030 FOR C=-1 TO 1 STEP 2:IF U+C<0 OR U+C>7 OR V+G<0 THEN 1080 */
line_1030:;
    C = -1; for_loop_C_1030: if (((2) >= 0 && C > (1)) || ((2) < 0 && C < (1))) goto end_for_C_1030;
    if (U+C<0   ||   U+C>7   ||   V+G<0) { goto line_1080; }
    /* BASIC: 1035 IF S(U+C,V+G)<0 THEN Q=Q+1:GOTO 1080 */
line_1035:;
    if (S_arr[(int)(U+C) * 100 + (int)(V+G)]<0) { Q = Q+1; goto line_1080; }
    /* BASIC: 1040 IF U-C<0 OR U-C>7 OR V-G>7 THEN 1080 */
line_1040:;
    if (U-C<0   ||   U-C>7   ||   V-G>7) { goto line_1080; }
    /* BASIC: 1045 IF S(U+C,V+G)>0 AND (S(U-C,V-G)=0 OR (U-C=X AND V-G=Y)) THEN Q=Q-2 */
line_1045:;
    if (S_arr[(int)(U+C) * 100 + (int)(V+G)]>0   &&   (S_arr[(int)(U-C) * 100 + (int)(V-G)]==0  ||  (U-C==X  &&  V-G==Y))) { Q = Q-2; }
    /* BASIC: 1080 NEXT C:IF Q>R(0) THEN R(0)=Q:R(1)=X:R(2)=Y:R(3)=U:R(4)=V */
line_1080:;
    C += (2); goto for_loop_C_1030; end_for_C_1030:;
    if (Q>R_arr[(int)(0)]) { R_arr[(int)(0)] = Q; }
    R_arr[(int)(1)] = X;
    R_arr[(int)(2)] = Y;
    R_arr[(int)(3)] = U;
    R_arr[(int)(4)] = V;
    /* BASIC: 1100 Q=0:RETURN */
line_1100:;
    Q = 0;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1140 IF R(0)=-99 THEN 1880 */
line_1140:;
    if (R_arr[(int)(0)]==-99) { goto line_1880; }
    /* BASIC: 1230 PRINT CHR$(30)"FROM"R(1);R(2)"TO"R(3);R(4);:R(0)=-99 */
line_1230:;
    printf("%s", basic_CHR(30)); printf("%s", "FROM"); printf("%g ", (double)(R_arr[(int)(1)])); printf("%g ", (double)(R_arr[(int)(2)])); printf("%s", "TO"); printf("%g ", (double)(R_arr[(int)(3)])); printf("%g ", (double)(R_arr[(int)(4)]));
    R_arr[(int)(0)] = -99;
    /* BASIC: 1240 IF R(4)=0 THEN S(R(3),R(4))=-2:GOTO 1420 */
line_1240:;
    if (R_arr[(int)(4)]==0) { S_arr[(int)(R_arr[(int)(3)]) * 100 + (int)(R_arr[(int)(4)])] = -2; goto line_1420; }
    /* BASIC: 1250 S(R(3),R(4))=S(R(1),R(2)) */
line_1250:;
    S_arr[(int)(R_arr[(int)(3)]) * 100 + (int)(R_arr[(int)(4)])] = S_arr[(int)(R_arr[(int)(1)]) * 100 + (int)(R_arr[(int)(2)])];
    /* BASIC: 1310 S(R(1),R(2))=0:IF ABS(R(1)-R(3))<>2 THEN 1420 */
line_1310:;
    S_arr[(int)(R_arr[(int)(1)]) * 100 + (int)(R_arr[(int)(2)])] = 0;
    if (fabs(R_arr[(int)(1)]-R_arr[(int)(3)])!=2) { goto line_1420; }
    /* BASIC: 1330 S((R(1)+R(3))/2,(R(2)+R(4))/2)=0 */
line_1330:;
    S_arr[(int)((R_arr[(int)(1)]+R_arr[(int)(3)])/2) * 100 + (int)((R_arr[(int)(2)]+R_arr[(int)(4)])/2)] = 0;
    /* BASIC: 1340 X=R(3):Y=R(4):IF S(X,Y)=-1 THEN B=-2:FOR A=-2 TO 2 STEP 4:GOSUB 1370 */
line_1340:;
    X = R_arr[(int)(3)];
    Y = R_arr[(int)(4)];
    if (S_arr[(int)(X) * 100 + (int)(Y)]==-1) { B = -2; }
    A = -2; for_loop_A_1340: if (((4) >= 0 && A > (2)) || ((4) < 0 && A < (2))) goto end_for_A_1340;
    gosub_stack[gosub_sp++] = 5; goto line_1370; line_ret_5:;
    /* BASIC: 1350 IF S(X,Y)=-2 THEN FOR A=-2 TO 2 STEP 4:FOR B=-2 TO 2 STEP 4:GOSUB 1370:NEXT B */
line_1350:;
    if (S_arr[(int)(X) * 100 + (int)(Y)]==-2) { A = -2; for_loop_A_1350: if (((4) >= 0 && A > (2)) || ((4) < 0 && A < (2))) goto end_for_A_1350; B = -2; for_loop_B_1350: if (((4) >= 0 && B > (2)) || ((4) < 0 && B < (2))) goto end_for_B_1350; gosub_stack[gosub_sp++] = 6; goto line_1370; line_ret_6:; B += (4); goto for_loop_B_1350; end_for_B_1350:; }
    /* BASIC: 1360 NEXT A:IF R(0)<>-99 THEN PRINT"TO"R(3);R(4);:R(0)=-99:GOTO 1240 */
line_1360:;
    A += (4); goto for_loop_A_1350; end_for_A_1350:;
    if (R_arr[(int)(0)]!=-99) { printf("%s", "TO"); printf("%g ", (double)(R_arr[(int)(3)])); printf("%g ", (double)(R_arr[(int)(4)])); }
    R_arr[(int)(0)] = -99;
    goto line_1240;
    /* BASIC: 1365 GOTO 1420 */
line_1365:;
    goto line_1420;
    /* BASIC: 1370 U=X+A:V=Y+B:IF U<0 OR U>7 OR V<0 OR V>7 THEN 1400 */
line_1370:;
    U = X+A;
    V = Y+B;
    if (U<0   ||   U>7   ||   V<0   ||   V>7) { goto line_1400; }
    /* BASIC: 1380 IF S(U,V)=0 AND S(X+A/2,Y+B/2)>0 THEN GOSUB 910 */
line_1380:;
    if (S_arr[(int)(U) * 100 + (int)(V)]==0   &&   S_arr[(int)(X+A/2) * 100 + (int)(Y+B/2)]>0) { gosub_stack[gosub_sp++] = 7; goto line_910; line_ret_7:; }
    /* BASIC: 1400 RETURN */
line_1400:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1420 PRINT:PRINT:PRINT:FOR Y=7 TO 0 STEP -1:FOR X=0 TO 7:I=5*X:PRINT TAB(I); */
line_1420:;
    printf("\n");
    printf("\n");
    printf("\n");
    Y = 7; for_loop_Y_1420: if (((-1) >= 0 && Y > (0)) || ((-1) < 0 && Y < (0))) goto end_for_Y_1420;
    X = 0; for_loop_X_1420: if (((1) >= 0 && X > (7)) || ((1) < 0 && X < (7))) goto end_for_X_1420;
    I = 5*X;
    { int _t; for(_t=0; _t<I; _t++) printf(" "); }
    /* BASIC: 1430 IF S(X,Y)=0 THEN PRINT"."; */
line_1430:;
    if (S_arr[(int)(X) * 100 + (int)(Y)]==0) { printf("%s", "."); }
    /* BASIC: 1470 IF S(X,Y)=1 THEN PRINT"O"; */
line_1470:;
    if (S_arr[(int)(X) * 100 + (int)(Y)]==1) { printf("%s", "O"); }
    /* BASIC: 1490 IF S(X,Y)=-1 THEN PRINT"X"; */
line_1490:;
    if (S_arr[(int)(X) * 100 + (int)(Y)]==-1) { printf("%s", "X"); }
    /* BASIC: 1510 IF S(X,Y)=-2 THEN PRINT"X*"; */
line_1510:;
    if (S_arr[(int)(X) * 100 + (int)(Y)]==-2) { printf("%s", "X*"); }
    /* BASIC: 1530 IF S(X,Y)=2 THEN PRINT"O*"; */
line_1530:;
    if (S_arr[(int)(X) * 100 + (int)(Y)]==2) { printf("%s", "O*"); }
    /* BASIC: 1550 NEXT X:PRINT" ":PRINT:NEXT Y:PRINT */
line_1550:;
    X += (1); goto for_loop_X_1420; end_for_X_1420:;
    printf("%s", " "); printf("\n");
    printf("\n");
    Y += (-1); goto for_loop_Y_1420; end_for_Y_1420:;
    printf("\n");
    /* BASIC: 1552 FOR L=0 TO 7 */
line_1552:;
    L = 0; for_loop_L_1552: if (((1) >= 0 && L > (7)) || ((1) < 0 && L < (7))) goto end_for_L_1552;
    /* BASIC: 1554 FOR M=0 TO 7 */
line_1554:;
    M = 0; for_loop_M_1554: if (((1) >= 0 && M > (7)) || ((1) < 0 && M < (7))) goto end_for_M_1554;
    /* BASIC: 1556 IF S(L,M)=1 OR S(L,M)=2 THEN Z=1 */
line_1556:;
    if (S_arr[(int)(L) * 100 + (int)(M)]==1   ||   S_arr[(int)(L) * 100 + (int)(M)]==2) { Z = 1; }
    /* BASIC: 1558 IF S(L,M)=-1 OR S(L,M)=-2 THEN T=1 */
line_1558:;
    if (S_arr[(int)(L) * 100 + (int)(M)]==-1   ||   S_arr[(int)(L) * 100 + (int)(M)]==-2) { T = 1; }
    /* BASIC: 1560 NEXT M */
line_1560:;
    M += (1); goto for_loop_M_1554; end_for_M_1554:;
    /* BASIC: 1562 NEXT L */
line_1562:;
    L += (1); goto for_loop_L_1552; end_for_L_1552:;
    /* BASIC: 1564 IF Z<>1 THEN 1885 */
line_1564:;
    if (Z!=1) { goto line_1885; }
    /* BASIC: 1566 IF T<>1 THEN 1880 */
line_1566:;
    if (T!=1) { goto line_1880; }
    /* BASIC: 1570 Z=0: T=0 */
line_1570:;
    Z = 0;
    T = 0;
    /* BASIC: 1590 INPUT "FROM";E,H:X=E:Y=H:IF S(X,Y)<=0 THEN 1590 */
line_1590:;
    printf("%s", "FROM"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf", &E, &H);
    X = E;
    Y = H;
    if (S_arr[(int)(X) * 100 + (int)(Y)]<=0) { goto line_1590; }
    /* BASIC: 1670 INPUT "TO";A,B:X=A:Y=B */
line_1670:;
    printf("%s", "TO"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf", &A, &B);
    X = A;
    Y = B;
    /* BASIC: 1680 IF S(X,Y)=0 AND ABS(A-E)<=2 AND ABS(A-E)=ABS(B-H) THEN 1700 */
line_1680:;
    if (S_arr[(int)(X) * 100 + (int)(Y)]==0   &&   fabs(A-E)<=2   &&   fabs(A-E)==fabs(B-H)) { goto line_1700; }
    /* BASIC: 1690 PRINT CHR$(7)CHR$(11);:GOTO 1670 */
line_1690:;
    printf("%s", basic_CHR(7)); printf("%s", basic_CHR(11));
    goto line_1670;
    /* BASIC: 1700 I=46 */
line_1700:;
    I = 46;
    /* BASIC: 1750 S(A,B)=S(E,H):S(E,H)=0:IF ABS(E-A)<>2 THEN 1810 */
line_1750:;
    S_arr[(int)(A) * 100 + (int)(B)] = S_arr[(int)(E) * 100 + (int)(H)];
    S_arr[(int)(E) * 100 + (int)(H)] = 0;
    if (fabs(E-A)!=2) { goto line_1810; }
    /* BASIC: 1800 S((E+A)/2,(H+B)/2)=0 */
line_1800:;
    S_arr[(int)((E+A)/2) * 100 + (int)((H+B)/2)] = 0;
    /* BASIC: 1802 INPUT "+TO";A1,B1:IF A1<0 THEN 1810 */
line_1802:;
    printf("%s", "+TO"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf", &A1, &B1);
    if (A1<0) { goto line_1810; }
    /* BASIC: 1804 IF S(A1,B1)<>0 OR ABS(A1-A)<>2 OR ABS(B1-B)<>2 THEN 1802 */
line_1804:;
    if (S_arr[(int)(A1) * 100 + (int)(B1)]!=0   ||   fabs(A1-A)!=2   ||   fabs(B1-B)!=2) { goto line_1802; }
    /* BASIC: 1806 E=A:H=B:A=A1:B=B1:I=I+15:GOTO 1750 */
line_1806:;
    E = A;
    H = B;
    A = A1;
    B = B1;
    I = I+15;
    goto line_1750;
    /* BASIC: 1810 IF B=7 THEN S(A,B)=2 */
line_1810:;
    if (B==7) { S_arr[(int)(A) * 100 + (int)(B)] = 2; }
    /* BASIC: 1830 GOTO 230 */
line_1830:;
    goto line_230;
    /* BASIC: 1880 PRINT: PRINT "YOU WIN.": END */
line_1880:;
    printf("\n");
    printf("%s", "YOU WIN."); printf("\n");
    exit(0);
    /* BASIC: 1885 PRINT: PRINT "I WIN.": END */
line_1885:;
    printf("\n");
    printf("%s", "I WIN."); printf("\n");
    exit(0);
    /* Undefined labels declared here to compile cleanly */
    end_for_A_1340:;
    end_for_A_330:;
    end_for_B_330:;
    end_for_X_120:;
    end_for_X_230:;
    end_for_Y_120:;
    end_for_Y_230:;

    return 0;
}
