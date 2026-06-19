/*
 * Transpiled from lifefortwo.bas
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

static DataItem program_data[34] = {
    { DATA_NUM, 3.0, NULL },
    { DATA_NUM, 102.0, NULL },
    { DATA_NUM, 103.0, NULL },
    { DATA_NUM, 120.0, NULL },
    { DATA_NUM, 130.0, NULL },
    { DATA_NUM, 121.0, NULL },
    { DATA_NUM, 112.0, NULL },
    { DATA_NUM, 111.0, NULL },
    { DATA_NUM, 12.0, NULL },
    { DATA_NUM, 21.0, NULL },
    { DATA_NUM, 30.0, NULL },
    { DATA_NUM, 1020.0, NULL },
    { DATA_NUM, 1030.0, NULL },
    { DATA_NUM, 1011.0, NULL },
    { DATA_NUM, 1021.0, NULL },
    { DATA_NUM, 1003.0, NULL },
    { DATA_NUM, 1002.0, NULL },
    { DATA_NUM, 1012.0, NULL },
    { DATA_NUM, -1.0, NULL },
    { DATA_NUM, 0.0, NULL },
    { DATA_NUM, 1.0, NULL },
    { DATA_NUM, 0.0, NULL },
    { DATA_NUM, 0.0, NULL },
    { DATA_NUM, -1.0, NULL },
    { DATA_NUM, 0.0, NULL },
    { DATA_NUM, 1.0, NULL },
    { DATA_NUM, -1.0, NULL },
    { DATA_NUM, -1.0, NULL },
    { DATA_NUM, 1.0, NULL },
    { DATA_NUM, -1.0, NULL },
    { DATA_NUM, -1.0, NULL },
    { DATA_NUM, 1.0, NULL },
    { DATA_NUM, 1.0, NULL },
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
static double A, B, J, K, K1, M, M2, M3, N, O1, P1, X, Y;
static double A_arr[2000] = {0};
static double K_arr[2000] = {0};
static double N_arr[2000] = {0};
static double X_arr[2000] = {0};
static double Y_arr[2000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 2 PRINT TAB(33);"LIFE2" */
line_2:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "LIFE2"); printf("\n");
    /* BASIC: 4 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 6 PRINT: PRINT: PRINT */
line_6:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 7 DIM N(6,6),K(18),A(16),X(2),Y(2) */
line_7:;
    /* DIM N(6,6),K(18),A(16),X(2),Y(2) (handled statically) */
    /* BASIC: 8 DATA 3,102,103,120,130,121,112,111,12 */
line_8:;
    /* UNTRANSLATED: DATA 3,102,103,120,130,121,112,111,12 */
    /* BASIC: 9 DATA 21,30,1020,1030,1011,1021,1003,1002,1012 */
line_9:;
    /* UNTRANSLATED: DATA 21,30,1020,1030,1011,1021,1003,1002,1012 */
    /* BASIC: 10 FOR M=1 TO 18: READ K(M): NEXT M */
line_10:;
    M = 1; for_loop_M_10: if (((1) >= 0 && M > (18)) || ((1) < 0 && M < (18))) goto end_for_M_10;
    read_numeric(&(K_arr[(int)(M)]));
    M += (1); goto for_loop_M_10; end_for_M_10:;
    /* BASIC: 13 DATA -1,0,1,0,0,-1,0,1,-1,-1,1,-1,-1,1,1,1 */
line_13:;
    /* UNTRANSLATED: DATA -1,0,1,0,0,-1,0,1,-1,-1,1,-1,-1,1,1,1 */
    /* BASIC: 14 FOR O1= 1 TO 16: READ A(O1): NEXT O1 */
line_14:;
    O1 = 1; for_loop_O1_14: if (((1) >= 0 && O1 > (16)) || ((1) < 0 && O1 < (16))) goto end_for_O1_14;
    read_numeric(&(A_arr[(int)(O1)]));
    O1 += (1); goto for_loop_O1_14; end_for_O1_14:;
    /* BASIC: 20 GOTO 500 */
line_20:;
    goto line_500;
    /* BASIC: 50 FOR J=1 TO 5 */
line_50:;
    J = 1; for_loop_J_50: if (((1) >= 0 && J > (5)) || ((1) < 0 && J < (5))) goto end_for_J_50;
    /* BASIC: 51 FOR K=1 TO 5 */
line_51:;
    K = 1; for_loop_K_51: if (((1) >= 0 && K > (5)) || ((1) < 0 && K < (5))) goto end_for_K_51;
    /* BASIC: 55 IF N(J,K)>99 THEN GOSUB 200 */
