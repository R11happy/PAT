/**
* @tag     PAT_B_1009
* @authors R11happy (xushuai100@126.com)
* @date    2016-8-21 20:39-21:01
* @version 1.0
* @Language C++
* @Ranking  395/1690
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    char str[82];
    gets(str);
    int len = strlen(str);
    int cnt = 0;
    stack<int> st;
    st.push(-1);
    cnt++;
    //存储空格在字符串中的位置
    for (int i = 0; i<len; i++)
    {
        if (str[i] == ' ')
        {
            st.push(i);
            cnt++;
        }
    }
    //将两个空格之间的内容输出
    for (int i = 0; i<cnt; i++)
    {
        for (int j = st.top() + 1; str[j] != ' ' && str[j] != '\0'; j++)
        {
            printf("%c", str[j]);
        }
        if (i < cnt - 1)   printf(" ");
        st.pop();
    }
    return 0;
}
