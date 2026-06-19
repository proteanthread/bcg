/*
 * Transpiled from stockmarket.bas
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
static double A, B5, C, C5, D, E1, E2, I, I1, I2, LET, N1, N2, P, P5, Q9, S, S4, S5, T, T5, T8, W3, X, X1, X9, Z, Z4, Z5, Z6, Z9;
static double C_arr[2000] = {0};
static double P_arr[2000] = {0};
static double S_arr[2000] = {0};
static double Z_arr[2000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(30);"STOCK MARKET" */
line_10:;
    { int _t; for(_t=0; _t<30; _t++) printf(" "); } printf("%s", "STOCK MARKET"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT: PRINT: PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 100 REM S TO CK MARKET SIMULATION     -S TO CK- */
line_100:;
    /* REM S TO CK MARKET SIMULATION     -S TO CK- */
    /* BASIC: 101 REM REVISED 8/18/70 (D. PESSEL, L. BRAUN, C. LOSIK) */
line_101:;
    /* REM REVISED 8/18/70 (D. PESSEL, L. BRAUN, C. LOSIK) */
    /* BASIC: 102 REM IMP VRBLS: A-MRKT TRND SLP; B5-BRKRGE FEE; C-TTL CSH ASSTS; */
line_102:;
    /* REM IMP VRBLS */
    /* UNTRANSLATED: A-MRKT TRND SLP; B5-BRKRGE FEE; C-TTL CSH ASSTS; */
    /* BASIC: 103 REM C5-TTL CSH ASSTS (TEMP); C(I)-CHNG IN STK VAL; D-TTL ASSTS; */
line_103:;
    /* REM C5-TTL CSH ASSTS (TEMP); C(I)-CHNG IN STK VAL; D-TTL ASSTS; */
    /* BASIC: 104 REM E1,E2-LRG CHNG MISC; I-STCK #; I1,I2-STCKS W LRG CHNG; */
line_104:;
    /* REM E1,E2-LRG CHNG MISC; I-STCK #; I1,I2-STCKS W LRG CHNG; */
    /* BASIC: 105 REM N1,N2-LRG CHNG DAY CNTS; P5-TTL DAYS PRCHSS; P(I)-PRTFL CNTNTS; */
line_105:;
    /* REM N1,N2-LRG CHNG DAY CNTS; P5-TTL DAYS PRCHSS; P(I)-PRTFL CNTNTS; */
    /* BASIC: 106 REM Q9-NEW CYCL?; S4-SGN OF A; S5-TTL DYS SLS; S(I)-VALUE/SHR; */
line_106:;
    /* REM Q9-NEW CYCL?; S4-SGN OF A; S5-TTL DYS SLS; S(I)-VALUE/SHR; */
    /* BASIC: 107 REM T-TTL STCK ASSTS; T5-TTL VAL OF TRNSCTNS; */
line_107:;
    /* REM T-TTL STCK ASSTS; T5-TTL VAL OF TRNSCTNS; */
    /* BASIC: 108 REM W3-LRG CHNG; X1-SMLL CHNG(<$1); Z4,Z5,Z6-NYSE AVE.; Z(I)-TRNSCT */
line_108:;
    /* REM W3-LRG CHNG; X1-SMLL CHNG(<$1); Z4,Z5,Z6-NYSE AVE.; Z(I)-TRNSCT */
    /* BASIC: 110 DIM S(5),P(5),Z(5),C(5) */
line_110:;
    /* DIM S(5),P(5),Z(5),C(5) (handled statically) */
    /* BASIC: 112 REM SLOPE OF MARKET TREND:A  (SAME FOR ALL S TO CKS) */
line_112:;
    /* REM SLOPE OF MARKET TREND */
    /* UNTRANSLATED: A  (SAME FOR ALL S TO CKS) */
    /* BASIC: 113 LET X=1 */
line_113:;
    /* UNTRANSLATED: LET X=1 */
    /* BASIC: 114 LET A=INT((RND(X)/10)*100+.5)/100 */
line_114:;
    /* UNTRANSLATED: LET A=INT((RND(X)/10)*100+.5)/100 */
    /* BASIC: 115 LET T5=0 */
line_115:;
    /* UNTRANSLATED: LET T5=0 */
    /* BASIC: 116 LET X9=0 */
line_116:;
    /* UNTRANSLATED: LET X9=0 */
    /* BASIC: 117 LET N1=0 */
line_117:;
    /* UNTRANSLATED: LET N1=0 */
    /* BASIC: 118 LET N2=0 */
line_118:;
    /* UNTRANSLATED: LET N2=0 */
    /* BASIC: 119 LET E1=0 */
line_119:;
    /* UNTRANSLATED: LET E1=0 */
    /* BASIC: 120 LET E2=0 */
line_120:;
    /* UNTRANSLATED: LET E2=0 */
    /* BASIC: 121 REM INTRODUCTION */
line_121:;
    /* REM INTRODUCTION */
    /* BASIC: 122 PRINT "DO YOU WANT THE INSTRUCTIONS (YES-TYPE 1, NO-TYPE 0)"; */
line_122:;
    printf("%s", "DO YOU WANT THE INSTRUCTIONS (YES-TYPE 1, NO-TYPE 0)");
    /* BASIC: 123 INPUT Z9 */
line_123:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &Z9);
    /* BASIC: 124 PRINT */
