/*
 * Transpiled from basketball.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double USE, INCORRECT, MAKES, SHOT, ZONE, P, GAME, PASSED, PRESS, NEW, TYPE, ANSWER, JUMP, PERIOD, JERSEY, THE, ON, LEFT, STARTING, POINTS, CHANGE, BASKETBALL, D, UP, LOSES, IT, SHOTS, BLOCKED, PLAYMAKER, T, MINUTES, FOLLOWS, IN, FT, BY, ALLIGNMENT, MORRISTOWN, CHARGING, TARGET, PLAYER, Z1, TEAMS, OFF, FOUL, DARTMOUTH, CENTER, TIME, BACK, GUARD, DEFENSE, RIM, SECOND, FINAL, DEFENSIVE, YOUR, MAN, REGULATION, LAY, CALL, MINUTE, IS, OVERTIME, OF, Z, SCORE, SET, COLLEGE, BEGIN, SAME, S, WILL, MISSES, CREATIVE, RETYPE, YOU, AS, MISSED, EASY, ONE, CAPTAIN, BOTH, STOLEN, CONTROLS, GOOD, OPPONENT, OFFENSIVE, CHOOSE, SHORT, CONTROLLED, BE, SHOOTER, LAYUP, REBOUND, LONG, TWO, NONE, COMPUTING, JUST, BALL, HALF, TAP, FOULED, AT, PASS, FIRST, O, THIS;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 5 PRINT TAB(31);"BASKETBALL" */
line_5:
    { int _t; for(_t=0; _t<31; _t++) printf(" "); } printf("%s", "BASKETBALL"); printf("\n");
    /* BASIC: 7 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_7:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 8 PRINT:PRINT:PRINT */
line_8:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 10 PRINT "THIS IS DARTMOUTH COLLEGE BASKETBALL.  YOU WILL BE DARTMOUTH" */
line_10:
    printf("%s", "THIS IS DARTMOUTH COLLEGE BASKETBALL.  YOU WILL BE DARTMOUTH"); printf("\n");
    /* BASIC: 20 PRINT " CAPTAIN AND PLAYMAKER.  CALL SHOTS AS FOLLOWS:  1. LONG" */
line_20:
    printf("%s", " CAPTAIN AND PLAYMAKER.  CALL SHOTS AS FOLLOWS:  1. LONG"); printf("\n");
    /* BASIC: 30 PRINT " (30 FT.) JUMP SHOT; 2. SHORT (15 FT.) JUMP SHOT; 3. LAY" */
line_30:
    printf("%s", " (30 FT.) JUMP SHOT; 2. SHORT (15 FT.) JUMP SHOT; 3. LAY"); printf("\n");
    /* BASIC: 40 PRINT " UP; 4. SET SHOT." */
line_40:
    printf("%s", " UP; 4. SET SHOT."); printf("\n");
    /* BASIC: 60 PRINT "BOTH TEAMS WILL USE THE SAME DEFENSE.  CALL DEFENSE AS" */
line_60:
    printf("%s", "BOTH TEAMS WILL USE THE SAME DEFENSE.  CALL DEFENSE AS"); printf("\n");
    /* BASIC: 70 PRINT "FOLLOWS:  6. PRESS; 6.5 MAN-TO MAN; 7. ZONE; 7.5 NONE." */
line_70:
    printf("%s", "FOLLOWS:  6. PRESS; 6.5 MAN-TO MAN; 7. ZONE; 7.5 NONE."); printf("\n");
    /* BASIC: 72 PRINT "TO CHANGE DEFENSE, JUST TYPE 0 AS YOUR NEXT SHOT." */
line_72:
    printf("%s", "TO CHANGE DEFENSE, JUST TYPE 0 AS YOUR NEXT SHOT."); printf("\n");
    /* BASIC: 76 INPUT "YOUR STARTING DEFENSE WILL BE";D:IF D<6 THEN 2010 */
