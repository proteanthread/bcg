/*
 * Transpiled from superstartrek.bas
 * GW-BASIC to strict C89 (ANSI) / C90 (ISO)
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
    if (n >= 0) sprintf(buf[idx], " %g", n);
    else sprintf(buf[idx], "%g", n);
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
    sprintf(buf[idx], "%s%s", s1, s2);
    return buf[idx];
}

static void str_assign(char *dest, size_t dest_sz, const char *src) {
    strncpy(dest, src, dest_sz - 1);
    dest[dest_sz - 1] = '\0';
}

/* Global variables */
static int gosub_stack[256];
static int gosub_sp = 0;
static double A, B3, B4, B5, B9, C, C1, D, D0, D1, D3, D4, D6, DEF, E, E0, G, G5, H, H1, H8, I, IFE, J, J0, K, K3, K7, K9, L, N, ONA, ONIGO, ONR1GO, ONZ4GO, ONZ5GO, P, P0, Q1, Q2, Q4, Q5, R, R1, R2, S, S1, S2, S3, S8, S9, T, T0, T8, T9, W1, X, X1, X2, X3, X5, Y, Y3, Z, Z1, Z2, Z3, Z4, Z5;
static char A_str[256] = {0};
static char A1_str[256] = {0};
static char C_str[256] = {0};
static char G2_str[256] = {0};
static char O1_str[256] = {0};
static char Q_str[256] = {0};
static char X_str[256] = {0};
static char X0_str[256] = {0};
static char Z_str[256] = {0};
static double C_arr[2000] = {0};
static double D_arr[2000] = {0};
static double G_arr[2000] = {0};
static double K_arr[2000] = {0};
static double N_arr[2000] = {0};
static double Z_arr[2000] = {0};
static char _input_buf[256];

/* User-defined functions forward declarations */
static double FND(double D);
static double FNR(double R);

/* User-defined functions definitions */
static double FND(double D) {
    return sqrt(pow((K_arr[(int)(I) * 100 + (int)(1)]-S1), 2)+pow((K_arr[(int)(I) * 100 + (int)(2)]-S2), 2));
}

static double FNR(double R) {
    return floor(((double)rand() / (double)RAND_MAX)*7.98+1.01);
}

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 REM SUPER STARTREK - MAY 16,1978 - REQUIRES 24K MEM OR Y */
line_10:;
    /* REM SUPER STARTREK - MAY 16,1978 - REQUIRES 24K MEM OR Y */
    /* BASIC: 30 REM */
line_30:;
    /* REM */
    /* BASIC: 40 REM ****        **** STAR TREK ****        **** */
line_40:;
    /* REM ****        **** STAR TREK ****        **** */
    /* BASIC: 50 REM **** SIMULATION OF A MISSION OF THE STARSHIP ENTERPRISE, */
line_50:;
    /* REM **** SIMULATION OF A MISSION OF THE STARSHIP ENTERPRISE, */
    /* BASIC: 60 REM **** AS SEEN ON THE STAR TREK TV SHOW. */
line_60:;
    /* REM **** AS SEEN ON THE STAR TREK TV SHOW. */
    /* BASIC: 70 REM **** OR IGIONAL PROGRAM BY MIKE MAYFIELD, MODIFIED VERSION */
line_70:;
    /* REM **** OR IGIONAL PROGRAM BY MIKE MAYFIELD, MODIFIED VERSION */
    /* BASIC: 80 REM **** PUBLISHED IN DEC'S "101 BASIC GAMES", BY DAVE AHL. */
line_80:;
    /* REM **** PUBLISHED IN DEC'S "101 BASIC GAMES", BY DAVE AHL. */
    /* BASIC: 90 REM **** MODIFICATIONS TO THE LATTER (PLUS DEBUGGING) BY BOB */
line_90:;
    /* REM **** MODIFICATIONS TO THE LATTER (PLUS DEBUGGING) BY BOB */
    /* BASIC: 100 REM *** LEEDOM - APRIL & DECEMBER 1974, */
line_100:;
    /* REM *** LEEDOM - APRIL & DECEMBER 1974, */
    /* BASIC: 110 REM *** WITH A LITTLE HELP FROM HIS FRIENDS . . . */
line_110:;
    /* REM *** WITH A LITTLE HELP FROM HIS FRIENDS . . . */
    /* BASIC: 120 REM *** COMMENTS, EPITHETS, AND SUGGESTIONS SOLICITED -- */
line_120:;
    /* REM *** COMMENTS, EPITHETS, AND SUGGESTIONS SOLICITED -- */
    /* BASIC: 130 REM *** SEND TO :  R. C. LEEDOM */
line_130:;
    /* REM *** SEND TO */
    /* UNTRANSLATED: R. C. LEEDOM */
    /* BASIC: 140 REM ***           WESTINGHOUSE DEFENSE & ELECTRONICS SYSTEMS CNTR. */
line_140:;
    /* REM ***           WESTINGHOUSE DEFENSE & ELECTRONICS SYSTEMS CNTR. */
    /* BASIC: 150 REM ***           BOX 746, M.S. 338 */
line_150:;
    /* REM ***           BOX 746, M.S. 338 */
    /* BASIC: 160 REM ***           BALTIM OR E, MD  21203 */
line_160:;
    /* REM ***           BALTIM OR E, MD  21203 */
    /* BASIC: 170 REM *** */
line_170:;
    /* REM *** */
    /* BASIC: 180 REM *** CONVERTED TO MICROSOFT 8 K BASIC 3/16/78 BY JOHN G OR DERS */
line_180:;
    /* REM *** CONVERTED TO MICROSOFT 8 K BASIC 3/16/78 BY JOHN G OR DERS */
    /* BASIC: 190 REM *** LINE NUMBERS FROM VERSION STREK7 OF 1/12/75 PRESERVED AS */
line_190:;
    /* REM *** LINE NUMBERS FROM VERSION STREK7 OF 1/12/75 PRESERVED AS */
    /* BASIC: 200 REM *** MUCH AS POSSIBLE WHILE USING MULTIPLE STATEMENTS PER LINE */
line_200:;
    /* REM *** MUCH AS POSSIBLE WHILE USING MULTIPLE STATEMENTS PER LINE */
    /* BASIC: 205 REM *** SOME LINES ARE LONGER THAN 72 CHARACTERS; THIS WAS DONE */
line_205:;
    /* REM *** SOME LINES ARE LONGER THAN 72 CHARACTERS; THIS WAS DONE */
    /* BASIC: 210 REM *** BY USING "?" INSTEAD OF "PRINT" WHEN ENTERING LINES */
line_210:;
    /* REM *** BY USING "?" INSTEAD OF "PRINT" WHEN ENTERING LINES */
    /* BASIC: 215 REM *** */
line_215:;
    /* REM *** */
    /* BASIC: 220 PRINT:PRINT:PRINT:PRINT:PRINT:PRINT:PRINT:PRINT:PRINT:PRINT:PRINT */
line_220:;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 221 PRINT"                                    ,------*------," */
line_221:;
    printf("%s", "                                    ,------*------,"); printf("\n");
    /* BASIC: 222 PRINT"                    ,-------------   '---  ------'" */
line_222:;
    printf("%s", "                    ,-------------   '---  ------'"); printf("\n");
    /* BASIC: 223 PRINT"                     '-------- --'      / /" */
line_223:;
    printf("%s", "                     '-------- --'      / /"); printf("\n");
    /* BASIC: 224 PRINT"                         ,---' '-------/ /--," */
line_224:;
    printf("%s", "                         ,---' '-------/ /--,"); printf("\n");
    /* BASIC: 225 PRINT"                          '----------------'":PRINT */
line_225:;
    printf("%s", "                          '----------------'"); printf("\n");
    printf("\n");
    /* BASIC: 226 PRINT"                    THE USS ENTERPRISE --- NCC-1701" */
line_226:;
    printf("%s", "                    THE USS ENTERPRISE --- NCC-1701"); printf("\n");
    /* BASIC: 227 PRINT:PRINT:PRINT:PRINT:PRINT */
line_227:;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 260 REM CLEAR 600 */
line_260:;
    /* REM CLEAR 600 */
    /* BASIC: 270 Z$="                         " */
line_270:;
    str_assign(Z_str, sizeof(Z_str), "                         ");
    /* BASIC: 330 DIM G(8,8),C(9,2),K(3,3),N(3),Z(8,8),D(8) */
line_330:;
    /* DIM G(8,8),C(9,2),K(3,3),N(3),Z(8,8),D(8) (handled statically) */
    /* BASIC: 370 T=INT(RND(1)*20+20)*100:T0=T:T9=25+INT(RND(1)*10):D0=0:E=3000:E0=E */
line_370:;
    T = floor(((double)rand() / (double)RAND_MAX)*20+20)*100;
    T0 = T;
    T9 = 25+floor(((double)rand() / (double)RAND_MAX)*10);
    D0 = 0;
    E = 3000;
    E0 = E;
    /* BASIC: 440 P=10:P0=P:S9=200:S=0:B9=2:K9=0:X$="":X0$=" IS " */
line_440:;
    P = 10;
    P0 = P;
    S9 = 200;
    S = 0;
    B9 = 2;
    K9 = 0;
    str_assign(X_str, sizeof(X_str), "");
    str_assign(X0_str, sizeof(X0_str), " IS ");
    /* BASIC: 470 DEF FND(D)=SQR((K(I,1)-S1)^2+(K(I,2)-S2)^2) */
line_470:;
    /* UNTRANSLATED: DEF FND(D)=SQR((K(I,1)-S1)^2+(K(I,2)-S2)^2) */
    /* BASIC: 475 DEF FNR(R)=INT(RND(R)*7.98+1.01) */
line_475:;
    /* UNTRANSLATED: DEF FNR(R)=INT(RND(R)*7.98+1.01) */
    /* BASIC: 480 REM INITIALIZE ENTERPRIZE'S POSITION */
line_480:;
    /* REM INITIALIZE ENTERPRIZE'S POSITION */
    /* BASIC: 490 Q1=FNR(1):Q2=FNR(1):S1=FNR(1):S2=FNR(1) */
line_490:;
    Q1 = FNR(1);
    Q2 = FNR(1);
    S1 = FNR(1);
    S2 = FNR(1);
    /* BASIC: 530 FOR I=1 TO 9:C(I,1)=0:C(I,2)=0:NEXT I */
line_530:;
    I = 1; for_loop_I_530: if (((1) >= 0 && I > (9)) || ((1) < 0 && I < (9))) goto end_for_I_530;
    C_arr[(int)(I) * 100 + (int)(1)] = 0;
    C_arr[(int)(I) * 100 + (int)(2)] = 0;
    I += (1); goto for_loop_I_530; end_for_I_530:;
    /* BASIC: 540 C(3,1)=-1:C(2,1)=-1:C(4,1)=-1:C(4,2)=-1:C(5,2)=-1:C(6,2)=-1 */
line_540:;
    C_arr[(int)(3) * 100 + (int)(1)] = -1;
    C_arr[(int)(2) * 100 + (int)(1)] = -1;
    C_arr[(int)(4) * 100 + (int)(1)] = -1;
    C_arr[(int)(4) * 100 + (int)(2)] = -1;
    C_arr[(int)(5) * 100 + (int)(2)] = -1;
    C_arr[(int)(6) * 100 + (int)(2)] = -1;
    /* BASIC: 600 C(1,2)=1:C(2,2)=1:C(6,1)=1:C(7,1)=1:C(8,1)=1:C(8,2)=1:C(9,2)=1 */
line_600:;
    C_arr[(int)(1) * 100 + (int)(2)] = 1;
    C_arr[(int)(2) * 100 + (int)(2)] = 1;
    C_arr[(int)(6) * 100 + (int)(1)] = 1;
    C_arr[(int)(7) * 100 + (int)(1)] = 1;
    C_arr[(int)(8) * 100 + (int)(1)] = 1;
    C_arr[(int)(8) * 100 + (int)(2)] = 1;
    C_arr[(int)(9) * 100 + (int)(2)] = 1;
    /* BASIC: 670 FOR I=1 TO 8:D(I)=0:NEXT I */
line_670:;
    I = 1; for_loop_I_670: if (((1) >= 0 && I > (8)) || ((1) < 0 && I < (8))) goto end_for_I_670;
    D_arr[(int)(I)] = 0;
    I += (1); goto for_loop_I_670; end_for_I_670:;
    /* BASIC: 710 A1$="NAVSRSLRSPHATORSHEDAMCOMXXX" */
line_710:;
    str_assign(A1_str, sizeof(A1_str), "NAVSRSLRSPHATORSHEDAMCOMXXX");
    /* BASIC: 810 REM SETUP WHAT EXHISTS IN GALAXY . . . */
line_810:;
    /* REM SETUP WHAT EXHISTS IN GALAXY . . . */
    /* BASIC: 815 REM K3= # KLINGONS  B3= # STARBASES  S3 = # STARS */
line_815:;
    /* REM K3= # KLINGONS  B3= # STARBASES  S3 = # STARS */
    /* BASIC: 820 FOR I=1 TO 8:FOR J=1 TO 8:K3=0:Z(I,J)=0:R1=RND(1) */
line_820:;
    I = 1; for_loop_I_820: if (((1) >= 0 && I > (8)) || ((1) < 0 && I < (8))) goto end_for_I_820;
    J = 1; for_loop_J_820: if (((1) >= 0 && J > (8)) || ((1) < 0 && J < (8))) goto end_for_J_820;
    K3 = 0;
    Z_arr[(int)(I) * 100 + (int)(J)] = 0;
    R1 = ((double)rand() / (double)RAND_MAX);
    /* BASIC: 850 IF R1>.98 THEN K3=3:K9=K9+3:GOTO 980 */
line_850:;
    if (R1>.98) { K3 = 3; K9 = K9+3; goto line_980; }
    /* BASIC: 860 IF R1>.95 THEN K3=2:K9=K9+2:GOTO 980 */
line_860:;
    if (R1>.95) { K3 = 2; K9 = K9+2; goto line_980; }
    /* BASIC: 870 IF R1>.80 THEN K3=1:K9=K9+1 */
line_870:;
    if (R1>.80) { K3 = 1; K9 = K9+1; }
    /* BASIC: 980 B3=0:IF RND(1)>.96 THEN B3=1:B9=B9+1 */
line_980:;
    B3 = 0;
    if (((double)rand() / (double)RAND_MAX)>.96) { B3 = 1; }
    B9 = B9+1;
    /* BASIC: 1040 G(I,J)=K3*100+B3*10+FNR(1):NEXT J:NEXT I:IF K9>T9 THEN T9=K9+1 */
line_1040:;
    G_arr[(int)(I) * 100 + (int)(J)] = K3*100+B3*10+FNR(1);
    J += (1); goto for_loop_J_820; end_for_J_820:;
    I += (1); goto for_loop_I_820; end_for_I_820:;
    if (K9>T9) { T9 = K9+1; }
    /* BASIC: 1100 IF B9<>0 THEN 1200 */
line_1100:;
    if (B9!=0) { goto line_1200; }
    /* BASIC: 1150 IF G(Q1,Q2)<200 THEN G(Q1,Q2)=G(Q1,Q2)+120:K9=K9+1 */
line_1150:;
    if (G_arr[(int)(Q1) * 100 + (int)(Q2)]<200) { G_arr[(int)(Q1) * 100 + (int)(Q2)] = G_arr[(int)(Q1) * 100 + (int)(Q2)]+120; K9 = K9+1; }
    /* BASIC: 1160 B9=1:G(Q1,Q2)=G(Q1,Q2)+10:Q1=FNR(1):Q2=FNR(1) */
line_1160:;
    B9 = 1;
    G_arr[(int)(Q1) * 100 + (int)(Q2)] = G_arr[(int)(Q1) * 100 + (int)(Q2)]+10;
    Q1 = FNR(1);
    Q2 = FNR(1);
    /* BASIC: 1200 K7=K9:IF B9<>1 THEN X$="S":X0$=" ARE " */
