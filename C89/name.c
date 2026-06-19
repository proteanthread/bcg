/*
 * Transpiled from name.bas
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
static double I, J, L;
static char A_str[256] = {0};
static char B_str[256] = {0};
static char D_str[256] = {0};
static char T_str[256] = {0};
static char B_str_arr[1000][64] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 1 PRINT TAB(34);"NAME" */
line_1:;
    { int _t; for(_t=0; _t<34; _t++) printf(" "); } printf("%s", "NAME"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT: PRINT: PRINT */
line_3:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 5 DIM B$(40) */
line_5:;
    /* DIM B$(40) (handled statically) */
    /* BASIC: 10 PRINT "HELLO.": PRINT "MY NAME IS CREATIVE COMPUTER." */
line_10:;
    printf("%s", "HELLO."); printf("\n");
    printf("%s", "MY NAME IS CREATIVE COMPUTER."); printf("\n");
    /* BASIC: 20 PRINT "WHAT'S YOUR NAME (FIRST AND LAST";: INPUT A$: L=LEN(A$) */
line_20:;
    printf("%s", "WHAT'S YOUR NAME (FIRST AND LAST");
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    L = basic_LEN(A_str);
    /* BASIC: 30 PRINT: PRINT "THANK YOU, "; */
line_30:;
    printf("\n");
    printf("%s", "THANK YOU, ");
    /* BASIC: 40 FOR I=1 TO L: B$(I)=MID$(A$,I,1): NEXT I */
line_40:;
    I = 1; for_loop_I_40: if (((1) >= 0 && I > (L)) || ((1) < 0 && I < (L))) goto end_for_I_40;
    str_assign(B_str_arr[(int)(I)], sizeof(B_str_arr[(int)(I)]), basic_MID(A_str,I,1));
    I += (1); goto for_loop_I_40; end_for_I_40:;
    /* BASIC: 50 FOR I=L TO 1 STEP -1: PRINT B$(I);: NEXT I */
line_50:;
    I = L; for_loop_I_50: if (((-1) >= 0 && I > (1)) || ((-1) < 0 && I < (1))) goto end_for_I_50;
    printf("%s", B_str_arr[(int)(I)]);
    I += (-1); goto for_loop_I_50; end_for_I_50:;
    /* BASIC: 60 PRINT ".": PRINT "OOPS!  I GUESS I GOT IT BACKWARDS.  A SMART" */
line_60:;
    printf("%s", "."); printf("\n");
    printf("%s", "OOPS!  I GUESS I GOT IT BACKWARDS.  A SMART"); printf("\n");
    /* BASIC: 70 PRINT "COMPUTER LIKE ME SHOULDN'T MAKE A MISTAKE LIKE THAT!": PRINT */
line_70:;
    printf("%s", "COMPUTER LIKE ME SHOULDN'T MAKE A MISTAKE LIKE THAT!"); printf("\n");
    printf("\n");
    /* BASIC: 80 PRINT "BUT I JUST NOTICED YOUR LETTERS ARE OUT OF ORDER." */
line_80:;
    printf("%s", "BUT I JUST NOTICED YOUR LETTERS ARE OUT OF ORDER."); printf("\n");
    /* BASIC: 90 PRINT "LET'S PUT THEM IN ORDER LIKE THIS: "; */
line_90:;
    printf("%s", "LET'S PUT THEM IN ORDER LIKE THIS: ");
    /* BASIC: 100 FOR J=2 TO L: I=J-1: T$=B$(J) */
line_100:;
    J = 2; for_loop_J_100: if (((1) >= 0 && J > (L)) || ((1) < 0 && J < (L))) goto end_for_J_100;
    I = J-1;
    str_assign(T_str, sizeof(T_str), B_str_arr[(int)(J)]);
    /* BASIC: 110 IF T$>B$(I) THEN 130 */
line_110:;
    if (strcmp(T_str, B_str_arr[(int)(I)]) > 0) { goto line_130; }
    /* BASIC: 120 B$(I+1)=B$(I): I=I-1: IF I>0 THEN 110 */
line_120:;
    str_assign(B_str_arr[(int)(I+1)], sizeof(B_str_arr[(int)(I+1)]), B_str_arr[(int)(I)]);
    I = I-1;
    if (I>0) { goto line_110; }
    /* BASIC: 130 B$(I+1)=T$: NEXT J */
line_130:;
    str_assign(B_str_arr[(int)(I+1)], sizeof(B_str_arr[(int)(I+1)]), T_str);
    J += (1); goto for_loop_J_100; end_for_J_100:;
    /* BASIC: 140 FOR I=1 TO L: PRINT B$(I);: NEXT I: PRINT: PRINT */
line_140:;
    I = 1; for_loop_I_140: if (((1) >= 0 && I > (L)) || ((1) < 0 && I < (L))) goto end_for_I_140;
    printf("%s", B_str_arr[(int)(I)]);
    I += (1); goto for_loop_I_140; end_for_I_140:;
    printf("\n");
    printf("\n");
    /* BASIC: 150 PRINT "DON'T YOU LIKE THAT BETTER";: INPUT D$ */
line_150:;
    printf("%s", "DON'T YOU LIKE THAT BETTER");
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", D_str);
    /* BASIC: 160 IF D$="YES" THEN 180 */
line_160:;
    if (strcmp(D_str, "YES") == 0) { goto line_180; }
    /* BASIC: 170 PRINT: PRINT "I'M SORRY YOU DON'T LIKE IT THAT WAY.": GOTO 200 */
line_170:;
    printf("\n");
    printf("%s", "I'M SORRY YOU DON'T LIKE IT THAT WAY."); printf("\n");
    goto line_200;
    /* BASIC: 180 PRINT: PRINT "I KNEW YOU'D AGREE!!" */
line_180:;
    printf("\n");
    printf("%s", "I KNEW YOU'D AGREE!!"); printf("\n");
    /* BASIC: 200 PRINT: PRINT "I REALLY ENJOYED MEETING YOU ";A$;"." */
line_200:;
    printf("\n");
    printf("%s", "I REALLY ENJOYED MEETING YOU "); printf("%s", A_str); printf("%s", "."); printf("\n");
    /* BASIC: 210 PRINT "HAVE A NICE DAY!" */
line_210:;
    printf("%s", "HAVE A NICE DAY!"); printf("\n");
    /* BASIC: 999 END */
line_999:;
    exit(0);

    return 0;
}