line_76:
    printf("%s", "YOUR STARTING DEFENSE WILL BE"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &D);
    if (D<6) goto line_2010;
    /* BASIC: 79 PRINT */
line_79:
    printf("\n");
    /* BASIC: 80 INPUT "CHOOSE YOUR OPPONENT";O$ */
line_80:
    printf("%s", "CHOOSE YOUR OPPONENT"); fgets(O_str, sizeof(O_str), stdin); O_str[strcspn(O_str, "\n")] = 0;
    /* BASIC: 370 PRINT "CENTER JUMP" */
line_370:
    printf("%s", "CENTER JUMP"); printf("\n");
    /* BASIC: 390 IF RND(1)> 3/5 THEN 420 */
line_390:
    if (((double)rand() / (double)RAND_MAX)> 3/5) goto line_420;
    /* BASIC: 400 PRINT O$;" CONTROLS THE TAP." */
line_400:
    printf("%s", O_str); printf("%s", " CONTROLS THE TAP."); printf("\n");
    /* BASIC: 410 GOTO 3000 */
line_410:
    goto line_3000;
    /* BASIC: 420 PRINT "DARTMOUTH CONTROLS THE TAP." */
line_420:
    printf("%s", "DARTMOUTH CONTROLS THE TAP."); printf("\n");
    /* BASIC: 425 PRINT */
line_425:
    printf("\n");
    /* BASIC: 430 INPUT "YOUR SHOT";Z */
line_430:
    printf("%s", "YOUR SHOT"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &Z);
    /* BASIC: 440 P=0 */
line_440:
    P = 0;
    /* BASIC: 445 IF Z<>INT(Z) THEN 455 */
line_445:
    if (Z!=floor(Z)) goto line_455;
    /* BASIC: 446 IF Z<0 OR Z>4 THEN 455 */
line_446:
    if (Z<0 || Z>4) goto line_455;
    /* BASIC: 447 GOTO 460 */
line_447:
    goto line_460;
    /* BASIC: 455 PRINT "INCORRECT ANSWER.  RETYPE IT. ";:GOTO 430 */
line_455:
    printf("%s", "INCORRECT ANSWER.  RETYPE IT. ");
    goto line_430;
    /* BASIC: 460 IF RND(1)<.5 THEN 1000 */
line_460:
    if (((double)rand() / (double)RAND_MAX)<.5) goto line_1000;
    /* BASIC: 480 IF T<100 THEN 1000 */
line_480:
    if (T<100) goto line_1000;
    /* BASIC: 490 PRINT */
line_490:
    printf("\n");
    /* BASIC: 491 IF S(1)<>S(0) THEN 510 */
line_491:
    if (S(1)!=S(0)) goto line_510;
    /* BASIC: 492 PRINT:PRINT "   ***** END OF SECOND HALF *****":PRINT */
line_492:
    printf("\n");
    printf("%s", "   ***** END OF SECOND HALF *****"); printf("\n");
    printf("\n");
    /* BASIC: 493 PRINT "SCORE AT END OF REGULATION TIME:" */
line_493:
    printf("%s", "SCORE AT END OF REGULATION TIME:"); printf("\n");
    /* BASIC: 494 PRINT "        DARTMOUTH:";S(1);"  ";O$;":";S(0) */
line_494:
    printf("%s", "        DARTMOUTH:"); printf("%g ", (double)(S(1))); printf("%s", "  "); printf("%s", O_str); printf("%s", ":"); printf("%g ", (double)(S(0))); printf("\n");
    /* BASIC: 495 PRINT */
line_495:
    printf("\n");
    /* BASIC: 496 PRINT "BEGIN TWO MINUTE OVERTIME PERIOD" */
line_496:
    printf("%s", "BEGIN TWO MINUTE OVERTIME PERIOD"); printf("\n");
    /* BASIC: 499 T=93 */
line_499:
    T = 93;
    /* BASIC: 500 GOTO 370 */
