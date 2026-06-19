/*
 * Transpiled from golf.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double ABS, GOING, SHOT, G2, HOLED, READ, PAST, NOW, STILL, P, GAME, PASSED, GAUGE, J, NEW, NICE, INCLUDE, ASSESSED, LAYOUT, RE, SQR, JERSEY, THE, PREVIOUS, PUTT, ON, LEFT, A, D, RIGHT, IT, SHOTS, TAN, DISTANCE, T, HOOK, FULL, IN, EIGHTEEN, OUT, PENALTY, PGA, BY, MORRISTOWN, DATA, KEEP, OFF, PUTTING, DOWNTOWN, WAS, GREAT, TREE, PLAY, POTENCY, BIG, COMMENTATOR, EAGLE, COUNTRY, SLICE, WHAT, BOUNCED, STROKE, BAG, DUBBED, SWING, RANGE, G1, S1, TOO, HANDICAP, YOUR, S2, I, YARDAGE, BADLY, ADJACENT, SLICED, FROM, LINE, W, HOLES, H, IS, LOCATION, DESIRED, YARDS, K, FEET, OF, ONLY, MUCH, SCORE, TREES, TRAP, POOR, S, PIN, WILL, CREATIVE, WENT, EXPLAIN, YOU, CLUB, ROUGH, WATER, X, AS, CUP, GREEN, ONE, HANDICAPS, PERCENTAGE, LOCATED, GOLF, AN, CHOOSE, SHORT, ARE, SEE, PAR, ENJOY, B, C, BIRDIE, HEAD, INTO, FAIRWAY, TOTAL, G3, CLUBS, WHICH, COMPUTING, HIT, WELCOME, BOUNDS, BALL, D2, SCENIC, SUGGESTED, AT, HOOKED, DOWN, F, TEE, HOLE, WORST, DIFFICULTIES, DO, THAT, O, CHAMPIONSHIP, D1, N, S9, Q, SELECTION;
    double L[1000] = {0}; /* Static array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 1 PRINT TAB(34);"GOLF" */
line_1:
    { int _t; for(_t=0; _t<34; _t++) printf(" "); } printf("%s", "GOLF"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT:PRINT:PRINT */
line_3:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 4 PRINT "WELCOME TO THE CREATIVE COMPUTING COUNTRY CLUB," */
line_4:
    printf("%s", "WELCOME TO THE CREATIVE COMPUTING COUNTRY CLUB,"); printf("\n");
    /* BASIC: 5 PRINT "AN EIGHTEEN HOLE CHAMPIONSHIP LAYOUT LOCATED A SHORT" */
line_5:
    printf("%s", "AN EIGHTEEN HOLE CHAMPIONSHIP LAYOUT LOCATED A SHORT"); printf("\n");
    /* BASIC: 6 PRINT "DISTANCE FROM SCENIC DOWNTOWN MORRISTOWN.  THE" */
line_6:
    printf("%s", "DISTANCE FROM SCENIC DOWNTOWN MORRISTOWN.  THE"); printf("\n");
    /* BASIC: 7 PRINT "COMMENTATOR WILL EXPLAIN THE GAME AS YOU PLAY." */
line_7:
    printf("%s", "COMMENTATOR WILL EXPLAIN THE GAME AS YOU PLAY."); printf("\n");
    /* BASIC: 8 PRINT "ENJOY YOUR GAME; SEE YOU AT THE 19TH HOLE..." */
line_8:
    printf("%s", "ENJOY YOUR GAME; SEE YOU AT THE 19TH HOLE..."); printf("\n");
    /* BASIC: 9 PRINT:PRINT: DIM L(10) */
line_9:
    printf("\n");
    printf("\n");
    /* DIM L(10) (handled statically) */
    /* BASIC: 10 G1=18 */
line_10:
    G1 = 18;
    /* BASIC: 20 G2=0 */
line_20:
    G2 = 0;
    /* BASIC: 30 G3=0 */
line_30:
    G3 = 0;
    /* BASIC: 40 A=0 */
line_40:
    A = 0;
    /* BASIC: 50 N=.8 */
line_50:
    N = .8;
    /* BASIC: 60 S2=0 */
line_60:
    S2 = 0;
    /* BASIC: 70 F=1 */
line_70:
    F = 1;
    /* BASIC: 80 PRINT "WHAT IS YOUR HANDICAP"; */
line_80:
    printf("%s", "WHAT IS YOUR HANDICAP");
    /* BASIC: 90 INPUT H:PRINT */
line_90:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &H);
    printf("\n");
    /* BASIC: 100 IF H>30 THEN 470 */
