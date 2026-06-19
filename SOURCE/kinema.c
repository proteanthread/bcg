/*
 * Transpiled from kinema.bas
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
static int gosub_stack[256];
static int gosub_sp = 0;
static double A, G, Q, T, V;
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(33);"KINEMA" */
line_10:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "KINEMA"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT: PRINT: PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 100 PRINT */
line_100:;
    printf("\n");
    /* BASIC: 105 PRINT */
line_105:;
    printf("\n");
    /* BASIC: 106 Q=0 */
line_106:;
    Q = 0;
    /* BASIC: 110 V=5+INT(35*RND(1)) */
line_110:;
    V = 5+floor(35*((double)rand() / (double)RAND_MAX));
    /* BASIC: 111 PRINT "A BALL IS THROWN UPWARDS AT";V;"METERS PER SECOND." */
line_111:;
    printf("%s", "A BALL IS THROWN UPWARDS AT"); printf("%g ", (double)(V)); printf("%s", "METERS PER SECOND."); printf("\n");
    /* BASIC: 112 PRINT */
line_112:;
    printf("\n");
    /* BASIC: 115 A=.05*V^2 */
line_115:;
    A = .05*pow(V, 2);
    /* BASIC: 116 PRINT "HOW HIGH WILL IT GO (IN METERS)"; */
line_116:;
    printf("%s", "HOW HIGH WILL IT GO (IN METERS)");
    /* BASIC: 117 GOSUB 500 */
line_117:;
    gosub_stack[gosub_sp++] = 1; goto line_500; line_ret_1:;
    /* BASIC: 120 A=V/5 */
line_120:;
    A = V/5;
    /* BASIC: 122 PRINT "HOW LONG UNTIL IT RETURNS (IN SECONDS)"; */
line_122:;
    printf("%s", "HOW LONG UNTIL IT RETURNS (IN SECONDS)");
    /* BASIC: 124 GOSUB 500 */
line_124:;
    gosub_stack[gosub_sp++] = 2; goto line_500; line_ret_2:;
    /* BASIC: 130 T=1+INT(2*V*RND(1))/10 */
line_130:;
    T = 1+floor(2*V*((double)rand() / (double)RAND_MAX))/10;
    /* BASIC: 132 A=V-10*T */
line_132:;
    A = V-10*T;
    /* BASIC: 134 PRINT "WHAT WILL ITS VELOCITY BE AFTER";T;"SECONDS"; */
line_134:;
    printf("%s", "WHAT WILL ITS VELOCITY BE AFTER"); printf("%g ", (double)(T)); printf("%s", "SECONDS");
    /* BASIC: 136 GOSUB 500 */
line_136:;
    gosub_stack[gosub_sp++] = 3; goto line_500; line_ret_3:;
    /* BASIC: 140 PRINT */
line_140:;
    printf("\n");
    /* BASIC: 150 PRINT Q;"RIGHT OUT OF 3."; */
line_150:;
    printf("%g ", (double)(Q)); printf("%s", "RIGHT OUT OF 3.");
    /* BASIC: 160 IF Q<2 THEN 100 */
line_160:;
    if (Q<2) { goto line_100; }
    /* BASIC: 170 PRINT "  NOT BAD." */
line_170:;
    printf("%s", "  NOT BAD."); printf("\n");
    /* BASIC: 180 GOTO 100 */
line_180:;
    goto line_100;
    /* BASIC: 500 INPUT G */
line_500:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &G);
    /* BASIC: 502 IF ABS((G-A)/A)<.15 THEN 510 */
line_502:;
    if (fabs((G-A)/A)<.15) { goto line_510; }
    /* BASIC: 504 PRINT "NOT EVEN CLOSE...." */
line_504:;
    printf("%s", "NOT EVEN CLOSE...."); printf("\n");
    /* BASIC: 506 GOTO 512 */
line_506:;
    goto line_512;
    /* BASIC: 510 PRINT "CLOSE ENOUGH." */
line_510:;
    printf("%s", "CLOSE ENOUGH."); printf("\n");
    /* BASIC: 511 Q=Q+1 */
line_511:;
    Q = Q+1;
    /* BASIC: 512 PRINT "CORRECT ANSWER IS ";A */
line_512:;
    printf("%s", "CORRECT ANSWER IS "); printf("%g ", (double)(A)); printf("\n");
    /* BASIC: 520 PRINT */
line_520:;
    printf("\n");
    /* BASIC: 530 RETURN */
line_530:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 999 END */
line_999:;
    exit(0);

    return 0;
}
