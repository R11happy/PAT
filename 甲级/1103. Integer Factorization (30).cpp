/**
* @tag     PAT_A_1103
* @authors R11happy (xushuai100@126.com)
* @date    2017-3-1 10:40-
* @version 1.0
* @Language C++
* @Ranking  1790/695
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, p, maxFacSum = -1; //maxFacSum记录最大底数之和
                             // ans存放最优底数序列，temp存放递归时的临时底数序列
vector<int> fac, ans, temp;
// power函数计算x^p
int power(int x)
{
    int ans = 1;
    for (int i = 0; i<p; i++)
    {
        ans *= x;
    }
    return ans;
}

// init预处理fac，把0也存进去
void init()
{
    int i = 0, temp = 0;
    while (temp <= n)
    {
        fac.push_back(temp);
        temp = power(++i);
    }
}

// DFS函数，当前访问fac[index], nowK为当前选中个数
// sum为当前选中的数之和，facSum为当前选中的底数之和
// index为fac数组的下标
void DFS(int index, int nowk, int sum, int facSum)
{
    if (sum > n || nowk > k) return;
    // 找到了满足要求的序列
    if (sum == n && nowk == k)
    {
        if (facSum > maxFacSum)
        {
            maxFacSum = facSum;
            ans = temp;
        }
        return;
    }

    if (index > 0)
    {
        temp.push_back(index);
        // 选
        DFS(index, nowk + 1, sum + fac[index], facSum + index); //因为底数是可以重复选的，所以下一个递归的底数仍然为index
        temp.pop_back();
        // 不选
        DFS(index - 1, nowk, sum, facSum);
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &n, &k, &p);
    init(); //初始化fac数组
    DFS(fac.size() - 1, 0, 0, 0);     //从fac的最后一位开始往前搜索
    if (maxFacSum == -1) printf("Impossible\n"); //没有找到满足的序列
    else
    {
        printf("%d = %d^%d", n, ans[0], p);
        for (int i = 1; i<ans.size(); i++)
        {
            printf(" + %d^%d", ans[i], p);
        }
    }
    return 0;
}

