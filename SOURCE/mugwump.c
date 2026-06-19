/*
 * Transpiled from mugwump.bas
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
static double D, I, J, M, N, P, T;
static double P_arr[20000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 1 PRINT TAB(33);"MUGWUMP" */
line_1:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "MUGWUMP"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT:PRINT:PRINT */
line_3:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 4 REM     COURTESY PEOPLE'S COMPUTER COMPANY */
line_4:;
    // REM     COURTESY PEOPLE'S COMPUTER COMPANY
    /* BASIC: 10 DIM P(4,2) */
line_10:;
    /* DIM P(4,2) (handled statically) */
    /* BASIC: 20 PRINT "THE OBJECT OF THIS GAME IS TO FIND FOUR MUGWUMPS" */
line_20:;
    printf("%s", "THE OBJECT OF THIS GAME IS TO FIND FOUR MUGWUMPS"); printf("\n");
    /* BASIC: 30 PRINT "HIDDEN ON A 10 BY 10 GRID.  HOMEBASE IS POSITION 0,0." */
line_30:;
    printf("%s", "HIDDEN ON A 10 BY 10 GRID.  HOMEBASE IS POSITION 0,0."); printf("\n");
    /* BASIC: 40 PRINT "ANY GUESS YOU MAKE MUST BE TWO NUMBERS WITH EACH" */
line_40:;
    printf("%s", "ANY GUESS YOU MAKE MUST BE TWO NUMBERS WITH EACH"); printf("\n");
    /* BASIC: 50 PRINT "NUMBER BETWEEN 0 AND 9, INCLUSIVE.  FIRST NUMBER" */
line_50:;
    printf("%s", "NUMBER BETWEEN 0 AND 9, INCLUSIVE.  FIRST NUMBER"); printf("\n");
    /* BASIC: 60 PRINT "IS DISTANCE TO RIGHT OF HOMEBASE AND SECOND NUMBER" */
line_60:;
    printf("%s", "IS DISTANCE TO RIGHT OF HOMEBASE AND SECOND NUMBER"); printf("\n");
    /* BASIC: 70 PRINT "IS DISTANCE ABOVE HOMEBASE." */
line_70:;
    printf("%s", "IS DISTANCE ABOVE HOMEBASE."); printf("\n");
    /* BASIC: 80 PRINT */
line_80:;
    printf("\n");
    /* BASIC: 90 PRINT "YOU GET 10 TRIES.  AFTER EACH TRY, I WILL TELL" */
line_90:;
    printf("%s", "YOU GET 10 TRIES.  AFTER EACH TRY, I WILL TELL"); printf("\n");
    /* BASIC: 100 PRINT "YOU HOW FAR YOU ARE FROM EACH MUGWUMP." */
line_100:;
    printf("%s", "YOU HOW FAR YOU ARE FROM EACH MUGWUMP."); printf("\n");
    /* BASIC: 110 PRINT */
line_110:;
    printf("\n");
    /* BASIC: 240 GOSUB 1000 */
line_240:;
    gosub_stack[gosub_sp++] = 1; goto line_1000; line_ret_1:;
    /* BASIC: 250 T=0 */
line_250:;
    T = 0;
    /* BASIC: 260 T=T+1 */
line_260:;
    T = T+1;
    /* BASIC: 270 PRINT */
line_270:;
    printf("\n");
    /* BASIC: 275 PRINT */
line_275:;
    printf("\n");
    /* BASIC: 290 PRINT "TURN NO.";T;"-- WHAT IS YOUR GUESS"; */
line_290:;
    printf("%s", "TURN NO."); printf("%g ", (double)(T)); printf("%s", "-- WHAT IS YOUR GUESS");
    /* BASIC: 300 INPUT M,N */
line_300:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf", &M, &N);
    /* BASIC: 310 FOR I=1 TO 4 */
line_310:;
    I = 1; for_loop_I_310: if (((1) >= 0 && I > (4)) || ((1) < 0 && I < (4))) goto end_for_I_310;
    /* BASIC: 320 IF P(I,1)=-1 THEN 400 */
line_320:;
    if (P_arr[(int)(I) * 100 + (int)(1)]==-1) { goto line_400; }
    /* BASIC: 330 IF P(I,1)<>M THEN 380 */
line_330:;
    if (P_arr[(int)(I) * 100 + (int)(1)]!=M) { goto line_380; }
    /* BASIC: 340 IF P(I,2)<>N THEN 380 */
line_340:;
    if (P_arr[(int)(I) * 100 + (int)(2)]!=N) { goto line_380; }
    /* BASIC: 350 P(I,1)=-1 */
line_350:;
    P_arr[(int)(I) * 100 + (int)(1)] = -1;
    /* BASIC: 360 PRINT "YOU HAVE FOUND MUGWUMP";I */
line_360:;
    printf("%s", "YOU HAVE FOUND MUGWUMP"); printf("%g ", (double)(I)); printf("\n");
    /* BASIC: 370 GOTO 400 */
