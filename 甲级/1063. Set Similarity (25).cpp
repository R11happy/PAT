/**
* @tag     PAT_A_1063
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-23 15:24-16:03
* @version 1.0
* @Language C++
* @Ranking  1565/824
* @function null
*/

#include <cstdio>
#include <set>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 55;
set<int> st[maxn];

// 不用开两个set，直接根据index，计算sameNum和totalNum即可
void compare(int a, int b)
{
    int sameNum = 0, totalNum = st[b].size();
    for (set<int>::iterator it = st[a].begin(); it != st[a].end(); it++)
    {
        // 如果当前a的元素也在b中
        if (st[b].find(*it) != st[b].end())  sameNum++;
        // 如果当前a的元素不在b中
        else totalNum++;
    }
    // 要打印出% 需要连续打2个%
    printf("%.1f%%\n", sameNum * 100.0/ totalNum );
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int m, tmp;
        scanf("%d", &m);
        for (int j = 0; j<m; j++)
        {
            scanf("%d", &tmp);
            st[i].insert(tmp);
        }
    }
    int query;
    scanf("%d", &query);
    for (int i = 0; i<query; i++)
    {
        int st1, st2;
        scanf("%d%d", &st1, &st2);
        compare(st1, st2);
    }
    return 0;
}
