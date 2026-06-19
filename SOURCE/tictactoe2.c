/*
 * Transpiled from tictactoe2.bas
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
static int gosub_stack[256];
static int gosub_sp = 0;
static double G, H, I, J, K, M, S;
static char C_str[256] = {0};
static char P_str[256] = {0};
static char Q_str[256] = {0};
static double S_arr[20000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 2 PRINT TAB(30);"TIC-TAC-TOE" */
line_2:;
    { int _t; for(_t=0; _t<30; _t++) printf(" "); } printf("%s", "TIC-TAC-TOE"); printf("\n");
    /* BASIC: 4 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 6 PRINT:PRINT:PRINT */
line_6:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 8 PRINT "THE BOARD IS NUMBERED:" */
line_8:;
    printf("%s", "THE BOARD IS NUMBERED:"); printf("\n");
    /* BASIC: 10 PRINT " 1  2  3" */
line_10:;
    printf("%s", " 1  2  3"); printf("\n");
    /* BASIC: 12 PRINT " 4  5  6" */
line_12:;
    printf("%s", " 4  5  6"); printf("\n");
    /* BASIC: 14 PRINT " 7  8  9" */
line_14:;
    printf("%s", " 7  8  9"); printf("\n");
    /* BASIC: 16 PRINT:PRINT:PRINT */
line_16:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 20 DIM S(9) */
line_20:;
    /* DIM S(9) (handled statically) */
    /* BASIC: 50 INPUT"DO YOU WANT 'X' OR 'O'";C$ */
