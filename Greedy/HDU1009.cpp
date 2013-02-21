/*
	Author: ShadowGeeker
	GitHub: https://github.com/ShadowGeeker/
	Blog:   http://liuke.org/
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int g_nMax = 1010;

class Room
{
public:
    int j;
    int f;
    double r;
};

template<class T>
class cmp
{
public:
    bool operator()(const T& x, const T& y) const
    {
        return y.r < x.r;
    }
};

int main(int argc, char **argv)
{
	//freopen("in.txt", "r", stdin);
	Room room[g_nMax];
    int i, n, m;
    double res;
    
    while (scanf("%d %d", &m, &n))
    {
        if (m == -1 && n == -1) break;
        for (i = 0; i < n; ++i)
        {
            scanf("%d %d", &room[i].j, &room[i].f);
            room[i].r = room[i].j*1.0 / room[i].f;
        }
        sort(room, room+n, cmp<Room>());
        res = 0;
        for (i = 0; i < n && m > 0; ++i)
        {
            if (m >= room[i].f)
            {
                m -= room[i].f;
                res += room[i].j;
            }
            else
            {
                res += room[i].r * m;
                m = 0;
            }
        }
        printf ("%.3f\n", res);
    }
	
	return 0;
}
/*
	简单贪心算法，按性价比对房间进行排序，
    依次挑选性价比最高的房间即可
*/