line_1200:;
    K7 = K9;
    if (B9!=1) { str_assign(X_str, sizeof(X_str), "S"); }
    str_assign(X0_str, sizeof(X0_str), " ARE ");
    /* BASIC: 1230 PRINT"YOUR ORDERS ARE AS FOLLOWS:" */
line_1230:;
    printf("%s", "YOUR ORDERS ARE AS FOLLOWS:"); printf("\n");
    /* BASIC: 1240 PRINT"     DESTROY THE";K9;"KLINGON WARSHIPS WHICH HAVE INVADED" */
line_1240:;
    printf("%s", "     DESTROY THE"); printf("%g ", (double)(K9)); printf("%s", "KLINGON WARSHIPS WHICH HAVE INVADED"); printf("\n");
    /* BASIC: 1252 PRINT"   THE GALAXY BEFORE THEY CAN ATTACK FEDERATION HEADQUARTERS" */
line_1252:;
    printf("%s", "   THE GALAXY BEFORE THEY CAN ATTACK FEDERATION HEADQUARTERS"); printf("\n");
    /* BASIC: 1260 PRINT"   ON STARDATE";T0+T9;"  THIS GIVES YOU";T9;"DAYS.  THERE";X0$ */
line_1260:;
    printf("%s", "   ON STARDATE"); printf("%g ", (double)(T0+T9)); printf("%s", "  THIS GIVES YOU"); printf("%g ", (double)(T9)); printf("%s", "DAYS.  THERE"); printf("%s", X0_str); printf("\n");
    /* BASIC: 1272 PRINT"  ";B9;"STARBASE";X$;" IN THE GALAXY FOR RESUPPLYING YOUR SHIP" */
line_1272:;
    printf("%s", "  "); printf("%g ", (double)(B9)); printf("%s", "STARBASE"); printf("%s", X_str); printf("%s", " IN THE GALAXY FOR RESUPPLYING YOUR SHIP"); printf("\n");
    /* BASIC: 1280 PRINT:REM PRINT"HIT ANY KEY EXCEPT RETURN WHEN READY TO ACCEPT COMMAND" */
line_1280:;
    printf("\n");
    /* REM PRINT"HIT ANY KEY EXCEPT RETURN WHEN READY TO ACCEPT COMMAND" */
    /* BASIC: 1300 I=RND(1):REM IF INP(1)=13 THEN 1300 */
line_1300:;
    I = ((double)rand() / (double)RAND_MAX);
    /* REM IF INP(1)=13 THEN 1300 */
    /* BASIC: 1310 REM HERE ANY TIME NEW QUADRANT ENTERED */
line_1310:;
    /* REM HERE ANY TIME NEW QUADRANT ENTERED */
    /* BASIC: 1320 Z4=Q1:Z5=Q2:K3=0:B3=0:S3=0:G5=0:D4=.5*RND(1):Z(Q1,Q2)=G(Q1,Q2) */
line_1320:;
    Z4 = Q1;
    Z5 = Q2;
    K3 = 0;
    B3 = 0;
    S3 = 0;
    G5 = 0;
    D4 = .5*((double)rand() / (double)RAND_MAX);
    Z_arr[(int)(Q1) * 100 + (int)(Q2)] = G_arr[(int)(Q1) * 100 + (int)(Q2)];
    /* BASIC: 1390 IF Q1<1 OR Q1>8 OR Q2<1 OR Q2>8 THEN 1600 */
line_1390:;
    if (Q1<1   ||   Q1>8   ||   Q2<1   ||   Q2>8) { goto line_1600; }
    /* BASIC: 1430 GOSUB 9030:PRINT:IF T0<>T THEN 1490 */
line_1430:;
    gosub_stack[gosub_sp++] = 1; goto line_9030; line_ret_1:;
    printf("\n");
    if (T0!=T) { goto line_1490; }
    /* BASIC: 1460 PRINT"YOUR MISSION BEGINS WITH YOUR STARSHIP LOCATED" */
line_1460:;
    printf("%s", "YOUR MISSION BEGINS WITH YOUR STARSHIP LOCATED"); printf("\n");
    /* BASIC: 1470 PRINT"IN THE GALACTIC QUADRANT, '";G2$;"'.":GOTO 1500 */
line_1470:;
    printf("%s", "IN THE GALACTIC QUADRANT, '"); printf("%s", G2_str); printf("%s", "'."); printf("\n");
    goto line_1500;
    /* BASIC: 1490 PRINT"NOW ENTERING ";G2$;" QUADRANT . . ." */
line_1490:;
    printf("%s", "NOW ENTERING "); printf("%s", G2_str); printf("%s", " QUADRANT . . ."); printf("\n");
    /* BASIC: 1500 PRINT:K3=INT(G(Q1,Q2)*.01):B3=INT(G(Q1,Q2)*.1)-10*K3 */
line_1500:;
    printf("\n");
    K3 = floor(G_arr[(int)(Q1) * 100 + (int)(Q2)]*.01);
    B3 = floor(G_arr[(int)(Q1) * 100 + (int)(Q2)]*.1)-10*K3;
    /* BASIC: 1540 S3=G(Q1,Q2)-100*K3-10*B3:IF K3=0 THEN 1590 */
line_1540:;
    S3 = G_arr[(int)(Q1) * 100 + (int)(Q2)]-100*K3-10*B3;
    if (K3==0) { goto line_1590; }
    /* BASIC: 1560 PRINT"COMBAT AREA      CONDITION RED":IF S>200 THEN 1590 */
line_1560:;
    printf("%s", "COMBAT AREA      CONDITION RED"); printf("\n");
    if (S>200) { goto line_1590; }
    /* BASIC: 1580 PRINT"   SHIELDS DANGEROUSLY LOW" */
line_1580:;
    printf("%s", "   SHIELDS DANGEROUSLY LOW"); printf("\n");
    /* BASIC: 1590 FOR I=1 TO 3:K(I,1)=0:K(I,2)=0:NEXT I */
line_1590:;
    I = 1; for_loop_I_1590: if (((1) >= 0 && I > (3)) || ((1) < 0 && I < (3))) goto end_for_I_1590;
    K_arr[(int)(I) * 100 + (int)(1)] = 0;
    K_arr[(int)(I) * 100 + (int)(2)] = 0;
    I += (1); goto for_loop_I_1590; end_for_I_1590:;
    /* BASIC: 1600 FOR I=1 TO 3:K(I,3)=0:NEXT I:Q$=Z$+Z$+Z$+Z$+Z$+Z$+Z$+LEFT$(Z$,17) */
line_1600:;
    I = 1; for_loop_I_1600: if (((1) >= 0 && I > (3)) || ((1) < 0 && I < (3))) goto end_for_I_1600;
    K_arr[(int)(I) * 100 + (int)(3)] = 0;
    I += (1); goto for_loop_I_1600; end_for_I_1600:;
    str_assign(Q_str, sizeof(Q_str), str_cat_helper(str_cat_helper(str_cat_helper(str_cat_helper(str_cat_helper(str_cat_helper(str_cat_helper(Z_str, Z_str), Z_str), Z_str), Z_str), Z_str), Z_str), basic_LEFT(Z_str,17)));
    /* BASIC: 1660 REM POSITION ENTERPRISE IN QUADRANT, THEN PLACE "K3" KLINGONS, & */
line_1660:;
    /* REM POSITION ENTERPRISE IN QUADRANT, THEN PLACE "K3" KLINGONS, & */
    /* BASIC: 1670 REM "B3" STARBASES, & "S3" STARS ELSE WHERE. */
line_1670:;
    /* REM "B3" STARBASES, & "S3" STARS ELSE WHERE. */
    /* BASIC: 1680 A$="<*>":Z1=S1:Z2=S2:GOSUB 8670:IF K3<1 THEN 1820 */
line_1680:;
    str_assign(A_str, sizeof(A_str), "<*>");
    Z1 = S1;
    Z2 = S2;
    gosub_stack[gosub_sp++] = 2; goto line_8670; line_ret_2:;
    if (K3<1) { goto line_1820; }
    /* BASIC: 1720 FOR I=1 TO K3:GOSUB 8590:A$="+K+":Z1=R1:Z2=R2 */
line_1720:;
    I = 1; for_loop_I_1720: if (((1) >= 0 && I > (K3)) || ((1) < 0 && I < (K3))) goto end_for_I_1720;
    gosub_stack[gosub_sp++] = 3; goto line_8590; line_ret_3:;
    str_assign(A_str, sizeof(A_str), "+K+");
    Z1 = R1;
    Z2 = R2;
    /* BASIC: 1780 GOSUB 8670:K(I,1)=R1:K(I,2)=R2:K(I,3)=S9*(0.5+RND(1)):NEXT I */
line_1780:;
    gosub_stack[gosub_sp++] = 4; goto line_8670; line_ret_4:;
    K_arr[(int)(I) * 100 + (int)(1)] = R1;
    K_arr[(int)(I) * 100 + (int)(2)] = R2;
    K_arr[(int)(I) * 100 + (int)(3)] = S9*(0.5+((double)rand() / (double)RAND_MAX));
    I += (1); goto for_loop_I_1720; end_for_I_1720:;
    /* BASIC: 1820 IF B3<1 THEN 1910 */
line_1820:;
    if (B3<1) { goto line_1910; }
    /* BASIC: 1880 GOSUB 8590:A$=">!<":Z1=R1:B4=R1:Z2=R2:B5=R2:GOSUB 8670 */
line_1880:;
    gosub_stack[gosub_sp++] = 5; goto line_8590; line_ret_5:;
    str_assign(A_str, sizeof(A_str), ">!<");
    Z1 = R1;
    B4 = R1;
    Z2 = R2;
    B5 = R2;
    gosub_stack[gosub_sp++] = 6; goto line_8670; line_ret_6:;
    /* BASIC: 1910 FOR I=1 TO S3:GOSUB 8590:A$=" * ":Z1=R1:Z2=R2:GOSUB 8670:NEXT I */
line_1910:;
    I = 1; for_loop_I_1910: if (((1) >= 0 && I > (S3)) || ((1) < 0 && I < (S3))) goto end_for_I_1910;
    gosub_stack[gosub_sp++] = 7; goto line_8590; line_ret_7:;
    str_assign(A_str, sizeof(A_str), " * ");
    Z1 = R1;
    Z2 = R2;
    gosub_stack[gosub_sp++] = 8; goto line_8670; line_ret_8:;
    I += (1); goto for_loop_I_1910; end_for_I_1910:;
    /* BASIC: 1980 GOSUB 6430 */
line_1980:;
    gosub_stack[gosub_sp++] = 9; goto line_6430; line_ret_9:;
    /* BASIC: 1990 IF S+E>10 THEN IFE>10 OR D(7)=0 THEN 2060 */
line_1990:;
    if (S+E>10) { /* UNTRANSLATED: IFE>10 OR D(7)=0 THEN 2060 */ }
    /* BASIC: 2020 PRINT:PRINT"** FATAL ERROR **   YOU'VE JUST STRANDED YOUR SHIP IN " */
line_2020:;
    printf("\n");
    printf("%s", "** FATAL ERROR **   YOU'VE JUST STRANDED YOUR SHIP IN "); printf("\n");
    /* BASIC: 2030 PRINT"SPACE":PRINT"YOU HAVE INSUFFICIENT MANEUVERING ENERGY,"; */
line_2030:;
    printf("%s", "SPACE"); printf("\n");
    printf("%s", "YOU HAVE INSUFFICIENT MANEUVERING ENERGY,");
    /* BASIC: 2040 PRINT" AND SHIELD CONTROL":PRINT"IS PRESENTLY INCAPABLE OF CROSS"; */
line_2040:;
    printf("%s", " AND SHIELD CONTROL"); printf("\n");
    printf("%s", "IS PRESENTLY INCAPABLE OF CROSS");
    /* BASIC: 2050 PRINT"-CIRCUITING TO ENGINE ROOM!!":GOTO 6220 */
line_2050:;
    printf("%s", "-CIRCUITING TO ENGINE ROOM!!"); printf("\n");
    goto line_6220;
    /* BASIC: 2060 INPUT"COMMAND";A$ */
line_2060:;
    printf("%s", "COMMAND"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    /* BASIC: 2080 FOR I=1 TO 9:IF LEFT$(A$,3)<>MID$(A1$,3*I-2,3) THEN 2160 */
line_2080:;
    I = 1; for_loop_I_2080: if (((1) >= 0 && I > (9)) || ((1) < 0 && I < (9))) goto end_for_I_2080;
    if (strcmp(basic_LEFT(A_str,3), basic_MID(A1_str,3*I-2,3)) != 0) { goto line_2160; }
    /* BASIC: 2140 ONIGO TO 2300,1980,4000,4260,4700,5530,5690,7290,6270 */
line_2140:;
    /* UNTRANSLATED: ONIGO TO 2300,1980,4000,4260,4700,5530,5690,7290,6270 */
    /* BASIC: 2160 NEXT I:PRINT"ENTER ONE OF THE FOLLOWING:" */
line_2160:;
    I += (1); goto for_loop_I_2080; end_for_I_2080:;
    printf("%s", "ENTER ONE OF THE FOLLOWING:"); printf("\n");
    /* BASIC: 2180 PRINT"  NAV  (TO SET COURSE)" */
line_2180:;
    printf("%s", "  NAV  (TO SET COURSE)"); printf("\n");
    /* BASIC: 2190 PRINT"  SRS  (FOR SHORT RANGE SENSOR SCAN)" */
line_2190:;
    printf("%s", "  SRS  (FOR SHORT RANGE SENSOR SCAN)"); printf("\n");
    /* BASIC: 2200 PRINT"  LRS  (FOR LONG RANGE SENSOR SCAN)" */
line_2200:;
    printf("%s", "  LRS  (FOR LONG RANGE SENSOR SCAN)"); printf("\n");
    /* BASIC: 2210 PRINT"  PHA  (TO FIRE PHASERS)" */
line_2210:;
    printf("%s", "  PHA  (TO FIRE PHASERS)"); printf("\n");
    /* BASIC: 2220 PRINT"  TOR  (TO FIRE PHOTON TORPEDOES)" */
line_2220:;
    printf("%s", "  TOR  (TO FIRE PHOTON TORPEDOES)"); printf("\n");
    /* BASIC: 2230 PRINT"  SHE  (TO RAISE OR LOWER SHIELDS)" */
line_2230:;
    printf("%s", "  SHE  (TO RAISE OR LOWER SHIELDS)"); printf("\n");
    /* BASIC: 2240 PRINT"  DAM  (FOR DAMAGE CONTROL REPORTS)" */
line_2240:;
    printf("%s", "  DAM  (FOR DAMAGE CONTROL REPORTS)"); printf("\n");
    /* BASIC: 2250 PRINT"  COM  (TO CALL ON LIBRARY-COMPUTER)" */
line_2250:;
    printf("%s", "  COM  (TO CALL ON LIBRARY-COMPUTER)"); printf("\n");
    /* BASIC: 2260 PRINT"  XXX  (TO RESIGN YOUR COMMAND)":PRINT:GOTO 1990 */
line_2260:;
    printf("%s", "  XXX  (TO RESIGN YOUR COMMAND)"); printf("\n");
    printf("\n");
    goto line_1990;
    /* BASIC: 2290 REM COURSE CONTROL BEGINS HERE */
line_2290:;
    /* REM COURSE CONTROL BEGINS HERE */
    /* BASIC: 2300 INPUT"COURSE (0-9)";C1:IF C1=9 THEN C1=1 */
line_2300:;
    printf("%s", "COURSE (0-9)"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &C1);
    if (C1==9) { C1 = 1; }
    /* BASIC: 2310 IF C1>=1 AND C1<9 THEN 2350 */
line_2310:;
    if (C1>=1   &&   C1<9) { goto line_2350; }
    /* BASIC: 2330 PRINT"   LT. SULU REPORTS, 'INCORRECT COURSE DATA, SIR!'":GOTO 1990 */
line_2330:;
    printf("%s", "   LT. SULU REPORTS, 'INCORRECT COURSE DATA, SIR!'"); printf("\n");
    goto line_1990;
    /* BASIC: 2350 X$="8":IF D(1)<0 THEN X$="0.2" */
line_2350:;
    str_assign(X_str, sizeof(X_str), "8");
    if (D_arr[(int)(1)]<0) { str_assign(X_str, sizeof(X_str), "0.2"); }
    /* BASIC: 2360 PRINT"WARP FACTOR (0-";X$;")";:INPUT W1:IF D(1)<0 AND W1>.2 THEN 2470 */
line_2360:;
    printf("%s", "WARP FACTOR (0-"); printf("%s", X_str); printf("%s", ")");
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &W1);
    if (D_arr[(int)(1)]<0   &&   W1>.2) { goto line_2470; }
    /* BASIC: 2380 IF W1>0 AND W1<=8 THEN 2490 */
