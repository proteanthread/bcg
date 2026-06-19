/*
 * Transpiled from boxing.bas
 * GW-BASIC to strict C89 (ANSI) / C90 (ISO)
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
    if (n >= 0) sprintf(buf[idx], " %g", n);
    else sprintf(buf[idx], "%g", n);
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
    sprintf(buf[idx], "%s%s", s1, s2);
    return buf[idx];
}

static void str_assign(char *dest, size_t dest_sz, const char *src) {
    strncpy(dest, src, dest_sz - 1);
    dest[dest_sz - 1] = '\0';
}

/* Global variables */
static double B, B1, C, D, D1, D5, H1, I, J, J7, L, P, Q4, R, R1, R6, X, X3, Y, Z4;
static char J_str[256] = {0};
static char L_str[256] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 1 PRINT TAB(33);"BOXING" */
line_1:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "BOXING"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT:PRINT:PRINT */
line_3:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 4 PRINT "BOXING OLYMPIC STYLE (3 ROUNDS -- 2 OUT OF 3 WINS)" */
line_4:;
    printf("%s", "BOXING OLYMPIC STYLE (3 ROUNDS -- 2 OUT OF 3 WINS)"); printf("\n");
    /* BASIC: 5 J=0 */
line_5:;
    J = 0;
    /* BASIC: 6 L=0 */
line_6:;
    L = 0;
    /* BASIC: 8 PRINT */
line_8:;
    printf("\n");
    /* BASIC: 10 PRINT "WHAT IS YOUR OPPONENT'S NAME"; */
line_10:;
    printf("%s", "WHAT IS YOUR OPPONENT'S NAME");
    /* BASIC: 20 INPUT J$ */
line_20:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", J_str);
    /* BASIC: 30 PRINT "INPUT YOUR MAN'S NAME"; */
line_30:;
    printf("%s", "INPUT YOUR MAN'S NAME");
    /* BASIC: 40 INPUT L$ */
line_40:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", L_str);
    /* BASIC: 50 PRINT "DIFFERENT PUNCHES ARE: (1) FULL SWING; (2) HOOK; (3) UPPERCUT; (4) JAB." */
line_50:;
    printf("%s", "DIFFERENT PUNCHES ARE: (1) FULL SWING; (2) HOOK; (3) UPPERCUT; (4) JAB."); printf("\n");
    /* BASIC: 60 PRINT "WHAT IS YOUR MANS BEST"; */
line_60:;
    printf("%s", "WHAT IS YOUR MANS BEST");
    /* BASIC: 64 INPUT B */
line_64:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &B);
    /* BASIC: 70 PRINT "WHAT IS HIS VULNERABILITY"; */
line_70:;
    printf("%s", "WHAT IS HIS VULNERABILITY");
    /* BASIC: 80 INPUT D */
line_80:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &D);
    /* BASIC: 90 B1=INT(4*RND(1)+1) */
