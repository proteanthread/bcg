/*
 * Transpiled from orbit.bas
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
static double A, A1, C, D, D1, H, R, T;
static char C_str[256] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 2 PRINT TAB(33);"ORBIT" */
line_2:;
    { int _t; for(_t=0; _t<33; _t++) printf(" "); } printf("%s", "ORBIT"); printf("\n");
    /* BASIC: 4 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 6 PRINT:PRINT:PRINT */
line_6:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 10 PRINT "SOMEWHERE ABOVE YOUR PLANET IS A ROMULAN SHIP." */
line_10:;
    printf("%s", "SOMEWHERE ABOVE YOUR PLANET IS A ROMULAN SHIP."); printf("\n");
    /* BASIC: 15 PRINT */
line_15:;
    printf("\n");
    /* BASIC: 20 PRINT "THE SHIP IS IN A CONSTANT POLAR ORBIT.  ITS" */
line_20:;
    printf("%s", "THE SHIP IS IN A CONSTANT POLAR ORBIT.  ITS"); printf("\n");
    /* BASIC: 25 PRINT "DISTANCE FROM THE CENTER OF YOUR PLANET IS FROM" */
line_25:;
    printf("%s", "DISTANCE FROM THE CENTER OF YOUR PLANET IS FROM"); printf("\n");
    /* BASIC: 30 PRINT "10,000 TO 30,000 MILES AND AT ITS PRESENT VELOCITY CAN" */
line_30:;
    printf("%s", "10,000 TO 30,000 MILES AND AT ITS PRESENT VELOCITY CAN"); printf("\n");
    /* BASIC: 31 PRINT "CIRCLE YOUR PLANET ONCE EVERY 12 TO 36 HOURS." */
line_31:;
    printf("%s", "CIRCLE YOUR PLANET ONCE EVERY 12 TO 36 HOURS."); printf("\n");
    /* BASIC: 35 PRINT */
line_35:;
    printf("\n");
    /* BASIC: 40 PRINT "UNFORTUNATELY, THEY ARE USING A CLOAKING DEVICE SO" */
line_40:;
    printf("%s", "UNFORTUNATELY, THEY ARE USING A CLOAKING DEVICE SO"); printf("\n");
    /* BASIC: 45 PRINT "YOU ARE UNABLE TO SEE THEM, BUT WITH A SPECIAL" */
line_45:;
    printf("%s", "YOU ARE UNABLE TO SEE THEM, BUT WITH A SPECIAL"); printf("\n");
    /* BASIC: 50 PRINT "INSTRUMENT YOU CAN TELL HOW NEAR THEIR SHIP YOUR" */
line_50:;
    printf("%s", "INSTRUMENT YOU CAN TELL HOW NEAR THEIR SHIP YOUR"); printf("\n");
    /* BASIC: 55 PRINT "PHOTON BOMB EXPLODED.  YOU HAVE SEVEN HOURS UNTIL THEY" */
line_55:;
    printf("%s", "PHOTON BOMB EXPLODED.  YOU HAVE SEVEN HOURS UNTIL THEY"); printf("\n");
    /* BASIC: 60 PRINT "HAVE BUILT UP SUFFICIENT POWER IN ORDER TO ESCAPE" */
line_60:;
    printf("%s", "HAVE BUILT UP SUFFICIENT POWER IN ORDER TO ESCAPE"); printf("\n");
    /* BASIC: 65 PRINT "YOUR PLANET'S GRAVITY." */
line_65:;
    printf("%s", "YOUR PLANET'S GRAVITY."); printf("\n");
    /* BASIC: 70 PRINT */
line_70:;
    printf("\n");
    /* BASIC: 75 PRINT "YOUR PLANET HAS ENOUGH POWER TO FIRE ONE BOMB AN HOUR." */
line_75:;
    printf("%s", "YOUR PLANET HAS ENOUGH POWER TO FIRE ONE BOMB AN HOUR."); printf("\n");
    /* BASIC: 80 PRINT */
line_80:;
    printf("\n");
    /* BASIC: 85 PRINT "AT THE BEGINNING OF EACH HOUR YOU WILL BE ASKED TO GIVE AN" */
