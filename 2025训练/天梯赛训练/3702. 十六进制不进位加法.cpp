#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
string a,b;
void solve()
{
	while(cin>>a>>b)
	{
		int maxx=max(a.size(),b.size());
		while(a.size()<maxx)
		{
			a="0"+a;
		}
		while(b.size()<maxx)
		{
			b="0"+b;
		}
		for(int i=0;i<maxx;i++)
		{
			int sum=0;
			if(a[i]>='0'&&a[i]<='9') sum+=(a[i]-'0');
			else sum+=(a[i]-'A'+10);
			if(b[i]>='0'&&b[i]<='9') sum+=(b[i]-'0');
			else sum+=(b[i]-'A'+10);
			sum%=16;
			if(sum<=9) cout<<(char)('0'+sum);
			else cout<<(char)('A'+sum-10);
		}
		cout<<endl;
	}
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