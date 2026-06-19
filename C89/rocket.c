/*
 * Transpiled from rocket.bas
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
static double B, D, F, H, T, V, V1;
static char A_str[256] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(30); "ROCKET" */
line_10:;
    { int _t; for(_t=0; _t<30; _t++) printf(" "); } printf("%s", "ROCKET"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 70 PRINT "LUNAR LANDING SIMULATION" */
line_70:;
    printf("%s", "LUNAR LANDING SIMULATION"); printf("\n");
    /* BASIC: 80 PRINT "----- ------- ----------": PRINT */
line_80:;
    printf("%s", "----- ------- ----------"); printf("\n");
    printf("\n");
    /* BASIC: 100 INPUT "DO YOU WANT INSTRUCTIONS (YES OR NO)";A$ */
line_100:;
    printf("%s", "DO YOU WANT INSTRUCTIONS (YES OR NO)"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    /* BASIC: 110 IF A$="NO" THEN 390 */
line_110:;
    if (strcmp(A_str, "NO") == 0) { goto line_390; }
    /* BASIC: 160 PRINT */
line_160:;
    printf("\n");
    /* BASIC: 200 PRINT"YOU ARE LANDING ON THE MOON AND AND HAVE TAKEN OVER MANUAL" */
line_200:;
    printf("%s", "YOU ARE LANDING ON THE MOON AND AND HAVE TAKEN OVER MANUAL"); printf("\n");
    /* BASIC: 210 PRINT"CONTROL 1000 FEET ABOVE A GOOD LANDING SPOT. YOU HAVE A DOWN-" */
line_210:;
    printf("%s", "CONTROL 1000 FEET ABOVE A GOOD LANDING SPOT. YOU HAVE A DOWN-"); printf("\n");
    /* BASIC: 220 PRINT"WARD VELOCITY OF 50 FEET/SEC. 150 UNITS OF FUEL REMAIN." */
line_220:;
    printf("%s", "WARD VELOCITY OF 50 FEET/SEC. 150 UNITS OF FUEL REMAIN."); printf("\n");
    /* BASIC: 225 PRINT */
line_225:;
    printf("\n");
    /* BASIC: 230 PRINT"HERE ARE THE RULES THAT GOVERN YOUR APOLLO SPACE-CRAFT:": PRINT */
line_230:;
    printf("%s", "HERE ARE THE RULES THAT GOVERN YOUR APOLLO SPACE-CRAFT:"); printf("\n");
    printf("\n");
    /* BASIC: 240 PRINT"(1) AFTER EACH SECOND THE HEIGHT, VELOCITY, AND REMAINING FUEL" */
line_240:;
    printf("%s", "(1) AFTER EACH SECOND THE HEIGHT, VELOCITY, AND REMAINING FUEL"); printf("\n");
    /* BASIC: 250 PRINT"    WILL BE REPORTED VIA DIGBY YOUR ON-BOARD COMPUTER." */
line_250:;
    printf("%s", "    WILL BE REPORTED VIA DIGBY YOUR ON-BOARD COMPUTER."); printf("\n");
    /* BASIC: 260 PRINT"(2) AFTER THE REPORT A '?' WILL APPEAR. ENTER THE NUMBER" */
line_260:;
    printf("%s", "(2) AFTER THE REPORT A '?' WILL APPEAR. ENTER THE NUMBER"); printf("\n");
    /* BASIC: 270 PRINT"    OF UNITS OF FUEL YOU WISH TO BURN DURING THE NEXT" */
line_270:;
    printf("%s", "    OF UNITS OF FUEL YOU WISH TO BURN DURING THE NEXT"); printf("\n");
    /* BASIC: 280 PRINT"    SECOND. EACH UNIT OF FUEL WILL SLOW YOUR DESCENT BY" */
line_280:;
    printf("%s", "    SECOND. EACH UNIT OF FUEL WILL SLOW YOUR DESCENT BY"); printf("\n");
    /* BASIC: 290 PRINT"    1 FOOT/SEC." */
line_290:;
    printf("%s", "    1 FOOT/SEC."); printf("\n");
    /* BASIC: 310 PRINT"(3) THE MAXIMUM THRUST OF YOUR ENGINE IS 30 FEET/SEC/SEC" */
line_310:;
    printf("%s", "(3) THE MAXIMUM THRUST OF YOUR ENGINE IS 30 FEET/SEC/SEC"); printf("\n");
    /* BASIC: 320 PRINT"    OR 30 UNITS OF FUEL PER SECOND." */
line_320:;
    printf("%s", "    OR 30 UNITS OF FUEL PER SECOND."); printf("\n");
    /* BASIC: 330 PRINT"(4) WHEN YOU CONTACT THE LUNAR SURFACE. YOUR DESCENT ENGINE" */
line_330:;
    printf("%s", "(4) WHEN YOU CONTACT THE LUNAR SURFACE. YOUR DESCENT ENGINE"); printf("\n");
    /* BASIC: 340 PRINT"    WILL AUTOMATICALLY SHUT DOWN AND YOU WILL BE GIVEN A" */
line_340:;
    printf("%s", "    WILL AUTOMATICALLY SHUT DOWN AND YOU WILL BE GIVEN A"); printf("\n");
    /* BASIC: 350 PRINT"    REPORT OF YOUR LANDING SPEED AND REMAINING FUEL." */
line_350:;
    printf("%s", "    REPORT OF YOUR LANDING SPEED AND REMAINING FUEL."); printf("\n");
    /* BASIC: 360 PRINT"(5) IF YOU RUN OUT OF FUEL THE '?' WILL NO LONGER APPEAR" */
line_360:;
    printf("%s", "(5) IF YOU RUN OUT OF FUEL THE '?' WILL NO LONGER APPEAR"); printf("\n");
    /* BASIC: 370 PRINT"    BUT YOUR SECOND BY SECOND REPORT WILL CONTINUE UNTIL" */
line_370:;
    printf("%s", "    BUT YOUR SECOND BY SECOND REPORT WILL CONTINUE UNTIL"); printf("\n");
    /* BASIC: 380 PRINT"    YOU CONTACT THE LUNAR SURFACE.":PRINT */
line_380:;
    printf("%s", "    YOU CONTACT THE LUNAR SURFACE."); printf("\n");
    printf("\n");
    /* BASIC: 390 PRINT"BEGINNING LANDING PROCEDURE..........":PRINT */
line_390:;
    printf("%s", "BEGINNING LANDING PROCEDURE.........."); printf("\n");
    printf("\n");
    /* BASIC: 400 PRINT"G O O D  L U C K ! ! !" */
line_400:;
    printf("%s", "G O O D  L U C K ! ! !"); printf("\n");
    /* BASIC: 420 PRINT:PRINT */
line_420:;
    printf("\n");
    printf("\n");
    /* BASIC: 430 PRINT"SEC  FEET      SPEED     FUEL     PLOT OF DISTANCE" */
line_430:;
    printf("%s", "SEC  FEET      SPEED     FUEL     PLOT OF DISTANCE"); printf("\n");
    /* BASIC: 450 PRINT */
line_450:;
    printf("\n");
    /* BASIC: 455 T=0:H=1000:V=50:F=150 */
line_455:;
    T = 0;
    H = 1000;
    V = 50;
    F = 150;
    /* BASIC: 490 PRINT T;TAB(6);H;TAB(16);V;TAB(26);F;TAB(35);"I";TAB(H/15);"*" */
line_490:;
    printf("%g ", (double)(T)); { int _t; for(_t=0; _t<6; _t++) printf(" "); } printf("%g ", (double)(H)); { int _t; for(_t=0; _t<16; _t++) printf(" "); } printf("%g ", (double)(V)); { int _t; for(_t=0; _t<26; _t++) printf(" "); } printf("%g ", (double)(F)); { int _t; for(_t=0; _t<35; _t++) printf(" "); } printf("%s", "I"); { int _t; for(_t=0; _t<H/15; _t++) printf(" "); } printf("%s", "*"); printf("\n");
    /* BASIC: 500 INPUT B */
line_500:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &B);
    /* BASIC: 510 IF B<0 THEN 650 */
line_510:;
    if (B<0) { goto line_650; }
    /* BASIC: 520 IF B>30 THEN B=30 */
line_520:;
    if (B>30) { B = 30; }
    /* BASIC: 530 IF B>F THEN B=F */
line_530:;
    if (B>F) { B = F; }
    /* BASIC: 540 V1=V-B+5 */
line_540:;
    V1 = V-B+5;
    /* BASIC: 560 F=F-B */
line_560:;
    F = F-B;
    /* BASIC: 570 H=H- .5*(V+V1) */
line_570:;
    H = H- .5*(V+V1);
    /* BASIC: 580 IF H<=0 THEN 670 */
line_580:;
    if (H<=0) { goto line_670; }
    /* BASIC: 590 T=T+1 */
line_590:;
    T = T+1;
    /* BASIC: 600 V=V1 */
line_600:;
    V = V1;
    /* BASIC: 610 IF F>0 THEN 490 */
line_610:;
    if (F>0) { goto line_490; }
    /* BASIC: 615 IF B=0 THEN 640 */
line_615:;
    if (B==0) { goto line_640; }
    /* BASIC: 620 PRINT"**** OUT OF FUEL ****" */
line_620:;
    printf("%s", "**** OUT OF FUEL ****"); printf("\n");
    /* BASIC: 640 PRINT T;TAB(4);H;TAB(12);V;TAB(20);F;TAB(29);"I";TAB(H/12+29);"*" */
line_640:;
    printf("%g ", (double)(T)); { int _t; for(_t=0; _t<4; _t++) printf(" "); } printf("%g ", (double)(H)); { int _t; for(_t=0; _t<12; _t++) printf(" "); } printf("%g ", (double)(V)); { int _t; for(_t=0; _t<20; _t++) printf(" "); } printf("%g ", (double)(F)); { int _t; for(_t=0; _t<29; _t++) printf(" "); } printf("%s", "I"); { int _t; for(_t=0; _t<H/12+29; _t++) printf(" "); } printf("%s", "*"); printf("\n");
    /* BASIC: 650 B=0 */
line_650:;
    B = 0;
    /* BASIC: 660 GOTO 540 */
line_660:;
    goto line_540;
    /* BASIC: 670 PRINT"***** CONTACT *****" */
line_670:;
    printf("%s", "***** CONTACT *****"); printf("\n");
    /* BASIC: 680 H=H+ .5*(V1+V) */
line_680:;
    H = H+ .5*(V1+V);
    /* BASIC: 690 IF B=5 THEN 720 */
line_690:;
    if (B==5) { goto line_720; }
    /* BASIC: 700 D=(-V+SQR(V*V+H*(10-2*B)))/(5-B) */
line_700:;
    D = (-V+sqrt(V*V+H*(10-2*B)))/(5-B);
    /* BASIC: 710 GOTO 730 */
line_710:;
    goto line_730;
    /* BASIC: 720 D=H/V */
line_720:;
    D = H/V;
    /* BASIC: 730 V1=V+(5-B)*D */
line_730:;
    V1 = V+(5-B)*D;
    /* BASIC: 760 PRINT"TOUCHDOWN AT";T+D;"SECONDS." */
line_760:;
    printf("%s", "TOUCHDOWN AT"); printf("%g ", (double)(T+D)); printf("%s", "SECONDS."); printf("\n");
    /* BASIC: 770 PRINT"LANDING VELOCITY=";V1;"FEET/SEC." */
line_770:;
    printf("%s", "LANDING VELOCITY="); printf("%g ", (double)(V1)); printf("%s", "FEET/SEC."); printf("\n");
    /* BASIC: 780 PRINT F;"UNITS OF FUEL REMAINING." */
line_780:;
    printf("%g ", (double)(F)); printf("%s", "UNITS OF FUEL REMAINING."); printf("\n");
    /* BASIC: 790 IF V1<>0 THEN 810 */
line_790:;
    if (V1!=0) { goto line_810; }
    /* BASIC: 800 PRINT"CONGRATULATIONS! A PERFECT LANDING!!" */
line_800:;
    printf("%s", "CONGRATULATIONS! A PERFECT LANDING!!"); printf("\n");
    /* BASIC: 805 PRINT"YOUR LICENSE WILL BE RENEWED.......LATER." */
line_805:;
    printf("%s", "YOUR LICENSE WILL BE RENEWED.......LATER."); printf("\n");
    /* BASIC: 810 IF ABS(V1)<2 THEN 840 */
line_810:;
    if (fabs(V1)<2) { goto line_840; }
    /* BASIC: 820 PRINT"***** SORRY, BUT YOU BLEW IT!!!!" */
line_820:;
    printf("%s", "***** SORRY, BUT YOU BLEW IT!!!!"); printf("\n");
    /* BASIC: 830 PRINT"APPROPRIATE CONDOLENCES WILL BE SENT TO YOUR NEXT OF KIN." */
line_830:;
    printf("%s", "APPROPRIATE CONDOLENCES WILL BE SENT TO YOUR NEXT OF KIN."); printf("\n");
    /* BASIC: 840 PRINT:PRINT:PRINT */
line_840:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 850 INPUT "ANOTHER MISSION";A$ */
line_850:;
    printf("%s", "ANOTHER MISSION"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    /* BASIC: 860 IF A$="YES" THEN 390 */
line_860:;
    if (strcmp(A_str, "YES") == 0) { goto line_390; }
    /* BASIC: 870 PRINT: PRINT "CONTROL OUT.": PRINT */
line_870:;
    printf("\n");
    printf("%s", "CONTROL OUT."); printf("\n");
    printf("\n");
    /* BASIC: 999 END */
line_999:;
    exit(0);

    return 0;
}
