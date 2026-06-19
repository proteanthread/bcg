/*
 * Transpiled from furtrader.bas
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

typedef enum { DATA_NUM, DATA_STR } DataType;
typedef struct {
    DataType type;
    double num;
    const char *str;
} DataItem;

static DataItem program_data[4] = {
    { DATA_STR, 0.0, "MINK" },
    { DATA_STR, 0.0, "BEAVER" },
    { DATA_STR, 0.0, "ERMINE" },
    { DATA_STR, 0.0, "FOX" },
};
static int data_ptr = 0;

static void read_numeric(double *var) {
    if (data_ptr < sizeof(program_data)/sizeof(program_data[0])) {
        if (program_data[data_ptr].type == DATA_NUM) *var = program_data[data_ptr].num;
        else *var = atof(program_data[data_ptr].str);
        data_ptr++;
    }
}

static void read_string(char *var, size_t max_len) {
    if (data_ptr < sizeof(program_data)/sizeof(program_data[0])) {
        if (program_data[data_ptr].type == DATA_STR) strncpy(var, program_data[data_ptr].str, max_len - 1);
        else sprintf(var, "%g", program_data[data_ptr].num);
        var[max_len - 1] = '\0';
        data_ptr++;
    }
}

/* Global variables */
static int gosub_stack[256];
static int gosub_sp = 0;
static double B, B1, D1, E1, F, I, J, LET, M1, P, S;
static char B_str[256] = {0};
static double F_arr[2000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 1 DIM F(4) */
line_1:;
    /* DIM F(4) (handled statically) */
    /* BASIC: 2 PRINT TAB(31);"FUR TRADER" */
line_2:;
    { int _t; for(_t=0; _t<31; _t++) printf(" "); } printf("%s", "FUR TRADER"); printf("\n");
    /* BASIC: 4 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_4:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 6 PRINT: PRINT: PRINT */
line_6:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 15 GOSUB 1091 */
line_15:;
    gosub_stack[gosub_sp++] = 1; goto line_1091; line_ret_1:;
    /* BASIC: 16 LET I=600 */
line_16:;
    /* UNTRANSLATED: LET I=600 */
    /* BASIC: 17 PRINT "DO YOU WISH TO TRADE FURS?" */
line_17:;
    printf("%s", "DO YOU WISH TO TRADE FURS?"); printf("\n");
    /* BASIC: 18 GOSUB 1402 */
line_18:;
    gosub_stack[gosub_sp++] = 2; goto line_1402; line_ret_2:;
    /* BASIC: 19 IF B$="YES" THEN 100 */
line_19:;
    if (strcmp(B_str, "YES") == 0) { goto line_100; }
    /* BASIC: 20 IF B$="YES " THEN 100 */
line_20:;
    if (strcmp(B_str, "YES ") == 0) { goto line_100; }
    /* BASIC: 21 S TO P */
line_21:;
    /* UNTRANSLATED: S TO P */
    /* BASIC: 100 PRINT */
line_100:;
    printf("\n");
    /* BASIC: 101 PRINT "YOU HAVE $";I " SAVINGS." */
line_101:;
    printf("%s", "YOU HAVE $"); printf("%g ", (double)(I)); printf("%s", " SAVINGS."); printf("\n");
    /* BASIC: 102 PRINT "AND 190 FURS TO BEGIN THE EXPEDITION." */
line_102:;
    printf("%s", "AND 190 FURS TO BEGIN THE EXPEDITION."); printf("\n");
    /* BASIC: 261 LET E1=INT((.15*RND(1)+.95)*10^2+.5)/10^2 */
line_261:;
    /* UNTRANSLATED: LET E1=INT((.15*RND(1)+.95)*10^2+.5)/10^2 */
    /* BASIC: 262 LET B1=INT((.25*RND(1)+1.00)*10^2+.5)/10^2 */
line_262:;
    /* UNTRANSLATED: LET B1=INT((.25*RND(1)+1.00)*10^2+.5)/10^2 */
    /* BASIC: 300 PRINT */
line_300:;
    printf("\n");
    /* BASIC: 301 PRINT "YOUR 190 FURS ARE DISTRIBUTED AMONG THE FOLLOWING" */
line_301:;
    printf("%s", "YOUR 190 FURS ARE DISTRIBUTED AMONG THE FOLLOWING"); printf("\n");
    /* BASIC: 302 PRINT "KINDS OF PELTS: MINK, BEAVER, ERMINE AND FOX." */
line_302:;
    printf("%s", "KINDS OF PELTS: MINK, BEAVER, ERMINE AND FOX."); printf("\n");
    /* BASIC: 310 GOSUB 1430 */
line_310:;
    gosub_stack[gosub_sp++] = 3; goto line_1430; line_ret_3:;
    /* BASIC: 315 RESTORE */
line_315:;
    data_ptr = 0;
    /* BASIC: 330 FOR J=1 TO 4 */
line_330:;
    J = 1; for_loop_J_330: if (((1) >= 0 && J > (4)) || ((1) < 0 && J < (4))) goto end_for_J_330;
    /* BASIC: 332 READ B$ */
line_332:;
    read_string(B_str, sizeof(B_str));
    /* BASIC: 333 PRINT */
line_333:;
    printf("\n");
    /* BASIC: 335 PRINT "HOW MANY ";B$;" PELTS DO YOU HAVE"; */
line_335:;
    printf("%s", "HOW MANY "); printf("%s", B_str); printf("%s", " PELTS DO YOU HAVE");
    /* BASIC: 338 INPUT F(J) */
line_338:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &(F_arr[(int)(J)]));
    /* BASIC: 340 LET F(0)=F(1)+F(2)+F(3)+F(4) */
