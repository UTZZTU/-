#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e11+3;
ll ans,a=1,b=3,n,c;
int main ()
{
	cin>>n;
	if(n==1)
	cout<<1;
	else if(n==2)
	cout<<4;
	else
	{
		ans=4;
		for(int i=3;i<=n;i++)
		{
			c=a+b;
			ans+=c;
			ans%=INF;
			a=b;
			b=c;
			a%=INF;
			b%=INF;
		}
		cout<<ans;
	}
	return 0;
}