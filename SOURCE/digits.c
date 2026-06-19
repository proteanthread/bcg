/*
 * Transpiled from digits.bas
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

static DataItem program_data[3] = {
    { DATA_NUM, { .num = 0.0 } },
    { DATA_NUM, { .num = 1.0 } },
    { DATA_NUM, { .num = 3.0 } },
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
static double A, B, C, E, G, I, J, K, L, M, N, Q, S, S1, T, U, W, X, Z, Z1, Z2;
static double K_arr[20000] = {0};
static double L_arr[20000] = {0};
static double M_arr[20000] = {0};
static double N_arr[20000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(33);"DIGITS" */
line_10:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "DIGITS"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 210 PRINT "THIS IS A GAME OF GUESSING." */
line_210:;
    printf("%s", "THIS IS A GAME OF GUESSING."); printf("\n");
    /* BASIC: 220 PRINT "FOR INSTRUCTIONS, TYPE '1', ELSE TYPE '0'"; */
line_220:;
    printf("%s", "FOR INSTRUCTIONS, TYPE '1', ELSE TYPE '0'");
    /* BASIC: 230 INPUT E */
line_230:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &E);
    /* BASIC: 240 IF E=0 THEN 360 */
line_240:;
    if (E==0) { goto line_360; }
    /* BASIC: 250 PRINT */
line_250:;
    printf("\n");
    /* BASIC: 260 PRINT "PLEASE TAKE A PIECE OF PAPER AND WRITE DOWN" */
line_260:;
    printf("%s", "PLEASE TAKE A PIECE OF PAPER AND WRITE DOWN"); printf("\n");
    /* BASIC: 270 PRINT "THE DIGITS '0', '1', OR '2' THIRTY TIMES AT RANDOM." */
line_270:;
    printf("%s", "THE DIGITS '0', '1', OR '2' THIRTY TIMES AT RANDOM."); printf("\n");
    /* BASIC: 280 PRINT "ARRANGE THEM IN THREE LINES OF TEN DIGITS EACH." */
line_280:;
    printf("%s", "ARRANGE THEM IN THREE LINES OF TEN DIGITS EACH."); printf("\n");
    /* BASIC: 290 PRINT "I WILL ASK FOR THEN TEN AT A TIME." */
line_290:;
    printf("%s", "I WILL ASK FOR THEN TEN AT A TIME."); printf("\n");
    /* BASIC: 300 PRINT "I WILL ALWAYS GUESS THEM FIRST AND THEN LOOK AT YOUR" */
line_300:;
    printf("%s", "I WILL ALWAYS GUESS THEM FIRST AND THEN LOOK AT YOUR"); printf("\n");
    /* BASIC: 310 PRINT "NEXT NUMBER TO SEE IF I WAS RIGHT. BY PURE LUCK," */
line_310:;
    printf("%s", "NEXT NUMBER TO SEE IF I WAS RIGHT. BY PURE LUCK,"); printf("\n");
    /* BASIC: 320 PRINT "I OUGHT TO BE RIGHT TEN TIMES. BUT I HOPE TO DO BETTER" */
line_320:;
    printf("%s", "I OUGHT TO BE RIGHT TEN TIMES. BUT I HOPE TO DO BETTER"); printf("\n");
    /* BASIC: 330 PRINT "THAN THAT *****" */
line_330:;
    printf("%s", "THAN THAT *****"); printf("\n");
    /* BASIC: 340 PRINT:PRINT */
line_340:;
    printf("\n");
    printf("\n");
    /* BASIC: 360 READ A,B,C */
line_360:;
    read_numeric(&A); read_numeric(&B); read_numeric(&C);
    /* BASIC: 370 DATA 0,1,3 */
line_370:;
    /* UNTRANSLATED: DATA 0,1,3 */
    /* BASIC: 380 DIM M(26,2),K(2,2),L(8,2) */
line_380:;
    /* DIM M(26,2),K(2,2),L(8,2) (handled statically) */
    /* BASIC: 400 FOR I=0 TO 26: FOR J=0 TO 2: M(I,J)=1: NEXT J: NEXT I */
