/*
 * Transpiled from banner.bas
 * GW-BASIC to strict C89 (ANSI)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    /* Variable declarations */
    double I1, Y, M, READ, MID, PAGE, P, B, W, H, C, DATA, J, TYPE, K, Z, SET, S, E, YOU, X, LEFT, BEING, A, L, CHARACTER, D, U, F, V, WANT, R, PRINTED, O, G1, T, RESTORE, G, N, ALL, T1, I, CENTERED, Q, VERTICAL, STATEMENT, HORIZONTAL;
    char _input_buf[256];
    srand((unsigned int)time(NULL));

    /* BASIC: 10 INPUT "HORIZONTAL";X */
line_10:
    printf("%s", "HORIZONTAL"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &X);
    /* BASIC: 20 INPUT "VERTICAL";Y */
line_20:
    printf("%s", "VERTICAL"); if (fgets(_input_buf, sizeof(_input_buf), stdin)) sscanf(_input_buf, "%lf", &Y);
    /* BASIC: 21 INPUT "CENTERED";L$ */
line_21:
    printf("%s", "CENTERED"); fgets(L_str, sizeof(L_str), stdin); L_str[strcspn(L_str, "\n")] = 0;
    /* BASIC: 22 G1=0:IF L$>"P" THEN G1=1 */
line_22:
    G1 = 0;
    if (L$>"P") { G1 = 1; }
    /* BASIC: 23 INPUT "CHARACTER (TYPE 'ALL' IF YOU WANT CHARACTER BEING PRINTED)";M$ */
line_23:
    printf("%s", "CHARACTER (TYPE 'ALL' IF YOU WANT CHARACTER BEING PRINTED)"); fgets(M_str, sizeof(M_str), stdin); M_str[strcspn(M_str, "\n")] = 0;
    /* BASIC: 29 PRINT "STATEMENT"; */
line_29:
    printf("%s", "STATEMENT");
    /* BASIC: 30 INPUT A$ */
line_30:
    printf("? "); fgets(A_str, sizeof(A_str), stdin); A_str[strcspn(A_str, "\n")] = 0;
    /* BASIC: 35 INPUT "SET PAGE";O$ */
line_35:
    printf("%s", "SET PAGE"); fgets(O_str, sizeof(O_str), stdin); O_str[strcspn(O_str, "\n")] = 0;
    /* BASIC: 40 A=ASC(LEFT$(A$,1)) */
line_40:
    A = ASC(LEFT$(A$,1));
    /* BASIC: 50 REM */
line_50:
    // REM
    /* BASIC: 60 REM */
line_60:
    // REM
    /* BASIC: 70 FOR T=1 TO LEN(A$) */
line_70:
    T = 1; for_loop_T: if ((1 >= 0 && T > LEN(A$)) || (1 < 0 && T < LEN(A$))) goto end_for_T;
    /* BASIC: 80 P$=MID$(A$,T,1) */
line_80:
    strncpy(P_str, "MID$(A$,T,1)", sizeof(P_str)); /* String assign approx */
    /* BASIC: 90 FOR O=1 TO 50 */
line_90:
    O = 1; for_loop_O: if ((1 >= 0 && O > 50) || (1 < 0 && O < 50)) goto end_for_O;
    /* BASIC: 95 READ S$,S(1),S(2),S(3),S(4),S(5),S(6),S(7) */
line_95:
    /* UNTRANSLATED: READ S$,S(1),S(2),S(3),S(4),S(5),S(6),S(7) */
    /* BASIC: 96 IF P$=" " THEN 812 */
line_96:
    if (P$==" ") goto line_812;
    /* BASIC: 100 IF P$=S$ THEN 200 */
line_100:
    if (P$==S$) goto line_200;
    /* BASIC: 120 NEXT O */
line_120:
    O += 1; goto for_loop_O; end_for_O:;
    /* BASIC: 200 RESTORE */
line_200:
    /* UNTRANSLATED: RESTORE */
    /* BASIC: 201 X$=M$ */
line_201:
    strncpy(X_str, "M$", sizeof(X_str)); /* String assign approx */
    /* BASIC: 202 IF M$="ALL" THEN X$=S$ */
line_202:
    if (M$=="ALL") { strncpy(X_str, "S$", sizeof(X_str)); /* String assign approx */ }
    /* BASIC: 205 FOR U=1 TO 7 */