line_124:;
    printf("\n");
    /* BASIC: 125 PRINT */
line_125:;
    printf("\n");
    /* BASIC: 126 IF Z9<1 THEN 200 */
line_126:;
    if (Z9<1) { goto line_200; }
    /* BASIC: 130 PRINT "THIS PROGRAM PLAYS THE STOCK MARKET.  YOU WILL BE GIVEN" */
line_130:;
    printf("%s", "THIS PROGRAM PLAYS THE STOCK MARKET.  YOU WILL BE GIVEN"); printf("\n");
    /* BASIC: 132 PRINT "$10,000 AND MAY BUY OR SELL STOCKS.  THE STOCK PRICES WILL" */
line_132:;
    printf("%s", "$10,000 AND MAY BUY OR SELL STOCKS.  THE STOCK PRICES WILL"); printf("\n");
    /* BASIC: 134 PRINT "BE GENERATED RANDOMLY AND THEREFORE THIS MODEL DOES NOT" */
line_134:;
    printf("%s", "BE GENERATED RANDOMLY AND THEREFORE THIS MODEL DOES NOT"); printf("\n");
    /* BASIC: 135 PRINT "REPRESENT EXACTLY WHAT HAPPENS ON THE EXCHANGE.  A TABLE" */
line_135:;
    printf("%s", "REPRESENT EXACTLY WHAT HAPPENS ON THE EXCHANGE.  A TABLE"); printf("\n");
    /* BASIC: 136 PRINT "OF AVAILABLE STOCKS, THEIR PRICES, AND THE NUMBER OF SHARES" */
line_136:;
    printf("%s", "OF AVAILABLE STOCKS, THEIR PRICES, AND THE NUMBER OF SHARES"); printf("\n");
    /* BASIC: 137 PRINT "IN YOUR PORTFOLIO WILL BE PRINTED.  FOLLOWING THIS, THE" */
line_137:;
    printf("%s", "IN YOUR PORTFOLIO WILL BE PRINTED.  FOLLOWING THIS, THE"); printf("\n");
    /* BASIC: 138 PRINT "INITIALS OF EACH STOCK WILL BE PRINTED WITH A QUESTION" */
line_138:;
    printf("%s", "INITIALS OF EACH STOCK WILL BE PRINTED WITH A QUESTION"); printf("\n");
    /* BASIC: 139 PRINT "MARK.  HERE YOU INDICATE A TRANSACTION.  TO BUY A STOCK" */
line_139:;
    printf("%s", "MARK.  HERE YOU INDICATE A TRANSACTION.  TO BUY A STOCK"); printf("\n");
    /* BASIC: 140 PRINT "TYPE +NNN, TO SELL A STOCK TYPE -NNN, WHERE NNN IS THE" */
line_140:;
    printf("%s", "TYPE +NNN, TO SELL A STOCK TYPE -NNN, WHERE NNN IS THE"); printf("\n");
    /* BASIC: 141 PRINT "NUMBER OF SHARES.  A BROKERAGE FEE OF 1% WILL BE CHARGED" */
line_141:;
    printf("%s", "NUMBER OF SHARES.  A BROKERAGE FEE OF 1% WILL BE CHARGED"); printf("\n");
    /* BASIC: 142 PRINT "ON ALL TRANSACTIONS.  NOTE THAT IF A STOCK'S VALUE DROPS" */
line_142:;
    printf("%s", "ON ALL TRANSACTIONS.  NOTE THAT IF A STOCK'S VALUE DROPS"); printf("\n");
    /* BASIC: 143 PRINT "TO ZERO IT MAY REBOUND TO A POSITIVE VALUE AGAIN.  YOU" */
line_143:;
    printf("%s", "TO ZERO IT MAY REBOUND TO A POSITIVE VALUE AGAIN.  YOU"); printf("\n");
    /* BASIC: 144 PRINT "HAVE $10,000 TO INVEST.  USE INTEGERS FOR ALL YOUR INPUTS." */
line_144:;
    printf("%s", "HAVE $10,000 TO INVEST.  USE INTEGERS FOR ALL YOUR INPUTS."); printf("\n");
    /* BASIC: 145 PRINT "(NOTE:  TO GET A 'FEEL' FOR THE MARKET RUN FOR AT LEAST" */
line_145:;
    printf("%s", "(NOTE:  TO GET A 'FEEL' FOR THE MARKET RUN FOR AT LEAST"); printf("\n");
    /* BASIC: 146 PRINT "10 DAYS)" */
line_146:;
    printf("%s", "10 DAYS)"); printf("\n");
    /* BASIC: 147 PRINT "-----GOOD LUCK!-----" */
line_147:;
    printf("%s", "-----GOOD LUCK!-----"); printf("\n");
    /* BASIC: 200 REM GENERATION OF S TO CK TABLE; INPUT REQUESTS */
line_200:;
    /* REM GENERATION OF S TO CK TABLE; INPUT REQUESTS */
    /* BASIC: 210 REM INITIAL S TO CK VALUES */
line_210:;
    /* REM INITIAL S TO CK VALUES */
    /* BASIC: 220 LET S(1)=100 */
line_220:;
    /* UNTRANSLATED: LET S(1)=100 */
    /* BASIC: 230 LET S(2)=85 */
line_230:;
    /* UNTRANSLATED: LET S(2)=85 */
    /* BASIC: 240 LET S(3)=150 */
