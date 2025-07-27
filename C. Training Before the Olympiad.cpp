#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,res,num1,num2,a[100010];
void solve()
{
	cin>>n;
	res=num1=num2=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		res+=a[i];
		if(a[i]&1) num1++;
		else num2++;
		if(i==1)
		{
			cout<<res<<" ";
		}
		else
		{
			int sum=num1/3,ys=num1%3;
			if(ys==1) sum++;
			cout<<res-sum<<" ";
		}
	}
	cout<<endl;
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
}