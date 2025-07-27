#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string too(ll n)
{
	string u;
	while(n)
	{
		u+='0'+n%2;
		n/=2;
	}
	reverse(u.begin(),u.end());
	return u;
}
ll s,t,n,x,y,f[200010];
int main ()
{
	scanf("%lld %lld",&s,&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%lld %lld %lld",&n,&x,&y);
		for(int j=1;j<=n;j++)
		scanf("%lld",&f[j]);
		cout<<too(f[1])<<endl;
		for(int j=1;j<=x;j++)
		cout<<"^";
		for(int j=1;j<=y;j++)
		cout<<"|";
		cout<<endl;
	}
	return 0;
}