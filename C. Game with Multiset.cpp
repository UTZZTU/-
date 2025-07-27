#include <bits/stdc++.h>
using namespace std;
int m,t,v,f[100];
void solve()
{
	cin>>m;
	while(m--)
	{
		cin>>t>>v;
		if(t==1)
		{
			f[v]++;
//			while(v<=50&&f[v]>=2)
//			{
//				f[v]-=2;
//				v++;
//				f[v]++;
//			}
		}
		else
		{
			for(int i=29;i>=0;i--)
			{
				int x=pow(2,i);
				for(int j=1;j<=f[i];j++)
				{
					if(v>=x) v-=x;
					else break;
				}
			}
			if(!v) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	while(t--)
	{
		solve();
	}
}