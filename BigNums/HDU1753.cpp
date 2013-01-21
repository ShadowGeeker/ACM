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

const int g_nMax = 410;

void BigNumAdd(const char *sa, const char *sb, char *sc)
{
    int lena = strlen(sa);
    int lenb = strlen(sb);
    int lenc = 0;
    int i = lena - 1;
    int    j = lenb - 1;
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
    //freopen("in.txt", "r", stdin);
    
    char sa[g_nMax], sb[g_nMax];
    char sa_p[g_nMax], sa_a[g_nMax];
    char sb_p[g_nMax], sb_a[g_nMax];
    char sc_p[g_nMax], sc_a[g_nMax];
    
    while (EOF != scanf("%s %s", sa, sb))
    {
        // split string a
        char *ptr = strstr(sa, ".");
        if (ptr == NULL)
        {
            strcpy(sa_p, sa);
            strcpy(sa_a, "0");
        }
        else
        {
            memcpy(sa_p, sa, ptr - sa);
            sa_p[ptr - sa] = '\0';
            strcpy(sa_a, ptr+1);
        }
        // split string b
        ptr = strstr(sb, ".");
        if (ptr == NULL)
        {
            strcpy(sb_p, sb);
            strcpy(sb_a, "0");
        }
        else
        {
            memcpy(sb_p, sb, ptr - sb);
            sb_p[ptr - sb] = '\0';
            strcpy(sb_a, ptr+1);
        }
        // fill with suffix 0
        int lena = strlen(sa_a);
        int lenb = strlen(sb_a);
        int maxlen = lena > lenb ? lena : lenb;
        int i, j;
        for (i = lena; i < maxlen; ++i)
        {
            sa_a[i] = '0';
        }
        sa_a[i] = '\0';
        for (j = lenb; j < maxlen; ++j)
        {
            sb_a[j] = '0';
        }
        sb_a[j] = '\0';
        
        // 求和
        BigNumAdd(sa_p, sb_p, sc_p);
        BigNumAdd(sa_a, sb_a, sc_a);
        if (strlen(sc_a) != strlen(sa_a)) // 有进位
        {
            strcpy(sa, sc_p);
            sb[0] = sc_a[0];
            sb[1] = '\0';
            BigNumAdd(sa, sb, sc_p);
            
            for(i = 0; i < strlen(sc_a); ++i)
            {
                sc_a[i] = sc_a[i+1];
            }
        }
        // 清除整数部分前导的0
        i = 0;
        lena = strlen(sc_p);
        while (i < lena && sc_p[i] == '0') ++i;
        // 清除小数部分后导的0
        j = strlen(sc_a) - 1;
        while (j >= 0 && sc_a[j] == '0')
        {
            sc_a[j] = '\0';
            --j;
        }
        // 输出
        printf("%s", sc_p + i);
        if (j >= 0)
        {
            printf(".%s", sc_a);
        }
        printf("\n");
    }
    
    return 0;
}
/*
    将将小数分割为整数部分和小数部分，
    然后对小数部分的尾部填充0，保证两个小数部分长度一致
    然后分别对小数部分和整数部分求和
    如果小数部分有进位，要加到整数部分
    然后分别清除不必要的0
*/