#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans,x;
int t[200010],c[200010],f[200010],p[200010];
int main ()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i]>>c[i];
		f[max(1,t[i]-c[i]+1)]++;
		f[t[i]+1]--;
//		cout<<max(1,t[i]-c[i])<<endl;
	}
	for(int i=1;i<=t[n];i++)
	{
		ans+=f[i];
		p[i]=ans;
	}
	while(m--)
	{
		cin>>x;
		if(x+k>t[n])
		cout<<0<<endl;
		else
		cout<<p[x+k]<<endl;
	}
	return 0;
}