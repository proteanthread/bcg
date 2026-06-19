/*
 * Transpiled from hammurabi.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double OFFICE, BETTER, ANCIENT, AVERAGE, SELL, NOW, SUMERIA, P, CHR, ENDED, PERCENT, NEW, TEND, SO, STRUCK, HAMURABI, IVAN, JERSEY, THE, GRAIN, ON, A, PERSON, NERO, CHARLEMANGE, D, BUT, FEED, LIKE, T, SEED, IN, TRADING, OWNS, OUT, HAND, Q, MORRISTOWN, ATE, SOMEWHAT, PEOPLE, HORRIBLE, DECLARED, CAME, RATS, TRY, THROWN, STARTED, HATE, WHAT, BAD, REALLY, CANNOT, HANDED, FIELDS, STARVED, TOO, ALL, COULD, YOUR, I, DIED, CITY, PERFORMANCE, Y, GOVERNING, BEEN, H, IS, OWN, OUR, OF, Z, ONLY, EXT, TRIVIAL, JEFFERSON, COMBINED, S, DUE, CREATIVE, WASN, POPULATION, THINK, PLAGUE, BEG, YOU, STEWARD, NATIONAL, WOULD, WITH, ASSASSINATED, PROBLEMS, ONE, ANOTHER, WE, DEARLY, YEAR, REPORT, BUSHELS, BUY, P1, FINK, HEAVY, SEE, DISRAELI, HOW, C, LONG, WISH, IV, TEN, TOTAL, IMPEACHED, LAND, TERM, YOURSELF, ACRES, COMPUTING, GET, E, GUTS, DONE, FRANKLY, HALF, ACRE, MANY, HARVESTED, AT, L, ALSO, DO, AGAIN, PER, FANTASTIC, D1, N, STORE, HAVE, SMACKS, THIS, PLANT;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 10 PRINT TAB(32);"HAMURABI" */
line_10:
    { int _t; for(_t=0; _t<32; _t++) printf(" "); } printf("%s", "HAMURABI"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 80 PRINT "TRY YOUR HAND AT GOVERNING ANCIENT SUMERIA" */
line_80:
    printf("%s", "TRY YOUR HAND AT GOVERNING ANCIENT SUMERIA"); printf("\n");
    /* BASIC: 90 PRINT "FOR A TEN-YEAR TERM OF OFFICE.":PRINT */
line_90:
    printf("%s", "FOR A TEN-YEAR TERM OF OFFICE."); printf("\n");
    printf("\n");
    /* BASIC: 95 D1=0: P1=0 */
line_95:
    D1 = 0;
    P1 = 0;
    /* BASIC: 100 Z=0: P=95:S=2800: H=3000: E=H-S */
line_100:
    Z = 0;
    P = 95;
    S = 2800;
    H = 3000;
    E = H-S;
    /* BASIC: 110 Y=3: A=H/Y: I=5: Q=1 */
line_110:
    Y = 3;
    A = H/Y;
    I = 5;
    Q = 1;
    /* BASIC: 210 D=0 */
line_210:
    D = 0;
    /* BASIC: 215 PRINT:PRINT:PRINT "HAMURABI:  I BEG TO REPORT TO YOU,": Z=Z+1 */
line_215:
    printf("\n");
    printf("\n");
    printf("%s", "HAMURABI:  I BEG TO REPORT TO YOU,"); printf("\n");
    Z = Z+1;
    /* BASIC: 217 PRINT "IN YEAR";Z;",";D;"PEOPLE STARVED,";I;"CAME TO THE CITY," */
line_217:
    printf("%s", "IN YEAR"); printf("%g ", (double)(Z)); printf("%s", ","); printf("%g ", (double)(D)); printf("%s", "PEOPLE STARVED,"); printf("%g ", (double)(I)); printf("%s", "CAME TO THE CITY,"); printf("\n");
    /* BASIC: 218 P=P+I */
line_218:
    P = P+I;
    /* BASIC: 227 IF Q>0 THEN 230 */
line_227:
    if (Q>0) goto line_230;
    /* BASIC: 228 P=INT(P/2) */
line_228:
    P = floor(P/2);
    /* BASIC: 229 PRINT "A HORRIBLE PLAGUE STRUCK!  HALF THE PEOPLE DIED." */
line_229:
    printf("%s", "A HORRIBLE PLAGUE STRUCK!  HALF THE PEOPLE DIED."); printf("\n");
    /* BASIC: 230 PRINT "POPULATION IS NOW";P */
line_230:
    printf("%s", "POPULATION IS NOW"); printf("%g ", (double)(P)); printf("\n");
    /* BASIC: 232 PRINT "THE CITY NOW OWNS ";A;"ACRES." */
line_232:
    printf("%s", "THE CITY NOW OWNS "); printf("%g ", (double)(A)); printf("%s", "ACRES."); printf("\n");
    /* BASIC: 235 PRINT "YOU HARVESTED";Y;"BUSHELS PER ACRE." */
line_235:
    printf("%s", "YOU HARVESTED"); printf("%g ", (double)(Y)); printf("%s", "BUSHELS PER ACRE."); printf("\n");
    /* BASIC: 250 PRINT "THE RATS ATE";E;"BUSHELS." */
line_250:
    printf("%s", "THE RATS ATE"); printf("%g ", (double)(E)); printf("%s", "BUSHELS."); printf("\n");
    /* BASIC: 260 PRINT "YOU NOW HAVE ";S;"BUSHELS IN STORE.": PRINT */
line_260:
    printf("%s", "YOU NOW HAVE "); printf("%g ", (double)(S)); printf("%s", "BUSHELS IN STORE."); printf("\n");
    printf("\n");
    /* BASIC: 270 IF Z=11 THEN 860 */
line_270:
    if (Z==11) goto line_860;
    /* BASIC: 310 C=INT(10*RND(1)): Y=C+17 */
line_310:
    C = floor(10*((double)rand() / (double)RAND_MAX));
    Y = C+17;
    /* BASIC: 312 PRINT "LAND IS TRADING AT";Y;"BUSHELS PER ACRE." */
line_312:
    printf("%s", "LAND IS TRADING AT"); printf("%g ", (double)(Y)); printf("%s", "BUSHELS PER ACRE."); printf("\n");
    /* BASIC: 320 PRINT "HOW MANY ACRES DO YOU WISH TO BUY"; */
line_320:
    printf("%s", "HOW MANY ACRES DO YOU WISH TO BUY");
    /* BASIC: 321 INPUT Q: IF Q<0 THEN 850 */
line_321:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &Q);
    if (Q<0) goto line_850;
    /* BASIC: 322 IF Y*Q<=S THEN 330 */
