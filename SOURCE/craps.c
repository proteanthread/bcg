/*
 * Transpiled from craps.bas
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
static double E, F, H, LET, M, O, Q, R, S, T, X, Z;
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 5 PRINT TAB(33);"CRAPS" */
line_5:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "CRAPS"); printf("\n");
    /* BASIC: 10 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_10:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 12 PRINT:PRINT:PRINT */
line_12:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 15 LET R=0 */
line_15:;
    /* UNTRANSLATED: LET R=0 */
    /* BASIC: 20 PRINT"2,3,12 ARE LOSERS; 4,5,6,8,9,10 ARE POINTS; 7,11 ARE NATURAL WINNERS." */
line_20:;
    printf("%s", "2,3,12 ARE LOSERS; 4,5,6,8,9,10 ARE POINTS; 7,11 ARE NATURAL WINNERS."); printf("\n");
    /* BASIC: 21 LET T=1 */
line_21:;
    /* UNTRANSLATED: LET T=1 */
    /* BASIC: 22 PRINT "PICK A NUMBER AND INPUT TO ROLL DICE"; */
line_22:;
    printf("%s", "PICK A NUMBER AND INPUT TO ROLL DICE");
    /* BASIC: 23 INPUT Z */
line_23:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &Z);
    /* BASIC: 24 LET X=(RND(0)) */
line_24:;
    /* UNTRANSLATED: LET X=(RND(0)) */
    /* BASIC: 25 LET T =T+1 */
line_25:;
    /* UNTRANSLATED: LET T =T+1 */
    /* BASIC: 26 IF T<=Z THEN 24 */
line_26:;
    if (T<=Z) { goto line_24; }
    /* BASIC: 27 PRINT"INPUT THE AMOUNT OF YOUR WAGER."; */
line_27:;
    printf("%s", "INPUT THE AMOUNT OF YOUR WAGER.");
    /* BASIC: 28 INPUT F */
line_28:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &F);
    /* BASIC: 30 PRINT "I WILL NOW THROW THE DICE" */
line_30:;
    printf("%s", "I WILL NOW THROW THE DICE"); printf("\n");
    /* BASIC: 40 LET E=INT(7*RND(1)) */
line_40:;
    /* UNTRANSLATED: LET E=INT(7*RND(1)) */
    /* BASIC: 41 LET S=INT(7*RND(1)) */
line_41:;
    /* UNTRANSLATED: LET S=INT(7*RND(1)) */
    /* BASIC: 42 LET X=E+S */
line_42:;
    /* UNTRANSLATED: LET X=E+S */
    /* BASIC: 50 IF X=7 THEN 180 */
line_50:;
    if (X==7) { goto line_180; }
    /* BASIC: 55 IF X=11 THEN 180 */
line_55:;
    if (X==11) { goto line_180; }
    /* BASIC: 60 IF X=1 THEN 40 */
line_60:;
    if (X==1) { goto line_40; }
    /* BASIC: 62 IF X=2 THEN 195 */
line_62:;
    if (X==2) { goto line_195; }
    /* BASIC: 65 IF X=0 THEN 40 */
line_65:;
    if (X==0) { goto line_40; }
    /* BASIC: 70 IF X=2 THEN 200 */
line_70:;
    if (X==2) { goto line_200; }
    /* BASIC: 80 IF X=3 THEN 200 */
line_80:;
    if (X==3) { goto line_200; }
    /* BASIC: 90 IF X=12 THEN 200 */
line_90:;
    if (X==12) { goto line_200; }
    /* BASIC: 125 IF X=5 THEN 220 */
line_125:;
    if (X==5) { goto line_220; }
    /* BASIC: 130 IF X =6 THEN 220 */
line_130:;
    if (X ==6) { goto line_220; }
    /* BASIC: 140 IF X=8 THEN 220 */
line_140:;
    if (X==8) { goto line_220; }
    /* BASIC: 150 IF X=9 THEN 220 */
line_150:;
    if (X==9) { goto line_220; }
    /* BASIC: 160 IF X =10 THEN 220 */
line_160:;
    if (X ==10) { goto line_220; }
    /* BASIC: 170 IF X=4 THEN 220 */
