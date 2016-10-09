/**
 * @tag     PAT_B_1016
 * @authors R11happy (xushuai100@126.com)
 * @date    2016-07-18 18:58:16-19:15
 * @version 1.0
 * @Language C++
 * @Ranking  65/6130
 */
 #include <cstdio>
 #include <cstring>
 #include <cmath>

/*计算PA和PB*/
 long long calcul(long long A, int B)
 {
    long long sum = 0;
    while(A > 9)
    {
        if(A % 10 == B)
            sum = sum*10 + B;
        A /= 10;
    }
    if(A == B)
        sum = sum*10 + B;
    return sum;
 }

 int main()
 {
    long long A, B;
    int DA, DB;
    scanf("%lld%d%lld%d", &A, &DA, &B, &DB);
    printf("%lld\n",(calcul(A, DA)+calcul(B,DB)));
    return 0;
 }
