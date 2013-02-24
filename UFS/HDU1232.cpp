/*
    Author: ShadowGeeker
    GitHub: https://github.com/ShadowGeeker/
    Blog:   http://liuke.org/
*/
#include <iostream>
#include <cstdio>
using namespace std;

struct Node
{
    int id;
    int parent;
    int rank;
};
Node node[1010];
bool flag[1010];

void MakeSet(int n)
{
    for (int i = 0; i < n; ++i)
    {
        node[i].id = node[i].parent = i;
        node[i].rank = 0;
        flag[i] = false;
    }
}

int FindSet(int x)
{
    if (x != node[x].parent)
    {
        node[x].parent = FindSet(node[x].parent);
    }
    return node[x].parent;
}

void UnionSet(int x, int y)
{
    x = FindSet(x);
    y = FindSet(y);
    
    if (x == y) return;
    if (node[x].rank > node[y].rank)
    {
        node[y].parent = x; // rank大的作为父节点
    }
    else
    {
        node[x].parent = y;
        if (node[x].rank == node[y].rank)
        {
            ++node[y].rank; // 如果秩相等，增加父节点的秩
        }
    }
}

int main(int argc, char **argv)
{
    int n, edge, i, t;
    int x, y, res;
    
    while(EOF != scanf("%d %d", &n, &edge), n)
    {
        MakeSet(n);
        for (i = 0; i < edge; ++i)
        {
            scanf("%d %d", &x, &y);
            --x, --y; // 题目编号从1开始, 代码实现的编号是从0开始的
            UnionSet(x, y);
        }
        res = 0;
        for (i = 0; i < n; ++i)
        {
            t = FindSet(i);
            if (!flag[t])
            {
                ++res;
                flag[t] = true;
            }
        }
        printf("%d\n", res-1);
    }
    
    return 0;
}
/*
    并查集基础题，注意编码是从1开始算的
*/