line_340:;
    /* UNTRANSLATED: LET F(0)=F(1)+F(2)+F(3)+F(4) */
    /* BASIC: 342 IF F(0)=190 THEN 1100 */
line_342:;
    if (F_arr[(int)(0)]==190) { goto line_1100; }
    /* BASIC: 344 IF F(0)>190 THEN 500 */
line_344:;
    if (F_arr[(int)(0)]>190) { goto line_500; }
    /* BASIC: 348 NEXT J */
line_348:;
    J += (1); goto for_loop_J_330; end_for_J_330:;
    /* BASIC: 350 GOTO 1100 */
line_350:;
    goto line_1100;
    /* BASIC: 500 PRINT */
line_500:;
    printf("\n");
    /* BASIC: 501 PRINT "YOU MAY NOT HAVE THAT MANY FURS." */
line_501:;
    printf("%s", "YOU MAY NOT HAVE THAT MANY FURS."); printf("\n");
    /* BASIC: 502 PRINT "DO NOT TRY TO CHEAT.  I CAN ADD." */
line_502:;
    printf("%s", "DO NOT TRY TO CHEAT.  I CAN ADD."); printf("\n");
    /* BASIC: 503 PRINT "YOU MUST START AGAIN." */
line_503:;
    printf("%s", "YOU MUST START AGAIN."); printf("\n");
    /* BASIC: 504 GOTO 15 */
line_504:;
    goto line_15;
    /* BASIC: 508 PRINT */
line_508:;
    printf("\n");
    /* BASIC: 511 PRINT "DO YOU WANT TO TRADE FURS NEXT YEAR?" */
line_511:;
    printf("%s", "DO YOU WANT TO TRADE FURS NEXT YEAR?"); printf("\n");
    /* BASIC: 513 GOTO 18 */
line_513:;
    goto line_18;
    /* BASIC: 1091 PRINT "YOU ARE THE LEADER OF A FRENCH FUR TRADING EXPEDITION IN " */
line_1091:;
    printf("%s", "YOU ARE THE LEADER OF A FRENCH FUR TRADING EXPEDITION IN "); printf("\n");
    /* BASIC: 1092 PRINT "1776 LEAVING THE LAKE ONTARIO AREA TO SELL FURS AND GET" */
line_1092:;
    printf("%s", "1776 LEAVING THE LAKE ONTARIO AREA TO SELL FURS AND GET"); printf("\n");
    /* BASIC: 1093 PRINT "SUPPLIES FOR THE NEXT YEAR.  YOU HAVE A CHOICE OF THREE" */