line_2380:;
    if (W1>0   &&   W1<=8) { goto line_2490; }
    /* BASIC: 2390 IF W1=0 THEN 1990 */
line_2390:;
    if (W1==0) { goto line_1990; }
    /* BASIC: 2420 PRINT"   CHIEF ENGINEER SCOTT REPORTS 'THE ENGINES WON'T TAKE"; */
line_2420:;
    printf("%s", "   CHIEF ENGINEER SCOTT REPORTS 'THE ENGINES WON'T TAKE");
    /* BASIC: 2430 PRINT" WARP ";W1;"!'":GOTO 1990 */
line_2430:;
    printf("%s", " WARP "); printf("%g ", (double)(W1)); printf("%s", "!'"); printf("\n");
    goto line_1990;
    /* BASIC: 2470 PRINT"WARP ENGINES ARE DAMAGED.  MAXIUM SPEED = WARP 0.2":GOTO 1990 */
line_2470:;
    printf("%s", "WARP ENGINES ARE DAMAGED.  MAXIUM SPEED = WARP 0.2"); printf("\n");
    goto line_1990;
    /* BASIC: 2490 N=INT(W1*8+.5):IF E-N>=0 THEN 2590 */
line_2490:;
    N = floor(W1*8+.5);
    if (E-N>=0) { goto line_2590; }
    /* BASIC: 2500 PRINT"ENGINEERING REPORTS   'INSUFFICIENT ENERGY AVAILABLE" */
line_2500:;
    printf("%s", "ENGINEERING REPORTS   'INSUFFICIENT ENERGY AVAILABLE"); printf("\n");
    /* BASIC: 2510 PRINT"                       FOR MANEUVERING AT WARP";W1;"!'" */
line_2510:;
    printf("%s", "                       FOR MANEUVERING AT WARP"); printf("%g ", (double)(W1)); printf("%s", "!'"); printf("\n");
    /* BASIC: 2530 IF S<N-E OR D(7)<0 THEN 1990 */
line_2530:;
    if (S<N-E   ||   D_arr[(int)(7)]<0) { goto line_1990; }
    /* BASIC: 2550 PRINT"DEFLECTOR CONTROL ROOM ACKNOWLEDGES";S;"UNITS OF ENERGY" */
line_2550:;
    printf("%s", "DEFLECTOR CONTROL ROOM ACKNOWLEDGES"); printf("%g ", (double)(S)); printf("%s", "UNITS OF ENERGY"); printf("\n");
    /* BASIC: 2560 PRINT"                         PRESENTLY DEPLOYED TO SHIELDS." */
line_2560:;
    printf("%s", "                         PRESENTLY DEPLOYED TO SHIELDS."); printf("\n");
    /* BASIC: 2570 GOTO 1990 */
line_2570:;
    goto line_1990;
    /* BASIC: 2580 REM KLINGONS MOVE/FIRE ON MOVING STARSHIP . . . */
line_2580:;
    /* REM KLINGONS MOVE/FIRE ON MOVING STARSHIP . . . */
    /* BASIC: 2590 FOR I=1 TO K3:IF K(I,3)=0 THEN 2700 */
line_2590:;
    I = 1; for_loop_I_2590: if (((1) >= 0 && I > (K3)) || ((1) < 0 && I < (K3))) goto end_for_I_2590;
    if (K_arr[(int)(I) * 100 + (int)(3)]==0) { goto line_2700; }
    /* BASIC: 2610 A$="   ":Z1=K(I,1):Z2=K(I,2):GOSUB 8670:GOSUB 8590 */
line_2610:;
    str_assign(A_str, sizeof(A_str), "   ");
    Z1 = K_arr[(int)(I) * 100 + (int)(1)];
    Z2 = K_arr[(int)(I) * 100 + (int)(2)];
    gosub_stack[gosub_sp++] = 10; goto line_8670; line_ret_10:;
    gosub_stack[gosub_sp++] = 11; goto line_8590; line_ret_11:;
    /* BASIC: 2660 K(I,1)=Z1:K(I,2)=Z2:A$="+K+":GOSUB 8670 */
line_2660:;
    K_arr[(int)(I) * 100 + (int)(1)] = Z1;
    K_arr[(int)(I) * 100 + (int)(2)] = Z2;
    str_assign(A_str, sizeof(A_str), "+K+");
    gosub_stack[gosub_sp++] = 12; goto line_8670; line_ret_12:;
    /* BASIC: 2700 NEXT I:GOSUB 6000:D1=0:D6=W1:IF W1>=1 THEN D6=1 */
line_2700:;
    I += (1); goto for_loop_I_2590; end_for_I_2590:;
    gosub_stack[gosub_sp++] = 13; goto line_6000; line_ret_13:;
    D1 = 0;
    D6 = W1;
    if (W1>=1) { D6 = 1; }
    /* BASIC: 2770 FOR I=1 TO 8:IF D(I)>=0 THEN 2880 */
line_2770:;
    I = 1; for_loop_I_2770: if (((1) >= 0 && I > (8)) || ((1) < 0 && I < (8))) goto end_for_I_2770;
    if (D_arr[(int)(I)]>=0) { goto line_2880; }
    /* BASIC: 2790 D(I)=D(I)+D6:IF D(I)>-.1 AND D(I)<0 THEN D(I)=-.1:GOTO 2880 */
line_2790:;
    D_arr[(int)(I)] = D_arr[(int)(I)]+D6;
    if (D_arr[(int)(I)]>-.1   &&   D_arr[(int)(I)]<0) { D_arr[(int)(I)] = -.1; }
    goto line_2880;
    /* BASIC: 2800 IF D(I)<0 THEN 2880 */
line_2800:;
    if (D_arr[(int)(I)]<0) { goto line_2880; }
    /* BASIC: 2810 IF D1<>1 THEN D1=1:PRINT"DAMAGE CONTROL REPORT:  "; */
line_2810:;
    if (D1!=1) { D1 = 1; printf("%s", "DAMAGE CONTROL REPORT:  "); }
    /* BASIC: 2840 PRINT TAB(8);:R1=I:GOSUB 8790:PRINT G2$;" REPAIR COMPLETED." */
line_2840:;
    { int _t; for(_t=0; _t<8; _t++) printf(" "); }
    R1 = I;
    gosub_stack[gosub_sp++] = 14; goto line_8790; line_ret_14:;
    printf("%s", G2_str); printf("%s", " REPAIR COMPLETED."); printf("\n");
    /* BASIC: 2880 NEXT I:IF RND(1)>.2 THEN 3070 */
line_2880:;
    I += (1); goto for_loop_I_2770; end_for_I_2770:;
    if (((double)rand() / (double)RAND_MAX)>.2) { goto line_3070; }
    /* BASIC: 2910 R1=FNR(1):IF RND(1)>=.6 THEN 3000 */
line_2910:;
    R1 = FNR(1);
    if (((double)rand() / (double)RAND_MAX)>=.6) { goto line_3000; }
    /* BASIC: 2930 D(R1)=D(R1)-(RND(1)*5+1):PRINT"DAMAGE CONTROL REPORT:  "; */
line_2930:;
    D_arr[(int)(R1)] = D_arr[(int)(R1)]-(((double)rand() / (double)RAND_MAX)*5+1);
    printf("%s", "DAMAGE CONTROL REPORT:  ");
    /* BASIC: 2960 GOSUB 8790:PRINT G2$;" DAMAGED":PRINT:GOTO 3070 */
line_2960:;
    gosub_stack[gosub_sp++] = 15; goto line_8790; line_ret_15:;
    printf("%s", G2_str); printf("%s", " DAMAGED"); printf("\n");
    printf("\n");
    goto line_3070;
    /* BASIC: 3000 D(R1)=D(R1)+RND(1)*3+1:PRINT"DAMAGE CONTROL REPORT:  "; */
line_3000:;
    D_arr[(int)(R1)] = D_arr[(int)(R1)]+((double)rand() / (double)RAND_MAX)*3+1;
    printf("%s", "DAMAGE CONTROL REPORT:  ");
    /* BASIC: 3030 GOSUB 8790:PRINT G2$;" STATE OF REPAIR IMPROVED":PRINT */
line_3030:;
    gosub_stack[gosub_sp++] = 16; goto line_8790; line_ret_16:;
    printf("%s", G2_str); printf("%s", " STATE OF REPAIR IMPROVED"); printf("\n");
    printf("\n");
    /* BASIC: 3060 REM BEGIN MOVING STARSHIP */
line_3060:;
    /* REM BEGIN MOVING STARSHIP */
    /* BASIC: 3070 A$="   ":Z1=INT(S1):Z2=INT(S2):GOSUB 8670 */
line_3070:;
    str_assign(A_str, sizeof(A_str), "   ");
    Z1 = floor(S1);
    Z2 = floor(S2);
    gosub_stack[gosub_sp++] = 17; goto line_8670; line_ret_17:;
    /* BASIC: 3110 X1=C(C1,1)+(C(C1+1,1)-C(C1,1))*(C1-INT(C1)):X=S1:Y=S2 */
line_3110:;
    X1 = C_arr[(int)(C1) * 100 + (int)(1)]+(C_arr[(int)(C1+1) * 100 + (int)(1)]-C_arr[(int)(C1) * 100 + (int)(1)])*(C1-floor(C1));
    X = S1;
    Y = S2;
    /* BASIC: 3140 X2=C(C1,2)+(C(C1+1,2)-C(C1,2))*(C1-INT(C1)):Q4=Q1:Q5=Q2 */
line_3140:;
    X2 = C_arr[(int)(C1) * 100 + (int)(2)]+(C_arr[(int)(C1+1) * 100 + (int)(2)]-C_arr[(int)(C1) * 100 + (int)(2)])*(C1-floor(C1));
    Q4 = Q1;
    Q5 = Q2;
    /* BASIC: 3170 FOR I=1 TO N:S1=S1+X1:S2=S2+X2:IF S1<1 OR S1>=9 OR S2<1 OR S2>=9 THEN 3500 */
line_3170:;
    I = 1; for_loop_I_3170: if (((1) >= 0 && I > (N)) || ((1) < 0 && I < (N))) goto end_for_I_3170;
    S1 = S1+X1;
    S2 = S2+X2;
    if (S1<1   ||   S1>=9   ||   S2<1   ||   S2>=9) { goto line_3500; }
    /* BASIC: 3240 S8=INT(S1)*24+INT(S2)*3-26:IF MID$(Q$,S8,2)="  " THEN 3360 */
line_3240:;
    S8 = floor(S1)*24+floor(S2)*3-26;
    if (strcmp(basic_MID(Q_str,S8,2), "  ") == 0) { goto line_3360; }
    /* BASIC: 3320 S1=INT(S1-X1):S2=INT(S2-X2):PRINT"WARP ENGINES SHUT DOWN AT "; */
line_3320:;
    S1 = floor(S1-X1);
    S2 = floor(S2-X2);
    printf("%s", "WARP ENGINES SHUT DOWN AT ");
    /* BASIC: 3350 PRINT"SECTOR";S1;",";S2;"DUE TO BAD NAVAGATION":GOTO 3370 */
line_3350:;
    printf("%s", "SECTOR"); printf("%g ", (double)(S1)); printf("%s", ","); printf("%g ", (double)(S2)); printf("%s", "DUE TO BAD NAVAGATION"); printf("\n");
    goto line_3370;
    /* BASIC: 3360 NEXT I:S1=INT(S1):S2=INT(S2) */
line_3360:;
    I += (1); goto for_loop_I_3170; end_for_I_3170:;
    S1 = floor(S1);
    S2 = floor(S2);
    /* BASIC: 3370 A$="<*>":Z1=INT(S1):Z2=INT(S2):GOSUB 8670:GOSUB 3910:T8=1 */
line_3370:;
    str_assign(A_str, sizeof(A_str), "<*>");
    Z1 = floor(S1);
    Z2 = floor(S2);
    gosub_stack[gosub_sp++] = 18; goto line_8670; line_ret_18:;
    gosub_stack[gosub_sp++] = 19; goto line_3910; line_ret_19:;
    T8 = 1;
    /* BASIC: 3430 IF W1<1 THEN T8=.1*INT(10*W1) */
line_3430:;
    if (W1<1) { T8 = .1*floor(10*W1); }
    /* BASIC: 3450 T=T+T8:IF T>T0+T9 THEN 6220 */
line_3450:;
    T = T+T8;
    if (T>T0+T9) { goto line_6220; }
    /* BASIC: 3470 REM SEE IF DOCKED, THEN GET COMM AND */
line_3470:;
    /* REM SEE IF DOCKED, THEN GET COMM AND */
    /* BASIC: 3480 GOTO 1980 */
line_3480:;
    goto line_1980;
    /* BASIC: 3490 REM EXCEEDED QUADRANT LIMITS */
line_3490:;
    /* REM EXCEEDED QUADRANT LIMITS */
    /* BASIC: 3500 X=8*Q1+X+N*X1:Y=8*Q2+Y+N*X2:Q1=INT(X/8):Q2=INT(Y/8):S1=INT(X-Q1*8) */
line_3500:;
    X = 8*Q1+X+N*X1;
    Y = 8*Q2+Y+N*X2;
    Q1 = floor(X/8);
    Q2 = floor(Y/8);
    S1 = floor(X-Q1*8);
    /* BASIC: 3550 S2=INT(Y-Q2*8):IF S1=0 THEN Q1=Q1-1:S1=8 */
line_3550:;
    S2 = floor(Y-Q2*8);
    if (S1==0) { Q1 = Q1-1; }
    S1 = 8;
    /* BASIC: 3590 IF S2=0 THEN Q2=Q2-1:S2=8 */
line_3590:;
    if (S2==0) { Q2 = Q2-1; S2 = 8; }
    /* BASIC: 3620 X5=0:IF Q1<1 THEN X5=1:Q1=1:S1=1 */
line_3620:;
    X5 = 0;
    if (Q1<1) { X5 = 1; }
    Q1 = 1;
    S1 = 1;
    /* BASIC: 3670 IF Q1>8 THEN X5=1:Q1=8:S1=8 */
line_3670:;
    if (Q1>8) { X5 = 1; Q1 = 8; S1 = 8; }
    /* BASIC: 3710 IF Q2<1 THEN X5=1:Q2=1:S2=1 */
line_3710:;
    if (Q2<1) { X5 = 1; Q2 = 1; S2 = 1; }
    /* BASIC: 3750 IF Q2>8 THEN X5=1:Q2=8:S2=8 */
line_3750:;
    if (Q2>8) { X5 = 1; Q2 = 8; S2 = 8; }
    /* BASIC: 3790 IF X5=0 THEN 3860 */
line_3790:;
    if (X5==0) { goto line_3860; }
    /* BASIC: 3800 PRINT"LT. UHURA REPORTS MESSAGE FROM STARFLEET COMMAND:" */
