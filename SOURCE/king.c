/*
 * Transpiled from king.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double MONOXIDE, OFFICE, ABS, SMALL, AMONG, YEARS, SELL, NOW, AIR, P, GAME, COSTS, J, NEW, TYPE, DECIDE, BUDGET, GOAL, INSTRUCTIONS, UPON, ANSWER, DISCOURAGING, RE, THEY, JERSEY, THE, TAKEN, FOREST, ON, LEFT, CURRENTLY, TOP, DECREASE, A, PERSON, RESERVES, STRIP, SUCCESFULLY, ACHIEVEMENT, PLAYS, SQ, D, FORCED, BUT, WHEN, HUNTING, IT, GOODBYE, PRISON, CONTROL, V3, MINORITY, SUN, WERE, INCREASED, HAD, GOUGED, IN, FOREIGN, MINE, NEED, PUBLIC, FUNERAL, NUMBER, REPUTATION, UNECONOMICAL, OUT, RESULT, Q, SMOG, BY, MORRISTOWN, GAINED, BATHERS, SUICIDE, WORKERS, POLLUTION, RUINED, N5, CROPS, X5, CHOICE, A4, PEOPLE, DECLARED, OFF, START, GRIT, CAME, CONTENT, WAS, V2, BIRD, TURN, COURSE, MONEY, LUCK, PROBABLY, RESIDING, COUNTRYMEN, THROWN, COUNTRY, LOOKING, BECAUSE, HATE, STARTED, BEING, F1, BATHS, COUNTRYMAN, BAD, BETWEEN, C1, SINCE, YOURS, LATER, WANT, CONTRY, CONTINUE, MAKING, FARM, SHABBY, FISHING, G1, THICKER, DETINU, YOUR, I, EXPENSES, DWINDLED, DIED, POPULTATION, SOIL, COVER, HAS, PROCEEDING, FROM, CARBON, VERY, ELECTED, RALLODS, COST, BEEN, SURVIVE, W, H, IS, CONGRATULATIONS, OWN, K, U1, MILES, UNPLEASANT, OF, Z, ONLY, INHALATION, LL, MUCH, TREES, FORESTS, EXT, SORRY, U2, S, WILL, DUE, LATTER, CREATIVE, JOB, V9, POPULATION, THINK, COMPUTER, EACH, PLEASE, YOU, WATER, VISITING, COMES, X, NATIONAL, TREASURY, AS, SPEND, SQUARE, ASSASSINATED, WITH, ETC, KING, MINERAL, ONE, FISH, YEAR, DUST, ASKED, T1, GOOD, BUY, P1, FINK, QUITE, AN, COME, MAY, THEIR, CHOOSE, COMMUNIST, DISTRIBUTE, V1, BE, ARE, HOTELS, ENRAGED, EYE, B, HOW, C, THIRD, NEVERTHELESS, TOURISTS, LONG, WISH, SOLD, COMMIT, RESIGN, INCOME, COMMUNAL, CAN, MILE, IMPEACHED, LAND, B5, TERM, INTERRUPTED, WHICH, MINING, COMPUTING, JUST, PLANT, MAGNIFICENT, PRODUCE, GUTS, SOME, VE, STARVATION, HALF, M6, SUPPORT, COMPLETED, TOURIST, MANY, BEFORE, HARVESTED, AT, REVOLTED, COMPLETE, DATE, ALSO, PLANTED, DID, DO, AGAIN, INSUFFICIENT, PER, THAT, WHO, OVER, EXCELLENT, MADE, N, NEEDS, EITHER, HAVE, EXCEEDED, SYSTEM, THIS, IMPORT, ISLAND, KILLING, INDUSTRY, TRADE;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 1 PRINT TAB(34);"KING" */
