/**
* @tag     PAT_A_1060
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-23 19:46-20:31
* @version 1.0
* @Language C++
* @Ranking  803/1590
* @function null
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int n;  //有效位数
string deal(string s, int &e)
{
    int k = 0; //s的下标
    while(s.length() > 0 && s[0] == '0')
    {
        s.erase(s.begin());
    }
    if(s[0] == '.') //若去掉前导0后是小数点，则说明s是小于1的小数
    {
        s.erase(s.begin()); //去掉小数点
        while(s.length() > 0 && s[0] == '0')
        {
            s.erase(s.begin()); //去掉小数点后非0位前的所有0
            e--;    //每去掉一个0，指数e减1
        }
    }
    else    //若去掉前导0后不是小数点，则找到后面的小数点删除
    {
        while(k<s.length() && s[k] != '.')
        {
            k++;
            e++;
        }
        if( k < s.length() )    //while结束后k<s.length(),说明遇到了小数点
        {
            s.erase(s.begin()+k);   //把小数点删除
        }
    }

    if(s.length() == 0) //如果去除前导0后s的长度变为0，则说明这个数是0
    {
        e = 0;
    }
    int num = 0;
    k = 0;
    string res;
    while(num < n)  //只要精度还没有到n
    {
        if(k < s.length())  res += s[k++];
        else res += '0';    //否则res末尾加0
        num++;  //精度加1
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string s1, s2, s3, s4;
    cin >> n >> s1 >> s2;
    int e1=0, e2=0; //e1,e2为s1,s2的指数
    s3 = deal(s1, e1);
    s4 = deal(s2, e2);
    if(s3 == s4 && e1 == e2)
    {
        cout << "YES 0." << s3 << "*10^" << e1 << endl;
    }
    else
    {
        cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2 << endl;
    }
    return 0;
}
