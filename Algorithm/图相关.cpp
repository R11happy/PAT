/**
* @tag     图相关
* @authors R11happy (xushuai100@126.com)
* @date    2016-10-31 16:22-
* @version 1.0
* @Language C++
* @Ranking  null
* @function null
*/

/*深度优先搜索*/

/*邻接矩阵版*/
 const int MAXV = 1000; //最大定点数
 const int INF = 100000000; //设INF为一个很大的数

 int n, G[MAXV][MAXV];
 bool vis[MAXV] = {false};

 void DFS(int u, int depth)
 {
    vis[u] = true;  //设置u已被访问
    // 对所有从u出发能到达的分支顶点进行枚举
    for(int v = 0; v<n; v++)
    {
        if(vis[v] == false && G[u][v] != INF )
        {
            DFS(v, depth+1);    //访问v，深度加1
        }
    }
 }

// 遍历图
 void DFSTrave()
 {
    for(int u = 0; u<n; u++)
    {
        if(vis[u] == false)
        {
            DFS(u,1);
        }
    }
 }

/*邻接表版*/
vector<int> Adj[MAXV];
int n;
bool vis[MAXV] = {false};

void DFS(int u, int depth)
{
    vis[u] = true;
    for(int i=0; i<Adj[u].size(); i++)
    {
        int v = Adj[u][i];
        if(vis[v] == false) DFS(V, depth+1);
    }
}

void DFSTrave()
{
    for(int u = 0; u<n; u++)
    {
        if(vis[u] == false) DFS(u,1);
    }
}


/*广度优先搜索*/

// 邻接矩阵版
int n, G[MAXV][MAXV];   //n为定点数,MAXV为最大顶点数
bool inq[MAXV] = {false};

void BFS(int u)
{
    queue<int> q;
    q.push(u);  //初始点u入队
    inq[u] = true;
    // 队列非空
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v = 0; v<n; v++)
        {
            //如果u的邻接点v未曾加入过队列
            if(inq[v] == false && G[u][v] != INF)
            {
                q.push(v);  //将v入队
                inq[v] = true;  //标记v为已被加入过队列
            }
        }
    }
}

void BFSTrave()
{
    for(int u = 0; u<n; u++)
    {
        if(inq[u] == false) BFS(q);
    }
}


// 邻接表版
vector<int> Adj[MAXV];  //Adj[u]存放从顶点u出发可以到达的所有顶点
int n;
bool inq[MAXV] = {false};

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    inq[u] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i<Adj[u].size(); i++)
        {
            int v = Adj[u][i];
            if(inq[v] == false) //v未曾加入过队列
            {
                q.push(v);  //v入队
                inq[v] = true;  //标记v为已被加入过队列
            }
        }
    }
}

void BFSTrave()
{
    for(int u = 0; u<n; u++)
    {
        if(inq[u] == false) //如果u未曾加入过队列
        {
            BFS(u); //遍历u所在的连通块
        }
    }
}

// 记录顶点层号的BFS
struct Node
{
    int v;  //顶点编号
    int layer;  //顶点层号
};

vector<Node> Adj[N];

void BFS(int s)
{
    queue<Node> q;
    Node start;
    start.v = s;
    start.layer = 0;
    q.push(start);
    inq[start.v] = true;
    while(!q.empty())
    {
        Node topNode = q.front();
        q.pop();
        int u = topNode.v;
        for(int i = 0; i<Adj[u].size(); i++)
        {
            Node next = Adj[u][i];  //从u出发能到达的顶点next
            next.layer = topNode.layer+1;
            if(inq[next.v] == false)
            {
                q.push(next);
                inq[next.v] = true;
            }
        }
    }
}


/*最短路径*/
// Dijkstra算法
const int MAXV =1000;
const int INF = 0x3fffffff;

// 邻接矩阵版 n<1000
int n, G[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV] = {false};

void Dijkstra(int s)
{
    fill(d, d+MAXV, INF);  //fill函数将整个d数组赋为INF(慎用memset)
    d[s] = 0;   //起点s
    for(int i = 0; i<n; i++)
    {
        int u = -1, MIN = INF;  //u使d[u]最小，MIN存放该最小的d[u]
        for(int j = 0; j<n; j++)
        {
            if(vis[j] == false && d[j] < MIN)
            {
                u = j;
                MIN = d[j];
            }
        }
        // 找不到小于INF的d[u],说明剩下的顶点和起点s不连通
        if(u == -1) return;
        vis[u] = true;  //标记u为已访问
        for(int v = 0; v<n; v++)    //如果v未访问 && u能到达v && 以u为中介点可以使d[v]更优
        {
            if(vis[v] == false && G[u][v] != INF && d[u]+G[u][v] < d[v])
            {
                d[v] = d[u] + G[u][v];  //优化d[v]
            }
        }
    }
}

// 邻接表版
struct Node
{
    int v, dis; //v为边的目标顶点，dis为边权
};

vector<Node> Adj[MAXV]; //Adj[u]存放从顶点u除非可以到达的所有顶点
int n;
int d[MAXV];
bool vis[MAXV] = {false};

void Dijkstra(int s)
{
    fill(d, d+MAXV, INF);  //fill函数将整个d数组赋为INF(慎用memset)
    d[s] = 0;   //起点s
    for(int i = 0; i<n; i++)
    {
        int u = -1, MIN = INF;  //u使d[u]最小，MIN存放该最小的d[u]
        for(int j = 0; j<n; j++)
        {
            if(vis[j] == false && d[j] < MIN)
            {
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int j = 0; j<Adj[u].size(); j++)
        {
            int v = Adj[u][j].v;
            if(vis[V] == false && d[u]+Adj[u][j].dis < d[v])
            {
                d[v] = d[u] + Adj[u][j].dis;
            }
        }
    }
}


/*最小生成树*/
// Prim算法
int n, G[MAXV][MAXV];
int d[MAXV];    //顶点与集合S的最短距离
bool vis[MAXV] = {false};

int Prim(int s) //起点为s
{
    for (int i = 0; i<MAXV; i++)
    {
        d[i] = INF;
        pre[i] = 0;
        vis[i] = false;
    }
    d[s] = 0;   //只有s号顶点到集合S的距离为0，其余全部为INF
    int ans = 0;    //存放最小生成树的边权之和
    for(int i = 0; i<n; i++)
    {
        int u = -1, MIN = INF;  //u使得d[u]最小，MIN记录该最小的d[u]
        // 寻找未访问顶点中d[]最小的
        for(int j = 0; j<n; j++)
        {
            if(vis[j] == false && d[j] < MIN)
            {
                u = j;
                MIN = d[j];
            }
        }

        // 找不到小于INF的d[u]，则剩下的顶点和集合S不联通
        if(u == -1) return -1;
        vis[u] = true;  //标记u为已访问
        ans += d[u];    //将与集合S距离最小的边加入最小生成树
        for(int v = 0; v<n; v++)
        {
            // v未访问&&u能到达v&&以u为中介点可以使v离集合S更近
            if(vis[v] == false && G[u][v] != INF && G[u][v] < d[v])
            {
                d[v] = G[u][v];
                pre[v] = u; //记录v的前驱节点u
            }
        }

    }
    return ans; //返回最小生成树的边权之和
}