line_400:;
    I = 0; for_loop_I_400: if (((1) >= 0 && I > (26)) || ((1) < 0 && I < (26))) goto end_for_I_400;
    J = 0; for_loop_J_400: if (((1) >= 0 && J > (2)) || ((1) < 0 && J < (2))) goto end_for_J_400;
    M_arr[(int)(I) * 100 + (int)(J)] = 1;
    J += (1); goto for_loop_J_400; end_for_J_400:;
    I += (1); goto for_loop_I_400; end_for_I_400:;
    /* BASIC: 410 FOR I=0 TO 2: FOR J=0 TO 2: K(I,J)=9: NEXT J: NEXT I */
line_410:;
    I = 0; for_loop_I_410: if (((1) >= 0 && I > (2)) || ((1) < 0 && I < (2))) goto end_for_I_410;
    J = 0; for_loop_J_410: if (((1) >= 0 && J > (2)) || ((1) < 0 && J < (2))) goto end_for_J_410;
    K_arr[(int)(I) * 100 + (int)(J)] = 9;
    J += (1); goto for_loop_J_410; end_for_J_410:;
    I += (1); goto for_loop_I_410; end_for_I_410:;
    /* BASIC: 420 FOR I=0 TO 8: FOR J=0 TO 2: L(I,J)=3: NEXT J: NEXT I */
line_420:;
    I = 0; for_loop_I_420: if (((1) >= 0 && I > (8)) || ((1) < 0 && I < (8))) goto end_for_I_420;
    J = 0; for_loop_J_420: if (((1) >= 0 && J > (2)) || ((1) < 0 && J < (2))) goto end_for_J_420;
    L_arr[(int)(I) * 100 + (int)(J)] = 3;
    J += (1); goto for_loop_J_420; end_for_J_420:;
    I += (1); goto for_loop_I_420; end_for_I_420:;
    /* BASIC: 450 L(0,0)=2: L(4,1)=2: L(8,2)=2 */
line_450:;
    L_arr[(int)(0) * 100 + (int)(0)] = 2;
    L_arr[(int)(4) * 100 + (int)(1)] = 2;
    L_arr[(int)(8) * 100 + (int)(2)] = 2;
    /* BASIC: 480 Z=26: Z1=8: Z2=2 */
line_480:;
    Z = 26;
    Z1 = 8;
    Z2 = 2;
    /* BASIC: 510 X=0 */
line_510:;
    X = 0;
    /* BASIC: 520 FOR T=1 TO 3 */
line_520:;
    T = 1; for_loop_T_520: if (((1) >= 0 && T > (3)) || ((1) < 0 && T < (3))) goto end_for_T_520;
    /* BASIC: 530 PRINT */
line_530:;
    printf("\n");
    /* BASIC: 540 PRINT "TEN NUMBERS, PLEASE"; */
line_540:;
    printf("%s", "TEN NUMBERS, PLEASE");
    /* BASIC: 550 INPUT N(1),N(2),N(3),N(4),N(5),N(6),N(7),N(8),N(9),N(10) */
line_550:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &(N_arr[(int)(1)]), &(N_arr[(int)(2)]), &(N_arr[(int)(3)]), &(N_arr[(int)(4)]), &(N_arr[(int)(5)]), &(N_arr[(int)(6)]), &(N_arr[(int)(7)]), &(N_arr[(int)(8)]), &(N_arr[(int)(9)]), &(N_arr[(int)(10)]));
    /* BASIC: 560 FOR I=1 TO 10 */
line_560:;
    I = 1; for_loop_I_560: if (((1) >= 0 && I > (10)) || ((1) < 0 && I < (10))) goto end_for_I_560;
    /* BASIC: 570 W=N(I)-1 */
line_570:;
    W = N_arr[(int)(I)]-1;
    /* BASIC: 580 IF W=SGN(W) THEN 620 */
