/*
 * Transpiled from splat.bas
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
static double A, A2, D, D1, I, J, K, K1, M, N, ON, T, V, V1;
static char A1_str[256] = {0};
static char B1_str[256] = {0};
static char Z_str[256] = {0};
static double A_arr[20000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(33);"SPLAT" */
line_10:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "SPLAT"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 40 PRINT:PRINT:PRINT */
line_40:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 50 DIM A(42) */
line_50:;
    /* DIM A(42) (handled statically) */
    /* BASIC: 95 PRINT "WELCOME TO 'SPLAT' -- THE GAME THAT SIMULATES A PARACHUTE" */
line_95:;
    printf("%s", "WELCOME TO 'SPLAT' -- THE GAME THAT SIMULATES A PARACHUTE"); printf("\n");
    /* BASIC: 96 PRINT "JUMP.  TRY TO OPEN YOUR CHUTE AT THE LAST POSSIBLE" */
line_96:;
    printf("%s", "JUMP.  TRY TO OPEN YOUR CHUTE AT THE LAST POSSIBLE"); printf("\n");
    /* BASIC: 97 PRINT "MOMENT WITHOUT GOING SPLAT." */
line_97:;
    printf("%s", "MOMENT WITHOUT GOING SPLAT."); printf("\n");
    /* BASIC: 118 PRINT:PRINT:D1=0:V=0:A=0:N=0:M=0:D1=INT(9001*RND(1)+1000) */
line_118:;
    printf("\n");
    printf("\n");
    D1 = 0;
    V = 0;
    A = 0;
    N = 0;
    M = 0;
    D1 = floor(9001*((double)rand() / (double)RAND_MAX)+1000);
    /* BASIC: 119 PRINT "SELECT YOUR OWN TERMINAL VELOCITY (YES OR NO)";:INPUT A1$ */
line_119:;
    printf("%s", "SELECT YOUR OWN TERMINAL VELOCITY (YES OR NO)");
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A1_str);
    /* BASIC: 120 IF A1$="NO" THEN 128 */
line_120:;
    if (strcmp(A1_str, "NO") == 0) { goto line_128; }
    /* BASIC: 121 IF A1$<>"YES" THEN PRINT "YES OR NO";:INPUT A1$:GOTO 120 */
line_121:;
    if (strcmp(A1_str, "YES") != 0) { printf("%s", "YES OR NO"); printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", A1_str); goto line_120; }
    /* BASIC: 123 PRINT "WHAT TERMINAL VELOCITY (MI/HR)";:INPUT V1 */
line_123:;
    printf("%s", "WHAT TERMINAL VELOCITY (MI/HR)");
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &V1);
    /* BASIC: 125 V1=V1*(5280/3600):V=V1+((V1*RND(1))/20)-((V1*RND(1))/20):GOTO 135 */
line_125:;
    V1 = V1*(5280/3600);
    V = V1+((V1*((double)rand() / (double)RAND_MAX))/20)-((V1*((double)rand() / (double)RAND_MAX))/20);
    goto line_135;
    /* BASIC: 128 V1=INT(1000*RND(1)) */
line_128:;
    V1 = floor(1000*((double)rand() / (double)RAND_MAX));
    /* BASIC: 130 PRINT "OK.  TERMINAL VELOCITY ="V1"MI/HR" */
line_130:;
    printf("%s", "OK.  TERMINAL VELOCITY ="); printf("%g ", (double)(V1)); printf("%s", "MI/HR"); printf("\n");
    /* BASIC: 131 V1=V1*(5280/3600):V=V1+((V1*RND(1))/20)-((V1*RND(1))/20) */
line_131:;
    V1 = V1*(5280/3600);
    V = V1+((V1*((double)rand() / (double)RAND_MAX))/20)-((V1*((double)rand() / (double)RAND_MAX))/20);
    /* BASIC: 135 PRINT "WANT TO SELECT ACCELERATION DUE TO GRAVITY (YES OR NO)"; */
