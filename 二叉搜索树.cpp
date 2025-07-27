#include<bits/stdc++.h>
using namespace std;
typedef struct node{
	struct node *left;
	struct node *right;
	int val;
}node,*tree;
void insert(tree &t,int x)
{
	if(t==NULL)
	{
		t=new node;
		t->val=x;
		t->left=NULL;
		t->right=NULL;
	}
	else if(x<t->val)
		insert(t->left,x);
	else if(x>t->val)
		insert(t->right,x);
}
int judge(tree t1,tree t2)
{
	if(t1!=NULL&&t2!=NULL)
	{
		if(t1->val!=t2->val)return 0;
		if(!judge(t1->left,t2->left))return 0;
		if(!judge(t1->right,t2->right))return 0;
	}
	else if((t1!=NULL&&t2==NULL)||t1==NULL&&t2!=NULL)
		return 0;
	return 1;
}
int main()
{
	int n;
	while(~scanf("%d",&n)&&n)
	{
		getchar();
		char ch;
		tree t1=NULL;
		while((ch=getchar())!='\n')
			insert(t1,ch-'0');
		for(int i=0;i<n;i++)
		{
			tree t2=NULL;
			while((ch=getchar())!='\n')
				insert(t2,ch-'0');
			if(judge(t1,t2))cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	return 0;
}