/*
	Author: ShadowGeeker
	GitHub: https://github.com/ShadowGeeker/
	Blog:   http://liuke.org/
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
using namespace std;

class Node
{
public:
    int id;
    int parent;
    int val;
    bool operator<(const Node& rhs) const
    {
        // priority_queue是从大到小排序的
        // 这样重载<可以使得实际上按照val从小到大排序
        return val > rhs.val;
    }
};

int GetIdx(char ch)
{
    if (ch == '_') return 26;
    return ch - 'A';
}

int main(int argc, char **argv)
{
    string str;
    string strEnd("END");
    int i, j, idx, len, res;
    
    while (cin >> str)
    {
        if (str == strEnd) break;
        Node n[100] = {0};
        len = str.size();
        for (i = 0; i < len; ++i)
        {
            idx = GetIdx(str[i]);
            n[idx].val++;
            n[idx].id = n[idx].parent = idx;
        }
        j = 27;
        // 入队
        priority_queue<Node> q;
        for (i = 0; i < j; ++i)
        {
            if (n[i].val) q.push(n[i]);
        }
        if (q.size() == 1)
        {
            printf("%d %d %.1f\n", len*8, len, 8.0);
            continue;
        }
        // 建树过程
        while (q.size() > 1)
        {
            // pop
            Node a = q.top();
            q.pop();
            Node b = q.top();
            q.pop();
            // combine
            n[j].val = a.val + b.val;
            n[j].id = n[j].parent = j;
            q.push(n[j]);
            // set parent
            n[a.id].parent = n[b.id].parent = j;
            ++j;
        }
        // calc depth
        res = 0;
        for (i = 0; i < 27; ++i)
        {
            if (n[i].val)
            {
                int height = 0;
                Node tmp = n[i];
                while (tmp.parent != tmp.id)
                {
                    tmp = n[tmp.parent];
                    ++height;
                }
                res += n[i].val * height;
            }
        }
        printf("%d %d %.1f\n", len*8, res, len*8.0 / res);
    }
    
    return 0;
}
/*
    哈弗曼编码问题
*/