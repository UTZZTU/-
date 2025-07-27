#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int primes[N],cnt,f[N],n,k,id;
bool st[N];
void init(int x)
{
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
	init(N-10);
	memset(f,-1,sizeof(f));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&id);
		f[id]=i;
	}
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d",&id);
		if(f[id]==-2)
		{
			printf("%04d: Checked\n",id);
		}
		else if(f[id]==-1)
		{
			printf("%04d: Are you kidding?\n",id);
		}
		else if(f[id]==1)
		{
			printf("%04d: Mystery Award\n",id);
			f[id]=-2;
		}
		else if(!st[f[id]])
		{
			printf("%04d: Minion\n",id);
			f[id]=-2;
		}
		else
		{
			printf("%04d: Chocolate\n",id);
			f[id]=-2;
		}
	}
	return 0;
}