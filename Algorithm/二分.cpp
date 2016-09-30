#include <cstdio>
//A[]为严格递增序列，left为二分下界，right为二分上界，x为欲查询的数
//二分区间为左闭右闭的[left,right]，传入的初值为[0,n-1]
int binarySearch(int A[], int left, int right, int x)
{
    int mid;    //mid为left和right中点
    while(left <= right)
    {
        mid = left +(right - left)/2;
        if(A[mid] == x) return mid;
        else if(A[mid] > x)
        {
            right = mid - 1;    //在[left, mid-1]找
        }
        else
        {
            left = mid + 1;     //在[mid+1, right]
        }
    }
    return -1；  //查找失败
}

//A[]为递增序列，x为欲查询的数，函数返回第一个大于等于x的元素的位置
//二分上下界为左闭右闭的[left, right]，传入的初值为[0,n]
int lower_bound(int A[], int left, int right, int x)
{
    int mid;
    while(left < right) //left == right的时候跳出，说明找到了唯一位置
    {
        mid = left + (right - left)/2;
        if(A[mid] >= x) //中间的数大于等于x
        {
            right = mid;    //[left,mid]
        }
        else
        {
            left = mid + 1; //[mid+1, right]
        }
    }
    return left;
}

//A[]为递增序列，x为欲查询的数，函数返回第一个大于x的元素的位置
//二分上下界为左闭右闭的[left, right]，传入的初值为[0,n]
int upper_bound(int A[], int left, int right, int x)
{
    int mid;
    while(left < right) //left == right的时候跳出，说明找到了唯一位置
    {
        mid = left + (right - left)/2;
        if(A[mid] > x)  //中间的数大于x
        {
            right = mid;    //[left,mid]
        }
        else
        {
            left = mid + 1; //[mid+1, right]
        }
    }
    return left;
}
