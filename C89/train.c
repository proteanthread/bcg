/*
 * Transpiled from train.bas
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

/* Global variables */
static double A, C, D, E, T, V;
static char A_str[256] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 1 PRINT TAB(33);"TRAIN" */
line_1:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "TRAIN"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT: PRINT: PRINT */
line_3:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 4 PRINT "TIME - SPEED DISTANCE EXERCISE": PRINT */
line_4:;
    printf("%s", "TIME - SPEED DISTANCE EXERCISE"); printf("\n");
    printf("\n");
    /* BASIC: 10 C=INT(25*RND(1))+40 */
line_10:;
    C = floor(25*((double)rand() / (double)RAND_MAX))+40;
    /* BASIC: 15 D=INT(15*RND(1))+5 */
line_15:;
    D = floor(15*((double)rand() / (double)RAND_MAX))+5;
    /* BASIC: 20 T=INT(19*RND(1))+20 */
line_20:;
    T = floor(19*((double)rand() / (double)RAND_MAX))+20;
    /* BASIC: 25 PRINT " A CAR TRAVELING";C;"MPH CAN MAKE A CERTAIN TRIP IN" */
line_25:;
    printf("%s", " A CAR TRAVELING"); printf("%g ", (double)(C)); printf("%s", "MPH CAN MAKE A CERTAIN TRIP IN"); printf("\n");
    /* BASIC: 30 PRINT D;"HOURS LESS THAN A TRAIN TRAVELING AT";T;"MPH." */
line_30:;
    printf("%g ", (double)(D)); printf("%s", "HOURS LESS THAN A TRAIN TRAVELING AT"); printf("%g ", (double)(T)); printf("%s", "MPH."); printf("\n");
    /* BASIC: 35 PRINT "HOW LONG DOES THE TRIP TAKE BY CAR"; */
line_35:;
    printf("%s", "HOW LONG DOES THE TRIP TAKE BY CAR");
    /* BASIC: 40 INPUT A */
line_40:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &A);
    /* BASIC: 45 V=D*T/(C-T) */
line_45:;
    V = D*T/(C-T);
    /* BASIC: 50 E=INT(ABS((V-A)*100/A)+.5) */
line_50:;
    E = floor(fabs((V-A)*100/A)+.5);
    /* BASIC: 55 IF E>5 THEN 70 */
line_55:;
    if (E>5) { goto line_70; }
    /* BASIC: 60 PRINT "GOOD! ANSWER WITHIN";E;"PERCENT." */
line_60:;
    printf("%s", "GOOD! ANSWER WITHIN"); printf("%g ", (double)(E)); printf("%s", "PERCENT."); printf("\n");
    /* BASIC: 65 GOTO 80 */
line_65:;
    goto line_80;
    /* BASIC: 70 PRINT "SORRY.  YOU WERE OFF BY";E;"PERCENT." */
line_70:;
    printf("%s", "SORRY.  YOU WERE OFF BY"); printf("%g ", (double)(E)); printf("%s", "PERCENT."); printf("\n");
    /* BASIC: 80 PRINT "CORRECT ANSWER IS";V;"HOURS." */
line_80:;
    printf("%s", "CORRECT ANSWER IS"); printf("%g ", (double)(V)); printf("%s", "HOURS."); printf("\n");
    /* BASIC: 90 PRINT */
line_90:;
    printf("\n");
    /* BASIC: 95 PRINT "ANOTHER PROBLEM (YES OR NO)"; */
line_95:;
    printf("%s", "ANOTHER PROBLEM (YES OR NO)");
    /* BASIC: 100 INPUT A$ */
line_100:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    /* BASIC: 105 PRINT */
line_105:;
    printf("\n");
    /* BASIC: 110 IF A$="YES" THEN 10 */
line_110:;
    if (strcmp(A_str, "YES") == 0) { goto line_10; }
    /* BASIC: 999 END */
line_999:;
    exit(0);

    return 0;
}
