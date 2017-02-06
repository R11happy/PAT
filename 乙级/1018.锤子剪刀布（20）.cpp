/**
* @tag     PAT_B_1018
* @authors R11happy (xushuai100@126.com)
* @date    2016-07-19 14:34:16-15:23
* @version 1.0
* @Language C++
* @Ranking  155/3936
*/

#include <cstdio>
#include <cstring>
#include <cmath>

/*将char转化为int变与比较*/
int Char_to_Num(char ch)
{
    if(ch == 'B')
        return 0;
    if(ch == 'C')
        return 1;
    if(ch == 'J')
        return 2;
}

/*将int转化为char用来输出*/
char Num_to_Char(int k)
{
    if(k == 0)
        return 'B';
    if(k == 1)
        return 'C';
    if(k == 2)
        return 'J';
}

int main()
{
    int N;
    char cA, cB;    //存放当前手势和次数最多手势
    int nA, nB;     //存放变为数字后的手势
    int maxA, maxB; //统计获胜次数最多的手势
    int cntA[3]={0}, cntB[3]={0};   //用于统计胜平负次数
    int timeA[3]= {0},timeB[3] = {0};   //用于统计每种手势获胜次数
    scanf("%d", &N);
    while(N--)
    {
        getchar();
        scanf("%c %c", &cA, &cB);
        nA = Char_to_Num(cA);
        nB = Char_to_Num(cB);
        if((nA+1)%3 == nB)  //甲胜
        {
            cntA[0]++;  //甲胜次数加一
            cntB[2]++;  //乙负次数加一
            timeA[nA]++;    //nA对应手势获胜加一
        }
        else if(nA == nB)   //甲乙平
        {
            cntA[1]++;  //甲平次数加一
            cntB[1]++;  //乙平次数加一
        }
        else    //乙胜
        {
            cntA[2]++;  //甲负次数加一
            cntB[0]++;  //乙胜次数加一
            timeB[nB]++;    //nB对应手势获胜加一
        }
    }
    maxA = timeA[0];
    cA = 'B';
    maxB = timeB[0];
    cB = 'B';
    for(int i = 0; i<3; i++)
    {
        if(maxA < timeA[i])
        {
            maxA = timeA[i];
            cA = Num_to_Char(i);
        }
        printf("%d",cntA[i]);
        if(i < 2)
            printf(" ");
        else
            printf("\n");
    }
    for(int i = 0; i<3; i++)
    {
        if(maxB < timeB[i])
        {
            maxB = timeB[i];
            cB = Num_to_Char(i);
        }
        printf("%d",cntB[i]);
        if(i < 2)
            printf(" ");
        else
            printf("\n");
    }
    printf("%c %c\n",cA,cB);
    return 0;
}
