/**
给出N个字符串(由恰好三位大写字母组成)，再给出M个查询字符串，问每个查询字符串在N个字符串中出现的次数
 */
#include <cstdio>
const int maxn = 100;
char s[maxn][5], temp[5];
int hashTable[26*26*26+10];
// hash函数，将字符串S转换为整数
int hashFunc(char S[], int len)
{
    int id = 0;
    for(int i = 0; i<len; i++)
    {
        id = id*26 + (S[i] - 'A');
    }
    return id;
}

int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i<n; i++)
    {
        scanf("%s", S[i]);
        int id = hashFunc(S[i], 3); //字符串S[i]转换为整数
        hashTable[id]++;
    }
    for(int i = 0; i<m; i++)
    {
        scanf("%s", temp);
        int id = hashFunc(temp, 3);
        printf("%d\n", hashTable[id] ); //输出该字符串的输出次数
    }
    return 0;
}
