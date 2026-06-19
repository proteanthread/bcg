/*
 * Transpiled from buzzword.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double READ, DISCOVERY, TRAINING, REPORTS, NEW, TYPE, GRADED, BUZZWORD, JERSEY, THE, RESOURCE, REINFORCEMENT, MARK, ENVIRONMENT, A, CORE, ACCEPTABLE, WORK, WHEN, PROGRAM, GROUPING, VERTICAL, IN, NEED, ABILITY, MORRISTOWN, MODIFICATION, HIGHLY, DATA, PRINTS, EDUCATOR, INDIVIDUALIZED, MODULAR, SPEECHES, BACK, MANIPULATIVE, HERE, QUIT, EVALUATIVE, INTEGRATED, PHRASES, OPEN, I, PERFORMANCE, Y, IS, HETEROGENEOUS, SPEAK, CURRICULUM, ACCOUNTABILITY, S, CREATIVE, WHENEVER, STRUCTURE, LEARNING, YOU, MOTIVATIONAL, ALGORITHM, WITH, HOMOGENEOUS, ANOTHER, GENERATOR, QUESTION, PRINTED, COGNITIVE, REPORT, PROCESS, AGE, CLASSROOM, CENTERED, COME, TAVISTOCK, SCHEDULING, INTO, CAN, COMPUTING, HELP, DIFFERENTIATED, HUMANISTIC, ENRICHMENT, FACILITY, OBJECTIVE, FLEXIBLE, FIRST, THAT, PHRASE, BASAL, BEHAVIORAL, N, CHILD, NON, THIS;
    char A_str[1000][256] = {0}; /* Static string array fallback */
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 10 PRINT TAB(26);"BUZZWORD GENERATOR" */
line_10:
    { int _t; for(_t=0; _t<26; _t++) printf(" "); } printf("%s", "BUZZWORD GENERATOR"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 40 PRINT "THIS PROGRAM PRINTS HIGHLY ACCEPTABLE PHRASES IN" */
line_40:
    printf("%s", "THIS PROGRAM PRINTS HIGHLY ACCEPTABLE PHRASES IN"); printf("\n");
    /* BASIC: 50 PRINT "'EDUCATOR-SPEAK'THAT YOU CAN WORK INTO REPORTS" */
line_50:
    printf("%s", "'EDUCATOR-SPEAK'THAT YOU CAN WORK INTO REPORTS"); printf("\n");
    /* BASIC: 60 PRINT "AND SPEECHES.  WHENEVER A QUESTION MARK IS PRINTED," */
line_60:
    printf("%s", "AND SPEECHES.  WHENEVER A QUESTION MARK IS PRINTED,"); printf("\n");
    /* BASIC: 70 PRINT "TYPE A 'Y' FOR ANOTHER PHRASE OR 'N' TO QUIT." */
line_70:
    printf("%s", "TYPE A 'Y' FOR ANOTHER PHRASE OR 'N' TO QUIT."); printf("\n");
    /* BASIC: 80 PRINT:PRINT:PRINT "HERE'S THE FIRST PHRASE:" */
line_80:
    printf("\n");
    printf("\n");
    printf("%s", "HERE'S THE FIRST PHRASE:"); printf("\n");
    /* BASIC: 90 DIM A$(40) */
line_90:
    /* DIM A$(40) (handled statically) */
    /* BASIC: 100 FOR I=1 TO 39 : READ A$(I) : NEXT I */
line_100:
    I = 1; for_loop_I: if ((1 >= 0 && I > 39) || (1 < 0 && I < 39)) goto end_for_I;
    /* UNTRANSLATED: READ A$(I) */
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 110 PRINT A$(INT(13*RND(1)+1));" "; */
line_110:
    printf("%g ", (double)(A$(floor(13*((double)rand() / (double)RAND_MAX)+1)))); printf("%s", " ");
    /* BASIC: 120 PRINT A$(INT(13*RND(1)+14));" "; */
line_120:
    printf("%g ", (double)(A$(floor(13*((double)rand() / (double)RAND_MAX)+14)))); printf("%s", " ");
    /* BASIC: 130 PRINT A$(INT(13*RND(1)+27)) : PRINT */
line_130:
    printf("%g ", (double)(A$(floor(13*((double)rand() / (double)RAND_MAX)+27)))); printf("\n");
    printf("\n");
    /* BASIC: 150 INPUT Y$ : IF Y$="Y" THEN 110 */
line_150:
    printf("? "); fgets(Y_str, sizeof(Y_str), stdin); Y_str[strcspn(Y_str, "\n")] = 0;
    if (Y$=="Y") goto line_110;
    /* BASIC: 160 GOTO 999 */
line_160:
    goto line_999;
    /* BASIC: 200 DATA "ABILITY","BASAL","BEHAVIORAL","CHILD-CENTERED" */
line_200:
    /* UNTRANSLATED: DATA "ABILITY","BASAL","BEHAVIORAL","CHILD-CENTERED" */
    /* BASIC: 210 DATA "DIFFERENTIATED","DISCOVERY","FLEXIBLE","HETEROGENEOUS" */
line_210:
    /* UNTRANSLATED: DATA "DIFFERENTIATED","DISCOVERY","FLEXIBLE","HETEROGENEOUS" */
    /* BASIC: 220 DATA "HOMOGENEOUS","MANIPULATIVE","MODULAR","TAVISTOCK" */
line_220:
    /* UNTRANSLATED: DATA "HOMOGENEOUS","MANIPULATIVE","MODULAR","TAVISTOCK" */
    /* BASIC: 230 DATA "INDIVIDUALIZED","LEARNING","EVALUATIVE","OBJECTIVE" */
line_230:
    /* UNTRANSLATED: DATA "INDIVIDUALIZED","LEARNING","EVALUATIVE","OBJECTIVE" */
    /* BASIC: 240 DATA "COGNITIVE","ENRICHMENT","SCHEDULING","HUMANISTIC" */
line_240:
    /* UNTRANSLATED: DATA "COGNITIVE","ENRICHMENT","SCHEDULING","HUMANISTIC" */
    /* BASIC: 250 DATA "INTEGRATED","NON-GRADED","TRAINING","VERTICAL AGE" */
line_250:
    /* UNTRANSLATED: DATA "INTEGRATED","NON-GRADED","TRAINING","VERTICAL AGE" */
    /* BASIC: 260 DATA "MOTIVATIONAL","CREATIVE","GROUPING","MODIFICATION" */
line_260:
    /* UNTRANSLATED: DATA "MOTIVATIONAL","CREATIVE","GROUPING","MODIFICATION" */
    /* BASIC: 270 DATA "ACCOUNTABILITY","PROCESS","CORE CURRICULUM","ALGORITHM" */
line_270:
    /* UNTRANSLATED: DATA "ACCOUNTABILITY","PROCESS","CORE CURRICULUM","ALGORITHM" */
    /* BASIC: 280 DATA "PERFORMANCE","REINFORCEMENT","OPEN CLASSROOM","RESOURCE" */
line_280:
    /* UNTRANSLATED: DATA "PERFORMANCE","REINFORCEMENT","OPEN CLASSROOM","RESOURCE" */
    /* BASIC: 290 DATA "STRUCTURE","FACILITY","ENVIRONMENT" */
line_290:
    /* UNTRANSLATED: DATA "STRUCTURE","FACILITY","ENVIRONMENT" */
    /* BASIC: 999 PRINT "COME BACK WHEN YOU NEED HELP WITH ANOTHER REPORT!":END */
line_999:
    printf("%s", "COME BACK WHEN YOU NEED HELP WITH ANOTHER REPORT!"); printf("\n");
    exit(0);

    return 0;
}
