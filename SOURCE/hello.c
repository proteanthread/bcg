/*
 * Transpiled from hello.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double ACTION, ORANGE, AMSTERDAM, CONFUSES, SELL, PATIENTS, THOSE, GO, WALK, NEW, BOSSES, COLD, NICE, SUFFERN, SO, SHOWER, ANSWER, JERSEY, THE, CHEATING, HEY, DON, REAL, GREEK, ON, YORK, LEFT, LIVING, A, ENJOYING, D, UP, WORK, IT, WON, BUT, LIKE, PAY, BEAT, T, HEALTH, HELLO, LITTLE, NEED, IN, TOKYO, BOTHERS, OUT, SHOOK, MARRY, MORRISTOWN, BRIGHTEN, ANY, TAKE, ALONE, ADVICE, JUICE, OFF, SEX, GREAT, OH, MONEY, KINDS, HERE, WHAT, EATING, ENCYCLOPEADIAS, REALLY, WANT, EXPECT, PSYCHOLOGY, OPEN, BROKE, BED, TOO, ALL, YOUR, I, ASPRIN, THERE, FUN, VERY, M, MORE, HEAR, VISIT, ME, CALL, HONEST, RICH, IS, OF, MUCH, DRINK, BEER, SORRY, S, KIND, WILL, CREATIVE, JOB, MY, COMPUTER, MEETING, PLEASE, YOU, SHOULD, NO, LEAVE, NAME, TERMINAL, WITH, DAY, PROBLEMS, WE, QUESTION, GREECE, WHY, FLUIDS, G, UNDERSTAND, HARD, SOMEONE, EARNED, THEIR, DEALING, ARE, RETAIL, PLENTY, BE, B, HOW, C, GLAD, EXCEPT, LONG, SYMPATHIZE, BIT, CAN, TWO, SOMEPLACE, SUCH, YOURSELF, WHICH, SAY, COMPUTING, JUST, GET, SOME, E, RIP, BILLS, KEYBOARD, AT, PROBLEM, SOLVE, MAYBE, HI, DID, HOURS, DO, STUDIES, THAT, YES, SIMPLE, SOLVED, N, STORE, HAVE, RESPOND;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 2 PRINT TAB(33);"HELLO" */
line_2:
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "HELLO"); printf("\n");
    /* BASIC: 4 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 6 PRINT: PRINT: PRINT */
line_6:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 10 PRINT "HELLO.  MY NAME IS CREATIVE COMPUTER." */
line_10:
    printf("%s", "HELLO.  MY NAME IS CREATIVE COMPUTER."); printf("\n");
    /* BASIC: 20 PRINT: PRINT: INPUT "WHAT'S YOUR NAME";N$: PRINT */
line_20:
    printf("\n");
    printf("\n");
    printf("%s", "WHAT'S YOUR NAME"); fgets(N_str, sizeof(N_str), stdin); N_str[strcspn(N_str, "\n")] = 0;
    printf("\n");
    /* BASIC: 30 PRINT "HI THERE, ";N$;", ARE YOU ENJOYING YOURSELF HERE"; */
line_30:
    printf("%s", "HI THERE, "); printf("%s", N_str); printf("%s", ", ARE YOU ENJOYING YOURSELF HERE");
    /* BASIC: 40 INPUT B$: PRINT */
line_40:
    printf("? "); fgets(B_str, sizeof(B_str), stdin); B_str[strcspn(B_str, "\n")] = 0;
    printf("\n");
    /* BASIC: 50 IF B$="YES" THEN 70 */
line_50:
    if (B$=="YES") goto line_70;
    /* BASIC: 55 IF B$="NO" THEN 80 */
line_55:
    if (B$=="NO") goto line_80;
    /* BASIC: 60 PRINT N$;", I DON'T UNDERSTAND YOUR ANSWER OF '";B$;"'." */
