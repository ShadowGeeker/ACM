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
class Node
{
public:
    char *pTrans;
    Node *next[nMaxSize];
    Node()
    {
        pTrans = NULL;
        for (int i = 0; i < nMaxSize; ++i)
        {
            next[i] = NULL;
        }
    }
};
Node root;

void TreeInsert(char *pWord, char *pTrans)
{
    int i, len = strlen(pWord);
    int id = 0;
    Node *p = &root, *q = NULL;

    for (i = 0; i < len; ++i)
    {
        id = pWord[i] - 'a';
        if (p->next[id] == NULL)
        {
            q = new Node();
            p->next[id] = q;
        }
        p = p->next[id];
    }

    len = strlen(pTrans) + 1;
    p->pTrans = new char[len];
    strcpy(p->pTrans, pTrans);
}

char* TreeQuery(char *pWord)
{
    int i, len = strlen(pWord);
    int id = 0;
    Node *p = &root;

    for (i = 0; i < len; ++i)
    {
        id = pWord[i] - 'a';
        if (p->next[id] == NULL)
        {
            return pWord;
        }
        p = p->next[id];
    }

    if (p->pTrans != NULL)
    {
        return p->pTrans;
    }
    return pWord;
}

void TreeDelete(Node *p)
{
    if (p == NULL) return ;

    for (int i = 0; i < nMaxSize; ++i)
    {
        TreeDelete(p->next[i]);
    }
    if (p == &root) return ;
    if (p->pTrans != NULL) delete p->pTrans;
    delete p;
}

int main(int argc, char **argv)
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    char ch;
    char szTrans[1024], szTmp[1024];
    int i;

    scanf("%s", szTmp);
    while (scanf("%s", szTrans))
    {
        if (strcmp("END", szTrans) == 0) break;
        scanf("%s", szTmp);
        TreeInsert(szTmp, szTrans);
    }
    scanf("%s%*c", szTmp);
    i = 0;
    while (1)
    {
        szTmp[i] = getchar();
        if (!(szTmp[i] >= 'a' && szTmp[i] <= 'z'))
        {
            if (szTmp[i] == 'E') break;
            ch = szTmp[i];
            szTmp[i] = 0;
            printf("%s%c", TreeQuery(szTmp), ch);
            i = -1;
        }
        ++i;
    }
    TreeDelete(&root);

    return 0;
}