line_135:;
    printf("%s", "WANT TO SELECT ACCELERATION DUE TO GRAVITY (YES OR NO)");
    /* BASIC: 136 INPUT B1$ */
line_136:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", B1_str);
    /* BASIC: 140 IF B1$="NO" THEN 150 */
line_140:;
    if (strcmp(B1_str, "NO") == 0) { goto line_150; }
    /* BASIC: 141 IF B1$<>"YES" THEN PRINT "YES OR NO";:INPUT B1$:GOTO 140 */
line_141:;
    if (strcmp(B1_str, "YES") != 0) { printf("%s", "YES OR NO"); printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", B1_str); goto line_140; }
    /* BASIC: 143 PRINT "WHAT ACCELERATION (FT/SEC/SEC)";:INPUT A2 */
line_143:;
    printf("%s", "WHAT ACCELERATION (FT/SEC/SEC)");
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &A2);
    /* BASIC: 145 A=A2+((A2*RND(1))/20)-((A2*RND(1))/20):GOTO 205 */
line_145:;
    A = A2+((A2*((double)rand() / (double)RAND_MAX))/20)-((A2*((double)rand() / (double)RAND_MAX))/20);
    goto line_205;
    /* BASIC: 150 ON INT(1+(10*RND(1)))GOTO 151,152,153,154,155,156,157,158,159,160 */
line_150:;
    /* UNTRANSLATED: ON INT(1+(10*RND(1)))GOTO 151,152,153,154,155,156,157,158,159,160 */
    /* BASIC: 151 PRINT"FINE. YOU'RE ON MERCURY. ACCELERATION=12.2 FT/SEC/SEC.":GOTO 161 */
line_151:;
    printf("%s", "FINE. YOU'RE ON MERCURY. ACCELERATION=12.2 FT/SEC/SEC."); printf("\n");
    goto line_161;
    /* BASIC: 152 PRINT"ALL RIGHT. YOU'RE ON VENUS. ACCELERATION=28.3 FT/SEC/SEC.":GOTO 162 */
line_152:;
    printf("%s", "ALL RIGHT. YOU'RE ON VENUS. ACCELERATION=28.3 FT/SEC/SEC."); printf("\n");
    goto line_162;
    /* BASIC: 153 PRINT "THEN YOU'RE ON EARTH. ACCELERATION=32.16 FT/SEC/SEC.":GOTO 163 */
line_153:;
    printf("%s", "THEN YOU'RE ON EARTH. ACCELERATION=32.16 FT/SEC/SEC."); printf("\n");
    goto line_163;
    /* BASIC: 154 PRINT"FINE. YOU'RE ON THE MOON. ACCELERATION=5.15 FT/SEC/SEC.":GOTO 164 */
line_154:;
    printf("%s", "FINE. YOU'RE ON THE MOON. ACCELERATION=5.15 FT/SEC/SEC."); printf("\n");
    goto line_164;
    /* BASIC: 155 PRINT"ALL RIGHT. YOU'RE ON MARS. ACCELERATION=12.5 FT/SEC/SEC.":GOTO 165 */
line_155:;
    printf("%s", "ALL RIGHT. YOU'RE ON MARS. ACCELERATION=12.5 FT/SEC/SEC."); printf("\n");
    goto line_165;
    /* BASIC: 156 PRINT"THEN YOU'RE ON JUPITER. ACCELERATION=85.2 FT/SEC/SEC.":GOTO 166 */
line_156:;
    printf("%s", "THEN YOU'RE ON JUPITER. ACCELERATION=85.2 FT/SEC/SEC."); printf("\n");
    goto line_166;
    /* BASIC: 157 PRINT"FINE. YOU'RE ON SATURN. ACCELERATION=37.6 FT/SEC/SEC.":GOTO 167 */
line_157:;
    printf("%s", "FINE. YOU'RE ON SATURN. ACCELERATION=37.6 FT/SEC/SEC."); printf("\n");
    goto line_167;
    /* BASIC: 158 PRINT"ALL RIGHT. YOU'RE ON URANUS. ACCELERATION=33.8 FT/SEC/SEC.":GOTO 168 */