line_1093:;
    printf("%s", "SUPPLIES FOR THE NEXT YEAR.  YOU HAVE A CHOICE OF THREE"); printf("\n");
    /* BASIC: 1094 PRINT "FORTS AT WHICH YOU MAY TRADE.  THE COST OF SUPPLIES" */
line_1094:;
    printf("%s", "FORTS AT WHICH YOU MAY TRADE.  THE COST OF SUPPLIES"); printf("\n");
    /* BASIC: 1095 PRINT "AND THE AMOUNT YOU RECEIVE FOR YOUR FURS WILL DEPEND" */
line_1095:;
    printf("%s", "AND THE AMOUNT YOU RECEIVE FOR YOUR FURS WILL DEPEND"); printf("\n");
    /* BASIC: 1096 PRINT "ON THE FORT THAT YOU CHOOSE." */
line_1096:;
    printf("%s", "ON THE FORT THAT YOU CHOOSE."); printf("\n");
    /* BASIC: 1099 RETURN */
line_1099:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1100 PRINT "YOU MAY TRADE YOUR FURS AT FORT 1, FORT 2," */
line_1100:;
    printf("%s", "YOU MAY TRADE YOUR FURS AT FORT 1, FORT 2,"); printf("\n");
    /* BASIC: 1102 PRINT "OR FORT 3.  FORT 1 IS FORT HOCHELAGA (MONTREAL)" */
line_1102:;
    printf("%s", "OR FORT 3.  FORT 1 IS FORT HOCHELAGA (MONTREAL)"); printf("\n");
    /* BASIC: 1103 PRINT "AND IS UNDER THE PROTECTION OF THE FRENCH ARMY." */
line_1103:;
    printf("%s", "AND IS UNDER THE PROTECTION OF THE FRENCH ARMY."); printf("\n");
    /* BASIC: 1104 PRINT "FORT 2 IS FORT STADACONA (QUEBEC) AND IS UNDER THE" */
line_1104:;
    printf("%s", "FORT 2 IS FORT STADACONA (QUEBEC) AND IS UNDER THE"); printf("\n");
    /* BASIC: 1105 PRINT "PROTECTION OF THE FRENCH ARMY.  HOWEVER, YOU MUST" */
line_1105:;
    printf("%s", "PROTECTION OF THE FRENCH ARMY.  HOWEVER, YOU MUST"); printf("\n");
    /* BASIC: 1106 PRINT "MAKE A PORTAGE AND CROSS THE LACHINE RAPIDS." */
line_1106:;
    printf("%s", "MAKE A PORTAGE AND CROSS THE LACHINE RAPIDS."); printf("\n");
    /* BASIC: 1108 PRINT "FORT 3 IS FORT NEW YORK AND IS UNDER DUTCH CONTROL." */
line_1108:;
    printf("%s", "FORT 3 IS FORT NEW YORK AND IS UNDER DUTCH CONTROL."); printf("\n");
    /* BASIC: 1109 PRINT "YOU MUST CROSS THROUGH IROQUOIS LAND." */
line_1109:;
    printf("%s", "YOU MUST CROSS THROUGH IROQUOIS LAND."); printf("\n");
    /* BASIC: 1110 PRINT "ANSWER 1, 2, OR 3." */
line_1110:;
    printf("%s", "ANSWER 1, 2, OR 3."); printf("\n");
    /* BASIC: 1111 INPUT B */
line_1111:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &B);
    /* BASIC: 1112 IF B=1 THEN 1120 */
line_1112:;
    if (B==1) { goto line_1120; }
    /* BASIC: 1113 IF B=2 THEN 1135 */
line_1113:;
    if (B==2) { goto line_1135; }
    /* BASIC: 1115 IF B=3 THEN 1147 */
line_1115:;
    if (B==3) { goto line_1147; }
    /* BASIC: 1116 GOTO 1110 */
line_1116:;
    goto line_1110;
    /* BASIC: 1120 PRINT "YOU HAVE CHOSEN THE EASIEST ROUTE.  HOWEVER, THE FORT" */
line_1120:;
    printf("%s", "YOU HAVE CHOSEN THE EASIEST ROUTE.  HOWEVER, THE FORT"); printf("\n");
    /* BASIC: 1121 PRINT "IS FAR FROM ANY SEAPORT.  THE VALUE" */
