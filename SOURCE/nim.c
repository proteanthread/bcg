/*
 * Transpiled from nim.bas
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
static int gosub_stack[256];
static int gosub_sp = 0;
static double A, B, C, D, E, F, G, H, I, J, LET, N, W, X, Y, Z;
static char Q9_str[256] = {0};
static char Z_str[256] = {0};
static double A_arr[20000] = {0};
static double B_arr[20000] = {0};
static double D_arr[20000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 100 PRINT TAB(33);"NIM" */
line_100:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "NIM"); printf("\n");
    /* BASIC: 110 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_110:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 120 PRINT:PRINT:PRINT */
line_120:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 210 DIM A(100),B(100,10),D(2) */
line_210:;
    /* DIM A(100),B(100,10),D(2) (handled statically) */
    /* BASIC: 220 PRINT "THIS IS THE GAME OF NIM." */
line_220:;
    printf("%s", "THIS IS THE GAME OF NIM."); printf("\n");
    /* BASIC: 230 PRINT "DO YOU WANT INSTRUCTIONS"; */
line_230:;
    printf("%s", "DO YOU WANT INSTRUCTIONS");
    /* BASIC: 240 INPUT Z$ */
line_240:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", Z_str);
    /* BASIC: 250 IF Z$="NO" THEN 440 */
line_250:;
    if (strcmp(Z_str, "NO") == 0) { goto line_440; }
    /* BASIC: 260 IF Z$="no" THEN 440 */
line_260:;
    if (strcmp(Z_str, "no") == 0) { goto line_440; }
    /* BASIC: 270 IF Z$="YES" THEN 310 */
line_270:;
    if (strcmp(Z_str, "YES") == 0) { goto line_310; }
    /* BASIC: 280 IF Z$="yes" THEN 310 */
line_280:;
    if (strcmp(Z_str, "yes") == 0) { goto line_310; }
    /* BASIC: 290 PRINT "PLEASE ANSWER YES OR NO" */
line_290:;
    printf("%s", "PLEASE ANSWER YES OR NO"); printf("\n");
    /* BASIC: 300 GOTO 240 */
line_300:;
    goto line_240;
    /* BASIC: 310 PRINT "THE GAME IS PLAYED WITH A NUMBER OF PILES OF OBJECTS." */
line_310:;
    printf("%s", "THE GAME IS PLAYED WITH A NUMBER OF PILES OF OBJECTS."); printf("\n");
    /* BASIC: 320 PRINT "ANY NUMBER OF OBJECTS ARE REMOVED FROM ONE PILE BY YOU AND" */
line_320:;
    printf("%s", "ANY NUMBER OF OBJECTS ARE REMOVED FROM ONE PILE BY YOU AND"); printf("\n");
    /* BASIC: 330 PRINT "THE MACHINE ALTERNATELY.  ON YOUR TURN, YOU MAY TAKE" */
line_330:;
    printf("%s", "THE MACHINE ALTERNATELY.  ON YOUR TURN, YOU MAY TAKE"); printf("\n");
    /* BASIC: 340 PRINT "ALL THE OBJECTS THAT REMAIN IN ANY PILE, BUT YOU MUST" */
line_340:;
    printf("%s", "ALL THE OBJECTS THAT REMAIN IN ANY PILE, BUT YOU MUST"); printf("\n");
    /* BASIC: 350 PRINT "TAKE AT LEAST ONE OBJECT, AND YOU MAY TAKE OBJECTS FROM" */
line_350:;
    printf("%s", "TAKE AT LEAST ONE OBJECT, AND YOU MAY TAKE OBJECTS FROM"); printf("\n");
    /* BASIC: 360 PRINT "ONLY ONE PILE ON A SINGLE TURN.  YOU MUST SPECIFY WHETHER" */
line_360:;
    printf("%s", "ONLY ONE PILE ON A SINGLE TURN.  YOU MUST SPECIFY WHETHER"); printf("\n");
    /* BASIC: 370 PRINT "WINNING IS DEFINED AS TAKING OR NOT TAKING THE LAST OBJECT," */
