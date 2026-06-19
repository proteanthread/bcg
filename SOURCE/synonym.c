/*
 * Transpiled from synonym.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double MEANS, SMALL, READ, WORD, PRESS, HURT, N2, J, NEW, TYPE, PAIN, DOMICILE, STAY, PROD, N1, JERSEY, THE, TINY, HALT, ACHE, A, DISTRESS, RIGHT, PIT, LIKE, NEARLY, T, LITTLE, IN, SYNONYM, FLAME, CORRECT, DRILL, SUFFERING, MORRISTOWN, DATA, THRUST, START, CRIMSON, INSIGNIFICANT, RESIDENCE, CRITERION, POKE, TRY, WHAT, SCARLET, LANGUAGE, G1, RESTORE, RED, RUBY, I, RESEMBLING, SIMILAR, WELL, SHOVE, MISERY, HAS, VERY, BUTT, ARREST, INITIAL, MINUTE, W, IS, K, GULF, OF, HABITATION, SAME, WILL, CREATIVE, HOUSE, THINK, BEGINNING, YOU, ROUGE, HOLLOW, ANOTHER, DWELLING, G, GOOD, CHOOSE, C, LODGING, STANDARD, ONSET, CHASM, TELL, CAN, ENGLISH, WHICH, MODEL, COMPUTING, HELP, DISCOMFORT, MEANING, PATTERN, COMPLETED, PUSH, L, ALIKE, HOLE, ABYSS, AGAIN, FIRST, R, PROTOTYPE, STANDSTILL, N, FINE, CHECK;
    char R_str[1000][256] = {0}; /* Static string array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 2 PRINT TAB(33);"SYNONYM" */
line_2:
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "SYNONYM"); printf("\n");
    /* BASIC: 4 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 6 PRINT: PRINT: PRINT */
line_6:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 10 DIM R$(5),W$(10),L(30),R(30) */
line_10:
    /* DIM R$(5),W$(10),L(30),R(30) (handled statically) */
    /* BASIC: 20 R$(1)="RIGHT": R$(2)="CORRECT": R$(3)="FINE": R$(4)="GOOD!" */
line_20:
    R$(1) = "RIGHT";
    R$(2) = "CORRECT";
    R$(3) = "FINE";
    R$(4) = "GOOD!";
    /* BASIC: 30 R$(5)="CHECK" */
line_30:
    R$(5) = "CHECK";
    /* BASIC: 70 C=0 */
line_70:
    C = 0;
    /* BASIC: 90 PRINT "A SYNONYM OF A WORD MEANS ANOTHER WORD IN THE ENGLISH" */
line_90:
    printf("%s", "A SYNONYM OF A WORD MEANS ANOTHER WORD IN THE ENGLISH"); printf("\n");
    /* BASIC: 100 PRINT "LANGUAGE WHICH HAS THE SAME OR VERY NEARLY THE SAME"; */
line_100:
    printf("%s", "LANGUAGE WHICH HAS THE SAME OR VERY NEARLY THE SAME");
    /* BASIC: 110 PRINT " MEANING." */
line_110:
    printf("%s", " MEANING."); printf("\n");
    /* BASIC: 130 PRINT "I CHOOSE A WORD -- YOU TYPE A SYNONYM." */
line_130:
    printf("%s", "I CHOOSE A WORD -- YOU TYPE A SYNONYM."); printf("\n");
    /* BASIC: 140 PRINT "IF YOU CAN'T THINK OF A SYNONYM, TYPE THE WORD 'HELP'" */
line_140:
    printf("%s", "IF YOU CAN'T THINK OF A SYNONYM, TYPE THE WORD 'HELP'"); printf("\n");
    /* BASIC: 145 PRINT "AND I WILL TELL YOU A SYNONYM.": PRINT */
line_145:
    printf("%s", "AND I WILL TELL YOU A SYNONYM."); printf("\n");
    printf("\n");
    /* BASIC: 150 RESTORE: C=C+1: READ N */