line_85:;
    printf("%s", "AT THE BEGINNING OF EACH HOUR YOU WILL BE ASKED TO GIVE AN"); printf("\n");
    /* BASIC: 90 PRINT "ANGLE (BETWEEN 0 AND 360) AND A DISTANCE IN UNITS OF" */
line_90:;
    printf("%s", "ANGLE (BETWEEN 0 AND 360) AND A DISTANCE IN UNITS OF"); printf("\n");
    /* BASIC: 95 PRINT "100 MILES (BETWEEN 100 AND 300), AFTER WHICH YOUR BOMB'S" */
line_95:;
    printf("%s", "100 MILES (BETWEEN 100 AND 300), AFTER WHICH YOUR BOMB'S"); printf("\n");
    /* BASIC: 100 PRINT "DISTANCE FROM THE ENEMY SHIP WILL BE GIVEN." */
line_100:;
    printf("%s", "DISTANCE FROM THE ENEMY SHIP WILL BE GIVEN."); printf("\n");
    /* BASIC: 105 PRINT */
line_105:;
    printf("\n");
    /* BASIC: 110 PRINT "AN EXPLOSION WITHIN 5,000 MILES OF THE ROMULAN SHIP" */
line_110:;
    printf("%s", "AN EXPLOSION WITHIN 5,000 MILES OF THE ROMULAN SHIP"); printf("\n");
    /* BASIC: 111 PRINT "WILL DESTROY IT." */
line_111:;
    printf("%s", "WILL DESTROY IT."); printf("\n");
    /* BASIC: 114 PRINT */
line_114:;
    printf("\n");
    /* BASIC: 115 PRINT "BELOW IS A DIAGRAM TO HELP YOU VISUALIZE YOUR PLIGHT." */
line_115:;
    printf("%s", "BELOW IS A DIAGRAM TO HELP YOU VISUALIZE YOUR PLIGHT."); printf("\n");
    /* BASIC: 116 PRINT */
line_116:;
    printf("\n");
    /* BASIC: 117 PRINT */
line_117:;
    printf("\n");
    /* BASIC: 168 PRINT "                          90" */
line_168:;
    printf("%s", "                          90"); printf("\n");
    /* BASIC: 170 PRINT "                    0000000000000" */
line_170:;
    printf("%s", "                    0000000000000"); printf("\n");
    /* BASIC: 171 PRINT "                 0000000000000000000" */
line_171:;
    printf("%s", "                 0000000000000000000"); printf("\n");
    /* BASIC: 172 PRINT "               000000           000000" */
line_172:;
    printf("%s", "               000000           000000"); printf("\n");
    /* BASIC: 173 PRINT "             00000                 00000" */
line_173:;
    printf("%s", "             00000                 00000"); printf("\n");
    /* BASIC: 174 PRINT "            00000    XXXXXXXXXXX    00000" */
line_174:;
    printf("%s", "            00000    XXXXXXXXXXX    00000"); printf("\n");
    /* BASIC: 175 PRINT "           00000    XXXXXXXXXXXXX    00000" */
line_175:;
    printf("%s", "           00000    XXXXXXXXXXXXX    00000"); printf("\n");
    /* BASIC: 176 PRINT "          0000     XXXXXXXXXXXXXXX     0000" */
line_176:;
    printf("%s", "          0000     XXXXXXXXXXXXXXX     0000"); printf("\n");
    /* BASIC: 177 PRINT "         0000     XXXXXXXXXXXXXXXXX     0000" */
line_177:;
    printf("%s", "         0000     XXXXXXXXXXXXXXXXX     0000"); printf("\n");
    /* BASIC: 178 PRINT "        0000     XXXXXXXXXXXXXXXXXXX     0000" */
line_178:;
    printf("%s", "        0000     XXXXXXXXXXXXXXXXXXX     0000"); printf("\n");
    /* BASIC: 179 PRINT "180<== 00000     XXXXXXXXXXXXXXXXXXX     00000 ==>0" */
line_179:;
    printf("%s", "180<== 00000     XXXXXXXXXXXXXXXXXXX     00000 ==>0"); printf("\n");
    /* BASIC: 180 PRINT "        0000     XXXXXXXXXXXXXXXXXXX     0000" */
line_180:;
    printf("%s", "        0000     XXXXXXXXXXXXXXXXXXX     0000"); printf("\n");
    /* BASIC: 181 PRINT "         0000     XXXXXXXXXXXXXXXXX     0000" */
