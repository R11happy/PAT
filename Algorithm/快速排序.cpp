//////////
// 快速排序 //
// //////////

// 对区间[left, right]进行划分
int Partition(int A[], int left, int right)
{
    int temp = A[left];
    while(left < right) //只要left与right不相遇
    {
        while(left < right && A[right] > temp)  right--;    //反复左移right
        A[left] = A[right];
        while(left < right && A[left] < temp)   left++;     //反复右移left
        A[right] = A[left];
    }
    A[left] = temp; //把temp放到left与right相遇的地方
    return left;
}

//快速排序，left与right初值为序列首尾下标(例如1与n)
void quickSort(int A[], int left, int right)
{
    if(left < right)    //当前区间长度不超过1
    {
        // 将[left,right]按A[left]一分为二
        int pos = Partition(A, left, right);    //此时pos位置的元素已经放到了正确位置
        quickSort(A, left, pos-1);
        quickSort(A, pos+1, right);
    }
}

/*
当序列接近有序的时候，最坏复杂度仍然是O(n^2)
解决办法：取一随机位置的数并与A[left]交换
生成的[0,1]范围的浮点数，相当于[a,b]范围内的比例位置
 */

// 随机取主元，并对[left,right]进行划分
int randPartition(int A[], int left, int right)
{
    // 生成[left,right]内的随机数p
    int p = (round(1.0*rand()/RAND_MAX*(right - left) + left));
    swap(A[p], A[left]);
    int temp = A[left];
    while(left < right) //只要left与right不相遇
    {
        while(left < right && A[right] > temp)  right--;    //反复左移right
        A[left] = A[right];
        while(left < right && A[left] < temp)   left++;     //反复右移left
        A[right] = A[left];
    }
    A[left] = temp; //把temp放到left与right相遇的地方
    return left;
}