line_322:
    if (Y*Q<==S) goto line_330;
    /* BASIC: 323 GOSUB 710 */
line_323:
    /* TODO: GOSUB 710 */
    /* BASIC: 324 GOTO 320 */
line_324:
    goto line_320;
    /* BASIC: 330 IF Q=0 THEN 340 */
line_330:
    if (Q==0) goto line_340;
    /* BASIC: 331 A=A+Q: S=S-Y*Q: C=0 */
line_331:
    A = A+Q;
    S = S-Y*Q;
    C = 0;
    /* BASIC: 334 GOTO 400 */
line_334:
    goto line_400;
    /* BASIC: 340 PRINT "HOW MANY ACRES DO YOU WISH TO SELL"; */
line_340:
    printf("%s", "HOW MANY ACRES DO YOU WISH TO SELL");
    /* BASIC: 341 INPUT Q: IF Q<0 THEN 850 */
line_341:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &Q);
    if (Q<0) goto line_850;
    /* BASIC: 342 IF Q<A THEN 350 */
line_342:
    if (Q<A) goto line_350;
    /* BASIC: 343 GOSUB 720 */
line_343:
    /* TODO: GOSUB 720 */
    /* BASIC: 344 GOTO 340 */
line_344:
    goto line_340;
    /* BASIC: 350 A=A-Q: S=S+Y*Q: C=0 */
line_350:
    A = A-Q;
    S = S+Y*Q;
    C = 0;
    /* BASIC: 400 PRINT */
line_400:
    printf("\n");
    /* BASIC: 410 PRINT "HOW MANY BUSHELS DO YOU WISH TO FEED YOUR PEOPLE"; */
line_410:
    printf("%s", "HOW MANY BUSHELS DO YOU WISH TO FEED YOUR PEOPLE");
    /* BASIC: 411 INPUT Q */
line_411:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &Q);
    /* BASIC: 412 IF Q<0 THEN 850 */
line_412:
    if (Q<0) goto line_850;
    /* BASIC: 418 REM *** TRYING TO USE MORE GRAIN THAN IS IN SILOS? */
line_418:
    // REM *** TRYING TO USE MORE GRAIN THAN IS IN SILOS?
    /* BASIC: 420 IF Q<=S THEN 430 */
line_420:
    if (Q<==S) goto line_430;
    /* BASIC: 421 GOSUB 710 */
line_421:
    /* TODO: GOSUB 710 */
    /* BASIC: 422 GOTO 410 */
