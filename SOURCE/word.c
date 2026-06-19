/*
 * Transpiled from word.bas
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

static DataItem program_data[13] = {
    { DATA_NUM, { .num = 12.0 } },
    { DATA_STR, { .str = "DINKY" } },
    { DATA_STR, { .str = "SMOKE" } },
    { DATA_STR, { .str = "WATER" } },
    { DATA_STR, { .str = "GRASS" } },
    { DATA_STR, { .str = "TRAIN" } },
    { DATA_STR, { .str = "MIGHT" } },
    { DATA_STR, { .str = "FIRST" } },
    { DATA_STR, { .str = "CANDY" } },
    { DATA_STR, { .str = "CHAMP" } },
    { DATA_STR, { .str = "WOULD" } },
    { DATA_STR, { .str = "CLUMP" } },
    { DATA_STR, { .str = "DOPEY" } },
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
static double A, C, D, G, I, J, L, M, N, P, Q, S;
static char A_str[256] = {0};
static char G_str[256] = {0};
static char L_str[256] = {0};
static char P_str[256] = {0};
static char Q_str[256] = {0};
static char S_str[256] = {0};
static double A_arr[20000] = {0};
static double D_arr[20000] = {0};
static double L_arr[20000] = {0};
static double P_arr[20000] = {0};
static double S_arr[20000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 2 PRINT TAB(33);"WORD" */
line_2:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "WORD"); printf("\n");
    /* BASIC: 3 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_3:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 4 PRINT: PRINT: PRINT */
line_4:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 5 DIM S(7),A(7),L(7),D(7),P(7) */
line_5:;
    /* DIM S(7),A(7),L(7),D(7),P(7) (handled statically) */
    /* BASIC: 10 PRINT "I AM THINKING OF A WORD -- YOU GUESS IT.  I WILL GIVE YOU" */
line_10:;
    printf("%s", "I AM THINKING OF A WORD -- YOU GUESS IT.  I WILL GIVE YOU"); printf("\n");
    /* BASIC: 15 PRINT "CLUES TO HELP YOU GET IT.  GOOD LUCK!!": PRINT: PRINT */
line_15:;
    printf("%s", "CLUES TO HELP YOU GET IT.  GOOD LUCK!!"); printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 20 REM */
line_20:;
    // REM
    /* BASIC: 30 PRINT: PRINT: PRINT "YOU ARE STARTING A NEW GAME..." */
line_30:;
    printf("\n");
    printf("\n");
    printf("%s", "YOU ARE STARTING A NEW GAME..."); printf("\n");
    /* BASIC: 35 RESTORE */
line_35:;
    data_ptr = 0;
    /* BASIC: 40 READ N */
line_40:;
    read_numeric(&N);
    /* BASIC: 50 C=INT(RND(1)*N+1) */
line_50:;
    C = floor(((double)rand() / (double)RAND_MAX)*N+1);
    /* BASIC: 60 FOR I=1 TO C */
line_60:;
    I = 1; for_loop_I_60: if (((1) >= 0 && I > (C)) || ((1) < 0 && I < (C))) goto end_for_I_60;
    /* BASIC: 70 READ S$ */
line_70:;
    read_string(S_str, sizeof(S_str));
    /* BASIC: 80 NEXT I */
line_80:;
    I += (1); goto for_loop_I_60; end_for_I_60:;
    /* BASIC: 90 G=0 */
line_90:;
    G = 0;
    /* BASIC: 95 S(0)=LEN(S$) */
line_95:;
    S_arr[(int)(0)] = basic_LEN(S_str);
    /* BASIC: 100 FOR I=1 TO LEN(S$): S(I)=ASC(MID$(S$,I,1)): NEXT I */
line_100:;
    I = 1; for_loop_I_100: if (((1) >= 0 && I > (basic_LEN(S_str))) || ((1) < 0 && I < (basic_LEN(S_str)))) goto end_for_I_100;
    S_arr[(int)(I)] = basic_ASC(basic_MID(S_str,I,1));
    I += (1); goto for_loop_I_100; end_for_I_100:;
    /* BASIC: 110 FOR I=1 TO 5 */
line_110:;
    I = 1; for_loop_I_110: if (((1) >= 0 && I > (5)) || ((1) < 0 && I < (5))) goto end_for_I_110;
    /* BASIC: 120 A(I)=45 */
line_120:;
    A_arr[(int)(I)] = 45;
    /* BASIC: 130 NEXT I */
line_130:;
    I += (1); goto for_loop_I_110; end_for_I_110:;
    /* BASIC: 140 FOR J=1 TO 5 */