line_1121:;
    printf("%s", "IS FAR FROM ANY SEAPORT.  THE VALUE"); printf("\n");
    /* BASIC: 1122 PRINT "YOU RECEIVE FOR YOUR FURS WILL BE LOW AND THE COST" */
line_1122:;
    printf("%s", "YOU RECEIVE FOR YOUR FURS WILL BE LOW AND THE COST"); printf("\n");
    /* BASIC: 1123 PRINT "OF SUPPLIES HIGHER THAN AT FORTS STADACONA OR NEW YORK." */
line_1123:;
    printf("%s", "OF SUPPLIES HIGHER THAN AT FORTS STADACONA OR NEW YORK."); printf("\n");
    /* BASIC: 1125 GOSUB 1400 */
line_1125:;
    gosub_stack[gosub_sp++] = 4; goto line_1400; line_ret_4:;
    /* BASIC: 1129 IF B$="YES" THEN 1110 */
line_1129:;
    if (strcmp(B_str, "YES") == 0) { goto line_1110; }
    /* BASIC: 1130 GOTO 1160 */
line_1130:;
    goto line_1160;
    /* BASIC: 1135 PRINT "YOU HAVE CHOSEN A HARD ROUTE.  IT IS, IN COMPARSION," */
line_1135:;
    printf("%s", "YOU HAVE CHOSEN A HARD ROUTE.  IT IS, IN COMPARSION,"); printf("\n");
    /* BASIC: 1136 PRINT "HARDER THAN THE ROUTE TO HOCHELAGA BUT EASIER THAN" */
line_1136:;
    printf("%s", "HARDER THAN THE ROUTE TO HOCHELAGA BUT EASIER THAN"); printf("\n");
    /* BASIC: 1137 PRINT "THE ROUTE TO NEW YORK.  YOU WILL RECEIVE AN AVERAGE VALUE" */
line_1137:;
    printf("%s", "THE ROUTE TO NEW YORK.  YOU WILL RECEIVE AN AVERAGE VALUE"); printf("\n");
    /* BASIC: 1138 PRINT "FOR YOUR FURS AND THE COST OF YOUR SUPPLIES WILL BE AVERAGE." */
line_1138:;
    printf("%s", "FOR YOUR FURS AND THE COST OF YOUR SUPPLIES WILL BE AVERAGE."); printf("\n");
    /* BASIC: 1141 GOSUB 1400 */
line_1141:;
    gosub_stack[gosub_sp++] = 5; goto line_1400; line_ret_5:;
    /* BASIC: 1144 IF B$="YES" THEN 1110 */
line_1144:;
    if (strcmp(B_str, "YES") == 0) { goto line_1110; }
    /* BASIC: 1145 GOTO 1198 */
line_1145:;
    goto line_1198;
    /* BASIC: 1147 PRINT "YOU HAVE CHOSEN THE MOST DIFFICULT ROUTE.  AT" */
line_1147:;
    printf("%s", "YOU HAVE CHOSEN THE MOST DIFFICULT ROUTE.  AT"); printf("\n");
    /* BASIC: 1148 PRINT "FORT NEW YORK YOU WILL RECEIVE THE HIGHEST VALUE" */
line_1148:;
    printf("%s", "FORT NEW YORK YOU WILL RECEIVE THE HIGHEST VALUE"); printf("\n");
    /* BASIC: 1149 PRINT "FOR YOUR FURS.  THE COST OF YOUR SUPPLIES" */
line_1149:;
    printf("%s", "FOR YOUR FURS.  THE COST OF YOUR SUPPLIES"); printf("\n");
    /* BASIC: 1150 PRINT "WILL BE LOWER THAN AT ALL THE OTHER FORTS." */
line_1150:;
    printf("%s", "WILL BE LOWER THAN AT ALL THE OTHER FORTS."); printf("\n");
    /* BASIC: 1152 GOSUB 1400 */
line_1152:;
    gosub_stack[gosub_sp++] = 6; goto line_1400; line_ret_6:;
    /* BASIC: 1155 IF B$="YES" THEN 1110 */
