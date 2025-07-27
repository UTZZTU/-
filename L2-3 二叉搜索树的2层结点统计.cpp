#include <bits/stdc++.h>
using namespace std;
int n,k,res,level[2100],maxx,vis[2100];
struct node{
	int value;
	node *left,*right;
	node(int v):value(v),left(NULL),right(NULL){}
};
node* buildtree(int k,node *&root)
{
	if(k<=root->value)
	{
		if(root->left==NULL)
		{
			root->left=new node(k);
			return root;
		}
		else
		root->left=buildtree(k,root->left);
	}
	else
	{
		if(root->right==NULL)
		{
			root->right=new node(k);
			return root;
		}
		else
		root->right=buildtree(k,root->right);
	}
	return root;
}

void dfs(node *root,int lev)
{
	level[lev]++;
	maxx=max(maxx,lev);
	if(root->left!=NULL)
	{
		dfs(root->left,lev+1);
	}
	if(root->right!=NULL)
	{
		dfs(root->right,lev+1);
	}
}
int main ()
{
	cin>>n;
	node *root=NULL;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		if(i==1) root=new node(k);
		else root = buildtree(k,root);
	}
	dfs(root,1);
	cout<<level[maxx]+level[maxx-1]<<endl;
	return 0;
}