line_100:
    if (H>30) goto line_470;
    /* BASIC: 110 IF H<0 THEN 470 */
line_110:
    if (H<0) goto line_470;
    /* BASIC: 120 PRINT "DIFFICULTIES AT GOLF INCLUDE:" */
line_120:
    printf("%s", "DIFFICULTIES AT GOLF INCLUDE:"); printf("\n");
    /* BASIC: 130 PRINT "0=HOOK, 1=SLICE, 2=POOR DISTANCE, 4=TRAP SHOTS, 5=PUTTING" */
line_130:
    printf("%s", "0=HOOK, 1=SLICE, 2=POOR DISTANCE, 4=TRAP SHOTS, 5=PUTTING"); printf("\n");
    /* BASIC: 140 PRINT "WHICH ONE (ONLY ONE) IS YOUR WORST"; */
line_140:
    printf("%s", "WHICH ONE (ONLY ONE) IS YOUR WORST");
    /* BASIC: 150 INPUT T:PRINT */
line_150:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &T);
    printf("\n");
    /* BASIC: 160 IF T>5 THEN 120 */
line_160:
    if (T>5) goto line_120;
    /* BASIC: 170 S1=0 */
line_170:
    S1 = 0;
    /* BASIC: 210 REM */
line_210:
    // REM
    /* BASIC: 230 L(0)=0 */
line_230:
    L(0) = 0;
    /* BASIC: 240 J=0 */
line_240:
    J = 0;
    /* BASIC: 245 Q=0 */
line_245:
    Q = 0;
    /* BASIC: 250 S2=S2+1 */
line_250:
    S2 = S2+1;
    /* BASIC: 260 K=0 */
line_260:
    K = 0;
    /* BASIC: 270 IF F=1 THEN 310 */
line_270:
    if (F==1) goto line_310;
    /* BASIC: 290 PRINT "YOUR SCORE ON HOLE";F-1;"WAS";S1 */
line_290:
    printf("%s", "YOUR SCORE ON HOLE"); printf("%g ", (double)(F-1)); printf("%s", "WAS"); printf("%g ", (double)(S1)); printf("\n");
    /* BASIC: 291 GOTO 1750 */
line_291:
    goto line_1750;
    /* BASIC: 292 IF S1>P+2 THEN 297 */
line_292:
    if (S1>P+2) goto line_297;
    /* BASIC: 293 IF S1=P THEN 299 */
line_293:
    if (S1==P) goto line_299;
    /* BASIC: 294 IF S1=P-1 THEN 301 */
line_294:
    if (S1==P-1) goto line_301;
    /* BASIC: 295 IF S1=P-2 THEN 303 */
line_295:
    if (S1==P-2) goto line_303;
    /* BASIC: 296 GOTO 310 */
line_296:
    goto line_310;
    /* BASIC: 297 PRINT "KEEP YOUR HEAD DOWN." */
line_297:
    printf("%s", "KEEP YOUR HEAD DOWN."); printf("\n");
    /* BASIC: 298 GOTO 310 */
line_298:
    goto line_310;
    /* BASIC: 299 PRINT "A PAR.  NICE GOING." */
line_299:
    printf("%s", "A PAR.  NICE GOING."); printf("\n");
    /* BASIC: 300 GOTO 310 */
line_300:
    goto line_310;
    /* BASIC: 301 PRINT "A BIRDIE." */
line_301:
    printf("%s", "A BIRDIE."); printf("\n");
    /* BASIC: 302 GOTO 310 */
line_302:
    goto line_310;
    /* BASIC: 303 IF P=3 THEN 306 */
line_303:
    if (P==3) goto line_306;
    /* BASIC: 304 PRINT "A GREAT BIG EAGLE." */
line_304:
    printf("%s", "A GREAT BIG EAGLE."); printf("\n");
    /* BASIC: 305 GOTO 310 */
line_305:
    goto line_310;
    /* BASIC: 306 PRINT "A HOLE IN ONE." */
