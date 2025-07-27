#include <bits/stdc++.h>
using namespace std;
int n,a[110],minn=0x3f3f3f3f,pos;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int j=(i+1)%n;
		if(j==0) j=n;
		if(abs(a[i]-a[j])<minn)
		{
			minn=abs(a[i]-a[j]);
			pos=i;
		}
	}
	cout<<pos<<" ";
	int j=(pos+1)%n;
	if(j==0) j=n;
	cout<<j<<endl;
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