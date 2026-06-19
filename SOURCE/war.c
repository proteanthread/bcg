/*
 * Transpiled from war.bas
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

static DataItem program_data[52] = {
    { DATA_STR, { .str = "S-2" } },
    { DATA_STR, { .str = "H-2" } },
    { DATA_STR, { .str = "C-2" } },
    { DATA_STR, { .str = "D-2" } },
    { DATA_STR, { .str = "S-3" } },
    { DATA_STR, { .str = "H-3" } },
    { DATA_STR, { .str = "C-3" } },
    { DATA_STR, { .str = "D-3" } },
    { DATA_STR, { .str = "S-4" } },
    { DATA_STR, { .str = "H-4" } },
    { DATA_STR, { .str = "C-4" } },
    { DATA_STR, { .str = "D-4" } },
    { DATA_STR, { .str = "S-5" } },
    { DATA_STR, { .str = "H-5" } },
    { DATA_STR, { .str = "C-5" } },
    { DATA_STR, { .str = "D-5" } },
    { DATA_STR, { .str = "S-6" } },
    { DATA_STR, { .str = "H-6" } },
    { DATA_STR, { .str = "C-6" } },
    { DATA_STR, { .str = "D-6" } },
    { DATA_STR, { .str = "S-7" } },
    { DATA_STR, { .str = "H-7" } },
    { DATA_STR, { .str = "C-7" } },
    { DATA_STR, { .str = "D-7" } },
    { DATA_STR, { .str = "S-8" } },
    { DATA_STR, { .str = "H-8" } },
    { DATA_STR, { .str = "C-8" } },
    { DATA_STR, { .str = "D-8" } },
    { DATA_STR, { .str = "S-9" } },
    { DATA_STR, { .str = "H-9" } },
    { DATA_STR, { .str = "C-9" } },
    { DATA_STR, { .str = "D-9" } },
    { DATA_STR, { .str = "S-10" } },
    { DATA_STR, { .str = "H-10" } },
    { DATA_STR, { .str = "C-10" } },
    { DATA_STR, { .str = "D-10" } },
    { DATA_STR, { .str = "S-J" } },
    { DATA_STR, { .str = "H-J" } },
    { DATA_STR, { .str = "C-J" } },
    { DATA_STR, { .str = "D-J" } },
    { DATA_STR, { .str = "S-Q" } },
    { DATA_STR, { .str = "H-Q" } },
    { DATA_STR, { .str = "C-Q" } },
    { DATA_STR, { .str = "D-Q" } },
    { DATA_STR, { .str = "S-K" } },
    { DATA_STR, { .str = "H-K" } },
    { DATA_STR, { .str = "C-K" } },
    { DATA_STR, { .str = "D-K" } },
    { DATA_STR, { .str = "S-A" } },
    { DATA_STR, { .str = "H-A" } },
    { DATA_STR, { .str = "C-A" } },
    { DATA_STR, { .str = "D-A" } },
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
static double A1, B1, I, J, K, L, LET, M1, M2, N1, N2, P;
static char A_str[256] = {0};
static char B_str[256] = {0};
static char V_str[256] = {0};
static double L_arr[20000] = {0};
static char A_str_arr[20000][256] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(33);"WAR" */
line_10:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "WAR"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT: PRINT: PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 100 PRINT "THIS IS THE CARD GAME OF WAR.  EACH CARD IS GIVEN BY SUIT-#" */
line_100:;
    printf("%s", "THIS IS THE CARD GAME OF WAR.  EACH CARD IS GIVEN BY SUIT-#"); printf("\n");
    /* BASIC: 110 PRINT "AS S-7 FOR SPADE 7.  "; */
line_110:;
    printf("%s", "AS S-7 FOR SPADE 7.  ");
    /* BASIC: 120 PRINT "DO YOU WANT DIRECTIONS"; */
line_120:;
    printf("%s", "DO YOU WANT DIRECTIONS");
    /* BASIC: 130 INPUT B$ */
line_130:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", B_str);
    /* BASIC: 140 IF B$="NO" THEN 210 */
line_140:;
    if (strcmp(B_str, "NO") == 0) { goto line_210; }
    /* BASIC: 150 IF B$="YES" THEN 180 */
line_150:;
    if (strcmp(B_str, "YES") == 0) { goto line_180; }
    /* BASIC: 160 PRINT "YES OR NO, PLEASE.  "; */
line_160:;
    printf("%s", "YES OR NO, PLEASE.  ");
    /* BASIC: 170 GOTO 120 */
line_170:;
    goto line_120;
    /* BASIC: 180 PRINT "THE COMPUTER GIVES YOU AND IT A 'CARD'.  THE HIGHER CARD" */
