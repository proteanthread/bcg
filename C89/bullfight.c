/*
 * Transpiled from bullfight.bas
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

typedef enum { DATA_NUM, DATA_STR } DataType;
typedef struct {
    DataType type;
    double num;
    const char *str;
} DataItem;

static DataItem program_data[5] = {
    { DATA_STR, 0.0, "SUPERB" },
    { DATA_STR, 0.0, "GOOD" },
    { DATA_STR, 0.0, "FAIR" },
    { DATA_STR, 0.0, "POOR" },
    { DATA_STR, 0.0, "AWFUL" },
};
static int data_ptr = 0;

static void read_numeric(double *var) {
    if (data_ptr < sizeof(program_data)/sizeof(program_data[0])) {
        if (program_data[data_ptr].type == DATA_NUM) *var = program_data[data_ptr].num;
        else *var = atof(program_data[data_ptr].str);
        data_ptr++;
    }
}

static void read_string(char *var, size_t max_len) {
    if (data_ptr < sizeof(program_data)/sizeof(program_data[0])) {
        if (program_data[data_ptr].type == DATA_STR) strncpy(var, program_data[data_ptr].str, max_len - 1);
        else sprintf(var, "%g", program_data[data_ptr].num);
        var[max_len - 1] = '\0';
        data_ptr++;
    }
}

/* Global variables */
static int gosub_stack[256];
static int gosub_sp = 0;
static double A, B, C, D, DEF, E, F, H, I, J, K, L, M, ON, Q, T, Z, Z1;
static char A_str[256] = {0};
static char B_str[256] = {0};
static char L_str[256] = {0};
static char Z_str[256] = {0};
static double D_arr[2000] = {0};
static char L_str_arr[1000][64] = {0};
static char _input_buf[256];

/* User-defined functions forward declarations */
static double FNA(double K);
static double FNC(double Q);
static double FND(double Q);

/* User-defined functions definitions */
static double FNA(double K) {
    return floor(((double)rand() / (double)RAND_MAX)*2+1);
}

static double FNC(double Q) {
    return FND(Q)*((double)rand() / (double)RAND_MAX);
}

