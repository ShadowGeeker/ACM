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
    int count;
    Node *next[nMaxSize];

    Node()
    {
        count = 0;
        for (int i = 0; i < nMaxSize; ++i)
        {
            next[i] = NULL;
        }
    }
};
Node root;
const int nMaxLen = 110;
int g_nMaxRes = 0;
char szMaxRes[nMaxLen], szTmp[nMaxLen];
char szMap[10][5] = {
    "", "", "abc", "def", "ghi", "jkl", 
    "mno", "pqrs", "tuv", "wxyz"
};

void TreeInsert(char *pWord, int nFreq)
{
    int i, len = strlen(pWord);
    int id = 0;
    Node *p = &root;
    
    for (i = 0; i < len; ++i)
    {
        id = pWord[i] - 'a';
        if (p->next[id] == NULL)
        {
            p->next[id] = new Node();
        }
        p = p->next[id];
        p->count += nFreq;
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
}

/*
    比通过对数字字符串进行DFS枚举所有可能的情况，然后查询要快
    因为这里通过字典树进行查询，如果某一个前缀没找到，那么
    以这个前缀开头的所有字符串都不用查询了
*/
void DFS(char *pNum, Node *p, int idx, int len)
{
    if (idx == len)
    {
        if (p->count > g_nMaxRes)
        {
            g_nMaxRes = p->count;
            strcpy(szMaxRes, szTmp);
        }
        return ;
    }

    int i, j;
    j = pNum[idx]-'0';
    for (i = 0; i < strlen(szMap[j]); ++i)
    {
        int id = szMap[j][i] - 'a';
        if (p->next[id] == NULL)
        {
            continue;
        }
        szTmp[idx] = id + 'a';
        szTmp[idx+1] = 0;
        DFS(pNum, p->next[id], idx+1, len);
    }
}

int main(int argc, char **argv)
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int tcase, idx;
    int n, i;
    int nFreq;
    char szWord[nMaxLen], szNum[nMaxLen];

    scanf("%d", &tcase);
    for (idx = 1; idx <= tcase; ++idx)
    {
        printf("Scenario #%d:\n", idx);
        scanf("%d", &n);
        while (n--)
        {
            scanf("%s %d", szWord, &nFreq);
            TreeInsert(szWord, nFreq);
        }
        scanf("%d", &n);
        while (n--)
        {
            scanf("%s", szNum);
            if (szNum[0] == '1')
            {
                printf("\n");
                continue;
            }
            int len = strlen(szNum);
            for (i = 0; i < len-1; ++i)
            {
                g_nMaxRes = 0;
                DFS(szNum, &root, 0, i+1);
                if (g_nMaxRes)
                {
                    printf("%s\n", szMaxRes);
                }
                else
                {
                    printf("MANUALLY\n");
                }
            }
            printf("\n");
        }
        printf("\n");
        TreeDelete(&root);
        memset(&root, 0, sizeof(root));
    }

    return 0;
}
