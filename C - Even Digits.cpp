#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,cnt;
string s;
void solve()
{
	cin>>n;
	if(n<=5)
	{
		cout<<(n-1)*2<<endl;
		return;
	}
	int pp=1;
	while(pp*5<n)
	{
		pp*=5;
		cnt++;
	}
//	cout<<cnt<<endl;
	cnt++;
	for(int i=cnt;i>=1;i--)
	{
		int p=pow((int)5,i-1);
		int pos=ceil(n*1.0/p);
//		cout<<"pos"<<pos<<endl;
		if(pos==0) s+='8';
		else
		s+=('0'+(pos-1)*2);
		n%=p;
	}
//	s+=('0'+(n/pp-1)*2);
//	for(int i=cnt;i>=1;i--)
//	{
//		if()
//	}
	
//	reverse(s.begin(),s.end());
	cout<<s<<endl;
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}