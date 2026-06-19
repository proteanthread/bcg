/*
 * Transpiled from bunny.bas
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

static DataItem program_data[233] = {
    { DATA_NUM, { .num = 2.0 } },
    { DATA_NUM, { .num = 21.0 } },
    { DATA_NUM, { .num = 14.0 } },
    { DATA_NUM, { .num = 14.0 } },
    { DATA_NUM, { .num = 25.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 2.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 2.0 } },
    { DATA_NUM, { .num = 45.0 } },
    { DATA_NUM, { .num = 50.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 5.0 } },
    { DATA_NUM, { .num = 43.0 } },
    { DATA_NUM, { .num = 52.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 7.0 } },
    { DATA_NUM, { .num = 41.0 } },
    { DATA_NUM, { .num = 52.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 9.0 } },
    { DATA_NUM, { .num = 37.0 } },
    { DATA_NUM, { .num = 50.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 2.0 } },
    { DATA_NUM, { .num = 11.0 } },
    { DATA_NUM, { .num = 36.0 } },
    { DATA_NUM, { .num = 50.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 3.0 } },
    { DATA_NUM, { .num = 13.0 } },
    { DATA_NUM, { .num = 34.0 } },
    { DATA_NUM, { .num = 49.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 4.0 } },
    { DATA_NUM, { .num = 14.0 } },
    { DATA_NUM, { .num = 32.0 } },
    { DATA_NUM, { .num = 48.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 5.0 } },
    { DATA_NUM, { .num = 15.0 } },
    { DATA_NUM, { .num = 31.0 } },
    { DATA_NUM, { .num = 47.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 6.0 } },
    { DATA_NUM, { .num = 16.0 } },
    { DATA_NUM, { .num = 30.0 } },
    { DATA_NUM, { .num = 45.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 7.0 } },
    { DATA_NUM, { .num = 17.0 } },
    { DATA_NUM, { .num = 29.0 } },
    { DATA_NUM, { .num = 44.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 8.0 } },
    { DATA_NUM, { .num = 19.0 } },
    { DATA_NUM, { .num = 28.0 } },
    { DATA_NUM, { .num = 43.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 9.0 } },
    { DATA_NUM, { .num = 20.0 } },
    { DATA_NUM, { .num = 27.0 } },
    { DATA_NUM, { .num = 41.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 10.0 } },
    { DATA_NUM, { .num = 21.0 } },
    { DATA_NUM, { .num = 26.0 } },
    { DATA_NUM, { .num = 40.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 11.0 } },
    { DATA_NUM, { .num = 22.0 } },
    { DATA_NUM, { .num = 25.0 } },
    { DATA_NUM, { .num = 38.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 12.0 } },
    { DATA_NUM, { .num = 22.0 } },
    { DATA_NUM, { .num = 24.0 } },
    { DATA_NUM, { .num = 36.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 13.0 } },
    { DATA_NUM, { .num = 34.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 14.0 } },
    { DATA_NUM, { .num = 33.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 15.0 } },
    { DATA_NUM, { .num = 31.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 17.0 } },
    { DATA_NUM, { .num = 29.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 18.0 } },
    { DATA_NUM, { .num = 27.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 19.0 } },
    { DATA_NUM, { .num = 26.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 16.0 } },
    { DATA_NUM, { .num = 28.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 13.0 } },
    { DATA_NUM, { .num = 30.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 11.0 } },
    { DATA_NUM, { .num = 31.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 10.0 } },
    { DATA_NUM, { .num = 32.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 8.0 } },
    { DATA_NUM, { .num = 33.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 7.0 } },
    { DATA_NUM, { .num = 34.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 6.0 } },
    { DATA_NUM, { .num = 13.0 } },
    { DATA_NUM, { .num = 16.0 } },
    { DATA_NUM, { .num = 34.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 5.0 } },
    { DATA_NUM, { .num = 12.0 } },
    { DATA_NUM, { .num = 16.0 } },
    { DATA_NUM, { .num = 35.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 4.0 } },
    { DATA_NUM, { .num = 12.0 } },
    { DATA_NUM, { .num = 16.0 } },
    { DATA_NUM, { .num = 35.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 3.0 } },
    { DATA_NUM, { .num = 12.0 } },
    { DATA_NUM, { .num = 15.0 } },
    { DATA_NUM, { .num = 35.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 2.0 } },
    { DATA_NUM, { .num = 35.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 35.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 2.0 } },
    { DATA_NUM, { .num = 34.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 3.0 } },
    { DATA_NUM, { .num = 34.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 4.0 } },
    { DATA_NUM, { .num = 33.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 6.0 } },
    { DATA_NUM, { .num = 33.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 10.0 } },
    { DATA_NUM, { .num = 32.0 } },
    { DATA_NUM, { .num = 34.0 } },
    { DATA_NUM, { .num = 34.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 14.0 } },
    { DATA_NUM, { .num = 17.0 } },
    { DATA_NUM, { .num = 19.0 } },
    { DATA_NUM, { .num = 25.0 } },
    { DATA_NUM, { .num = 28.0 } },
    { DATA_NUM, { .num = 31.0 } },
    { DATA_NUM, { .num = 35.0 } },
    { DATA_NUM, { .num = 35.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 15.0 } },
    { DATA_NUM, { .num = 19.0 } },
    { DATA_NUM, { .num = 23.0 } },
    { DATA_NUM, { .num = 30.0 } },
    { DATA_NUM, { .num = 36.0 } },
    { DATA_NUM, { .num = 36.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 14.0 } },
    { DATA_NUM, { .num = 18.0 } },
    { DATA_NUM, { .num = 21.0 } },
    { DATA_NUM, { .num = 21.0 } },
    { DATA_NUM, { .num = 24.0 } },
    { DATA_NUM, { .num = 30.0 } },
    { DATA_NUM, { .num = 37.0 } },
    { DATA_NUM, { .num = 37.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 13.0 } },
    { DATA_NUM, { .num = 18.0 } },
    { DATA_NUM, { .num = 23.0 } },
    { DATA_NUM, { .num = 29.0 } },
    { DATA_NUM, { .num = 33.0 } },
    { DATA_NUM, { .num = 38.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 12.0 } },
    { DATA_NUM, { .num = 29.0 } },
    { DATA_NUM, { .num = 31.0 } },
    { DATA_NUM, { .num = 33.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 11.0 } },
    { DATA_NUM, { .num = 13.0 } },
    { DATA_NUM, { .num = 17.0 } },
    { DATA_NUM, { .num = 17.0 } },
    { DATA_NUM, { .num = 19.0 } },
    { DATA_NUM, { .num = 19.0 } },
    { DATA_NUM, { .num = 22.0 } },
    { DATA_NUM, { .num = 22.0 } },
    { DATA_NUM, { .num = 24.0 } },
    { DATA_NUM, { .num = 31.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 10.0 } },
    { DATA_NUM, { .num = 11.0 } },
    { DATA_NUM, { .num = 17.0 } },
    { DATA_NUM, { .num = 18.0 } },
    { DATA_NUM, { .num = 22.0 } },
    { DATA_NUM, { .num = 22.0 } },
    { DATA_NUM, { .num = 24.0 } },
    { DATA_NUM, { .num = 24.0 } },
    { DATA_NUM, { .num = 29.0 } },
    { DATA_NUM, { .num = 29.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 22.0 } },
    { DATA_NUM, { .num = 23.0 } },
    { DATA_NUM, { .num = 26.0 } },
    { DATA_NUM, { .num = 29.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 27.0 } },
    { DATA_NUM, { .num = 29.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 28.0 } },
    { DATA_NUM, { .num = 29.0 } },
    { DATA_NUM, { .num = -1.0 } },
    { DATA_NUM, { .num = 4096.0 } },
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
static double B, I, J, L, X, Y;
static double B_arr[20000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(33);"BUNNY" */
line_10:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "BUNNY"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT: PRINT: PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 100 REM  "BUNNY" FROM AHL'S 'BASIC COMPUTER GAMES' */
line_100:;
    // REM  "BUNNY" FROM AHL'S 'BASIC COMPUTER GAMES'
    /* BASIC: 110 REM */