line_1:
    { int _t; for(_t=0; _t<34; _t++) printf(" "); } printf("%s", "KING"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT:PRINT:PRINT */
line_3:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 4 PRINT "DO YOU WANT INSTRUCTIONS"; */
line_4:
    printf("%s", "DO YOU WANT INSTRUCTIONS");
    /* BASIC: 5 INPUT Z$ */
line_5:
    printf("? "); fgets(Z_str, sizeof(Z_str), stdin); Z_str[strcspn(Z_str, "\n")] = 0;
    /* BASIC: 6 N5=8 */
line_6:
    N5 = 8;
    /* BASIC: 10 IF LEFT$(Z$,1)="N" THEN 47 */
line_10:
    if (LEFT$(Z$,1)=="N") goto line_47;
    /* BASIC: 11 IF Z$="AGAIN" THEN 1960 */
line_11:
    if (Z$=="AGAIN") goto line_1960;
    /* BASIC: 12 PRINT:PRINT:PRINT */
line_12:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 20 PRINT "CONGRATULATIONS! YOU'VE JUST BEEN ELECTED PREMIER OF SETATS" */
line_20:
    printf("%s", "CONGRATULATIONS! YOU'VE JUST BEEN ELECTED PREMIER OF SETATS"); printf("\n");
    /* BASIC: 22 PRINT "DETINU, A SMALL COMMUNIST ISLAND 30 BY 70 MILES LONG. YOUR" */
line_22:
    printf("%s", "DETINU, A SMALL COMMUNIST ISLAND 30 BY 70 MILES LONG. YOUR"); printf("\n");
    /* BASIC: 24 PRINT "JOB IS TO DECIDE UPON THE CONTRY'S BUDGET AND DISTRIBUTE" */
line_24:
    printf("%s", "JOB IS TO DECIDE UPON THE CONTRY'S BUDGET AND DISTRIBUTE"); printf("\n");
    /* BASIC: 26 PRINT "MONEY TO YOUR COUNTRYMEN FROM THE COMMUNAL TREASURY." */
line_26:
    printf("%s", "MONEY TO YOUR COUNTRYMEN FROM THE COMMUNAL TREASURY."); printf("\n");
    /* BASIC: 28 PRINT "THE MONEY SYSTEM IS RALLODS, AND EACH PERSON NEEDS 100" */
line_28:
    printf("%s", "THE MONEY SYSTEM IS RALLODS, AND EACH PERSON NEEDS 100"); printf("\n");
    /* BASIC: 30 PRINT "RALLODS PER YEAR TO SURVIVE. YOUR COUNTRY'S INCOME COMES" */
line_30:
    printf("%s", "RALLODS PER YEAR TO SURVIVE. YOUR COUNTRY'S INCOME COMES"); printf("\n");
    /* BASIC: 32 PRINT "FROM FARM PRODUCE AND TOURISTS VISITING YOUR MAGNIFICENT" */
line_32:
    printf("%s", "FROM FARM PRODUCE AND TOURISTS VISITING YOUR MAGNIFICENT"); printf("\n");
    /* BASIC: 34 PRINT "FORESTS, HUNTING, FISHING, ETC. HALF YOUR LAND IS FARM LAND" */
line_34:
    printf("%s", "FORESTS, HUNTING, FISHING, ETC. HALF YOUR LAND IS FARM LAND"); printf("\n");
    /* BASIC: 36 PRINT "WHICH ALSO HAS AN EXCELLENT MINERAL CONTENT AND MAY BE SOLD" */
line_36:
    printf("%s", "WHICH ALSO HAS AN EXCELLENT MINERAL CONTENT AND MAY BE SOLD"); printf("\n");
    /* BASIC: 38 PRINT "TO FOREIGN INDUSTRY (STRIP MINING) WHO IMPORT AND SUPPORT" */
line_38:
    printf("%s", "TO FOREIGN INDUSTRY (STRIP MINING) WHO IMPORT AND SUPPORT"); printf("\n");
    /* BASIC: 40 PRINT "THEIR OWN WORKERS. CROPS COST BETWEEN 10 AND 15 RALLODS PER" */
line_40:
    printf("%s", "THEIR OWN WORKERS. CROPS COST BETWEEN 10 AND 15 RALLODS PER"); printf("\n");
    /* BASIC: 42 PRINT "SQUARE MILE TO PLANT." */
line_42:
    printf("%s", "SQUARE MILE TO PLANT."); printf("\n");
    /* BASIC: 44 PRINT "YOUR GOAL IS TO COMPLETE YOUR";N5;"YEAR TERM OF OFFICE." */
line_44:
    printf("%s", "YOUR GOAL IS TO COMPLETE YOUR"); printf("%g ", (double)(N5)); printf("%s", "YEAR TERM OF OFFICE."); printf("\n");
    /* BASIC: 46 PRINT "GOOD LUCK!" */
line_46:
    printf("%s", "GOOD LUCK!"); printf("\n");
    /* BASIC: 47 PRINT */
line_47:
    printf("\n");
    /* BASIC: 50 A=INT(60000+(1000*RND(1))-(1000*RND(1))) */
line_50:
    A = floor(60000+(1000*((double)rand() / (double)RAND_MAX))-(1000*((double)rand() / (double)RAND_MAX)));
    /* BASIC: 55 B=INT(500+(10*RND(1))-(10*RND(1))) */
line_55:
    B = floor(500+(10*((double)rand() / (double)RAND_MAX))-(10*((double)rand() / (double)RAND_MAX)));
    /* BASIC: 65 D=2000 */
line_65:
    D = 2000;
    /* BASIC: 100 W=INT(10*RND(1)+95) */
line_100:
    W = floor(10*((double)rand() / (double)RAND_MAX)+95);
    /* BASIC: 102 PRINT */
line_102:
    printf("\n");
    /* BASIC: 105 PRINT "YOU NOW HAVE ";A;" RALLODS IN THE TREASURY." */
line_105:
    printf("%s", "YOU NOW HAVE "); printf("%g ", (double)(A)); printf("%s", " RALLODS IN THE TREASURY."); printf("\n");
    /* BASIC: 110 PRINT INT(B);:PRINT "COUNTRYMEN, "; */
line_110:
    printf("%g ", (double)(floor(B)));
    printf("%s", "COUNTRYMEN, ");
    /* BASIC: 115 V9=INT(((RND(1)/2)*10+10)) */
line_115:
    V9 = floor(((((double)rand() / (double)RAND_MAX)/2)*10+10));
    /* BASIC: 120 IF C=0 THEN 140 */
line_120:
    if (C==0) goto line_140;
    /* BASIC: 130 PRINT INT(C);"FOREIGN WORKERS, "; */
line_130:
    printf("%g ", (double)(floor(C))); printf("%s", "FOREIGN WORKERS, ");
    /* BASIC: 140 PRINT "AND";INT(D);"SQ. MILES OF LAND." */
line_140:
    printf("%s", "AND"); printf("%g ", (double)(floor(D))); printf("%s", "SQ. MILES OF LAND."); printf("\n");
    /* BASIC: 150 PRINT "THIS YEAR INDUSTRY WILL BUY LAND FOR";W; */
line_150:
    printf("%s", "THIS YEAR INDUSTRY WILL BUY LAND FOR"); printf("%g ", (double)(W));
    /* BASIC: 152 PRINT "RALLODS PER SQUARE MILE." */
line_152:
    printf("%s", "RALLODS PER SQUARE MILE."); printf("\n");
    /* BASIC: 155 PRINT "LAND CURRENTLY COSTS";V9;"RALLODS PER SQUARE MILE TO PLANT." */
line_155:
    printf("%s", "LAND CURRENTLY COSTS"); printf("%g ", (double)(V9)); printf("%s", "RALLODS PER SQUARE MILE TO PLANT."); printf("\n");
    /* BASIC: 162 PRINT */
line_162:
    printf("\n");
    /* BASIC: 200 PRINT "HOW MANY SQUARE MILES DO YOU WISH TO SELL TO INDUSTRY"; */
line_200:
    printf("%s", "HOW MANY SQUARE MILES DO YOU WISH TO SELL TO INDUSTRY");
    /* BASIC: 210 INPUT H */
line_210:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &H);
    /* BASIC: 215 IF H<0 THEN 200 */
