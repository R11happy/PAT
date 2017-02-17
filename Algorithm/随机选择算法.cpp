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


int randPartition(int A[], int left, int right)
{
    // 随机取一个落在left和right之间的整数
    int p = (round(1.0*rand()/RAND_MAX*(right - left))+left);
    swap(A[p], A[left]);
    int tmp = A[left];
    while(left < right)
    {
        while(left < right && A[right] > tmp) right--;
        A[left] = A[right];
        while(left < right && A[left] < tmp)    left++;
        A[right] = A[left];
    }
    A[left] = tmp;
    return left;
}
