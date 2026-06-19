/*
 * Transpiled from lem.bas
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
static double A, A1, A2, A3, A4, B, B1, C, D, D1, F, F1, G3, G5, H, H0, H1, I, K, M, M0, M1, M2, N, P, R, R0, R1, R2, R3, R4, S, T, T1, T2, V0, X, X1, Z;
static char M_str[256] = {0};
static char N_str[256] = {0};
static char Q_str[256] = {0};
static char Z_str[256] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 2 PRINT TAB(34);"LEM" */
line_2:;
    { int _t; for(_t=0; _t<34; _t++) printf(" "); } printf("%s", "LEM"); printf("\n");
    /* BASIC: 4 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 7 REM ROCKT2 IS AN INTERACTIVE GAME THAT SIMULATES A LUNAR */
line_7:;
    /* REM ROCKT2 IS AN INTERACTIVE GAME THAT SIMULATES A LUNAR */
    /* BASIC: 8 REM L AND ING IS SIMILAR TO THAT OF THE APOLLO PROGRAM. */
line_8:;
    /* REM L AND ING IS SIMILAR TO THAT OF THE APOLLO PROGRAM. */
    /* BASIC: 9 REM THERE IS ABSOLUTELY NO CHANCE INVOLVED */
line_9:;
    /* REM THERE IS ABSOLUTELY NO CHANCE INVOLVED */
    /* BASIC: 10 Z$="GO" */
line_10:;
    str_assign(Z_str, sizeof(Z_str), "GO");
    /* BASIC: 15 B1=1 */
line_15:;
    B1 = 1;
    /* BASIC: 20 M=17.95 */
line_20:;
    M = 17.95;
    /* BASIC: 25 F1=5.25 */
line_25:;
    F1 = 5.25;
    /* BASIC: 30 N=7.5 */
line_30:;
    N = 7.5;
    /* BASIC: 35 R0=926 */
line_35:;
    R0 = 926;
    /* BASIC: 40 V0=1.29 */
line_40:;
    V0 = 1.29;
    /* BASIC: 45 T=0 */
line_45:;
    T = 0;
    /* BASIC: 50 H0=60 */
line_50:;
    H0 = 60;
    /* BASIC: 55 R=R0+H0 */
line_55:;
    R = R0+H0;
    /* BASIC: 60 A=-3.425 */
line_60:;
    A = -3.425;
    /* BASIC: 65 R1=0 */
line_65:;
    R1 = 0;
    /* BASIC: 70 A1=8.84361E-04 */
line_70:;
    A1 = 8.84361E-04;
    /* BASIC: 75 R3=0 */
line_75:;
    R3 = 0;
    /* BASIC: 80 A3=0 */
line_80:;
    A3 = 0;
    /* BASIC: 85 M1=7.45 */
line_85:;
    M1 = 7.45;
    /* BASIC: 90 M0=M1 */
line_90:;
    M0 = M1;
    /* BASIC: 95 B=750 */
line_95:;
    B = 750;
    /* BASIC: 100 T1=0 */
line_100:;
    T1 = 0;
    /* BASIC: 105 F=0 */
line_105:;
    F = 0;
    /* BASIC: 110 P=0 */
line_110:;
    P = 0;
    /* BASIC: 115 N=1 */
line_115:;
    N = 1;
    /* BASIC: 120 M2=0 */
line_120:;
    M2 = 0;
    /* BASIC: 125 S=0 */
line_125:;
    S = 0;
    /* BASIC: 130 C=0 */
line_130:;
    C = 0;
    /* BASIC: 135 IF Z$="YES" THEN 1150 */
line_135:;
    if (strcmp(Z_str, "YES") == 0) { goto line_1150; }
    /* BASIC: 140 PRINT */
line_140:;
    printf("\n");
    /* BASIC: 145 PRINT "LUNAR LANDING SIMULATION" */
line_145:;
    printf("%s", "LUNAR LANDING SIMULATION"); printf("\n");
    /* BASIC: 150 PRINT */
line_150:;
    printf("\n");
    /* BASIC: 155 PRINT "HAVE YOU FLOWN AN APOLLO/LEM MISSION BEFORE"; */
line_155:;
    printf("%s", "HAVE YOU FLOWN AN APOLLO/LEM MISSION BEFORE");
    /* BASIC: 160 PRINT " (YES OR NO)"; */
line_160:;
    printf("%s", " (YES OR NO)");
    /* BASIC: 165 INPUT Q$ */
line_165:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", Q_str);
    /* BASIC: 170 IF Q$="YES" THEN 190 */
