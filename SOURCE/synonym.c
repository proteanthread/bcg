/*
 * Transpiled from synonym.bas
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

static DataItem program_data[70] = {
    { DATA_NUM, { .num = 10.0 } },
    { DATA_NUM, { .num = 5.0 } },
    { DATA_STR, { .str = "FIRST" } },
    { DATA_STR, { .str = "START" } },
    { DATA_STR, { .str = "BEGINNING" } },
    { DATA_STR, { .str = "ONSET" } },
    { DATA_STR, { .str = "INITIAL" } },
    { DATA_NUM, { .num = 5.0 } },
    { DATA_STR, { .str = "SIMILAR" } },
    { DATA_STR, { .str = "ALIKE" } },
    { DATA_STR, { .str = "SAME" } },
    { DATA_STR, { .str = "LIKE" } },
    { DATA_STR, { .str = "RESEMBLING" } },
    { DATA_NUM, { .num = 5.0 } },
    { DATA_STR, { .str = "MODEL" } },
    { DATA_STR, { .str = "PATTERN" } },
    { DATA_STR, { .str = "PROTOTYPE" } },
    { DATA_STR, { .str = "STANDARD" } },
    { DATA_STR, { .str = "CRITERION" } },
    { DATA_NUM, { .num = 5.0 } },
    { DATA_STR, { .str = "SMALL" } },
    { DATA_STR, { .str = "INSIGNIFICANT" } },
    { DATA_STR, { .str = "LITTLE" } },
    { DATA_STR, { .str = "TINY" } },
    { DATA_STR, { .str = "MINUTE" } },
    { DATA_NUM, { .num = 6.0 } },
    { DATA_STR, { .str = "STOP" } },
    { DATA_STR, { .str = "HALT" } },
    { DATA_STR, { .str = "STAY" } },
    { DATA_STR, { .str = "ARREST" } },
    { DATA_STR, { .str = "CHECK" } },
    { DATA_STR, { .str = "STANDSTILL" } },
    { DATA_NUM, { .num = 6.0 } },
    { DATA_STR, { .str = "HOUSE" } },
    { DATA_STR, { .str = "DWELLING" } },
    { DATA_STR, { .str = "RESIDENCE" } },
    { DATA_STR, { .str = "DOMICILE" } },
    { DATA_STR, { .str = "LODGING" } },
    { DATA_STR, { .str = "HABITATION" } },
    { DATA_NUM, { .num = 7.0 } },
    { DATA_STR, { .str = "PIT" } },
    { DATA_STR, { .str = "HOLE" } },
    { DATA_STR, { .str = "HOLLOW" } },
    { DATA_STR, { .str = "WELL" } },
    { DATA_STR, { .str = "GULF" } },
    { DATA_STR, { .str = "CHASM" } },
    { DATA_STR, { .str = "ABYSS" } },
    { DATA_NUM, { .num = 7.0 } },
    { DATA_STR, { .str = "PUSH" } },
    { DATA_STR, { .str = "SHOVE" } },
    { DATA_STR, { .str = "THRUST" } },
    { DATA_STR, { .str = "PROD" } },
    { DATA_STR, { .str = "POKE" } },
    { DATA_STR, { .str = "BUTT" } },
    { DATA_STR, { .str = "PRESS" } },
    { DATA_NUM, { .num = 6.0 } },
    { DATA_STR, { .str = "RED" } },
    { DATA_STR, { .str = "ROUGE" } },
    { DATA_STR, { .str = "SCARLET" } },
    { DATA_STR, { .str = "CRIMSON" } },
    { DATA_STR, { .str = "FLAME" } },
    { DATA_STR, { .str = "RUBY" } },
    { DATA_NUM, { .num = 7.0 } },
    { DATA_STR, { .str = "PAIN" } },
    { DATA_STR, { .str = "SUFFERING" } },
    { DATA_STR, { .str = "HURT" } },
    { DATA_STR, { .str = "MISERY" } },
    { DATA_STR, { .str = "DISTRESS" } },
    { DATA_STR, { .str = "ACHE" } },
    { DATA_STR, { .str = "DISCOMFORT" } },
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
static double C, G, G1, I, J, K, L, N, N1, N2, R;
static char A_str[256] = {0};
static char R_str[256] = {0};
static char W_str[256] = {0};
static double L_arr[20000] = {0};
static double R_arr[20000] = {0};
static char R_str_arr[20000][256] = {0};
static char W_str_arr[20000][256] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 2 PRINT TAB(33);"SYNONYM" */
line_2:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "SYNONYM"); printf("\n");
    /* BASIC: 4 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 6 PRINT: PRINT: PRINT */
