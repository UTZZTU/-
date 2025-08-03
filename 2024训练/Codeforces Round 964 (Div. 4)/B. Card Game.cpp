#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a1,a2,b1,b2,res,cnt1,cnt2;
void solve()
{
	
	res=0;
	cin>>a1>>a2>>b1>>b2;
	cnt1=cnt2=0;
	if(a1>b1) cnt1++;
	else if(a1<b1) cnt2++;
	if(a2>b2) cnt1++;
	else if(a2<b2) cnt2++;
	if(cnt1>cnt2) res++;
	
	cnt1=cnt2=0;
	if(a1>b2) cnt1++;
	else if(a1<b2) cnt2++;
	if(a2>b1) cnt1++;
	else if(a2<b1) cnt2++;
	if(cnt1>cnt2) res++;
	
	res*=2;
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