/*
	Author: ShadowGeeker
	GitHub: https://github.com/ShadowGeeker/
	Blog:   http://liuke.org/
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int g_nMax = 1010;

void BigNumAdd(const char *sa, const char *sb, char *sc)
{
	int lena = strlen(sa);
	int lenb = strlen(sb);
	int lenc = 0;
	int i = lena - 1;
	int	j = lenb - 1;
	int k = 0, tmp;
	int flow = 0;
	
	for (k = flow = 0; i >= 0 && j >= 0;)
	{
		tmp = sa[i] - '0' + sb[j] - '0' + flow;
		if (tmp >= 10)
		{
			flow = 1;
			tmp -= 10;
		}
		else
		{
			flow = 0;
		}
		sc[k] = tmp + '0';
		--i, --j, ++k;
	}
	while (i >= 0)
	{
		tmp = sa[i] - '0' + flow;
		if (tmp >= 10)
		{
			flow = 1;
			tmp -= 10;
		}
		else
		{
			flow = 0;
		}
		sc[k] = tmp + '0';
		--i, ++k;
	}
	while (j >= 0)
	{
		tmp = sb[j] - '0' + flow;
		if (tmp >= 10)
		{
			flow = 1;
			tmp -= 10;
		}
		else
		{
			flow = 0;
		}
		sc[k] = tmp + '0';
		--j, ++k;
	}
	if (flow)
	{
		sc[k++] = '1';
	}
	sc[k] = '\0';
	
	lenc = k;
	for (i = 0; i < lenc/2; ++i)
	{
		tmp = sc[i];
		sc[i] = sc[lenc-1 - i];
		sc[lenc-1 - i] = tmp;
	}
}

int main(int argc, char **argv)
{
	char sa[g_nMax], sb[g_nMax], sc[g_nMax];
	int n, m, i;
	
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &m);
		if (m == 1 || m == 2)
		{
			printf("1\n");
			continue;
		}
		strcpy(sa, "1");
		strcpy(sb, "1");
		for (i = 3; i <= m; ++i)
		{
			BigNumAdd(sa, sb, sc);
			strcpy(sa, sb);
			strcpy(sb, sc);
		}
		printf("%s\n", sc);
	}
	
	return 0;
}
/*
	斐波那契数列，大数加法
*/