line_580:;
    if (W==basic_SGN(W)) { goto line_620; }
    /* BASIC: 590 PRINT "ONLY USE THE DIGITS '0', '1', OR '2'." */
line_590:;
    printf("%s", "ONLY USE THE DIGITS '0', '1', OR '2'."); printf("\n");
    /* BASIC: 600 PRINT "LET'S TRY AGAIN.":GOTO 530 */
line_600:;
    printf("%s", "LET'S TRY AGAIN."); printf("\n");
    goto line_530;
    /* BASIC: 620 NEXT I */
line_620:;
    I += (1); goto for_loop_I_560; end_for_I_560:;
    /* BASIC: 630 PRINT: PRINT "MY GUESS","YOUR NO.","RESULT","NO. RIGHT":PRINT */
line_630:;
    printf("\n");
    printf("%s", "MY GUESS"); printf("\t"); printf("%s", "YOUR NO."); printf("\t"); printf("%s", "RESULT"); printf("\t"); printf("%s", "NO. RIGHT"); printf("\n");
    printf("\n");
    /* BASIC: 660 FOR U=1 TO 10 */
line_660:;
    U = 1; for_loop_U_660: if (((1) >= 0 && U > (10)) || ((1) < 0 && U < (10))) goto end_for_U_660;
    /* BASIC: 670 N=N(U): S=0 */
line_670:;
    N = N_arr[(int)(U)];
    S = 0;
    /* BASIC: 690 FOR J=0 TO 2 */
line_690:;
    J = 0; for_loop_J_690: if (((1) >= 0 && J > (2)) || ((1) < 0 && J < (2))) goto end_for_J_690;
    /* BASIC: 700 S1=A*K(Z2,J)+B*L(Z1,J)+C*M(Z,J) */
line_700:;
    S1 = A*K_arr[(int)(Z2) * 100 + (int)(J)]+B*L_arr[(int)(Z1) * 100 + (int)(J)]+C*M_arr[(int)(Z) * 100 + (int)(J)];
    /* BASIC: 710 IF S>S1 THEN 760 */
line_710:;
    if (S>S1) { goto line_760; }
    /* BASIC: 720 IF S<S1 THEN 740 */
line_720:;
    if (S<S1) { goto line_740; }
    /* BASIC: 730 IF RND(1)<.5 THEN 760 */
line_730:;
    if (((double)rand() / (double)RAND_MAX)<.5) { goto line_760; }
    /* BASIC: 740 S=S1: G=J */
line_740:;
    S = S1;
    G = J;
    /* BASIC: 760 NEXT J */
line_760:;
    J += (1); goto for_loop_J_690; end_for_J_690:;
    /* BASIC: 770 PRINT "  ";G,"   ";N(U), */
line_770:;
    printf("%s", "  "); printf("%g ", (double)(G)); printf("\t"); printf("%s", "   "); printf("%g ", (double)(N_arr[(int)(U)])); printf("\t");
    /* BASIC: 780 IF G=N(U) THEN 810 */
line_780:;
    if (G==N_arr[(int)(U)]) { goto line_810; }
    /* BASIC: 790 PRINT " WRONG",X */
line_790:;
    printf("%s", " WRONG"); printf("\t"); printf("%g ", (double)(X)); printf("\n");
    /* BASIC: 800 GOTO 880 */
line_800:;
    goto line_880;
    /* BASIC: 810 X=X+1 */
line_810:;
    X = X+1;
    /* BASIC: 820 PRINT " RIGHT",X */
line_820:;
    printf("%s", " RIGHT"); printf("\t"); printf("%g ", (double)(X)); printf("\n");
    /* BASIC: 830 M(Z,N)=M(Z,N)+1 */
line_830:;
    M_arr[(int)(Z) * 100 + (int)(N)] = M_arr[(int)(Z) * 100 + (int)(N)]+1;
    /* BASIC: 840 L(Z1,N)=L(Z1,N)+1 */
line_840:;
    L_arr[(int)(Z1) * 100 + (int)(N)] = L_arr[(int)(Z1) * 100 + (int)(N)]+1;
    /* BASIC: 850 K(Z2,N)=K(Z2,N)+1 */