line_422:
    goto line_410;
    /* BASIC: 430 S=S-Q: C=1: PRINT */
line_430:
    S = S-Q;
    C = 1;
    printf("\n");
    /* BASIC: 440 PRINT "HOW MANY ACRES DO YOU WISH TO PLANT WITH SEED"; */
line_440:
    printf("%s", "HOW MANY ACRES DO YOU WISH TO PLANT WITH SEED");
    /* BASIC: 441 INPUT D: IF D=0 THEN 511 */
line_441:
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &D);
    if (D==0) goto line_511;
    /* BASIC: 442 IF D<0 THEN 850 */
line_442:
    if (D<0) goto line_850;
    /* BASIC: 444 REM *** TRYING TO PLANT MORE ACRES THAN YOU OWN? */
line_444:
    // REM *** TRYING TO PLANT MORE ACRES THAN YOU OWN?
    /* BASIC: 445 IF D<=A THEN 450 */
line_445:
    if (D<==A) goto line_450;
    /* BASIC: 446 GOSUB 720 */
line_446:
    /* TODO: GOSUB 720 */
    /* BASIC: 447 GOTO 440 */
line_447:
    goto line_440;
    /* BASIC: 449 REM *** ENOUGH GRAIN FOR SEED? */
line_449:
    // REM *** ENOUGH GRAIN FOR SEED?
    /* BASIC: 450 IF INT(D/2)<=S THEN 455 */
line_450:
    if (floor(D/2)<==S) goto line_455;
    /* BASIC: 452 GOSUB 710 */
line_452:
    /* TODO: GOSUB 710 */
    /* BASIC: 453 GOTO 440 */
line_453:
    goto line_440;
    /* BASIC: 454 REM *** ENOUGH PEOPLE TO TEND THE CROPS? */
line_454:
    // REM *** ENOUGH PEOPLE TO TEND THE CROPS?
    /* BASIC: 455 IF D<10*P THEN 510 */
line_455:
    if (D<10*P) goto line_510;
    /* BASIC: 460 PRINT "BUT YOU HAVE ONLY";P;"PEOPLE TO TEND THE FIELDS!  NOW THEN," */
line_460:
    printf("%s", "BUT YOU HAVE ONLY"); printf("%g ", (double)(P)); printf("%s", "PEOPLE TO TEND THE FIELDS!  NOW THEN,"); printf("\n");
    /* BASIC: 470 GOTO 440 */
line_470:
    goto line_440;
    /* BASIC: 510 S=S-INT(D/2) */
line_510:
    S = S-floor(D/2);
    /* BASIC: 511 GOSUB 800 */
line_511:
    /* TODO: GOSUB 800 */
    /* BASIC: 512 REM *** A BOUNTIFUL HARVEST! */
line_512:
    // REM *** A BOUNTIFUL HARVEST!
    /* BASIC: 515 Y=C: H=D*Y: E=0 */
line_515:
    Y = C;
    H = D*Y;
    E = 0;
    /* BASIC: 521 GOSUB 800 */
line_521:
    /* TODO: GOSUB 800 */
    /* BASIC: 522 IF INT(C/2)<>C/2 THEN 530 */
line_522:
    if (floor(C/2)!=C/2) goto line_530;
    /* BASIC: 523 REM *** RATS ARE RUNNING WILD!! */
line_523:
    // REM *** RATS ARE RUNNING WILD!!
    /* BASIC: 525 E=INT(S/C) */
line_525:
    E = floor(S/C);
    /* BASIC: 530 S=S-E+H */
line_530:
    S = S-E+H;
    /* BASIC: 531 GOSUB 800 */
line_531:
    /* TODO: GOSUB 800 */
    /* BASIC: 532 REM *** LET'S HAVE SOME BABIES */
line_532:
    // REM *** LET'S HAVE SOME BABIES
    /* BASIC: 533 I=INT(C*(20*A+S)/P/100+1) */
line_533:
    I = floor(C*(20*A+S)/P/100+1);
    /* BASIC: 539 REM *** HOW MANY PEOPLE HAD FULL TUMMIES? */
line_539:
    // REM *** HOW MANY PEOPLE HAD FULL TUMMIES?
    /* BASIC: 540 C=INT(Q/20) */
line_540:
    C = floor(Q/20);
    /* BASIC: 541 REM *** HORROS, A 15% CHANCE OF PLAGUE */
line_541:
    // REM *** HORROS, A 15% CHANCE OF PLAGUE
    /* BASIC: 542 Q=INT(10*(2*RND(1)-.3)) */
line_542:
    Q = floor(10*(2*((double)rand() / (double)RAND_MAX)-.3));
    /* BASIC: 550 IF P<C THEN 210 */