line_1155:;
    if (strcmp(B_str, "YES") == 0) { goto line_1110; }
    /* BASIC: 1156 GOTO 1250 */
line_1156:;
    goto line_1250;
    /* BASIC: 1160 LET I=I-160 */
line_1160:;
    /* UNTRANSLATED: LET I=I-160 */
    /* BASIC: 1169 PRINT */
line_1169:;
    printf("\n");
    /* BASIC: 1174 LET M1=INT((.2*RND(1)+.7)*10^2+.5)/10^2 */
line_1174:;
    /* UNTRANSLATED: LET M1=INT((.2*RND(1)+.7)*10^2+.5)/10^2 */
    /* BASIC: 1175 LET E1=INT((.2*RND(1)+.65)*10^2+.5)/10^2 */
line_1175:;
    /* UNTRANSLATED: LET E1=INT((.2*RND(1)+.65)*10^2+.5)/10^2 */
    /* BASIC: 1176 LET B1=INT((.2*RND(1)+.75)*10^2+.5)/10^2 */
line_1176:;
    /* UNTRANSLATED: LET B1=INT((.2*RND(1)+.75)*10^2+.5)/10^2 */
    /* BASIC: 1177 LET D1=INT((.2*RND(1)+.8)*10^2+.5)/10^2 */
line_1177:;
    /* UNTRANSLATED: LET D1=INT((.2*RND(1)+.8)*10^2+.5)/10^2 */
    /* BASIC: 1180 PRINT "SUPPLIES AT FORT HOCHELAGA COST $150.00." */
line_1180:;
    printf("%s", "SUPPLIES AT FORT HOCHELAGA COST $150.00."); printf("\n");
    /* BASIC: 1181 PRINT "YOUR TRAVEL EXPENSES TO HOCHELAGA WERE $10.00." */
line_1181:;
    printf("%s", "YOUR TRAVEL EXPENSES TO HOCHELAGA WERE $10.00."); printf("\n");
    /* BASIC: 1190 GOTO 1410 */
line_1190:;
    goto line_1410;
    /* BASIC: 1198 LET I=I-140 */
line_1198:;
    /* UNTRANSLATED: LET I=I-140 */
    /* BASIC: 1201 PRINT */
line_1201:;
    printf("\n");
    /* BASIC: 1205 LET M1=INT((.3*RND(1)+.85)*10^2+.5)/10^2 */
line_1205:;
    /* UNTRANSLATED: LET M1=INT((.3*RND(1)+.85)*10^2+.5)/10^2 */
    /* BASIC: 1206 LET E1=INT((.15*RND(1)+.8)*10^2+.5)/10^2 */
line_1206:;
    /* UNTRANSLATED: LET E1=INT((.15*RND(1)+.8)*10^2+.5)/10^2 */
    /* BASIC: 1207 LET B1=INT((.2*RND(1)+.9)*10^2+.5)/10^2 */
line_1207:;
    /* UNTRANSLATED: LET B1=INT((.2*RND(1)+.9)*10^2+.5)/10^2 */
    /* BASIC: 1209 LET P=INT(10*RND(1))+1 */
line_1209:;
    /* UNTRANSLATED: LET P=INT(10*RND(1))+1 */
    /* BASIC: 1210 IF P<=2 THEN 1216 */
line_1210:;
    if (P<=2) { goto line_1216; }
    /* BASIC: 1212 IF P<=6 THEN 1224 */
line_1212:;
    if (P<=6) { goto line_1224; }
    /* BASIC: 1213 IF P<=8 THEN 1226 */
line_1213:;
    if (P<=8) { goto line_1226; }
    /* BASIC: 1215 IF P<=10 THEN 1235 */
line_1215:;
    if (P<=10) { goto line_1235; }
    /* BASIC: 1216 LET F(2)=0 */
line_1216:;
    /* UNTRANSLATED: LET F(2)=0 */
    /* BASIC: 1218 PRINT "YOUR BEAVER WERE TOO HEAVY TO CARRY ACROSS" */
