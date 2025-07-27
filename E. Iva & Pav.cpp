#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[200010],q,l,k,f[200010][35];
bool check(int l,int r,int k)
{
	int res=0,p=1;
	for(int i=0;i<30;i++)
	{
		if(f[r][i]-f[l-1][i]==r-l+1) res+=p;
		p*=2;
	}
	return res>=k;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int x=a[i];
		for(int j=0;j<30;j++)
		{
			if(((x>>j)&1))
			{
				f[i][j]=1;
			}
			else
			{
				f[i][j]=0;
			}
			f[i][j]+=f[i-1][j];
		}
	}
	cin>>q;
	vector<int> vec;
	while(q--)
	{
		cin>>l>>k;
		if(a[l]<k) vec.push_back(-1);
		else
		{
			int ll=l,rr=n;
			while(ll<rr)
			{
				int mid=ll+rr+1>>1;
				if(check(l,mid,k)) ll=mid;
				else rr=mid-1;
			}
			vec.push_back(ll);
		}
	}
	for(auto x:vec) cout<<x<<" ";
	cout<<endl;
	
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}