line_180:;
    printf("%s", "THE COMPUTER GIVES YOU AND IT A 'CARD'.  THE HIGHER CARD"); printf("\n");
    /* BASIC: 190 PRINT "(NUMERICALLY) WINS.  THE GAME ENDS WHEN YOU CHOOSE NOT TO" */
line_190:;
    printf("%s", "(NUMERICALLY) WINS.  THE GAME ENDS WHEN YOU CHOOSE NOT TO"); printf("\n");
    /* BASIC: 200 PRINT "CONTINUE OR WHEN YOU HAVE FINISHED THE PACK." */
line_200:;
    printf("%s", "CONTINUE OR WHEN YOU HAVE FINISHED THE PACK."); printf("\n");
    /* BASIC: 210 PRINT */
line_210:;
    printf("\n");
    /* BASIC: 220 PRINT */
line_220:;
    printf("\n");
    /* BASIC: 230 DIM A$(52),L(54) */
line_230:;
    /* DIM A$(52),L(54) (handled statically) */
    /* BASIC: 240 FOR I=1 TO 52 */
line_240:;
    I = 1; for_loop_I_240: if (((1) >= 0 && I > (52)) || ((1) < 0 && I < (52))) goto end_for_I_240;
    /* BASIC: 250 READ A$(I) */
line_250:;
    read_string(A_str_arr[(int)(I)], sizeof(A_str_arr[(int)(I)]));
    /* BASIC: 260 NEXT I */
line_260:;
    I += (1); goto for_loop_I_240; end_for_I_240:;
    /* BASIC: 270 REM */
line_270:;
    // REM
    /* BASIC: 280 FOR J=1 TO 52 */
line_280:;
    J = 1; for_loop_J_280: if (((1) >= 0 && J > (52)) || ((1) < 0 && J < (52))) goto end_for_J_280;
    /* BASIC: 290 LET L(J)=INT(52*RND(1))+1 */
line_290:;
    /* UNTRANSLATED: LET L(J)=INT(52*RND(1))+1 */
    /* BASIC: 295 IF J=1 THEN 350 */
line_295:;
    if (J==1) { goto line_350; }
    /* BASIC: 300 FOR K=1 TO J-1 */
line_300:;
    K = 1; for_loop_K_300: if (((1) >= 0 && K > (J-1)) || ((1) < 0 && K < (J-1))) goto end_for_K_300;
    /* BASIC: 310 IF L(K)<>L(J) THEN 340 */
line_310:;
    if (L_arr[(int)(K)]!=L_arr[(int)(J)]) { goto line_340; }
    /* BASIC: 320 REM */
line_320:;
    // REM
    /* BASIC: 330 GOTO 290 */
line_330:;
    goto line_290;
    /* BASIC: 340 NEXT K */
line_340:;
    K += (1); goto for_loop_K_300; end_for_K_300:;
    /* BASIC: 350 NEXT J */
line_350:;
    J += (1); goto for_loop_J_280; end_for_J_280:;
    /* BASIC: 360 P=P+1 */
line_360:;
    P = P+1;
    /* BASIC: 370 M1=L(P) */
line_370:;
    M1 = L_arr[(int)(P)];
    /* BASIC: 380 P=P+1 */
line_380:;
    P = P+1;
    /* BASIC: 390 M2=L(P) */
line_390:;
    M2 = L_arr[(int)(P)];
    /* BASIC: 400 PRINT */
line_400:;
    printf("\n");
    /* BASIC: 420 PRINT "YOU: ";A$(M1),"COMPUTER: ";A$(M2) */
line_420:;
    printf("%s", "YOU: "); printf("%s", A_str_arr[(int)(M1)]); printf("\t"); printf("%s", "COMPUTER: "); printf("%s", A_str_arr[(int)(M2)]); printf("\n");
    /* BASIC: 430 N1=INT((M1-.5)/4) */
line_430:;
    N1 = floor((M1-.5)/4);
    /* BASIC: 440 N2=INT((M2-.5)/4) */
line_440:;
    N2 = floor((M2-.5)/4);
    /* BASIC: 450 IF N1>=N2 THEN 490 */
line_450:;
    if (N1>=N2) { goto line_490; }
    /* BASIC: 460 A1=A1+1 */
line_460:;
    A1 = A1+1;
    /* BASIC: 470 PRINT "THE COMPUTER WINS!!! YOU HAVE";B1;"AND THE COMPUTER HAS";A1 */
line_470:;
    printf("%s", "THE COMPUTER WINS!!! YOU HAVE"); printf("%g ", (double)(B1)); printf("%s", "AND THE COMPUTER HAS"); printf("%g ", (double)(A1)); printf("\n");
    /* BASIC: 480 GOTO 540 */
