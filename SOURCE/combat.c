/*
 * Transpiled from combat.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double SHOT, AIR, MEN, GAME, NEW, TYPE, ATTACKS, TREATY, PARIS, FINISHED, SHUCKS, JERSEY, THE, CONQUERED, ON, LEFT, A, D, RIGHT, BUT, WON, IT, T, HAD, COUNTRIES, IN, FELL, XIII, OUT, PLAYING, MORRISTOWN, TAKE, ARMY, WAS, SHAMBLES, WIPED, OH, SOLDIERS, PLANES, WAR, BOATS, COUNTRY, RESPECTIVE, STOPPED, WHAT, PATROL, THREE, SERVES, COMBAT, UNGAURDED, YOUR, I, CRASHED, AM, FROM, Y, ME, BATTLESHIPS, IS, RESULTS, OUR, DESTROYED, OF, COMBINED, CREATIVE, HOUSE, MY, YOU, FORCES, X, LIVE, CONCLUDED, WITH, APART, ONE, WE, BOMBED, BOTH, DOGFIGHT, NAVY, G, FORCE, DISTRIBUTE, B, HOW, C, MOVE, INTO, TWO, APIECE, SUNK, LOST, PATROLS, COMPUTING, BASES, ATTACK, E, MISSION, STUPID, CAPITOL, MANY, AT, DOWN, F, DEAD, PEACE, FIRST, THAT, HAVE, THIS;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 1 PRINT TAB(33);"COMBAT" */
line_1:
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "COMBAT"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT: PRINT: PRINT */
line_3:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 4 PRINT "I AM AT WAR WITH YOU.": PRINT "WE HAVE 72000 SOLDIERS APIECE." */
line_4:
    printf("%s", "I AM AT WAR WITH YOU."); printf("\n");
    printf("%s", "WE HAVE 72000 SOLDIERS APIECE."); printf("\n");
    /* BASIC: 5 PRINT:PRINT "DISTRIBUTE YOUR FORCES." */
line_5:
    printf("\n");
    printf("%s", "DISTRIBUTE YOUR FORCES."); printf("\n");
    /* BASIC: 6 PRINT ,"ME","  YOU" */
line_6:
    printf("\t"); printf("%s", "ME"); printf("\t"); printf("%s", "  YOU"); printf("\n");
    /* BASIC: 7 PRINT "ARMY",30000, */
line_7:
    printf("%s", "ARMY"); printf("\t"); printf("%g ", (double)(30000)); printf("\t");
    /* BASIC: 8 INPUT A */
line_8:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &A);
    /* BASIC: 9 PRINT "NAVY",20000, */
line_9:
    printf("%s", "NAVY"); printf("\t"); printf("%g ", (double)(20000)); printf("\t");
    /* BASIC: 10 INPUT B */
line_10:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &B);
    /* BASIC: 11 PRINT "A. F.",22000, */
line_11:
    printf("%s", "A. F."); printf("\t"); printf("%g ", (double)(22000)); printf("\t");
    /* BASIC: 12 INPUT C */
line_12:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &C);
    /* BASIC: 13 IF A+B+C>72000 THEN 5 */
line_13:
    if (A+B+C>72000) goto line_5;
    /* BASIC: 14 D=30000 */
line_14:
    D = 30000;
    /* BASIC: 15 E=20000 */
line_15:
    E = 20000;
    /* BASIC: 16 F=22000 */
line_16:
    F = 22000;
    /* BASIC: 17 PRINT "YOU ATTACK FIRST. TYPE (1) FOR ARMY; (2) FOR NAVY;" */
line_17:
    printf("%s", "YOU ATTACK FIRST. TYPE (1) FOR ARMY; (2) FOR NAVY;"); printf("\n");
    /* BASIC: 18 PRINT "AND (3) FOR AIR FORCE." */
line_18:
    printf("%s", "AND (3) FOR AIR FORCE."); printf("\n");
    /* BASIC: 19 INPUT Y */
line_19:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &Y);
    /* BASIC: 20 PRINT "HOW MANY MEN" */
line_20:
    printf("%s", "HOW MANY MEN"); printf("\n");
    /* BASIC: 21 INPUT X */
line_21:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &X);
    /* BASIC: 22 IF X<0 THEN 20 */
line_22:
    if (X<0) goto line_20;
    /* BASIC: 23 ON Y GOTO 100,200,300 */
line_23:
    /* UNTRANSLATED: ON Y GOTO 100,200,300 */
    /* BASIC: 100 IF X>A THEN 20 */
line_100:
    if (X>A) goto line_20;
    /* BASIC: 105 IF X<A/3 THEN 120 */
line_105:
    if (X<A/3) goto line_120;
    /* BASIC: 110 IF X<2*A/3 THEN 150 */
line_110:
    if (X<2*A/3) goto line_150;
    /* BASIC: 115 GOTO 270 */
