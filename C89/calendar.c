/*
 * Transpiled from calendar.bas
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

static DataItem program_data[13] = {
    { DATA_NUM, 0.0, NULL },
    { DATA_NUM, 31.0, NULL },
    { DATA_NUM, 28.0, NULL },
    { DATA_NUM, 31.0, NULL },
    { DATA_NUM, 30.0, NULL },
    { DATA_NUM, 31.0, NULL },
    { DATA_NUM, 30.0, NULL },
    { DATA_NUM, 31.0, NULL },
    { DATA_NUM, 31.0, NULL },
    { DATA_NUM, 30.0, NULL },
    { DATA_NUM, 31.0, NULL },
    { DATA_NUM, 30.0, NULL },
    { DATA_NUM, 31.0, NULL },
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
static double D, D2, G, I, M, N, ON, S, W;
static double M_arr[2000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(32);"CALENDAR" */
line_10:;
    { int _t; for(_t=0; _t<32; _t++) printf(" "); } printf("%s", "CALENDAR"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 100 REM     VALUES FOR 1979 - SEE NOT ES */
line_100:;
    /* REM     VALUES FOR 1979 - SEE NOT ES */
    /* BASIC: 110 DIM M(12) */
line_110:;
    /* DIM M(12) (handled statically) */
    /* BASIC: 120 FOR I=1 TO 6: PRINT CHR$(10);: NEXT I */
line_120:;
    I = 1; for_loop_I_120: if (((1) >= 0 && I > (6)) || ((1) < 0 && I < (6))) goto end_for_I_120;
    printf("%s", basic_CHR(10));
    I += (1); goto for_loop_I_120; end_for_I_120:;
    /* BASIC: 130 D=1: REM 1979 STARTS ON MONDAY (0=SUN, -1=MON, -2=TUES...) */
line_130:;
    D = 1;
    /* REM 1979 STARTS ON MONDAY (0=SUN, -1=MON, -2=TUES...) */
    /* BASIC: 140 S=0 */
line_140:;
    S = 0;
    /* BASIC: 150 REM     READ DAYS OF EACH MONTH */
line_150:;
    /* REM     READ DAYS OF EACH MONTH */
    /* BASIC: 160 FOR N=0 TO 12: READ M(N): NEXT N */
line_160:;
    N = 0; for_loop_N_160: if (((1) >= 0 && N > (12)) || ((1) < 0 && N < (12))) goto end_for_N_160;
    read_numeric(&(M_arr[(int)(N)]));
    N += (1); goto for_loop_N_160; end_for_N_160:;
    /* BASIC: 170 REM */
line_170:;
    /* REM */
    /* BASIC: 180 FOR N=1 TO 12 */
line_180:;
    N = 1; for_loop_N_180: if (((1) >= 0 && N > (12)) || ((1) < 0 && N < (12))) goto end_for_N_180;
    /* BASIC: 190 PRINT: PRINT: S=S+M(N-1) */
line_190:;
    printf("\n");
    printf("\n");
    S = S+M_arr[(int)(N-1)];
    /* BASIC: 200 PRINT "**";S;TAB(7); */
line_200:;
    printf("%s", "**"); printf("%g ", (double)(S)); { int _t; for(_t=0; _t<7; _t++) printf(" "); }
    /* BASIC: 210 FOR I=1 TO 18: PRINT "*";: NEXT I */
line_210:;
    I = 1; for_loop_I_210: if (((1) >= 0 && I > (18)) || ((1) < 0 && I < (18))) goto end_for_I_210;
    printf("%s", "*");
    I += (1); goto for_loop_I_210; end_for_I_210:;
    /* BASIC: 220 ON N GOTO 230,240,250,260,270,280,290,300,310,320,330,340 */
line_220:;
    switch ((int)(N)) {     case 1: goto line_230;     case 2: goto line_240;     case 3: goto line_250;     case 4: goto line_260;     case 5: goto line_270;     case 6: goto line_280;     case 7: goto line_290;     case 8: goto line_300;     case 9: goto line_310;     case 10: goto line_320;     case 11: goto line_330;     case 12: goto line_340; }
    /* BASIC: 230 PRINT " JANUARY ";: GOTO 350 */
line_230:;
    printf("%s", " JANUARY ");
    goto line_350;
    /* BASIC: 240 PRINT " FEBRUARY";: GOTO 350 */
line_240:;
    printf("%s", " FEBRUARY");
    goto line_350;
    /* BASIC: 250 PRINT "  MARCH  ";: GOTO 350 */
line_250:;
    printf("%s", "  MARCH  ");
    goto line_350;
    /* BASIC: 260 PRINT "  APRIL  ";: GOTO 350 */
line_260:;
    printf("%s", "  APRIL  ");
    goto line_350;
    /* BASIC: 270 PRINT "   MAY   ";: GOTO 350 */
line_270:;
    printf("%s", "   MAY   ");
    goto line_350;
    /* BASIC: 280 PRINT "   JUNE  ";: GOTO 350 */
line_280:;
    printf("%s", "   JUNE  ");
    goto line_350;
    /* BASIC: 290 PRINT "   JULY  ";: GOTO 350 */
line_290:;
    printf("%s", "   JULY  ");
    goto line_350;
    /* BASIC: 300 PRINT "  AUGUST ";: GOTO 350 */
line_300:;
    printf("%s", "  AUGUST ");
    goto line_350;
    /* BASIC: 310 PRINT "SEPTEMBER";: GOTO 350 */
line_310:;
    printf("%s", "SEPTEMBER");
    goto line_350;
    /* BASIC: 320 PRINT " OCTOBER ";: GOTO 350 */
line_320:;
    printf("%s", " OCTOBER ");
    goto line_350;
    /* BASIC: 330 PRINT " NOVEMBER";: GOTO 350 */
line_330:;
    printf("%s", " NOVEMBER");
    goto line_350;
    /* BASIC: 340 PRINT " DECEMBER"; */
line_340:;
    printf("%s", " DECEMBER");
    /* BASIC: 350 FOR I=1 TO 18: PRINT "*";: NEXT I */
line_350:;
    I = 1; for_loop_I_350: if (((1) >= 0 && I > (18)) || ((1) < 0 && I < (18))) goto end_for_I_350;
    printf("%s", "*");
    I += (1); goto for_loop_I_350; end_for_I_350:;
    /* BASIC: 360 PRINT 365-S;"**"; */
line_360:;
    printf("%g ", (double)(365-S)); printf("%s", "**");
    /* BASIC: 370 REM   366-S;     ON LEAP YEARS */
line_370:;
    /* REM   366-S;     ON LEAP YEARS */
    /* BASIC: 380 PRINT CHR$(10): PRINT "     S       M       T       W"; */
line_380:;
    printf("%s", basic_CHR(10)); printf("\n");
    printf("%s", "     S       M       T       W");
    /* BASIC: 390 PRINT "       T       F       S" */
line_390:;
    printf("%s", "       T       F       S"); printf("\n");
    /* BASIC: 400 PRINT */
line_400:;
    printf("\n");
    /* BASIC: 410 FOR I=1 TO 59: PRINT "*";: NEXT I */
line_410:;
    I = 1; for_loop_I_410: if (((1) >= 0 && I > (59)) || ((1) < 0 && I < (59))) goto end_for_I_410;
    printf("%s", "*");
    I += (1); goto for_loop_I_410; end_for_I_410:;
    /* BASIC: 420 REM */
line_420:;
    /* REM */
    /* BASIC: 430 FOR W=1 TO 6 */
line_430:;
    W = 1; for_loop_W_430: if (((1) >= 0 && W > (6)) || ((1) < 0 && W < (6))) goto end_for_W_430;
    /* BASIC: 440 PRINT CHR$(10) */
line_440:;
    printf("%s", basic_CHR(10)); printf("\n");
    /* BASIC: 450 PRINT TAB(4) */
line_450:;
    { int _t; for(_t=0; _t<4; _t++) printf(" "); } printf("\n");
    /* BASIC: 460 REM */
line_460:;
    /* REM */
    /* BASIC: 470 FOR G=1 TO 7 */
line_470:;
    G = 1; for_loop_G_470: if (((1) >= 0 && G > (7)) || ((1) < 0 && G < (7))) goto end_for_G_470;
    /* BASIC: 480 D=D+1 */
line_480:;
    D = D+1;
    /* BASIC: 490 D2=D-S */
line_490:;
    D2 = D-S;
    /* BASIC: 500 IF D2>M(N) THEN 580 */
line_500:;
    if (D2>M_arr[(int)(N)]) { goto line_580; }
    /* BASIC: 510 IF D2>0 THEN PRINT D2; */
line_510:;
    if (D2>0) { printf("%g ", (double)(D2)); }
    /* BASIC: 520 PRINT TAB(4+8*G); */
line_520:;
    { int _t; for(_t=0; _t<4+8*G; _t++) printf(" "); }
    /* BASIC: 530 NEXT G */
line_530:;
    G += (1); goto for_loop_G_470; end_for_G_470:;
    /* BASIC: 540 REM */
line_540:;
    /* REM */
    /* BASIC: 550 IF D2=M(N) THEN 590 */
line_550:;
    if (D2==M_arr[(int)(N)]) { goto line_590; }
    /* BASIC: 560 NEXT W */
line_560:;
    W += (1); goto for_loop_W_430; end_for_W_430:;
    /* BASIC: 570 REM */
line_570:;
    /* REM */
    /* BASIC: 580 D=D-G */
line_580:;
    D = D-G;
    /* BASIC: 590 NEXT N */
line_590:;
    N += (1); goto for_loop_N_180; end_for_N_180:;
    /* BASIC: 600 REM */
line_600:;
    /* REM */
    /* BASIC: 610 FOR I=1 TO 6: PRINT CHR$(10);: NEXT I */
line_610:;
    I = 1; for_loop_I_610: if (((1) >= 0 && I > (6)) || ((1) < 0 && I < (6))) goto end_for_I_610;
    printf("%s", basic_CHR(10));
    I += (1); goto for_loop_I_610; end_for_I_610:;
    /* BASIC: 620 DATA 0,31,28,31,30,31,30,31,31,30,31,30,31 */
line_620:;
    /* UNTRANSLATED: DATA 0,31,28,31,30,31,30,31,31,30,31,30,31 */
    /* BASIC: 630 REM  0,31,29,  ..., ON LEAP YEARS */
line_630:;
    /* REM  0,31,29,  ..., ON LEAP YEARS */
    /* BASIC: 640 END */
line_640:;
    exit(0);

    return 0;
}
