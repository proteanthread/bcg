/*
 * Transpiled from tictactoe2.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double THANK, M, MORRISTOWN, ME, P, MOVES, GAME, TURKEY, C, IS, H, J, NEW, MOVE, K, TOE, BOARD, COMPUTING, CREATIVE, JERSEY, THE, WIN, COMPUTER, WHERE, YOU, X, A, SQUARE, OCCUPIED, DRAW, IT, WANT, DO, THAT, BEAT, O, G, NUMBERED, TAC, THANKS, I, GOOD, Q, TIC;
    double S[1000] = {0}; /* Static array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 2 PRINT TAB(30);"TIC-TAC-TOE" */
line_2:
    { int _t; for(_t=0; _t<30; _t++) printf(" "); } printf("%s", "TIC-TAC-TOE"); printf("\n");
    /* BASIC: 4 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 6 PRINT:PRINT:PRINT */
line_6:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 8 PRINT "THE BOARD IS NUMBERED:" */
line_8:
    printf("%s", "THE BOARD IS NUMBERED:"); printf("\n");
    /* BASIC: 10 PRINT " 1  2  3" */
line_10:
    printf("%s", " 1  2  3"); printf("\n");
    /* BASIC: 12 PRINT " 4  5  6" */
line_12:
    printf("%s", " 4  5  6"); printf("\n");
    /* BASIC: 14 PRINT " 7  8  9" */
line_14:
    printf("%s", " 7  8  9"); printf("\n");
    /* BASIC: 16 PRINT:PRINT:PRINT */
line_16:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 20 DIM S(9) */
line_20:
    /* DIM S(9) (handled statically) */
    /* BASIC: 50 INPUT"DO YOU WANT 'X' OR 'O'";C$ */
line_50:
    printf("%s", "DO YOU WANT 'X' OR 'O'"); fgets(C_str, sizeof(C_str), stdin); C_str[strcspn(C_str, "\n")] = 0;
    /* BASIC: 55 IF C$="X"THEN 475 */
line_55:
    /* UNTRANSLATED: IF C$="X"THEN 475 */
    /* BASIC: 60 P$="O":Q$="X" */
line_60:
    strncpy(P_str, ""O"", sizeof(P_str)); /* String assign approx */
    strncpy(Q_str, ""X"", sizeof(Q_str)); /* String assign approx */
    /* BASIC: 100 G=-1:H=1:IF S(5)<>0 THEN 103 */
line_100:
    G = -1;
    H = 1;
    if (S(5)!=0) goto line_103;
    /* BASIC: 102 S(5)=-1:GOTO 195 */
line_102:
    S(5) = -1;
    goto line_195;
    /* BASIC: 103 IF S(5)<>1 THEN 106 */
line_103:
    if (S(5)!=1) goto line_106;
    /* BASIC: 104 IF S(1)<>0 THEN 110 */
line_104:
    if (S(1)!=0) goto line_110;
    /* BASIC: 105 S(1)=-1:GOTO 195 */
line_105:
    S(1) = -1;
    goto line_195;
    /* BASIC: 106 IF S(2)=1 AND S(1)=0 THEN 181 */
line_106:
    if (S(2)==1 && S(1)==0) goto line_181;
    /* BASIC: 107 IF S(4)=1 AND S(1)=0 THEN 181 */
line_107:
    if (S(4)==1 && S(1)==0) goto line_181;
    /* BASIC: 108 IF S(6)=1 AND S(9)=0 THEN 189 */
line_108:
    if (S(6)==1 && S(9)==0) goto line_189;
    /* BASIC: 109 IF S(8)=1 AND S(9)=0 THEN 189 */
line_109:
    if (S(8)==1 && S(9)==0) goto line_189;
    /* BASIC: 110 IF G=1 THEN 112 */
line_110:
    if (G==1) goto line_112;
    /* BASIC: 111 GOTO 118 */
line_111:
    goto line_118;
    /* BASIC: 112 J=3*INT((M-1)/3)+1 */
line_112:
    J = 3*floor((M-1)/3)+1;
    /* BASIC: 113 IF 3*INT((M-1)/3)+1=M THEN K=1 */
line_113:
    if (3*floor((M-1)/3)+1==M) { K = 1; }
    /* BASIC: 114 IF 3*INT((M-1)/3)+2=M THEN K=2 */
line_114:
    if (3*floor((M-1)/3)+2==M) { K = 2; }
    /* BASIC: 115 IF 3*INT((M-1)/3)+3=M THEN K=3 */
