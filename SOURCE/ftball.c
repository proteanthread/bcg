/*
 * Transpiled from ftball.bas
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

typedef enum { DATA_NUM, DATA_STR } DataType;
typedef struct {
    DataType type;
    union {
        double num;
        const char *str;
    } u;
} DataItem;

static DataItem program_data[20] = {
    { DATA_STR, { .str = "KICK" } },
    { DATA_STR, { .str = "RECEIVE" } },
    { DATA_STR, { .str = " YARD " } },
    { DATA_STR, { .str = "RUN BACK FOR " } },
    { DATA_STR, { .str = "BALL ON " } },
    { DATA_STR, { .str = "YARD LINE" } },
    { DATA_STR, { .str = " SIMPLE RUN" } },
    { DATA_STR, { .str = " TRICKY RUN" } },
    { DATA_STR, { .str = " SHORT PASS" } },
    { DATA_STR, { .str = " LONG PASS" } },
    { DATA_STR, { .str = "PUNT" } },
    { DATA_STR, { .str = " QUICK KICK " } },
    { DATA_STR, { .str = " PLACE KICK" } },
    { DATA_STR, { .str = " LOSS " } },
    { DATA_STR, { .str = " NO GAIN" } },
    { DATA_STR, { .str = "GAIN " } },
    { DATA_STR, { .str = " TOUCHDOWN " } },
    { DATA_STR, { .str = " TOUCHBACK " } },
    { DATA_STR, { .str = "SAFETY***" } },
    { DATA_STR, { .str = "JUNK" } },
};
static int data_ptr = 0;

static void read_numeric(double *var) {
    if (data_ptr < sizeof(program_data)/sizeof(program_data[0])) {
        if (program_data[data_ptr].type == DATA_NUM) *var = program_data[data_ptr].u.num;
        else *var = atof(program_data[data_ptr].u.str);
        data_ptr++;
    }
}

static void read_string(char *var, size_t max_len) {
    if (data_ptr < sizeof(program_data)/sizeof(program_data[0])) {
        if (program_data[data_ptr].type == DATA_STR) strncpy(var, program_data[data_ptr].u.str, max_len - 1);
        else snprintf(var, max_len, "%g", program_data[data_ptr].u.num);
        var[max_len - 1] = '\0';
        data_ptr++;
    }
}

/* Global variables */
static int gosub_stack[256];
static int gosub_sp = 0;
static double A, D, DEF, E, F, I, LET, ON, P, P3, R, R1, S, T, X, X1, X3, Y, Y1, Z;
static char A_str[256] = {0};
static char L_str[256] = {0};
static char O_str[256] = {0};
static double S_arr[20000] = {0};
static char L_str_arr[20000][256] = {0};
static char O_str_arr[20000][256] = {0};
static char _input_buf[256];

/* User-defined functions forward declarations */
static double FNF(double X);
static double FNG(double Z);

/* User-defined functions definitions */
static double FNF(double X) {
    return 1-2*P;
}

static double FNG(double Z) {
    return P*(X1-X)+(1-P)*(X-X1);
}

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(33);"FTBALL" */
line_10:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "FTBALL"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT */
line_30:;
    printf("\n");
    printf("\n");
    /* BASIC: 220 PRINT "THIS IS DARTMOUTH CHAMPIONSHIP FOOTBALL.":PRINT */
line_220:;
    printf("%s", "THIS IS DARTMOUTH CHAMPIONSHIP FOOTBALL."); printf("\n");
    printf("\n");
    /* BASIC: 230 PRINT "YOU WILL QUARTERBACK DARTMOUTH. CALL PLAYS AS FOLLOWS:" */
line_230:;
    printf("%s", "YOU WILL QUARTERBACK DARTMOUTH. CALL PLAYS AS FOLLOWS:"); printf("\n");
    /* BASIC: 240 PRINT "1= SIMPLE RUN; 2= TRICKY RUN; 3= SHORT PASS;" */
line_240:;
    printf("%s", "1= SIMPLE RUN; 2= TRICKY RUN; 3= SHORT PASS;"); printf("\n");
    /* BASIC: 250 PRINT "4= LONG PASS; 5= PUNT; 6= QUICK KICK; 7= PLACE KICK." */
line_250:;
    printf("%s", "4= LONG PASS; 5= PUNT; 6= QUICK KICK; 7= PLACE KICK."); printf("\n");
    /* BASIC: 260 PRINT */
line_260:;
    printf("\n");
    /* BASIC: 270 PRINT "CHOOSE YOUR OPPONENT"; */
line_270:;
    printf("%s", "CHOOSE YOUR OPPONENT");
    /* BASIC: 280 INPUT O$(1) */
line_280:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", O_str_arr[(int)(1)]);
    /* BASIC: 290 O$(0)="DARTMOUTH" */
line_290:;
    str_assign(O_str_arr[(int)(0)], sizeof(O_str_arr[(int)(0)]), "DARTMOUTH");
    /* BASIC: 300 PRINT */
line_300:;
    printf("\n");
    /* BASIC: 310 LET S(0)=0: LET S(1)=0 */
line_310:;
    /* UNTRANSLATED: LET S(0)=0 */
    /* UNTRANSLATED: LET S(1)=0 */
    /* BASIC: 320 REM */
line_320:;
    // REM
    /* BASIC: 330 DIM L$(20) */
line_330:;
    /* DIM L$(20) (handled statically) */
    /* BASIC: 340 FOR I=1 TO 20: READ L$(I): NEXT I */
line_340:;
    I = 1; for_loop_I_340: if (((1) >= 0 && I > (20)) || ((1) < 0 && I < (20))) goto end_for_I_340;
    read_string(L_str_arr[(int)(I)], sizeof(L_str_arr[(int)(I)]));
    I += (1); goto for_loop_I_340; end_for_I_340:;
    /* BASIC: 350 DATA "KICK","RECEIVE"," YARD ","RUN BACK FOR ","BALL ON " */
