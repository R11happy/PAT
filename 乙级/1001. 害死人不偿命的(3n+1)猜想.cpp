/**
 * @tag     PAT_B_1001
 * @authors R11happy (xushuai100@126.com)
 * @date    2016-07-17 15:30:16-15:38
 * @version 1.0
 * @Language C++
 * @Ranking 15/10062
 */
#include <iostream>
#include <string>
using namespace std;

int cnt;

int main()
{
    int n;
    cin >> n;
    while(n > 1)
    {
        if(n % 2 == 0)
        {
            n = n / 2;
            cnt++;
        }
        else
        {
            n = (3*n+1)/2;  //3n+1之后记得除以2
            cnt++;
        }
    }
    cout << cnt << endl;      //输出的是cnt不是n
    return 0;
}
