/*
 * Transpiled from bombsaway.bas
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
static double A, B, D, G, M, ON, R, S, T;
static char F_str[256] = {0};
static char U_str[256] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 8 PRINT "YOU ARE A PILOT IN A WORLD WAR II BOMBER." */
line_8:;
    printf("%s", "YOU ARE A PILOT IN A WORLD WAR II BOMBER."); printf("\n");
    /* BASIC: 10 INPUT "WHAT SIDE -- ITALY(1), ALLIES(2), JAPAN(3), GERMANY(4)";A */
line_10:;
    printf("%s", "WHAT SIDE -- ITALY(1), ALLIES(2), JAPAN(3), GERMANY(4)"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &A);
    /* BASIC: 20 IF A>0 AND A<5 THEN 25 */
line_20:;
    if (A>0   &&   A<5) { goto line_25; }
    /* BASIC: 22 PRINT "TRY AGAIN..." : GOTO 10 */
line_22:;
    printf("%s", "TRY AGAIN..."); printf("\n");
    goto line_10;
    /* BASIC: 25 ON A GOTO 30, 110, 200, 220 */
line_25:;
    switch ((int)(A)) {     case 1: goto line_30;     case 2: goto line_110;     case 3: goto line_200;     case 4: goto line_220; }
    /* BASIC: 30 INPUT "YOUR TARGET -- ALBANIA(1), GREECE(2), NORTH AFRICA(3)";B */
line_30:;
    printf("%s", "YOUR TARGET -- ALBANIA(1), GREECE(2), NORTH AFRICA(3)"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &B);
    /* BASIC: 40 IF B>0 AND B<4 THEN 45 */
line_40:;
    if (B>0   &&   B<4) { goto line_45; }
    /* BASIC: 42 PRINT "TRY AGAIN..." : GOTO 30 */
line_42:;
    printf("%s", "TRY AGAIN..."); printf("\n");
    goto line_30;
    /* BASIC: 45 PRINT : ON B GOTO 50, 80,90 */
line_45:;
    printf("\n");
    switch ((int)(B)) {     case 1: goto line_50;     case 2: goto line_80;     case 3: goto line_90; }
    /* BASIC: 50 PRINT "SHOULD BE EASY -- YOU'RE FLYING A NAZI-MADE PLANE." */
line_50:;
    printf("%s", "SHOULD BE EASY -- YOU'RE FLYING A NAZI-MADE PLANE."); printf("\n");
    /* BASIC: 60 GOTO 280 */
line_60:;
    goto line_280;
    /* BASIC: 80 PRINT "BE CAREFUL!!!" : GOTO 280 */
line_80:;
    printf("%s", "BE CAREFUL!!!"); printf("\n");
    goto line_280;
    /* BASIC: 90 PRINT "YOU'RE GOING FOR THE OIL, EH?" : GOTO 280 */
line_90:;
    printf("%s", "YOU'RE GOING FOR THE OIL, EH?"); printf("\n");
    goto line_280;
    /* BASIC: 110 INPUT "AIRCRAFT -- LIBERATOR(1), B-29(2), B-17(3), LANCASTER(4)";G */
line_110:;
    printf("%s", "AIRCRAFT -- LIBERATOR(1), B-29(2), B-17(3), LANCASTER(4)"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &G);
    /* BASIC: 120 IF G>0 AND G<5 THEN 125 */
line_120:;
    if (G>0   &&   G<5) { goto line_125; }
    /* BASIC: 122 PRINT "TRY AGAIN..." : GOTO 110 */
line_122:;
    printf("%s", "TRY AGAIN..."); printf("\n");
    goto line_110;
    /* BASIC: 125 PRINT : ON G GOTO 130, 150, 170, 190 */
line_125:;
    printf("\n");
    switch ((int)(G)) {     case 1: goto line_130;     case 2: goto line_150;     case 3: goto line_170;     case 4: goto line_190; }
    /* BASIC: 130 PRINT "YOU'VE GOT 2 TONS OF BOMBS FLYING FOR PLOESTI." : GOTO 280 */
line_130:;
    printf("%s", "YOU'VE GOT 2 TONS OF BOMBS FLYING FOR PLOESTI."); printf("\n");
    goto line_280;
    /* BASIC: 150 PRINT "YOU'RE DUMPING THE A-BOMB ON HIROSHIMA." : GOTO 280 */
line_150:;
    printf("%s", "YOU'RE DUMPING THE A-BOMB ON HIROSHIMA."); printf("\n");
    goto line_280;
    /* BASIC: 170 PRINT "YOU'RE CHASING THE BISMARK IN THE NORTH SEA." : GOTO 280 */
line_170:;
    printf("%s", "YOU'RE CHASING THE BISMARK IN THE NORTH SEA."); printf("\n");
    goto line_280;
    /* BASIC: 190 PRINT "YOU'RE BUSTING A GERMAN HEAVY WATER PLANT IN THE RUHR." */