line_55:;
    if (N_arr[(int)(J) * 100 + (int)(K)]>99) { gosub_stack[gosub_sp++] = 1; goto line_200; line_ret_1:; }
    /* BASIC: 60 NEXT K */
line_60:;
    K += (1); goto for_loop_K_51; end_for_K_51:;
    /* BASIC: 65 NEXT J */
line_65:;
    J += (1); goto for_loop_J_50; end_for_J_50:;
    /* BASIC: 90 K=0: M2=0: M3=0 */
line_90:;
    K = 0;
    M2 = 0;
    M3 = 0;
    /* BASIC: 99 FOR J=0 TO 6: PRINT */
line_99:;
    J = 0; for_loop_J_99: if (((1) >= 0 && J > (6)) || ((1) < 0 && J < (6))) goto end_for_J_99;
    printf("\n");
    /* BASIC: 100 FOR K=0 TO 6 */
line_100:;
    K = 0; for_loop_K_100: if (((1) >= 0 && K > (6)) || ((1) < 0 && K < (6))) goto end_for_K_100;
    /* BASIC: 101 IF J<>0 THEN IF J<>6 THEN 105 */
line_101:;
    if (J!=0) { if (J!=6) { goto line_105; } }
    /* BASIC: 102 IF K=6 THEN PRINT 0;: GOTO 125 */
line_102:;
    if (K==6) { printf("%g ", (double)(0)); goto line_125; }
    /* BASIC: 103 PRINT K;: GOTO 120 */
line_103:;
    printf("%g ", (double)(K));
    goto line_120;
    /* BASIC: 105 IF K<>0 THEN IF K<>6 THEN 110 */
line_105:;
    if (K!=0) { if (K!=6) { goto line_110; } }
    /* BASIC: 106 IF J=6 THEN PRINT 0: GOTO 126 */
line_106:;
    if (J==6) { printf("%g ", (double)(0)); printf("\n"); goto line_126; }
    /* BASIC: 107 PRINT J;: GOTO 120 */
line_107:;
    printf("%g ", (double)(J));
    goto line_120;
    /* BASIC: 110 GOSUB 300 */
line_110:;
    gosub_stack[gosub_sp++] = 2; goto line_300; line_ret_2:;
    /* BASIC: 120 NEXT K */
line_120:;
    K += (1); goto for_loop_K_100; end_for_K_100:;
    /* BASIC: 125 NEXT J */
line_125:;
    J += (1); goto for_loop_J_99; end_for_J_99:;
    /* BASIC: 126 RETURN */
line_126:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 200 B=1: IF N(J,K)>999 THEN B=10 */
line_200:;
    B = 1;
    if (N_arr[(int)(J) * 100 + (int)(K)]>999) { B = 10; }
    /* BASIC: 220 FOR O1= 1 TO 15 STEP 2 */
line_220:;
    O1 = 1; for_loop_O1_220: if (((2) >= 0 && O1 > (15)) || ((2) < 0 && O1 < (15))) goto end_for_O1_220;
    /* BASIC: 230 N(J+A(O1),K+A(O1+1))=N(J+A(O1),K+A(O1+1))+B */
line_230:;
    N_arr[(int)(J+A_arr[(int)(O1)]) * 100 + (int)(K+A_arr[(int)(O1+1)])] = N_arr[(int)(J+A_arr[(int)(O1)]) * 100 + (int)(K+A_arr[(int)(O1+1)])]+B;
    /* BASIC: 231 NEXT O1 */
line_231:;
    O1 += (2); goto for_loop_O1_220; end_for_O1_220:;
    /* BASIC: 239 RETURN */
line_239:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 300 IF N(J,K)<3 THEN 399 */
line_300:;
    if (N_arr[(int)(J) * 100 + (int)(K)]<3) { goto line_399; }
    /* BASIC: 305 FOR O1=1 TO 18 */
line_305:;
    O1 = 1; for_loop_O1_305: if (((1) >= 0 && O1 > (18)) || ((1) < 0 && O1 < (18))) goto end_for_O1_305;
    /* BASIC: 310 IF N(J,K)=K(O1) THEN 350 */
line_310:;
    if (N_arr[(int)(J) * 100 + (int)(K)]==K_arr[(int)(O1)]) { goto line_350; }
    /* BASIC: 315 NEXT O1 */
line_315:;
    O1 += (1); goto for_loop_O1_305; end_for_O1_305:;
    /* BASIC: 320 GOTO 399 */