line_110:;
    // REM
    /* BASIC: 120 FOR I=0 TO 4: READ B(I): NEXT I */
line_120:;
    I = 0; for_loop_I_120: if (((1) >= 0 && I > (4)) || ((1) < 0 && I < (4))) goto end_for_I_120;
    read_numeric(&(B_arr[(int)(I)]));
    I += (1); goto for_loop_I_120; end_for_I_120:;
    /* BASIC: 130 GOSUB 260 */
line_130:;
    gosub_stack[gosub_sp++] = 1; goto line_260; line_ret_1:;
    /* BASIC: 140 L=64: REM  ASCII LETTER CODE... */
line_140:;
    L = 64;
    // REM  ASCII LETTER CODE...
    /* BASIC: 150 REM */
line_150:;
    // REM
    /* BASIC: 160 PRINT */
line_160:;
    printf("\n");
    /* BASIC: 170 READ X: IF X<0 THEN 160 */
line_170:;
    read_numeric(&X);
    if (X<0) { goto line_160; }
    /* BASIC: 175 IF X>128 THEN 240 */
line_175:;
    if (X>128) { goto line_240; }
    /* BASIC: 180 PRINT TAB(X);: READ Y */
line_180:;
    { int _t; for(_t=0; _t<X; _t++) printf(" "); }
    read_numeric(&Y);
    /* BASIC: 190 FOR I=X TO Y: J=I-5*INT(I/5) */
line_190:;
    I = X; for_loop_I_190: if (((1) >= 0 && I > (Y)) || ((1) < 0 && I < (Y))) goto end_for_I_190;
    J = I-5*floor(I/5);
    /* BASIC: 200 PRINT CHR$(L+B(J)); */
line_200:;
    printf("%s", basic_CHR(L+B_arr[(int)(J)]));
    /* BASIC: 210 NEXT I */
line_210:;
    I += (1); goto for_loop_I_190; end_for_I_190:;
    /* BASIC: 220 GOTO 170 */
line_220:;
    goto line_170;
    /* BASIC: 230 REM */
