/*
 * Transpiled from hello.bas
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
static double I;
static char B_str[256] = {0};
static char C_str[256] = {0};
static char D_str[256] = {0};
static char E_str[256] = {0};
static char G_str[256] = {0};
static char N_str[256] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 2 PRINT TAB(33);"HELLO" */
line_2:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "HELLO"); printf("\n");
    /* BASIC: 4 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 6 PRINT: PRINT: PRINT */
line_6:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 10 PRINT "HELLO.  MY NAME IS CREATIVE COMPUTER." */
line_10:;
    printf("%s", "HELLO.  MY NAME IS CREATIVE COMPUTER."); printf("\n");
    /* BASIC: 20 PRINT: PRINT: INPUT "WHAT'S YOUR NAME";N$: PRINT */
line_20:;
    printf("\n");
    printf("\n");
    printf("%s", "WHAT'S YOUR NAME"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", N_str);
    printf("\n");
    /* BASIC: 30 PRINT "HI THERE, ";N$;", ARE YOU ENJOYING YOURSELF HERE"; */
line_30:;
    printf("%s", "HI THERE, "); printf("%s", N_str); printf("%s", ", ARE YOU ENJOYING YOURSELF HERE");
    /* BASIC: 40 INPUT B$: PRINT */
line_40:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", B_str);
    printf("\n");
    /* BASIC: 50 IF B$="YES" THEN 70 */
line_50:;
    if (strcmp(B_str, "YES") == 0) { goto line_70; }
    /* BASIC: 55 IF B$="NO" THEN 80 */
line_55:;
    if (strcmp(B_str, "NO") == 0) { goto line_80; }
    /* BASIC: 60 PRINT N$;", I DON'T UNDERSTAND YOUR ANSWER OF '";B$;"'." */
line_60:;
    printf("%s", N_str); printf("%s", ", I DON'T UNDERSTAND YOUR ANSWER OF '"); printf("%s", B_str); printf("%s", "'."); printf("\n");
    /* BASIC: 65 PRINT "PLEASE ANSWER 'YES' OR 'NO'.  DO YOU LIKE IT HERE";: GOTO 40 */
line_65:;
    printf("%s", "PLEASE ANSWER 'YES' OR 'NO'.  DO YOU LIKE IT HERE");
    goto line_40;
    /* BASIC: 70 PRINT "I'M GLAD TO HEAR THAT, ";N$;".": PRINT */
line_70:;
    printf("%s", "I'M GLAD TO HEAR THAT, "); printf("%s", N_str); printf("%s", "."); printf("\n");
    printf("\n");
    /* BASIC: 75 GOTO 100 */
line_75:;
    goto line_100;
    /* BASIC: 80 PRINT "OH, I'M SORRY TO HEAR THAT, ";N$;". MAYBE WE CAN" */
line_80:;
    printf("%s", "OH, I'M SORRY TO HEAR THAT, "); printf("%s", N_str); printf("%s", ". MAYBE WE CAN"); printf("\n");
    /* BASIC: 85 PRINT "BRIGHTEN UP YOUR VISIT A BIT." */
line_85:;
    printf("%s", "BRIGHTEN UP YOUR VISIT A BIT."); printf("\n");
    /* BASIC: 100 PRINT */
line_100:;
    printf("\n");
    /* BASIC: 105 PRINT "SAY, ";N$;", I CAN SOLVE ALL KINDS OF PROBLEMS EXCEPT" */
line_105:;
    printf("%s", "SAY, "); printf("%s", N_str); printf("%s", ", I CAN SOLVE ALL KINDS OF PROBLEMS EXCEPT"); printf("\n");
    /* BASIC: 110 PRINT "THOSE DEALING WITH GREECE.  WHAT KIND OF PROBLEMS DO" */
line_110:;
    printf("%s", "THOSE DEALING WITH GREECE.  WHAT KIND OF PROBLEMS DO"); printf("\n");
    /* BASIC: 120 PRINT "YOU HAVE (ANSWER SEX, HEALTH, MONEY, OR JOB)"; */
line_120:;
    printf("%s", "YOU HAVE (ANSWER SEX, HEALTH, MONEY, OR JOB)");
    /* BASIC: 125 INPUT C$ */
line_125:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", C_str);
    /* BASIC: 126 PRINT */
line_126:;
    printf("\n");
    /* BASIC: 130 IF C$="SEX" THEN 200 */
line_130:;
    if (strcmp(C_str, "SEX") == 0) { goto line_200; }
    /* BASIC: 132 IF C$="HEALTH" THEN 180 */
line_132:;
    if (strcmp(C_str, "HEALTH") == 0) { goto line_180; }
    /* BASIC: 134 IF C$="MONEY" THEN 160 */
line_134:;
    if (strcmp(C_str, "MONEY") == 0) { goto line_160; }
    /* BASIC: 136 IF C$="JOB" THEN 145 */
line_136:;
    if (strcmp(C_str, "JOB") == 0) { goto line_145; }
    /* BASIC: 138 PRINT "OH, ";N$;", YOUR ANSWER OF ";C$;" IS GREEK TO ME." */
line_138:;
    printf("%s", "OH, "); printf("%s", N_str); printf("%s", ", YOUR ANSWER OF "); printf("%s", C_str); printf("%s", " IS GREEK TO ME."); printf("\n");
    /* BASIC: 140 GOTO 250 */
line_140:;
    goto line_250;
    /* BASIC: 145 PRINT "I CAN SYMPATHIZE WITH YOU ";N$;".  I HAVE TO WORK" */
line_145:;
    printf("%s", "I CAN SYMPATHIZE WITH YOU "); printf("%s", N_str); printf("%s", ".  I HAVE TO WORK"); printf("\n");
    /* BASIC: 148 PRINT "VERY LONG HOURS FOR NO PAY -- AND SOME OF MY BOSSES" */
line_148:;
    printf("%s", "VERY LONG HOURS FOR NO PAY -- AND SOME OF MY BOSSES"); printf("\n");
    /* BASIC: 150 PRINT "REALLY BEAT ON MY KEYBOARD.  MY ADVICE TO YOU, ";N$;"," */
line_150:;
    printf("%s", "REALLY BEAT ON MY KEYBOARD.  MY ADVICE TO YOU, "); printf("%s", N_str); printf("%s", ","); printf("\n");
    /* BASIC: 153 PRINT "IS TO OPEN A RETAIL COMPUTER STORE.  IT'S GREAT FUN." */
line_153:;
    printf("%s", "IS TO OPEN A RETAIL COMPUTER STORE.  IT'S GREAT FUN."); printf("\n");
    /* BASIC: 155 GOTO 250 */
line_155:;
    goto line_250;
    /* BASIC: 160 PRINT "SORRY, ";N$;", I'M BROKE TOO.  WHY DON'T YOU SELL" */
line_160:;
    printf("%s", "SORRY, "); printf("%s", N_str); printf("%s", ", I'M BROKE TOO.  WHY DON'T YOU SELL"); printf("\n");
    /* BASIC: 162 PRINT "ENCYCLOPEADIAS OR MARRY SOMEONE RICH OR STOP EATING" */
line_162:;
    printf("%s", "ENCYCLOPEADIAS OR MARRY SOMEONE RICH OR STOP EATING"); printf("\n");
    /* BASIC: 164 PRINT "SO YOU WON'T NEED SO MUCH MONEY?" */
line_164:;
    printf("%s", "SO YOU WON'T NEED SO MUCH MONEY?"); printf("\n");
    /* BASIC: 170 GOTO 250 */
line_170:;
    goto line_250;
    /* BASIC: 180 PRINT "MY ADVICE TO YOU ";N$;" IS:" */
line_180:;
    printf("%s", "MY ADVICE TO YOU "); printf("%s", N_str); printf("%s", " IS:"); printf("\n");
    /* BASIC: 185 PRINT "     1.  TAKE TWO ASPRIN" */
line_185:;
    printf("%s", "     1.  TAKE TWO ASPRIN"); printf("\n");
    /* BASIC: 188 PRINT "     2.  DRINK PLENTY OF FLUIDS (ORANGE JUICE, NOT BEER!)" */
line_188:;
    printf("%s", "     2.  DRINK PLENTY OF FLUIDS (ORANGE JUICE, NOT BEER!)"); printf("\n");
    /* BASIC: 190 PRINT "     3.  GO TO BED (ALONE)" */
line_190:;
    printf("%s", "     3.  GO TO BED (ALONE)"); printf("\n");
    /* BASIC: 195 GOTO 250 */
line_195:;
    goto line_250;
    /* BASIC: 200 INPUT "IS YOUR PROBLEM TOO MUCH OR TOO LITTLE";D$: PRINT */
line_200:;
    printf("%s", "IS YOUR PROBLEM TOO MUCH OR TOO LITTLE"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", D_str);
    printf("\n");
    /* BASIC: 210 IF D$="TOO MUCH" THEN 220 */
line_210:;
    if (strcmp(D_str, "TOO MUCH") == 0) { goto line_220; }
    /* BASIC: 212 IF D$="TOO LITTLE" THEN 230 */
line_212:;
    if (strcmp(D_str, "TOO LITTLE") == 0) { goto line_230; }
    /* BASIC: 215 PRINT "DON'T GET ALL SHOOK, ";N$;", JUST ANSWER THE QUESTION" */
line_215:;
    printf("%s", "DON'T GET ALL SHOOK, "); printf("%s", N_str); printf("%s", ", JUST ANSWER THE QUESTION"); printf("\n");
    /* BASIC: 217 INPUT "WITH 'TOO MUCH' OR 'TOO LITTLE'.  WHICH IS IT";D$:GOTO 210 */
line_217:;
    printf("%s", "WITH 'TOO MUCH' OR 'TOO LITTLE'.  WHICH IS IT"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", D_str);
    goto line_210;
    /* BASIC: 220 PRINT "YOU CALL THAT A PROBLEM?!!  I SHOULD HAVE SUCH PROBLEMS!" */
line_220:;
    printf("%s", "YOU CALL THAT A PROBLEM?!!  I SHOULD HAVE SUCH PROBLEMS!"); printf("\n");
    /* BASIC: 225 PRINT "IF IT BOTHERS YOU, ";N$;", TAKE A COLD SHOWER." */
line_225:;
    printf("%s", "IF IT BOTHERS YOU, "); printf("%s", N_str); printf("%s", ", TAKE A COLD SHOWER."); printf("\n");
    /* BASIC: 228 GOTO 250 */
line_228:;
    goto line_250;
    /* BASIC: 230 PRINT "WHY ARE YOU HERE IN SUFFERN, ";N$;"?  YOU SHOULD BE" */
line_230:;
    printf("%s", "WHY ARE YOU HERE IN SUFFERN, "); printf("%s", N_str); printf("%s", "?  YOU SHOULD BE"); printf("\n");
    /* BASIC: 235 PRINT "IN TOKYO OR NEW YORK OR AMSTERDAM OR SOMEPLACE WITH SOME" */
line_235:;
    printf("%s", "IN TOKYO OR NEW YORK OR AMSTERDAM OR SOMEPLACE WITH SOME"); printf("\n");
    /* BASIC: 240 PRINT "REAL ACTION." */
line_240:;
    printf("%s", "REAL ACTION."); printf("\n");
    /* BASIC: 250 PRINT */
line_250:;
    printf("\n");
    /* BASIC: 255 PRINT "ANY MORE PROBLEMS YOU WANT SOLVED, ";N$; */
line_255:;
    printf("%s", "ANY MORE PROBLEMS YOU WANT SOLVED, "); printf("%s", N_str);
    /* BASIC: 260 INPUT E$: PRINT */
line_260:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", E_str);
    printf("\n");
    /* BASIC: 270 IF E$="YES" THEN 280 */
line_270:;
    if (strcmp(E_str, "YES") == 0) { goto line_280; }
    /* BASIC: 273 IF E$="NO" THEN 300 */
line_273:;
    if (strcmp(E_str, "NO") == 0) { goto line_300; }
    /* BASIC: 275 PRINT "JUST A SIMPLE 'YES' OR 'NO' PLEASE, ";N$;"." */
line_275:;
    printf("%s", "JUST A SIMPLE 'YES' OR 'NO' PLEASE, "); printf("%s", N_str); printf("%s", "."); printf("\n");
    /* BASIC: 277 GOTO 255 */
line_277:;
    goto line_255;
    /* BASIC: 280 PRINT "WHAT KIND (SEX, MONEY, HEALTH, JOB)"; */
line_280:;
    printf("%s", "WHAT KIND (SEX, MONEY, HEALTH, JOB)");
    /* BASIC: 282 GOTO 125 */
line_282:;
    goto line_125;
    /* BASIC: 300 PRINT */
line_300:;
    printf("\n");
    /* BASIC: 302 PRINT "THAT WILL BE $5.00 FOR THE ADVICE, ";N$;"." */
line_302:;
    printf("%s", "THAT WILL BE $5.00 FOR THE ADVICE, "); printf("%s", N_str); printf("%s", "."); printf("\n");
    /* BASIC: 305 PRINT "PLEASE LEAVE THE MONEY ON THE TERMINAL." */
line_305:;
    printf("%s", "PLEASE LEAVE THE MONEY ON THE TERMINAL."); printf("\n");
    /* BASIC: 307 FOR I=1 TO 2000: NEXT I */
line_307:;
    I = 1; for_loop_I_307: if (((1) >= 0 && I > (2000)) || ((1) < 0 && I < (2000))) goto end_for_I_307;
    I += (1); goto for_loop_I_307; end_for_I_307:;
    /* BASIC: 310 PRINT: PRINT: PRINT */
line_310:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 315 PRINT "DID YOU LEAVE THE MONEY"; */
line_315:;
    printf("%s", "DID YOU LEAVE THE MONEY");
    /* BASIC: 320 INPUT G$: PRINT */
line_320:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", G_str);
    printf("\n");
    /* BASIC: 325 IF G$="YES" THEN 350 */
line_325:;
    if (strcmp(G_str, "YES") == 0) { goto line_350; }
    /* BASIC: 330 IF G$="NO" THEN 370 */
line_330:;
    if (strcmp(G_str, "NO") == 0) { goto line_370; }
    /* BASIC: 335 PRINT "YOUR ANSWER OF '";G$;"' CONFUSES ME, ";N$;"." */
line_335:;
    printf("%s", "YOUR ANSWER OF '"); printf("%s", G_str); printf("%s", "' CONFUSES ME, "); printf("%s", N_str); printf("%s", "."); printf("\n");
    /* BASIC: 340 PRINT "PLEASE RESPOND WITH 'YES' OR 'NO'.": GOTO 315 */
line_340:;
    printf("%s", "PLEASE RESPOND WITH 'YES' OR 'NO'."); printf("\n");
    goto line_315;
    /* BASIC: 350 PRINT "HEY, ";N$;"??? YOU LEFT NO MONEY AT ALL!" */
line_350:;
    printf("%s", "HEY, "); printf("%s", N_str); printf("%s", "??? YOU LEFT NO MONEY AT ALL!"); printf("\n");
    /* BASIC: 355 PRINT "YOU ARE CHEATING ME OUT OF MY HARD-EARNED LIVING." */
line_355:;
    printf("%s", "YOU ARE CHEATING ME OUT OF MY HARD-EARNED LIVING."); printf("\n");
    /* BASIC: 360 PRINT:PRINT "WHAT A RIP OFF, ";N$;"!!!":PRINT */
line_360:;
    printf("\n");
    printf("%s", "WHAT A RIP OFF, "); printf("%s", N_str); printf("%s", "!!!"); printf("\n");
    printf("\n");
    /* BASIC: 365 GOTO 385 */
line_365:;
    goto line_385;
    /* BASIC: 370 PRINT "THAT'S HONEST, ";N$;", BUT HOW DO YOU EXPECT" */
line_370:;
    printf("%s", "THAT'S HONEST, "); printf("%s", N_str); printf("%s", ", BUT HOW DO YOU EXPECT"); printf("\n");
    /* BASIC: 375 PRINT "ME TO GO ON WITH MY PSYCHOLOGY STUDIES IF MY PATIENTS" */
line_375:;
    printf("%s", "ME TO GO ON WITH MY PSYCHOLOGY STUDIES IF MY PATIENTS"); printf("\n");
    /* BASIC: 380 PRINT "DON'T PAY THEIR BILLS?" */
line_380:;
    printf("%s", "DON'T PAY THEIR BILLS?"); printf("\n");
    /* BASIC: 385 PRINT:PRINT "TAKE A WALK, ";N$;".":PRINT:PRINT:GOTO 999 */
line_385:;
    printf("\n");
    printf("%s", "TAKE A WALK, "); printf("%s", N_str); printf("%s", "."); printf("\n");
    printf("\n");
    printf("\n");
    goto line_999;
    /* BASIC: 390 PRINT "NICE MEETING YOU, ";N$;", HAVE A NICE DAY." */
line_390:;
    printf("%s", "NICE MEETING YOU, "); printf("%s", N_str); printf("%s", ", HAVE A NICE DAY."); printf("\n");
    /* BASIC: 400 REM */
line_400:;
    // REM
    /* BASIC: 999 END */
line_999:;
    exit(0);

    return 0;
}
