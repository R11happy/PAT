/**
* @tag     PAT_A_1106
* @authors R11happy (xushuai100@126.com)
* @date    2017-3-2 06:37-06:50
* @version 1.0
* @Language C++
* @Ranking  1920/605
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

vector<int> child[maxn];
int miniDepth = 1 << 31 - 1;
int num = 0;

void DFS(int index, int depth)
{
    if (child[index].size() == 0)
    {
        if (depth < miniDepth)
        {
            miniDepth = depth;
            num = 1;
        }
        else if (depth == miniDepth) num++;
        return;
    }
    for (int i = 0; i<child[index].size(); i++)
    {
        DFS(child[index][i], depth + 1);
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    for (int i = 0; i<n; i++)
    {
        int k, kid;
        scanf("%d", &k);
        if (k > 0)
        {
            for (int j = 0; j<k; j++)
            {
                scanf("%d", &kid);
                child[i].push_back(kid);
            }
        }
    }
    DFS(0,0);
    printf("%.4f %d\n", p*pow(1 + r, miniDepth), num);
    return 0;
}
