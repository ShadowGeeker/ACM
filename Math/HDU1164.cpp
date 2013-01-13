/*
	Author: ShadowGeeker
	GitHub: https://github.com/ShadowGeeker/
	Blog:   http://liuke.org/
*/
#include <iostream>
#include <cstdio>
using namespace std;

const int nMaxNum = 65536;
int g_prime[nMaxNum] = {0};

int GenPrime(/*int nMaxNum*/)
{
	int i, j;
	g_prime[0] = g_prime[1] = 1;    // not prime
	for (i = 3; i < nMaxNum; ++i)
	{
		if (!g_prime[i])            // prime
		{
			for (j = i + i; j < nMaxNum; j += i)
			{
				g_prime[j] = 1;
			}
		}
	}
	// copy to self
	i = j = 0;
	for (; i < nMaxNum; ++i)
	{
		if (!g_prime[i])
		{
			g_prime[j++] = i;
		}
	}
	
	return j;
}

int main(int argc, char **argv)
{
	int m, n;
	n = GenPrime();
	
	while (EOF != scanf("%d", &m))
	{
		int i = 0;
		bool bFirst = true;
		while (i < n && m != 1)
		{
			if (m % g_prime[i] == 0)
			{
				if (bFirst) bFirst = false;
				else putchar('*');
				printf("%d", g_prime[i]);
				m /= g_prime[i];
			}
			else
			{
				++i;
			}
		}
		putchar('\n');
	}
	
	return 0;
}

/*
	先生成65535内所有的素数，然后从小到大逐个取模即可
	筛选法求素数效率更高
*/