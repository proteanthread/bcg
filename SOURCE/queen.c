/*
 * Transpiled from queen.bas
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

static DataItem program_data[64] = {
    { DATA_NUM, { .num = 81.0 } },
    { DATA_NUM, { .num = 71.0 } },
    { DATA_NUM, { .num = 61.0 } },
    { DATA_NUM, { .num = 51.0 } },
    { DATA_NUM, { .num = 41.0 } },
    { DATA_NUM, { .num = 31.0 } },
    { DATA_NUM, { .num = 21.0 } },
    { DATA_NUM, { .num = 11.0 } },
    { DATA_NUM, { .num = 92.0 } },
    { DATA_NUM, { .num = 82.0 } },
    { DATA_NUM, { .num = 72.0 } },
    { DATA_NUM, { .num = 62.0 } },
    { DATA_NUM, { .num = 52.0 } },
    { DATA_NUM, { .num = 42.0 } },
    { DATA_NUM, { .num = 32.0 } },
    { DATA_NUM, { .num = 22.0 } },
    { DATA_NUM, { .num = 103.0 } },
    { DATA_NUM, { .num = 93.0 } },
    { DATA_NUM, { .num = 83.0 } },
    { DATA_NUM, { .num = 73.0 } },
    { DATA_NUM, { .num = 63.0 } },
    { DATA_NUM, { .num = 53.0 } },
    { DATA_NUM, { .num = 43.0 } },
    { DATA_NUM, { .num = 33.0 } },
    { DATA_NUM, { .num = 114.0 } },
    { DATA_NUM, { .num = 104.0 } },
    { DATA_NUM, { .num = 94.0 } },
    { DATA_NUM, { .num = 84.0 } },
    { DATA_NUM, { .num = 74.0 } },
    { DATA_NUM, { .num = 64.0 } },
    { DATA_NUM, { .num = 54.0 } },
    { DATA_NUM, { .num = 44.0 } },
    { DATA_NUM, { .num = 125.0 } },
    { DATA_NUM, { .num = 115.0 } },
    { DATA_NUM, { .num = 105.0 } },
    { DATA_NUM, { .num = 95.0 } },
    { DATA_NUM, { .num = 85.0 } },
    { DATA_NUM, { .num = 75.0 } },
    { DATA_NUM, { .num = 65.0 } },
    { DATA_NUM, { .num = 55.0 } },
    { DATA_NUM, { .num = 136.0 } },
    { DATA_NUM, { .num = 126.0 } },
    { DATA_NUM, { .num = 116.0 } },
    { DATA_NUM, { .num = 106.0 } },
    { DATA_NUM, { .num = 96.0 } },
    { DATA_NUM, { .num = 86.0 } },
    { DATA_NUM, { .num = 76.0 } },
    { DATA_NUM, { .num = 66.0 } },
    { DATA_NUM, { .num = 147.0 } },
    { DATA_NUM, { .num = 137.0 } },
    { DATA_NUM, { .num = 127.0 } },
    { DATA_NUM, { .num = 117.0 } },
    { DATA_NUM, { .num = 107.0 } },
    { DATA_NUM, { .num = 97.0 } },
    { DATA_NUM, { .num = 87.0 } },
    { DATA_NUM, { .num = 77.0 } },
    { DATA_NUM, { .num = 158.0 } },
    { DATA_NUM, { .num = 148.0 } },
    { DATA_NUM, { .num = 138.0 } },
    { DATA_NUM, { .num = 128.0 } },
    { DATA_NUM, { .num = 118.0 } },
    { DATA_NUM, { .num = 108.0 } },
    { DATA_NUM, { .num = 98.0 } },
    { DATA_NUM, { .num = 88.0 } },
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
static double A, B, C, I, K, L, M, M1, P, S, T, T1, U, U1, Z;
static char Q_str[256] = {0};
static char W_str[256] = {0};
static double S_arr[20000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 1 PRINT TAB(33);"QUEEN" */
line_1:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "QUEEN"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT:PRINT:PRINT */
line_3:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 10 DIM S(64) */
line_10:;
    /* DIM S(64) (handled statically) */
    /* BASIC: 11 FOR I=1 TO 64 */
line_11:;
    I = 1; for_loop_I_11: if (((1) >= 0 && I > (64)) || ((1) < 0 && I < (64))) goto end_for_I_11;
    /* BASIC: 12 READ S(I) */
line_12:;
    read_numeric(&(S_arr[(int)(I)]));
    /* BASIC: 13 NEXT I */