line_1218:;
    printf("%s", "YOUR BEAVER WERE TOO HEAVY TO CARRY ACROSS"); printf("\n");
    /* BASIC: 1219 PRINT "THE PORTAGE.  YOU HAD TO LEAVE THE PELTS, BUT FOUND" */
line_1219:;
    printf("%s", "THE PORTAGE.  YOU HAD TO LEAVE THE PELTS, BUT FOUND"); printf("\n");
    /* BASIC: 1220 PRINT "THEM STOLEN WHEN YOU RETURNED." */
line_1220:;
    printf("%s", "THEM STOLEN WHEN YOU RETURNED."); printf("\n");
    /* BASIC: 1221 GOSUB 1244 */
line_1221:;
    gosub_stack[gosub_sp++] = 7; goto line_1244; line_ret_7:;
    /* BASIC: 1222 GOTO 1414 */
line_1222:;
    goto line_1414;
    /* BASIC: 1224 PRINT "YOU ARRIVED SAFELY AT FORT STADACONA." */
line_1224:;
    printf("%s", "YOU ARRIVED SAFELY AT FORT STADACONA."); printf("\n");
    /* BASIC: 1225 GOTO 1239 */
line_1225:;
    goto line_1239;
    /* BASIC: 1226 GOSUB 1430 */
line_1226:;
    gosub_stack[gosub_sp++] = 8; goto line_1430; line_ret_8:;
    /* BASIC: 1230 PRINT "YOUR CANOE UPSET IN THE LACHINE RAPIDS.  YOU" */
line_1230:;
    printf("%s", "YOUR CANOE UPSET IN THE LACHINE RAPIDS.  YOU"); printf("\n");
    /* BASIC: 1231 PRINT "LOST ALL YOUR FURS." */
line_1231:;
    printf("%s", "LOST ALL YOUR FURS."); printf("\n");
    /* BASIC: 1232 GOSUB 1244 */
line_1232:;
    gosub_stack[gosub_sp++] = 9; goto line_1244; line_ret_9:;
    /* BASIC: 1233 GOTO 1418 */
line_1233:;
    goto line_1418;
    /* BASIC: 1235 LET F(4)=0 */
line_1235:;
    /* UNTRANSLATED: LET F(4)=0 */
    /* BASIC: 1237 PRINT "YOUR FOX PELTS WERE NOT CURED PROPERLY." */
line_1237:;
    printf("%s", "YOUR FOX PELTS WERE NOT CURED PROPERLY."); printf("\n");
    /* BASIC: 1238 PRINT "NO ONE WILL BUY THEM." */
line_1238:;
    printf("%s", "NO ONE WILL BUY THEM."); printf("\n");
    /* BASIC: 1239 GOSUB 1244 */
line_1239:;
    gosub_stack[gosub_sp++] = 10; goto line_1244; line_ret_10:;
    /* BASIC: 1240 GOTO 1410 */
line_1240:;
    goto line_1410;
    /* BASIC: 1244 PRINT "SUPPLIES AT FORT STADACONA COST $125.00." */
line_1244:;
    printf("%s", "SUPPLIES AT FORT STADACONA COST $125.00."); printf("\n");
    /* BASIC: 1246 PRINT "YOUR TRAVEL EXPENSES TO STADACONA WERE $15.00." */
line_1246:;
    printf("%s", "YOUR TRAVEL EXPENSES TO STADACONA WERE $15.00."); printf("\n");
    /* BASIC: 1248 RETURN */
line_1248:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1250 LET I=I-105 */
line_1250:;
    /* UNTRANSLATED: LET I=I-105 */
    /* BASIC: 1254 PRINT */
line_1254:;
    printf("\n");
    /* BASIC: 1260 LET M1=INT((.15*RND(1)+1.05)*10^2+.5)/10^2 */
line_1260:;
    /* UNTRANSLATED: LET M1=INT((.15*RND(1)+1.05)*10^2+.5)/10^2 */
    /* BASIC: 1263 LET D1=INT((.25*RND(1)+1.1)*10^2+.5)/10^2 */
line_1263:;
    /* UNTRANSLATED: LET D1=INT((.25*RND(1)+1.1)*10^2+.5)/10^2 */
    /* BASIC: 1270 LET P=INT(10*RND(1))+1 */