line_306:
    printf("%s", "A HOLE IN ONE."); printf("\n");
    /* BASIC: 310 IF F=19 THEN 1710 */
line_310:
    if (F==19) goto line_1710;
    /* BASIC: 315 S1=0 */
line_315:
    S1 = 0;
    /* BASIC: 316 PRINT */
line_316:
    printf("\n");
    /* BASIC: 320 IF S1=0 THEN 1590 */
line_320:
    if (S1==0) goto line_1590;
    /* BASIC: 330 IF L(0)<1 THEN 1150 */
line_330:
    if (L(0)<1) goto line_1150;
    /* BASIC: 340 X=0 */
line_340:
    X = 0;
    /* BASIC: 350 IF L(0)>5 THEN 1190 */
line_350:
    if (L(0)>5) goto line_1190;
    /* BASIC: 360 PRINT "SHOT WENT";D1;"YARDS.  IT'S";D2;"YARDS FROM THE CUP." */
line_360:
    printf("%s", "SHOT WENT"); printf("%g ", (double)(D1)); printf("%s", "YARDS.  IT'S"); printf("%g ", (double)(D2)); printf("%s", "YARDS FROM THE CUP."); printf("\n");
    /* BASIC: 362 PRINT "BALL IS";INT(O);"YARDS OFF LINE... IN "; */
line_362:
    printf("%s", "BALL IS"); printf("%g ", (double)(floor(O))); printf("%s", "YARDS OFF LINE... IN ");
    /* BASIC: 380 GOSUB 400 */
line_380:
    /* TODO: GOSUB 400 */
    /* BASIC: 390 GOTO 620 */
line_390:
    goto line_620;
    /* BASIC: 400 IF L(X)=1 THEN 480 */
line_400:
    if (L(X)==1) goto line_480;
    /* BASIC: 410 IF L(X)=2 THEN 500 */
line_410:
    if (L(X)==2) goto line_500;
    /* BASIC: 420 IF L(X)=3 THEN 520 */
line_420:
    if (L(X)==3) goto line_520;
    /* BASIC: 430 IF L(X)=4 THEN 540 */
line_430:
    if (L(X)==4) goto line_540;
    /* BASIC: 440 IF L(X)=5 THEN 560 */
line_440:
    if (L(X)==5) goto line_560;
    /* BASIC: 450 IF L(X)=6 THEN 580 */
line_450:
    if (L(X)==6) goto line_580;
    /* BASIC: 460 PRINT "OUT OF BOUNDS." */
line_460:
    printf("%s", "OUT OF BOUNDS."); printf("\n");
    /* BASIC: 465 GOTO 1690 */
line_465:
    goto line_1690;
    /* BASIC: 470 PRINT "PGA HANDICAPS RANGE FROM 0 TO 30." */
line_470:
    printf("%s", "PGA HANDICAPS RANGE FROM 0 TO 30."); printf("\n");
    /* BASIC: 472 GOTO 80 */
line_472:
    goto line_80;
    /* BASIC: 480 PRINT "FAIRWAY." */
line_480:
    printf("%s", "FAIRWAY."); printf("\n");
    /* BASIC: 490 GOTO 1690 */
line_490:
    goto line_1690;
    /* BASIC: 500 PRINT "ROUGH." */
line_500:
    printf("%s", "ROUGH."); printf("\n");
    /* BASIC: 510 GOTO 1690 */
line_510:
    goto line_1690;
    /* BASIC: 520 PRINT "TREES." */
line_520:
    printf("%s", "TREES."); printf("\n");
    /* BASIC: 530 GOTO 1690 */
line_530:
    goto line_1690;
    /* BASIC: 540 PRINT "ADJACENT FAIRWAY." */
line_540:
    printf("%s", "ADJACENT FAIRWAY."); printf("\n");
    /* BASIC: 550 GOTO 1690 */
line_550:
    goto line_1690;
    /* BASIC: 560 PRINT "TRAP." */
line_560:
    printf("%s", "TRAP."); printf("\n");
    /* BASIC: 570 GOTO 1690 */
line_570:
    goto line_1690;
    /* BASIC: 580 PRINT "WATER." */
line_580:
    printf("%s", "WATER."); printf("\n");
    /* BASIC: 590 GOTO 1690 */
