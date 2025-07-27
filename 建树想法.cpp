#include <iostream>
using namespace std;
int pre[1010],post[1010];
int ks=1,sum=1;
node *root;
struct node
{
	int value;
	node *l,*r;
	node(int value=0,node *l=NULL,node *r=NULL):value(value),l(l),r(r){}
};
void dfs(int n,int l,int r)
{
	sum++;
	if(sum>)
	int i,k,nl=0,nr=0;
	for(i=l;i<=r;i++)
	{
		if(pre[i]<n)
		{
			if(nl==0)
			{
				nl=i;
			}
		}
		if(pre[i]>=n)
		{
			if(nr==0)
			{
				nr=i;
				break;
			}
		}
	}
	buildtree1()
}
void buildtree1(int l,int r,node *&root,int wz)
{
	root=new node(pre[wz]);
}
int main ()
{
	int n,i,l,r;
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>pre[i];
	l=2;
	r=n;
	dfs(pre[ks],l,r);
	
}