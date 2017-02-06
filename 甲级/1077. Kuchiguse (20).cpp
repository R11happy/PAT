/**
* @tag     PAT_A_1077
* @authors R11happy (xushuai100@126.com)
* @date    2016-8-30 23:56-00:30
* @version 1.0
* @Language C++
* @Ranking  380/2402
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

char str[110][260];

//反转字符串
void reverse(char s[])
{
    int len = strlen(s);
    for (int i = 0; i<len / 2; i++)
    {
        int tmp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = tmp;
    }
}

int main(int argc, char const *argv[])
{
    int N,j;
    char ans[260];
    scanf("%d", &N);
    getchar();
    gets(ans);
    reverse(ans);
    for (int i = 1; i<N; i++)
    {
        char tmp[260];
        gets(str[i]);
        reverse(str[i]);
        int len_ans = strlen(ans);
        int len_str = strlen(str[i]);
        int len = len_ans > len_str ? len_str : len_ans;
        for (j = 0; j<len; j++)
        {
            if (ans[j] == str[i][j])    tmp[j] = ans[j];
            else break;
        }
        tmp[j] = '\0';  //注意，不是tmp[++j]
        strcpy(ans, tmp);
    }
    reverse(ans);
    if (strlen(ans)) puts(ans);
    else    printf("nai\n");
    return 0;
}