line_350:;
    /* UNTRANSLATED: DATA "KICK","RECEIVE"," YARD ","RUN BACK FOR ","BALL ON " */
    /* BASIC: 360 DATA "YARD LINE"," SIMPLE RUN"," TRICKY RUN"," SHORT PASS" */
line_360:;
    /* UNTRANSLATED: DATA "YARD LINE"," SIMPLE RUN"," TRICKY RUN"," SHORT PASS" */
    /* BASIC: 370 DATA " LONG PASS","PUNT"," QUICK KICK "," PLACE KICK"," LOSS " */
line_370:;
    /* UNTRANSLATED: DATA " LONG PASS","PUNT"," QUICK KICK "," PLACE KICK"," LOSS " */
    /* BASIC: 380 DATA " NO GAIN","GAIN "," TOUCHDOWN "," TOUCHBACK ","SAFETY***" */
line_380:;
    /* UNTRANSLATED: DATA " NO GAIN","GAIN "," TOUCHDOWN "," TOUCHBACK ","SAFETY***" */
    /* BASIC: 385 DATA "JUNK" */
line_385:;
    /* UNTRANSLATED: DATA "JUNK" */
    /* BASIC: 390 LET P=INT(RND(1)*2) */
line_390:;
    /* UNTRANSLATED: LET P=INT(RND(1)*2) */
    /* BASIC: 400 PRINT O$(P);" WON THE TOSS" */
line_400:;
    printf("%s", O_str_arr[(int)(P)]); printf("%s", " WON THE TOSS"); printf("\n");
    /* BASIC: 410 DEF FNF(X)=1-2*P */
line_410:;
    /* UNTRANSLATED: DEF FNF(X)=1-2*P */
    /* BASIC: 420 DEF FNG(Z)=P*(X1-X)+(1-P)*(X-X1) */
line_420:;
    /* UNTRANSLATED: DEF FNG(Z)=P*(X1-X)+(1-P)*(X-X1) */
    /* BASIC: 430 IF P=0 THEN 470 */
line_430:;
    if (P==0) { goto line_470; }
    /* BASIC: 440 PRINT O$(1);" ELECTS TO RECEIVE." */
line_440:;
    printf("%s", O_str_arr[(int)(1)]); printf("%s", " ELECTS TO RECEIVE."); printf("\n");
    /* BASIC: 450 PRINT */
line_450:;
    printf("\n");
    /* BASIC: 460 GOTO 580 */
line_460:;
    goto line_580;
    /* BASIC: 470 PRINT "DO YOU ELECT TO KICK OR RECEIVE"; */
line_470:;
    printf("%s", "DO YOU ELECT TO KICK OR RECEIVE");
    /* BASIC: 480 INPUT A$ */
line_480:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    /* BASIC: 490 PRINT */
line_490:;
    printf("\n");
    /* BASIC: 500 FOR E=1 TO 2 */
line_500:;
    E = 1; for_loop_E_500: if (((1) >= 0 && E > (2)) || ((1) < 0 && E < (2))) goto end_for_E_500;
    /* BASIC: 510 IF A$=L$(E) THEN 550 */
line_510:;
    if (strcmp(A_str, L_str_arr[(int)(E)]) == 0) { goto line_550; }
    /* BASIC: 520 NEXT E */
line_520:;
    E += (1); goto for_loop_E_500; end_for_E_500:;
    /* BASIC: 530 PRINT "INCORRECT ANSWER.  PLEASE TYPE 'KICK' OR 'RECIEVE'"; */
line_530:;
    printf("%s", "INCORRECT ANSWER.  PLEASE TYPE 'KICK' OR 'RECIEVE'");
    /* BASIC: 540 GOTO 480 */
line_540:;
    goto line_480;
    /* BASIC: 550 IF E=2 THEN 580 */
line_550:;
    if (E==2) { goto line_580; }
    /* BASIC: 560 LET P=1 */
line_560:;
    /* UNTRANSLATED: LET P=1 */
    /* BASIC: 580 LET X=40+(1-P)*20 */
line_580:;
    /* UNTRANSLATED: LET X=40+(1-P)*20 */
    /* BASIC: 590 LET Y=INT(200*(RND(1)-.5)^3+55) */
line_590:;
    /* UNTRANSLATED: LET Y=INT(200*(RND(1)-.5)^3+55) */
    /* BASIC: 600 PRINT Y;L$(3);" KICKOFF" */
line_600:;
    printf("%g ", (double)(Y)); printf("%s", L_str_arr[(int)(3)]); printf("%s", " KICKOFF"); printf("\n");
    /* BASIC: 610 LET X=X-FNF(1)*Y */
line_610:;
    /* UNTRANSLATED: LET X=X-FNF(1)*Y */
    /* BASIC: 620 IF ABS(X-50)>=50 THEN 700 */
line_620:;
    if (fabs(X-50)>=50) { goto line_700; }
    /* BASIC: 630 LET Y=INT(50*RND(1)^2)+(1-P)*INT(50*RND(1)^4) */
line_630:;
    /* UNTRANSLATED: LET Y=INT(50*RND(1)^2)+(1-P)*INT(50*RND(1)^4) */
    /* BASIC: 640 LET X=X+FNF(1)*Y */
line_640:;
    /* UNTRANSLATED: LET X=X+FNF(1)*Y */
    /* BASIC: 650 IF ABS(X-50)>=50 THEN 655 */
line_650:;
    if (fabs(X-50)>=50) { goto line_655; }
    /* BASIC: 651 PRINT Y;L$(3);" RUNBACK" */
line_651:;
    printf("%g ", (double)(Y)); printf("%s", L_str_arr[(int)(3)]); printf("%s", " RUNBACK"); printf("\n");
    /* BASIC: 652 GOTO 720 */
line_652:;
    goto line_720;
    /* BASIC: 655 PRINT L$(4); */
line_655:;
    printf("%s", L_str_arr[(int)(4)]);
    /* BASIC: 660 GOTO 2600 */
