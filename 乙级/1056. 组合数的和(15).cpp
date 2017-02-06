/**
* @tag     PAT_B_1056
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-11 13:30-13:43
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

int num[10];
int convert(int a, int b)
{
	int res = 0;
	return a*10+b;
}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d",&N);
	int sum = 0;
	int temp = 0;
	for(int i = 0; i<N; i++)
	{
		scanf("%d", &num[i]);
	}
	for(int i = 0; i<N; i++)
	{
		for(int j = 0; j<N; j++)
		{
			if(j == i)	continue;
			temp = convert(num[i], num[j]);
			sum += temp;
		}
	}
	printf("%d\n",sum );
	return 0;
}
