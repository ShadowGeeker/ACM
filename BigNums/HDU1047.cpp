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
	int n, i, j;
	char ch;
	char sa[g_nMax], sb[g_nMax], sc[g_nMax];
	int bEof = 0;
	scanf("%d%*c", &n);
	
	//getchar(); // blank line
	getchar(); // blank line
	
	for (i = 0; i < n; ++i)
	{
		memset(sb, 0, sizeof(sb));
		if (i) putchar('\n');
		while(1)
		{
			// get input
			memset(sa, 0, sizeof(sa));
			j = 0;
			while ((ch = getchar()) != '\n')
			{
				if (ch == EOF)
				{
					bEof = 1;
					break;
				}
				sa[j++] = ch;
			}
			if (bEof) break;
			sa[j] = '\0';
			if (strlen(sa) == 0) break;
			BigNumAdd(sa, sb, sc);
			strcpy(sb, sc);
		}
		// 删除前导的0
		j = 0;
		while (j < strlen(sc) && sc[j] == '0') ++j;
		if (j == strlen(sc))
			printf("0\n");
		else
			printf("%s\n", sc+j);
	}
	
	return 0;
}
/*
	大数累加，题目比较恶心：
		1. 输入格式比较搞, 另外说是有两个空行, 
		   但如果真那样就WA了, 只需要一个空行就好
*/