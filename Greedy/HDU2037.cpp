/*
	Author: ShadowGeeker
	GitHub: https://github.com/ShadowGeeker/
	Blog:   http://liuke.org/
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int g_nMax = 110;

class CEvent
{
public:
    int s, e;
    bool operator<(const CEvent& rhs)
    {
        return e < rhs.e;
    }
};

int main(int argc, char **argv)
{
	//freopen("in.txt", "r", stdin);
	CEvent e[g_nMax];
    int n, i, j, res;
    
    while (scanf("%d", &n), n)
    {
        for (i = 0; i < n; ++i)
        {
            scanf("%d %d", &e[i].s, &e[i].e);
        }
        sort(e, e+n);
        j = 0;
        res = 1;
        for (i = 1; i < n; ++i)
        {
            if (e[i].s >= e[j].e)
            {
                ++res;
                j = i;
            }
        }
        printf("%d\n", res);
    }
	
	return 0;
}
/*
	经典贪心问题：活动安排。按结束时间从小到大排序，也就是选取尽早结束的活动
    给后面的活动留下尽可能多的时间
*/