line_590:
    goto line_1690;
    /* BASIC: 620 IF A=1 THEN 629 */
line_620:
    if (A==1) goto line_629;
    /* BASIC: 621 PRINT "SELECTION OF CLUBS" */
line_621:
    printf("%s", "SELECTION OF CLUBS"); printf("\n");
    /* BASIC: 622 PRINT "YARDAGE DESIRED                       SUGGESTED CLUBS" */
line_622:
    printf("%s", "YARDAGE DESIRED                       SUGGESTED CLUBS"); printf("\n");
    /* BASIC: 623 PRINT "200 TO 280 YARDS                           1 TO 4" */
line_623:
    printf("%s", "200 TO 280 YARDS                           1 TO 4"); printf("\n");
    /* BASIC: 624 PRINT "100 TO 200 YARDS                          19 TO 13" */
line_624:
    printf("%s", "100 TO 200 YARDS                          19 TO 13"); printf("\n");
    /* BASIC: 625 PRINT "  0 TO 100 YARDS                          29 TO 23" */
line_625:
    printf("%s", "  0 TO 100 YARDS                          29 TO 23"); printf("\n");
    /* BASIC: 626 A=1 */
line_626:
    A = 1;
    /* BASIC: 629 PRINT "WHAT CLUB DO YOU CHOOSE"; */
line_629:
    printf("%s", "WHAT CLUB DO YOU CHOOSE");
    /* BASIC: 630 INPUT C */
line_630:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &C);
    /* BASIC: 632 PRINT */
line_632:
    printf("\n");
    /* BASIC: 635 IF C<1 THEN 690 */
line_635:
    if (C<1) goto line_690;
    /* BASIC: 637 IF C>29 THEN 690 */
line_637:
    if (C>29) goto line_690;
    /* BASIC: 640 IF C>4 THEN 710 */
line_640:
    if (C>4) goto line_710;
    /* BASIC: 650 IF L(0)<=5 THEN 740 */
line_650:
    if (L(0)<==5) goto line_740;
    /* BASIC: 660 IF C=14 THEN 740 */
line_660:
    if (C==14) goto line_740;
    /* BASIC: 665 IF C=23 THEN 740 */
line_665:
    if (C==23) goto line_740;
    /* BASIC: 670 GOTO 690 */
line_670:
    goto line_690;
    /* BASIC: 680 S1=S1-1 */
line_680:
    S1 = S1-1;
    /* BASIC: 690 PRINT "THAT CLUB IS NOT IN THE BAG." */
line_690:
    printf("%s", "THAT CLUB IS NOT IN THE BAG."); printf("\n");
    /* BASIC: 693 PRINT */
line_693:
    printf("\n");
    /* BASIC: 700 GOTO 620 */
line_700:
    goto line_620;
    /* BASIC: 710 IF C<12 THEN 690 */
line_710:
    if (C<12) goto line_690;
    /* BASIC: 720 C=C-6 */
line_720:
    C = C-6;
    /* BASIC: 730 GOTO 650 */
line_730:
    goto line_650;
    /* BASIC: 740 S1=S1+1 */
line_740:
    S1 = S1+1;
    /* BASIC: 741 W=1 */
line_741:
    W = 1;
    /* BASIC: 742 IF C>13 THEN 960 */
line_742:
    if (C>13) goto line_960;
    /* BASIC: 746 IF INT(F/3)=F/3 THEN 952 */
line_746:
    if (floor(F/3)==F/3) goto line_952;
    /* BASIC: 752 IF C<4 THEN 756 */
line_752:
    if (C<4) goto line_756;
    /* BASIC: 754 GOTO 760 */
line_754:
    goto line_760;
    /* BASIC: 756 IF L(0)=2 THEN 862 */
line_756:
    if (L(0)==2) goto line_862;
    /* BASIC: 760 IF S1>7 THEN 867 */
line_760:
    if (S1>7) goto line_867;
    /* BASIC: 770 D1=INT(((30-H)*2.5+187-((30-H)*.25+15)*C/2)+25*RND(1)) */
line_770:
    D1 = floor(((30-H)*2.5+187-((30-H)*.25+15)*C/2)+25*((double)rand() / (double)RAND_MAX));
    /* BASIC: 780 D1=INT(D1*W) */
