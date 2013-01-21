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
const int g_nFib = 550;
char g_szFib[g_nFib+1][g_nMax] = {0};

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

void InitFib()
{
	int i;
	
	strcpy(g_szFib[0], "1");
	strcpy(g_szFib[1], "2");
	
	for (i = 2; i <= g_nFib; ++i)
	{
		BigNumAdd(g_szFib[i-2], g_szFib[i-1], g_szFib[i]);
	}
}

int StringCompare(const char *sa, const char *sb)
{
	int lena = strlen(sa);
	int lenb = strlen(sb);
	
	if (lena < lenb) return -1;
	if (lena > lenb) return 1;
	
	/* int i, j;
	for (i = j = 0; i < lena; ++i, ++j)
	{
		if (sa[i] > sb[j]) return 1;
		if (sa[i] < sb[j]) return -1;
	}
	
	return 0; */
	return strcmp(sa, sb);
}

int main(int argc, char **argv)
{
	//freopen("in.txt", "r", stdin);
	char sa[g_nMax], sb[g_nMax];
	InitFib();
	
	while (EOF != scanf("%s %s", sa, sb))
	{
		if (strcmp(sa, "0") == 0 && strcmp(sb, "0") == 0)
			break;
		int i, j;
		for (i = 0; i <= g_nFib; ++i)
		{
			if (StringCompare(sa, g_szFib[i]) <= 0) break;
		}
		for (j = i; j <= g_nFib; ++j)
		{
			if (StringCompare(sb, g_szFib[j]) < 0) break;
		}
		printf("%d\n", j - i);
	}
	
	return 0;
}
/*
	斐波那契数列，大数加法
	先打表，再枚举
	操蛋的数列：1 2 3 5 8 13...注意第二项是2，不是1
*/