line_60:
    printf("%s", N_str); printf("%s", ", I DON'T UNDERSTAND YOUR ANSWER OF '"); printf("%s", B_str); printf("%s", "'."); printf("\n");
    /* BASIC: 65 PRINT "PLEASE ANSWER 'YES' OR 'NO'.  DO YOU LIKE IT HERE";: GOTO 40 */
line_65:
    printf("%s", "PLEASE ANSWER 'YES' OR 'NO'.  DO YOU LIKE IT HERE");
    goto line_40;
    /* BASIC: 70 PRINT "I'M GLAD TO HEAR THAT, ";N$;".": PRINT */
line_70:
    printf("%s", "I'M GLAD TO HEAR THAT, "); printf("%s", N_str); printf("%s", "."); printf("\n");
    printf("\n");
    /* BASIC: 75 GOTO 100 */
line_75:
    goto line_100;
    /* BASIC: 80 PRINT "OH, I'M SORRY TO HEAR THAT, ";N$;". MAYBE WE CAN" */
line_80:
    printf("%s", "OH, I'M SORRY TO HEAR THAT, "); printf("%s", N_str); printf("%s", ". MAYBE WE CAN"); printf("\n");
    /* BASIC: 85 PRINT "BRIGHTEN UP YOUR VISIT A BIT." */
line_85:
    printf("%s", "BRIGHTEN UP YOUR VISIT A BIT."); printf("\n");
    /* BASIC: 100 PRINT */
line_100:
    printf("\n");
    /* BASIC: 105 PRINT "SAY, ";N$;", I CAN SOLVE ALL KINDS OF PROBLEMS EXCEPT" */
line_105:
    printf("%s", "SAY, "); printf("%s", N_str); printf("%s", ", I CAN SOLVE ALL KINDS OF PROBLEMS EXCEPT"); printf("\n");
    /* BASIC: 110 PRINT "THOSE DEALING WITH GREECE.  WHAT KIND OF PROBLEMS DO" */
line_110:
    printf("%s", "THOSE DEALING WITH GREECE.  WHAT KIND OF PROBLEMS DO"); printf("\n");
    /* BASIC: 120 PRINT "YOU HAVE (ANSWER SEX, HEALTH, MONEY, OR JOB)"; */
line_120:
    printf("%s", "YOU HAVE (ANSWER SEX, HEALTH, MONEY, OR JOB)");
    /* BASIC: 125 INPUT C$ */
line_125:
    printf("? "); fgets(C_str, sizeof(C_str), stdin); C_str[strcspn(C_str, "\n")] = 0;
    /* BASIC: 126 PRINT */
line_126:
    printf("\n");
    /* BASIC: 130 IF C$="SEX" THEN 200 */
line_130:
    if (C$=="SEX") goto line_200;
    /* BASIC: 132 IF C$="HEALTH" THEN 180 */
line_132:
    if (C$=="HEALTH") goto line_180;
    /* BASIC: 134 IF C$="MONEY" THEN 160 */
line_134:
    if (C$=="MONEY") goto line_160;
    /* BASIC: 136 IF C$="JOB" THEN 145 */
line_136:
    if (C$=="JOB") goto line_145;
    /* BASIC: 138 PRINT "OH, ";N$;", YOUR ANSWER OF ";C$;" IS GREEK TO ME." */
line_138:
    printf("%s", "OH, "); printf("%s", N_str); printf("%s", ", YOUR ANSWER OF "); printf("%s", C_str); printf("%s", " IS GREEK TO ME."); printf("\n");
    /* BASIC: 140 GOTO 250 */
line_140:
    goto line_250;
    /* BASIC: 145 PRINT "I CAN SYMPATHIZE WITH YOU ";N$;".  I HAVE TO WORK" */
line_145:
    printf("%s", "I CAN SYMPATHIZE WITH YOU "); printf("%s", N_str); printf("%s", ".  I HAVE TO WORK"); printf("\n");
    /* BASIC: 148 PRINT "VERY LONG HOURS FOR NO PAY -- AND SOME OF MY BOSSES" */
