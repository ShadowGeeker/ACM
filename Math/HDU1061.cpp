/*
	Author: ShadowGeeker
	GitHub: https://github.com/ShadowGeeker/
	Blog:   http://liuke.org/
*/
#include <iostream>
#include <cstdio>
using namespace std;

int GetRightMostNumber(int n)
{
	int res, i, tmp;
	int T[10] = {1, 1, 4, 4, 2, 1, 1, 4, 4, 2};
	
	tmp = n % 10;
	if (T[tmp] == 1) return tmp;
	
	res = 1;
	n = n % T[tmp];
	if (n == 0) n = T[tmp];
	
	for (i = 0; i < n; ++i)
	{
		res *= tmp;
		res %= 10;
	}
	
	return res;
}

int main(int argc, char **argv)
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int n, m;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &m);
		printf("%d\n", GetRightMostNumber(m));
	}

	return 0;
}

/*
个位数0-9乘以自身所得个位数的周期：
0           1
1           1
2 4 8 6     4
3 9 7 1     4
4 6         2
5           1
6           1
7 9 3 1     4
8 4 2 6     4
9 1         2
如果n%T为0，那么应该令n=T

Problem : 1061 ( Rightmost Digit )     Judge Status : Accepted
RunId : 7495078    Language : C++    Author : ShadowGeeker
Code Render Status : Rendered By HDOJ C++ Code Render Version 0.01 Beta
*/