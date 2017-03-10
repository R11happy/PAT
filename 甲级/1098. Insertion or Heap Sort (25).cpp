/**
* @tag     PAT_A_1098
* @authors R11happy (xushuai100@126.com)
* @date    2017-3-10 17:34-
* @version 1.0
* @Language C++
* @Ranking  null
* @function 最后一个测试点始终过不去
*/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int insertFlag = 0;
vector<int> origin, res, insertion, heap;

bool isSame(vector<int>::iterator a, vector<int>::iterator b)
{
    for (int i = 0; i<n; i++)
    {
        if (a[i] != b[i])    return false;
    }
    return true;
}

void insertSort()
{
    for (int i = 2; i<n; i++)
    {
        if (insertion == res)
        {
            insertFlag = 1;
            sort(insertion.begin(), insertion.begin() + i);
            if(i>2) break;  //初始序列不参与比较
        }
        else
        {
            sort(insertion.begin(), insertion.begin() + i);
        }
    }
}

void percolateDown(int low, int high)
{
    int i = low, j = i * 2;
    while (j <= high)
    {
        if (j + 1 <= high && heap[j] <heap[j + 1]) j = j + 1;
        if (heap[i] < heap[j])
        {
            swap(heap[i], heap[j]);
            i = j;
            j = i * 2;
        }
        else
        {
            break;
        }
    }
}

void createHeap()
{
    for (int i = n / 2; i >= 1; i--)
    {
        percolateDown(i, n);
    }
}

void heapSort()
{
    createHeap();
    for (int i = n; i>1; i--)
    {
        if (isSame(res.begin(), heap.begin() + 1))
        {
            swap(heap[1], heap[i]);
            percolateDown(1, i - 1);
            break;  //初始序列不参与比较
        }
        else
        {
            swap(heap[1], heap[i]);
            percolateDown(1, i - 1);
        }
    }
}

int main(int argc, char const *argv[])
{
    int input;
    scanf("%d", &n);
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &input);
        origin.push_back(input);
    }
    heap.push_back(-1);
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &input);
        res.push_back(input);
        heap.push_back(input);
    }
    insertion = origin;
    insertSort();
    if (insertFlag == 1)
    {
        printf("Insertion Sort\n");
        printf("%d", insertion[0]);
        for (int i = 1; i<n; i++)
        {
            printf(" %d", insertion[i]);
        }
        printf("\n");
    }
    else
    {
        heapSort();
        printf("Heap Sort\n");
        printf("%d", heap[1]);
        for (int i = 2; i <= n; i++)
        {
            printf(" %d", heap[i]);
        }
        printf("\n");

    }
    return 0;
}