line_148:
    printf("%s", "VERY LONG HOURS FOR NO PAY -- AND SOME OF MY BOSSES"); printf("\n");
    /* BASIC: 150 PRINT "REALLY BEAT ON MY KEYBOARD.  MY ADVICE TO YOU, ";N$;"," */
line_150:
    printf("%s", "REALLY BEAT ON MY KEYBOARD.  MY ADVICE TO YOU, "); printf("%s", N_str); printf("%s", ","); printf("\n");
    /* BASIC: 153 PRINT "IS TO OPEN A RETAIL COMPUTER STORE.  IT'S GREAT FUN." */
line_153:
    printf("%s", "IS TO OPEN A RETAIL COMPUTER STORE.  IT'S GREAT FUN."); printf("\n");
    /* BASIC: 155 GOTO 250 */
line_155:
    goto line_250;
    /* BASIC: 160 PRINT "SORRY, ";N$;", I'M BROKE TOO.  WHY DON'T YOU SELL" */
line_160:
    printf("%s", "SORRY, "); printf("%s", N_str); printf("%s", ", I'M BROKE TOO.  WHY DON'T YOU SELL"); printf("\n");
    /* BASIC: 162 PRINT "ENCYCLOPEADIAS OR MARRY SOMEONE RICH OR STOP EATING" */
line_162:
    printf("%s", "ENCYCLOPEADIAS OR MARRY SOMEONE RICH OR STOP EATING"); printf("\n");
    /* BASIC: 164 PRINT "SO YOU WON'T NEED SO MUCH MONEY?" */
line_164:
    printf("%s", "SO YOU WON'T NEED SO MUCH MONEY?"); printf("\n");
    /* BASIC: 170 GOTO 250 */
line_170:
    goto line_250;
    /* BASIC: 180 PRINT "MY ADVICE TO YOU ";N$;" IS:" */
line_180:
    printf("%s", "MY ADVICE TO YOU "); printf("%s", N_str); printf("%s", " IS:"); printf("\n");
    /* BASIC: 185 PRINT "     1.  TAKE TWO ASPRIN" */
line_185:
    printf("%s", "     1.  TAKE TWO ASPRIN"); printf("\n");
    /* BASIC: 188 PRINT "     2.  DRINK PLENTY OF FLUIDS (ORANGE JUICE, NOT BEER!)" */
line_188:
    printf("%s", "     2.  DRINK PLENTY OF FLUIDS (ORANGE JUICE, NOT BEER!)"); printf("\n");
    /* BASIC: 190 PRINT "     3.  GO TO BED (ALONE)" */
line_190:
    printf("%s", "     3.  GO TO BED (ALONE)"); printf("\n");
    /* BASIC: 195 GOTO 250 */
line_195:
    goto line_250;
    /* BASIC: 200 INPUT "IS YOUR PROBLEM TOO MUCH OR TOO LITTLE";D$: PRINT */
line_200:
    printf("%s", "IS YOUR PROBLEM TOO MUCH OR TOO LITTLE"); fgets(D_str, sizeof(D_str), stdin); D_str[strcspn(D_str, "\n")] = 0;
    printf("\n");
    /* BASIC: 210 IF D$="TOO MUCH" THEN 220 */
line_210:
    if (D$=="TOO MUCH") goto line_220;
    /* BASIC: 212 IF D$="TOO LITTLE" THEN 230 */
line_212:
    if (D$=="TOO LITTLE") goto line_230;
    /* BASIC: 215 PRINT "DON'T GET ALL SHOOK, ";N$;", JUST ANSWER THE QUESTION" */
line_215:
    printf("%s", "DON'T GET ALL SHOOK, "); printf("%s", N_str); printf("%s", ", JUST ANSWER THE QUESTION"); printf("\n");
    /* BASIC: 217 INPUT "WITH 'TOO MUCH' OR 'TOO LITTLE'.  WHICH IS IT";D$:GOTO 210 */
