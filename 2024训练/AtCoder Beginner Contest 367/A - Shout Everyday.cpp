#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b,c;
void solve()
{
	cin>>a>>b>>c;
	for(int i=b;i!=c;)
	{
		if(i==a)
		{
			cout<<"No"<<endl;
			return;
		}
		i++;
		i%=24;
	}
//	if(a==0) a=24;
//	if(c<b) c+=24;
//	if(a>=b&&a<=c) cout<<"No"<<endl;
//	else 
	cout<<"Yes"<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}