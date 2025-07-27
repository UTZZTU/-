#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int pre[100],in[100],post[100],k;
struct node
{
	int value;
	node *l;
	node *r;
	node(int val=0,node *left=NULL,node *right=NULL):value(val),l(left),r(right){}
};
void buildtree(int begin,int end,int &t,node *&root)
{
	int i,flag=-1;
	for(i=end;i>=begin;i--)
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
	if(flag<end)
	buildtree(flag+1,end,t,root->r);
	if(flag>begin)
	buildtree(begin,flag-1,t,root->l);
	
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
void levelorder (node *root)
{
	queue<node*> p;
	node *w;
	if(root==NULL)
	return;
    p.push(root);
    while(!p.empty())
    {
    	w=p.front();
    	p.pop();
    	if(w->l!=NULL)
    	p.push(w->l);
    	if(w->r!=NULL)
    	p.push(w->r);
    	printf("%d ",w->value);
	}
}
int main ()
{
	int i,n;
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>post[i];
	for(i=1;i<=n;i++)
	cin>>in[i];
	node *root;
	buildtree(1,n,n,root);
    k=1;
	preorder(root);
	for(i=1;i<k;i++)
	printf("%d ",pre[i]);
	return 0;
}