line_500:
    goto line_370;
    /* BASIC: 510 PRINT "   ***** END OF GAME *****" */
line_510:
    printf("%s", "   ***** END OF GAME *****"); printf("\n");
    /* BASIC: 515 PRINT "FINAL SCORE: DARTMOUTH:";S(1);"  ";O$;":";S(0) */
line_515:
    printf("%s", "FINAL SCORE: DARTMOUTH:"); printf("%g ", (double)(S(1))); printf("%s", "  "); printf("%s", O_str); printf("%s", ":"); printf("%g ", (double)(S(0))); printf("\n");
    /* BASIC: 520 STOP */
line_520:
    exit(0);
    /* BASIC: 600 PRINT */
line_600:
    printf("\n");
    /* BASIC: 610 PRINT "   *** TWO MINUTES LEFT IN THE GAME ***" */
line_610:
    printf("%s", "   *** TWO MINUTES LEFT IN THE GAME ***"); printf("\n");
    /* BASIC: 620 PRINT */
line_620:
    printf("\n");
    /* BASIC: 630 RETURN */
line_630:
    /* TODO: RETURN */
    /* BASIC: 1000 ON Z GOTO 1040,1040 */
line_1000:
    /* UNTRANSLATED: ON Z GOTO 1040,1040 */
    /* BASIC: 1030 GOTO 1300 */
line_1030:
    goto line_1300;
    /* BASIC: 1040 T=T+1 */
line_1040:
    T = T+1;
    /* BASIC: 1041 IF T=50 THEN 8000 */
line_1041:
    if (T==50) goto line_8000;
    /* BASIC: 1042 IF T=92 THEN 1046 */
line_1042:
    if (T==92) goto line_1046;
    /* BASIC: 1043 GOTO 1050 */
line_1043:
    goto line_1050;
    /* BASIC: 1046 GOSUB 600 */
line_1046:
    /* TODO: GOSUB 600 */
    /* BASIC: 1050 PRINT "JUMP SHOT" */
line_1050:
    printf("%s", "JUMP SHOT"); printf("\n");
    /* BASIC: 1060 IF RND(1)>.341*D/8 THEN 1090 */
line_1060:
    if (((double)rand() / (double)RAND_MAX)>.341*D/8) goto line_1090;
    /* BASIC: 1070 PRINT "SHOT IS GOOD." */
line_1070:
    printf("%s", "SHOT IS GOOD."); printf("\n");
    /* BASIC: 1075 GOSUB 7000 */
line_1075:
    /* TODO: GOSUB 7000 */
    /* BASIC: 1085 GOTO 3000 */
line_1085:
    goto line_3000;
    /* BASIC: 1090 IF RND(1)>.682*D/8 THEN 1200 */
line_1090:
    if (((double)rand() / (double)RAND_MAX)>.682*D/8) goto line_1200;
    /* BASIC: 1100 PRINT "SHOT IS OFF TARGET." */
line_1100:
    printf("%s", "SHOT IS OFF TARGET."); printf("\n");
    /* BASIC: 1105 IF D/6*RND(1)>.45 THEN 1130 */
line_1105:
    if (D/6*((double)rand() / (double)RAND_MAX)>.45) goto line_1130;
    /* BASIC: 1110 PRINT "DARTMOUTH CONTROLS THE REBOUND." */
line_1110:
    printf("%s", "DARTMOUTH CONTROLS THE REBOUND."); printf("\n");
    /* BASIC: 1120 GOTO 1145 */
line_1120:
    goto line_1145;
    /* BASIC: 1130 PRINT "REBOUND TO ";O$ */
line_1130:
    printf("%s", "REBOUND TO "); printf("%s", O_str); printf("\n");
    /* BASIC: 1140 GOTO 3000 */
line_1140:
    goto line_3000;
    /* BASIC: 1145 IF RND(1)>.4 THEN 1158 */