line_13:;
    I += (1); goto for_loop_I_11; end_for_I_11:;
    /* BASIC: 14 DATA  81,  71,  61,  51,  41,  31,  21,  11 */
line_14:;
    /* UNTRANSLATED: DATA  81,  71,  61,  51,  41,  31,  21,  11 */
    /* BASIC: 15 DATA  92,  82,  72,  62,  52,  42,  32,  22 */
line_15:;
    /* UNTRANSLATED: DATA  92,  82,  72,  62,  52,  42,  32,  22 */
    /* BASIC: 16 DATA 103,  93,  83,  73,  63,  53,  43,  33 */
line_16:;
    /* UNTRANSLATED: DATA 103,  93,  83,  73,  63,  53,  43,  33 */
    /* BASIC: 17 DATA 114, 104,  94,  84,  74,  64,  54,  44 */
line_17:;
    /* UNTRANSLATED: DATA 114, 104,  94,  84,  74,  64,  54,  44 */
    /* BASIC: 18 DATA 125, 115, 105,  95,  85,  75,  65,  55 */
line_18:;
    /* UNTRANSLATED: DATA 125, 115, 105,  95,  85,  75,  65,  55 */
    /* BASIC: 19 DATA 136, 126, 116, 106,  96,  86,  76,  66 */
line_19:;
    /* UNTRANSLATED: DATA 136, 126, 116, 106,  96,  86,  76,  66 */
    /* BASIC: 20 DATA 147, 137, 127, 117, 107,  97,  87,  77 */
line_20:;
    /* UNTRANSLATED: DATA 147, 137, 127, 117, 107,  97,  87,  77 */
    /* BASIC: 21 DATA 158, 148, 138, 128, 118, 108,  98,  88 */
line_21:;
    /* UNTRANSLATED: DATA 158, 148, 138, 128, 118, 108,  98,  88 */
    /* BASIC: 22 INPUT "DO YOU WANT INSTRUCTIONS";W$ */
line_22:;
    printf("%s", "DO YOU WANT INSTRUCTIONS"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", W_str);
    /* BASIC: 23 IF W$="NO" THEN 30 */
line_23:;
    if (strcmp(W_str, "NO") == 0) { goto line_30; }
    /* BASIC: 24 IF W$="YES" THEN 28 */
line_24:;
    if (strcmp(W_str, "YES") == 0) { goto line_28; }
    /* BASIC: 25 PRINT "PLEASE ANSWER 'YES' OR 'NO'." */
line_25:;
    printf("%s", "PLEASE ANSWER 'YES' OR 'NO'."); printf("\n");
    /* BASIC: 26 GOTO 22 */
line_26:;
    goto line_22;
    /* BASIC: 28 GOSUB 5000 */
line_28:;
    gosub_stack[gosub_sp++] = 1; goto line_5000; line_ret_1:;
    /* BASIC: 29 GOTO 100 */
line_29:;
    goto line_100;
    /* BASIC: 30 GOSUB 5160 */
line_30:;
    gosub_stack[gosub_sp++] = 2; goto line_5160; line_ret_2:;
    /* BASIC: 90 REM     ERR OR CHECKS */
line_90:;
    // REM     ERR OR CHECKS
    /* BASIC: 100 PRINT "WHERE WOULD YOU LIKE TO START"; */
line_100:;
    printf("%s", "WHERE WOULD YOU LIKE TO START");
    /* BASIC: 110 INPUT M1 */
line_110:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &M1);
    /* BASIC: 115 IF M1=0 THEN 232 */
line_115:;
    if (M1==0) { goto line_232; }
    /* BASIC: 120 T1=INT(M1/10) */
line_120:;
    T1 = floor(M1/10);
    /* BASIC: 130 U1=M1-10*T1 */
line_130:;
    U1 = M1-10*T1;
    /* BASIC: 140 IF U1=1 THEN 200 */
line_140:;
    if (U1==1) { goto line_200; }
    /* BASIC: 150 IF U1=T1 THEN 200 */
line_150:;
    if (U1==T1) { goto line_200; }
    /* BASIC: 160 PRINT "PLEASE READ THE DIRECTIONS AGAIN." */
line_160:;
    printf("%s", "PLEASE READ THE DIRECTIONS AGAIN."); printf("\n");
    /* BASIC: 170 PRINT "YOU HAVE BEGUN ILLEGALLY." */
line_170:;
    printf("%s", "YOU HAVE BEGUN ILLEGALLY."); printf("\n");
    /* BASIC: 175 PRINT */