static double FND(double Q) {
    return (4.5+L/6-(D_arr[(int)(1)]+D_arr[(int)(2)])*2.5+4*D_arr[(int)(4)]+2*D_arr[(int)(5)]-pow(D_arr[(int)(3)], 2)/120-A);
}

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(34);"BULL" */
line_10:;
    { int _t; for(_t=0; _t<34; _t++) printf(" "); } printf("%s", "BULL"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 DEF FNA(K)=INT(RND(1)*2+1) */
line_30:;
    /* UNTRANSLATED: DEF FNA(K)=INT(RND(1)*2+1) */
    /* BASIC: 200 PRINT:PRINT:PRINT */
line_200:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 202 L=1 */
line_202:;
    L = 1;
    /* BASIC: 205 PRINT "DO YOU WANT INSTRUCTIONS"; */
line_205:;
    printf("%s", "DO YOU WANT INSTRUCTIONS");
    /* BASIC: 206 INPUT Z$ */
line_206:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", Z_str);
    /* BASIC: 207 IF Z$="NO" THEN 400 */
line_207:;
    if (strcmp(Z_str, "NO") == 0) { goto line_400; }
    /* BASIC: 210 PRINT "HELLO, ALL YOU BLOODLOVERS AND AFICIONADOS." */
line_210:;
    printf("%s", "HELLO, ALL YOU BLOODLOVERS AND AFICIONADOS."); printf("\n");
    /* BASIC: 220 PRINT "HERE IS YOUR BIG CHANCE TO KILL A BULL." */
line_220:;
    printf("%s", "HERE IS YOUR BIG CHANCE TO KILL A BULL."); printf("\n");
    /* BASIC: 230 PRINT */
line_230:;
    printf("\n");
    /* BASIC: 240 PRINT "ON EACH PASS OF THE BULL, YOU MAY TRY" */
line_240:;
    printf("%s", "ON EACH PASS OF THE BULL, YOU MAY TRY"); printf("\n");
    /* BASIC: 250 PRINT "0 - VERONICA (DANGEROUS INSIDE MOVE OF THE CAPE)" */
line_250:;
    printf("%s", "0 - VERONICA (DANGEROUS INSIDE MOVE OF THE CAPE)"); printf("\n");
    /* BASIC: 260 PRINT "1 - LESS DANGEROUS OUTSIDE MOVE OF THE CAPE" */
line_260:;
    printf("%s", "1 - LESS DANGEROUS OUTSIDE MOVE OF THE CAPE"); printf("\n");
    /* BASIC: 270 PRINT "2 - ORDINARY SWIRL OF THE CAPE." */
line_270:;
    printf("%s", "2 - ORDINARY SWIRL OF THE CAPE."); printf("\n");
    /* BASIC: 280 PRINT */
line_280:;
    printf("\n");
    /* BASIC: 290 PRINT "INSTEAD OF THE ABOVE, YOU MAY TRY TO KILL THE BULL" */
line_290:;
    printf("%s", "INSTEAD OF THE ABOVE, YOU MAY TRY TO KILL THE BULL"); printf("\n");
    /* BASIC: 300 PRINT "ON ANY TURN: 4 (OVER THE HORNS), 5 (IN THE CHEST)." */
line_300:;
    printf("%s", "ON ANY TURN: 4 (OVER THE HORNS), 5 (IN THE CHEST)."); printf("\n");
    /* BASIC: 310 PRINT "BUT IF I WERE YOU," */
line_310:;
    printf("%s", "BUT IF I WERE YOU,"); printf("\n");
    /* BASIC: 320 PRINT "I WOULDN'T TRY IT BEFORE THE SEVENTH PASS." */
line_320:;
    printf("%s", "I WOULDN'T TRY IT BEFORE THE SEVENTH PASS."); printf("\n");
    /* BASIC: 330 PRINT */
line_330:;
    printf("\n");
    /* BASIC: 340 PRINT "THE CROWD WILL DETERMINE WHAT AWARD YOU DESERVE" */
line_340:;
    printf("%s", "THE CROWD WILL DETERMINE WHAT AWARD YOU DESERVE"); printf("\n");
    /* BASIC: 350 PRINT "(POSTHUMOUSLY IF NECESSARY)." */
line_350:;
    printf("%s", "(POSTHUMOUSLY IF NECESSARY)."); printf("\n");
    /* BASIC: 360 PRINT "THE BRAVER YOU ARE, THE BETTER THE AWARD YOU RECIEVE." */
line_360:;
    printf("%s", "THE BRAVER YOU ARE, THE BETTER THE AWARD YOU RECIEVE."); printf("\n");
    /* BASIC: 370 PRINT */
line_370:;
    printf("\n");
    /* BASIC: 380 PRINT "THE BETTER THE JOB THE PICADORES AND TOREADORES DO," */
line_380:;
    printf("%s", "THE BETTER THE JOB THE PICADORES AND TOREADORES DO,"); printf("\n");
    /* BASIC: 390 PRINT "THE BETTER YOUR CHANCES ARE." */
line_390:;
    printf("%s", "THE BETTER YOUR CHANCES ARE."); printf("\n");
    /* BASIC: 400 PRINT */
line_400:;
    printf("\n");
    /* BASIC: 410 PRINT */
line_410:;
    printf("\n");
    /* BASIC: 420 D(5)=1 */
line_420:;
    D_arr[(int)(5)] = 1;
    /* BASIC: 430 D(4)=1 */
line_430:;
    D_arr[(int)(4)] = 1;
    /* BASIC: 450 DIM L$(5) */
line_450:;
    /* DIM L$(5) (handled statically) */
    /* BASIC: 455 A=INT(RND(1)*5+1) */
line_455:;
    A = floor(((double)rand() / (double)RAND_MAX)*5+1);
    /* BASIC: 460 FOR I=1 TO 5 */
line_460:;
    I = 1; for_loop_I_460: if (((1) >= 0 && I > (5)) || ((1) < 0 && I < (5))) goto end_for_I_460;
    /* BASIC: 463 READ L$(I) */
line_463:;
    read_string(L_str_arr[(int)(I)], sizeof(L_str_arr[(int)(I)]));
    /* BASIC: 467 NEXT I */
line_467:;
    I += (1); goto for_loop_I_460; end_for_I_460:;
    /* BASIC: 470 DATA "SUPERB","GOOD","FAIR","POOR","AWFUL" */
line_470:;
    /* UNTRANSLATED: DATA "SUPERB","GOOD","FAIR","POOR","AWFUL" */
    /* BASIC: 490 PRINT "YOU HAVE DRAWN A ";L$(A);" BULL." */
line_490:;
    printf("%s", "YOU HAVE DRAWN A "); printf("%s", L_str_arr[(int)(A)]); printf("%s", " BULL."); printf("\n");
    /* BASIC: 500 IF A>4 THEN 530 */
line_500:;
    if (A>4) { goto line_530; }
    /* BASIC: 510 IF A<2 THEN 550 */
line_510:;
    if (A<2) { goto line_550; }
    /* BASIC: 520 GOTO 570 */
line_520:;
    goto line_570;
    /* BASIC: 530 PRINT "YOU'RE LUCKY." */
line_530:;
    printf("%s", "YOU'RE LUCKY."); printf("\n");
    /* BASIC: 540 GOTO 570 */
line_540:;
    goto line_570;
    /* BASIC: 550 PRINT "GOOD LUCK.  YOU'LL NEED IT." */
line_550:;
    printf("%s", "GOOD LUCK.  YOU'LL NEED IT."); printf("\n");
    /* BASIC: 560 PRINT */
line_560:;
    printf("\n");
    /* BASIC: 570 PRINT */
line_570:;
    printf("\n");
    /* BASIC: 590 A$="PICADO" */
line_590:;
    str_assign(A_str, sizeof(A_str), "PICADO");
    /* BASIC: 595 B$="RES" */
line_595:;
    str_assign(B_str, sizeof(B_str), "RES");
    /* BASIC: 600 GOSUB 1610 */
line_600:;
    gosub_stack[gosub_sp++] = 1; goto line_1610; line_ret_1:;
    /* BASIC: 610 D(1)=C */
line_610:;
    D_arr[(int)(1)] = C;
    /* BASIC: 630 A$="TOREAD" */
line_630:;
    str_assign(A_str, sizeof(A_str), "TOREAD");
    /* BASIC: 635 B$="ORES" */
line_635:;
    str_assign(B_str, sizeof(B_str), "ORES");
    /* BASIC: 640 GOSUB 1610 */
line_640:;
    gosub_stack[gosub_sp++] = 2; goto line_1610; line_ret_2:;
    /* BASIC: 650 D(2)=C */
line_650:;
    D_arr[(int)(2)] = C;
    /* BASIC: 660 PRINT */
line_660:;
    printf("\n");
    /* BASIC: 670 PRINT */
line_670:;
    printf("\n");
    /* BASIC: 680 IF Z=1 THEN 1310 */
line_680:;
    if (Z==1) { goto line_1310; }
    /* BASIC: 690 D(3)=D(3)+1 */
line_690:;
    D_arr[(int)(3)] = D_arr[(int)(3)]+1;
    /* BASIC: 700 PRINT "PASS NUMBER";D(3) */
line_700:;
    printf("%s", "PASS NUMBER"); printf("%g ", (double)(D_arr[(int)(3)])); printf("\n");
    /* BASIC: 710 IF D(3)<3 THEN 760 */
line_710:;
    if (D_arr[(int)(3)]<3) { goto line_760; }
    /* BASIC: 720 PRINT "HERE COMES THE BULL.  TRY FOR A KILL"; */
line_720:;
    printf("%s", "HERE COMES THE BULL.  TRY FOR A KILL");
    /* BASIC: 730 GOSUB 1930 */
line_730:;
    gosub_stack[gosub_sp++] = 3; goto line_1930; line_ret_3:;
    /* BASIC: 735 IF Z1=1 THEN 1130 */
line_735:;
    if (Z1==1) { goto line_1130; }
    /* BASIC: 740 PRINT "CAPE MOVE"; */
line_740:;
    printf("%s", "CAPE MOVE");
    /* BASIC: 750 GOTO 800 */
line_750:;
    goto line_800;
    /* BASIC: 760 PRINT "THE BULL IS CHARGING AT YOU!  YOU ARE THE MATADOR--" */
line_760:;
    printf("%s", "THE BULL IS CHARGING AT YOU!  YOU ARE THE MATADOR--"); printf("\n");
    /* BASIC: 770 PRINT "DO YOU WANT TO KILL THE BULL"; */
line_770:;
    printf("%s", "DO YOU WANT TO KILL THE BULL");
    /* BASIC: 780 GOSUB 1930 */
line_780:;
    gosub_stack[gosub_sp++] = 4; goto line_1930; line_ret_4:;
    /* BASIC: 785 IF Z1=1 THEN 1130 */
line_785:;
    if (Z1==1) { goto line_1130; }
    /* BASIC: 790 PRINT "WHAT MOVE DO YOU MAKE WITH THE CAPE"; */
line_790:;
    printf("%s", "WHAT MOVE DO YOU MAKE WITH THE CAPE");
    /* BASIC: 800 INPUT E */
line_800:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &E);
    /* BASIC: 810 IF E<>INT(ABS(E)) THEN 830 */