line_215:
    if (H<0) goto line_200;
    /* BASIC: 220 IF H<=D-1000 THEN 300 */
line_220:
    if (H<==D-1000) goto line_300;
    /* BASIC: 230 PRINT "***  THINK AGAIN. YOU ONLY HAVE";D-1000;"SQUARE MILES OF FARM LAND." */
line_230:
    printf("%s", "***  THINK AGAIN. YOU ONLY HAVE"); printf("%g ", (double)(D-1000)); printf("%s", "SQUARE MILES OF FARM LAND."); printf("\n");
    /* BASIC: 240 IF X<>0 THEN 200 */
line_240:
    if (X!=0) goto line_200;
    /* BASIC: 250 PRINT:PRINT "(FOREIGN INDUSTRY WILL ONLY BUY FARM LAND BECAUSE" */
line_250:
    printf("\n");
    printf("%s", "(FOREIGN INDUSTRY WILL ONLY BUY FARM LAND BECAUSE"); printf("\n");
    /* BASIC: 260 PRINT "FOREST LAND IS UNECONOMICAL TO STRIP MINE DUE TO TREES," */
line_260:
    printf("%s", "FOREST LAND IS UNECONOMICAL TO STRIP MINE DUE TO TREES,"); printf("\n");
    /* BASIC: 270 PRINT "THICKER TOP SOIL, ETC.)" */
line_270:
    printf("%s", "THICKER TOP SOIL, ETC.)"); printf("\n");
    /* BASIC: 280 X=1 */
line_280:
    X = 1;
    /* BASIC: 299 GOTO 200 */
line_299:
    goto line_200;
    /* BASIC: 300 D=INT(D-H) */
line_300:
    D = floor(D-H);
    /* BASIC: 310 A=INT(A+(H*W)) */
line_310:
    A = floor(A+(H*W));
    /* BASIC: 320 PRINT "HOW MANY RALLODS WILL YOU DISTRIBUTE AMONG YOUR COUNTRYMEN"; */
line_320:
    printf("%s", "HOW MANY RALLODS WILL YOU DISTRIBUTE AMONG YOUR COUNTRYMEN");
    /* BASIC: 340 INPUT I */
line_340:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &I);
    /* BASIC: 342 IF I<0 THEN 320 */
line_342:
    if (I<0) goto line_320;
    /* BASIC: 350 IF I<A THEN 400 */
line_350:
    if (I<A) goto line_400;
    /* BASIC: 360 IF I=A THEN 380 */
line_360:
    if (I==A) goto line_380;
    /* BASIC: 370 PRINT "   THINK AGAIN. YOU'VE ONLY";A;" RALLODS IN THE TREASURY" */
line_370:
    printf("%s", "   THINK AGAIN. YOU'VE ONLY"); printf("%g ", (double)(A)); printf("%s", " RALLODS IN THE TREASURY"); printf("\n");
    /* BASIC: 375 GOTO 320 */
line_375:
    goto line_320;
    /* BASIC: 380 J=0 */
line_380:
    J = 0;
    /* BASIC: 390 K=0 */
line_390:
    K = 0;
    /* BASIC: 395 A=0 */
line_395:
    A = 0;
    /* BASIC: 399 GOTO 1000 */
line_399:
    goto line_1000;
    /* BASIC: 400 A=INT(A-I) */
line_400:
    A = floor(A-I);
    /* BASIC: 410 PRINT "HOW MANY SQUARE MILES DO YOU WISH TO PLANT"; */
line_410:
    printf("%s", "HOW MANY SQUARE MILES DO YOU WISH TO PLANT");
    /* BASIC: 420 INPUT J */
line_420:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &J);
    /* BASIC: 421 IF J<0 THEN 410 */
line_421:
    if (J<0) goto line_410;
    /* BASIC: 422 IF J<=B*2 THEN 426 */
line_422:
    if (J<==B*2) goto line_426;
    /* BASIC: 423 PRINT "   SORRY, BUT EACH COUNTRYMAN CAN ONLY PLANT 2 SQ. MILES." */
line_423:
    printf("%s", "   SORRY, BUT EACH COUNTRYMAN CAN ONLY PLANT 2 SQ. MILES."); printf("\n");
    /* BASIC: 424 GOTO 410 */
line_424:
    goto line_410;
    /* BASIC: 426 IF J<=D-1000 THEN 430 */
line_426:
    if (J<==D-1000) goto line_430;
    /* BASIC: 427 PRINT "   SORRY, BUT YOU'VE ONLY";D-1000;"SQ. MILES OF FARM LAND." */
line_427:
    printf("%s", "   SORRY, BUT YOU'VE ONLY"); printf("%g ", (double)(D-1000)); printf("%s", "SQ. MILES OF FARM LAND."); printf("\n");
    /* BASIC: 428 GOTO 410 */
line_428:
    goto line_410;
    /* BASIC: 430 U1=INT(J*V9) */
line_430:
    U1 = floor(J*V9);
    /* BASIC: 435 IF U1<A THEN 500 */
line_435:
    if (U1<A) goto line_500;
    /* BASIC: 440 IF U1=A THEN 490 */
line_440:
    if (U1==A) goto line_490;
    /* BASIC: 450 PRINT "   THINK AGAIN. YOU'VE ONLY";A;" RALLODS LEFT IN THE TREASURY." */
line_450:
    printf("%s", "   THINK AGAIN. YOU'VE ONLY"); printf("%g ", (double)(A)); printf("%s", " RALLODS LEFT IN THE TREASURY."); printf("\n");
    /* BASIC: 460 GOTO 410 */
line_460:
    goto line_410;
    /* BASIC: 490 K=0 */
line_490:
    K = 0;
    /* BASIC: 495 A=0 */
line_495:
    A = 0;
    /* BASIC: 499 GOTO 1000 */