line_660:;
    goto line_2600;
    /* BASIC: 700 PRINT "TOUCHBACK FOR ";O$(P);"." */
line_700:;
    printf("%s", "TOUCHBACK FOR "); printf("%s", O_str_arr[(int)(P)]); printf("%s", "."); printf("\n");
    /* BASIC: 710 LET X=20+P*60 */
line_710:;
    /* UNTRANSLATED: LET X=20+P*60 */
    /* BASIC: 720 REM FIRST DOWN */
line_720:;
    // REM FIRST DOWN
    /* BASIC: 730 GOSUB 800 */
line_730:;
    gosub_stack[gosub_sp++] = 1; goto line_800; line_ret_1:;
    /* BASIC: 740 LET X1=X */
line_740:;
    /* UNTRANSLATED: LET X1=X */
    /* BASIC: 750 LET D=1 */
line_750:;
    /* UNTRANSLATED: LET D=1 */
    /* BASIC: 760 PRINT:PRINT "FIRST DOWN ";O$(P);"***" */
line_760:;
    printf("\n");
    printf("%s", "FIRST DOWN "); printf("%s", O_str_arr[(int)(P)]); printf("%s", "***"); printf("\n");
    /* BASIC: 770 PRINT */
line_770:;
    printf("\n");
    /* BASIC: 780 PRINT */
line_780:;
    printf("\n");
    /* BASIC: 790 GOTO 860 */
line_790:;
    goto line_860;
    /* BASIC: 800 REM PRINT POSITION */
line_800:;
    // REM PRINT POSITION
    /* BASIC: 810 IF X>50 THEN 840 */
line_810:;
    if (X>50) { goto line_840; }
    /* BASIC: 820 PRINT L$(5);O$(0);X;L$(6) */
line_820:;
    printf("%s", L_str_arr[(int)(5)]); printf("%s", O_str_arr[(int)(0)]); printf("%g ", (double)(X)); printf("%s", L_str_arr[(int)(6)]); printf("\n");
    /* BASIC: 830 GOTO 850 */
line_830:;
    goto line_850;
    /* BASIC: 840 PRINT L$(5);O$(1);100-X;L$(6) */
line_840:;
    printf("%s", L_str_arr[(int)(5)]); printf("%s", O_str_arr[(int)(1)]); printf("%g ", (double)(100-X)); printf("%s", L_str_arr[(int)(6)]); printf("\n");
    /* BASIC: 850 RETURN */
line_850:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 860 REM NEW PLAY */
line_860:;
    // REM NEW PLAY
    /* BASIC: 870 LET T=T+1 */
line_870:;
    /* UNTRANSLATED: LET T=T+1 */
    /* BASIC: 880 IF T=30 THEN 1060 */
line_880:;
    if (T==30) { goto line_1060; }
    /* BASIC: 890 IF T<50 THEN 940 */
line_890:;
    if (T<50) { goto line_940; }
    /* BASIC: 900 IF RND(1)>.2 THEN 940 */
line_900:;
    if (((double)rand() / (double)RAND_MAX)>.2) { goto line_940; }
    /* BASIC: 910 PRINT "END OF GAME  ***" */
line_910:;
    printf("%s", "END OF GAME  ***"); printf("\n");
    /* BASIC: 920 PRINT "FINAL SCORE:  ";O$(0);": ";S(0);"  ";O$(1);": ";S(1) */
line_920:;
    printf("%s", "FINAL SCORE:  "); printf("%s", O_str_arr[(int)(0)]); printf("%s", ": "); printf("%g ", (double)(S_arr[(int)(0)])); printf("%s", "  "); printf("%s", O_str_arr[(int)(1)]); printf("%s", ": "); printf("%g ", (double)(S_arr[(int)(1)])); printf("\n");
    /* BASIC: 930 S TO P */
line_930:;
    /* UNTRANSLATED: S TO P */
    /* BASIC: 940 IF P=1 THEN 1870 */
line_940:;
    if (P==1) { goto line_1870; }
    /* BASIC: 950 PRINT "NEXT PLAY"; */
line_950:;
    printf("%s", "NEXT PLAY");
    /* BASIC: 960 INPUT Z */
line_960:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &Z);
    /* BASIC: 970 IF Z<>INT(Z) THEN 990 */
line_970:;
    if (Z!=floor(Z)) { goto line_990; }
    /* BASIC: 980 IF ABS(Z-4)<=3 THEN 1010 */
line_980:;
    if (fabs(Z-4)<=3) { goto line_1010; }
    /* BASIC: 990 PRINT "ILLEGAL PLAY NUMBER, RETYPE"; */
line_990:;
    printf("%s", "ILLEGAL PLAY NUMBER, RETYPE");
    /* BASIC: 1000 GOTO 960 */
line_1000:;
    goto line_960;
    /* BASIC: 1010 LET F=0 */
line_1010:;
    /* UNTRANSLATED: LET F=0 */
    /* BASIC: 1020 PRINT L$(Z+6);".  "; */
line_1020:;
    printf("%s", L_str_arr[(int)(Z+6)]); printf("%s", ".  ");
    /* BASIC: 1030 LET R=RND(1)*(.98+FNF(1)*.02) */
line_1030:;
    /* UNTRANSLATED: LET R=RND(1)*(.98+FNF(1)*.02) */
    /* BASIC: 1040 LET R1=RND(1) */
line_1040:;
    /* UNTRANSLATED: LET R1=RND(1) */
    /* BASIC: 1050 ON Z GOTO 1110,1150,1260,1480,1570,1570,1680 */
line_1050:;
    switch ((int)(Z)) {     case 1: goto line_1110;     case 2: goto line_1150;     case 3: goto line_1260;     case 4: goto line_1480;     case 5: goto line_1570;     case 6: goto line_1570;     case 7: goto line_1680; }
    /* BASIC: 1060 REM  JEAN'S SPECIAL */