line_370:;
    printf("%s", "WINNING IS DEFINED AS TAKING OR NOT TAKING THE LAST OBJECT,"); printf("\n");
    /* BASIC: 380 PRINT "THE NUMBER OF PILES IN THE GAME, AND HOW MANY OBJECTS ARE" */
line_380:;
    printf("%s", "THE NUMBER OF PILES IN THE GAME, AND HOW MANY OBJECTS ARE"); printf("\n");
    /* BASIC: 390 PRINT "ORIGINALLY IN EACH PILE.  EACH PILE MAY CONTAIN A" */
line_390:;
    printf("%s", "ORIGINALLY IN EACH PILE.  EACH PILE MAY CONTAIN A"); printf("\n");
    /* BASIC: 400 PRINT "DIFFERENT NUMBER OF OBJECTS." */
line_400:;
    printf("%s", "DIFFERENT NUMBER OF OBJECTS."); printf("\n");
    /* BASIC: 410 PRINT "THE MACHINE WILL SHOW ITS MOVE BY LISTING EACH PILE AND THE" */
line_410:;
    printf("%s", "THE MACHINE WILL SHOW ITS MOVE BY LISTING EACH PILE AND THE"); printf("\n");
    /* BASIC: 420 PRINT "NUMBER OF OBJECTS REMAINING IN THE PILES AFTER  EACH OF ITS" */
line_420:;
    printf("%s", "NUMBER OF OBJECTS REMAINING IN THE PILES AFTER  EACH OF ITS"); printf("\n");
    /* BASIC: 430 PRINT "MOVES." */
line_430:;
    printf("%s", "MOVES."); printf("\n");
    /* BASIC: 440 PRINT */
line_440:;
    printf("\n");
    /* BASIC: 450 PRINT "ENTER WIN OPTION - 1 TO TAKE LAST, 2 TO AVOID LAST"; */
line_450:;
    printf("%s", "ENTER WIN OPTION - 1 TO TAKE LAST, 2 TO AVOID LAST");
    /* BASIC: 460 INPUT W */
line_460:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &W);
    /* BASIC: 470 IF W=1 THEN 490 */
line_470:;
    if (W==1) { goto line_490; }
    /* BASIC: 480 IF W<>2 THEN 450 */
line_480:;
    if (W!=2) { goto line_450; }
    /* BASIC: 490 PRINT "ENTER NUMBER OF PILES"; */
line_490:;
    printf("%s", "ENTER NUMBER OF PILES");
    /* BASIC: 500 INPUT N */
line_500:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &N);
    /* BASIC: 510 IF N>100 THEN 490 */
line_510:;
    if (N>100) { goto line_490; }
    /* BASIC: 520 IF N<1 THEN 490 */
line_520:;
    if (N<1) { goto line_490; }
    /* BASIC: 530 IF N<>INT(N) THEN 490 */
line_530:;
    if (N!=floor(N)) { goto line_490; }
    /* BASIC: 540 PRINT "ENTER PILE SIZES" */
line_540:;
    printf("%s", "ENTER PILE SIZES"); printf("\n");
    /* BASIC: 550 FOR I=1 TO N */
line_550:;
    I = 1; for_loop_I_550: if (((1) >= 0 && I > (N)) || ((1) < 0 && I < (N))) goto end_for_I_550;
    /* BASIC: 560 PRINT I; */
line_560:;
    printf("%g ", (double)(I));
    /* BASIC: 570 INPUT A(I) */
line_570:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &(A_arr[(int)(I)]));
    /* BASIC: 580 IF A(I)>2000 THEN 560 */
line_580:;
    if (A_arr[(int)(I)]>2000) { goto line_560; }
    /* BASIC: 590 IF A(I)<1 THEN 560 */
line_590:;
    if (A_arr[(int)(I)]<1) { goto line_560; }
    /* BASIC: 600 IF A(I)<>INT(A(I)) THEN 560 */
line_600:;
    if (A_arr[(int)(I)]!=floor(A_arr[(int)(I)])) { goto line_560; }
    /* BASIC: 610 NEXT I */
line_610:;
    I += (1); goto for_loop_I_550; end_for_I_550:;
    /* BASIC: 620 PRINT "DO YOU WANT TO MOVE FIRST"; */
