/**
* @tag     PAT_A_1090
* @authors R11happy (xushuai100@126.com)
* @date    2017-3-2 05:37-06:03
* @version 1.0
* @Language C++
* @Ranking 1870/636
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100010;
vector<int> child[maxn];
int n, num = 0, maxDepth = 0;
double p, r;

void DFS(int index, int depth)
{
    if(child[index].size() == 0)    //到达叶子结点
    {
        if(depth > maxDepth)
        {
            maxDepth = depth;
            num = 1;
        }
        else if(depth == maxDepth)  num++;
        return;
    }
    for(int i = 0; i<child[index].size(); i++)
    {
        DFS(child[index][i], depth+1);
    }
}

int main(int argc, char const *argv[])
{
    int father, root;
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &father);
        if(father == -1)    root = i;
        else child[father].push_back(i);
    }
    DFS(root, 0);
    printf("%.2f %d\n", p*pow(1+r, maxDepth), num );
    return 0;
}