line_230:;
    // REM
    /* BASIC: 240 GOSUB 260: GOTO 450 */
line_240:;
    gosub_stack[gosub_sp++] = 2; goto line_260; line_ret_2:;
    goto line_450;
    /* BASIC: 250 REM */
line_250:;
    // REM
    /* BASIC: 260 FOR I=1 TO 6: PRINT CHR$(10);: NEXT I */
line_260:;
    I = 1; for_loop_I_260: if (((1) >= 0 && I > (6)) || ((1) < 0 && I < (6))) goto end_for_I_260;
    printf("%s", basic_CHR(10));
    I += (1); goto for_loop_I_260; end_for_I_260:;
    /* BASIC: 270 RETURN */
line_270:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 280 REM */
line_280:;
    // REM
    /* BASIC: 290 DATA 2,21,14,14,25 */
line_290:;
    /* UNTRANSLATED: DATA 2,21,14,14,25 */
    /* BASIC: 300 DATA 1,2,-1,0,2,45,50,-1,0,5,43,52,-1,0,7,41,52,-1 */
line_300:;
    /* UNTRANSLATED: DATA 1,2,-1,0,2,45,50,-1,0,5,43,52,-1,0,7,41,52,-1 */
    /* BASIC: 310 DATA 1,9,37,50,-1,2,11,36,50,-1,3,13,34,49,-1,4,14,32,48,-1 */
line_310:;
    /* UNTRANSLATED: DATA 1,9,37,50,-1,2,11,36,50,-1,3,13,34,49,-1,4,14,32,48,-1 */
    /* BASIC: 320 DATA 5,15,31,47,-1,6,16,30,45,-1,7,17,29,44,-1,8,19,28,43,-1 */
line_320:;
    /* UNTRANSLATED: DATA 5,15,31,47,-1,6,16,30,45,-1,7,17,29,44,-1,8,19,28,43,-1 */
    /* BASIC: 330 DATA 9,20,27,41,-1,10,21,26,40,-1,11,22,25,38,-1,12,22,24,36,-1 */
line_330:;
    /* UNTRANSLATED: DATA 9,20,27,41,-1,10,21,26,40,-1,11,22,25,38,-1,12,22,24,36,-1 */
    /* BASIC: 340 DATA 13,34,-1,14,33,-1,15,31,-1,17,29,-1,18,27,-1 */
line_340:;
    /* UNTRANSLATED: DATA 13,34,-1,14,33,-1,15,31,-1,17,29,-1,18,27,-1 */
    /* BASIC: 350 DATA 19,26,-1,16,28,-1,13,30,-1,11,31,-1,10,32,-1 */
line_350:;
    /* UNTRANSLATED: DATA 19,26,-1,16,28,-1,13,30,-1,11,31,-1,10,32,-1 */
    /* BASIC: 360 DATA 8,33,-1,7,34,-1,6,13,16,34,-1,5,12,16,35,-1 */
line_360:;
    /* UNTRANSLATED: DATA 8,33,-1,7,34,-1,6,13,16,34,-1,5,12,16,35,-1 */
    /* BASIC: 370 DATA 4,12,16,35,-1,3,12,15,35,-1,2,35,-1,1,35,-1 */
line_370:;
    /* UNTRANSLATED: DATA 4,12,16,35,-1,3,12,15,35,-1,2,35,-1,1,35,-1 */
    /* BASIC: 380 DATA 2,34,-1,3,34,-1,4,33,-1,6,33,-1,10,32,34,34,-1 */
line_380:;
    /* UNTRANSLATED: DATA 2,34,-1,3,34,-1,4,33,-1,6,33,-1,10,32,34,34,-1 */
    /* BASIC: 390 DATA 14,17,19,25,28,31,35,35,-1,15,19,23,30,36,36,-1 */
line_390:;
    /* UNTRANSLATED: DATA 14,17,19,25,28,31,35,35,-1,15,19,23,30,36,36,-1 */
    /* BASIC: 400 DATA 14,18,21,21,24,30,37,37,-1,13,18,23,29,33,38,-1 */
line_400:;
    /* UNTRANSLATED: DATA 14,18,21,21,24,30,37,37,-1,13,18,23,29,33,38,-1 */
    /* BASIC: 410 DATA 12,29,31,33,-1,11,13,17,17,19,19,22,22,24,31,-1 */
line_410:;
    /* UNTRANSLATED: DATA 12,29,31,33,-1,11,13,17,17,19,19,22,22,24,31,-1 */
    /* BASIC: 420 DATA 10,11,17,18,22,22,24,24,29,29,-1 */
line_420:;
    /* UNTRANSLATED: DATA 10,11,17,18,22,22,24,24,29,29,-1 */
    /* BASIC: 430 DATA 22,23,26,29,-1,27,29,-1,28,29,-1,4096 */
line_430:;
    /* UNTRANSLATED: DATA 22,23,26,29,-1,27,29,-1,28,29,-1,4096 */
    /* BASIC: 440 REM */
line_440:;
    // REM
    /* BASIC: 450 END */
line_450:;
    exit(0);

    return 0;
}
