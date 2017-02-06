/**
* @tag     pat_b_1003
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-7 22:19-23:19
* @version 1.0
* @Language C++
* @Ranking  830/447
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        char str[110];
        scanf("%s", str);   //输入字符串
        int len = strlen(str);
        int num_p = 0, num_t = 0, other = 0;
        int pos_p=-1, pos_t=-1;
        for(int i = 0; i<len; i++)
        {
            if(str[i] == 'P')
            {
                num_p++;
                pos_p = i;
            }
            else if(str[i] == 'T')
            {
                num_t++;
                pos_t = i;
            }
            else if(str[i] != 'A')
            {
                other++;
            }
        }
        if((num_p != 1) || (num_t != 1) || (other!=0) ||(pos_t - pos_p <= 1))
        {
            printf("NO\n");
            continue;
        }
        else
        // 记录P左边A的个数为x，P和T中间A的个数为y,T右边A的个数为z
        {
            int x = pos_p, y = pos_t - pos_p-1, z=len - pos_t - 1;
            if(z-(y-1)*x == x)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n", );
            }
        }
    }
    return 0;
}
