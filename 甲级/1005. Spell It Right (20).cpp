/**
* @tag     PAT_A_1005
* @authors R11happy (xushuai100@126.com)
* @date    2016-8-28 00:08-00:24
* @version 1.0
* @Language C++
* @Ranking  340/2590
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
using namespace std;

char convert[10][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(int argc, char const *argv[])
{
    stack<int> st;
    char str[110];
    gets(str);
    int len = strlen(str);
    int sum = 0;
    int cnt = 0;    //记录入栈个数
    // 统计字串各位数数字和
    for(int i = 0; i < len; i++)
    {
        sum += str[i] - '0';
    }
    // 每一位入栈再pop出来
    do
    {
        st.push(sum % 10);
        cnt++;
        sum /= 10;
    } while (sum != 0);
    for(int i = 0; i<cnt-1; i++)
    {
        printf("%s ",convert[st.top()] );
        st.pop();
    }
    printf("%s",convert[st.top()] );
    st.pop();
    return 0;
}