line_1270:;
    /* UNTRANSLATED: LET P=INT(10*RND(1))+1 */
    /* BASIC: 1271 IF P<=2 THEN 1281 */
line_1271:;
    if (P<=2) { goto line_1281; }
    /* BASIC: 1272 IF P<=6 THEN 1291 */
line_1272:;
    if (P<=6) { goto line_1291; }
    /* BASIC: 1273 IF P<=8 THEN 1295 */
line_1273:;
    if (P<=8) { goto line_1295; }
    /* BASIC: 1274 IF P<=10 THEN 1306 */
line_1274:;
    if (P<=10) { goto line_1306; }
    /* BASIC: 1281 PRINT "YOU WERE ATTACKED BY A PARTY OF IROQUOIS." */
line_1281:;
    printf("%s", "YOU WERE ATTACKED BY A PARTY OF IROQUOIS."); printf("\n");
    /* BASIC: 1282 PRINT "ALL PEOPLE IN YOUR TRADING GROUP WERE" */
line_1282:;
    printf("%s", "ALL PEOPLE IN YOUR TRADING GROUP WERE"); printf("\n");
    /* BASIC: 1283 PRINT "KILLED.  THIS ENDS THE GAME." */
line_1283:;
    printf("%s", "KILLED.  THIS ENDS THE GAME."); printf("\n");
    /* BASIC: 1284 S TO P */
line_1284:;
    /* UNTRANSLATED: S TO P */
    /* BASIC: 1291 PRINT "YOU WERE LUCKY.  YOU ARRIVED SAFELY" */
line_1291:;
    printf("%s", "YOU WERE LUCKY.  YOU ARRIVED SAFELY"); printf("\n");
    /* BASIC: 1292 PRINT "AT FORT NEW YORK." */
line_1292:;
    printf("%s", "AT FORT NEW YORK."); printf("\n");
    /* BASIC: 1293 GOTO 1311 */
line_1293:;
    goto line_1311;
    /* BASIC: 1295 GOSUB 1430 */
line_1295:;
    gosub_stack[gosub_sp++] = 11; goto line_1430; line_ret_11:;
    /* BASIC: 1300 PRINT "YOU NARROWLY ESCAPED AN IROQUOIS RAIDING PARTY." */
line_1300:;
    printf("%s", "YOU NARROWLY ESCAPED AN IROQUOIS RAIDING PARTY."); printf("\n");
    /* BASIC: 1301 PRINT "HOWEVER, YOU HAD TO LEAVE ALL YOUR FURS BEHIND." */
line_1301:;
    printf("%s", "HOWEVER, YOU HAD TO LEAVE ALL YOUR FURS BEHIND."); printf("\n");
    /* BASIC: 1303 GOSUB 1320 */
line_1303:;
    gosub_stack[gosub_sp++] = 12; goto line_1320; line_ret_12:;
    /* BASIC: 1304 GOTO 1418 */
line_1304:;
    goto line_1418;
    /* BASIC: 1306 LET B1=B1/2 */
line_1306:;
    /* UNTRANSLATED: LET B1=B1/2 */
    /* BASIC: 1307 LET M1=M1/2 */
line_1307:;
    /* UNTRANSLATED: LET M1=M1/2 */
    /* BASIC: 1308 PRINT "YOUR MINK AND BEAVER WERE DAMAGED ON YOUR TRIP." */
line_1308:;
    printf("%s", "YOUR MINK AND BEAVER WERE DAMAGED ON YOUR TRIP."); printf("\n");
    /* BASIC: 1309 PRINT "YOU RECEIVE ONLY HALF THE CURRENT PRICE FOR THESE FURS." */
line_1309:;
    printf("%s", "YOU RECEIVE ONLY HALF THE CURRENT PRICE FOR THESE FURS."); printf("\n");
    /* BASIC: 1311 GOSUB 1320 */
line_1311:;
    gosub_stack[gosub_sp++] = 13; goto line_1320; line_ret_13:;
    /* BASIC: 1312 GOTO 1410 */
line_1312:;
    goto line_1410;
    /* BASIC: 1320 PRINT "SUPPLIES AT NEW YORK COST $80.00." */