line_175:;
    printf("\n");
    /* BASIC: 180 GOTO 100 */
line_180:;
    goto line_100;
    /* BASIC: 200 GOSUB 2000 */
line_200:;
    gosub_stack[gosub_sp++] = 3; goto line_2000; line_ret_3:;
    /* BASIC: 210 PRINT "COMPUTER MOVES TO SQUARE";M */
line_210:;
    printf("%s", "COMPUTER MOVES TO SQUARE"); printf("%g ", (double)(M)); printf("\n");
    /* BASIC: 215 IF M=158 THEN 3400 */
line_215:;
    if (M==158) { goto line_3400; }
    /* BASIC: 220 PRINT "WHAT IS YOUR MOVE"; */
line_220:;
    printf("%s", "WHAT IS YOUR MOVE");
    /* BASIC: 230 INPUT M1 */
line_230:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &M1);
    /* BASIC: 231 IF M1<>0 THEN 239 */
line_231:;
    if (M1!=0) { goto line_239; }
    /* BASIC: 232 PRINT */
line_232:;
    printf("\n");
    /* BASIC: 233 PRINT "IT LOOKS LIKE I HAVE WON BY FORFEIT." */
line_233:;
    printf("%s", "IT LOOKS LIKE I HAVE WON BY FORFEIT."); printf("\n");
    /* BASIC: 234 PRINT */
line_234:;
    printf("\n");
    /* BASIC: 235 GOTO 4000 */
line_235:;
    goto line_4000;
    /* BASIC: 239 IF M1<=M THEN 3200 */
line_239:;
    if (M1<=M) { goto line_3200; }
    /* BASIC: 240 T1=INT(M1/10) */
line_240:;
    T1 = floor(M1/10);
    /* BASIC: 250 U1=M1-10*T1 */
line_250:;
    U1 = M1-10*T1;
    /* BASIC: 260 P=U1-U */
line_260:;
    P = U1-U;
    /* BASIC: 270 IF P<>0 THEN 300 */
line_270:;
    if (P!=0) { goto line_300; }
    /* BASIC: 280 L=T1-T */
line_280:;
    L = T1-T;
    /* BASIC: 290 IF L<=0 THEN 3200 */
line_290:;
    if (L<=0) { goto line_3200; }
    /* BASIC: 295 GOTO 200 */
line_295:;
    goto line_200;
    /* BASIC: 300 IF T1-T <>P THEN 320 */
line_300:;
    if (T1-T !=P) { goto line_320; }
    /* BASIC: 310 GOTO 200 */
line_310:;
    goto line_200;
    /* BASIC: 320 IF T1-T <>2*P THEN 3200 */
line_320:;
    if (T1-T !=2*P) { goto line_3200; }
    /* BASIC: 330 GOTO 200 */
line_330:;
    goto line_200;
    /* BASIC: 1990 REM     LOCATE MOVE FOR COMPUTER */
line_1990:;
    // REM     LOCATE MOVE FOR COMPUTER
    /* BASIC: 2000 IF M1=41 THEN 2180 */
line_2000:;
    if (M1==41) { goto line_2180; }
    /* BASIC: 2010 IF M1=44 THEN 2180 */
line_2010:;
    if (M1==44) { goto line_2180; }
    /* BASIC: 2020 IF M1=73 THEN 2180 */
line_2020:;
    if (M1==73) { goto line_2180; }
    /* BASIC: 2030 IF M1=75 THEN 2180 */
line_2030:;
    if (M1==75) { goto line_2180; }
    /* BASIC: 2040 IF M1=126 THEN 2180 */
line_2040:;
    if (M1==126) { goto line_2180; }
    /* BASIC: 2050 IF M1=127 THEN 2180 */
line_2050:;
    if (M1==127) { goto line_2180; }
    /* BASIC: 2060 IF M1=158 THEN 3300 */
line_2060:;
    if (M1==158) { goto line_3300; }
    /* BASIC: 2065 C=0 */
line_2065:;
    C = 0;
    /* BASIC: 2070 FOR K=7 TO 1 STEP -1 */
line_2070:;
    K = 7; for_loop_K_2070: if (((-1) >= 0 && K > (1)) || ((-1) < 0 && K < (1))) goto end_for_K_2070;
    /* BASIC: 2080 U=U1 */
line_2080:;
    U = U1;
    /* BASIC: 2090 T=T1+K */
line_2090:;
    T = T1+K;
    /* BASIC: 2100 GOSUB 3500 */
