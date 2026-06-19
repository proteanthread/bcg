/*
 * Transpiled from chief.bas
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

/* Global variables */
static double B, C, F, G, H, I, J, K, LET, X, Y;
static char A_str[256] = {0};
static char D_str[256] = {0};
static char Z_str[256] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 2 PRINT TAB(30) "CHIEF" */
line_2:;
    { int _t; for(_t=0; _t<30; _t++) printf(" "); } printf("%s", "CHIEF"); printf("\n");
    /* BASIC: 4 PRINT TAB(15) "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 6 PRINT:PRINT:PRINT */
line_6:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 10 PRINT "I AM CHIEF NUMBERS FREEK, THE GREAT INDIAN MATH GOD." */
line_10:;
    printf("%s", "I AM CHIEF NUMBERS FREEK, THE GREAT INDIAN MATH GOD."); printf("\n");
    /* BASIC: 20 PRINT "ARE YOU READY TO TAKE THE TEST YOU CALLED ME OUT FOR"; */
line_20:;
    printf("%s", "ARE YOU READY TO TAKE THE TEST YOU CALLED ME OUT FOR");
    /* BASIC: 30 INPUT A$ */
line_30:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    /* BASIC: 40 IF A$="YES" THEN 60 */
line_40:;
    if (strcmp(A_str, "YES") == 0) { goto line_60; }
    /* BASIC: 50 PRINT "SHUT UP, PALE FACE WITH WISE TONGUE." */
line_50:;
    printf("%s", "SHUT UP, PALE FACE WITH WISE TONGUE."); printf("\n");
    /* BASIC: 60 PRINT " TAKE A NUMBER AND ADD 3. DIVIDE THIS NUMBER BY 5 AND" */
line_60:;
    printf("%s", " TAKE A NUMBER AND ADD 3. DIVIDE THIS NUMBER BY 5 AND"); printf("\n");
    /* BASIC: 70 PRINT "MULTIPLY BY 8. DIVIDE BY 5 AND ADD THE SAME. SUBTRACT 1." */
line_70:;
    printf("%s", "MULTIPLY BY 8. DIVIDE BY 5 AND ADD THE SAME. SUBTRACT 1."); printf("\n");
    /* BASIC: 80 PRINT "  WHAT DO YOU HAVE"; */
line_80:;
    printf("%s", "  WHAT DO YOU HAVE");
    /* BASIC: 90 INPUT B */
line_90:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &B);
    /* BASIC: 100 LET C = (B+1-5)*5/8*5-3 */
line_100:;
    /* UNTRANSLATED: LET C = (B+1-5)*5/8*5-3 */
    /* BASIC: 110 PRINT "I BET YOUR NUMBER WAS" C". AM I RIGHT"; */
line_110:;
    printf("%s", "I BET YOUR NUMBER WAS"); printf("%g ", (double)(C)); printf("%s", ". AM I RIGHT");
    /* BASIC: 120 INPUT D$ */
line_120:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", D_str);
    /* BASIC: 130 IF D$="YES" THEN 500 */
line_130:;
    if (strcmp(D_str, "YES") == 0) { goto line_500; }
    /* BASIC: 140 PRINT "WHAT WAS YOUR ORIGINAL NUMBER"; */
line_140:;
    printf("%s", "WHAT WAS YOUR ORIGINAL NUMBER");
    /* BASIC: 150 INPUT K */
line_150:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &K);
    /* BASIC: 155 LET F=K+3 */
line_155:;
    /* UNTRANSLATED: LET F=K+3 */
    /* BASIC: 160 LET G=F/5 */
line_160:;
    /* UNTRANSLATED: LET G=F/5 */
    /* BASIC: 170 LET H=G*8 */
line_170:;
    /* UNTRANSLATED: LET H=G*8 */
    /* BASIC: 180 LET I=H/5+5 */
line_180:;
    /* UNTRANSLATED: LET I=H/5+5 */
    /* BASIC: 190 LET J=I-1 */
line_190:;
    /* UNTRANSLATED: LET J=I-1 */
    /* BASIC: 200 PRINT "SO YOU THINK YOU'RE SO SMART, EH?" */
line_200:;
    printf("%s", "SO YOU THINK YOU'RE SO SMART, EH?"); printf("\n");
    /* BASIC: 210 PRINT "NOW WATCH." */
line_210:;
    printf("%s", "NOW WATCH."); printf("\n");
    /* BASIC: 230 PRINT K"PLUS 3 EQUALS"F". THIS DIVIDED BY 5 EQUALS"G";" */
line_230:;
    printf("%g ", (double)(K)); printf("%s", "PLUS 3 EQUALS"); printf("%g ", (double)(F)); printf("%s", ". THIS DIVIDED BY 5 EQUALS"); printf("%g ", (double)(G)); printf("%s", ";"); printf("\n");
    /* BASIC: 240 PRINT "THIS TIMES 8 EQUALS"H". IF WE DIVIDE BY 5 AND ADD 5," */