line_320:;
    goto line_399;
    /* BASIC: 350 IF O1>9 THEN 360 */
line_350:;
    if (O1>9) { goto line_360; }
    /* BASIC: 351 N(J,K)=100: M2=M2+1: PRINT " * "; */
line_351:;
    N_arr[(int)(J) * 100 + (int)(K)] = 100;
    M2 = M2+1;
    printf("%s", " * ");
    /* BASIC: 355 RETURN */
line_355:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 360 N(J,K)=1000: M3=M3+1: PRINT " # "; */
line_360:;
    N_arr[(int)(J) * 100 + (int)(K)] = 1000;
    M3 = M3+1;
    printf("%s", " # ");
    /* BASIC: 365 RETURN */
line_365:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 399 N(J,K)=0: PRINT "   ";: RETURN */
line_399:;
    N_arr[(int)(J) * 100 + (int)(K)] = 0;
    printf("%s", "   ");
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 500 PRINT TAB(10);"U.B. LIFE GAME" */
line_500:;
    { int _t; for(_t=0; _t<10; _t++) printf(" "); } printf("%s", "U.B. LIFE GAME"); printf("\n");
    /* BASIC: 505 M2=0: M3=0 */
line_505:;
    M2 = 0;
    M3 = 0;
    /* BASIC: 510 FOR J=1 TO 5 */
line_510:;
    J = 1; for_loop_J_510: if (((1) >= 0 && J > (5)) || ((1) < 0 && J < (5))) goto end_for_J_510;
    /* BASIC: 511 FOR K=1 TO 5 */
line_511:;
    K = 1; for_loop_K_511: if (((1) >= 0 && K > (5)) || ((1) < 0 && K < (5))) goto end_for_K_511;
    /* BASIC: 515 N(J,K)=0 */
line_515:;
    N_arr[(int)(J) * 100 + (int)(K)] = 0;
    /* BASIC: 516 NEXT K */
line_516:;
    K += (1); goto for_loop_K_511; end_for_K_511:;
    /* BASIC: 517 NEXT J */
line_517:;
    J += (1); goto for_loop_J_510; end_for_J_510:;
    /* BASIC: 519 FOR B=1 TO 2: P1=3: IF B=2 THEN P1=30 */
line_519:;
    B = 1; for_loop_B_519: if (((1) >= 0 && B > (2)) || ((1) < 0 && B < (2))) goto end_for_B_519;
    P1 = 3;
    if (B==2) { P1 = 30; }
    /* BASIC: 520 PRINT:PRINT "PLAYER";B;" - 3 LIVE PIECES." */
line_520:;
    printf("\n");
    printf("%s", "PLAYER"); printf("%g ", (double)(B)); printf("%s", " - 3 LIVE PIECES."); printf("\n");
    /* BASIC: 535 FOR K1=1 TO 3: GOSUB 700 */
line_535:;
    K1 = 1; for_loop_K1_535: if (((1) >= 0 && K1 > (3)) || ((1) < 0 && K1 < (3))) goto end_for_K1_535;
    gosub_stack[gosub_sp++] = 3; goto line_700; line_ret_3:;
    /* BASIC: 540 N(X(B),Y(B))=P1: NEXT K1 */
line_540:;
    N_arr[(int)(X_arr[(int)(B)]) * 100 + (int)(Y_arr[(int)(B)])] = P1;
    K1 += (1); goto for_loop_K1_535; end_for_K1_535:;
    /* BASIC: 542 NEXT B */
line_542:;
    B += (1); goto for_loop_B_519; end_for_B_519:;
    /* BASIC: 559 GOSUB 90 */
line_559:;
    gosub_stack[gosub_sp++] = 4; goto line_90; line_ret_4:;
    /* BASIC: 560 PRINT: GOSUB 50 */
line_560:;
    printf("\n");
    gosub_stack[gosub_sp++] = 5; goto line_50; line_ret_5:;
    /* BASIC: 570 IF M2=0 THEN IF M3=0 THEN 574 */
line_570:;
    if (M2==0) { if (M3==0) { goto line_574; } }
    /* BASIC: 571 IF M3=0 THEN B=1: GOTO 575 */
line_571:;
    if (M3==0) { B = 1; goto line_575; }
    /* BASIC: 572 IF M2=0 THEN B=2: GOTO 575 */
line_572:;
    if (M2==0) { B = 2; goto line_575; }
    /* BASIC: 573 GOTO 580 */
line_573:;
    goto line_580;
    /* BASIC: 574 PRINT: PRINT "A DRAW":GOTO 800 */