line_780:
    D1 = floor(D1*W);
    /* BASIC: 800 IF T=2 THEN 1170 */
line_800:
    if (T==2) goto line_1170;
    /* BASIC: 830 O=(RND(1)/.8)*(2*H+16)*ABS(TAN(D1*.0035)) */
line_830:
    O = (((double)rand() / (double)RAND_MAX)/.8)*(2*H+16)*fabs(TAN(D1*.0035));
    /* BASIC: 840 D2=INT(SQR(O^2+ABS(D-D1)^2)) */
line_840:
    D2 = floor(sqrt(O^2+fabs(D-D1)^2));
    /* BASIC: 850 IF D-D1<0 THEN 870 */
line_850:
    if (D-D1<0) goto line_870;
    /* BASIC: 860 GOTO 890 */
line_860:
    goto line_890;
    /* BASIC: 862 PRINT "YOU DUBBED IT." */
line_862:
    printf("%s", "YOU DUBBED IT."); printf("\n");
    /* BASIC: 864 D1=35 */
line_864:
    D1 = 35;
    /* BASIC: 866 GOTO 830 */
line_866:
    goto line_830;
    /* BASIC: 867 IF D<200 THEN 1300 */
line_867:
    if (D<200) goto line_1300;
    /* BASIC: 868 GOTO 770 */
line_868:
    goto line_770;
    /* BASIC: 870 IF D2<20 THEN 890 */
line_870:
    if (D2<20) goto line_890;
    /* BASIC: 880 PRINT "TOO MUCH CLUB. YOU'RE PAST THE HOLE." */
line_880:
    printf("%s", "TOO MUCH CLUB. YOU'RE PAST THE HOLE."); printf("\n");
    /* BASIC: 890 B=D */
line_890:
    B = D;
    /* BASIC: 900 D=D2 */
line_900:
    D = D2;
    /* BASIC: 910 IF D2>27 THEN 1020 */
line_910:
    if (D2>27) goto line_1020;
    /* BASIC: 920 IF D2>20 THEN 1100 */
line_920:
    if (D2>20) goto line_1100;
    /* BASIC: 930 IF D2>.5 THEN 1120 */
line_930:
    if (D2>.5) goto line_1120;
    /* BASIC: 940 L(0)=9 */
line_940:
    L(0) = 9;
    /* BASIC: 950 GOTO 1470 */
line_950:
    goto line_1470;
    /* BASIC: 952 IF S2+Q+(10*(F-1)/18)<(F-1)*(72+((H+1)/.85))/18 THEN 956 */
line_952:
    if (S2+Q+(10*(F-1)/18)<(F-1)*(72+((H+1)/.85))/18) goto line_956;
    /* BASIC: 954 GOTO 752 */
line_954:
    goto line_752;
    /* BASIC: 956 Q=Q+1 */
line_956:
    Q = Q+1;
    /* BASIC: 957 IF S1/2<>INT(S1/2) THEN 1011 */
line_957:
    if (S1/2!=floor(S1/2)) goto line_1011;
    /* BASIC: 958 GOTO 862 */
line_958:
    goto line_862;
    /* BASIC: 960 PRINT "NOW GAUGE YOUR DISTANCE BY A PERCENTAGE (1 TO 100)" */
line_960:
    printf("%s", "NOW GAUGE YOUR DISTANCE BY A PERCENTAGE (1 TO 100)"); printf("\n");
    /* BASIC: 961 PRINT "OF A FULL SWING"; */
line_961:
    printf("%s", "OF A FULL SWING");
    /* BASIC: 970 INPUT W: W=W/100 */
line_970:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &W);
    W = W/100;
    /* BASIC: 972 PRINT */
line_972:
    printf("\n");
    /* BASIC: 980 IF W>1 THEN 680 */
line_980:
    if (W>1) goto line_680;
    /* BASIC: 985 IF L(0)=5 THEN 1280 */
line_985:
    if (L(0)==5) goto line_1280;
    /* BASIC: 990 IF C=14 THEN 760 */
line_990:
    if (C==14) goto line_760;
    /* BASIC: 1000 C=C-10 */
line_1000:
    C = C-10;
    /* BASIC: 1010 GOTO 760 */
line_1010:
    goto line_760;
    /* BASIC: 1011 IF D<95 THEN 862 */