line_205:
    U = 1; for_loop_U: if ((1 >= 0 && U > 7) || (1 < 0 && U < 7)) goto end_for_U;
    /* BASIC: 210 FOR K=8 TO 0 STEP -1 */
line_210:
    K = 8; for_loop_K: if ((-1 >= 0 && K > 0) || (-1 < 0 && K < 0)) goto end_for_K;
    /* BASIC: 230 IF 2^K<S(U) THEN 270 */
line_230:
    if (2^K<S(U)) goto line_270;
    /* BASIC: 240 J(9-K)=0 */
line_240:
    J(9-K) = 0;
    /* BASIC: 250 GOTO 280 */
line_250:
    goto line_280;
    /* BASIC: 270 J(9-K)=1: S(U)=S(U)-2^K */
line_270:
    J(9-K) = 1;
    S(U) = S(U)-2^K;
    /* BASIC: 272 IF S(U)=1 THEN 815 */
line_272:
    if (S(U)==1) goto line_815;
    /* BASIC: 280 NEXT K */
line_280:
    K += -1; goto for_loop_K; end_for_K:;
    /* BASIC: 445 FOR T1=1 TO X */
line_445:
    T1 = 1; for_loop_T1: if ((1 >= 0 && T1 > X) || (1 < 0 && T1 < X)) goto end_for_T1;
    /* BASIC: 447 PRINT TAB((63-4.5*Y)*G1/(LEN(X$))+1); */
line_447:
    { int _t; for(_t=0; _t<(63-4.5*Y)*G1/(LEN(X$))+1; _t++) printf(" "); }
    /* BASIC: 450 FOR B=1 TO F(U) */
line_450:
    B = 1; for_loop_B: if ((1 >= 0 && B > F(U)) || (1 < 0 && B < F(U))) goto end_for_B;
    /* BASIC: 460 IF J(B)=0 THEN 500 */
line_460:
    if (J(B)==0) goto line_500;
    /* BASIC: 465 FOR I=1 TO Y: PRINT X$;: NEXT I */
line_465:
    I = 1; for_loop_I: if ((1 >= 0 && I > Y) || (1 < 0 && I < Y)) goto end_for_I;
    printf("%s", X_str);
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 470 GOTO 600 */
line_470:
    goto line_600;
    /* BASIC: 500 FOR I=1 TO Y */
line_500:
    I = 1; for_loop_I: if ((1 >= 0 && I > Y) || (1 < 0 && I < Y)) goto end_for_I;
    /* BASIC: 510 FOR I1=1 TO LEN(X$) */
line_510:
    I1 = 1; for_loop_I1: if ((1 >= 0 && I1 > LEN(X$)) || (1 < 0 && I1 < LEN(X$))) goto end_for_I1;
    /* BASIC: 520 PRINT " ";: NEXT I1 */
line_520:
    printf("%s", " ");
    I1 += 1; goto for_loop_I1; end_for_I1:;
    /* BASIC: 530 NEXT I */
line_530:
    I += 1; goto for_loop_I; end_for_I:;
    /* BASIC: 600 NEXT B */
line_600:
    B += 1; goto for_loop_B; end_for_B:;
    /* BASIC: 620 PRINT */
line_620:
    printf("\n");
    /* BASIC: 630 NEXT T1 */
line_630:
    T1 += 1; goto for_loop_T1; end_for_T1:;
    /* BASIC: 700 NEXT U */
line_700:
    U += 1; goto for_loop_U; end_for_U:;
    /* BASIC: 750 FOR H=1 TO 2*X: PRINT: NEXT H */
line_750:
    H = 1; for_loop_H: if ((1 >= 0 && H > 2*X) || (1 < 0 && H < 2*X)) goto end_for_H;
    printf("\n");
    H += 1; goto for_loop_H; end_for_H:;
    /* BASIC: 800 NEXT T */
line_800:
    T += 1; goto for_loop_T; end_for_T:;
    /* BASIC: 806 FOR H=1 TO 75: PRINT: NEXT H */
line_806:
    H = 1; for_loop_H: if ((1 >= 0 && H > 75) || (1 < 0 && H < 75)) goto end_for_H;
    printf("\n");
    H += 1; goto for_loop_H; end_for_H:;
    /* BASIC: 810 END */
