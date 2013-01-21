/*
	Author: ShadowGeeker
	GitHub: https://github.com/ShadowGeeker/
	Blog:   http://liuke.org/
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

const int g_nMax = 10100;

void BigNumPlus(const char* sa, const char* sb, char *sc)
{
	int lena = strlen(sa);
	int lenb = strlen(sb);
	int i = lena - 1;
	int j = lenb - 1;
	int k, flow, tmp;

	memset(sc, 0, g_nMax);
	
	for (k = flow = 0; i >= 0; --i)
	{
		tmp = 0;
		for (j = lenb - 1; j >= 0; --j)
		{
			tmp = (sa[i]-'0')*(sb[j]-'0') + flow;
			k = lena-1-i + lenb-j-1;
			if (sc[k] != '\0') tmp = tmp + (sc[k]-'0');
			if (tmp >= 10)
			{
				sc[k] = tmp%10 + '0';
				flow = tmp/10;
			}
			else
			{
				sc[k] = tmp + '0';
				flow = 0;
			}
		}
		// 处理进位
		while (flow)
		{
			k = lena-1-i + lenb;
			if (sc[k] == '\0')
			{
				sc[k] = flow + '0';
				flow = 0;
				break;
			}
			tmp = flow + (sc[k]-'0');
			if (tmp >= 10)
			{
				sc[k] = tmp%10 + '0';
				flow = tmp/10;
			}
			else
			{
				sc[k] = tmp + '0';
				flow = 0;
			}
		}
	}

	int lenc = strlen(sc);
	for (i = 0; i < lenc/2; ++i)
	{
		tmp = sc[i];
		sc[i] = sc[lenc-1 - i];
		sc[lenc-1 - i] = tmp;
	}
}

void erase_prefix0(char *sz)
{
	int len = strlen(sz);
	int i = 0, j = 0;
	while (i < len && sz[i] == '0') ++i;
	if (i == len)
	{
		sz[0] = '0';
		sz[1] = '\0';
		return;
	}
	for (; i <= len; ++i, ++j)
	{
		sz[j] = sz[i];
	}
}

int main(int argc, char **argv)
{
	//freopen("in.txt", "r", stdin);
	char sa[g_nMax], sb[g_nMax], sc[g_nMax];
	char sbase[16];
	int nPow;
	
	while (EOF != scanf("%s %d", sbase, &nPow))
	{
		int ptPos = 0;    // 小数点位置
		int ptNum = 0;    // 小数位数
		int ptVal = 0;    // 去除小数点的值
		erase_prefix0(sbase);
		int ptLen = strlen(sbase);
		int i, j, k;
		char *ptr = strstr(sbase, ".");
		if (ptr != NULL)
		{
			ptPos = ptr - sbase;
			i = ptLen - 1;
			while (i >= 0 && sbase[i] == '0')
			{
				--i;
			}
			ptNum = i - ptPos;
			for (j = 0; j <= i; ++j)
			{
				if (j == ptPos) continue;
				ptVal = ptVal*10 + sbase[j] - '0';
			}
			sprintf(sb, "%d", ptVal);
		}
		else
		{
			ptNum = 0;
			strcpy(sb, sbase);
		}
		// 小数位数
		ptNum = ptNum * nPow;
		// 幂计算
		strcpy(sa, sb);
		strcpy(sc, sb);
		for (i = 2; i <= nPow; ++i)
		{
			BigNumPlus(sa, sb, sc);
			strcpy(sa, sc);
		}
		// 计算小数点位置
		int len = strlen(sc);
		if (ptNum == 0)
		{
			printf("%s\n", sc);
		}
		else if (len <= ptNum)
		{
			putchar('.');
			for (i = 0; i < ptNum - len; ++i)
			{
				putchar('0');
			}
			printf("%s\n", sc);
		}
		else
		{
			for (i = 0; i < len - ptNum; ++i)
			{
				putchar(sc[i]);
			}
			j = len - 1;
			while (j >= 0 && sc[j] == '0')
			{
				--j;
			}
			if (i <= j)
			{
				putchar('.');
				while (i <= j) putchar(sc[i++]);
				putchar('\n');
			}
		}
	}
	
	return 0;
}
/*
	大数乘法
	就是先把小数转换成整数，然后算出原来的浮点数中小数的位数
	最后对整数求幂，然后计算好小数点的位置即可
	注意处理好多余的0的问题
	另外注意浮点数的整数部分可能会存在多余的前导的0
	
	开始是用浮点数输入然后乘以1000000来化为整数，但会存在精度误差
*/