line_115:
    goto line_270;
    /* BASIC: 120 PRINT "YOU LOST";X;"MEN FROM YOUR ARMY." */
line_120:
    printf("%s", "YOU LOST"); printf("%g ", (double)(X)); printf("%s", "MEN FROM YOUR ARMY."); printf("\n");
    /* BASIC: 125 A=INT(A-X) */
line_125:
    A = floor(A-X);
    /* BASIC: 130 GOTO 500 */
line_130:
    goto line_500;
    /* BASIC: 150 PRINT "YOU LOST";INT(X/3);"MEN, BUT I LOST ";INT(2*D/3) */
line_150:
    printf("%s", "YOU LOST"); printf("%g ", (double)(floor(X/3))); printf("%s", "MEN, BUT I LOST "); printf("%g ", (double)(floor(2*D/3))); printf("\n");
    /* BASIC: 155 A=INT(A-X/3) */
line_155:
    A = floor(A-X/3);
    /* BASIC: 160 D=0 */
line_160:
    D = 0;
    /* BASIC: 165 GOTO 500 */
line_165:
    goto line_500;
    /* BASIC: 200 IF X>B THEN 20 */
line_200:
    if (X>B) goto line_20;
    /* BASIC: 210 IF X<E/3 THEN 230 */
line_210:
    if (X<E/3) goto line_230;
    /* BASIC: 215 IF X<2*E/3 THEN 250 */
line_215:
    if (X<2*E/3) goto line_250;
    /* BASIC: 220 GOTO 270 */
line_220:
    goto line_270;
    /* BASIC: 230 PRINT "YOUR ATTACK WAS STOPPED!" */
line_230:
    printf("%s", "YOUR ATTACK WAS STOPPED!"); printf("\n");
    /* BASIC: 232 B=INT(B-X) */
line_232:
    B = floor(B-X);
    /* BASIC: 235 GOTO 500 */
line_235:
    goto line_500;
    /* BASIC: 250 PRINT "YOU DESTROYED";INT(2*E/3);"OF MY ARMY." */
line_250:
    printf("%s", "YOU DESTROYED"); printf("%g ", (double)(floor(2*E/3))); printf("%s", "OF MY ARMY."); printf("\n");
    /* BASIC: 255 E=INT(E/3) */
line_255:
    E = floor(E/3);
    /* BASIC: 260 GOTO 500 */
line_260:
    goto line_500;
    /* BASIC: 270 PRINT "YOU SUNK ONE OF MY PATROL BOATS, BUT I WIPED OUT TWO" */
line_270:
    printf("%s", "YOU SUNK ONE OF MY PATROL BOATS, BUT I WIPED OUT TWO"); printf("\n");
    /* BASIC: 275 PRINT "OF YOUR AIR FORCE BASES AND 3 ARMY BASES." */
line_275:
    printf("%s", "OF YOUR AIR FORCE BASES AND 3 ARMY BASES."); printf("\n");
    /* BASIC: 280 A=INT(A/3) */
line_280:
    A = floor(A/3);
    /* BASIC: 285 C=INT(C/3) */
line_285:
    C = floor(C/3);
    /* BASIC: 290 E=INT(2*E/3) */
line_290:
    E = floor(2*E/3);
    /* BASIC: 293 GOTO 500 */
line_293:
    goto line_500;
    /* BASIC: 300 IF X>C THEN 20 */
line_300:
    if (X>C) goto line_20;
    /* BASIC: 310 IF X<C/3 THEN 350 */
line_310:
    if (X<C/3) goto line_350;
    /* BASIC: 320 IF X<2*C/3 THEN 370 */
line_320:
    if (X<2*C/3) goto line_370;
    /* BASIC: 330 GOTO 380 */
line_330:
    goto line_380;
    /* BASIC: 350 PRINT "YOUR ATTACK WAS WIPED OUT." */
line_350:
    printf("%s", "YOUR ATTACK WAS WIPED OUT."); printf("\n");
    /* BASIC: 355 C=INT(C-X) */
line_355:
    C = floor(C-X);
    /* BASIC: 360 GOTO 500 */
line_360:
    goto line_500;
    /* BASIC: 370 PRINT "WE HAD A DOGFIGHT. YOU WON - AND FINISHED YOUR MISSION." */
line_370:
    printf("%s", "WE HAD A DOGFIGHT. YOU WON - AND FINISHED YOUR MISSION."); printf("\n");
    /* BASIC: 375 D=INT(2*D/3) */
line_375:
    D = floor(2*D/3);
    /* BASIC: 377 E=INT(E/3) */
line_377:
    E = floor(E/3);
    /* BASIC: 378 F=INT(F/3) */
line_378:
    F = floor(F/3);
    /* BASIC: 379 GOTO 500 */