line_170:;
    if (strcmp(Q_str, "YES") == 0) { goto line_190; }
    /* BASIC: 175 IF Q$="NO" THEN 205 */
line_175:;
    if (strcmp(Q_str, "NO") == 0) { goto line_205; }
    /* BASIC: 180 PRINT "JUST ANSWER THE QUESTION, PLEASE, "; */
line_180:;
    printf("%s", "JUST ANSWER THE QUESTION, PLEASE, ");
    /* BASIC: 185 GOTO 160 */
line_185:;
    goto line_160;
    /* BASIC: 190 PRINT */
line_190:;
    printf("\n");
    /* BASIC: 195 PRINT "INPUT MEASUREMENT OPTION NUMBER"; */
line_195:;
    printf("%s", "INPUT MEASUREMENT OPTION NUMBER");
    /* BASIC: 200 GOTO 225 */
line_200:;
    goto line_225;
    /* BASIC: 205 PRINT */
line_205:;
    printf("\n");
    /* BASIC: 210 PRINT "WHICH SYSTEM OF MEASUREMENT DO YOU PREFER?" */
line_210:;
    printf("%s", "WHICH SYSTEM OF MEASUREMENT DO YOU PREFER?"); printf("\n");
    /* BASIC: 215 PRINT " 1=METRIC     0=ENGLISH" */
line_215:;
    printf("%s", " 1=METRIC     0=ENGLISH"); printf("\n");
    /* BASIC: 220 PRINT "ENTER THE APPROPRIATE NUMBER"; */
line_220:;
    printf("%s", "ENTER THE APPROPRIATE NUMBER");
    /* BASIC: 225 INPUT K */
line_225:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &K);
    /* BASIC: 230 PRINT */
line_230:;
    printf("\n");
    /* BASIC: 235 IF K=0 THEN 280 */
line_235:;
    if (K==0) { goto line_280; }
    /* BASIC: 240 IF K=1 THEN 250 */
line_240:;
    if (K==1) { goto line_250; }
    /* BASIC: 245 GOTO 220 */
line_245:;
    goto line_220;
    /* BASIC: 250 Z=1852.8 */
line_250:;
    Z = 1852.8;
    /* BASIC: 255 M$="METERS" */
line_255:;
    str_assign(M_str, sizeof(M_str), "METERS");
    /* BASIC: 260 G3=3.6 */
line_260:;
    G3 = 3.6;
    /* BASIC: 265 N$=" KILOMETERS" */
line_265:;
    str_assign(N_str, sizeof(N_str), " KILOMETERS");
    /* BASIC: 270 G5=1000 */
line_270:;
    G5 = 1000;
    /* BASIC: 275 GOTO 305 */
line_275:;
    goto line_305;
    /* BASIC: 280 Z=6080 */
line_280:;
    Z = 6080;
    /* BASIC: 285 M$="FEET" */
line_285:;
    str_assign(M_str, sizeof(M_str), "FEET");
    /* BASIC: 290 G3=.592 */
line_290:;
    G3 = .592;
    /* BASIC: 295 N$="N.MILES" */
line_295:;
    str_assign(N_str, sizeof(N_str), "N.MILES");
    /* BASIC: 300 G5=Z */
line_300:;
    G5 = Z;
    /* BASIC: 305 IF B1=3 THEN 670 */
line_305:;
    if (B1==3) { goto line_670; }
    /* BASIC: 310 IF Q$="YES" THEN 485 */
line_310:;
    if (strcmp(Q_str, "YES") == 0) { goto line_485; }
    /* BASIC: 315 PRINT */
line_315:;
    printf("\n");
    /* BASIC: 320 PRINT "  YOU ARE ON A LUNAR LANDING MISSION.  AS THE PILOT OF" */
line_320:;
    printf("%s", "  YOU ARE ON A LUNAR LANDING MISSION.  AS THE PILOT OF"); printf("\n");
    /* BASIC: 325 PRINT "THE LUNAR EXCURSION MODULE, YOU WILL BE EXPECTED TO" */
line_325:;
    printf("%s", "THE LUNAR EXCURSION MODULE, YOU WILL BE EXPECTED TO"); printf("\n");
    /* BASIC: 330 PRINT "GIVE CERTAIN COMMANDS TO THE MODULE NAVIGATION SYSTEM." */
line_330:;
    printf("%s", "GIVE CERTAIN COMMANDS TO THE MODULE NAVIGATION SYSTEM."); printf("\n");
    /* BASIC: 335 PRINT "THE ON-BOARD COMPUTER WILL GIVE A RUNNING ACCOUNT" */