line_1145:
    if (((double)rand() / (double)RAND_MAX)>.4) goto line_1158;
    /* BASIC: 1150 GOTO 1300 */
line_1150:
    goto line_1300;
    /* BASIC: 1158 IF D=6 THEN 5100 */
line_1158:
    if (D==6) goto line_5100;
    /* BASIC: 1160 PRINT "BALL PASSED BACK TO YOU. "; */
line_1160:
    printf("%s", "BALL PASSED BACK TO YOU. ");
    /* BASIC: 1170 GOTO 430 */
line_1170:
    goto line_430;
    /* BASIC: 1180 IF RND(1)>.9 THEN 1190 */
line_1180:
    if (((double)rand() / (double)RAND_MAX)>.9) goto line_1190;
    /* BASIC: 1185 PRINT "PLAYER FOULED, TWO SHOTS." */
line_1185:
    printf("%s", "PLAYER FOULED, TWO SHOTS."); printf("\n");
    /* BASIC: 1187 GOSUB 4000 */
line_1187:
    /* TODO: GOSUB 4000 */
    /* BASIC: 1188 GOTO 3000 */
line_1188:
    goto line_3000;
    /* BASIC: 1190 PRINT "BALL STOLEN. ";O$;"'S BALL." */
line_1190:
    printf("%s", "BALL STOLEN. "); printf("%s", O_str); printf("%s", "'S BALL."); printf("\n");
    /* BASIC: 1195 GOTO 3000 */
line_1195:
    goto line_3000;
    /* BASIC: 1200 IF RND(1)>.782*D/8 THEN 1250 */
line_1200:
    if (((double)rand() / (double)RAND_MAX)>.782*D/8) goto line_1250;
    /* BASIC: 1210 PRINT "SHOT IS BLOCKED.  BALL CONTROLLED BY "; */
line_1210:
    printf("%s", "SHOT IS BLOCKED.  BALL CONTROLLED BY ");
    /* BASIC: 1230 IF RND(1)>.5 THEN 1242 */
line_1230:
    if (((double)rand() / (double)RAND_MAX)>.5) goto line_1242;
    /* BASIC: 1235 PRINT "DARTMOUTH." */
line_1235:
    printf("%s", "DARTMOUTH."); printf("\n");
    /* BASIC: 1240 GOTO 430 */
line_1240:
    goto line_430;
    /* BASIC: 1242 PRINT O$;"." */
line_1242:
    printf("%s", O_str); printf("%s", "."); printf("\n");
    /* BASIC: 1245 GOTO 3000 */
line_1245:
    goto line_3000;
    /* BASIC: 1250 IF RND(1)>.843*D/8 THEN 1270 */
line_1250:
    if (((double)rand() / (double)RAND_MAX)>.843*D/8) goto line_1270;
    /* BASIC: 1255 PRINT "SHOOTER IS FOULED.  TWO SHOTS." */
line_1255:
    printf("%s", "SHOOTER IS FOULED.  TWO SHOTS."); printf("\n");
    /* BASIC: 1260 GOSUB 4000 */
line_1260:
    /* TODO: GOSUB 4000 */
    /* BASIC: 1265 GOTO 3000 */
line_1265:
    goto line_3000;
    /* BASIC: 1270 PRINT "CHARGING FOUL.  DARTMOUTH LOSES BALL." */
line_1270:
    printf("%s", "CHARGING FOUL.  DARTMOUTH LOSES BALL."); printf("\n");
    /* BASIC: 1280 GOTO 3000 */
line_1280:
    goto line_3000;
    /* BASIC: 1300 T=T+1 */
line_1300:
    T = T+1;
    /* BASIC: 1301 IF T=50 THEN 8000 */
line_1301:
    if (T==50) goto line_8000;
    /* BASIC: 1302 IF T=92 THEN 1304 */
line_1302:
    if (T==92) goto line_1304;
    /* BASIC: 1303 GOTO 1305 */
