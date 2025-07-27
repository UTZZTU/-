#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll rev(string u)
{
	reverse(u.begin(),u.end());
	ll res=0;
	for(int i=0;i<u.size();i++)
    res=res*10+(u[i]-'0');
    return res;
}
ll reve(ll n)
{
	ll res=0;
	while(n)
	{
		res=res*10+n%10;
		n/=10;
	}
	return res;
}
ll t,sum;
string a,b;
int main ()
{
	scanf("%lld",&t);
	getchar();
	while(t--)
	{
		cin>>a>>b;
		sum=rev(a);
		sum+=rev(b);
		sum=reve(sum);
		printf("%lld\n",sum);
	}
	return 0;
}