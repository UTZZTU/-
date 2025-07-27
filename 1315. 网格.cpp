#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int primes[N],cnt;
bool st[N];
int a[N],b[N],n,m;
int get(int n,int p)
{
	int res=0;
	while(n) res+=n/p,n/=p;
	return res;
}
void init(int x)
{
	st[1]=true;
	for(int i=2;i<=x;i++)
	{
		if(!st[i]) primes[cnt++]=i;
		for(int j=0;primes[j]*i<=x;j++)
		{
			st[primes[j]*i]=true;
			if(i%primes[j]==0) break;
		}
	}
}
void mul(int r[],int p,int &len)
{
	int t=0;
	for(int i=0;i<len;i++)
	{
		t+=r[i]*p;
		r[i]=t%10;
		t/=10;
	}
	while(t) r[len++]=t%10,t/=10;
}
void sub(int a[],int al,int b[],int bl)
{
	for(int i=0,t=0;i<al;i++)
	{
		a[i]-=t+b[i];
		if(a[i]<0) a[i]+=10,t=1;
		else t=0;
	}
}
int C(int a,int b,int r[])
{
	r[0]=1;
	int len=1;
	for(int i=0;i<cnt;i++)
	{
		int p=primes[i];
		int s=get(a,p)-get(b,p)-get(a-b,p);
		while(s--)
		{
			mul(r,p,len);
		}
	}
	return len;
}
int main ()
{
	init(10000);
	cin>>n>>m;
	int al=C(n+m,m,a);
	int bl=C(n+m,m-1,b);
	sub(a,al,b,bl);
	int s=al-1;
	while(s>0&&!a[s]) s--;
	while(s>=0) printf("%d",a[s--]);
	return 0;
}