line_181:;
    printf("%s", "         0000     XXXXXXXXXXXXXXXXX     0000"); printf("\n");
    /* BASIC: 182 PRINT "          0000     XXXXXXXXXXXXXXX     0000" */
line_182:;
    printf("%s", "          0000     XXXXXXXXXXXXXXX     0000"); printf("\n");
    /* BASIC: 183 PRINT "           00000    XXXXXXXXXXXXX    00000" */
line_183:;
    printf("%s", "           00000    XXXXXXXXXXXXX    00000"); printf("\n");
    /* BASIC: 184 PRINT "            00000    XXXXXXXXXXX    00000" */
line_184:;
    printf("%s", "            00000    XXXXXXXXXXX    00000"); printf("\n");
    /* BASIC: 185 PRINT "             00000                 00000" */
line_185:;
    printf("%s", "             00000                 00000"); printf("\n");
    /* BASIC: 186 PRINT "               000000           000000" */
line_186:;
    printf("%s", "               000000           000000"); printf("\n");
    /* BASIC: 187 PRINT "                 0000000000000000000" */
line_187:;
    printf("%s", "                 0000000000000000000"); printf("\n");
    /* BASIC: 188 PRINT "                    0000000000000" */
line_188:;
    printf("%s", "                    0000000000000"); printf("\n");
    /* BASIC: 190 PRINT "                         270" */
line_190:;
    printf("%s", "                         270"); printf("\n");
    /* BASIC: 192 PRINT */
line_192:;
    printf("\n");
    /* BASIC: 195 PRINT "X - YOUR PLANET" */
line_195:;
    printf("%s", "X - YOUR PLANET"); printf("\n");
    /* BASIC: 196 PRINT "O - THE ORBIT OF THE ROMULAN SHIP" */
line_196:;
    printf("%s", "O - THE ORBIT OF THE ROMULAN SHIP"); printf("\n");
    /* BASIC: 197 PRINT */
line_197:;
    printf("\n");
    /* BASIC: 198 PRINT "ON THE ABOVE DIAGRAM, THE ROMULAN SHIP IS CIRCLING" */
line_198:;
    printf("%s", "ON THE ABOVE DIAGRAM, THE ROMULAN SHIP IS CIRCLING"); printf("\n");
    /* BASIC: 199 PRINT "COUNTERCLOCKWISE AROUND YOUR PLANET.  DON'T FORGET THAT" */
line_199:;
    printf("%s", "COUNTERCLOCKWISE AROUND YOUR PLANET.  DON'T FORGET THAT"); printf("\n");
    /* BASIC: 200 PRINT "WITHOUT SUFFICIENT POWER THE ROMULAN SHIP'S ALTITUDE" */
line_200:;
    printf("%s", "WITHOUT SUFFICIENT POWER THE ROMULAN SHIP'S ALTITUDE"); printf("\n");
    /* BASIC: 210 PRINT "AND ORBITAL RATE WILL REMAIN CONSTANT." */
line_210:;
    printf("%s", "AND ORBITAL RATE WILL REMAIN CONSTANT."); printf("\n");
    /* BASIC: 220 PRINT */
line_220:;
    printf("\n");
    /* BASIC: 230 PRINT "GOOD LUCK.  THE FEDERATION IS COUNTING ON YOU." */
line_230:;
    printf("%s", "GOOD LUCK.  THE FEDERATION IS COUNTING ON YOU."); printf("\n");
    /* BASIC: 270 A=INT(360*RND(1)) */
line_270:;
    A = floor(360*((double)rand() / (double)RAND_MAX));
    /* BASIC: 280 D=INT(200*RND(1)+200) */
line_280:;
    D = floor(200*((double)rand() / (double)RAND_MAX)+200);
    /* BASIC: 290 R=INT(20*RND(1)+10) */
line_290:;
    R = floor(20*((double)rand() / (double)RAND_MAX)+10);
    /* BASIC: 300 H=0 */
line_300:;
    H = 0;
    /* BASIC: 310 IF H=7 THEN 490 */
line_310:;
    if (H==7) { goto line_490; }
    /* BASIC: 320 H=H+1 */