line_1303:
    goto line_1305;
    /* BASIC: 1304 GOSUB 600 */
line_1304:
    /* TODO: GOSUB 600 */
    /* BASIC: 1305 IF Z=0 THEN 2010 */
line_1305:
    if (Z==0) goto line_2010;
    /* BASIC: 1310 IF Z>3 THEN 1700 */
line_1310:
    if (Z>3) goto line_1700;
    /* BASIC: 1320 PRINT "LAY UP." */
line_1320:
    printf("%s", "LAY UP."); printf("\n");
    /* BASIC: 1330 IF 7/D*RND(1)>.4 THEN 1360 */
line_1330:
    if (7/D*((double)rand() / (double)RAND_MAX)>.4) goto line_1360;
    /* BASIC: 1340 PRINT "SHOT IS GOOD.  TWO POINTS." */
line_1340:
    printf("%s", "SHOT IS GOOD.  TWO POINTS."); printf("\n");
    /* BASIC: 1345 GOSUB 7000 */
line_1345:
    /* TODO: GOSUB 7000 */
    /* BASIC: 1355 GOTO 3000 */
line_1355:
    goto line_3000;
    /* BASIC: 1360 IF 7/D*RND(1)>.7 THEN 1500 */
line_1360:
    if (7/D*((double)rand() / (double)RAND_MAX)>.7) goto line_1500;
    /* BASIC: 1370 PRINT "SHOT IS OFF THE RIM." */
line_1370:
    printf("%s", "SHOT IS OFF THE RIM."); printf("\n");
    /* BASIC: 1380 IF RND(1)>2/3 THEN 1415 */
line_1380:
    if (((double)rand() / (double)RAND_MAX)>2/3) goto line_1415;
    /* BASIC: 1390 PRINT O$;" CONTROLS THE REBOUND." */
line_1390:
    printf("%s", O_str); printf("%s", " CONTROLS THE REBOUND."); printf("\n");
    /* BASIC: 1400 GOTO 3000 */
line_1400:
    goto line_3000;
    /* BASIC: 1415 PRINT "DARTMOUTH CONTROLS THE REBOUND." */
line_1415:
    printf("%s", "DARTMOUTH CONTROLS THE REBOUND."); printf("\n");
    /* BASIC: 1420 IF RND(1)>.4 THEN 1440 */
line_1420:
    if (((double)rand() / (double)RAND_MAX)>.4) goto line_1440;
    /* BASIC: 1430 GOTO 1300 */
line_1430:
    goto line_1300;
    /* BASIC: 1440 PRINT "BALL PASSED BACK TO YOU."; */
line_1440:
    printf("%s", "BALL PASSED BACK TO YOU.");
    /* BASIC: 1450 GOTO 430 */
line_1450:
    goto line_430;
    /* BASIC: 1500 IF 7/D*RND(1)>.875 THEN 1600 */
line_1500:
    if (7/D*((double)rand() / (double)RAND_MAX)>.875) goto line_1600;
    /* BASIC: 1510 PRINT "SHOOTER FOULED.  TWO SHOTS." */
line_1510:
    printf("%s", "SHOOTER FOULED.  TWO SHOTS."); printf("\n");
    /* BASIC: 1520 GOSUB 4000 */
line_1520:
    /* TODO: GOSUB 4000 */
    /* BASIC: 1530 GOTO 3000 */
line_1530:
    goto line_3000;
    /* BASIC: 1600 IF 7/D*RND(1)>.925 THEN 1630 */
line_1600:
    if (7/D*((double)rand() / (double)RAND_MAX)>.925) goto line_1630;
    /* BASIC: 1610 PRINT "SHOT BLOCKED. ";O$;"'S BALL." */
line_1610:
    printf("%s", "SHOT BLOCKED. "); printf("%s", O_str); printf("%s", "'S BALL."); printf("\n");
    /* BASIC: 1620 GOTO 3000 */