line_6:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 10 DIM R$(5),W$(10),L(30),R(30) */
line_10:;
    /* DIM R$(5),W$(10),L(30),R(30) (handled statically) */
    /* BASIC: 20 R$(1)="RIGHT": R$(2)="CORRECT": R$(3)="FINE": R$(4)="GOOD!" */
line_20:;
    str_assign(R_str_arr[(int)(1)], sizeof(R_str_arr[(int)(1)]), "RIGHT");
    str_assign(R_str_arr[(int)(2)], sizeof(R_str_arr[(int)(2)]), "CORRECT");
    str_assign(R_str_arr[(int)(3)], sizeof(R_str_arr[(int)(3)]), "FINE");
    str_assign(R_str_arr[(int)(4)], sizeof(R_str_arr[(int)(4)]), "GOOD!");
    /* BASIC: 30 R$(5)="CHECK" */
line_30:;
    str_assign(R_str_arr[(int)(5)], sizeof(R_str_arr[(int)(5)]), "CHECK");
    /* BASIC: 70 C=0 */
line_70:;
    C = 0;
    /* BASIC: 90 PRINT "A SYNONYM OF A WORD MEANS ANOTHER WORD IN THE ENGLISH" */
line_90:;
    printf("%s", "A SYNONYM OF A WORD MEANS ANOTHER WORD IN THE ENGLISH"); printf("\n");
    /* BASIC: 100 PRINT "LANGUAGE WHICH HAS THE SAME OR VERY NEARLY THE SAME"; */
line_100:;
    printf("%s", "LANGUAGE WHICH HAS THE SAME OR VERY NEARLY THE SAME");
    /* BASIC: 110 PRINT " MEANING." */
line_110:;
    printf("%s", " MEANING."); printf("\n");
    /* BASIC: 130 PRINT "I CHOOSE A WORD -- YOU TYPE A SYNONYM." */
line_130:;
    printf("%s", "I CHOOSE A WORD -- YOU TYPE A SYNONYM."); printf("\n");
    /* BASIC: 140 PRINT "IF YOU CAN'T THINK OF A SYNONYM, TYPE THE WORD 'HELP'" */
line_140:;
    printf("%s", "IF YOU CAN'T THINK OF A SYNONYM, TYPE THE WORD 'HELP'"); printf("\n");
    /* BASIC: 145 PRINT "AND I WILL TELL YOU A SYNONYM.": PRINT */
line_145:;
    printf("%s", "AND I WILL TELL YOU A SYNONYM."); printf("\n");
    printf("\n");
    /* BASIC: 150 RESTORE: C=C+1: READ N */
line_150:;
    data_ptr = 0;
    C = C+1;
    read_numeric(&N);
    /* BASIC: 160 IF C>N THEN 420 */
line_160:;
    if (C>N) { goto line_420; }
    /* BASIC: 170 N1=INT(RND(1)*N+1) */
line_170:;
    N1 = floor(((double)rand() / (double)RAND_MAX)*N+1);
    /* BASIC: 174 IF R(N1)=1 THEN 170 */
line_174:;
    if (R_arr[(int)(N1)]==1) { goto line_170; }
    /* BASIC: 176 R(N1)=1 */
