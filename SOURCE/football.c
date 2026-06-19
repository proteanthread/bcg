/*
 * Transpiled from football.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double ABS, SCORES, QUARTERBACK, READ, AROUND, NOW, GAIN, DAZZLE, P, GAME, P2, LOSS, NEW, DOUBLE, CHART, GOAL, INSTRUCTIONS, ANSWER, POSSESSION, JERSEY, HAVING, THE, PLAYED, ENDZONE, LIST, ON, LEFT, TACKLE, FORTRAN, PLAYS, D, RIGHT, DRAW, IT, REVERSE, CONTROL, T, PROVIDED, WISHBONE, IN, SNEAK, NUMBER, SCREEN, OUT, BY, MORRISTOWN, GAINED, BOMB, TEAR, DATA, SIDELINE, OBTAINED, TEAMS, MUST, OFF, TWENTY, WHETHER, WAS, OH, PLAY, NET, TRY, BACK, DEFENDS, OPTION, ILLEGAL, HERE, BAD, U, NUMBERS, WANT, ROLL, WIDE, TOO, ALL, QUESTIONS, DEFENSIVE, I, YARDAGE, SIMILAR, QB, TAPE, UNSUCCESFUL, STATEMENT, AUTOMATIC, FROM, Y, M, MORE, UNTIL, W, H, IS, NOS, POINT, KICKOFF, YARDS, K, INPUTTING, KICK, OF, Z, SCORE, RUNBACK, PRESENTING, SAME, S, WILL, CURL, CREATIVE, WHENEVER, WENT, EACH, PLEASE, YOU, X, UNSUCCESSFUL, WINS, PITCHOUT, NO, USED, WITH, GIVEN, BOTH, RUN, SAFETY, SCRAMBLES, RECEIVES, G, LESS, ASKED, EXTRA, GOOD, P1, PREPARE, TOUCHDOWN, RAZZLE, OFFENSIVE, MAY, THEIR, TEAM, CONVERSION, ARE, BE, YEA, B, C, ASSIGNED, LONG, AGAINST, TWO, ASSUMED, WHICH, YD, COMPUTING, E, COIN, BALL, ATTEMPT, FLARE, HALF, SCRAMBLED, COMPLETED, PUNT, FIELD, FLIPPED, L, PASS, PLAYERS, ALSO, F, DOWN, DOES, INSTEAD, SWEEP, DO, TOUCHBACK, R, YES, FOOTBALL, INCOMPLETE, TRIPLE, MADE, LIMIT, N, THIS, TERMINATE, Q, CHECK, THESE;
    double A[1000] = {0}; /* Static array fallback */
    char M_str[1000][256] = {0}; /* Static string array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 1 PRINT TAB(32);"FOOTBALL" */
