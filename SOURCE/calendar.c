/*
 * Transpiled from calendar.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double MAY, DECEMBER, READ, MORRISTOWN, CHR, W, DATA, NEW, MARCH, AUGUST, S, OCTOBER, COMPUTING, CREATIVE, JERSEY, APRIL, SEPTEMBER, ON, D2, JANUARY, NOVEMBER, D, CALENDAR, JULY, F, FEBRUARY, T, G, N, I, JUNE;
    double M[1000] = {0}; /* Static array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 10 PRINT TAB(32);"CALENDAR" */
line_10:
    { int _t; for(_t=0; _t<32; _t++) printf(" "); } printf("%s", "CALENDAR"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 100 REM     VALUES FOR 1979 - SEE NOTES */
line_100:
    // REM     VALUES FOR 1979 - SEE NOTES
    /* BASIC: 110 DIM M(12) */
line_110:
    /* DIM M(12) (handled statically) */
    /* BASIC: 120 FOR I=1 TO 6: PRINT CHR$(10);: NEXT I */
line_120:
    I = 1; for_loop_I: if ((1 >= 0 && I > 6) || (1 < 0 && I < 6)) goto end_for_I;
    printf("%g ", (double)(CHR$(10)));
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 130 D=1: REM 1979 STARTS ON MONDAY (0=SUN, -1=MON, -2=TUES...) */
line_130:
    D = 1;
    // REM 1979 STARTS ON MONDAY (0=SUN, -1=MON, -2=TUES...)
    /* BASIC: 140 S=0 */
line_140:
    S = 0;
    /* BASIC: 150 REM     READ DAYS OF EACH MONTH */
line_150:
    // REM     READ DAYS OF EACH MONTH
    /* BASIC: 160 FOR N=0 TO 12: READ M(N): NEXT N */
line_160:
    N = 0; for_loop_N: if ((1 >= 0 && N > 12) || (1 < 0 && N < 12)) goto end_for_N;
    /* UNTRANSLATED: READ M(N) */
    N += 1; goto for_loop_N; end_for_N:;
    /* BASIC: 170 REM */
line_170:
    // REM
    /* BASIC: 180 FOR N=1 TO 12 */
line_180:
    N = 1; for_loop_N: if ((1 >= 0 && N > 12) || (1 < 0 && N < 12)) goto end_for_N;
    /* BASIC: 190 PRINT: PRINT: S=S+M(N-1) */
line_190:
    printf("\n");
    printf("\n");
    S = S+M(N-1);
    /* BASIC: 200 PRINT "**";S;TAB(7); */
line_200:
    printf("%s", "**"); printf("%g ", (double)(S)); { int _t; for(_t=0; _t<7; _t++) printf(" "); }
    /* BASIC: 210 FOR I=1 TO 18: PRINT "*";: NEXT I */
line_210:
    I = 1; for_loop_I: if ((1 >= 0 && I > 18) || (1 < 0 && I < 18)) goto end_for_I;
    printf("%s", "*");
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 220 ON N GOTO 230,240,250,260,270,280,290,300,310,320,330,340 */
line_220:
    /* UNTRANSLATED: ON N GOTO 230,240,250,260,270,280,290,300,310,320,330,340 */
    /* BASIC: 230 PRINT " JANUARY ";: GOTO 350 */
line_230:
    printf("%s", " JANUARY ");
    goto line_350;
    /* BASIC: 240 PRINT " FEBRUARY";: GOTO 350 */
line_240:
    printf("%s", " FEBRUARY");
    goto line_350;
    /* BASIC: 250 PRINT "  MARCH  ";: GOTO 350 */
line_250:
    printf("%s", "  MARCH  ");
    goto line_350;
    /* BASIC: 260 PRINT "  APRIL  ";: GOTO 350 */
line_260:
    printf("%s", "  APRIL  ");
    goto line_350;
    /* BASIC: 270 PRINT "   MAY   ";: GOTO 350 */
line_270:
    printf("%s", "   MAY   ");
    goto line_350;
    /* BASIC: 280 PRINT "   JUNE  ";: GOTO 350 */
line_280:
    printf("%s", "   JUNE  ");
    goto line_350;
    /* BASIC: 290 PRINT "   JULY  ";: GOTO 350 */
line_290:
    printf("%s", "   JULY  ");
    goto line_350;
    /* BASIC: 300 PRINT "  AUGUST ";: GOTO 350 */
line_300:
    printf("%s", "  AUGUST ");
    goto line_350;
    /* BASIC: 310 PRINT "SEPTEMBER";: GOTO 350 */
line_310:
    printf("%s", "SEPTEMBER");
    goto line_350;
    /* BASIC: 320 PRINT " OCTOBER ";: GOTO 350 */
line_320:
    printf("%s", " OCTOBER ");
    goto line_350;
    /* BASIC: 330 PRINT " NOVEMBER";: GOTO 350 */
line_330:
    printf("%s", " NOVEMBER");
    goto line_350;
    /* BASIC: 340 PRINT " DECEMBER"; */
line_340:
    printf("%s", " DECEMBER");
    /* BASIC: 350 FOR I=1 TO 18: PRINT "*";: NEXT I */
line_350:
    I = 1; for_loop_I: if ((1 >= 0 && I > 18) || (1 < 0 && I < 18)) goto end_for_I;
    printf("%s", "*");
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 360 PRINT 365-S;"**"; */
line_360:
    printf("%g ", (double)(365-S)); printf("%s", "**");
    /* BASIC: 370 REM   366-S;     ON LEAP YEARS */
line_370:
    // REM   366-S;     ON LEAP YEARS
    /* BASIC: 380 PRINT CHR$(10): PRINT "     S       M       T       W"; */
line_380:
    printf("%g ", (double)(CHR$(10))); printf("\n");
    printf("%s", "     S       M       T       W");
    /* BASIC: 390 PRINT "       T       F       S" */
line_390:
    printf("%s", "       T       F       S"); printf("\n");
    /* BASIC: 400 PRINT */
line_400:
    printf("\n");
    /* BASIC: 410 FOR I=1 TO 59: PRINT "*";: NEXT I */
line_410:
    I = 1; for_loop_I: if ((1 >= 0 && I > 59) || (1 < 0 && I < 59)) goto end_for_I;
    printf("%s", "*");
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 420 REM */
line_420:
    // REM
    /* BASIC: 430 FOR W=1 TO 6 */
line_430:
    W = 1; for_loop_W: if ((1 >= 0 && W > 6) || (1 < 0 && W < 6)) goto end_for_W;
    /* BASIC: 440 PRINT CHR$(10) */
line_440:
    printf("%g ", (double)(CHR$(10))); printf("\n");
    /* BASIC: 450 PRINT TAB(4) */
line_450:
    { int _t; for(_t=0; _t<4; _t++) printf(" "); } printf("\n");
    /* BASIC: 460 REM */
line_460:
    // REM
    /* BASIC: 470 FOR G=1 TO 7 */
line_470:
    G = 1; for_loop_G: if ((1 >= 0 && G > 7) || (1 < 0 && G < 7)) goto end_for_G;
    /* BASIC: 480 D=D+1 */
line_480:
    D = D+1;
    /* BASIC: 490 D2=D-S */
line_490:
    D2 = D-S;
    /* BASIC: 500 IF D2>M(N) THEN 580 */
line_500:
    if (D2>M(N)) goto line_580;
    /* BASIC: 510 IF D2>0 THEN PRINT D2; */
line_510:
    if (D2>0) { printf("%g ", (double)(D2)); }
    /* BASIC: 520 PRINT TAB(4+8*G); */
line_520:
    { int _t; for(_t=0; _t<4+8*G; _t++) printf(" "); }
    /* BASIC: 530 NEXT G */
line_530:
    G += 1; goto for_loop_G; end_for_G:;
    /* BASIC: 540 REM */
line_540:
    // REM
    /* BASIC: 550 IF D2=M(N) THEN 590 */
line_550:
    if (D2==M(N)) goto line_590;
    /* BASIC: 560 NEXT W */
line_560:
    W += 1; goto for_loop_W; end_for_W:;
    /* BASIC: 570 REM */
line_570:
    // REM
    /* BASIC: 580 D=D-G */
line_580:
    D = D-G;
    /* BASIC: 590 NEXT N */
line_590:
    N += 1; goto for_loop_N; end_for_N:;
    /* BASIC: 600 REM */
line_600:
    // REM
    /* BASIC: 610 FOR I=1 TO 6: PRINT CHR$(10);: NEXT I */
line_610:
    I = 1; for_loop_I: if ((1 >= 0 && I > 6) || (1 < 0 && I < 6)) goto end_for_I;
    printf("%g ", (double)(CHR$(10)));
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 620 DATA 0,31,28,31,30,31,30,31,31,30,31,30,31 */
line_620:
    /* UNTRANSLATED: DATA 0,31,28,31,30,31,30,31,31,30,31,30,31 */
    /* BASIC: 630 REM  0,31,29,  ..., ON LEAP YEARS */
line_630:
    // REM  0,31,29,  ..., ON LEAP YEARS
    /* BASIC: 640 END */
line_640:
    exit(0);

    return 0;
}
