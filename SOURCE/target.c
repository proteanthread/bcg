/*
 * Transpiled from target.bas
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
static double A, A1, B, B1, D, I, ON, P, P1, P2, P3, Q, R, R1, W, X, X1, X2, Y, Y1, Y2, Z, Z1, Z2;
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(33);"TARGET" */
line_10:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "TARGET"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT: PRINT: PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 100 R=1: R1=57.296: P=3.14159 */
line_100:;
    R = 1;
    R1 = 57.296;
    P = 3.14159;
    /* BASIC: 110 PRINT "YOU ARE THE WEAPONS OFFICER ON THE STARSHIP ENTERPRISE" */
line_110:;
    printf("%s", "YOU ARE THE WEAPONS OFFICER ON THE STARSHIP ENTERPRISE"); printf("\n");
    /* BASIC: 120 PRINT "AND THIS IS A TEST TO SEE HOW ACCURATE A SHOT YOU" */
line_120:;
    printf("%s", "AND THIS IS A TEST TO SEE HOW ACCURATE A SHOT YOU"); printf("\n");
    /* BASIC: 130 PRINT "ARE IN A THREE-DIMENSIONAL RANGE.  YOU WILL BE TOLD" */
line_130:;
    printf("%s", "ARE IN A THREE-DIMENSIONAL RANGE.  YOU WILL BE TOLD"); printf("\n");
    /* BASIC: 140 PRINT "THE RADIAN OFFSET FOR THE X AND Z AXES, THE LOCATION" */
line_140:;
    printf("%s", "THE RADIAN OFFSET FOR THE X AND Z AXES, THE LOCATION"); printf("\n");
    /* BASIC: 150 PRINT "OF THE TARGET IN THREE DIMENSIONAL RECTANGULAR COORDINATES," */
line_150:;
    printf("%s", "OF THE TARGET IN THREE DIMENSIONAL RECTANGULAR COORDINATES,"); printf("\n");
    /* BASIC: 160 PRINT "THE APPROXIMATE NUMBER OF DEGREES FROM THE X AND Z" */
line_160:;
    printf("%s", "THE APPROXIMATE NUMBER OF DEGREES FROM THE X AND Z"); printf("\n");
    /* BASIC: 170 PRINT "AXES, AND THE APPROXIMATE DISTANCE TO THE TARGET." */
line_170:;
    printf("%s", "AXES, AND THE APPROXIMATE DISTANCE TO THE TARGET."); printf("\n");
    /* BASIC: 180 PRINT "YOU WILL THEN PROCEEED TO SHOOT AT THE TARGET UNTIL IT IS" */
line_180:;
    printf("%s", "YOU WILL THEN PROCEEED TO SHOOT AT THE TARGET UNTIL IT IS"); printf("\n");
    /* BASIC: 190 PRINT "DESTROYED!": PRINT: PRINT "GOOD LUCK!!":PRINT: PRINT */
line_190:;
    printf("%s", "DESTROYED!"); printf("\n");
    printf("\n");
    printf("%s", "GOOD LUCK!!"); printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 220 A=RND(1)*2*P: B=RND(1)*2*P: Q=INT(A*R1): W=INT(B*R1) */
line_220:;
    A = ((double)rand() / (double)RAND_MAX)*2*P;
    B = ((double)rand() / (double)RAND_MAX)*2*P;
    Q = floor(A*R1);
    W = floor(B*R1);
    /* BASIC: 260 PRINT "RADIANS FROM X AXIS =";A;"   FROM Z AXIS =";B */
line_260:;
    printf("%s", "RADIANS FROM X AXIS ="); printf("%g ", (double)(A)); printf("%s", "   FROM Z AXIS ="); printf("%g ", (double)(B)); printf("\n");
    /* BASIC: 280 P1=100000*RND(1)+RND(1): X=SIN(B)*COS(A)*P1: Y=SIN(B)*SIN(A)*P1 */
line_280:;
    P1 = 100000*((double)rand() / (double)RAND_MAX)+((double)rand() / (double)RAND_MAX);
    X = sin(B)*cos(A)*P1;
    Y = sin(B)*sin(A)*P1;
    /* BASIC: 290 Z=COS(B)*P1 */
line_290:;
    Z = cos(B)*P1;
    /* BASIC: 340 PRINT "TARGET SIGHTED: APPROXIMATE COORDINATES:  X=";X;"  Y=";Y;"  Z=";Z */