line_1:
    { int _t; for(_t=0; _t<32; _t++) printf(" "); } printf("%s", "FOOTBALL"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT:PRINT:PRINT */
line_3:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 100 REM */
line_100:
    // REM
    /* BASIC: 120 DIM A(20),B(20),C(40),H(2),T(2),W(2),X(2),Y(2),Z(2) */
line_120:
    /* DIM A(20),B(20),C(40),H(2),T(2),W(2),X(2),Y(2),Z(2) (handled statically) */
    /* BASIC: 130 DIM M$(2),D(2),P$(20) */
line_130:
    /* DIM M$(2),D(2),P$(20) (handled statically) */
    /* BASIC: 140 PRINT "PRESENTING N.F.U. FOOTBALL (NO FORTRAN USED)" */
line_140:
    printf("%s", "PRESENTING N.F.U. FOOTBALL (NO FORTRAN USED)"); printf("\n");
    /* BASIC: 145 PRINT:PRINT */
line_145:
    printf("\n");
    printf("\n");
    /* BASIC: 150 INPUT "DO YOU WANT INSTRUCTIONS";A$ */
line_150:
    printf("%s", "DO YOU WANT INSTRUCTIONS"); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    /* BASIC: 160 IF A$="NO" THEN 290 */
line_160:
    if (A$=="NO") goto line_290;
    /* BASIC: 165 IF A$<>"YES" THEN 150 */
line_165:
    if (A$!="YES") goto line_150;
    /* BASIC: 170 PRINT "THIS IS A FOOTBALL GAME FOR TWO TEAMS IN WHICH PLAYERS MUST" */
line_170:
    printf("%s", "THIS IS A FOOTBALL GAME FOR TWO TEAMS IN WHICH PLAYERS MUST"); printf("\n");
    /* BASIC: 180 PRINT "PREPARE A TAPE WITH A DATA STATEMENT (1770 FOR TEAM 1," */
line_180:
    printf("%s", "PREPARE A TAPE WITH A DATA STATEMENT (1770 FOR TEAM 1,"); printf("\n");
    /* BASIC: 190 PRINT "1780 FOR TEAM 2) IN WHICH EACH TEAM SCRAMBLES NOS. 1-20" */
line_190:
    printf("%s", "1780 FOR TEAM 2) IN WHICH EACH TEAM SCRAMBLES NOS. 1-20"); printf("\n");
    /* BASIC: 195 PRINT "THESE NUMBERS ARE THEN ASSIGNED TO TWENTY GIVEN PLAYS." */
line_195:
    printf("%s", "THESE NUMBERS ARE THEN ASSIGNED TO TWENTY GIVEN PLAYS."); printf("\n");
    /* BASIC: 200 PRINT"A LIST OF NOS. AND THEIR PLAYS IS PROVIDED WITH" */
line_200:
    printf("%s", "A LIST OF NOS. AND THEIR PLAYS IS PROVIDED WITH"); printf("\n");
    /* BASIC: 210 PRINT "BOTH TEAMS HAVING THE SAME PLAYS. THE MORE SIMILAR THE" */
line_210:
    printf("%s", "BOTH TEAMS HAVING THE SAME PLAYS. THE MORE SIMILAR THE"); printf("\n");
    /* BASIC: 220 PRINT "PLAYS THE LESS YARDAGE GAINED.  SCORES ARE GIVEN" */
line_220:
    printf("%s", "PLAYS THE LESS YARDAGE GAINED.  SCORES ARE GIVEN"); printf("\n");
    /* BASIC: 223 PRINT "WHENEVER SCORES ARE MADE. SCORES MAY ALSO BE OBTAINED" */
line_223:
    printf("%s", "WHENEVER SCORES ARE MADE. SCORES MAY ALSO BE OBTAINED"); printf("\n");
    /* BASIC: 225 PRINT "BY INPUTTING 99,99 FOR PLAY NOS. TO PUNT OR ATTEMPT A" */
line_225:
    printf("%s", "BY INPUTTING 99,99 FOR PLAY NOS. TO PUNT OR ATTEMPT A"); printf("\n");
    /* BASIC: 227 PRINT "FIELD GOAL, INPUT 77,77 FOR PLAY NUMBERS. QUESTIONS WILL BE" */
line_227:
    printf("%s", "FIELD GOAL, INPUT 77,77 FOR PLAY NUMBERS. QUESTIONS WILL BE"); printf("\n");
    /* BASIC: 230 PRINT "ASKED THEN. ON 4TH DOWN, YOU WILL ALSO BE ASKED WHETHER" */
line_230:
    printf("%s", "ASKED THEN. ON 4TH DOWN, YOU WILL ALSO BE ASKED WHETHER"); printf("\n");
    /* BASIC: 240 PRINT "YOU WANT TO PUNT OR ATTEMPT A FIELD GOAL. IF THE ANSWER TO" */
line_240:
    printf("%s", "YOU WANT TO PUNT OR ATTEMPT A FIELD GOAL. IF THE ANSWER TO"); printf("\n");
    /* BASIC: 250 PRINT "BOTH QUESTIONS IS NO IT WILL BE ASSUMED YOU WANT TO" */
line_250:
    printf("%s", "BOTH QUESTIONS IS NO IT WILL BE ASSUMED YOU WANT TO"); printf("\n");
    /* BASIC: 260 PRINT "TRY AND GAIN YARDAGE. ANSWER ALL QUESTIONS YES OR NO." */
line_260:
    printf("%s", "TRY AND GAIN YARDAGE. ANSWER ALL QUESTIONS YES OR NO."); printf("\n");
    /* BASIC: 270 PRINT "THE GAME IS PLAYED UNTIL PLAYERS TERMINATE (CONTROL-C)." */
line_270:
    printf("%s", "THE GAME IS PLAYED UNTIL PLAYERS TERMINATE (CONTROL-C)."); printf("\n");
    /* BASIC: 280 PRINT "PLEASE PREPARE A TAPE AND RUN.": STOP */
line_280:
    printf("%s", "PLEASE PREPARE A TAPE AND RUN."); printf("\n");
    exit(0);
    /* BASIC: 290 PRINT:PRINT "PLEASE INPUT SCORE LIMIT ON GAME";:INPUT E */
line_290:
    printf("\n");
    printf("%s", "PLEASE INPUT SCORE LIMIT ON GAME");
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &E);
    /* BASIC: 300 FOR I=1 TO 40: READ N: IF I>20 THEN 350 */
line_300:
    I = 1; for_loop_I: if ((1 >= 0 && I > 40) || (1 < 0 && I < 40)) goto end_for_I;
    /* UNTRANSLATED: READ N */
    if (I>20) goto line_350;
    /* BASIC: 330 A(N)=I: GOTO 360 */
line_330:
    A(N) = I;
    goto line_360;
    /* BASIC: 350 B(N)=I-20 */
line_350:
    B(N) = I-20;
    /* BASIC: 360 C(I)=N: NEXT I */
