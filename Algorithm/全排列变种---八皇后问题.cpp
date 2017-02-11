/**
 * 考虑到每行只能放置一个皇后，每列也只能放置一个皇后，那么如果把n列皇后所在的行号依次写出，那么就会是1~n的一个排列
 *
 * 在n*n的国际象棋棋盘上放置n个皇后，求合法的方案数
 */

/*暴力法*/
int count = 0;
void generateP(int index)
{
    if(index == n+1){//递归边界，生成一个排列
        bool flag = true;
        for(int i = 1; i<=n; i++){
            for(int j = i+1; j<=n; j++)
            {
                if(abs(i - j) == abs(P[i] - P[j])){//如果在一条对角线上
                    flag = false;   //不合法
                }
            }
        }
        if(flag)    count++;
        return;
    }
    for(int x = 1; x<=n; x++)
    {
        if(hashTable[x] == false){
            P[index] = x;
            hashTable[x] = true;
            generateP(index+1);
            hashTable[x] = false;
        }
    }
}

/*回溯法*/
/**
 * 如果在到达递归边界前的某层，由于一些试试导致已经不需要往任何一个子问题递归，就可以直接返回上一层
 */
void generateP(int index)
{
    if(index == n+1){   //递归边界，生成一个合法方案
        count++;    //能到达这里的一定是合法的
        return;
    }
    for(int x = 1; x<=n; x++)   //第x行
    {
        if(hashTable[x] == false) //第x行还没有皇后
        {
            bool flag = true;   //flag为true表示当前皇后不会和之前的皇后冲突
            for(int pre = 1; pre < index; pre++)    //遍历之前的皇后
            {
                if(abs(index - pre) == abs(x - P[pre]))
                {
                    flag = false;   //与之前的皇后在同一条对角线上，冲突
                    break;
                }
            }
            if(flag)    //可以把皇后放在第x行
            {
                P[index] = x;   //令第index列皇后的行号为x
                hashTable[x] = true;    //第x行已经被占用
                generateP(index+1); //递归处理第index+1行皇后
                hashTable[x] = false;   //递归完毕，还原第x行为未占用

            }

        }
    }
}