line_90:;
    B1 = floor(4*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 100 D1=INT(4*RND(1)+1) */
line_100:;
    D1 = floor(4*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 110 IF B1=D1 THEN 90 */
line_110:;
    if (B1==D1) { goto line_90; }
    /* BASIC: 120 PRINT J$;"'S ADVANTAGE IS";B1;"AND VULNERABILITY IS SECRET.":PRINT */
line_120:;
    printf("%s", J_str); printf("%s", "'S ADVANTAGE IS"); printf("%g ", (double)(B1)); printf("%s", "AND VULNERABILITY IS SECRET."); printf("\n");
    printf("\n");
    /* BASIC: 130 FOR R=1 TO 3 */
line_130:;
    R = 1; for_loop_R_130: if (((1) >= 0 && R > (3)) || ((1) < 0 && R < (3))) goto end_for_R_130;
    /* BASIC: 140 IF J>= 2 THEN 1040 */
line_140:;
    if (J>= 2) { goto line_1040; }
    /* BASIC: 150 IF L>=2 THEN 1060 */
line_150:;
    if (L>=2) { goto line_1060; }
    /* BASIC: 160 X=0 */
line_160:;
    X = 0;
    /* BASIC: 170 Y=0 */
line_170:;
    Y = 0;
    /* BASIC: 180 PRINT "ROUND";R;"BEGINS..." */
line_180:;
    printf("%s", "ROUND"); printf("%g ", (double)(R)); printf("%s", "BEGINS..."); printf("\n");
    /* BASIC: 185 FOR R1= 1 TO 7 */
line_185:;
    R1 = 1; for_loop_R1_185: if (((1) >= 0 && R1 > (7)) || ((1) < 0 && R1 < (7))) goto end_for_R1_185;
    /* BASIC: 190 I=INT(10*RND(1)+1) */
line_190:;
    I = floor(10*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 200 IF I>5 THEN 600 */
line_200:;
    if (I>5) { goto line_600; }
    /* BASIC: 210 PRINT L$;"'S PUNCH"; */
line_210:;
    printf("%s", L_str); printf("%s", "'S PUNCH");
    /* BASIC: 220 INPUT P */
line_220:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &P);
    /* BASIC: 221 IF P=B THEN 225 */
line_221:;
    if (P==B) { goto line_225; }
    /* BASIC: 222 GOTO 230 */
line_222:;
    goto line_230;
    /* BASIC: 225 X=X+2 */
line_225:;
    X = X+2;
    /* BASIC: 230 IF P=1 THEN 340 */
line_230:;
    if (P==1) { goto line_340; }
    /* BASIC: 240 IF P=2 THEN 450 */
line_240:;
    if (P==2) { goto line_450; }
    /* BASIC: 250 IF P=3 THEN 520 */
line_250:;
    if (P==3) { goto line_520; }
    /* BASIC: 270 PRINT L$;" JABS AT ";J$"'S HEAD "; */
line_270:;
    printf("%s", L_str); printf("%s", " JABS AT "); printf("%s", J_str); printf("%s", "'S HEAD ");
    /* BASIC: 271 IF D1=4 THEN 290 */
line_271:;
    if (D1==4) { goto line_290; }
    /* BASIC: 275 C=INT(8*RND(1)+1) */
line_275:;
    C = floor(8*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 280 IF C<4 THEN 310 */
line_280:;
    if (C<4) { goto line_310; }
    /* BASIC: 290 X=X+3 */
line_290:;
    X = X+3;
    /* BASIC: 300 GOTO 950 */
line_300:;
    goto line_950;
    /* BASIC: 310 PRINT "IT'S BLOCKED." */
line_310:;
    printf("%s", "IT'S BLOCKED."); printf("\n");
    /* BASIC: 330 GOTO 950 */
line_330:;
    goto line_950;
    /* BASIC: 340 PRINT L$ " SWINGS AND "; */
line_340:;
    printf("%s", L_str); printf("%s", " SWINGS AND ");
    /* BASIC: 341 IF D1=4 THEN 410 */
line_341:;
    if (D1==4) { goto line_410; }
    /* BASIC: 345 X3=INT(30*RND(1)+1) */
line_345:;
    X3 = floor(30*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 350 IF X3<10 THEN 410 */
line_350:;
    if (X3<10) { goto line_410; }
    /* BASIC: 360 PRINT "HE MISSES "; */
line_360:;
    printf("%s", "HE MISSES ");
    /* BASIC: 370 PRINT */
line_370:;
    printf("\n");
    /* BASIC: 375 IF X=1 THEN 950 */
line_375:;
    if (X==1) { goto line_950; }
    /* BASIC: 380 PRINT */
line_380:;
    printf("\n");
    /* BASIC: 390 PRINT */
line_390:;
    printf("\n");
    /* BASIC: 400 GOTO 300 */
line_400:;
    goto line_300;
    /* BASIC: 410 PRINT "HE CONNECTS!" */
line_410:;
    printf("%s", "HE CONNECTS!"); printf("\n");
    /* BASIC: 420 IF X>35 THEN 980 */
line_420:;
    if (X>35) { goto line_980; }
    /* BASIC: 425 X=X+15 */
line_425:;
    X = X+15;
    /* BASIC: 440 GOTO 300 */
line_440:;
    goto line_300;
    /* BASIC: 450 PRINT L$;" GIVES THE HOOK... "; */
line_450:;
    printf("%s", L_str); printf("%s", " GIVES THE HOOK... ");
    /* BASIC: 455 IF D1=2 THEN 480 */
line_455:;
    if (D1==2) { goto line_480; }
    /* BASIC: 460 H1=INT(2*RND(1)+1) */
line_460:;
    H1 = floor(2*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 470 IF H1=1 THEN 500 */
line_470:;
    if (H1==1) { goto line_500; }
    /* BASIC: 475 PRINT "CONNECTS..." */
line_475:;
    printf("%s", "CONNECTS..."); printf("\n");
    /* BASIC: 480 X=X+7 */
line_480:;
    X = X+7;
    /* BASIC: 490 GOTO 300 */
line_490:;
    goto line_300;
    /* BASIC: 500 PRINT "BUT IT'S BLOCKED!!!!!!!!!!!!!" */
line_500:;
    printf("%s", "BUT IT'S BLOCKED!!!!!!!!!!!!!"); printf("\n");
    /* BASIC: 510 GOTO 300 */
line_510:;
    goto line_300;
    /* BASIC: 520 PRINT L$ " TRIES AN UPPERCUT "; */
line_520:;
    printf("%s", L_str); printf("%s", " TRIES AN UPPERCUT ");
    /* BASIC: 530 IF D1=3 THEN 570 */
line_530:;
    if (D1==3) { goto line_570; }
    /* BASIC: 540 D5=INT(100*RND(1)+1) */
line_540:;
    D5 = floor(100*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 550 IF D5<51 THEN 570 */
line_550:;
    if (D5<51) { goto line_570; }
    /* BASIC: 560 PRINT "AND IT'S BLOCKED (LUCKY BLOCK!)" */
line_560:;
    printf("%s", "AND IT'S BLOCKED (LUCKY BLOCK!)"); printf("\n");
    /* BASIC: 565 GOTO 300 */
line_565:;
    goto line_300;
    /* BASIC: 570 PRINT "AND HE CONNECTS!" */
line_570:;
    printf("%s", "AND HE CONNECTS!"); printf("\n");
    /* BASIC: 580 X=X+4 */
line_580:;
    X = X+4;
    /* BASIC: 590 GOTO 300 */
line_590:;
    goto line_300;
    /* BASIC: 600 J7=INT(4*RND(1)+1) */
line_600:;
    J7 = floor(4*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 601 IF J7 =B1 THEN 605 */
line_601:;
    if (J7 ==B1) { goto line_605; }
    /* BASIC: 602 GOTO 610 */
line_602:;
    goto line_610;
    /* BASIC: 605 Y=Y+2 */
line_605:;
    Y = Y+2;
    /* BASIC: 610 IF J7=1 THEN 720 */
line_610:;
    if (J7==1) { goto line_720; }
    /* BASIC: 620 IF J7=2 THEN 810 */
line_620:;
    if (J7==2) { goto line_810; }
    /* BASIC: 630 IF J7 =3 THEN 860 */
line_630:;
    if (J7 ==3) { goto line_860; }
    /* BASIC: 640 PRINT J$;" JABS AND "; */
line_640:;
    printf("%s", J_str); printf("%s", " JABS AND ");
    /* BASIC: 645 IF D=4 THEN 700 */
line_645:;
    if (D==4) { goto line_700; }
    /* BASIC: 650 Z4=INT(7*RND(1)+1) */
line_650:;
    Z4 = floor(7*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 655 IF Z4>4 THEN 690 */
line_655:;
    if (Z4>4) { goto line_690; }
    /* BASIC: 660 PRINT "IT'S BLOCKED!" */
line_660:;
    printf("%s", "IT'S BLOCKED!"); printf("\n");
    /* BASIC: 670 GOTO 300 */
line_670:;
    goto line_300;
    /* BASIC: 690 PRINT " BLOOD SPILLS !!!" */
line_690:;
    printf("%s", " BLOOD SPILLS !!!"); printf("\n");
    /* BASIC: 700 Y=Y+5 */
line_700:;
    Y = Y+5;
    /* BASIC: 710 GOTO 300 */
line_710:;
    goto line_300;
    /* BASIC: 720 PRINT J$" TAKES A FULL SWING AND"; */
line_720:;
    printf("%s", J_str); printf("%s", " TAKES A FULL SWING AND");
    /* BASIC: 730 IF D=1 THEN 770 */
line_730:;
    if (D==1) { goto line_770; }
    /* BASIC: 740 R6=INT(60*RND(1)+1) */
line_740:;
    R6 = floor(60*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 745 IF R6 <30 THEN 770 */
line_745:;
    if (R6 <30) { goto line_770; }
    /* BASIC: 750 PRINT " IT'S BLOCKED!" */
line_750:;
    printf("%s", " IT'S BLOCKED!"); printf("\n");
    /* BASIC: 760 GOTO 300 */
line_760:;
    goto line_300;
    /* BASIC: 770 PRINT " POW!!!!! HE HITS HIM RIGHT IN THE FACE!" */
line_770:;
    printf("%s", " POW!!!!! HE HITS HIM RIGHT IN THE FACE!"); printf("\n");
    /* BASIC: 780 IF Y>35 THEN 1010 */
line_780:;
    if (Y>35) { goto line_1010; }
    /* BASIC: 790 Y=Y+15 */
line_790:;
    Y = Y+15;
    /* BASIC: 800 GOTO 300 */
line_800:;
    goto line_300;
    /* BASIC: 810 PRINT J$;" GETS ";L$;" IN THE JAW (OUCH!)" */
line_810:;
    printf("%s", J_str); printf("%s", " GETS "); printf("%s", L_str); printf("%s", " IN THE JAW (OUCH!)"); printf("\n");
    /* BASIC: 820 Y=Y+7 */
line_820:;
    Y = Y+7;
    /* BASIC: 830 PRINT "....AND AGAIN!" */
line_830:;
    printf("%s", "....AND AGAIN!"); printf("\n");
    /* BASIC: 835 Y=Y+5 */
line_835:;
    Y = Y+5;
    /* BASIC: 840 IF Y>35 THEN 1010 */
line_840:;
    if (Y>35) { goto line_1010; }
    /* BASIC: 850 PRINT */
line_850:;
    printf("\n");
    /* BASIC: 860 PRINT L$;" IS ATTACKED BY AN UPPERCUT (OH,OH)..." */
line_860:;
    printf("%s", L_str); printf("%s", " IS ATTACKED BY AN UPPERCUT (OH,OH)..."); printf("\n");
    /* BASIC: 865 IF D=3 THEN 890 */
line_865:;
    if (D==3) { goto line_890; }
    /* BASIC: 870 Q4=INT(200*RND(1)+1) */
line_870:;
    Q4 = floor(200*((double)rand() / (double)RAND_MAX)+1);
    /* BASIC: 880 IF Q4>75 THEN 920 */
line_880:;
    if (Q4>75) { goto line_920; }
    /* BASIC: 890 PRINT "AND ";J$;" CONNECTS..." */
line_890:;
    printf("%s", "AND "); printf("%s", J_str); printf("%s", " CONNECTS..."); printf("\n");
    /* BASIC: 900 Y=Y+8 */
line_900:;
    Y = Y+8;
    /* BASIC: 910 GOTO 300 */
line_910:;
    goto line_300;
    /* BASIC: 920 PRINT " BLOCKS AND HITS ";J$;" WITH A HOOK." */
line_920:;
    printf("%s", " BLOCKS AND HITS "); printf("%s", J_str); printf("%s", " WITH A HOOK."); printf("\n");
    /* BASIC: 930 X=X+5 */
line_930:;
    X = X+5;
    /* BASIC: 940 GOTO 300 */
line_940:;
    goto line_300;
    /* BASIC: 950 NEXT R1 */
line_950:;
    R1 += (1); goto for_loop_R1_185; end_for_R1_185:;
    /* BASIC: 951 IF X>Y THEN 955 */
line_951:;
    if (X>Y) { goto line_955; }
    /* BASIC: 952 PRINT:PRINT J$" WINS ROUND" R */
line_952:;
    printf("\n");
    printf("%s", J_str); printf("%s", " WINS ROUND"); printf("%g ", (double)(R)); printf("\n");
    /* BASIC: 953 J=J+1 */
line_953:;
    J = J+1;
    /* BASIC: 954 GOTO 960 */
line_954:;
    goto line_960;
    /* BASIC: 955 PRINT:PRINT L$" WINS ROUND"R */
line_955:;
    printf("\n");
    printf("%s", L_str); printf("%s", " WINS ROUND"); printf("%g ", (double)(R)); printf("\n");
    /* BASIC: 956 L=L+1 */
line_956:;
    L = L+1;
    /* BASIC: 960 NEXT R */
line_960:;
    R += (1); goto for_loop_R_130; end_for_R_130:;
    /* BASIC: 961 IF J>= 2 THEN 1040 */
line_961:;
    if (J>= 2) { goto line_1040; }
    /* BASIC: 962 IF L>=2 THEN 1060 */
line_962:;
    if (L>=2) { goto line_1060; }
    /* BASIC: 980 PRINT J$ " IS KNOCKED COLD AND " L$" IS THE WINNER AND CHAMP!"; */
line_980:;
    printf("%s", J_str); printf("%s", " IS KNOCKED COLD AND "); printf("%s", L_str); printf("%s", " IS THE WINNER AND CHAMP!");
    /* BASIC: 1000 GOTO 1080 */
line_1000:;
    goto line_1080;
    /* BASIC: 1010 PRINT L$ " IS KNOCKED COLD AND " J$" IS THE WINNER AND CHAMP!"; */
line_1010:;
    printf("%s", L_str); printf("%s", " IS KNOCKED COLD AND "); printf("%s", J_str); printf("%s", " IS THE WINNER AND CHAMP!");
    /* BASIC: 1030 GOTO 1000 */
line_1030:;
    goto line_1000;
    /* BASIC: 1040 PRINT J$ " WINS (NICE GOING," J$;")." */
line_1040:;
    printf("%s", J_str); printf("%s", " WINS (NICE GOING,"); printf("%s", J_str); printf("%s", ")."); printf("\n");
    /* BASIC: 1050 GOTO 1000 */
line_1050:;
    goto line_1000;
    /* BASIC: 1060 PRINT L$ " AMAZINGLY WINS!!" */
line_1060:;
    printf("%s", L_str); printf("%s", " AMAZINGLY WINS!!"); printf("\n");
    /* BASIC: 1070 GOTO 1000 */
line_1070:;
    goto line_1000;
    /* BASIC: 1080 PRINT */
line_1080:;
    printf("\n");
    /* BASIC: 1085 PRINT */
line_1085:;
    printf("\n");
    /* BASIC: 1090 PRINT "AND NOW GOODBYE FROM THE OLYMPIC ARENA." */
line_1090:;
    printf("%s", "AND NOW GOODBYE FROM THE OLYMPIC ARENA."); printf("\n");
    /* BASIC: 1100 PRINT */
line_1100:;
    printf("\n");
    /* BASIC: 1110 END */
line_1110:;
    exit(0);

    return 0;
}