line_499:
    goto line_1000;
    /* BASIC: 500 A=A-U1 */
line_500:
    A = A-U1;
    /* BASIC: 510 PRINT "HOW MANY RALLODS DO YOU WISH TO SPEND ON POLLUTION CONTROL"; */
line_510:
    printf("%s", "HOW MANY RALLODS DO YOU WISH TO SPEND ON POLLUTION CONTROL");
    /* BASIC: 520 INPUT K */
line_520:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &K);
    /* BASIC: 522 IF K<0 THEN 510 */
line_522:
    if (K<0) goto line_510;
    /* BASIC: 530 IF K<=A THEN 1000 */
line_530:
    if (K<==A) goto line_1000;
    /* BASIC: 540 PRINT "   THINK AGAIN. YOU ONLY HAVE ";A;" RALLODS REMAINING." */
line_540:
    printf("%s", "   THINK AGAIN. YOU ONLY HAVE "); printf("%g ", (double)(A)); printf("%s", " RALLODS REMAINING."); printf("\n");
    /* BASIC: 550 GOTO 510 */
line_550:
    goto line_510;
    /* BASIC: 600 IF H<>0 THEN 1002 */
line_600:
    if (H!=0) goto line_1002;
    /* BASIC: 602 IF I<>0 THEN 1002 */
line_602:
    if (I!=0) goto line_1002;
    /* BASIC: 604 IF J<>0 THEN 1002 */
line_604:
    if (J!=0) goto line_1002;
    /* BASIC: 606 IF K<>0 THEN 1002 */
line_606:
    if (K!=0) goto line_1002;
    /* BASIC: 609 PRINT */
line_609:
    printf("\n");
    /* BASIC: 612 PRINT "GOODBYE." */
line_612:
    printf("%s", "GOODBYE."); printf("\n");
    /* BASIC: 614 PRINT "(IF YOU WISH TO CONTINUE THIS GAME AT A LATER DATE, ANSWER" */
line_614:
    printf("%s", "(IF YOU WISH TO CONTINUE THIS GAME AT A LATER DATE, ANSWER"); printf("\n");
    /* BASIC: 616 PRINT "'AGAIN' WHEN ASKED IF YOU WANT INSTRUCTIONS AT THE START" */
line_616:
    printf("%s", "'AGAIN' WHEN ASKED IF YOU WANT INSTRUCTIONS AT THE START"); printf("\n");
    /* BASIC: 617 PRINT "OF THE GAME)." */
line_617:
    printf("%s", "OF THE GAME)."); printf("\n");
    /* BASIC: 618 STOP */
line_618:
    exit(0);
    /* BASIC: 1000 GOTO 600 */
line_1000:
    goto line_600;
    /* BASIC: 1002 PRINT */
line_1002:
    printf("\n");
    /* BASIC: 1003 PRINT */
line_1003:
    printf("\n");
    /* BASIC: 1010 A=INT(A-K) */
line_1010:
    A = floor(A-K);
    /* BASIC: 1020 A4=A */
line_1020:
    A4 = A;
    /* BASIC: 1100 IF INT(I/100-B)>=0 THEN 1120 */
line_1100:
    if (floor(I/100-B)>==0) goto line_1120;
    /* BASIC: 1105 IF I/100<50 THEN 1700 */
line_1105:
    if (I/100<50) goto line_1700;
    /* BASIC: 1110 PRINT INT(B-(I/100));"COUNTRYMEN DIED OF STARVATION" */
line_1110:
    printf("%g ", (double)(floor(B-(I/100)))); printf("%s", "COUNTRYMEN DIED OF STARVATION"); printf("\n");
    /* BASIC: 1120 F1=INT(RND(1)*(2000-D)) */
line_1120:
    F1 = floor(((double)rand() / (double)RAND_MAX)*(2000-D));
    /* BASIC: 1122 IF K<25 THEN 1130 */
line_1122:
    if (K<25) goto line_1130;
    /* BASIC: 1125 F1=INT(F1/(K/25)) */
line_1125:
    F1 = floor(F1/(K/25));
    /* BASIC: 1130 IF F1<=0 THEN 1150 */
line_1130:
    if (F1<==0) goto line_1150;
    /* BASIC: 1140 PRINT F1;"COUNTRYMEN DIED OF CARBON-MONOXIDE AND DUST INHALATION" */
line_1140:
    printf("%g ", (double)(F1)); printf("%s", "COUNTRYMEN DIED OF CARBON-MONOXIDE AND DUST INHALATION"); printf("\n");
    /* BASIC: 1150 IF INT((I/100)-B)<0 THEN 1170 */
line_1150:
    if (floor((I/100)-B)<0) goto line_1170;
    /* BASIC: 1160 IF F1>0 THEN 1180 */
line_1160:
    if (F1>0) goto line_1180;
    /* BASIC: 1165 GOTO 1200 */
line_1165:
    goto line_1200;
    /* BASIC: 1170 PRINT "   YOU WERE FORCED TO SPEND";INT((F1+(B-(I/100)))*9); */
line_1170:
    printf("%s", "   YOU WERE FORCED TO SPEND"); printf("%g ", (double)(floor((F1+(B-(I/100)))*9)));
    /* BASIC: 1172 PRINT "RALLODS ON FUNERAL EXPENSES" */
line_1172:
    printf("%s", "RALLODS ON FUNERAL EXPENSES"); printf("\n");
    /* BASIC: 1174 B5=INT(F1+(B-(I/100))) */
line_1174:
    B5 = floor(F1+(B-(I/100)));
    /* BASIC: 1175 A=INT(A-((F1+(B-(I/100)))*9)) */
line_1175:
    A = floor(A-((F1+(B-(I/100)))*9));
    /* BASIC: 1176 GOTO 1185 */
line_1176:
    goto line_1185;
    /* BASIC: 1180 PRINT "   YOU WERE FORCED TO SPEND ";INT(F1*9);"RALLODS ON "; */