line_158:;
    printf("%s", "ALL RIGHT. YOU'RE ON URANUS. ACCELERATION=33.8 FT/SEC/SEC."); printf("\n");
    goto line_168;
    /* BASIC: 159 PRINT"THEN YOU'RE ON NEPTUNE. ACCELERATION=39.6 FT/SEC/SEC.":GOTO 169 */
line_159:;
    printf("%s", "THEN YOU'RE ON NEPTUNE. ACCELERATION=39.6 FT/SEC/SEC."); printf("\n");
    goto line_169;
    /* BASIC: 160 PRINT"FINE. YOU'RE ON THE SUN. ACCELERATION=896 FT/SEC/SEC.":GOTO 170 */
line_160:;
    printf("%s", "FINE. YOU'RE ON THE SUN. ACCELERATION=896 FT/SEC/SEC."); printf("\n");
    goto line_170;
    /* BASIC: 161 A2=12.2:GOTO 145 */
line_161:;
    A2 = 12.2;
    goto line_145;
    /* BASIC: 162 A2=28.3:GOTO 145 */
line_162:;
    A2 = 28.3;
    goto line_145;
    /* BASIC: 163 A2=32.16:GOTO 145 */
line_163:;
    A2 = 32.16;
    goto line_145;
    /* BASIC: 164 A2=5.15:GOTO 145 */
line_164:;
    A2 = 5.15;
    goto line_145;
    /* BASIC: 165 A2=12.5:GOTO 145 */
line_165:;
    A2 = 12.5;
    goto line_145;
    /* BASIC: 166 A2=85.2:GOTO 145 */
line_166:;
    A2 = 85.2;
    goto line_145;
    /* BASIC: 167 A2=37.6:GOTO 145 */
line_167:;
    A2 = 37.6;
    goto line_145;
    /* BASIC: 168 A2=33.8 :GOTO 145 */
line_168:;
    A2 = 33.8;
    goto line_145;
    /* BASIC: 169 A2=39.6:GOTO 145 */
line_169:;
    A2 = 39.6;
    goto line_145;
    /* BASIC: 170 A2=896:GOTO 145 */
line_170:;
    A2 = 896;
    goto line_145;
    /* BASIC: 205 PRINT */
line_205:;
    printf("\n");
    /* BASIC: 206 PRINT "    ALTITUDE         ="D1"FT" */
line_206:;
    printf("%s", "    ALTITUDE         ="); printf("%g ", (double)(D1)); printf("%s", "FT"); printf("\n");
    /* BASIC: 207 PRINT "    TERM. VELOCITY   ="V1"FT/SEC +/-5%" */
line_207:;
    printf("%s", "    TERM. VELOCITY   ="); printf("%g ", (double)(V1)); printf("%s", "FT/SEC +/-5%"); printf("\n");
    /* BASIC: 208 PRINT "    ACCELERATION     ="A2"FT/SEC/SEC +/-5%" */
line_208:;
    printf("%s", "    ACCELERATION     ="); printf("%g ", (double)(A2)); printf("%s", "FT/SEC/SEC +/-5%"); printf("\n");
    /* BASIC: 210 PRINT "SET THE TIMER FOR YOUR FREEFALL." */
line_210:;
    printf("%s", "SET THE TIMER FOR YOUR FREEFALL."); printf("\n");
    /* BASIC: 211 PRINT "HOW MANY SECONDS";:INPUT T */
line_211:;
    printf("%s", "HOW MANY SECONDS");
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &T);
    /* BASIC: 215 PRINT "HERE WE GO." */
line_215:;
    printf("%s", "HERE WE GO."); printf("\n");
    /* BASIC: 217 PRINT */
line_217:;
    printf("\n");
    /* BASIC: 218 PRINT "TIME (SEC)","DIST TO FALL (FT)" */
