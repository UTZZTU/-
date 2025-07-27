#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[1000010],s[1000010],n,k,a,b;
ll ans;
int main ()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d %d",&a,&b);
		f[a]+=1;
		f[b+1]-=1;
	}
	for(int i=1;i<=n;i++)
	{
		ans+=f[i];
		s[i]=ans;
	}
	sort(s+1,s+1+n);
	cout<<s[n/2+1];
	return 0;
}