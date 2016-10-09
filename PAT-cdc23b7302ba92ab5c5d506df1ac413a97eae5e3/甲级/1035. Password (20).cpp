/**
* @tag     PAT_A_1035
* @authors R11happy (xushuai100@126.com)
* @date    2016-8-28 22:55-23:20
* @version 1.0
* @Language C++
* @Ranking  360/2499
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

const int Max = 1000;
struct account
{
    char id[15];
    char password[15];
}modify[Max+10],tmp;

int main(int argc, char const *argv[])
{
    int N;
    int m_cnt = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%s %s", tmp.id, tmp.password);
        int flag = 0;
        for(int j = 0; j<strlen(tmp.password); j++)
        {
            if(tmp.password[j] == '1')  {tmp.password[j] = '@';flag = 1;}
            else if(tmp.password[j] == '0') {tmp.password[j] = '%';flag = 1;}
            else if(tmp.password[j] == 'l') {tmp.password[j] = 'L';flag = 1;}
            else if(tmp.password[j] == 'O') {tmp.password[j] = 'o';flag = 1;}
        }
        if(flag)
        {
            modify[m_cnt++] = tmp;  //开始写成modify[i] = tmp; m_cnt++;  不合适
        }
    }
    if(m_cnt)
    {
        printf("%d\n",m_cnt );
        for(int i = 0; i < m_cnt; i++)  printf("%s %s\n",modify[i].id,modify[i].password );
    }
    //注意，N=1和N>2不一样
    else if(N == 1) printf("There is 1 account and no account is modified\n");
    else    printf("There are %d accounts and no account is modified\n",N );
    return 0;
}
