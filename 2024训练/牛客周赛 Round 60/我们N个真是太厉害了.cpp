#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll n,a[100010],maxx;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	maxx=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>maxx+1)
		{
			if(maxx>=n)
			cout<<"Cool!"<<endl;
			else cout<<maxx+1<<endl;
			return;
		}
		else maxx+=a[i];
	}
	if(maxx>=n)
	cout<<"Cool!"<<endl;
	else cout<<maxx+1<<endl;
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