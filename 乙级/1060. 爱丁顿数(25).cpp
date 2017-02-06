/**
* @tag     PAT_B_1060
* @authors R11happy (xushuai100@126.com)
* @date		2016-9-11 15:54-16:22
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

const int maxn = 100010;
int hashTable[maxn];

bool cmp(int a, int b)
{
	return a > b;
}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int tmp;
	int res = 0;
	int a[maxn];
	int k;
	for(int i = 0; i<N; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a+N, cmp);
	for( k = 0; k<N; k++)
	{
		if(a[k] <= k+1)	break;
	}
	printf("%d\n",k );
	return 0;
}