line_335:;
    printf("%s", "THE ON-BOARD COMPUTER WILL GIVE A RUNNING ACCOUNT"); printf("\n");
    /* BASIC: 340 PRINT "OF INFORMATION NEEDED TO NAVIGATE THE SHIP." */
line_340:;
    printf("%s", "OF INFORMATION NEEDED TO NAVIGATE THE SHIP."); printf("\n");
    /* BASIC: 345 PRINT */
line_345:;
    printf("\n");
    /* BASIC: 350 PRINT */
line_350:;
    printf("\n");
    /* BASIC: 355 PRINT "THE ATTITUDE ANGLE CALLED FOR IS DESCRIBED AS FOLLOWS." */
line_355:;
    printf("%s", "THE ATTITUDE ANGLE CALLED FOR IS DESCRIBED AS FOLLOWS."); printf("\n");
    /* BASIC: 360 PRINT "+ OR -180 DEGREES IS DIRECTLY AWAY FROM THE MOON" */
line_360:;
    printf("%s", "+ OR -180 DEGREES IS DIRECTLY AWAY FROM THE MOON"); printf("\n");
    /* BASIC: 365 PRINT "-90 DEGREES IS ON A TANGENT IN THE DIRECTION OF ORBIT" */
line_365:;
    printf("%s", "-90 DEGREES IS ON A TANGENT IN THE DIRECTION OF ORBIT"); printf("\n");
    /* BASIC: 370 PRINT "+90 DEGREES IS ON A TANGENT FROM THE DIRECTION OF ORBIT" */
line_370:;
    printf("%s", "+90 DEGREES IS ON A TANGENT FROM THE DIRECTION OF ORBIT"); printf("\n");
    /* BASIC: 375 PRINT "0 (ZERO) DEGREES IS DIRECTLY TOWARD THE MOON" */
line_375:;
    printf("%s", "0 (ZERO) DEGREES IS DIRECTLY TOWARD THE MOON"); printf("\n");
    /* BASIC: 380 PRINT */
line_380:;
    printf("\n");
    /* BASIC: 385 PRINT TAB(30);"-180|+180" */
line_385:;
    { int _t; for(_t=0; _t<30; _t++) printf(" "); } printf("%s", "-180|+180"); printf("\n");
    /* BASIC: 390 PRINT TAB(34);"^" */
line_390:;
    { int _t; for(_t=0; _t<34; _t++) printf(" "); } printf("%s", "^"); printf("\n");
    /* BASIC: 395 PRINT TAB(27);"-90 < -+- > +90" */
line_395:;
    { int _t; for(_t=0; _t<27; _t++) printf(" "); } printf("%s", "-90 < -+- > +90"); printf("\n");
    /* BASIC: 400 PRINT TAB(34);"!" */
line_400:;
    { int _t; for(_t=0; _t<34; _t++) printf(" "); } printf("%s", "!"); printf("\n");
    /* BASIC: 405 PRINT TAB(34);"0" */
line_405:;
    { int _t; for(_t=0; _t<34; _t++) printf(" "); } printf("%s", "0"); printf("\n");
    /* BASIC: 410 PRINT TAB(21);"<<<< DIRECTION OF ORBIT <<<<" */
line_410:;
    { int _t; for(_t=0; _t<21; _t++) printf(" "); } printf("%s", "<<<< DIRECTION OF ORBIT <<<<"); printf("\n");
    /* BASIC: 415 PRINT */
line_415:;
    printf("\n");
    /* BASIC: 420 PRINT TAB(20);"------ SURFACE OF MOON ------" */
line_420:;
    { int _t; for(_t=0; _t<20; _t++) printf(" "); } printf("%s", "------ SURFACE OF MOON ------"); printf("\n");
    /* BASIC: 425 PRINT */
line_425:;
    printf("\n");
    /* BASIC: 430 PRINT */
line_430:;
    printf("\n");
    /* BASIC: 435 PRINT "ALL ANGLES BETWEEN -180 AND +180 DEGREES ARE ACCEPTED." */
line_435:;
    printf("%s", "ALL ANGLES BETWEEN -180 AND +180 DEGREES ARE ACCEPTED."); printf("\n");
    /* BASIC: 440 PRINT */
line_440:;
    printf("\n");
    /* BASIC: 445 PRINT "1 FUEL UNIT = 1 SEC. AT MAX THRUST" */
