/**
* @tag     null
* @authors R11happy (xushuai100@126.com)
* @date
* @version 1.0
* @Language C++
* @Ranking  null
* @function 读入一个只包含+-* /的计算表达式，计算表达式的值
*/

/*
输入：30/90-26+97-5-6-13/88*6+51/29+79*87+57*92
0
输出:12178.21
 */

/*注意：只有当op的优先级高于栈顶操作符的优先级时才压入操作符栈*/

#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <map>
using namespace std;

struct node
{
    double num; //操作数
    char op;    //操作符
    bool flag;  //true表示操作数，false表示操作符
};

string str;
stack<node> s;  //操作符栈
queue<node> q;  //后缀表达式序列
map<char, int> op;

////////////////////
// 将中缀表达式转化为后缀表达式 //
////////////////////
// 操作数（可能不止一位，需要一位一位读入后合并在一起）直接加入后缀表达式(queue)
// 操作符 只有当op的优先级 大于 栈顶的优先级的时候，op才入栈
// 否则依次将栈弹出到后缀表达式
void Change()
{
    double num;
    node temp;
    for(int i = 0; i<str.length();)
    {
        if(str[i]>= '0' && str[i] <= '9')   //是数字
        {
            temp.flag = true;   //标记是数字
            temp.num = str[i++] - '0';
            while(i < str.length() && str[i] >= '0' && str[i] <= '9')
            {
                temp.num = temp.num * 10 + (str[i] - '0');  //更新操作数
                i++;
            }
            q.push(temp);   //将操作数压入后缀表达式的序列
        }
        else    //如果是操作符
        {
            temp.flag = false;  //标记操作符
            // 只要操作符栈的栈顶元素比该操作符优先级高
            // 就把操作符栈栈顶元素弹出到后缀表达式的队列中
            while(!s.empty() && op[str[i]] <= op[s.top().op])
            {
                q.push(s.top());
                s.pop();
            }
            temp.op = str[i];
            s.push(temp);   //把该操作符压入操作符栈中
            i++;
        }
    }
    // 如果操作符栈中还有操作符，就把它弹出到后缀表达式队列中
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

// 计算后缀表达式
double Cal()
{
    double tmp1, tmp2;
    node cur, tmp;
    while(!q.empty())
    {
        cur = q.front();    //cur记录队首元素
        q.pop();
        if(cur.flag == true)    s.push(cur);    //操作数直接入栈
        else    //操作符
        {
            tmp2 = s.top().num; //弹出第二操作数
            s.pop();
            tmp1 = s.top().num; //弹出第一操作数
            s.pop();
            tmp.flag = true;    //临时记录操作数
            if(cur.op == '+')   tmp.num = tmp1 + tmp2;
            else if(cur.op == '-')  tmp.num = tmp1 - tmp2;
            else if(cur.op == '*')  tmp.num = tmp1 * tmp2;
            else    tmp.num = tmp1 / tmp2;
            s.push(tmp);
        }
    }
    return s.top().num; //栈顶元素就是后缀表达式的值
}

int main(int argc, char const *argv[])
{
    op['+'] = op['-'] = 1;   //设定操作符优先级
    op['*'] = op['/'] = 2;
    while(getline(cin, str), str != "0")
    {
        for(string::iterator it = str.end()-1; it != str.begin(); it--)
        {
            if(*it == ' ')  str.erase(it);  //把表达式中的空格全部去掉
        }
        while(!s.empty())   s.pop();    //初始化栈
        Change();   //中缀表达式转后缀表达式
        printf("%.2f\n",Cal() );    //计算后缀表达式
    }
    return 0;
}