line_480:;
    goto line_540;
    /* BASIC: 490 IF N1=N2 THEN 530 */
line_490:;
    if (N1==N2) { goto line_530; }
    /* BASIC: 500 B1=B1+1 */
line_500:;
    B1 = B1+1;
    /* BASIC: 510 PRINT "YOU WIN. YOU HAVE";B1;"AND THE COMPUTER HAS";A1 */
line_510:;
    printf("%s", "YOU WIN. YOU HAVE"); printf("%g ", (double)(B1)); printf("%s", "AND THE COMPUTER HAS"); printf("%g ", (double)(A1)); printf("\n");
    /* BASIC: 520 GOTO 540 */
line_520:;
    goto line_540;
    /* BASIC: 530 PRINT "TIE.  NO SCORE CHANGE." */
line_530:;
    printf("%s", "TIE.  NO SCORE CHANGE."); printf("\n");
    /* BASIC: 540 IF L(P+1)=0 THEN 610 */
line_540:;
    if (L_arr[(int)(P+1)]==0) { goto line_610; }
    /* BASIC: 550 PRINT "DO YOU WANT TO CONTINUE"; */
line_550:;
    printf("%s", "DO YOU WANT TO CONTINUE");
    /* BASIC: 560 INPUT V$ */
line_560:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", V_str);
    /* BASIC: 570 IF V$="YES" THEN 360 */
line_570:;
    if (strcmp(V_str, "YES") == 0) { goto line_360; }
    /* BASIC: 580 IF V$="NO" THEN 650 */
line_580:;
    if (strcmp(V_str, "NO") == 0) { goto line_650; }
    /* BASIC: 590 PRINT "YES OR NO, PLEASE.  "; */
line_590:;
    printf("%s", "YES OR NO, PLEASE.  ");
    /* BASIC: 600 GOTO 540 */
line_600:;
    goto line_540;
    /* BASIC: 610 PRINT */
line_610:;
    printf("\n");
    /* BASIC: 620 PRINT */
line_620:;
    printf("\n");
    /* BASIC: 630 PRINT "WE HAVE RUN OUT OF CARDS.  FINAL SCORE:  YOU: ";B1; */
line_630:;
    printf("%s", "WE HAVE RUN OUT OF CARDS.  FINAL SCORE:  YOU: "); printf("%g ", (double)(B1));
    /* BASIC: 640 PRINT "  THE COMPUTER: ";A1:PRINT */
line_640:;
    printf("%s", "  THE COMPUTER: "); printf("%g ", (double)(A1)); printf("\n");
    printf("\n");
    /* BASIC: 650 PRINT "THANKS FOR PLAYING.  IT WAS FUN." */
line_650:;
    printf("%s", "THANKS FOR PLAYING.  IT WAS FUN."); printf("\n");
    /* BASIC: 655 PRINT */
line_655:;
    printf("\n");
    /* BASIC: 660 DATA "S-2","H-2","C-2","D-2","S-3","H-3","C-3","D-3" */
line_660:;
    /* UNTRANSLATED: DATA "S-2","H-2","C-2","D-2","S-3","H-3","C-3","D-3" */
    /* BASIC: 670 DATA "S-4","H-4","C-4","D-4","S-5","H-5","C-5","D-5" */
line_670:;
    /* UNTRANSLATED: DATA "S-4","H-4","C-4","D-4","S-5","H-5","C-5","D-5" */
    /* BASIC: 680 DATA "S-6","H-6","C-6","D-6","S-7","H-7","C-7","D-7" */
line_680:;
    /* UNTRANSLATED: DATA "S-6","H-6","C-6","D-6","S-7","H-7","C-7","D-7" */
    /* BASIC: 690 DATA "S-8","H-8","C-8","D-8","S-9","H-9","C-9","D-9" */
line_690:;
    /* UNTRANSLATED: DATA "S-8","H-8","C-8","D-8","S-9","H-9","C-9","D-9" */
    /* BASIC: 700 DATA "S-10","H-10","C-10","D-10","S-J","H-J","C-J","D-J" */
line_700:;
    /* UNTRANSLATED: DATA "S-10","H-10","C-10","D-10","S-J","H-J","C-J","D-J" */
    /* BASIC: 710 DATA "S-Q","H-Q","C-Q","D-Q","S-K","H-K","C-K","D-K" */
line_710:;
    /* UNTRANSLATED: DATA "S-Q","H-Q","C-Q","D-Q","S-K","H-K","C-K","D-K" */
    /* BASIC: 720 DATA "S-A","H-A","C-A","D-A" */
line_720:;
    /* UNTRANSLATED: DATA "S-A","H-A","C-A","D-A" */
    /* BASIC: 999 END */
line_999:;
    exit(0);

    return 0;
}