line_810:;
    if (E!=floor(fabs(E))) { goto line_830; }
    /* BASIC: 820 IF E<3 THEN 850 */
line_820:;
    if (E<3) { goto line_850; }
    /* BASIC: 830 PRINT "DON'T PANIC, YOU IDIOT!  PUT DOWN A CORRECT NUMBER" */
line_830:;
    printf("%s", "DON'T PANIC, YOU IDIOT!  PUT DOWN A CORRECT NUMBER"); printf("\n");
    /* BASIC: 840 GOTO 800 */
line_840:;
    goto line_800;
    /* BASIC: 850 REM */
line_850:;
    /* REM */
    /* BASIC: 860 IF E=0 THEN 920 */
line_860:;
    if (E==0) { goto line_920; }
    /* BASIC: 870 IF E=1 THEN 900 */
line_870:;
    if (E==1) { goto line_900; }
    /* BASIC: 880 M=.5 */
line_880:;
    M = .5;
    /* BASIC: 890 GOTO 930 */
line_890:;
    goto line_930;
    /* BASIC: 900 M=2 */
line_900:;
    M = 2;
    /* BASIC: 910 GOTO 930 */
line_910:;
    goto line_930;
    /* BASIC: 920 M=3 */
line_920:;
    M = 3;
    /* BASIC: 930 L=L+M */
