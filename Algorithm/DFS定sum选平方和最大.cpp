// 序列A中n个数选k个数使得和为x,最大平方和为maxSumSqu
int n, k, x, maxSumSqu = -1, A[maxn];
// temp存放临时方案，ans存放平方和最大的方案
vector<int> temp, ans;
// 当前处理index号整数，当前已选整数个数为nowK
void DFS(int index, int nowK, int sum, int sumSqu)
{
    if(index == n|| nowK > k|| sum > x) return;
    // 找到k个数的和为x
    if(nowK == k && sum == x)
    {
        // 如果比当前找到的更优
        if(sumSqu > maxSumSqu)
        {
            maxSumSqu = sumSqu; //更新最大平方和
            ans = temp; //更新最优方案
        }
        return;
    }
    // 选index号数
    temp.push_back(A[index]);
    DFS(index+1, nowK+1, sum+A[index], sumSqu+A[index]*A[index]);
    temp.pop_back();
    // 不选index号数
    DFS(index+1, nowK, sum, sumSqu);
}
