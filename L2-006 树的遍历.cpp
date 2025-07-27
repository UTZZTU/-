#include <bits/stdc++.h>
using namespace std;
int pre[100],in[100],post[100],k,level[100],n;
struct node
{
	int val;
	node *l;
	node *r;
	node(int v=0,node *left=NULL,node *right=NULL):val(v),l(left),r(right){}
};
void buildtree(int l,int r,int &t,node *&root)
{
	int flag=-1;
	for(int i=r;i>=l;i--)
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
	if(flag<r)
	buildtree(flag+1,r,t,root->r);
	if(flag>l)
	buildtree(l,flag-1,t,root->l);
}
void levelorder(node *root)
{
	queue<node*> q;
	node *w;
	if(root==NULL)
	return;
	q.push(root);
	while(!q.empty())
	{
		w=q.front();
		q.pop();
		if(w->l!=NULL)
		q.push(w->l);
		if(w->r!=NULL)
		q.push(w->r);
		level[++k]=w->val;
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
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>post[i];
	for(int i=1;i<=n;i++)
	cin>>in[i];
	int t=n;
	node *root;
	buildtree(1,n,t,root);
	k=0;
	levelorder(root);
	for(int i=1;i<=k;i++)
	{
		if(i!=1)
		cout<<" ";
		cout<<level[i];
	}
	return 0;
}
