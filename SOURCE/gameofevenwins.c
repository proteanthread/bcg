/*
 * Transpiled from gameofevenwins.bas
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

/* Global variables */
static double A, B, E, E1, I, L, L1, M, P, R;
static char A_str[256] = {0};
static double R_arr[20000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 1 PRINT TAB(28);"GAME OF EVEN WINS" */
line_1:;
    { int _t; for(_t=0; _t<28; _t++) printf(" "); } printf("%s", "GAME OF EVEN WINS"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT:PRINT */
line_3:;
    printf("\n");
    printf("\n");
    /* BASIC: 4 INPUT "DO YOU WANT INSTRUCTIONS (YES OR NO)";A$:PRINT */
line_4:;
    printf("%s", "DO YOU WANT INSTRUCTIONS (YES OR NO)"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    printf("\n");
    /* BASIC: 5 IF A$="NO" THEN 20 */
line_5:;
    if (strcmp(A_str, "NO") == 0) { goto line_20; }
    /* BASIC: 6 PRINT "THE GAME IS PLAYED AS FOLLOWS:":PRINT */
line_6:;
    printf("%s", "THE GAME IS PLAYED AS FOLLOWS:"); printf("\n");
    printf("\n");
    /* BASIC: 7 PRINT "AT THE BEGINNING OF THE GAME, A RANDOM NUMBER OF CHIPS ARE" */
line_7:;
    printf("%s", "AT THE BEGINNING OF THE GAME, A RANDOM NUMBER OF CHIPS ARE"); printf("\n");
    /* BASIC: 8 PRINT "PLACED ON THE BOARD.  THE NUMBER OF CHIPS ALWAYS STARTS" */
line_8:;
    printf("%s", "PLACED ON THE BOARD.  THE NUMBER OF CHIPS ALWAYS STARTS"); printf("\n");
    /* BASIC: 9 PRINT "AS AN ODD NUMBER.  ON EACH TURN, A PLAYER MUST TAKE ONE," */
line_9:;
    printf("%s", "AS AN ODD NUMBER.  ON EACH TURN, A PLAYER MUST TAKE ONE,"); printf("\n");
    /* BASIC: 10 PRINT "TWO, THREE, OR FOUR CHIPS.  THE WINNER IS THE PLAYER WHO" */
line_10:;
    printf("%s", "TWO, THREE, OR FOUR CHIPS.  THE WINNER IS THE PLAYER WHO"); printf("\n");
    /* BASIC: 11 PRINT "FINISHES WITH A TOTAL NUMBER OF CHIPS THAT IS EVEN." */
line_11:;
    printf("%s", "FINISHES WITH A TOTAL NUMBER OF CHIPS THAT IS EVEN."); printf("\n");
    /* BASIC: 12 PRINT "THE COMPUTER STARTS OUT KNOWING ONLY THE RULES OF THE" */
line_12:;
    printf("%s", "THE COMPUTER STARTS OUT KNOWING ONLY THE RULES OF THE"); printf("\n");
    /* BASIC: 13 PRINT "GAME.  IT GRADUALLY LEARNS TO PLAY WELL.  IT SHOULD BE" */
line_13:;
    printf("%s", "GAME.  IT GRADUALLY LEARNS TO PLAY WELL.  IT SHOULD BE"); printf("\n");
    /* BASIC: 14 PRINT "DIFFICULT TO BEAT THE COMPUTER AFTER TWENTY GAMES IN A ROW." */
line_14:;
    printf("%s", "DIFFICULT TO BEAT THE COMPUTER AFTER TWENTY GAMES IN A ROW."); printf("\n");
    /* BASIC: 15 PRINT "TRY IT!!!!": PRINT */
line_15:;
    printf("%s", "TRY IT!!!!"); printf("\n");
    printf("\n");
    /* BASIC: 16 PRINT "TO QUIT AT ANY TIME, TYPE A '0' AS YOUR MOVE.": PRINT */
line_16:;
    printf("%s", "TO QUIT AT ANY TIME, TYPE A '0' AS YOUR MOVE."); printf("\n");
    printf("\n");
    /* BASIC: 20 DIM R(1,5) */
line_20:;
    /* DIM R(1,5) (handled statically) */
    /* BASIC: 25 L=0: B=0 */
line_25:;
    L = 0;
    B = 0;
    /* BASIC: 30 FOR I=0 TO 5 */
line_30:;
    I = 0; for_loop_I_30: if (((1) >= 0 && I > (5)) || ((1) < 0 && I < (5))) goto end_for_I_30;
    /* BASIC: 40 R(1,I)=4 */
line_40:;
    R_arr[(int)(1) * 100 + (int)(I)] = 4;
    /* BASIC: 50 R(0,I)=4 */
line_50:;
    R_arr[(int)(0) * 100 + (int)(I)] = 4;
    /* BASIC: 60 NEXT I */
line_60:;
    I += (1); goto for_loop_I_30; end_for_I_30:;
    /* BASIC: 70 A=0: B=0 */
line_70:;
    A = 0;
    B = 0;
    /* BASIC: 90 P=INT((13*RND(1)+9)/2)*2+1 */
line_90:;
    P = floor((13*((double)rand() / (double)RAND_MAX)+9)/2)*2+1;
    /* BASIC: 100 IF P=1 THEN 530 */
line_100:;
    if (P==1) { goto line_530; }
    /* BASIC: 110 PRINT "THERE ARE";P;"CHIPS ON THE BOARD." */
line_110:;
    printf("%s", "THERE ARE"); printf("%g ", (double)(P)); printf("%s", "CHIPS ON THE BOARD."); printf("\n");
    /* BASIC: 120 E1=E */
line_120:;
    E1 = E;
    /* BASIC: 130 L1=L */
line_130:;
    L1 = L;
    /* BASIC: 140 E=(A/2-INT(A/2))*2 */
line_140:;
    E = (A/2-floor(A/2))*2;
    /* BASIC: 150 L=INT((P/6-INT(P/6))*6+.5) */
line_150:;
    L = floor((P/6-floor(P/6))*6+.5);
    /* BASIC: 160 IF R(E,L)>=P THEN 320 */
line_160:;
    if (R_arr[(int)(E) * 100 + (int)(L)]>=P) { goto line_320; }
    /* BASIC: 170 M=R(E,L) */
line_170:;
    M = R_arr[(int)(E) * 100 + (int)(L)];
    /* BASIC: 180 IF M<=0 THEN 370 */
line_180:;
    if (M<=0) { goto line_370; }
    /* BASIC: 190 P=P-M */
line_190:;
    P = P-M;
    /* BASIC: 200 IF M=1 THEN 510 */
line_200:;
    if (M==1) { goto line_510; }
    /* BASIC: 210 PRINT "COMPUTER TAKES";M;"CHIPS LEAVING";P;"... YOUR MOVE"; */
line_210:;
    printf("%s", "COMPUTER TAKES"); printf("%g ", (double)(M)); printf("%s", "CHIPS LEAVING"); printf("%g ", (double)(P)); printf("%s", "... YOUR MOVE");
    /* BASIC: 220 B=B+M */
line_220:;
    B = B+M;
    /* BASIC: 230 INPUT M */
line_230:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &M);
    /* BASIC: 240 M=INT(M) */
line_240:;
    M = floor(M);
    /* BASIC: 250 IF M<1 THEN 450 */
line_250:;
    if (M<1) { goto line_450; }
    /* BASIC: 260 IF M>4 THEN 460 */
line_260:;
    if (M>4) { goto line_460; }
    /* BASIC: 270 IF M>P THEN 460 */
line_270:;
    if (M>P) { goto line_460; }
    /* BASIC: 280 IF M=P THEN 360 */
line_280:;
    if (M==P) { goto line_360; }
    /* BASIC: 290 P=P-M */
line_290:;
    P = P-M;
    /* BASIC: 300 A=A+M */
line_300:;
    A = A+M;
    /* BASIC: 310 GOTO 100 */
line_310:;
    goto line_100;
    /* BASIC: 320 IF P=1 THEN 550 */
line_320:;
    if (P==1) { goto line_550; }
    /* BASIC: 330 PRINT "COMPUTER TAKES";P;"CHIPS." */
line_330:;
    printf("%s", "COMPUTER TAKES"); printf("%g ", (double)(P)); printf("%s", "CHIPS."); printf("\n");
    /* BASIC: 340 R(E,L)=P */
line_340:;
    R_arr[(int)(E) * 100 + (int)(L)] = P;
    /* BASIC: 350 B=B+P */
line_350:;
    B = B+P;
    /* BASIC: 360 IF B/2=INT(B/2) THEN 420 */
line_360:;
    if (B/2==floor(B/2)) { goto line_420; }
    /* BASIC: 370 PRINT "GAME OVER ... YOU WIN!!!": PRINT */
line_370:;
    printf("%s", "GAME OVER ... YOU WIN!!!"); printf("\n");
    printf("\n");
    /* BASIC: 390 IF R(E,L)=1 THEN 480 */
line_390:;
    if (R_arr[(int)(E) * 100 + (int)(L)]==1) { goto line_480; }
    /* BASIC: 400 R(E,L)=R(E,L)-1 */
line_400:;
    R_arr[(int)(E) * 100 + (int)(L)] = R_arr[(int)(E) * 100 + (int)(L)]-1;
    /* BASIC: 410 GOTO 70 */
line_410:;
    goto line_70;
    /* BASIC: 420 PRINT "GAME OVER ... I WIN!!!": PRINT */
line_420:;
    printf("%s", "GAME OVER ... I WIN!!!"); printf("\n");
    printf("\n");
    /* BASIC: 430 GOTO 70 */
line_430:;
    goto line_70;
    /* BASIC: 450 IF M=0 THEN 570 */
line_450:;
    if (M==0) { goto line_570; }
    /* BASIC: 460 PRINT M;"IS AN ILLEGAL MOVE ... YOUR MOVE"; */
line_460:;
    printf("%g ", (double)(M)); printf("%s", "IS AN ILLEGAL MOVE ... YOUR MOVE");
    /* BASIC: 470 GOTO 230 */
line_470:;
    goto line_230;
    /* BASIC: 480 IF R(E1,L1)=1 THEN 70 */
line_480:;
    if (R_arr[(int)(E1) * 100 + (int)(L1)]==1) { goto line_70; }
    /* BASIC: 490 R(E1,L1)=R(E1,L1)-1 */
line_490:;
    R_arr[(int)(E1) * 100 + (int)(L1)] = R_arr[(int)(E1) * 100 + (int)(L1)]-1;
    /* BASIC: 500 GOTO 70 */
line_500:;
    goto line_70;
    /* BASIC: 510 PRINT "COMPUTER TAKES 1 CHIP LEAVING";P;"... YOUR MOVE"; */
line_510:;
    printf("%s", "COMPUTER TAKES 1 CHIP LEAVING"); printf("%g ", (double)(P)); printf("%s", "... YOUR MOVE");
    /* BASIC: 520 GOTO 220 */
line_520:;
    goto line_220;
    /* BASIC: 530 PRINT "THERE IS 1 CHIP ON THE BOARD." */
line_530:;
    printf("%s", "THERE IS 1 CHIP ON THE BOARD."); printf("\n");
    /* BASIC: 540 GOTO 120 */
line_540:;
    goto line_120;
    /* BASIC: 550 PRINT "COMPUTER TAKES 1 CHIP." */
line_550:;
    printf("%s", "COMPUTER TAKES 1 CHIP."); printf("\n");
    /* BASIC: 560 GOTO 340 */
line_560:;
    goto line_340;
    /* BASIC: 570 END */
line_570:;
    exit(0);

    return 0;
}
