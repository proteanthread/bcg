/*
 * Transpiled from awari.bas
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

static DataItem program_data[1] = {
    { DATA_NUM, { .num = 0.0 } },
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
static double A, B, C, D, E, F, G, H, I, J, K, L, M, N, P, Q, R;
static double B_arr[20000] = {0};
static double F_arr[20000] = {0};
static double G_arr[20000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 5 PRINT TAB(34);"AWARI" */
line_5:;
    { int _t; for(_t=0; _t<34; _t++) printf(" "); } printf("%s", "AWARI"); printf("\n");
    /* BASIC: 7 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_7:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 10 DATA 0 */
line_10:;
    /* UNTRANSLATED: DATA 0 */
    /* BASIC: 15 DIM B(13),G(13),F(50):READ N */
line_15:;
    /* DIM B(13),G(13),F(50) (handled statically) */
    read_numeric(&N);
    /* BASIC: 20 PRINT:PRINT:E=0 */
line_20:;
    printf("\n");
    printf("\n");
    E = 0;
    /* BASIC: 25 FOR I=0 TO 12:B(I)=3:NEXT I */
line_25:;
    I = 0; for_loop_I_25: if (((1) >= 0 && I > (12)) || ((1) < 0 && I < (12))) goto end_for_I_25;
    B_arr[(int)(I)] = 3;
    I += (1); goto for_loop_I_25; end_for_I_25:;
    /* BASIC: 30 C=0:F(N)=0:B(13)=0:B(6)=0 */
line_30:;
    C = 0;
    F_arr[(int)(N)] = 0;
    B_arr[(int)(13)] = 0;
    B_arr[(int)(6)] = 0;
    /* BASIC: 35 GOSUB 500 */
line_35:;
    gosub_stack[gosub_sp++] = 1; goto line_500; line_ret_1:;
    /* BASIC: 40 PRINT "YOUR MOVE";:GOSUB 110 */
line_40:;
    printf("%s", "YOUR MOVE");
    gosub_stack[gosub_sp++] = 2; goto line_110; line_ret_2:;
    /* BASIC: 45 IF E=0 THEN 80 */
line_45:;
    if (E==0) { goto line_80; }
    /* BASIC: 50 IF M=H THEN GOSUB 100 */
line_50:;
    if (M==H) { gosub_stack[gosub_sp++] = 3; goto line_100; line_ret_3:; }
    /* BASIC: 55 IF E=0 THEN 80 */
line_55:;
    if (E==0) { goto line_80; }
    /* BASIC: 60 PRINT "MY MOVE IS ";:GOSUB 800 */
line_60:;
    printf("%s", "MY MOVE IS ");
    gosub_stack[gosub_sp++] = 4; goto line_800; line_ret_4:;
    /* BASIC: 65 IF E=0 THEN 80 */
line_65:;
    if (E==0) { goto line_80; }
    /* BASIC: 70 IF M=H THEN PRINT ",";:GOSUB 800 */
line_70:;
    if (M==H) { printf("%s", ","); gosub_stack[gosub_sp++] = 5; goto line_800; line_ret_5:; }
    /* BASIC: 75 IF E>0 THEN 35 */
line_75:;
    if (E>0) { goto line_35; }
    /* BASIC: 80 PRINT:PRINT"GAME OVER" */
line_80:;
    printf("\n");
    printf("%s", "GAME OVER"); printf("\n");
    /* BASIC: 85 D=B(6)-B(13):IF D<0 THEN PRINT "I WIN BY";-D;"POINTS":GOTO 20 */
line_85:;
    D = B_arr[(int)(6)]-B_arr[(int)(13)];
    if (D<0) { printf("%s", "I WIN BY"); printf("%g ", (double)(-D)); printf("%s", "POINTS"); printf("\n"); }
    goto line_20;
    /* BASIC: 90 N=N+1:IF D=0 THEN PRINT "DRAWN GAME":GOTO 20 */
line_90:;
    N = N+1;
    if (D==0) { printf("%s", "DRAWN GAME"); printf("\n"); }
    goto line_20;
    /* BASIC: 95 PRINT "YOU WIN BY";D;"POINTS":GOTO 20 */
line_95:;
    printf("%s", "YOU WIN BY"); printf("%g ", (double)(D)); printf("%s", "POINTS"); printf("\n");
    goto line_20;
    /* BASIC: 100 PRINT "AGAIN"; */
line_100:;
    printf("%s", "AGAIN");
    /* BASIC: 110 INPUT M:IF M<7 THEN IF M>0 THEN M=M-1:GOTO 130 */
line_110:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &M);
    if (M<7) { if (M>0) { M = M-1; } }
    goto line_130;
    /* BASIC: 120 PRINT "ILLEGAL MOVE":GOTO 100 */
line_120:;
    printf("%s", "ILLEGAL MOVE"); printf("\n");
    goto line_100;
    /* BASIC: 130 IF B(M)=0 THEN 120 */
