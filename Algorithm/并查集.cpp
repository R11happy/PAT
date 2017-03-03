// 1.初始化
for(int i = 1; i<=N; i++)
{
    father[i] = i;
}
// 2.查找
int findFather(int x)
{
    if(x == father[x])  return x;
    else
    {
        int F = findFather(father[v]);
        father[v] = F;
        return F;
    }
}
// 3.合并
void Union(int a, int b)
{
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB)  father[faA] = faB;
}
