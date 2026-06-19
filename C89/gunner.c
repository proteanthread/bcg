/*
 * Transpiled from gunner.bas
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
static double B, B2, E, I, R, S, S1, T, X, Z;
static char Z_str[256] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(30);"GUNNER" */
line_10:;
    { int _t; for(_t=0; _t<30; _t++) printf(" "); } printf("%s", "GUNNER"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 130 PRINT "YOU ARE THE OFFICER-IN-CHARGE, GIVING ORDERS TO A GUN" */
line_130:;
    printf("%s", "YOU ARE THE OFFICER-IN-CHARGE, GIVING ORDERS TO A GUN"); printf("\n");
    /* BASIC: 140 PRINT "CREW, TELLING THEM THE DEGREES OF ELEVATION YOU ESTIMATE" */
line_140:;
    printf("%s", "CREW, TELLING THEM THE DEGREES OF ELEVATION YOU ESTIMATE"); printf("\n");
    /* BASIC: 150 PRINT "WILL PLACE A PROJECTILE ON TARGET.  A HIT WITHIN 100 YARDS" */
line_150:;
    printf("%s", "WILL PLACE A PROJECTILE ON TARGET.  A HIT WITHIN 100 YARDS"); printf("\n");
    /* BASIC: 160 PRINT "OF THE TARGET WILL DESTROY IT." : PRINT */
line_160:;
    printf("%s", "OF THE TARGET WILL DESTROY IT."); printf("\n");
    printf("\n");
    /* BASIC: 170 R=INT(40000*RND(1)+20000) */
line_170:;
    R = floor(40000*((double)rand() / (double)RAND_MAX)+20000);
    /* BASIC: 180 PRINT "MAXIMUM RANGE OF YOUR GUN IS";R;" YARDS." */
line_180:;
    printf("%s", "MAXIMUM RANGE OF YOUR GUN IS"); printf("%g ", (double)(R)); printf("%s", " YARDS."); printf("\n");
    /* BASIC: 185 Z=0 */
line_185:;
    Z = 0;
    /* BASIC: 190 PRINT */
line_190:;
    printf("\n");
    /* BASIC: 195 S1=0 */
line_195:;
    S1 = 0;
    /* BASIC: 200 T=INT(R*(.1+.8*RND(1))) */
line_200:;
    T = floor(R*(.1+.8*((double)rand() / (double)RAND_MAX)));
    /* BASIC: 210 S=0 */
line_210:;
    S = 0;
    /* BASIC: 220 GOTO 370 */
line_220:;
    goto line_370;
    /* BASIC: 230 PRINT "MINIMUM ELEVATION IS ONE DEGREE." */
line_230:;
    printf("%s", "MINIMUM ELEVATION IS ONE DEGREE."); printf("\n");
    /* BASIC: 240 GOTO 390 */
line_240:;
    goto line_390;
    /* BASIC: 250 PRINT "MAXIMUM ELEVATION IS 89 DEGREES." */
line_250:;
    printf("%s", "MAXIMUM ELEVATION IS 89 DEGREES."); printf("\n");
    /* BASIC: 260 GOTO 390 */
line_260:;
    goto line_390;
    /* BASIC: 270 PRINT "OVER TARGET BY ";ABS(E);"YARDS." */
line_270:;
    printf("%s", "OVER TARGET BY "); printf("%g ", (double)(fabs(E))); printf("%s", "YARDS."); printf("\n");
    /* BASIC: 280 GOTO 390 */
line_280:;
    goto line_390;
    /* BASIC: 290 PRINT "SHORT OF TARGET BY "ABS(E);"YARDS." */
line_290:;
    printf("%s", "SHORT OF TARGET BY "); printf("%g ", (double)(fabs(E))); printf("%s", "YARDS."); printf("\n");
    /* BASIC: 300 GOTO 390 */
line_300:;
    goto line_390;
    /* BASIC: 320 PRINT "*** TARGET DESTROYED ***  ";S;"ROUNDS OF AMMUNITION EXPENDED." */
line_320:;
    printf("%s", "*** TARGET DESTROYED ***  "); printf("%g ", (double)(S)); printf("%s", "ROUNDS OF AMMUNITION EXPENDED."); printf("\n");
    /* BASIC: 325 S1=S1+S */
line_325:;
    S1 = S1+S;
    /* BASIC: 330 IF Z=4 THEN 490 */
line_330:;
    if (Z==4) { goto line_490; }
    /* BASIC: 340 Z=Z+1 */
line_340:;
    Z = Z+1;
    /* BASIC: 345 PRINT */
line_345:;
    printf("\n");
    /* BASIC: 350 PRINT "THE FORWARD OBSERVER HAS SIGHTED MORE ENEMY ACTIVITY..." */
line_350:;
    printf("%s", "THE FORWARD OBSERVER HAS SIGHTED MORE ENEMY ACTIVITY..."); printf("\n");
    /* BASIC: 360 GOTO 200 */
line_360:;
    goto line_200;
    /* BASIC: 370 PRINT "DISTANCE TO THE TARGET IS "T;" YARDS." */
line_370:;
    printf("%s", "DISTANCE TO THE TARGET IS "); printf("%g ", (double)(T)); printf("%s", " YARDS."); printf("\n");
    /* BASIC: 380 PRINT */
line_380:;
    printf("\n");
    /* BASIC: 390 PRINT */
line_390:;
    printf("\n");
    /* BASIC: 400 INPUT "ELEVATION";B */
line_400:;
    printf("%s", "ELEVATION"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &B);
    /* BASIC: 420 IF B>89 THEN 250 */
line_420:;
    if (B>89) { goto line_250; }
    /* BASIC: 430 IF B<1 THEN 230 */
line_430:;
    if (B<1) { goto line_230; }
    /* BASIC: 440 S=S+1 */
line_440:;
    S = S+1;
    /* BASIC: 442 IF S<6 THEN 450 */
line_442:;
    if (S<6) { goto line_450; }
    /* BASIC: 444 PRINT:PRINT "BOOM !!!!   YOU HAVE JUST BEEN DESTROYED "; */
line_444:;
    printf("\n");
    printf("%s", "BOOM !!!!   YOU HAVE JUST BEEN DESTROYED ");
    /* BASIC: 446 PRINT "BY THE ENEMY." : PRINT : PRINT : PRINT : GOTO 495 */
line_446:;
    printf("%s", "BY THE ENEMY."); printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    goto line_495;
    /* BASIC: 450 B2=2*B/57.3 : I=R*SIN(B2) : X=T-I : E=INT(X) */
line_450:;
    B2 = 2*B/57.3;
    I = R*sin(B2);
    X = T-I;
    E = floor(X);
    /* BASIC: 460 IF ABS(E)<100 THEN 320 */
line_460:;
    if (fabs(E)<100) { goto line_320; }
    /* BASIC: 470 IF E>100 THEN 290 */
line_470:;
    if (E>100) { goto line_290; }
    /* BASIC: 480 GOTO 270 */
line_480:;
    goto line_270;
    /* BASIC: 490 PRINT : PRINT : PRINT "TOTAL ROUNDS EXPENDED WERE:";S1 */
line_490:;
    printf("\n");
    printf("\n");
    printf("%s", "TOTAL ROUNDS EXPENDED WERE:"); printf("%g ", (double)(S1)); printf("\n");
    /* BASIC: 492 IF S1>18 THEN 495 */
line_492:;
    if (S1>18) { goto line_495; }
    /* BASIC: 493 PRINT "NICE SHOOTING !!" : GOTO 500 */
line_493:;
    printf("%s", "NICE SHOOTING !!"); printf("\n");
    goto line_500;
    /* BASIC: 495 PRINT "BETTER GO BACK TO FORT SILL FOR REFRESHER TRAINING!" */
line_495:;
    printf("%s", "BETTER GO BACK TO FORT SILL FOR REFRESHER TRAINING!"); printf("\n");
    /* BASIC: 500 PRINT : INPUT "TRY AGAIN (Y OR N)";Z$ */
line_500:;
    printf("\n");
    printf("%s", "TRY AGAIN (Y OR N)"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", Z_str);
    /* BASIC: 510 IF Z$="Y" THEN 170 */
line_510:;
    if (strcmp(Z_str, "Y") == 0) { goto line_170; }
    /* BASIC: 520 PRINT:PRINT "OK.  RETURN TO BASE CAMP." */
line_520:;
    printf("\n");
    printf("%s", "OK.  RETURN TO BASE CAMP."); printf("\n");
    /* BASIC: 999 END */
line_999:;
    exit(0);

    return 0;
}