line_130:;
    if (B_arr[(int)(M)]==0) { goto line_120; }
    /* BASIC: 140 H=6:GOSUB 200 */
line_140:;
    H = 6;
    gosub_stack[gosub_sp++] = 6; goto line_200; line_ret_6:;
    /* BASIC: 150 GOTO 500 */
line_150:;
    goto line_500;
    /* BASIC: 200 K=M:GOSUB 600 */
line_200:;
    K = M;
    gosub_stack[gosub_sp++] = 7; goto line_600; line_ret_7:;
    /* BASIC: 205 E=0:IF K>6 THEN K=K-7 */
line_205:;
    E = 0;
    if (K>6) { K = K-7; }
    /* BASIC: 210 C=C+1:IF C<9 THEN F(N)=F(N)*6+K */
line_210:;
    C = C+1;
    if (C<9) { F_arr[(int)(N)] = F_arr[(int)(N)]*6+K; }
    /* BASIC: 215 FOR I=0 TO 5:IF B(I)<>0 THEN 230 */
line_215:;
    I = 0; for_loop_I_215: if (((1) >= 0 && I > (5)) || ((1) < 0 && I < (5))) goto end_for_I_215;
    if (B_arr[(int)(I)]!=0) { goto line_230; }
    /* BASIC: 220 NEXT I */
line_220:;
    I += (1); goto for_loop_I_215; end_for_I_215:;
    /* BASIC: 225 RETURN */
line_225:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 230 FOR I=7 TO 12:IF B(I)<>0 THEN E=1:RETURN */
line_230:;
    I = 7; for_loop_I_230: if (((1) >= 0 && I > (12)) || ((1) < 0 && I < (12))) goto end_for_I_230;
    if (B_arr[(int)(I)]!=0) { E = 1; }
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 235 GOTO 220 */
line_235:;
    goto line_220;
    /* BASIC: 500 PRINT:PRINT"   "; */
line_500:;
    printf("\n");
    printf("%s", "   ");
    /* BASIC: 505 FOR I=12 TO 7 STEP -1:GOSUB 580 */
line_505:;
    I = 12; for_loop_I_505: if (((-1) >= 0 && I > (7)) || ((-1) < 0 && I < (7))) goto end_for_I_505;
    gosub_stack[gosub_sp++] = 8; goto line_580; line_ret_8:;
    /* BASIC: 510 NEXT I */
line_510:;
    I += (-1); goto for_loop_I_505; end_for_I_505:;
    /* BASIC: 515 PRINT:I=13:GOSUB 580 */
line_515:;
    printf("\n");
    I = 13;
    gosub_stack[gosub_sp++] = 9; goto line_580; line_ret_9:;
    /* BASIC: 520 PRINT "                       ";:PRINT B(6):PRINT "   "; */
line_520:;
    printf("%s", "                       ");
    printf("%g ", (double)(B_arr[(int)(6)])); printf("\n");
    printf("%s", "   ");
    /* BASIC: 525 FOR I=0 TO 5:GOSUB 580 */
line_525:;
    I = 0; for_loop_I_525: if (((1) >= 0 && I > (5)) || ((1) < 0 && I < (5))) goto end_for_I_525;
    gosub_stack[gosub_sp++] = 10; goto line_580; line_ret_10:;
    /* BASIC: 530 NEXT I */
line_530:;
    I += (1); goto for_loop_I_525; end_for_I_525:;
    /* BASIC: 535 PRINT:PRINT:RETURN */
line_535:;
    printf("\n");
    printf("\n");
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 580 IF B(I)<10 THEN PRINT " "; */
line_580:;
    if (B_arr[(int)(I)]<10) { printf("%s", " "); }
    /* BASIC: 585 PRINT B(I);:RETURN */
line_585:;
    printf("%g ", (double)(B_arr[(int)(I)]));
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 600 P=B(M):B(M)=0 */
line_600:;
    P = B_arr[(int)(M)];
    B_arr[(int)(M)] = 0;
    /* BASIC: 605 FOR P=P TO 1 STEP -1:M=M+1:IF M>13 THEN M=M-14 */
line_605:;
    P = P; for_loop_P_605: if (((-1) >= 0 && P > (1)) || ((-1) < 0 && P < (1))) goto end_for_P_605;
    M = M+1;
    if (M>13) { M = M-14; }
    /* BASIC: 610 B(M)=B(M)+1:NEXT P */
line_610:;
    B_arr[(int)(M)] = B_arr[(int)(M)]+1;
    P += (-1); goto for_loop_P_605; end_for_P_605:;
    /* BASIC: 615 IF B(M)=1 THEN IF M<>6 THEN IF M<>13 THEN IF B(12-M)<>0 THEN 625 */
line_615:;
    if (B_arr[(int)(M)]==1) { if (M!=6) { if (M!=13) { if (B_arr[(int)(12-M)]!=0) { goto line_625; } } } }
    /* BASIC: 620 RETURN */
