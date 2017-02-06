typedef int dataType;

struct node
{
    dataType data;
    // int layer;   层序遍历专用，记录层次
    node *lchild;
    node *rchild;
};

node *root = NULL;



// 生成一个新结点，v为结点权值
node *newNode(int v)
{
    node *Node = new Node;
    Node->data = v;
    Node->lchild = Node->rchild = NULL; //初始状态下没有左右孩子
    return Node;    //返回新建结点的地址
}

// 查找修改
void search(node *root, int x, int newdata)
{
    if(root == NULL)    return; //空树，死胡同(递归边界)
    if(root->data == x) root->data = newdata;   //找到数据域为x的结点，修改为newdata
    search(root->lchild, x, newdata);   //左子树递归搜索
    search(root->rchild, x, newdata);   //右子树递归搜索
}

// search函数查找二叉树中数据域为x的结点
void search(node *root, int x)
{
    if(root == NULL)
    {
        printf("search failed\n");
        return;
    }
    if(x == root->data) printf("%d\n",root->data );
    else if(x < root->data) search(root->lchild, x);
    else    search(root->rchild, x);
}

// insert函数将在二叉树中插入一个数据域为x的新节点
// 注意根结点指针root要使用引用，否则插入不会成功
void insert(node *&root, int x)
{
    if(root == NULL)    //空树，说明查找失败，也即递归边界
    {
        root = newNode(x);
        return;
    }
    if(x < root->data)  insert(root->lchild, x);    //递归搜索左子树
    else insert(root->rchild, x);
}

/*二叉树的创建*/
node* Create(int data[], int n)
{
    node *root = NULL;  //新建空根结点root
    for(int i = 0; i<n; i++)
    {
        insert(root, data[i]);  //将data[0]~data[n-1]插入到二叉树中
    }
    return root;    //返回根结点
}

void preorder(node *root)
{
    if(root == NULL)    return; //到达空树，递归边界
    printf("%d\n",root->data );
    preorder(root->lchild); //访问左子树
    preorder(root->rchild); //访问右子树
}

void inorder(node *root)
{
    if(root == NULL)    return; //到达空树，递归边界
    inorder(root->lchild);  //访问左子树
    printf("%d\n",root->data );
    inorder(root->rchild);  //访问右子树
}

void postorder(node *root)
{
    if(root == NULL)    return; //到达空树，递归边界
    postorder(root->lchild);    //访问左子树
    postorder(root->rchild);    //访问右子树
    printf("%d\n",root->data );
}

/*层序遍历*/
void LayerOrder(node *root)
{
    queue<node*> q; //注意队列里是存地址
    q.push(root);   //将根结点地址入队
    while(!q.empty())
    {
        node *now = q.front();  //取出队首元素
        q.pop();
        printf("%d",now->data );    //访问队首元素
        if(now->lchild != NULL) q.push(now->lchild);    //左子树非空
        if(now->rchild != NULL) q.push(now->rchild);    //右子树非空
    }
}

/*记录层号的层序遍历*/
void LayerOrder(node *root)
{
    queue<node*> q;    //注意队列里存的是地址
    root->layer = 1;    //根结点层号为1
    q.push(root);   //将根结点地址入队
    while(!q.empty())
    {
        node *now = q.front();  //取出队首元素
        q.pop();
        printf("%d ",now->data );
        if(now->lchild != NULL)
        {
            now->lchild->layer = now->layer+1;
            q.push(now->lchild);
        }
        if(now->rchild != NULL)
        {
            now->rchild->layer = now->layer+1;
            q.push(now->rchild);
        }
    }
}

// 当前先序序列区间为[preL, preR],中序序列区间为[inL,inR],返回根结点地址
node *create(int prel, int preR, int inL, int inR)
{
    if(preL > preR) return NULL;    //先序序列长度小于等于0时，直接返回
    node *root = new node;  //新建一个新的结点，用来存放当前二叉树的根节点
    root->data = pre[preL]; //新节点数据域为根结点的值
    int k;

    for(int k = inL; k<=inR; k++)
    {
        if(in[k] == pre[preL])  break;
        // 在中序序列中找到in[k] == pre[L]的结点
    }

    int numLeft = k - inL;  //左子树的结点个数

    // 左子树的先序区间为[preL+1, preL+numLeft], 中序区间为[inL, k-1]
    // 返回左子树根结点地址，赋值给root的左指针
    root->lchild = create(preL+1, preL+numLeft, inL, k-1);

    // 右子树的先序区间[preL+numLeft+1,preR],中序区间为[k+1,inR]
    // 返回右子树的根节点地址，赋值给root的右指针
    root->rchild = create(preL+numLeft+1, preR, k+1, inR);

    return root;    //返回根结点地址
}


/*寻找以root为根结点的树中最大权值结点*/
node *findMax(node *root)
{
    while(root->rchild != NULL) root = root->rchild;
    return root;
}

// 寻找以root为根结点的树中的最小权值结点
node *findMin(node *root)
{
    while(root->lchild != NULL) root = root->lchild;
    return root;
}

void deleteNode(node *&root, int x)
{
    if(root == NULL)    return;
    if(root->data == x)
    {
        // 叶子结点
        if(root->lchild == NULL && root->rchild)    root = NULL;
        // 左子树非空
        else if(root->lchild != NULL)
        {
            node *pre = findMax(root->lchild);
            root->data = pre->data;
            deleteNode(root->lchild, pre->data);
        }
        // 右子树非空
        else
        {
            node *next = findMin(root->rchild);
            root->data = next->data;
            deleteNode(root->rchild, next->data);
        }
    }
    else if(root->data > x) deleteNode(root->lchild, x);
    else    deleteNode(root->rchild, x);
}


/*输出叶子结点*/
void PreOrderPrintLeaves(node *BT)
{
    if(BT)
    {
        if(!BT->lchild && !BT->rchild)  printf("%d",BT->data );
        PreOrderPrintLeaves(BT->lchild);
        PreOrderPrintLeaves(BT->rchild);
    }
}

/*求二叉树的高度*/
int PostOrderGetHeight(node *T)
{
    int HL, HR, MaxH;
    if(T)
    {
        HL = PostOrderGetHeight(T->lchild);
        HR = PostOrderGetHeight(T->rchild);
        MaxH = (HL > HR)?HL:HR;
        return(MaxH+1);
    }
    else return 0;
}