line_176:;
    R_arr[(int)(N1)] = 1;
    /* BASIC: 180 FOR I=1 TO N1 */
line_180:;
    I = 1; for_loop_I_180: if (((1) >= 0 && I > (N1)) || ((1) < 0 && I < (N1))) goto end_for_I_180;
    /* BASIC: 190 READ N2 */
line_190:;
    read_numeric(&N2);
    /* BASIC: 200 FOR J=1 TO N2 */
line_200:;
    J = 1; for_loop_J_200: if (((1) >= 0 && J > (N2)) || ((1) < 0 && J < (N2))) goto end_for_J_200;
    /* BASIC: 210 READ W$(J) */
line_210:;
    read_string(W_str_arr[(int)(J)], sizeof(W_str_arr[(int)(J)]));
    /* BASIC: 220 NEXT J */
line_220:;
    J += (1); goto for_loop_J_200; end_for_J_200:;
    /* BASIC: 230 NEXT I */
line_230:;
    I += (1); goto for_loop_I_180; end_for_I_180:;
    /* BASIC: 232 FOR J=1 TO N2: L(J)=J: NEXT J */
line_232:;
    J = 1; for_loop_J_232: if (((1) >= 0 && J > (N2)) || ((1) < 0 && J < (N2))) goto end_for_J_232;
    L_arr[(int)(J)] = J;
    J += (1); goto for_loop_J_232; end_for_J_232:;
    /* BASIC: 235 L(0)=N2: G=1: PRINT */
line_235:;
    L_arr[(int)(0)] = N2;
    G = 1;
    printf("\n");
    /* BASIC: 237 L(G)=L(L(0)): L(0)=N2-1: PRINT */
line_237:;
    L_arr[(int)(G)] = L_arr[(int)(L_arr[(int)(0)])];
    L_arr[(int)(0)] = N2-1;
    printf("\n");
    /* BASIC: 240 PRINT "     WHAT IS A SYNONYM OF ";W$(G);: INPUT A$ */
line_240:;
    printf("%s", "     WHAT IS A SYNONYM OF "); printf("%s", W_str_arr[(int)(G)]);
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    /* BASIC: 250 IF A$="HELP" THEN 340 */
line_250:;
    if (strcmp(A_str, "HELP") == 0) { goto line_340; }
    /* BASIC: 260 FOR K=1 TO N2 */
line_260:;
    K = 1; for_loop_K_260: if (((1) >= 0 && K > (N2)) || ((1) < 0 && K < (N2))) goto end_for_K_260;
    /* BASIC: 270 IF G=K THEN 290 */
line_270:;
    if (G==K) { goto line_290; }
    /* BASIC: 280 IF A$=W$(K) THEN 320 */
line_280:;
    if (strcmp(A_str, W_str_arr[(int)(K)]) == 0) { goto line_320; }
    /* BASIC: 290 NEXT K */
line_290:;
    K += (1); goto for_loop_K_260; end_for_K_260:;
    /* BASIC: 300 PRINT "     TRY AGAIN.": GOTO 240 */
line_300:;
    printf("%s", "     TRY AGAIN."); printf("\n");
    goto line_240;
    /* BASIC: 320 PRINT R$(INT(RND(1)*5+1)): GOTO 150 */
line_320:;
    printf("%s", R_str_arr[(int)(floor(((double)rand() / (double)RAND_MAX)*5+1))]); printf("\n");
    goto line_150;
    /* BASIC: 340 G1=INT(RND(1)*L(0)+1) */
line_340:;
    G1 = floor(((double)rand() / (double)RAND_MAX)*L_arr[(int)(0)]+1);
    /* BASIC: 360 PRINT "**** A SYNONYM OF ";W$(G);" IS ";W$(L(G1));".": PRINT */
line_360:;
    printf("%s", "**** A SYNONYM OF "); printf("%s", W_str_arr[(int)(G)]); printf("%s", " IS "); printf("%s", W_str_arr[(int)(L_arr[(int)(G1)])]); printf("%s", "."); printf("\n");
    printf("\n");
    /* BASIC: 370 L(G1)=L(L(0)): L(0)=L(0)-1: GOTO 240 */
