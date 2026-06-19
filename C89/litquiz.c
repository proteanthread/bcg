/*
 * Transpiled from litquiz.bas
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
static double A, P, R, S;
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;

    /* BASIC: 1 PRINT TAB(25);"LITERATURE QUIZ" */
line_1:;
    { int _t; for(_t=0; _t<25; _t++) printf(" "); } printf("%s", "LITERATURE QUIZ"); printf("\n");
    /* BASIC: 2 PRINT TAB(15);"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY" */
line_2:;
    { int _t; for(_t=0; _t<15; _t++) printf(" "); } printf("%s", "CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY"); printf("\n");
    /* BASIC: 3 PRINT:PRINT:PRINT */
line_3:;
    printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 5 R=0 */
line_5:;
    R = 0;
    /* BASIC: 10 PRINT "TEST YOUR KNOWLEDGE OF CHILDREN'S LITERATURE." */
line_10:;
    printf("%s", "TEST YOUR KNOWLEDGE OF CHILDREN'S LITERATURE."); printf("\n");
    /* BASIC: 12 PRINT: PRINT "THIS IS A MULTIPLE-CHOICE QUIZ." */
line_12:;
    printf("\n");
    printf("%s", "THIS IS A MULTIPLE-CHOICE QUIZ."); printf("\n");
    /* BASIC: 13 PRINT "TYPE A 1, 2, 3, OR 4 AFTER THE QUESTION MARK." */
line_13:;
    printf("%s", "TYPE A 1, 2, 3, OR 4 AFTER THE QUESTION MARK."); printf("\n");
    /* BASIC: 15 PRINT: PRINT "GOOD LUCK!": PRINT: PRINT */
line_15:;
    printf("\n");
    printf("%s", "GOOD LUCK!"); printf("\n");
    printf("\n");
    printf("\n");
    /* BASIC: 40 PRINT "IN PINOCCHIO, WHAT WAS THE NAME OF THE CAT" */
line_40:;
    printf("%s", "IN PINOCCHIO, WHAT WAS THE NAME OF THE CAT"); printf("\n");
    /* BASIC: 42 PRINT "1)TIGGER, 2)CICERO, 3)FIGARO, 4)GUIPETTO"; */
line_42:;
    printf("%s", "1)TIGGER, 2)CICERO, 3)FIGARO, 4)GUIPETTO");
    /* BASIC: 43 INPUT A: IF A=3 THEN 46 */
line_43:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &A);
    if (A==3) { goto line_46; }
    /* BASIC: 44 PRINT "SORRY...FIGARO WAS HIS NAME.": GOTO 50 */
line_44:;
    printf("%s", "SORRY...FIGARO WAS HIS NAME."); printf("\n");
    goto line_50;
    /* BASIC: 46 PRINT "VERY GOOD!  HERE'S ANOTHER." */
line_46:;
    printf("%s", "VERY GOOD!  HERE'S ANOTHER."); printf("\n");
    /* BASIC: 47 R=R+1 */
line_47:;
    R = R+1;
    /* BASIC: 50 PRINT: PRINT */
line_50:;
    printf("\n");
    printf("\n");
    /* BASIC: 51 PRINT "FROM WHOSE GARDEN DID BUGS BUNNY STEAL THE CARROTS?" */
line_51:;
    printf("%s", "FROM WHOSE GARDEN DID BUGS BUNNY STEAL THE CARROTS?"); printf("\n");
    /* BASIC: 52 PRINT "1)MR. NIXON'S, 2)ELMER FUDD'S, 3)CLEM JUDD'S, 4)STROMBOLI'S"; */
line_52:;
    printf("%s", "1)MR. NIXON'S, 2)ELMER FUDD'S, 3)CLEM JUDD'S, 4)STROMBOLI'S");
    /* BASIC: 53 INPUT A: IF A=2 THEN 56 */
line_53:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &A);
    if (A==2) { goto line_56; }
    /* BASIC: 54 PRINT "TOO BAD...IT WAS ELMER FUDD'S GARDEN.": GOTO 60 */
line_54:;
    printf("%s", "TOO BAD...IT WAS ELMER FUDD'S GARDEN."); printf("\n");
    goto line_60;
    /* BASIC: 56 PRINT "PRETTY GOOD!" */
line_56:;
    printf("%s", "PRETTY GOOD!"); printf("\n");
    /* BASIC: 57 R=R+1 */
line_57:;
    R = R+1;
    /* BASIC: 60 PRINT: PRINT */
line_60:;
    printf("\n");
    printf("\n");
    /* BASIC: 61 PRINT "IN THE WIZARD OF OS, DOROTHY'S DOG WAS NAMED" */
