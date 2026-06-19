/*
 * Transpiled from superstartrekins.bas
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
static double I;
static char K_str[256] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 REM INSTRUCTIONS FOR "SUPER STARTREK"  MAR 5, 1978 */
line_10:;
    /* REM INSTRUCTIONS FOR "SUPER STARTREK"  MAR 5, 1978 */
    /* BASIC: 20 FOR I=1 TO 12:PRINT:NEXT I */
line_20:;
    I = 1; for_loop_I_20: if (((1) >= 0 && I > (12)) || ((1) < 0 && I < (12))) goto end_for_I_20;
    printf("\n");
    I += (1); goto for_loop_I_20; end_for_I_20:;
    /* BASIC: 21 PRINT TAB(10);"*************************************" */
line_21:;
    { int _t; for(_t=0; _t<10; _t++) printf(" "); } printf("%s", "*************************************"); printf("\n");
    /* BASIC: 22 PRINT TAB(10);"*                                   *" */
line_22:;
    { int _t; for(_t=0; _t<10; _t++) printf(" "); } printf("%s", "*                                   *"); printf("\n");
    /* BASIC: 23 PRINT TAB(10);"*                                   *" */
line_23:;
    { int _t; for(_t=0; _t<10; _t++) printf(" "); } printf("%s", "*                                   *"); printf("\n");
    /* BASIC: 30 PRINT TAB(10);"*      * * SUPER STAR TREK * *      *" */
line_30:;
    { int _t; for(_t=0; _t<10; _t++) printf(" "); } printf("%s", "*      * * SUPER STAR TREK * *      *"); printf("\n");
    /* BASIC: 31 PRINT TAB(10);"*                                   *" */
line_31:;
    { int _t; for(_t=0; _t<10; _t++) printf(" "); } printf("%s", "*                                   *"); printf("\n");
    /* BASIC: 32 PRINT TAB(10);"*                                   *" */
line_32:;
    { int _t; for(_t=0; _t<10; _t++) printf(" "); } printf("%s", "*                                   *"); printf("\n");
    /* BASIC: 35 PRINT TAB(10);"*************************************" */
line_35:;
    { int _t; for(_t=0; _t<10; _t++) printf(" "); } printf("%s", "*************************************"); printf("\n");
    /* BASIC: 36 FOR I=1 TO 8:PRINT:NEXT I */
line_36:;
    I = 1; for_loop_I_36: if (((1) >= 0 && I > (8)) || ((1) < 0 && I < (8))) goto end_for_I_36;
    printf("\n");
    I += (1); goto for_loop_I_36; end_for_I_36:;
    /* BASIC: 40 INPUT "DO YOU NEED INSTRUCTIONS (Y/N)";K$:IF K$="N" THEN 2000 */
