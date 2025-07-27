#include <bits/stdc++.h>
using namespace std;
int da[100010],ne[100010];
vector<int> a,f[100010];
int s,n,k,m=0;
int main ()
{
	scanf("%d %d %d",&s,&n,&k);
	for(int i=1,u;i<=n;i++)
	{
		scanf("%d",&u);
		scanf("%d %d",&da[u],&ne[u]);
	}
	for(int i=s;~i;i=ne[i])
	a.push_back(i);
	for(int i=0;i<a.size();i++)
	{
		f[++m].push_back(a[i]);
		i++;
		for(int j=2;j<=k&&i<a.size();j++,i++)
		f[m].push_back(a[i]);
		i--;
	}
	for(int i=m;i>=1;i--)
	{
		for(int j=0;j<f[i].size();j++)
		{
			printf("%05d %d ",f[i][j],da[f[i][j]]);
			if(j==f[i].size()-1)
			{
				if(i==1)
				cout<<-1;
				else
				printf("%05d\n",f[i-1][0]);
			}
			else
			printf("%05d\n",f[i][j+1]);
		}
	}
	return 0;
}