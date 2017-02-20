/**
* @tag     PAT_A_1039
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-20 19:19-20:03
* @version 1.0
* @Language C++
* @Ranking  1515/848
* @function null
*/

#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 40010;    //总人数
const int M = 26 * 26 * 26 * 10 + 1;    //由姓名散列成的数字上界
vector<int> selectCourse[M];    //每个学生选择的课程编号
                                // 字符串hash,将字符串name转换成数字
int getID(char name[])
{
    int id = 0;
    for (int i = 0; i<3; i++)
    {
        id = id * 26 + (name[i] - 'A');
    }
    id = id * 10 + (name[3] - '0');
    return id;
}

int main(int argc, char const *argv[])
{
    char name[5];
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i<k; i++)
    {
        int course, x;
        scanf("%d%d", &course, &x); //输入课程编号与选课人数
        for (int j = 0; j<x; j++)
        {
            scanf("%s", name);
            int id = getID(name);   //将姓名映射为一个整数作为编号
            selectCourse[id].push_back(course); //将该课程编号加入学生选择中
        }
    }
    // n个查询
    for (int i = 0; i<n; i++)
    {
        scanf("%s", name);
        int id = getID(name);   //获得学生编号
        sort(selectCourse[id].begin(), selectCourse[id].end());    //从小到大排序
        printf("%s %d", name, selectCourse[id].size()); //姓名，选课数
        for (int j = 0; j<selectCourse[id].size(); j++)
        {
            printf(" %d", selectCourse[id][j]); //选课编号
        }
        printf("\n");
    }
    return 0;
}

