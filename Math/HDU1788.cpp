/*
	Author: ShadowGeeker
	GitHub: https://github.com/ShadowGeeker/
	Blog:   http://liuke.org/
*/
#include <iostream>
#include <cstdio>
using namespace std;

__int64 GCD(__int64 a, __int64 b)
{
    __int64 r = a % b;
    
    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    
    return b;
}

__int64 LCM(__int64 m[], int n)
{
    __int64 gcd = 0, lcm = m[0];
    int i;
    
    for (i = 1; i < n; ++i)
    {
        gcd = GCD(lcm, m[i]);
        if (lcm > m[i])
            lcm = lcm / gcd * m[i];
        else
            lcm = m[i] / gcd * lcm;
    }
    
    return lcm;
}

int main(int argc, char **argv)
{
    const int nMax = 15;
    __int64 m[nMax];
    int n, x;
    
    while (EOF != scanf("%d %d", &n, &x), n)
    {
        for(int i = 0; i < n; ++i)
        {
            scanf("%I64d", &m[i]);
        }
        printf("%I64d\n", LCM(m, n) - x);
    }
    
    return 0;
}
/*
	本来是用中国剩余定理做的，结果Wrong Answer了，
	找不到原因，估计是溢出了
	网上基本都是用最小公倍数求解的，思路为：
	N % M1 = M1 - a  ->  (N + a) % M1 = 0
	N % M2 = M2 - a  ->  (N + a) % M2 = 0
	...
	N % Mn = Mn - a  ->  (N + a) % Mn = 0
	结果就是 LCM(M1, M2, ... , Mn) - a
*/