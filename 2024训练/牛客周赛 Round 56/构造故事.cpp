#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
bool isthree(ll a,ll b,ll c)
{
	if(a>abs(b-c)&&a<b+c&&b>abs(a-c)&&b<a+c&&c>abs(b-a)&&c<b+a) return true;
	else return false;
}
ll f[10010],n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>f[i];
	sort(f+1,f+1+n);
	for(int i=n-2;i>=1;i--)
	{
		if(isthree(f[i],f[i+1],f[i+2]))
		{
			cout<<f[i]+f[i+1]+f[i+2]<<endl;
			return;
		}
	}
	cout<<-1<<endl;
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