line_190:;
    printf("%s", "YOU'RE BUSTING A GERMAN HEAVY WATER PLANT IN THE RUHR."); printf("\n");
    /* BASIC: 195 GOTO 280 */
line_195:;
    goto line_280;
    /* BASIC: 200 PRINT "YOU'RE FLYING A KAMIKAZE MISSION OVER THE USS LEXINGTON." */
line_200:;
    printf("%s", "YOU'RE FLYING A KAMIKAZE MISSION OVER THE USS LEXINGTON."); printf("\n");
    /* BASIC: 205 INPUT "YOUR FIRST KAMIKAZE MISSION(Y OR N)";F$ */
line_205:;
    printf("%s", "YOUR FIRST KAMIKAZE MISSION(Y OR N)"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", F_str);
    /* BASIC: 207 IF F$="N" THEN S=0 : GOTO 358 */
line_207:;
    if (strcmp(F_str, "N") == 0) { S = 0; goto line_358; }
    /* BASIC: 210 PRINT : IF RND(1)>.65 THEN 325 */
line_210:;
    printf("\n");
    if (((double)rand() / (double)RAND_MAX)>.65) { goto line_325; }
    /* BASIC: 215 GOTO 380 */
line_215:;
    goto line_380;
    /* BASIC: 220 PRINT "A NAZI, EH?  OH WELL.  ARE YOU GOING FOR RUSSIA(1)," */
line_220:;
    printf("%s", "A NAZI, EH?  OH WELL.  ARE YOU GOING FOR RUSSIA(1),"); printf("\n");
    /* BASIC: 230 INPUT "ENGLAND(2), OR FRANCE(3)";M : IF M>0 AND M<4 THEN 235 */
line_230:;
    printf("%s", "ENGLAND(2), OR FRANCE(3)"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &M);
    if (M>0   &&   M<4) { goto line_235; }
    /* BASIC: 232 PRINT "TRY AGAIN..." : GOTO 220 */
line_232:;
    printf("%s", "TRY AGAIN..."); printf("\n");
    goto line_220;
    /* BASIC: 235 PRINT : ON M GOTO 250, 260, 270 */
line_235:;
    printf("\n");
    switch ((int)(M)) {     case 1: goto line_250;     case 2: goto line_260;     case 3: goto line_270; }
    /* BASIC: 250 PRINT "YOU'RE NEARING STALINGRAD." : GOTO 280 */
line_250:;
    printf("%s", "YOU'RE NEARING STALINGRAD."); printf("\n");
    goto line_280;
    /* BASIC: 260 PRINT "NEARING LONDON.  BE CAREFUL, THEY'VE GOT RADAR." : GOTO 280 */
line_260:;
    printf("%s", "NEARING LONDON.  BE CAREFUL, THEY'VE GOT RADAR."); printf("\n");
    goto line_280;
    /* BASIC: 270 PRINT "NEARING VERSAILLES.  DUCK SOUP.  THEY'RE NEARLY DEFENSELESS." */
line_270:;
    printf("%s", "NEARING VERSAILLES.  DUCK SOUP.  THEY'RE NEARLY DEFENSELESS."); printf("\n");
    /* BASIC: 280 PRINT */
line_280:;
    printf("\n");
    /* BASIC: 285 INPUT "HOW MANY MISSIONS HAVE YOU FLOWN";D */
line_285:;
    printf("%s", "HOW MANY MISSIONS HAVE YOU FLOWN"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &D);
    /* BASIC: 290 IF D<160 THEN 300 */
line_290:;
    if (D<160) { goto line_300; }
    /* BASIC: 292 PRINT "MISSIONS, NOT MILES..." */
line_292:;
    printf("%s", "MISSIONS, NOT MILES..."); printf("\n");
    /* BASIC: 295 PRINT "150 MISSIONS IS HIGH EVEN FOR OLD-TIMERS." */
line_295:;
    printf("%s", "150 MISSIONS IS HIGH EVEN FOR OLD-TIMERS."); printf("\n");
    /* BASIC: 297 PRINT "NOW THEN, "; : GOTO 285 */
line_297:;
    printf("%s", "NOW THEN, ");
    goto line_285;
    /* BASIC: 300 PRINT:IF D<100 THEN 310 */
line_300:;
    printf("\n");
    if (D<100) { goto line_310; }
    /* BASIC: 305 PRINT "THAT'S PUSHING THE ODDS!" : GOTO 320 */
line_305:;
    printf("%s", "THAT'S PUSHING THE ODDS!"); printf("\n");
    goto line_320;
    /* BASIC: 310 IF D<25 THEN PRINT "FRESH OUT OF TRAINING, EH?" */
line_310:;
    if (D<25) { printf("%s", "FRESH OUT OF TRAINING, EH?"); printf("\n"); }
    /* BASIC: 320 PRINT : IF D<160*RND(1) THEN 330 */
line_320:;
    printf("\n");
    if (D<160*((double)rand() / (double)RAND_MAX)) { goto line_330; }
    /* BASIC: 325 PRINT "DIRECT HIT!!!! "INT(100*RND(1))"KILLED." */
line_325:;
    printf("%s", "DIRECT HIT!!!! "); printf("%g ", (double)(floor(100*((double)rand() / (double)RAND_MAX)))); printf("%s", "KILLED."); printf("\n");
    /* BASIC: 327 PRINT "MISSION SUCCESSFUL." : GOTO 390 */
line_327:;
    printf("%s", "MISSION SUCCESSFUL."); printf("\n");
    goto line_390;
    /* BASIC: 330 PRINT "MISSED TARGET BY"INT(2+30*RND(1))"MILES!" */
line_330:;
    printf("%s", "MISSED TARGET BY"); printf("%g ", (double)(floor(2+30*((double)rand() / (double)RAND_MAX)))); printf("%s", "MILES!"); printf("\n");
    /* BASIC: 335 PRINT "NOW YOU'RE REALLY IN FOR IT !!" : PRINT */
line_335:;
    printf("%s", "NOW YOU'RE REALLY IN FOR IT !!"); printf("\n");
    printf("\n");
    /* BASIC: 340 INPUT "DOES THE ENEMY HAVE GUNS(1), MISSILES(2), OR BOTH(3)";R */
line_340:;
    printf("%s", "DOES THE ENEMY HAVE GUNS(1), MISSILES(2), OR BOTH(3)"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &R);
    /* BASIC: 345 IF R>0 AND R<4 THEN 350 */
line_345:;
    if (R>0   &&   R<4) { goto line_350; }
    /* BASIC: 347 PRINT "TRY AGAIN..." : GOTO 340 */
line_347:;
    printf("%s", "TRY AGAIN..."); printf("\n");
    goto line_340;
    /* BASIC: 350 PRINT : T=0 : IF R=2 THEN 360 */
line_350:;
    printf("\n");
    T = 0;
    if (R==2) { goto line_360; }
    /* BASIC: 355 INPUT "WHAT'S THE PERCENT HIT RATE OF ENEMY GUNNERS (10 TO 50)";S */
line_355:;
    printf("%s", "WHAT'S THE PERCENT HIT RATE OF ENEMY GUNNERS (10 TO 50)"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &S);
    /* BASIC: 357 IF S<10 THEN PRINT "YOU LIE, BUT YOU'LL PAY...": GOTO 380 */
line_357:;
    if (S<10) { printf("%s", "YOU LIE, BUT YOU'LL PAY..."); printf("\n"); goto line_380; }
    /* BASIC: 358 PRINT */
line_358:;
    printf("\n");
    /* BASIC: 360 PRINT : IF R>1 THEN T=35 */
line_360:;
    printf("\n");
    if (R>1) { T = 35; }
    /* BASIC: 365 IF S+T>100*RND(1) THEN 380 */
line_365:;
    if (S+T>100*((double)rand() / (double)RAND_MAX)) { goto line_380; }
    /* BASIC: 370 PRINT "YOU MADE IT THROUGH TREMENDOUS FLAK!!" : GOTO 390 */
line_370:;
    printf("%s", "YOU MADE IT THROUGH TREMENDOUS FLAK!!"); printf("\n");
    goto line_390;
    /* BASIC: 380 PRINT "* * * * BOOM * * * *" */
line_380:;
    printf("%s", "* * * * BOOM * * * *"); printf("\n");
    /* BASIC: 384 PRINT "YOU HAVE BEEN SHOT DOWN....." */
line_384:;
    printf("%s", "YOU HAVE BEEN SHOT DOWN....."); printf("\n");
    /* BASIC: 386 PRINT "DEARLY BELOVED, WE ARE GATHERED HERE TODAY TO PAY OUR" */
line_386:;
    printf("%s", "DEARLY BELOVED, WE ARE GATHERED HERE TODAY TO PAY OUR"); printf("\n");
    /* BASIC: 387 PRINT "LAST TRIBUTE..." */
line_387:;
    printf("%s", "LAST TRIBUTE..."); printf("\n");
    /* BASIC: 390 PRINT:PRINT:PRINT:INPUT "ANOTHER MISSION (Y OR N)";U$ */
line_390:;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("%s", "ANOTHER MISSION (Y OR N)"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", U_str);
    /* BASIC: 395 IF U$="Y" THEN 8 */
line_395:;
    if (strcmp(U_str, "Y") == 0) { goto line_8; }
    /* BASIC: 400 PRINT "CHICKEN !!!" : PRINT : END */
line_400:;
    printf("%s", "CHICKEN !!!"); printf("\n");
    printf("\n");
    exit(0);

    return 0;
}