line_445:;
    printf("%s", "1 FUEL UNIT = 1 SEC. AT MAX THRUST"); printf("\n");
    /* BASIC: 450 PRINT "ANY DISCREPANCIES ARE ACCOUNTED FOR IN THE USE OF FUEL" */
line_450:;
    printf("%s", "ANY DISCREPANCIES ARE ACCOUNTED FOR IN THE USE OF FUEL"); printf("\n");
    /* BASIC: 455 PRINT "FOR AN ATTITUDE CHANGE." */
line_455:;
    printf("%s", "FOR AN ATTITUDE CHANGE."); printf("\n");
    /* BASIC: 460 PRINT "AVAILABLE ENGINE POWER: 0 (ZERO) AND ANY VALUE BETWEEN" */
line_460:;
    printf("%s", "AVAILABLE ENGINE POWER: 0 (ZERO) AND ANY VALUE BETWEEN"); printf("\n");
    /* BASIC: 465 PRINT "10 AND 100 PERCENT." */
line_465:;
    printf("%s", "10 AND 100 PERCENT."); printf("\n");
    /* BASIC: 470 PRINT */
line_470:;
    printf("\n");
    /* BASIC: 475 PRINT"NEGATIVE THRUST OR TIME IS PROHIBITED." */
line_475:;
    printf("%s", "NEGATIVE THRUST OR TIME IS PROHIBITED."); printf("\n");
    /* BASIC: 480 PRINT */
line_480:;
    printf("\n");
    /* BASIC: 485 PRINT */
line_485:;
    printf("\n");
    /* BASIC: 490 PRINT "INPUT: TIME INTERVAL IN SECONDS ------ (T)" */
line_490:;
    printf("%s", "INPUT: TIME INTERVAL IN SECONDS ------ (T)"); printf("\n");
    /* BASIC: 495 PRINT "       PERCENTAGE OF THRUST ---------- (P)" */
line_495:;
    printf("%s", "       PERCENTAGE OF THRUST ---------- (P)"); printf("\n");
    /* BASIC: 500 PRINT "       ATTITUDE ANGLE IN DEGREES ----- (A)" */
line_500:;
    printf("%s", "       ATTITUDE ANGLE IN DEGREES ----- (A)"); printf("\n");
    /* BASIC: 505 PRINT */
line_505:;
    printf("\n");
    /* BASIC: 510 IF Q$="YES" THEN 535 */
line_510:;
    if (strcmp(Q_str, "YES") == 0) { goto line_535; }
    /* BASIC: 515 PRINT "FOR EXAMPLE:" */
line_515:;
    printf("%s", "FOR EXAMPLE:"); printf("\n");
    /* BASIC: 520 PRINT "T,P,A? 10,65,-60" */
line_520:;
    printf("%s", "T,P,A? 10,65,-60"); printf("\n");
    /* BASIC: 525 PRINT "TO ABORT THE MISSION AT ANY TIME, ENTER 0,0,0" */
line_525:;
    printf("%s", "TO ABORT THE MISSION AT ANY TIME, ENTER 0,0,0"); printf("\n");
    /* BASIC: 530 PRINT */
line_530:;
    printf("\n");
    /* BASIC: 535 PRINT "OUTPUT: TOTAL TIME IN ELAPSED SECONDS" */
line_535:;
    printf("%s", "OUTPUT: TOTAL TIME IN ELAPSED SECONDS"); printf("\n");
    /* BASIC: 540 PRINT "        HEIGHT IN ";M$ */
line_540:;
    printf("%s", "        HEIGHT IN "); printf("%s", M_str); printf("\n");
    /* BASIC: 545 PRINT "        DISTANCE FROM LANDING SITE IN ";M$ */
line_545:;
    printf("%s", "        DISTANCE FROM LANDING SITE IN "); printf("%s", M_str); printf("\n");
    /* BASIC: 550 PRINT "        VERTICAL VELOCITY IN ";M$;"/SECOND" */
line_550:;
    printf("%s", "        VERTICAL VELOCITY IN "); printf("%s", M_str); printf("%s", "/SECOND"); printf("\n");
    /* BASIC: 555 PRINT "        HORIZONTAL VELOCITY IN ";M$;"/SECOND" */
line_555:;
    printf("%s", "        HORIZONTAL VELOCITY IN "); printf("%s", M_str); printf("%s", "/SECOND"); printf("\n");
    /* BASIC: 560 PRINT "        FUEL UNITS REMAINING" */
line_560:;
    printf("%s", "        FUEL UNITS REMAINING"); printf("\n");
    /* BASIC: 565 PRINT */
line_565:;
    printf("\n");
    /* BASIC: 570 GOTO 670 */
