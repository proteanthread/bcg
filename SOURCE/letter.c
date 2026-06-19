/*
 * Transpiled from letter.bas
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
static double A, G, L, N;
static char A_str[256] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(33);"LETTER" */
line_10:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "LETTER"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 100 PRINT "LETTER GUESSING GAME": PRINT */
line_100:;
    printf("%s", "LETTER GUESSING GAME"); printf("\n");
    printf("\n");
    /* BASIC: 210 PRINT "I'LL THINK OF A LETTER OF THE ALPHABET, A TO Z." */
line_210:;
    printf("%s", "I'LL THINK OF A LETTER OF THE ALPHABET, A TO Z."); printf("\n");
    /* BASIC: 220 PRINT "TRY TO GUESS MY LETTER AND I'LL GIVE YOU CLUES" */
line_220:;
    printf("%s", "TRY TO GUESS MY LETTER AND I'LL GIVE YOU CLUES"); printf("\n");
    /* BASIC: 230 PRINT "AS TO HOW CLOSE YOU'RE GETTING TO MY LETTER." */
line_230:;
    printf("%s", "AS TO HOW CLOSE YOU'RE GETTING TO MY LETTER."); printf("\n");
    /* BASIC: 310 L=65+INT(RND(1)*26) */
line_310:;
    L = 65+floor(((double)rand() / (double)RAND_MAX)*26);
    /* BASIC: 320 G=0 */
line_320:;
    G = 0;
    /* BASIC: 340 PRINT: PRINT "O.K., I HAVE A LETTER.  START GUESSING." */
line_340:;
    printf("\n");
    printf("%s", "O.K., I HAVE A LETTER.  START GUESSING."); printf("\n");
    /* BASIC: 410 PRINT: PRINT "WHAT IS YOUR GUESS"; */
line_410:;
    printf("\n");
    printf("%s", "WHAT IS YOUR GUESS");
    /* BASIC: 420 G=G+1 */
line_420:;
    G = G+1;
    /* BASIC: 430 INPUT A$: A=ASC(A$): PRINT */
line_430:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    A = basic_ASC(A_str);
    printf("\n");
    /* BASIC: 440 IF A=L THEN 500 */
line_440:;
    if (A==L) { goto line_500; }
    /* BASIC: 450 IF A>L THEN 480 */
line_450:;
    if (A>L) { goto line_480; }
    /* BASIC: 460 PRINT "TOO LOW.  TRY A HIGHER LETTER.": GOTO 410 */
line_460:;
    printf("%s", "TOO LOW.  TRY A HIGHER LETTER."); printf("\n");
    goto line_410;
    /* BASIC: 480 PRINT "TOO HIGH.  TRY A LOWER LETTER.": GOTO 410 */
line_480:;
    printf("%s", "TOO HIGH.  TRY A LOWER LETTER."); printf("\n");
    goto line_410;
    /* BASIC: 500 PRINT: PRINT "YOU GOT IT IN";G;"GUESSES!!" */
line_500:;
    printf("\n");
    printf("%s", "YOU GOT IT IN"); printf("%g ", (double)(G)); printf("%s", "GUESSES!!"); printf("\n");
    /* BASIC: 504 IF G<=5 THEN 508 */
line_504:;
    if (G<=5) { goto line_508; }
    /* BASIC: 506 PRINT "BUT IT SHOULDN'T TAKE MORE THAN 5 GUESSES!": GOTO 515 */
line_506:;
    printf("%s", "BUT IT SHOULDN'T TAKE MORE THAN 5 GUESSES!"); printf("\n");
    goto line_515;
    /* BASIC: 508 PRINT "GOOD JOB !!!!!" */
line_508:;
    printf("%s", "GOOD JOB !!!!!"); printf("\n");
    /* BASIC: 510 FOR N=1 TO 15: PRINT CHR$(7);: NEXT N */
line_510:;
    N = 1; for_loop_N_510: if (((1) >= 0 && N > (15)) || ((1) < 0 && N < (15))) goto end_for_N_510;
    printf("%s", basic_CHR(7));
    N += (1); goto for_loop_N_510; end_for_N_510:;
    /* BASIC: 515 PRINT */
line_515:;
    printf("\n");
    /* BASIC: 520 PRINT "LET'S PLAN AGAIN....." */
line_520:;
    printf("%s", "LET'S PLAN AGAIN....."); printf("\n");
    /* BASIC: 530 GOTO 310 */
line_530:;
    goto line_310;
    /* BASIC: 999 END */
line_999:;
    exit(0);

    return 0;
}
