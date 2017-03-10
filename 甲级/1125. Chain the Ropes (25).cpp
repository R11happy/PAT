/**
* @tag     PAT_A_1125
* @authors R11happy (xushuai100@126.com)
* @date    2017-3-10 20:00-20:30
* @version 1.0
* @Language C++
* @Ranking  2265/400
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
const int maxn = 100010;
double origin[maxn] = {-1}, heap[maxn] ={-1};
void percolateDown(int low, int high)
{
    int i = low, j = i*2;
    while(j <= high)
    {
        if(j+1 <= high && heap[j] > heap[j+1]) j = j+1;
        if(heap[i] > heap[j])
        {
            swap(heap[i], heap[j]);
            i = j;
            j = i*2;
        }
        else    break;
    }
}

void percolateUp(int low, int high)
{
    int i = high, j = i/2;
    while(j>=low)
    {
        if(heap[j] > heap[i])
        {
            swap(heap[i], heap[i]);
            i = j;
            j = i/2;
        }
        else break;
    }
}

void createHeap()
{
    for(int i = n/2; i>=1; i--)
    {
        percolateDown(i, n);
    }
}

double deleteTop()
{
    double res = heap[1];
    heap[1] = heap[n--];
    percolateDown(1,n);
    return res;
}

void insert(double x)
{
    heap[++n] = x;
    percolateUp(1,n);
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    double input, ans = 0;
    for(int i = 1; i<=n; i++)
    {
        scanf("%lf", &input);
        origin[i] = input;
        heap[i] = input;
    }
    createHeap();

    while(n>1)
    {
        double les1 = 0, les2 = 0, lesSum = 0;
        les1 = deleteTop();
        les2 = deleteTop();
        lesSum = les1/2 + les2/2;
        ans += lesSum;
        insert(lesSum);
    }
    printf("%d\n",ans );
    return 0;
}
