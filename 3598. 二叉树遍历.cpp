#include <bits/stdc++.h>
using namespace std;
char pre[30],in[30],post[30];
int k;
struct node
{
	char value;
	node *l;
	node *r;
	node(char v=0,node *left=NULL,node *right=NULL):value(v),l(left),r(right){}
};
void buildtree(int l,int r,int &t,node *&root)
{
	int flag=-1;
	for(int i=l;i<=r;i++)
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
		post[k++]=root->value;
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
	while(cin>>pre>>in)
	{
		k=0;
		node *root;
		int t=0;
		buildtree(0,strlen(pre)-1,t,root);
		postorder(root);
		post[k]='\0';
		printf("%s\n",post);
		remove_tree(root);
	}
	return 0;
}