/*
	Author: ShadowGeeker
	GitHub: https://github.com/ShadowGeeker/
	Blog:   http://liuke.org/
*/
#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char **argv)
{
	int t, idx = 1;
	scanf("%d%*c", &t);
	//getchar();
	
	int p, e, i, d;
	int tp = 23, te = 28, ti = 33;
	while (1)
	{
		scanf("%d %d %d %d", &p, &e, &i, &d);
		if (p == -1) break;
		
		int curd = i;
		while (curd <= d) curd += ti;
		while (!((curd - p) % tp == 0 && 
				 (curd - e) % te == 0 /*&& 
				 (curd - i) % ti == 0*/))
		{
			curd += ti;
		}
		printf("Case %d: the next triple peak occurs in %d days.\n", idx++, curd - d);
	}
	
	return 0;
}

/*
	下一个目标日期减去给定的peak值p,e,i分别是
	三个周期的倍数
	寻找可能的目标日期的时候可以累加最大的周期
	
	那个空行比较蛋疼，用getchar()反而WA了
	而第一个数N不知道到底有何用途
*/
