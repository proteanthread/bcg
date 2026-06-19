/*
 * Transpiled from buzzword.bas
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

static DataItem program_data[39] = {
    { DATA_STR, 0.0, "ABILITY" },
    { DATA_STR, 0.0, "BASAL" },
    { DATA_STR, 0.0, "BEHAVIORAL" },
    { DATA_STR, 0.0, "CHILD-CENTERED" },
    { DATA_STR, 0.0, "DIFFERENTIATED" },
    { DATA_STR, 0.0, "DISCOVERY" },
    { DATA_STR, 0.0, "FLEXIBLE" },
    { DATA_STR, 0.0, "HETEROGENEOUS" },
    { DATA_STR, 0.0, "HOMOGENEOUS" },
    { DATA_STR, 0.0, "MANIPULATIVE" },
    { DATA_STR, 0.0, "MODULAR" },
    { DATA_STR, 0.0, "TAVISTOCK" },
    { DATA_STR, 0.0, "INDIVIDUALIZED" },
    { DATA_STR, 0.0, "LEARNING" },
    { DATA_STR, 0.0, "EVALUATIVE" },
    { DATA_STR, 0.0, "OBJECTIVE" },
    { DATA_STR, 0.0, "COGNITIVE" },
    { DATA_STR, 0.0, "ENRICHMENT" },
    { DATA_STR, 0.0, "SCHEDULING" },
    { DATA_STR, 0.0, "HUMANISTIC" },
    { DATA_STR, 0.0, "INTEGRATED" },
    { DATA_STR, 0.0, "NON-GRADED" },
    { DATA_STR, 0.0, "TRAINING" },
    { DATA_STR, 0.0, "VERTICAL AGE" },
    { DATA_STR, 0.0, "MOTIVATIONAL" },
    { DATA_STR, 0.0, "CREATIVE" },
    { DATA_STR, 0.0, "GROUPING" },
    { DATA_STR, 0.0, "MODIFICATION" },
    { DATA_STR, 0.0, "ACCOUNTABILITY" },
    { DATA_STR, 0.0, "PROCESS" },
    { DATA_STR, 0.0, "CORE CURRICULUM" },
    { DATA_STR, 0.0, "ALGORITHM" },
    { DATA_STR, 0.0, "PERFORMANCE" },
    { DATA_STR, 0.0, "REINFORCEMENT" },
    { DATA_STR, 0.0, "OPEN CLASSROOM" },
    { DATA_STR, 0.0, "RESOURCE" },
    { DATA_STR, 0.0, "STRUCTURE" },
    { DATA_STR, 0.0, "FACILITY" },
    { DATA_STR, 0.0, "ENVIRONMENT" },
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
static double I;
static char A_str[256] = {0};
static char Y_str[256] = {0};
static char A_str_arr[1000][64] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 10 PRINT TAB(26);"BUZZWORD GENERATOR" */
line_10:;
    { int _t; for(_t=0; _t<26; _t++) printf(" "); } printf("%s", "BUZZWORD GENERATOR"); printf("\n");
    /* BASIC: 20 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_20:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 30 PRINT:PRINT:PRINT */
line_30:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 40 PRINT "THIS PROGRAM PRINTS HIGHLY ACCEPTABLE PHRASES IN" */
line_40:;
    printf("%s", "THIS PROGRAM PRINTS HIGHLY ACCEPTABLE PHRASES IN"); printf("\n");
    /* BASIC: 50 PRINT "'EDUCATOR-SPEAK'THAT YOU CAN WORK INTO REPORTS" */
line_50:;
    printf("%s", "'EDUCATOR-SPEAK'THAT YOU CAN WORK INTO REPORTS"); printf("\n");
    /* BASIC: 60 PRINT "AND SPEECHES.  WHENEVER A QUESTION MARK IS PRINTED," */
line_60:;
    printf("%s", "AND SPEECHES.  WHENEVER A QUESTION MARK IS PRINTED,"); printf("\n");
    /* BASIC: 70 PRINT "TYPE A 'Y' FOR ANOTHER PHRASE OR 'N' TO QUIT." */
line_70:;
    printf("%s", "TYPE A 'Y' FOR ANOTHER PHRASE OR 'N' TO QUIT."); printf("\n");
    /* BASIC: 80 PRINT:PRINT:PRINT "HERE'S THE FIRST PHRASE:" */
line_80:;
    printf("\n");
    printf("\n");
    printf("%s", "HERE'S THE FIRST PHRASE:"); printf("\n");
    /* BASIC: 90 DIM A$(40) */