line_930:;
    L = L+M;
    /* BASIC: 940 F=(6-A+M/10)*RND(1)/((D(1)+D(2)+D(3)/10)*5) */
line_940:;
    F = (6-A+M/10)*((double)rand() / (double)RAND_MAX)/((D_arr[(int)(1)]+D_arr[(int)(2)]+D_arr[(int)(3)]/10)*5);
    /* BASIC: 950 IF F<.51 THEN 660 */
line_950:;
    if (F<.51) { goto line_660; }
    /* BASIC: 960 PRINT "THE BULL HAS GORED YOU!" */
line_960:;
    printf("%s", "THE BULL HAS GORED YOU!"); printf("\n");
    /* BASIC: 970 ON FNA(0) GOTO 980,1010 */
line_970:;
    switch ((int)(FNA(0))) {     case 1: goto line_980;     case 2: goto line_1010; }
    /* BASIC: 980 PRINT "YOU ARE DEAD." */
line_980:;
    printf("%s", "YOU ARE DEAD."); printf("\n");
    /* BASIC: 990 D(4)=1.5 */
line_990:;
    D_arr[(int)(4)] = 1.5;
    /* BASIC: 1000 GOTO 1310 */
line_1000:;
    goto line_1310;
    /* BASIC: 1010 PRINT "YOU ARE STILL ALIVE.":PRINT */
