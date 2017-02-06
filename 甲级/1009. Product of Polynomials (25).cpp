/*
* @tag     PAT_A_1009
* @authors R11happy (xushuai100@126.com)
* @date    2016-07-20 20:08:15-21:04
* @version 1.0
* @Language C++
* @Ranking  130/4240
*/

#include <cstdio>
#include <cstdlib>  //用malloc要用<cstdlib>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;

typedef struct Poly* PtrtoPoly;
struct Poly
{
    int expo;
    double coef;
    PtrtoPoly next;
};
double res[2005]; //res[i]用来存指数为i的系数
int main()
{
    int k;
    int expo;
    double coef;
    stack<int> st;
    int Max = 0;    //记录出现过的最大指数
    int cnt = 0;    //记录输出的多项式项数
    PtrtoPoly a = (PtrtoPoly)malloc(sizeof(struct Poly));
    a->next = NULL;
    scanf("%d", &k);
    while (k--) //输入第一个多项式,用链表存储
    {
        PtrtoPoly tmpa = (PtrtoPoly)malloc(sizeof(struct Poly));
        scanf("%d", &(tmpa->expo));
        if (tmpa->expo > Max)
            Max = tmpa->expo;
        scanf("%lf", &(tmpa->coef));
        tmpa->next = a->next;
        a->next = tmpa;
    }
    scanf("%d", &k);
    while (k--) //输入第二个多项式
    {
        PtrtoPoly tmpb = (PtrtoPoly)malloc(sizeof(struct Poly));
        scanf("%d", &expo);
        int index = expo;
        scanf("%lf", &coef);
        tmpb = a->next;
        while (tmpb)
        {
            index = expo + tmpb->expo;
            if (index > Max)
                Max = index;
            res[index] += (coef * tmpb->coef);
            tmpb = tmpb->next;
        }
    }
    for (int i = 0; i <= Max; i++)
    {
        if (res[i])
        {
            st.push(i); //对所有非零项，push指数
            cnt++;
        }
    }
    printf("%d", cnt);  //最初为printf("%d ", cnt); 但当只输出0时末尾有多余空格
    for (int i = 0; i<cnt; i++)
    {
        int index = st.top();   //记录栈顶元素，即结果项的指数
        printf(" %d %.1f", index, res[index]);
        st.pop();   //堆栈的使用要记得pop栈顶
    }
    printf("\n");
    return 0;
}





