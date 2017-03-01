/**
* @tag     PAT_A_1079
* @authors R11happy (xushuai100@126.com)
* @date    2017-3-2 06:10-06:32
* @version 1.0
* @Language C++
* @Ranking  1895/623
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100010;

int n;
double p, r;

struct Node
{
    int data;   //结点的货物量
    vector<int> child;
}node[maxn];

double ans = 0;

void DFS(int index, int depth)
{
    if (node[index].child.size() == 0)
    {
        ans += node[index].data*pow(1 + r, depth);
        return;
    }
    for (int i = 0; i<node[index].child.size(); i++)
    {
        DFS(node[index].child[i], depth + 1);
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    for (int i = 0; i<n; i++)
    {
        int k, child;
        scanf("%d", &k);
        if (k > 0)
        {
            for (int j = 0; j<k; j++)
            {
                scanf("%d", &child);
                node[i].child.push_back(child);
            }
        }
        else
        {
            int data;
            scanf("%d", &data);
            node[i].data = data;
        }
    }
    DFS(0, 0);
    printf("%.1f\n", ans*p);
    return 0;
}
