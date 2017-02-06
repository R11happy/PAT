////////////
// 随机选择算法 //
// ////////////

// 随机选择算法，从A[left, right]中返回第K大的数
int randSelect(int A[], int left, int right, int K)
{
    if(left == right)   return A[left]; //边界
    int p = randPartition(A,left, right);   //划分后主元的位置P
    int M = p - left + 1;   //A[p]是A[left,right]中的第M大
    if(K == M)  return A[p];    //找到第K大的数
    if(K < M)   //第K大的数在主元左侧
    {
        return randSelect(A, left, p-1, K);
    }
    else    //第K大的数在主元右侧
    {
        return randSelect(A, p+1, right, K-M);
    }
}