line_570:;
    goto line_670;
    /* BASIC: 575 PRINT */
line_575:;
    printf("\n");
    /* BASIC: 580 PRINT "T,P,A"; */
line_580:;
    printf("%s", "T,P,A");
    /* BASIC: 585 INPUT T1,F,P */
line_585:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf %lf", &T1, &F, &P);
    /* BASIC: 590 F=F/100 */
line_590:;
    F = F/100;
    /* BASIC: 595 IF T1<0 THEN 905 */
line_595:;
    if (T1<0) { goto line_905; }
    /* BASIC: 600 IF T1=0 THEN 1090 */
line_600:;
    if (T1==0) { goto line_1090; }
    /* BASIC: 605 IF ABS(F-.05)>1 THEN 945 */
line_605:;
    if (fabs(F-.05)>1) { goto line_945; }
    /* BASIC: 610 IF ABS(F-.05)<.05 THEN 945 */
line_610:;
    if (fabs(F-.05)<.05) { goto line_945; }
    /* BASIC: 615 IF ABS(P)>180 THEN 925 */
line_615:;
    if (fabs(P)>180) { goto line_925; }
    /* BASIC: 620 N=20 */
line_620:;
    N = 20;
    /* BASIC: 625 IF T1<400 THEN 635 */
line_625:;
    if (T1<400) { goto line_635; }
    /* BASIC: 630 N=T1/20 */
line_630:;
    N = T1/20;
    /* BASIC: 635 T1=T1/N */
line_635:;
    T1 = T1/N;
    /* BASIC: 640 P=P*3.14159/180 */
line_640:;
    P = P*3.14159/180;
    /* BASIC: 645 S=SIN(P) */
line_645:;
    S = sin(P);
    /* BASIC: 650 C=COS(P) */
line_650:;
    C = cos(P);
    /* BASIC: 655 M2=M0*T1*F/B */
line_655:;
    M2 = M0*T1*F/B;
    /* BASIC: 660 R3=-.5*R0*((V0/R)^2)+R*A1*A1 */
line_660:;
    R3 = -.5*R0*(pow((V0/R), 2))+R*A1*A1;
    /* BASIC: 665 A3=-2*R1*A1/R */
line_665:;
    A3 = -2*R1*A1/R;
    /* BASIC: 670 FOR I=1 TO N */
line_670:;
    I = 1; for_loop_I_670: if (((1) >= 0 && I > (N)) || ((1) < 0 && I < (N))) goto end_for_I_670;
    /* BASIC: 675 IF M1=0 THEN 715 */
line_675:;
    if (M1==0) { goto line_715; }
    /* BASIC: 680 M1=M1-M2 */
line_680:;
    M1 = M1-M2;
    /* BASIC: 685 IF M1>0 THEN 725 */
line_685:;
    if (M1>0) { goto line_725; }
    /* BASIC: 690 F=F*(1+M1/M2) */
line_690:;
    F = F*(1+M1/M2);
    /* BASIC: 695 M2=M1+M2 */
line_695:;
    M2 = M1+M2;
    /* BASIC: 700 PRINT "YOU ARE OUT OF FUEL." */
line_700:;
    printf("%s", "YOU ARE OUT OF FUEL."); printf("\n");
    /* BASIC: 705 M1=0 */
line_705:;
    M1 = 0;
    /* BASIC: 710 GOTO 725 */
line_710:;
    goto line_725;
    /* BASIC: 715 F=0 */
line_715:;
    F = 0;
    /* BASIC: 720 M2=0 */
line_720:;
    M2 = 0;
    /* BASIC: 725 M=M-.5*M2 */
line_725:;
    M = M-.5*M2;
    /* BASIC: 730 R4=R3 */
line_730:;
    R4 = R3;
    /* BASIC: 735 R3=-.5*R0*((V0/R)^2)+R*A1*A1 */
line_735:;
    R3 = -.5*R0*(pow((V0/R), 2))+R*A1*A1;
    /* BASIC: 740 R2=(3*R3-R4)/2+.00526*F1*F*C/M */
line_740:;
    R2 = (3*R3-R4)/2+.00526*F1*F*C/M;
    /* BASIC: 745 A4=A3 */
line_745:;
    A4 = A3;
    /* BASIC: 750 A3=-2*R1*A1/R */
line_750:;
    A3 = -2*R1*A1/R;
    /* BASIC: 755 A2=(3*A3-A4)/2+.0056*F1*F*S/(M*R) */
line_755:;
    A2 = (3*A3-A4)/2+.0056*F1*F*S/(M*R);
    /* BASIC: 760 X=R1*T1+.5*R2*T1*T1 */