line_218:;
    printf("%s", "TIME (SEC)"); printf("\t"); printf("%s", "DIST TO FALL (FT)"); printf("\n");
    /* BASIC: 219 PRINT "==========","=================" */
line_219:;
    printf("%s", "=========="); printf("\t"); printf("%s", "================="); printf("\n");
    /* BASIC: 300 FOR I=0 TO T STEP (T/8) */
line_300:;
    I = 0; for_loop_I_300: if ((((T/8)) >= 0 && I > (T)) || (((T/8)) < 0 && I < (T))) goto end_for_I_300;
    /* BASIC: 310 IF I>V/A THEN 400 */
line_310:;
    if (I>V/A) { goto line_400; }
    /* BASIC: 320 D=D1-((A/2)*I^2) */
line_320:;
    D = D1-((A/2)*pow(I, 2));
    /* BASIC: 330 IF D<=0 THEN 1000 */
line_330:;
    if (D<=0) { goto line_1000; }
    /* BASIC: 340 PRINT I,D */
line_340:;
    printf("%g ", (double)(I)); printf("\t"); printf("%g ", (double)(D)); printf("\n");
    /* BASIC: 350 NEXT I */
line_350:;
    I += ((T/8)); goto for_loop_I_300; end_for_I_300:;
    /* BASIC: 360 GOTO 500 */
line_360:;
    goto line_500;
    /* BASIC: 400 PRINT "TERMINAL VELOCITY REACHED AT T PLUS"V/A"SECONDS." */
line_400:;
    printf("%s", "TERMINAL VELOCITY REACHED AT T PLUS"); printf("%g ", (double)(V/A)); printf("%s", "SECONDS."); printf("\n");
    /* BASIC: 405 FOR I=I TO T STEP (T/8) */
line_405:;
    I = I; for_loop_I_405: if ((((T/8)) >= 0 && I > (T)) || (((T/8)) < 0 && I < (T))) goto end_for_I_405;
    /* BASIC: 410 D=D1-((V^2/(2*A))+(V*(I-(V/A)))) */
line_410:;
    D = D1-((pow(V, 2)/(2*A))+(V*(I-(V/A))));
    /* BASIC: 420 IF D<=0 THEN 1010 */
line_420:;
    if (D<=0) { goto line_1010; }
    /* BASIC: 430 PRINT I,D */
line_430:;
    printf("%g ", (double)(I)); printf("\t"); printf("%g ", (double)(D)); printf("\n");
    /* BASIC: 440 NEXT I */
line_440:;
    I += ((T/8)); goto for_loop_I_405; end_for_I_405:;
    /* BASIC: 500 PRINT "CHUTE OPEN" */
line_500:;
    printf("%s", "CHUTE OPEN"); printf("\n");
    /* BASIC: 510 K=0:K1=0 */
line_510:;
    K = 0;
    K1 = 0;
    /* BASIC: 550 FOR J=0 TO 42 */
line_550:;
    J = 0; for_loop_J_550: if (((1) >= 0 && J > (42)) || ((1) < 0 && J < (42))) goto end_for_J_550;
    /* BASIC: 555 IF A(J)=0 THEN 620 */
line_555:;
    if (A_arr[(int)(J)]==0) { goto line_620; }
    /* BASIC: 560 K=K+1 */
line_560:;
    K = K+1;
    /* BASIC: 570 IF D>=A(J) THEN 600 */
line_570:;
    if (D>=A_arr[(int)(J)]) { goto line_600; }
    /* BASIC: 580 K1=K1+1 */
line_580:;
    K1 = K1+1;
    /* BASIC: 600 NEXT J */
line_600:;
    J += (1); goto for_loop_J_550; end_for_J_550:;
    /* BASIC: 610 GOTO 540 */
line_610:;
    goto line_540;
    /* BASIC: 620 A(J)=D */
line_620:;
    A_arr[(int)(J)] = D;
    /* BASIC: 630 IF J>2 THEN 650 */
line_630:;
    if (J>2) { goto line_650; }
    /* BASIC: 635 PRINT "AMAZING!!! NOT BAD FOR YOUR "; */
