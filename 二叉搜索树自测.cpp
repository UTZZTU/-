#include <iostream>
using namespace std;
int pre[100000],ks[100000];
int k;
struct node
{
	int value;
	node *r;
	node *l;
	node(int w=0,node *left=NULL,node *right=NULL):value(w),r(right),l(left){}
};
void buildtree(int l,int r,int &t,node *&root)
{
	if(l>r)
	return;
	int j=r;
	while(ks[j]>=ks[t]&&j>l)
	{
		j--;
	}
	cout<<l<<" "<<r<<" "<<j<<" "<<t<<endl;
	root=new node(ks[t]);
	t++;
	if(j<r)
	buildtree(j+1,r,t,root->r);
	if(j>l)
	buildtree(l,j,t,root->l);
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
int main ()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>ks[i];
	node *root;
	int t=1;
	buildtree(1,n,t,root);
	k=0;
	preorder(root);
	for(int i=0;i<k;i++)
	cout<<pre[i]<<" ";
	return 0;
}