/**
* @tag     PAT_A_1107
* @authors R11happy (xushuai100@126.com)
* @date     2017-3-4 0:08-0:59
* @version 1.0
* @Language C++
* @Ranking  2110/485
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int father[maxn];
int isRoot[maxn] = {0};
int course[maxn] = {0};
bool cmp(int a, int b)
{
    return a>b;
}
void init(int n)
{
    for(int i = 1; i<=n; i++)
    {
        father[i] = i;
        isRoot[i] = 0;
    }
}
int findFather(int x)
{
    if(father[x] == x)  return x;
    else
    {
        int F = findFather(father[x]);
        father[x] = F;
        return F;
    }
}
void Union(int a, int b)
{
    int faA = findFather(a);
    int fbB = findFather(b);
    if(faA != fbB)
    {
        father[faA] = fbB;
    }
}
int main(int argc, char const *argv[])
{
    int n, k, h;
    scanf("%d", &n);
    init(n);
    for(int i = 1; i<=n; i++)
    {
        scanf("%d:", &k);
        for(int j = 0; j<k; j++)
        {
            scanf("%d", &h);
            if(course[h] == 0)  course[h] = i;
            Union(i, findFather(course[h]));
        }
    }
    for(int i = 1; i<=n; i++)
    {
        isRoot[findFather(i)]++;
    }
    int ans = 0;
    for(int i = 1; i<=n; i++)
    {
        if(isRoot[i] != 0)  ans++;
    }
    printf("%d\n",ans );
    sort(isRoot+1, isRoot+n+1, cmp);
    printf("%d",isRoot[1] );
    for(int i = 2; i<=ans; i++)
    {
        printf(" %d",isRoot[i] );
    }
    printf("\n");
    return 0;
}
