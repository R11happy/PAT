/**
* 计数排序（针对整数排序）
* 1.初始化一个计数数组，大小输入数组中的最大的数
* 2.遍历输入数组，遇到一个数就在计数数组对应的位置上加一。
* 例如：遇到5，就将计数数组第五个位置的数加一
* 3.把计数数组直接覆盖到输出数组（节约空间）
*/

/*
举例：
1.遍历输入数组
{3,4,3,2,1} -> {0,0,1,0}
{3,4,3,2,1} -> {0,0,1,1}
{3,4,3,2,1} -> {0,0,2,1}
{3,4,3,2,1} -> {0,1,2,1}
{3,4,3,2,1} -> {1,1,2,1}

2.写回输入数组准备输出
{0,1,2,1} -> {1,4,3,2,1}
{0,0,2,1} -> {1,2,3,2,1}
{0,0,1,1} -> {1,2,3,2,1}
{0,0,0,1} -> {1,2,3,3,1}
{0,0,0,0} -> {1,2,3,3,4}

时间复杂度：O(n+k) n是输入数组长度，k是最大的数的大小
空间复杂度：O(n+k) n是输入数组长度，k是最大的数的大小
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

void pringArray(int *array, int size)
{
    int curr;
    for (curr = 0; curr < size; curr++)
    {
        printf("%d, ", array[curr]);
    }
    printf("\n");
}

int maximum(int *array, int size)
{
    int curr = 0;
    int max = 0;
    for (curr = 0; curr < size; curr++)
    {
        if (max < array[curr])   max = array[curr];
    }
    return max;
}

void coutingSort(int *array, int size)
{
    int curr = 0;
    int max = maximum(array, size)+1;   //下标从0开始，加1防止越界
    int *counting_array = (int*)calloc(max, sizeof(int)); //Zeros out the array

    for (curr = 0; curr < size; curr++)
    {
        counting_array[array[curr]]++;
    }

    int num = 0;
    curr = 0;
    while (curr <= size)
    {
        while (counting_array[num] > 0)
        {
            array[curr] = num;
            counting_array[num]--;
            curr++;
            if (curr > size) break;
        }
        num++;
    }
    pringArray(array, size);
}

int main(int argc, char const *argv[])
{
    int test1[] = { 2,6,4,3,2,3,4,6,3,4,3,5,2,6 };
    int size1 = 14;

    coutingSort(test1, size1);

    int test2[] = { 5,6,7,8,5 };
    int size2 = 5;

    coutingSort(test2, size2);

    int test3[] = { 8,1,2,3,3,4 };
    int size3 = 6;

    coutingSort(test3, size3);
    return 0;
}