line_550:
    if (P<C) goto line_210;
    /* BASIC: 551 REM *** STARVE ENOUGH FOR IMPEACHMENT? */
line_551:
    // REM *** STARVE ENOUGH FOR IMPEACHMENT?
    /* BASIC: 552 D=P-C: IF D>.45*P THEN 560 */
line_552:
    D = P-C;
    if (D>.45*P) goto line_560;
    /* BASIC: 553 P1=((Z-1)*P1+D*100/P)/Z */
line_553:
    P1 = ((Z-1)*P1+D*100/P)/Z;
    /* BASIC: 555 P=C: D1=D1+D: GOTO 215 */
line_555:
    P = C;
    D1 = D1+D;
    goto line_215;
    /* BASIC: 560 PRINT: PRINT "YOU STARVED";D;"PEOPLE IN ONE YEAR!!!" */
line_560:
    printf("\n");
    printf("%s", "YOU STARVED"); printf("%g ", (double)(D)); printf("%s", "PEOPLE IN ONE YEAR!!!"); printf("\n");
    /* BASIC: 565 PRINT "DUE TO THIS EXTREME MISMANAGEMENT YOU HAVE NOT ONLY" */
line_565:
    printf("%s", "DUE TO THIS EXTREME MISMANAGEMENT YOU HAVE NOT ONLY"); printf("\n");
    /* BASIC: 566 PRINT "BEEN IMPEACHED AND THROWN OUT OF OFFICE BUT YOU HAVE" */
line_566:
    printf("%s", "BEEN IMPEACHED AND THROWN OUT OF OFFICE BUT YOU HAVE"); printf("\n");
    /* BASIC: 567 PRINT "ALSO BEEN DECLARED NATIONAL FINK!!!!": GOTO 990 */
line_567:
    printf("%s", "ALSO BEEN DECLARED NATIONAL FINK!!!!"); printf("\n");
    goto line_990;
    /* BASIC: 710 PRINT "HAMURABI:  THINK AGAIN.  YOU HAVE ONLY" */
line_710:
    printf("%s", "HAMURABI:  THINK AGAIN.  YOU HAVE ONLY"); printf("\n");
    /* BASIC: 711 PRINT S;"BUSHELS OF GRAIN.  NOW THEN," */
line_711:
    printf("%g ", (double)(S)); printf("%s", "BUSHELS OF GRAIN.  NOW THEN,"); printf("\n");
    /* BASIC: 712 RETURN */
line_712:
    /* TODO: RETURN */
    /* BASIC: 720 PRINT "HAMURABI:  THINK AGAIN.  YOU OWN ONLY";A;"ACRES.  NOW THEN," */
line_720:
    printf("%s", "HAMURABI:  THINK AGAIN.  YOU OWN ONLY"); printf("%g ", (double)(A)); printf("%s", "ACRES.  NOW THEN,"); printf("\n");
    /* BASIC: 730 RETURN */
line_730:
    /* TODO: RETURN */
    /* BASIC: 800 C=INT(RND(1)*5)+1 */
line_800:
    C = floor(((double)rand() / (double)RAND_MAX)*5)+1;
    /* BASIC: 801 RETURN */
line_801:
    /* TODO: RETURN */
    /* BASIC: 850 PRINT: PRINT "HAMURABI:  I CANNOT DO WHAT YOU WISH." */
line_850:
    printf("\n");
    printf("%s", "HAMURABI:  I CANNOT DO WHAT YOU WISH."); printf("\n");
    /* BASIC: 855 PRINT "GET YOURSELF ANOTHER STEWARD!!!!!" */
line_855:
    printf("%s", "GET YOURSELF ANOTHER STEWARD!!!!!"); printf("\n");
    /* BASIC: 857 GOTO 990 */
line_857:
    goto line_990;
    /* BASIC: 860 PRINT "IN YOUR 10-YEAR TERM OF OFFICE,";P1;"PERCENT OF THE" */
line_860:
    printf("%s", "IN YOUR 10-YEAR TERM OF OFFICE,"); printf("%g ", (double)(P1)); printf("%s", "PERCENT OF THE"); printf("\n");
    /* BASIC: 862 PRINT "POPULATION STARVED PER YEAR ON THE AVERAGE, I.E. A TOTAL OF" */
line_862:
    printf("%s", "POPULATION STARVED PER YEAR ON THE AVERAGE, I.E. A TOTAL OF"); printf("\n");
    /* BASIC: 865 PRINT D1;"PEOPLE DIED!!": L=A/P */