line_240:;
    printf("%s", "THIS TIMES 8 EQUALS"); printf("%g ", (double)(H)); printf("%s", ". IF WE DIVIDE BY 5 AND ADD 5,"); printf("\n");
    /* BASIC: 250 PRINT "WE GET"I", WHICH, MINUS 1, EQUALS"J"." */
line_250:;
    printf("%s", "WE GET"); printf("%g ", (double)(I)); printf("%s", ", WHICH, MINUS 1, EQUALS"); printf("%g ", (double)(J)); printf("%s", "."); printf("\n");
    /* BASIC: 260 PRINT "NOW DO YOU BELIEVE ME"; */
line_260:;
    printf("%s", "NOW DO YOU BELIEVE ME");
    /* BASIC: 270 INPUT Z$ */
line_270:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", Z_str);
    /* BASIC: 290 IF Z$="YES" THEN 500 */
line_290:;
    if (strcmp(Z_str, "YES") == 0) { goto line_500; }
    /* BASIC: 295 PRINT "YOU HAVE MADE ME MAD!!!" */
line_295:;
    printf("%s", "YOU HAVE MADE ME MAD!!!"); printf("\n");
    /* BASIC: 300 PRINT "THERE MUST BE A GREAT LIGHTNING BOLT!" */
line_300:;
    printf("%s", "THERE MUST BE A GREAT LIGHTNING BOLT!"); printf("\n");
    /* BASIC: 310 PRINT:PRINT */
line_310:;
    printf("\n");
    printf("\n");
    /* BASIC: 330 FOR X=30 TO 22 STEP -1 */
line_330:;
    X = 30; for_loop_X_330: if (((-1) >= 0 && X > (22)) || ((-1) < 0 && X < (22))) goto end_for_X_330;
    /* BASIC: 340 PRINT TAB(X) "X X" */
line_340:;
    { int _t; for(_t=0; _t<X; _t++) printf(" "); } printf("%s", "X X"); printf("\n");
    /* BASIC: 350 NEXT X */
line_350:;
    X += (-1); goto for_loop_X_330; end_for_X_330:;
    /* BASIC: 360 PRINT TAB(21) "X XXX" */
line_360:;
    { int _t; for(_t=0; _t<21; _t++) printf(" "); } printf("%s", "X XXX"); printf("\n");
    /* BASIC: 370 PRINT TAB(20) "X   X" */
line_370:;
    { int _t; for(_t=0; _t<20; _t++) printf(" "); } printf("%s", "X   X"); printf("\n");
    /* BASIC: 380 PRINT TAB(19) "XX X" */
line_380:;
    { int _t; for(_t=0; _t<19; _t++) printf(" "); } printf("%s", "XX X"); printf("\n");
    /* BASIC: 390 FOR Y=20 TO 13 STEP -1 */
line_390:;
    Y = 20; for_loop_Y_390: if (((-1) >= 0 && Y > (13)) || ((-1) < 0 && Y < (13))) goto end_for_Y_390;
    /* BASIC: 400 PRINT TAB(Y) "X X" */
line_400:;
    { int _t; for(_t=0; _t<Y; _t++) printf(" "); } printf("%s", "X X"); printf("\n");
    /* BASIC: 410 NEXT Y */
line_410:;
    Y += (-1); goto for_loop_Y_390; end_for_Y_390:;
    /* BASIC: 420 PRINT TAB(12) "XX" */
line_420:;
    { int _t; for(_t=0; _t<12; _t++) printf(" "); } printf("%s", "XX"); printf("\n");
    /* BASIC: 430 PRINT TAB(11) "X" */
line_430:;
    { int _t; for(_t=0; _t<11; _t++) printf(" "); } printf("%s", "X"); printf("\n");
    /* BASIC: 440 PRINT TAB(10) "*" */
line_440:;
    { int _t; for(_t=0; _t<10; _t++) printf(" "); } printf("%s", "*"); printf("\n");
    /* BASIC: 450 PRINT:PRINT"#########################":PRINT */
line_450:;
    printf("\n");
    printf("%s", "#########################"); printf("\n");
    printf("\n");
    /* BASIC: 470 PRINT "I HOPE YOU BELIEVE ME NOW, FOR YOUR SAKE!!" */
line_470:;
    printf("%s", "I HOPE YOU BELIEVE ME NOW, FOR YOUR SAKE!!"); printf("\n");
    /* BASIC: 480 GOTO 520 */
line_480:;
    goto line_520;
    /* BASIC: 510 PRINT "BYE!!!" */
line_510:;
    printf("%s", "BYE!!!"); printf("\n");
    /* BASIC: 520 END */
line_520:;
    exit(0);
    /* Undefined labels declared here to compile cleanly */
    line_500:;

    return 0;
}