line_240:;
    /* UNTRANSLATED: LET S(3)=150 */
    /* BASIC: 250 LET S(4)=140 */
line_250:;
    /* UNTRANSLATED: LET S(4)=140 */
    /* BASIC: 260 LET S(5)=110 */
line_260:;
    /* UNTRANSLATED: LET S(5)=110 */
    /* BASIC: 265 REM INITIAL T8 - # DAYS FOR FIRST TREND SLOPE (A) */
line_265:;
    /* REM INITIAL T8 - # DAYS FOR FIRST TREND SLOPE (A) */
    /* BASIC: 266 LET T8=INT(4.99*RND(X)+1) */
line_266:;
    /* UNTRANSLATED: LET T8=INT(4.99*RND(X)+1) */
    /* BASIC: 267 REM R AND OMIZE SIGN OF FIRST TREND SLOPE (A) */
line_267:;
    /* REM R AND OMIZE SIGN OF FIRST TREND SLOPE (A) */
    /* BASIC: 268 IF RND(X)>.5 THEN 270 */
line_268:;
    if (((double)rand() / (double)RAND_MAX)>.5) { goto line_270; }
    /* BASIC: 269 LET A=-A */
line_269:;
    /* UNTRANSLATED: LET A=-A */
    /* BASIC: 270 REM R AND OMIZE INITIAL VALUES */
line_270:;
    /* REM R AND OMIZE INITIAL VALUES */
    /* BASIC: 280 GOSUB 830 */
line_280:;
    gosub_stack[gosub_sp++] = 1; goto line_830; line_ret_1:;
    /* BASIC: 285 REM INITIAL P OR TFOLIO CONTENTS */
line_285:;
    /* REM INITIAL P OR TFOLIO CONTENTS */
    /* BASIC: 290 FOR I=1 TO 5 */
line_290:;
    I = 1; for_loop_I_290: if (((1) >= 0 && I > (5)) || ((1) < 0 && I < (5))) goto end_for_I_290;
    /* BASIC: 300 LET P(I)=0 */
line_300:;
    /* UNTRANSLATED: LET P(I)=0 */
    /* BASIC: 305 LET Z(I)=0 */
line_305:;
    /* UNTRANSLATED: LET Z(I)=0 */
    /* BASIC: 310 NEXT I */
line_310:;
    I += (1); goto for_loop_I_290; end_for_I_290:;
    /* BASIC: 320 PRINT */
line_320:;
    printf("\n");
    /* BASIC: 330 PRINT */
line_330:;
    printf("\n");
    /* BASIC: 333 REM INITIALIZE CASH ASSETS:C */
line_333:;
    /* REM INITIALIZE CASH ASSETS */
    /* UNTRANSLATED: C */
    /* BASIC: 335 LET C=10000 */
line_335:;
    /* UNTRANSLATED: LET C=10000 */
    /* BASIC: 338 REM PRINT INITIAL P OR TFOLIO */
line_338:;
    /* REM PRINT INITIAL P OR TFOLIO */
    /* BASIC: 340 PRINT "STOCK"," ","INITIALS","PRICE/SHARE" */
line_340:;
    printf("%s", "STOCK"); printf("\t"); printf("%s", " "); printf("\t"); printf("%s", "INITIALS"); printf("\t"); printf("%s", "PRICE/SHARE"); printf("\n");
    /* BASIC: 350 PRINT "INT. BALLISTIC MISSILES","  IBM",S(1) */
line_350:;
    printf("%s", "INT. BALLISTIC MISSILES"); printf("\t"); printf("%s", "  IBM"); printf("\t"); printf("%g ", (double)(S_arr[(int)(1)])); printf("\n");
    /* BASIC: 352 PRINT "RED CROSS OF AMERICA","  RCA",S(2) */
line_352:;
    printf("%s", "RED CROSS OF AMERICA"); printf("\t"); printf("%s", "  RCA"); printf("\t"); printf("%g ", (double)(S_arr[(int)(2)])); printf("\n");
    /* BASIC: 354 PRINT "LICHTENSTEIN, BUMRAP & JOKE","  LBJ",S(3) */
line_354:;
    printf("%s", "LICHTENSTEIN, BUMRAP & JOKE"); printf("\t"); printf("%s", "  LBJ"); printf("\t"); printf("%g ", (double)(S_arr[(int)(3)])); printf("\n");
    /* BASIC: 356 PRINT "AMERICAN BANKRUPT CO.","  ABC",S(4) */
line_356:;
    printf("%s", "AMERICAN BANKRUPT CO."); printf("\t"); printf("%s", "  ABC"); printf("\t"); printf("%g ", (double)(S_arr[(int)(4)])); printf("\n");
    /* BASIC: 358 PRINT "CENSURED BOOKS STORE","  CBS",S(5) */
line_358:;
    printf("%s", "CENSURED BOOKS STORE"); printf("\t"); printf("%s", "  CBS"); printf("\t"); printf("%g ", (double)(S_arr[(int)(5)])); printf("\n");
    /* BASIC: 360 PRINT */
line_360:;
    printf("\n");
    /* BASIC: 361 REM NYSE AVERAGE:Z5; TEMP. VALUE:Z4; NET CHANGE:Z6 */
line_361:;
    /* REM NYSE AVERAGE */
    /* UNTRANSLATED: Z5; TEMP. VALUE */
    /* UNTRANSLATED: Z4; NET CHANGE */
    /* UNTRANSLATED: Z6 */
    /* BASIC: 363 LET Z4=Z5 */