line_1620:
    goto line_3000;
    /* BASIC: 1630 PRINT "CHARGING FOUL.  DARTMOUTH LOSES THE BALL." */
line_1630:
    printf("%s", "CHARGING FOUL.  DARTMOUTH LOSES THE BALL."); printf("\n");
    /* BASIC: 1640 GOTO 3000 */
line_1640:
    goto line_3000;
    /* BASIC: 1700 PRINT "SET SHOT." */
line_1700:
    printf("%s", "SET SHOT."); printf("\n");
    /* BASIC: 1710 GOTO 1330 */
line_1710:
    goto line_1330;
    /* BASIC: 2010 INPUT "YOUR NEW DEFENSIVE ALLIGNMENT IS";D */
line_2010:
    printf("%s", "YOUR NEW DEFENSIVE ALLIGNMENT IS"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &D);
    /* BASIC: 2030 IF D<6 THEN 2010 */
line_2030:
    if (D<6) goto line_2010;
    /* BASIC: 2040 GOTO 425 */
line_2040:
    goto line_425;
    /* BASIC: 3000 P=1 */
line_3000:
    P = 1;
    /* BASIC: 3005 T=T+1 */
line_3005:
    T = T+1;
    /* BASIC: 3008 IF T=50 THEN 8000 */
line_3008:
    if (T==50) goto line_8000;
    /* BASIC: 3012 GOTO 3018 */
line_3012:
    goto line_3018;
    /* BASIC: 3015 GOSUB 600 */
line_3015:
    /* TODO: GOSUB 600 */
    /* BASIC: 3018 PRINT */
line_3018:
    printf("\n");
    /* BASIC: 3020 Z1=10/4*RND(1)+1 */
line_3020:
    Z1 = 10/4*((double)rand() / (double)RAND_MAX)+1;
    /* BASIC: 3030 IF Z1>2 THEN 3500 */
line_3030:
    if (Z1>2) goto line_3500;
    /* BASIC: 3040 PRINT "JUMP SHOT." */
line_3040:
    printf("%s", "JUMP SHOT."); printf("\n");
    /* BASIC: 3050 IF 8/D*RND(1)>.35 THEN 3100 */
line_3050:
    if (8/D*((double)rand() / (double)RAND_MAX)>.35) goto line_3100;
    /* BASIC: 3060 PRINT "SHOT IS GOOD." */
line_3060:
    printf("%s", "SHOT IS GOOD."); printf("\n");
    /* BASIC: 3080 GOSUB 6000 */
line_3080:
    /* TODO: GOSUB 6000 */
    /* BASIC: 3090 GOTO 425 */
line_3090:
    goto line_425;
    /* BASIC: 3100 IF 8/D*RND(1)>.75 THEN 3200 */
line_3100:
    if (8/D*((double)rand() / (double)RAND_MAX)>.75) goto line_3200;
    /* BASIC: 3105 PRINT "SHOT IS OFF RIM." */
line_3105:
    printf("%s", "SHOT IS OFF RIM."); printf("\n");
    /* BASIC: 3110 IF D/6*RND(1)>.5 THEN 3150 */
line_3110:
    if (D/6*((double)rand() / (double)RAND_MAX)>.5) goto line_3150;
    /* BASIC: 3120 PRINT "DARTMOUTH CONTROLS THE REBOUND." */
line_3120:
    printf("%s", "DARTMOUTH CONTROLS THE REBOUND."); printf("\n");
    /* BASIC: 3130 GOTO 425 */
line_3130:
    goto line_425;
    /* BASIC: 3150 PRINT O$;" CONTROLS THE REBOUND." */
line_3150:
    printf("%s", O_str); printf("%s", " CONTROLS THE REBOUND."); printf("\n");
    /* BASIC: 3160 IF D=6 THEN 5000 */
line_3160:
    if (D==6) goto line_5000;
    /* BASIC: 3165 IF RND(1)>.5 THEN 3175 */
