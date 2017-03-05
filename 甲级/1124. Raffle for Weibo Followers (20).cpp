/**
* @tag     PAT_A_1124
* @authors R11happy (xushuai100@126.com)
* @date
* @version 1.0
* @Language C++
* @Ranking  2215/418
* @function null
*/


#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 1010;

struct Stu
{
	string name;
}stu[maxn];
map<string, int> hashTable;
// int strHash(char str[])
// {
// 	int len = strlen(str);
// 	int ans = 0;
// 	for(int i = 0; i<len; i++)
// 	{
// 		ans += str[i]
// 	}
// }
int main(int argc, char const *argv[])
{
	int m, n, s;
	scanf("%d%d%d", &m, &n, &s);
	string str;
	for (int i = 1; i <= m; i++)
	{
		cin >> stu[i].name;
	}
	int i = s;
	int flag = 0;
	while (i <= m)
	{
		if (hashTable[stu[i].name] != 1)
		{
			cout << stu[i].name << endl;
			flag = 1;
			hashTable[stu[i].name] = 1;
			i += n;
		}
		else
		{
			i = i + 1;
		}
	}
	if(!flag)	printf("Keep going...\n");
	return 0;
}
