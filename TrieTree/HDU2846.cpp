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
    int sid;
    Node *next[nMaxSize];
    
    Node()
    {
        sid = -1;
        count = 0;
        for (int i = 0; i < nMaxSize; ++i)
        {
            next[i] = NULL;
        }
    }
};
Node root;

void TreeInsert(char *pStr, int sid)
{
    int i, len = strlen(pStr);
    Node *p = &root;
    
    for (i = 0; i < len; ++i)
    {
        int id = pStr[i] - 'a';
        if (p->next[id] == NULL)
        {
            p->next[id] = new Node();
        }
        p = p->next[id];
        if (p->sid != sid)
        {
            p->sid = sid;
            p->count++;
        }
    }
}

int TreeQuery(char *pStr)
{
    int i, len = strlen(pStr);
    int id = 0;
    Node *p = &root;
    
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
    if (p == &root) return ;
    free(p);
}

int main(int argc, char **argv)
{
    //freopen("in.txt", "r", stdin);
    char szBuffer[25];
    int res = 0, n, i, j, len;
    
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        scanf("%s", szBuffer);
        len = strlen(szBuffer);
        for (j = 0; j < len; ++j)
        {
            TreeInsert(szBuffer+j, i);
        }
    }
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        scanf("%s", szBuffer);
        printf("%d\n", TreeQuery(szBuffer));
    }
    
    TreeDelete(&root);
    
    return 0;
}
// 字典树变形：
//     1. 对于每一个输入的字符串，插入所有可能的前缀
//     2. 插入时给字符串添加SID，防止同一个字符串的子串重复计数