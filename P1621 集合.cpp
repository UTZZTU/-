#include <bits/stdc++.h>
using namespace std;
int a,b,f[100010],p,maxx;
vector<int> vec[1000010];
set<int> st;
int find(int x)
{
	while(x!=f[x])
	x=f[x]=f[f[x]];
	return x;
}
int main ()
{
	cin>>a>>b>>p;
	int ans=b-a+1;
	for(int i=a;i<=b;i++)
	{
		f[i]=i;
		int tt=i;
		for(int j=2;j*j<=tt;j++)
		{
			if(tt%j==0)
			{
				while(tt%j==0) tt/=j;
				vec[j].push_back(i);
				maxx=max(maxx,j);
			}
		}
		if(tt>1)
		{
			vec[tt].push_back(i);
			maxx=max(maxx,tt);
		}
	}
	for(int k=maxx;k>=p;k--)
	{
		if(vec[k].size()<=1)
		continue;
		for(int i=0;i<vec[k].size()-1;i++)
		{
			for(int j=i+1;j<vec[k].size();j++)
			{
				int tx=find(vec[k][i]),ty=find(vec[k][j]);
				if(tx!=ty)
				{
					f[ty]=tx;
					ans--;
				}
				
			}
		}
	}
	/*for(int i=a;i<=b;i++)
	{
		int tt=find(i);
		st.insert(tt);
	}
	cout<<st.size();*/
	cout<<ans;
	return 0;
}