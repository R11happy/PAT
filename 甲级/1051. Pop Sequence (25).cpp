/**
* @tag     PAT_A_1051
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-26 21:38-
* @version 1.0
* @Language C++
* @Ranking  null
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <stack>
#include <algorithm>
using namespace std;

const int maxn = 10010;
stack<int> st;
int query[maxn];

int main(int argc, char const *argv[])
{
    int m, n, k;
    scanf("%d%d%d", &m, &n, &k);
    while(k--)
    {
        while(!st.empty())
        {
            st.pop();
        }
        for(int i = 0; i<n; i++)
        {
            scanf("%d", &query[i]);
        }
        int current = 1;
        bool flag = true;
        for(int i = 1; i<=n; i++)
        {
            st.push(i);
            if(st.size() > m)
            {
                flag = false;
                break;
            }
            while(!st.empty() && st.top == query[current])
            {
                st.pop();
                current++;
            }
        }
        if(st.empty()==true && flag ==true)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