line_363:;
    /* UNTRANSLATED: LET Z4=Z5 */
    /* BASIC: 364 LET Z5=0 */
line_364:;
    /* UNTRANSLATED: LET Z5=0 */
    /* BASIC: 365 LET T=0 */
line_365:;
    /* UNTRANSLATED: LET T=0 */
    /* BASIC: 370 FOR I=1 TO 5 */
line_370:;
    I = 1; for_loop_I_370: if (((1) >= 0 && I > (5)) || ((1) < 0 && I < (5))) goto end_for_I_370;
    /* BASIC: 375 LET Z5=Z5+S(I) */
line_375:;
    /* UNTRANSLATED: LET Z5=Z5+S(I) */
    /* BASIC: 380 LET T=T+S(I)*P(I) */
line_380:;
    /* UNTRANSLATED: LET T=T+S(I)*P(I) */
    /* BASIC: 390 NEXT I */
line_390:;
    I += (1); goto for_loop_I_370; end_for_I_370:;
    /* BASIC: 391 LET Z5=INT(100*(Z5/5)+.5)/100 */
line_391:;
    /* UNTRANSLATED: LET Z5=INT(100*(Z5/5)+.5)/100 */
    /* BASIC: 392 LET Z6=INT((Z5-Z4)*100+.5)/100 */
line_392:;
    /* UNTRANSLATED: LET Z6=INT((Z5-Z4)*100+.5)/100 */
    /* BASIC: 393 REM TO TAL ASSETS:D */
line_393:;
    /* REM TO TAL ASSETS */
    /* UNTRANSLATED: D */
    /* BASIC: 394 LET D=T+C */
line_394:;
    /* UNTRANSLATED: LET D=T+C */
    /* BASIC: 395 IF X9>0 THEN 398 */
line_395:;
    if (X9>0) { goto line_398; }
    /* BASIC: 396 PRINT "NEW YORK STOCK EXCHANGE AVERAGE: "Z5 */
line_396:;
    printf("%s", "NEW YORK STOCK EXCHANGE AVERAGE: "); printf("%g ", (double)(Z5)); printf("\n");
    /* BASIC: 397 GOTO 399 */
line_397:;
    goto line_399;
    /* BASIC: 398 PRINT "NEW YORK STOCK EXCHANGE AVERAGE: "Z5"NET CHANGE"Z6 */
line_398:;
    printf("%s", "NEW YORK STOCK EXCHANGE AVERAGE: "); printf("%g ", (double)(Z5)); printf("%s", "NET CHANGE"); printf("%g ", (double)(Z6)); printf("\n");
    /* BASIC: 399 PRINT */
line_399:;
    printf("\n");
    /* BASIC: 400 LET T=INT(100*T+.5)/100 */
line_400:;
    /* UNTRANSLATED: LET T=INT(100*T+.5)/100 */
    /* BASIC: 401 PRINT "TOTAL STOCK ASSETS ARE   $";T */
line_401:;
    printf("%s", "TOTAL STOCK ASSETS ARE   $"); printf("%g ", (double)(T)); printf("\n");
    /* BASIC: 403 LET C=INT(100*C+.5)/100 */
line_403:;
    /* UNTRANSLATED: LET C=INT(100*C+.5)/100 */
    /* BASIC: 405 PRINT "TOTAL CASH ASSETS ARE    $";C */
line_405:;
    printf("%s", "TOTAL CASH ASSETS ARE    $"); printf("%g ", (double)(C)); printf("\n");
    /* BASIC: 407 LET D=INT(100*D+.5)/100 */
line_407:;
    /* UNTRANSLATED: LET D=INT(100*D+.5)/100 */
    /* BASIC: 408 PRINT "TOTAL ASSETS ARE         $";D */
line_408:;
    printf("%s", "TOTAL ASSETS ARE         $"); printf("%g ", (double)(D)); printf("\n");
    /* BASIC: 410 PRINT */
line_410:;
    printf("\n");
    /* BASIC: 411 IF X9=0 THEN 416 */
line_411:;
    if (X9==0) { goto line_416; }
    /* BASIC: 412 PRINT "DO YOU WISH TO CONTINUE (YES-TYPE 1, NO-TYPE 0)"; */
line_412:;
    printf("%s", "DO YOU WISH TO CONTINUE (YES-TYPE 1, NO-TYPE 0)");
    /* BASIC: 413 INPUT Q9 */
line_413:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &Q9);
    /* BASIC: 414 IF Q9<1 THEN 998 */
line_414:;
    if (Q9<1) { goto line_998; }
    /* BASIC: 416 REM INPUT TRANSACTIONS */
line_416:;
    /* REM INPUT TRANSACTIONS */
    /* BASIC: 420 PRINT "WHAT IS YOUR TRANSACTION IN" */
line_420:;
    printf("%s", "WHAT IS YOUR TRANSACTION IN"); printf("\n");
    /* BASIC: 430 PRINT "IBM"; */
line_430:;
    printf("%s", "IBM");
    /* BASIC: 440 INPUT Z(1) */
line_440:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &(Z_arr[(int)(1)]));
    /* BASIC: 450 PRINT "RCA"; */
line_450:;
    printf("%s", "RCA");
    /* BASIC: 460 INPUT Z(2) */
