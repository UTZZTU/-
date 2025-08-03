#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,a[100010],b,k;
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	while(q--)
	{
		cin>>b>>k;
		int l=0,r=1e9;
		while(l<r)
		{
			int mid=l+r>>1;
			int pos1=lower_bound(a+1,a+1+n,b-mid)-a;
			int pos2=upper_bound(a+1,a+1+n,b+mid)-a;
			if(pos2-pos1>=k)
			{
				r=mid;
			}
			else l=mid+1;
		}
		cout<<l<<endl;
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