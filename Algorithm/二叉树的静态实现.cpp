struct Node
{
    typename data;
    int lchild;
    int rchild;

}node[maxn];

int index = 0;
int newNode(int v)
{
    node[index].data = v;
    node[index].lchild = -1;
    node[index].rchild = -1;
    return index++;
}

// 插入，root为根结点在数组中的下标
void insert(int &root, int x)
{
    if(root == -1)
    {
        root = newNode(x);
        return;
    }
    if(node[node[index].lchild].data < x)   insert(node[root].lchild, x);
    else insert(node[root].rchild, x);
}


// 层序遍历
void LayerOrder(int root)
{
    queue<int> q;   //队列里存放的是结点的下标
    q.push(root);
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        printf("%d ",node[now].data );
        if(node[root].lchild != -1) q.push(node[now].lchild);
        if(node[root].rchild != -1) q.push(node[now].rchild);
    }
}
