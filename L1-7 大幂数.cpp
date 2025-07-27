#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool flag;
int main ()
{
	ll n;
	cin>>n;
	for(ll i=31;i>=1;i--)
	{
		ll sum=0;
		ll j=1;
		for(j=1;;j++)
		{
			sum+=(ll)pow(j,i);
			if(sum>=n) break;
		}
		if(sum==n)
		{
			flag=true;
			for(int k=1;k<=j;k++)
			{
				if(k!=1) cout<<"+";
				cout<<k<<"^"<<i;
			}
			break;
		}
	}
	if(flag==false)
	{
		cout<<"Impossible for "<<n;
	}
	return 0;
}
