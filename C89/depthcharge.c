/*
 * Transpiled from depthcharge.bas
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
static double A, B, C, D, G, N, X, Y, Z;
static char A_str[256] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 2 PRINT TAB(30);"DEPTH CHARGE" */
line_2:;
    { int _t; for(_t=0; _t<30; _t++) printf(" "); } printf("%s", "DEPTH CHARGE"); printf("\n");
    /* BASIC: 4 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 6 PRINT: PRINT: PRINT */
line_6:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 20 INPUT "DIMENSION OF SEARCH AREA";G: PRINT */
line_20:;
    printf("%s", "DIMENSION OF SEARCH AREA"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &G);
    printf("\n");
    /* BASIC: 30 N=INT(LOG(G)/LOG(2))+1 */
line_30:;
    N = floor(log(G)/log(2))+1;
    /* BASIC: 40 PRINT "YOU ARE THE CAPTAIN OF THE DESTROYER USS COMPUTER" */
line_40:;
    printf("%s", "YOU ARE THE CAPTAIN OF THE DESTROYER USS COMPUTER"); printf("\n");
    /* BASIC: 50 PRINT "AN ENEMY SUB HAS BEEN CAUSING YOU TROUBLE.  YOUR" */
line_50:;
    printf("%s", "AN ENEMY SUB HAS BEEN CAUSING YOU TROUBLE.  YOUR"); printf("\n");
    /* BASIC: 60 PRINT "MISSION IS TO DESTROY IT.  YOU HAVE";N;"SHOTS." */
line_60:;
    printf("%s", "MISSION IS TO DESTROY IT.  YOU HAVE"); printf("%g ", (double)(N)); printf("%s", "SHOTS."); printf("\n");
    /* BASIC: 70 PRINT "SPECIFY DEPTH CHARGE EXPLOSION POINT WITH A" */
line_70:;
    printf("%s", "SPECIFY DEPTH CHARGE EXPLOSION POINT WITH A"); printf("\n");
    /* BASIC: 80 PRINT "TRIO OF NUMBERS -- THE FIRST TWO ARE THE" */
line_80:;
    printf("%s", "TRIO OF NUMBERS -- THE FIRST TWO ARE THE"); printf("\n");
    /* BASIC: 90 PRINT "SURFACE COORDINATES; THE THIRD IS THE DEPTH." */
line_90:;
    printf("%s", "SURFACE COORDINATES; THE THIRD IS THE DEPTH."); printf("\n");
    /* BASIC: 100 PRINT : PRINT "GOOD LUCK !": PRINT */
line_100:;
    printf("\n");
    printf("%s", "GOOD LUCK !"); printf("\n");
    printf("\n");
    /* BASIC: 110 A=INT(G*RND(1)) : B=INT(G*RND(1)) : C=INT(G*RND(1)) */
line_110:;
    A = floor(G*((double)rand() / (double)RAND_MAX));
    B = floor(G*((double)rand() / (double)RAND_MAX));
    C = floor(G*((double)rand() / (double)RAND_MAX));
    /* BASIC: 120 FOR D=1 TO N : PRINT : PRINT "TRIAL #";D; : INPUT X,Y,Z */
line_120:;
    D = 1; for_loop_D_120: if (((1) >= 0 && D > (N)) || ((1) < 0 && D < (N))) goto end_for_D_120;
    printf("\n");
    printf("%s", "TRIAL #"); printf("%g ", (double)(D));
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf %lf", &X, &Y, &Z);
    /* BASIC: 130 IF ABS(X-A)+ABS(Y-B)+ABS(Z-C)=0 THEN 300 */
line_130:;
    if (fabs(X-A)+fabs(Y-B)+fabs(Z-C)==0) { goto line_300; }
    /* BASIC: 140 GOSUB 500 : PRINT : NEXT D */
line_140:;
    gosub_stack[gosub_sp++] = 1; goto line_500; line_ret_1:;
    printf("\n");
    D += (1); goto for_loop_D_120; end_for_D_120:;
    /* BASIC: 200 PRINT : PRINT "YOU HAVE BEEN TORPEDOED!  ABANDON SHIP!" */
line_200:;
    printf("\n");
    printf("%s", "YOU HAVE BEEN TORPEDOED!  ABANDON SHIP!"); printf("\n");
    /* BASIC: 210 PRINT "THE SUBMARINE WAS AT";A;",";B;",";C : GOTO 400 */
line_210:;
    printf("%s", "THE SUBMARINE WAS AT"); printf("%g ", (double)(A)); printf("%s", ","); printf("%g ", (double)(B)); printf("%s", ","); printf("%g ", (double)(C)); printf("\n");
    goto line_400;
    /* BASIC: 300 PRINT : PRINT "B O O M ! ! YOU FOUND IT IN";D;"TRIES!" */
line_300:;
    printf("\n");
    printf("%s", "B O O M ! ! YOU FOUND IT IN"); printf("%g ", (double)(D)); printf("%s", "TRIES!"); printf("\n");
    /* BASIC: 400 PRINT : PRINT: INPUT "ANOTHER GAME (Y OR N)";A$ */
line_400:;
    printf("\n");
    printf("\n");
    printf("%s", "ANOTHER GAME (Y OR N)"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    /* BASIC: 410 IF A$="Y" THEN 100 */
line_410:;
    if (strcmp(A_str, "Y") == 0) { goto line_100; }
    /* BASIC: 420 PRINT "OK.  HOPE YOU ENJOYED YOURSELF." : GOTO 600 */
line_420:;
    printf("%s", "OK.  HOPE YOU ENJOYED YOURSELF."); printf("\n");
    goto line_600;
    /* BASIC: 500 PRINT "SONAR REPORTS SHOT WAS "; */
line_500:;
    printf("%s", "SONAR REPORTS SHOT WAS ");
    /* BASIC: 510 IF Y>B THEN PRINT "NORTH"; */
line_510:;
    if (Y>B) { printf("%s", "NORTH"); }
    /* BASIC: 520 IF Y<B THEN PRINT "SOUTH"; */
line_520:;
    if (Y<B) { printf("%s", "SOUTH"); }
    /* BASIC: 530 IF X>A THEN PRINT "EAST"; */
line_530:;
    if (X>A) { printf("%s", "EAST"); }
    /* BASIC: 540 IF X<A THEN PRINT "WEST"; */
line_540:;
    if (X<A) { printf("%s", "WEST"); }
    /* BASIC: 550 IF Y<>B OR X<>A THEN PRINT " AND"; */
line_550:;
    if (Y!=B   ||   X!=A) { printf("%s", " AND"); }
    /* BASIC: 560 IF Z>C THEN PRINT " TOO LOW." */
line_560:;
    if (Z>C) { printf("%s", " TOO LOW."); printf("\n"); }
    /* BASIC: 570 IF Z<C THEN PRINT " TOO HIGH." */
line_570:;
    if (Z<C) { printf("%s", " TOO HIGH."); printf("\n"); }
    /* BASIC: 580 IF Z=C THEN PRINT " DEPTH OK." */
line_580:;
    if (Z==C) { printf("%s", " DEPTH OK."); printf("\n"); }
    /* BASIC: 590 RETURN */
line_590:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 600 END */
line_600:;
    exit(0);

    return 0;
}
