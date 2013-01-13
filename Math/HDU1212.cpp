/*
	Author: ShadowGeeker
	GitHub: https://github.com/ShadowGeeker/
	Blog:   http://liuke.org/
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char **argv)
{
	char a[1010];
	int b;
	
	while (EOF != scanf("%s %d", a, &b))
	{
		int r = 0, i = 0, len = strlen(a);
		for (i = 0; i < len; ++i)
		{
			r = (r*10 + a[i]-'0') % b;
		}
		printf("%d\n", r);
	}

	return 0;
}
/*
	模拟最原始的除法运算
*/