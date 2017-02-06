/**
* @tag     PAT_A_1065
* @authors R11happy (xushuai100@126.com)
* @date    2016-07-20 22:11:16-23:04
* @version 1.0
* @Language C++
* @Ranking  60/5474
*/

#include <cstdio>
#include <cstring>
#include <cmath>

typedef long long LL;

int main()
{
    int N;
    LL A, B, C;
    LL res;     //存放结果
    bool flag = false;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%lld%lld%lld", &A, &B, &C);
        res = A + B;
        if (A>0 && B>0 && res < 0)  //正溢出
        {
            flag = true;
        }
        else if (A<0 && B<0 && A + B >= 0)    //负溢出
        {
            flag = false;
        }
        else if (res > C)   //else if 不能换为if， 不然可能会覆盖之前的flag
        {
            flag = true;
        }
        else
            flag = false;

        if (flag == true)
            printf("Case #%d: true\n", i);
        else
            printf("Case #%d: false\n", i);
    }
    return 0;
}