line_620:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 625 B(H)=B(H)+B(12-M)+1:B(M)=0:B(12-M)=0:RETURN */
line_625:;
    B_arr[(int)(H)] = B_arr[(int)(H)]+B_arr[(int)(12-M)]+1;
    B_arr[(int)(M)] = 0;
    B_arr[(int)(12-M)] = 0;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 800 D=-99:H=13 */
line_800:;
    D = -99;
    H = 13;
    /* BASIC: 805 FOR I=0 TO 13:G(I)=B(I):NEXT I */
line_805:;
    I = 0; for_loop_I_805: if (((1) >= 0 && I > (13)) || ((1) < 0 && I < (13))) goto end_for_I_805;
    G_arr[(int)(I)] = B_arr[(int)(I)];
    I += (1); goto for_loop_I_805; end_for_I_805:;
    /* BASIC: 810 FOR J=7 TO 12:IF B(J)=0 THEN 885 */
line_810:;
    J = 7; for_loop_J_810: if (((1) >= 0 && J > (12)) || ((1) < 0 && J < (12))) goto end_for_J_810;
    if (B_arr[(int)(J)]==0) { goto line_885; }
    /* BASIC: 815 G=0:M=J:GOSUB 600 */
line_815:;
    G = 0;
    M = J;
    gosub_stack[gosub_sp++] = 11; goto line_600; line_ret_11:;
    /* BASIC: 820 FOR I=0 TO 5:IF B(I)=0 THEN 845 */
line_820:;
    I = 0; for_loop_I_820: if (((1) >= 0 && I > (5)) || ((1) < 0 && I < (5))) goto end_for_I_820;
    if (B_arr[(int)(I)]==0) { goto line_845; }
    /* BASIC: 825 L=B(I)+I:R=0 */
line_825:;
    L = B_arr[(int)(I)]+I;
    R = 0;
    /* BASIC: 830 IF L>13 THEN L=L-14:R=1:GOTO 830 */
line_830:;
    if (L>13) { L = L-14; R = 1; goto line_830; }
    /* BASIC: 835 IF B(L)=0 THEN IF L<>6 THEN IF L<>13 THEN R=B(12-L)+R */
line_835:;
    if (B_arr[(int)(L)]==0) { if (L!=6) { if (L!=13) { R = B_arr[(int)(12-L)]+R; } } }
    /* BASIC: 840 IF R>Q THEN Q=R */
line_840:;
    if (R>Q) { Q = R; }
    /* BASIC: 845 NEXT I */
line_845:;
    I += (1); goto for_loop_I_820; end_for_I_820:;
    /* BASIC: 850 Q=B(13)-B(6)-Q:IF C>8 THEN 875 */
line_850:;
    Q = B_arr[(int)(13)]-B_arr[(int)(6)]-Q;
    if (C>8) { goto line_875; }
    /* BASIC: 855 K=J:IF K>6 THEN K=K-7 */
line_855:;
    K = J;
    if (K>6) { K = K-7; }
    /* BASIC: 860 FOR I=0 TO N-1:IF F(N)*6+K=INT(F(I)/6^(7-C)+.1) THEN Q=Q-2 */
line_860:;
    I = 0; for_loop_I_860: if (((1) >= 0 && I > (N-1)) || ((1) < 0 && I < (N-1))) goto end_for_I_860;
    if (F_arr[(int)(N)]*6+K==floor(F_arr[(int)(I)]/pow(6, (7-C))+.1)) { Q = Q-2; }
    /* BASIC: 870 NEXT I */
line_870:;
    I += (1); goto for_loop_I_860; end_for_I_860:;
    /* BASIC: 875 FOR I=0 TO 13:B(I)=G(I):NEXT I */
line_875:;
    I = 0; for_loop_I_875: if (((1) >= 0 && I > (13)) || ((1) < 0 && I < (13))) goto end_for_I_875;
    B_arr[(int)(I)] = G_arr[(int)(I)];
    I += (1); goto for_loop_I_875; end_for_I_875:;
    /* BASIC: 880 IF Q>=D THEN A=J:D=Q */
line_880:;
    if (Q>=D) { A = J; D = Q; }
    /* BASIC: 885 NEXT J */
line_885:;
    J += (1); goto for_loop_J_810; end_for_J_810:;
    /* BASIC: 890 M=A:PRINT CHR$(42+M);:GOTO 200 */
line_890:;
    M = A;
    printf("%s", basic_CHR(42+M));
    goto line_200;
    /* BASIC: 900 FOR I=0 TO N-1:PRINT B(I):NEXT I */
line_900:;
    I = 0; for_loop_I_900: if (((1) >= 0 && I > (N-1)) || ((1) < 0 && I < (N-1))) goto end_for_I_900;
    printf("%g ", (double)(B_arr[(int)(I)])); printf("\n");
    I += (1); goto for_loop_I_900; end_for_I_900:;
    /* BASIC: 999 END */
line_999:;
    exit(0);
    /* Undefined labels declared here to compile cleanly */
    end_for_I_230:;

    return 0;
}
