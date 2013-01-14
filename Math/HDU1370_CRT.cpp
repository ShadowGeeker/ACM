/*
    Author: ShadowGeeker
    GitHub: https://github.com/ShadowGeeker/
    Blog:   http://liuke.org/
*/
#include <iostream>
#include <cstdio>
using namespace std;

__int64 PlusInv(__int64 a, __int64 b)
{
    // 求a mod b的乘法逆
    // ax + by = 1
    __int64 r[3] = {a, b};
    __int64 x[3] = {1, 0};
    __int64 y[3] = {0, 1};
    __int64 q, rmd, _b = b;
    
    rmd = a % b;
    q = a / b;
    while (rmd != 0)
    {
        x[2] = x[0] - q*x[1];
        y[2] = y[0] - q*y[1];
        a = b;
        b = rmd;
        x[0] = x[1];
        y[0] = y[1];
        x[1] = x[2];
        y[1] = y[2];
        rmd = a % b;
        q = a / b;
    }
    
    while (x[2] < 0)
    {
        x[2] += _b;
    }
    
    return x[2];
}

__int64 CRT(int a[], int m[], int n)
{
    __int64 M, A;
    int i;
    __int64 *Mi = new __int64[n];
    __int64 *c = new __int64[n];
    
    M = 1;
    for (i = 0; i < n; ++i)
    {
        M *= m[i];
    }
    
    A = 0;
    for (i = 0; i < n; ++i)
    {
        Mi[i] = M/m[i];
        c[i] = Mi[i] * PlusInv(Mi[i], m[i]);
        A += a[i]*c[i];
        A %= M;
    }
    
    delete []Mi;
    delete []c;
    
    return A;
}

int main(int argc, char **argv)
{
    int t, idx = 1;
    scanf("%d%*c", &t);
    //getchar();
    
    const int nMax = 5;
    int m[nMax], a[nMax], n, x;
    
    int p, e, i, d;
    int tp = 23, te = 28, ti = 33;
    while (1)
    {
        scanf("%d %d %d %d", &p, &e, &i, &d);
        if (p == -1) break;
        
        m[0] = tp, m[1] = te, m[2] = ti;
        a[0] = p,  a[1] = e , a[2] = i;
        int res = CRT(a, m, 3);
        res = (res - d + tp*te*ti)%(tp*te*ti);
        if (!res) res = tp*te*ti;
        
        printf("Case %d: the next triple peak occurs in %d days.\n", idx++, res);
    }
    
    return 0;
}
/*
    可以使用中国剩余定理求解本题
    同余方程组为：
        A ≡ p mod tp
        A ≡ e mod te
        A ≡ i mod ti
    答案为 A - d，可能会小于0，领 T=tp*te*ti
    求 (A+T)%T即可
*/