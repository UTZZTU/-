#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int pre[N],in[N],post[N];
int k;
struct node
{
	int value;
	node *l,*r;
	node(int value=0,node *l=NULL,node *r=NULL):value(value),l(l),r(r){}
};
void buildtree(int l,int r,int &t,node *&root)
{
	int flag=-1;
	for(int i=l;i<=r;i++)
	{
		if(in[i]==post[t])
		{
			flag=i;
			break;
		}
	}
	if(flag==-1)
	return;
	root=new node(in[flag]);
	t--;
	if(flag>l)
	buildtree(l,flag-1,t,root->l);
	if(flag<r)
	buildtree(flag+1,r,t,root->r);
}
void preorder(node *root)
{
	if(root!=NULL)
	{
		pre[k++]=root->value;
		preorder(root->l);
		preorder(root->r);
	}
}
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->l);
		pre[k++]=root->value;
		inorder(root->r);
	}
}
void postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->l);
		postorder(root->r);
		pre[k++]=root->value;
	}
}
void remove_tree(node *root)
{
	if(root==NULL)
	return;
	remove_tree(root->l);
	remove_tree(root->r);
	delete root;
}
int main ()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
		cin>>post[i];
		for(int j=1;j<=n;j++)
	    cin>>in[j];
	    node *root;
	    int t=n;
	    buildtree(1,n,t,root);
	    k=0;
	    preorder(root);
	    for(int i=0;i<k;i++)
		printf("%d%c",pre[i],i==k-1?'\n':' ');
		remove_tree(root);
	}
	return 0;
}
