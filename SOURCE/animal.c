/*
 * Transpiled from animal.bas
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

static DataItem program_data[4] = {
    { DATA_STR, { .str = "4" } },
    { DATA_STR, { .str = "\\QDOES IT SWIM\\Y2\\N3\\" } },
    { DATA_STR, { .str = "\\AFISH" } },
    { DATA_STR, { .str = "\\ABIRD" } },
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
static double I, K, N, P, S, X, Y, Z, Z1;
static char A_str[256] = {0};
static char B_str[256] = {0};
static char C_str[256] = {0};
static char Q_str[256] = {0};
static char T_str[256] = {0};
static char V_str[256] = {0};
static char X_str[256] = {0};
static char A_str_arr[20000][256] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(32);"ANIMAL" */
line_10:;
    { int _t; for(_t=0; _t<32; _t++) printf(" "); } printf("%s", "ANIMAL"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT: PRINT: PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 40 PRINT "PLAY 'GUESS THE ANIMAL'" */
line_40:;
    printf("%s", "PLAY 'GUESS THE ANIMAL'"); printf("\n");
    /* BASIC: 45 PRINT */
line_45:;
    printf("\n");
    /* BASIC: 50 PRINT "THINK OF AN ANIMAL AND THE COMPUTER WILL TRY TO GUESS IT." */
line_50:;
    printf("%s", "THINK OF AN ANIMAL AND THE COMPUTER WILL TRY TO GUESS IT."); printf("\n");
    /* BASIC: 60 PRINT */
line_60:;
    printf("\n");
    /* BASIC: 70 DIM A$(200) */
line_70:;
    /* DIM A$(200) (handled statically) */
    /* BASIC: 80 FOR I=0 TO 3 */
line_80:;
    I = 0; for_loop_I_80: if (((1) >= 0 && I > (3)) || ((1) < 0 && I < (3))) goto end_for_I_80;
    /* BASIC: 90 READ A$(I) */
line_90:;
    read_string(A_str_arr[(int)(I)], sizeof(A_str_arr[(int)(I)]));
    /* BASIC: 100 NEXT I */
line_100:;
    I += (1); goto for_loop_I_80; end_for_I_80:;
    /* BASIC: 110 N=VAL(A$(0)) */
line_110:;
    N = basic_VAL(A_str_arr[(int)(0)]);
    /* BASIC: 120 REM          MAIN CONTROL SECTION */
line_120:;
    // REM          MAIN CONTROL SECTION
    /* BASIC: 130 INPUT "ARE YOU THINKING OF AN ANIMAL";A$ */
line_130:;
    printf("%s", "ARE YOU THINKING OF AN ANIMAL"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    /* BASIC: 140 IF A$="LIST" THEN 600 */
line_140:;
    if (strcmp(A_str, "LIST") == 0) { goto line_600; }
    /* BASIC: 150 IF LEFT$(A$,1)<>"Y" THEN 120 */
line_150:;
    if (strcmp(basic_LEFT(A_str,1), "Y") != 0) { goto line_120; }
    /* BASIC: 160 K=1 */
line_160:;
    K = 1;
    /* BASIC: 170 GOSUB 390 */
line_170:;
    gosub_stack[gosub_sp++] = 1; goto line_390; line_ret_1:;
    /* BASIC: 180 IF LEN(A$(K))=0 THEN 999 */
line_180:;
    if (basic_LEN(A_str_arr[(int)(K)])==0) { goto line_999; }
    /* BASIC: 190 IF LEFT$(A$(K),2)="\Q" THEN 170 */
line_190:;
    if (strcmp(basic_LEFT(A_str_arr[(int)(K)],2), "\\Q") == 0) { goto line_170; }
    /* BASIC: 200 PRINT "IS IT A ";RIGHT$(A$(K),LEN(A$(K))-2); */
line_200:;
    printf("%s", "IS IT A "); printf("%s", basic_RIGHT(A_str_arr[(int)(K)],basic_LEN(A_str_arr[(int)(K)])-2));
    /* BASIC: 210 INPUT A$ */
line_210:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    /* BASIC: 220 A$=LEFT$(A$,1) */
line_220:;
    str_assign(A_str, sizeof(A_str), basic_LEFT(A_str,1));
    /* BASIC: 230 IF LEFT$(A$,1)="Y" THEN PRINT "WHY NOT TRY ANOTHER ANIMAL?": GOTO 120 */
line_230:;
    if (strcmp(basic_LEFT(A_str,1), "Y") == 0) { printf("%s", "WHY NOT TRY ANOTHER ANIMAL?"); printf("\n"); goto line_120; }
    /* BASIC: 240 INPUT "THE ANIMAL YOU WERE THINKING OF WAS A ";V$ */
line_240:;
    printf("%s", "THE ANIMAL YOU WERE THINKING OF WAS A "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", V_str);
    /* BASIC: 250 PRINT "PLEASE TYPE IN A QUESTION THAT WOULD DISTINGUISH A" */
line_250:;
    printf("%s", "PLEASE TYPE IN A QUESTION THAT WOULD DISTINGUISH A"); printf("\n");
    /* BASIC: 260 PRINT V$;" FROM A ";RIGHT$(A$(K),LEN(A$(K))-2) */
line_260:;
    printf("%s", V_str); printf("%s", " FROM A "); printf("%s", basic_RIGHT(A_str_arr[(int)(K)],basic_LEN(A_str_arr[(int)(K)])-2)); printf("\n");
    /* BASIC: 270 INPUT X$ */
line_270:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", X_str);
    /* BASIC: 280 PRINT "FOR A ";V$;" THE ANSWER WOULD BE "; */
line_280:;
    printf("%s", "FOR A "); printf("%s", V_str); printf("%s", " THE ANSWER WOULD BE ");
    /* BASIC: 290 INPUT A$ */
line_290:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    /* BASIC: 300 A$=LEFT$(A$,1): IF A$<>"Y" AND A$<>"N" THEN 280 */
line_300:;
    str_assign(A_str, sizeof(A_str), basic_LEFT(A_str,1));
    if (strcmp(A_str, "Y") != 0 && strcmp(A_str, "N") != 0) { goto line_280; }
    /* BASIC: 310 IF A$="Y" THEN B$="N" */
line_310:;
    if (strcmp(A_str, "Y") == 0) { str_assign(B_str, sizeof(B_str), "N"); }
    /* BASIC: 320 IF A$="N" THEN B$="Y" */
line_320:;
    if (strcmp(A_str, "N") == 0) { str_assign(B_str, sizeof(B_str), "Y"); }
    /* BASIC: 330 Z1=VAL(A$(0)) */
line_330:;
    Z1 = basic_VAL(A_str_arr[(int)(0)]);
    /* BASIC: 340 A$(0)=STR$(Z1+2) */
line_340:;
    str_assign(A_str_arr[(int)(0)], sizeof(A_str_arr[(int)(0)]), basic_STR(Z1+2));
    /* BASIC: 350 A$(Z1)=A$(K) */
line_350:;
    str_assign(A_str_arr[(int)(Z1)], sizeof(A_str_arr[(int)(Z1)]), A_str_arr[(int)(K)]);
    /* BASIC: 360 A$(Z1+1)="\A"+V$ */
line_360:;
    str_assign(A_str_arr[(int)(Z1+1)], sizeof(A_str_arr[(int)(Z1+1)]), str_cat_helper("\\A", V_str));
    /* BASIC: 370 A$(K)="\Q"+X$+"\"+A$+STR$(Z1+1)+"\"+B$+STR$(Z1)+"\" */
line_370:;
    str_assign(A_str_arr[(int)(K)], sizeof(A_str_arr[(int)(K)]), str_cat_helper(str_cat_helper(str_cat_helper(str_cat_helper(str_cat_helper(str_cat_helper(str_cat_helper(str_cat_helper("\\Q", X_str), "\\"), A_str), basic_STR(Z1+1)), "\\"), B_str), basic_STR(Z1)), "\\"));
    /* BASIC: 380 GOTO 120 */
line_380:;
    goto line_120;
    /* BASIC: 390 REM     SUBROUTINE TO PRINT QUESTIONS */
line_390:;
    // REM     SUBROUTINE TO PRINT QUESTIONS
    /* BASIC: 400 Q$=A$(K) */
line_400:;
    str_assign(Q_str, sizeof(Q_str), A_str_arr[(int)(K)]);
    /* BASIC: 410 FOR Z=3 TO LEN(Q$) */
line_410:;
    Z = 3; for_loop_Z_410: if (((1) >= 0 && Z > (basic_LEN(Q_str))) || ((1) < 0 && Z < (basic_LEN(Q_str)))) goto end_for_Z_410;
    /* BASIC: 415 IF MID$(Q$,Z,1)<>"\" THEN PRINT MID$(Q$,Z,1);: NEXT Z */
line_415:;
    if (strcmp(basic_MID(Q_str,Z,1), "\\") != 0) { printf("%s", basic_MID(Q_str,Z,1)); Z += (1); goto for_loop_Z_410; end_for_Z_410:; }
    /* BASIC: 420 INPUT C$ */
line_420:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", C_str);
    /* BASIC: 430 C$=LEFT$(C$,1) */
line_430:;
    str_assign(C_str, sizeof(C_str), basic_LEFT(C_str,1));
    /* BASIC: 440 IF C$<>"Y" AND C$<>"N" THEN 410 */
line_440:;
    if (strcmp(C_str, "Y") != 0 && strcmp(C_str, "N") != 0) { goto line_410; }
    /* BASIC: 450 T$="\"+C$ */
line_450:;
    str_assign(T_str, sizeof(T_str), str_cat_helper("\\", C_str));
    /* BASIC: 455 FOR X=3 TO LEN(Q$)-1 */
line_455:;
    X = 3; for_loop_X_455: if (((1) >= 0 && X > (basic_LEN(Q_str)-1)) || ((1) < 0 && X < (basic_LEN(Q_str)-1))) goto end_for_X_455;
    /* BASIC: 460 IF MID$(Q$,X,2)=T$ THEN 480 */
line_460:;
    if (strcmp(basic_MID(Q_str,X,2), T_str) == 0) { goto line_480; }
    /* BASIC: 470 NEXT X */
line_470:;
    X += (1); goto for_loop_X_455; end_for_X_455:;
    /* BASIC: 475 S TO P */
line_475:;
    /* UNTRANSLATED: S TO P */
    /* BASIC: 480 FOR Y=X+1 TO LEN(Q$) */
line_480:;
    Y = X+1; for_loop_Y_480: if (((1) >= 0 && Y > (basic_LEN(Q_str))) || ((1) < 0 && Y < (basic_LEN(Q_str)))) goto end_for_Y_480;
    /* BASIC: 490 IF MID$(Q$,Y,1)="\" THEN 510 */
line_490:;
    if (strcmp(basic_MID(Q_str,Y,1), "\\") == 0) { goto line_510; }
    /* BASIC: 500 NEXT Y */
line_500:;
    Y += (1); goto for_loop_Y_480; end_for_Y_480:;
    /* BASIC: 505 S TO P */
line_505:;
    /* UNTRANSLATED: S TO P */
    /* BASIC: 510 K=VAL(MID$(Q$,X+2,Y-X-2)) */
line_510:;
    K = basic_VAL(basic_MID(Q_str,X+2,Y-X-2));
    /* BASIC: 520 RETURN */
line_520:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 530 DATA "4","\QDOES IT SWIM\Y2\N3\","\AFISH","\ABIRD" */
line_530:;
    /* UNTRANSLATED: DATA "4","\\QDOES IT SWIM\\Y2\\N3\\","\\AFISH","\\ABIRD" */
    /* BASIC: 600 PRINT:PRINT "ANIMALS I ALREADY KNOW ARE:" */
line_600:;
    printf("\n");
    printf("%s", "ANIMALS I ALREADY KNOW ARE:"); printf("\n");
    /* BASIC: 605 X=0 */
line_605:;
    X = 0;
    /* BASIC: 610 FOR I=1 TO 200 */
line_610:;
    I = 1; for_loop_I_610: if (((1) >= 0 && I > (200)) || ((1) < 0 && I < (200))) goto end_for_I_610;
    /* BASIC: 620 IF LEFT$(A$(I),2)<>"\A" THEN 650 */
line_620:;
    if (strcmp(basic_LEFT(A_str_arr[(int)(I)],2), "\\A") != 0) { goto line_650; }
    /* BASIC: 624 PRINT TAB(15*X); */
line_624:;
    { int _t; for(_t=0; _t<15*X; _t++) printf(" "); }
    /* BASIC: 630 FOR Z=3 TO LEN(A$(I)) */
line_630:;
    Z = 3; for_loop_Z_630: if (((1) >= 0 && Z > (basic_LEN(A_str_arr[(int)(I)]))) || ((1) < 0 && Z < (basic_LEN(A_str_arr[(int)(I)])))) goto end_for_Z_630;
    /* BASIC: 640 IF MID$(A$(I),Z,1)<>"\" THEN PRINT MID$(A$(I),Z,1);: NEXT Z */
line_640:;
    if (strcmp(basic_MID(A_str_arr[(int)(I)],Z,1), "\\") != 0) { printf("%s", basic_MID(A_str_arr[(int)(I)],Z,1)); Z += (1); goto for_loop_Z_630; end_for_Z_630:; }
    /* BASIC: 645 X=X+1: IF X=4 THEN X=0: PRINT */
line_645:;
    X = X+1;
    if (X==4) { X = 0; }
    printf("\n");
    /* BASIC: 650 NEXT I */
line_650:;
    I += (1); goto for_loop_I_610; end_for_I_610:;
    /* BASIC: 660 PRINT */
line_660:;
    printf("\n");
    /* BASIC: 670 PRINT */
line_670:;
    printf("\n");
    /* BASIC: 680 GOTO 120 */
line_680:;
    goto line_120;
    /* BASIC: 999 END */
line_999:;
    exit(0);

    return 0;
}
