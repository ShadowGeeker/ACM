/*
    Author: ShadowGeeker
    GitHub: https://github.com/ShadowGeeker/
    Blog:   http://liuke.org/
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

const int nMaxSize = 10;
struct Node
{
    int count;
    Node *next[nMaxSize];
};
Node root = {0};
int g_nMaxRes = 0;

void TreeInsert(char *pStr)
{
    Node *p = &root, *q = NULL;
    int i, j, len = strlen(pStr);
    int id = 0;

    for (i = 0; i < len; ++i)
    {
        id = pStr[i] - '0';
        if (p->next[id] == NULL)
        {
            q = new Node();
            for (j = 0; j < nMaxSize; ++j)
            {
                q->next[j] = NULL;
            }
            q->count = 0;
            p->next[id] = q;
        }
        p = p->next[id];
    }

    p->count++;
    if (g_nMaxRes < p->count)
    {
        g_nMaxRes = p->count;
    }
}

void TreeDelete(Node *p)
{
    if (p == NULL) return ;
    for (int i = 0; i < nMaxSize; ++i)
    {
        TreeDelete(p->next[i]);
    }

    if (p == &root) return ;
    delete p;
    p = NULL;
}

int main(int argc, char **argv)
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    char szStr[32];
    int i, n;
    char *p = NULL;

    while (EOF != scanf("%d%*c", &n))
    {
        g_nMaxRes = 0;
        memset(&root, 0, sizeof(root));  // 奇葩点
        for (i = 0; i < n; ++i)
        {
            gets(szStr);
            p = szStr;
            while (*p == '0') ++p;
            TreeInsert(p);
        }
        printf("%d\n", g_nMaxRes);
        TreeDelete(&root);
    }

    return 0;
}
// 扩展阅读：http://www.programlife.net/debugger-magic-number.html