#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
long double n,k;
void solve()
{
	cin>>n>>k;
	if(k>=100) cout<<1<<endl;
	else
	{
		ll p=pow(n,1.0/k);
		if(p==0) cout<<1<<endl;
		else
		{
			if(abs(n-pow(p,k))<abs(n-pow(p+1,k)))
			{
				cout<<p<<endl;
			}
			else cout<<p+1<<endl;
		}
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}