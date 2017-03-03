struct Node
{
    int data, height;
    int lchild = -1;
    int rchild = -1;
}node[maxn];

int index = 0;

int newNode(int data)
{
    node[index].data = data;
    node[index].lchild = -1;
    node[index].rchild = -1;
    node[index].height = 1;
    return index++;
}

int getHeight(int root)
{
    if(root == -1)  return 0;
    return node[root].height;
}

int getBalanceFactor(int root)
{
    return getHeight(node[root].lchild) - getHeight(node[root].rchild);
}

void updateHeight(int root)
{
    node[root].height = max(getHeight(node[root].lchild), getHeight(node[root].rchild)) + 1;
}

void L(int &root)
{
    int tmp = node[root].rchild;
    node[root].rchild = node[tmp].lchild;
    node[tmp].lchild = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void R(int &root)
{
    int tmp = node[root].lchild;
    node[root].lchild = node[tmp].rchild;
    node[tmp].rchild = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}



// 插入键值为data的结点
void insert(int &root, int data)
{
    if(root == -1)
    {
        root = newNode(data);
        return;
    }
    if(data < node[root].data)
    {
        insert(node[root].lchild, data);    //往左子树插入
        updateHeight(root);
        if(getBalanceFactor(root) == 2)
        {
            if(getBalanceFactor(node[root].lchild) == 1)   R(root);
            else if(getBalanceFactor(node[root].lchild) == -1)
            {
                L(node[root].lchild);
                R(root);
            }
        }
    }
    else
    {
        insert(node[root].rchild, data);   //往右子树插入
        updateHeight(root);
        if(getBalanceFactor(root) == -2)
        {
            if(getBalanceFactor(node[root].rchild) == -1)   L(root);
            else if(getBalanceFactor(node[root].rchild) == 1)
            {
                R(node[root].rchild);
                L(root);
            }
        }
    }
}