line_1060:;
    // REM  JEAN'S SPECIAL
    /* BASIC: 1070 IF RND(1)> 1/3 THEN 940 */
line_1070:;
    if (((double)rand() / (double)RAND_MAX)> 1/3) { goto line_940; }
    /* BASIC: 1080 PRINT "GAME DELAYED.  DOG ON FIELD." */
line_1080:;
    printf("%s", "GAME DELAYED.  DOG ON FIELD."); printf("\n");
    /* BASIC: 1090 PRINT */
line_1090:;
    printf("\n");
    /* BASIC: 1100 GOTO 940 */
line_1100:;
    goto line_940;
    /* BASIC: 1110 REM  SIMPLE RUN */
line_1110:;
    // REM  SIMPLE RUN
    /* BASIC: 1120 LET Y=INT(24*(R-.5)^3+3) */
line_1120:;
    /* UNTRANSLATED: LET Y=INT(24*(R-.5)^3+3) */
    /* BASIC: 1130 IF RND(1)<.05 THEN 1180 */
line_1130:;
    if (((double)rand() / (double)RAND_MAX)<.05) { goto line_1180; }
    /* BASIC: 1140 GOTO 2190 */
line_1140:;
    goto line_2190;
    /* BASIC: 1150 REM  TRICKY RUN */
line_1150:;
    // REM  TRICKY RUN
    /* BASIC: 1160 LET Y=INT(20*R-5) */
line_1160:;
    /* UNTRANSLATED: LET Y=INT(20*R-5) */
    /* BASIC: 1170 IF RND(1)>.1 THEN 2190 */
line_1170:;
    if (((double)rand() / (double)RAND_MAX)>.1) { goto line_2190; }
    /* BASIC: 1180 LET F=-1 */
line_1180:;
    /* UNTRANSLATED: LET F=-1 */
    /* BASIC: 1190 LET X3=X */
line_1190:;
    /* UNTRANSLATED: LET X3=X */
    /* BASIC: 1200 LET X=X+FNF(1)*Y */
line_1200:;
    /* UNTRANSLATED: LET X=X+FNF(1)*Y */
    /* BASIC: 1210 IF ABS(X-50)>=50 THEN 1240 */
line_1210:;
    if (fabs(X-50)>=50) { goto line_1240; }
    /* BASIC: 1220 PRINT "***  FUMBLE AFTER "; */
line_1220:;
    printf("%s", "***  FUMBLE AFTER ");
    /* BASIC: 1230 GOTO 2230 */
line_1230:;
    goto line_2230;
    /* BASIC: 1240 PRINT "***  FUMBLE." */
line_1240:;
    printf("%s", "***  FUMBLE."); printf("\n");
    /* BASIC: 1250 GOTO 2450 */
line_1250:;
    goto line_2450;
    /* BASIC: 1260 REM  SH OR T PASS */
line_1260:;
    // REM  SH OR T PASS
    /* BASIC: 1270 LET Y=INT(60*(R1-.5)^3+10) */
line_1270:;
    /* UNTRANSLATED: LET Y=INT(60*(R1-.5)^3+10) */
    /* BASIC: 1280 IF R<.05 THEN 1330 */
line_1280:;
    if (R<.05) { goto line_1330; }
    /* BASIC: 1290 IF R<.15 THEN 1390 */
line_1290:;
    if (R<.15) { goto line_1390; }
    /* BASIC: 1300 IF R<.55 THEN 1420 */
line_1300:;
    if (R<.55) { goto line_1420; }
    /* BASIC: 1310 PRINT "COMPLETE.  "; */
line_1310:;
    printf("%s", "COMPLETE.  ");
    /* BASIC: 1320 GOTO 2190 */
line_1320:;
    goto line_2190;
    /* BASIC: 1330 IF D=4 THEN 1420 */
line_1330:;
    if (D==4) { goto line_1420; }
    /* BASIC: 1340 PRINT "INTERCEPTED." */
line_1340:;
    printf("%s", "INTERCEPTED."); printf("\n");
    /* BASIC: 1350 LET F=-1 */
line_1350:;
    /* UNTRANSLATED: LET F=-1 */
    /* BASIC: 1360 LET X=X+FNF(1)*Y */
line_1360:;
    /* UNTRANSLATED: LET X=X+FNF(1)*Y */
    /* BASIC: 1370 IF ABS(X-50)>=50 THEN 2450 */
line_1370:;
    if (fabs(X-50)>=50) { goto line_2450; }
    /* BASIC: 1380 GOTO 2300 */
line_1380:;
    goto line_2300;
    /* BASIC: 1390 PRINT "PASSER TACKLED.  "; */
line_1390:;
    printf("%s", "PASSER TACKLED.  ");
    /* BASIC: 1400 LET Y=-INT(10*R1) */
line_1400:;
    /* UNTRANSLATED: LET Y=-INT(10*R1) */
    /* BASIC: 1410 GOTO 2190 */
line_1410:;
    goto line_2190;
    /* BASIC: 1420 LET Y=0 */
line_1420:;
    /* UNTRANSLATED: LET Y=0 */
    /* BASIC: 1430 IF RND(1)<.3 THEN 1460 */
line_1430:;
    if (((double)rand() / (double)RAND_MAX)<.3) { goto line_1460; }
    /* BASIC: 1440 PRINT "INCOMPLETE.  "; */
line_1440:;
    printf("%s", "INCOMPLETE.  ");
    /* BASIC: 1450 GOTO 2190 */
line_1450:;
    goto line_2190;
    /* BASIC: 1460 PRINT "BATTED DOWN.  "; */
line_1460:;
    printf("%s", "BATTED DOWN.  ");
    /* BASIC: 1470 GOTO 2190 */
line_1470:;
    goto line_2190;
    /* BASIC: 1480 REM  LONG PASS */
line_1480:;
    // REM  LONG PASS
    /* BASIC: 1490 LET Y=INT(160*(R1-.5)^3+30) */