line_1010:;
    printf("%s", "YOU ARE STILL ALIVE."); printf("\n");
    printf("\n");
    /* BASIC: 1020 PRINT "DO YOU RUN FROM THE RING"; */
line_1020:;
    printf("%s", "DO YOU RUN FROM THE RING");
    /* BASIC: 1030 GOSUB 1930 */
line_1030:;
    gosub_stack[gosub_sp++] = 5; goto line_1930; line_ret_5:;
    /* BASIC: 1035 IF Z1=2 THEN 1070 */
line_1035:;
    if (Z1==2) { goto line_1070; }
    /* BASIC: 1040 PRINT "COWARD" */
line_1040:;
    printf("%s", "COWARD"); printf("\n");
    /* BASIC: 1050 D(4)=0 */
line_1050:;
    D_arr[(int)(4)] = 0;
    /* BASIC: 1060 GOTO 1310 */
line_1060:;
    goto line_1310;
    /* BASIC: 1070 PRINT "YOU ARE BRAVE.  STUPID, BUT BRAVE." */
line_1070:;
    printf("%s", "YOU ARE BRAVE.  STUPID, BUT BRAVE."); printf("\n");
    /* BASIC: 1080 ON FNA(0) GOTO 1090,1110 */
line_1080:;
    switch ((int)(FNA(0))) {     case 1: goto line_1090;     case 2: goto line_1110; }
    /* BASIC: 1090 D(4)=2 */
line_1090:;
    D_arr[(int)(4)] = 2;
    /* BASIC: 1100 GOTO 660 */
line_1100:;
    goto line_660;
    /* BASIC: 1110 PRINT "YOU ARE GORED AGAIN!" */
line_1110:;
    printf("%s", "YOU ARE GORED AGAIN!"); printf("\n");
    /* BASIC: 1120 GOTO 970 */
line_1120:;
    goto line_970;
    /* BASIC: 1130 REM */
line_1130:;
    /* REM */
    /* BASIC: 1140 Z=1 */
line_1140:;
    Z = 1;
    /* BASIC: 1150 PRINT:PRINT "IT IS THE MOMENT OF TRUTH.":PRINT */
line_1150:;
    printf("\n");
    printf("%s", "IT IS THE MOMENT OF TRUTH."); printf("\n");
    printf("\n");
    /* BASIC: 1155 PRINT "HOW DO YOU TRY TO KILL THE BULL"; */
line_1155:;
    printf("%s", "HOW DO YOU TRY TO KILL THE BULL");
    /* BASIC: 1160 INPUT H */
line_1160:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &H);
    /* BASIC: 1170 IF H=4 THEN 1230 */
line_1170:;
    if (H==4) { goto line_1230; }
    /* BASIC: 1180 IF H=5 THEN 1230 */
line_1180:;
    if (H==5) { goto line_1230; }
    /* BASIC: 1190 PRINT "YOU PANICKED.  THE BULL GORED YOU." */
line_1190:;
    printf("%s", "YOU PANICKED.  THE BULL GORED YOU."); printf("\n");
    /* BASIC: 1220 GOTO 970 */
line_1220:;
    goto line_970;
    /* BASIC: 1230 K=(6-A)*10*RND(1)/((D(1)+D(2))*5*D(3)) */
line_1230:;
    K = (6-A)*10*((double)rand() / (double)RAND_MAX)/((D_arr[(int)(1)]+D_arr[(int)(2)])*5*D_arr[(int)(3)]);
    /* BASIC: 1240 IF J=4 THEN 1290 */