line_217:
    printf("%s", "WITH 'TOO MUCH' OR 'TOO LITTLE'.  WHICH IS IT"); fgets(D_str, sizeof(D_str), stdin); D_str[strcspn(D_str, "\n")] = 0;
    goto line_210;
    /* BASIC: 220 PRINT "YOU CALL THAT A PROBLEM?!!  I SHOULD HAVE SUCH PROBLEMS!" */
line_220:
    printf("%s", "YOU CALL THAT A PROBLEM?!!  I SHOULD HAVE SUCH PROBLEMS!"); printf("\n");
    /* BASIC: 225 PRINT "IF IT BOTHERS YOU, ";N$;", TAKE A COLD SHOWER." */
line_225:
    printf("%s", "IF IT BOTHERS YOU, "); printf("%s", N_str); printf("%s", ", TAKE A COLD SHOWER."); printf("\n");
    /* BASIC: 228 GOTO 250 */
line_228:
    goto line_250;
    /* BASIC: 230 PRINT "WHY ARE YOU HERE IN SUFFERN, ";N$;"?  YOU SHOULD BE" */
line_230:
    printf("%s", "WHY ARE YOU HERE IN SUFFERN, "); printf("%s", N_str); printf("%s", "?  YOU SHOULD BE"); printf("\n");
    /* BASIC: 235 PRINT "IN TOKYO OR NEW YORK OR AMSTERDAM OR SOMEPLACE WITH SOME" */
line_235:
    printf("%s", "IN TOKYO OR NEW YORK OR AMSTERDAM OR SOMEPLACE WITH SOME"); printf("\n");
    /* BASIC: 240 PRINT "REAL ACTION." */
line_240:
    printf("%s", "REAL ACTION."); printf("\n");
    /* BASIC: 250 PRINT */
line_250:
    printf("\n");
    /* BASIC: 255 PRINT "ANY MORE PROBLEMS YOU WANT SOLVED, ";N$; */
line_255:
    printf("%s", "ANY MORE PROBLEMS YOU WANT SOLVED, "); printf("%s", N_str);
    /* BASIC: 260 INPUT E$: PRINT */
line_260:
    printf("? "); fgets(E_str, sizeof(E_str), stdin); E_str[strcspn(E_str, "\n")] = 0;
    printf("\n");
    /* BASIC: 270 IF E$="YES" THEN 280 */
line_270:
    if (E$=="YES") goto line_280;
    /* BASIC: 273 IF E$="NO" THEN 300 */
line_273:
    if (E$=="NO") goto line_300;
    /* BASIC: 275 PRINT "JUST A SIMPLE 'YES' OR 'NO' PLEASE, ";N$;"." */
line_275:
    printf("%s", "JUST A SIMPLE 'YES' OR 'NO' PLEASE, "); printf("%s", N_str); printf("%s", "."); printf("\n");
    /* BASIC: 277 GOTO 255 */
line_277:
    goto line_255;
    /* BASIC: 280 PRINT "WHAT KIND (SEX, MONEY, HEALTH, JOB)"; */
line_280:
    printf("%s", "WHAT KIND (SEX, MONEY, HEALTH, JOB)");
    /* BASIC: 282 GOTO 125 */
line_282:
    goto line_125;
    /* BASIC: 300 PRINT */
line_300:
    printf("\n");
    /* BASIC: 302 PRINT "THAT WILL BE $5.00 FOR THE ADVICE, ";N$;"." */
line_302:
    printf("%s", "THAT WILL BE $5.00 FOR THE ADVICE, "); printf("%s", N_str); printf("%s", "."); printf("\n");
    /* BASIC: 305 PRINT "PLEASE LEAVE THE MONEY ON THE TERMINAL." */
line_305:
    printf("%s", "PLEASE LEAVE THE MONEY ON THE TERMINAL."); printf("\n");
    /* BASIC: 307 FOR I=1 TO 2000: NEXT I */