line_865:
    printf("%g ", (double)(D1)); printf("%s", "PEOPLE DIED!!"); printf("\n");
    L = A/P;
    /* BASIC: 870 PRINT "YOU STARTED WITH 10 ACRES PER PERSON AND ENDED WITH" */
line_870:
    printf("%s", "YOU STARTED WITH 10 ACRES PER PERSON AND ENDED WITH"); printf("\n");
    /* BASIC: 875 PRINT L;"ACRES PER PERSON.": PRINT */
line_875:
    printf("%g ", (double)(L)); printf("%s", "ACRES PER PERSON."); printf("\n");
    printf("\n");
    /* BASIC: 880 IF P1>33 THEN 565 */
line_880:
    if (P1>33) goto line_565;
    /* BASIC: 885 IF L<7 THEN 565 */
line_885:
    if (L<7) goto line_565;
    /* BASIC: 890 IF P1>10 THEN 940 */
line_890:
    if (P1>10) goto line_940;
    /* BASIC: 892 IF L<9 THEN 940 */
line_892:
    if (L<9) goto line_940;
    /* BASIC: 895 IF P1>3 THEN 960 */
line_895:
    if (P1>3) goto line_960;
    /* BASIC: 896 IF L<10 THEN 960 */
line_896:
    if (L<10) goto line_960;
    /* BASIC: 900 PRINT "A FANTASTIC PERFORMANCE!!!  CHARLEMANGE, DISRAELI, AND" */
line_900:
    printf("%s", "A FANTASTIC PERFORMANCE!!!  CHARLEMANGE, DISRAELI, AND"); printf("\n");
    /* BASIC: 905 PRINT "JEFFERSON COMBINED COULD NOT HAVE DONE BETTER!":GOTO 990 */
line_905:
    printf("%s", "JEFFERSON COMBINED COULD NOT HAVE DONE BETTER!"); printf("\n");
    goto line_990;
    /* BASIC: 940 PRINT "YOUR HEAVY-HANDED PERFORMANCE SMACKS OF NERO AND IVAN IV." */
line_940:
    printf("%s", "YOUR HEAVY-HANDED PERFORMANCE SMACKS OF NERO AND IVAN IV."); printf("\n");
    /* BASIC: 945 PRINT "THE PEOPLE (REMIANING) FIND YOU AN UNPLEASANT RULER, AND," */
line_945:
    printf("%s", "THE PEOPLE (REMIANING) FIND YOU AN UNPLEASANT RULER, AND,"); printf("\n");
    /* BASIC: 950 PRINT "FRANKLY, HATE YOUR GUTS!!":GOTO 990 */
line_950:
    printf("%s", "FRANKLY, HATE YOUR GUTS!!"); printf("\n");
    goto line_990;
    /* BASIC: 960 PRINT "YOUR PERFORMANCE COULD HAVE BEEN SOMEWHAT BETTER, BUT" */
line_960:
    printf("%s", "YOUR PERFORMANCE COULD HAVE BEEN SOMEWHAT BETTER, BUT"); printf("\n");
    /* BASIC: 965 PRINT "REALLY WASN'T TOO BAD AT ALL. ";INT(P*.8*RND(1));"PEOPLE" */
line_965:
    printf("%s", "REALLY WASN'T TOO BAD AT ALL. "); printf("%g ", (double)(floor(P*.8*((double)rand() / (double)RAND_MAX)))); printf("%s", "PEOPLE"); printf("\n");
    /* BASIC: 970 PRINT "WOULD DEARLY LIKE TO SEE YOU ASSASSINATED BUT WE ALL HAVE OUR" */
line_970:
    printf("%s", "WOULD DEARLY LIKE TO SEE YOU ASSASSINATED BUT WE ALL HAVE OUR"); printf("\n");
    /* BASIC: 975 PRINT "TRIVIAL PROBLEMS." */
line_975:
    printf("%s", "TRIVIAL PROBLEMS."); printf("\n");
    /* BASIC: 990 PRINT: FOR N=1 TO 10: PRINT CHR$(7);: NEXT N */
line_990:
    printf("\n");
    N = 1; for_loop_N: if ((1 >= 0 && N > 10) || (1 < 0 && N < 10)) goto end_for_N;
    printf("%g ", (double)(CHR$(7)));
    N += 1; goto for_loop_N; end_for_N:;
    /* BASIC: 995 PRINT "SO LONG FOR NOW.": PRINT */
line_995:
    printf("%s", "SO LONG FOR NOW."); printf("\n");
    printf("\n");
    /* BASIC: 999 END */
line_999:
    exit(0);

    return 0;
}