line_140:;
    J = 1; for_loop_J_140: if (((1) >= 0 && J > (5)) || ((1) < 0 && J < (5))) goto end_for_J_140;
    /* BASIC: 144 P(J)=0 */
line_144:;
    P_arr[(int)(J)] = 0;
    /* BASIC: 146 NEXT J */
line_146:;
    J += (1); goto for_loop_J_140; end_for_J_140:;
    /* BASIC: 150 PRINT "GUESS A FIVE LETTER WORD"; */
line_150:;
    printf("%s", "GUESS A FIVE LETTER WORD");
    /* BASIC: 160 INPUT L$ */
line_160:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", L_str);
    /* BASIC: 170 G=G+1 */
line_170:;
    G = G+1;
    /* BASIC: 172 IF S$=G$ THEN 500 */
line_172:;
    if (strcmp(S_str, G_str) == 0) { goto line_500; }
    /* BASIC: 173 FOR I=1 TO 7: P(I)=0: NEXT I */
line_173:;
    I = 1; for_loop_I_173: if (((1) >= 0 && I > (7)) || ((1) < 0 && I < (7))) goto end_for_I_173;
    P_arr[(int)(I)] = 0;
    I += (1); goto for_loop_I_173; end_for_I_173:;
    /* BASIC: 175 L(0)=LEN(L$) */
line_175:;
    L_arr[(int)(0)] = basic_LEN(L_str);
    /* BASIC: 180 FOR I=1 TO LEN(L$): L(I)=ASC(MID$(L$,I,1)): NEXT I */
line_180:;
    I = 1; for_loop_I_180: if (((1) >= 0 && I > (basic_LEN(L_str))) || ((1) < 0 && I < (basic_LEN(L_str)))) goto end_for_I_180;
    L_arr[(int)(I)] = basic_ASC(basic_MID(L_str,I,1));
    I += (1); goto for_loop_I_180; end_for_I_180:;
    /* BASIC: 190 IF L(1)=63 THEN 300 */
line_190:;
    if (L_arr[(int)(1)]==63) { goto line_300; }
    /* BASIC: 200 IF L(0)<>5 THEN 400 */
line_200:;
    if (L_arr[(int)(0)]!=5) { goto line_400; }
    /* BASIC: 205 M=0: Q=1 */
line_205:;
    M = 0;
    Q = 1;
    /* BASIC: 210 FOR I=1 TO 5 */
line_210:;
    I = 1; for_loop_I_210: if (((1) >= 0 && I > (5)) || ((1) < 0 && I < (5))) goto end_for_I_210;
    /* BASIC: 220 FOR J=1 TO 5 */
line_220:;
    J = 1; for_loop_J_220: if (((1) >= 0 && J > (5)) || ((1) < 0 && J < (5))) goto end_for_J_220;
    /* BASIC: 230 IF S(I)<>L(J) THEN 260 */
line_230:;
    if (S_arr[(int)(I)]!=L_arr[(int)(J)]) { goto line_260; }
    /* BASIC: 231 P(Q)=L(J) */
line_231:;
    P_arr[(int)(Q)] = L_arr[(int)(J)];
    /* BASIC: 232 Q=Q+1 */
line_232:;
    Q = Q+1;
    /* BASIC: 233 IF I<>J THEN 250 */
line_233:;
    if (I!=J) { goto line_250; }
    /* BASIC: 240 A(J)=L(J) */
line_240:;
    A_arr[(int)(J)] = L_arr[(int)(J)];
    /* BASIC: 250 M=M+1 */
line_250:;
    M = M+1;
    /* BASIC: 260 NEXT J */
line_260:;
    J += (1); goto for_loop_J_220; end_for_J_220:;
    /* BASIC: 265 NEXT I */
line_265:;
    I += (1); goto for_loop_I_210; end_for_I_210:;
    /* BASIC: 270 A(0)=5 */
line_270:;
    A_arr[(int)(0)] = 5;
    /* BASIC: 272 P(0)=M */
line_272:;
    P_arr[(int)(0)] = M;
    /* BASIC: 275 A$="": FOR I=1 TO A(0): A$=A$+CHR$(A(I)): NEXT I */
line_275:;
    str_assign(A_str, sizeof(A_str), "");
    I = 1; for_loop_I_275: if (((1) >= 0 && I > (A_arr[(int)(0)])) || ((1) < 0 && I < (A_arr[(int)(0)]))) goto end_for_I_275;
    str_assign(A_str, sizeof(A_str), str_cat_helper(A_str, basic_CHR(A_arr[(int)(I)])));
    I += (1); goto for_loop_I_275; end_for_I_275:;
    /* BASIC: 277 P$="": FOR I=1 TO P(0): P$=P$+CHR$(P(I)): NEXT I */
