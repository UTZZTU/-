#include <bits/stdc++.h>
using namespace std;
int n,f[100010],sum1,sum2;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
	}
	int l=1,r=n,res1=0,res2=0;
	while(l<=r)
	{
		if(res1<=res2)
		{
			res1+=f[l];
			sum1++;
			l++;
		}
		else 
		{
			res2+=f[r];
			sum2++;
			r--;
		}
	}
	cout<<sum1<<" "<<sum2<<endl;
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