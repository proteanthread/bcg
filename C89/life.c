/*
 * Transpiled from life.bas
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
static double A, C, G, I, I9, J, L, P, X, X1, X2, X3, X4, Y, Y1, Y2, Y3, Y4;
static char B_str[256] = {0};
static double A_arr[2000] = {0};
static char B_str_arr[1000][64] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 2 PRINT TAB(34);"LIFE" */
line_2:;
    { int _t; for(_t=0; _t<34; _t++) printf(" "); } printf("%s", "LIFE"); printf("\n");
    /* BASIC: 4 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 6 PRINT: PRINT: PRINT */
line_6:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 8 PRINT "ENTER YOUR PATTERN:" */
line_8:;
    printf("%s", "ENTER YOUR PATTERN:"); printf("\n");
    /* BASIC: 9 X1=1: Y1=1: X2=24: Y2=70 */
line_9:;
    X1 = 1;
    Y1 = 1;
    X2 = 24;
    Y2 = 70;
    /* BASIC: 10 DIM A(24,70),B$(24) */
line_10:;
    /* DIM A(24,70),B$(24) (handled statically) */
    /* BASIC: 20 C=1 */
line_20:;
    C = 1;
    /* BASIC: 30 INPUT B$(C) */
line_30:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", B_str_arr[(int)(C)]);
    /* BASIC: 40 IF B$(C)="DONE" THEN B$(C)="": GOTO 80 */
line_40:;
    if (strcmp(B_str_arr[(int)(C)], "DONE") == 0) { str_assign(B_str_arr[(int)(C)], sizeof(B_str_arr[(int)(C)]), ""); goto line_80; }
    /* BASIC: 50 IF LEFT$(B$(C),1)="." THEN B$(C)=" "+RIGHT$(B$(C),LEN(B$(C))-1) */
line_50:;
    if (strcmp(basic_LEFT(B_str_arr[(int)(C)],1), ".") == 0) { str_assign(B_str_arr[(int)(C)], sizeof(B_str_arr[(int)(C)]), str_cat_helper(" ", basic_RIGHT(B_str_arr[(int)(C)],basic_LEN(B_str_arr[(int)(C)])-1))); }
    /* BASIC: 60 C=C+1 */
line_60:;
    C = C+1;
    /* BASIC: 70 GOTO 30 */
line_70:;
    goto line_30;
    /* BASIC: 80 C=C-1: L=0 */
line_80:;
    C = C-1;
    L = 0;
    /* BASIC: 90 FOR X=1 TO C-1 */
line_90:;
    X = 1; for_loop_X_90: if (((1) >= 0 && X > (C-1)) || ((1) < 0 && X < (C-1))) goto end_for_X_90;
    /* BASIC: 100 IF LEN(B$(X))>L THEN L=LEN(B$(X)) */
line_100:;
    if (basic_LEN(B_str_arr[(int)(X)])>L) { L = basic_LEN(B_str_arr[(int)(X)]); }
    /* BASIC: 110 NEXT X */
line_110:;
    X += (1); goto for_loop_X_90; end_for_X_90:;
    /* BASIC: 120 X1=11-C/2 */
line_120:;
    X1 = 11-C/2;
    /* BASIC: 130 Y1=33-L/2 */
line_130:;
    Y1 = 33-L/2;
    /* BASIC: 140 FOR X=1 TO C */
line_140:;
    X = 1; for_loop_X_140: if (((1) >= 0 && X > (C)) || ((1) < 0 && X < (C))) goto end_for_X_140;
    /* BASIC: 150 FOR Y=1 TO LEN(B$(X)) */
line_150:;
    Y = 1; for_loop_Y_150: if (((1) >= 0 && Y > (basic_LEN(B_str_arr[(int)(X)]))) || ((1) < 0 && Y < (basic_LEN(B_str_arr[(int)(X)])))) goto end_for_Y_150;
    /* BASIC: 160 IF MID$(B$(X),Y,1)<>" " THEN A(X1+X,Y1+Y)=1:P=P+1 */
line_160:;
    if (strcmp(basic_MID(B_str_arr[(int)(X)],Y,1), " ") != 0) { A_arr[(int)(X1+X) * 100 + (int)(Y1+Y)] = 1; P = P+1; }
    /* BASIC: 170 NEXT Y */
