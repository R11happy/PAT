/**
* @tag     PAT_A_1100
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-25 14:27-15:32
* @version 1.0
* @Language C++
* @Ranking  1610/798
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

// [0,12]的火星文
string unitDigit[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
// 13的[0,12]倍的火星文
string tenDigit[13] = { "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

string numToStr[170];   //数字->火星文
map<string, int> strToNum;  //火星文->数字

                            // 打表
void init()
{
    // 对十位为0，和个位为0的数字进行特殊处理
    for (int i = 0; i<13; i++)
    {
        numToStr[i] = unitDigit[i];
        numToStr[i * 13] = tenDigit[i];
        strToNum[unitDigit[i]] = i;
        strToNum[tenDigit[i]] = i * 13;
    }

    // 对十位和个位均不为0的数进行处理
    for (int i = 1; i<13; i++)
    {
        for (int j = 1; j<13; j++)
        {
            string str = tenDigit[i] + " " + unitDigit[j];
            numToStr[i * 13 + j] = str;
            strToNum[str] = i * 13 + j;
        }
    }
}

int main(int argc, char const *argv[])
{
    init();
    int n;
    scanf("%d", &n);
    getchar();  //每次用getline或者gets前，先考虑加一个getchar()吸收多余字符
    // 也可以考虑用scanf("%d%*c", &n);  效果一样
    for (int i = 0; i<n; i++)
    {
        string str;
        getline(cin, str);
        // 数字->火星文
        if (str[0] >= '0' && str[0] <= '9')
        {
            int num = 0;
            // 字符串转化为数字
            for (int j = 0; j<str.length(); j++)
            {
                num = num * 10 + str[j] - '0';
            }
            cout << numToStr[num] << endl;
        }
        // 火星文->数字
        else
        {
            cout << strToNum[str] << endl;
        }
    }
    return 0;
}
