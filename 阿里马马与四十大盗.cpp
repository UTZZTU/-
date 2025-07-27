#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,f[100010],sum,cnt,rs;
bool judge()
{
	int res;
	for(int i=1;i<=n;i++)
	{
		res=0;
		if(f[i]==0) continue;
		int j=i;
		while(j<=n&&f[j])
		{
			res+=f[j];
			j++;
		}
		j--;
		if(res>=m) return true;
		i=j;
	}
	return false;
}
signed main ()
{
	scanf("%lld%lld",&n,&m);
	rs=m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&f[i]);
		cnt+=f[i];
	}
	if(judge())
	{
		cout<<"NO";
	}
	else
	{
		for(int i=2;i<=n;i++)
		{
			sum++;
			if(i==n) break;
			cnt-=f[i];
			if(f[i]==0)
			{
				if(m<=cnt)
				{
					sum+=rs-m;
					m=rs;
				}
			}
			else
			{
				m-=f[i];
			}
		}
		printf("%lld",sum);
	}
	return 0;
}