line_115:
    if (3*floor((M-1)/3)+3==M) { K = 3; }
    /* BASIC: 116 GOTO 120 */
line_116:
    goto line_120;
    /* BASIC: 118 FOR J=1 TO 7 STEP 3:FOR K=1 TO 3 */
line_118:
    J = 1; for_loop_J: if ((3 >= 0 && J > 7) || (3 < 0 && J < 7)) goto end_for_J;
    K = 1; for_loop_K: if ((1 >= 0 && K > 3) || (1 < 0 && K < 3)) goto end_for_K;
    /* BASIC: 120 IF S(J)<>G THEN 130 */
line_120:
    if (S(J)!=G) goto line_130;
    /* BASIC: 122 IF S(J+2)<>G THEN 135 */
line_122:
    if (S(J+2)!=G) goto line_135;
    /* BASIC: 126 IF S(J+1)<>0 THEN 150 */
line_126:
    if (S(J+1)!=0) goto line_150;
    /* BASIC: 128 S(J+1)=-1:GOTO 195 */
line_128:
    S(J+1) = -1;
    goto line_195;
    /* BASIC: 130 IF S(J)=H THEN 150 */
line_130:
    if (S(J)==H) goto line_150;
    /* BASIC: 131 IF S(J+2)<>G THEN 150 */
line_131:
    if (S(J+2)!=G) goto line_150;
    /* BASIC: 132 IF S(J+1)<>G THEN 150 */
line_132:
    if (S(J+1)!=G) goto line_150;
    /* BASIC: 133 S(J)=-1:GOTO 195 */
line_133:
    S(J) = -1;
    goto line_195;
    /* BASIC: 135 IF S(J+2)<>0 THEN 150 */
line_135:
    if (S(J+2)!=0) goto line_150;
    /* BASIC: 136 IF S(J+1)<>G THEN 150 */
line_136:
    if (S(J+1)!=G) goto line_150;
    /* BASIC: 138 S(J+2)=-1:GOTO 195 */
line_138:
    S(J+2) = -1;
    goto line_195;
    /* BASIC: 150 IF S(K)<>G THEN 160 */
line_150:
    if (S(K)!=G) goto line_160;
    /* BASIC: 152 IF S(K+6)<>G THEN 165 */
line_152:
    if (S(K+6)!=G) goto line_165;
    /* BASIC: 156 IF S(K+3)<>0 THEN 170 */
line_156:
    if (S(K+3)!=0) goto line_170;
    /* BASIC: 158 S(K+3)=-1:GOTO 195 */
line_158:
    S(K+3) = -1;
    goto line_195;
    /* BASIC: 160 IF S(K)=H THEN 170 */
line_160:
    if (S(K)==H) goto line_170;
    /* BASIC: 161 IF S(K+6)<>G THEN 170 */
line_161:
    if (S(K+6)!=G) goto line_170;
    /* BASIC: 162 IF S(K+3)<>G THEN 170 */
line_162:
    if (S(K+3)!=G) goto line_170;
    /* BASIC: 163 S(K)=-1:GOTO 195 */
line_163:
    S(K) = -1;
    goto line_195;
    /* BASIC: 165 IF S(K+6)<>0 THEN 170 */
line_165:
    if (S(K+6)!=0) goto line_170;
    /* BASIC: 166 IF S(K+3)<>G THEN 170 */
line_166:
    if (S(K+3)!=G) goto line_170;
    /* BASIC: 168 S(K+6)=-1:GOTO 195 */
line_168:
    S(K+6) = -1;
    goto line_195;
    /* BASIC: 170 GOTO 450 */
line_170:
    goto line_450;
    /* BASIC: 171 IF S(3)=G AND S(7)=0 THEN 187 */
line_171:
    if (S(3)==G && S(7)==0) goto line_187;
    /* BASIC: 172 IF S(9)=G AND S(1)=0 THEN 181 */
line_172:
    if (S(9)==G && S(1)==0) goto line_181;
    /* BASIC: 173 IF S(7)=G AND S(3)=0 THEN 183 */
line_173:
    if (S(7)==G && S(3)==0) goto line_183;
    /* BASIC: 174 IF S(9)=0 AND S(1)=G THEN 189 */
line_174:
    if (S(9)==0 && S(1)==G) goto line_189;
    /* BASIC: 175 IF G=-1 THEN G=1:H=-1:GOTO 110 */
line_175:
    if (G==-1) { G = 1; }
    H = -1;
    goto line_110;
    /* BASIC: 176 IF S(9)=1 AND S(3)=0 THEN 182 */
