/*
 * Transpiled from hurkle.bas
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
static double A, B, G, K, N, X, Y;
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(33);"HURKLE" */
line_10:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "HURKLE"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 110 N=5 */
line_110:;
    N = 5;
    /* BASIC: 120 G=10 */
line_120:;
    G = 10;
    /* BASIC: 210 PRINT */
line_210:;
    printf("\n");
    /* BASIC: 220 PRINT "A HURKLE IS HIDING ON A";G;"BY";G;"GRID. HOMEBASE" */
line_220:;
    printf("%s", "A HURKLE IS HIDING ON A"); printf("%g ", (double)(G)); printf("%s", "BY"); printf("%g ", (double)(G)); printf("%s", "GRID. HOMEBASE"); printf("\n");
    /* BASIC: 230 PRINT "ON THE GRID IS POINT 0,0 IN THE SOUTHWEST CORNER," */
line_230:;
    printf("%s", "ON THE GRID IS POINT 0,0 IN THE SOUTHWEST CORNER,"); printf("\n");
    /* BASIC: 235 PRINT "AND ANY POINT ON THE GRID IS DESIGNATED BY A" */
line_235:;
    printf("%s", "AND ANY POINT ON THE GRID IS DESIGNATED BY A"); printf("\n");
    /* BASIC: 240 PRINT "PAIR OF WHOLE NUMBERS SEPERATED BY A COMMA. THE FIRST" */
line_240:;
    printf("%s", "PAIR OF WHOLE NUMBERS SEPERATED BY A COMMA. THE FIRST"); printf("\n");
    /* BASIC: 245 PRINT "NUMBER IS THE HORIZONTAL POSITION AND THE SECOND NUMBER" */
line_245:;
    printf("%s", "NUMBER IS THE HORIZONTAL POSITION AND THE SECOND NUMBER"); printf("\n");
    /* BASIC: 246 PRINT "IS THE VERTICAL POSITION. YOU MUST TRY TO" */
line_246:;
    printf("%s", "IS THE VERTICAL POSITION. YOU MUST TRY TO"); printf("\n");
    /* BASIC: 250 PRINT "GUESS THE HURKLE'S GRIDPOINT. YOU GET";N;"TRIES." */
line_250:;
    printf("%s", "GUESS THE HURKLE'S GRIDPOINT. YOU GET"); printf("%g ", (double)(N)); printf("%s", "TRIES."); printf("\n");
    /* BASIC: 260 PRINT "AFTER EACH TRY, I WILL TELL YOU THE APPROXIMATE" */
line_260:;
    printf("%s", "AFTER EACH TRY, I WILL TELL YOU THE APPROXIMATE"); printf("\n");
    /* BASIC: 270 PRINT "DIRECTION TO GO TO LOOK FOR THE HURKLE." */
line_270:;
    printf("%s", "DIRECTION TO GO TO LOOK FOR THE HURKLE."); printf("\n");
    /* BASIC: 280 PRINT */
line_280:;
    printf("\n");
    /* BASIC: 285 A=INT(G*RND(1)) */
line_285:;
    A = floor(G*((double)rand() / (double)RAND_MAX));
    /* BASIC: 286 B=INT(G*RND(1)) */
line_286:;
    B = floor(G*((double)rand() / (double)RAND_MAX));
    /* BASIC: 310 FOR K=1 TO N */
line_310:;
    K = 1; for_loop_K_310: if (((1) >= 0 && K > (N)) || ((1) < 0 && K < (N))) goto end_for_K_310;
    /* BASIC: 320 PRINT "GUESS #";K; */
line_320:;
    printf("%s", "GUESS #"); printf("%g ", (double)(K));
    /* BASIC: 330 INPUT X,Y */
line_330:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf", &X, &Y);
    /* BASIC: 340 IF ABS(X-A)+ABS(Y-B)=0 THEN 500 */
line_340:;
    if (fabs(X-A)+fabs(Y-B)==0) { goto line_500; }
    /* BASIC: 350 REM PRINT INFO */
line_350:;
    // REM PRINT INFO
    /* BASIC: 360 GOSUB 610 */
line_360:;
    gosub_stack[gosub_sp++] = 1; goto line_610; line_ret_1:;
    /* BASIC: 370 PRINT */
line_370:;
    printf("\n");
    /* BASIC: 380 NEXT K */
line_380:;
    K += (1); goto for_loop_K_310; end_for_K_310:;
    /* BASIC: 410 PRINT */
line_410:;
    printf("\n");
    /* BASIC: 420 PRINT "SORRY, THAT'S";N;"GUESSES." */
line_420:;
    printf("%s", "SORRY, THAT'S"); printf("%g ", (double)(N)); printf("%s", "GUESSES."); printf("\n");
    /* BASIC: 430 PRINT "THE HURKLE IS AT ";A;",";B */
line_430:;
    printf("%s", "THE HURKLE IS AT "); printf("%g ", (double)(A)); printf("%s", ","); printf("%g ", (double)(B)); printf("\n");
    /* BASIC: 440 PRINT */
line_440:;
    printf("\n");
    /* BASIC: 450 PRINT "LET'S PLAY AGAIN, HURKLE IS HIDING." */
line_450:;
    printf("%s", "LET'S PLAY AGAIN, HURKLE IS HIDING."); printf("\n");
    /* BASIC: 460 PRINT */
line_460:;
    printf("\n");
    /* BASIC: 470 GOTO 285 */
line_470:;
    goto line_285;
    /* BASIC: 500 REM */
line_500:;
    // REM
    /* BASIC: 510 PRINT */
line_510:;
    printf("\n");
    /* BASIC: 520 PRINT "YOU FOUND HIM IN";K;"GUESSES!" */
line_520:;
    printf("%s", "YOU FOUND HIM IN"); printf("%g ", (double)(K)); printf("%s", "GUESSES!"); printf("\n");
    /* BASIC: 540 GOTO 440 */
line_540:;
    goto line_440;
    /* BASIC: 610 PRINT "GO "; */
line_610:;
    printf("%s", "GO ");
    /* BASIC: 620 IF Y=B THEN 670 */
line_620:;
    if (Y==B) { goto line_670; }
    /* BASIC: 630 IF Y<B THEN 660 */
line_630:;
    if (Y<B) { goto line_660; }
    /* BASIC: 640 PRINT "SOUTH"; */
line_640:;
    printf("%s", "SOUTH");
    /* BASIC: 650 GOTO 670 */
line_650:;
    goto line_670;
    /* BASIC: 660 PRINT "NORTH"; */
line_660:;
    printf("%s", "NORTH");
    /* BASIC: 670 IF X=A THEN 720 */
line_670:;
    if (X==A) { goto line_720; }
    /* BASIC: 680 IF X<A THEN 710 */
line_680:;
    if (X<A) { goto line_710; }
    /* BASIC: 690 PRINT "WEST"; */
line_690:;
    printf("%s", "WEST");
    /* BASIC: 700 GOTO 720 */
line_700:;
    goto line_720;
    /* BASIC: 710 PRINT "EAST"; */
line_710:;
    printf("%s", "EAST");
    /* BASIC: 720 PRINT */
line_720:;
    printf("\n");
    /* BASIC: 730 RETURN */
line_730:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 999 END */
line_999:;
    exit(0);

    return 0;
}