line_1490:;
    /* UNTRANSLATED: LET Y=INT(160*(R1-.5)^3+30) */
    /* BASIC: 1500 IF R<.1 THEN 1330 */
line_1500:;
    if (R<.1) { goto line_1330; }
    /* BASIC: 1510 IF R<.3 THEN 1540 */
line_1510:;
    if (R<.3) { goto line_1540; }
    /* BASIC: 1520 IF R<.75 THEN 1420 */
line_1520:;
    if (R<.75) { goto line_1420; }
    /* BASIC: 1530 GOTO 1310 */
line_1530:;
    goto line_1310;
    /* BASIC: 1540 PRINT "PASSER TACKLED.  "; */
line_1540:;
    printf("%s", "PASSER TACKLED.  ");
    /* BASIC: 1550 LET Y=-INT(15*R1+3) */
line_1550:;
    /* UNTRANSLATED: LET Y=-INT(15*R1+3) */
    /* BASIC: 1560 GOTO 2190 */
line_1560:;
    goto line_2190;
    /* BASIC: 1570 REM  PUNT OR KICK */
line_1570:;
    // REM  PUNT OR KICK
    /* BASIC: 1580 LET Y=INT(100*(R-.5)^3+35) */
line_1580:;
    /* UNTRANSLATED: LET Y=INT(100*(R-.5)^3+35) */
    /* BASIC: 1590 IF D=4 THEN 1610 */
line_1590:;
    if (D==4) { goto line_1610; }
    /* BASIC: 1600 LET Y=INT(Y*1.3) */
line_1600:;
    /* UNTRANSLATED: LET Y=INT(Y*1.3) */
    /* BASIC: 1610 PRINT Y;L$(3);" PUNT" */
line_1610:;
    printf("%g ", (double)(Y)); printf("%s", L_str_arr[(int)(3)]); printf("%s", " PUNT"); printf("\n");
    /* BASIC: 1620 IF ABS(X+Y*FNF(1)-50)>=50 THEN 1670 */
line_1620:;
    if (fabs(X+Y*FNF(1)-50)>=50) { goto line_1670; }
    /* BASIC: 1630 IF D<4 THEN 1670 */
line_1630:;
    if (D<4) { goto line_1670; }
    /* BASIC: 1640 LET Y1=INT(R1^2*20) */
line_1640:;
    /* UNTRANSLATED: LET Y1=INT(R1^2*20) */
    /* BASIC: 1650 PRINT Y1;L$(3);" RUN BACK" */
line_1650:;
    printf("%g ", (double)(Y1)); printf("%s", L_str_arr[(int)(3)]); printf("%s", " RUN BACK"); printf("\n");
    /* BASIC: 1660 LET Y=Y-Y1 */
line_1660:;
    /* UNTRANSLATED: LET Y=Y-Y1 */
    /* BASIC: 1670 GOTO 1350 */
line_1670:;
    goto line_1350;
    /* BASIC: 1680 REM  PLACE KICK */
line_1680:;
    // REM  PLACE KICK
    /* BASIC: 1690 LET Y=INT(100*(R-.5)^3+35) */
line_1690:;
    /* UNTRANSLATED: LET Y=INT(100*(R-.5)^3+35) */
    /* BASIC: 1700 IF R1>.15 THEN 1740 */
line_1700:;
    if (R1>.15) { goto line_1740; }
    /* BASIC: 1710 PRINT "KICK IS BLOCKED  ***" */
line_1710:;
    printf("%s", "KICK IS BLOCKED  ***"); printf("\n");
    /* BASIC: 1720 LET X=X-5*FNF(1) */
line_1720:;
    /* UNTRANSLATED: LET X=X-5*FNF(1) */
    /* BASIC: 1730 LET P=1-P */
line_1730:;
    /* UNTRANSLATED: LET P=1-P */
    /* BASIC: 1740 GOTO 720 */
line_1740:;
    goto line_720;
    /* BASIC: 1750 LET X=X+FNF(1)*Y */
line_1750:;
    /* UNTRANSLATED: LET X=X+FNF(1)*Y */
    /* BASIC: 1760 IF ABS(X-50)>=60 THEN 1810 */
line_1760:;
    if (fabs(X-50)>=60) { goto line_1810; }
    /* BASIC: 1770 PRINT "KICK IS SHORT." */
line_1770:;
    printf("%s", "KICK IS SHORT."); printf("\n");
    /* BASIC: 1780 IF ABS(X-50)>=50 THEN 2710 */
line_1780:;
    if (fabs(X-50)>=50) { goto line_2710; }
    /* BASIC: 1790 P=1-P */
line_1790:;
    P = 1-P;
    /* BASIC: 1800 GOTO 630 */
line_1800:;
    goto line_630;
    /* BASIC: 1810 IF R1>.5 THEN 1840 */
line_1810:;
    if (R1>.5) { goto line_1840; }
    /* BASIC: 1820 PRINT "KICK IS OFF TO THE SIDE." */
line_1820:;
    printf("%s", "KICK IS OFF TO THE SIDE."); printf("\n");
    /* BASIC: 1830 GOTO 2710 */
line_1830:;
    goto line_2710;
    /* BASIC: 1840 PRINT "FIELD GOAL ***" */
line_1840:;
    printf("%s", "FIELD GOAL ***"); printf("\n");
    /* BASIC: 1850 LET S(P)=S(P)+3 */
line_1850:;
    /* UNTRANSLATED: LET S(P)=S(P)+3 */
    /* BASIC: 1860 GOTO 2640 */
line_1860:;
    goto line_2640;
    /* BASIC: 1870 REM  OPPONENT'S PLAY */
line_1870:;
    // REM  OPPONENT'S PLAY
    /* BASIC: 1880 IF D>1 THEN 1940 */
line_1880:;
    if (D>1) { goto line_1940; }
    /* BASIC: 1890 IF RND(1)>1/3 THEN 1920 */
