/**
* @tag     PAT_B_1059
* @authors R11happy (xushuai100@126.com)
* @date		2016-9-11 15:23-15:53
* @version 1.0
* @Language C++
* @Ranking  null
* @function null
*/


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 10010;
int prime[maxn], pNum;
bool p[maxn] = { 0 };

void Find_Prime()
{
	p[0] = true;
	p[1] = true;
	for (int i = 2; i<maxn; i++)
	{
		if (p[i] == false)
		{
			prime[pNum++] = i;
			for (int j = i + i; j <maxn; j += i)
			{
				p[j] = true;
			}
		}
	}
}

struct Person
{
	int rank = -1;
	int flag = 0;
}tmp, player[maxn];

int main(int argc, char const *argv[])
{
	int K, N;
	scanf("%d", &N);
	Find_Prime();
	int ID;
	for (int i = 0; i<N; i++)
	{
		scanf("%d", &ID);
		player[ID].rank = i+1;
	}
	scanf("%d", &K);
	while (K--)
	{
		scanf("%d", &ID);
		printf("%04d: ", ID);
		if(player[ID].flag == 1)	printf("Checked\n");
		else if (player[ID].rank == 1)
		{
			player[ID].flag = 1;
			printf("Mystery Award\n");
		}
		else if (player[ID].rank == -1)
			printf("Are you kidding?\n");
		else if (p[player[ID].rank] == false)
		{
			player[ID].flag = 1;
			printf("Minion\n");
		}
		else
		{
			player[ID].flag = 1;
			printf("Chocolate\n");
		}
	}
	return 0;
}
