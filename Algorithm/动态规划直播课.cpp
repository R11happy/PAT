/**
* @tag     动态规划直播课
* @authors R11happy (xushuai100@126.com)
* @date    2017-3-22 10:29
* @version 1.0
* @Language C++
* @Ranking  null
* @function null
*/

#include <iostream>
using namespace std;
const int INT_MAX = 2147483647;
int main(int argc, char const *argv[])
{
    int f[28], i;
    f[0] = 0;
    for(int i = 1; i<=27; ++i)
    {
        f[i] = INT_MAX;
        if(i-2 >= 0 && f[i-2] < INT_MAX && f[i-2]+1 < f[i])
        {
            f[i] = f[i-2]+1;
        }
        if(i-5 >= 0 && f[i-5] < INT_MAX && f[i-5]+1 < f[i])
        {
            f[i] = f[i-5]+1;
        }
        if(i-7 >= 0 && f[i-7] < INT_MAX && f[i-7]+1 < f[i])
        {
            f[i] = f[i-7]+1;
        }
    }
    cout<<f[27]<<endl;
    return 0;
}


/**
 * 最长子序列
*/
class Solution{
    void rotate(vector<int> & a)
    {
        int i, j ,t;
        i = 0;
        j = a.size()-1;
        while(i<j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
            ++t;
            --j;
        }
    }

    void compute(vector<int> &a, vector<int> &f, int &res)
    {
        int i , j;
        for(i = 0; i<a.size(); ++i)
        {
            f[i] = 1;
            if(i>0 && f[i-1]+1 > f[i] && a[i-1] < a[i])
            {
                f[i] = f[i-1]+1;
            }
            if(f[i] > res)
            {
                res = f[i];
            }
        }
    }
    int longestIncreasionContinuousSubsequence(vector<int> &a)
    {
        int n = a.size();
        int i, res = 0;
        vecotr<int> f;
        for (int i = 0; i < n; ++i)
        {
            f.push_back(0);
        }
        compute(a, f, res);
        rotate(a);
        compute(a,f,res);
        cout<<res<<endl;
    }
}


/**
 * 最长递增子序列(不要去连续)
 */

class Solution{
public:
    int longestIncreasionContinuousSubsequence(vector<int> a)
    {
        int n = a.size();
        vecotr<int> f;
        int i, j, res = 0;
        // 初始
        for (int i = 0; i < n; ++i)
        {
            f.push_back(0);
        }
        for(int j = 0; j<n; j++)
        {
            f[j] = 1;
            for(i = 0; i<j; ++i)
            {
                if(a[i] < a[j] && f[i]+1 > f[j])
                {
                    f[j] = f[i] + 1;
                }
            }
            res = max(res, f[j]);
        }
    }
    return res;
}