line_360:
    C(I) = N;
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 370 FOR I=1 TO 20: READ P$(I): NEXT I */
line_370:
    I = 1; for_loop_I: if ((1 >= 0 && I > 20) || (1 < 0 && I < 20)) goto end_for_I;
    /* UNTRANSLATED: READ P$(I) */
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 380 L=0: T=1 */
line_380:
    L = 0;
    T = 1;
    /* BASIC: 410 PRINT "TEAM";T;"PLAY CHART" */
line_410:
    printf("%s", "TEAM"); printf("%g ", (double)(T)); printf("%s", "PLAY CHART"); printf("\n");
    /* BASIC: 420 PRINT "NO.      PLAY" */
line_420:
    printf("%s", "NO.      PLAY"); printf("\n");
    /* BASIC: 430 FOR I=1 TO 20 */
line_430:
    I = 1; for_loop_I: if ((1 >= 0 && I > 20) || (1 < 0 && I < 20)) goto end_for_I;
    /* BASIC: 440 REM */
line_440:
    // REM
    /* BASIC: 450 PRINT C(I+L);TAB(6);P$(I) */
line_450:
    printf("%g ", (double)(C(I+L))); { int _t; for(_t=0; _t<6; _t++) printf(" "); } printf("%g ", (double)(P$(I))); printf("\n");
    /* BASIC: 460 NEXT I */
line_460:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 630 L=L+20:T=2 */
line_630:
    L = L+20;
    T = 2;
    /* BASIC: 640 PRINT */
line_640:
    printf("\n");
    /* BASIC: 650 PRINT "TEAR OFF HERE----------------------------------------------" */
line_650:
    printf("%s", "TEAR OFF HERE----------------------------------------------"); printf("\n");
    /* BASIC: 660 FOR X=1 TO 11: PRINT: NEXT X */
line_660:
    X = 1; for_loop_X: if ((1 >= 0 && X > 11) || (1 < 0 && X < 11)) goto end_for_X;
    printf("\n");
    X += 1; goto for_loop_X; end_for_X:;
    /* BASIC: 670 FOR Z=1 TO 3000: NEXT Z */
line_670:
    Z = 1; for_loop_Z: if ((1 >= 0 && Z > 3000) || (1 < 0 && Z < 3000)) goto end_for_Z;
    Z += 1; goto for_loop_Z; end_for_Z:;
    /* BASIC: 680 IF L=20 THEN 410 */
line_680:
    if (L==20) goto line_410;
    /* BASIC: 690 D(1)=0: D(2)=3: M$(1)="--->": M$(2)="<---" */
line_690:
    D(1) = 0;
    D(2) = 3;
    M$(1) = "--->";
    M$(2) = "<---";
    /* BASIC: 700 H(1)=0: H(2)=0: T(1)=2: T(2)=1 */
line_700:
    H(1) = 0;
    H(2) = 0;
    T(1) = 2;
    T(2) = 1;
    /* BASIC: 710 W(1)=-1: W(2)=1: X(1)=100: X(2)=0 */
line_710:
    W(1) = -1;
    W(2) = 1;
    X(1) = 100;
    X(2) = 0;
    /* BASIC: 720 Y(1)=1: Y(2)=-1: Z(1)=0: Z(2)=100 */
line_720:
    Y(1) = 1;
    Y(2) = -1;
    Z(1) = 0;
    Z(2) = 100;
    /* BASIC: 725 GOSUB 1910 */
line_725:
    /* TODO: GOSUB 1910 */
    /* BASIC: 730 PRINT "TEAM 1 DEFENDS 0 YD GOAL -- TEAM 2 DEFENDS 100 YD GOAL." */
line_730:
    printf("%s", "TEAM 1 DEFENDS 0 YD GOAL -- TEAM 2 DEFENDS 100 YD GOAL."); printf("\n");
    /* BASIC: 740 T=INT(2*RND(1)+1) */