line_574:;
    printf("\n");
    printf("%s", "A DRAW"); printf("\n");
    goto line_800;
    /* BASIC: 575 PRINT: PRINT "PLAYER";B;"IS THE WINNER":GOTO 800 */
line_575:;
    printf("\n");
    printf("%s", "PLAYER"); printf("%g ", (double)(B)); printf("%s", "IS THE WINNER"); printf("\n");
    goto line_800;
    /* BASIC: 580 FOR B=1 TO 2: PRINT: PRINT: PRINT "PLAYER";B;: GOSUB 700 */
line_580:;
    B = 1; for_loop_B_580: if (((1) >= 0 && B > (2)) || ((1) < 0 && B < (2))) goto end_for_B_580;
    printf("\n");
    printf("\n");
    printf("%s", "PLAYER"); printf("%g ", (double)(B));
    gosub_stack[gosub_sp++] = 6; goto line_700; line_ret_6:;
    /* BASIC: 581 IF B=99 THEN 560 */
line_581:;
    if (B==99) { goto line_560; }
    /* BASIC: 582 NEXT B */
line_582:;
    B += (1); goto for_loop_B_580; end_for_B_580:;
    /* BASIC: 586 N(X(1),Y(1))=100: N(X(2),Y(2))=1000 */
line_586:;
    N_arr[(int)(X_arr[(int)(1)]) * 100 + (int)(Y_arr[(int)(1)])] = 100;
    N_arr[(int)(X_arr[(int)(2)]) * 100 + (int)(Y_arr[(int)(2)])] = 1000;
    /* BASIC: 596 GOTO 560 */
line_596:;
    goto line_560;
    /* BASIC: 700 PRINT "X,Y":PRINT"XXXXXX";CHR$(13);"$$$$$$";CHR$(13);"&&&&&&"; */
line_700:;
    printf("%s", "X,Y"); printf("\n");
    printf("%s", "XXXXXX"); printf("%s", basic_CHR(13)); printf("%s", "$$$$$$"); printf("%s", basic_CHR(13)); printf("%s", "&&&&&&");
    /* BASIC: 701 PRINT CHR$(13);: INPUT Y(B),X(B) */
line_701:;
    printf("%s", basic_CHR(13));
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf", &(Y_arr[(int)(B)]), &(X_arr[(int)(B)]));
    /* BASIC: 705 IF X(B)<=5 THEN IF X(B)>0 THEN 708 */
line_705:;
    if (X_arr[(int)(B)]<=5) { if (X_arr[(int)(B)]>0) { goto line_708; } }
    /* BASIC: 706 GOTO 750 */
line_706:;
    goto line_750;
    /* BASIC: 708 IF Y(B)<=5 THEN IF Y(B)>0 THEN 715 */
line_708:;
    if (Y_arr[(int)(B)]<=5) { if (Y_arr[(int)(B)]>0) { goto line_715; } }
    /* BASIC: 710 GOTO 750 */
line_710:;
    goto line_750;
    /* BASIC: 715 IF N(X(B),Y(B))<>0 THEN 750 */
line_715:;
    if (N_arr[(int)(X_arr[(int)(B)]) * 100 + (int)(Y_arr[(int)(B)])]!=0) { goto line_750; }
    /* BASIC: 720 IF B=1 THEN RETURN */
line_720:;
    if (B==1) { switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); } }
    /* BASIC: 725 IF X(1)=X(2) THEN IF Y(1)=Y(2) THEN 740 */
line_725:;
    if (X_arr[(int)(1)]==X_arr[(int)(2)]) { if (Y_arr[(int)(1)]==Y_arr[(int)(2)]) { goto line_740; } }
    /* BASIC: 730 RETURN */
line_730:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 740 PRINT "SAME COORD.  SET TO 0" */
line_740:;
    printf("%s", "SAME COORD.  SET TO 0"); printf("\n");
    /* BASIC: 741 N(X(B)+1,Y(B)+1)=0: B=99: RETURN */
line_741:;
    N_arr[(int)(X_arr[(int)(B)]+1) * 100 + (int)(Y_arr[(int)(B)]+1)] = 0;
    B = 99;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 750 PRINT "ILLEGAL COORDS. RETYPE": GOTO 700 */
line_750:;
    printf("%s", "ILLEGAL COORDS. RETYPE"); printf("\n");
    goto line_700;
    /* BASIC: 999 END */
line_999:;
    exit(0);
    /* Undefined labels declared here to compile cleanly */
    line_800:;

    return 0;
}