line_3165:
    if (((double)rand() / (double)RAND_MAX)>.5) goto line_3175;
    /* BASIC: 3168 PRINT "PASS BACK TO ";O$;" GUARD." */
line_3168:
    printf("%s", "PASS BACK TO "); printf("%s", O_str); printf("%s", " GUARD."); printf("\n");
    /* BASIC: 3170 GOTO 3000 */
line_3170:
    goto line_3000;
    /* BASIC: 3175 GOTO 3500 */
line_3175:
    goto line_3500;
    /* BASIC: 3200 IF 8/D*RND(1)>.9 THEN 3310 */
line_3200:
    if (8/D*((double)rand() / (double)RAND_MAX)>.9) goto line_3310;
    /* BASIC: 3210 PRINT "PLAYER FOULED.  TWO SHOTS." */
line_3210:
    printf("%s", "PLAYER FOULED.  TWO SHOTS."); printf("\n");
    /* BASIC: 3220 GOSUB 4000 */
line_3220:
    /* TODO: GOSUB 4000 */
    /* BASIC: 3230 GOTO 425 */
line_3230:
    goto line_425;
    /* BASIC: 3310 PRINT "OFFENSIVE FOUL.  DARTMOUTH'S BALL." */
line_3310:
    printf("%s", "OFFENSIVE FOUL.  DARTMOUTH'S BALL."); printf("\n");
    /* BASIC: 3320 GOTO 425 */
line_3320:
    goto line_425;
    /* BASIC: 3500 IF Z1>3 THEN 3800 */
line_3500:
    if (Z1>3) goto line_3800;
    /* BASIC: 3510 PRINT "LAY UP." */
line_3510:
    printf("%s", "LAY UP."); printf("\n");
    /* BASIC: 3520 IF 7/D*RND(1)>.413 THEN 3600 */
line_3520:
    if (7/D*((double)rand() / (double)RAND_MAX)>.413) goto line_3600;
    /* BASIC: 3530 PRINT "SHOT IS GOOD." */
line_3530:
    printf("%s", "SHOT IS GOOD."); printf("\n");
    /* BASIC: 3540 GOSUB 6000 */
line_3540:
    /* TODO: GOSUB 6000 */
    /* BASIC: 3550 GOTO 425 */
line_3550:
    goto line_425;
    /* BASIC: 3600 PRINT "SHOT IS MISSED." */
line_3600:
    printf("%s", "SHOT IS MISSED."); printf("\n");
    /* BASIC: 3610 GOTO 3110 */
line_3610:
    goto line_3110;
    /* BASIC: 3800 PRINT "SET SHOT." */
line_3800:
    printf("%s", "SET SHOT."); printf("\n");
    /* BASIC: 3810 GOTO 3520 */
line_3810:
    goto line_3520;
    /* BASIC: 4000 REM FOUL SHOOTING */
line_4000:
    // REM FOUL SHOOTING
    /* BASIC: 4010 IF RND(1)>.49 THEN 4050 */
line_4010:
    if (((double)rand() / (double)RAND_MAX)>.49) goto line_4050;
    /* BASIC: 4020 PRINT "SHOOTER MAKES BOTH SHOTS." */
line_4020:
    printf("%s", "SHOOTER MAKES BOTH SHOTS."); printf("\n");
    /* BASIC: 4030 S(1-P)=S(1-P)+2 */
line_4030:
    S(1-P) = S(1-P)+2;
    /* BASIC: 4040 GOSUB 6010 */
line_4040:
    /* TODO: GOSUB 6010 */
    /* BASIC: 4041 RETURN */
line_4041:
    /* TODO: RETURN */
    /* BASIC: 4050 IF RND(1)>.75 THEN 4100 */
line_4050:
    if (((double)rand() / (double)RAND_MAX)>.75) goto line_4100;
    /* BASIC: 4060 PRINT "SHOOTER MAKES ONE SHOT AND MISSES ONE." */
