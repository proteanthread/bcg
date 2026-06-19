/*
 * Transpiled from battle.bas
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
static double A, B, C, D, F, H, I, J, K, L, M, N, ON, R, S, X, Y, Z, Z1, Z2;
static double A_arr[2000] = {0};
static double B_arr[2000] = {0};
static double C_arr[2000] = {0};
static double F_arr[2000] = {0};
static double H_arr[2000] = {0};
static double L_arr[2000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 5 PRINT TAB(33);"BATTLE" */
line_5:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "BATTLE"); printf("\n");
    /* BASIC: 7 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_7:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 10 REM -- BATTLE WRITTEN BY RAY WESTERGARD  10/70 */
line_10:;
    /* REM -- BATTLE WRITTEN BY RAY WESTERGARD  10/70 */
    /* BASIC: 20 REM COPYRIGHT 1971 BY THE REGENTS OF THE UNIV. OF CALIF. */
line_20:;
    /* REM COPYRIGHT 1971 BY THE REGENTS OF THE UNIV. OF CALIF. */
    /* BASIC: 30 REM PRODUCED AT THE LAWRENCE HALL OF SCIENCE, BERKELEY */
line_30:;
    /* REM PRODUCED AT THE LAWRENCE HALL OF SCIENCE, BERKELEY */
    /* BASIC: 40 DIM F(6,6),H(6,6),A(4),B(4),C(6),L(3) */
line_40:;
    /* DIM F(6,6),H(6,6),A(4),B(4),C(6),L(3) (handled statically) */
    /* BASIC: 50 FOR X=1 TO 6 */
line_50:;
    X = 1; for_loop_X_50: if (((1) >= 0 && X > (6)) || ((1) < 0 && X < (6))) goto end_for_X_50;
    /* BASIC: 51 FOR Y=1 TO 6 */
line_51:;
    Y = 1; for_loop_Y_51: if (((1) >= 0 && Y > (6)) || ((1) < 0 && Y < (6))) goto end_for_Y_51;
    /* BASIC: 52 F(X,Y)=0 */
line_52:;
    F_arr[(int)(X) * 100 + (int)(Y)] = 0;
    /* BASIC: 53 NEXT Y */
line_53:;
    Y += (1); goto for_loop_Y_51; end_for_Y_51:;
    /* BASIC: 54 NEXT X */
line_54:;
    X += (1); goto for_loop_X_50; end_for_X_50:;
    /* BASIC: 60 FOR I=1 TO 3 */
line_60:;
    I = 1; for_loop_I_60: if (((1) >= 0 && I > (3)) || ((1) < 0 && I < (3))) goto end_for_I_60;
    /* BASIC: 70 N=4-I */
line_70:;
    N = 4-I;
    /* BASIC: 80 FOR J=1 TO 2 */
line_80:;
    J = 1; for_loop_J_80: if (((1) >= 0 && J > (2)) || ((1) < 0 && J < (2))) goto end_for_J_80;
    /* BASIC: 90 A=INT(6*RND(1)+1) */