line_460:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &(Z_arr[(int)(2)]));
    /* BASIC: 470 PRINT "LBJ"; */
line_470:;
    printf("%s", "LBJ");
    /* BASIC: 480 INPUT Z(3) */
line_480:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &(Z_arr[(int)(3)]));
    /* BASIC: 490 PRINT "ABC"; */
line_490:;
    printf("%s", "ABC");
    /* BASIC: 500 INPUT Z(4) */
line_500:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &(Z_arr[(int)(4)]));
    /* BASIC: 510 PRINT "CBS"; */
line_510:;
    printf("%s", "CBS");
    /* BASIC: 520 INPUT Z(5) */
line_520:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &(Z_arr[(int)(5)]));
    /* BASIC: 525 PRINT */
line_525:;
    printf("\n");
    /* BASIC: 530 REM TO TAL DAY'S PURCHASES IN $:P5 */
line_530:;
    /* REM TO TAL DAY'S PURCHASES IN $ */
    /* UNTRANSLATED: P5 */
    /* BASIC: 540 LET P5=0 */
line_540:;
    /* UNTRANSLATED: LET P5=0 */
    /* BASIC: 550 REM TO TAL DAY'S SALES IN $:S5 */
line_550:;
    /* REM TO TAL DAY'S SALES IN $ */
    /* UNTRANSLATED: S5 */
    /* BASIC: 560 LET S5=0 */
line_560:;
    /* UNTRANSLATED: LET S5=0 */
    /* BASIC: 570 FOR I=1 TO 5 */
line_570:;
    I = 1; for_loop_I_570: if (((1) >= 0 && I > (5)) || ((1) < 0 && I < (5))) goto end_for_I_570;
    /* BASIC: 575 LET Z(I)=INT(Z(I)+.5) */
line_575:;
    /* UNTRANSLATED: LET Z(I)=INT(Z(I)+.5) */
    /* BASIC: 580 IF Z(I)<=0 THEN 610 */
line_580:;
    if (Z_arr[(int)(I)]<=0) { goto line_610; }
    /* BASIC: 590 LET P5=P5+Z(I)*S(I) */
line_590:;
    /* UNTRANSLATED: LET P5=P5+Z(I)*S(I) */
    /* BASIC: 600 GOTO 620 */
line_600:;
    goto line_620;
    /* BASIC: 610 LET S5=S5-Z(I)*S(I) */
line_610:;
    /* UNTRANSLATED: LET S5=S5-Z(I)*S(I) */
    /* BASIC: 612 IF -Z(I)<=P(I) THEN 620 */
line_612:;
    if (-Z_arr[(int)(I)]<=P_arr[(int)(I)]) { goto line_620; }
    /* BASIC: 614 PRINT "YOU HAVE OVERSOLD A STOCK; TRY AGAIN." */
line_614:;
    printf("%s", "YOU HAVE OVERSOLD A STOCK; TRY AGAIN."); printf("\n");
    /* BASIC: 616 GOTO 420 */
line_616:;
    goto line_420;
    /* BASIC: 620 NEXT I */
line_620:;
    I += (1); goto for_loop_I_570; end_for_I_570:;
    /* BASIC: 622 REM TO TAL VALUE OF TRANSACTIONS:T5 */
line_622:;
    /* REM TO TAL VALUE OF TRANSACTIONS */
    /* UNTRANSLATED: T5 */
    /* BASIC: 625 LET T5=P5+S5 */
line_625:;
    /* UNTRANSLATED: LET T5=P5+S5 */
    /* BASIC: 630 REM BROKERAGE FEE:B5 */
line_630:;
    /* REM BROKERAGE FEE */
    /* UNTRANSLATED: B5 */
    /* BASIC: 640 LET B5=INT(.01*T5*100+.5)/100 */
line_640:;
    /* UNTRANSLATED: LET B5=INT(.01*T5*100+.5)/100 */
    /* BASIC: 650 REM CASH ASSETS=OLD CASH ASSETS- TO TAL PURCHASES */
line_650:;
    /* REM CASH ASSETS=OLD CASH ASSETS- TO TAL PURCHASES */
    /* BASIC: 652 REM -BROKERAGE FEES+ TO TAL SALES:C5 */
line_652:;
    /* REM -BROKERAGE FEES+ TO TAL SALES */
    /* UNTRANSLATED: C5 */
    /* BASIC: 654 LET C5=C-P5-B5+S5 */
line_654:;
    /* UNTRANSLATED: LET C5=C-P5-B5+S5 */
    /* BASIC: 656 IF C5>=0 THEN 674 */
line_656:;
    if (C5>=0) { goto line_674; }
    /* BASIC: 658 PRINT "YOU HAVE USED $"-C5" MORE THAN YOU HAVE." */
line_658:;
    printf("%s", "YOU HAVE USED $"); printf("%g ", (double)(-C5)); printf("%s", " MORE THAN YOU HAVE."); printf("\n");
    /* BASIC: 660 GOTO 420 */
line_660:;
    goto line_420;
    /* BASIC: 674 LET C=C5 */
line_674:;
    /* UNTRANSLATED: LET C=C5 */
    /* BASIC: 675 REM CALCULATE NEW P OR TFOLIO */
line_675:;
    /* REM CALCULATE NEW P OR TFOLIO */
    /* BASIC: 680 FOR I=1 TO 5 */