line_320:;
    H = H+1;
    /* BASIC: 325 PRINT */
line_325:;
    printf("\n");
    /* BASIC: 326 PRINT */
line_326:;
    printf("\n");
    /* BASIC: 330 PRINT "THIS IS HOUR";H;", AT WHAT ANGLE DO YOU WISH TO SEND" */
line_330:;
    printf("%s", "THIS IS HOUR"); printf("%g ", (double)(H)); printf("%s", ", AT WHAT ANGLE DO YOU WISH TO SEND"); printf("\n");
    /* BASIC: 335 PRINT "YOUR PHOTON BOMB"; */
line_335:;
    printf("%s", "YOUR PHOTON BOMB");
    /* BASIC: 340 INPUT A1 */
line_340:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &A1);
    /* BASIC: 350 PRINT "HOW FAR OUT DO YOU WISH TO DETONATE IT"; */
line_350:;
    printf("%s", "HOW FAR OUT DO YOU WISH TO DETONATE IT");
    /* BASIC: 360 INPUT D1 */
line_360:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &D1);
    /* BASIC: 365 PRINT */
line_365:;
    printf("\n");
    /* BASIC: 366 PRINT */
line_366:;
    printf("\n");
    /* BASIC: 370 A=A+R */
line_370:;
    A = A+R;
    /* BASIC: 380 IF A<360 THEN 400 */
line_380:;
    if (A<360) { goto line_400; }
    /* BASIC: 390 A=A-360 */
line_390:;
    A = A-360;
    /* BASIC: 400 T=ABS(A-A1) */
line_400:;
    T = fabs(A-A1);
    /* BASIC: 410 IF T<180 THEN 430 */
line_410:;
    if (T<180) { goto line_430; }
    /* BASIC: 420 T=360-T */
line_420:;
    T = 360-T;
    /* BASIC: 430 C=SQR(D*D+D1*D1-2*D*D1*COS(T*3.14159/180)) */
line_430:;
    C = sqrt(D*D+D1*D1-2*D*D1*cos(T*3.14159/180));
    /* BASIC: 440 PRINT "YOUR PHOTON BOMB EXPLODED";C;"*10^2 MILES FROM THE" */
line_440:;
    printf("%s", "YOUR PHOTON BOMB EXPLODED"); printf("%g ", (double)(C)); printf("%s", "*10^2 MILES FROM THE"); printf("\n");
    /* BASIC: 445 PRINT "ROMULAN SHIP." */
line_445:;
    printf("%s", "ROMULAN SHIP."); printf("\n");
    /* BASIC: 450 IF C<=50 THEN 470 */
line_450:;
    if (C<=50) { goto line_470; }
    /* BASIC: 460 GOTO 310 */
line_460:;
    goto line_310;
    /* BASIC: 470 PRINT "YOU HAVE SUCCESFULLY COMPLETED YOUR MISSION." */
line_470:;
    printf("%s", "YOU HAVE SUCCESFULLY COMPLETED YOUR MISSION."); printf("\n");
    /* BASIC: 480 GOTO 500 */
line_480:;
    goto line_500;
    /* BASIC: 490 PRINT "YOU HAVE ALLOWED THE ROMULANS TO ESCAPE." */
line_490:;
    printf("%s", "YOU HAVE ALLOWED THE ROMULANS TO ESCAPE."); printf("\n");
    /* BASIC: 500 PRINT "ANOTHER ROMULAN SHIP HAS GONE INTO ORBIT." */
line_500:;
    printf("%s", "ANOTHER ROMULAN SHIP HAS GONE INTO ORBIT."); printf("\n");
    /* BASIC: 510 PRINT "DO YOU WISH TO TRY TO DESTROY IT"; */
line_510:;
    printf("%s", "DO YOU WISH TO TRY TO DESTROY IT");
    /* BASIC: 520 INPUT C$ */
line_520:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", C_str);
    /* BASIC: 530 IF C$="YES" THEN 270 */
line_530:;
    if (strcmp(C_str, "YES") == 0) { goto line_270; }
    /* BASIC: 540 PRINT "GOOD BYE." */
line_540:;
    printf("%s", "GOOD BYE."); printf("\n");
    /* BASIC: 999 END */
line_999:;
    exit(0);

    return 0;
}