line_150:
    /* UNTRANSLATED: RESTORE */
    C = C+1;
    /* UNTRANSLATED: READ N */
    /* BASIC: 160 IF C>N THEN 420 */
line_160:
    if (C>N) goto line_420;
    /* BASIC: 170 N1=INT(RND(1)*N+1) */
line_170:
    N1 = floor(((double)rand() / (double)RAND_MAX)*N+1);
    /* BASIC: 174 IF R(N1)=1 THEN 170 */
line_174:
    if (R(N1)==1) goto line_170;
    /* BASIC: 176 R(N1)=1 */
line_176:
    R(N1) = 1;
    /* BASIC: 180 FOR I=1 TO N1 */
line_180:
    I = 1; for_loop_I: if ((1 >= 0 && I > N1) || (1 < 0 && I < N1)) goto end_for_I;
    /* BASIC: 190 READ N2 */
line_190:
    /* UNTRANSLATED: READ N2 */
    /* BASIC: 200 FOR J=1 TO N2 */
line_200:
    J = 1; for_loop_J: if ((1 >= 0 && J > N2) || (1 < 0 && J < N2)) goto end_for_J;
    /* BASIC: 210 READ W$(J) */
line_210:
    /* UNTRANSLATED: READ W$(J) */
    /* BASIC: 220 NEXT J */
line_220:
    J += 1; goto for_loop_J; end_for_J:;
    /* BASIC: 230 NEXT I */
line_230:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 232 FOR J=1 TO N2: L(J)=J: NEXT J */
line_232:
    J = 1; for_loop_J: if ((1 >= 0 && J > N2) || (1 < 0 && J < N2)) goto end_for_J;
    L(J) = J;
    J += 1; goto for_loop_J; end_for_J:;
    /* BASIC: 235 L(0)=N2: G=1: PRINT */
line_235:
    L(0) = N2;
    G = 1;
    printf("\n");
    /* BASIC: 237 L(G)=L(L(0)): L(0)=N2-1: PRINT */
line_237:
    L(G) = L(L(0));
    L(0) = N2-1;
    printf("\n");
    /* BASIC: 240 PRINT "     WHAT IS A SYNONYM OF ";W$(G);: INPUT A$ */
line_240:
    printf("%s", "     WHAT IS A SYNONYM OF "); printf("%g ", (double)(W$(G)));
    printf("? "); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    /* BASIC: 250 IF A$="HELP" THEN 340 */
line_250:
    if (A$=="HELP") goto line_340;
    /* BASIC: 260 FOR K=1 TO N2 */
line_260:
    K = 1; for_loop_K: if ((1 >= 0 && K > N2) || (1 < 0 && K < N2)) goto end_for_K;
    /* BASIC: 270 IF G=K THEN 290 */
line_270:
    if (G==K) goto line_290;
    /* BASIC: 280 IF A$=W$(K) THEN 320 */
line_280:
    if (A$==W$(K)) goto line_320;
    /* BASIC: 290 NEXT K */
line_290:
    K += 1; goto for_loop_K; end_for_K:;
    /* BASIC: 300 PRINT "     TRY AGAIN.": GOTO 240 */
line_300:
    printf("%s", "     TRY AGAIN."); printf("\n");
    goto line_240;
    /* BASIC: 320 PRINT R$(INT(RND(1)*5+1)): GOTO 150 */
line_320:
    printf("%g ", (double)(R$(floor(((double)rand() / (double)RAND_MAX)*5+1)))); printf("\n");
    goto line_150;
    /* BASIC: 340 G1=INT(RND(1)*L(0)+1) */
line_340:
    G1 = floor(((double)rand() / (double)RAND_MAX)*L(0)+1);
    /* BASIC: 360 PRINT "**** A SYNONYM OF ";W$(G);" IS ";W$(L(G1));".": PRINT */
