#include <iostream>
using namespace std;
int pre[1010],in[1010],post[1010],k;
struct node
{
	int value;
	node *l,*r;
	node(int w=0,node *left=NULL,node *right=NULL):value(w),l(left),r(right){}
};
void buildtree(int begin,int end,int &t,node *&root)
{
	int flag=-1,i;
	for(i=begin;i<=end;i++)
	{
		if(in[i]==pre[t])
		{
			flag=i;
			break;
		}
	}
	if(flag==-1)
	return;
	root=new node(in[flag]);
	t++;
	if(flag>begin)
	buildtree(begin,flag-1,t,root->l);
	if(flag<end)
	buildtree(flag+1,end,t,root->r);
}
void postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->l);
		postorder(root->r);
		post[k++]=root->value;
	}
}
void remove(node *root)
{
	if(root==NULL)
	return;
	remove(root->l);
	remove(root->r);
	delete root;
}
int main ()
{
	int n,t;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
	cin>>pre[i];
	for(int i=1;i<=n;i++)
	cin>>in[i];
	node *root;
	t=1;
	buildtree(1,n,t,root);
	k=1;
	postorder(root);
	for(int i=1;i<k-1;i++)
	cout<<post[i]<<" ";
	cout<<post[k-1]<<endl;
	remove(root);
	}
	return 0;
}