line_1240:;
    if (J==4) { goto line_1290; }
    /* BASIC: 1250 IF K>.2 THEN 960 */
line_1250:;
    if (K>.2) { goto line_960; }
    /* BASIC: 1260 PRINT "YOU KILLED THE BULL!" */
line_1260:;
    printf("%s", "YOU KILLED THE BULL!"); printf("\n");
    /* BASIC: 1270 D(5)=2 */
line_1270:;
    D_arr[(int)(5)] = 2;
    /* BASIC: 1280 GOTO 1320 */
line_1280:;
    goto line_1320;
    /* BASIC: 1290 IF K>.8 THEN 960 */
line_1290:;
    if (K>.8) { goto line_960; }
    /* BASIC: 1300 GOTO 1260 */
line_1300:;
    goto line_1260;
    /* BASIC: 1310 PRINT */
line_1310:;
    printf("\n");
    /* BASIC: 1320 PRINT */
line_1320:;
    printf("\n");
    /* BASIC: 1330 PRINT */
line_1330:;
    printf("\n");
    /* BASIC: 1340 IF D(4)<>0 THEN 1390 */
line_1340:;
    if (D_arr[(int)(4)]!=0) { goto line_1390; }
    /* BASIC: 1350 PRINT "THE CROWD BOOS FOR TEN MINUTES.  IF YOU EVER DARE TO SHOW" */
line_1350:;
    printf("%s", "THE CROWD BOOS FOR TEN MINUTES.  IF YOU EVER DARE TO SHOW"); printf("\n");
    /* BASIC: 1360 PRINT "YOUR FACE IN A RING AGAIN, THEY SWEAR THEY WILL KILL YOU--" */
line_1360:;
    printf("%s", "YOUR FACE IN A RING AGAIN, THEY SWEAR THEY WILL KILL YOU--"); printf("\n");
    /* BASIC: 1370 PRINT "UNLES THE BULL DOES FIRST." */
line_1370:;
    printf("%s", "UNLES THE BULL DOES FIRST."); printf("\n");
    /* BASIC: 1380 GOTO 1580 */
line_1380:;
    goto line_1580;
    /* BASIC: 1390 DEF FNC(Q)=FND(Q)*RND(1) */
line_1390:;
    /* UNTRANSLATED: DEF FNC(Q)=FND(Q)*RND(1) */
    /* BASIC: 1395 DEF FND(Q)=(4.5+L/6-(D(1)+D(2))*2.5+4*D(4)+2*D(5)-D(3)^2/120-A) */
line_1395:;
    /* UNTRANSLATED: DEF FND(Q)=(4.5+L/6-(D(1)+D(2))*2.5+4*D(4)+2*D(5)-D(3)^2/120-A) */
    /* BASIC: 1400 IF D(4)<>2 THEN 1430 */
line_1400:;
    if (D_arr[(int)(4)]!=2) { goto line_1430; }
    /* BASIC: 1410 PRINT "THE CROWD CHEERS WILDLY!" */
line_1410:;
    printf("%s", "THE CROWD CHEERS WILDLY!"); printf("\n");
    /* BASIC: 1420 GOTO 1450 */
line_1420:;
    goto line_1450;
    /* BASIC: 1430 IF D(5)<>2 THEN 1450 */
line_1430:;
    if (D_arr[(int)(5)]!=2) { goto line_1450; }
    /* BASIC: 1440 PRINT "THE CROWD CHEERS!":PRINT */
line_1440:;
    printf("%s", "THE CROWD CHEERS!"); printf("\n");
    printf("\n");
    /* BASIC: 1450 PRINT "THE CROWD AWARDS YOU" */
line_1450:;
    printf("%s", "THE CROWD AWARDS YOU"); printf("\n");
    /* BASIC: 1460 IF FNC(Q)<2.4 THEN 1570 */
line_1460:;
    if (FNC(Q)<2.4) { goto line_1570; }
    /* BASIC: 1470 IF FNC(Q)<4.9 THEN 1550 */