line_307:
    I = 1; for_loop_I: if ((1 >= 0 && I > 2000) || (1 < 0 && I < 2000)) goto end_for_I;
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 310 PRINT: PRINT: PRINT */
line_310:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 315 PRINT "DID YOU LEAVE THE MONEY"; */
line_315:
    printf("%s", "DID YOU LEAVE THE MONEY");
    /* BASIC: 320 INPUT G$: PRINT */
line_320:
    printf("? "); fgets(G_str, sizeof(G_str), stdin); G_str[strcspn(G_str, "\n")] = 0;
    printf("\n");
    /* BASIC: 325 IF G$="YES" THEN 350 */
line_325:
    if (G$=="YES") goto line_350;
    /* BASIC: 330 IF G$="NO" THEN 370 */
line_330:
    if (G$=="NO") goto line_370;
    /* BASIC: 335 PRINT "YOUR ANSWER OF '";G$;"' CONFUSES ME, ";N$;"." */
line_335:
    printf("%s", "YOUR ANSWER OF '"); printf("%s", G_str); printf("%s", "' CONFUSES ME, "); printf("%s", N_str); printf("%s", "."); printf("\n");
    /* BASIC: 340 PRINT "PLEASE RESPOND WITH 'YES' OR 'NO'.": GOTO 315 */
line_340:
    printf("%s", "PLEASE RESPOND WITH 'YES' OR 'NO'."); printf("\n");
    goto line_315;
    /* BASIC: 350 PRINT "HEY, ";N$;"??? YOU LEFT NO MONEY AT ALL!" */
line_350:
    printf("%s", "HEY, "); printf("%s", N_str); printf("%s", "??? YOU LEFT NO MONEY AT ALL!"); printf("\n");
    /* BASIC: 355 PRINT "YOU ARE CHEATING ME OUT OF MY HARD-EARNED LIVING." */
line_355:
    printf("%s", "YOU ARE CHEATING ME OUT OF MY HARD-EARNED LIVING."); printf("\n");
    /* BASIC: 360 PRINT:PRINT "WHAT A RIP OFF, ";N$;"!!!":PRINT */
line_360:
    printf("\n");
    printf("%s", "WHAT A RIP OFF, "); printf("%s", N_str); printf("%s", "!!!"); printf("\n");
    printf("\n");
    /* BASIC: 365 GOTO 385 */
line_365:
    goto line_385;
    /* BASIC: 370 PRINT "THAT'S HONEST, ";N$;", BUT HOW DO YOU EXPECT" */
line_370:
    printf("%s", "THAT'S HONEST, "); printf("%s", N_str); printf("%s", ", BUT HOW DO YOU EXPECT"); printf("\n");
    /* BASIC: 375 PRINT "ME TO GO ON WITH MY PSYCHOLOGY STUDIES IF MY PATIENTS" */
line_375:
    printf("%s", "ME TO GO ON WITH MY PSYCHOLOGY STUDIES IF MY PATIENTS"); printf("\n");
    /* BASIC: 380 PRINT "DON'T PAY THEIR BILLS?" */
line_380:
    printf("%s", "DON'T PAY THEIR BILLS?"); printf("\n");
    /* BASIC: 385 PRINT:PRINT "TAKE A WALK, ";N$;".":PRINT:PRINT:GOTO 999 */
line_385:
    printf("\n");
    printf("%s", "TAKE A WALK, "); printf("%s", N_str); printf("%s", "."); printf("\n");
    printf("\n");
    printf("\n");
    goto line_999;
    /* BASIC: 390 PRINT "NICE MEETING YOU, ";N$;", HAVE A NICE DAY." */
line_390:
    printf("%s", "NICE MEETING YOU, "); printf("%s", N_str); printf("%s", ", HAVE A NICE DAY."); printf("\n");
    /* BASIC: 400 REM */
line_400:
    // REM
    /* BASIC: 999 END */
line_999:
    exit(0);

    return 0;
}