line_360:
    printf("%s", "**** A SYNONYM OF "); printf("%g ", (double)(W$(G))); printf("%s", " IS "); printf("%g ", (double)(W$(L(G1)))); printf("%s", "."); printf("\n");
    printf("\n");
    /* BASIC: 370 L(G1)=L(L(0)): L(0)=L(0)-1: GOTO 240 */
line_370:
    L(G1) = L(L(0));
    L(0) = L(0)-1;
    goto line_240;
    /* BASIC: 420 PRINT: PRINT "SYNONYM DRILL COMPLETED.": GOTO 999 */
line_420:
    printf("\n");
    printf("%s", "SYNONYM DRILL COMPLETED."); printf("\n");
    goto line_999;
    /* BASIC: 500 DATA 10 */
line_500:
    /* UNTRANSLATED: DATA 10 */
    /* BASIC: 510 DATA 5,"FIRST","START","BEGINNING","ONSET","INITIAL" */
line_510:
    /* UNTRANSLATED: DATA 5,"FIRST","START","BEGINNING","ONSET","INITIAL" */
    /* BASIC: 520 DATA 5,"SIMILAR","ALIKE","SAME","LIKE","RESEMBLING" */
line_520:
    /* UNTRANSLATED: DATA 5,"SIMILAR","ALIKE","SAME","LIKE","RESEMBLING" */
    /* BASIC: 530 DATA 5,"MODEL","PATTERN","PROTOTYPE","STANDARD","CRITERION" */
line_530:
    /* UNTRANSLATED: DATA 5,"MODEL","PATTERN","PROTOTYPE","STANDARD","CRITERION" */
    /* BASIC: 540 DATA 5,"SMALL","INSIGNIFICANT","LITTLE","TINY","MINUTE" */
line_540:
    /* UNTRANSLATED: DATA 5,"SMALL","INSIGNIFICANT","LITTLE","TINY","MINUTE" */
    /* BASIC: 550 DATA 6,"STOP","HALT","STAY","ARREST","CHECK","STANDSTILL" */
line_550:
    /* UNTRANSLATED: DATA 6,"STOP","HALT","STAY","ARREST","CHECK","STANDSTILL" */
    /* BASIC: 560 DATA 6,"HOUSE","DWELLING","RESIDENCE","DOMICILE","LODGING" */
line_560:
    /* UNTRANSLATED: DATA 6,"HOUSE","DWELLING","RESIDENCE","DOMICILE","LODGING" */
    /* BASIC: 565 DATA "HABITATION" */
line_565:
    /* UNTRANSLATED: DATA "HABITATION" */
    /* BASIC: 570 DATA 7,"PIT","HOLE","HOLLOW","WELL","GULF","CHASM","ABYSS" */
line_570:
    /* UNTRANSLATED: DATA 7,"PIT","HOLE","HOLLOW","WELL","GULF","CHASM","ABYSS" */
    /* BASIC: 580 DATA 7,"PUSH","SHOVE","THRUST","PROD","POKE","BUTT","PRESS" */
line_580:
    /* UNTRANSLATED: DATA 7,"PUSH","SHOVE","THRUST","PROD","POKE","BUTT","PRESS" */
    /* BASIC: 590 DATA 6,"RED","ROUGE","SCARLET","CRIMSON","FLAME","RUBY" */
line_590:
    /* UNTRANSLATED: DATA 6,"RED","ROUGE","SCARLET","CRIMSON","FLAME","RUBY" */
    /* BASIC: 600 DATA 7,"PAIN","SUFFERING","HURT","MISERY","DISTRESS","ACHE" */
line_600:
    /* UNTRANSLATED: DATA 7,"PAIN","SUFFERING","HURT","MISERY","DISTRESS","ACHE" */
    /* BASIC: 605 DATA "DISCOMFORT" */
line_605:
    /* UNTRANSLATED: DATA "DISCOMFORT" */
    /* BASIC: 999 END */
line_999:
    exit(0);

    return 0;
}
