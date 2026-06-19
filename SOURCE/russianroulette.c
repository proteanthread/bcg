/*
 * Transpiled from russianroulette.bas
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
static double I, N;
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 1 PRINT TAB(28);"RUSSIAN ROULETTE" */
line_1:;
    { int _t; for(_t=0; _t<28; _t++) printf(" "); } printf("%s", "RUSSIAN ROULETTE"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT:PRINT:PRINT */
line_3:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 5 PRINT "THIS IS A GAME OF >>>>>>>>>>RUSSIAN ROULETTE." */
line_5:;
    printf("%s", "THIS IS A GAME OF >>>>>>>>>>RUSSIAN ROULETTE."); printf("\n");
    /* BASIC: 10 PRINT:PRINT "HERE IS A REVOLVER." */
line_10:;
    printf("\n");
    printf("%s", "HERE IS A REVOLVER."); printf("\n");
    /* BASIC: 20 PRINT "TYPE '1' TO SPIN CHAMBER AND PULL TRIGGER." */
line_20:;
    printf("%s", "TYPE '1' TO SPIN CHAMBER AND PULL TRIGGER."); printf("\n");
    /* BASIC: 22 PRINT "TYPE '2' TO GIVE UP." */
line_22:;
    printf("%s", "TYPE '2' TO GIVE UP."); printf("\n");
    /* BASIC: 23 PRINT "GO"; */
line_23:;
    printf("%s", "GO");
    /* BASIC: 25 N=0 */
line_25:;
    N = 0;
    /* BASIC: 30 INPUT I */
line_30:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &I);
    /* BASIC: 31 IF I<>2 THEN 35 */
line_31:;
    if (I!=2) { goto line_35; }
    /* BASIC: 32 PRINT "     CHICKEN!!!!!" */
line_32:;
    printf("%s", "     CHICKEN!!!!!"); printf("\n");
    /* BASIC: 33 GOTO 72 */
line_33:;
    goto line_72;
    /* BASIC: 35 N=N+1 */
line_35:;
    N = N+1;
    /* BASIC: 40 IF RND(1)>.833333 THEN 70 */
line_40:;
    if (((double)rand() / (double)RAND_MAX)>.833333) { goto line_70; }
    /* BASIC: 45 IF N>10 THEN 80 */
line_45:;
    if (N>10) { goto line_80; }
    /* BASIC: 50 PRINT "- CLICK -" */
line_50:;
    printf("%s", "- CLICK -"); printf("\n");
    /* BASIC: 60 PRINT: GOTO 30 */
line_60:;
    printf("\n");
    goto line_30;
    /* BASIC: 70 PRINT "     BANG!!!!!   YOU'RE DEAD!" */
line_70:;
    printf("%s", "     BANG!!!!!   YOU'RE DEAD!"); printf("\n");
    /* BASIC: 71 PRINT "CONDOLENCES WILL BE SENT TO YOUR RELATIVES." */
line_71:;
    printf("%s", "CONDOLENCES WILL BE SENT TO YOUR RELATIVES."); printf("\n");
    /* BASIC: 72 PRINT:PRINT:PRINT */
line_72:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 75 PRINT "...NEXT VICTIM...":GOTO 20 */
line_75:;
    printf("%s", "...NEXT VICTIM..."); printf("\n");
    goto line_20;
    /* BASIC: 80 PRINT "YOU WIN!!!!!" */
line_80:;
    printf("%s", "YOU WIN!!!!!"); printf("\n");
    /* BASIC: 85 PRINT "LET SOMEONE ELSE BLOW HIS BRAINS OUT." */
line_85:;
    printf("%s", "LET SOMEONE ELSE BLOW HIS BRAINS OUT."); printf("\n");
    /* BASIC: 90 GOTO 10 */
line_90:;
    goto line_10;
    /* BASIC: 99 END */
line_99:;
    exit(0);

    return 0;
}
