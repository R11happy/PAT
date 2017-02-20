/**
* @tag     PAT_A_1047
* @authors R11happy (xushuai100@126.com)
* @date     2017-2-20 20:07-20:28
* @version 1.0
* @Language C++
* @Ranking  1540/821
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;


const int maxn = 40010;    //学生姓名上界
const int maxc = 2510;  //最大课程门数

char name[maxn][5];
vector<int> course[maxc];

// 保证姓名字母表升序排列
bool cmp(int a, int b)
{
    return strcmp(name[a], name[b]) < 0;
}

int main(int argc, char const *argv[])
{
    int n, k;
    int cntC = 0;
    int numC = 0;
    scanf("%d%d", &n, &k);
    for(int i = 0; i<n; i++)
    {
        scanf("%s %d", name[i], &cntC);
        for(int j = 0; j<cntC; j++)
        {
            scanf("%d", &numC);
            course[numC].push_back(i);
        }
    }
    for(int i = 1; i<=k; i++)
    {
        printf("%d %d\n",i, course[i].size() );
        sort(course[i].begin(), course[i].end(), cmp);
        for(int j = 0; j<course[i].size(); j++)
        {
            printf("%s\n", name[course[i][j]]);
        }
    }
    return 0;
}
