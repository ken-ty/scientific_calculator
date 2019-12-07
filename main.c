#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#define PI 3.1415926
int main(void)
{
    char inputBuff_1[17];
    char inputBuff_2[16];
    char op;
    double ang;
    double num;
    double ans = 0;
    printf("\n///簡易関数電卓///\n"
            "\t終了コマンド...q\n"
            "\t新しく計算するなら、先頭に演算子をつけずに入力\n"
            "\t続けて計算するなら、先頭に演算子をつけて入力\n\n");
    while (inputBuff_1[0] != 'q')
    {
        op = '0';
        ang, num = 0;

        scanf(" %17s", inputBuff_1);
        if (inputBuff_1[0] == '+' | inputBuff_1[0] == '-' | inputBuff_1[0] == '*' | inputBuff_1[0] == '/') {
            op = inputBuff_1[0];
            strcpy(inputBuff_2, inputBuff_1 + 1);
            strcpy(inputBuff_1, inputBuff_2);
        }
        if (strncmp(inputBuff_1, "sin", 3) == 0 | strncmp(inputBuff_1, "cos", 3) == 0 | strncmp(inputBuff_1, "tan", 3) == 0) {
            ang = atof(inputBuff_1 + 3);
            if (strncmp(inputBuff_1, "sin", 3)) {
                num = sin(ang * PI / 180);
            }else if (strncmp(inputBuff_1, "cos", 3)) {
                num = cos(ang * PI / 180);
            }else if (strncmp(inputBuff_1, "tan", 3)) {
                num = tan(ang * PI / 180);
            }
        }
        else {
            num = atof(inputBuff_1);
        }
        //2回目以降
        if (op == '+' | op == '-' | op == '*' | op == '/') {
            switch (op) {
            case '+':
                ans += num;
                break;
            case '-':
                ans -= num;
                break;
            case '*':
                ans *= num;
                break;
            case '/':
                ans /= num;
                break;

            }
            printf("%f\n", ans);
        }
        //1回目
        else {
            ans = num;
            if (strncmp(inputBuff_1, "sin", 3) == 0 | strncmp(inputBuff_1, "cos", 3) == 0 | strncmp(inputBuff_1, "tan", 3) == 0) {
                printf("%f", ans);
            }
        }
    }
}
