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

const int nMaxSize = 26;
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
char szWord[50010][256];          // 适当设置大小，否则会超内存MLE
char szLeft[256], szRight[256];

void TreeInsert(char *pWord)
{
    int i, len = strlen(pWord);
    Node *p = &root;
    int id = 0;
    
    for (i = 0; i < len; ++i)
    {
        id = pWord[i] - 'a';
        if (p->next[id] == NULL)
        {
            p->next[id] = new Node();
        }
        p = p->next[id];
    }
    p->isEnd = true;
}

bool TreeQuery(char *pWord)
{
    int i, len = strlen(pWord);
    int id = 0;
    Node *p = &root;
    
    for (i = 0; i < len; ++i)
    {
        id = pWord[i] - 'a';
        if (p->next[id] == NULL)
        {
            return false;
        }
        p = p->next[id];
    }
    
    return p->isEnd;
}

void TreeDelete(Node* p)
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
    
    int i = 0, n;
    while (EOF != scanf("%s", szWord[i]))
    {
        TreeInsert(szWord[i]);
        ++i;
    }
    n = i;
    
    for (i = 0; i < n; ++i)
    {
        int len = strlen(szWord[i]);
        int j = 0;
        memset(szLeft, 0, sizeof(szLeft));
        for (j = 0; j < len-1; ++j)
        {
            szLeft[j] = szWord[i][j];
            if (TreeQuery(szLeft))
            {
                strcpy(szRight, szWord[i]+j+1);
                if (TreeQuery(szRight))
                {
                    printf("%s\n", szWord[i]);
                    break;
                }
            }
        }
    }
    TreeDelete(&root);
    memset(&root, 0, sizeof(root));

    return 0;
}