line_1890:;
    if (((double)rand() / (double)RAND_MAX)>1/3) { goto line_1920; }
    /* BASIC: 1900 LET Z=3 */
line_1900:;
    /* UNTRANSLATED: LET Z=3 */
    /* BASIC: 1910 GOTO 1010 */
line_1910:;
    goto line_1010;
    /* BASIC: 1920 LET Z=1 */
line_1920:;
    /* UNTRANSLATED: LET Z=1 */
    /* BASIC: 1930 GOTO 1010 */
line_1930:;
    goto line_1010;
    /* BASIC: 1940 IF D=4 THEN 2090 */
line_1940:;
    if (D==4) { goto line_2090; }
    /* BASIC: 1950 IF 10+X-X1<5 THEN 1890 */
line_1950:;
    if (10+X-X1<5) { goto line_1890; }
    /* BASIC: 1960 IF X<5 THEN 1890 */
line_1960:;
    if (X<5) { goto line_1890; }
    /* BASIC: 1970 IF X<=10 THEN 2160 */
line_1970:;
    if (X<=10) { goto line_2160; }
    /* BASIC: 1980 IF X>X1 THEN 2020 */
line_1980:;
    if (X>X1) { goto line_2020; }
    /* BASIC: 1990 LET A=INT(2*RND(1)) */
line_1990:;
    /* UNTRANSLATED: LET A=INT(2*RND(1)) */
    /* BASIC: 2000 LET Z=2+A*2 */
line_2000:;
    /* UNTRANSLATED: LET Z=2+A*2 */
    /* BASIC: 2010 GOTO 1010 */
line_2010:;
    goto line_1010;
    /* BASIC: 2020 IF D<3 THEN 1990 */
line_2020:;
    if (D<3) { goto line_1990; }
    /* BASIC: 2030 IF X<45 THEN 1990 */
line_2030:;
    if (X<45) { goto line_1990; }
    /* BASIC: 2040 IF RND(1)>1/4 THEN 2070 */
line_2040:;
    if (((double)rand() / (double)RAND_MAX)>1/4) { goto line_2070; }
    /* BASIC: 2050 LET Z=6 */
line_2050:;
    /* UNTRANSLATED: LET Z=6 */
    /* BASIC: 2060 GOTO 1010 */
line_2060:;
    goto line_1010;
    /* BASIC: 2070 LET Z=4 */
line_2070:;
    /* UNTRANSLATED: LET Z=4 */
    /* BASIC: 2080 GOTO 1010 */
line_2080:;
    goto line_1010;
    /* BASIC: 2090 IF X>30 THEN 2140 */
line_2090:;
    if (X>30) { goto line_2140; }
    /* BASIC: 2100 IF 10+X-X1<3 THEN 1890 */
line_2100:;
    if (10+X-X1<3) { goto line_1890; }
    /* BASIC: 2110 IF X<3 THEN 1890 */
line_2110:;
    if (X<3) { goto line_1890; }
    /* BASIC: 2120 LET Z=7 */
line_2120:;
    /* UNTRANSLATED: LET Z=7 */
    /* BASIC: 2130 GOTO 1010 */
line_2130:;
    goto line_1010;
    /* BASIC: 2140 LET Z=5 */
line_2140:;
    /* UNTRANSLATED: LET Z=5 */
    /* BASIC: 2150 GOTO 1010 */
line_2150:;
    goto line_1010;
    /* BASIC: 2160 LET A=INT(2*RND(1)) */
line_2160:;
    /* UNTRANSLATED: LET A=INT(2*RND(1)) */
    /* BASIC: 2170 LET Z=2+A */
line_2170:;
    /* UNTRANSLATED: LET Z=2+A */
    /* BASIC: 2180 GOTO 1010 */
line_2180:;
    goto line_1010;
    /* BASIC: 2190 REM GAIN OR LOSS */
line_2190:;
    // REM GAIN OR LOSS
    /* BASIC: 2200 LET X3=X */
line_2200:;
    /* UNTRANSLATED: LET X3=X */
    /* BASIC: 2210 LET X=X+FNF(1)*Y */
line_2210:;
    /* UNTRANSLATED: LET X=X+FNF(1)*Y */
    /* BASIC: 2220 IF ABS(X-50)>=50 THEN 2450 */
line_2220:;
    if (fabs(X-50)>=50) { goto line_2450; }
    /* BASIC: 2230 IF Y=0 THEN 2250 */
line_2230:;
    if (Y==0) { goto line_2250; }
    /* BASIC: 2240 PRINT ABS(Y);L$(3); */
line_2240:;
    printf("%g ", (double)(fabs(Y))); printf("%s", L_str_arr[(int)(3)]);
    /* BASIC: 2250 PRINT L$(15+SGN(Y)) */
line_2250:;
    printf("%s", L_str_arr[(int)(15+basic_SGN(Y))]); printf("\n");
    /* BASIC: 2280 IF ABS(X3-50)>40 THEN 2300 */
line_2280:;
    if (fabs(X3-50)>40) { goto line_2300; }
    /* BASIC: 2290 IF RND(1)<.1 THEN 2860 */
line_2290:;
    if (((double)rand() / (double)RAND_MAX)<.1) { goto line_2860; }
    /* BASIC: 2300 GOSUB 800 */
line_2300:;
    gosub_stack[gosub_sp++] = 2; goto line_800; line_ret_2:;
    /* BASIC: 2310 IF F=0 THEN 2340 */
line_2310:;
    if (F==0) { goto line_2340; }
    /* BASIC: 2320 LET P=1-P */
line_2320:;
    /* UNTRANSLATED: LET P=1-P */
    /* BASIC: 2330 GOTO 740 */
line_2330:;
    goto line_740;
    /* BASIC: 2340 IF FNG(1)>=10 THEN 740 */
line_2340:;
    if (FNG(1)>=10) { goto line_740; }
    /* BASIC: 2350 IF D=4 THEN 2320 */