line_2100:;
    gosub_stack[gosub_sp++] = 4; goto line_3500; line_ret_4:;
    /* BASIC: 2105 IF C=1 THEN 2160 */
line_2105:;
    if (C==1) { goto line_2160; }
    /* BASIC: 2110 U=U+K */
line_2110:;
    U = U+K;
    /* BASIC: 2120 GOSUB 3500 */
line_2120:;
    gosub_stack[gosub_sp++] = 5; goto line_3500; line_ret_5:;
    /* BASIC: 2125 IF C=1 THEN 2160 */
line_2125:;
    if (C==1) { goto line_2160; }
    /* BASIC: 2130 T=T+K */
line_2130:;
    T = T+K;
    /* BASIC: 2140 GOSUB 3500 */
line_2140:;
    gosub_stack[gosub_sp++] = 6; goto line_3500; line_ret_6:;
    /* BASIC: 2145 IF C=1 THEN 2160 */
line_2145:;
    if (C==1) { goto line_2160; }
    /* BASIC: 2150 NEXT K */
line_2150:;
    K += (-1); goto for_loop_K_2070; end_for_K_2070:;
    /* BASIC: 2155 GOTO 2180 */
line_2155:;
    goto line_2180;
    /* BASIC: 2160 C=0 */
line_2160:;
    C = 0;
    /* BASIC: 2170 RETURN */
line_2170:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 2180 GOSUB 3000 */
line_2180:;
    gosub_stack[gosub_sp++] = 7; goto line_3000; line_ret_7:;
    /* BASIC: 2190 RETURN */
line_2190:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 2990 REM     R AND OM MOVE */
line_2990:;
    // REM     R AND OM MOVE
    /* BASIC: 3000 Z=RND(1) */
line_3000:;
    Z = ((double)rand() / (double)RAND_MAX);
    /* BASIC: 3010 IF Z>.6 THEN 3110 */
line_3010:;
    if (Z>.6) { goto line_3110; }
    /* BASIC: 3020 IF Z>.3 THEN 3070 */
line_3020:;
    if (Z>.3) { goto line_3070; }
    /* BASIC: 3030 U=U1 */
line_3030:;
    U = U1;
    /* BASIC: 3040 T=T1+1 */
line_3040:;
    T = T1+1;
    /* BASIC: 3050 M=10*T+U */
line_3050:;
    M = 10*T+U;
    /* BASIC: 3060 RETURN */
line_3060:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 3070 U=U1+1 */
line_3070:;
    U = U1+1;
    /* BASIC: 3080 T=T1+2 */
line_3080:;
    T = T1+2;
    /* BASIC: 3090 M=10*T+U */
line_3090:;
    M = 10*T+U;
    /* BASIC: 3100 RETURN */
line_3100:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 3110 U=U1+1 */
line_3110:;
    U = U1+1;
    /* BASIC: 3120 T=T1+1 */
line_3120:;
    T = T1+1;
    /* BASIC: 3130 M=10*T+U */
line_3130:;
    M = 10*T+U;
    /* BASIC: 3140 RETURN */
line_3140:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 3190 REM     ILLEGAL MOVE MESSAGE */
line_3190:;
    // REM     ILLEGAL MOVE MESSAGE
    /* BASIC: 3200 PRINT */
line_3200:;
    printf("\n");
    /* BASIC: 3210 PRINT "Y O U   C H E A T . . .  TRY AGAIN"; */
line_3210:;
    printf("%s", "Y O U   C H E A T . . .  TRY AGAIN");
    /* BASIC: 3220 GOTO 230 */
line_3220:;
    goto line_230;
    /* BASIC: 3290 REM     PLAYER WINS */
line_3290:;
    // REM     PLAYER WINS
    /* BASIC: 3300 PRINT */
line_3300:;
    printf("\n");
    /* BASIC: 3310 PRINT "C O N G R A T U L A T I O N S . . ." */
line_3310:;
    printf("%s", "C O N G R A T U L A T I O N S . . ."); printf("\n");
    /* BASIC: 3320 PRINT */
line_3320:;
    printf("\n");
    /* BASIC: 3330 PRINT "YOU HAVE WON--VERY WELL PLAYED." */
line_3330:;
    printf("%s", "YOU HAVE WON--VERY WELL PLAYED."); printf("\n");
    /* BASIC: 3340 PRINT "IT LOOKS LIKE I HAVE MET MY MATCH." */
line_3340:;
    printf("%s", "IT LOOKS LIKE I HAVE MET MY MATCH."); printf("\n");
    /* BASIC: 3350 PRINT "THANKS FOR PLAYING---I CAN'T WIN ALL THE TIME." */