line_90:;
    /* DIM A$(40) (handled statically) */
    /* BASIC: 100 FOR I=1 TO 39 : READ A$(I) : NEXT I */
line_100:;
    I = 1; for_loop_I_100: if (((1) >= 0 && I > (39)) || ((1) < 0 && I < (39))) goto end_for_I_100;
    read_string(A_str_arr[(int)(I)], sizeof(A_str_arr[(int)(I)]));
    I += (1); goto for_loop_I_100; end_for_I_100:;
    /* BASIC: 110 PRINT A$(INT(13*RND(1)+1));" "; */
line_110:;
    printf("%s", A_str_arr[(int)(floor(13*((double)rand() / (double)RAND_MAX)+1))]); printf("%s", " ");
    /* BASIC: 120 PRINT A$(INT(13*RND(1)+14));" "; */
line_120:;
    printf("%s", A_str_arr[(int)(floor(13*((double)rand() / (double)RAND_MAX)+14))]); printf("%s", " ");
    /* BASIC: 130 PRINT A$(INT(13*RND(1)+27)) : PRINT */
line_130:;
    printf("%s", A_str_arr[(int)(floor(13*((double)rand() / (double)RAND_MAX)+27))]); printf("\n");
    printf("\n");
    /* BASIC: 150 INPUT Y$ : IF Y$="Y" THEN 110 */
line_150:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%255s", Y_str);
    if (strcmp(Y_str, "Y") == 0) { goto line_110; }
    /* BASIC: 160 GOTO 999 */
line_160:;
    goto line_999;
    /* BASIC: 200 DATA "ABILITY","BASAL","BEHAVIORAL","CHILD-CENTERED" */
line_200:;
    /* UNTRANSLATED: DATA "ABILITY","BASAL","BEHAVIORAL","CHILD-CENTERED" */
    /* BASIC: 210 DATA "DIFFERENTIATED","DISCOVERY","FLEXIBLE","HETEROGENEOUS" */
line_210:;
    /* UNTRANSLATED: DATA "DIFFERENTIATED","DISCOVERY","FLEXIBLE","HETEROGENEOUS" */
    /* BASIC: 220 DATA "HOMOGENEOUS","MANIPULATIVE","MODULAR","TAVISTOCK" */
line_220:;
    /* UNTRANSLATED: DATA "HOMOGENEOUS","MANIPULATIVE","MODULAR","TAVISTOCK" */
    /* BASIC: 230 DATA "INDIVIDUALIZED","LEARNING","EVALUATIVE","OBJECTIVE" */
line_230:;
    /* UNTRANSLATED: DATA "INDIVIDUALIZED","LEARNING","EVALUATIVE","OBJECTIVE" */
    /* BASIC: 240 DATA "COGNITIVE","ENRICHMENT","SCHEDULING","HUMANISTIC" */
line_240:;
    /* UNTRANSLATED: DATA "COGNITIVE","ENRICHMENT","SCHEDULING","HUMANISTIC" */
    /* BASIC: 250 DATA "INTEGRATED","NON-GRADED","TRAINING","VERTICAL AGE" */
line_250:;
    /* UNTRANSLATED: DATA "INTEGRATED","NON-GRADED","TRAINING","VERTICAL AGE" */
    /* BASIC: 260 DATA "MOTIVATIONAL","CREATIVE","GROUPING","MODIFICATION" */
line_260:;
    /* UNTRANSLATED: DATA "MOTIVATIONAL","CREATIVE","GROUPING","MODIFICATION" */
    /* BASIC: 270 DATA "ACCOUNTABILITY","PROCESS","CORE CURRICULUM","ALGORITHM" */
line_270:;
    /* UNTRANSLATED: DATA "ACCOUNTABILITY","PROCESS","CORE CURRICULUM","ALGORITHM" */
    /* BASIC: 280 DATA "PERFORMANCE","REINFORCEMENT","OPEN CLASSROOM","RESOURCE" */
line_280:;
    /* UNTRANSLATED: DATA "PERFORMANCE","REINFORCEMENT","OPEN CLASSROOM","RESOURCE" */
    /* BASIC: 290 DATA "STRUCTURE","FACILITY","ENVIRONMENT" */
line_290:;
    /* UNTRANSLATED: DATA "STRUCTURE","FACILITY","ENVIRONMENT" */
    /* BASIC: 999 PRINT "COME BACK WHEN YOU NEED HELP WITH ANOTHER REPORT!":END */
line_999:;
    printf("%s", "COME BACK WHEN YOU NEED HELP WITH ANOTHER REPORT!"); printf("\n");
    exit(0);

    return 0;
}