line_740:
    T = floor(2*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 760 PRINT: PRINT "THE COIN IS FLIPPED" */
line_760:
    printf("\n");
    printf("%s", "THE COIN IS FLIPPED"); printf("\n");
    /* BASIC: 765 P=X(T)-Y(T)*40 */
line_765:
    P = X(T)-Y(T)*40;
    /* BASIC: 770 GOSUB 1860: PRINT : PRINT "TEAM";T;"RECEIVES KICK-OFF" */
line_770:
    /* TODO: GOSUB 1860 */
    printf("\n");
    printf("%s", "TEAM"); printf("%g ", (double)(T)); printf("%s", "RECEIVES KICK-OFF"); printf("\n");
    /* BASIC: 780 K=INT(26*RND(1)+40) */
line_780:
    K = floor(26*((double)rand() / (double)RAND_MAX)+40);
    /* BASIC: 790 P=P-Y(T)*K */
line_790:
    P = P-Y(T)*K;
    /* BASIC: 794 IF W(T)*P<Z(T)+10 THEN 810 */
line_794:
    if (W(T)*P<Z(T)+10) goto line_810;
    /* BASIC: 795 PRINT: PRINT "BALL WENT OUT OF ENDZONE --AUTOMATIC TOUCHBACK--" */
line_795:
    printf("\n");
    printf("%s", "BALL WENT OUT OF ENDZONE --AUTOMATIC TOUCHBACK--"); printf("\n");
    /* BASIC: 796 GOTO 870 */
line_796:
    goto line_870;
    /* BASIC: 810 PRINT "BALL WENT";K;"YARDS.  NOW ON";P:GOSUB 1900 */
line_810:
    printf("%s", "BALL WENT"); printf("%g ", (double)(K)); printf("%s", "YARDS.  NOW ON"); printf("%g ", (double)(P)); printf("\n");
    /* TODO: GOSUB 1900 */
    /* BASIC: 830 PRINT "TEAM";T;"DO YOU WANT TO RUNBACK";:INPUT A$ */
line_830:
    printf("%s", "TEAM"); printf("%g ", (double)(T)); printf("%s", "DO YOU WANT TO RUNBACK");
    printf("? "); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    /* BASIC: 840 IF A$="YES" THEN 1430 */
line_840:
    if (A$=="YES") goto line_1430;
    /* BASIC: 845 IF A$<>"NO" THEN 830 */
line_845:
    if (A$!="NO") goto line_830;
    /* BASIC: 850 IF W(T)*P<Z(T) THEN 880 */
line_850:
    if (W(T)*P<Z(T)) goto line_880;
    /* BASIC: 870 P=Z(T)-W(T)*20 */
line_870:
    P = Z(T)-W(T)*20;
    /* BASIC: 880 D=1: S=P */
line_880:
    D = 1;
    S = P;
    /* BASIC: 885 FOR I=1 TO 72: PRINT "=";: NEXT I */
line_885:
    I = 1; for_loop_I: if ((1 >= 0 && I > 72) || (1 < 0 && I < 72)) goto end_for_I;
    printf("%s", "=");
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 890 PRINT: PRINT "TEAM";T;"DOWN";D;"ON";P */
line_890:
    printf("\n");
    printf("%s", "TEAM"); printf("%g ", (double)(T)); printf("%s", "DOWN"); printf("%g ", (double)(D)); printf("%s", "ON"); printf("%g ", (double)(P)); printf("\n");
    /* BASIC: 893 IF D<>1 THEN 900 */
line_893:
    if (D!=1) goto line_900;
    /* BASIC: 895 IF Y(T)*(P+Y(T)*10)>=X(T) THEN 898 */
line_895:
    if (Y(T)*(P+Y(T)*10)>==X(T)) goto line_898;
    /* BASIC: 897 C=4: GOTO 900 */
line_897:
    C = 4;
    goto line_900;
    /* BASIC: 898 C=8 */
line_898:
    C = 8;
    /* BASIC: 900 IF C=8 THEN 904 */
line_900:
    if (C==8) goto line_904;
    /* BASIC: 901 PRINT TAB(27);10-(Y(T)*P-Y(T)*S);"YARDS TO 1ST DOWN" */
line_901:
    { int _t; for(_t=0; _t<27; _t++) printf(" "); } printf("%g ", (double)(10-(Y(T)*P-Y(T)*S))); printf("%s", "YARDS TO 1ST DOWN"); printf("\n");
    /* BASIC: 902 GOTO 910 */
line_902:
    goto line_910;
    /* BASIC: 904 PRINT TAB(27);X(T)-Y(T)*P;"YARDS" */
line_904:
    { int _t; for(_t=0; _t<27; _t++) printf(" "); } printf("%g ", (double)(X(T)-Y(T)*P)); printf("%s", "YARDS"); printf("\n");
    /* BASIC: 910 GOSUB 1900: IF D=4 THEN 1180 */
line_910:
    /* TODO: GOSUB 1900 */
    if (D==4) goto line_1180;
    /* BASIC: 920 REM */
line_920:
    // REM
    /* BASIC: 930 U=INT(3*RND(0)-1): GOTO 940 */
line_930:
    U = floor(3*((double)rand() / (double)RAND_MAX)-1);
    goto line_940;
    /* BASIC: 936 PRINT "ILLEGAL PLAY NUMBER, CHECK AND" */
line_936:
    printf("%s", "ILLEGAL PLAY NUMBER, CHECK AND"); printf("\n");
    /* BASIC: 940 PRINT "INPUT OFFENSIVE PLAY, DEFENSIVE PLAY"; */
line_940:
    printf("%s", "INPUT OFFENSIVE PLAY, DEFENSIVE PLAY");
    /* BASIC: 950 IF T=2 THEN 970 */
line_950:
    if (T==2) goto line_970;
    /* BASIC: 960 INPUT P1,P2: GOTO 975 */
line_960:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &P1,P2);
    goto line_975;
    /* BASIC: 970 INPUT P2,P1 */