line_3800:;
    printf("%s", "LT. UHURA REPORTS MESSAGE FROM STARFLEET COMMAND:"); printf("\n");
    /* BASIC: 3810 PRINT"  'PERMISSION TO ATTEMPT CROSSING OF GALACTIC PERIMETER" */
line_3810:;
    printf("%s", "  'PERMISSION TO ATTEMPT CROSSING OF GALACTIC PERIMETER"); printf("\n");
    /* BASIC: 3820 PRINT"  IS HEREBY *DENIED*.  SHUT DOWN YOUR ENGINES.'" */
line_3820:;
    printf("%s", "  IS HEREBY *DENIED*.  SHUT DOWN YOUR ENGINES.'"); printf("\n");
    /* BASIC: 3830 PRINT"CHIEF ENGINEER SCOTT REPORTS  'WARP ENGINES SHUT DOWN" */
line_3830:;
    printf("%s", "CHIEF ENGINEER SCOTT REPORTS  'WARP ENGINES SHUT DOWN"); printf("\n");
    /* BASIC: 3840 PRINT"  AT SECTOR";S1;",";S2;"OF QUADRANT";Q1;",";Q2;".'" */
line_3840:;
    printf("%s", "  AT SECTOR"); printf("%g ", (double)(S1)); printf("%s", ","); printf("%g ", (double)(S2)); printf("%s", "OF QUADRANT"); printf("%g ", (double)(Q1)); printf("%s", ","); printf("%g ", (double)(Q2)); printf("%s", ".'"); printf("\n");
    /* BASIC: 3850 IF T>T0+T9 THEN 6220 */
line_3850:;
    if (T>T0+T9) { goto line_6220; }
    /* BASIC: 3860 IF 8*Q1+Q2=8*Q4+Q5 THEN 3370 */
line_3860:;
    if (8*Q1+Q2==8*Q4+Q5) { goto line_3370; }
    /* BASIC: 3870 T=T+1:GOSUB 3910:GOTO 1320 */
line_3870:;
    T = T+1;
    gosub_stack[gosub_sp++] = 20; goto line_3910; line_ret_20:;
    goto line_1320;
    /* BASIC: 3900 REM MANEUVER ENERGY S/R ** */
line_3900:;
    /* REM MANEUVER ENERGY S/R ** */
    /* BASIC: 3910 E=E-N-10:IF E>=0 THEN RETURN */
line_3910:;
    E = E-N-10;
    if (E>=0) { switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     case 27: goto line_ret_27;     case 28: goto line_ret_28;     case 29: goto line_ret_29;     case 30: goto line_ret_30;     case 31: goto line_ret_31;     case 32: goto line_ret_32;     case 33: goto line_ret_33;     case 34: goto line_ret_34;     case 35: goto line_ret_35;     case 36: goto line_ret_36;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); } }
    /* BASIC: 3930 PRINT"SHIELD CONTROL SUPPLIES ENERGY TO COMPLETE THE MANEUVER." */
line_3930:;
    printf("%s", "SHIELD CONTROL SUPPLIES ENERGY TO COMPLETE THE MANEUVER."); printf("\n");
    /* BASIC: 3940 S=S+E:E=0:IF S<=0 THEN S=0 */
line_3940:;
    S = S+E;
    E = 0;
    if (S<=0) { S = 0; }
    /* BASIC: 3980 RETURN */
line_3980:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     case 27: goto line_ret_27;     case 28: goto line_ret_28;     case 29: goto line_ret_29;     case 30: goto line_ret_30;     case 31: goto line_ret_31;     case 32: goto line_ret_32;     case 33: goto line_ret_33;     case 34: goto line_ret_34;     case 35: goto line_ret_35;     case 36: goto line_ret_36;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 3990 REM LONG RANGE SENS OR SCAN CODE */
line_3990:;
    /* REM LONG RANGE SENS OR SCAN CODE */
    /* BASIC: 4000 IF D(3)<0 THEN PRINT"LONG RANGE SENSORS ARE INOPERABLE":GOTO 1990 */
line_4000:;
    if (D_arr[(int)(3)]<0) { printf("%s", "LONG RANGE SENSORS ARE INOPERABLE"); printf("\n"); goto line_1990; }
    /* BASIC: 4030 PRINT"LONG RANGE SCAN FOR QUADRANT";Q1;",";Q2 */
line_4030:;
    printf("%s", "LONG RANGE SCAN FOR QUADRANT"); printf("%g ", (double)(Q1)); printf("%s", ","); printf("%g ", (double)(Q2)); printf("\n");
    /* BASIC: 4040 O1$="-------------------":PRINT O1$ */
line_4040:;
    str_assign(O1_str, sizeof(O1_str), "-------------------");
    printf("%s", O1_str); printf("\n");
    /* BASIC: 4060 FOR I=Q1-1 TO Q1+1:N(1)=-1:N(2)=-2:N(3)=-3:FOR J=Q2-1 TO Q2+1 */
line_4060:;
    I = Q1-1; for_loop_I_4060: if (((1) >= 0 && I > (Q1+1)) || ((1) < 0 && I < (Q1+1))) goto end_for_I_4060;
    N_arr[(int)(1)] = -1;
    N_arr[(int)(2)] = -2;
    N_arr[(int)(3)] = -3;
    J = Q2-1; for_loop_J_4060: if (((1) >= 0 && J > (Q2+1)) || ((1) < 0 && J < (Q2+1))) goto end_for_J_4060;
    /* BASIC: 4120 IF I>0 AND I<9 AND J>0 AND J<9 THEN N(J-Q2+2)=G(I,J):Z(I,J)=G(I,J) */
line_4120:;
    if (I>0   &&   I<9   &&   J>0   &&   J<9) { N_arr[(int)(J-Q2+2)] = G_arr[(int)(I) * 100 + (int)(J)]; Z_arr[(int)(I) * 100 + (int)(J)] = G_arr[(int)(I) * 100 + (int)(J)]; }
    /* BASIC: 4180 NEXT J:FOR L=1 TO 3:PRINT": ";:IF N(L)<0 THEN PRINT"*** ";:GOTO 4230 */
line_4180:;
    J += (1); goto for_loop_J_4060; end_for_J_4060:;
    L = 1; for_loop_L_4180: if (((1) >= 0 && L > (3)) || ((1) < 0 && L < (3))) goto end_for_L_4180;
    printf("%s", ": ");
    if (N_arr[(int)(L)]<0) { printf("%s", "*** "); }
    goto line_4230;
    /* BASIC: 4210 PRINT RIGHT$(STR$(N(L)+1000),3);" "; */
line_4210:;
    printf("%s", basic_RIGHT(basic_STR(N_arr[(int)(L)]+1000),3)); printf("%s", " ");
    /* BASIC: 4230 NEXT L:PRINT":":PRINT O1$:NEXT I:GOTO 1990 */
line_4230:;
    L += (1); goto for_loop_L_4180; end_for_L_4180:;
    printf("%s", ":"); printf("\n");
    printf("%s", O1_str); printf("\n");
    I += (1); goto for_loop_I_4060; end_for_I_4060:;
    goto line_1990;
    /* BASIC: 4250 REM PHASER CONTROL CODE BEGINS HERE */
line_4250:;
    /* REM PHASER CONTROL CODE BEGINS HERE */
    /* BASIC: 4260 IF D(4)<0 THEN PRINT"PHASERS INOPERATIVE":GOTO 1990 */
line_4260:;
    if (D_arr[(int)(4)]<0) { printf("%s", "PHASERS INOPERATIVE"); printf("\n"); goto line_1990; }
    /* BASIC: 4265 IF K3>0 THEN 4330 */
line_4265:;
    if (K3>0) { goto line_4330; }
    /* BASIC: 4270 PRINT"SCIENCE OFFICER SPOCK REPORTS  'SENSORS SHOW NO ENEMY SHIPS" */
line_4270:;
    printf("%s", "SCIENCE OFFICER SPOCK REPORTS  'SENSORS SHOW NO ENEMY SHIPS"); printf("\n");
    /* BASIC: 4280 PRINT"                                IN THIS QUADRANT'":GOTO 1990 */
line_4280:;
    printf("%s", "                                IN THIS QUADRANT'"); printf("\n");
    goto line_1990;
    /* BASIC: 4330 IF D(8)<0 THEN PRINT"COMPUTER FAILURE HAMPERS ACCURACY" */
line_4330:;
    if (D_arr[(int)(8)]<0) { printf("%s", "COMPUTER FAILURE HAMPERS ACCURACY"); printf("\n"); }
    /* BASIC: 4350 PRINT"PHASERS LOCKED ON TARGET;  "; */
line_4350:;
    printf("%s", "PHASERS LOCKED ON TARGET;  ");
    /* BASIC: 4360 PRINT"ENERGY AVAILABLE =";E;"UNITS" */
line_4360:;
    printf("%s", "ENERGY AVAILABLE ="); printf("%g ", (double)(E)); printf("%s", "UNITS"); printf("\n");
    /* BASIC: 4370 INPUT"NUMBER OF UNITS TO FIRE";X:IF X<=0 THEN 1990 */
line_4370:;
    printf("%s", "NUMBER OF UNITS TO FIRE"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &X);
    if (X<=0) { goto line_1990; }
    /* BASIC: 4400 IF E-X<0 THEN 4360 */
line_4400:;
    if (E-X<0) { goto line_4360; }
    /* BASIC: 4410 E=E-X:IF D(7)<0 THEN X=X*RND(1) */
line_4410:;
    E = E-X;
    if (D_arr[(int)(7)]<0) { X = X*((double)rand() / (double)RAND_MAX); }
    /* BASIC: 4450 H1=INT(X/K3):FOR I=1 TO 3:IF K(I,3)<=0 THEN 4670 */
line_4450:;
    H1 = floor(X/K3);
    I = 1; for_loop_I_4450: if (((1) >= 0 && I > (3)) || ((1) < 0 && I < (3))) goto end_for_I_4450;
    if (K_arr[(int)(I) * 100 + (int)(3)]<=0) { goto line_4670; }
    /* BASIC: 4480 H=INT((H1/FND(0))*(RND(1)+2)):IF H>.15*K(I,3) THEN 4530 */
line_4480:;
    H = floor((H1/FND(0))*(((double)rand() / (double)RAND_MAX)+2));
    if (H>.15*K_arr[(int)(I) * 100 + (int)(3)]) { goto line_4530; }
    /* BASIC: 4500 PRINT"SENSORS SHOW NO DAMAGE TO ENEMY AT ";K(I,1);",";K(I,2):GOTO 4670 */
line_4500:;
    printf("%s", "SENSORS SHOW NO DAMAGE TO ENEMY AT "); printf("%g ", (double)(K_arr[(int)(I) * 100 + (int)(1)])); printf("%s", ","); printf("%g ", (double)(K_arr[(int)(I) * 100 + (int)(2)])); printf("\n");
    goto line_4670;
    /* BASIC: 4530 K(I,3)=K(I,3)-H:PRINT H;"UNIT HIT ON KLINGON AT SECTOR";K(I,1);","; */
line_4530:;
    K_arr[(int)(I) * 100 + (int)(3)] = K_arr[(int)(I) * 100 + (int)(3)]-H;
    printf("%g ", (double)(H)); printf("%s", "UNIT HIT ON KLINGON AT SECTOR"); printf("%g ", (double)(K_arr[(int)(I) * 100 + (int)(1)])); printf("%s", ",");
    /* BASIC: 4550 PRINT K(I,2):IF K(I,3)<=0 THEN PRINT"*** KLINGON DESTROYED ***":GOTO 4580 */
line_4550:;
    printf("%g ", (double)(K_arr[(int)(I) * 100 + (int)(2)])); printf("\n");
    if (K_arr[(int)(I) * 100 + (int)(3)]<=0) { printf("%s", "*** KLINGON DESTROYED ***"); printf("\n"); }
    goto line_4580;
    /* BASIC: 4560 PRINT"   (SENSORS SHOW";K(I,3);"UNITS REMAINING)":GOTO 4670 */
line_4560:;
    printf("%s", "   (SENSORS SHOW"); printf("%g ", (double)(K_arr[(int)(I) * 100 + (int)(3)])); printf("%s", "UNITS REMAINING)"); printf("\n");
    goto line_4670;
    /* BASIC: 4580 K3=K3-1:K9=K9-1:Z1=K(I,1):Z2=K(I,2):A$="   ":GOSUB 8670 */
line_4580:;
    K3 = K3-1;
    K9 = K9-1;
    Z1 = K_arr[(int)(I) * 100 + (int)(1)];
    Z2 = K_arr[(int)(I) * 100 + (int)(2)];
    str_assign(A_str, sizeof(A_str), "   ");
    gosub_stack[gosub_sp++] = 21; goto line_8670; line_ret_21:;
    /* BASIC: 4650 K(I,3)=0:G(Q1,Q2)=G(Q1,Q2)-100:Z(Q1,Q2)=G(Q1,Q2):IF K9<=0 THEN 6370 */
line_4650:;
    K_arr[(int)(I) * 100 + (int)(3)] = 0;
    G_arr[(int)(Q1) * 100 + (int)(Q2)] = G_arr[(int)(Q1) * 100 + (int)(Q2)]-100;
    Z_arr[(int)(Q1) * 100 + (int)(Q2)] = G_arr[(int)(Q1) * 100 + (int)(Q2)];
    if (K9<=0) { goto line_6370; }
    /* BASIC: 4670 NEXT I:GOSUB 6000:GOTO 1990 */
line_4670:;
    I += (1); goto for_loop_I_4450; end_for_I_4450:;
    gosub_stack[gosub_sp++] = 22; goto line_6000; line_ret_22:;
    goto line_1990;
    /* BASIC: 4690 REM PHO TO N T OR PEDO CODE BEGINS HERE */
line_4690:;
    /* REM PHO TO N T OR PEDO CODE BEGINS HERE */
    /* BASIC: 4700 IF P<=0 THEN PRINT"ALL PHOTON TORPEDOES EXPENDED":GOTO 1990 */
line_4700:;
    if (P<=0) { printf("%s", "ALL PHOTON TORPEDOES EXPENDED"); printf("\n"); goto line_1990; }
    /* BASIC: 4730 IF D(5)<0 THEN PRINT"PHOTON TUBES ARE NOT OPERATIONAL":GOTO 1990 */
line_4730:;
    if (D_arr[(int)(5)]<0) { printf("%s", "PHOTON TUBES ARE NOT OPERATIONAL"); printf("\n"); goto line_1990; }
    /* BASIC: 4760 INPUT"PHOTON TORPEDO COURSE (1-9)";C1:IF C1=9 THEN C1=1 */
line_4760:;
    printf("%s", "PHOTON TORPEDO COURSE (1-9)"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &C1);
    if (C1==9) { C1 = 1; }
    /* BASIC: 4780 IF C1>=1 AND C1<9 THEN 4850 */
line_4780:;
    if (C1>=1   &&   C1<9) { goto line_4850; }
    /* BASIC: 4790 PRINT"ENSIGN CHEKOV REPORTS,  'INCORRECT COURSE DATA, SIR!'" */
line_4790:;
    printf("%s", "ENSIGN CHEKOV REPORTS,  'INCORRECT COURSE DATA, SIR!'"); printf("\n");
    /* BASIC: 4800 GOTO 1990 */
line_4800:;
    goto line_1990;
    /* BASIC: 4850 X1=C(C1,1)+(C(C1+1,1)-C(C1,1))*(C1-INT(C1)):E=E-2:P=P-1 */
line_4850:;
    X1 = C_arr[(int)(C1) * 100 + (int)(1)]+(C_arr[(int)(C1+1) * 100 + (int)(1)]-C_arr[(int)(C1) * 100 + (int)(1)])*(C1-floor(C1));
    E = E-2;
    P = P-1;
    /* BASIC: 4860 X2=C(C1,2)+(C(C1+1,2)-C(C1,2))*(C1-INT(C1)):X=S1:Y=S2 */
