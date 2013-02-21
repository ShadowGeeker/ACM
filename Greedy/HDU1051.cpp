/*
	Author: ShadowGeeker
	GitHub: https://github.com/ShadowGeeker/
	Blog:   http://liuke.org/
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int g_nMax = 5010;

class Stick
{
public:
    int l;
    int w;
    bool f;
    bool operator<(const Stick& rhs)
    {
        if (l == rhs.l)
            return w < rhs.w;
        else
            return l < rhs.l;
    }
    bool operator>=(const Stick& rhs)
    {
        return l >= rhs.l && w >= rhs.w;
    }
};

int main(int argc, char **argv)
{
	//freopen("in.txt", "r", stdin);
	int c, t, n, i, j, res;
    Stick s[g_nMax];
    
    scanf("%d", &c);
    while (c--)
    {
        scanf("%d", &n);
        for (i = 0; i < n; ++i)
        {
            scanf("%d %d", &s[i].l, &s[i].w);
            s[i].f = true;
        }
        sort(s, s+n);
        res = 0;
        for (i = 0; i < n; ++i)
        {
            if (s[i].f)
            {
                res++;
                t = i;
                s[t].f = false;
                for (j = t+1; j < n; ++j)
                {
                    if (s[j].f && s[j] >= s[t])
                    {
                        t = j;
                        s[j].f = false;
                    }
                }
            }
        }
        printf("%d\n", res);
    }
	
	return 0;
}
/*
	简单贪心算法，按l从小到大进行排序，如果l相等则按w从小到大排序
    Right after processing a stick of length l and weight w , 
    the machine will need no setup time for a stick of length l' and weight w' 
    if l<=l' and w<=w'. Otherwise, it will need 1 minute for setup. 
    就是说如果下一个比当前处理的一个要大，那么就不用处理时间了
    是和当前正在处理的作比较，所以t要不断的更新，否则WA
*/