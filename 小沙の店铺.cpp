#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y,k,n,t,num,res;
int main ()
{
	cin>>x>>y>>k>>n>>t;
	for(int i=n;i>=1;i--)
	{
		res+=x*i;
		if(res>=t)
		{
			cout<<(n-i+1);
			return 0;
		}
		num+=i;
		x+=(num/k)*y;
		num%=k;
	}
	cout<<-1;
	return 0;
}