line_680:;
    I = 1; for_loop_I_680: if (((1) >= 0 && I > (5)) || ((1) < 0 && I < (5))) goto end_for_I_680;
    /* BASIC: 690 LET P(I)=P(I)+Z(I) */
line_690:;
    /* UNTRANSLATED: LET P(I)=P(I)+Z(I) */
    /* BASIC: 700 NEXT I */
line_700:;
    I += (1); goto for_loop_I_680; end_for_I_680:;
    /* BASIC: 710 REM CALCULATE NEW S TO CK VALUES */
line_710:;
    /* REM CALCULATE NEW S TO CK VALUES */
    /* BASIC: 720 GOSUB 830 */
line_720:;
    gosub_stack[gosub_sp++] = 2; goto line_830; line_ret_2:;
    /* BASIC: 750 REM PRINT P OR TFOLIO */
line_750:;
    /* REM PRINT P OR TFOLIO */
    /* BASIC: 751 REM BELL RINGING-DIFFERENT ON MANY COMPUTERS */
line_751:;
    /* REM BELL RINGING-DIFFERENT ON MANY COMPUTERS */
    /* BASIC: 755 PRINT */
line_755:;
    printf("\n");
    /* BASIC: 756 PRINT "**********     END OF DAY'S TRADING     **********" */
line_756:;
    printf("%s", "**********     END OF DAY'S TRADING     **********"); printf("\n");
    /* BASIC: 757 PRINT */
line_757:;
    printf("\n");
    /* BASIC: 758 PRINT */
line_758:;
    printf("\n");
    /* BASIC: 759 IF X9<1 THEN 769 */
line_759:;
    if (X9<1) { goto line_769; }
    /* BASIC: 769 PRINT "STOCK","PRICE/SHARE","HOLDINGS", "VALUE", "NET PRICE CHANGE" */
line_769:;
    printf("%s", "STOCK"); printf("\t"); printf("%s", "PRICE/SHARE"); printf("\t"); printf("%s", "HOLDINGS"); printf("\t"); printf("%s", "VALUE"); printf("\t"); printf("%s", "NET PRICE CHANGE"); printf("\n");
    /* BASIC: 770 PRINT "IBM", S(1), P(1), S(1)*P(1), C(1) */
line_770:;
    printf("%s", "IBM"); printf("\t"); printf("%g ", (double)(S_arr[(int)(1)])); printf("\t"); printf("%g ", (double)(P_arr[(int)(1)])); printf("\t"); printf("%g ", (double)(S_arr[(int)(1)]*P_arr[(int)(1)])); printf("\t"); printf("%g ", (double)(C_arr[(int)(1)])); printf("\n");
    /* BASIC: 771 PRINT "RCA", S(2), P(2), S(2)*P(2), C(2) */
line_771:;
    printf("%s", "RCA"); printf("\t"); printf("%g ", (double)(S_arr[(int)(2)])); printf("\t"); printf("%g ", (double)(P_arr[(int)(2)])); printf("\t"); printf("%g ", (double)(S_arr[(int)(2)]*P_arr[(int)(2)])); printf("\t"); printf("%g ", (double)(C_arr[(int)(2)])); printf("\n");
    /* BASIC: 772 PRINT "LBJ", S(3), P(3), S(3)*P(3), C(3) */
line_772:;
    printf("%s", "LBJ"); printf("\t"); printf("%g ", (double)(S_arr[(int)(3)])); printf("\t"); printf("%g ", (double)(P_arr[(int)(3)])); printf("\t"); printf("%g ", (double)(S_arr[(int)(3)]*P_arr[(int)(3)])); printf("\t"); printf("%g ", (double)(C_arr[(int)(3)])); printf("\n");
    /* BASIC: 773 PRINT "ABC", S(4), P(4), S(4)*P(4), C(4) */
line_773:;
    printf("%s", "ABC"); printf("\t"); printf("%g ", (double)(S_arr[(int)(4)])); printf("\t"); printf("%g ", (double)(P_arr[(int)(4)])); printf("\t"); printf("%g ", (double)(S_arr[(int)(4)]*P_arr[(int)(4)])); printf("\t"); printf("%g ", (double)(C_arr[(int)(4)])); printf("\n");
    /* BASIC: 774 PRINT "CBS", S(5), P(5), S(5)*P(5), C(5) */
line_774:;
    printf("%s", "CBS"); printf("\t"); printf("%g ", (double)(S_arr[(int)(5)])); printf("\t"); printf("%g ", (double)(P_arr[(int)(5)])); printf("\t"); printf("%g ", (double)(S_arr[(int)(5)]*P_arr[(int)(5)])); printf("\t"); printf("%g ", (double)(C_arr[(int)(5)])); printf("\n");
    /* BASIC: 775 LET X9=1 */
line_775:;
    /* UNTRANSLATED: LET X9=1 */
    /* BASIC: 780 PRINT */
line_780:;
    printf("\n");
    /* BASIC: 790 PRINT */
line_790:;
    printf("\n");
    /* BASIC: 810 GOTO 360 */
line_810:;
    goto line_360;
    /* BASIC: 829 REM NEW S TO CK VALUES - SUBROUTINE */
line_829:;
    /* REM NEW S TO CK VALUES - SUBROUTINE */
    /* BASIC: 830 REM R AND OMLY PRODUCE NEW S TO CK VALUES BASED ON PREVIOUS */
