/**
* @tag     PAT_A_1004
* @authors R11happy (xushuai100@126.com)
* @date    2016-10-25 13:00 - 13:33
* @version 1.0
* @Language C++
* @Ranking  730/1595
* @function DFS遍历
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 110;

vector<int> G[N];   //存放树
int leaf[N] = { 0 };  //存放每层叶子结点个数
int h[N] = {0}; //记录每个结点所在的层
int max_h = 1;  //树的深度

                /*index为当前遍历到的结点编号,h为当前深度*/
void BFS()
{
    queue<int> Q;   //注意queue队列中存放的其实是原元素的一个副本，所以在将元素压入队列后修改原元素的值不会使队列中的元素发生改变
    Q.push(1);
    while(!Q.empty())
    {
        int id = Q.front();
        Q.pop();
        max_h = max(max_h, h[id]);
        if(G[id].size() == 0)   leaf[h[id]]++;  //叶子结点
        for(int i = 0; i<G[id].size(); i++)
        {
            h[G[id][i]] = h[id]+1;
            Q.push(G[id][i]);   //子结点压入队列
        }
    }
}


int main(int argc, char const *argv[])
{
    int n, m, parent, child, k;
    scanf("%d%d", &n, &m);
    for (int i = 0; i<m; i++)
    {
        scanf("%d%d", &parent, &k);
        for (int j = 0; j<k; j++)
        {
            scanf("%d", &child);
            G[parent].push_back(child);
        }
    }
    h[1] = 1;
    BFS();
    printf("%d", leaf[1]);
    // 注意是<=max_h
    for (int i = 2; i<=max_h; i++)    printf(" %d", leaf[i]);
    printf("\n");
    return 0;
}
