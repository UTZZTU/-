#include <bits/stdc++.h>
using namespace std;
int vis[1010],f[1010],n,pd;
set<int> p;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	scanf("%d",&f[i]);
	for(int i=1;i<=n;i++)
	{
		if(f[i]==0)
		continue;
		int j=i;
		pd=0;
		memset(vis,0,sizeof(vis));
		vector<int> vec;
		while(1)
		{
			if(vis[j])
			{
                pd=1;
				break;
			}
			if(f[j]==0)
			break;
			vec.push_back(j);
			vis[j]=1;
			j=f[j];
		}
		if(pd)
		{
			for(auto it=vec.begin();it!=vec.end();it++)
			{
				p.insert(*it);
			}
		}
	}
	cout<<n-p.size();
	return 0;
}