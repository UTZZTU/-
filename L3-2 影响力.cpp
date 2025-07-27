#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
vector<ll> vec[1010],pp[1010];
int main ()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			ll x;
			cin>>x;
			vec[i].push_back(x);
			pp[i].push_back(0);
//			pp[i][j]=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k1=0;k1<n;k1++)
			{
				for(int k2=0;k2<m;k2++)
				{
					if(k1==i&&k2==j) continue;
					pp[i][j]+=(ll)max(abs(k1-i),abs(k2-j))*vec[i][j];
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(j!=0) cout<<" ";
			cout<<pp[i][j];
		}
		cout<<endl;
	}
	return 0;
}
