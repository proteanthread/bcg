/*
 * Transpiled from bounce.bas
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
static double C, H, I, L, S1, S2, T, V;
static double T_arr[20000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(33);"BOUNCE" */
line_10:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "BOUNCE"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 90 DIM T(20) */
line_90:;
    /* DIM T(20) (handled statically) */
    /* BASIC: 100 PRINT "THIS SIMULATION LETS YOU SPECIFY THE INITIAL VELOCITY" */
line_100:;
    printf("%s", "THIS SIMULATION LETS YOU SPECIFY THE INITIAL VELOCITY"); printf("\n");
    /* BASIC: 110 PRINT "OF A BALL THROWN STRAIGHT UP, AND THE COEFFICIENT OF" */
line_110:;
    printf("%s", "OF A BALL THROWN STRAIGHT UP, AND THE COEFFICIENT OF"); printf("\n");
    /* BASIC: 120 PRINT "ELASTICITY OF THE BALL.  PLEASE USE A DECIMAL FRACTION" */
line_120:;
    printf("%s", "ELASTICITY OF THE BALL.  PLEASE USE A DECIMAL FRACTION"); printf("\n");
    /* BASIC: 130 PRINT "COEFFICIENCY (LESS THAN 1)." */
line_130:;
    printf("%s", "COEFFICIENCY (LESS THAN 1)."); printf("\n");
    /* BASIC: 131 PRINT */
line_131:;
    printf("\n");
    /* BASIC: 132 PRINT "YOU ALSO SPECIFY THE TIME INCREMENT TO BE USED IN" */
line_132:;
    printf("%s", "YOU ALSO SPECIFY THE TIME INCREMENT TO BE USED IN"); printf("\n");
    /* BASIC: 133 PRINT "'STROBING' THE BALL'S FLIGHT (TRY .1 INITIALLY)." */
line_133:;
    printf("%s", "'STROBING' THE BALL'S FLIGHT (TRY .1 INITIALLY)."); printf("\n");
    /* BASIC: 134 PRINT */
line_134:;
    printf("\n");
    /* BASIC: 135 INPUT "TIME INCREMENT (SEC)";S2 */
line_135:;
    printf("%s", "TIME INCREMENT (SEC)"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &S2);
    /* BASIC: 140 PRINT */
line_140:;
    printf("\n");
    /* BASIC: 150 INPUT "VELOCITY (FPS)";V */
line_150:;
    printf("%s", "VELOCITY (FPS)"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &V);
    /* BASIC: 160 PRINT */
line_160:;
    printf("\n");
    /* BASIC: 170 INPUT "COEFFICIENT";C */
line_170:;
    printf("%s", "COEFFICIENT"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &C);
    /* BASIC: 180 PRINT */
line_180:;
    printf("\n");
    /* BASIC: 182 PRINT "FEET" */
line_182:;
    printf("%s", "FEET"); printf("\n");
    /* BASIC: 184 PRINT */
line_184:;
    printf("\n");
    /* BASIC: 186 S1=INT(70/(V/(16*S2))) */
line_186:;
    S1 = floor(70/(V/(16*S2)));
    /* BASIC: 190 FOR I=1 TO S1 */
line_190:;
    I = 1; for_loop_I_190: if (((1) >= 0 && I > (S1)) || ((1) < 0 && I < (S1))) goto end_for_I_190;
    /* BASIC: 200 T(I)=V*C^(I-1)/16 */
line_200:;
    T_arr[(int)(I)] = V*pow(C, (I-1))/16;
    /* BASIC: 210 NEXT I */
line_210:;
    I += (1); goto for_loop_I_190; end_for_I_190:;
    /* BASIC: 220 FOR H=INT(-16*(V/32)^2+V^2/32+.5) TO 0 STEP -.5 */
line_220:;
    H = floor(-16*pow((V/32), 2)+pow(V, 2)/32+.5); for_loop_H_220: if (((-.5) >= 0 && H > (0)) || ((-.5) < 0 && H < (0))) goto end_for_H_220;
    /* BASIC: 221 IF INT(H)<>H THEN 225 */
line_221:;
    if (floor(H)!=H) { goto line_225; }
    /* BASIC: 222 PRINT H; */