line_170:;
    if (X==4) { goto line_220; }
    /* BASIC: 180 PRINT X "- NATURAL....A WINNER!!!!" */
line_180:;
    printf("%g ", (double)(X)); printf("%s", "- NATURAL....A WINNER!!!!"); printf("\n");
    /* BASIC: 185 PRINT X"PAYS EVEN MONEY, YOU WIN"F"DOLLARS" */
line_185:;
    printf("%g ", (double)(X)); printf("%s", "PAYS EVEN MONEY, YOU WIN"); printf("%g ", (double)(F)); printf("%s", "DOLLARS"); printf("\n");
    /* BASIC: 190 GOTO 210 */
line_190:;
    goto line_210;
    /* BASIC: 195 PRINT X"- SNAKE EYES....YOU LOSE." */
line_195:;
    printf("%g ", (double)(X)); printf("%s", "- SNAKE EYES....YOU LOSE."); printf("\n");
    /* BASIC: 196 PRINT "YOU LOSE"F "DOLLARS." */
line_196:;
    printf("%s", "YOU LOSE"); printf("%g ", (double)(F)); printf("%s", "DOLLARS."); printf("\n");
    /* BASIC: 197 LET F=0-F */
line_197:;
    /* UNTRANSLATED: LET F=0-F */
    /* BASIC: 198 GOTO 210 */
line_198:;
    goto line_210;
    /* BASIC: 200 PRINT X " - CRAPS...YOU LOSE." */
line_200:;
    printf("%g ", (double)(X)); printf("%s", " - CRAPS...YOU LOSE."); printf("\n");
    /* BASIC: 205 PRINT "YOU LOSE"F"DOLLARS." */
line_205:;
    printf("%s", "YOU LOSE"); printf("%g ", (double)(F)); printf("%s", "DOLLARS."); printf("\n");
    /* BASIC: 206 LET F=0-F */
line_206:;
    /* UNTRANSLATED: LET F=0-F */
    /* BASIC: 210 LET R= R+F */
line_210:;
    /* UNTRANSLATED: LET R= R+F */
    /* BASIC: 211 GOTO 320 */
line_211:;
    goto line_320;
    /* BASIC: 220 PRINT X "IS THE POINT. I WILL ROLL AGAIN" */
line_220:;
    printf("%g ", (double)(X)); printf("%s", "IS THE POINT. I WILL ROLL AGAIN"); printf("\n");
    /* BASIC: 230 LET H=INT(7*RND(1)) */
line_230:;
    /* UNTRANSLATED: LET H=INT(7*RND(1)) */
    /* BASIC: 231 LET Q=INT(7*RND(1)) */
line_231:;
    /* UNTRANSLATED: LET Q=INT(7*RND(1)) */
    /* BASIC: 232 LET O=H+Q */
line_232:;
    /* UNTRANSLATED: LET O=H+Q */
    /* BASIC: 240 IF O=1 THEN 230 */
line_240:;
    if (O==1) { goto line_230; }
    /* BASIC: 250 IF O=7 THEN 290 */
line_250:;
    if (O==7) { goto line_290; }
    /* BASIC: 255 IF O=0 THEN 230 */
line_255:;
    if (O==0) { goto line_230; }
    /* BASIC: 260 IF O=X THEN 310 */
line_260:;
    if (O==X) { goto line_310; }
    /* BASIC: 270 PRINT O " - NO POINT. I WILL ROLL AGAIN" */
line_270:;
    printf("%g ", (double)(O)); printf("%s", " - NO POINT. I WILL ROLL AGAIN"); printf("\n");
    /* BASIC: 280 GOTO 230 */
line_280:;
    goto line_230;
    /* BASIC: 290 PRINT O "- CRAPS. YOU LOSE." */
line_290:;
    printf("%g ", (double)(O)); printf("%s", "- CRAPS. YOU LOSE."); printf("\n");
    /* BASIC: 291 PRINT "YOU LOSE $"F */
line_291:;
    printf("%s", "YOU LOSE $"); printf("%g ", (double)(F)); printf("\n");
    /* BASIC: 292 F=0-F */