line_1180:
    printf("%s", "   YOU WERE FORCED TO SPEND "); printf("%g ", (double)(floor(F1*9))); printf("%s", "RALLODS ON ");
    /* BASIC: 1181 PRINT "FUNERAL EXPENSES." */
line_1181:
    printf("%s", "FUNERAL EXPENSES."); printf("\n");
    /* BASIC: 1182 B5=F1 */
line_1182:
    B5 = F1;
    /* BASIC: 1183 A=INT(A-(F1*9)) */
line_1183:
    A = floor(A-(F1*9));
    /* BASIC: 1185 IF A>=0 THEN 1194 */
line_1185:
    if (A>==0) goto line_1194;
    /* BASIC: 1187 PRINT "   INSUFFICIENT RESERVES TO COVER COST - LAND WAS SOLD" */
line_1187:
    printf("%s", "   INSUFFICIENT RESERVES TO COVER COST - LAND WAS SOLD"); printf("\n");
    /* BASIC: 1189 D=INT(D+(A/W)) */
line_1189:
    D = floor(D+(A/W));
    /* BASIC: 1190 A=0 */
line_1190:
    A = 0;
    /* BASIC: 1194 B=INT(B-B5) */
line_1194:
    B = floor(B-B5);
    /* BASIC: 1200 IF H=0 THEN 1250 */
line_1200:
    if (H==0) goto line_1250;
    /* BASIC: 1220 C1=INT(H+(RND(1)*10)-(RND(1)*20)) */
line_1220:
    C1 = floor(H+(((double)rand() / (double)RAND_MAX)*10)-(((double)rand() / (double)RAND_MAX)*20));
    /* BASIC: 1224 IF C>0 THEN 1230 */
line_1224:
    if (C>0) goto line_1230;
    /* BASIC: 1226 C1=C1+20 */
line_1226:
    C1 = C1+20;
    /* BASIC: 1230 PRINT C1;"WORKERS CAME TO THE COUNTRY AND"; */
line_1230:
    printf("%g ", (double)(C1)); printf("%s", "WORKERS CAME TO THE COUNTRY AND");
    /* BASIC: 1250 P1=INT(((I/100-B)/10)+(K/25)-((2000-D)/50)-(F1/2)) */
line_1250:
    P1 = floor(((I/100-B)/10)+(K/25)-((2000-D)/50)-(F1/2));
    /* BASIC: 1255 PRINT ABS(P1);"COUNTRYMEN "; */
line_1255:
    printf("%g ", (double)(fabs(P1))); printf("%s", "COUNTRYMEN ");
    /* BASIC: 1260 IF P1<0 THEN 1275 */
line_1260:
    if (P1<0) goto line_1275;
    /* BASIC: 1265 PRINT "CAME TO"; */
line_1265:
    printf("%s", "CAME TO");
    /* BASIC: 1270 GOTO 1280 */
line_1270:
    goto line_1280;
    /* BASIC: 1275 PRINT "LEFT"; */
line_1275:
    printf("%s", "LEFT");
    /* BASIC: 1280 PRINT " THE ISLAND." */
line_1280:
    printf("%s", " THE ISLAND."); printf("\n");
    /* BASIC: 1290 B=INT(B+P1) */
line_1290:
    B = floor(B+P1);
    /* BASIC: 1292 C=INT(C+C1) */
line_1292:
    C = floor(C+C1);
    /* BASIC: 1305 U2=INT(((2000-D)*((RND(1)+1.5)/2))) */
line_1305:
    U2 = floor(((2000-D)*((((double)rand() / (double)RAND_MAX)+1.5)/2)));
    /* BASIC: 1310 IF C=0 THEN 1324 */
line_1310:
    if (C==0) goto line_1324;
    /* BASIC: 1320 PRINT "OF ";INT(J);"SQ. MILES PLANTED,"; */
line_1320:
    printf("%s", "OF "); printf("%g ", (double)(floor(J))); printf("%s", "SQ. MILES PLANTED,");
    /* BASIC: 1324 IF J>U2 THEN 1330 */
line_1324:
    if (J>U2) goto line_1330;
    /* BASIC: 1326 U2=J */
line_1326:
    U2 = J;
    /* BASIC: 1330 PRINT " YOU HARVESTED ";INT(J-U2);"SQ. MILES OF CROPS." */
line_1330:
    printf("%s", " YOU HARVESTED "); printf("%g ", (double)(floor(J-U2))); printf("%s", "SQ. MILES OF CROPS."); printf("\n");
    /* BASIC: 1340 IF U2=0 THEN 1370 */
line_1340:
    if (U2==0) goto line_1370;
    /* BASIC: 1344 IF T1>=2 THEN 1370 */
line_1344:
    if (T1>==2) goto line_1370;
    /* BASIC: 1350 PRINT "   (DUE TO "; */
line_1350:
    printf("%s", "   (DUE TO ");
    /* BASIC: 1355 IF T1=0 THEN 1365 */
line_1355:
    if (T1==0) goto line_1365;
    /* BASIC: 1360 PRINT "INCREASED "; */
line_1360:
    printf("%s", "INCREASED ");
    /* BASIC: 1365 PRINT "AIR AND WATER POLLUTION FROM FOREIGN INDUSTRY.)" */
line_1365:
    printf("%s", "AIR AND WATER POLLUTION FROM FOREIGN INDUSTRY.)"); printf("\n");
    /* BASIC: 1370 Q=INT((J-U2)*(W/2)) */
line_1370:
    Q = floor((J-U2)*(W/2));
    /* BASIC: 1380 PRINT "MAKING";INT(Q);"RALLODS." */
line_1380:
    printf("%s", "MAKING"); printf("%g ", (double)(floor(Q))); printf("%s", "RALLODS."); printf("\n");
    /* BASIC: 1390 A=INT(A+Q) */
line_1390:
    A = floor(A+Q);
    /* BASIC: 1400 V1=INT(((B-P1)*22)+(RND(1)*500)) */