line_635:;
    printf("%s", "AMAZING!!! NOT BAD FOR YOUR ");
    /* BASIC: 636 IF J=0 THEN PRINT "1ST "; */
line_636:;
    if (J==0) { printf("%s", "1ST "); }
    /* BASIC: 637 IF J=1 THEN PRINT "2ND "; */
line_637:;
    if (J==1) { printf("%s", "2ND "); }
    /* BASIC: 638 IF J=2 THEN PRINT "3RD "; */
line_638:;
    if (J==2) { printf("%s", "3RD "); }
    /* BASIC: 639 PRINT "SUCCESSFUL JUMP!!!":GOTO 2000 */
line_639:;
    printf("%s", "SUCCESSFUL JUMP!!!"); printf("\n");
    goto line_2000;
    /* BASIC: 650 IF K-K1<=.1*K THEN 700 */
line_650:;
    if (K-K1<=.1*K) { goto line_700; }
    /* BASIC: 660 IF K-K1<=.25*K THEN 710 */
line_660:;
    if (K-K1<=.25*K) { goto line_710; }
    /* BASIC: 670 IF K-K1<=.5*K THEN 720 */
line_670:;
    if (K-K1<=.5*K) { goto line_720; }
    /* BASIC: 680 IF K-K1<=.75*K THEN 730 */
line_680:;
    if (K-K1<=.75*K) { goto line_730; }
    /* BASIC: 690 IF K-K1<=.9*K THEN 740 */
line_690:;
    if (K-K1<=.9*K) { goto line_740; }
    /* BASIC: 695 GOTO 750 */
line_695:;
    goto line_750;
    /* BASIC: 700 PRINT "WOW!  THAT'S SOME JUMPING.  OF THE"K"SUCCESSFUL JUMPS" */
line_700:;
    printf("%s", "WOW!  THAT'S SOME JUMPING.  OF THE"); printf("%g ", (double)(K)); printf("%s", "SUCCESSFUL JUMPS"); printf("\n");
    /* BASIC: 701 PRINT "BEFORE YOURS, ONLY"K-K1"OPENED THEIR CHUTES LOWER THAN" */
line_701:;
    printf("%s", "BEFORE YOURS, ONLY"); printf("%g ", (double)(K-K1)); printf("%s", "OPENED THEIR CHUTES LOWER THAN"); printf("\n");
    /* BASIC: 702 PRINT "YOU DID." */
line_702:;
    printf("%s", "YOU DID."); printf("\n");
    /* BASIC: 703 GOTO 2000 */
line_703:;
    goto line_2000;
    /* BASIC: 710 PRINT "PRETTY GOOD! " K"SUCCESSFUL JUMPS PRECEDED YOURS AND ONLY" */
line_710:;
    printf("%s", "PRETTY GOOD! "); printf("%g ", (double)(K)); printf("%s", "SUCCESSFUL JUMPS PRECEDED YOURS AND ONLY"); printf("\n");
    /* BASIC: 711 PRINT K-K1" OF THEM GOT LOWER THAN YOU DID BEFORE THEIR CHUTES" */
line_711:;
    printf("%g ", (double)(K-K1)); printf("%s", " OF THEM GOT LOWER THAN YOU DID BEFORE THEIR CHUTES"); printf("\n");
    /* BASIC: 712 PRINT "OPENED." :GOTO 2000 */
line_712:;
    printf("%s", "OPENED."); printf("\n");
    goto line_2000;
    /* BASIC: 720 PRINT "NOT BAD.  THERE HAVE BEEN"K"SUCCESSFUL JUMPS BEFORE YOURS." */
line_720:;
    printf("%s", "NOT BAD.  THERE HAVE BEEN"); printf("%g ", (double)(K)); printf("%s", "SUCCESSFUL JUMPS BEFORE YOURS."); printf("\n");
    /* BASIC: 721 PRINT"YOU WERE BEATEN OUT BY"K-K1"OF THEM.":GOTO 2000 */
