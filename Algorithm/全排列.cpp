/**
* @tag     Algorithm
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-4
* @version 1.0
* @Language C++
* @Ranking  null
* @function Full Permutation(求全排列)
* eg. (1,2,3) (1,3,2) (2,1,3) (2,3,1) (3,1,2) (3,2,1)
*/

#include <cstdio>
const int maxn = 11;
// P为当前排列，hashTable记录整数是否已经在P中
int n, P[maxn], hashTable[maxn] = {false};
//当前处理排列的第index号位
void generateP(int index)
{
    if(index == n+1)    //递归边界，已经处理完排列的1~n位
    {
        printf("( ");
        for(int i = 1; i <= n-1; i++ )
        {
            printf("%d, ", P[i]);
        }
        printf("%d )\n", P[n]);
        return;
    }
    for(int x = 1; x<=n; x++)   //枚举1~n，试图将x填入P[index]
    {
        if(hashTable[x] == false)   //如果x不在P[0]~P[index-1]中
        {
            P[index] = x;   //把x加入当前排列
            hashTable[x] = true;    //记录x已经在P中
            generateP(index+1);     //处理完排列的第index+1号位
            hashTable[x] = false;   //已经处理完P[index]为x的子问题，还原状态，进行 x++后的下一次判断
        }
    }
}

int main(int argc, char const *argv[])
{
    n = 3;
    generateP(1);   //从P[1]开始填
    return 0;
}
