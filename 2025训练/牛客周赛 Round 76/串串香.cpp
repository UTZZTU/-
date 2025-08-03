#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int a[100],n,maxx;
char c;
string s;
void solve()
{
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		a[s[i]-'a']++;
		if(a[s[i]-'a']>maxx)
		{
			maxx=a[s[i]-'a'];
			c=s[i];
		}
	}
	cout<<c<<endl;
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