line_370:;
    goto line_400;
    /* BASIC: 380 D=SQR((P(I,1)-M)^2+(P(I,2)-N)^2) */
line_380:;
    D = sqrt(pow((P_arr[(int)(I) * 100 + (int)(1)]-M), 2)+pow((P_arr[(int)(I) * 100 + (int)(2)]-N), 2));
    /* BASIC: 390 PRINT "YOU ARE";(INT(D*10))/10;"UNITS FROM MUGWUMP";I */
line_390:;
    printf("%s", "YOU ARE"); printf("%g ", (double)((floor(D*10))/10)); printf("%s", "UNITS FROM MUGWUMP"); printf("%g ", (double)(I)); printf("\n");
    /* BASIC: 400 NEXT I */
line_400:;
    I += (1); goto for_loop_I_310; end_for_I_310:;
    /* BASIC: 410 FOR J=1 TO 4 */
line_410:;
    J = 1; for_loop_J_410: if (((1) >= 0 && J > (4)) || ((1) < 0 && J < (4))) goto end_for_J_410;
    /* BASIC: 420 IF P(J,1)<>-1 THEN 470 */
line_420:;
    if (P_arr[(int)(J) * 100 + (int)(1)]!=-1) { goto line_470; }
    /* BASIC: 430 NEXT J */
line_430:;
    J += (1); goto for_loop_J_410; end_for_J_410:;
    /* BASIC: 440 PRINT */
line_440:;
    printf("\n");
    /* BASIC: 450 PRINT "YOU GOT THEM ALL IN";T;"TURNS!" */
line_450:;
    printf("%s", "YOU GOT THEM ALL IN"); printf("%g ", (double)(T)); printf("%s", "TURNS!"); printf("\n");
    /* BASIC: 460 GOTO 580 */
line_460:;
    goto line_580;
    /* BASIC: 470 IF T<10 THEN 260 */
line_470:;
    if (T<10) { goto line_260; }
    /* BASIC: 480 PRINT */
line_480:;
    printf("\n");
    /* BASIC: 490 PRINT "SORRY, THAT'S 10 TRIES.  HERE IS WHERE THEY'RE HIDING:" */
line_490:;
    printf("%s", "SORRY, THAT'S 10 TRIES.  HERE IS WHERE THEY'RE HIDING:"); printf("\n");
    /* BASIC: 540 FOR I=1 TO 4 */
line_540:;
    I = 1; for_loop_I_540: if (((1) >= 0 && I > (4)) || ((1) < 0 && I < (4))) goto end_for_I_540;
    /* BASIC: 550 IF P(I,1)=-1 THEN 570 */
line_550:;
    if (P_arr[(int)(I) * 100 + (int)(1)]==-1) { goto line_570; }
    /* BASIC: 560 PRINT "MUGWUMP";I;"IS AT (";P(I,1);",";P(I,2);")" */
line_560:;
    printf("%s", "MUGWUMP"); printf("%g ", (double)(I)); printf("%s", "IS AT ("); printf("%g ", (double)(P_arr[(int)(I) * 100 + (int)(1)])); printf("%s", ","); printf("%g ", (double)(P_arr[(int)(I) * 100 + (int)(2)])); printf("%s", ")"); printf("\n");
    /* BASIC: 570 NEXT I */
line_570:;
    I += (1); goto for_loop_I_540; end_for_I_540:;
    /* BASIC: 580 PRINT */
line_580:;
    printf("\n");
    /* BASIC: 600 PRINT "THAT WAS FUN! LET'S PLAY AGAIN......." */
line_600:;
    printf("%s", "THAT WAS FUN! LET'S PLAY AGAIN......."); printf("\n");
    /* BASIC: 610 PRINT "FOUR MORE MUGWUMPS ARE NOW IN HIDING." */
line_610:;
    printf("%s", "FOUR MORE MUGWUMPS ARE NOW IN HIDING."); printf("\n");
    /* BASIC: 630 GOTO 240 */
line_630:;
    goto line_240;
    /* BASIC: 1000 FOR J=1 TO 2 */
line_1000:;
    J = 1; for_loop_J_1000: if (((1) >= 0 && J > (2)) || ((1) < 0 && J < (2))) goto end_for_J_1000;
    /* BASIC: 1010 FOR I=1 TO 4 */
line_1010:;
    I = 1; for_loop_I_1010: if (((1) >= 0 && I > (4)) || ((1) < 0 && I < (4))) goto end_for_I_1010;
    /* BASIC: 1020 P(I,J)=INT(10*RND(1)) */
line_1020:;
    P_arr[(int)(I) * 100 + (int)(J)] = floor(10*((double)rand() / (double)RAND_MAX));
    /* BASIC: 1030 NEXT I */
line_1030:;
    I += (1); goto for_loop_I_1010; end_for_I_1010:;
    /* BASIC: 1040 NEXT J */
line_1040:;
    J += (1); goto for_loop_J_1000; end_for_J_1000:;
    /* BASIC: 1050 RETURN */
line_1050:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1099 END */
line_1099:;
    exit(0);

    return 0;
}
