/**
* @tag     PAT_B_1030
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-5 16:44-17:44
* @version 1.0
* @Language C++
* @Ranking  715/651
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int Max = 1e5;

int upper(int num[], int left, int right, long long x)
{
    int mid;
    while(left < right)
    {
        mid = left + (right - left)/2;
        if(num[mid] > x)
        {
            right = mid;
        }
        else
        {
            left = mid + 1; //不能是left = mid, 不然有可能死循环
        }
    }
    return left-1;  //返回第一个满足M>x的数(left是最后一个满足M<=x的数)
}

int main(int argc, char const *argv[])
{
    int num[Max+10];
    int N;
    long long x, p;
    int res, Max = 0;
    scanf("%d %d",&N, &p );
    for(int i = 0; i<N; i++)
    {
        scanf("%d", &num[i]);
    }
    sort(num, num+N);   //组成递增序列
    for(int i = 0; i < N; i++)
    {
        x = num[i] * p; //这里，x可能达到18位数,但要保证x存储正确的long long 类型，p也必须是long long 类型
        res = upper(num, i, N, x) - i + 1;
        if(res > Max)   Max = res;
    }
    printf("%d\n",Max );
    return 0;
}
