#include <bits/stdc++.h>
using namespace std;
int n,a[110],b[110];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	int pos=upper_bound(b+1,b+1+n,b[1])-b;
	if(pos==n+1)
	{
		cout<<"NO"<<endl;
	}
	else
	{
//		int x=b[pos];
//		for(int i=1;i<=n;i++)
//		{
//			if(a[i]==x)
//			{
//				cout<<i<<endl;
//				return;
//			}
//		}
		cout<<b[pos]<<endl;
	}
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