line_176:
    if (S(9)==1 && S(3)==0) goto line_182;
    /* BASIC: 177 FOR I=2 TO 9:IF S(I)<>0 THEN 179 */
line_177:
    I = 2; for_loop_I: if ((1 >= 0 && I > 9) || (1 < 0 && I < 9)) goto end_for_I;
    if (S(I)!=0) goto line_179;
    /* BASIC: 178 S(I)=-1:GOTO 195 */
line_178:
    S(I) = -1;
    goto line_195;
    /* BASIC: 179 NEXT I */
line_179:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 181 S(1)=-1:GOTO 195 */
line_181:
    S(1) = -1;
    goto line_195;
    /* BASIC: 182 IF S(1)=1 THEN 177 */
line_182:
    if (S(1)==1) goto line_177;
    /* BASIC: 183 S(3)=-1:GOTO 195 */
line_183:
    S(3) = -1;
    goto line_195;
    /* BASIC: 187 S(7)=-1:GOTO 195 */
line_187:
    S(7) = -1;
    goto line_195;
    /* BASIC: 189 S(9)=-1 */
line_189:
    S(9) = -1;
    /* BASIC: 195 PRINT:PRINT"THE COMPUTER MOVES TO..." */
line_195:
    printf("\n");
    printf("%s", "THE COMPUTER MOVES TO..."); printf("\n");
    /* BASIC: 202 GOSUB 1000 */
line_202:
    /* TODO: GOSUB 1000 */
    /* BASIC: 205 GOTO 500 */
line_205:
    goto line_500;
    /* BASIC: 450 IF G=1 THEN 465 */
line_450:
    if (G==1) goto line_465;
    /* BASIC: 455 IF J=7 AND K=3 THEN 465 */
line_455:
    if (J==7 && K==3) goto line_465;
    /* BASIC: 460 NEXT K,J */
line_460:
    /* TODO: NEXT (unmatched) */
    /* BASIC: 465 IF S(5)=G THEN 171 */
line_465:
    if (S(5)==G) goto line_171;
    /* BASIC: 467 GOTO 175 */
line_467:
    goto line_175;
    /* BASIC: 475 P$="X":Q$="O" */
line_475:
    strncpy(P_str, ""X"", sizeof(P_str)); /* String assign approx */
    strncpy(Q_str, ""O"", sizeof(Q_str)); /* String assign approx */
    /* BASIC: 500 PRINT:INPUT"WHERE DO YOU MOVE";M */
line_500:
    printf("\n");
    printf("%s", "WHERE DO YOU MOVE"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &M);
    /* BASIC: 502 IF M=0 THEN PRINT"THANKS FOR THE GAME.":GOTO 2000 */
line_502:
    if (M==0) { printf("%s", "THANKS FOR THE GAME."); printf("\n"); }
    goto line_2000;
    /* BASIC: 503 IF M>9 THEN 506 */
line_503:
    if (M>9) goto line_506;
    /* BASIC: 505 IF S(M)=0 THEN 510 */
line_505:
    if (S(M)==0) goto line_510;
    /* BASIC: 506 PRINT"THAT SQUARE IS OCCUPIED.":PRINT:PRINT:GOTO 500 */
line_506:
    printf("%s", "THAT SQUARE IS OCCUPIED."); printf("\n");
    printf("\n");
    printf("\n");
    goto line_500;
    /* BASIC: 510 G=1:S(M)=1 */
line_510:
    G = 1;
    S(M) = 1;
    /* BASIC: 520 GOSUB 1000 */
line_520:
    /* TODO: GOSUB 1000 */
    /* BASIC: 530 GOTO 100 */
line_530:
    goto line_100;
    /* BASIC: 1000 PRINT:FOR I=1 TO 9:PRINT" ";:IF S(I)<>-1 THEN 1014 */
line_1000:
    printf("\n");
    I = 1; for_loop_I: if ((1 >= 0 && I > 9) || (1 < 0 && I < 9)) goto end_for_I;
    printf("%s", " ");
    if (S(I)!=-1) goto line_1014;
    /* BASIC: 1012 PRINT Q$" ";:GOTO 1020 */
line_1012:
    printf("%g ", (double)(Q$" "));
    goto line_1020;
    /* BASIC: 1014 IF S(I)<>0 THEN 1018 */
line_1014:
    if (S(I)!=0) goto line_1018;
    /* BASIC: 1016 PRINT"  ";:GOTO 1020 */
line_1016:
    printf("%s", "  ");
    goto line_1020;
    /* BASIC: 1018 PRINT P$" "; */