line_620:;
    printf("%s", "DO YOU WANT TO MOVE FIRST");
    /* BASIC: 630 INPUT Q9$ */
line_630:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", Q9_str);
    /* BASIC: 640 IF Q9$="YES" THEN 1450 */
line_640:;
    if (strcmp(Q9_str, "YES") == 0) { goto line_1450; }
    /* BASIC: 650 IF Q9$="yes" THEN 1450 */
line_650:;
    if (strcmp(Q9_str, "yes") == 0) { goto line_1450; }
    /* BASIC: 660 IF Q9$="NO" THEN 700 */
line_660:;
    if (strcmp(Q9_str, "NO") == 0) { goto line_700; }
    /* BASIC: 670 IF Q9$="no" THEN 700 */
line_670:;
    if (strcmp(Q9_str, "no") == 0) { goto line_700; }
    /* BASIC: 680 PRINT "PLEASE ANSWER YES OR NO." */
line_680:;
    printf("%s", "PLEASE ANSWER YES OR NO."); printf("\n");
    /* BASIC: 690 GOTO 630 */
line_690:;
    goto line_630;
    /* BASIC: 700 IF W=1 THEN 940 */
line_700:;
    if (W==1) { goto line_940; }
    /* BASIC: 710 LET C=0 */
line_710:;
    /* UNTRANSLATED: LET C=0 */
    /* BASIC: 720 FOR I=1 TO N */
line_720:;
    I = 1; for_loop_I_720: if (((1) >= 0 && I > (N)) || ((1) < 0 && I < (N))) goto end_for_I_720;
    /* BASIC: 730 IF A(I)=0 THEN 770 */
line_730:;
    if (A_arr[(int)(I)]==0) { goto line_770; }
    /* BASIC: 740 LET C=C+1 */
line_740:;
    /* UNTRANSLATED: LET C=C+1 */
    /* BASIC: 750 IF C=3 THEN 840 */
line_750:;
    if (C==3) { goto line_840; }
    /* BASIC: 760 LET D(C)=I */
line_760:;
    /* UNTRANSLATED: LET D(C)=I */
    /* BASIC: 770 NEXT I */
line_770:;
    I += (1); goto for_loop_I_720; end_for_I_720:;
    /* BASIC: 780 IF C=2 THEN 920 */
line_780:;
    if (C==2) { goto line_920; }
    /* BASIC: 790 IF A(D(1))>1 THEN 820 */
line_790:;
    if (A_arr[(int)(D_arr[(int)(1)])]>1) { goto line_820; }
    /* BASIC: 800 PRINT "MACHINE LOSES" */
line_800:;
    printf("%s", "MACHINE LOSES"); printf("\n");
    /* BASIC: 810 GOTO 1640 */
line_810:;
    goto line_1640;
    /* BASIC: 820 PRINT "MACHINE WINS" */
line_820:;
    printf("%s", "MACHINE WINS"); printf("\n");
    /* BASIC: 830 GOTO 1640 */
line_830:;
    goto line_1640;
    /* BASIC: 840 LET C=0 */
line_840:;
    /* UNTRANSLATED: LET C=0 */
    /* BASIC: 850 FOR I=1 TO N */
line_850:;
    I = 1; for_loop_I_850: if (((1) >= 0 && I > (N)) || ((1) < 0 && I < (N))) goto end_for_I_850;
    /* BASIC: 860 IF A(I)>1 THEN 940 */
line_860:;
    if (A_arr[(int)(I)]>1) { goto line_940; }
    /* BASIC: 870 IF A(I)=0 THEN 890 */
line_870:;
    if (A_arr[(int)(I)]==0) { goto line_890; }
    /* BASIC: 880 LET C=C+1 */
line_880:;
    /* UNTRANSLATED: LET C=C+1 */
    /* BASIC: 890 NEXT I */
line_890:;
    I += (1); goto for_loop_I_850; end_for_I_850:;
    /* BASIC: 900 IF C/2<>INT(C/2) THEN 800 */
line_900:;
    if (C/2!=floor(C/2)) { goto line_800; }
    /* BASIC: 910 GOTO 940 */
line_910:;
    goto line_940;
    /* BASIC: 920 IF A(D(1))=1 THEN 820 */
