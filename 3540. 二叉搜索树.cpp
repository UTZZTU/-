#include <bits/stdc++.h>
using namespace std;
int pre[110],in[110],post[110],k;
struct node
{
	int val;
	node *l;
	node *r;
	node(int value):val(value),l(NULL),r(NULL){}
};
node* Insert(node* root,int val)
{
	if(root==NULL)
	root=new node(val);
	else if(val<root->val)
	root->l=Insert(root->l,val);
	else if(val>root->val)
	root->r=Insert(root->r,val);
	return root;
}
void preorder(node *root)
{
	if(root!=NULL)
	{
		pre[++k]=root->val;
		preorder(root->l);
		preorder(root->r);
	}
}
void inorder(node *root)
{
	if(root!=NULL)
	{
	    inorder(root->l);
		in[++k]=root->val;
		inorder(root->r);
	}
}
void postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->l);
		postorder(root->r);
		post[++k]=root->val;
	}
}
int n;
int main ()
{
	cin>>n;
	node *root=NULL;
	for(int i=1,x;i<=n;i++)
	{
		cin>>x;
		root=Insert(root,x);
	}
	preorder(root);
	for(int i=1;i<=k;i++)
	{
		if(i!=1)
		cout<<" ";
		cout<<pre[i];
	}
	cout<<endl;
	k=0;
	inorder(root);
	for(int i=1;i<=k;i++)
	{
		if(i!=1)
		cout<<" ";
		cout<<in[i];
	}
	cout<<endl;
	k=0;
	postorder(root);
	for(int i=1;i<=k;i++)
	{
		if(i!=1)
		cout<<" ";
		cout<<post[i];
	}
	return 0;
}