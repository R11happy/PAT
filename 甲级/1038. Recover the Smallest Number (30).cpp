/**
* @tag     PAT_A_1038
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-14 13:47-14:36
* @version 1.0
* @Language C++
* @Ranking  1140/1211
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 10010;
string str[maxn];
bool cmp(string a, string b)
{
    return a+b < b+a;   //如果a+b生成的新字符串排在b+a生成的新字符串 字典序前面，那么a就排在b的前面
}

int main(int argc, char const *argv[])
{
    int N;
    string ans;
    cin >> N;
    for(int i = 0; i<N; i++)
    {
        cin>>str[i];
    }
    sort(str, str+N, cmp);
    for(int i = 0; i<N; i++)
    {
        ans += str[i];  //将排序后的数字进行拼接
    }
    // 消除前导0
    while( ans.size() > 1 && ans[0] == '0')
    {
        ans.erase(ans.begin());
    }
    cout << ans;
    return 0;
}