line_170:;
    Y += (1); goto for_loop_Y_150; end_for_Y_150:;
    /* BASIC: 180 NEXT X */
line_180:;
    X += (1); goto for_loop_X_140; end_for_X_140:;
    /* BASIC: 200 PRINT:PRINT:PRINT */
line_200:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 210 PRINT "GENERATION:";G,"POPULATION:";P;: IF I9 THEN PRINT "INVALID!"; */
line_210:;
    printf("%s", "GENERATION:"); printf("%g ", (double)(G)); printf("\t"); printf("%s", "POPULATION:"); printf("%g ", (double)(P));
    if (I9) { printf("%s", "INVALID!"); }
    /* BASIC: 215 X3=24:Y3=70:X4=1: Y4=1: P=0 */
line_215:;
    X3 = 24;
    Y3 = 70;
    X4 = 1;
    Y4 = 1;
    P = 0;
    /* BASIC: 220 G=G+1 */
line_220:;
    G = G+1;
    /* BASIC: 225 FOR X=1 TO X1-1: PRINT: NEXT X */
line_225:;
    X = 1; for_loop_X_225: if (((1) >= 0 && X > (X1-1)) || ((1) < 0 && X < (X1-1))) goto end_for_X_225;
    printf("\n");
    X += (1); goto for_loop_X_225; end_for_X_225:;
    /* BASIC: 230 FOR X=X1 TO X2 */
line_230:;
    X = X1; for_loop_X_230: if (((1) >= 0 && X > (X2)) || ((1) < 0 && X < (X2))) goto end_for_X_230;
    /* BASIC: 240 PRINT */
line_240:;
    printf("\n");
    /* BASIC: 250 FOR Y=Y1 TO Y2 */
line_250:;
    Y = Y1; for_loop_Y_250: if (((1) >= 0 && Y > (Y2)) || ((1) < 0 && Y < (Y2))) goto end_for_Y_250;
    /* BASIC: 253 IF A(X,Y)=2 THEN A(X,Y)=0:GOTO 270 */
line_253:;
    if (A_arr[(int)(X) * 100 + (int)(Y)]==2) { A_arr[(int)(X) * 100 + (int)(Y)] = 0; goto line_270; }
    /* BASIC: 256 IF A(X,Y)=3 THEN A(X,Y)=1:GOTO 261 */
line_256:;
    if (A_arr[(int)(X) * 100 + (int)(Y)]==3) { A_arr[(int)(X) * 100 + (int)(Y)] = 1; goto line_261; }
    /* BASIC: 260 IF A(X,Y)<>1 THEN 270 */
line_260:;
    if (A_arr[(int)(X) * 100 + (int)(Y)]!=1) { goto line_270; }
    /* BASIC: 261 PRINT TAB(Y);"*"; */
line_261:;
    { int _t; for(_t=0; _t<Y; _t++) printf(" "); } printf("%s", "*");
    /* BASIC: 262 IF X<X3 THEN X3=X */
line_262:;
    if (X<X3) { X3 = X; }
    /* BASIC: 264 IF X>X4 THEN X4=X */
line_264:;
    if (X>X4) { X4 = X; }
    /* BASIC: 266 IF Y<Y3 THEN Y3=Y */
line_266:;
    if (Y<Y3) { Y3 = Y; }
    /* BASIC: 268 IF Y>Y4 THEN Y4=Y */
line_268:;
    if (Y>Y4) { Y4 = Y; }
    /* BASIC: 270 NEXT Y */
line_270:;
    Y += (1); goto for_loop_Y_250; end_for_Y_250:;
    /* BASIC: 290 NEXT X */
line_290:;
    X += (1); goto for_loop_X_230; end_for_X_230:;
    /* BASIC: 295 FOR X=X2+1 TO 24: PRINT: NEXT X */
line_295:;
    X = X2+1; for_loop_X_295: if (((1) >= 0 && X > (24)) || ((1) < 0 && X < (24))) goto end_for_X_295;
    printf("\n");
    X += (1); goto for_loop_X_295; end_for_X_295:;
    /* BASIC: 299 X1=X3: X2=X4: Y1=Y3: Y2=Y4 */