line_1470:;
    if (FNC(Q)<4.9) { goto line_1550; }
    /* BASIC: 1480 IF FNC(Q)<7.4 THEN 1520 */
line_1480:;
    if (FNC(Q)<7.4) { goto line_1520; }
    /* BASIC: 1500 PRINT "OLE!  YOU ARE 'MUY HOMBRE'!! OLE!  OLE!" */
line_1500:;
    printf("%s", "OLE!  YOU ARE 'MUY HOMBRE'!! OLE!  OLE!"); printf("\n");
    /* BASIC: 1510 GOTO 1580 */
line_1510:;
    goto line_1580;
    /* BASIC: 1520 PRINT "BOTH EARS OF THE BULL!" */
line_1520:;
    printf("%s", "BOTH EARS OF THE BULL!"); printf("\n");
    /* BASIC: 1530 PRINT "OLE!" */
line_1530:;
    printf("%s", "OLE!"); printf("\n");
    /* BASIC: 1540 GOTO 1580 */
line_1540:;
    goto line_1580;
    /* BASIC: 1550 PRINT "ONE EAR OF THE BULL." */
line_1550:;
    printf("%s", "ONE EAR OF THE BULL."); printf("\n");
    /* BASIC: 1560 GOTO 1580 */
line_1560:;
    goto line_1580;
    /* BASIC: 1570 PRINT "NOTHING AT ALL." */
line_1570:;
    printf("%s", "NOTHING AT ALL."); printf("\n");
    /* BASIC: 1580 PRINT */
line_1580:;
    printf("\n");
    /* BASIC: 1590 PRINT "ADIOS":PRINT:PRINT:PRINT */
line_1590:;
    printf("%s", "ADIOS"); printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 1600 GOTO 2030 */
line_1600:;
    goto line_2030;
    /* BASIC: 1610 B=3/A*RND(1) */
line_1610:;
    B = 3/A*((double)rand() / (double)RAND_MAX);
    /* BASIC: 1620 IF B<.37 THEN 1740 */
line_1620:;
    if (B<.37) { goto line_1740; }
    /* BASIC: 1630 IF B<.5 THEN 1720 */
line_1630:;
    if (B<.5) { goto line_1720; }
    /* BASIC: 1640 IF B<.63 THEN 1700 */
line_1640:;
    if (B<.63) { goto line_1700; }
    /* BASIC: 1650 IF B<.87 THEN 1680 */
line_1650:;
    if (B<.87) { goto line_1680; }
    /* BASIC: 1660 C=.1 */
line_1660:;
    C = .1;
    /* BASIC: 1670 GOTO 1750 */
line_1670:;
    goto line_1750;
    /* BASIC: 1680 C=.2 */
line_1680:;
    C = .2;
    /* BASIC: 1690 GOTO 1750 */
line_1690:;
    goto line_1750;
    /* BASIC: 1700 C=.3 */
line_1700:;
    C = .3;
    /* BASIC: 1710 GOTO 1750 */
line_1710:;
    goto line_1750;
    /* BASIC: 1720 C=.4 */
line_1720:;
    C = .4;
    /* BASIC: 1730 GOTO 1750 */
line_1730:;
    goto line_1750;
    /* BASIC: 1740 C=.5 */
line_1740:;
    C = .5;
    /* BASIC: 1750 T=INT(10*C+.2) */
line_1750:;
    T = floor(10*C+.2);
    /* BASIC: 1760 PRINT "THE ";A$;B$;" DID A ";L$(T);" JOB." */
line_1760:;
    printf("%s", "THE "); printf("%s", A_str); printf("%s", B_str); printf("%s", " DID A "); printf("%s", L_str_arr[(int)(T)]); printf("%s", " JOB."); printf("\n");
    /* BASIC: 1770 IF 4>T THEN 1900 */
line_1770:;
    if (4>T) { goto line_1900; }
    /* BASIC: 1780 IF 5=T THEN 1870 */
