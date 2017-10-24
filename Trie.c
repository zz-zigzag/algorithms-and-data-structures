#include <stdio.h>
#include <string.h>

const int N=26,M=400000;

typedef struct TrieNode
{
    int nCount;
    TrieNode *next[N];
    TrieNode()
    {
        nCount=1;
        memset(next,NULL,sizeof(next));
    }
}TrieNode;

TrieNode *Root=NULL,Memory[M];
int Top,i,k;

void InsertTrie(const char *s)
{
    TrieNode *p=Root;
    if(p==NULL)
        p=Root=&Memory[Top++];
    for(i=0;s[i]!=0;i++)
    {
        k=s[i]-'a';
        if(p->next[k])
            p->next[k]->nCount++;
        else p->next[k]=&Memory[Top++];
        p=p->next[k];
    }
}
int SearchTrie(const char *s)
{
    TrieNode *p=Root;
    if(p==NULL)
        return 0;
    for(i=0;s[i]!=0;i++)
    {
        k=s[i]-'a';
        if(p->next[k]==NULL)
            return 0;
        p=p->next[k];
    }
    return p->nCount;
}
int main()
{
    char a[15];
    Top=0;
    while(gets(a) && a[0]!=0)
    {
        InsertTrie(a);
    }
    while(scanf("%s",a)!=EOF)
    {
        printf("%d\n",SearchTrie(a));
    }
    return 0;
}
