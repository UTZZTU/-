#include <bits/stdc++.h>
using namespace std;
int t,n,ans,f[110];
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
    for(int k=1;k<=t;k++)
    {
    	ans=0;
    	cin>>n;
    	for(int i=1;i<=n;i++)
    	cin>>f[i];
    	for(int i=2;i<n;i++)
    	if(f[i]>f[i+1]&&f[i]>f[i-1])
    	ans++;
    	cout<<"Case #"<<k<<": "<<ans<<endl;
	}
	return 0;
}