line_4860:;
    X2 = C_arr[(int)(C1) * 100 + (int)(2)]+(C_arr[(int)(C1+1) * 100 + (int)(2)]-C_arr[(int)(C1) * 100 + (int)(2)])*(C1-floor(C1));
    X = S1;
    Y = S2;
    /* BASIC: 4910 PRINT"TORPEDO TRACK:" */
line_4910:;
    printf("%s", "TORPEDO TRACK:"); printf("\n");
    /* BASIC: 4920 X=X+X1:Y=Y+X2:X3=INT(X+.5):Y3=INT(Y+.5) */
line_4920:;
    X = X+X1;
    Y = Y+X2;
    X3 = floor(X+.5);
    Y3 = floor(Y+.5);
    /* BASIC: 4960 IF X3<1 OR X3>8 OR Y3<1 OR Y3>8 THEN 5490 */
line_4960:;
    if (X3<1   ||   X3>8   ||   Y3<1   ||   Y3>8) { goto line_5490; }
    /* BASIC: 5000 PRINT"               ";X3;",";Y3:A$="   ":Z1=X:Z2=Y:GOSUB 8830 */
line_5000:;
    printf("%s", "               "); printf("%g ", (double)(X3)); printf("%s", ","); printf("%g ", (double)(Y3)); printf("\n");
    str_assign(A_str, sizeof(A_str), "   ");
    Z1 = X;
    Z2 = Y;
    gosub_stack[gosub_sp++] = 23; goto line_8830; line_ret_23:;
    /* BASIC: 5050 IF Z3<>0 THEN 4920 */
line_5050:;
    if (Z3!=0) { goto line_4920; }
    /* BASIC: 5060 A$="+K+":Z1=X:Z2=Y:GOSUB 8830:IF Z3=0 THEN 5210 */
line_5060:;
    str_assign(A_str, sizeof(A_str), "+K+");
    Z1 = X;
    Z2 = Y;
    gosub_stack[gosub_sp++] = 24; goto line_8830; line_ret_24:;
    if (Z3==0) { goto line_5210; }
    /* BASIC: 5110 PRINT"*** KLINGON DESTROYED ***":K3=K3-1:K9=K9-1:IF K9<=0 THEN 6370 */
line_5110:;
    printf("%s", "*** KLINGON DESTROYED ***"); printf("\n");
    K3 = K3-1;
    K9 = K9-1;
    if (K9<=0) { goto line_6370; }
    /* BASIC: 5150 FOR I=1 TO 3:IF X3=K(I,1) AND Y3=K(I,2) THEN 5190 */
line_5150:;
    I = 1; for_loop_I_5150: if (((1) >= 0 && I > (3)) || ((1) < 0 && I < (3))) goto end_for_I_5150;
    if (X3==K_arr[(int)(I) * 100 + (int)(1)]   &&   Y3==K_arr[(int)(I) * 100 + (int)(2)]) { goto line_5190; }
    /* BASIC: 5180 NEXT I:I=3 */
line_5180:;
    I += (1); goto for_loop_I_5150; end_for_I_5150:;
    I = 3;
    /* BASIC: 5190 K(I,3)=0:GOTO 5430 */
line_5190:;
    K_arr[(int)(I) * 100 + (int)(3)] = 0;
    goto line_5430;
    /* BASIC: 5210 A$=" * ":Z1=X:Z2=Y:GOSUB 8830:IF Z3=0 THEN 5280 */
line_5210:;
    str_assign(A_str, sizeof(A_str), " * ");
    Z1 = X;
    Z2 = Y;
    gosub_stack[gosub_sp++] = 25; goto line_8830; line_ret_25:;
    if (Z3==0) { goto line_5280; }
    /* BASIC: 5260 PRINT"STAR AT";X3;",";Y3;"ABSORBED TORPEDO ENERGY.":GOSUB 6000:GOTO 1990 */
line_5260:;
    printf("%s", "STAR AT"); printf("%g ", (double)(X3)); printf("%s", ","); printf("%g ", (double)(Y3)); printf("%s", "ABSORBED TORPEDO ENERGY."); printf("\n");
    gosub_stack[gosub_sp++] = 26; goto line_6000; line_ret_26:;
    goto line_1990;
    /* BASIC: 5280 A$=">!<":Z1=X:Z2=Y:GOSUB 8830:IF Z3=0 THEN 4760 */
line_5280:;
    str_assign(A_str, sizeof(A_str), ">!<");
    Z1 = X;
    Z2 = Y;
    gosub_stack[gosub_sp++] = 27; goto line_8830; line_ret_27:;
    if (Z3==0) { goto line_4760; }
    /* BASIC: 5330 PRINT"*** STARBASE DESTROYED ***":B3=B3-1:B9=B9-1 */
line_5330:;
    printf("%s", "*** STARBASE DESTROYED ***"); printf("\n");
    B3 = B3-1;
    B9 = B9-1;
    /* BASIC: 5360 IF B9>0 OR K9>T-T0-T9 THEN 5400 */
line_5360:;
    if (B9>0   ||   K9>T-T0-T9) { goto line_5400; }
    /* BASIC: 5370 PRINT"THAT DOES IT, CAPTAIN!!  YOU ARE HEREBY RELIEVED OF COMMAND" */
line_5370:;
    printf("%s", "THAT DOES IT, CAPTAIN!!  YOU ARE HEREBY RELIEVED OF COMMAND"); printf("\n");
    /* BASIC: 5380 PRINT"AND SENTENCED TO 99 STARDATES AT HARD LABOR ON CYGNUS 12!!" */
line_5380:;
    printf("%s", "AND SENTENCED TO 99 STARDATES AT HARD LABOR ON CYGNUS 12!!"); printf("\n");
    /* BASIC: 5390 GOTO 6270 */
line_5390:;
    goto line_6270;
    /* BASIC: 5400 PRINT"STARFLEET COMMAND REVIEWING YOUR RECORD TO CONSIDER" */
line_5400:;
    printf("%s", "STARFLEET COMMAND REVIEWING YOUR RECORD TO CONSIDER"); printf("\n");
    /* BASIC: 5410 PRINT"COURT MARTIAL!":D0=0 */
line_5410:;
    printf("%s", "COURT MARTIAL!"); printf("\n");
    D0 = 0;
    /* BASIC: 5430 Z1=X:Z2=Y:A$="   ":GOSUB 8670 */
line_5430:;
    Z1 = X;
    Z2 = Y;
    str_assign(A_str, sizeof(A_str), "   ");
    gosub_stack[gosub_sp++] = 28; goto line_8670; line_ret_28:;
    /* BASIC: 5470 G(Q1,Q2)=K3*100+B3*10+S3:Z(Q1,Q2)=G(Q1,Q2):GOSUB 6000:GOTO 1990 */
line_5470:;
    G_arr[(int)(Q1) * 100 + (int)(Q2)] = K3*100+B3*10+S3;
    Z_arr[(int)(Q1) * 100 + (int)(Q2)] = G_arr[(int)(Q1) * 100 + (int)(Q2)];
    gosub_stack[gosub_sp++] = 29; goto line_6000; line_ret_29:;
    goto line_1990;
    /* BASIC: 5490 PRINT"TORPEDO MISSED":GOSUB 6000:GOTO 1990 */
line_5490:;
    printf("%s", "TORPEDO MISSED"); printf("\n");
    gosub_stack[gosub_sp++] = 30; goto line_6000; line_ret_30:;
    goto line_1990;
    /* BASIC: 5520 REM SHIELD CONTROL */
line_5520:;
    /* REM SHIELD CONTROL */
    /* BASIC: 5530 IF D(7)<0 THEN PRINT"SHIELD CONTROL INOPERABLE":GOTO 1990 */
line_5530:;
    if (D_arr[(int)(7)]<0) { printf("%s", "SHIELD CONTROL INOPERABLE"); printf("\n"); goto line_1990; }
    /* BASIC: 5560 PRINT"ENERGY AVAILABLE =";E+S;:INPUT"NUMBER OF UNITS TO SHIELDS";X */
line_5560:;
    printf("%s", "ENERGY AVAILABLE ="); printf("%g ", (double)(E+S));
    printf("%s", "NUMBER OF UNITS TO SHIELDS"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &X);
    /* BASIC: 5580 IF X<0 OR S=X THEN PRINT"<SHIELDS UNCHANGED>":GOTO 1990 */
line_5580:;
    if (X<0   ||   S==X) { printf("%s", "<SHIELDS UNCHANGED>"); printf("\n"); goto line_1990; }
    /* BASIC: 5590 IF X<=E+S THEN 5630 */
line_5590:;
    if (X<=E+S) { goto line_5630; }
    /* BASIC: 5600 PRINT"SHIELD CONTROL REPORTS  'THIS IS NOT THE FEDERATION TREASURY.'" */
line_5600:;
    printf("%s", "SHIELD CONTROL REPORTS  'THIS IS NOT THE FEDERATION TREASURY.'"); printf("\n");
    /* BASIC: 5610 PRINT"<SHIELDS UNCHANGED>":GOTO 1990 */
line_5610:;
    printf("%s", "<SHIELDS UNCHANGED>"); printf("\n");
    goto line_1990;
    /* BASIC: 5630 E=E+S-X:S=X:PRINT"DEFLECTOR CONTROL ROOM REPORT:" */
line_5630:;
    E = E+S-X;
    S = X;
    printf("%s", "DEFLECTOR CONTROL ROOM REPORT:"); printf("\n");
    /* BASIC: 5660 PRINT"  'SHIELDS NOW AT";INT(S);"UNITS PER YOUR COMMAND.'":GOTO 1990 */
line_5660:;
    printf("%s", "  'SHIELDS NOW AT"); printf("%g ", (double)(floor(S))); printf("%s", "UNITS PER YOUR COMMAND.'"); printf("\n");
    goto line_1990;
    /* BASIC: 5680 REM DAMAGE CONTROL */
line_5680:;
    /* REM DAMAGE CONTROL */
    /* BASIC: 5690 IF D(6)>=0 THEN 5910 */
line_5690:;
    if (D_arr[(int)(6)]>=0) { goto line_5910; }
    /* BASIC: 5700 PRINT"DAMAGE CONTROL REPORT NOT AVAILABLE":IF D0=0 THEN 1990 */
line_5700:;
    printf("%s", "DAMAGE CONTROL REPORT NOT AVAILABLE"); printf("\n");
    if (D0==0) { goto line_1990; }
    /* BASIC: 5720 D3=0:FOR I=1 TO 8:IF D(I)<0 THEN D3=D3+.1 */
line_5720:;
    D3 = 0;
    I = 1; for_loop_I_5720: if (((1) >= 0 && I > (8)) || ((1) < 0 && I < (8))) goto end_for_I_5720;
    if (D_arr[(int)(I)]<0) { D3 = D3+.1; }
    /* BASIC: 5760 NEXT I:IF D3=0 THEN 1990 */
line_5760:;
    I += (1); goto for_loop_I_5720; end_for_I_5720:;
    if (D3==0) { goto line_1990; }
    /* BASIC: 5780 PRINT:D3=D3+D4:IF D3>=1 THEN D3=.9 */
line_5780:;
    printf("\n");
    D3 = D3+D4;
    if (D3>=1) { D3 = .9; }
    /* BASIC: 5810 PRINT"TECHNICIANS STANDING BY TO EFFECT REPAIRS TO YOUR SHIP;" */
line_5810:;
    printf("%s", "TECHNICIANS STANDING BY TO EFFECT REPAIRS TO YOUR SHIP;"); printf("\n");
    /* BASIC: 5820 PRINT"ESTIMATED TIME TO REPAIR:";.01*INT(100*D3);"STARDATES" */
line_5820:;
    printf("%s", "ESTIMATED TIME TO REPAIR:"); printf("%g ", (double)(.01*floor(100*D3))); printf("%s", "STARDATES"); printf("\n");
    /* BASIC: 5840 INPUT "WILL YOU AUTHORIZE THE REPAIR ORDER (Y/N)";A$ */
line_5840:;
    printf("%s", "WILL YOU AUTHORIZE THE REPAIR ORDER (Y/N)"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    /* BASIC: 5860 IF A$<>"Y" THEN 1990 */
line_5860:;
    if (strcmp(A_str, "Y") != 0) { goto line_1990; }
    /* BASIC: 5870 FOR I=1 TO 8:IF D(I)<0 THEN D(I)=0 */
line_5870:;
    I = 1; for_loop_I_5870: if (((1) >= 0 && I > (8)) || ((1) < 0 && I < (8))) goto end_for_I_5870;
    if (D_arr[(int)(I)]<0) { D_arr[(int)(I)] = 0; }
    /* BASIC: 5890 NEXT I:T=T+D3+.1 */
line_5890:;
    I += (1); goto for_loop_I_5870; end_for_I_5870:;
    T = T+D3+.1;
    /* BASIC: 5910 PRINT:PRINT"DEVICE             STATE OF REPAIR":FOR R1=1 TO 8 */
line_5910:;
    printf("\n");
    printf("%s", "DEVICE             STATE OF REPAIR"); printf("\n");
    R1 = 1; for_loop_R1_5910: if (((1) >= 0 && R1 > (8)) || ((1) < 0 && R1 < (8))) goto end_for_R1_5910;
    /* BASIC: 5920 GOSUB 8790:PRINT G2$;LEFT$(Z$,25-LEN(G2$));INT(D(R1)*100)*.01 */
line_5920:;
    gosub_stack[gosub_sp++] = 31; goto line_8790; line_ret_31:;
    printf("%s", G2_str); printf("%s", basic_LEFT(Z_str,25-basic_LEN(G2_str))); printf("%g ", (double)(floor(D_arr[(int)(R1)]*100)*.01)); printf("\n");
    /* BASIC: 5950 NEXT R1:PRINT:IF D0<>0 THEN 5720 */
line_5950:;
    R1 += (1); goto for_loop_R1_5910; end_for_R1_5910:;
    printf("\n");
    if (D0!=0) { goto line_5720; }
    /* BASIC: 5980 GOTO 1990 */
line_5980:;
    goto line_1990;
    /* BASIC: 5990 REM KLINGONS SHOOTING */
line_5990:;
    /* REM KLINGONS SHOOTING */
    /* BASIC: 6000 IF K3<=0 THEN RETURN */
line_6000:;
    if (K3<=0) { switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     case 27: goto line_ret_27;     case 28: goto line_ret_28;     case 29: goto line_ret_29;     case 30: goto line_ret_30;     case 31: goto line_ret_31;     case 32: goto line_ret_32;     case 33: goto line_ret_33;     case 34: goto line_ret_34;     case 35: goto line_ret_35;     case 36: goto line_ret_36;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); } }
    /* BASIC: 6010 IF D0<>0 THEN PRINT"STARBASE SHIELDS PROTECT THE ENTERPRISE":RETURN */
line_6010:;
    if (D0!=0) { printf("%s", "STARBASE SHIELDS PROTECT THE ENTERPRISE"); printf("\n"); switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     case 27: goto line_ret_27;     case 28: goto line_ret_28;     case 29: goto line_ret_29;     case 30: goto line_ret_30;     case 31: goto line_ret_31;     case 32: goto line_ret_32;     case 33: goto line_ret_33;     case 34: goto line_ret_34;     case 35: goto line_ret_35;     case 36: goto line_ret_36;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); } }
    /* BASIC: 6040 FOR I=1 TO 3:IF K(I,3)<=0 THEN 6200 */
line_6040:;
    I = 1; for_loop_I_6040: if (((1) >= 0 && I > (3)) || ((1) < 0 && I < (3))) goto end_for_I_6040;
    if (K_arr[(int)(I) * 100 + (int)(3)]<=0) { goto line_6200; }
    /* BASIC: 6060 H=INT((K(I,3)/FND(1))*(2+RND(1))):S=S-H:K(I,3)=K(I,3)/(3+RND(0)) */
