///////////////////
// Two Pointers  //
/////////////////////
//使用两个下标i,j进行扫描

// 在递增序列中，求两位置，使其元素和为m
while(i < j)
{
    if(a[i] + a[j] == m)
    {
        printf("%d %d\n",i,j );
        i++;
        j--;
    }
    else if(a[i] + a[j] > m)
    {
        j--;
    }
    else
    {
        i++;
    }
}


///////////////
// 递增序列合并问题
//////////////////
int merge( int A[], int B[], int C[], int n, int m)
{
    int i = 0, j = 0, index = 0;    //i指向A[0], j指向B[0]
    while(i < n && j < m)
    {
        if(A[i] <= B[j])
        {
            C[index++] = A[i++];    //A[i]加入序列
        }
        else
        {
            C[index++] = B[j++];    //B[j]加入序列
        }
    }
    while(i < n)    C[index++] = A[i++];    //将A[]剩余元素加到C中
    while(j < m)    C[index++] = B[j++];    //将B[]剩余元素加到C中
    return index;
}