line_1400:
    V1 = floor(((B-P1)*22)+(((double)rand() / (double)RAND_MAX)*500));
    /* BASIC: 1405 V2=INT((2000-D)*15) */
line_1405:
    V2 = floor((2000-D)*15);
    /* BASIC: 1410 PRINT " YOU MADE";ABS(INT(V1-V2));"RALLODS FROM TOURIST TRADE." */
line_1410:
    printf("%s", " YOU MADE"); printf("%g ", (double)(fabs(floor(V1-V2)))); printf("%s", "RALLODS FROM TOURIST TRADE."); printf("\n");
    /* BASIC: 1420 IF V2=0 THEN 1450 */
line_1420:
    if (V2==0) goto line_1450;
    /* BASIC: 1425 IF V1-V2>=V3 THEN 1450 */
line_1425:
    if (V1-V2>==V3) goto line_1450;
    /* BASIC: 1430 PRINT "   DECREASE BECAUSE "; */
line_1430:
    printf("%s", "   DECREASE BECAUSE ");
    /* BASIC: 1435 G1=10*RND(1) */
line_1435:
    G1 = 10*((double)rand() / (double)RAND_MAX);
    /* BASIC: 1440 IF G1<=2 THEN 1460 */
line_1440:
    if (G1<==2) goto line_1460;
    /* BASIC: 1442 IF G1<=4 THEN 1465 */
line_1442:
    if (G1<==4) goto line_1465;
    /* BASIC: 1444 IF G1<=6 THEN 1470 */
line_1444:
    if (G1<==6) goto line_1470;
    /* BASIC: 1446 IF G1<=8 THEN 1475 */
line_1446:
    if (G1<==8) goto line_1475;
    /* BASIC: 1448 IF G1<=10 THEN 1480 */
line_1448:
    if (G1<==10) goto line_1480;
    /* BASIC: 1450 V3=INT(A+V3) */
line_1450:
    V3 = floor(A+V3);
    /* BASIC: 1451 A=INT(A+V3) */
line_1451:
    A = floor(A+V3);
    /* BASIC: 1452 GOTO 1500 */
line_1452:
    goto line_1500;
    /* BASIC: 1460 PRINT "FISH POPULATION HAS DWINDLED DUE TO WATER POLLUTION." */
line_1460:
    printf("%s", "FISH POPULATION HAS DWINDLED DUE TO WATER POLLUTION."); printf("\n");
    /* BASIC: 1462 GOTO 1450 */
line_1462:
    goto line_1450;
    /* BASIC: 1465 PRINT "AIR POLLUTION IS KILLING GAME BIRD POPULATION." */
line_1465:
    printf("%s", "AIR POLLUTION IS KILLING GAME BIRD POPULATION."); printf("\n");
    /* BASIC: 1467 GOTO 1450 */
line_1467:
    goto line_1450;
    /* BASIC: 1470 PRINT "MINERAL BATHS ARE BEING RUINED BY WATER POLLUTION." */
line_1470:
    printf("%s", "MINERAL BATHS ARE BEING RUINED BY WATER POLLUTION."); printf("\n");
    /* BASIC: 1472 GOTO 1450 */
line_1472:
    goto line_1450;
    /* BASIC: 1475 PRINT "UNPLEASANT SMOG IS DISCOURAGING SUN BATHERS." */
line_1475:
    printf("%s", "UNPLEASANT SMOG IS DISCOURAGING SUN BATHERS."); printf("\n");
    /* BASIC: 1477 GOTO 1450 */
line_1477:
    goto line_1450;
    /* BASIC: 1480 PRINT "HOTELS ARE LOOKING SHABBY DUE TO SMOG GRIT." */
line_1480:
    printf("%s", "HOTELS ARE LOOKING SHABBY DUE TO SMOG GRIT."); printf("\n");
    /* BASIC: 1482 GOTO 1450 */
line_1482:
    goto line_1450;
    /* BASIC: 1500 IF B5>200 THEN 1600 */
line_1500:
    if (B5>200) goto line_1600;
    /* BASIC: 1505 IF B<343 THEN 1700 */
line_1505:
    if (B<343) goto line_1700;
    /* BASIC: 1510 IF (A4/100)>5 THEN 1800 */
line_1510:
    if ((A4/100)>5) goto line_1800;
    /* BASIC: 1515 IF C>B THEN 1550 */
line_1515:
    if (C>B) goto line_1550;
    /* BASIC: 1520 IF N5-1=X5 THEN 1900 */
line_1520:
    if (N5-1==X5) goto line_1900;
    /* BASIC: 1545 GOTO 2000 */
line_1545:
    goto line_2000;
    /* BASIC: 1550 PRINT */
line_1550:
    printf("\n");
    /* BASIC: 1552 PRINT */
line_1552:
    printf("\n");
    /* BASIC: 1560 PRINT "THE NUMBER OF FOREIGN WORKERS HAS EXCEEDED THE NUMBER" */
line_1560:
    printf("%s", "THE NUMBER OF FOREIGN WORKERS HAS EXCEEDED THE NUMBER"); printf("\n");
    /* BASIC: 1562 PRINT "OF COUNTRYMEN. AS A MINORITY, THEY HAVE REVOLTED AND" */
line_1562:
    printf("%s", "OF COUNTRYMEN. AS A MINORITY, THEY HAVE REVOLTED AND"); printf("\n");
    /* BASIC: 1564 PRINT "TAKEN OVER THE COUNTRY." */
line_1564:
    printf("%s", "TAKEN OVER THE COUNTRY."); printf("\n");
    /* BASIC: 1570 IF RND(1)<=.5 THEN 1580 */
line_1570:
    if (((double)rand() / (double)RAND_MAX)<==.5) goto line_1580;
    /* BASIC: 1574 PRINT "YOU HAVE BEEN THROWN OUT OF OFFICE AND ARE NOW" */
line_1574:
    printf("%s", "YOU HAVE BEEN THROWN OUT OF OFFICE AND ARE NOW"); printf("\n");
    /* BASIC: 1576 PRINT "RESIDING IN PRISON." */
