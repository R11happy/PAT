/**
* @tag     堆相关
* @authors R11happy (xushuai100@126.com)
* @date    2017-3-10
* @version 1.0
* @Language C++
* @Ranking  null
* @function null
*/

// 堆是完全二叉树，第1个结点存储于数组中的1号位，第i号结点的左儿子为2*i,右儿子为2*i+1

const int maxn = 100;
// heap为堆，n为元素个数
int heap[maxn], n;

// 对heap数组在[low,high]范围内进行向下调整
// 其中low为预调整结点的数组下标，high一般为堆的最后一个元素的数组下标
void percolateDown(int low, int high)
{
    int i = low, j = i*2;   //i为调整结点，j为左孩子
    while(j <= high)
    {
        // 注意：要先保证heap[j+1]存在
        if(heap[j] < heap[j+1]) j=j+1;  //选左右孩子中大的哪一个
        // 将heap[i]向下调整
        if(heap[j] > heap[i])
        {
            swap(heap[i], heap[j]);
            i = j;
            j = i*2;
        }
        // heap[i]比两个孩子都大，跳出
        else
        {
            break;
        }
    }
}

// 建堆：自底向上逐步percolateDown
void creteHeap()
{
    for(int i = n/2; i>=1; i--)
    {
        percolateDown(i, n);
    }
}

// 删除堆顶元素
// 最后一个元素覆盖堆顶元素，同时元素个数减一，将堆顶元素逐步percolateDown
void deleteTop()
{
    heap[1] = heap[n--];
    percolateDown(1, n);
}

// 往堆里面添加一个元素，在最后添加，然后逐步percolateUp，直到父元素大于两个孩子
// 对heap数组在[low,high]范围percolateUp
// 其中low一般设置为1，high表示欲调整结点的数组下标
void percolateUp(int low, int high)
{
    int i = high, j = i/2;
    while(j >= low)
    {
        if(heap[j] < heap[i])
        {
            swap(heap[j], heap[i]);
            i = j;
            j = i /2;
        }
        else
        {
            break;
        }
    }
}

// 添加元素x
// 将待添加元素加入堆的末尾，然后逐步percolateUp,直到父元素比自己大为止
void insert(int x)
{
    heap[++n] = x;
    percolateUp(1, n);
}

// 堆排序  倒着遍历数组
// 先建堆，取出堆顶元素，将最后一个元素替换至堆顶，然后逐步percolateDown
// 一直重复，直到堆中只有一个元素为止
void heapSort()
{
    creteHeap();
    for(int i = n; i>1; i--)
    {
        swap(heap[1], heap[i]);
        percolateDown(1,i-1);
    }
}
