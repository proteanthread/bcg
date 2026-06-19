/*
 * Transpiled from pizza.bas
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
    { DATA_STR, { .str = "A" } },
    { DATA_STR, { .str = "B" } },
    { DATA_STR, { .str = "C" } },
    { DATA_STR, { .str = "D" } },
    { DATA_STR, { .str = "E" } },
    { DATA_STR, { .str = "F" } },
    { DATA_STR, { .str = "G" } },
    { DATA_STR, { .str = "H" } },
    { DATA_STR, { .str = "I" } },
    { DATA_STR, { .str = "J" } },
    { DATA_STR, { .str = "K" } },
    { DATA_STR, { .str = "L" } },
    { DATA_STR, { .str = "M" } },
    { DATA_STR, { .str = "N" } },
    { DATA_STR, { .str = "O" } },
    { DATA_STR, { .str = "P" } },
    { DATA_STR, { .str = "1" } },
    { DATA_STR, { .str = "2" } },
    { DATA_STR, { .str = "3" } },
    { DATA_STR, { .str = "4" } },
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
static double A, I, K, S, S1, T;
static char A_str[256] = {0};
static char M_str[256] = {0};
static char N_str[256] = {0};
static char S_str[256] = {0};
static double A_arr[20000] = {0};
static char M_str_arr[20000][256] = {0};
static char S_str_arr[20000][256] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 5 PRINT TAB(33);"PIZZA" */
line_5:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "PIZZA"); printf("\n");
    /* BASIC: 10 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_10:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 15 PRINT: PRINT: PRINT */
line_15:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 20 DIM S$(16),M$(4) */
line_20:;
    /* DIM S$(16),M$(4) (handled statically) */
    /* BASIC: 30 PRINT "PIZZA DELIVERY GAME": PRINT */
line_30:;
    printf("%s", "PIZZA DELIVERY GAME"); printf("\n");
    printf("\n");
    /* BASIC: 50 INPUT "WHAT IS YOUR FIRST NAME";N$: PRINT */
