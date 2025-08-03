#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int n,a,b,c,d;
void solve()
{
	cin>>n;
	a=b=c=d=0;
	cin>>s;
	for(int i=0;i<4*n;i++)
	{
		if(s[i]=='A') a++;
		else if(s[i]=='B') b++;
		else if(s[i]=='C') c++;
		else if(s[i]=='D') d++;
	}
	int res=0;
	res+=min(a,n);
	res+=min(b,n);
	res+=min(c,n);
	res+=min(d,n);
	cout<<res<<endl;
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