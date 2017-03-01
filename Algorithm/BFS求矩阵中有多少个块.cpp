/**
* @tag     BFS求矩阵中有多少个块
* @authors R11happy (xushuai100@126.com)
* @date    2017-3-1
* @version 1.0
* @Language C++
* @Ranking  null
* @function null
* 比如：
* 0111001
* 0010000
* 0000100
* 0001110
* 1110100
* 1111000
* 就有4个块
* 思路：枚举每一个位置的元素，如果为0，则跳过；如果为1，则使用BFS查询与该位置相邻的4个位置（前提是不出界)，判断它们是否为1(如果某个相邻的位置为1，则同样去查询与噶爱位置相邻的4个位置，直到整个"1"块访问完毕)。而为了防止走回头路，一般可以设置一个bool型数组inq(in queue缩写)来记录每个位置是否爱BFS中已入过队
*
*/

#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 100;
struct Node
{
    int x, y;
}node;

int n, m;
int matrix[maxn][maxn]; //01矩阵
bool inq[maxn][maxn] = {false}; //记录位置(x,y)是否已入过队
// 增量数组，竖着看为(0,1)(0,-1)(1,0)(-1,0)
int X[4] = {0,0,1,-1};
int Y[4] = {1,-1,0,0};

// 判断坐标(x,y)是否需要访问
bool judge(int x, int y)
{
    // 越界返回false
    if(x >= n || x<0 ||y>=m || y<0) return false;
    // 当前位置为0，或(x,y)已入过队，返回false
    if(matrix[x][y] == 0 || inq[x][y] == true)  return false;
    return true;
}

// BFS函数访问位置(x,y)所在的块，将该块中所有"1"的inq都设置为true
void BFS(int x, int y)
{
    queue<Node> Q;  //定义队列
    node.x = x, node.y = y; //当前结点的坐标(x,y)
    Q.push(node);   //结点node入队
    inq[x][y] = true;
    while(!Q.empty())
    {
        node top = Q.front();   //取出队首元素
        Q.pop();    //队首元素出队
        // 得到4个相邻位置
        for(int i = 0; i<4; i++)
        {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            // 如果新位置需要访问
            if(judge(newX, newY))
            {
                node.x = newX;
                node.y = newY;
                Q.push(node);
                inq[newX][newY] = true; //设置位置(newX, newY)已入过队
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for(int x = 0; x<n; x++)
    {
        for(int y = 0; y<m; y++)
        {
            scanf("%d", &matrix[x][y]); //读入01矩阵
        }
    }
    int ans = 0;    //存放块数
    // 枚举每一个位置
    for(int x = 0; x<n; x++)
    {
        for(int y = 0; y<m; y++)
        {
            if(matrix[x][y] == 1 && inq[x][y] == false)
            {
                ans++;
                BFS(x, y);  //宽搜扫描整个块，将该块所有"1"的inq都标记为true
            }
        }
    }
    return 0;
}
