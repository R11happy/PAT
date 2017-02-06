/**
 * @tag     PAT_B_1046
 * @authors R11happy (xushuai100@126.com)
 * @date    2016-07-18 19:58:16-20:09
 * @version 1.0
 * @Language C++
 * @Ranking  95/4985
 */

 #include <cstdio>
 #include <cstring>
 #include <cmath>

 int main()
 {
    int N;
    int A1, A2, B1, B2;
    int cntA = 0, cntB = 0; //记录喝酒杯数
    bool flagA = false, flagB = false;  //记录谁胜
    scanf("%d", &N);
    while(N--)
    {
        flagA = false, flagB = false;   //注意每次循环要重置flag
        scanf("%d%d%d%d", &A1,&A2,&B1,&B2);
        if(A1 + B1 == A2)
            flagA = true;
        if(A1 + B1 == B2)
            flagB = true;
        if(flagA && !flagB)
            cntB++;
        if(!flagA && flagB)
            cntA++;
    }
    printf("%d %d", cntA, cntB);
    return 0;
 }