line_340:;
    printf("%s", "TARGET SIGHTED: APPROXIMATE COORDINATES:  X="); printf("%g ", (double)(X)); printf("%s", "  Y="); printf("%g ", (double)(Y)); printf("%s", "  Z="); printf("%g ", (double)(Z)); printf("\n");
    /* BASIC: 345 R=R+1: IF R>5 THEN 390 */
line_345:;
    R = R+1;
    if (R>5) { goto line_390; }
    /* BASIC: 350 ON R GOTO 355,360,365,370,375 */
line_350:;
    switch ((int)(R)) {     case 1: goto line_355;     case 2: goto line_360;     case 3: goto line_365;     case 4: goto line_370;     case 5: goto line_375; }
    /* BASIC: 355 P3=INT(P1*.05)*20: GOTO 390 */
line_355:;
    P3 = floor(P1*.05)*20;
    goto line_390;
    /* BASIC: 360 P3=INT(P1*.1)*10: GOTO 390 */
line_360:;
    P3 = floor(P1*.1)*10;
    goto line_390;
    /* BASIC: 365 P3=INT(P1*.5)*2: GOTO 390 */
line_365:;
    P3 = floor(P1*.5)*2;
    goto line_390;
    /* BASIC: 370 P3=INT(P1): GOTO 390 */
line_370:;
    P3 = floor(P1);
    goto line_390;
    /* BASIC: 375 P3=P1 */
line_375:;
    P3 = P1;
    /* BASIC: 390 PRINT "     ESTIMATED DISTANCE:";P3 */
line_390:;
    printf("%s", "     ESTIMATED DISTANCE:"); printf("%g ", (double)(P3)); printf("\n");
    /* BASIC: 400 PRINT:PRINT "INPUT ANGLE DEVIATION FROM X, DEVIATION FROM Z, DISTANCE"; */
line_400:;
    printf("\n");
    printf("%s", "INPUT ANGLE DEVIATION FROM X, DEVIATION FROM Z, DISTANCE");
    /* BASIC: 405 INPUT A1,B1,P2 */
line_405:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf %lf", &A1, &B1, &P2);
    /* BASIC: 410 PRINT: IF P2<20 THEN PRINT "YOU BLEW YOURSELF UP!!": GOTO 580 */
line_410:;
    printf("\n");
    if (P2<20) { printf("%s", "YOU BLEW YOURSELF UP!!"); printf("\n"); }
    goto line_580;
    /* BASIC: 420 A1=A1/R1: B1=B1/R1: PRINT "RADIANS FROM X AXIS =";A1;"  "; */
line_420:;
    A1 = A1/R1;
    B1 = B1/R1;
    printf("%s", "RADIANS FROM X AXIS ="); printf("%g ", (double)(A1)); printf("%s", "  ");
    /* BASIC: 425 PRINT "FROM Z AXIS =";B1 */
line_425:;
    printf("%s", "FROM Z AXIS ="); printf("%g ", (double)(B1)); printf("\n");
    /* BASIC: 480 X1=P2*SIN(B1)*COS(A1): Y1=P2*SIN(B1)*SIN(A1): Z1=P2*COS(B1) */
line_480:;
    X1 = P2*sin(B1)*cos(A1);
    Y1 = P2*sin(B1)*sin(A1);
    Z1 = P2*cos(B1);
    /* BASIC: 510 D=((X1-X)^2+(Y1-Y)^2+(Z1-Z)^2)^(1/2) */
line_510:;
    D = pow((pow((X1-X), 2)+pow((Y1-Y), 2)+pow((Z1-Z), 2)), (1/2));
    /* BASIC: 520 IF D>20 THEN 670 */
line_520:;
    if (D>20) { goto line_670; }
    /* BASIC: 530 PRINT: PRINT " * * * HIT * * *   TARGET IS NON-FUNCTIONAL": PRINT */
line_530:;
    printf("\n");
    printf("%s", " * * * HIT * * *   TARGET IS NON-FUNCTIONAL"); printf("\n");
    printf("\n");
    /* BASIC: 550 PRINT "DISTANCE OF EXPLOSION FROM TARGET WAS";D;"KILOMETERS." */