line_1011:
    if (D<95) goto line_862;
    /* BASIC: 1012 PRINT "BALL HIT TREE - BOUNCED INTO ROUGH";D-75;"YARDS FROM HOLE." */
line_1012:
    printf("%s", "BALL HIT TREE - BOUNCED INTO ROUGH"); printf("%g ", (double)(D-75)); printf("%s", "YARDS FROM HOLE."); printf("\n");
    /* BASIC: 1014 D=D-75 */
line_1014:
    D = D-75;
    /* BASIC: 1018 GOTO 620 */
line_1018:
    goto line_620;
    /* BASIC: 1020 IF O<30 THEN 1150 */
line_1020:
    if (O<30) goto line_1150;
    /* BASIC: 1022 IF J>0 THEN 1150 */
line_1022:
    if (J>0) goto line_1150;
    /* BASIC: 1030 IF T>0 THEN 1070 */
line_1030:
    if (T>0) goto line_1070;
    /* BASIC: 1035 S9=(S2+1)/15 */
line_1035:
    S9 = (S2+1)/15;
    /* BASIC: 1036 IF INT(S9)=S9 THEN 1075 */
line_1036:
    if (floor(S9)==S9) goto line_1075;
    /* BASIC: 1040 PRINT "YOU HOOKED- "; */
line_1040:
    printf("%s", "YOU HOOKED- ");
    /* BASIC: 1050 L(0)=L(2) */
line_1050:
    L(0) = L(2);
    /* BASIC: 1055 IF O>45 THEN 1092 */
line_1055:
    if (O>45) goto line_1092;
    /* BASIC: 1060 GOTO 320 */
line_1060:
    goto line_320;
    /* BASIC: 1070 S9=(S2+1)/15 */
line_1070:
    S9 = (S2+1)/15;
    /* BASIC: 1071 IF INT(S9)=S9 THEN 1040 */
line_1071:
    if (floor(S9)==S9) goto line_1040;
    /* BASIC: 1075 PRINT "YOU SLICED- "; */
line_1075:
    printf("%s", "YOU SLICED- ");
    /* BASIC: 1080 L(0)=L(1) */
line_1080:
    L(0) = L(1);
    /* BASIC: 1090 GOTO 1055 */
line_1090:
    goto line_1055;
    /* BASIC: 1092 PRINT "BADLY." */
line_1092:
    printf("%s", "BADLY."); printf("\n");
    /* BASIC: 1094 GOTO 320 */
line_1094:
    goto line_320;
    /* BASIC: 1100 L(0)=5 */
line_1100:
    L(0) = 5;
    /* BASIC: 1110 GOTO 320 */
line_1110:
    goto line_320;
    /* BASIC: 1120 L(0)=8 */
line_1120:
    L(0) = 8;
    /* BASIC: 1130 D2=INT(D2*3) */
line_1130:
    D2 = floor(D2*3);
    /* BASIC: 1140 GOTO 1380 */
line_1140:
    goto line_1380;
    /* BASIC: 1150 L(0)=1 */
line_1150:
    L(0) = 1;
    /* BASIC: 1160 GOTO 320 */
line_1160:
    goto line_320;
    /* BASIC: 1170 D1=INT(.85*D1) */
line_1170:
    D1 = floor(.85*D1);
    /* BASIC: 1180 GOTO 830 */
line_1180:
    goto line_830;
    /* BASIC: 1190 IF L(0)>6 THEN 1260 */
line_1190:
    if (L(0)>6) goto line_1260;
    /* BASIC: 1200 PRINT "YOUR SHOT WENT INTO THE WATER." */
line_1200:
    printf("%s", "YOUR SHOT WENT INTO THE WATER."); printf("\n");
    /* BASIC: 1210 S1=S1+1 */
line_1210:
    S1 = S1+1;
    /* BASIC: 1220 PRINT "PENALTY STROKE ASSESSED.  HIT FROM PREVIOUS LOCATION." */
line_1220:
    printf("%s", "PENALTY STROKE ASSESSED.  HIT FROM PREVIOUS LOCATION."); printf("\n");
    /* BASIC: 1230 J=J+1 */
line_1230:
    J = J+1;
    /* BASIC: 1240 L(0)=1 */
line_1240:
    L(0) = 1;
    /* BASIC: 1242 D=B */
