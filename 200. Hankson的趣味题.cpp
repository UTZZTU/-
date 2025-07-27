#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 50010;
int primes[N],cnt,n,scnt,number[N],ncnt,res;
bool st[N];
void init(int n)
{
	st[1]=true;
	for(int i=2;i<=n;i++)
	{
		if(!st[i]) primes[cnt++]=i;
		for(int j=0;primes[j]*i<=n;j++)
		{
			st[primes[j]*i]=true;
			if(i%primes[j]==0) break;
		}
	}
}
struct node
{
	int num,cs;
}sl[2000];
int gcd(int a,int b)
{
	return b? gcd(b,a%b):a;
}
void dfs(int level,int p)
{
	if(level==scnt)
	{
		number[ncnt++]=p;
		return;
	 } 
	for(int i=0;i<=sl[level].cs;i++)
	{
		dfs(level+1,p);
		p*=sl[level].num;
	}
}
int main ()
{
	init(N-1);
	scanf("%d",&n);
	while(n--)
	{
		scnt=0;
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int t=d;
		for(int i=0;primes[i]<=t/primes[i];i++)
		{
			int p=primes[i];
			if(t%p==0)
			{
				int s=0;
				while(t%p==0) t/=p,s++;
				sl[scnt++]={p,s};
			}
		}
		if(t>1)
		sl[scnt++]={t,1};
		ncnt=0,res=0;
		dfs(0,1);
		for(int i=0;i<ncnt;i++)
		{
			if(gcd(a,number[i])==b&&(ll)c*number[i]/gcd(c,number[i])==d)
			res++;
		}
		printf("%d\n",res);
	}
	return 0;
}