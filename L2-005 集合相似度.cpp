#include <bits/stdc++.h>
using namespace std;
int main ()
{
	set<int> p[100];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1,x;j<=k;j++)
		{
			cin>>x;
			p[i].insert(x);
		}
	}
	int m;
	cin>>m;
	for(int i=1,x,y;i<=m;i++)
	{
		int sum=0;
		cin>>x>>y;
		set<int>::iterator it=p[x].begin();
		for(it;it!=p[x].end();it++)
		{
			if(p[y].find(*it)!=p[y].end())
			sum++;
		}
		double s=sum*100.0/(p[x].size()+p[y].size()-sum);
		printf("%.2f%%\n",s);
	}
	return 0;
}
