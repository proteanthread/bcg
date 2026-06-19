/*
 * Transpiled from poetry.bas
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
static double I, J, K, ON, U;
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(30);"POETRY" */
line_10:;
    { int _t; for(_t=0; _t<30; _t++) printf(" "); } printf("%s", "POETRY"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 90 ON I GOTO 100,101,102,103,104 */
line_90:;
    switch ((int)(I)) {     case 1: goto line_100;     case 2: goto line_101;     case 3: goto line_102;     case 4: goto line_103;     case 5: goto line_104; }
    /* BASIC: 100 PRINT "MIDNIGHT DREARY";:GOTO 210 */
line_100:;
    printf("%s", "MIDNIGHT DREARY");
    goto line_210;
    /* BASIC: 101 PRINT "FIERY EYES";:GOTO 210 */
line_101:;
    printf("%s", "FIERY EYES");
    goto line_210;
    /* BASIC: 102 PRINT "BIRD OR FIEND";:GOTO 210 */
line_102:;
    printf("%s", "BIRD OR FIEND");
    goto line_210;
    /* BASIC: 103 PRINT "THING OF EVIL";:GOTO 210 */
line_103:;
    printf("%s", "THING OF EVIL");
    goto line_210;
    /* BASIC: 104 PRINT "PROPHET";:GOTO 210 */
line_104:;
    printf("%s", "PROPHET");
    goto line_210;
    /* BASIC: 110 ON I GOTO 111,112,113,114,115 */
line_110:;
    switch ((int)(I)) {     case 1: goto line_111;     case 2: goto line_112;     case 3: goto line_113;     case 4: goto line_114;     case 5: goto line_115; }
    /* BASIC: 111 PRINT "BEGUILING ME";:U=2:GOTO 210 */
line_111:;
    printf("%s", "BEGUILING ME");
    U = 2;
    goto line_210;
    /* BASIC: 112 PRINT "THRILLED ME";:GOTO 210 */
line_112:;
    printf("%s", "THRILLED ME");
    goto line_210;
    /* BASIC: 113 PRINT "STILL SITTING....";:GOTO 212 */
line_113:;
    printf("%s", "STILL SITTING....");
    goto line_212;
    /* BASIC: 114 PRINT "NEVER FLITTING";:U=2:GOTO 210 */
line_114:;
    printf("%s", "NEVER FLITTING");
    U = 2;
    goto line_210;
    /* BASIC: 115 PRINT "BURNED";:GOTO 210 */
line_115:;
    printf("%s", "BURNED");
    goto line_210;
    /* BASIC: 120 ON I GOTO 121,122,123,124,125 */
line_120:;
    switch ((int)(I)) {     case 1: goto line_121;     case 2: goto line_122;     case 3: goto line_123;     case 4: goto line_124;     case 5: goto line_125; }
    /* BASIC: 121 PRINT "AND MY SOUL";:GOTO 210 */
line_121:;
    printf("%s", "AND MY SOUL");
    goto line_210;
    /* BASIC: 122 PRINT "DARKNESS THERE";:GOTO 210 */
line_122:;
    printf("%s", "DARKNESS THERE");
    goto line_210;
    /* BASIC: 123 PRINT "SHALL BE LIFTED";:GOTO 210 */
line_123:;
    printf("%s", "SHALL BE LIFTED");
    goto line_210;
    /* BASIC: 124 PRINT "QUOTH THE RAVEN";:GOTO 210 */
line_124:;
    printf("%s", "QUOTH THE RAVEN");
    goto line_210;
    /* BASIC: 125 IF U=0 THEN 210 */
line_125:;
    if (U==0) { goto line_210; }
    /* BASIC: 126 PRINT "SIGN OF PARTING";:GOTO 210 */
line_126:;
    printf("%s", "SIGN OF PARTING");
    goto line_210;
    /* BASIC: 130 ON I GOTO 131,132,133,134,135 */
line_130:;
    switch ((int)(I)) {     case 1: goto line_131;     case 2: goto line_132;     case 3: goto line_133;     case 4: goto line_134;     case 5: goto line_135; }
    /* BASIC: 131 PRINT "NOTHING MORE";:GOTO 210 */
line_131:;
    printf("%s", "NOTHING MORE");
    goto line_210;
    /* BASIC: 132 PRINT "YET AGAIN";:GOTO 210 */
line_132:;
    printf("%s", "YET AGAIN");
    goto line_210;
    /* BASIC: 133 PRINT "SLOWLY CREEPING";:GOTO 210 */
line_133:;
    printf("%s", "SLOWLY CREEPING");
    goto line_210;
    /* BASIC: 134 PRINT "...EVERMORE";:GOTO 210 */
line_134:;
    printf("%s", "...EVERMORE");
    goto line_210;
    /* BASIC: 135 PRINT "NEVERMORE"; */
line_135:;
    printf("%s", "NEVERMORE");
    /* BASIC: 210 IF U=0 OR RND(1)>.19 THEN 212 */
line_210:;
    if (U==0   ||   ((double)rand() / (double)RAND_MAX)>.19) { goto line_212; }
    /* BASIC: 211 PRINT ",";:U=2 */
line_211:;
    printf("%s", ",");
    U = 2;
    /* BASIC: 212 IF RND(1)>.65 THEN 214 */
line_212:;
    if (((double)rand() / (double)RAND_MAX)>.65) { goto line_214; }
    /* BASIC: 213 PRINT " ";:U=U+1:GOTO 215 */
line_213:;
    printf("%s", " ");
    U = U+1;
    goto line_215;
    /* BASIC: 214 PRINT : U=0 */
line_214:;
    printf("\n");
    U = 0;
    /* BASIC: 215 I=INT(INT(10*RND(1))/2)+1 */
line_215:;
    I = floor(floor(10*((double)rand() / (double)RAND_MAX))/2)+1;
    /* BASIC: 220 J=J+1 : K=K+1 */
line_220:;
    J = J+1;
    K = K+1;
    /* BASIC: 230 IF U>0 OR INT(J/2)<>J/2 THEN 240 */
line_230:;
    if (U>0   ||   floor(J/2)!=J/2) { goto line_240; }
    /* BASIC: 235 PRINT "     "; */
line_235:;
    printf("%s", "     ");
    /* BASIC: 240 ON J GOTO 90,110,120,130,250 */
line_240:;
    switch ((int)(J)) {     case 1: goto line_90;     case 2: goto line_110;     case 3: goto line_120;     case 4: goto line_130;     case 5: goto line_250; }
    /* BASIC: 250 J=0 : PRINT : IF K>20 THEN 270 */
line_250:;
    J = 0;
    printf("\n");
    if (K>20) { goto line_270; }
    /* BASIC: 260 GOTO 215 */
line_260:;
    goto line_215;
    /* BASIC: 270 PRINT : U=0 : K=0 : GOTO 110 */
line_270:;
    printf("\n");
    U = 0;
    K = 0;
    goto line_110;
    /* BASIC: 999 END */
line_999:;
    exit(0);

    return 0;
}