line_1242:
    D = B;
    /* BASIC: 1250 GOTO 620 */
line_1250:
    goto line_620;
    /* BASIC: 1260 PRINT "YOUR SHOT WENT OUT OF BOUNDS." */
line_1260:
    printf("%s", "YOUR SHOT WENT OUT OF BOUNDS."); printf("\n");
    /* BASIC: 1270 GOTO 1210 */
line_1270:
    goto line_1210;
    /* BASIC: 1280 IF T=3 THEN 1320 */
line_1280:
    if (T==3) goto line_1320;
    /* BASIC: 1300 D2=1+(3*INT((80/(40-H))*RND(1))) */
line_1300:
    D2 = 1+(3*floor((80/(40-H))*((double)rand() / (double)RAND_MAX)));
    /* BASIC: 1310 GOTO 1380 */
line_1310:
    goto line_1380;
    /* BASIC: 1320 IF RND(1)>N THEN 1360 */
line_1320:
    if (((double)rand() / (double)RAND_MAX)>N) goto line_1360;
    /* BASIC: 1330 N=N*.2 */
line_1330:
    N = N*.2;
    /* BASIC: 1340 PRINT "SHOT DUBBED, STILL IN TRAP." */
line_1340:
    printf("%s", "SHOT DUBBED, STILL IN TRAP."); printf("\n");
    /* BASIC: 1350 GOTO 620 */
line_1350:
    goto line_620;
    /* BASIC: 1360 N=.8 */
line_1360:
    N = .8;
    /* BASIC: 1370 GOTO 1300 */
line_1370:
    goto line_1300;
    /* BASIC: 1380 PRINT "ON GREEN,";D2;"FEET FROM THE PIN." */
line_1380:
    printf("%s", "ON GREEN,"); printf("%g ", (double)(D2)); printf("%s", "FEET FROM THE PIN."); printf("\n");
    /* BASIC: 1381 PRINT "CHOOSE YOUR PUTT POTENCY (1 TO 13):"; */
line_1381:
    printf("%s", "CHOOSE YOUR PUTT POTENCY (1 TO 13):");
    /* BASIC: 1400 INPUT I */
line_1400:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &I);
    /* BASIC: 1410 S1=S1+1 */
line_1410:
    S1 = S1+1;
    /* BASIC: 1420 IF S1+1-P>(H*.072)+2 THEN 1470 */
line_1420:
    if (S1+1-P>(H*.072)+2) goto line_1470;
    /* BASIC: 1425 IF K>2 THEN 1470 */
line_1425:
    if (K>2) goto line_1470;
    /* BASIC: 1428 K=K+1 */
line_1428:
    K = K+1;
    /* BASIC: 1430 IF T=4 THEN 1530 */
line_1430:
    if (T==4) goto line_1530;
    /* BASIC: 1440 D2=D2-I*(4+2*RND(1))+1.5 */
line_1440:
    D2 = D2-I*(4+2*((double)rand() / (double)RAND_MAX))+1.5;
    /* BASIC: 1450 IF D2<-2 THEN 1560 */
line_1450:
    if (D2<-2) goto line_1560;
    /* BASIC: 1460 IF D2>2 THEN 1500 */
line_1460:
    if (D2>2) goto line_1500;
    /* BASIC: 1470 PRINT "YOU HOLED IT." */
line_1470:
    printf("%s", "YOU HOLED IT."); printf("\n");
    /* BASIC: 1472 PRINT */
line_1472:
    printf("\n");
    /* BASIC: 1480 F=F+1 */
line_1480:
    F = F+1;
    /* BASIC: 1490 GOTO 230 */
line_1490:
    goto line_230;
    /* BASIC: 1500 PRINT "PUTT SHORT." */
line_1500:
    printf("%s", "PUTT SHORT."); printf("\n");
    /* BASIC: 1505 D2=INT(D2) */
line_1505:
    D2 = floor(D2);
    /* BASIC: 1510 GOTO 1380 */
line_1510:
    goto line_1380;
    /* BASIC: 1530 D2=D2-I*(4+1*RND(1))+1 */
line_1530:
    D2 = D2-I*(4+1*((double)rand() / (double)RAND_MAX))+1;
    /* BASIC: 1550 GOTO 1450 */
