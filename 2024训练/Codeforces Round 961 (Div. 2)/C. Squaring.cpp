#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,res,f[200010],flag,tt,sc[200010];
//double p[200010];
void solve()
{
	cin>>n;
	flag=0;
	tt=0;
	res=0;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		if(f[i]==1&&flag)
		{
			tt=1;
		}
		if(f[i]>1) flag=1;
		sc[i]=0;
	}
	if(tt)
	{
		cout<<-1<<endl;
		return;
	}
	int i=1;
	while(i<=n&&f[i]==1)
	{
		i++;
	}
	for(int j=i;j<=n;j++)
	{
//		p[j]=(double)log(1.0*f[j])/log(2.0);
//		p[j]=log(1.0*p[j])*1.0/log(2.0);
		if(j>i)
		{
			if(f[j]>f[j-1])
			{
				ll pre=f[j-1];
				while(pre<f[j])
				{
//					if(p[j]-pre<0.00000001) break;
					pre=pre*pre;
					sc[j]--;
					if(pre==f[j])
					{
//						sc[j]++;
						break;
					}
					else if(pre>f[j])
					{
						sc[j]++;
						break;
					}
				}
			}
			else
			{
				ll now=f[j];
				while(now<f[j-1])
				{
//					if(p[j-1]-now<0.00000001) break;
					now=now*now;
					sc[j]++;
				}
			}
//			cout<<p[j]<<" ";
		}
	}
//	cout<<endl;
	ll cs=0;
	for(int j=i+1;j<=n;j++)
	{
		cs+=sc[j];
		if(cs<0) cs=0;
		res+=cs;
//		cout<<cs<<" ";
	}
//	cout<<endl;
	cout<<res<<endl;
}
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