line_379:
    goto line_500;
    /* BASIC: 380 PRINT "YOU WIPED OUT ONE OF MY ARMY PATROLS, BUT I DESTROYED" */
line_380:
    printf("%s", "YOU WIPED OUT ONE OF MY ARMY PATROLS, BUT I DESTROYED"); printf("\n");
    /* BASIC: 381 PRINT "TWO NAVY BASES AND BOMBED THREE ARMY BASES." */
line_381:
    printf("%s", "TWO NAVY BASES AND BOMBED THREE ARMY BASES."); printf("\n");
    /* BASIC: 385 A=INT(A/4) */
line_385:
    A = floor(A/4);
    /* BASIC: 387 B=INT(B/3) */
line_387:
    B = floor(B/3);
    /* BASIC: 390 D=INT(2*D/3) */
line_390:
    D = floor(2*D/3);
    /* BASIC: 500 PRINT */
line_500:
    printf("\n");
    /* BASIC: 501 PRINT,"YOU","ME" */
line_501:
    printf("\t"); printf("%s", "YOU"); printf("\t"); printf("%s", "ME"); printf("\n");
    /* BASIC: 510 PRINT "ARMY",A,D */
line_510:
    printf("%s", "ARMY"); printf("\t"); printf("%g ", (double)(A)); printf("\t"); printf("%g ", (double)(D)); printf("\n");
    /* BASIC: 520 PRINT "NAVY",B,E */
line_520:
    printf("%s", "NAVY"); printf("\t"); printf("%g ", (double)(B)); printf("\t"); printf("%g ", (double)(E)); printf("\n");
    /* BASIC: 530 PRINT "A. F.",C,F */
line_530:
    printf("%s", "A. F."); printf("\t"); printf("%g ", (double)(C)); printf("\t"); printf("%g ", (double)(F)); printf("\n");
    /* BASIC: 1000 PRINT "WHAT IS YOUR NEXT MOVE?" */
line_1000:
    printf("%s", "WHAT IS YOUR NEXT MOVE?"); printf("\n");
    /* BASIC: 1010 PRINT "ARMY=1  NAVY=2  AIR FORCE=3" */
line_1010:
    printf("%s", "ARMY=1  NAVY=2  AIR FORCE=3"); printf("\n");
    /* BASIC: 1020 INPUT G */
line_1020:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &G);
    /* BASIC: 1030 PRINT "HOW MANY MEN" */
line_1030:
    printf("%s", "HOW MANY MEN"); printf("\n");
    /* BASIC: 1040 INPUT T */
line_1040:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &T);
    /* BASIC: 1045 IF T<0 THEN 1030 */
line_1045:
    if (T<0) goto line_1030;
    /* BASIC: 1050 ON G GOTO 1600,1700,1800 */
line_1050:
    /* UNTRANSLATED: ON G GOTO 1600,1700,1800 */
    /* BASIC: 1600 IF T>A THEN 1030 */
line_1600:
    if (T>A) goto line_1030;
    /* BASIC: 1610 IF T<D/2 THEN 1630 */
line_1610:
    if (T<D/2) goto line_1630;
    /* BASIC: 1615 PRINT "YOU DESTROYED MY ARMY!" */
line_1615:
    printf("%s", "YOU DESTROYED MY ARMY!"); printf("\n");
    /* BASIC: 1616 D=0 */
line_1616:
    D = 0;
    /* BASIC: 1617 GOTO 2000 */
line_1617:
    goto line_2000;
    /* BASIC: 1630 PRINT "I WIPED OUT YOUR ATTACK!" */
line_1630:
    printf("%s", "I WIPED OUT YOUR ATTACK!"); printf("\n");
    /* BASIC: 1635 A=A-T */
line_1635:
    A = A-T;
    /* BASIC: 1640 GOTO 2000 */
line_1640:
    goto line_2000;
    /* BASIC: 1700 IF T>B THEN 1030 */
line_1700:
    if (T>B) goto line_1030;
    /* BASIC: 1710 IF T<E/2 THEN 1750 */
line_1710:
    if (T<E/2) goto line_1750;
    /* BASIC: 1720 GOTO 1770 */
line_1720:
    goto line_1770;
    /* BASIC: 1750 PRINT "I SUNK TWO OF YOUR BATTLESHIPS, AND MY AIR FORCE" */
line_1750:
    printf("%s", "I SUNK TWO OF YOUR BATTLESHIPS, AND MY AIR FORCE"); printf("\n");
    /* BASIC: 1751 PRINT "WIPED OUT YOUR UNGAURDED CAPITOL." */
line_1751:
    printf("%s", "WIPED OUT YOUR UNGAURDED CAPITOL."); printf("\n");
    /* BASIC: 1755 A=A/4 */
line_1755:
    A = A/4;
    /* BASIC: 1760 B=B/2 */