line_90:;
    A = floor(6*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 100 B=INT(6*RND(1)+1) */
line_100:;
    B = floor(6*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 110 D=INT(4*RND(1)+1) */
line_110:;
    D = floor(4*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 120 IF F(A,B)>0 THEN 90 */
line_120:;
    if (F_arr[(int)(A) * 100 + (int)(B)]>0) { goto line_90; }
    /* BASIC: 130 M=0 */
line_130:;
    M = 0;
    /* BASIC: 140 ON D GOTO 150,340,550,740 */
line_140:;
    switch ((int)(D)) {     case 1: goto line_150;     case 2: goto line_340;     case 3: goto line_550;     case 4: goto line_740; }
    /* BASIC: 150 B(1)=B */
line_150:;
    B_arr[(int)(1)] = B;
    /* BASIC: 160 B(2)=7:B(3)=7 */
line_160:;
    B_arr[(int)(2)] = 7;
    B_arr[(int)(3)] = 7;
    /* BASIC: 170 FOR K=1 TO N */
line_170:;
    K = 1; for_loop_K_170: if (((1) >= 0 && K > (N)) || ((1) < 0 && K < (N))) goto end_for_K_170;
    /* BASIC: 180 IF M>1 THEN 240 */
line_180:;
    if (M>1) { goto line_240; }
    /* BASIC: 190 IF B(K)=6 THEN 230 */
line_190:;
    if (B_arr[(int)(K)]==6) { goto line_230; }
    /* BASIC: 200 IF F(A,B(K)+1)>0 THEN 230 */
line_200:;
    if (F_arr[(int)(A) * 100 + (int)(B_arr[(int)(K)]+1)]>0) { goto line_230; }
    /* BASIC: 210 B(K+1)=B(K)+1 */
line_210:;
    B_arr[(int)(K+1)] = B_arr[(int)(K)]+1;
    /* BASIC: 220 GOTO 280 */
line_220:;
    goto line_280;
    /* BASIC: 230 M=2 */
line_230:;
    M = 2;
    /* BASIC: 240 IF B(1)<B(2) AND B(1)<B(3) THEN Z=B(1) */
line_240:;
    if (B_arr[(int)(1)]<B_arr[(int)(2)]   &&   B_arr[(int)(1)]<B_arr[(int)(3)]) { Z = B_arr[(int)(1)]; }
    /* BASIC: 242 IF B(2)<B(1) AND B(2)<B(3) THEN Z=B(2) */
line_242:;
    if (B_arr[(int)(2)]<B_arr[(int)(1)]   &&   B_arr[(int)(2)]<B_arr[(int)(3)]) { Z = B_arr[(int)(2)]; }
    /* BASIC: 244 IF B(3)<B(1) AND B(3)<B(2) THEN Z=B(3) */
line_244:;
    if (B_arr[(int)(3)]<B_arr[(int)(1)]   &&   B_arr[(int)(3)]<B_arr[(int)(2)]) { Z = B_arr[(int)(3)]; }
    /* BASIC: 250 IF Z=1 THEN 90 */
line_250:;
    if (Z==1) { goto line_90; }
    /* BASIC: 260 IF F(A,Z-1)>0 THEN 90 */
line_260:;
    if (F_arr[(int)(A) * 100 + (int)(Z-1)]>0) { goto line_90; }
    /* BASIC: 270 B(K+1)=Z-1 */
line_270:;
    B_arr[(int)(K+1)] = Z-1;
    /* BASIC: 280 NEXT K */
line_280:;
    K += (1); goto for_loop_K_170; end_for_K_170:;
    /* BASIC: 290 F(A,B)=9-2*I-J */
line_290:;
    F_arr[(int)(A) * 100 + (int)(B)] = 9-2*I-J;
    /* BASIC: 300 FOR K=1 TO N */
line_300:;
    K = 1; for_loop_K_300: if (((1) >= 0 && K > (N)) || ((1) < 0 && K < (N))) goto end_for_K_300;
    /* BASIC: 310 F(A,B(K+1))=F(A,B) */
line_310:;
    F_arr[(int)(A) * 100 + (int)(B_arr[(int)(K+1)])] = F_arr[(int)(A) * 100 + (int)(B)];
    /* BASIC: 320 NEXT K */
line_320:;
    K += (1); goto for_loop_K_300; end_for_K_300:;
    /* BASIC: 330 GOTO 990 */
line_330:;
    goto line_990;
    /* BASIC: 340 A(1)=A */
line_340:;
    A_arr[(int)(1)] = A;
    /* BASIC: 350 B(1)=B */
line_350:;
    B_arr[(int)(1)] = B;
    /* BASIC: 360 A(2)=0:A(3)=0:B(2)=0:B(3)=0 */
line_360:;
    A_arr[(int)(2)] = 0;
    A_arr[(int)(3)] = 0;
    B_arr[(int)(2)] = 0;
    B_arr[(int)(3)] = 0;
    /* BASIC: 370 FOR K=1 TO N */
line_370:;
    K = 1; for_loop_K_370: if (((1) >= 0 && K > (N)) || ((1) < 0 && K < (N))) goto end_for_K_370;
    /* BASIC: 380 IF M>1 THEN 460 */
line_380:;
    if (M>1) { goto line_460; }
    /* BASIC: 390 IF A(K)=1 OR B(K)=1 THEN 450 */
line_390:;
    if (A_arr[(int)(K)]==1   ||   B_arr[(int)(K)]==1) { goto line_450; }
    /* BASIC: 400 IF F(A(K)-1,B(K)-1)>0 THEN 450 */
line_400:;
    if (F_arr[(int)(A_arr[(int)(K)]-1) * 100 + (int)(B_arr[(int)(K)]-1)]>0) { goto line_450; }
    /* BASIC: 410 IF F(A(K)-1,B(K))>0 AND F(A(K)-1,B(K))=F(A(K),B(K)-1) THEN 450 */
line_410:;
    if (F_arr[(int)(A_arr[(int)(K)]-1) * 100 + (int)(B_arr[(int)(K)])]>0   &&   F_arr[(int)(A_arr[(int)(K)]-1) * 100 + (int)(B_arr[(int)(K)])]==F_arr[(int)(A_arr[(int)(K)]) * 100 + (int)(B_arr[(int)(K)]-1)]) { goto line_450; }
    /* BASIC: 420 A(K+1)=A(K)-1 */
line_420:;
    A_arr[(int)(K+1)] = A_arr[(int)(K)]-1;
    /* BASIC: 430 B(K+1)=B(K)-1 */
line_430:;
    B_arr[(int)(K+1)] = B_arr[(int)(K)]-1;
    /* BASIC: 440 GOTO 530 */
line_440:;
    goto line_530;
    /* BASIC: 450 M=2 */
line_450:;
    M = 2;
    /* BASIC: 460 IF A(1)>A(2) AND A(1)>A(3) THEN Z1=A(1) */
line_460:;
    if (A_arr[(int)(1)]>A_arr[(int)(2)]   &&   A_arr[(int)(1)]>A_arr[(int)(3)]) { Z1 = A_arr[(int)(1)]; }
    /* BASIC: 462 IF A(2)>A(1) AND A(2)>A(3) THEN Z1=A(2) */
line_462:;
    if (A_arr[(int)(2)]>A_arr[(int)(1)]   &&   A_arr[(int)(2)]>A_arr[(int)(3)]) { Z1 = A_arr[(int)(2)]; }
    /* BASIC: 464 IF A(3)>A(1) AND A(3)>A(2) THEN Z1=A(3) */
line_464:;
    if (A_arr[(int)(3)]>A_arr[(int)(1)]   &&   A_arr[(int)(3)]>A_arr[(int)(2)]) { Z1 = A_arr[(int)(3)]; }
    /* BASIC: 470 IF B(1)>B(2) AND B(1)>B(3) THEN Z2=B(1) */
line_470:;
    if (B_arr[(int)(1)]>B_arr[(int)(2)]   &&   B_arr[(int)(1)]>B_arr[(int)(3)]) { Z2 = B_arr[(int)(1)]; }
    /* BASIC: 474 IF B(2)>B(1) AND B(2)>B(3) THEN Z2=B(2) */
line_474:;
    if (B_arr[(int)(2)]>B_arr[(int)(1)]   &&   B_arr[(int)(2)]>B_arr[(int)(3)]) { Z2 = B_arr[(int)(2)]; }
    /* BASIC: 476 IF B(3)>B(1) AND B(3)>B(2) THEN Z2=B(3) */
line_476:;
    if (B_arr[(int)(3)]>B_arr[(int)(1)]   &&   B_arr[(int)(3)]>B_arr[(int)(2)]) { Z2 = B_arr[(int)(3)]; }
    /* BASIC: 480 IF Z1=6 OR Z2=6 THEN 90 */
line_480:;
    if (Z1==6   ||   Z2==6) { goto line_90; }
    /* BASIC: 490 IF F(Z1+1,Z2+1)>0 THEN 90 */
line_490:;
    if (F_arr[(int)(Z1+1) * 100 + (int)(Z2+1)]>0) { goto line_90; }
    /* BASIC: 500 IF F(Z1,Z2+1)>0 AND F(Z1,Z2+1)=F(Z1+1,Z2) THEN 90 */
line_500:;
    if (F_arr[(int)(Z1) * 100 + (int)(Z2+1)]>0   &&   F_arr[(int)(Z1) * 100 + (int)(Z2+1)]==F_arr[(int)(Z1+1) * 100 + (int)(Z2)]) { goto line_90; }
    /* BASIC: 510 A(K+1)=Z1+1 */
line_510:;
    A_arr[(int)(K+1)] = Z1+1;
    /* BASIC: 520 B(K+1)=Z2+1 */
line_520:;
    B_arr[(int)(K+1)] = Z2+1;
    /* BASIC: 530 NEXT K */
line_530:;
    K += (1); goto for_loop_K_370; end_for_K_370:;
    /* BASIC: 540 GOTO 950 */
line_540:;
    goto line_950;
    /* BASIC: 550 A(1)=A */
line_550:;
    A_arr[(int)(1)] = A;
    /* BASIC: 560 A(2)=7:A(3)=7 */
line_560:;
    A_arr[(int)(2)] = 7;
    A_arr[(int)(3)] = 7;
    /* BASIC: 570 FOR K=1 TO N */
line_570:;
    K = 1; for_loop_K_570: if (((1) >= 0 && K > (N)) || ((1) < 0 && K < (N))) goto end_for_K_570;
    /* BASIC: 580 IF M>1 THEN 640 */
line_580:;
    if (M>1) { goto line_640; }
    /* BASIC: 590 IF A(K)=6 THEN 630 */
line_590:;
    if (A_arr[(int)(K)]==6) { goto line_630; }
    /* BASIC: 600 IF F(A(K)+1,B)>0 THEN 630 */
line_600:;
    if (F_arr[(int)(A_arr[(int)(K)]+1) * 100 + (int)(B)]>0) { goto line_630; }
    /* BASIC: 610 A(K+1)=A(K)+1 */
line_610:;
    A_arr[(int)(K+1)] = A_arr[(int)(K)]+1;
    /* BASIC: 620 GOTO 680 */
line_620:;
    goto line_680;
    /* BASIC: 630 M=2 */
line_630:;
    M = 2;
    /* BASIC: 640 IF A(1)<A(2) AND A(1)<A(3) THEN Z=A(1) */
line_640:;
    if (A_arr[(int)(1)]<A_arr[(int)(2)]   &&   A_arr[(int)(1)]<A_arr[(int)(3)]) { Z = A_arr[(int)(1)]; }
    /* BASIC: 642 IF A(2)<A(1) AND A(2)<A(3) THEN Z=A(2) */
line_642:;
    if (A_arr[(int)(2)]<A_arr[(int)(1)]   &&   A_arr[(int)(2)]<A_arr[(int)(3)]) { Z = A_arr[(int)(2)]; }
    /* BASIC: 644 IF A(3)<A(1) AND A(3)<A(2) THEN Z=A(3) */
line_644:;
    if (A_arr[(int)(3)]<A_arr[(int)(1)]   &&   A_arr[(int)(3)]<A_arr[(int)(2)]) { Z = A_arr[(int)(3)]; }
    /* BASIC: 650 IF Z=1 THEN 90 */
line_650:;
    if (Z==1) { goto line_90; }
    /* BASIC: 660 IF F(Z-1,B)>0 THEN 90 */
line_660:;
    if (F_arr[(int)(Z-1) * 100 + (int)(B)]>0) { goto line_90; }
    /* BASIC: 670 A(K+1)=Z-1 */
line_670:;
    A_arr[(int)(K+1)] = Z-1;
    /* BASIC: 680 NEXT K */
line_680:;
    K += (1); goto for_loop_K_570; end_for_K_570:;
    /* BASIC: 690 F(A,B)=9-2*I-J */
line_690:;
    F_arr[(int)(A) * 100 + (int)(B)] = 9-2*I-J;
    /* BASIC: 700 FOR K=1 TO N */
line_700:;
    K = 1; for_loop_K_700: if (((1) >= 0 && K > (N)) || ((1) < 0 && K < (N))) goto end_for_K_700;
    /* BASIC: 710 F(A(K+1),B)=F(A,B) */
line_710:;
    F_arr[(int)(A_arr[(int)(K+1)]) * 100 + (int)(B)] = F_arr[(int)(A) * 100 + (int)(B)];
    /* BASIC: 720 NEXT K */
line_720:;
    K += (1); goto for_loop_K_700; end_for_K_700:;
    /* BASIC: 730 GOTO 990 */
line_730:;
    goto line_990;
    /* BASIC: 740 A(1)=A */
line_740:;
    A_arr[(int)(1)] = A;
    /* BASIC: 750 B(1)=B */
line_750:;
    B_arr[(int)(1)] = B;
    /* BASIC: 760 A(2)=7:A(3)=7 */
line_760:;
    A_arr[(int)(2)] = 7;
    A_arr[(int)(3)] = 7;
    /* BASIC: 770 B(2)=0:B(3)=0 */
line_770:;
    B_arr[(int)(2)] = 0;
    B_arr[(int)(3)] = 0;
    /* BASIC: 780 FOR K=1 TO N */
line_780:;
    K = 1; for_loop_K_780: if (((1) >= 0 && K > (N)) || ((1) < 0 && K < (N))) goto end_for_K_780;
    /* BASIC: 790 IF M>1 THEN 870 */
line_790:;
    if (M>1) { goto line_870; }
    /* BASIC: 800 IF A(K)=6 OR B(K)=1 THEN 860 */
line_800:;
    if (A_arr[(int)(K)]==6   ||   B_arr[(int)(K)]==1) { goto line_860; }
    /* BASIC: 810 IF F(A(K)+1,B(K)-1)>0 THEN 860 */
line_810:;
    if (F_arr[(int)(A_arr[(int)(K)]+1) * 100 + (int)(B_arr[(int)(K)]-1)]>0) { goto line_860; }
    /* BASIC: 820 IF F(A(K)+1,B(K))>0 AND F(A(K)+1,B(K))=F(A(K),B(K)-1) THEN 860 */
line_820:;
    if (F_arr[(int)(A_arr[(int)(K)]+1) * 100 + (int)(B_arr[(int)(K)])]>0   &&   F_arr[(int)(A_arr[(int)(K)]+1) * 100 + (int)(B_arr[(int)(K)])]==F_arr[(int)(A_arr[(int)(K)]) * 100 + (int)(B_arr[(int)(K)]-1)]) { goto line_860; }
    /* BASIC: 830 A(K+1)=A(K)+1 */
line_830:;
    A_arr[(int)(K+1)] = A_arr[(int)(K)]+1;
    /* BASIC: 840 B(K+1)=B(K)-1 */
line_840:;
    B_arr[(int)(K+1)] = B_arr[(int)(K)]-1;
    /* BASIC: 850 GOTO 940 */
line_850:;
    goto line_940;
    /* BASIC: 860 M=2 */
line_860:;
    M = 2;
    /* BASIC: 870 IF A(1)<A(2) AND A(1)<A(3) THEN Z1=A(1) */
line_870:;
    if (A_arr[(int)(1)]<A_arr[(int)(2)]   &&   A_arr[(int)(1)]<A_arr[(int)(3)]) { Z1 = A_arr[(int)(1)]; }
    /* BASIC: 872 IF A(2)<A(1) AND A(2)<A(3) THEN Z1=A(2) */
line_872:;
    if (A_arr[(int)(2)]<A_arr[(int)(1)]   &&   A_arr[(int)(2)]<A_arr[(int)(3)]) { Z1 = A_arr[(int)(2)]; }
    /* BASIC: 874 IF A(3)<A(1) AND A(3)<A(2) THEN Z1=A(3) */
line_874:;
    if (A_arr[(int)(3)]<A_arr[(int)(1)]   &&   A_arr[(int)(3)]<A_arr[(int)(2)]) { Z1 = A_arr[(int)(3)]; }
    /* BASIC: 880 IF B(1)>B(2) AND B(1)>B(3) THEN Z2=B(1) */
line_880:;
    if (B_arr[(int)(1)]>B_arr[(int)(2)]   &&   B_arr[(int)(1)]>B_arr[(int)(3)]) { Z2 = B_arr[(int)(1)]; }
    /* BASIC: 882 IF B(2)>B(1) AND B(2)>B(3) THEN Z2=B(2) */
line_882:;
    if (B_arr[(int)(2)]>B_arr[(int)(1)]   &&   B_arr[(int)(2)]>B_arr[(int)(3)]) { Z2 = B_arr[(int)(2)]; }
    /* BASIC: 884 IF B(3)>B(1) AND B(3)>B(2) THEN Z2=B(3) */
line_884:;
    if (B_arr[(int)(3)]>B_arr[(int)(1)]   &&   B_arr[(int)(3)]>B_arr[(int)(2)]) { Z2 = B_arr[(int)(3)]; }
    /* BASIC: 890 IF Z1=1 OR Z2=6 THEN 90 */
line_890:;
    if (Z1==1   ||   Z2==6) { goto line_90; }
    /* BASIC: 900 IF F(Z1-1,Z2+1)>0 THEN 90 */
line_900:;
    if (F_arr[(int)(Z1-1) * 100 + (int)(Z2+1)]>0) { goto line_90; }
    /* BASIC: 910 IF F(Z1,Z2+1)>0 AND F(Z1,Z2+1)=F(Z1-1,Z2) THEN 90 */
line_910:;
    if (F_arr[(int)(Z1) * 100 + (int)(Z2+1)]>0   &&   F_arr[(int)(Z1) * 100 + (int)(Z2+1)]==F_arr[(int)(Z1-1) * 100 + (int)(Z2)]) { goto line_90; }
    /* BASIC: 920 A(K+1)=Z1-1 */
line_920:;
    A_arr[(int)(K+1)] = Z1-1;
    /* BASIC: 930 B(K+1)=Z2+1 */
line_930:;
    B_arr[(int)(K+1)] = Z2+1;
    /* BASIC: 940 NEXT K */
line_940:;
    K += (1); goto for_loop_K_780; end_for_K_780:;
    /* BASIC: 950 F(A,B)=9-2*I-J */
line_950:;
    F_arr[(int)(A) * 100 + (int)(B)] = 9-2*I-J;
    /* BASIC: 960 FOR K=1 TO N */
line_960:;
    K = 1; for_loop_K_960: if (((1) >= 0 && K > (N)) || ((1) < 0 && K < (N))) goto end_for_K_960;
    /* BASIC: 970 F(A(K+1),B(K+1))=F(A,B) */
line_970:;
    F_arr[(int)(A_arr[(int)(K+1)]) * 100 + (int)(B_arr[(int)(K+1)])] = F_arr[(int)(A) * 100 + (int)(B)];
    /* BASIC: 980 NEXT K */
line_980:;
    K += (1); goto for_loop_K_960; end_for_K_960:;
    /* BASIC: 990 NEXT J */
line_990:;
    J += (1); goto for_loop_J_80; end_for_J_80:;
    /* BASIC: 1000 NEXT I */
line_1000:;
    I += (1); goto for_loop_I_60; end_for_I_60:;
    /* BASIC: 1010 PRINT */
line_1010:;
    printf("\n");
    /* BASIC: 1020 PRINT "THE FOLLOWING CODE OF THE BAD GUYS' FLEET DISPOSITION" */
line_1020:;
    printf("%s", "THE FOLLOWING CODE OF THE BAD GUYS' FLEET DISPOSITION"); printf("\n");
    /* BASIC: 1030 PRINT "HAS BEEN CAPTURED BUT NOT DECODED:" */
line_1030:;
    printf("%s", "HAS BEEN CAPTURED BUT NOT DECODED:"); printf("\n");
    /* BASIC: 1040 PRINT */
line_1040:;
    printf("\n");
    /* BASIC: 1050 FOR I=1 TO 6 */
line_1050:;
    I = 1; for_loop_I_1050: if (((1) >= 0 && I > (6)) || ((1) < 0 && I < (6))) goto end_for_I_1050;
    /* BASIC: 1051 FOR J=1 TO 6 */
line_1051:;
    J = 1; for_loop_J_1051: if (((1) >= 0 && J > (6)) || ((1) < 0 && J < (6))) goto end_for_J_1051;
    /* BASIC: 1052 H(I,J)=F(J,I) */
line_1052:;
    H_arr[(int)(I) * 100 + (int)(J)] = F_arr[(int)(J) * 100 + (int)(I)];
    /* BASIC: 1053 NEXT J */
line_1053:;
    J += (1); goto for_loop_J_1051; end_for_J_1051:;
    /* BASIC: 1054 NEXT I */
line_1054:;
    I += (1); goto for_loop_I_1050; end_for_I_1050:;
    /* BASIC: 1060 FOR I=1 TO 6 */
line_1060:;
    I = 1; for_loop_I_1060: if (((1) >= 0 && I > (6)) || ((1) < 0 && I < (6))) goto end_for_I_1060;
    /* BASIC: 1061 FOR J=1 TO 6 */
line_1061:;
    J = 1; for_loop_J_1061: if (((1) >= 0 && J > (6)) || ((1) < 0 && J < (6))) goto end_for_J_1061;
    /* BASIC: 1062 PRINT H(I,J); */
line_1062:;
    printf("%g ", (double)(H_arr[(int)(I) * 100 + (int)(J)]));
    /* BASIC: 1063 NEXT J */
line_1063:;
    J += (1); goto for_loop_J_1061; end_for_J_1061:;
    /* BASIC: 1064 PRINT */
line_1064:;
    printf("\n");
    /* BASIC: 1065 NEXT I */
line_1065:;
    I += (1); goto for_loop_I_1060; end_for_I_1060:;
    /* BASIC: 1070 PRINT */
line_1070:;
    printf("\n");
    /* BASIC: 1080 PRINT "DE-CODE IT AND USE IT IF YOU CAN" */
line_1080:;
    printf("%s", "DE-CODE IT AND USE IT IF YOU CAN"); printf("\n");
    /* BASIC: 1090 PRINT "BUT KEEP THE DE-CODING METHOD A SECRET." */
line_1090:;
    printf("%s", "BUT KEEP THE DE-CODING METHOD A SECRET."); printf("\n");
    /* BASIC: 1100 PRINT */
line_1100:;
    printf("\n");
    /* BASIC: 1110 FOR I=1 TO 6 */
line_1110:;
    I = 1; for_loop_I_1110: if (((1) >= 0 && I > (6)) || ((1) < 0 && I < (6))) goto end_for_I_1110;
    /* BASIC: 1111 FOR J=1 TO 6 */
line_1111:;
    J = 1; for_loop_J_1111: if (((1) >= 0 && J > (6)) || ((1) < 0 && J < (6))) goto end_for_J_1111;
    /* BASIC: 1112 H(I,J)=0 */
line_1112:;
    H_arr[(int)(I) * 100 + (int)(J)] = 0;
    /* BASIC: 1113 NEXT J */
line_1113:;
    J += (1); goto for_loop_J_1111; end_for_J_1111:;
    /* BASIC: 1114 NEXT I */
line_1114:;
    I += (1); goto for_loop_I_1110; end_for_I_1110:;
    /* BASIC: 1120 FOR I=1 TO 3 */
line_1120:;
    I = 1; for_loop_I_1120: if (((1) >= 0 && I > (3)) || ((1) < 0 && I < (3))) goto end_for_I_1120;
    /* BASIC: 1121 L(I)=0 */
line_1121:;
    L_arr[(int)(I)] = 0;
    /* BASIC: 1122 NEXT I */
line_1122:;
    I += (1); goto for_loop_I_1120; end_for_I_1120:;
    /* BASIC: 1130 C(1)=2:C(2)=2 */
line_1130:;
    C_arr[(int)(1)] = 2;
    C_arr[(int)(2)] = 2;
    /* BASIC: 1140 C(3)=1:C(4)=1 */
line_1140:;
    C_arr[(int)(3)] = 1;
    C_arr[(int)(4)] = 1;
    /* BASIC: 1150 C(5)=0:C(6)=0 */
line_1150:;
    C_arr[(int)(5)] = 0;
    C_arr[(int)(6)] = 0;
    /* BASIC: 1160 S=0:H=0 */
line_1160:;
    S = 0;
    H = 0;
    /* BASIC: 1170 PRINT "START GAME" */
line_1170:;
    printf("%s", "START GAME"); printf("\n");
    /* BASIC: 1180 INPUT X,Y */
line_1180:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf", &X, &Y);
    /* BASIC: 1190 IF X<1 OR X>6 OR INT(X)<>ABS(X) THEN 1210 */
line_1190:;
    if (X<1   ||   X>6   ||   floor(X)!=fabs(X)) { goto line_1210; }
    /* BASIC: 1200 IF Y>0 AND Y<7 AND INT(Y)=ABS(Y) THEN 1230 */
line_1200:;
    if (Y>0   &&   Y<7   &&   floor(Y)==fabs(Y)) { goto line_1230; }
    /* BASIC: 1210 PRINT "INVALID INPUT.  TRY AGAIN." */
line_1210:;
    printf("%s", "INVALID INPUT.  TRY AGAIN."); printf("\n");
    /* BASIC: 1220 GOTO 1180 */
line_1220:;
    goto line_1180;
    /* BASIC: 1230 R=7-Y */
line_1230:;
    R = 7-Y;
    /* BASIC: 1240 C=X */
line_1240:;
    C = X;
    /* BASIC: 1250 IF F(R,C)>0 THEN 1290 */
line_1250:;
    if (F_arr[(int)(R) * 100 + (int)(C)]>0) { goto line_1290; }
    /* BASIC: 1260 S=S+1 */
line_1260:;
    S = S+1;
    /* BASIC: 1270 PRINT "SPLASH!  TRY AGAIN." */
line_1270:;
    printf("%s", "SPLASH!  TRY AGAIN."); printf("\n");
    /* BASIC: 1280 GOTO 1180 */
line_1280:;
    goto line_1180;
    /* BASIC: 1290 IF C(F(R,C))<4 THEN 1340 */
line_1290:;
    if (C_arr[(int)(F_arr[(int)(R) * 100 + (int)(C)])]<4) { goto line_1340; }
    /* BASIC: 1300 PRINT "THERE USED TO BE A SHIP AT THAT POINT, BUT YOU SUNK IT." */
line_1300:;
    printf("%s", "THERE USED TO BE A SHIP AT THAT POINT, BUT YOU SUNK IT."); printf("\n");
    /* BASIC: 1310 PRINT "SPLASH!  TRY AGAIN." */
line_1310:;
    printf("%s", "SPLASH!  TRY AGAIN."); printf("\n");
    /* BASIC: 1320 S=S+1 */
line_1320:;
    S = S+1;
    /* BASIC: 1330 GOTO 1180 */
line_1330:;
    goto line_1180;
    /* BASIC: 1340 IF H(R,C)>0 THEN 1420 */
line_1340:;
    if (H_arr[(int)(R) * 100 + (int)(C)]>0) { goto line_1420; }
    /* BASIC: 1350 H=H+1 */
line_1350:;
    H = H+1;
    /* BASIC: 1360 H(R,C)=F(R,C) */
line_1360:;
    H_arr[(int)(R) * 100 + (int)(C)] = F_arr[(int)(R) * 100 + (int)(C)];
    /* BASIC: 1370 PRINT "A DIRECT HIT ON SHIP NUMBER";F(R,C) */
line_1370:;
    printf("%s", "A DIRECT HIT ON SHIP NUMBER"); printf("%g ", (double)(F_arr[(int)(R) * 100 + (int)(C)])); printf("\n");
    /* BASIC: 1380 C(F(R,C))=C(F(R,C))+1 */
line_1380:;
    C_arr[(int)(F_arr[(int)(R) * 100 + (int)(C)])] = C_arr[(int)(F_arr[(int)(R) * 100 + (int)(C)])]+1;
    /* BASIC: 1390 IF C(F(R,C))>=4 THEN 1470 */
line_1390:;
    if (C_arr[(int)(F_arr[(int)(R) * 100 + (int)(C)])]>=4) { goto line_1470; }
    /* BASIC: 1400 PRINT "TRY AGAIN." */
line_1400:;
    printf("%s", "TRY AGAIN."); printf("\n");
    /* BASIC: 1410 GOTO 1180 */
line_1410:;
    goto line_1180;
    /* BASIC: 1420 PRINT "YOU ALREADY PUT A HOLE IN SHIP NUMBER";F(R,C); */
line_1420:;
    printf("%s", "YOU ALREADY PUT A HOLE IN SHIP NUMBER"); printf("%g ", (double)(F_arr[(int)(R) * 100 + (int)(C)]));
    /* BASIC: 1430 PRINT "AT THAT POINT." */
line_1430:;
    printf("%s", "AT THAT POINT."); printf("\n");
    /* BASIC: 1440 PRINT "SPLASH!  TRY AGAIN." */
line_1440:;
    printf("%s", "SPLASH!  TRY AGAIN."); printf("\n");
    /* BASIC: 1450 S=S+1 */
line_1450:;
    S = S+1;
    /* BASIC: 1460 GOTO 1180 */
line_1460:;
    goto line_1180;
    /* BASIC: 1470 L((INT(F(R,C)-1)/2)+1)=L((INT(F(R,C)-1)/2)+1)+1 */
line_1470:;
    L_arr[(int)((floor(F_arr[(int)(R) * 100 + (int)(C)]-1)/2)+1)] = L_arr[(int)((floor(F_arr[(int)(R) * 100 + (int)(C)]-1)/2)+1)]+1;
    /* BASIC: 1480 PRINT "AND YOU SUNK IT.  HURRAH FOR THE GOOD GUYS." */
line_1480:;
    printf("%s", "AND YOU SUNK IT.  HURRAH FOR THE GOOD GUYS."); printf("\n");
    /* BASIC: 1490 PRINT "SO FAR, THE BAD GUYS HAVE LOST" */
line_1490:;
    printf("%s", "SO FAR, THE BAD GUYS HAVE LOST"); printf("\n");
    /* BASIC: 1500 PRINT L(1);"DESTROYER(S),";L(2);"CRUISER(S), AND"; */
line_1500:;
    printf("%g ", (double)(L_arr[(int)(1)])); printf("%s", "DESTROYER(S),"); printf("%g ", (double)(L_arr[(int)(2)])); printf("%s", "CRUISER(S), AND");
    /* BASIC: 1510 PRINT L(3);"AIRCRAFT CARRIER(S)." */
line_1510:;
    printf("%g ", (double)(L_arr[(int)(3)])); printf("%s", "AIRCRAFT CARRIER(S)."); printf("\n");
    /* BASIC: 1520 PRINT "YOUR CURRENT SPLASH/HIT RATIO IS";S/H */
line_1520:;
    printf("%s", "YOUR CURRENT SPLASH/HIT RATIO IS"); printf("%g ", (double)(S/H)); printf("\n");
    /* BASIC: 1530 IF (L(1)+L(2)+L(3))<6 THEN 1180 */
line_1530:;
    if ((L_arr[(int)(1)]+L_arr[(int)(2)]+L_arr[(int)(3)])<6) { goto line_1180; }
    /* BASIC: 1540 PRINT */
line_1540:;
    printf("\n");
    /* BASIC: 1550 PRINT "YOU HAVE TOTALLY WIPED OUT THE BAD GUYS' FLEET" */
line_1550:;
    printf("%s", "YOU HAVE TOTALLY WIPED OUT THE BAD GUYS' FLEET"); printf("\n");
    /* BASIC: 1560 PRINT "WITH A FINAL SPLASH/HIT RATIO OF";S/H */
line_1560:;
    printf("%s", "WITH A FINAL SPLASH/HIT RATIO OF"); printf("%g ", (double)(S/H)); printf("\n");
    /* BASIC: 1570 IF S/H>0 THEN 1590 */
line_1570:;
    if (S/H>0) { goto line_1590; }
    /* BASIC: 1580 PRINT "CONGRATULATIONS -- A DIRECT HIT EVERY TIME." */
line_1580:;
    printf("%s", "CONGRATULATIONS -- A DIRECT HIT EVERY TIME."); printf("\n");
    /* BASIC: 1590 PRINT */
line_1590:;
    printf("\n");
    /* BASIC: 1600 PRINT "****************************" */
line_1600:;
    printf("%s", "****************************"); printf("\n");
    /* BASIC: 1610 PRINT */
line_1610:;
    printf("\n");
    /* BASIC: 1620 GOTO 50 */
line_1620:;
    goto line_50;
    /* BASIC: 1630 END */
line_1630:;
    exit(0);

    return 0;
}