line_292:;
    F = 0-F;
    /* BASIC: 293 GOTO 210 */
line_293:;
    goto line_210;
    /* BASIC: 300 GOTO 320 */
line_300:;
    goto line_320;
    /* BASIC: 310 PRINT X"- A WINNER.........CONGRATS!!!!!!!!" */
line_310:;
    printf("%g ", (double)(X)); printf("%s", "- A WINNER.........CONGRATS!!!!!!!!"); printf("\n");
    /* BASIC: 311 PRINT X "AT 2 TO 1 ODDS PAYS YOU...LET ME SEE..."2*F"DOLLARS" */
line_311:;
    printf("%g ", (double)(X)); printf("%s", "AT 2 TO 1 ODDS PAYS YOU...LET ME SEE..."); printf("%g ", (double)(2*F)); printf("%s", "DOLLARS"); printf("\n");
    /* BASIC: 312 LET F=2*F */
line_312:;
    /* UNTRANSLATED: LET F=2*F */
    /* BASIC: 313 GOTO 210 */
line_313:;
    goto line_210;
    /* BASIC: 320 PRINT " IF YOU WANT TO PLAY AGAIN PRINT 5 IF NOT PRINT 2"; */
line_320:;
    printf("%s", " IF YOU WANT TO PLAY AGAIN PRINT 5 IF NOT PRINT 2");
    /* BASIC: 330 INPUT M */
line_330:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &M);
    /* BASIC: 331 IF R<0 THEN 334 */
line_331:;
    if (R<0) { goto line_334; }
    /* BASIC: 332 IF R>0 THEN 336 */
line_332:;
    if (R>0) { goto line_336; }
    /* BASIC: 333 IF R=0 THEN 338 */
line_333:;
    if (R==0) { goto line_338; }
    /* BASIC: 334 PRINT "YOU ARE NOW UNDER $";-R */
line_334:;
    printf("%s", "YOU ARE NOW UNDER $"); printf("%g ", (double)(-R)); printf("\n");
    /* BASIC: 335 GOTO 340 */
line_335:;
    goto line_340;
    /* BASIC: 336 PRINT "YOU ARE NOW AHEAD $";R */
line_336:;
    printf("%s", "YOU ARE NOW AHEAD $"); printf("%g ", (double)(R)); printf("\n");
    /* BASIC: 337 GOTO 340 */
line_337:;
    goto line_340;
    /* BASIC: 338 PRINT "YOU ARE NOW EVEN AT 0" */
line_338:;
    printf("%s", "YOU ARE NOW EVEN AT 0"); printf("\n");
    /* BASIC: 340 IF M=5 THEN 27 */
line_340:;
    if (M==5) { goto line_27; }
    /* BASIC: 341 IF R<0 THEN 350 */
line_341:;
    if (R<0) { goto line_350; }
    /* BASIC: 342 IF R>0 THEN 353 */
line_342:;
    if (R>0) { goto line_353; }
    /* BASIC: 343 IF R=0 THEN 355 */
line_343:;
    if (R==0) { goto line_355; }
    /* BASIC: 350 PRINT"TOO BAD, YOU ARE IN THE HOLE. COME AGAIN." */
line_350:;
    printf("%s", "TOO BAD, YOU ARE IN THE HOLE. COME AGAIN."); printf("\n");
    /* BASIC: 351 GOTO 360 */
line_351:;
    goto line_360;
    /* BASIC: 353 PRINT"CONGRATULATIONS---YOU CAME OUT A WINNER. COME AGAIN!" */
line_353:;
    printf("%s", "CONGRATULATIONS---YOU CAME OUT A WINNER. COME AGAIN!"); printf("\n");
    /* BASIC: 354 GOTO 360 */
line_354:;
    goto line_360;
    /* BASIC: 355 PRINT"CONGRATULATIONS---YOU CAME OUT EVEN, NOT BAD FOR AN AMATEUR" */
line_355:;
    printf("%s", "CONGRATULATIONS---YOU CAME OUT EVEN, NOT BAD FOR AN AMATEUR"); printf("\n");
    /* BASIC: 360 END */
line_360:;
    exit(0);

    return 0;
}