line_4060:
    printf("%s", "SHOOTER MAKES ONE SHOT AND MISSES ONE."); printf("\n");
    /* BASIC: 4070 S(1-P)=S(1-P)+1 */
line_4070:
    S(1-P) = S(1-P)+1;
    /* BASIC: 4080 GOTO 4040 */
line_4080:
    goto line_4040;
    /* BASIC: 4100 PRINT "BOTH SHOTS MISSED." */
line_4100:
    printf("%s", "BOTH SHOTS MISSED."); printf("\n");
    /* BASIC: 4110 GOTO 4040 */
line_4110:
    goto line_4040;
    /* BASIC: 5000 IF RND(1)>.75 THEN 5010 */
line_5000:
    if (((double)rand() / (double)RAND_MAX)>.75) goto line_5010;
    /* BASIC: 5005 GOTO 3165 */
line_5005:
    goto line_3165;
    /* BASIC: 5010 PRINT "BALL STOLEN.  EASY LAY UP FOR DARTMOUTH." */
line_5010:
    printf("%s", "BALL STOLEN.  EASY LAY UP FOR DARTMOUTH."); printf("\n");
    /* BASIC: 5015 GOSUB 7000 */
line_5015:
    /* TODO: GOSUB 7000 */
    /* BASIC: 5030 GOTO 3000 */
line_5030:
    goto line_3000;
    /* BASIC: 5100 IF RND(1)>.6 THEN 5120 */
line_5100:
    if (((double)rand() / (double)RAND_MAX)>.6) goto line_5120;
    /* BASIC: 5110 GOTO 1160 */
line_5110:
    goto line_1160;
    /* BASIC: 5120 PRINT "PASS STOLEN BY ";O$;" EASY LAYUP." */
line_5120:
    printf("%s", "PASS STOLEN BY "); printf("%s", O_str); printf("%s", " EASY LAYUP."); printf("\n");
    /* BASIC: 5130 GOSUB 6000 */
line_5130:
    /* TODO: GOSUB 6000 */
    /* BASIC: 5140 GOTO 425 */
line_5140:
    goto line_425;
    /* BASIC: 6000 S(0)=S(0)+2 */
line_6000:
    S(0) = S(0)+2;
    /* BASIC: 6010 PRINT "SCORE: ";S(1);"TO";S(0) */
line_6010:
    printf("%s", "SCORE: "); printf("%g ", (double)(S(1))); printf("%s", "TO"); printf("%g ", (double)(S(0))); printf("\n");
    /* BASIC: 6020 RETURN */
line_6020:
    /* TODO: RETURN */
    /* BASIC: 7000 S(1)=S(1)+2 */
line_7000:
    S(1) = S(1)+2;
    /* BASIC: 7010 GOSUB 6010 */
line_7010:
    /* TODO: GOSUB 6010 */
    /* BASIC: 7020 RETURN */
line_7020:
    /* TODO: RETURN */
    /* BASIC: 8000 PRINT:PRINT "   ***** END OF FIRST HALF *****":PRINT */
line_8000:
    printf("\n");
    printf("%s", "   ***** END OF FIRST HALF *****"); printf("\n");
    printf("\n");
    /* BASIC: 8010 PRINT "SCORE: DARTMOUTH:";S(1);"  ";O$;":";S(0) */
line_8010:
    printf("%s", "SCORE: DARTMOUTH:"); printf("%g ", (double)(S(1))); printf("%s", "  "); printf("%s", O_str); printf("%s", ":"); printf("%g ", (double)(S(0))); printf("\n");
    /* BASIC: 8015 PRINT */
line_8015:
    printf("\n");
    /* BASIC: 8016 PRINT */
line_8016:
    printf("\n");
    /* BASIC: 8020 GOTO 370 */
line_8020:
    goto line_370;
    /* BASIC: 9999 END */
line_9999:
    exit(0);

    return 0;
}