line_2350:;
    if (D==4) { goto line_2320; }
    /* BASIC: 2360 LET D=D+1 */
line_2360:;
    /* UNTRANSLATED: LET D=D+1 */
    /* BASIC: 2370 PRINT "DOWN: ";D;"     "; */
line_2370:;
    printf("%s", "DOWN: "); printf("%g ", (double)(D)); printf("%s", "     ");
    /* BASIC: 2380 IF (X1-50)*FNF(1)<40 THEN 2410 */
line_2380:;
    if ((X1-50)*FNF(1)<40) { goto line_2410; }
    /* BASIC: 2390 PRINT "GOAL TO GO" */
line_2390:;
    printf("%s", "GOAL TO GO"); printf("\n");
    /* BASIC: 2400 GOTO 2420 */
line_2400:;
    goto line_2420;
    /* BASIC: 2410 PRINT "YARDS TO GO: ";10-FNG(1) */
line_2410:;
    printf("%s", "YARDS TO GO: "); printf("%g ", (double)(10-FNG(1))); printf("\n");
    /* BASIC: 2420 PRINT */
line_2420:;
    printf("\n");
    /* BASIC: 2430 PRINT */
line_2430:;
    printf("\n");
    /* BASIC: 2440 GOTO 860 */
line_2440:;
    goto line_860;
    /* BASIC: 2450 REM BALL IN END-ZONE */
line_2450:;
    // REM BALL IN END-ZONE
    /* BASIC: 2460 IF X>=100 THEN 2490 */
line_2460:;
    if (X>=100) { goto line_2490; }
    /* BASIC: 2470 LET E=0 */
line_2470:;
    /* UNTRANSLATED: LET E=0 */
    /* BASIC: 2480 GOTO 2500 */
line_2480:;
    goto line_2500;
    /* BASIC: 2490 LET E=1 */
line_2490:;
    /* UNTRANSLATED: LET E=1 */
    /* BASIC: 2500 ON 1+E-F*2+P*4 GOTO 2510,2590,2760,2710,2590,2510,2710,2760 */
line_2500:;
    switch ((int)(1+E-F*2+P*4)) {     case 1: goto line_2510;     case 2: goto line_2590;     case 3: goto line_2760;     case 4: goto line_2710;     case 5: goto line_2590;     case 6: goto line_2510;     case 7: goto line_2710;     case 8: goto line_2760; }
    /* BASIC: 2510 REM SAFETY */
line_2510:;
    // REM SAFETY
    /* BASIC: 2520 LET S(1-P)=S(1-P)+2 */
line_2520:;
    /* UNTRANSLATED: LET S(1-P)=S(1-P)+2 */
    /* BASIC: 2530 PRINT L$(19) */
line_2530:;
    printf("%s", L_str_arr[(int)(19)]); printf("\n");
    /* BASIC: 2540 GOSUB 2800 */
line_2540:;
    gosub_stack[gosub_sp++] = 3; goto line_2800; line_ret_3:;
    /* BASIC: 2550 PRINT O$(P);" KICKS OFF FROM ITS 20 YARD LINE." */
line_2550:;
    printf("%s", O_str_arr[(int)(P)]); printf("%s", " KICKS OFF FROM ITS 20 YARD LINE."); printf("\n");
    /* BASIC: 2560 LET X=20+P*60 */
line_2560:;
    /* UNTRANSLATED: LET X=20+P*60 */
    /* BASIC: 2570 LET P=1-P */
line_2570:;
    /* UNTRANSLATED: LET P=1-P */
    /* BASIC: 2580 GOTO 590 */
line_2580:;
    goto line_590;
    /* BASIC: 2590 REM OFFENSIVE TD */
line_2590:;
    // REM OFFENSIVE TD
    /* BASIC: 2600 PRINT L$(17);"***" */
line_2600:;
    printf("%s", L_str_arr[(int)(17)]); printf("%s", "***"); printf("\n");
    /* BASIC: 2610 IF RND(1)>.8 THEN 2680 */
line_2610:;
    if (((double)rand() / (double)RAND_MAX)>.8) { goto line_2680; }
    /* BASIC: 2620 LET S(P)=S(P)+7 */
line_2620:;
    /* UNTRANSLATED: LET S(P)=S(P)+7 */
    /* BASIC: 2630 PRINT "KICK IS GOOD." */
line_2630:;
    printf("%s", "KICK IS GOOD."); printf("\n");
    /* BASIC: 2640 GOSUB 2800 */
line_2640:;
    gosub_stack[gosub_sp++] = 4; goto line_2800; line_ret_4:;
    /* BASIC: 2650 PRINT O$(P);" KICKS OFF" */
line_2650:;
    printf("%s", O_str_arr[(int)(P)]); printf("%s", " KICKS OFF"); printf("\n");
    /* BASIC: 2660 LET P=1-P */
line_2660:;
    /* UNTRANSLATED: LET P=1-P */
    /* BASIC: 2670 GOTO 580 */
line_2670:;
    goto line_580;
    /* BASIC: 2680 PRINT "KICK IS OFF TO THE SIDE" */
line_2680:;
    printf("%s", "KICK IS OFF TO THE SIDE"); printf("\n");
    /* BASIC: 2690 LET S(P)=S(P)+6 */
line_2690:;
    /* UNTRANSLATED: LET S(P)=S(P)+6 */
    /* BASIC: 2700 GOTO 2640 */
line_2700:;
    goto line_2640;
    /* BASIC: 2710 REM TO UCHBACK */
line_2710:;
    // REM TO UCHBACK
    /* BASIC: 2720 PRINT L$(18) */
line_2720:;
    printf("%s", L_str_arr[(int)(18)]); printf("\n");
    /* BASIC: 2730 LET P=1-P */
line_2730:;
    /* UNTRANSLATED: LET P=1-P */
    /* BASIC: 2740 LET X=20+P*60 */
line_2740:;
    /* UNTRANSLATED: LET X=20+P*60 */
    /* BASIC: 2750 GOTO 720 */
