#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e18;
const int N = 1e5+5;
int n,q,b,x,k,tp[N],num[N];
__int128 len[N];
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>b>>x;
		if(b==1)
		{
			tp[i]=1;
			num[i]=x;
			len[i]=len[i-1]+1;
		}
		else
		{
			tp[i]=2;
			len[i]=len[i-1]*(x+1);
			if(len[i]>M) len[i]=M+1;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>k;
		for(int j=lower_bound(len+1,len+1+n,k)-len;j>0;j=lower_bound(len+1,len+1+j,k)-len)
		{
			if(tp[j]==2)
			{
				k%=len[j-1];
				if(k==0) k=len[j-1];
			}
			else
			{
				if(k==len[j])
				{
					cout<<num[j]<<" ";
					break;
				}
				else j--;
			}
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
	return 0;
}