line_1018:
    printf("%g ", (double)(P$" "));
    /* BASIC: 1020 IF I<>3 AND I<>6 THEN 1050 */
line_1020:
    if (I!=3 && I!=6) goto line_1050;
    /* BASIC: 1030 PRINT:PRINT"---+---+---" */
line_1030:
    printf("\n");
    printf("%s", "---+---+---"); printf("\n");
    /* BASIC: 1040 GOTO 1080 */
line_1040:
    goto line_1080;
    /* BASIC: 1050 IF I=9 THEN 1080 */
line_1050:
    if (I==9) goto line_1080;
    /* BASIC: 1060 PRINT"!"; */
line_1060:
    printf("%s", "!");
    /* BASIC: 1080 NEXT I:PRINT:PRINT:PRINT */
line_1080:
    I += 1; goto for_loop_I; end_for_I:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 1095 FOR I=1 TO 7 STEP 3 */
line_1095:
    I = 1; for_loop_I: if ((3 >= 0 && I > 7) || (3 < 0 && I < 7)) goto end_for_I;
    /* BASIC: 1100 IF S(I)<>S(I+1)THEN 1115 */
line_1100:
    /* UNTRANSLATED: IF S(I)<>S(I+1)THEN 1115 */
    /* BASIC: 1105 IF S(I)<>S(I+2)THEN 1115 */
line_1105:
    /* UNTRANSLATED: IF S(I)<>S(I+2)THEN 1115 */
    /* BASIC: 1110 IF S(I)=-1 THEN 1350 */
line_1110:
    if (S(I)==-1) goto line_1350;
    /* BASIC: 1112 IF S(I)=1 THEN 1200 */
line_1112:
    if (S(I)==1) goto line_1200;
    /* BASIC: 1115 NEXT I:FOR I=1 TO 3:IF S(I)<>S(I+3)THEN 1150 */
line_1115:
    I += 3; goto for_loop_I; end_for_I:;
    I = 1; for_loop_I: if ((1 >= 0 && I > 3) || (1 < 0 && I < 3)) goto end_for_I;
    /* UNTRANSLATED: IF S(I)<>S(I+3)THEN 1150 */
    /* BASIC: 1130 IF S(I)<>S(I+6)THEN 1150 */
line_1130:
    /* UNTRANSLATED: IF S(I)<>S(I+6)THEN 1150 */
    /* BASIC: 1135 IF S(I)=-1 THEN 1350 */
line_1135:
    if (S(I)==-1) goto line_1350;
    /* BASIC: 1137 IF S(I)=1 THEN 1200 */
line_1137:
    if (S(I)==1) goto line_1200;
    /* BASIC: 1150 NEXT I:FOR I=1 TO 9:IF S(I)=0 THEN 1155 */
line_1150:
    I += 1; goto for_loop_I; end_for_I:;
    I = 1; for_loop_I: if ((1 >= 0 && I > 9) || (1 < 0 && I < 9)) goto end_for_I;
    if (S(I)==0) goto line_1155;
    /* BASIC: 1152 NEXT I:GOTO 1400 */
line_1152:
    I += 1; goto for_loop_I; end_for_I:;
    goto line_1400;
    /* BASIC: 1155 IF S(5)<>G THEN 1170 */
line_1155:
    if (S(5)!=G) goto line_1170;
    /* BASIC: 1160 IF S(1)=G AND S(9)=G THEN 1180 */
line_1160:
    if (S(1)==G && S(9)==G) goto line_1180;
    /* BASIC: 1165 IF S(3)=G AND S(7)=G THEN 1180 */
line_1165:
    if (S(3)==G && S(7)==G) goto line_1180;
    /* BASIC: 1170 RETURN */
line_1170:
    /* TODO: RETURN */
    /* BASIC: 1180 IF G=-1 THEN 1350 */
line_1180:
    if (G==-1) goto line_1350;
    /* BASIC: 1200 PRINT"YOU BEAT ME!! GOOD GAME.":GOTO 2000 */
line_1200:
    printf("%s", "YOU BEAT ME!! GOOD GAME."); printf("\n");
    goto line_2000;
    /* BASIC: 1350 PRINT"I WIN, TURKEY!!!":GOTO 2000 */
line_1350:
    printf("%s", "I WIN, TURKEY!!!"); printf("\n");
    goto line_2000;
    /* BASIC: 1400 PRINT"IT'S A DRAW. THANK YOU." */
line_1400:
    printf("%s", "IT'S A DRAW. THANK YOU."); printf("\n");
    /* BASIC: 2000 END */
line_2000:
    exit(0);

    return 0;
}