line_1760:
    B = B/2;
    /* BASIC: 1765 GOTO 2000 */
line_1765:
    goto line_2000;
    /* BASIC: 1770 PRINT "YOUR NAVY SHOT DOWN THREE OF MY XIII PLANES," */
line_1770:
    printf("%s", "YOUR NAVY SHOT DOWN THREE OF MY XIII PLANES,"); printf("\n");
    /* BASIC: 1771 PRINT "AND SUNK THREE BATTLESHIPS." */
line_1771:
    printf("%s", "AND SUNK THREE BATTLESHIPS."); printf("\n");
    /* BASIC: 1775 F=2*F/3 */
line_1775:
    F = 2*F/3;
    /* BASIC: 1780 E=(E/2) */
line_1780:
    E = (E/2);
    /* BASIC: 1790 GOTO 2000 */
line_1790:
    goto line_2000;
    /* BASIC: 1800 IF T>C THEN 1030 */
line_1800:
    if (T>C) goto line_1030;
    /* BASIC: 1810 IF T>F/2 THEN 1830 */
line_1810:
    if (T>F/2) goto line_1830;
    /* BASIC: 1820 GOTO 1850 */
line_1820:
    goto line_1850;
    /* BASIC: 1830 PRINT "MY NAVY AND AIR FORCE IN A COMBINED ATTACK LEFT" */
line_1830:
    printf("%s", "MY NAVY AND AIR FORCE IN A COMBINED ATTACK LEFT"); printf("\n");
    /* BASIC: 1831 PRINT "YOUR COUNTRY IN SHAMBLES." */
line_1831:
    printf("%s", "YOUR COUNTRY IN SHAMBLES."); printf("\n");
    /* BASIC: 1835 A=A/3 */
line_1835:
    A = A/3;
    /* BASIC: 1837 B=B/3 */
line_1837:
    B = B/3;
    /* BASIC: 1840 C=C/3 */
line_1840:
    C = C/3;
    /* BASIC: 1845 GOTO 2000 */
line_1845:
    goto line_2000;
    /* BASIC: 1850 PRINT "ONE OF YOUR PLANES CRASHED INTO MY HOUSE. I AM DEAD." */
line_1850:
    printf("%s", "ONE OF YOUR PLANES CRASHED INTO MY HOUSE. I AM DEAD."); printf("\n");
    /* BASIC: 1851 PRINT "MY COUNTRY FELL APART." */
line_1851:
    printf("%s", "MY COUNTRY FELL APART."); printf("\n");
    /* BASIC: 1860 GOTO 2010 */
line_1860:
    goto line_2010;
    /* BASIC: 2000 PRINT */
line_2000:
    printf("\n");
    /* BASIC: 2001 PRINT "FROM THE RESULTS OF BOTH OF YOUR ATTACKS," */
line_2001:
    printf("%s", "FROM THE RESULTS OF BOTH OF YOUR ATTACKS,"); printf("\n");
    /* BASIC: 2002 IF A+B+C>3/2*(D+E+F) THEN 2010 */
line_2002:
    if (A+B+C>3/2*(D+E+F)) goto line_2010;
    /* BASIC: 2005 IF A+B+C<2/3*(D+E+F) THEN 2015 */
line_2005:
    if (A+B+C<2/3*(D+E+F)) goto line_2015;
    /* BASIC: 2006 PRINT "THE TREATY OF PARIS CONCLUDED THAT WE TAKE OUR" */
line_2006:
    printf("%s", "THE TREATY OF PARIS CONCLUDED THAT WE TAKE OUR"); printf("\n");
    /* BASIC: 2007 PRINT "RESPECTIVE COUNTRIES AND LIVE IN PEACE." */
line_2007:
    printf("%s", "RESPECTIVE COUNTRIES AND LIVE IN PEACE."); printf("\n");
    /* BASIC: 2008 GOTO 2020 */
line_2008:
    goto line_2020;
    /* BASIC: 2010 PRINT "YOU WON, OH! SHUCKS!!!!" */
line_2010:
    printf("%s", "YOU WON, OH! SHUCKS!!!!"); printf("\n");
    /* BASIC: 2012 GOTO 2020 */
line_2012:
    goto line_2020;
    /* BASIC: 2015 PRINT "YOU LOST-I CONQUERED YOUR COUNTRY.  IT SERVES YOU" */
line_2015:
    printf("%s", "YOU LOST-I CONQUERED YOUR COUNTRY.  IT SERVES YOU"); printf("\n");
    /* BASIC: 2016 PRINT "RIGHT FOR PLAYING THIS STUPID GAME!!!" */
line_2016:
    printf("%s", "RIGHT FOR PLAYING THIS STUPID GAME!!!"); printf("\n");
    /* BASIC: 2020 END */
line_2020:
    exit(0);

    return 0;
}