line_222:;
    printf("%g ", (double)(H));
    /* BASIC: 225 L=0 */
line_225:;
    L = 0;
    /* BASIC: 230 FOR I=1 TO S1 */
line_230:;
    I = 1; for_loop_I_230: if (((1) >= 0 && I > (S1)) || ((1) < 0 && I < (S1))) goto end_for_I_230;
    /* BASIC: 240 FOR T=0 TO T(I) STEP S2 */
line_240:;
    T = 0; for_loop_T_240: if (((S2) >= 0 && T > (T_arr[(int)(I)])) || ((S2) < 0 && T < (T_arr[(int)(I)]))) goto end_for_T_240;
    /* BASIC: 245 L=L+S2 */
line_245:;
    L = L+S2;
    /* BASIC: 250 IF ABS(H-(.5*(-32)*T^2+V*C^(I-1)*T))>.25 THEN 270 */
line_250:;
    if (fabs(H-(.5*(-32)*pow(T, 2)+V*pow(C, (I-1))*T))>.25) { goto line_270; }
    /* BASIC: 260 PRINT TAB(L/S2);"0"; */
line_260:;
    { int _t; for(_t=0; _t<L/S2; _t++) printf(" "); } printf("%s", "0");
    /* BASIC: 270 NEXT T */
line_270:;
    T += (S2); goto for_loop_T_240; end_for_T_240:;
    /* BASIC: 275 T=T(I+1)/2 */
line_275:;
    T = T_arr[(int)(I+1)]/2;
    /* BASIC: 276 IF -16*T^2+V*C^(I-1)*T<H THEN 290 */
line_276:;
    if (-16*pow(T, 2)+V*pow(C, (I-1))*T<H) { goto line_290; }
    /* BASIC: 280 NEXT I */
line_280:;
    I += (1); goto for_loop_I_230; end_for_I_230:;
    /* BASIC: 290 PRINT */
line_290:;
    printf("\n");
    /* BASIC: 300 NEXT H */
line_300:;
    H += (-.5); goto for_loop_H_220; end_for_H_220:;
    /* BASIC: 310 PRINT TAB(1); */
line_310:;
    { int _t; for(_t=0; _t<1; _t++) printf(" "); }
    /* BASIC: 320 FOR I=1 TO INT(L+1)/S2+1 */
line_320:;
    I = 1; for_loop_I_320: if (((1) >= 0 && I > (floor(L+1)/S2+1)) || ((1) < 0 && I < (floor(L+1)/S2+1))) goto end_for_I_320;
    /* BASIC: 330 PRINT "."; */
line_330:;
    printf("%s", ".");
    /* BASIC: 340 NEXT I */
line_340:;
    I += (1); goto for_loop_I_320; end_for_I_320:;
    /* BASIC: 350 PRINT */
line_350:;
    printf("\n");
    /* BASIC: 355 PRINT " 0"; */
line_355:;
    printf("%s", " 0");
    /* BASIC: 360 FOR I=1 TO INT(L+.9995) */
line_360:;
    I = 1; for_loop_I_360: if (((1) >= 0 && I > (floor(L+.9995))) || ((1) < 0 && I < (floor(L+.9995)))) goto end_for_I_360;
    /* BASIC: 380 PRINT TAB(INT(I/S2));I; */
line_380:;
    { int _t; for(_t=0; _t<floor(I/S2); _t++) printf(" "); } printf("%g ", (double)(I));
    /* BASIC: 390 NEXT I */
line_390:;
    I += (1); goto for_loop_I_360; end_for_I_360:;
    /* BASIC: 400 PRINT */
line_400:;
    printf("\n");
    /* BASIC: 410 PRINT TAB(INT(L+1)/(2*S2)-2);"SECONDS" */
line_410:;
    { int _t; for(_t=0; _t<floor(L+1)/(2*S2)-2; _t++) printf(" "); } printf("%s", "SECONDS"); printf("\n");
    /* BASIC: 420 PRINT */
line_420:;
    printf("\n");
    /* BASIC: 430 GOTO 135 */
line_430:;
    goto line_135;
    /* BASIC: 440 END */
line_440:;
    exit(0);

    return 0;
}
