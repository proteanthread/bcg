/*
 * Transpiled from hangman.bas
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

static DataItem program_data[50] = {
    { DATA_STR, { .str = "GUM" } },
    { DATA_STR, { .str = "SIN" } },
    { DATA_STR, { .str = "FOR" } },
    { DATA_STR, { .str = "CRY" } },
    { DATA_STR, { .str = "LUG" } },
    { DATA_STR, { .str = "BYE" } },
    { DATA_STR, { .str = "FLY" } },
    { DATA_STR, { .str = "UGLY" } },
    { DATA_STR, { .str = "EACH" } },
    { DATA_STR, { .str = "FROM" } },
    { DATA_STR, { .str = "WORK" } },
    { DATA_STR, { .str = "TALK" } },
    { DATA_STR, { .str = "WITH" } },
    { DATA_STR, { .str = "SELF" } },
    { DATA_STR, { .str = "PIZZA" } },
    { DATA_STR, { .str = "THING" } },
    { DATA_STR, { .str = "FEIGN" } },
    { DATA_STR, { .str = "FIEND" } },
    { DATA_STR, { .str = "ELBOW" } },
    { DATA_STR, { .str = "FAULT" } },
    { DATA_STR, { .str = "DIRTY" } },
    { DATA_STR, { .str = "BUDGET" } },
    { DATA_STR, { .str = "SPIRIT" } },
    { DATA_STR, { .str = "QUAINT" } },
    { DATA_STR, { .str = "MAIDEN" } },
    { DATA_STR, { .str = "ESCORT" } },
    { DATA_STR, { .str = "PICKAX" } },
    { DATA_STR, { .str = "EXAMPLE" } },
    { DATA_STR, { .str = "TENSION" } },
    { DATA_STR, { .str = "QUININE" } },
    { DATA_STR, { .str = "KIDNEY" } },
    { DATA_STR, { .str = "REPLICA" } },
    { DATA_STR, { .str = "SLEEPER" } },
    { DATA_STR, { .str = "TRIANGLE" } },
    { DATA_STR, { .str = "KANGAROO" } },
    { DATA_STR, { .str = "MAHOGANY" } },
    { DATA_STR, { .str = "SERGEANT" } },
    { DATA_STR, { .str = "SEQUENCE" } },
    { DATA_STR, { .str = "MOUSTACHE" } },
    { DATA_STR, { .str = "DANGEROUS" } },
    { DATA_STR, { .str = "SCIENTIST" } },
    { DATA_STR, { .str = "DIFFERENT" } },
    { DATA_STR, { .str = "QUIESCENT" } },
    { DATA_STR, { .str = "MAGISTRATE" } },
    { DATA_STR, { .str = "ERRONEOUSLY" } },
    { DATA_STR, { .str = "LOUDSPEAKER" } },
    { DATA_STR, { .str = "PHYTOTOXIC" } },
    { DATA_STR, { .str = "MATRIMONIAL" } },
    { DATA_STR, { .str = "PARASYMPATHOMIMETIC" } },
    { DATA_STR, { .str = "THIGMOTROPISM" } },
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
static double C, I, J, L, M, N, ON, P, Q, R, S, T1, U;
static char A_str[256] = {0};
static char B_str[256] = {0};
static char D_str[256] = {0};
static char G_str[256] = {0};
static char L_str[256] = {0};
static char N_str[256] = {0};
static char P_str[256] = {0};
static char W_str[256] = {0};
static char Y_str[256] = {0};
static double U_arr[20000] = {0};
static char D_str_arr[20000][256] = {0};
static char L_str_arr[20000][256] = {0};
static char N_str_arr[20000][256] = {0};
static char P_str_arr[20000][256] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(32);"HANGMAN" */
line_10:;
    { int _t; for(_t=0; _t<32; _t++) printf(" "); } printf("%s", "HANGMAN"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 25 PRINT:PRINT:PRINT */
line_25:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 30 DIM P$(12,12),L$(20),D$(20),N$(26),U(50) */
line_30:;
    /* DIM P$(12,12),L$(20),D$(20),N$(26),U(50) (handled statically) */
    /* BASIC: 40 C=1: N=50 */
line_40:;
    C = 1;
    N = 50;
    /* BASIC: 50 FOR I=1 TO 20: D$(I)="-": NEXT I: M=0 */
line_50:;
    I = 1; for_loop_I_50: if (((1) >= 0 && I > (20)) || ((1) < 0 && I < (20))) goto end_for_I_50;
    str_assign(D_str_arr[(int)(I)], sizeof(D_str_arr[(int)(I)]), "-");
    I += (1); goto for_loop_I_50; end_for_I_50:;
    M = 0;
    /* BASIC: 60 FOR I=1 TO 26: N$(I)="": NEXT I */
line_60:;
    I = 1; for_loop_I_60: if (((1) >= 0 && I > (26)) || ((1) < 0 && I < (26))) goto end_for_I_60;
    str_assign(N_str_arr[(int)(I)], sizeof(N_str_arr[(int)(I)]), "");
    I += (1); goto for_loop_I_60; end_for_I_60:;
    /* BASIC: 70 FOR I=1 TO 12: FOR J=1 TO 12: P$(I,J)=" ": NEXT J: NEXT I */
line_70:;
    I = 1; for_loop_I_70: if (((1) >= 0 && I > (12)) || ((1) < 0 && I < (12))) goto end_for_I_70;
    J = 1; for_loop_J_70: if (((1) >= 0 && J > (12)) || ((1) < 0 && J < (12))) goto end_for_J_70;
    str_assign(P_str_arr[(int)(I) * 100 + (int)(J)], sizeof(P_str_arr[(int)(I) * 100 + (int)(J)]), " ");
    J += (1); goto for_loop_J_70; end_for_J_70:;
    I += (1); goto for_loop_I_70; end_for_I_70:;
    /* BASIC: 80 FOR I=1 TO 12: P$(I,1)="X": NEXT I */
line_80:;
    I = 1; for_loop_I_80: if (((1) >= 0 && I > (12)) || ((1) < 0 && I < (12))) goto end_for_I_80;
    str_assign(P_str_arr[(int)(I) * 100 + (int)(1)], sizeof(P_str_arr[(int)(I) * 100 + (int)(1)]), "X");
    I += (1); goto for_loop_I_80; end_for_I_80:;
    /* BASIC: 90 FOR I=1 TO 7: P$(1,I)="X": NEXT: P$(2,7)="X" */
line_90:;
    I = 1; for_loop_I_90: if (((1) >= 0 && I > (7)) || ((1) < 0 && I < (7))) goto end_for_I_90;
    str_assign(P_str_arr[(int)(1) * 100 + (int)(I)], sizeof(P_str_arr[(int)(1) * 100 + (int)(I)]), "X");
    /* NEXT (unmatched) */
    str_assign(P_str_arr[(int)(2) * 100 + (int)(7)], sizeof(P_str_arr[(int)(2) * 100 + (int)(7)]), "X");
    /* BASIC: 95 IF C<N THEN 100 */
line_95:;
    if (C<N) { goto line_100; }
    /* BASIC: 97 PRINT "YOU DID ALL THE WORDS!!": S TO P */
line_97:;
    printf("%s", "YOU DID ALL THE WORDS!!"); printf("\n");
    /* UNTRANSLATED: S TO P */
    /* BASIC: 100 Q=INT(N*RND(1))+1 */
line_100:;
    Q = floor(N*((double)rand() / (double)RAND_MAX))+1;
    /* BASIC: 110 IF U(Q)=1 THEN 100 */
line_110:;
    if (U_arr[(int)(Q)]==1) { goto line_100; }
    /* BASIC: 115 U(Q)=1: C=C+1: RESTORE: T1=0 */
line_115:;
    U_arr[(int)(Q)] = 1;
    C = C+1;
    data_ptr = 0;
    T1 = 0;
    /* BASIC: 150 FOR I=1 TO Q: READ A$: NEXT I */
line_150:;
    I = 1; for_loop_I_150: if (((1) >= 0 && I > (Q)) || ((1) < 0 && I < (Q))) goto end_for_I_150;
    read_string(A_str, sizeof(A_str));
    I += (1); goto for_loop_I_150; end_for_I_150:;
    /* BASIC: 160 L=LEN(A$): FOR I=1 TO LEN(A$): L$(I)=MID$(A$,I,1): NEXT I */
line_160:;
    L = basic_LEN(A_str);
    I = 1; for_loop_I_160: if (((1) >= 0 && I > (basic_LEN(A_str))) || ((1) < 0 && I < (basic_LEN(A_str)))) goto end_for_I_160;
    str_assign(L_str_arr[(int)(I)], sizeof(L_str_arr[(int)(I)]), basic_MID(A_str,I,1));
    I += (1); goto for_loop_I_160; end_for_I_160:;
    /* BASIC: 170 PRINT "HERE ARE THE LETTERS YOU USED:" */
line_170:;
    printf("%s", "HERE ARE THE LETTERS YOU USED:"); printf("\n");
    /* BASIC: 180 FOR I=1 TO 26: PRINT N$(I);: IF N$(I+1)="" THEN 200 */
line_180:;
    I = 1; for_loop_I_180: if (((1) >= 0 && I > (26)) || ((1) < 0 && I < (26))) goto end_for_I_180;
    printf("%s", N_str_arr[(int)(I)]);
    if (strcmp(N_str_arr[(int)(I+1)], "") == 0) { goto line_200; }
    /* BASIC: 190 PRINT ",";: NEXT I */
line_190:;
    printf("%s", ",");
    I += (1); goto for_loop_I_180; end_for_I_180:;
    /* BASIC: 200 PRINT: PRINT: FOR I=1 TO L: PRINT D$(I);: NEXT I: PRINT: PRINT */
line_200:;
    printf("\n");
    printf("\n");
    I = 1; for_loop_I_200: if (((1) >= 0 && I > (L)) || ((1) < 0 && I < (L))) goto end_for_I_200;
    printf("%s", D_str_arr[(int)(I)]);
    I += (1); goto for_loop_I_200; end_for_I_200:;
    printf("\n");
    printf("\n");
    /* BASIC: 210 INPUT "WHAT IS YOUR GUESS";G$: R=0 */
line_210:;
    printf("%s", "WHAT IS YOUR GUESS"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", G_str);
    R = 0;
    /* BASIC: 220 FOR I=1 TO 26: IF N$(I)="" THEN 250 */
line_220:;
    I = 1; for_loop_I_220: if (((1) >= 0 && I > (26)) || ((1) < 0 && I < (26))) goto end_for_I_220;
    if (strcmp(N_str_arr[(int)(I)], "") == 0) { goto line_250; }
    /* BASIC: 230 IF G$=N$(I) THEN PRINT "YOU GUESSED THAT LETTER BEFORE!": GOTO 170 */
line_230:;
    if (strcmp(G_str, N_str_arr[(int)(I)]) == 0) { printf("%s", "YOU GUESSED THAT LETTER BEFORE!"); printf("\n"); goto line_170; }
    /* BASIC: 240 NEXT I: PRINT "PROGRAM ERROR.  RUN AGAIN.": S TO P */
line_240:;
    I += (1); goto for_loop_I_220; end_for_I_220:;
    printf("%s", "PROGRAM ERROR.  RUN AGAIN."); printf("\n");
    /* UNTRANSLATED: S TO P */
    /* BASIC: 250 N$(I)=G$: T1=T1+1 */
line_250:;
    str_assign(N_str_arr[(int)(I)], sizeof(N_str_arr[(int)(I)]), G_str);
    T1 = T1+1;
    /* BASIC: 260 FOR I=1 TO L: IF L$(I)=G$ THEN 280 */
line_260:;
    I = 1; for_loop_I_260: if (((1) >= 0 && I > (L)) || ((1) < 0 && I < (L))) goto end_for_I_260;
    if (strcmp(L_str_arr[(int)(I)], G_str) == 0) { goto line_280; }
    /* BASIC: 270 NEXT I: IF R=0 THEN 290 */
line_270:;
    I += (1); goto for_loop_I_260; end_for_I_260:;
    if (R==0) { goto line_290; }
    /* BASIC: 275 GOTO 300 */
line_275:;
    goto line_300;
    /* BASIC: 280 D$(I)=G$: R=R+1: GOTO 270 */
line_280:;
    str_assign(D_str_arr[(int)(I)], sizeof(D_str_arr[(int)(I)]), G_str);
    R = R+1;
    goto line_270;
    /* BASIC: 290 M=M+1: GOTO 400 */
line_290:;
    M = M+1;
    goto line_400;
    /* BASIC: 300 FOR I=1 TO L: IF D$(I)="-" THEN 320 */
line_300:;
    I = 1; for_loop_I_300: if (((1) >= 0 && I > (L)) || ((1) < 0 && I < (L))) goto end_for_I_300;
    if (strcmp(D_str_arr[(int)(I)], "-") == 0) { goto line_320; }
    /* BASIC: 310 NEXT I: GOTO 390 */
line_310:;
    I += (1); goto for_loop_I_300; end_for_I_300:;
    goto line_390;
    /* BASIC: 320 PRINT: FOR I=1 TO L: PRINT D$(I);: NEXT I: PRINT: PRINT */
line_320:;
    printf("\n");
    I = 1; for_loop_I_320: if (((1) >= 0 && I > (L)) || ((1) < 0 && I < (L))) goto end_for_I_320;
    printf("%s", D_str_arr[(int)(I)]);
    I += (1); goto for_loop_I_320; end_for_I_320:;
    printf("\n");
    printf("\n");
    /* BASIC: 330 INPUT "WHAT IS YOUR GUESS FOR THE WORD";B$ */
line_330:;
    printf("%s", "WHAT IS YOUR GUESS FOR THE WORD"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", B_str);
    /* BASIC: 340 IF A$=B$ THEN 360 */
line_340:;
    if (strcmp(A_str, B_str) == 0) { goto line_360; }
    /* BASIC: 350 PRINT "WRONG.  TRY ANOTHER LETTER.": PRINT: GOTO 170 */
line_350:;
    printf("%s", "WRONG.  TRY ANOTHER LETTER."); printf("\n");
    printf("\n");
    goto line_170;
    /* BASIC: 360 PRINT "RIGHT!!  IT TOOK YOU";T1;"GUESSES!" */
line_360:;
    printf("%s", "RIGHT!!  IT TOOK YOU"); printf("%g ", (double)(T1)); printf("%s", "GUESSES!"); printf("\n");
    /* BASIC: 370 INPUT "WANT ANOTHER WORD";W$: IF W$="YES" THEN 50 */
line_370:;
    printf("%s", "WANT ANOTHER WORD"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", W_str);
    if (strcmp(W_str, "YES") == 0) { goto line_50; }
    /* BASIC: 380 PRINT: PRINT "IT'S BEEN FUN!  BYE FOR NOW.": GOTO 999 */
line_380:;
    printf("\n");
    printf("%s", "IT'S BEEN FUN!  BYE FOR NOW."); printf("\n");
    goto line_999;
    /* BASIC: 390 PRINT "YOU FOUND THE WORD!": GOTO 370 */
line_390:;
    printf("%s", "YOU FOUND THE WORD!"); printf("\n");
    goto line_370;
    /* BASIC: 400 PRINT: PRINT: PRINT"SORRY, THAT LETTER ISN'T IN THE WORD." */
line_400:;
    printf("\n");
    printf("\n");
    printf("%s", "SORRY, THAT LETTER ISN'T IN THE WORD."); printf("\n");
    /* BASIC: 410 ON M GOTO 415,420,425,430,435,440,445,450,455,460 */
line_410:;
    switch ((int)(M)) {     case 1: goto line_415;     case 2: goto line_420;     case 3: goto line_425;     case 4: goto line_430;     case 5: goto line_435;     case 6: goto line_440;     case 7: goto line_445;     case 8: goto line_450;     case 9: goto line_455;     case 10: goto line_460; }
    /* BASIC: 415 PRINT "FIRST, WE DRAW A HEAD": GOTO 470 */
line_415:;
    printf("%s", "FIRST, WE DRAW A HEAD"); printf("\n");
    goto line_470;
    /* BASIC: 420 PRINT "NOW WE DRAW A BODY.": GOTO 470 */
line_420:;
    printf("%s", "NOW WE DRAW A BODY."); printf("\n");
    goto line_470;
    /* BASIC: 425 PRINT "NEXT WE DRAW AN ARM.": GOTO 470 */
line_425:;
    printf("%s", "NEXT WE DRAW AN ARM."); printf("\n");
    goto line_470;
    /* BASIC: 430 PRINT "THIS TIME IT'S THE OTHER ARM.": GOTO 470 */
line_430:;
    printf("%s", "THIS TIME IT'S THE OTHER ARM."); printf("\n");
    goto line_470;
    /* BASIC: 435 PRINT "NOW, LET'S DRAW THE RIGHT LEG.": GOTO 470 */
line_435:;
    printf("%s", "NOW, LET'S DRAW THE RIGHT LEG."); printf("\n");
    goto line_470;
    /* BASIC: 440 PRINT "THIS TIME WE DRAW THE LEFT LEG.": GOTO 470 */
line_440:;
    printf("%s", "THIS TIME WE DRAW THE LEFT LEG."); printf("\n");
    goto line_470;
    /* BASIC: 445 PRINT "NOW WE PUT UP A HAND.": GOTO 470 */
line_445:;
    printf("%s", "NOW WE PUT UP A HAND."); printf("\n");
    goto line_470;
    /* BASIC: 450 PRINT "NEXT THE OTHER HAND.": GOTO 470 */
line_450:;
    printf("%s", "NEXT THE OTHER HAND."); printf("\n");
    goto line_470;
    /* BASIC: 455 PRINT "NOW WE DRAW ONE FOOT": GOTO 470 */
line_455:;
    printf("%s", "NOW WE DRAW ONE FOOT"); printf("\n");
    goto line_470;
    /* BASIC: 460 PRINT "HERE'S THE OTHER FOOT -- YOU'RE HUNG!!" */
line_460:;
    printf("%s", "HERE'S THE OTHER FOOT -- YOU'RE HUNG!!"); printf("\n");
    /* BASIC: 470 ON M GOTO 480,490,500,510,520,530,540,550,560,570 */
line_470:;
    switch ((int)(M)) {     case 1: goto line_480;     case 2: goto line_490;     case 3: goto line_500;     case 4: goto line_510;     case 5: goto line_520;     case 6: goto line_530;     case 7: goto line_540;     case 8: goto line_550;     case 9: goto line_560;     case 10: goto line_570; }
    /* BASIC: 480 P$(3,6)="-": P$(3,7)="-": P$(3,8)="-": P$(4,5)="(": P$(4,6)="." */
line_480:;
    str_assign(P_str_arr[(int)(3) * 100 + (int)(6)], sizeof(P_str_arr[(int)(3) * 100 + (int)(6)]), "-");
    str_assign(P_str_arr[(int)(3) * 100 + (int)(7)], sizeof(P_str_arr[(int)(3) * 100 + (int)(7)]), "-");
    str_assign(P_str_arr[(int)(3) * 100 + (int)(8)], sizeof(P_str_arr[(int)(3) * 100 + (int)(8)]), "-");
    str_assign(P_str_arr[(int)(4) * 100 + (int)(5)], sizeof(P_str_arr[(int)(4) * 100 + (int)(5)]), "(");
    str_assign(P_str_arr[(int)(4) * 100 + (int)(6)], sizeof(P_str_arr[(int)(4) * 100 + (int)(6)]), ".");
    /* BASIC: 481 P$(4,8)=".":P$(4,9)=")":P$(5,6)="-":P$(5,7)="-":P$(5,8)="-":GOTO 580 */
line_481:;
    str_assign(P_str_arr[(int)(4) * 100 + (int)(8)], sizeof(P_str_arr[(int)(4) * 100 + (int)(8)]), ".");
    str_assign(P_str_arr[(int)(4) * 100 + (int)(9)], sizeof(P_str_arr[(int)(4) * 100 + (int)(9)]), ")");
    str_assign(P_str_arr[(int)(5) * 100 + (int)(6)], sizeof(P_str_arr[(int)(5) * 100 + (int)(6)]), "-");
    str_assign(P_str_arr[(int)(5) * 100 + (int)(7)], sizeof(P_str_arr[(int)(5) * 100 + (int)(7)]), "-");
    str_assign(P_str_arr[(int)(5) * 100 + (int)(8)], sizeof(P_str_arr[(int)(5) * 100 + (int)(8)]), "-");
    goto line_580;
    /* BASIC: 490 FOR I=6 TO 9: P$(I,7)="X": NEXT I: GOTO 580 */
line_490:;
    I = 6; for_loop_I_490: if (((1) >= 0 && I > (9)) || ((1) < 0 && I < (9))) goto end_for_I_490;
    str_assign(P_str_arr[(int)(I) * 100 + (int)(7)], sizeof(P_str_arr[(int)(I) * 100 + (int)(7)]), "X");
    I += (1); goto for_loop_I_490; end_for_I_490:;
    goto line_580;
    /* BASIC: 500 FOR I=4 TO 7: P$(I,I-1)="\": NEXT I: GOTO 580 */
line_500:;
    I = 4; for_loop_I_500: if (((1) >= 0 && I > (7)) || ((1) < 0 && I < (7))) goto end_for_I_500;
    str_assign(P_str_arr[(int)(I) * 100 + (int)(I-1)], sizeof(P_str_arr[(int)(I) * 100 + (int)(I-1)]), "\\");
    I += (1); goto for_loop_I_500; end_for_I_500:;
    goto line_580;
    /* BASIC: 510 P$(4,11)="/": P$(5,10)="/": P$(6,9)="/": P$(7,8)="/": GOTO 580 */
line_510:;
    str_assign(P_str_arr[(int)(4) * 100 + (int)(11)], sizeof(P_str_arr[(int)(4) * 100 + (int)(11)]), "/");
    str_assign(P_str_arr[(int)(5) * 100 + (int)(10)], sizeof(P_str_arr[(int)(5) * 100 + (int)(10)]), "/");
    str_assign(P_str_arr[(int)(6) * 100 + (int)(9)], sizeof(P_str_arr[(int)(6) * 100 + (int)(9)]), "/");
    str_assign(P_str_arr[(int)(7) * 100 + (int)(8)], sizeof(P_str_arr[(int)(7) * 100 + (int)(8)]), "/");
    goto line_580;
    /* BASIC: 520 P$(10,6)="/": P$(11,5)="/": GOTO 580 */
line_520:;
    str_assign(P_str_arr[(int)(10) * 100 + (int)(6)], sizeof(P_str_arr[(int)(10) * 100 + (int)(6)]), "/");
    str_assign(P_str_arr[(int)(11) * 100 + (int)(5)], sizeof(P_str_arr[(int)(11) * 100 + (int)(5)]), "/");
    goto line_580;
    /* BASIC: 530 P$(10,8)="\": P$(11,9)="\": GOTO 580 */
line_530:;
    str_assign(P_str_arr[(int)(10) * 100 + (int)(8)], sizeof(P_str_arr[(int)(10) * 100 + (int)(8)]), "\\");
    str_assign(P_str_arr[(int)(11) * 100 + (int)(9)], sizeof(P_str_arr[(int)(11) * 100 + (int)(9)]), "\\");
    goto line_580;
    /* BASIC: 540 P$(3,11)="\": GOTO 580 */
line_540:;
    str_assign(P_str_arr[(int)(3) * 100 + (int)(11)], sizeof(P_str_arr[(int)(3) * 100 + (int)(11)]), "\\");
    goto line_580;
    /* BASIC: 550 P$(3,3)="/": GOTO 580 */
line_550:;
    str_assign(P_str_arr[(int)(3) * 100 + (int)(3)], sizeof(P_str_arr[(int)(3) * 100 + (int)(3)]), "/");
    goto line_580;
    /* BASIC: 560 P$(12,10)="\": P$(12,11)="-": GOTO 580 */
line_560:;
    str_assign(P_str_arr[(int)(12) * 100 + (int)(10)], sizeof(P_str_arr[(int)(12) * 100 + (int)(10)]), "\\");
    str_assign(P_str_arr[(int)(12) * 100 + (int)(11)], sizeof(P_str_arr[(int)(12) * 100 + (int)(11)]), "-");
    goto line_580;
    /* BASIC: 570 P$(12,3)="-": P$(12,4)="/" */
line_570:;
    str_assign(P_str_arr[(int)(12) * 100 + (int)(3)], sizeof(P_str_arr[(int)(12) * 100 + (int)(3)]), "-");
    str_assign(P_str_arr[(int)(12) * 100 + (int)(4)], sizeof(P_str_arr[(int)(12) * 100 + (int)(4)]), "/");
    /* BASIC: 580 FOR I=1 TO 12: FOR J=1 TO 12: PRINT P$(I,J);: NEXT J */
line_580:;
    I = 1; for_loop_I_580: if (((1) >= 0 && I > (12)) || ((1) < 0 && I < (12))) goto end_for_I_580;
    J = 1; for_loop_J_580: if (((1) >= 0 && J > (12)) || ((1) < 0 && J < (12))) goto end_for_J_580;
    printf("%s", P_str_arr[(int)(I) * 100 + (int)(J)]);
    J += (1); goto for_loop_J_580; end_for_J_580:;
    /* BASIC: 590 PRINT: NEXT I: PRINT: PRINT: IF M<>10 THEN 170 */
line_590:;
    printf("\n");
    I += (1); goto for_loop_I_580; end_for_I_580:;
    printf("\n");
    printf("\n");
    if (M!=10) { goto line_170; }
    /* BASIC: 600 PRINT "SORRY, YOU LOSE.  THE WORD WAS ";A$ */
line_600:;
    printf("%s", "SORRY, YOU LOSE.  THE WORD WAS "); printf("%s", A_str); printf("\n");
    /* BASIC: 610 PRINT "YOU MISSED THAT ONE.  DO YOU ";: GOTO 370 */
line_610:;
    printf("%s", "YOU MISSED THAT ONE.  DO YOU ");
    goto line_370;
    /* BASIC: 620 INPUT "TYPE YES OR NO";Y$: IF LEFT$(Y$,1)="Y" THEN 50 */
line_620:;
    printf("%s", "TYPE YES OR NO"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", Y_str);
    if (strcmp(basic_LEFT(Y_str,1), "Y") == 0) { goto line_50; }
    /* BASIC: 700 DATA "GUM","SIN","FOR","CRY","LUG","BYE","FLY" */
line_700:;
    /* UNTRANSLATED: DATA "GUM","SIN","FOR","CRY","LUG","BYE","FLY" */
    /* BASIC: 710 DATA "UGLY","EACH","FROM","WORK","TALK","WITH","SELF" */
line_710:;
    /* UNTRANSLATED: DATA "UGLY","EACH","FROM","WORK","TALK","WITH","SELF" */
    /* BASIC: 720 DATA "PIZZA","THING","FEIGN","FIEND","ELBOW","FAULT","DIRTY" */
line_720:;
    /* UNTRANSLATED: DATA "PIZZA","THING","FEIGN","FIEND","ELBOW","FAULT","DIRTY" */
    /* BASIC: 730 DATA "BUDGET","SPIRIT","QUAINT","MAIDEN","ESCORT","PICKAX" */
line_730:;
    /* UNTRANSLATED: DATA "BUDGET","SPIRIT","QUAINT","MAIDEN","ESCORT","PICKAX" */
    /* BASIC: 740 DATA "EXAMPLE","TENSION","QUININE","KIDNEY","REPLICA","SLEEPER" */
line_740:;
    /* UNTRANSLATED: DATA "EXAMPLE","TENSION","QUININE","KIDNEY","REPLICA","SLEEPER" */
    /* BASIC: 750 DATA "TRIANGLE","KANGAROO","MAHOGANY","SERGEANT","SEQUENCE" */
line_750:;
    /* UNTRANSLATED: DATA "TRIANGLE","KANGAROO","MAHOGANY","SERGEANT","SEQUENCE" */
    /* BASIC: 760 DATA "MOUSTACHE","DANGEROUS","SCIENTIST","DIFFERENT","QUIESCENT" */
line_760:;
    /* UNTRANSLATED: DATA "MOUSTACHE","DANGEROUS","SCIENTIST","DIFFERENT","QUIESCENT" */
    /* BASIC: 770 DATA "MAGISTRATE","ERRONEOUSLY","LOUDSPEAKER","PHYTOTOXIC" */
line_770:;
    /* UNTRANSLATED: DATA "MAGISTRATE","ERRONEOUSLY","LOUDSPEAKER","PHYTOTOXIC" */
    /* BASIC: 780 DATA "MATRIMONIAL","PARASYMPATHOMIMETIC","THIGMOTROPISM" */
line_780:;
    /* UNTRANSLATED: DATA "MATRIMONIAL","PARASYMPATHOMIMETIC","THIGMOTROPISM" */
    /* BASIC: 990 PRINT "BYE NOW" */
line_990:;
    printf("%s", "BYE NOW"); printf("\n");
    /* BASIC: 999 END */
line_999:;
    exit(0);
    /* Undefined labels declared here to compile cleanly */
    end_for_I_90:;

    return 0;
}
