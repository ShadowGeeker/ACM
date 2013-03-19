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

const int nMaxSize = 2;
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

bool TreeInsert(char *pWord)
{
    int i, len = strlen(pWord);
    int id = 0;
    Node *p = &root;
    bool bAlloc = false;
    
    for (i = 0; i < len; ++i)
    {
        id = pWord[i] - '0';
        if (p->next[id] == NULL)
        {
            p->next[id] = new Node();
            bAlloc = true;
        }
        p = p->next[id];
        if (p->isEnd) return false;
    }
    
    p->isEnd = true;
    return bAlloc;
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
    
    char szNum[16];
    bool bOK = true;
    int i = 0;
    
    while (1)
    {
        if (EOF == scanf("%s", szNum))
        {
            break;
        }
        if (szNum[0] == '9')
        {
            ++i;
            if (bOK)
            {
                printf("Set %d is immediately decodable\n", i);
            }
            else
            {
                printf("Set %d is not immediately decodable\n", i);
            }
            bOK = true;
            TreeDelete(&root);
            memset(&root, 0, sizeof(root));
        }
        else
        {
            if (bOK) bOK = TreeInsert(szNum);
        }
    }

    return 0;
}
