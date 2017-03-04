/**
* @tag     PAT_A_1076
* @authors R11happy (xushuai100@126.com)
* @date    2017-3-4 09:53-10:13
* @version 1.0
* @Language C++
* @Ranking  2165/454
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 1010;

struct Node
{
    int id;
    int layer;
};



vector<Node> Adj[maxn];
bool inq[maxn] = { false };
int n, l;

int BFS(int s, int l)
{
    queue<Node> q;
    int ans = 0;
    Node start;
    start.id = s;
    start.layer = 0;
    q.push(start);
    inq[start.id] = true;
    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        int u = now.id;
        for (int i = 0; i<Adj[u].size(); i++)
        {
            Node next;
            next.id = Adj[u][i].id;
            next.layer = now.layer + 1;
            if (inq[next.id] == false && next.layer <= l)
            {
                q.push(next);
                inq[next.id] = true;
                ans++;
            }
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &l);
    for (int i = 1; i <= n; i++)
    {
        Node user;
        user.id = i;
        int num;
        scanf("%d", &num);
        for (int j = 0; j<num; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            Adj[tmp].push_back(user);
        }
    }
    int queryNum;
    scanf("%d", &queryNum);
    for (int i = 0; i<queryNum; i++)
    {
        memset(inq, false, sizeof(inq));
        int query, ans;
        scanf("%d", &query);
        ans = BFS(query, l);
        printf("%d\n", ans);
    }
    return 0;
}
