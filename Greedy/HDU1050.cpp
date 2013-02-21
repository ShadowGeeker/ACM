/*
	Author: ShadowGeeker
	GitHub: https://github.com/ShadowGeeker/
	Blog:   http://liuke.org/
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int g_nMax = 210;

class Room
{
public:
    int s, t;
    bool f;
    bool operator<(const Room& rhs)
    {
        return s < rhs.s;
    }
};

bool check(const Room& l, const Room& r)
{
    int maxl = max(l.s, l.t);
    int minr = min(r.s, r.t);
    if (!(minr & 1)) // even
        return maxl < minr-1;
    return maxl < minr;
}

int main(int argc, char **argv)
{
	//freopen("in.txt", "r", stdin);
    int c, n, t, i, j;
    int res;
    Room r[g_nMax];
    
    scanf("%d", &c);
    while(c--)
    {
        scanf("%d", &n);
        for (i = 0; i < n; ++i)
        {
            scanf("%d %d", &r[i].s, &r[i].t);
            if (r[i].s > r[i].t)
                swap(r[i].s, r[i].t);
            r[i].f = true;
        }
        sort(r, r+n);
        res = 0;
        for (i = 0; i < n; ++i)
        {
            if (r[i].f)
            {
                res += 10;
                t = i;
                r[t].f = false;
                for (j = t+1; j < n; ++j)
                {
                    if (r[j].f && check(r[t], r[j]))
                    {
                        t = j;
                        r[t].f = false;
                    }
                }
            }
        }
        printf("%d\n", res);
    }
    
	return 0;
}
/*
	简单贪心算法，按照s从小到大进行排序，然后逐个进行比较
    比较规则为两个区间段没有交叉，那么左边最大的应该小于右边最小的
    又考虑到题目所给的分布，如果右边最小的是偶数，那么应该maxl < minr-1
    因为是从左往右扫描，所以排序之前，要确保s小于t，如果不小于要自行进行交换
*/