line_299:;
    X1 = X3;
    X2 = X4;
    Y1 = Y3;
    Y2 = Y4;
    /* BASIC: 301 IF X1<3 THEN X1=3:I9=-1 */
line_301:;
    if (X1<3) { X1 = 3; I9 = -1; }
    /* BASIC: 303 IF X2>22 THEN X2=22:I9=-1 */
line_303:;
    if (X2>22) { X2 = 22; I9 = -1; }
    /* BASIC: 305 IF Y1<3 THEN Y1=3:I9=-1 */
line_305:;
    if (Y1<3) { Y1 = 3; I9 = -1; }
    /* BASIC: 307 IF Y2>68 THEN Y2=68:I9=-1 */
line_307:;
    if (Y2>68) { Y2 = 68; I9 = -1; }
    /* BASIC: 309 P=0 */
line_309:;
    P = 0;
    /* BASIC: 500 FOR X=X1-1 TO X2+1 */
line_500:;
    X = X1-1; for_loop_X_500: if (((1) >= 0 && X > (X2+1)) || ((1) < 0 && X < (X2+1))) goto end_for_X_500;
    /* BASIC: 510 FOR Y=Y1-1 TO Y2+1 */
line_510:;
    Y = Y1-1; for_loop_Y_510: if (((1) >= 0 && Y > (Y2+1)) || ((1) < 0 && Y < (Y2+1))) goto end_for_Y_510;
    /* BASIC: 520 C=0 */
line_520:;
    C = 0;
    /* BASIC: 530 FOR I=X-1 TO X+1 */
line_530:;
    I = X-1; for_loop_I_530: if (((1) >= 0 && I > (X+1)) || ((1) < 0 && I < (X+1))) goto end_for_I_530;
    /* BASIC: 540 FOR J=Y-1 TO Y+1 */
line_540:;
    J = Y-1; for_loop_J_540: if (((1) >= 0 && J > (Y+1)) || ((1) < 0 && J < (Y+1))) goto end_for_J_540;
    /* BASIC: 550 IF A(I,J)=1 OR A(I,J)=2 THEN C=C+1 */
line_550:;
    if (A_arr[(int)(I) * 100 + (int)(J)]==1   ||   A_arr[(int)(I) * 100 + (int)(J)]==2) { C = C+1; }
    /* BASIC: 560 NEXT J */
line_560:;
    J += (1); goto for_loop_J_540; end_for_J_540:;
    /* BASIC: 570 NEXT I */
line_570:;
    I += (1); goto for_loop_I_530; end_for_I_530:;
    /* BASIC: 580 IF A(X,Y)=0 THEN 610 */
line_580:;
    if (A_arr[(int)(X) * 100 + (int)(Y)]==0) { goto line_610; }
    /* BASIC: 590 IF C<3 OR C>4 THEN A(X,Y)=2: GOTO 600 */
line_590:;
    if (C<3   ||   C>4) { A_arr[(int)(X) * 100 + (int)(Y)] = 2; goto line_600; }
    /* BASIC: 595 P=P+1 */
line_595:;
    P = P+1;
    /* BASIC: 600 GOTO 620 */
line_600:;
    goto line_620;
    /* BASIC: 610 IF C=3 THEN A(X,Y)=3:P=P+1 */
line_610:;
    if (C==3) { A_arr[(int)(X) * 100 + (int)(Y)] = 3; P = P+1; }
    /* BASIC: 620 NEXT Y */
line_620:;
    Y += (1); goto for_loop_Y_510; end_for_Y_510:;
    /* BASIC: 630 NEXT X */
line_630:;
    X += (1); goto for_loop_X_500; end_for_X_500:;
    /* BASIC: 635 X1=X1-1:Y1=Y1-1:X2=X2+1:Y2=Y2+1 */
line_635:;
    X1 = X1-1;
    Y1 = Y1-1;
    X2 = X2+1;
    Y2 = Y2+1;
    /* BASIC: 640 GOTO 210 */
line_640:;
    goto line_210;
    /* BASIC: 650 END */
line_650:;
    exit(0);

    return 0;
}