line_50:;
    printf("%s", "DO YOU WANT 'X' OR 'O'"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", C_str);
    /* BASIC: 55 IF C$="X" THEN 475 */
line_55:;
    if (strcmp(C_str, "X") == 0) { goto line_475; }
    /* BASIC: 60 P$="O":Q$="X" */
line_60:;
    str_assign(P_str, sizeof(P_str), "O");
    str_assign(Q_str, sizeof(Q_str), "X");
    /* BASIC: 100 G=-1:H=1:IF S(5)<>0 THEN 103 */
line_100:;
    G = -1;
    H = 1;
    if (S_arr[(int)(5)]!=0) { goto line_103; }
    /* BASIC: 102 S(5)=-1:GOTO 195 */
line_102:;
    S_arr[(int)(5)] = -1;
    goto line_195;
    /* BASIC: 103 IF S(5)<>1 THEN 106 */
line_103:;
    if (S_arr[(int)(5)]!=1) { goto line_106; }
    /* BASIC: 104 IF S(1)<>0 THEN 110 */
line_104:;
    if (S_arr[(int)(1)]!=0) { goto line_110; }
    /* BASIC: 105 S(1)=-1:GOTO 195 */
line_105:;
    S_arr[(int)(1)] = -1;
    goto line_195;
    /* BASIC: 106 IF S(2)=1 AND S(1)=0 THEN 181 */
line_106:;
    if (S_arr[(int)(2)]==1   &&   S_arr[(int)(1)]==0) { goto line_181; }
    /* BASIC: 107 IF S(4)=1 AND S(1)=0 THEN 181 */
line_107:;
    if (S_arr[(int)(4)]==1   &&   S_arr[(int)(1)]==0) { goto line_181; }
    /* BASIC: 108 IF S(6)=1 AND S(9)=0 THEN 189 */
line_108:;
    if (S_arr[(int)(6)]==1   &&   S_arr[(int)(9)]==0) { goto line_189; }
    /* BASIC: 109 IF S(8)=1 AND S(9)=0 THEN 189 */
line_109:;
    if (S_arr[(int)(8)]==1   &&   S_arr[(int)(9)]==0) { goto line_189; }
    /* BASIC: 110 IF G=1 THEN 112 */
line_110:;
    if (G==1) { goto line_112; }
    /* BASIC: 111 GOTO 118 */
line_111:;
    goto line_118;
    /* BASIC: 112 J=3*INT((M-1)/3)+1 */
line_112:;
    J = 3*floor((M-1)/3)+1;
    /* BASIC: 113 IF 3*INT((M-1)/3)+1=M THEN K=1 */
line_113:;
    if (3*floor((M-1)/3)+1==M) { K = 1; }
    /* BASIC: 114 IF 3*INT((M-1)/3)+2=M THEN K=2 */
line_114:;
    if (3*floor((M-1)/3)+2==M) { K = 2; }
    /* BASIC: 115 IF 3*INT((M-1)/3)+3=M THEN K=3 */
line_115:;
    if (3*floor((M-1)/3)+3==M) { K = 3; }
    /* BASIC: 116 GOTO 120 */
line_116:;
    goto line_120;
    /* BASIC: 118 FOR J=1 TO 7 STEP 3:FOR K=1 TO 3 */
line_118:;
    J = 1; for_loop_J_118: if (((3) >= 0 && J > (7)) || ((3) < 0 && J < (7))) goto end_for_J_118;
    K = 1; for_loop_K_118: if (((1) >= 0 && K > (3)) || ((1) < 0 && K < (3))) goto end_for_K_118;
    /* BASIC: 120 IF S(J)<>G THEN 130 */
line_120:;
    if (S_arr[(int)(J)]!=G) { goto line_130; }
    /* BASIC: 122 IF S(J+2)<>G THEN 135 */
line_122:;
    if (S_arr[(int)(J+2)]!=G) { goto line_135; }
    /* BASIC: 126 IF S(J+1)<>0 THEN 150 */
line_126:;
    if (S_arr[(int)(J+1)]!=0) { goto line_150; }
    /* BASIC: 128 S(J+1)=-1:GOTO 195 */
line_128:;
    S_arr[(int)(J+1)] = -1;
    goto line_195;
    /* BASIC: 130 IF S(J)=H THEN 150 */
line_130:;
    if (S_arr[(int)(J)]==H) { goto line_150; }
    /* BASIC: 131 IF S(J+2)<>G THEN 150 */
line_131:;
    if (S_arr[(int)(J+2)]!=G) { goto line_150; }
    /* BASIC: 132 IF S(J+1)<>G THEN 150 */
line_132:;
    if (S_arr[(int)(J+1)]!=G) { goto line_150; }
    /* BASIC: 133 S(J)=-1:GOTO 195 */
line_133:;
    S_arr[(int)(J)] = -1;
    goto line_195;
    /* BASIC: 135 IF S(J+2)<>0 THEN 150 */
line_135:;
    if (S_arr[(int)(J+2)]!=0) { goto line_150; }
    /* BASIC: 136 IF S(J+1)<>G THEN 150 */
line_136:;
    if (S_arr[(int)(J+1)]!=G) { goto line_150; }
    /* BASIC: 138 S(J+2)=-1:GOTO 195 */
line_138:;
    S_arr[(int)(J+2)] = -1;
    goto line_195;
    /* BASIC: 150 IF S(K)<>G THEN 160 */
line_150:;
    if (S_arr[(int)(K)]!=G) { goto line_160; }
    /* BASIC: 152 IF S(K+6)<>G THEN 165 */
line_152:;
    if (S_arr[(int)(K+6)]!=G) { goto line_165; }
    /* BASIC: 156 IF S(K+3)<>0 THEN 170 */
line_156:;
    if (S_arr[(int)(K+3)]!=0) { goto line_170; }
    /* BASIC: 158 S(K+3)=-1:GOTO 195 */
line_158:;
    S_arr[(int)(K+3)] = -1;
    goto line_195;
    /* BASIC: 160 IF S(K)=H THEN 170 */
line_160:;
    if (S_arr[(int)(K)]==H) { goto line_170; }
    /* BASIC: 161 IF S(K+6)<>G THEN 170 */
line_161:;
    if (S_arr[(int)(K+6)]!=G) { goto line_170; }
    /* BASIC: 162 IF S(K+3)<>G THEN 170 */
line_162:;
    if (S_arr[(int)(K+3)]!=G) { goto line_170; }
    /* BASIC: 163 S(K)=-1:GOTO 195 */
line_163:;
    S_arr[(int)(K)] = -1;
    goto line_195;
    /* BASIC: 165 IF S(K+6)<>0 THEN 170 */
line_165:;
    if (S_arr[(int)(K+6)]!=0) { goto line_170; }
    /* BASIC: 166 IF S(K+3)<>G THEN 170 */
line_166:;
    if (S_arr[(int)(K+3)]!=G) { goto line_170; }
    /* BASIC: 168 S(K+6)=-1:GOTO 195 */
line_168:;
    S_arr[(int)(K+6)] = -1;
    goto line_195;
    /* BASIC: 170 GOTO 450 */
line_170:;
    goto line_450;
    /* BASIC: 171 IF S(3)=G AND S(7)=0 THEN 187 */
line_171:;
    if (S_arr[(int)(3)]==G   &&   S_arr[(int)(7)]==0) { goto line_187; }
    /* BASIC: 172 IF S(9)=G AND S(1)=0 THEN 181 */
line_172:;
    if (S_arr[(int)(9)]==G   &&   S_arr[(int)(1)]==0) { goto line_181; }
    /* BASIC: 173 IF S(7)=G AND S(3)=0 THEN 183 */
line_173:;
    if (S_arr[(int)(7)]==G   &&   S_arr[(int)(3)]==0) { goto line_183; }
    /* BASIC: 174 IF S(9)=0 AND S(1)=G THEN 189 */
line_174:;
    if (S_arr[(int)(9)]==0   &&   S_arr[(int)(1)]==G) { goto line_189; }
    /* BASIC: 175 IF G=-1 THEN G=1:H=-1:GOTO 110 */
line_175:;
    if (G==-1) { G = 1; H = -1; goto line_110; }
    /* BASIC: 176 IF S(9)=1 AND S(3)=0 THEN 182 */
line_176:;
    if (S_arr[(int)(9)]==1   &&   S_arr[(int)(3)]==0) { goto line_182; }
    /* BASIC: 177 FOR I=2 TO 9:IF S(I)<>0 THEN 179 */
line_177:;
    I = 2; for_loop_I_177: if (((1) >= 0 && I > (9)) || ((1) < 0 && I < (9))) goto end_for_I_177;
    if (S_arr[(int)(I)]!=0) { goto line_179; }
    /* BASIC: 178 S(I)=-1:GOTO 195 */
line_178:;
    S_arr[(int)(I)] = -1;
    goto line_195;
    /* BASIC: 179 NEXT I */
line_179:;
    I += (1); goto for_loop_I_177; end_for_I_177:;
    /* BASIC: 181 S(1)=-1:GOTO 195 */
line_181:;
    S_arr[(int)(1)] = -1;
    goto line_195;
    /* BASIC: 182 IF S(1)=1 THEN 177 */
line_182:;
    if (S_arr[(int)(1)]==1) { goto line_177; }
    /* BASIC: 183 S(3)=-1:GOTO 195 */
line_183:;
    S_arr[(int)(3)] = -1;
    goto line_195;
    /* BASIC: 187 S(7)=-1:GOTO 195 */
line_187:;
    S_arr[(int)(7)] = -1;
    goto line_195;
    /* BASIC: 189 S(9)=-1 */
line_189:;
    S_arr[(int)(9)] = -1;
    /* BASIC: 195 PRINT:PRINT"THE COMPUTER MOVES TO..." */
line_195:;
    printf("\n");
    printf("%s", "THE COMPUTER MOVES TO..."); printf("\n");
    /* BASIC: 202 GOSUB 1000 */
line_202:;
    gosub_stack[gosub_sp++] = 1; goto line_1000; line_ret_1:;
    /* BASIC: 205 GOTO 500 */
line_205:;
    goto line_500;
    /* BASIC: 450 IF G=1 THEN 465 */
line_450:;
    if (G==1) { goto line_465; }
    /* BASIC: 455 IF J=7 AND K=3 THEN 465 */
line_455:;
    if (J==7   &&   K==3) { goto line_465; }
    /* BASIC: 460 NEXT K,J */
line_460:;
    /* NEXT (unmatched) */
    /* BASIC: 465 IF S(5)=G THEN 171 */
line_465:;
    if (S_arr[(int)(5)]==G) { goto line_171; }
    /* BASIC: 467 GOTO 175 */
line_467:;
    goto line_175;
    /* BASIC: 475 P$="X":Q$="O" */
line_475:;
    str_assign(P_str, sizeof(P_str), "X");
    str_assign(Q_str, sizeof(Q_str), "O");
    /* BASIC: 500 PRINT:INPUT"WHERE DO YOU MOVE";M */
line_500:;
    printf("\n");
    printf("%s", "WHERE DO YOU MOVE"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &M);
    /* BASIC: 502 IF M=0 THEN PRINT"THANKS FOR THE GAME.":GOTO 2000 */
line_502:;
    if (M==0) { printf("%s", "THANKS FOR THE GAME."); printf("\n"); goto line_2000; }
    /* BASIC: 503 IF M>9 THEN 506 */
line_503:;
    if (M>9) { goto line_506; }
    /* BASIC: 505 IF S(M)=0 THEN 510 */
line_505:;
    if (S_arr[(int)(M)]==0) { goto line_510; }
    /* BASIC: 506 PRINT"THAT SQUARE IS OCCUPIED.":PRINT:PRINT:GOTO 500 */
line_506:;
    printf("%s", "THAT SQUARE IS OCCUPIED."); printf("\n");
    printf("\n");
    printf("\n");
    goto line_500;
    /* BASIC: 510 G=1:S(M)=1 */
line_510:;
    G = 1;
    S_arr[(int)(M)] = 1;
    /* BASIC: 520 GOSUB 1000 */
line_520:;
    gosub_stack[gosub_sp++] = 2; goto line_1000; line_ret_2:;
    /* BASIC: 530 GOTO 100 */
line_530:;
    goto line_100;
    /* BASIC: 1000 PRINT:FOR I=1 TO 9:PRINT" ";:IF S(I)<>-1 THEN 1014 */
line_1000:;
    printf("\n");
    I = 1; for_loop_I_1000: if (((1) >= 0 && I > (9)) || ((1) < 0 && I < (9))) goto end_for_I_1000;
    printf("%s", " ");
    if (S_arr[(int)(I)]!=-1) { goto line_1014; }
    /* BASIC: 1012 PRINT Q$" ";:GOTO 1020 */
line_1012:;
    printf("%s", Q_str); printf("%s", " ");
    goto line_1020;
    /* BASIC: 1014 IF S(I)<>0 THEN 1018 */
line_1014:;
    if (S_arr[(int)(I)]!=0) { goto line_1018; }
    /* BASIC: 1016 PRINT"  ";:GOTO 1020 */
line_1016:;
    printf("%s", "  ");
    goto line_1020;
    /* BASIC: 1018 PRINT P$" "; */
line_1018:;
    printf("%s", P_str); printf("%s", " ");
    /* BASIC: 1020 IF I<>3 AND I<>6 THEN 1050 */
line_1020:;
    if (I!=3   &&   I!=6) { goto line_1050; }
    /* BASIC: 1030 PRINT:PRINT"---+---+---" */
line_1030:;
    printf("\n");
    printf("%s", "---+---+---"); printf("\n");
    /* BASIC: 1040 GOTO 1080 */
line_1040:;
    goto line_1080;
    /* BASIC: 1050 IF I=9 THEN 1080 */
line_1050:;
    if (I==9) { goto line_1080; }
    /* BASIC: 1060 PRINT"!"; */
line_1060:;
    printf("%s", "!");
    /* BASIC: 1080 NEXT I:PRINT:PRINT:PRINT */
line_1080:;
    I += (1); goto for_loop_I_1000; end_for_I_1000:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 1095 FOR I=1 TO 7 STEP 3 */
line_1095:;
    I = 1; for_loop_I_1095: if (((3) >= 0 && I > (7)) || ((3) < 0 && I < (7))) goto end_for_I_1095;
    /* BASIC: 1100 IF S(I)<>S(I+1) THEN 1115 */
line_1100:;
    if (S_arr[(int)(I)]!=S_arr[(int)(I+1)]) { goto line_1115; }
    /* BASIC: 1105 IF S(I)<>S(I+2) THEN 1115 */
line_1105:;
    if (S_arr[(int)(I)]!=S_arr[(int)(I+2)]) { goto line_1115; }
    /* BASIC: 1110 IF S(I)=-1 THEN 1350 */
line_1110:;
    if (S_arr[(int)(I)]==-1) { goto line_1350; }
    /* BASIC: 1112 IF S(I)=1 THEN 1200 */
line_1112:;
    if (S_arr[(int)(I)]==1) { goto line_1200; }
    /* BASIC: 1115 NEXT I:FOR I=1 TO 3:IF S(I)<>S(I+3) THEN 1150 */
line_1115:;
    I += (3); goto for_loop_I_1095; end_for_I_1095:;
    I = 1; for_loop_I_1115: if (((1) >= 0 && I > (3)) || ((1) < 0 && I < (3))) goto end_for_I_1115;
    if (S_arr[(int)(I)]!=S_arr[(int)(I+3)]) { goto line_1150; }
    /* BASIC: 1130 IF S(I)<>S(I+6) THEN 1150 */
line_1130:;
    if (S_arr[(int)(I)]!=S_arr[(int)(I+6)]) { goto line_1150; }
    /* BASIC: 1135 IF S(I)=-1 THEN 1350 */
line_1135:;
    if (S_arr[(int)(I)]==-1) { goto line_1350; }
    /* BASIC: 1137 IF S(I)=1 THEN 1200 */
line_1137:;
    if (S_arr[(int)(I)]==1) { goto line_1200; }
    /* BASIC: 1150 NEXT I:FOR I=1 TO 9:IF S(I)=0 THEN 1155 */
line_1150:;
    I += (1); goto for_loop_I_1115; end_for_I_1115:;
    I = 1; for_loop_I_1150: if (((1) >= 0 && I > (9)) || ((1) < 0 && I < (9))) goto end_for_I_1150;
    if (S_arr[(int)(I)]==0) { goto line_1155; }
    /* BASIC: 1152 NEXT I:GOTO 1400 */
line_1152:;
    I += (1); goto for_loop_I_1150; end_for_I_1150:;
    goto line_1400;
    /* BASIC: 1155 IF S(5)<>G THEN 1170 */
line_1155:;
    if (S_arr[(int)(5)]!=G) { goto line_1170; }
    /* BASIC: 1160 IF S(1)=G AND S(9)=G THEN 1180 */
line_1160:;
    if (S_arr[(int)(1)]==G   &&   S_arr[(int)(9)]==G) { goto line_1180; }
    /* BASIC: 1165 IF S(3)=G AND S(7)=G THEN 1180 */
line_1165:;
    if (S_arr[(int)(3)]==G   &&   S_arr[(int)(7)]==G) { goto line_1180; }
    /* BASIC: 1170 RETURN */
line_1170:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1180 IF G=-1 THEN 1350 */
line_1180:;
    if (G==-1) { goto line_1350; }
    /* BASIC: 1200 PRINT"YOU BEAT ME!! GOOD GAME.":GOTO 2000 */
line_1200:;
    printf("%s", "YOU BEAT ME!! GOOD GAME."); printf("\n");
    goto line_2000;
    /* BASIC: 1350 PRINT"I WIN, TURKEY!!!":GOTO 2000 */
line_1350:;
    printf("%s", "I WIN, TURKEY!!!"); printf("\n");
    goto line_2000;
    /* BASIC: 1400 PRINT"IT'S A DRAW. THANK YOU." */
line_1400:;
    printf("%s", "IT'S A DRAW. THANK YOU."); printf("\n");
    /* BASIC: 2000 END */
line_2000:;
    exit(0);
    /* Undefined labels declared here to compile cleanly */
    end_for_J_118:;
    end_for_K_118:;

    return 0;
}
