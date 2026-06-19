/*
 * Transpiled from bunny.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double X, Y, READ, MORRISTOWN, B, L, CHR, I, COMPUTING, CREATIVE, JERSEY, J, NEW, DATA, BUNNY;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 10 PRINT TAB(33);"BUNNY" */
line_10:
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "BUNNY"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT: PRINT: PRINT */
line_30:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 100 REM  "BUNNY" FROM AHL'S 'BASIC COMPUTER GAMES' */
line_100:
    // REM  "BUNNY" FROM AHL'S 'BASIC COMPUTER GAMES'
    /* BASIC: 110 REM */
line_110:
    // REM
    /* BASIC: 120 FOR I=0 TO 4: READ B(I): NEXT I */
line_120:
    I = 0; for_loop_I: if ((1 >= 0 && I > 4) || (1 < 0 && I < 4)) goto end_for_I;
    /* UNTRANSLATED: READ B(I) */
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 130 GOSUB 260 */
line_130:
    /* TODO: GOSUB 260 */
    /* BASIC: 140 L=64: REM  ASCII LETTER CODE... */
line_140:
    L = 64;
    // REM  ASCII LETTER CODE...
    /* BASIC: 150 REM */
line_150:
    // REM
    /* BASIC: 160 PRINT */
line_160:
    printf("\n");
    /* BASIC: 170 READ X: IF X<0 THEN 160 */
line_170:
    /* UNTRANSLATED: READ X */
    if (X<0) goto line_160;
    /* BASIC: 175 IF X>128 THEN 240 */
line_175:
    if (X>128) goto line_240;
    /* BASIC: 180 PRINT TAB(X);: READ Y */
line_180:
    { int _t; for(_t=0; _t<X; _t++) printf(" "); }
    /* UNTRANSLATED: READ Y */
    /* BASIC: 190 FOR I=X TO Y: J=I-5*INT(I/5) */
line_190:
    I = X; for_loop_I: if ((1 >= 0 && I > Y) || (1 < 0 && I < Y)) goto end_for_I;
    J = I-5*floor(I/5);
    /* BASIC: 200 PRINT CHR$(L+B(J)); */
line_200:
    printf("%g ", (double)(CHR$(L+B(J))));
    /* BASIC: 210 NEXT I */
line_210:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 220 GOTO 170 */
line_220:
    goto line_170;
    /* BASIC: 230 REM */
line_230:
    // REM
    /* BASIC: 240 GOSUB 260: GOTO 450 */
line_240:
    /* TODO: GOSUB 260 */
    goto line_450;
    /* BASIC: 250 REM */
line_250:
    // REM
    /* BASIC: 260 FOR I=1 TO 6: PRINT CHR$(10);: NEXT I */
line_260:
    I = 1; for_loop_I: if ((1 >= 0 && I > 6) || (1 < 0 && I < 6)) goto end_for_I;
    printf("%g ", (double)(CHR$(10)));
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 270 RETURN */
line_270:
    /* TODO: RETURN */
    /* BASIC: 280 REM */
line_280:
    // REM
    /* BASIC: 290 DATA 2,21,14,14,25 */
line_290:
    /* UNTRANSLATED: DATA 2,21,14,14,25 */
    /* BASIC: 300 DATA 1,2,-1,0,2,45,50,-1,0,5,43,52,-1,0,7,41,52,-1 */
line_300:
    /* UNTRANSLATED: DATA 1,2,-1,0,2,45,50,-1,0,5,43,52,-1,0,7,41,52,-1 */
    /* BASIC: 310 DATA 1,9,37,50,-1,2,11,36,50,-1,3,13,34,49,-1,4,14,32,48,-1 */
line_310:
    /* UNTRANSLATED: DATA 1,9,37,50,-1,2,11,36,50,-1,3,13,34,49,-1,4,14,32,48,-1 */
    /* BASIC: 320 DATA 5,15,31,47,-1,6,16,30,45,-1,7,17,29,44,-1,8,19,28,43,-1 */
line_320:
    /* UNTRANSLATED: DATA 5,15,31,47,-1,6,16,30,45,-1,7,17,29,44,-1,8,19,28,43,-1 */
    /* BASIC: 330 DATA 9,20,27,41,-1,10,21,26,40,-1,11,22,25,38,-1,12,22,24,36,-1 */
line_330:
    /* UNTRANSLATED: DATA 9,20,27,41,-1,10,21,26,40,-1,11,22,25,38,-1,12,22,24,36,-1 */
    /* BASIC: 340 DATA 13,34,-1,14,33,-1,15,31,-1,17,29,-1,18,27,-1 */
line_340:
    /* UNTRANSLATED: DATA 13,34,-1,14,33,-1,15,31,-1,17,29,-1,18,27,-1 */
    /* BASIC: 350 DATA 19,26,-1,16,28,-1,13,30,-1,11,31,-1,10,32,-1 */
line_350:
    /* UNTRANSLATED: DATA 19,26,-1,16,28,-1,13,30,-1,11,31,-1,10,32,-1 */
    /* BASIC: 360 DATA 8,33,-1,7,34,-1,6,13,16,34,-1,5,12,16,35,-1 */
line_360:
    /* UNTRANSLATED: DATA 8,33,-1,7,34,-1,6,13,16,34,-1,5,12,16,35,-1 */
    /* BASIC: 370 DATA 4,12,16,35,-1,3,12,15,35,-1,2,35,-1,1,35,-1 */
line_370:
    /* UNTRANSLATED: DATA 4,12,16,35,-1,3,12,15,35,-1,2,35,-1,1,35,-1 */
    /* BASIC: 380 DATA 2,34,-1,3,34,-1,4,33,-1,6,33,-1,10,32,34,34,-1 */
line_380:
    /* UNTRANSLATED: DATA 2,34,-1,3,34,-1,4,33,-1,6,33,-1,10,32,34,34,-1 */
    /* BASIC: 390 DATA 14,17,19,25,28,31,35,35,-1,15,19,23,30,36,36,-1 */
line_390:
    /* UNTRANSLATED: DATA 14,17,19,25,28,31,35,35,-1,15,19,23,30,36,36,-1 */
    /* BASIC: 400 DATA 14,18,21,21,24,30,37,37,-1,13,18,23,29,33,38,-1 */
line_400:
    /* UNTRANSLATED: DATA 14,18,21,21,24,30,37,37,-1,13,18,23,29,33,38,-1 */
    /* BASIC: 410 DATA 12,29,31,33,-1,11,13,17,17,19,19,22,22,24,31,-1 */
line_410:
    /* UNTRANSLATED: DATA 12,29,31,33,-1,11,13,17,17,19,19,22,22,24,31,-1 */
    /* BASIC: 420 DATA 10,11,17,18,22,22,24,24,29,29,-1 */
line_420:
    /* UNTRANSLATED: DATA 10,11,17,18,22,22,24,24,29,29,-1 */
    /* BASIC: 430 DATA 22,23,26,29,-1,27,29,-1,28,29,-1,4096 */
line_430:
    /* UNTRANSLATED: DATA 22,23,26,29,-1,27,29,-1,28,29,-1,4096 */
    /* BASIC: 440 REM */
line_440:
    // REM
    /* BASIC: 450 END */
line_450:
    exit(0);

    return 0;
}
