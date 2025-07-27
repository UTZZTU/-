#include <bits/stdc++.h>
using namespace std;
int fa[100010],a[100010];
int tot,sum;
int find(int x)
{
	if(a[x]) return a[x];
	if(x==-1)
    return 0;
    else
	return a[x]=find(fa[x])+1;
}
int main ()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	fa[i]=i;
	for(int i=1,k;i<=n;i++)
	{
		scanf("%d",&k);
		fa[i]=k;
	}
	for(int i=1;i<=n;i++)
	{
		int u=find(i);
		if(u>tot)
		{
			tot=u;
			sum=1;
		}
		else if(u==tot)
		sum++;
	}
	cout<<tot<<endl;
	for(int i=1;i<=n;i++)
	{
		if(find(i)==tot)
		{
			cout<<i;
			sum--;
			if(sum!=0)
		cout<<" ";
		}
	}
	return 0;
}