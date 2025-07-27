#include <bits/stdc++.h>
using namespace std;
set<int> p;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k,a[55];
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int o1=1;o1<=n-3;o1++)
	{
		for(int o2=o1+1;o2<=n-2;o2++)
		{
			if(o2==o1)
			continue;
			for(int o3=o2+1;o3<=n-1;o3++)
			{
				if(o3==o2||o3==o1)
				continue;
				for(int o4=o3+1;o4<=n;o4++)
				{
					if(o4==o3||o4==o2||o4==o1)
					continue;
					int tot=(a[o1]+a[o2]+a[o3]+a[o4]);
					if(tot%4==0)
					p.insert(tot/4);
				}
			}
		}
	}
	for(int i=1;i<=k;i++)
	{
		int pd=0;
		int u,l;
		cin>>u;
		for(int j=1;j<=u;j++)
		{
			cin>>l;
			set<int>::iterator it=p.find(l);
			if(it==p.end())
			pd=1;
		}
		if(pd==1)
		printf("No\n");
		else
		printf("Yes\n");
	}
	return 0;
}