line_370:;
    L_arr[(int)(G1)] = L_arr[(int)(L_arr[(int)(0)])];
    L_arr[(int)(0)] = L_arr[(int)(0)]-1;
    goto line_240;
    /* BASIC: 420 PRINT: PRINT "SYNONYM DRILL COMPLETED.": GOTO 999 */
line_420:;
    printf("\n");
    printf("%s", "SYNONYM DRILL COMPLETED."); printf("\n");
    goto line_999;
    /* BASIC: 500 DATA 10 */
line_500:;
    /* UNTRANSLATED: DATA 10 */
    /* BASIC: 510 DATA 5,"FIRST","START","BEGINNING","ONSET","INITIAL" */
line_510:;
    /* UNTRANSLATED: DATA 5,"FIRST","START","BEGINNING","ONSET","INITIAL" */
    /* BASIC: 520 DATA 5,"SIMILAR","ALIKE","SAME","LIKE","RESEMBLING" */
line_520:;
    /* UNTRANSLATED: DATA 5,"SIMILAR","ALIKE","SAME","LIKE","RESEMBLING" */
    /* BASIC: 530 DATA 5,"MODEL","PATTERN","PROTOTYPE","STANDARD","CRITERION" */
line_530:;
    /* UNTRANSLATED: DATA 5,"MODEL","PATTERN","PROTOTYPE","STANDARD","CRITERION" */
    /* BASIC: 540 DATA 5,"SMALL","INSIGNIFICANT","LITTLE","TINY","MINUTE" */
line_540:;
    /* UNTRANSLATED: DATA 5,"SMALL","INSIGNIFICANT","LITTLE","TINY","MINUTE" */
    /* BASIC: 550 DATA 6,"STOP","HALT","STAY","ARREST","CHECK","STANDSTILL" */
line_550:;
    /* UNTRANSLATED: DATA 6,"STOP","HALT","STAY","ARREST","CHECK","STANDSTILL" */
    /* BASIC: 560 DATA 6,"HOUSE","DWELLING","RESIDENCE","DOMICILE","LODGING" */
line_560:;
    /* UNTRANSLATED: DATA 6,"HOUSE","DWELLING","RESIDENCE","DOMICILE","LODGING" */
    /* BASIC: 565 DATA "HABITATION" */
line_565:;
    /* UNTRANSLATED: DATA "HABITATION" */
    /* BASIC: 570 DATA 7,"PIT","HOLE","HOLLOW","WELL","GULF","CHASM","ABYSS" */
line_570:;
    /* UNTRANSLATED: DATA 7,"PIT","HOLE","HOLLOW","WELL","GULF","CHASM","ABYSS" */
    /* BASIC: 580 DATA 7,"PUSH","SHOVE","THRUST","PROD","POKE","BUTT","PRESS" */
line_580:;
    /* UNTRANSLATED: DATA 7,"PUSH","SHOVE","THRUST","PROD","POKE","BUTT","PRESS" */
    /* BASIC: 590 DATA 6,"RED","ROUGE","SCARLET","CRIMSON","FLAME","RUBY" */
line_590:;
    /* UNTRANSLATED: DATA 6,"RED","ROUGE","SCARLET","CRIMSON","FLAME","RUBY" */
    /* BASIC: 600 DATA 7,"PAIN","SUFFERING","HURT","MISERY","DISTRESS","ACHE" */
line_600:;
    /* UNTRANSLATED: DATA 7,"PAIN","SUFFERING","HURT","MISERY","DISTRESS","ACHE" */
    /* BASIC: 605 DATA "DISCOMFORT" */
line_605:;
    /* UNTRANSLATED: DATA "DISCOMFORT" */
    /* BASIC: 999 END */
line_999:;
    exit(0);

    return 0;
}
