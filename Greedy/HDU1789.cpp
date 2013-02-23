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

class HWork
{
public:
    int d, p;
};

template<class T>
class cmp
{
public:
    bool operator()(const T& lhs, const T& rhs)
    {
        if (lhs.p == rhs.p)
            return rhs.d < lhs.d;
        return rhs.p < lhs.p;
    }
};

int main(int argc, char **argv)
{
	//freopen("in.txt", "r", stdin);
	int c, i, j, n, res;
    HWork hw[g_nMax];
    bool flag[g_nMax];
    
    scanf("%d", &c);
    while (c--)
    {
        scanf("%d", &n);
        for (i = 0; i < n; ++i)
        {
            scanf("%d", &hw[i].d);
        }
        for (i = 0; i < n; ++i)
        {
            scanf("%d", &hw[i].p);
        }
        memset(flag, 0, sizeof(flag));
        sort(hw, hw+n, cmp<HWork>());
        res = 0;
        for (i = 0; i < n; ++i)
        {
            for (j = hw[i].d; j > 0; j--)
            {
                if (!flag[j])
                {
                    flag[j] = true;
                    break;
                }
            }
            if (j == 0) res += hw[i].p;
        }
        printf("%d\n", res);
    }
	
	return 0;
}
/*
    惩罚最大的任务应该尽可能完成，以减少惩罚
    所以按照惩罚从大到小排序，如果惩罚相同则按截止日期从大到小排序
    然后一个一个扫描看是否可以完成。
*/