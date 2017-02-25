/**
* @tag     PAT_A_1022
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-25 18:57-20:14
* @version 1.0
* @Language C++
* @Ranking  1685/743
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
// 5个map变量分别建立书名、作者、关键词、出版社及出版年份与id的映射关系
map<string, set<int> > mpTitle, mpAuthor, mpKey, mpPub, mpYear;

// void类型，希望函数内部对传入参数有影响的，考虑 引用类型&
void query(map<string, set<int> > &mp, string &str)
{
    if (mp.find(str) == mp.end())    printf("Not Found\n");
    else
    {
        for (set<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++)
        {
            printf("%07d\n", *it);   //输出str对应所有id
        }
    }
}

int main(int argc, char const *argv[])
{
    int numOfBook;
    scanf("%d", &numOfBook);
    int m, id, type;
    string title, author, key, pub, year;
    for (int i = 0; i<numOfBook; i++)
    {
        scanf("%d", &id);
        char c = getchar(); //吸收id后面的换行符
        getline(cin, title);
        mpTitle[title].insert(id);
        getline(cin, author);
        mpAuthor[author].insert(id);
        // 注意：如何处理不指定数量的string输入
        while (cin >> key)
        {
            mpKey[key].insert(id);
            char c = getchar();
            if (c == '\n')    break;  //结束关键词输入，退出
        }
        getline(cin, pub);
        mpPub[pub].insert(id);
        getline(cin, year);
        mpYear[year].insert(id);
    }

    // 处理查询
    string contentOfQuery;
    scanf("%d", &m);
    for (int i = 0; i<m; i++)
    {
        scanf("%d: ", &type);
        getline(cin, contentOfQuery);
        cout << type << ": " << contentOfQuery << endl;
        if (type == 1)   query(mpTitle, contentOfQuery);
        else if (type == 2)  query(mpAuthor, contentOfQuery);
        else if (type == 3)  query(mpKey, contentOfQuery);
        else if (type == 4)  query(mpPub, contentOfQuery);
        else query(mpYear, contentOfQuery);
    }
    return 0;
}
