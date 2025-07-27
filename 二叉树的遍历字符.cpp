#include <iostream>
#include <string.h>
using namespace std;
int k;
char post[100010],in[100010],pre[100010];
struct node
{
	char s;
	node *l;
	node *r;
	node( char ch=0,node *left=NULL,node *right=NULL):s(ch),l(left),r(right){}
};
void buildtree(int l,int r,int &t,node *&root)
{
	int i,flag=-1;
	for(i=l;i<=r;i++)
	{
		if(in[i]==pre[t])
		{
			flag=i;
			break;
		}
	}
	if(flag==-1)
	return ;
	root=new node(in[flag]);
	t++;
	if(flag>l)
	buildtree(l,flag-1,t,root->l);
	if(flag<r)
	buildtree(flag+1,r,t,root->r);
}
void postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->l);
		postorder(root->r);
		post[k++]=root->s;
	}
}
void remove_tree(node *root)
{
	if(root==NULL)
	return ;
	remove_tree(root->l);
	remove_tree(root->r);
	delete root;
}
int main ()
{
	int n,l;
	cin>>n;
	getchar();
	while(n--)
	{
		cin>>pre>>in;
		node *root;
		int t=0;
		l=strlen(pre);
		buildtree(0,l-1,t,root);
		k=0;
		postorder(root);
		post[k]='\0';
		cout<<post<<endl;
		remove_tree(root);
	}
	return 0;
}