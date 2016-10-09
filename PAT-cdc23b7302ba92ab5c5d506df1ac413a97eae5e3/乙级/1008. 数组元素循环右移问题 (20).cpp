/**
 * @tag     PAT_B_1008
 * @authors R11happy (xushuai100@126.com)
 * @date    2016-07-18 20:16:16-20:27
 * @version 1.0
 * @Language C++
 * @Ranking  115/4588
 */

 #include <cstdio>
 #include <cstring>
 #include <cmath>

 int a[105];

 int main()
 {
    int N, M;
    scanf("%d%d",&N, &M);
    for(int i = 0; i < N; i++)
    {
        int j = i;
        j = (i + M)%N;  //计算新的位置
        scanf("%d", &a[j]);
    }
    for(int i = 0; i < N; i++)
    {
        printf("%d", a[i]);
        if(i < N-1)
            printf(" ");  //保证结尾没有多余的空格
    }
    return 0;
 }
