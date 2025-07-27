#include <bits/stdc++.h>
using namespace std;
struct node{
	int data,next;
}s[100010];
int root,n,pos,f[100010],cnt=1;
void dfs(int root,int num)
{
	f[num]=root;
	if(s[root].next==-1) return;
	cnt++;
	dfs(s[root].next,num+1);
}
int main ()
{
	scanf("%d%d",&root,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&pos);
		scanf("%d%d",&s[pos].data,&s[pos].next);
	}
	dfs(root,1);
	for(int i=cnt,j=1;i>=j;i--,j++)
	{
		printf("%05d %d ",f[i],s[f[i]].data);
		if(i==j)
		{
			cout<<-1<<endl;
			break;
		} 
		else
		{
			printf("%05d\n",f[j]);
		}
		printf("%05d %d ",f[j],s[f[j]].data);
		if(i==j+1)
		{
			printf("-1\n");
			break;
		}
		else
		{
			printf("%05d\n",f[i-1]);
		}
	}
	return 0;
}