line_920:;
    if (A_arr[(int)(D_arr[(int)(1)])]==1) { goto line_820; }
    /* BASIC: 930 IF A(D(2))=1 THEN 820 */
line_930:;
    if (A_arr[(int)(D_arr[(int)(2)])]==1) { goto line_820; }
    /* BASIC: 940 FOR I=1 TO N */
line_940:;
    I = 1; for_loop_I_940: if (((1) >= 0 && I > (N)) || ((1) < 0 && I < (N))) goto end_for_I_940;
    /* BASIC: 950 LET E=A(I) */
line_950:;
    /* UNTRANSLATED: LET E=A(I) */
    /* BASIC: 960 FOR J=0 TO 10 */
line_960:;
    J = 0; for_loop_J_960: if (((1) >= 0 && J > (10)) || ((1) < 0 && J < (10))) goto end_for_J_960;
    /* BASIC: 970 LET F=E/2 */
line_970:;
    /* UNTRANSLATED: LET F=E/2 */
    /* BASIC: 980 LET B(I,J)=2*(F-INT(F)) */
line_980:;
    /* UNTRANSLATED: LET B(I,J)=2*(F-INT(F)) */
    /* BASIC: 990 LET E=INT(F) */
line_990:;
    /* UNTRANSLATED: LET E=INT(F) */
    /* BASIC: 1000 NEXT J */
line_1000:;
    J += (1); goto for_loop_J_960; end_for_J_960:;
    /* BASIC: 1010 NEXT I */
line_1010:;
    I += (1); goto for_loop_I_940; end_for_I_940:;
    /* BASIC: 1020 FOR J=10 TO 0 STEP -1 */
line_1020:;
    J = 10; for_loop_J_1020: if (((-1) >= 0 && J > (0)) || ((-1) < 0 && J < (0))) goto end_for_J_1020;
    /* BASIC: 1030 LET C=0 */
line_1030:;
    /* UNTRANSLATED: LET C=0 */
    /* BASIC: 1040 LET H=0 */
line_1040:;
    /* UNTRANSLATED: LET H=0 */
    /* BASIC: 1050 FOR I=1 TO N */
line_1050:;
    I = 1; for_loop_I_1050: if (((1) >= 0 && I > (N)) || ((1) < 0 && I < (N))) goto end_for_I_1050;
    /* BASIC: 1060 IF B(I,J)=0 THEN 1110 */
line_1060:;
    if (B_arr[(int)(I) * 100 + (int)(J)]==0) { goto line_1110; }
    /* BASIC: 1070 LET C=C+1 */
line_1070:;
    /* UNTRANSLATED: LET C=C+1 */
    /* BASIC: 1080 IF A(I)<=H THEN 1110 */
line_1080:;
    if (A_arr[(int)(I)]<=H) { goto line_1110; }
    /* BASIC: 1090 LET H=A(I) */
line_1090:;
    /* UNTRANSLATED: LET H=A(I) */
    /* BASIC: 1100 LET G=I */
line_1100:;
    /* UNTRANSLATED: LET G=I */
    /* BASIC: 1110 NEXT I */
line_1110:;
    I += (1); goto for_loop_I_1050; end_for_I_1050:;
    /* BASIC: 1120 IF C/2<>INT(C/2) THEN 1190 */
line_1120:;
    if (C/2!=floor(C/2)) { goto line_1190; }
    /* BASIC: 1130 NEXT J */
line_1130:;
    J += (-1); goto for_loop_J_1020; end_for_J_1020:;
    /* BASIC: 1140 LET E=INT(N*RND(1)+1) */
line_1140:;
    /* UNTRANSLATED: LET E=INT(N*RND(1)+1) */
    /* BASIC: 1150 IF A(E)=0 THEN 1140 */
line_1150:;
    if (A_arr[(int)(E)]==0) { goto line_1140; }
    /* BASIC: 1160 LET F=INT(A(E)*RND(1)+1) */
line_1160:;
    /* UNTRANSLATED: LET F=INT(A(E)*RND(1)+1) */
    /* BASIC: 1170 LET A(E)=A(E)-F */
line_1170:;
    /* UNTRANSLATED: LET A(E)=A(E)-F */
    /* BASIC: 1180 GOTO 1380 */
