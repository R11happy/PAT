/**
* @tag     PAT_B_1019
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-7 21:21-21:57
* @version 1.0
* @Language C++
* @Ranking  810/474
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int A[5];

bool cmp(int a, int b)
{
    return a > b;
}

int toNum(int A[])
{
    int num = 0;
    for (int i = 0; i<4; i++)
    {
        num *= 10;
        num += A[i];
    }
    return num;
}

void toArray(int A[], int N)
{
    for (int i = 0; i<4; i++)
    {
        A[i] = N % 10;
        N /= 10;
    }
}

int main(int argc, char const *argv[])
{
    int N;
    int minu = 1, sub = 0;
    scanf("%d", &N);
    do  //这里不能用while循环，因为当输入6174的时候，也要输出7641 -1467 = 6174
    {
        toArray(A, N);
        sort(A, A + 4);   //升序排列
        sub = toNum(A);
        sort(A, A + 4, cmp);    //降序排列
        minu = toNum(A);
        N = minu - sub;
        printf("%04d - %04d = %04d\n", minu, sub, N);
    }while (minu != sub && N != 6174);
    return 0;
}
