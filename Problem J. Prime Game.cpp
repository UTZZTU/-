#include <bits/stdc++.h>
using namespace std;
//#define int long long
typedef long long ll;
const int N = 1e6+10;
int mp[N];
int n,a[N],vis[N];
ll res;
bool st[N];
int cnt,primes[N];
void init(int x)
{
	st[1]=true;
	for(int i=2;i<=1000000;i++)
	{
		if(!st[i]) primes[cnt++]=i;
		for(int j=0;primes[j]*i<=1000000;j++)
		{
			st[primes[j]*i]=true;
			if(i%primes[j]==0)
			break;
		}
	}
}
int main ()
{
//	init(1000000);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for(int j=2;j*j<=a[i];j++)
		{
			if(a[i]%j==0)
			{
				while(a[i]%j==0)
				{
					a[i]/=j;
				}
				res+=(ll)(i-mp[j])*(n-i+1);
				mp[j]=i;
			}
		}
		if(a[i]>1)
		{
			res+=(ll)(i-mp[a[i]])*(n-i+1);
			mp[a[i]]=i;
		}		
	}
	printf("%lld",res);
	return 0;
}