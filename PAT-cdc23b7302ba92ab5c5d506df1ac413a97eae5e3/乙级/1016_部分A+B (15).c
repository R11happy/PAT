/*1016. 部分A+B (15)
正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。
例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。

现给定A、DA、B、DB，请编写程序计算PA + PB。

输入格式：

输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。

输出格式：

在一行中输出PA + PB的值。
*/
#include <stdio.h>
#include <stdlib.h>
int GetCounts(int A, int D);
int main()
{
	int i;
	int A,dA,B,dB;
	int cA, cB;
	scanf("%d %d %d %d",&A,&dA,&B,&dB);
	int pa = 0, pb = 0;
	cA = GetCounts(A, dA);
	cB = GetCounts(B, dB);
	for(i = 0; i<cA; i++)
		pa = pa*10 + dA;
	for(i = 0; i<cB; i++)
		pb = pb*10 + dB;
	printf("%d\n",pa+pb );
	return 0;
}

int GetCounts(int A, int D)
{
	int dit;
	int i=0;
	int cnt = 0;
	while(A>0)
	{
		if((A % 10) == D)
			cnt++;
		A /= 10;
	}
	return cnt;
}//1968_264

/*

输入格式：

输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。

输出格式：

在一行中输出PA + PB的值。
输入样例1：

3862767 6 13530293 3

输出样例1：

399

输入样例2：

3862767 1 13530293 8

输出样例2：

0
*/