line_61:;
    printf("%s", "IN THE WIZARD OF OS, DOROTHY'S DOG WAS NAMED"); printf("\n");
    /* BASIC: 62 PRINT "1)CICERO, 2)TRIXIA, 3)KING, 4)TOTO"; */
line_62:;
    printf("%s", "1)CICERO, 2)TRIXIA, 3)KING, 4)TOTO");
    /* BASIC: 63 INPUT A: IF A=4 THEN 66 */
line_63:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &A);
    if (A==4) { goto line_66; }
    /* BASIC: 64 PRINT "BACK TO THE BOOKS,...TOTO WAS HIS NAME.": GOTO 70 */
line_64:;
    printf("%s", "BACK TO THE BOOKS,...TOTO WAS HIS NAME."); printf("\n");
    goto line_70;
    /* BASIC: 66 PRINT "YEA!  YOU'RE A REAL LITERATURE GIANT." */
line_66:;
    printf("%s", "YEA!  YOU'RE A REAL LITERATURE GIANT."); printf("\n");
    /* BASIC: 67 R=R+1 */
line_67:;
    R = R+1;
    /* BASIC: 70 PRINT:PRINT */
line_70:;
    printf("\n");
    printf("\n");
    /* BASIC: 71 PRINT "WHO WAS THE FAIR MAIDEN WHO ATE THE POISON APPLE" */
line_71:;
    printf("%s", "WHO WAS THE FAIR MAIDEN WHO ATE THE POISON APPLE"); printf("\n");
    /* BASIC: 72 PRINT "1)SLEEPING BEAUTY, 2)CINDERELLA, 3)SNOW WHITE, 4)WENDY"; */
line_72:;
    printf("%s", "1)SLEEPING BEAUTY, 2)CINDERELLA, 3)SNOW WHITE, 4)WENDY");
    /* BASIC: 73 INPUT A: IF A=3 THEN 76 */
line_73:;
    printf("? "); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &A);
    if (A==3) { goto line_76; }
    /* BASIC: 74 PRINT "OH, COME ON NOW...IT WAS SNOW WHITE." */
line_74:;
    printf("%s", "OH, COME ON NOW...IT WAS SNOW WHITE."); printf("\n");
    /* BASIC: 75 GOTO 80 */
line_75:;
    goto line_80;
    /* BASIC: 76 PRINT "GOOD MEMORY!" */
line_76:;
    printf("%s", "GOOD MEMORY!"); printf("\n");
    /* BASIC: 77 R=R+1 */
line_77:;
    R = R+1;
    /* BASIC: 80 PRINT:PRINT */
line_80:;
    printf("\n");
    printf("\n");
    /* BASIC: 85 IF R=4 THEN 100 */
line_85:;
    if (R==4) { goto line_100; }
    /* BASIC: 90 IF R<2 THEN 200 */
line_90:;
    if (R<2) { goto line_200; }
    /* BASIC: 92 PRINT "NOT BAD, BUT YOU MIGHT SPEND A LITTLE MORE TIME" */
line_92:;
    printf("%s", "NOT BAD, BUT YOU MIGHT SPEND A LITTLE MORE TIME"); printf("\n");
    /* BASIC: 94 PRINT "READING THE NURSERY GREATS." */
line_94:;
    printf("%s", "READING THE NURSERY GREATS."); printf("\n");
    /* BASIC: 96 S TO P */
line_96:;
    /* UNTRANSLATED: S TO P */
    /* BASIC: 100 PRINT "WOW!  THAT'S SUPER!  YOU REALLY KNOW YOUR NURSERY" */
line_100:;
    printf("%s", "WOW!  THAT'S SUPER!  YOU REALLY KNOW YOUR NURSERY"); printf("\n");
    /* BASIC: 110 PRINT "YOUR NEXT QUIZ WILL BE ON 2ND CENTURY CHINESE" */
line_110:;
    printf("%s", "YOUR NEXT QUIZ WILL BE ON 2ND CENTURY CHINESE"); printf("\n");
    /* BASIC: 120 PRINT "LITERATURE (HA, HA, HA)" */
line_120:;
    printf("%s", "LITERATURE (HA, HA, HA)"); printf("\n");
    /* BASIC: 130 S TO P */
line_130:;
    /* UNTRANSLATED: S TO P */
    /* BASIC: 200 PRINT "UGH.  THAT WAS DEFINITELY NOT TOO SWIFT.  BACK TO" */
line_200:;
    printf("%s", "UGH.  THAT WAS DEFINITELY NOT TOO SWIFT.  BACK TO"); printf("\n");
    /* BASIC: 205 PRINT "NURSERY SCHOOL FOR YOU, MY FRIEND." */
line_205:;
    printf("%s", "NURSERY SCHOOL FOR YOU, MY FRIEND."); printf("\n");
    /* BASIC: 999 END */
line_999:;
    exit(0);

    return 0;
}
