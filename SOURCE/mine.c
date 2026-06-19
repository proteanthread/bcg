/*
 * Transpiled from mine.bas
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
static double A, ADJACENT, ALL, ALREADY, AMOUBN, ANNOUNCE, ANSI, ANY, ARE, AREA, AROUND, ARRAY, AS, ASK, ASKS, ASSERTION, AT, AUTO, BACKGROUND, BACKWARD, BAD, BADGUESS, BASED, BCLR, BCOLOR, BLACK, BLOCK, BLUE, BOARD, BORDER, BOTTOM, BOX, BUT, BUTTON, BY, CALCULATE, CANCEL, CANCELS, CASE, CENTER, CENTERED, CENTERX, CENTERY, CHAR, CHARACTER, CHECK, CHECKS, CLASSIC, CLEAN, CLEAR, CLEARS, CLR, CLRBRD, CLRLIN, CNT, COLOR, COLORS, COMPASS, COMPLETE, CONTINUE, CONTRUCT, COORDINATES, COPY, COUNT, COUNTING, COUNTS, CURRENT, CURSOR, CURSORX, CURSORY, CYAN, DEASSERTION, DECLARES, DEFINES, DELETE, DERIVED, DESIRED, DISPLAY, DISPLAYS, DIV, DO, DOCUMENT, DONE, DOWN, DRAW, DRAWS, EITHER, EMPTY, ENDFUNC, ENDIF, ENDPROC, ENDSEL, ENTER, EQUAL, ETC, ETCAN, ETCHAR, ETCONT, ETCOPY, ETCOPYL, ETDEL, ETDELCB, ETDELCF, ETDELL, ETDOWN, ETEND, ETENDL, ETENDS, ETENTER, ETFUN, ETHOME, ETHOMEL, ETHOMES, ETINSERT, ETINSERTL, ETINSERTT, ETJOYBA, ETJOYBD, ETJOYMOV, ETLEFT, ETLEFTW, ETMENU, ETMOUBA, ETMOUBD, ETMOUMOV, ETPAGD, ETPAGU, ETPRINT, ETPRINTB, ETPRINTS, ETRIGHT, ETRIGHTW, ETSCRD, ETSCRL, ETSCRR, ETSCRU, ETSTOP, ETTAB, ETTERM, ETTIM, ETUP, ETYPE, EVENT, EVENTS, EX, EXISTS, EY, FALSE, FCLR, FCOLOR, FIELD, FIND, FINDS, FLAG, FLAGGED, FLAGGING, FORCE, FORWARD, FOUND, FROM, FUNCTION, GAME, GET, GIVEN, GREEN, GRID, GRIDS, GUESS, GUESSES, HAVE, HELPER, HIDDEN, HIT, HOME, I, IN, INDEX, INDEXES, INITAL, INITALIZE, INSERT, INSIDE, INSQUARE, INVISIBLE, INX, INY, IS, JOYSTICK, KEY, LAYED, LCASE, LEFT, LINE, LOCATION, LOCATIONS, LOWER, MAGENTA, MAIN, MAKE, MAP, MATURES, MAXMINE, MAXX, MAXXS, MAXY, MAXYS, MAY, MEANS, MENU, MESSAGES, MINE, MINEFIELD, MINES, MOUPX, MOUPY, MOUSE, MOUSEX, MOUSEY, MOVE, MOVEMENT, MOVES, N, NEIGHBOR, NEIGHBORS, NEW, NEXTEVENT, NICE, NO, NOW, NUMBER, OBVIOUSLY, OF, OFF, OFFSET, OLD, ON, ONBOARD, ONE, OPERATION, OUT, OUTPUT, OVER, PAGE, PASCAL, PERFORM, PLACE, PLAYER, PLAYING, POINTS, POSITION, POSSIBLY, POSTION, PRESENTED, PRESSED, PRINTS, PROCEDURE, PROCESS, PROCESSES, PROGRAM, PROGRESS, PRTMID, QUIT, RANDOM, RECURSIVELY, RED, REDISPLAY, REPEAT, REPLAY, REQUESTED, REQUIRED, RESPONSE, RESTORED, RETURNED, REVEALING, REVERSE, RIGHT, SAVED, SCAN, SCREEN, SCROLL, SCROLLING, SEEING, SELECT, SET, SETS, SIDE, SIZE, SPACES, SPECIFIED, SQUARE, SQUARES, START, STRING, SX, SY, TABLE, TBOX, TERMINATE, THAT, THE, THIS, THOSE, TILL, TIMER, TITLE, TOGGLE, TOO, TOP, TRIES, TRIGGERING, TRUE, TURN, UNCOVERED, UNTIL, UP, UPPER, USER, VALID, VERSION, VIS, VISABLE, VISADJ, VISCNT, VISIBLE, WAIT, WE, WHERE, WHICH, WHITE, WINS, WON, WORD, X, XI, XN, XOFF, Y, YELLOW, YI, YN, YOFF;
static char C_str[256] = {0};
static char CHAR_str[256] = {0};
static char S_str[256] = {0};
static double AUTO_arr[20000] = {0};
static double BCOLOR_arr[20000] = {0};
static double CLRLIN_arr[20000] = {0};
static double CURSOR_arr[20000] = {0};
static double EVENT_arr[20000] = {0};
static double FCOLOR_arr[20000] = {0};
static double FLAG_arr[20000] = {0};
static double HIT_arr[20000] = {0};
static double LCASE_arr[20000] = {0};
static double PRTMID_arr[20000] = {0};
static double TBOX_arr[20000] = {0};
static double VISADJ_arr[20000] = {0};
static char _input_buf[256];

int main(int argc, char **argv) {
    srand((unsigned int)time(NULL));

    (void)argc;
    (void)argv;
    (void)_input_buf;


    return 0;
}