line_760:;
    X = R1*T1+.5*R2*T1*T1;
    /* BASIC: 765 R=R+X */
line_765:;
    R = R+X;
    /* BASIC: 770 H0=H0+X */
line_770:;
    H0 = H0+X;
    /* BASIC: 775 R1=R1+R2*T1 */
line_775:;
    R1 = R1+R2*T1;
    /* BASIC: 780 A=A+A1*T1+.5*A2*T1*T1 */
line_780:;
    A = A+A1*T1+.5*A2*T1*T1;
    /* BASIC: 785 A1=A1+A2*T1 */
line_785:;
    A1 = A1+A2*T1;
    /* BASIC: 790 M=M-.5*M2 */
line_790:;
    M = M-.5*M2;
    /* BASIC: 795 T=T+T1 */
line_795:;
    T = T+T1;
    /* BASIC: 800 IF H0<3.287828E-04 THEN 810 */
line_800:;
    if (H0<3.287828E-04) { goto line_810; }
    /* BASIC: 805 NEXT I */
line_805:;
    I += (1); goto for_loop_I_670; end_for_I_670:;
    /* BASIC: 810 H=H0*Z */
line_810:;
    H = H0*Z;
    /* BASIC: 815 H1=R1*Z */
line_815:;
    H1 = R1*Z;
    /* BASIC: 820 D=R0*A*Z */
line_820:;
    D = R0*A*Z;
    /* BASIC: 825 D1=R*A1*Z */
line_825:;
    D1 = R*A1*Z;
    /* BASIC: 830 T2=M1*B/M0 */
line_830:;
    T2 = M1*B/M0;
    /* BASIC: 835 PRINT " ";T;TAB(10);H;TAB(23);D; */
line_835:;
    printf("%s", " "); printf("%g ", (double)(T)); { int _t; for(_t=0; _t<10; _t++) printf(" "); } printf("%g ", (double)(H)); { int _t; for(_t=0; _t<23; _t++) printf(" "); } printf("%g ", (double)(D));
    /* BASIC: 840 PRINT TAB(37);H1;TAB(49);D1;TAB(60);T2 */
line_840:;
    { int _t; for(_t=0; _t<37; _t++) printf(" "); } printf("%g ", (double)(H1)); { int _t; for(_t=0; _t<49; _t++) printf(" "); } printf("%g ", (double)(D1)); { int _t; for(_t=0; _t<60; _t++) printf(" "); } printf("%g ", (double)(T2)); printf("\n");
    /* BASIC: 845 IF H0<3.287828E-04 THEN 880 */
line_845:;
    if (H0<3.287828E-04) { goto line_880; }
    /* BASIC: 850 IF R0*A>164.474 THEN 1050 */
line_850:;
    if (R0*A>164.474) { goto line_1050; }
    /* BASIC: 855 IF M1>0 THEN 580 */
line_855:;
    if (M1>0) { goto line_580; }
    /* BASIC: 860 T1=20 */
line_860:;
    T1 = 20;
    /* BASIC: 865 F=0 */
line_865:;
    F = 0;
    /* BASIC: 870 P=0 */
line_870:;
    P = 0;
    /* BASIC: 875 GOTO 620 */
line_875:;
    goto line_620;
    /* BASIC: 880 IF R1<-8.21957E-04 THEN 1020 */
line_880:;
    if (R1<-8.21957E-04) { goto line_1020; }
    /* BASIC: 885 IF ABS(R*A1)>4.93174E-04 THEN 1020 */
line_885:;
    if (fabs(R*A1)>4.93174E-04) { goto line_1020; }
    /* BASIC: 890 IF H0<-3.287828E-04 THEN 1020 */
line_890:;
    if (H0<-3.287828E-04) { goto line_1020; }
    /* BASIC: 895 IF ABS(D)>10*Z THEN 1065 */
line_895:;
    if (fabs(D)>10*Z) { goto line_1065; }
    /* BASIC: 900 GOTO 995 */
line_900:;
    goto line_995;
    /* BASIC: 905 PRINT */
line_905:;
    printf("\n");
    /* BASIC: 910 PRINT "THIS SPACECRAFT IS NOT ABLE TO VIOLATE THE SPACE-"; */
line_910:;
    printf("%s", "THIS SPACECRAFT IS NOT ABLE TO VIOLATE THE SPACE-");
    /* BASIC: 915 PRINT "TIME CONTINUUM." */