line_1550:
    goto line_1450;
    /* BASIC: 1560 PRINT "PASSED BY CUP." */
line_1560:
    printf("%s", "PASSED BY CUP."); printf("\n");
    /* BASIC: 1570 D2=-D2 */
line_1570:
    D2 = -D2;
    /* BASIC: 1580 GOTO 1505 */
line_1580:
    goto line_1505;
    /* BASIC: 1590 READ D,P,L(1),L(2) */
line_1590:
    /* UNTRANSLATED: READ D,P,L(1),L(2) */
    /* BASIC: 1595 PRINT */
line_1595:
    printf("\n");
    /* BASIC: 1600 PRINT "YOU ARE AT THE TEE OFF HOLE";F;"DISTANCE";D;"YARDS, PAR";P */
line_1600:
    printf("%s", "YOU ARE AT THE TEE OFF HOLE"); printf("%g ", (double)(F)); printf("%s", "DISTANCE"); printf("%g ", (double)(D)); printf("%s", "YARDS, PAR"); printf("%g ", (double)(P)); printf("\n");
    /* BASIC: 1605 G3=G3+P */
line_1605:
    G3 = G3+P;
    /* BASIC: 1620 PRINT "ON YOUR RIGHT IS "; */
line_1620:
    printf("%s", "ON YOUR RIGHT IS ");
    /* BASIC: 1630 X=1 */
line_1630:
    X = 1;
    /* BASIC: 1640 GOSUB 400 */
line_1640:
    /* TODO: GOSUB 400 */
    /* BASIC: 1650 PRINT "ON YOUR LEFT IS "; */
line_1650:
    printf("%s", "ON YOUR LEFT IS ");
    /* BASIC: 1660 X=2 */
line_1660:
    X = 2;
    /* BASIC: 1670 GOSUB 400 */
line_1670:
    /* TODO: GOSUB 400 */
    /* BASIC: 1680 GOTO 620 */
line_1680:
    goto line_620;
    /* BASIC: 1690 RETURN */
line_1690:
    /* TODO: RETURN */
    /* BASIC: 1700 DATA 361,4,4,2,389,4,3,3,206,3,4,2,500,5,7,2 */
line_1700:
    /* UNTRANSLATED: DATA 361,4,4,2,389,4,3,3,206,3,4,2,500,5,7,2 */
    /* BASIC: 1702 DATA 408,4,2,4,359,4,6,4,424,4,4,2,388,4,4,4 */
line_1702:
    /* UNTRANSLATED: DATA 408,4,2,4,359,4,6,4,424,4,4,2,388,4,4,4 */
    /* BASIC: 1704 DATA 196,3,7,2,400,4,7,2,560,5,7,2,132,3,2,2 */
line_1704:
    /* UNTRANSLATED: DATA 196,3,7,2,400,4,7,2,560,5,7,2,132,3,2,2 */
    /* BASIC: 1706 DATA 357,4,4,4,294,4,2,4,475,5,2,3,375,4,4,2 */
line_1706:
    /* UNTRANSLATED: DATA 357,4,4,4,294,4,2,4,475,5,2,3,375,4,4,2 */
    /* BASIC: 1708 DATA 180,3,6,2,550,5,6,6 */
line_1708:
    /* UNTRANSLATED: DATA 180,3,6,2,550,5,6,6 */
    /* BASIC: 1710 PRINT */
line_1710:
    printf("\n");
    /* BASIC: 1750 G2=G2+S1 */
line_1750:
    G2 = G2+S1;
    /* BASIC: 1760 PRINT "TOTAL PAR FOR";F-1;"HOLES IS";G3;"  YOUR TOTAL IS";G2 */
line_1760:
    printf("%s", "TOTAL PAR FOR"); printf("%g ", (double)(F-1)); printf("%s", "HOLES IS"); printf("%g ", (double)(G3)); printf("%s", "  YOUR TOTAL IS"); printf("%g ", (double)(G2)); printf("\n");
    /* BASIC: 1761 IF G1=F-1 THEN 1770 */
line_1761:
    if (G1==F-1) goto line_1770;
    /* BASIC: 1765 GOTO 292 */
line_1765:
    goto line_292;
    /* BASIC: 1770 END */
line_1770:
    exit(0);

    return 0;
}