line_810:
    exit(0);
    /* BASIC: 812 FOR H=1 TO 7*X: PRINT: NEXT H */
line_812:
    H = 1; for_loop_H: if ((1 >= 0 && H > 7*X) || (1 < 0 && H < 7*X)) goto end_for_H;
    printf("\n");
    H += 1; goto for_loop_H; end_for_H:;
    /* BASIC: 813 GOTO 800 */
line_813:
    goto line_800;
    /* BASIC: 815 F(U)=9-K: GOTO 445 */
line_815:
    F(U) = 9-K;
    goto line_445;
    /* BASIC: 899 DATA " ",0,0,0,0,0,0,0 */
line_899:
    /* UNTRANSLATED: DATA " ",0,0,0,0,0,0,0 */
    /* BASIC: 900 DATA "A",505,37,35,34,35,37,505 */
line_900:
    /* UNTRANSLATED: DATA "A",505,37,35,34,35,37,505 */
    /* BASIC: 901 DATA "G",125,131,258,258,290,163,101 */
line_901:
    /* UNTRANSLATED: DATA "G",125,131,258,258,290,163,101 */
    /* BASIC: 902 DATA "E",512,274,274,274,274,258,258 */
line_902:
    /* UNTRANSLATED: DATA "E",512,274,274,274,274,258,258 */
    /* BASIC: 903 DATA "T",2,2,2,512,2,2,2 */
line_903:
    /* UNTRANSLATED: DATA "T",2,2,2,512,2,2,2 */
    /* BASIC: 904 DATA "W",256,257,129,65,129,257,256 */
line_904:
    /* UNTRANSLATED: DATA "W",256,257,129,65,129,257,256 */
    /* BASIC: 905 DATA "L",512,257,257,257,257,257,257 */
line_905:
    /* UNTRANSLATED: DATA "L",512,257,257,257,257,257,257 */
    /* BASIC: 906 DATA "S",69,139,274,274,274,163,69 */
line_906:
    /* UNTRANSLATED: DATA "S",69,139,274,274,274,163,69 */
    /* BASIC: 907 DATA "O",125,131,258,258,258,131,125 */
line_907:
    /* UNTRANSLATED: DATA "O",125,131,258,258,258,131,125 */
    /* BASIC: 908 DATA "N",512,7,9,17,33,193,512 */
line_908:
    /* UNTRANSLATED: DATA "N",512,7,9,17,33,193,512 */
    /* BASIC: 909 DATA "F",512,18,18,18,18,2,2 */
line_909:
    /* UNTRANSLATED: DATA "F",512,18,18,18,18,2,2 */
    /* BASIC: 910 DATA "K",512,17,17,41,69,131,258 */
line_910:
    /* UNTRANSLATED: DATA "K",512,17,17,41,69,131,258 */
    /* BASIC: 911 DATA "B",512,274,274,274,274,274,239 */
line_911:
    /* UNTRANSLATED: DATA "B",512,274,274,274,274,274,239 */
    /* BASIC: 912 DATA "D",512,258,258,258,258,131,125 */
line_912:
    /* UNTRANSLATED: DATA "D",512,258,258,258,258,131,125 */
    /* BASIC: 913 DATA "H",512,17,17,17,17,17,512 */
line_913:
    /* UNTRANSLATED: DATA "H",512,17,17,17,17,17,512 */
    /* BASIC: 914 DATA "M",512,7,13,25,13,7,512 */
line_914:
    /* UNTRANSLATED: DATA "M",512,7,13,25,13,7,512 */
    /* BASIC: 915 DATA "?",5,3,2,354,18,11,5 */
line_915:
    /* UNTRANSLATED: DATA "?",5,3,2,354,18,11,5 */
    /* BASIC: 916 DATA "U",128,129,257,257,257,129,128 */
line_916:
    /* UNTRANSLATED: DATA "U",128,129,257,257,257,129,128 */
    /* BASIC: 917 DATA "R",512,18,18,50,82,146,271 */
line_917:
    /* UNTRANSLATED: DATA "R",512,18,18,50,82,146,271 */
    /* BASIC: 918 DATA "P",512,18,18,18,18,18,15 */
