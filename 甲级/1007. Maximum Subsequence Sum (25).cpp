/**
* @tag     PAT_A_1007
* @authors R11happy (xushuai100@126.com)
* @date    2016-10-12 10:23-11:47
* @version 1.0
* @Language C++
* @Ranking  590-1825
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

const int maxn = 10010;
int Array[maxn];

int main(int argc, char const *argv[])
{
    int K;
    int curSum=0;
    int sum = 0, maxBegin=0, maxEnd=0;
    int flag = 0;   //判断是否全为负数
    scanf("%d", &K);
    // 一次遍历
    for(int i = 0; i <K; i++)
    {
        scanf("%d", &Array[i]);
        if(Array[i] >= 0)    flag = 1;  //标记不是全负数的情况
        curSum += Array[i]; //更新当前序列和
        if(curSum < 0)
        {
            curSum = 0; //当前序列为负数，就抛弃
        }
        if(curSum > sum)
        {
           sum = curSum;
           maxEnd = i;
        }
    }
    curSum = 0;
    // 找起始位置(有点蠢)
    for(maxBegin = maxEnd; maxBegin>=0; maxBegin--)
    {
        curSum += Array[maxBegin];
        if(sum == curSum)   break;
    }
    if(flag==0)    printf("%d %d %d\n",sum, Array[0], Array[K-1] ); //全为负数，输出第一个和最后一个元素
    else if(sum == 0)   printf("0 0 0\n");  //0和负数的组合，输出全0
    else printf("%d %d %d\n",sum, Array[maxBegin], Array[maxEnd] ); //其他输出起始和终止位置

    return 0;
}


/*
输入
10
-10 1 2 3 4 -5 -23 3 7 -21
 */

/*
输出
10 1 4
 */