line_721:;
    printf("%s", "YOU WERE BEATEN OUT BY"); printf("%g ", (double)(K-K1)); printf("%s", "OF THEM."); printf("\n");
    goto line_2000;
    /* BASIC: 730 PRINT "CONSERVATIVE, AREN'T YOU?  YOU RANKED ONLY"K-K1"IN THE" */
line_730:;
    printf("%s", "CONSERVATIVE, AREN'T YOU?  YOU RANKED ONLY"); printf("%g ", (double)(K-K1)); printf("%s", "IN THE"); printf("\n");
    /* BASIC: 731 PRINT K"SUCCESSFUL JUMPS BEFORE YOURS.":GOTO 2000 */
line_731:;
    printf("%g ", (double)(K)); printf("%s", "SUCCESSFUL JUMPS BEFORE YOURS."); printf("\n");
    goto line_2000;
    /* BASIC: 740 PRINT "HUMPH!  DON'T YOU HAVE ANY SPORTING BLOOD?  THERE WERE" */
line_740:;
    printf("%s", "HUMPH!  DON'T YOU HAVE ANY SPORTING BLOOD?  THERE WERE"); printf("\n");
    /* BASIC: 741 PRINT K"SUCCESSFUL JUMPS BEFORE YOURS AND YOU CAME IN"K1"JUMPS" */
line_741:;
    printf("%g ", (double)(K)); printf("%s", "SUCCESSFUL JUMPS BEFORE YOURS AND YOU CAME IN"); printf("%g ", (double)(K1)); printf("%s", "JUMPS"); printf("\n");
    /* BASIC: 742 PRINT "BETTER THAN THE WORST.  SHAPE UP!!!":GOTO 2000 */
line_742:;
    printf("%s", "BETTER THAN THE WORST.  SHAPE UP!!!"); printf("\n");
    goto line_2000;
    /* BASIC: 750 PRINT "HEY!  YOU PULLED THE RIP CORD MUCH TOO SOON.  "K"SUCCESSFUL" */
line_750:;
    printf("%s", "HEY!  YOU PULLED THE RIP CORD MUCH TOO SOON.  "); printf("%g ", (double)(K)); printf("%s", "SUCCESSFUL"); printf("\n");
    /* BASIC: 751 PRINT "JUMPS BEFORE YOURS AND YOU CAME IN NUMBER"K-K1"!  GET WITH IT!" */
line_751:;
    printf("%s", "JUMPS BEFORE YOURS AND YOU CAME IN NUMBER"); printf("%g ", (double)(K-K1)); printf("%s", "!  GET WITH IT!"); printf("\n");
    /* BASIC: 752 GOTO 2000 */
line_752:;
    goto line_2000;
    /* BASIC: 800 PRINT "REQUIESCAT IN PACE.":GOTO 1950 */
line_800:;
    printf("%s", "REQUIESCAT IN PACE."); printf("\n");
    goto line_1950;
    /* BASIC: 801 PRINT "MAY THE ANGEL OF HEAVEN LEAD YOU INTO PARADISE.":GOTO 1950 */
line_801:;
    printf("%s", "MAY THE ANGEL OF HEAVEN LEAD YOU INTO PARADISE."); printf("\n");
    goto line_1950;
    /* BASIC: 802 PRINT "REST IN PEACE.":GOTO 1950 */
line_802:;
    printf("%s", "REST IN PEACE."); printf("\n");
    goto line_1950;
    /* BASIC: 803 PRINT "SON-OF-A-GUN.":GOTO 1950 */
line_803:;
    printf("%s", "SON-OF-A-GUN."); printf("\n");
    goto line_1950;
    /* BASIC: 804 PRINT "#$%&&%!$":GOTO 1950 */
line_804:;
    printf("%s", "#$%&&%!$"); printf("\n");
    goto line_1950;
    /* BASIC: 805 PRINT "A KICK IN THE PANTS IS A BOOST IF YOU'RE HEADED RIGHT.":GOTO 1950 */