line_1780:;
    if (5==T) { goto line_1870; }
    /* BASIC: 1790 ON FNA(K) GOTO 1830,1850 */
line_1790:;
    switch ((int)(FNA(K))) {     case 1: goto line_1830;     case 2: goto line_1850; }
    /* BASIC: 1800 IF A$="TOREAD" THEN 1820 */
line_1800:;
    if (strcmp(A_str, "TOREAD") == 0) { goto line_1820; }
    /* BASIC: 1810 PRINT "ONE OF THE HORSES OF THE ";A$;B$;" WAS KILLED." */
line_1810:;
    printf("%s", "ONE OF THE HORSES OF THE "); printf("%s", A_str); printf("%s", B_str); printf("%s", " WAS KILLED."); printf("\n");
    /* BASIC: 1820 ON FNA(K) GOTO 1830,1850 */
line_1820:;
    switch ((int)(FNA(K))) {     case 1: goto line_1830;     case 2: goto line_1850; }
    /* BASIC: 1830 PRINT "ONE OF THE ";A$;B$;" WAS KILLED." */
line_1830:;
    printf("%s", "ONE OF THE "); printf("%s", A_str); printf("%s", B_str); printf("%s", " WAS KILLED."); printf("\n");
    /* BASIC: 1840 GOTO 1900 */
line_1840:;
    goto line_1900;
    /* BASIC: 1850 PRINT "NO ";A$;B$;" WERE KILLED." */
line_1850:;
    printf("%s", "NO "); printf("%s", A_str); printf("%s", B_str); printf("%s", " WERE KILLED."); printf("\n");
    /* BASIC: 1860 GOTO 1900 */
line_1860:;
    goto line_1900;
    /* BASIC: 1870 IF A$="TOREAD" THEN 1890 */
line_1870:;
    if (strcmp(A_str, "TOREAD") == 0) { goto line_1890; }
    /* BASIC: 1880 PRINT FNA(K);"OF THE HORSES OF THE ";A$;B$;" KILLED." */
line_1880:;
    printf("%g ", (double)(FNA(K))); printf("%s", "OF THE HORSES OF THE "); printf("%s", A_str); printf("%s", B_str); printf("%s", " KILLED."); printf("\n");
    /* BASIC: 1890 PRINT FNA(K);"OF THE ";A$;B$;" KILLED." */
line_1890:;
    printf("%g ", (double)(FNA(K))); printf("%s", "OF THE "); printf("%s", A_str); printf("%s", B_str); printf("%s", " KILLED."); printf("\n");
    /* BASIC: 1900 PRINT */
line_1900:;
    printf("\n");
    /* BASIC: 1910 RETURN */
line_1910:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1920 REM */
line_1920:;
    /* REM */
    /* BASIC: 1930 INPUT A$ */
line_1930:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    /* BASIC: 1940 IF A$="YES" THEN 1990 */
line_1940:;
    if (strcmp(A_str, "YES") == 0) { goto line_1990; }
    /* BASIC: 1950 IF A$="NO" THEN 2010 */
line_1950:;
    if (strcmp(A_str, "NO") == 0) { goto line_2010; }
    /* BASIC: 1970 PRINT "INCORRECT ANSWER - - PLEASE TYPE 'YES' OR 'NO'." */
line_1970:;
    printf("%s", "INCORRECT ANSWER - - PLEASE TYPE 'YES' OR 'NO'."); printf("\n");
    /* BASIC: 1980 GOTO 1930 */
line_1980:;
    goto line_1930;
    /* BASIC: 1990 Z1=1 */
line_1990:;
    Z1 = 1;
    /* BASIC: 2000 GOTO 2020 */
line_2000:;
    goto line_2020;
    /* BASIC: 2010 Z1=2 */
line_2010:;
    Z1 = 2;
    /* BASIC: 2020 RETURN */
line_2020:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 2030 END */
line_2030:;
    exit(0);

    return 0;
}