line_830:;
    /* REM R AND OMLY PRODUCE NEW S TO CK VALUES BASED ON PREVIOUS */
    /* BASIC: 831 REM DAY'S VALUES */
line_831:;
    /* REM DAY'S VALUES */
    /* BASIC: 832 REM N1,N2 ARE R AND OM NUMBERS OF DAYS WHICH RESPECTIVELY */
line_832:;
    /* REM N1,N2 ARE R AND OM NUMBERS OF DAYS WHICH RESPECTIVELY */
    /* BASIC: 833 REM DETERMINE WHEN S TO CK I1 WILL INCREASE 10 PTS. AND S TO CK */
line_833:;
    /* REM DETERMINE WHEN S TO CK I1 WILL INCREASE 10 PTS. AND S TO CK */
    /* BASIC: 834 REM I2 WILL DECREASE 10 PTS. */
line_834:;
    /* REM I2 WILL DECREASE 10 PTS. */
    /* BASIC: 840 REM IF N1 DAYS HAVE PASSED, PICK AN I1, SET E1, DETERMINE NEW N1 */
line_840:;
    /* REM IF N1 DAYS HAVE PASSED, PICK AN I1, SET E1, DETERMINE NEW N1 */
    /* BASIC: 841 IF N1>0 THEN 850 */
line_841:;
    if (N1>0) { goto line_850; }
    /* BASIC: 845 LET I1=INT(4.99*RND(X)+1) */
line_845:;
    /* UNTRANSLATED: LET I1=INT(4.99*RND(X)+1) */
    /* BASIC: 846 LET N1=INT(4.99*RND(X)+1) */
line_846:;
    /* UNTRANSLATED: LET N1=INT(4.99*RND(X)+1) */
    /* BASIC: 847 LET E1=1 */
line_847:;
    /* UNTRANSLATED: LET E1=1 */
    /* BASIC: 850 REM IF N2 DAYS HAVE PASSED, PICK AN I2, SET E2, DETERMINE NEW N2 */
line_850:;
    /* REM IF N2 DAYS HAVE PASSED, PICK AN I2, SET E2, DETERMINE NEW N2 */
    /* BASIC: 851 IF N2>0 THEN 860 */
line_851:;
    if (N2>0) { goto line_860; }
    /* BASIC: 855 LET I2=INT(4.99*RND(X)+1) */
line_855:;
    /* UNTRANSLATED: LET I2=INT(4.99*RND(X)+1) */
    /* BASIC: 856 LET N2=INT(4.99*RND(X)+1) */
line_856:;
    /* UNTRANSLATED: LET N2=INT(4.99*RND(X)+1) */
    /* BASIC: 857 LET E2=1 */
line_857:;
    /* UNTRANSLATED: LET E2=1 */
    /* BASIC: 860 REM DEDUCT ONE DAY FROM N1 AND N2 */
line_860:;
    /* REM DEDUCT ONE DAY FROM N1 AND N2 */
    /* BASIC: 861 LET N1=N1-1 */
line_861:;
    /* UNTRANSLATED: LET N1=N1-1 */
    /* BASIC: 862 LET N2=N2-1 */
line_862:;
    /* UNTRANSLATED: LET N2=N2-1 */
    /* BASIC: 890 REM LOOP THROUGH ALL S TO CKS */
line_890:;
    /* REM LOOP THROUGH ALL S TO CKS */
    /* BASIC: 900 FOR I=1 TO 5 */
line_900:;
    I = 1; for_loop_I_900: if (((1) >= 0 && I > (5)) || ((1) < 0 && I < (5))) goto end_for_I_900;
    /* BASIC: 910 LET X1=RND(X) */
line_910:;
    /* UNTRANSLATED: LET X1=RND(X) */
    /* BASIC: 915 IF X1>.25 THEN 920 */
line_915:;
    if (X1>.25) { goto line_920; }
    /* BASIC: 916 LET X1=.25 */
line_916:;
    /* UNTRANSLATED: LET X1=.25 */
    /* BASIC: 917 GOTO 935 */
line_917:;
    goto line_935;
    /* BASIC: 920 IF X1>.5 THEN 925 */
line_920:;
    if (X1>.5) { goto line_925; }
    /* BASIC: 921 LET X1=.5 */
line_921:;
    /* UNTRANSLATED: LET X1=.5 */
    /* BASIC: 922 GOTO 935 */
line_922:;
    goto line_935;
    /* BASIC: 925 IF X1>.75 THEN 930 */
line_925:;
    if (X1>.75) { goto line_930; }
    /* BASIC: 926 LET X1=.75 */
line_926:;
    /* UNTRANSLATED: LET X1=.75 */
    /* BASIC: 927 GOTO 935 */
line_927:;
    goto line_935;
    /* BASIC: 930 LET X1=0.0 */
line_930:;
    /* UNTRANSLATED: LET X1=0.0 */
    /* BASIC: 931 REM BIG CHANGE CONSTANT:W3  (SET TO ZERO INITIALLY) */
line_931:;
    /* REM BIG CHANGE CONSTANT */
    /* UNTRANSLATED: W3  (SET TO ZERO INITIALLY) */
    /* BASIC: 935 LET W3=0 */
line_935:;
    /* UNTRANSLATED: LET W3=0 */
    /* BASIC: 936 IF E1<1 THEN 945 */
