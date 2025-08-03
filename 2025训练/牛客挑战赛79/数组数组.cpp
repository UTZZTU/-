#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}());
int n,f[200010],res; 
void solve()
{
	cin>>n;
	res=1;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		res*=f[i];
	}
	if(res==1) cout<<"Alice"<<endl;
	else 
	{
		int res=0,cnt=0,p=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i]==1) cnt++;
			else
			{
				p++;
				if(cnt)
				{
					cnt=0;
					res++;
				}
			}
		}
		if(cnt) res++;
		if(n==1&&p==n) cout<<"Bob"<<endl;
		else if(p==n)  cout<<"Alice"<<endl;
		else
		{
			if(p==1&&n&1&&f[n+1>>1]==-1) cout<<"Bob"<<endl;
			else cout<<"Alice"<<endl;
		}
	}
}
//  xxx-1xxx只有这种A才会输，其余都是B输
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}