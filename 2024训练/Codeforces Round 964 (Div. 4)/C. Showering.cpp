#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,s,m;
int flag,l,r,prel,prer;
void solve()
{
	cin>>n>>s>>m;
	flag=0;
	for(int i=1;i<=n;i++)
	{
		cin>>l>>r;
		if(i==1)
		{
			if(l>=s)
			{
				flag=1;
			}
		}
		else
		{
			if(l-prer>=s)
			{
				flag=1;
			}
		}
		prel=l,prer=r;
	}
	if(m-r>=s)
	{
		flag=1;
	}
	if(flag) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
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