line_3350:;
    printf("%s", "THANKS FOR PLAYING---I CAN'T WIN ALL THE TIME."); printf("\n");
    /* BASIC: 3360 PRINT */
line_3360:;
    printf("\n");
    /* BASIC: 3370 GOTO 4000 */
line_3370:;
    goto line_4000;
    /* BASIC: 3390 REM     COMPUTER WINS */
line_3390:;
    // REM     COMPUTER WINS
    /* BASIC: 3400 PRINT */
line_3400:;
    printf("\n");
    /* BASIC: 3410 PRINT "NICE TRY, BUT IT LOOKS LIKE I HAVE WON." */
line_3410:;
    printf("%s", "NICE TRY, BUT IT LOOKS LIKE I HAVE WON."); printf("\n");
    /* BASIC: 3420 PRINT "THANKS FOR PLAYING." */
line_3420:;
    printf("%s", "THANKS FOR PLAYING."); printf("\n");
    /* BASIC: 3430 PRINT */
line_3430:;
    printf("\n");
    /* BASIC: 3440 GOTO 4000 */
line_3440:;
    goto line_4000;
    /* BASIC: 3490 REM     TEST FOR COMPUTER MOVE */
line_3490:;
    // REM     TEST FOR COMPUTER MOVE
    /* BASIC: 3500 M=10*T+U */
line_3500:;
    M = 10*T+U;
    /* BASIC: 3510 IF M=158 THEN 3570 */
line_3510:;
    if (M==158) { goto line_3570; }
    /* BASIC: 3520 IF M=127 THEN 3570 */
line_3520:;
    if (M==127) { goto line_3570; }
    /* BASIC: 3530 IF M=126 THEN 3570 */
line_3530:;
    if (M==126) { goto line_3570; }
    /* BASIC: 3540 IF M=75 THEN 3570 */
line_3540:;
    if (M==75) { goto line_3570; }
    /* BASIC: 3550 IF M=73 THEN 3570 */
line_3550:;
    if (M==73) { goto line_3570; }
    /* BASIC: 3560 RETURN */
line_3560:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 3570 C=1 */
line_3570:;
    C = 1;
    /* BASIC: 3580 GOTO 3560 */
line_3580:;
    goto line_3560;
    /* BASIC: 3990 REM     A NOT HER GAME??? */
line_3990:;
    // REM     A NOT HER GAME???
    /* BASIC: 4000 PRINT "ANYONE ELSE CARE TO TRY"; */
line_4000:;
    printf("%s", "ANYONE ELSE CARE TO TRY");
    /* BASIC: 4010 INPUT Q$ */
line_4010:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", Q_str);
    /* BASIC: 4020 PRINT */
line_4020:;
    printf("\n");
    /* BASIC: 4030 IF Q$="YES" THEN 30 */
line_4030:;
    if (strcmp(Q_str, "YES") == 0) { goto line_30; }
    /* BASIC: 4040 IF Q$="NO" THEN 4050 */
line_4040:;
    if (strcmp(Q_str, "NO") == 0) { goto line_4050; }
    /* BASIC: 4042 PRINT "PLEASE ANSWER 'YES' OR 'NO'." */
line_4042:;
    printf("%s", "PLEASE ANSWER 'YES' OR 'NO'."); printf("\n");
    /* BASIC: 4045 GOTO 4000 */
line_4045:;
    goto line_4000;
    /* BASIC: 4050 PRINT:PRINT "OK --- THANKS AGAIN." */
line_4050:;
    printf("\n");
    printf("%s", "OK --- THANKS AGAIN."); printf("\n");
    /* BASIC: 4060 S TO P */
line_4060:;
    /* UNTRANSLATED: S TO P */
    /* BASIC: 4990 REM     DIRECTIONS */
line_4990:;
    // REM     DIRECTIONS
    /* BASIC: 5000 PRINT "WE ARE GOING TO PLAY A GAME BASED ON ONE OF THE CHESS" */
line_5000:;
    printf("%s", "WE ARE GOING TO PLAY A GAME BASED ON ONE OF THE CHESS"); printf("\n");
    /* BASIC: 5010 PRINT "MOVES.  OUR QUEEN WILL BE ABLE TO MOVE ONLY TO THE LEFT," */
line_5010:;
    printf("%s", "MOVES.  OUR QUEEN WILL BE ABLE TO MOVE ONLY TO THE LEFT,"); printf("\n");
    /* BASIC: 5020 PRINT "DOWN, OR DIAGONALLY DOWN AND TO THE LEFT." */
