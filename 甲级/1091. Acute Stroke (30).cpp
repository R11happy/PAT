/**
* @tag     PAT_A_1091
* @authors R11happy (xushuai100@126.com)
* @date     2017-3-1 15:55-20:09
* @version 1.0
* @Language C++
* @Ranking  1820/675
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;

struct Node
{
    int x, y, z;
}node;

int n, m, slice, t; //n*m矩阵，共有slice层，t为卒中核心区中1的个数的下限
int pixel[1290][130][61];
bool inq[1290][130][61] = {false}; //记录坐标(x,y,z)是否已经入过队
// 增量数组
int X[6] = {0, 0, 0, 0, 1, -1};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};

bool judge(int x, int y ,int z)
{
    // 判别区域上限和下限都需要考虑
    if(x >= m || y >= n || z >= slice || x<0 || y<0 || z<0)  return false;
    if(pixel[x][y][z] == 0 || inq[x][y][z] == true)    return false;
    return true;
}

int BFS(int x, int y, int z)
{
    int sum = 0;    //记录该区域1的个数
    queue<Node> Q;
    node.x = x, node.y = y, node.z = z;
    Q.push(node);
    inq[x][y][z] = true;
    while(!Q.empty())
    {
        Node top = Q.front();
        Q.pop();
        sum++;
        for(int i = 0; i<6; i++)
        {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            int newZ = top.z + Z[i];
            if(judge(newX, newY, newZ))
            {
                node.x = newX;
                node.y = newY;
                node.z = newZ;
                Q.push(node);
                inq[newX][newY][newZ] = true;
            }
        }
    }
    if(sum >= t)    return sum;
    else return 0;
}

int main(int argc, char const *argv[])
{
    scanf("%d%d%d%d", &m, &n, &slice, &t);
    for(int z = 0; z<slice; z++)
    {
        for(int x = 0; x<m; x++)
        {
            for(int y = 0; y<n; y++)
            {
                scanf("%d", &pixel[x][y][z]);
            }
        }
    }
    int ans = 0;
    for(int z = 0; z<slice; z++)
    {
        for(int x = 0; x<m; x++)
        {
            for(int y = 0; y<n; y++)
            {
                // 如果当前位置为1，且未被访问，则BFS当前块
                if(pixel[x][y][z] == 1 && inq[x][y][z] == false)
                {
                    ans += BFS(x, y, z);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