line_915:;
    printf("%s", "TIME CONTINUUM."); printf("\n");
    /* BASIC: 920 GOTO 575 */
line_920:;
    goto line_575;
    /* BASIC: 925 PRINT */
line_925:;
    printf("\n");
    /* BASIC: 930 PRINT "IF YOU WANT TO SPIN AROUND, GO OUTSIDE THE MODULE" */
line_930:;
    printf("%s", "IF YOU WANT TO SPIN AROUND, GO OUTSIDE THE MODULE"); printf("\n");
    /* BASIC: 935 PRINT "FOR AN E.V.A." */
line_935:;
    printf("%s", "FOR AN E.V.A."); printf("\n");
    /* BASIC: 940 GOTO 575 */
line_940:;
    goto line_575;
    /* BASIC: 945 PRINT */
line_945:;
    printf("\n");
    /* BASIC: 950 PRINT "IMPOSSIBLE THRUST VALUE "; */
line_950:;
    printf("%s", "IMPOSSIBLE THRUST VALUE ");
    /* BASIC: 955 IF F<0 THEN 985 */
line_955:;
    if (F<0) { goto line_985; }
    /* BASIC: 960 IF F-.05<.05 THEN 975 */
line_960:;
    if (F-.05<.05) { goto line_975; }
    /* BASIC: 965 PRINT "TOO LARGE" */
line_965:;
    printf("%s", "TOO LARGE"); printf("\n");
    /* BASIC: 970 GOTO 575 */
line_970:;
    goto line_575;
    /* BASIC: 975 PRINT "TOO SMALL" */
line_975:;
    printf("%s", "TOO SMALL"); printf("\n");
    /* BASIC: 980 GOTO 575 */
line_980:;
    goto line_575;
    /* BASIC: 985 PRINT "NEGATIVE" */
line_985:;
    printf("%s", "NEGATIVE"); printf("\n");
    /* BASIC: 990 GOTO 575 */
line_990:;
    goto line_575;
    /* BASIC: 995 PRINT */
line_995:;
    printf("\n");
    /* BASIC: 1000 PRINT "TRANQUILITY BASE HERE -- THE EAGLE HAS LANDED." */
line_1000:;
    printf("%s", "TRANQUILITY BASE HERE -- THE EAGLE HAS LANDED."); printf("\n");
    /* BASIC: 1005 PRINT "CONGRATULATIONS -- THERE WAS NO SPACECRAFT DAMAGE." */
line_1005:;
    printf("%s", "CONGRATULATIONS -- THERE WAS NO SPACECRAFT DAMAGE."); printf("\n");
    /* BASIC: 1010 PRINT "YOU MAY NOW PROCEED WITH SURFACE EXPLORATION." */
line_1010:;
    printf("%s", "YOU MAY NOW PROCEED WITH SURFACE EXPLORATION."); printf("\n");
    /* BASIC: 1015 GOTO 1100 */
line_1015:;
    goto line_1100;
    /* BASIC: 1020 PRINT */
line_1020:;
    printf("\n");
    /* BASIC: 1025 PRINT "CRASH !!!!!!!!!!!!!!!!" */
line_1025:;
    printf("%s", "CRASH !!!!!!!!!!!!!!!!"); printf("\n");
    /* BASIC: 1030 PRINT "YOUR IMPACT CREATED A CRATER";ABS(H);M$;" DEEP." */
line_1030:;
    printf("%s", "YOUR IMPACT CREATED A CRATER"); printf("%g ", (double)(fabs(H))); printf("%s", M_str); printf("%s", " DEEP."); printf("\n");
    /* BASIC: 1035 X1=SQR(D1*D1+H1*H1)*G3 */
line_1035:;
    X1 = sqrt(D1*D1+H1*H1)*G3;
    /* BASIC: 1040 PRINT "AT CONTACT YOU WERE TRAVELING";X1;N$;"/HR" */
line_1040:;
    printf("%s", "AT CONTACT YOU WERE TRAVELING"); printf("%g ", (double)(X1)); printf("%s", N_str); printf("%s", "/HR"); printf("\n");
    /* BASIC: 1045 GOTO 1100 */
line_1045:;
    goto line_1100;
    /* BASIC: 1050 PRINT */
line_1050:;
    printf("\n");
    /* BASIC: 1055 PRINT "YOU HAVE BEEN LOST IN SPACE WITH NO HOPE OF RECOVERY." */
line_1055:;
    printf("%s", "YOU HAVE BEEN LOST IN SPACE WITH NO HOPE OF RECOVERY."); printf("\n");
    /* BASIC: 1060 GOTO 1100 */