line_50:;
    printf("%s", "WHAT IS YOUR FIRST NAME"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", N_str);
    printf("\n");
    /* BASIC: 80 PRINT "HI, ";N$;".  IN THIS GAME YOU ARE TO TAKE ORDERS" */
line_80:;
    printf("%s", "HI, "); printf("%s", N_str); printf("%s", ".  IN THIS GAME YOU ARE TO TAKE ORDERS"); printf("\n");
    /* BASIC: 90 PRINT "FOR PIZZAS.  THEN YOU ARE TO TELL A DELIVERY BOY" */
line_90:;
    printf("%s", "FOR PIZZAS.  THEN YOU ARE TO TELL A DELIVERY BOY"); printf("\n");
    /* BASIC: 100 PRINT "WHERE TO DELIVER THE ORDERED PIZZAS.": PRINT: PRINT */
line_100:;
    printf("%s", "WHERE TO DELIVER THE ORDERED PIZZAS."); printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 140 FOR I=1 TO 16 */
line_140:;
    I = 1; for_loop_I_140: if (((1) >= 0 && I > (16)) || ((1) < 0 && I < (16))) goto end_for_I_140;
    /* BASIC: 150 READ S$(I) */
line_150:;
    read_string(S_str_arr[(int)(I)], sizeof(S_str_arr[(int)(I)]));
    /* BASIC: 160 NEXT I */
line_160:;
    I += (1); goto for_loop_I_140; end_for_I_140:;
    /* BASIC: 170 FOR I=1 TO 4 */
line_170:;
    I = 1; for_loop_I_170: if (((1) >= 0 && I > (4)) || ((1) < 0 && I < (4))) goto end_for_I_170;
    /* BASIC: 180 READ M$(I) */
line_180:;
    read_string(M_str_arr[(int)(I)], sizeof(M_str_arr[(int)(I)]));
    /* BASIC: 190 NEXT I */
line_190:;
    I += (1); goto for_loop_I_170; end_for_I_170:;
    /* BASIC: 200 DATA "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O" */
line_200:;
    /* UNTRANSLATED: DATA "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O" */
    /* BASIC: 210 DATA "P","1","2","3","4" */
line_210:;
    /* UNTRANSLATED: DATA "P","1","2","3","4" */
    /* BASIC: 230 PRINT "MAP OF THE CITY OF HYATTSVILLE": PRINT */
line_230:;
    printf("%s", "MAP OF THE CITY OF HYATTSVILLE"); printf("\n");
    printf("\n");
    /* BASIC: 250 PRINT " -----1-----2-----3-----4-----" */
line_250:;
    printf("%s", " -----1-----2-----3-----4-----"); printf("\n");
    /* BASIC: 260 K=4 */
line_260:;
    K = 4;
    /* BASIC: 270 FOR I=1 TO 4 */
line_270:;
    I = 1; for_loop_I_270: if (((1) >= 0 && I > (4)) || ((1) < 0 && I < (4))) goto end_for_I_270;
    /* BASIC: 280 PRINT "-": PRINT "-": PRINT"-": PRINT "-" */
line_280:;
    printf("%s", "-"); printf("\n");
    printf("%s", "-"); printf("\n");
    printf("%s", "-"); printf("\n");
    printf("%s", "-"); printf("\n");
    /* BASIC: 320 PRINT M$(K); */
line_320:;
    printf("%s", M_str_arr[(int)(K)]);
    /* BASIC: 330 S1=16-4*I+1 */
line_330:;
    S1 = 16-4*I+1;
    /* BASIC: 340 PRINT "     ";S$(S1);"     ";S$(S1+1);"     ";S$(S1+2);"     "; */
line_340:;
    printf("%s", "     "); printf("%s", S_str_arr[(int)(S1)]); printf("%s", "     "); printf("%s", S_str_arr[(int)(S1+1)]); printf("%s", "     "); printf("%s", S_str_arr[(int)(S1+2)]); printf("%s", "     ");
    /* BASIC: 350 PRINT S$(S1+3);"     ";M$(K) */
line_350:;
    printf("%s", S_str_arr[(int)(S1+3)]); printf("%s", "     "); printf("%s", M_str_arr[(int)(K)]); printf("\n");
    /* BASIC: 380 K=K-1 */
line_380:;
    K = K-1;
    /* BASIC: 390 NEXT I */
line_390:;
    I += (1); goto for_loop_I_270; end_for_I_270:;
    /* BASIC: 400 PRINT "-": PRINT "-": PRINT "-": PRINT "-" */
line_400:;
    printf("%s", "-"); printf("\n");
    printf("%s", "-"); printf("\n");
    printf("%s", "-"); printf("\n");
    printf("%s", "-"); printf("\n");
    /* BASIC: 440 PRINT " -----1-----2-----3-----4-----": PRINT */
line_440:;
    printf("%s", " -----1-----2-----3-----4-----"); printf("\n");
    printf("\n");
    /* BASIC: 460 PRINT "THE OUTPUT IS A MAP OF THE HOMES WHERE" */
line_460:;
    printf("%s", "THE OUTPUT IS A MAP OF THE HOMES WHERE"); printf("\n");
    /* BASIC: 470 PRINT "YOU ARE TO SEND PIZZAS.": PRINT */
line_470:;
    printf("%s", "YOU ARE TO SEND PIZZAS."); printf("\n");
    printf("\n");
    /* BASIC: 490 PRINT "YOUR JOB IS TO GIVE A TRUCK DRIVER" */
line_490:;
    printf("%s", "YOUR JOB IS TO GIVE A TRUCK DRIVER"); printf("\n");
    /* BASIC: 500 PRINT "THE LOCATION OR COORDINATES OF THE" */
line_500:;
    printf("%s", "THE LOCATION OR COORDINATES OF THE"); printf("\n");
    /* BASIC: 510 PRINT "HOME ORDERING THE PIZZA.": PRINT */
line_510:;
    printf("%s", "HOME ORDERING THE PIZZA."); printf("\n");
    printf("\n");
    /* BASIC: 520 INPUT "DO YOU NEED MORE DIRECTIONS";A$ */
line_520:;
    printf("%s", "DO YOU NEED MORE DIRECTIONS"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    /* BASIC: 530 IF A$="YES" THEN 590 */
line_530:;
    if (strcmp(A_str, "YES") == 0) { goto line_590; }
    /* BASIC: 540 IF A$="NO" THEN 750 */
line_540:;
    if (strcmp(A_str, "NO") == 0) { goto line_750; }
    /* BASIC: 550 PRINT "'YES' OR 'NO' PLEASE, NOW THEN,": GOTO 520 */
line_550:;
    printf("%s", "'YES' OR 'NO' PLEASE, NOW THEN,"); printf("\n");
    goto line_520;
    /* BASIC: 590 PRINT: PRINT "SOMEBODY WILL ASK FOR A PIZZA TO BE" */
line_590:;
    printf("\n");
    printf("%s", "SOMEBODY WILL ASK FOR A PIZZA TO BE"); printf("\n");
    /* BASIC: 600 PRINT "DELIVERED.  THEN A DELIVERY BOY WILL" */
line_600:;
    printf("%s", "DELIVERED.  THEN A DELIVERY BOY WILL"); printf("\n");
    /* BASIC: 610 PRINT "ASK YOU FOR THE LOCATION.":PRINT "     EXAMPLE:" */
line_610:;
    printf("%s", "ASK YOU FOR THE LOCATION."); printf("\n");
    printf("%s", "     EXAMPLE:"); printf("\n");
    /* BASIC: 620 PRINT "THIS IS J.  PLEASE SEND A PIZZA." */
line_620:;
    printf("%s", "THIS IS J.  PLEASE SEND A PIZZA."); printf("\n");
    /* BASIC: 640 PRINT "DRIVER TO ";N$;".  WHERE DOES J LIVE?" */
line_640:;
    printf("%s", "DRIVER TO "); printf("%s", N_str); printf("%s", ".  WHERE DOES J LIVE?"); printf("\n");
    /* BASIC: 650 PRINT "YOUR ANSWER WOULD BE 2,3": PRINT */
line_650:;
    printf("%s", "YOUR ANSWER WOULD BE 2,3"); printf("\n");
    printf("\n");
    /* BASIC: 660 INPUT "UNDERSTAND";A$ */
line_660:;
    printf("%s", "UNDERSTAND"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    /* BASIC: 670 IF A$="YES" THEN 690 */
line_670:;
    if (strcmp(A_str, "YES") == 0) { goto line_690; }
    /* BASIC: 680 PRINT "THIS JOB IS DEFINITELY TOO DIFFICULT FOR YOU. THANKS ANYWAY" */
line_680:;
    printf("%s", "THIS JOB IS DEFINITELY TOO DIFFICULT FOR YOU. THANKS ANYWAY"); printf("\n");
    /* BASIC: 685 GOTO 999 */
line_685:;
    goto line_999;
    /* BASIC: 690 PRINT "GOOD.  YOU ARE NOW READY TO START TAKING ORDERS.": PRINT */
line_690:;
    printf("%s", "GOOD.  YOU ARE NOW READY TO START TAKING ORDERS."); printf("\n");
    printf("\n");
    /* BASIC: 700 PRINT "GOOD LUCK!!": PRINT */
line_700:;
    printf("%s", "GOOD LUCK!!"); printf("\n");
    printf("\n");
    /* BASIC: 750 FOR I=1 TO 5 */
line_750:;
    I = 1; for_loop_I_750: if (((1) >= 0 && I > (5)) || ((1) < 0 && I < (5))) goto end_for_I_750;
    /* BASIC: 760 S=INT(RND(1)*16+1): PRINT */
line_760:;
    S = floor(((double)rand() / (double)RAND_MAX)*16+1);
    printf("\n");
    /* BASIC: 770 PRINT "HELLO ";N$;"'S PIZZA.  THIS IS ";S$(S);"."; */
line_770:;
    printf("%s", "HELLO "); printf("%s", N_str); printf("%s", "'S PIZZA.  THIS IS "); printf("%s", S_str_arr[(int)(S)]); printf("%s", ".");
    /* BASIC: 775 PRINT "  PLEASE SEND A PIZZA." */
line_775:;
    printf("%s", "  PLEASE SEND A PIZZA."); printf("\n");
    /* BASIC: 780 PRINT "  DRIVER TO ";N$;":  WHERE DOES ";S$(S);" LIVE"; */
line_780:;
    printf("%s", "  DRIVER TO "); printf("%s", N_str); printf("%s", ":  WHERE DOES "); printf("%s", S_str_arr[(int)(S)]); printf("%s", " LIVE");
    /* BASIC: 790 INPUT A(1),A(2) */
line_790:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf", &(A_arr[(int)(1)]), &(A_arr[(int)(2)]));
    /* BASIC: 870 T=A(1)+(A(2)-1)*4 */
line_870:;
    T = A_arr[(int)(1)]+(A_arr[(int)(2)]-1)*4;
    /* BASIC: 880 IF T=S THEN 920 */
line_880:;
    if (T==S) { goto line_920; }
    /* BASIC: 890 PRINT "THIS IS ";S$(T);".  I DID NOT ORDER A PIZZA." */
line_890:;
    printf("%s", "THIS IS "); printf("%s", S_str_arr[(int)(T)]); printf("%s", ".  I DID NOT ORDER A PIZZA."); printf("\n");
    /* BASIC: 900 PRINT "I LIVE AT ";A(1);",";A(2) */
line_900:;
    printf("%s", "I LIVE AT "); printf("%g ", (double)(A_arr[(int)(1)])); printf("%s", ","); printf("%g ", (double)(A_arr[(int)(2)])); printf("\n");
    /* BASIC: 910 GOTO 780 */
line_910:;
    goto line_780;
    /* BASIC: 920 PRINT "HELLO "N$;".  THIS IS ";S$(S);", THANKS FOR THE PIZZA." */
line_920:;
    printf("%s", "HELLO "); printf("%s", N_str); printf("%s", ".  THIS IS "); printf("%s", S_str_arr[(int)(S)]); printf("%s", ", THANKS FOR THE PIZZA."); printf("\n");
    /* BASIC: 930 NEXT I */
line_930:;
    I += (1); goto for_loop_I_750; end_for_I_750:;
    /* BASIC: 940 PRINT: INPUT "DO YOU WANT TO DELIVER MORE PIZZAS";A$ */
line_940:;
    printf("\n");
    printf("%s", "DO YOU WANT TO DELIVER MORE PIZZAS"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    /* BASIC: 960 IF A$="YES" THEN 750 */
line_960:;
    if (strcmp(A_str, "YES") == 0) { goto line_750; }
    /* BASIC: 970 PRINT: PRINT "O.K. ";N$;", SEE YOU LATER!":PRINT */
line_970:;
    printf("\n");
    printf("%s", "O.K. "); printf("%s", N_str); printf("%s", ", SEE YOU LATER!"); printf("\n");
    printf("\n");
    /* BASIC: 999 END */
line_999:;
    exit(0);

    return 0;
}