line_2750:;
    goto line_720;
    /* BASIC: 2760 REM DEFENSIVE TD */
line_2760:;
    // REM DEFENSIVE TD
    /* BASIC: 2770 PRINT L$(17);"FOR ";O$(1-P);"***" */
line_2770:;
    printf("%s", L_str_arr[(int)(17)]); printf("%s", "FOR "); printf("%s", O_str_arr[(int)(1-P)]); printf("%s", "***"); printf("\n");
    /* BASIC: 2780 LET P=1-P */
line_2780:;
    /* UNTRANSLATED: LET P=1-P */
    /* BASIC: 2790 GOTO 2600 */
line_2790:;
    goto line_2600;
    /* BASIC: 2800 REM SC OR E */
line_2800:;
    // REM SC OR E
    /* BASIC: 2810 PRINT */
line_2810:;
    printf("\n");
    /* BASIC: 2820 PRINT "SCORE:  ";S(0);" TO ";S(1) */
line_2820:;
    printf("%s", "SCORE:  "); printf("%g ", (double)(S_arr[(int)(0)])); printf("%s", " TO "); printf("%g ", (double)(S_arr[(int)(1)])); printf("\n");
    /* BASIC: 2830 PRINT */
line_2830:;
    printf("\n");
    /* BASIC: 2840 PRINT */
line_2840:;
    printf("\n");
    /* BASIC: 2850 RETURN */
line_2850:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 2860 REM PENALTY */
line_2860:;
    // REM PENALTY
    /* BASIC: 2870 LET P3=INT(2*RND(1)) */
line_2870:;
    /* UNTRANSLATED: LET P3=INT(2*RND(1)) */
    /* BASIC: 2880 PRINT O$(P3);" OFFSIDES -- PENALTY OF 5 YARDS." */
line_2880:;
    printf("%s", O_str_arr[(int)(P3)]); printf("%s", " OFFSIDES -- PENALTY OF 5 YARDS."); printf("\n");
    /* BASIC: 2890 PRINT */
line_2890:;
    printf("\n");
    /* BASIC: 2900 PRINT */
line_2900:;
    printf("\n");
    /* BASIC: 2910 IF P3=0 THEN 2980 */
line_2910:;
    if (P3==0) { goto line_2980; }
    /* BASIC: 2920 PRINT "DO YOU ACCEPT THE PENALTY"; */
line_2920:;
    printf("%s", "DO YOU ACCEPT THE PENALTY");
    /* BASIC: 2930 INPUT A$ */
line_2930:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    /* BASIC: 2940 IF A$="NO" THEN 2300 */
line_2940:;
    if (strcmp(A_str, "NO") == 0) { goto line_2300; }
    /* BASIC: 2950 IF A$="YES" THEN 3110 */
line_2950:;
    if (strcmp(A_str, "YES") == 0) { goto line_3110; }
    /* BASIC: 2960 PRINT "TYPE 'YES' OR 'NO'"; */
line_2960:;
    printf("%s", "TYPE 'YES' OR 'NO'");
    /* BASIC: 2970 GOTO 2930 */
line_2970:;
    goto line_2930;
    /* BASIC: 2980 REM OPPONENT'S STRATEGY ON PENALTY */
line_2980:;
    // REM OPPONENT'S STRATEGY ON PENALTY
    /* BASIC: 2990 IF P=1 THEN 3040 */
line_2990:;
    if (P==1) { goto line_3040; }
    /* BASIC: 3000 IF Y<=0 THEN 3080 */
line_3000:;
    if (Y<=0) { goto line_3080; }
    /* BASIC: 3010 IF F<0 THEN 3080 */
line_3010:;
    if (F<0) { goto line_3080; }
    /* BASIC: 3020 IF FNG(1)<3*D-2 THEN 3080 */
line_3020:;
    if (FNG(1)<3*D-2) { goto line_3080; }
    /* BASIC: 3030 GOTO 3100 */
line_3030:;
    goto line_3100;
    /* BASIC: 3040 IF Y<=5 THEN 3100 */
line_3040:;
    if (Y<=5) { goto line_3100; }
    /* BASIC: 3050 IF F<0 THEN 3100 */
line_3050:;
    if (F<0) { goto line_3100; }
    /* BASIC: 3060 IF D<4 THEN 3080 */
line_3060:;
    if (D<4) { goto line_3080; }
    /* BASIC: 3070 IF FNG(1)<10 THEN 3100 */
line_3070:;
    if (FNG(1)<10) { goto line_3100; }
    /* BASIC: 3080 PRINT "PENALTY REFUSED." */
line_3080:;
    printf("%s", "PENALTY REFUSED."); printf("\n");
    /* BASIC: 3090 GOTO 2300 */
line_3090:;
    goto line_2300;
    /* BASIC: 3100 PRINT "PENALTY ACCEPTED." */
line_3100:;
    printf("%s", "PENALTY ACCEPTED."); printf("\n");
    /* BASIC: 3110 LET F=0 */
line_3110:;
    /* UNTRANSLATED: LET F=0 */
    /* BASIC: 3120 LET D=D-1 */
line_3120:;
    /* UNTRANSLATED: LET D=D-1 */
    /* BASIC: 3130 IF P<>P3 THEN 3160 */
line_3130:;
    if (P!=P3) { goto line_3160; }
    /* BASIC: 3140 LET X=X3-FNF(1)*5 */
line_3140:;
    /* UNTRANSLATED: LET X=X3-FNF(1)*5 */
    /* BASIC: 3150 GOTO 2300 */
line_3150:;
    goto line_2300;
    /* BASIC: 3160 LET X=X3+FNF(1)*5 */
line_3160:;
    /* UNTRANSLATED: LET X=X3+FNF(1)*5 */
    /* BASIC: 3170 GOTO 2300 */
line_3170:;
    goto line_2300;
    /* BASIC: 3180 END */
line_3180:;
    exit(0);

    return 0;
}
