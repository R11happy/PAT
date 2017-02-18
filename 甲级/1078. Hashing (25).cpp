/**
* @tag     PAT_A_1078
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-18 18:29-19:13
* @version 1.0
* @Language C++
* @Ranking  1425/918
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int prime[maxn], pNum = 0;
bool p[maxn] = {1,1};

int hashTable[maxn];

void findPrime()
{
    for(int i = 2; i<maxn; i++)
    {
        if(p[i] == false)
        {
            prime[pNum++] = i;
            for(int j=i+i; j<maxn; j+=i)
            {
                p[j] = true;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int Msize, N;
    scanf("%d%d", &Msize, &N);
    int num;
    int step;
    findPrime();
    // 找到最接近的素数
    while(p[Msize])
    {
        Msize++;
    }
    for(int i = 0; i<N; i++)
    {
        int flag = 0;
        int newPos, currentPos;
        scanf("%d", &num);
        newPos = num % Msize;
        currentPos = newPos;
        if(!hashTable[currentPos])
        {
            hashTable[currentPos] = num;
            flag = 1;
        }
        else
        {
            for(step = 1; step <Msize; step++)
            {
                newPos = (currentPos+step*step)%Msize;
                if(!hashTable[newPos])
                {
                    hashTable[newPos] = num;
                    flag = 1;
                    break;
                }
            }
        }

        if(!flag)   printf("-");
        else printf("%d", newPos);

        if(i<N-1) printf(" ");

    }
    return 0;
}
