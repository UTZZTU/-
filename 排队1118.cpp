#include <bits/stdc++.h>
using namespace std;
int n,f[10];
map<int,int> mp;
int nxs()
{
	int res=0;
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(f[i]>f[j])
			res++;
		}
	}
	return res;
}
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>f[i];
	sort(f+1,f+1+n);
	do{
		int res=nxs();
		mp[res]++;
	}while(next_permutation(f+1,f+1+n));
	for(auto it=mp.begin();it!=mp.end();it++)
	cout<<it->first<<" "<<it->second<<endl;
	return 0;
}