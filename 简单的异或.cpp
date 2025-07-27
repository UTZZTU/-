#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100010][50],k,q,l,r;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		int pos=1;
		while(k)
		{
			if(k%2) a[i][pos]=1+a[i-1][pos];
			else a[i][pos]=a[i-1][pos];
			k>>=1;
			pos++;
		}
		while(pos<=31)
		{
			a[i][pos]=a[i-1][pos];
			pos++;
		}
	}
	cin>>q;
	while(q--)
	{
		ll num=0,pos=1;
		cin>>l>>r;
		while(pos<=31)
		{
			ll cnt=a[r][pos]-a[l-1][pos];
			if(cnt*2==r-l+1)
			{
				;
			}
			else if(cnt*2>r-l+1)
			{
				;
			}
			else
			{
				num+=(ll)pow(2,pos-1);
			}
			pos++;
		}
		cout<<num<<endl;
	}
//	cout<<(p1^aa)+(p1^bb)<<endl;
//	cout<<(p2^aa)+(p2^bb)<<endl;
	return 0;
}

/*
1 2 => 4

*/