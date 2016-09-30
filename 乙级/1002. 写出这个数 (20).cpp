/**
 * @tag     PAT_B_1002
 * @authors R11happy (xushuai100@126.com)
 * @date    2016-07-17 15:53:16-16:45
 * @version 1.0
 * @Language C++
 * @Ranking  35/7667
 */

#include <iostream>
#include <cstring>
#include <string>
#include <stack>
using namespace std;

string Num_to_String(int n)
{
    if (n == 0)
        return "ling";
    else if (n == 1)
    {
        return "yi";
    }
    else if (n == 2)
    {
        return "er";
    }
    else if (n == 3)
    {
        return "san";/* code */
    }
    else if (n == 4)
    {
        return "si";
    }
    else if (n == 5)
    {
        return "wu";
    }
    else if (n == 6)
        return "liu";
    else if (n == 7)
        return "qi";
    else if (n == 8)
        return "ba";
    else if (n == 9)
        return "jiu";
    else
        return "ERROR";
}

int sum;
int cnt;
int main()
{
    char str[110];
    gets_s(str);
    int len = strlen(str);
    for (int k = 0; k < len; k++)
        sum += str[k] - '0';
    stack<int> st;
    int n;
    while (sum>9)
    {
        n = sum % 10;
        st.push(n);
        sum /= 10;
        cnt++;
    }
    cout << Num_to_String(sum);
    for (int i = 0; i < cnt; i++)
    {
        cout << " " + Num_to_String(st.top());
        st.pop();
    }
    return 0;
}
