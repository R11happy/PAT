/*1032. 挖掘机技术哪家强(20)
为了用事实说明挖掘机技术到底哪家强，PAT组织了一场挖掘机技能大赛。现请你根据比赛结果统计出技术最强的那个学校。
输入格式：
//输入在第1行给出不超过105的正整数N，即参赛人数。随后N行，每行给出一位参赛者的信息和成绩，
//包括其所代表的学校的编号（从1开始连续编号）、及其比赛成绩（百分制），中间以空格分隔。

//输出格式：
//在一行中给出总得分最高的学校的编号、及其总分，中间以空格分隔。题目保证答案唯一，没有并列。 
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,*A;
	int N, val, num;
	int index = 1,Max = 0;
	scanf("%d",&N); 
	A = (int*)malloc((N+1) * sizeof(int));
	for(i = 0; i<N; i++)
		A[i+1] = 0;
	for(i = 0; i<N; i++)
	{
		scanf("%d %d",&num, &val);
		A[num] += val;
		if(A[num] > Max)
		{
			Max = A[num];
			index = num;
		}
	}
	printf("%d %d\n",index, Max);//wrong code: &index, &Max
	return 0;
} //2104——249

/*输入样例：

6
3 65
2 80
1 100
2 70
3 40
3 0

输出样例：

2 150
*/