line_277:;
    str_assign(P_str, sizeof(P_str), "");
    I = 1; for_loop_I_277: if (((1) >= 0 && I > (P_arr[(int)(0)])) || ((1) < 0 && I < (P_arr[(int)(0)]))) goto end_for_I_277;
    str_assign(P_str, sizeof(P_str), str_cat_helper(P_str, basic_CHR(P_arr[(int)(I)])));
    I += (1); goto for_loop_I_277; end_for_I_277:;
    /* BASIC: 280 PRINT "THERE WERE";M;"MATCHES AND THE COMMON LETTERS WERE...";P$ */
line_280:;
    printf("%s", "THERE WERE"); printf("%g ", (double)(M)); printf("%s", "MATCHES AND THE COMMON LETTERS WERE..."); printf("%s", P_str); printf("\n");
    /* BASIC: 285 PRINT "FROM THE EXACT LETTER MATCHES, YOU KNOW................";A$ */
line_285:;
    printf("%s", "FROM THE EXACT LETTER MATCHES, YOU KNOW................"); printf("%s", A_str); printf("\n");
    /* BASIC: 286 IF A$=S$ THEN 500 */
line_286:;
    if (strcmp(A_str, S_str) == 0) { goto line_500; }
    /* BASIC: 287 IF M>1 THEN 289 */
line_287:;
    if (M>1) { goto line_289; }
    /* BASIC: 288 PRINT: PRINT "IF YOU GIVE UP, TYPE '?' FOR YOUR NEXT GUESS." */
line_288:;
    printf("\n");
    printf("%s", "IF YOU GIVE UP, TYPE '?' FOR YOUR NEXT GUESS."); printf("\n");
    /* BASIC: 289 PRINT */
line_289:;
    printf("\n");
    /* BASIC: 290 GOTO 150 */
line_290:;
    goto line_150;
    /* BASIC: 300 S$="": FOR I=1 TO 7: S$=S$+CHR$(S(I)): NEXT I */
line_300:;
    str_assign(S_str, sizeof(S_str), "");
    I = 1; for_loop_I_300: if (((1) >= 0 && I > (7)) || ((1) < 0 && I < (7))) goto end_for_I_300;
    str_assign(S_str, sizeof(S_str), str_cat_helper(S_str, basic_CHR(S_arr[(int)(I)])));
    I += (1); goto for_loop_I_300; end_for_I_300:;
    /* BASIC: 310 PRINT "THE SECRET WORD IS ";S$: PRINT */
line_310:;
    printf("%s", "THE SECRET WORD IS "); printf("%s", S_str); printf("\n");
    printf("\n");
    /* BASIC: 320 GOTO 30 */
line_320:;
    goto line_30;
    /* BASIC: 400 PRINT "YOU MUST GUESS A 5 LETTER WORD.  START AGAIN." */
line_400:;
    printf("%s", "YOU MUST GUESS A 5 LETTER WORD.  START AGAIN."); printf("\n");
    /* BASIC: 410 PRINT: G=G-1: GOTO 150 */
line_410:;
    printf("\n");
    G = G-1;
    goto line_150;
    /* BASIC: 500 PRINT "YOU HAVE GUESSED THE WORD.  IT TOOK";G;"GUESSES!": PRINT */
line_500:;
    printf("%s", "YOU HAVE GUESSED THE WORD.  IT TOOK"); printf("%g ", (double)(G)); printf("%s", "GUESSES!"); printf("\n");
    printf("\n");
    /* BASIC: 510 INPUT "WANT TO PLAY AGAIN";Q$ */
line_510:;
    printf("%s", "WANT TO PLAY AGAIN"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", Q_str);
    /* BASIC: 520 IF Q$="YES" THEN 30 */
line_520:;
    if (strcmp(Q_str, "YES") == 0) { goto line_30; }
    /* BASIC: 530 DATA 12,"DINKY","SMOKE","WATER","GRASS","TRAIN","MIGHT","FIRST" */
line_530:;
    /* UNTRANSLATED: DATA 12,"DINKY","SMOKE","WATER","GRASS","TRAIN","MIGHT","FIRST" */
    /* BASIC: 540 DATA "CANDY","CHAMP","WOULD","CLUMP","DOPEY" */
line_540:;
    /* UNTRANSLATED: DATA "CANDY","CHAMP","WOULD","CLUMP","DOPEY" */
    /* BASIC: 999 END */
line_999:;
    exit(0);

    return 0;
}
