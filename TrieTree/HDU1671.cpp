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
    bool isEnd;
    Node *next[nMaxSize];
    
    Node()
    {
        isEnd = false;
        for (int i = 0; i < nMaxSize; ++i)
        {
            next[i] = NULL;
        }
    }
};
Node root;

bool TreeInsert(char *pNum)
{
    int i, len = strlen(pNum);
    Node *p = &root;
    bool bAlloc = false;
    int id = 0;
    
    for (i = 0; i < len; ++i)
    {
        id = pNum[i] - '0';
        if (p->next[id] == NULL)
        {
            p->next[id] = new Node();
            bAlloc = true;
        }
        p = p->next[id];
        if (p->isEnd)
        {
            return false;
        }
    }
    
    p->isEnd = true;
    if (!bAlloc) return false;
    return true;
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
}

int main(int argc, char **argv)
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    int tcase, n, i;
    char szNum[12];
    bool bContinue;
    
    scanf("%d", &tcase);
    while (tcase--)
    {
        scanf("%d", &n);
        bContinue = true;
        for (i = 0; i < n; ++i)
        {
            scanf("%s", szNum);
            if (bContinue)
            {
                if (!TreeInsert(szNum))
                {
                    bContinue = false;
                }
            }
        }
        printf("%s\n", bContinue ? "YES":"NO");
        TreeDelete(&root);
        memset(&root, 0, sizeof(root));
    }
    
    return 0;
}
