/*
	Author: ShadowGeeker
	GitHub: https://github.com/ShadowGeeker/
	Blog:   http://liuke.org/
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

char dict[4][4];
int nMax, n, tcnt;

bool check(int x, int y)
{
    int i, j;
    
    // Right
    i = x, j = y + 1;
    while (j < n && dict[i][j] != 'X')
    {
        if (dict[i][j] == 'O') return false;
        ++j;
    }
    // Left
    i = x, j = y - 1;
    while (j >= 0 && dict[i][j] != 'X')
    {
        if (dict[i][j] == 'O') return false;
        --j;
    }
    // Up
    i = x - 1, j = y;
    while (i >= 0 && dict[i][j] != 'X')
    {
        if (dict[i][j] == 'O') return false;
        --i;
    }
    // Down
    i = x + 1, j = y;
    while (i < n && dict[i][j] != 'X')
    {
        if (dict[i][j] == 'O') return false;
        ++i;
    }
    
    return true;
}

void Search()
{
    int i, j, flag = 0;
    int backup[4][4];
    
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (dict[i][j] == '.' && check(i, j))
            {
                flag = 1;
                dict[i][j] = 'O';
                tcnt++;
                Search();
                tcnt--;
                dict[i][j] = '.';
            }
        }
    }
    if (flag == 0)
    {
        nMax = max(nMax, tcnt);
    }
}

int main(int argc, char **argv)
{
    //freopen("in.txt", "r", stdin);
    int i, j;
    char ch;
    
    while (ch=getchar(), ch != '0')
    {
        getchar();
        n = ch - '0';
        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < n; ++j)
            {
                dict[i][j] = getchar();
            }
            getchar();
        }
        nMax = 0;
        tcnt = 0;
        Search();
        printf("%d\n", nMax);
    }
    
    return 0;
}
/*
    用的递归+回溯的方法，对于每一个空余的点，先检查这个点是否可以放
    如果可以放，再计算放的最大值，然后回溯，计算这个点不放时的最大值
*/