line_6060:;
    H = floor((K_arr[(int)(I) * 100 + (int)(3)]/FND(1))*(2+((double)rand() / (double)RAND_MAX)));
    S = S-H;
    K_arr[(int)(I) * 100 + (int)(3)] = K_arr[(int)(I) * 100 + (int)(3)]/(3+((double)rand() / (double)RAND_MAX));
    /* BASIC: 6080 PRINT H;"UNIT HIT ON ENTERPRISE FROM SECTOR";K(I,1);",";K(I,2) */
line_6080:;
    printf("%g ", (double)(H)); printf("%s", "UNIT HIT ON ENTERPRISE FROM SECTOR"); printf("%g ", (double)(K_arr[(int)(I) * 100 + (int)(1)])); printf("%s", ","); printf("%g ", (double)(K_arr[(int)(I) * 100 + (int)(2)])); printf("\n");
    /* BASIC: 6090 IF S<=0 THEN 6240 */
line_6090:;
    if (S<=0) { goto line_6240; }
    /* BASIC: 6100 PRINT"      <SHIELDS DOWN TO";S;"UNITS>":IF H<20 THEN 6200 */
line_6100:;
    printf("%s", "      <SHIELDS DOWN TO"); printf("%g ", (double)(S)); printf("%s", "UNITS>"); printf("\n");
    if (H<20) { goto line_6200; }
    /* BASIC: 6120 IF RND(1)>.6 OR H/S<=.02 THEN 6200 */
line_6120:;
    if (((double)rand() / (double)RAND_MAX)>.6   ||   H/S<=.02) { goto line_6200; }
    /* BASIC: 6140 R1=FNR(1):D(R1)=D(R1)-H/S-.5*RND(1):GOSUB 8790 */
line_6140:;
    R1 = FNR(1);
    D_arr[(int)(R1)] = D_arr[(int)(R1)]-H/S-.5*((double)rand() / (double)RAND_MAX);
    gosub_stack[gosub_sp++] = 32; goto line_8790; line_ret_32:;
    /* BASIC: 6170 PRINT"DAMAGE CONTROL REPORTS ";G2$;" DAMAGED BY THE HIT'" */
line_6170:;
    printf("%s", "DAMAGE CONTROL REPORTS "); printf("%s", G2_str); printf("%s", " DAMAGED BY THE HIT'"); printf("\n");
    /* BASIC: 6200 NEXT I:RETURN */
line_6200:;
    I += (1); goto for_loop_I_6040; end_for_I_6040:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     case 27: goto line_ret_27;     case 28: goto line_ret_28;     case 29: goto line_ret_29;     case 30: goto line_ret_30;     case 31: goto line_ret_31;     case 32: goto line_ret_32;     case 33: goto line_ret_33;     case 34: goto line_ret_34;     case 35: goto line_ret_35;     case 36: goto line_ret_36;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 6210 REM END OF GAME */
line_6210:;
    /* REM END OF GAME */
    /* BASIC: 6220 PRINT"IT IS STARDATE";T:GOTO 6270 */
line_6220:;
    printf("%s", "IT IS STARDATE"); printf("%g ", (double)(T)); printf("\n");
    goto line_6270;
    /* BASIC: 6240 PRINT:PRINT"THE ENTERPRISE HAS BEEN DESTROYED.  THEN FEDERATION "; */
line_6240:;
    printf("\n");
    printf("%s", "THE ENTERPRISE HAS BEEN DESTROYED.  THEN FEDERATION ");
    /* BASIC: 6250 PRINT"WILL BE CONQUERED":GOTO 6220 */
line_6250:;
    printf("%s", "WILL BE CONQUERED"); printf("\n");
    goto line_6220;
    /* BASIC: 6270 PRINT"THERE WERE";K9;"KLINGON BATTLE CRUISERS LEFT AT" */
line_6270:;
    printf("%s", "THERE WERE"); printf("%g ", (double)(K9)); printf("%s", "KLINGON BATTLE CRUISERS LEFT AT"); printf("\n");
    /* BASIC: 6280 PRINT"THE END OF YOUR MISSION." */
line_6280:;
    printf("%s", "THE END OF YOUR MISSION."); printf("\n");
    /* BASIC: 6290 PRINT:PRINT:IF B9=0 THEN 6360 */
line_6290:;
    printf("\n");
    printf("\n");
    if (B9==0) { goto line_6360; }
    /* BASIC: 6310 PRINT"THE FEDERATION IS IN NEED OF A NEW STARSHIP COMMANDER" */
line_6310:;
    printf("%s", "THE FEDERATION IS IN NEED OF A NEW STARSHIP COMMANDER"); printf("\n");
    /* BASIC: 6320 PRINT"FOR A SIMILAR MISSION -- IF THERE IS A VOLUNTEER," */
line_6320:;
    printf("%s", "FOR A SIMILAR MISSION -- IF THERE IS A VOLUNTEER,"); printf("\n");
    /* BASIC: 6330 INPUT"LET HIM STEP FORWARD AND ENTER 'AYE'";A$:IF A$="AYE" THEN 10 */
line_6330:;
    printf("%s", "LET HIM STEP FORWARD AND ENTER 'AYE'"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A_str);
    if (strcmp(A_str, "AYE") == 0) { goto line_10; }
    /* BASIC: 6360 END */
line_6360:;
    exit(0);
    /* BASIC: 6370 PRINT"CONGRULATION, CAPTAIN!  THEN LAST KLINGON BATTLE CRUISER" */
line_6370:;
    printf("%s", "CONGRULATION, CAPTAIN!  THEN LAST KLINGON BATTLE CRUISER"); printf("\n");
    /* BASIC: 6380 PRINT"MENACING THE FDERATION HAS BEEN DESTROYED.":PRINT */
line_6380:;
    printf("%s", "MENACING THE FDERATION HAS BEEN DESTROYED."); printf("\n");
    printf("\n");
    /* BASIC: 6400 PRINT"YOUR EFFICIENCY RATING IS";1000*(K7/(T-T0))^2:GOTO 6290 */
line_6400:;
    printf("%s", "YOUR EFFICIENCY RATING IS"); printf("%g ", (double)(1000*pow((K7/(T-T0)), 2))); printf("\n");
    goto line_6290;
    /* BASIC: 6420 REM SH OR T RANGE SENS OR SCAN & STARTUP SUBROUTINE */
line_6420:;
    /* REM SH OR T RANGE SENS OR SCAN & STARTUP SUBROUTINE */
    /* BASIC: 6430 FOR I=S1-1 TO S1+1:FOR J=S2-1 TO S2+1 */
line_6430:;
    I = S1-1; for_loop_I_6430: if (((1) >= 0 && I > (S1+1)) || ((1) < 0 && I < (S1+1))) goto end_for_I_6430;
    J = S2-1; for_loop_J_6430: if (((1) >= 0 && J > (S2+1)) || ((1) < 0 && J < (S2+1))) goto end_for_J_6430;
    /* BASIC: 6450 IF INT(I+.5)<1 OR INT(I+.5)>8 OR INT(J+.5)<1 OR INT(J+.5)>8 THEN 6540 */
line_6450:;
    if (floor(I+.5)<1   ||   floor(I+.5)>8   ||   floor(J+.5)<1   ||   floor(J+.5)>8) { goto line_6540; }
    /* BASIC: 6490 A$=">!<":Z1=I:Z2=J:GOSUB 8830:IF Z3=1 THEN 6580 */
line_6490:;
    str_assign(A_str, sizeof(A_str), ">!<");
    Z1 = I;
    Z2 = J;
    gosub_stack[gosub_sp++] = 33; goto line_8830; line_ret_33:;
    if (Z3==1) { goto line_6580; }
    /* BASIC: 6540 NEXT J:NEXT I:D0=0:GOTO 6650 */
line_6540:;
    J += (1); goto for_loop_J_6430; end_for_J_6430:;
    I += (1); goto for_loop_I_6430; end_for_I_6430:;
    D0 = 0;
    goto line_6650;
    /* BASIC: 6580 D0=1:C$="DOCKED":E=E0:P=P0 */
line_6580:;
    D0 = 1;
    str_assign(C_str, sizeof(C_str), "DOCKED");
    E = E0;
    P = P0;
    /* BASIC: 6620 PRINT"SHIELDS DROPPED FOR DOCKING PURPOSES":S=0:GOTO 6720 */
line_6620:;
    printf("%s", "SHIELDS DROPPED FOR DOCKING PURPOSES"); printf("\n");
    S = 0;
    goto line_6720;
    /* BASIC: 6650 IF K3>0 THEN C$="*RED*":GOTO 6720 */
line_6650:;
    if (K3>0) { str_assign(C_str, sizeof(C_str), "*RED*"); goto line_6720; }
    /* BASIC: 6660 C$="GREEN":IF E<E0*.1 THEN C$="YELLOW" */
line_6660:;
    str_assign(C_str, sizeof(C_str), "GREEN");
    if (E<E0*.1) { str_assign(C_str, sizeof(C_str), "YELLOW"); }
    /* BASIC: 6720 IF D(2)>=0 THEN 6770 */
line_6720:;
    if (D_arr[(int)(2)]>=0) { goto line_6770; }
    /* BASIC: 6730 PRINT:PRINT"*** SHORT RANGE SENSORS ARE OUT ***":PRINT:RETURN */
line_6730:;
    printf("\n");
    printf("%s", "*** SHORT RANGE SENSORS ARE OUT ***"); printf("\n");
    printf("\n");
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     case 27: goto line_ret_27;     case 28: goto line_ret_28;     case 29: goto line_ret_29;     case 30: goto line_ret_30;     case 31: goto line_ret_31;     case 32: goto line_ret_32;     case 33: goto line_ret_33;     case 34: goto line_ret_34;     case 35: goto line_ret_35;     case 36: goto line_ret_36;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 6770 O1$="---------------------------------":PRINT O1$:FOR I=1 TO 8 */
line_6770:;
    str_assign(O1_str, sizeof(O1_str), "---------------------------------");
    printf("%s", O1_str); printf("\n");
    I = 1; for_loop_I_6770: if (((1) >= 0 && I > (8)) || ((1) < 0 && I < (8))) goto end_for_I_6770;
    /* BASIC: 6820 FOR J=(I-1)*24+1 TO (I-1)*24+22 STEP 3:PRINT" ";MID$(Q$,J,3);:NEXT J */
line_6820:;
    J = (I-1)*24+1; for_loop_J_6820: if (((3) >= 0 && J > ((I-1)*24+22)) || ((3) < 0 && J < ((I-1)*24+22))) goto end_for_J_6820;
    printf("%s", " "); printf("%s", basic_MID(Q_str,J,3));
    J += (3); goto for_loop_J_6820; end_for_J_6820:;
    /* BASIC: 6830 ONIGO TO 6850,6900,6960,7020,7070,7120,7180,7240 */
line_6830:;
    /* UNTRANSLATED: ONIGO TO 6850,6900,6960,7020,7070,7120,7180,7240 */
    /* BASIC: 6850 PRINT"        STARDATE          ";INT(T*10)*.1:GOTO 7260 */
line_6850:;
    printf("%s", "        STARDATE          "); printf("%g ", (double)(floor(T*10)*.1)); printf("\n");
    goto line_7260;
    /* BASIC: 6900 PRINT"        CONDITION          ";C$:GOTO 7260 */
line_6900:;
    printf("%s", "        CONDITION          "); printf("%s", C_str); printf("\n");
    goto line_7260;
    /* BASIC: 6960 PRINT"        QUADRANT          ";Q1;",";Q2:GOTO 7260 */
line_6960:;
    printf("%s", "        QUADRANT          "); printf("%g ", (double)(Q1)); printf("%s", ","); printf("%g ", (double)(Q2)); printf("\n");
    goto line_7260;
    /* BASIC: 7020 PRINT"        SECTOR            ";S1;",";S2:GOTO 7260 */
line_7020:;
    printf("%s", "        SECTOR            "); printf("%g ", (double)(S1)); printf("%s", ","); printf("%g ", (double)(S2)); printf("\n");
    goto line_7260;
    /* BASIC: 7070 PRINT"        PHOTON TORPEDOES  ";INT(P):GOTO 7260 */
line_7070:;
    printf("%s", "        PHOTON TORPEDOES  "); printf("%g ", (double)(floor(P))); printf("\n");
    goto line_7260;
    /* BASIC: 7120 PRINT"        TOTAL ENERGY      ";INT(E+S):GOTO 7260 */
line_7120:;
    printf("%s", "        TOTAL ENERGY      "); printf("%g ", (double)(floor(E+S))); printf("\n");
    goto line_7260;
    /* BASIC: 7180 PRINT"        SHIELDS           ";INT(S):GOTO 7260 */
line_7180:;
    printf("%s", "        SHIELDS           "); printf("%g ", (double)(floor(S))); printf("\n");
    goto line_7260;
    /* BASIC: 7240 PRINT"        KLINGONS REMAINING";INT(K9) */
line_7240:;
    printf("%s", "        KLINGONS REMAINING"); printf("%g ", (double)(floor(K9))); printf("\n");
    /* BASIC: 7260 NEXT I:PRINT O1$:RETURN */
line_7260:;
    I += (1); goto for_loop_I_6770; end_for_I_6770:;
    printf("%s", O1_str); printf("\n");
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     case 27: goto line_ret_27;     case 28: goto line_ret_28;     case 29: goto line_ret_29;     case 30: goto line_ret_30;     case 31: goto line_ret_31;     case 32: goto line_ret_32;     case 33: goto line_ret_33;     case 34: goto line_ret_34;     case 35: goto line_ret_35;     case 36: goto line_ret_36;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 7280 REM LIBRARY COMPUTER CODE */
line_7280:;
    /* REM LIBRARY COMPUTER CODE */
    /* BASIC: 7290 IF D(8)<0 THEN PRINT"COMPUTER DISABLED":GOTO 1990 */
line_7290:;
    if (D_arr[(int)(8)]<0) { printf("%s", "COMPUTER DISABLED"); printf("\n"); goto line_1990; }
    /* BASIC: 7320 INPUT"COMPUTER ACTIVE AND AWAITING COMMAND";A:IF A<0 THEN 1990 */
line_7320:;
    printf("%s", "COMPUTER ACTIVE AND AWAITING COMMAND"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &A);
    if (A<0) { goto line_1990; }
    /* BASIC: 7350 PRINT:H8=1:ONA+1GO TO 7540,7900,8070,8500,8150,7400 */
line_7350:;
    printf("\n");
    H8 = 1;
    /* UNTRANSLATED: ONA+1GO TO 7540,7900,8070,8500,8150,7400 */
    /* BASIC: 7360 PRINT"FUNCTIONS AVAILABLE FROM LIBRARY-COMPUTER:" */
line_7360:;
    printf("%s", "FUNCTIONS AVAILABLE FROM LIBRARY-COMPUTER:"); printf("\n");
    /* BASIC: 7370 PRINT"   0 = CUMULATIVE GALACTIC RECORD" */
line_7370:;
    printf("%s", "   0 = CUMULATIVE GALACTIC RECORD"); printf("\n");
    /* BASIC: 7372 PRINT"   1 = STATUS REPORT" */
line_7372:;
    printf("%s", "   1 = STATUS REPORT"); printf("\n");
    /* BASIC: 7374 PRINT"   2 = PHOTON TORPEDO DATA" */
line_7374:;
    printf("%s", "   2 = PHOTON TORPEDO DATA"); printf("\n");
    /* BASIC: 7376 PRINT"   3 = STARBASE NAV DATA" */
line_7376:;
    printf("%s", "   3 = STARBASE NAV DATA"); printf("\n");
    /* BASIC: 7378 PRINT"   4 = DIRECTION/DISTANCE CALCULATOR" */