line_970:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &P2,P1);
    /* BASIC: 975 IF P1=77 THEN 1180 */
line_975:
    if (P1==77) goto line_1180;
    /* BASIC: 980 IF P1>20 THEN 1800 */
line_980:
    if (P1>20) goto line_1800;
    /* BASIC: 985 IF P1<1 THEN 1800 */
line_985:
    if (P1<1) goto line_1800;
    /* BASIC: 990 IF P2>20 THEN 1800 */
line_990:
    if (P2>20) goto line_1800;
    /* BASIC: 992 IF P2<1 THEN 1800 */
line_992:
    if (P2<1) goto line_1800;
    /* BASIC: 995 P1=INT(P1): P2=INT(P2) */
line_995:
    P1 = floor(P1);
    P2 = floor(P2);
    /* BASIC: 1000 Y=INT(ABS(A(P1)-B(P2))/19*((X(T)-Y(T)*P+25)*RND(1)-15)) */
line_1000:
    Y = floor(fabs(A(P1)-B(P2))/19*((X(T)-Y(T)*P+25)*((double)rand() / (double)RAND_MAX)-15));
    /* BASIC: 1005 PRINT: IF T=2 THEN 1015 */
line_1005:
    printf("\n");
    if (T==2) goto line_1015;
    /* BASIC: 1010 IF A(P1)<11 THEN 1048 */
line_1010:
    if (A(P1)<11) goto line_1048;
    /* BASIC: 1012 GOTO 1020 */
line_1012:
    goto line_1020;
    /* BASIC: 1015 IF B(P2)<11 THEN 1048 */
line_1015:
    if (B(P2)<11) goto line_1048;
    /* BASIC: 1020 IF U<>0 THEN 1035 */
line_1020:
    if (U!=0) goto line_1035;
    /* BASIC: 1025 PRINT "PASS INCOMPLETE TEAM";T */
line_1025:
    printf("%s", "PASS INCOMPLETE TEAM"); printf("%g ", (double)(T)); printf("\n");
    /* BASIC: 1030 Y=0: GOTO 1050 */
line_1030:
    Y = 0;
    goto line_1050;
    /* BASIC: 1035 G=RND(1): IF G>.025 THEN 1040 */
line_1035:
    G = ((double)rand() / (double)RAND_MAX);
    if (G>.025) goto line_1040;
    /* BASIC: 1037 IF Y>2 THEN 1045 */
line_1037:
    if (Y>2) goto line_1045;
    /* BASIC: 1040 PRINT "QUARTERBACK SCRAMBLED": GOTO 1050 */
line_1040:
    printf("%s", "QUARTERBACK SCRAMBLED"); printf("\n");
    goto line_1050;
    /* BASIC: 1045 PRINT "PASS COMPLETED": GOTO 1050 */
line_1045:
    printf("%s", "PASS COMPLETED"); printf("\n");
    goto line_1050;
    /* BASIC: 1048 PRINT "THE BALL WAS RUN" */
line_1048:
    printf("%s", "THE BALL WAS RUN"); printf("\n");
    /* BASIC: 1050 P=P-W(T)*Y */
line_1050:
    P = P-W(T)*Y;
    /* BASIC: 1060 PRINT: PRINT "NET YARDS GAINED ON DOWN";D;"ARE ";Y */
line_1060:
    printf("\n");
    printf("%s", "NET YARDS GAINED ON DOWN"); printf("%g ", (double)(D)); printf("%s", "ARE "); printf("%g ", (double)(Y)); printf("\n");
    /* BASIC: 1070 G=RND(1): IF G>.025 THEN 1110 */
line_1070:
    G = ((double)rand() / (double)RAND_MAX);
    if (G>.025) goto line_1110;
    /* BASIC: 1080 PRINT: PRINT "** LOSS OF POSSESSION FROM TEAM";T;"TO TEAM";T(T) */
line_1080:
    printf("\n");
    printf("%s", "** LOSS OF POSSESSION FROM TEAM"); printf("%g ", (double)(T)); printf("%s", "TO TEAM"); printf("%g ", (double)(T(T))); printf("\n");
    /* BASIC: 1100 GOSUB 1850: PRINT: T=T(T): GOTO 830 */
line_1100:
    /* TODO: GOSUB 1850 */
    printf("\n");
    T = T(T);
    goto line_830;
    /* BASIC: 1110 IF Y(T)*P>=X(T) THEN 1320 */
line_1110:
    if (Y(T)*P>==X(T)) goto line_1320;
    /* BASIC: 1120 IF W(T)*P>=Z(T) THEN 1230 */