line_1180:;
    goto line_1380;
    /* BASIC: 1190 LET A(G)=0 */
line_1190:;
    /* UNTRANSLATED: LET A(G)=0 */
    /* BASIC: 1200 FOR J=0 TO 10 */
line_1200:;
    J = 0; for_loop_J_1200: if (((1) >= 0 && J > (10)) || ((1) < 0 && J < (10))) goto end_for_J_1200;
    /* BASIC: 1210 LET B(G,J)=0 */
line_1210:;
    /* UNTRANSLATED: LET B(G,J)=0 */
    /* BASIC: 1220 LET C=0 */
line_1220:;
    /* UNTRANSLATED: LET C=0 */
    /* BASIC: 1230 FOR I=1 TO N */
line_1230:;
    I = 1; for_loop_I_1230: if (((1) >= 0 && I > (N)) || ((1) < 0 && I < (N))) goto end_for_I_1230;
    /* BASIC: 1240 IF B(I,J)=0 THEN 1260 */
line_1240:;
    if (B_arr[(int)(I) * 100 + (int)(J)]==0) { goto line_1260; }
    /* BASIC: 1250 LET C=C+1 */
line_1250:;
    /* UNTRANSLATED: LET C=C+1 */
    /* BASIC: 1260 NEXT I */
line_1260:;
    I += (1); goto for_loop_I_1230; end_for_I_1230:;
    /* BASIC: 1270 LET A(G)=A(G)+2*(C/2-INT(C/2))*2^J */
line_1270:;
    /* UNTRANSLATED: LET A(G)=A(G)+2*(C/2-INT(C/2))*2^J */
    /* BASIC: 1280 NEXT J */
line_1280:;
    J += (1); goto for_loop_J_1200; end_for_J_1200:;
    /* BASIC: 1290 IF W=1 THEN 1380 */
line_1290:;
    if (W==1) { goto line_1380; }
    /* BASIC: 1300 LET C=0 */
line_1300:;
    /* UNTRANSLATED: LET C=0 */
    /* BASIC: 1310 FOR I=1 TO N */
line_1310:;
    I = 1; for_loop_I_1310: if (((1) >= 0 && I > (N)) || ((1) < 0 && I < (N))) goto end_for_I_1310;
    /* BASIC: 1320 IF A(I)>1 THEN 1380 */
line_1320:;
    if (A_arr[(int)(I)]>1) { goto line_1380; }
    /* BASIC: 1330 IF A(I)=0 THEN 1350 */
line_1330:;
    if (A_arr[(int)(I)]==0) { goto line_1350; }
    /* BASIC: 1340 LET C=C+1 */
line_1340:;
    /* UNTRANSLATED: LET C=C+1 */
    /* BASIC: 1350 NEXT I */
line_1350:;
    I += (1); goto for_loop_I_1310; end_for_I_1310:;
    /* BASIC: 1360 IF C/2<>INT(C/2) THEN 1380 */
line_1360:;
    if (C/2!=floor(C/2)) { goto line_1380; }
    /* BASIC: 1370 LET A(G)=1-A(G) */
line_1370:;
    /* UNTRANSLATED: LET A(G)=1-A(G) */
    /* BASIC: 1380 PRINT "PILE  SIZE" */
line_1380:;
    printf("%s", "PILE  SIZE"); printf("\n");
    /* BASIC: 1390 FOR I=1 TO N */
line_1390:;
    I = 1; for_loop_I_1390: if (((1) >= 0 && I > (N)) || ((1) < 0 && I < (N))) goto end_for_I_1390;
    /* BASIC: 1400 PRINT I;A(I) */
line_1400:;
    printf("%g ", (double)(I)); printf("%g ", (double)(A_arr[(int)(I)])); printf("\n");
    /* BASIC: 1410 NEXT I */
line_1410:;
    I += (1); goto for_loop_I_1390; end_for_I_1390:;
    /* BASIC: 1420 IF W=2 THEN 1450 */
line_1420:;
    if (W==2) { goto line_1450; }
    /* BASIC: 1430 GOSUB 1570 */