line_936:;
    if (E1<1) { goto line_945; }
    /* BASIC: 937 IF INT(I1+.5)<>INT(I+.5) THEN 945 */
line_937:;
    if (floor(I1+.5)!=floor(I+.5)) { goto line_945; }
    /* BASIC: 938 REM ADD 10 PTS. TO THIS S TO CK;  RESET E1 */
line_938:;
    /* REM ADD 10 PTS. TO THIS S TO CK;  RESET E1 */
    /* BASIC: 939 LET W3=10 */
line_939:;
    /* UNTRANSLATED: LET W3=10 */
    /* BASIC: 943 LET E1=0 */
line_943:;
    /* UNTRANSLATED: LET E1=0 */
    /* BASIC: 945 IF E2<1 THEN 955 */
line_945:;
    if (E2<1) { goto line_955; }
    /* BASIC: 947 IF INT(I2+.5)<>INT(I+.5) THEN 955 */
line_947:;
    if (floor(I2+.5)!=floor(I+.5)) { goto line_955; }
    /* BASIC: 948 REM SUBTRACT 10 PTS. FROM THIS S TO CK;  RESET E2 */
line_948:;
    /* REM SUBTRACT 10 PTS. FROM THIS S TO CK;  RESET E2 */
    /* BASIC: 949 LET W3=W3-10 */
line_949:;
    /* UNTRANSLATED: LET W3=W3-10 */
    /* BASIC: 953 LET E2=0 */
line_953:;
    /* UNTRANSLATED: LET E2=0 */
    /* BASIC: 954 REM C(I) IS CHANGE IN S TO CK VALUE */
line_954:;
    /* REM C(I) IS CHANGE IN S TO CK VALUE */
    /* BASIC: 955 LET C(I)=INT(A*S(I))+X1+INT(3-6*RND(X)+.5)+W3 */
line_955:;
    /* UNTRANSLATED: LET C(I)=INT(A*S(I))+X1+INT(3-6*RND(X)+.5)+W3 */
    /* BASIC: 956 LET C(I)=INT(100*C(I)+.5)/100 */
line_956:;
    /* UNTRANSLATED: LET C(I)=INT(100*C(I)+.5)/100 */
    /* BASIC: 957 LET S(I)=S(I)+C(I) */
line_957:;
    /* UNTRANSLATED: LET S(I)=S(I)+C(I) */
    /* BASIC: 960 IF S(I)>0 THEN 967 */
line_960:;
    if (S_arr[(int)(I)]>0) { goto line_967; }
    /* BASIC: 964 LET C(I)=0 */
line_964:;
    /* UNTRANSLATED: LET C(I)=0 */
    /* BASIC: 965 LET S(I)=0 */
line_965:;
    /* UNTRANSLATED: LET S(I)=0 */
    /* BASIC: 966 GOTO 970 */
line_966:;
    goto line_970;
    /* BASIC: 967 LET S(I)=INT(100*S(I)+.5)/100 */
line_967:;
    /* UNTRANSLATED: LET S(I)=INT(100*S(I)+.5)/100 */
    /* BASIC: 970 NEXT I */
line_970:;
    I += (1); goto for_loop_I_900; end_for_I_900:;
    /* BASIC: 972 REM AFTER T8 DAYS R AND OMLY CHANGE TREND SIGN AND SLOPE */
line_972:;
    /* REM AFTER T8 DAYS R AND OMLY CHANGE TREND SIGN AND SLOPE */
    /* BASIC: 973 LET T8=T8-1 */
line_973:;
    /* UNTRANSLATED: LET T8=T8-1 */
    /* BASIC: 974 IF T8<1 THEN 985 */
line_974:;
    if (T8<1) { goto line_985; }
    /* BASIC: 980 RETURN */
line_980:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 985 REM R AND OMLY CHANGE TREND SIGN AND SLOPE (A), AND DURATION */
line_985:;
    /* REM R AND OMLY CHANGE TREND SIGN AND SLOPE (A), AND DURATION */
    /* BASIC: 986 REM OF TREND (T8) */
line_986:;
    /* REM OF TREND (T8) */
    /* BASIC: 990 LET T8=INT(4.99*RND(X)+1) */
line_990:;
    /* UNTRANSLATED: LET T8=INT(4.99*RND(X)+1) */
    /* BASIC: 992 LET A=INT((RND(X)/10)*100+.5)/100 */
line_992:;
    /* UNTRANSLATED: LET A=INT((RND(X)/10)*100+.5)/100 */
    /* BASIC: 993 LET S4=RND(X) */
line_993:;
    /* UNTRANSLATED: LET S4=RND(X) */
    /* BASIC: 994 IF S4<=.5 THEN 997 */
line_994:;
    if (S4<=.5) { goto line_997; }
    /* BASIC: 995 LET A=-A */
line_995:;
    /* UNTRANSLATED: LET A=-A */
    /* BASIC: 997 RETURN */
line_997:;
    switch (gosub_stack[--gosub_sp]) {     case 1: goto line_ret_1;     case 2: goto line_ret_2;     default: fprintf(stderr, "GOSUB stack error\n"); exit(1); }
    /* BASIC: 998 PRINT "HOPE YOU HAD FUN!!" */
line_998:;
    printf("%s", "HOPE YOU HAD FUN!!"); printf("\n");
    /* BASIC: 999 END */
line_999:;
    exit(0);

    return 0;
}