line_850:;
    K_arr[(int)(Z2) * 100 + (int)(N)] = K_arr[(int)(Z2) * 100 + (int)(N)]+1;
    /* BASIC: 860 Z=Z-INT(Z/9)*9 */
line_860:;
    Z = Z-floor(Z/9)*9;
    /* BASIC: 870 Z=3*Z+N(U) */
line_870:;
    Z = 3*Z+N_arr[(int)(U)];
    /* BASIC: 880 Z1=Z-INT(Z/9)*9 */
line_880:;
    Z1 = Z-floor(Z/9)*9;
    /* BASIC: 890 Z2=N(U) */
line_890:;
    Z2 = N_arr[(int)(U)];
    /* BASIC: 900 NEXT U */
line_900:;
    U += (1); goto for_loop_U_660; end_for_U_660:;
    /* BASIC: 910 NEXT T */
line_910:;
    T += (1); goto for_loop_T_520; end_for_T_520:;
    /* BASIC: 920 PRINT */
line_920:;
    printf("\n");
    /* BASIC: 930 IF X>10 THEN 980 */
line_930:;
    if (X>10) { goto line_980; }
    /* BASIC: 940 IF X<10 THEN 1010 */
line_940:;
    if (X<10) { goto line_1010; }
    /* BASIC: 950 PRINT "I GUESSED EXACTLY 1/3 OF YOUR NUMBERS." */
line_950:;
    printf("%s", "I GUESSED EXACTLY 1/3 OF YOUR NUMBERS."); printf("\n");
    /* BASIC: 960 PRINT "IT'S A TIE GAME." */
line_960:;
    printf("%s", "IT'S A TIE GAME."); printf("\n");
    /* BASIC: 970 GOTO 1030 */
line_970:;
    goto line_1030;
    /* BASIC: 980 PRINT "I GUESSED MORE THAN 1/3 OF YOUR NUMBERS." */
line_980:;
    printf("%s", "I GUESSED MORE THAN 1/3 OF YOUR NUMBERS."); printf("\n");
    /* BASIC: 990 PRINT "I WIN.": FOR Q=1 TO 10: PRINT CHR$(7);: NEXT Q */
line_990:;
    printf("%s", "I WIN."); printf("\n");
    Q = 1; for_loop_Q_990: if (((1) >= 0 && Q > (10)) || ((1) < 0 && Q < (10))) goto end_for_Q_990;
    printf("%s", basic_CHR(7));
    Q += (1); goto for_loop_Q_990; end_for_Q_990:;
    /* BASIC: 1000 GOTO 1030 */
line_1000:;
    goto line_1030;
    /* BASIC: 1010 PRINT "I GUESSED LESS THAN 1/3 OF YOUR NUMBERS." */
line_1010:;
    printf("%s", "I GUESSED LESS THAN 1/3 OF YOUR NUMBERS."); printf("\n");
    /* BASIC: 1020 PRINT "YOU BEAT ME.  CONGRATULATIONS *****" */
line_1020:;
    printf("%s", "YOU BEAT ME.  CONGRATULATIONS *****"); printf("\n");
    /* BASIC: 1030 PRINT */
line_1030:;
    printf("\n");
    /* BASIC: 1040 PRINT "DO YOU WANT TO TRY AGAIN (1 FOR YES, 0 FOR NO)"; */
line_1040:;
    printf("%s", "DO YOU WANT TO TRY AGAIN (1 FOR YES, 0 FOR NO)");
    /* BASIC: 1060 INPUT X */
line_1060:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &X);
    /* BASIC: 1070 IF X=1 THEN 400 */
line_1070:;
    if (X==1) { goto line_400; }
    /* BASIC: 1080 PRINT:PRINT "THANKS FOR THE GAME." */
line_1080:;
    printf("\n");
    printf("%s", "THANKS FOR THE GAME."); printf("\n");
    /* BASIC: 1090 END */
line_1090:;
    exit(0);

    return 0;
}
