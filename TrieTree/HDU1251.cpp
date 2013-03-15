/*
    Author: ShadowGeeker
    GitHub: https://github.com/ShadowGeeker/
    Blog:   http://liuke.org/
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int nMaxSize = 26;
struct Node
{
    int count;
    Node *next[nMaxSize];
};
Node *root = NULL;

void TreeCreate()
{
    root = (Node *)malloc(sizeof(Node));
    for (int i = 0; i < nMaxSize; ++i)
    {
        root->next[i] = NULL;
    }
}

void TreeInsert(char *pStr)
{
    int i, j, len = strlen(pStr);
    Node *p = root;
    Node *q = NULL;
    
    for (i = 0; i < len; ++i)
    {
        int id = pStr[i] - 'a';
        if (p->next[id] == NULL)
        {
            q = (Node *)malloc(sizeof(Node));
            q->count = 0;
            for (j = 0; j < nMaxSize; ++j)
            {
                q->next[j] = NULL;
            }
            p->next[id] = q;
        }
        p->next[id]->count++;
        p = p->next[id];
    }
}

int TreeQuery(char *pStr)
{
    int i, len = strlen(pStr);
    int id = 0;
    Node *p = root;
    
    for (i = 0; i < len; ++i)
    {
        id = pStr[i] - 'a';
        p = p->next[id];
        if (p == NULL) return 0;
    }
    
    return p->count;
}

void TreeDelete(Node *p)
{
    if (p == NULL) return ;
    for (int i = 0; i < nMaxSize; ++i)
    {
        TreeDelete(p->next[i]);
    }
    free(p);
}

int main(int argc, char **argv)
{
    //freopen("in.txt", "r", stdin);
    char szBuffer[16];
    int res = 0;
    
    TreeCreate();
    while (1)
    {
        gets(szBuffer);
        if (strlen(szBuffer) == 0) break;
        TreeInsert(szBuffer);
    }
    while (EOF != scanf("%s", szBuffer))
    {
        res = TreeQuery(szBuffer);
        printf("%d\n", res);
    }
    
    TreeDelete(root);
    
    return 0;
}
// 太贱了 getchar() 就给WA了
// 中间那个空行 不是一个换行符那么简单……可能还有许多的空格……用gets就过了