/**
* @tag     PAT_B_1057
* @authors R11happy (xushuai100@126.com)
* @date
* @version 1.0
* @Language C++
* @Ranking  1010/191
* @function null
*/



#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int hashTable[2];

int main(int argc, char const *argv[])
{
	char str[maxn];
	gets(str);
	int len = strlen(str);
	int sum = 0;
	int temp = 0;
	for(int i = 0; i<len; i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			temp = str[i] - 'A' + 1;
			sum += temp;
		}
		else if(str[i] >= 'a' && str[i] <= 'z')
		{
			temp = str[i] - 'a' + 1;
			sum += temp;
		}
		else continue;
	}
	while (sum != 0)	//不能用do--while循环，否则测试点2出错
	{
		if(sum & 1)
		{
			hashTable[1]++;
		}
		else	hashTable[0]++;
		sum >>= 1;
	}
	printf("%d %d\n",hashTable[0], hashTable[1] );
	return 0;
}
