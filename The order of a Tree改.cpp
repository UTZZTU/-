#include<iostream>
#include<sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int k;
struct Tree
{
    Tree *l,*r;
    int x;
}tree;
Tree *root;
Tree *create(Tree *rt,int x)//建立二叉搜索树
{
    if(rt==NULL)
    {
        rt=(Tree *)malloc(sizeof(Tree));
        rt->x=x;
        rt->l=rt->r=NULL;
        return rt;
    }
    if(rt->x<x)
        rt->r=create(rt->r,x);
    else
        rt->l=create(rt->l,x);
    return rt;
}
void preorder(Tree *rt,int x)
{
    if(x==1) printf("%d",rt->x);
    else printf(" %d",rt->x);
    if(rt->l!=NULL)
        preorder(rt->l,2);
    if(rt->r!=NULL)
        preorder(rt->r,2);
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        root =NULL;
        if(n==-1) break;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&k);
            root=create(root,k);
        }
        preorder(root,1);
        printf("\n");
    }
    return 0;
}