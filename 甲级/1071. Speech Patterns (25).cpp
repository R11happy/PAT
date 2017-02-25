/**
* @tag     PAT_A_1054
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-25 17:30-18:40
* @version 1.0
* @Language C++
* @Ranking  1655/762
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

// 判断是否是有效字符
bool isAlphanumerical(char c)
{
    if (c >= '0' && c <= '9')    return true;
    if (c >= 'a' && c <= 'z')    return true;
    if (c >= 'A' && c <= 'Z')    return true;
    return false;
}



int main(int argc, char const *argv[])
{
    map<string, int> count; //不能放到全局变量
    string str;
    getline(cin, str);
    int index = 0;
    while (index < str.length())
    {
        string word;
        while (index < str.length() && isAlphanumerical(str[index]))
        {
            // 大写变小写
            if (str[index] >= 'A' && str[index] <= 'Z')
            {
                str[index] += 32;
            }
            word += str[index];
            index++;
        }
        if (word != "")  //单词非空
        {
            if (count.find(word) == count.end()) count[word] = 1;
            else count[word]++;
        }
        while (index < str.length() && !isAlphanumerical(str[index]))    index++;
    }
    string ans;
    int Max = 0;
    for (map<string, int>::iterator it = count.begin(); it != count.end(); it++)
    {
        if (it->second > Max)
        {
            ans = it->first;
            Max = it->second;
        }
    }
    cout << ans << " " << Max << endl;
    return 0;
}



