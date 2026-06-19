/*
 * Transpiled from guess.bas
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
static int gosub_stack[256];
static int gosub_sp = 0;
static double G, H, L, L1, M, N;
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 1 PRINT TAB(33);"GUESS" */
line_1:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "GUESS"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT:PRINT:PRINT */
line_3:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 4 PRINT "THIS IS A NUMBER GUESSING GAME. I'LL THINK" */
line_4:;
    printf("%s", "THIS IS A NUMBER GUESSING GAME. I'LL THINK"); printf("\n");
    /* BASIC: 5 PRINT "OF A NUMBER BETWEEN 1 AND ANY LIMIT YOU WANT." */
line_5:;
    printf("%s", "OF A NUMBER BETWEEN 1 AND ANY LIMIT YOU WANT."); printf("\n");
    /* BASIC: 6 PRINT "THEN YOU HAVE TO GUESS WHAT IT IS." */
line_6:;
    printf("%s", "THEN YOU HAVE TO GUESS WHAT IT IS."); printf("\n");
    /* BASIC: 7 PRINT */
line_7:;
    printf("\n");
    /* BASIC: 8 PRINT "WHAT LIMIT DO YOU WANT"; */
line_8:;
    printf("%s", "WHAT LIMIT DO YOU WANT");
    /* BASIC: 9 INPUT L */
line_9:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &L);
    /* BASIC: 10 PRINT */
line_10:;
    printf("\n");
    /* BASIC: 11 L1=INT(LOG(L)/LOG(2))+1 */
line_11:;
    L1 = floor(log(L)/log(2))+1;
    /* BASIC: 12 PRINT "I'M THINKING OF A NUMBER BETWEEN 1 AND";L */
line_12:;
    printf("%s", "I'M THINKING OF A NUMBER BETWEEN 1 AND"); printf("%g ", (double)(L)); printf("\n");
    /* BASIC: 13 G=1 */
line_13:;
    G = 1;
    /* BASIC: 14 PRINT "NOW YOU TRY TO GUESS WHAT IT IS." */
line_14:;
    printf("%s", "NOW YOU TRY TO GUESS WHAT IT IS."); printf("\n");
    /* BASIC: 15 M=INT(L*RND(1)+1) */
line_15:;
    M = floor(L*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 20 INPUT N */
line_20:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &N);
    /* BASIC: 21 IF N>0 THEN 25 */
line_21:;
    if (N>0) { goto line_25; }
    /* BASIC: 22 GOSUB 70 */
line_22:;
    gosub_stack[gosub_sp++] = 1; goto line_70; line_ret_1:;
    /* BASIC: 23 GOTO 1 */
line_23:;
    goto line_1;
    /* BASIC: 25 IF N=M THEN 50 */
line_25:;
    if (N==M) { goto line_50; }
    /* BASIC: 30 G=G+1 */
line_30:;
    G = G+1;
    /* BASIC: 31 IF N>M THEN 40 */
line_31:;
    if (N>M) { goto line_40; }
    /* BASIC: 32 PRINT "TOO LOW. TRY A BIGGER ANSWER." */
line_32:;
    printf("%s", "TOO LOW. TRY A BIGGER ANSWER."); printf("\n");
    /* BASIC: 33 GOTO 20 */
line_33:;
    goto line_20;
    /* BASIC: 40 PRINT "TOO HIGH. TRY A SMALLER ANSWER." */
line_40:;
    printf("%s", "TOO HIGH. TRY A SMALLER ANSWER."); printf("\n");
    /* BASIC: 42 GOTO 20 */
line_42:;
    goto line_20;
    /* BASIC: 50 PRINT "THAT'S IT! YOU GOT IT IN";G;"TRIES." */
line_50:;
    printf("%s", "THAT'S IT! YOU GOT IT IN"); printf("%g ", (double)(G)); printf("%s", "TRIES."); printf("\n");
    /* BASIC: 52 IF G<L1 THEN 58 */
line_52:;
    if (G<L1) { goto line_58; }
    /* BASIC: 54 IF G=L1 THEN 60 */
line_54:;
    if (G==L1) { goto line_60; }
    /* BASIC: 56 PRINT "YOU SHOULD HAVE BEEN ABLE TO GET IT IN ONLY";L1 */
line_56:;
    printf("%s", "YOU SHOULD HAVE BEEN ABLE TO GET IT IN ONLY"); printf("%g ", (double)(L1)); printf("\n");
    /* BASIC: 57 GOTO 65 */
line_57:;
    goto line_65;
    /* BASIC: 58 PRINT "VERY "; */
line_58:;
    printf("%s", "VERY ");
    /* BASIC: 60 PRINT "GOOD." */
line_60:;
    printf("%s", "GOOD."); printf("\n");
    /* BASIC: 65 GOSUB 70 */
line_65:;
    gosub_stack[gosub_sp++] = 2; goto line_70; line_ret_2:;
    /* BASIC: 66 GOTO 12 */
line_66:;
    goto line_12;
    /* BASIC: 70 FOR H=1 TO 5 */
line_70:;
    H = 1; for_loop_H_70: if (((1) >= 0 && H > (5)) || ((1) < 0 && H < (5))) goto end_for_H_70;
    /* BASIC: 71 PRINT */
line_71:;
    printf("\n");
    /* BASIC: 72 NEXT H */
line_72:;
    H += (1); goto for_loop_H_70; end_for_H_70:;
    /* BASIC: 73 RETURN */
line_73:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 99 END */
line_99:;
    exit(0);

    return 0;
}
