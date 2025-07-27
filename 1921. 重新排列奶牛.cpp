#include <bits/stdc++.h>
using namespace std;
map<int,int> mp1;
map<int,int> mp2;
int n,f[110],len=-1,ans;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	scanf("%d",&f[i]);
	for(int i=1,k;i<=n;i++)
	{
		scanf("%d",&k);
		mp1[k]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(mp2.count(f[i])||i==mp1[f[i]])
		continue;
		ans++;
		int j=i,res=0;
		while(!mp2.count(f[j]))
		{
			res++;
			mp2[f[j]]=1;
			j=mp1[f[j]];
		}
		len=max(len,res);
	}
	cout<<ans<<" "<<len;
	return 0;
}