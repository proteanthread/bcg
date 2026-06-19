/*
 * Transpiled from weekday.bas
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

static DataItem program_data[12] = {
    { DATA_NUM, 0.0, NULL },
    { DATA_NUM, 3.0, NULL },
    { DATA_NUM, 3.0, NULL },
    { DATA_NUM, 6.0, NULL },
    { DATA_NUM, 1.0, NULL },
    { DATA_NUM, 4.0, NULL },
    { DATA_NUM, 6.0, NULL },
    { DATA_NUM, 2.0, NULL },
    { DATA_NUM, 5.0, NULL },
    { DATA_NUM, 0.0, NULL },
    { DATA_NUM, 3.0, NULL },
    { DATA_NUM, 5.0, NULL },
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
static double A, A8, B, D, D1, DEF, E, F, I, I1, I2, I5, I6, I7, K1, K5, K6, K7, LET, M, M1, T, T1, Y, Y1, Y2, Y3;
static double T_arr[2000] = {0};
static char _input_buf[256];

/* User-defined functions forward declarations */
static double FNA(double A);
static double FNB(double A);

/* User-defined functions definitions */
static double FNA(double A) {
    return floor(A/4);
}

static double FNB(double A) {
    return floor(A/7);
}

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(32);"WEEKDAY" */
line_10:;
    { int _t; for(_t=0; _t<32; _t++) printf(" "); } printf("%s", "WEEKDAY"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 100 PRINT "WEEKDAY IS A COMPUTER DEMONSTRATION THAT" */
line_100:;
    printf("%s", "WEEKDAY IS A COMPUTER DEMONSTRATION THAT"); printf("\n");
    /* BASIC: 110 PRINT"GIVES FACTS ABOUT A DATE OF INTEREST TO YOU." */
line_110:;
    printf("%s", "GIVES FACTS ABOUT A DATE OF INTEREST TO YOU."); printf("\n");
    /* BASIC: 120 PRINT */
line_120:;
    printf("\n");
    /* BASIC: 130 PRINT "ENTER TODAY'S DATE IN THE FORM: 3,24,1979  "; */
line_130:;
    printf("%s", "ENTER TODAY'S DATE IN THE FORM: 3,24,1979  ");
    /* BASIC: 140 INPUT M1,D1,Y1 */
line_140:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf %lf", &M1, &D1, &Y1);
    /* BASIC: 150 REM THIS PROGRAM DETERMINES THE DAY OF THE WEEK */
line_150:;
    /* REM THIS PROGRAM DETERMINES THE DAY OF THE WEEK */
    /* BASIC: 160 REM  FOR A DATE AFTER 1582 */
line_160:;
    /* REM  FOR A DATE AFTER 1582 */
    /* BASIC: 170 DEF FNA(A)=INT(A/4) */
line_170:;
    /* UNTRANSLATED: DEF FNA(A)=INT(A/4) */
    /* BASIC: 180 DIM T(12) */
line_180:;
    /* DIM T(12) (handled statically) */
    /* BASIC: 190 DEF FNB(A)=INT(A/7) */
line_190:;
    /* UNTRANSLATED: DEF FNB(A)=INT(A/7) */
    /* BASIC: 200 REM SPACE OUTPUT AND READ IN INITIAL VALUES FOR MONTHS. */
line_200:;
    /* REM SPACE OUTPUT AND READ IN INITIAL VALUES FOR MONTHS. */
    /* BASIC: 210 FOR I= 1 TO 12 */
line_210:;
    I = 1; for_loop_I_210: if (((1) >= 0 && I > (12)) || ((1) < 0 && I < (12))) goto end_for_I_210;
    /* BASIC: 220 READ T(I) */
line_220:;
    read_numeric(&(T_arr[(int)(I)]));
    /* BASIC: 230 NEXT I */
line_230:;
    I += (1); goto for_loop_I_210; end_for_I_210:;
    /* BASIC: 240 PRINT"ENTER DAY OF BIRTH (OR OTHER DAY OF INTEREST)"; */
line_240:;
    printf("%s", "ENTER DAY OF BIRTH (OR OTHER DAY OF INTEREST)");
    /* BASIC: 250 INPUT M,D,Y */
line_250:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf %lf", &M, &D, &Y);
    /* BASIC: 260 PRINT */
line_260:;
    printf("\n");
    /* BASIC: 270 LET I1 = INT((Y-1500)/100) */
line_270:;
    /* UNTRANSLATED: LET I1 = INT((Y-1500)/100) */
    /* BASIC: 280 REM TEST FOR DATE BEF OR E CURRENT CALENDAR. */
line_280:;
    /* REM TEST FOR DATE BEF OR E CURRENT CALENDAR. */
    /* BASIC: 290 IF Y-1582 <0 THEN 1300 */
line_290:;
    if (Y-1582 <0) { goto line_1300; }
    /* BASIC: 300 LET A = I1*5+(I1+3)/4 */
line_300:;
    /* UNTRANSLATED: LET A = I1*5+(I1+3)/4 */
    /* BASIC: 310 LET I2=INT(A-FNB(A)*7) */
line_310:;
    /* UNTRANSLATED: LET I2=INT(A-FNB(A)*7) */
    /* BASIC: 320 LET Y2=INT(Y/100) */
line_320:;
    /* UNTRANSLATED: LET Y2=INT(Y/100) */
    /* BASIC: 330 LET Y3 =INT(Y-Y2*100) */
line_330:;
    /* UNTRANSLATED: LET Y3 =INT(Y-Y2*100) */
    /* BASIC: 340 LET A =Y3/4+Y3+D+T(M)+I2 */
line_340:;
    /* UNTRANSLATED: LET A =Y3/4+Y3+D+T(M)+I2 */
    /* BASIC: 350 LET B=INT(A-FNB(A)*7)+1 */
line_350:;
    /* UNTRANSLATED: LET B=INT(A-FNB(A)*7)+1 */
    /* BASIC: 360 IF M > 2 THEN 470 */
line_360:;
    if (M > 2) { goto line_470; }
    /* BASIC: 370 IF Y3 = 0 THEN 440 */
line_370:;
    if (Y3 == 0) { goto line_440; }
    /* BASIC: 380 LET T1=INT(Y-FNA(Y)*4) */
line_380:;
    /* UNTRANSLATED: LET T1=INT(Y-FNA(Y)*4) */
    /* BASIC: 390 IF T1 <> 0 THEN 470 */
line_390:;
    if (T1 != 0) { goto line_470; }
    /* BASIC: 400 IF B<>0 THEN 420 */
line_400:;
    if (B!=0) { goto line_420; }
    /* BASIC: 410 LET B=6 */
line_410:;
    /* UNTRANSLATED: LET B=6 */
    /* BASIC: 420 LET B = B-1 */
line_420:;
    /* UNTRANSLATED: LET B = B-1 */
    /* BASIC: 430 GOTO 470 */
line_430:;
    goto line_470;
    /* BASIC: 440 LET A = I1-1 */
line_440:;
    /* UNTRANSLATED: LET A = I1-1 */
    /* BASIC: 450 LET T1=INT(A-FNA(A)*4) */
line_450:;
    /* UNTRANSLATED: LET T1=INT(A-FNA(A)*4) */
    /* BASIC: 460 IF T1 = 0 THEN 400 */
line_460:;
    if (T1 == 0) { goto line_400; }
    /* BASIC: 470 IF B <>0 THEN 490 */
line_470:;
    if (B !=0) { goto line_490; }
    /* BASIC: 480 LET B = 7 */
line_480:;
    /* UNTRANSLATED: LET B = 7 */
    /* BASIC: 490 IF (Y1*12+M1)*31+D1<(Y*12+M)*31+D THEN 550 */
line_490:;
    if ((Y1*12+M1)*31+D1<(Y*12+M)*31+D) { goto line_550; }
    /* BASIC: 500 IF (Y1*12+M1)*31+D1=(Y*12+M)*31+D THEN 530 */
line_500:;
    if ((Y1*12+M1)*31+D1==(Y*12+M)*31+D) { goto line_530; }
    /* BASIC: 510 PRINT M;"/";D;"/";Y;" WAS A "; */
line_510:;
    printf("%g ", (double)(M)); printf("%s", "/"); printf("%g ", (double)(D)); printf("%s", "/"); printf("%g ", (double)(Y)); printf("%s", " WAS A ");
    /* BASIC: 520 GOTO 570 */
line_520:;
    goto line_570;
    /* BASIC: 530 PRINT M;"/";D;"/";Y;" IS A "; */
line_530:;
    printf("%g ", (double)(M)); printf("%s", "/"); printf("%g ", (double)(D)); printf("%s", "/"); printf("%g ", (double)(Y)); printf("%s", " IS A ");
    /* BASIC: 540 GOTO 570 */
line_540:;
    goto line_570;
    /* BASIC: 550 PRINT M;"/";D;"/";Y;" WILL BE A "; */
line_550:;
    printf("%g ", (double)(M)); printf("%s", "/"); printf("%g ", (double)(D)); printf("%s", "/"); printf("%g ", (double)(Y)); printf("%s", " WILL BE A ");
    /* BASIC: 560 REM PRINT THE DAY OF THE WEEK THE DATE FALLS ON. */
line_560:;
    /* REM PRINT THE DAY OF THE WEEK THE DATE FALLS ON. */
    /* BASIC: 570 IF B <>1 THEN 590 */
line_570:;
    if (B !=1) { goto line_590; }
    /* BASIC: 580 PRINT "SUNDAY." */
line_580:;
    printf("%s", "SUNDAY."); printf("\n");
    /* BASIC: 590 IF B<>2 THEN 610 */
line_590:;
    if (B!=2) { goto line_610; }
    /* BASIC: 600 PRINT "MONDAY." */
line_600:;
    printf("%s", "MONDAY."); printf("\n");
    /* BASIC: 610 IF B<>3 THEN 630 */
line_610:;
    if (B!=3) { goto line_630; }
    /* BASIC: 620 PRINT "TUESDAY." */
line_620:;
    printf("%s", "TUESDAY."); printf("\n");
    /* BASIC: 630 IF B<>4 THEN 650 */
line_630:;
    if (B!=4) { goto line_650; }
    /* BASIC: 640 PRINT "WEDNESDAY." */
line_640:;
    printf("%s", "WEDNESDAY."); printf("\n");
    /* BASIC: 650 IF B<>5 THEN 670 */
line_650:;
    if (B!=5) { goto line_670; }
    /* BASIC: 660 PRINT "THURSDAY." */
line_660:;
    printf("%s", "THURSDAY."); printf("\n");
    /* BASIC: 670 IF B<>6 THEN 690 */
line_670:;
    if (B!=6) { goto line_690; }
    /* BASIC: 680 GOTO 1250 */
line_680:;
    goto line_1250;
    /* BASIC: 690 IF B<>7 THEN 710 */
line_690:;
    if (B!=7) { goto line_710; }
    /* BASIC: 700 PRINT "SATURDAY." */
line_700:;
    printf("%s", "SATURDAY."); printf("\n");
    /* BASIC: 710 IF (Y1*12+M1)*31+D1=(Y*12+M)*31+D THEN 1120 */
line_710:;
    if ((Y1*12+M1)*31+D1==(Y*12+M)*31+D) { goto line_1120; }
    /* BASIC: 720 LET I5=Y1-Y */
line_720:;
    /* UNTRANSLATED: LET I5=Y1-Y */
    /* BASIC: 730 PRINT */
line_730:;
    printf("\n");
    /* BASIC: 740 LET I6=M1-M */
line_740:;
    /* UNTRANSLATED: LET I6=M1-M */
    /* BASIC: 750 LET I7=D1-D */
line_750:;
    /* UNTRANSLATED: LET I7=D1-D */
    /* BASIC: 760 IF I7>=0 THEN 790 */
line_760:;
    if (I7>=0) { goto line_790; }
    /* BASIC: 770 LET I6= I6-1 */
line_770:;
    /* UNTRANSLATED: LET I6= I6-1 */
    /* BASIC: 780 LET I7=I7+30 */
line_780:;
    /* UNTRANSLATED: LET I7=I7+30 */
    /* BASIC: 790 IF I6>=0 THEN 820 */
line_790:;
    if (I6>=0) { goto line_820; }
    /* BASIC: 800 LET I5=I5-1 */
line_800:;
    /* UNTRANSLATED: LET I5=I5-1 */
    /* BASIC: 810 LET I6=I6+12 */
line_810:;
    /* UNTRANSLATED: LET I6=I6+12 */
    /* BASIC: 820 IF I5<0 THEN 1310 */
line_820:;
    if (I5<0) { goto line_1310; }
    /* BASIC: 830 IF I7 <> 0 THEN 850 */
line_830:;
    if (I7 != 0) { goto line_850; }
    /* BASIC: 835 IF I6 <> 0 THEN 850 */
line_835:;
    if (I6 != 0) { goto line_850; }
    /* BASIC: 840 PRINT"***HAPPY BIRTHDAY***" */
line_840:;
    printf("%s", "***HAPPY BIRTHDAY***"); printf("\n");
    /* BASIC: 850 PRINT " "," ","YEARS","MONTHS","DAYS" */
line_850:;
    printf("%s", " "); printf("\t"); printf("%s", " "); printf("\t"); printf("%s", "YEARS"); printf("\t"); printf("%s", "MONTHS"); printf("\t"); printf("%s", "DAYS"); printf("\n");
    /* BASIC: 855 PRINT " "," ","-----","------","----" */
line_855:;
    printf("%s", " "); printf("\t"); printf("%s", " "); printf("\t"); printf("%s", "-----"); printf("\t"); printf("%s", "------"); printf("\t"); printf("%s", "----"); printf("\n");
    /* BASIC: 860 PRINT "YOUR AGE (IF BIRTHDATE) ",I5,I6,I7 */
line_860:;
    printf("%s", "YOUR AGE (IF BIRTHDATE) "); printf("\t"); printf("%g ", (double)(I5)); printf("\t"); printf("%g ", (double)(I6)); printf("\t"); printf("%g ", (double)(I7)); printf("\n");
    /* BASIC: 870 LET A8 = (I5*365)+(I6*30)+I7+INT(I6/2) */
line_870:;
    /* UNTRANSLATED: LET A8 = (I5*365)+(I6*30)+I7+INT(I6/2) */
    /* BASIC: 880 LET K5 = I5 */
line_880:;
    /* UNTRANSLATED: LET K5 = I5 */
    /* BASIC: 890 LET K6 = I6 */
line_890:;
    /* UNTRANSLATED: LET K6 = I6 */
    /* BASIC: 900 LET K7 = I7 */
line_900:;
    /* UNTRANSLATED: LET K7 = I7 */
    /* BASIC: 910 REM CALCULATE RETIREMENT DATE. */
line_910:;
    /* REM CALCULATE RETIREMENT DATE. */
    /* BASIC: 920 LET E = Y+65 */
line_920:;
    /* UNTRANSLATED: LET E = Y+65 */
    /* BASIC: 930 REM CALCULATE TIME SPENT IN THE FOLLOWING FUNCTIONS. */
line_930:;
    /* REM CALCULATE TIME SPENT IN THE FOLLOWING FUNCTIONS. */
    /* BASIC: 940 LET F = .35 */
line_940:;
    /* UNTRANSLATED: LET F = .35 */
    /* BASIC: 950 PRINT "YOU HAVE SLEPT ", */
line_950:;
    printf("%s", "YOU HAVE SLEPT "); printf("\t");
    /* BASIC: 960 GOSUB 1370 */
line_960:;
    gosub_stack[gosub_sp++] = 1; goto line_1370; line_ret_1:;
    /* BASIC: 970 LET F = .17 */
line_970:;
    /* UNTRANSLATED: LET F = .17 */
    /* BASIC: 980 PRINT "YOU HAVE EATEN ", */
line_980:;
    printf("%s", "YOU HAVE EATEN "); printf("\t");
    /* BASIC: 990 GOSUB 1370 */
line_990:;
    gosub_stack[gosub_sp++] = 2; goto line_1370; line_ret_2:;
    /* BASIC: 1000 LET F = .23 */
line_1000:;
    /* UNTRANSLATED: LET F = .23 */
    /* BASIC: 1010 IF K5 > 3 THEN 1040 */
line_1010:;
    if (K5 > 3) { goto line_1040; }
    /* BASIC: 1020 PRINT "YOU HAVE PLAYED", */
line_1020:;
    printf("%s", "YOU HAVE PLAYED"); printf("\t");
    /* BASIC: 1030 GOTO 1080 */
line_1030:;
    goto line_1080;
    /* BASIC: 1040 IF K5 > 9 THEN 1070 */
line_1040:;
    if (K5 > 9) { goto line_1070; }
    /* BASIC: 1050 PRINT "YOU HAVE PLAYED/STUDIED", */
line_1050:;
    printf("%s", "YOU HAVE PLAYED/STUDIED"); printf("\t");
    /* BASIC: 1060 GOTO  1080 */
line_1060:;
    goto line_1080;
    /* BASIC: 1070 PRINT "YOU HAVE WORKED/PLAYED", */
line_1070:;
    printf("%s", "YOU HAVE WORKED/PLAYED"); printf("\t");
    /* BASIC: 1080 GOSUB 1370 */
line_1080:;
    gosub_stack[gosub_sp++] = 3; goto line_1370; line_ret_3:;
    /* BASIC: 1085 GOTO 1530 */
line_1085:;
    goto line_1530;
    /* BASIC: 1090 PRINT "YOU HAVE RELAXED ",K5,K6,K7 */
line_1090:;
    printf("%s", "YOU HAVE RELAXED "); printf("\t"); printf("%g ", (double)(K5)); printf("\t"); printf("%g ", (double)(K6)); printf("\t"); printf("%g ", (double)(K7)); printf("\n");
    /* BASIC: 1100 PRINT */
line_1100:;
    printf("\n");
    /* BASIC: 1110 PRINT TAB(16);"***  YOU MAY RETIRE IN";E;" ***" */
line_1110:;
    { int _t; for(_t=0; _t<16; _t++) printf(" "); } printf("%s", "***  YOU MAY RETIRE IN"); printf("%g ", (double)(E)); printf("%s", " ***"); printf("\n");
    /* BASIC: 1120 PRINT */
line_1120:;
    printf("\n");
    /* BASIC: 1140 PRINT */
line_1140:;
    printf("\n");
    /* BASIC: 1200 PRINT */
line_1200:;
    printf("\n");
    /* BASIC: 1210 PRINT */
line_1210:;
    printf("\n");
    /* BASIC: 1220 PRINT */
line_1220:;
    printf("\n");
    /* BASIC: 1230 PRINT */
line_1230:;
    printf("\n");
    /* BASIC: 1240 END */
line_1240:;
    exit(0);
    /* BASIC: 1250 IF D=13 THEN 1280 */
line_1250:;
    if (D==13) { goto line_1280; }
    /* BASIC: 1260 PRINT "FRIDAY." */
line_1260:;
    printf("%s", "FRIDAY."); printf("\n");
    /* BASIC: 1270 GOTO 710 */
line_1270:;
    goto line_710;
    /* BASIC: 1280 PRINT "FRIDAY THE THIRTEENTH---BEWARE!" */
line_1280:;
    printf("%s", "FRIDAY THE THIRTEENTH---BEWARE!"); printf("\n");
    /* BASIC: 1290 GOTO 710 */
line_1290:;
    goto line_710;
    /* BASIC: 1300 PRINT "NOT PREPARED TO GIVE DAY OF WEEK PRIOR TO MDLXXXII. " */
line_1300:;
    printf("%s", "NOT PREPARED TO GIVE DAY OF WEEK PRIOR TO MDLXXXII. "); printf("\n");
    /* BASIC: 1310 GOTO 1140 */
line_1310:;
    goto line_1140;
    /* BASIC: 1320 REM TABLE OF VALUES FOR THE MONTHS TO BE USED IN CALCULATIONS. */
line_1320:;
    /* REM TABLE OF VALUES FOR THE MONTHS TO BE USED IN CALCULATIONS. */
    /* BASIC: 1330 DATA 0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5 */
line_1330:;
    /* UNTRANSLATED: DATA 0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5 */
    /* BASIC: 1340 REM THIS IS THE CURRENT DATE USED IN THE CALCULATIONS. */
line_1340:;
    /* REM THIS IS THE CURRENT DATE USED IN THE CALCULATIONS. */
    /* BASIC: 1350 REM THIS IS THE DATE TO BE CALCULATED ON. */
line_1350:;
    /* REM THIS IS THE DATE TO BE CALCULATED ON. */
    /* BASIC: 1360 REM CALCULATE TIME IN YEARS, MONTHS, AND DAYS */
line_1360:;
    /* REM CALCULATE TIME IN YEARS, MONTHS, AND DAYS */
    /* BASIC: 1370 LET K1=INT(F*A8) */
line_1370:;
    /* UNTRANSLATED: LET K1=INT(F*A8) */
    /* BASIC: 1380 LET I5 = INT(K1/365) */
line_1380:;
    /* UNTRANSLATED: LET I5 = INT(K1/365) */
    /* BASIC: 1390 LET K1 = K1- (I5*365) */
line_1390:;
    /* UNTRANSLATED: LET K1 = K1- (I5*365) */
    /* BASIC: 1400 LET I6 = INT(K1/30) */
line_1400:;
    /* UNTRANSLATED: LET I6 = INT(K1/30) */
    /* BASIC: 1410 LET I7 = K1 -(I6*30) */
line_1410:;
    /* UNTRANSLATED: LET I7 = K1 -(I6*30) */
    /* BASIC: 1420 LET K5 = K5-I5 */
line_1420:;
    /* UNTRANSLATED: LET K5 = K5-I5 */
    /* BASIC: 1430 LET K6 =K6-I6 */
line_1430:;
    /* UNTRANSLATED: LET K6 =K6-I6 */
    /* BASIC: 1440 LET K7 = K7-I7 */
line_1440:;
    /* UNTRANSLATED: LET K7 = K7-I7 */
    /* BASIC: 1450 IF K7>=0 THEN 1480 */
line_1450:;
    if (K7>=0) { goto line_1480; }
    /* BASIC: 1460 LET K7=K7+30 */
line_1460:;
    /* UNTRANSLATED: LET K7=K7+30 */
    /* BASIC: 1470 LET K6=K6-1 */
line_1470:;
    /* UNTRANSLATED: LET K6=K6-1 */
    /* BASIC: 1480 IF K6>0 THEN 1510 */
line_1480:;
    if (K6>0) { goto line_1510; }
    /* BASIC: 1490 LET K6=K6+12 */
line_1490:;
    /* UNTRANSLATED: LET K6=K6+12 */
    /* BASIC: 1500 LET K5=K5-1 */
line_1500:;
    /* UNTRANSLATED: LET K5=K5-1 */
    /* BASIC: 1510 PRINT I5,I6,I7 */
line_1510:;
    printf("%g ", (double)(I5)); printf("\t"); printf("%g ", (double)(I6)); printf("\t"); printf("%g ", (double)(I7)); printf("\n");
    /* BASIC: 1520 RETURN */
line_1520:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1530 IF K6=12 THEN 1550 */
line_1530:;
    if (K6==12) { goto line_1550; }
    /* BASIC: 1540 GOTO 1090 */
line_1540:;
    goto line_1090;
    /* BASIC: 1550 LET K5=K5+1 */
line_1550:;
    /* UNTRANSLATED: LET K5=K5+1 */
    /* BASIC: 1560 LET K6=0 */
line_1560:;
    /* UNTRANSLATED: LET K6=0 */
    /* BASIC: 1570 GOTO 1090 */
line_1570:;
    goto line_1090;
    /* BASIC: 1580 REM */
line_1580:;
    /* REM */
    /* BASIC: 1590 END */
line_1590:;
    exit(0);

    return 0;
}