line_1576:
    printf("%s", "RESIDING IN PRISON."); printf("\n");
    /* BASIC: 1578 GOTO 1590 */
line_1578:
    goto line_1590;
    /* BASIC: 1580 PRINT "YOU HAVE BEEN ASSASSINATED." */
line_1580:
    printf("%s", "YOU HAVE BEEN ASSASSINATED."); printf("\n");
    /* BASIC: 1590 PRINT */
line_1590:
    printf("\n");
    /* BASIC: 1592 PRINT */
line_1592:
    printf("\n");
    /* BASIC: 1596 STOP */
line_1596:
    exit(0);
    /* BASIC: 1600 PRINT */
line_1600:
    printf("\n");
    /* BASIC: 1602 PRINT */
line_1602:
    printf("\n");
    /* BASIC: 1610 PRINT B5;"COUNTRYMEN DIED IN ONE YEAR!!!!!" */
line_1610:
    printf("%g ", (double)(B5)); printf("%s", "COUNTRYMEN DIED IN ONE YEAR!!!!!"); printf("\n");
    /* BASIC: 1615 PRINT "DUE TO THIS EXTREME MISMANAGEMENT, YOU HAVE NOT ONLY" */
line_1615:
    printf("%s", "DUE TO THIS EXTREME MISMANAGEMENT, YOU HAVE NOT ONLY"); printf("\n");
    /* BASIC: 1620 PRINT "BEEN IMPEACHED AND THROWN OUT OF OFFICE, BUT YOU" */
line_1620:
    printf("%s", "BEEN IMPEACHED AND THROWN OUT OF OFFICE, BUT YOU"); printf("\n");
    /* BASIC: 1622 M6=INT(RND(1)*10) */
line_1622:
    M6 = floor(((double)rand() / (double)RAND_MAX)*10);
    /* BASIC: 1625 IF M6<=3 THEN 1670 */
line_1625:
    if (M6<==3) goto line_1670;
    /* BASIC: 1630 IF M6<=6 THEN 1680 */
line_1630:
    if (M6<==6) goto line_1680;
    /* BASIC: 1635 IF M6<=10 THEN 1690 */
line_1635:
    if (M6<==10) goto line_1690;
    /* BASIC: 1670 PRINT "ALSO HAD YOUR LEFT EYE GOUGED OUT!" */
line_1670:
    printf("%s", "ALSO HAD YOUR LEFT EYE GOUGED OUT!"); printf("\n");
    /* BASIC: 1672 GOTO 1590 */
line_1672:
    goto line_1590;
    /* BASIC: 1680 PRINT "HAVE ALSO GAINED A VERY BAD REPUTATION." */
line_1680:
    printf("%s", "HAVE ALSO GAINED A VERY BAD REPUTATION."); printf("\n");
    /* BASIC: 1682 GOTO 1590 */
line_1682:
    goto line_1590;
    /* BASIC: 1690 PRINT "HAVE ALSO BEEN DECLARED NATIONAL FINK." */
line_1690:
    printf("%s", "HAVE ALSO BEEN DECLARED NATIONAL FINK."); printf("\n");
    /* BASIC: 1692 GOTO 1590 */
line_1692:
    goto line_1590;
    /* BASIC: 1700 PRINT */
line_1700:
    printf("\n");
    /* BASIC: 1702 PRINT */
line_1702:
    printf("\n");
    /* BASIC: 1710 PRINT "OVER ONE THIRD OF THE POPULTATION HAS DIED SINCE YOU" */
line_1710:
    printf("%s", "OVER ONE THIRD OF THE POPULTATION HAS DIED SINCE YOU"); printf("\n");
    /* BASIC: 1715 PRINT "WERE ELECTED TO OFFICE. THE PEOPLE (REMAINING)" */
line_1715:
    printf("%s", "WERE ELECTED TO OFFICE. THE PEOPLE (REMAINING)"); printf("\n");
    /* BASIC: 1720 PRINT "HATE YOUR GUTS." */
line_1720:
    printf("%s", "HATE YOUR GUTS."); printf("\n");
    /* BASIC: 1730 GOTO 1570 */
line_1730:
    goto line_1570;
    /* BASIC: 1800 IF B5-F1<2 THEN 1515 */
line_1800:
    if (B5-F1<2) goto line_1515;
    /* BASIC: 1807 PRINT */
line_1807:
    printf("\n");
    /* BASIC: 1815 PRINT "MONEY WAS LEFT OVER IN THE TREASURY WHICH YOU DID" */
line_1815:
    printf("%s", "MONEY WAS LEFT OVER IN THE TREASURY WHICH YOU DID"); printf("\n");
    /* BASIC: 1820 PRINT "NOT SPEND. AS A RESULT, SOME OF YOUR COUNTRYMEN DIED" */
line_1820:
    printf("%s", "NOT SPEND. AS A RESULT, SOME OF YOUR COUNTRYMEN DIED"); printf("\n");
    /* BASIC: 1825 PRINT "OF STARVATION. THE PUBLIC IS ENRAGED AND YOU HAVE" */
line_1825:
    printf("%s", "OF STARVATION. THE PUBLIC IS ENRAGED AND YOU HAVE"); printf("\n");
    /* BASIC: 1830 PRINT "BEEN FORCED TO EITHER RESIGN OR COMMIT SUICIDE." */
line_1830:
    printf("%s", "BEEN FORCED TO EITHER RESIGN OR COMMIT SUICIDE."); printf("\n");
    /* BASIC: 1835 PRINT "THE CHOICE IS YOURS." */
line_1835:
    printf("%s", "THE CHOICE IS YOURS."); printf("\n");
    /* BASIC: 1840 PRINT "IF YOU CHOOSE THE LATTER, PLEASE TURN OFF YOUR COMPUTER" */
line_1840:
    printf("%s", "IF YOU CHOOSE THE LATTER, PLEASE TURN OFF YOUR COMPUTER"); printf("\n");
    /* BASIC: 1845 PRINT "BEFORE PROCEEDING." */
