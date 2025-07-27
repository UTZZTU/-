#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll res=-1e18,n,m,f[300010],p[300010];
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>f[i],f[i]+=f[i-1];
	int hh=0,tt=0;
	for(int i=1;i<=n;i++)
	{
		while(hh<=tt&&i-p[hh]>m) hh++;
		res=max(res,f[i]-f[p[hh]]);
		while(hh<=tt&&f[p[tt]]>f[i]) tt--;
		p[++tt]=i;
	}
	cout<<res;
	return 0;
}