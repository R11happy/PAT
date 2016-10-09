/**
* @tag     PAT_A_1027
* @authors R11happy (xushuai100@126.com)
* @date    2016-8-19 23:29-23:57
* @version 1.0
* @Language C++
* @Ranking  260/3135
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>


int main(int argc, char const *argv[])
{
    char tRGB[3][2];   //tRGB[0][2]-R  tRGB[1][2]-G    tRGB[2][2]-B
                        //不能直接放全局，因为会初始化为\0，而不是字符'0'
    for (int i = 0; i < 3; ++i)
    {
        for(int j = 0; j<2; j++)
            tRGB[i][j] = '0';
    }
    char radix13[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9','A','B','C'};
    int dRGB[3];    //dRGB[0]-R  dRGB[1]-G  dRGB[2]-B
    scanf("%d%d%d", &dRGB[0], &dRGB[1], &dRGB[2]);
    for(int i = 0; i<3; i++)
    {
        int num = 0;    //num初始化要放在do外面
        do
        {
            tRGB[i][num++] = radix13[dRGB[i] % 13]; //除基取余
            dRGB[i] /= 13;
        } while (dRGB[i] != 0);
    }
    printf("#");
    for(int i = 0; i<3; i++)
        for(int j = 1; j>=0; j--)
        {
            printf("%c",tRGB[i][j] );
        }
    return 0;
}