line_550:;
    printf("%s", "DISTANCE OF EXPLOSION FROM TARGET WAS"); printf("%g ", (double)(D)); printf("%s", "KILOMETERS."); printf("\n");
    /* BASIC: 570 PRINT: PRINT "MISSION ACCOMPLISHED IN ";R;" SHOTS." */
line_570:;
    printf("\n");
    printf("%s", "MISSION ACCOMPLISHED IN "); printf("%g ", (double)(R)); printf("%s", " SHOTS."); printf("\n");
    /* BASIC: 580 R=0: FOR I=1 TO 5: PRINT: NEXT I: PRINT "NEXT TARGET...": PRINT */
line_580:;
    R = 0;
    I = 1; for_loop_I_580: if (((1) >= 0 && I > (5)) || ((1) < 0 && I < (5))) goto end_for_I_580;
    printf("\n");
    I += (1); goto for_loop_I_580; end_for_I_580:;
    printf("%s", "NEXT TARGET..."); printf("\n");
    printf("\n");
    /* BASIC: 590 GOTO 220 */
line_590:;
    goto line_220;
    /* BASIC: 670 X2=X1-X: Y2=Y1-Y: Z2=Z1-Z: IF X2<0 THEN 730 */
line_670:;
    X2 = X1-X;
    Y2 = Y1-Y;
    Z2 = Z1-Z;
    if (X2<0) { goto line_730; }
    /* BASIC: 710 PRINT "SHOT IN FRONT OF TARGET";X2;"KILOMETERS.": GOTO 740 */
line_710:;
    printf("%s", "SHOT IN FRONT OF TARGET"); printf("%g ", (double)(X2)); printf("%s", "KILOMETERS."); printf("\n");
    goto line_740;
    /* BASIC: 730 PRINT "SHOT BEHIND TARGET";-X2;"KILOMETERS." */
line_730:;
    printf("%s", "SHOT BEHIND TARGET"); printf("%g ", (double)(-X2)); printf("%s", "KILOMETERS."); printf("\n");
    /* BASIC: 740 IF Y2<0 THEN 770 */
line_740:;
    if (Y2<0) { goto line_770; }
    /* BASIC: 750 PRINT "SHOT TO LEFT OF TARGET";Y2;"KILOMETERS.": GOTO 780 */
line_750:;
    printf("%s", "SHOT TO LEFT OF TARGET"); printf("%g ", (double)(Y2)); printf("%s", "KILOMETERS."); printf("\n");
    goto line_780;
    /* BASIC: 770 PRINT "SHOT TO RIGHT OF TARGET";-Y2;"KILOMETERS." */
line_770:;
    printf("%s", "SHOT TO RIGHT OF TARGET"); printf("%g ", (double)(-Y2)); printf("%s", "KILOMETERS."); printf("\n");
    /* BASIC: 780 IF Z2<0 THEN 810 */
line_780:;
    if (Z2<0) { goto line_810; }
    /* BASIC: 790 PRINT "SHOT ABOVE TARGET";Z2;"KILOMETERS.": GOTO 820 */
line_790:;
    printf("%s", "SHOT ABOVE TARGET"); printf("%g ", (double)(Z2)); printf("%s", "KILOMETERS."); printf("\n");
    goto line_820;
    /* BASIC: 810 PRINT "SHOT BELOW TARGET";-Z2;"KILOMETERS." */
line_810:;
    printf("%s", "SHOT BELOW TARGET"); printf("%g ", (double)(-Z2)); printf("%s", "KILOMETERS."); printf("\n");
    /* BASIC: 820 PRINT "APPROX POSITION OF EXPLOSION:  X=";X1;"   Y=";Y1;"   Z=";Z1 */
line_820:;
    printf("%s", "APPROX POSITION OF EXPLOSION:  X="); printf("%g ", (double)(X1)); printf("%s", "   Y="); printf("%g ", (double)(Y1)); printf("%s", "   Z="); printf("%g ", (double)(Z1)); printf("\n");
    /* BASIC: 830 PRINT "     DISTANCE FROM TARGET =";D: PRINT: PRINT: PRINT: GOTO 345 */
line_830:;
    printf("%s", "     DISTANCE FROM TARGET ="); printf("%g ", (double)(D)); printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    goto line_345;
    /* BASIC: 999 END */
line_999:;
    exit(0);

    return 0;
}