line_1060:;
    goto line_1100;
    /* BASIC: 1065 PRINT "YOU ARE DOWN SAFELY - " */
line_1065:;
    printf("%s", "YOU ARE DOWN SAFELY - "); printf("\n");
    /* BASIC: 1075 PRINT */
line_1075:;
    printf("\n");
    /* BASIC: 1080 PRINT "BUT MISSED THE LANDING SITE BY";ABS(D/G5);N$;"." */
line_1080:;
    printf("%s", "BUT MISSED THE LANDING SITE BY"); printf("%g ", (double)(fabs(D/G5))); printf("%s", N_str); printf("%s", "."); printf("\n");
    /* BASIC: 1085 GOTO 1100 */
line_1085:;
    goto line_1100;
    /* BASIC: 1090 PRINT */
line_1090:;
    printf("\n");
    /* BASIC: 1095 PRINT "MISSION ABENDED" */
line_1095:;
    printf("%s", "MISSION ABENDED"); printf("\n");
    /* BASIC: 1100 PRINT */
line_1100:;
    printf("\n");
    /* BASIC: 1105 PRINT "DO YOU WANT TO TRY IT AGAIN (YES/NO)?" */
line_1105:;
    printf("%s", "DO YOU WANT TO TRY IT AGAIN (YES/NO)?"); printf("\n");
    /* BASIC: 1110 INPUT Z$ */
line_1110:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", Z_str);
    /* BASIC: 1115 IF Z$="YES" THEN 20 */
line_1115:;
    if (strcmp(Z_str, "YES") == 0) { goto line_20; }
    /* BASIC: 1120 IF Z$="NO" THEN 1130 */
line_1120:;
    if (strcmp(Z_str, "NO") == 0) { goto line_1130; }
    /* BASIC: 1125 GOTO 1105 */
line_1125:;
    goto line_1105;
    /* BASIC: 1130 PRINT */
line_1130:;
    printf("\n");
    /* BASIC: 1135 PRINT "TOO BAD, THE SPACE PROGRAM HATES TO LOSE EXPERIENCED" */
line_1135:;
    printf("%s", "TOO BAD, THE SPACE PROGRAM HATES TO LOSE EXPERIENCED"); printf("\n");
    /* BASIC: 1140 PRINT "ASTRONAUTS." */
line_1140:;
    printf("%s", "ASTRONAUTS."); printf("\n");
    /* BASIC: 1145 S TO P */
line_1145:;
    /* UNTRANSLATED: S TO P */
    /* BASIC: 1150 PRINT */
line_1150:;
    printf("\n");
    /* BASIC: 1155 PRINT "OK, DO YOU WANT THE COMPLETE INSTRUCTIONS OR THE INPUT -" */
line_1155:;
    printf("%s", "OK, DO YOU WANT THE COMPLETE INSTRUCTIONS OR THE INPUT -"); printf("\n");
    /* BASIC: 1160 PRINT "OUTPUT STATEMENTS?" */
line_1160:;
    printf("%s", "OUTPUT STATEMENTS?"); printf("\n");
    /* BASIC: 1165 PRINT "1=COMPLETE INSTRUCTIONS" */
line_1165:;
    printf("%s", "1=COMPLETE INSTRUCTIONS"); printf("\n");
    /* BASIC: 1170 PRINT "2=INPUT-OUTPUT STATEMENTS" */
line_1170:;
    printf("%s", "2=INPUT-OUTPUT STATEMENTS"); printf("\n");
    /* BASIC: 1175 PRINT "3=NEITHER" */
line_1175:;
    printf("%s", "3=NEITHER"); printf("\n");
    /* BASIC: 1180 INPUT B1 */
line_1180:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &B1);
    /* BASIC: 1185 Q$="NO" */
line_1185:;
    str_assign(Q_str, sizeof(Q_str), "NO");
    /* BASIC: 1190 IF B1=1 THEN 205 */
line_1190:;
    if (B1==1) { goto line_205; }
    /* BASIC: 1195 Q$="YES" */
line_1195:;
    str_assign(Q_str, sizeof(Q_str), "YES");
    /* BASIC: 1200 IF B1=2 THEN 190 */
line_1200:;
    if (B1==2) { goto line_190; }
    /* BASIC: 1205 IF B1=3 THEN 190 */
line_1205:;
    if (B1==3) { goto line_190; }
    /* BASIC: 1210 GOTO 1165 */
line_1210:;
    goto line_1165;
    /* BASIC: 1215 END */
line_1215:;
    exit(0);

    return 0;
}