line_40:;
    printf("%s", "DO YOU NEED INSTRUCTIONS (Y/N)"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", K_str);
    if (strcmp(K_str, "N") == 0) { goto line_2000; }
    /* BASIC: 44 PRINT */
line_44:;
    printf("\n");
    /* BASIC: 45 REM PRINT "TURN THE TTY ON-LINE AND HIT ANY KEY EXCEPT RETURN" */
line_45:;
    /* REM PRINT "TURN THE TTY ON-LINE AND HIT ANY KEY EXCEPT RETURN" */
    /* BASIC: 46 REM IF INP(1)=13 THEN 46 */
line_46:;
    /* REM IF INP(1)=13 THEN 46 */
    /* BASIC: 50 REM POKE 1229,2:POKE 1237,3:NULL 1 */
line_50:;
    /* REM POKE 1229,2 */
    /* UNTRANSLATED: POKE 1237,3 */
    /* UNTRANSLATED: NULL 1 */
    /* BASIC: 90 PRINT"      INSTRUCTIONS FOR 'SUPER STAR TREK'" */
line_90:;
    printf("%s", "      INSTRUCTIONS FOR 'SUPER STAR TREK'"); printf("\n");
    /* BASIC: 100 PRINT */
line_100:;
    printf("\n");
    /* BASIC: 110 PRINT"1. WHEN YOU SEE \COMMAND ?\ PRINTED, ENTER ONE OF THE LEGAL" */
line_110:;
    printf("%s", "1. WHEN YOU SEE \\COMMAND ?\\ PRINTED, ENTER ONE OF THE LEGAL"); printf("\n");
    /* BASIC: 120 PRINT"     COMMANDS (NAV,SRS,LRS,PHA,TOR,SHE,DAM,COM, OR XXX)." */
line_120:;
    printf("%s", "     COMMANDS (NAV,SRS,LRS,PHA,TOR,SHE,DAM,COM, OR XXX)."); printf("\n");
    /* BASIC: 130 PRINT"2. IF YOU SHOULD TYPE IN AN ILLEGAL COMMAND, YOU'LL GET A SHORT" */
line_130:;
    printf("%s", "2. IF YOU SHOULD TYPE IN AN ILLEGAL COMMAND, YOU'LL GET A SHORT"); printf("\n");
    /* BASIC: 140 PRINT"     LIST OF THE LEGAL COMMANDS PRINTED OUT." */
line_140:;
    printf("%s", "     LIST OF THE LEGAL COMMANDS PRINTED OUT."); printf("\n");
    /* BASIC: 150 PRINT"3. SOME COMMANDS REQUIRE YOU TO ENTER DATA (FOR EXAMPLE, THE" */
line_150:;
    printf("%s", "3. SOME COMMANDS REQUIRE YOU TO ENTER DATA (FOR EXAMPLE, THE"); printf("\n");
    /* BASIC: 160 PRINT"     'NAV' COMMAND COMES BACK WITH 'COURSE (1-9) ?'.)  IF YOU" */
line_160:;
    printf("%s", "     'NAV' COMMAND COMES BACK WITH 'COURSE (1-9) ?'.)  IF YOU"); printf("\n");
    /* BASIC: 170 PRINT"     TYPE IN ILLEGAL DATA (LIKE NEGATIVE NUMBERS), THAN COMMAND" */
line_170:;
    printf("%s", "     TYPE IN ILLEGAL DATA (LIKE NEGATIVE NUMBERS), THAN COMMAND"); printf("\n");
    /* BASIC: 180 PRINT"     WILL BE ABORTED" */
line_180:;
    printf("%s", "     WILL BE ABORTED"); printf("\n");
    /* BASIC: 190 PRINT */
line_190:;
    printf("\n");
    /* BASIC: 270 PRINT"     THE GALAXY IS DIVIDED INTO AN 8 X 8 QUADRANT GRID," */
line_270:;
    printf("%s", "     THE GALAXY IS DIVIDED INTO AN 8 X 8 QUADRANT GRID,"); printf("\n");
    /* BASIC: 280 PRINT"AND EACH QUADRANT IS FURTHER DIVIDED INTO AN 8 X 8 SECTOR GRID." */
line_280:;
    printf("%s", "AND EACH QUADRANT IS FURTHER DIVIDED INTO AN 8 X 8 SECTOR GRID."); printf("\n");
    /* BASIC: 290 PRINT */
line_290:;
    printf("\n");
    /* BASIC: 300 PRINT"     YOU WILL BE ASSIGNED A STARTING POINT SOMEWHERE IN THE" */
line_300:;
    printf("%s", "     YOU WILL BE ASSIGNED A STARTING POINT SOMEWHERE IN THE"); printf("\n");
    /* BASIC: 310 PRINT"GALAXY TO BEGIN A TOUR OF DUTY AS COMANDER OF THE STARSHIP" */
line_310:;
    printf("%s", "GALAXY TO BEGIN A TOUR OF DUTY AS COMANDER OF THE STARSHIP"); printf("\n");
    /* BASIC: 320 PRINT"\ENTERPRISE\; YOUR MISSION: TO SEEK AND DESTROY THE FLEET OF" */
line_320:;
    printf("%s", "\\ENTERPRISE\\; YOUR MISSION: TO SEEK AND DESTROY THE FLEET OF"); printf("\n");
    /* BASIC: 330 PRINT"KLINGON WARWHIPS WHICH ARE MENACING THE UNITED FEDERATION OF" */
line_330:;
    printf("%s", "KLINGON WARWHIPS WHICH ARE MENACING THE UNITED FEDERATION OF"); printf("\n");
    /* BASIC: 340 PRINT"PLANETS." */
line_340:;
    printf("%s", "PLANETS."); printf("\n");
    /* BASIC: 360 PRINT */
line_360:;
    printf("\n");
    /* BASIC: 370 PRINT"     YOU HAVE THE FOLLOWING COMMANDS AVAILABLE TO YOU AS CAPTAIN" */
line_370:;
    printf("%s", "     YOU HAVE THE FOLLOWING COMMANDS AVAILABLE TO YOU AS CAPTAIN"); printf("\n");
    /* BASIC: 380 PRINT"OF THE STARSHIP ENTERPRISE:" */
line_380:;
    printf("%s", "OF THE STARSHIP ENTERPRISE:"); printf("\n");
    /* BASIC: 385 PRINT */
line_385:;
    printf("\n");
    /* BASIC: 390 PRINT"\NAV\ COMMAND = WARP ENGINE CONTROL --" */
line_390:;
    printf("%s", "\\NAV\\ COMMAND = WARP ENGINE CONTROL --"); printf("\n");
    /* BASIC: 400 PRINT"     COURSE IS IN A CIRCULAR NUMERICAL      4  3  2" */
line_400:;
    printf("%s", "     COURSE IS IN A CIRCULAR NUMERICAL      4  3  2"); printf("\n");
    /* BASIC: 410 PRINT"     VECTOR ARRANGEMENT AS SHOWN             . . ." */
line_410:;
    printf("%s", "     VECTOR ARRANGEMENT AS SHOWN             . . ."); printf("\n");
    /* BASIC: 420 PRINT"     INTEGER AND REAL VALUES MAY BE           ..." */
line_420:;
    printf("%s", "     INTEGER AND REAL VALUES MAY BE           ..."); printf("\n");
    /* BASIC: 430 PRINT"     USED.  (THUS COURSE 1.5 IS HALF-     5 ---*--- 1" */
line_430:;
    printf("%s", "     USED.  (THUS COURSE 1.5 IS HALF-     5 ---*--- 1"); printf("\n");
    /* BASIC: 440 PRINT"     WAY BETWEEN 1 AND 2                      ..." */
line_440:;
    printf("%s", "     WAY BETWEEN 1 AND 2                      ..."); printf("\n");
    /* BASIC: 450 PRINT"                                             . . ." */
line_450:;
    printf("%s", "                                             . . ."); printf("\n");
    /* BASIC: 460 PRINT"     VALUES MAY APPROACH 9.0, WHICH         6  7  8" */
line_460:;
    printf("%s", "     VALUES MAY APPROACH 9.0, WHICH         6  7  8"); printf("\n");
    /* BASIC: 470 PRINT"     ITSELF IS EQUIVALENT TO 1.0" */
line_470:;
    printf("%s", "     ITSELF IS EQUIVALENT TO 1.0"); printf("\n");
    /* BASIC: 480 PRINT"                                            COURSE" */
line_480:;
    printf("%s", "                                            COURSE"); printf("\n");
    /* BASIC: 490 PRINT"     ONE WARP FACTOR IS THE SIZE OF " */
line_490:;
    printf("%s", "     ONE WARP FACTOR IS THE SIZE OF "); printf("\n");
    /* BASIC: 500 PRINT"     ONE QUADTANT.  THEREFORE, TO GET" */
line_500:;
    printf("%s", "     ONE QUADTANT.  THEREFORE, TO GET"); printf("\n");
    /* BASIC: 510 PRINT"     FROM QUADRANT 6,5 TO 5,5, YOU WOULD" */
line_510:;
    printf("%s", "     FROM QUADRANT 6,5 TO 5,5, YOU WOULD"); printf("\n");
    /* BASIC: 520 PRINT"     USE COURSE 3, WARP FACTOR 1." */
line_520:;
    printf("%s", "     USE COURSE 3, WARP FACTOR 1."); printf("\n");
    /* BASIC: 530 PRINT */
line_530:;
    printf("\n");
    /* BASIC: 540 PRINT"\SRS\ COMMAND = SHORT RANGE SENSOR SCAN" */
line_540:;
    printf("%s", "\\SRS\\ COMMAND = SHORT RANGE SENSOR SCAN"); printf("\n");
    /* BASIC: 550 PRINT"     SHOWS YOU A SCAN OF YOUR PRESENT QUADRANT." */
line_550:;
    printf("%s", "     SHOWS YOU A SCAN OF YOUR PRESENT QUADRANT."); printf("\n");
    /* BASIC: 555 PRINT */
line_555:;
    printf("\n");
    /* BASIC: 560 PRINT"     SYMBOLOGY ON YOUR SENSOR SCREEN IS AS FOLLOWS:" */
line_560:;
    printf("%s", "     SYMBOLOGY ON YOUR SENSOR SCREEN IS AS FOLLOWS:"); printf("\n");
    /* BASIC: 570 PRINT"        <*> = YOUR STARSHIP'S POSITION" */
line_570:;
    printf("%s", "        <*> = YOUR STARSHIP'S POSITION"); printf("\n");
    /* BASIC: 580 PRINT"        +K+ = KLINGON BATTLE CRUISER" */
line_580:;
    printf("%s", "        +K+ = KLINGON BATTLE CRUISER"); printf("\n");
    /* BASIC: 590 PRINT"        >!< = FEDERATION STARBASE (REFUEL/REPAIR/RE-ARM HERE!)" */
line_590:;
    printf("%s", "        >!< = FEDERATION STARBASE (REFUEL/REPAIR/RE-ARM HERE!)"); printf("\n");
    /* BASIC: 600 PRINT"         *  = STAR" */
line_600:;
    printf("%s", "         *  = STAR"); printf("\n");
    /* BASIC: 605 PRINT */
line_605:;
    printf("\n");
    /* BASIC: 610 PRINT"     A CONDENSED 'STATUS REPORT' WILL ALSO BE PRESENTED." */
line_610:;
    printf("%s", "     A CONDENSED 'STATUS REPORT' WILL ALSO BE PRESENTED."); printf("\n");
    /* BASIC: 620 PRINT */
line_620:;
    printf("\n");
    /* BASIC: 640 PRINT"\LRS\ COMMAND = LONG RANGE SENSOR SCAN" */
line_640:;
    printf("%s", "\\LRS\\ COMMAND = LONG RANGE SENSOR SCAN"); printf("\n");
    /* BASIC: 650 PRINT"     SHOWS CONDITIONS IN SPACE FOR ONE QUADRANT ON EACH SIDE" */
line_650:;
    printf("%s", "     SHOWS CONDITIONS IN SPACE FOR ONE QUADRANT ON EACH SIDE"); printf("\n");
    /* BASIC: 660 PRINT"     OF THE ENTERPRISE (WHICH IS IN THE MIDDLE OF THE SCAN)" */
line_660:;
    printf("%s", "     OF THE ENTERPRISE (WHICH IS IN THE MIDDLE OF THE SCAN)"); printf("\n");
    /* BASIC: 670 PRINT"     THE SCAN IS CODED IN THE FORM \###\, WHERE TH UNITS DIGIT" */
line_670:;
    printf("%s", "     THE SCAN IS CODED IN THE FORM \\###\\, WHERE TH UNITS DIGIT"); printf("\n");
    /* BASIC: 680 PRINT"     IS THE NUMBER OF STARS, THE TENS DIGIT IS THE NUMBER OF" */
line_680:;
    printf("%s", "     IS THE NUMBER OF STARS, THE TENS DIGIT IS THE NUMBER OF"); printf("\n");
    /* BASIC: 690 PRINT"     STARBASES, AND THE HUNDRESDS DIGIT IS THE NUMBER OF" */
line_690:;
    printf("%s", "     STARBASES, AND THE HUNDRESDS DIGIT IS THE NUMBER OF"); printf("\n");
    /* BASIC: 700 PRINT"     KLINGONS." */
line_700:;
    printf("%s", "     KLINGONS."); printf("\n");
    /* BASIC: 705 PRINT */
line_705:;
    printf("\n");
    /* BASIC: 706 PRINT"     EXAMPLE - 207 = 2 KLINGONS, NO STARBASES, & 7 STARS." */
line_706:;
    printf("%s", "     EXAMPLE - 207 = 2 KLINGONS, NO STARBASES, & 7 STARS."); printf("\n");
    /* BASIC: 710 PRINT */
line_710:;
    printf("\n");
    /* BASIC: 720 PRINT"\PHA\ COMMAND = PHASER CONTROL." */
line_720:;
    printf("%s", "\\PHA\\ COMMAND = PHASER CONTROL."); printf("\n");
    /* BASIC: 730 PRINT"     ALLOWS YOU TO DESTROY THE KLINGON BATTLE CRUISERS BY " */
line_730:;
    printf("%s", "     ALLOWS YOU TO DESTROY THE KLINGON BATTLE CRUISERS BY "); printf("\n");
    /* BASIC: 740 PRINT"     ZAPPING THEM WITH SUITABLY LARGE UNITS OF ENERGY TO" */
line_740:;
    printf("%s", "     ZAPPING THEM WITH SUITABLY LARGE UNITS OF ENERGY TO"); printf("\n");
    /* BASIC: 750 PRINT"     DEPLETE THEIR SHIELD POWER.  (REMBER, KLINGONS HAVE" */
line_750:;
    printf("%s", "     DEPLETE THEIR SHIELD POWER.  (REMBER, KLINGONS HAVE"); printf("\n");
    /* BASIC: 760 PRINT"     PHASERS TOO!)" */
line_760:;
    printf("%s", "     PHASERS TOO!)"); printf("\n");
    /* BASIC: 770 PRINT */
line_770:;
    printf("\n");
    /* BASIC: 780 PRINT"\TOR\ COMMAND = PHOTON TORPEDO CONTROL" */
line_780:;
    printf("%s", "\\TOR\\ COMMAND = PHOTON TORPEDO CONTROL"); printf("\n");
    /* BASIC: 790 PRINT"     TORPEDO COURSE IS THE SAME AS USED IN WARP ENGINE CONTROL" */
line_790:;
    printf("%s", "     TORPEDO COURSE IS THE SAME AS USED IN WARP ENGINE CONTROL"); printf("\n");
    /* BASIC: 800 PRINT"     IF YOU HIT THE KLINGON VESSEL, HE IS DESTROYED AND" */
line_800:;
    printf("%s", "     IF YOU HIT THE KLINGON VESSEL, HE IS DESTROYED AND"); printf("\n");
    /* BASIC: 810 PRINT"     CANNOT FIRE BACK AT YOU.  IF YOU MISS, YOU ARE SUBJECT TO" */
line_810:;
    printf("%s", "     CANNOT FIRE BACK AT YOU.  IF YOU MISS, YOU ARE SUBJECT TO"); printf("\n");
    /* BASIC: 820 PRINT"     HIS PHASER FIRE.  IN EITHER CASE, YOU ARE ALSO SUBJECT TO " */
line_820:;
    printf("%s", "     HIS PHASER FIRE.  IN EITHER CASE, YOU ARE ALSO SUBJECT TO "); printf("\n");
    /* BASIC: 825 PRINT"     THE PHASER FIRE OF ALL OTHER KLINGONS IN THE QUADRANT." */
line_825:;
    printf("%s", "     THE PHASER FIRE OF ALL OTHER KLINGONS IN THE QUADRANT."); printf("\n");
    /* BASIC: 830 PRINT */
line_830:;
    printf("\n");
    /* BASIC: 835 PRINT"     THE LIBRARY-COMPUTER (\COM\ COMMAND) HAS AN OPTION TO " */
line_835:;
    printf("%s", "     THE LIBRARY-COMPUTER (\\COM\\ COMMAND) HAS AN OPTION TO "); printf("\n");
    /* BASIC: 840 PRINT"     COMPUTE TORPEDO TRAJECTORY FOR YOU (OPTION 2)" */
line_840:;
    printf("%s", "     COMPUTE TORPEDO TRAJECTORY FOR YOU (OPTION 2)"); printf("\n");
    /* BASIC: 850 PRINT */
line_850:;
    printf("\n");
    /* BASIC: 860 PRINT"\SHE\ COMMAND = SHIELD CONTROL" */
line_860:;
    printf("%s", "\\SHE\\ COMMAND = SHIELD CONTROL"); printf("\n");
    /* BASIC: 870 PRINT"     DEFINES THE NUMBER OF ENERGY UNITS TO BE ASSIGNED TO THE" */
line_870:;
    printf("%s", "     DEFINES THE NUMBER OF ENERGY UNITS TO BE ASSIGNED TO THE"); printf("\n");
    /* BASIC: 880 PRINT"     SHIELDS.  ENERGY IS TAKEN FROM TOTAL SHIP'S ENERGY.  NOTE" */
line_880:;
    printf("%s", "     SHIELDS.  ENERGY IS TAKEN FROM TOTAL SHIP'S ENERGY.  NOTE"); printf("\n");
    /* BASIC: 890 PRINT"     THAN THE STATUS DISPLAY TOTAL ENERGY INCLUDES SHIELD ENERGY" */
line_890:;
    printf("%s", "     THAN THE STATUS DISPLAY TOTAL ENERGY INCLUDES SHIELD ENERGY"); printf("\n");
    /* BASIC: 900 PRINT */
line_900:;
    printf("\n");
    /* BASIC: 910 PRINT"\DAM\ COMMAND = DAMMAGE CONTROL REPORT" */
line_910:;
    printf("%s", "\\DAM\\ COMMAND = DAMMAGE CONTROL REPORT"); printf("\n");
    /* BASIC: 920 PRINT"     GIVES THE STATE OF REPAIR OF ALL DEVICES.  WHERE A NEGATIVE" */
line_920:;
    printf("%s", "     GIVES THE STATE OF REPAIR OF ALL DEVICES.  WHERE A NEGATIVE"); printf("\n");
    /* BASIC: 930 PRINT"     'STATE OF REPAIR' SHOWS THAT THE DEVICE IS TEMPORARILY" */
line_930:;
    printf("%s", "     'STATE OF REPAIR' SHOWS THAT THE DEVICE IS TEMPORARILY"); printf("\n");
    /* BASIC: 940 PRINT"     DAMAGED." */
line_940:;
    printf("%s", "     DAMAGED."); printf("\n");
    /* BASIC: 950 PRINT */
line_950:;
    printf("\n");
    /* BASIC: 960 PRINT"\COM\ COMMAND = LIBRARY-COMPUTER" */
line_960:;
    printf("%s", "\\COM\\ COMMAND = LIBRARY-COMPUTER"); printf("\n");
    /* BASIC: 970 PRINT"     THE LIBRARY-COMPUTER CONTAINS SIX OPTIONS:" */
line_970:;
    printf("%s", "     THE LIBRARY-COMPUTER CONTAINS SIX OPTIONS:"); printf("\n");
    /* BASIC: 980 PRINT"     OPTION 0 = CUMULATIVE GALACTIC RECORD" */
line_980:;
    printf("%s", "     OPTION 0 = CUMULATIVE GALACTIC RECORD"); printf("\n");
    /* BASIC: 990 PRINT"        THIS OPTION SHOWES COMPUTER MEMORY OF THE RESULTS OF ALL" */
line_990:;
    printf("%s", "        THIS OPTION SHOWES COMPUTER MEMORY OF THE RESULTS OF ALL"); printf("\n");
    /* BASIC: 1000 PRINT"        PREVIOUS SHORT AND LONG RANGE SENSOR SCANS" */
line_1000:;
    printf("%s", "        PREVIOUS SHORT AND LONG RANGE SENSOR SCANS"); printf("\n");
    /* BASIC: 1010 PRINT"     OPTION 1 = STATUS REPORT" */
line_1010:;
    printf("%s", "     OPTION 1 = STATUS REPORT"); printf("\n");
    /* BASIC: 1020 PRINT"        THIS OPTION SHOWS THE NUMBER OF KLINGONS, STARDATES," */
line_1020:;
    printf("%s", "        THIS OPTION SHOWS THE NUMBER OF KLINGONS, STARDATES,"); printf("\n");
    /* BASIC: 1030 PRINT"        AND STARBASES REMAINING IN THE GAME." */
line_1030:;
    printf("%s", "        AND STARBASES REMAINING IN THE GAME."); printf("\n");
    /* BASIC: 1040 PRINT"     OPTION 2 = PHOTON TORPEDO DATA" */
line_1040:;
    printf("%s", "     OPTION 2 = PHOTON TORPEDO DATA"); printf("\n");
    /* BASIC: 1050 PRINT"        WHICH GIVES DIRECTIONS AND DISTANCE FROM THE ENTERPRISE" */
line_1050:;
    printf("%s", "        WHICH GIVES DIRECTIONS AND DISTANCE FROM THE ENTERPRISE"); printf("\n");
    /* BASIC: 1060 PRINT"        TO ALL KLINGONS IN YOUR QUADRANT" */
line_1060:;
    printf("%s", "        TO ALL KLINGONS IN YOUR QUADRANT"); printf("\n");
    /* BASIC: 1070 PRINT"     OPTION 3 = STARBASE NAV DATA" */
line_1070:;
    printf("%s", "     OPTION 3 = STARBASE NAV DATA"); printf("\n");
    /* BASIC: 1080 PRINT"        THIS OPTION GIVES DIRECTION AND DISTANCE TO ANY " */
line_1080:;
    printf("%s", "        THIS OPTION GIVES DIRECTION AND DISTANCE TO ANY "); printf("\n");
    /* BASIC: 1090 PRINT"        STARBASE WITHIN YOUR QUADRANT" */
line_1090:;
    printf("%s", "        STARBASE WITHIN YOUR QUADRANT"); printf("\n");
    /* BASIC: 1100 PRINT"     OPTION 4 = DIRECTION/DISTANCE CALCULATOR" */
line_1100:;
    printf("%s", "     OPTION 4 = DIRECTION/DISTANCE CALCULATOR"); printf("\n");
    /* BASIC: 1110 PRINT"        THIS OPTION ALLOWS YOU TO ENTER COORDINATES FOR" */
line_1110:;
    printf("%s", "        THIS OPTION ALLOWS YOU TO ENTER COORDINATES FOR"); printf("\n");
    /* BASIC: 1120 PRINT"        DIRECTION/DISTANCE CALCULATIONS" */
line_1120:;
    printf("%s", "        DIRECTION/DISTANCE CALCULATIONS"); printf("\n");
    /* BASIC: 1130 PRINT"     OPTION 5 = GALACTIC /REGION NAME/ MAP" */
line_1130:;
    printf("%s", "     OPTION 5 = GALACTIC /REGION NAME/ MAP"); printf("\n");
    /* BASIC: 1140 PRINT"        THIS OPTION PRINTS THE NAMES OF THE SIXTEEN MAJOR " */
line_1140:;
    printf("%s", "        THIS OPTION PRINTS THE NAMES OF THE SIXTEEN MAJOR "); printf("\n");
    /* BASIC: 1150 PRINT"        GALACTIC REGIONS REFERRED TO IN THE GAME." */
line_1150:;
    printf("%s", "        GALACTIC REGIONS REFERRED TO IN THE GAME."); printf("\n");
    /* BASIC: 1990 REM POKE 1229,0:POKE 1237,1:NULL 0 */
line_1990:;
    /* REM POKE 1229,0 */
    /* UNTRANSLATED: POKE 1237,1 */
    /* UNTRANSLATED: NULL 0 */
    /* BASIC: 2000 REM PRINT:PRINT:PRINT */
line_2000:;
    /* REM PRINT */
    printf("\n");
    printf("\n");
    /* BASIC: 2010 REM PRINT "TURN CASSETTE PLAYER ON AND HIT ANY KEY EXCEPT RETURN" */
line_2010:;
    /* REM PRINT "TURN CASSETTE PLAYER ON AND HIT ANY KEY EXCEPT RETURN" */
    /* BASIC: 2020 REM IF INP(1)=13 THEN 2020 */
line_2020:;
    /* REM IF INP(1)=13 THEN 2020 */
    /* BASIC: 2030 REM PRINT */
line_2030:;
    /* REM PRINT */
    /* BASIC: 2040 REM PRINT "TURN CASSETTE PLAYER OFF AND " */
line_2040:;
    /* REM PRINT "TURN CASSETTE PLAYER OFF AND " */
    /* BASIC: 2050 REM PRINT "TYPE 'RUN' WHEN COMPUTER PRINTS 'OK'" */
line_2050:;
    /* REM PRINT "TYPE 'RUN' WHEN COMPUTER PRINTS 'OK'" */

    return 0;
}