line_7378:;
    printf("%s", "   4 = DIRECTION/DISTANCE CALCULATOR"); printf("\n");
    /* BASIC: 7380 PRINT"   5 = GALAXY 'REGION NAME' MAP":PRINT:GOTO 7320 */
line_7380:;
    printf("%s", "   5 = GALAXY 'REGION NAME' MAP"); printf("\n");
    printf("\n");
    goto line_7320;
    /* BASIC: 7390 REM SETUP TO CHANGE CUM GAL REC OR D TO GALAXY MAP */
line_7390:;
    /* REM SETUP TO CHANGE CUM GAL REC OR D TO GALAXY MAP */
    /* BASIC: 7400 H8=0:G5=1:PRINT"                        THE GALAXY":GOTO 7550 */
line_7400:;
    H8 = 0;
    G5 = 1;
    printf("%s", "                        THE GALAXY"); printf("\n");
    goto line_7550;
    /* BASIC: 7530 REM CUM GALACTIC REC OR D */
line_7530:;
    /* REM CUM GALACTIC REC OR D */
    /* BASIC: 7540 REM INPUT"DO YOU WANT A HARDCOPY? IS THE TTY ON (Y/N)";A$ */
line_7540:;
    /* REM INPUT"DO YOU WANT A HARDCOPY? IS THE TTY ON (Y/N)";A$ */
    /* BASIC: 7542 REM IF A$="Y" THEN POKE1229,2:POKE1237,3:NULL1 */
line_7542:;
    /* REM IF A$="Y" THEN POKE1229,2 */
    /* UNTRANSLATED: POKE1237,3 */
    /* UNTRANSLATED: NULL1 */
    /* BASIC: 7543 PRINT:PRINT"        "; */
line_7543:;
    printf("\n");
    printf("%s", "        ");
    /* BASIC: 7544 PRINT"COMPUTER RECORD OF GALAXY FOR QUADRANT";Q1;",";Q2 */
line_7544:;
    printf("%s", "COMPUTER RECORD OF GALAXY FOR QUADRANT"); printf("%g ", (double)(Q1)); printf("%s", ","); printf("%g ", (double)(Q2)); printf("\n");
    /* BASIC: 7546 PRINT */
line_7546:;
    printf("\n");
    /* BASIC: 7550 PRINT"       1     2     3     4     5     6     7     8" */
line_7550:;
    printf("%s", "       1     2     3     4     5     6     7     8"); printf("\n");
    /* BASIC: 7560 O1$="     ----- ----- ----- ----- ----- ----- ----- -----" */
line_7560:;
    str_assign(O1_str, sizeof(O1_str), "     ----- ----- ----- ----- ----- ----- ----- -----");
    /* BASIC: 7570 PRINT O1$:FOR I=1 TO 8:PRINT I;:IF H8=0 THEN 7740 */
line_7570:;
    printf("%s", O1_str); printf("\n");
    I = 1; for_loop_I_7570: if (((1) >= 0 && I > (8)) || ((1) < 0 && I < (8))) goto end_for_I_7570;
    printf("%g ", (double)(I));
    if (H8==0) { goto line_7740; }
    /* BASIC: 7630 FOR J=1 TO 8:PRINT"   ";:IF Z(I,J)=0 THEN PRINT"***";:GOTO 7720 */
line_7630:;
    J = 1; for_loop_J_7630: if (((1) >= 0 && J > (8)) || ((1) < 0 && J < (8))) goto end_for_J_7630;
    printf("%s", "   ");
    if (Z_arr[(int)(I) * 100 + (int)(J)]==0) { printf("%s", "***"); }
    goto line_7720;
    /* BASIC: 7700 PRINT RIGHT$(STR$(Z(I,J)+1000),3); */
line_7700:;
    printf("%s", basic_RIGHT(basic_STR(Z_arr[(int)(I) * 100 + (int)(J)]+1000),3));
    /* BASIC: 7720 NEXT J:GOTO 7850 */
line_7720:;
    J += (1); goto for_loop_J_7630; end_for_J_7630:;
    goto line_7850;
    /* BASIC: 7740 Z4=I:Z5=1:GOSUB 9030:J0=INT(15-.5*LEN(G2$)):PRINT TAB(J0);G2$; */
line_7740:;
    Z4 = I;
    Z5 = 1;
    gosub_stack[gosub_sp++] = 34; goto line_9030; line_ret_34:;
    J0 = floor(15-.5*basic_LEN(G2_str));
    { int _t; for(_t=0; _t<J0; _t++) printf(" "); } printf("%s", G2_str);
    /* BASIC: 7800 Z5=5:GOSUB 9030:J0=INT(39-.5*LEN(G2$)):PRINT TAB(J0);G2$; */
line_7800:;
    Z5 = 5;
    gosub_stack[gosub_sp++] = 35; goto line_9030; line_ret_35:;
    J0 = floor(39-.5*basic_LEN(G2_str));
    { int _t; for(_t=0; _t<J0; _t++) printf(" "); } printf("%s", G2_str);
    /* BASIC: 7850 PRINT:PRINT O1$:NEXT I:PRINT:GOTO 1990 */
line_7850:;
    printf("\n");
    printf("%s", O1_str); printf("\n");
    I += (1); goto for_loop_I_7570; end_for_I_7570:;
    printf("\n");
    goto line_1990;
    /* BASIC: 7890 REM STATUS REP OR T */
line_7890:;
    /* REM STATUS REP OR T */
    /* BASIC: 7900 PRINT "   STATUS REPORT:":X$="":IF K9>1 THEN X$="S" */
line_7900:;
    printf("%s", "   STATUS REPORT:"); printf("\n");
    str_assign(X_str, sizeof(X_str), "");
    if (K9>1) { str_assign(X_str, sizeof(X_str), "S"); }
    /* BASIC: 7940 PRINT"KLINGON";X$;" LEFT: ";K9 */
line_7940:;
    printf("%s", "KLINGON"); printf("%s", X_str); printf("%s", " LEFT: "); printf("%g ", (double)(K9)); printf("\n");
    /* BASIC: 7960 PRINT"MISSION MUST BE COMPLETED IN";.1*INT((T0+T9-T)*10);"STARDATES" */
line_7960:;
    printf("%s", "MISSION MUST BE COMPLETED IN"); printf("%g ", (double)(.1*floor((T0+T9-T)*10))); printf("%s", "STARDATES"); printf("\n");
    /* BASIC: 7970 X$="S":IF B9<2 THEN X$="":IF B9<1 THEN 8010 */
line_7970:;
    str_assign(X_str, sizeof(X_str), "S");
    if (B9<2) { str_assign(X_str, sizeof(X_str), ""); }
    if (B9<1) { goto line_8010; }
    /* BASIC: 7980 PRINT"THE FEDERATION IS MAINTAINING";B9;"STARBASE";X$;" IN THE GALAXY" */
line_7980:;
    printf("%s", "THE FEDERATION IS MAINTAINING"); printf("%g ", (double)(B9)); printf("%s", "STARBASE"); printf("%s", X_str); printf("%s", " IN THE GALAXY"); printf("\n");
    /* BASIC: 7990 GOTO 5690 */
line_7990:;
    goto line_5690;
    /* BASIC: 8010 PRINT"YOUR STUPIDITY HAS LEFT YOU ON YOUR ON IN" */
line_8010:;
    printf("%s", "YOUR STUPIDITY HAS LEFT YOU ON YOUR ON IN"); printf("\n");
    /* BASIC: 8020 PRINT"  THE GALAXY -- YOU HAVE NO STARBASES LEFT!":GOTO 5690 */
line_8020:;
    printf("%s", "  THE GALAXY -- YOU HAVE NO STARBASES LEFT!"); printf("\n");
    goto line_5690;
    /* BASIC: 8060 REM T OR PEDO, BASE NAV, D/D CALCULAT OR */
line_8060:;
    /* REM T OR PEDO, BASE NAV, D/D CALCULAT OR */
    /* BASIC: 8070 IF K3<=0 THEN 4270 */
line_8070:;
    if (K3<=0) { goto line_4270; }
    /* BASIC: 8080 X$="":IF K3>1 THEN X$="S" */
line_8080:;
    str_assign(X_str, sizeof(X_str), "");
    if (K3>1) { str_assign(X_str, sizeof(X_str), "S"); }
    /* BASIC: 8090 PRINT"FROM ENTERPRISE TO KLINGON BATTLE CRUSER";X$ */
line_8090:;
    printf("%s", "FROM ENTERPRISE TO KLINGON BATTLE CRUSER"); printf("%s", X_str); printf("\n");
    /* BASIC: 8100 H8=0:FOR I=1 TO 3:IF K(I,3)<=0 THEN 8480 */
line_8100:;
    H8 = 0;
    I = 1; for_loop_I_8100: if (((1) >= 0 && I > (3)) || ((1) < 0 && I < (3))) goto end_for_I_8100;
    if (K_arr[(int)(I) * 100 + (int)(3)]<=0) { goto line_8480; }
    /* BASIC: 8110 W1=K(I,1):X=K(I,2) */
line_8110:;
    W1 = K_arr[(int)(I) * 100 + (int)(1)];
    X = K_arr[(int)(I) * 100 + (int)(2)];
    /* BASIC: 8120 C1=S1:A=S2:GOTO 8220 */
line_8120:;
    C1 = S1;
    A = S2;
    goto line_8220;
    /* BASIC: 8150 PRINT"DIRECTION/DISTANCE CALCULATOR:" */
line_8150:;
    printf("%s", "DIRECTION/DISTANCE CALCULATOR:"); printf("\n");
    /* BASIC: 8160 PRINT"YOU ARE AT QUADRANT ";Q1;",";Q2;" SECTOR ";S1;",";S2 */
line_8160:;
    printf("%s", "YOU ARE AT QUADRANT "); printf("%g ", (double)(Q1)); printf("%s", ","); printf("%g ", (double)(Q2)); printf("%s", " SECTOR "); printf("%g ", (double)(S1)); printf("%s", ","); printf("%g ", (double)(S2)); printf("\n");
    /* BASIC: 8170 PRINT"PLEASE ENTER":INPUT"  INITIAL COORDINATES (X,Y)";C1,A */
line_8170:;
    printf("%s", "PLEASE ENTER"); printf("\n");
    printf("%s", "  INITIAL COORDINATES (X,Y)"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf", &C1, &A);
    /* BASIC: 8200 INPUT"  FINAL COORDINATES (X,Y)";W1,X */
line_8200:;
    printf("%s", "  FINAL COORDINATES (X,Y)"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf %lf", &W1, &X);
    /* BASIC: 8220 X=X-A:A=C1-W1:IF X<0 THEN 8350 */
line_8220:;
    X = X-A;
    A = C1-W1;
    if (X<0) { goto line_8350; }
    /* BASIC: 8250 IF A<0 THEN 8410 */
line_8250:;
    if (A<0) { goto line_8410; }
    /* BASIC: 8260 IF X>0 THEN 8280 */
line_8260:;
    if (X>0) { goto line_8280; }
    /* BASIC: 8270 IF A=0 THEN C1=5:GOTO 8290 */
line_8270:;
    if (A==0) { C1 = 5; goto line_8290; }
    /* BASIC: 8280 C1=1 */
line_8280:;
    C1 = 1;
    /* BASIC: 8290 IF ABS(A)<=ABS(X) THEN 8330 */
line_8290:;
    if (fabs(A)<=fabs(X)) { goto line_8330; }
    /* BASIC: 8310 PRINT"DIRECTION =";C1+(((ABS(A)-ABS(X))+ABS(A))/ABS(A)):GOTO 8460 */
line_8310:;
    printf("%s", "DIRECTION ="); printf("%g ", (double)(C1+(((fabs(A)-fabs(X))+fabs(A))/fabs(A)))); printf("\n");
    goto line_8460;
    /* BASIC: 8330 PRINT"DIRECTION =";C1+(ABS(A)/ABS(X)):GOTO 8460 */
line_8330:;
    printf("%s", "DIRECTION ="); printf("%g ", (double)(C1+(fabs(A)/fabs(X)))); printf("\n");
    goto line_8460;
    /* BASIC: 8350 IF A>0 THEN C1=3:GOTO 8420 */
line_8350:;
    if (A>0) { C1 = 3; goto line_8420; }
    /* BASIC: 8360 IF X<>0 THEN C1=5:GOTO 8290 */
line_8360:;
    if (X!=0) { C1 = 5; goto line_8290; }
    /* BASIC: 8410 C1=7 */
line_8410:;
    C1 = 7;
    /* BASIC: 8420 IF ABS(A)>=ABS(X) THEN 8450 */
line_8420:;
    if (fabs(A)>=fabs(X)) { goto line_8450; }
    /* BASIC: 8430 PRINT"DIRECTION =";C1+(((ABS(X)-ABS(A))+ABS(X))/ABS(X)):GOTO 8460 */
line_8430:;
    printf("%s", "DIRECTION ="); printf("%g ", (double)(C1+(((fabs(X)-fabs(A))+fabs(X))/fabs(X)))); printf("\n");
    goto line_8460;
    /* BASIC: 8450 PRINT"DIRECTION =";C1+(ABS(X)/ABS(A)) */
line_8450:;
    printf("%s", "DIRECTION ="); printf("%g ", (double)(C1+(fabs(X)/fabs(A)))); printf("\n");
    /* BASIC: 8460 PRINT"DISTANCE =";SQR(X^2+A^2):IF H8=1 THEN 1990 */
line_8460:;
    printf("%s", "DISTANCE ="); printf("%g ", (double)(sqrt(pow(X, 2)+pow(A, 2)))); printf("\n");
    if (H8==1) { goto line_1990; }
    /* BASIC: 8480 NEXT I:GOTO 1990 */
line_8480:;
    I += (1); goto for_loop_I_8100; end_for_I_8100:;
    goto line_1990;
    /* BASIC: 8500 IF B3<>0 THEN PRINT"FROM ENTERPRISE TO STARBASE:":W1=B4:X=B5:GOTO 8120 */
line_8500:;
    if (B3!=0) { printf("%s", "FROM ENTERPRISE TO STARBASE:"); printf("\n"); W1 = B4; X = B5; goto line_8120; }
    /* BASIC: 8510 PRINT"MR. SPOCK REPORTS,  'SENSORS SHOW NO STARBASES IN THIS"; */
line_8510:;
    printf("%s", "MR. SPOCK REPORTS,  'SENSORS SHOW NO STARBASES IN THIS");
    /* BASIC: 8520 PRINT" QUADRANT.'":GOTO 1990 */
line_8520:;
    printf("%s", " QUADRANT.'"); printf("\n");
    goto line_1990;
    /* BASIC: 8580 REM FIND EMPTY PLACE IN QUADRANT (FOR THINGS) */
line_8580:;
    /* REM FIND EMPTY PLACE IN QUADRANT (FOR THINGS) */
    /* BASIC: 8590 R1=FNR(1):R2=FNR(1):A$="   ":Z1=R1:Z2=R2:GOSUB 8830:IF Z3=0 THEN 8590 */
line_8590:;
    R1 = FNR(1);
    R2 = FNR(1);
    str_assign(A_str, sizeof(A_str), "   ");
    Z1 = R1;
    Z2 = R2;
    gosub_stack[gosub_sp++] = 36; goto line_8830; line_ret_36:;
    if (Z3==0) { goto line_8590; }
    /* BASIC: 8600 RETURN */
line_8600:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     case 27: goto line_ret_27;     case 28: goto line_ret_28;     case 29: goto line_ret_29;     case 30: goto line_ret_30;     case 31: goto line_ret_31;     case 32: goto line_ret_32;     case 33: goto line_ret_33;     case 34: goto line_ret_34;     case 35: goto line_ret_35;     case 36: goto line_ret_36;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 8660 REM INSERT IN STRING ARRAY FOR QUADRANT */
line_8660:;
    /* REM INSERT IN STRING ARRAY FOR QUADRANT */
    /* BASIC: 8670 S8=INT(Z2-.5)*3+INT(Z1-.5)*24+1 */
line_8670:;
    S8 = floor(Z2-.5)*3+floor(Z1-.5)*24+1;
    /* BASIC: 8675 IF LEN(A$)<>3 THEN PRINT"ERROR":S TO P */
line_8675:;
    if (basic_LEN(A_str)!=3) { printf("%s", "ERROR"); printf("\n"); /* UNTRANSLATED: S TO P */ }
    /* BASIC: 8680 IF S8=1 THEN Q$=A$+RIGHT$(Q$,189):RETURN */
line_8680:;
    if (S8==1) { str_assign(Q_str, sizeof(Q_str), str_cat_helper(A_str, basic_RIGHT(Q_str,189))); switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     case 27: goto line_ret_27;     case 28: goto line_ret_28;     case 29: goto line_ret_29;     case 30: goto line_ret_30;     case 31: goto line_ret_31;     case 32: goto line_ret_32;     case 33: goto line_ret_33;     case 34: goto line_ret_34;     case 35: goto line_ret_35;     case 36: goto line_ret_36;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); } }
    /* BASIC: 8690 IF S8=190 THEN Q$=LEFT$(Q$,189)+A$:RETURN */