line_1320:;
    printf("%s", "SUPPLIES AT NEW YORK COST $80.00."); printf("\n");
    /* BASIC: 1321 PRINT "YOUR TRAVEL EXPENSES TO NEW YORK WERE $25.00." */
line_1321:;
    printf("%s", "YOUR TRAVEL EXPENSES TO NEW YORK WERE $25.00."); printf("\n");
    /* BASIC: 1322 RETURN */
line_1322:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1400 PRINT "DO YOU WANT TO TRADE AT ANOTHER FORT?" */
line_1400:;
    printf("%s", "DO YOU WANT TO TRADE AT ANOTHER FORT?"); printf("\n");
    /* BASIC: 1402 PRINT "ANSWER YES OR NO", */
line_1402:;
    printf("%s", "ANSWER YES OR NO"); printf("\t");
    /* BASIC: 1403 INPUT B$ */
line_1403:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", B_str);
    /* BASIC: 1404 RETURN */
line_1404:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 1410 PRINT */
line_1410:;
    printf("\n");
    /* BASIC: 1412 PRINT "YOUR BEAVER SOLD FOR $";B1*F(2); */
line_1412:;
    printf("%s", "YOUR BEAVER SOLD FOR $"); printf("%g ", (double)(B1*F_arr[(int)(2)]));
    /* BASIC: 1414 PRINT "YOUR FOX SOLD FOR $";D1*F(4) */
line_1414:;
    printf("%s", "YOUR FOX SOLD FOR $"); printf("%g ", (double)(D1*F_arr[(int)(4)])); printf("\n");
    /* BASIC: 1416 PRINT "YOUR ERMINE SOLD FOR $";E1*F(3); */
line_1416:;
    printf("%s", "YOUR ERMINE SOLD FOR $"); printf("%g ", (double)(E1*F_arr[(int)(3)]));
    /* BASIC: 1417 PRINT "YOUR MINK SOLD FOR $";M1*F(1) */
line_1417:;
    printf("%s", "YOUR MINK SOLD FOR $"); printf("%g ", (double)(M1*F_arr[(int)(1)])); printf("\n");
    /* BASIC: 1418 LET I=M1*F(1)+B1*F(2)+E1*F(3)+D1*F(4)+I */
line_1418:;
    /* UNTRANSLATED: LET I=M1*F(1)+B1*F(2)+E1*F(3)+D1*F(4)+I */
    /* BASIC: 1420 PRINT */
line_1420:;
    printf("\n");
    /* BASIC: 1422 PRINT "YOU NOW HAVE $";I;" INCLUDING YOUR PREVIOUS SAVINGS" */
line_1422:;
    printf("%s", "YOU NOW HAVE $"); printf("%g ", (double)(I)); printf("%s", " INCLUDING YOUR PREVIOUS SAVINGS"); printf("\n");
    /* BASIC: 1425 GOTO 508 */
line_1425:;
    goto line_508;
    /* BASIC: 1430 FOR J=1 TO 4 */
line_1430:;
    J = 1; for_loop_J_1430: if (((1) >= 0 && J > (4)) || ((1) < 0 && J < (4))) goto end_for_J_1430;
    /* BASIC: 1432 LET F(J)=0 */
line_1432:;
    /* UNTRANSLATED: LET F(J)=0 */
    /* BASIC: 1434 NEXT J */
line_1434:;
    J += (1); goto for_loop_J_1430; end_for_J_1430:;
    /* BASIC: 1436 RETURN */
line_1436:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     case 3: goto line_ret_3;     case 4: goto line_ret_4;     case 5: goto line_ret_5;     case 6: goto line_ret_6;     case 7: goto line_ret_7;     case 8: goto line_ret_8;     case 9: goto line_ret_9;     case 10: goto line_ret_10;     case 11: goto line_ret_11;     case 12: goto line_ret_12;     case 13: goto line_ret_13;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 2000 DATA "MINK","BEAVER","ERMINE","FOX" */
line_2000:;
    /* UNTRANSLATED: DATA "MINK","BEAVER","ERMINE","FOX" */
    /* BASIC: 2046 END */
line_2046:;
    exit(0);

    return 0;
}