line_918:
    /* UNTRANSLATED: DATA "P",512,18,18,18,18,18,15 */
    /* BASIC: 919 DATA "Q",125,131,258,258,322,131,381 */
line_919:
    /* UNTRANSLATED: DATA "Q",125,131,258,258,322,131,381 */
    /* BASIC: 920 DATA "Y",8,9,17,481,17,9,8 */
line_920:
    /* UNTRANSLATED: DATA "Y",8,9,17,481,17,9,8 */
    /* BASIC: 921 DATA "V",64,65,129,257,129,65,64 */
line_921:
    /* UNTRANSLATED: DATA "V",64,65,129,257,129,65,64 */
    /* BASIC: 922 DATA "X",388,69,41,17,41,69,388 */
line_922:
    /* UNTRANSLATED: DATA "X",388,69,41,17,41,69,388 */
    /* BASIC: 923 DATA "Z",386,322,290,274,266,262,260 */
line_923:
    /* UNTRANSLATED: DATA "Z",386,322,290,274,266,262,260 */
    /* BASIC: 924 DATA "I",258,258,258,512,258,258,258 */
line_924:
    /* UNTRANSLATED: DATA "I",258,258,258,512,258,258,258 */
    /* BASIC: 925 DATA "C",125,131,258,258,258,131,69 */
line_925:
    /* UNTRANSLATED: DATA "C",125,131,258,258,258,131,69 */
    /* BASIC: 926 DATA "J",65,129,257,257,257,129,128 */
line_926:
    /* UNTRANSLATED: DATA "J",65,129,257,257,257,129,128 */
    /* BASIC: 927 DATA "1",0,0,261,259,512,257,257 */
line_927:
    /* UNTRANSLATED: DATA "1",0,0,261,259,512,257,257 */
    /* BASIC: 928 DATA "2",261,387,322,290,274,267,261 */
line_928:
    /* UNTRANSLATED: DATA "2",261,387,322,290,274,267,261 */
    /* BASIC: 929 DATA "*",69,41,17,512,17,41,69 */
line_929:
    /* UNTRANSLATED: DATA "*",69,41,17,512,17,41,69 */
    /* BASIC: 930 DATA "3",66,130,258,274,266,150,100 */
line_930:
    /* UNTRANSLATED: DATA "3",66,130,258,274,266,150,100 */
    /* BASIC: 931 DATA "4",33,49,41,37,35,512,33 */
line_931:
    /* UNTRANSLATED: DATA "4",33,49,41,37,35,512,33 */
    /* BASIC: 932 DATA "5",160,274,274,274,274,274,226 */
line_932:
    /* UNTRANSLATED: DATA "5",160,274,274,274,274,274,226 */
    /* BASIC: 933 DATA "6",194,291,293,297,305,289,193 */
line_933:
    /* UNTRANSLATED: DATA "6",194,291,293,297,305,289,193 */
    /* BASIC: 934 DATA "7",258,130,66,34,18,10,8 */
line_934:
    /* UNTRANSLATED: DATA "7",258,130,66,34,18,10,8 */
    /* BASIC: 935 DATA "8",69,171,274,274,274,171,69 */
line_935:
    /* UNTRANSLATED: DATA "8",69,171,274,274,274,171,69 */
    /* BASIC: 936 DATA "9",263,138,74,42,26,10,7 */
line_936:
    /* UNTRANSLATED: DATA "9",263,138,74,42,26,10,7 */
    /* BASIC: 937 DATA "=",41,41,41,41,41,41,41 */
line_937:
    /* UNTRANSLATED: DATA "=",41,41,41,41,41,41,41 */
    /* BASIC: 938 DATA "!",1,1,1,384,1,1,1 */
line_938:
    /* UNTRANSLATED: DATA "!",1,1,1,384,1,1,1 */
    /* BASIC: 939 DATA "0",57,69,131,258,131,69,57 */
line_939:
    /* UNTRANSLATED: DATA "0",57,69,131,258,131,69,57 */
    /* BASIC: 940 DATA ".",1,1,129,449,129,1,1 */
line_940:
    /* UNTRANSLATED: DATA ".",1,1,129,449,129,1,1 */
    /* BASIC: 1000 STOP */
line_1000:
    exit(0);
    /* BASIC: 1002 END */
line_1002:
    exit(0);

    return 0;
}