line_1120:
    if (W(T)*P>==Z(T)) goto line_1230;
    /* BASIC: 1130 IF Y(T)*P-Y(T)*S>=10 THEN 880 */
line_1130:
    if (Y(T)*P-Y(T)*S>==10) goto line_880;
    /* BASIC: 1140 D=D+1: IF D<>5 THEN 885 */
line_1140:
    D = D+1;
    if (D!=5) goto line_885;
    /* BASIC: 1160 PRINT: PRINT "CONVERSION UNSUCCESSFUL TEAM";T:T=T(T) */
line_1160:
    printf("\n");
    printf("%s", "CONVERSION UNSUCCESSFUL TEAM"); printf("%g ", (double)(T)); printf("\n");
    T = T(T);
    /* BASIC: 1170 GOSUB 1850: GOTO 880 */
line_1170:
    /* TODO: GOSUB 1850 */
    goto line_880;
    /* BASIC: 1180 PRINT "DOES TEAM";T;"WANT TO PUNT";: INPUT A$ */
line_1180:
    printf("%s", "DOES TEAM"); printf("%g ", (double)(T)); printf("%s", "WANT TO PUNT");
    printf("? "); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    /* BASIC: 1185 IF A$="NO" THEN 1200 */
line_1185:
    if (A$=="NO") goto line_1200;
    /* BASIC: 1187 IF A$<>"YES" THEN 1180 */
line_1187:
    if (A$!="YES") goto line_1180;
    /* BASIC: 1190 PRINT:PRINT "TEAM";T;"WILL PUNT": G=RND(1): IF G<.025 THEN 1080 */
line_1190:
    printf("\n");
    printf("%s", "TEAM"); printf("%g ", (double)(T)); printf("%s", "WILL PUNT"); printf("\n");
    G = ((double)rand() / (double)RAND_MAX);
    if (G<.025) goto line_1080;
    /* BASIC: 1195 GOSUB 1850: K=INT(25*RND(1)+35): T=T(T): GOTO 790 */
line_1195:
    /* TODO: GOSUB 1850 */
    K = floor(25*((double)rand() / (double)RAND_MAX)+35);
    T = T(T);
    goto line_790;
    /* BASIC: 1200 PRINT "DOES TEAM";T;"WANT TO ATTEMPT A FIELD GOAL";: INPUT A$ */
line_1200:
    printf("%s", "DOES TEAM"); printf("%g ", (double)(T)); printf("%s", "WANT TO ATTEMPT A FIELD GOAL");
    printf("? "); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    /* BASIC: 1210 IF A$="YES" THEN 1640 */
line_1210:
    if (A$=="YES") goto line_1640;
    /* BASIC: 1215 IF A$<>"NO" THEN 1200 */
line_1215:
    if (A$!="NO") goto line_1200;
    /* BASIC: 1217 GOTO 920 */
line_1217:
    goto line_920;
    /* BASIC: 1230 PRINT: PRINT "SAFETY AGAINST TEAM";T;"**********************OH-OH" */
line_1230:
    printf("\n");
    printf("%s", "SAFETY AGAINST TEAM"); printf("%g ", (double)(T)); printf("%s", "**********************OH-OH"); printf("\n");
    /* BASIC: 1240 H(T(T))=H(T(T))+2: GOSUB 1810 */
line_1240:
    H(T(T)) = H(T(T))+2;
    /* TODO: GOSUB 1810 */
    /* BASIC: 1280 PRINT"TEAM";T;"DO YOU WANT TO PUNT INSTEAD OF A KICKOFF";:INPUT A$ */
line_1280:
    printf("%s", "TEAM"); printf("%g ", (double)(T)); printf("%s", "DO YOU WANT TO PUNT INSTEAD OF A KICKOFF");
    printf("? "); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    /* BASIC: 1290 P=Z(T)-W(T)*20: IF A$="YES" THEN 1190 */
line_1290:
    P = Z(T)-W(T)*20;
    if (A$=="YES") goto line_1190;
    /* BASIC: 1320 PRINT: PRINT "TOUCHDOWN BY TEAM";T;"*********************YEA TEAM" */
line_1320:
    printf("\n");
    printf("%s", "TOUCHDOWN BY TEAM"); printf("%g ", (double)(T)); printf("%s", "*********************YEA TEAM"); printf("\n");
    /* BASIC: 1340 Q=7: G=RND(1): IF G>.1 THEN 1380 */
line_1340:
    Q = 7;
    G = ((double)rand() / (double)RAND_MAX);
    if (G>.1) goto line_1380;
    /* BASIC: 1360 Q=6: PRINT "EXTRA POINT NO GOOD": GOTO 1390 */
line_1360:
    Q = 6;
    printf("%s", "EXTRA POINT NO GOOD"); printf("\n");
    goto line_1390;
    /* BASIC: 1380 PRINT "EXTRA POINT GOOD" */
