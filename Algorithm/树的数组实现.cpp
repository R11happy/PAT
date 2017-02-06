/**
* @tag     树的数组实现
* @authors R11happy (xushuai100@126.com)
* @date    2016-10-21 19:22-
* @version 1.0
* @Language C++
* @Ranking  null
* @function null
*/

typedef int dataType;

struct node
{
    dataType data;
    node *lchild;
    node *rchild;
}Node[maxn];

int index = 0;

/*分配一个Node数组中的结点给新的结点，index为其下标*/
int newNode(int v)
{
    Node[index].data = v;
    Node[index].lchild = -1;
    Node[index].rchild = -1;
    return index++;
}

// 查找,root为根结点在数组中的下标
void search(int root, int x, int newdata)
{
    if(root == -1)  return;
    if(Node[root].data == x)    Node[root].data = newdata;
    search(Node[root].lchild, x, newdata);
    search(Node[root].rchild, x, newdata);
}

// 插入, root为根节点在数组中的下标
void insert(int &root, int n)
{
    if(root == -1)
    {
        root = newNode(x);
        return;
    }
    if(root.data < n)   insert(Node[root].lchild, x);
    else insert(Node[root].rchild, x);
}

// 二叉树的建立，函数返回根结点root的下标
int Create(int data[], int n)
{
    int root = -1;
    for(int i = 0; i<n; i++)    insert(root, data[i]);
    return root;
}

// 先序遍历
void preorder(int root)
{
    if(root == -1)  return;
    printf("%d\n",Node[root].data );
    preorder(Node[root].lchild);
    preorder(Node[root].rchild);
}

// 中序遍历
void inorder(int root)
{
    if(root == -1)  return;
    inorder(Node[root].lchild);
    printf("%d\n",Node[root].data );
    inorder(Node[root].rchild);
}

// 后序遍历
void postorder(int root)
{
    if(root == -1)  return;
    postorder(Node[root].lchild);
    postorder(Node[root].rchild);
    printf("%d\n",Node[root].data );
}

// 层序遍历
void LayerOrder(int root)
{
    queue<int> q;
    q.push(root);
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        printf("%d ",Node[now].data );
        if(Node[now].lchild != -1)  q.push(Node[now].lchild);
        if(Node[now].rchild != -1)  q.push(Node[now].rchild);
    }
}


/*树的静态写法*/
/*指的是一般意义上的树，不一定是二叉树*/
struct node
{
    int layer;
    dataType data;
    vector child;
}Node[maxn];

int index = 0;
int newNode(int v)
{
    Node[index].data = v;
    Node[index].child.clear();
    return index++;
}

/*树的先根遍历*/
void PreOrder(int root)
{
    printf("%d ",Node[root].data );
    for(int i = 0; i<Node[root].child.size(); i++)
    {
        PreOrder(Node[root].child[i]);
    }
}

/*树的层序遍历*/
void LayerOrder(int root)
{
    queue<int> Q;
    Q.push(root);
    Node[root].layer = 0;
    while(!Q.empty())
    {
        int front = Q.front();
        printf("%d ",Node[front].data );
        Q.pop();
        for(int i = 0; i<Node[front].child.size(); i++)
        {
            int child = Node[front].child[i];
            Node[child].layer = Node[front].layer+1;
            Q.push(Node[front].child[i]);
        }
    }
}