line_1430:;
    gosub_stack[gosub_sp++] = 1; goto line_1570; line_ret_1:;
    /* BASIC: 1440 IF Z=1 THEN 820 */
line_1440:;
    if (Z==1) { goto line_820; }
    /* BASIC: 1450 PRINT "YOUR MOVE - PILE, NUMBER TO BE REMOVED"; */
line_1450:;
    printf("%s", "YOUR MOVE - PILE, NUMBER TO BE REMOVED");
    /* BASIC: 1460 INPUT X,Y */
line_1460:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf", &X, &Y);
    /* BASIC: 1470 IF X>N THEN 1450 */
line_1470:;
    if (X>N) { goto line_1450; }
    /* BASIC: 1480 IF X<1 THEN 1450 */
line_1480:;
    if (X<1) { goto line_1450; }
    /* BASIC: 1490 IF X<>INT(X) THEN 1450 */
line_1490:;
    if (X!=floor(X)) { goto line_1450; }
    /* BASIC: 1500 IF Y>A(X) THEN 1450 */
line_1500:;
    if (Y>A_arr[(int)(X)]) { goto line_1450; }
    /* BASIC: 1510 IF Y<1 THEN 1450 */
line_1510:;
    if (Y<1) { goto line_1450; }
    /* BASIC: 1520 IF Y<>INT(Y) THEN 1450 */
line_1520:;
    if (Y!=floor(Y)) { goto line_1450; }
    /* BASIC: 1530 LET A(X)=A(X)-Y */
line_1530:;
    /* UNTRANSLATED: LET A(X)=A(X)-Y */
    /* BASIC: 1540 GOSUB 1570 */
line_1540:;
    gosub_stack[gosub_sp++] = 2; goto line_1570; line_ret_2:;
    /* BASIC: 1550 IF Z=1 THEN 800 */
line_1550:;
    if (Z==1) { goto line_800; }
    /* BASIC: 1560 GOTO 700 */
line_1560:;
    goto line_700;
    /* BASIC: 1570 LET Z=0 */
line_1570:;
    /* UNTRANSLATED: LET Z=0 */
    /* BASIC: 1580 FOR I=1 TO N */
line_1580:;
    I = 1; for_loop_I_1580: if (((1) >= 0 && I > (N)) || ((1) < 0 && I < (N))) goto end_for_I_1580;
    /* BASIC: 1590 IF A(I)=0 THEN 1610 */
line_1590:;
    if (A_arr[(int)(I)]==0) { goto line_1610; }
    /* BASIC: 1600 RETURN */
line_1600:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1610 NEXT I */
line_1610:;
    I += (1); goto for_loop_I_1580; end_for_I_1580:;
    /* BASIC: 1620 LET Z=1 */
line_1620:;
    /* UNTRANSLATED: LET Z=1 */
    /* BASIC: 1630 RETURN */
line_1630:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1640 PRINT "do you want to play another game"; */
line_1640:;
    printf("%s", "do you want to play another game");
    /* BASIC: 1650 INPUT Q9$ */
line_1650:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", Q9_str);
    /* BASIC: 1660 IF Q9$="YES" THEN 1720 */
line_1660:;
    if (strcmp(Q9_str, "YES") == 0) { goto line_1720; }
    /* BASIC: 1670 IF Q9$="yes" THEN 1720 */
line_1670:;
    if (strcmp(Q9_str, "yes") == 0) { goto line_1720; }
    /* BASIC: 1680 IF Q9$="NO" THEN 1730 */
line_1680:;
    if (strcmp(Q9_str, "NO") == 0) { goto line_1730; }
    /* BASIC: 1690 IF Q9$="no" THEN 1730 */
line_1690:;
    if (strcmp(Q9_str, "no") == 0) { goto line_1730; }
    /* BASIC: 1700 PRINT "PLEASE.  YES OR NO." */
line_1700:;
    printf("%s", "PLEASE.  YES OR NO."); printf("\n");
    /* BASIC: 1710 GOTO 1650 */
line_1710:;
    goto line_1650;
    /* BASIC: 1720 GOTO 440 */
line_1720:;
    goto line_440;
    /* BASIC: 1730 END */
line_1730:;
    exit(0);

    return 0;
}
