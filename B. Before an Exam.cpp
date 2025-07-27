#include <bits/stdc++.h>
using namespace std;
int d,sum,a[50],b[50];
void solve()
{
	int res1=0,res2=0;
	cin>>d>>sum;
	for(int i=1;i<=d;i++)
	{
		cin>>a[i]>>b[i];
		res1+=a[i];
		res2+=b[i];
	}
	if(sum>=res1&&sum<=res2)
	{
		cout<<"YES"<<endl;
		int cnt=sum-res1;
		for(int i=1;i<=d;i++)
		{
			if(cnt>=b[i]-a[i])
			{
				cout<<b[i]<<" ";
				cnt-=(b[i]-a[i]);
			}
			else
			{
				cout<<a[i]+cnt<<" ";
				cnt=0;
			}
		}
		cout<<endl;
	}
	else cout<<"NO"<<endl;
}
int main ()
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