line_8690:;
    if (S8==190) { str_assign(Q_str, sizeof(Q_str), str_cat_helper(basic_LEFT(Q_str,189), A_str)); switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     case 27: goto line_ret_27;     case 28: goto line_ret_28;     case 29: goto line_ret_29;     case 30: goto line_ret_30;     case 31: goto line_ret_31;     case 32: goto line_ret_32;     case 33: goto line_ret_33;     case 34: goto line_ret_34;     case 35: goto line_ret_35;     case 36: goto line_ret_36;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); } }
    /* BASIC: 8700 Q$=LEFT$(Q$,S8-1)+A$+RIGHT$(Q$,190-S8):RETURN */
line_8700:;
    str_assign(Q_str, sizeof(Q_str), str_cat_helper(str_cat_helper(basic_LEFT(Q_str,S8-1), A_str), basic_RIGHT(Q_str,190-S8)));
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     case 27: goto line_ret_27;     case 28: goto line_ret_28;     case 29: goto line_ret_29;     case 30: goto line_ret_30;     case 31: goto line_ret_31;     case 32: goto line_ret_32;     case 33: goto line_ret_33;     case 34: goto line_ret_34;     case 35: goto line_ret_35;     case 36: goto line_ret_36;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 8780 REM PRINT S DEVICE NAME */
line_8780:;
    /* REM PRINT S DEVICE NAME */
    /* BASIC: 8790 ONR1GO TO 8792,8794,8796,8798,8800,8802,8804,8806 */
line_8790:;
    /* UNTRANSLATED: ONR1GO TO 8792,8794,8796,8798,8800,8802,8804,8806 */
    /* BASIC: 8792 G2$="WARP ENGINES":RETURN */
line_8792:;
    str_assign(G2_str, sizeof(G2_str), "WARP ENGINES");
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     case 27: goto line_ret_27;     case 28: goto line_ret_28;     case 29: goto line_ret_29;     case 30: goto line_ret_30;     case 31: goto line_ret_31;     case 32: goto line_ret_32;     case 33: goto line_ret_33;     case 34: goto line_ret_34;     case 35: goto line_ret_35;     case 36: goto line_ret_36;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 8794 G2$="SHORT RANGE SENSORS":RETURN */
line_8794:;
    str_assign(G2_str, sizeof(G2_str), "SHORT RANGE SENSORS");
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     case 27: goto line_ret_27;     case 28: goto line_ret_28;     case 29: goto line_ret_29;     case 30: goto line_ret_30;     case 31: goto line_ret_31;     case 32: goto line_ret_32;     case 33: goto line_ret_33;     case 34: goto line_ret_34;     case 35: goto line_ret_35;     case 36: goto line_ret_36;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 8796 G2$="LONG RANGE SENSORS":RETURN */
line_8796:;
    str_assign(G2_str, sizeof(G2_str), "LONG RANGE SENSORS");
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     case 27: goto line_ret_27;     case 28: goto line_ret_28;     case 29: goto line_ret_29;     case 30: goto line_ret_30;     case 31: goto line_ret_31;     case 32: goto line_ret_32;     case 33: goto line_ret_33;     case 34: goto line_ret_34;     case 35: goto line_ret_35;     case 36: goto line_ret_36;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 8798 G2$="PHASER CONTROL":RETURN */
line_8798:;
    str_assign(G2_str, sizeof(G2_str), "PHASER CONTROL");
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     case 27: goto line_ret_27;     case 28: goto line_ret_28;     case 29: goto line_ret_29;     case 30: goto line_ret_30;     case 31: goto line_ret_31;     case 32: goto line_ret_32;     case 33: goto line_ret_33;     case 34: goto line_ret_34;     case 35: goto line_ret_35;     case 36: goto line_ret_36;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 8800 G2$="PHOTON TUBES":RETURN */
line_8800:;
    str_assign(G2_str, sizeof(G2_str), "PHOTON TUBES");
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     case 27: goto line_ret_27;     case 28: goto line_ret_28;     case 29: goto line_ret_29;     case 30: goto line_ret_30;     case 31: goto line_ret_31;     case 32: goto line_ret_32;     case 33: goto line_ret_33;     case 34: goto line_ret_34;     case 35: goto line_ret_35;     case 36: goto line_ret_36;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 8802 G2$="DAMAGE CONTROL":RETURN */
line_8802:;
    str_assign(G2_str, sizeof(G2_str), "DAMAGE CONTROL");
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     case 27: goto line_ret_27;     case 28: goto line_ret_28;     case 29: goto line_ret_29;     case 30: goto line_ret_30;     case 31: goto line_ret_31;     case 32: goto line_ret_32;     case 33: goto line_ret_33;     case 34: goto line_ret_34;     case 35: goto line_ret_35;     case 36: goto line_ret_36;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 8804 G2$="SHIELD CONTROL":RETURN */
line_8804:;
    str_assign(G2_str, sizeof(G2_str), "SHIELD CONTROL");
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     case 27: goto line_ret_27;     case 28: goto line_ret_28;     case 29: goto line_ret_29;     case 30: goto line_ret_30;     case 31: goto line_ret_31;     case 32: goto line_ret_32;     case 33: goto line_ret_33;     case 34: goto line_ret_34;     case 35: goto line_ret_35;     case 36: goto line_ret_36;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 8806 G2$="LIBRARY-COMPUTER":RETURN */
line_8806:;
    str_assign(G2_str, sizeof(G2_str), "LIBRARY-COMPUTER");
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     case 27: goto line_ret_27;     case 28: goto line_ret_28;     case 29: goto line_ret_29;     case 30: goto line_ret_30;     case 31: goto line_ret_31;     case 32: goto line_ret_32;     case 33: goto line_ret_33;     case 34: goto line_ret_34;     case 35: goto line_ret_35;     case 36: goto line_ret_36;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 8820 REM STRING COMPARISON IN QUADRANT ARRAY */
line_8820:;
    /* REM STRING COMPARISON IN QUADRANT ARRAY */
    /* BASIC: 8830 Z1=INT(Z1+.5):Z2=INT(Z2+.5):S8=(Z2-1)*3+(Z1-1)*24+1:Z3=0 */
line_8830:;
    Z1 = floor(Z1+.5);
    Z2 = floor(Z2+.5);
    S8 = (Z2-1)*3+(Z1-1)*24+1;
    Z3 = 0;
    /* BASIC: 8890 IF MID$(Q$,S8,3)<>A$ THEN RETURN */
line_8890:;
    if (strcmp(basic_MID(Q_str,S8,3), A_str) != 0) { switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     case 27: goto line_ret_27;     case 28: goto line_ret_28;     case 29: goto line_ret_29;     case 30: goto line_ret_30;     case 31: goto line_ret_31;     case 32: goto line_ret_32;     case 33: goto line_ret_33;     case 34: goto line_ret_34;     case 35: goto line_ret_35;     case 36: goto line_ret_36;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); } }
    /* BASIC: 8900 Z3=1:RETURN */
line_8900:;
    Z3 = 1;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     case 27: goto line_ret_27;     case 28: goto line_ret_28;     case 29: goto line_ret_29;     case 30: goto line_ret_30;     case 31: goto line_ret_31;     case 32: goto line_ret_32;     case 33: goto line_ret_33;     case 34: goto line_ret_34;     case 35: goto line_ret_35;     case 36: goto line_ret_36;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 9010 REM QUADRANT NAME IN G2$ FROM Z4,Z5 (=Q1,Q2) */
line_9010:;
    /* REM QUADRANT NAME IN G2$ FROM Z4,Z5 (=Q1,Q2) */
    /* BASIC: 9020 REM CALL WITH G5=1 TO GET REGION NAME ONLY */
line_9020:;
    /* REM CALL WITH G5=1 TO GET REGION NAME ONLY */
    /* BASIC: 9030 IF Z5<=4 THEN ONZ4GO TO 9040,9050,9060,9070,9080,9090,9100,9110 */
line_9030:;
    if (Z5<=4) { /* UNTRANSLATED: ONZ4GO TO 9040,9050,9060,9070,9080,9090,9100,9110 */ }
    /* BASIC: 9035 GOTO 9120 */
line_9035:;
    goto line_9120;
    /* BASIC: 9040 G2$="ANTARES":GOTO 9210 */
line_9040:;
    str_assign(G2_str, sizeof(G2_str), "ANTARES");
    goto line_9210;
    /* BASIC: 9050 G2$="RIGEL":GOTO 9210 */
line_9050:;
    str_assign(G2_str, sizeof(G2_str), "RIGEL");
    goto line_9210;
    /* BASIC: 9060 G2$="PROCYON":GOTO 9210 */
line_9060:;
    str_assign(G2_str, sizeof(G2_str), "PROCYON");
    goto line_9210;
    /* BASIC: 9070 G2$="VEGA":GOTO 9210 */
line_9070:;
    str_assign(G2_str, sizeof(G2_str), "VEGA");
    goto line_9210;
    /* BASIC: 9080 G2$="CANOPUS":GOTO 9210 */
line_9080:;
    str_assign(G2_str, sizeof(G2_str), "CANOPUS");
    goto line_9210;
    /* BASIC: 9090 G2$="ALTAIR":GOTO 9210 */
line_9090:;
    str_assign(G2_str, sizeof(G2_str), "ALTAIR");
    goto line_9210;
    /* BASIC: 9100 G2$="SAGITTARIUS":GOTO 9210 */
line_9100:;
    str_assign(G2_str, sizeof(G2_str), "SAGITTARIUS");
    goto line_9210;
    /* BASIC: 9110 G2$="POLLUX":GOTO 9210 */
line_9110:;
    str_assign(G2_str, sizeof(G2_str), "POLLUX");
    goto line_9210;
    /* BASIC: 9120 ONZ4GO TO 9130,9140,9150,9160,9170,9180,9190,9200 */
line_9120:;
    /* UNTRANSLATED: ONZ4GO TO 9130,9140,9150,9160,9170,9180,9190,9200 */
    /* BASIC: 9130 G2$="SIRIUS":GOTO 9210 */
line_9130:;
    str_assign(G2_str, sizeof(G2_str), "SIRIUS");
    goto line_9210;
    /* BASIC: 9140 G2$="DENEB":GOTO 9210 */
line_9140:;
    str_assign(G2_str, sizeof(G2_str), "DENEB");
    goto line_9210;
    /* BASIC: 9150 G2$="CAPELLA":GOTO 9210 */
line_9150:;
    str_assign(G2_str, sizeof(G2_str), "CAPELLA");
    goto line_9210;
    /* BASIC: 9160 G2$="BETELGEUSE":GOTO 9210 */
line_9160:;
    str_assign(G2_str, sizeof(G2_str), "BETELGEUSE");
    goto line_9210;
    /* BASIC: 9170 G2$="ALDEBARAN":GOTO 9210 */
line_9170:;
    str_assign(G2_str, sizeof(G2_str), "ALDEBARAN");
    goto line_9210;
    /* BASIC: 9180 G2$="REGULUS":GOTO 9210 */
line_9180:;
    str_assign(G2_str, sizeof(G2_str), "REGULUS");
    goto line_9210;
    /* BASIC: 9190 G2$="ARCTURUS":GOTO 9210 */
line_9190:;
    str_assign(G2_str, sizeof(G2_str), "ARCTURUS");
    goto line_9210;
    /* BASIC: 9200 G2$="SPICA" */
line_9200:;
    str_assign(G2_str, sizeof(G2_str), "SPICA");
    /* BASIC: 9210 IF G5<>1 THEN ONZ5GO TO 9230,9240,9250,9260,9230,9240,9250,9260 */
line_9210:;
    if (G5!=1) { /* UNTRANSLATED: ONZ5GO TO 9230,9240,9250,9260,9230,9240,9250,9260 */ }
    /* BASIC: 9220 RETURN */
line_9220:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     case 27: goto line_ret_27;     case 28: goto line_ret_28;     case 29: goto line_ret_29;     case 30: goto line_ret_30;     case 31: goto line_ret_31;     case 32: goto line_ret_32;     case 33: goto line_ret_33;     case 34: goto line_ret_34;     case 35: goto line_ret_35;     case 36: goto line_ret_36;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 9230 G2$=G2$+" I":RETURN */
line_9230:;
    str_assign(G2_str, sizeof(G2_str), str_cat_helper(G2_str, " I"));
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     case 27: goto line_ret_27;     case 28: goto line_ret_28;     case 29: goto line_ret_29;     case 30: goto line_ret_30;     case 31: goto line_ret_31;     case 32: goto line_ret_32;     case 33: goto line_ret_33;     case 34: goto line_ret_34;     case 35: goto line_ret_35;     case 36: goto line_ret_36;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 9240 G2$=G2$+" II":RETURN */
line_9240:;
    str_assign(G2_str, sizeof(G2_str), str_cat_helper(G2_str, " II"));
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     case 27: goto line_ret_27;     case 28: goto line_ret_28;     case 29: goto line_ret_29;     case 30: goto line_ret_30;     case 31: goto line_ret_31;     case 32: goto line_ret_32;     case 33: goto line_ret_33;     case 34: goto line_ret_34;     case 35: goto line_ret_35;     case 36: goto line_ret_36;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 9250 G2$=G2$+" III":RETURN */
line_9250:;
    str_assign(G2_str, sizeof(G2_str), str_cat_helper(G2_str, " III"));
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     case 27: goto line_ret_27;     case 28: goto line_ret_28;     case 29: goto line_ret_29;     case 30: goto line_ret_30;     case 31: goto line_ret_31;     case 32: goto line_ret_32;     case 33: goto line_ret_33;     case 34: goto line_ret_34;     case 35: goto line_ret_35;     case 36: goto line_ret_36;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 9260 G2$=G2$+" IV":RETURN */
line_9260:;
    str_assign(G2_str, sizeof(G2_str), str_cat_helper(G2_str, " IV"));
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     case 14: goto line_ret_14;     case 15: goto line_ret_15;     case 16: goto line_ret_16;     case 17: goto line_ret_17;     case 18: goto line_ret_18;     case 19: goto line_ret_19;     case 20: goto line_ret_20;     case 21: goto line_ret_21;     case 22: goto line_ret_22;     case 23: goto line_ret_23;     case 24: goto line_ret_24;     case 25: goto line_ret_25;     case 26: goto line_ret_26;     case 27: goto line_ret_27;     case 28: goto line_ret_28;     case 29: goto line_ret_29;     case 30: goto line_ret_30;     case 31: goto line_ret_31;     case 32: goto line_ret_32;     case 33: goto line_ret_33;     case 34: goto line_ret_34;     case 35: goto line_ret_35;     case 36: goto line_ret_36;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }

    return 0;
}