line_805:;
    printf("%s", "A KICK IN THE PANTS IS A BOOST IF YOU'RE HEADED RIGHT."); printf("\n");
    goto line_1950;
    /* BASIC: 806 PRINT "HMMM. SHOULD HAVE PICKED A SHORTER TIME.":GOTO 1950 */
line_806:;
    printf("%s", "HMMM. SHOULD HAVE PICKED A SHORTER TIME."); printf("\n");
    goto line_1950;
    /* BASIC: 807 PRINT "MUTTER. MUTTER. MUTTER.":GOTO 1950 */
line_807:;
    printf("%s", "MUTTER. MUTTER. MUTTER."); printf("\n");
    goto line_1950;
    /* BASIC: 808 PRINT "PUSHING UP DAISIES.":GOTO 1950 */
line_808:;
    printf("%s", "PUSHING UP DAISIES."); printf("\n");
    goto line_1950;
    /* BASIC: 809 PRINT "EASY COME, EASY GO.":GOTO 1950 */
line_809:;
    printf("%s", "EASY COME, EASY GO."); printf("\n");
    goto line_1950;
    /* BASIC: 1000 PRINT SQR(2*D1/A),"SPLAT" */
line_1000:;
    printf("%g ", (double)(sqrt(2*D1/A))); printf("\t"); printf("%s", "SPLAT"); printf("\n");
    /* BASIC: 1005 ON INT(1+(10*RND(1)))GOTO 800,801,802,803,804,805,806,807,808,809 */
line_1005:;
    /* UNTRANSLATED: ON INT(1+(10*RND(1)))GOTO 800,801,802,803,804,805,806,807,808,809 */
    /* BASIC: 1010 PRINT (V/A)+((D1-(V^2/(2*A)))/V),"SPLAT" */
line_1010:;
    printf("%g ", (double)((V/A)+((D1-(pow(V, 2)/(2*A)))/V))); printf("\t"); printf("%s", "SPLAT"); printf("\n");
    /* BASIC: 1020 GOTO 1005 */
line_1020:;
    goto line_1005;
    /* BASIC: 1950 PRINT "I'LL GIVE YOU ANOTHER CHANCE.":GOTO 2000 */
line_1950:;
    printf("%s", "I'LL GIVE YOU ANOTHER CHANCE."); printf("\n");
    goto line_2000;
    /* BASIC: 2000 PRINT "DO YOU WANT TO PLAY AGAIN";:INPUT Z$ */
line_2000:;
    printf("%s", "DO YOU WANT TO PLAY AGAIN");
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", Z_str);
    /* BASIC: 2001 IF Z$="YES" THEN 118 */
line_2001:;
    if (strcmp(Z_str, "YES") == 0) { goto line_118; }
    /* BASIC: 2002 IF Z$="NO" THEN 2005 */
line_2002:;
    if (strcmp(Z_str, "NO") == 0) { goto line_2005; }
    /* BASIC: 2003 PRINT "YES OR NO":GOTO 2000 */
line_2003:;
    printf("%s", "YES OR NO"); printf("\n");
    goto line_2000;
    /* BASIC: 2005 PRINT "PLEASE";:INPUT Z$:IF Z$="YES" THEN 118 */
line_2005:;
    printf("%s", "PLEASE");
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", Z_str);
    if (strcmp(Z_str, "YES") == 0) { goto line_118; }
    /* BASIC: 2006 IF Z$<>"NO" THEN PRINT "YES OR NO ";:GOTO 2005 */
line_2006:;
    if (strcmp(Z_str, "NO") != 0) { printf("%s", "YES OR NO "); goto line_2005; }
    /* BASIC: 2007 PRINT "SSSSSSSSSS.":PRINT:GOTO 2046 */
line_2007:;
    printf("%s", "SSSSSSSSSS."); printf("\n");
    printf("\n");
    goto line_2046;
    /* BASIC: 2046 END */
line_2046:;
    exit(0);
    /* Undefined labels declared here to compile cleanly */
    line_540:;

    return 0;
}