line_1380:
    printf("%s", "EXTRA POINT GOOD"); printf("\n");
    /* BASIC: 1390 H(T)=H(T)+Q: GOSUB 1810 */
line_1390:
    H(T) = H(T)+Q;
    /* TODO: GOSUB 1810 */
    /* BASIC: 1420 T=T(T): GOTO 765 */
line_1420:
    T = T(T);
    goto line_765;
    /* BASIC: 1430 K=INT(9*RND(0)+1) */
line_1430:
    K = floor(9*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 1440 R=INT(((X(T)-Y(T)*P+25)*RND(1)-15)/K) */
line_1440:
    R = floor(((X(T)-Y(T)*P+25)*((double)rand() / (double)RAND_MAX)-15)/K);
    /* BASIC: 1460 P=P-W(T)*R */
line_1460:
    P = P-W(T)*R;
    /* BASIC: 1480 PRINT:PRINT "RUNBACK TEAM";T;R;"YARDS" */
line_1480:
    printf("\n");
    printf("%s", "RUNBACK TEAM"); printf("%g ", (double)(T)); printf("%g ", (double)(R)); printf("%s", "YARDS"); printf("\n");
    /* BASIC: 1485 G=RND(1): IF G<.025 THEN 1080 */
line_1485:
    G = ((double)rand() / (double)RAND_MAX);
    if (G<.025) goto line_1080;
    /* BASIC: 1490 IF Y(T)*P>=X(T) THEN 1320 */
line_1490:
    if (Y(T)*P>==X(T)) goto line_1320;
    /* BASIC: 1500 IF W(T)*P>=Z(T) THEN 1230 */
line_1500:
    if (W(T)*P>==Z(T)) goto line_1230;
    /* BASIC: 1510 GOTO 880 */
line_1510:
    goto line_880;
    /* BASIC: 1640 PRINT: PRINT "TEAM";T;"WILL ATTEMPT A FIELD GOAL" */
line_1640:
    printf("\n");
    printf("%s", "TEAM"); printf("%g ", (double)(T)); printf("%s", "WILL ATTEMPT A FIELD GOAL"); printf("\n");
    /* BASIC: 1645 G=RND(1): IF G<.025 THEN 1080 */
line_1645:
    G = ((double)rand() / (double)RAND_MAX);
    if (G<.025) goto line_1080;
    /* BASIC: 1650 F=INT(35*RND(1)+20) */
line_1650:
    F = floor(35*((double)rand() / (double)RAND_MAX)+20);
    /* BASIC: 1660 PRINT: PRINT "KICK IS";F;"YARDS LONG" */
line_1660:
    printf("\n");
    printf("%s", "KICK IS"); printf("%g ", (double)(F)); printf("%s", "YARDS LONG"); printf("\n");
    /* BASIC: 1680 P=P-W(T)*F: G=RND(1) */
line_1680:
    P = P-W(T)*F;
    G = ((double)rand() / (double)RAND_MAX);
    /* BASIC: 1690 IF G<.35 THEN 1735 */
line_1690:
    if (G<.35) goto line_1735;
    /* BASIC: 1700 IF Y(T)*P<X(T) THEN 1740 */
line_1700:
    if (Y(T)*P<X(T)) goto line_1740;
    /* BASIC: 1710 PRINT "FIELD GOAL GOOD FOR TEAM";T;"*********************YEA" */
line_1710:
    printf("%s", "FIELD GOAL GOOD FOR TEAM"); printf("%g ", (double)(T)); printf("%s", "*********************YEA"); printf("\n");
    /* BASIC: 1720 Q=3: GOTO 1390 */
line_1720:
    Q = 3;
    goto line_1390;
    /* BASIC: 1735 PRINT "BALL WENT WIDE" */
line_1735:
    printf("%s", "BALL WENT WIDE"); printf("\n");
    /* BASIC: 1740 PRINT "FIELD GOAL UNSUCCESFUL TEAM";T;"-----------------TOO BAD" */
line_1740:
    printf("%s", "FIELD GOAL UNSUCCESFUL TEAM"); printf("%g ", (double)(T)); printf("%s", "-----------------TOO BAD"); printf("\n");
    /* BASIC: 1742 GOSUB 1850: IF Y(T)*P<X(T)+10 THEN 1745 */
line_1742:
    /* TODO: GOSUB 1850 */
    if (Y(T)*P<X(T)+10) goto line_1745;
    /* BASIC: 1744 T=T(T): GOTO 794 */
line_1744:
    T = T(T);
    goto line_794;
    /* BASIC: 1745 PRINT: PRINT "BALL NOW ON";P */
line_1745:
    printf("\n");
    printf("%s", "BALL NOW ON"); printf("%g ", (double)(P)); printf("\n");
    /* BASIC: 1750 T=T(T): GOSUB 1900: GOTO 830 */
line_1750:
    T = T(T);
    /* TODO: GOSUB 1900 */
    goto line_830;
    /* BASIC: 1770 DATA 17,8,4,14,19,3,10,1,7,11,15,9,5,20,13,18,16,2,12,6 */
line_1770:
    /* UNTRANSLATED: DATA 17,8,4,14,19,3,10,1,7,11,15,9,5,20,13,18,16,2,12,6 */
    /* BASIC: 1780 DATA 20,2,17,5,8,18,12,11,1,4,19,14,10,7,9,15,6,13,16,3 */
line_1780:
    /* UNTRANSLATED: DATA 20,2,17,5,8,18,12,11,1,4,19,14,10,7,9,15,6,13,16,3 */
    /* BASIC: 1790 DATA "PITCHOUT","TRIPLE REVERSE","DRAW","QB SNEAK","END AROUND" */
line_1790:
    /* UNTRANSLATED: DATA "PITCHOUT","TRIPLE REVERSE","DRAW","QB SNEAK","END AROUND" */
    /* BASIC: 1792 DATA "DOUBLE REVERSE","LEFT SWEEP","RIGHT SWEEP","OFF TACKLE" */
line_1792:
    /* UNTRANSLATED: DATA "DOUBLE REVERSE","LEFT SWEEP","RIGHT SWEEP","OFF TACKLE" */
    /* BASIC: 1794 DATA "WISHBONE OPTION","FLARE PASS","SCREEN PASS" */
line_1794:
    /* UNTRANSLATED: DATA "WISHBONE OPTION","FLARE PASS","SCREEN PASS" */
    /* BASIC: 1796 DATA "ROLL OUT OPTION","RIGHT CURL","LEFT CURL","WISHBONE OPTION" */
line_1796:
    /* UNTRANSLATED: DATA "ROLL OUT OPTION","RIGHT CURL","LEFT CURL","WISHBONE OPTION" */
    /* BASIC: 1798 DATA "SIDELINE PASS","HALF-BACK OPTION","RAZZLE-DAZZLE","BOMB!!!!" */
line_1798:
    /* UNTRANSLATED: DATA "SIDELINE PASS","HALF-BACK OPTION","RAZZLE-DAZZLE","BOMB!!!!" */
    /* BASIC: 1800 IF P1<>99 THEN 936 */
line_1800:
    if (P1!=99) goto line_936;
    /* BASIC: 1810 PRINT: PRINT "TEAM 1 SCORE IS";H(1) */
line_1810:
    printf("\n");
    printf("%s", "TEAM 1 SCORE IS"); printf("%g ", (double)(H(1))); printf("\n");
    /* BASIC: 1820 PRINT "TEAM 2 SCORE IS";H(2): PRINT */
line_1820:
    printf("%s", "TEAM 2 SCORE IS"); printf("%g ", (double)(H(2))); printf("\n");
    printf("\n");
    /* BASIC: 1825 IF H(T)<E THEN 1830 */
line_1825:
    if (H(T)<E) goto line_1830;
    /* BASIC: 1827 PRINT "TEAM";T;"WINS*******************": GOTO 2000 */
line_1827:
    printf("%s", "TEAM"); printf("%g ", (double)(T)); printf("%s", "WINS*******************"); printf("\n");
    goto line_2000;
    /* BASIC: 1830 IF P1=99 THEN 940 */
line_1830:
    if (P1==99) goto line_940;
    /* BASIC: 1835 RETURN */
line_1835:
    /* TODO: RETURN */
    /* BASIC: 1850 PRINT */
line_1850:
    printf("\n");
    /* BASIC: 1860 FOR X=1 TO 72: PRINT "+";: NEXT X: PRINT */
line_1860:
    X = 1; for_loop_X: if ((1 >= 0 && X > 72) || (1 < 0 && X < 72)) goto end_for_X;
    printf("%s", "+");
    X += 1; goto for_loop_X; end_for_X:;
    printf("\n");
    /* BASIC: 1870 RETURN */
line_1870:
    /* TODO: RETURN */
    /* BASIC: 1900 PRINT TAB(D(T)+5+P/2);M$(T) */
line_1900:
    { int _t; for(_t=0; _t<D(T)+5+P/2; _t++) printf(" "); } printf("%g ", (double)(M$(T))); printf("\n");
    /* BASIC: 1910 PRINT "TEAM 1 [0   10   20   30   40   50   60   70   80   90"; */
line_1910:
    printf("%s", "TEAM 1 [0   10   20   30   40   50   60   70   80   90");
    /* BASIC: 1915 PRINT "   100] TEAM 2" */
line_1915:
    printf("%s", "   100] TEAM 2"); printf("\n");
    /* BASIC: 1920 PRINT */
line_1920:
    printf("\n");
    /* BASIC: 1930 RETURN */
line_1930:
    /* TODO: RETURN */
    /* BASIC: 2000 END */
line_2000:
    exit(0);

    return 0;
}
