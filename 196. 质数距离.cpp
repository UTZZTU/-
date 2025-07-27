#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool st[1000010];
int primes[1000010],cnt,l,u;
void init(int x)
{
	memset(st,0,sizeof(st));
	cnt=0;
	st[1]=true;
	for(int i=2;i<=x;i++)
	{
		if(!st[i]) primes[cnt++]=i;
		for(int j=0;primes[j]*i<=x;j++)
		{
			st[primes[j]*i]=true;
			if(i%primes[j]==0)
			break;
		}
	}
}
int main ()
{
	while(scanf("%d %d",&l,&u)!=EOF)
	{
		init(50000);
		memset(st,0,sizeof(st));
		for(int i=0;i<cnt;i++)
		{
			ll p=primes[i];
			for(ll j=max(2*p,(l+p-1)/p*p);j<=u;j+=p)
			{
				st[j-l]=true;
			}
		}
		cnt=0;
		for(int i=0;i<=u-l;i++)
		{
			if(!st[i]&&i+l!=1)
			primes[cnt++]=i+l;
		}
		if(cnt<2)
		{
			printf("There are no adjacent primes.\n");
		}
		else
		{
			int maxx=0,minn=0x3f3f3f3f,dx,dy;
			for(int i=0;i<cnt-1;i++)
			{
				if(primes[i+1]-primes[i]<minn) minn=primes[i+1]-primes[i],dx=i;
				if(primes[i+1]-primes[i]>maxx) maxx=primes[i+1]-primes[i],dy=i;
			}
			printf("%d,%d are closest, %d,%d are most distant.\n",primes[dx],primes[dx+1],primes[dy],primes[dy+1]);
		}
	}
	return 0;
}