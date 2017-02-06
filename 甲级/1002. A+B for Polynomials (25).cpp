/*
* @tag     PAT_A_1002
* @authors R11happy (xushuai100@126.com)
* @date    2016-07-20 16:08:16-16:59:04
* @version 1.0
* @Language C++
* @Ranking  105/4548
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;

double a[1005]; //a[i]用来存指数为i的系数
int main()
{
    int k;
    int expo;
    stack<int> st;
    int Max = 0;    //记录出现过的最大指数
    int cnt = 0;    //记录输出的多项式项数
    double coef;
    scanf("%d", &k);
    while (k--) //输入第一个多项式
    {
        scanf("%d", &expo);
        if (expo > Max)
            Max = expo;
        scanf("%lf", &a[expo]);
    }
    scanf("%d", &k);
    while (k--) //输入第二个多项式
    {
        scanf("%d", &expo);
        if (expo > Max)
            Max = expo;
        scanf("%lf", &coef);
        a[expo] += coef;
    }
    for (int i = 0; i <= Max; i++)
    {
        if (a[i])
        {
            st.push(i); //对所有非零项，push指数
            cnt++;
        }
    }
    printf("%d", cnt);  //最初为printf("%d ", cnt); 但当只输出0时末尾有多余空格
    for (int i = 0; i<cnt; i++)
    {
        int index = st.top();   //记录栈顶元素，即结果项的指数
        printf(" %d %.1f", index, a[index]);
        st.pop();   //堆栈的使用要记得pop栈顶
    }
    printf("\n");
    return 0;
}





