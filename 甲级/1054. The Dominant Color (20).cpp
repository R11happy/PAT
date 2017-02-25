/**
* @tag     PAT_A_1054
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-25 15:47-16:29
* @version 1.0
* @Language C++
* @Ranking  1630/778
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

map<int, int> domaint;

int main(int argc, char const *argv[])
{
    int m, n;
    scanf("%d%d", &m, &n);
    int col;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            scanf("%d", &col);
            if(domaint.find(col) != domaint.end())
            {
                domaint[col]++;
            }
            else domaint[col] = 1;
        }
    }
    int index = 0, Max = 0;
    for(map<int,int>::iterator it = domaint.begin(); it != domaint.end(); it++ )
    {
        if(it->second > Max)
        {
            index = it->first;
            Max = it->second;
        }
    }
    printf("%d\n", index);
    return 0;
}