line_1845:
    printf("%s", "BEFORE PROCEEDING."); printf("\n");
    /* BASIC: 1850 GOTO 1590 */
line_1850:
    goto line_1590;
    /* BASIC: 1900 PRINT */
line_1900:
    printf("\n");
    /* BASIC: 1902 PRINT */
line_1902:
    printf("\n");
    /* BASIC: 1920 PRINT "CONGRATULATIONS!!!!!!!!!!!!!!!!!!" */
line_1920:
    printf("%s", "CONGRATULATIONS!!!!!!!!!!!!!!!!!!"); printf("\n");
    /* BASIC: 1925 PRINT "YOU HAVE SUCCESFULLY COMPLETED YOUR";N5;"YEAR TERM" */
line_1925:
    printf("%s", "YOU HAVE SUCCESFULLY COMPLETED YOUR"); printf("%g ", (double)(N5)); printf("%s", "YEAR TERM"); printf("\n");
    /* BASIC: 1930 PRINT "OF OFFICE. YOU WERE, OF COURSE, EXTREMELY LUCKY, BUT" */
line_1930:
    printf("%s", "OF OFFICE. YOU WERE, OF COURSE, EXTREMELY LUCKY, BUT"); printf("\n");
    /* BASIC: 1935 PRINT "NEVERTHELESS, IT'S QUITE AN ACHIEVEMENT. GOODBYE AND GOOD" */
line_1935:
    printf("%s", "NEVERTHELESS, IT'S QUITE AN ACHIEVEMENT. GOODBYE AND GOOD"); printf("\n");
    /* BASIC: 1940 PRINT "LUCK - YOU'LL PROBABLY NEED IT IF YOU'RE THE TYPE THAT" */
line_1940:
    printf("%s", "LUCK - YOU'LL PROBABLY NEED IT IF YOU'RE THE TYPE THAT"); printf("\n");
    /* BASIC: 1945 PRINT "PLAYS THIS GAME." */
line_1945:
    printf("%s", "PLAYS THIS GAME."); printf("\n");
    /* BASIC: 1950 GOTO 1590 */
line_1950:
    goto line_1590;
    /* BASIC: 1960 PRINT "HOW MANY YEARS HAD YOU BEEN IN OFFICE WHEN INTERRUPTED"; */
line_1960:
    printf("%s", "HOW MANY YEARS HAD YOU BEEN IN OFFICE WHEN INTERRUPTED");
    /* BASIC: 1961 INPUT X5 */
line_1961:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &X5);
    /* BASIC: 1962 IF X5<0 THEN 1590 */
line_1962:
    if (X5<0) goto line_1590;
    /* BASIC: 1963 IF X5<8 THEN 1969 */
line_1963:
    if (X5<8) goto line_1969;
    /* BASIC: 1965 PRINT "   COME ON, YOUR TERM IN OFFICE IS ONLY";N5;"YEARS." */
line_1965:
    printf("%s", "   COME ON, YOUR TERM IN OFFICE IS ONLY"); printf("%g ", (double)(N5)); printf("%s", "YEARS."); printf("\n");
    /* BASIC: 1967 GOTO 1960 */
line_1967:
    goto line_1960;
    /* BASIC: 1969 PRINT "HOW MUCH DID YOU HAVE IN THE TREASURY"; */
line_1969:
    printf("%s", "HOW MUCH DID YOU HAVE IN THE TREASURY");
    /* BASIC: 1970 INPUT A */
line_1970:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &A);
    /* BASIC: 1971 IF A<0 THEN 1590 */
line_1971:
    if (A<0) goto line_1590;
    /* BASIC: 1975 PRINT "HOW MANY COUNTRYMEN"; */
line_1975:
    printf("%s", "HOW MANY COUNTRYMEN");
    /* BASIC: 1976 INPUT B */
line_1976:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &B);
    /* BASIC: 1977 IF B<0 THEN 1590 */
line_1977:
    if (B<0) goto line_1590;
    /* BASIC: 1980 PRINT "HOW MANY WORKERS"; */
line_1980:
    printf("%s", "HOW MANY WORKERS");
    /* BASIC: 1981 INPUT C */
line_1981:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &C);
    /* BASIC: 1982 IF C<0 THEN 1590 */
line_1982:
    if (C<0) goto line_1590;
    /* BASIC: 1990 PRINT "HOW MANY SQUARE MILES OF LAND"; */
line_1990:
    printf("%s", "HOW MANY SQUARE MILES OF LAND");
    /* BASIC: 1991 INPUT D */
line_1991:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &D);
    /* BASIC: 1992 IF D<0 THEN 1590 */
line_1992:
    if (D<0) goto line_1590;
    /* BASIC: 1993 IF D>2000 THEN 1996 */
line_1993:
    if (D>2000) goto line_1996;
    /* BASIC: 1994 IF D>1000 THEN 100 */
line_1994:
    if (D>1000) goto line_100;
    /* BASIC: 1996 PRINT "   COME ON, YOU STARTED WITH 1000 SQ. MILES OF FARM LAND" */
line_1996:
    printf("%s", "   COME ON, YOU STARTED WITH 1000 SQ. MILES OF FARM LAND"); printf("\n");
    /* BASIC: 1997 PRINT "   AND 10,000 SQ. MILES OF FOREST LAND." */
line_1997:
    printf("%s", "   AND 10,000 SQ. MILES OF FOREST LAND."); printf("\n");
    /* BASIC: 1998 GOTO 1990 */
line_1998:
    goto line_1990;
    /* BASIC: 2000 X5=X5+1 */
line_2000:
    X5 = X5+1;
    /* BASIC: 2020 B5=0 */
line_2020:
    B5 = 0;
    /* BASIC: 2040 GOTO 100 */
line_2040:
    goto line_100;
    /* BASIC: 2046 END */
line_2046:
    exit(0);

    return 0;
}