line_5020:;
    printf("%s", "DOWN, OR DIAGONALLY DOWN AND TO THE LEFT."); printf("\n");
    /* BASIC: 5030 PRINT */
line_5030:;
    printf("\n");
    /* BASIC: 5040 PRINT "THE OBJECT OF THE GAME IS TO PLACE THE QUEEN IN THE LOWER" */
line_5040:;
    printf("%s", "THE OBJECT OF THE GAME IS TO PLACE THE QUEEN IN THE LOWER"); printf("\n");
    /* BASIC: 5050 PRINT "LEFT HAND SQUARE BY ALTERNATING MOVES BETWEEN YOU AND THE" */
line_5050:;
    printf("%s", "LEFT HAND SQUARE BY ALTERNATING MOVES BETWEEN YOU AND THE"); printf("\n");
    /* BASIC: 5060 PRINT "COMPUTER.  THE FIRST ONE TO PLACE THE QUEEN THERE WINS." */
line_5060:;
    printf("%s", "COMPUTER.  THE FIRST ONE TO PLACE THE QUEEN THERE WINS."); printf("\n");
    /* BASIC: 5070 PRINT */
line_5070:;
    printf("\n");
    /* BASIC: 5080 PRINT "YOU GO FIRST AND PLACE THE QUEEN IN ANY ONE OF THE SQUARES" */
line_5080:;
    printf("%s", "YOU GO FIRST AND PLACE THE QUEEN IN ANY ONE OF THE SQUARES"); printf("\n");
    /* BASIC: 5090 PRINT "ON THE TOP ROW OR RIGHT HAND COLUMN." */
line_5090:;
    printf("%s", "ON THE TOP ROW OR RIGHT HAND COLUMN."); printf("\n");
    /* BASIC: 5100 PRINT "THAT WILL BE YOUR FIRST MOVE." */
line_5100:;
    printf("%s", "THAT WILL BE YOUR FIRST MOVE."); printf("\n");
    /* BASIC: 5110 PRINT "WE ALTERNATE MOVES." */
line_5110:;
    printf("%s", "WE ALTERNATE MOVES."); printf("\n");
    /* BASIC: 5120 PRINT "YOU MAY FORFEIT BY TYPING '0' AS YOUR MOVE." */
line_5120:;
    printf("%s", "YOU MAY FORFEIT BY TYPING '0' AS YOUR MOVE."); printf("\n");
    /* BASIC: 5130 PRINT "BE SURE TO PRESS THE RETURN KEY AFTER EACH RESPONSE." */
line_5130:;
    printf("%s", "BE SURE TO PRESS THE RETURN KEY AFTER EACH RESPONSE."); printf("\n");
    /* BASIC: 5140 PRINT */
line_5140:;
    printf("\n");
    /* BASIC: 5150 PRINT */
line_5150:;
    printf("\n");
    /* BASIC: 5160 PRINT */
line_5160:;
    printf("\n");
    /* BASIC: 5170 FOR A=0 TO 7 */
line_5170:;
    A = 0; for_loop_A_5170: if (((1) >= 0 && A > (7)) || ((1) < 0 && A < (7))) goto end_for_A_5170;
    /* BASIC: 5180 FOR B=1 TO 8 */
line_5180:;
    B = 1; for_loop_B_5180: if (((1) >= 0 && B > (8)) || ((1) < 0 && B < (8))) goto end_for_B_5180;
    /* BASIC: 5185 I=8*A+B */
line_5185:;
    I = 8*A+B;
    /* BASIC: 5190 PRINT S(I); */
line_5190:;
    printf("%g ", (double)(S_arr[(int)(I)]));
    /* BASIC: 5200 NEXT B */
line_5200:;
    B += (1); goto for_loop_B_5180; end_for_B_5180:;
    /* BASIC: 5210 PRINT */
line_5210:;
    printf("\n");
    /* BASIC: 5220 PRINT */
line_5220:;
    printf("\n");
    /* BASIC: 5230 PRINT */
line_5230:;
    printf("\n");
    /* BASIC: 5240 NEXT A */
line_5240:;
    A += (1); goto for_loop_A_5170; end_for_A_5170:;
    /* BASIC: 5250 PRINT */
line_5250:;
    printf("\n");
    /* BASIC: 5260 RETURN */
line_5260:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 9999 END */
line_9999:;
    exit(0);

    return 0;
}
