/**
* @tag     PAT_A_1001
* @authors R11happy (xushuai100@126.com)
* @date    2016-07-20 15:28:15-59:04
* @version 1.0
* @Language C++
* @Ranking  80/4926
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;    //用到stack<char> st

typedef long long LL;
LL a, b, res;

int main()
{
    while (scanf("%lld%lld", &a, &b) != EOF)    //未指定结束次数
    {
        bool flag = true;
        int cnt1 = 0, cnt2 = 0;
        stack<char> st;
        res = a + b;
        if (res == 0)
        {
            printf("%d", res);
            continue;
        }
        else if (res < 0)   //负数当正数处理并标记
        {
            res = -res;
            flag = false;
        }
        while (res != 0)
        {
            st.push(res % 10 + '0');    //转化为字符入栈
            res /= 10;
            cnt1++;
            cnt2++;
            if (cnt1 % 3 == 0 && res != 0)
            {
                st.push(',');   //逗号一并入栈
                cnt2++;
            }
        }
        if (flag == false)
            printf("-");    //标记为负数
        for (int i = 0; i<cnt2; i++)
        {
            printf("%c", st.top()); //打栈顶元素
            st.pop();   //弹出栈顶元素
        }
        printf("\n");

    }
    return 0;
}
