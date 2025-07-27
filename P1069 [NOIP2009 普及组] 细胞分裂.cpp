#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int primes[N],cnt,a[10010],m1,m2,n,scnt,minn=0x3f3f3f3f,flag;
map<int,int>mp;
bool st[N];
struct node
{
	int p,pos;
}s[10010];
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
	init(1e6);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=2;i*i<=m1;i++)
	{
		if(m1%i==0)
		{
			int t=0;
			while(m1%i==0) m1/=i,t++;
			s[++scnt].p=i;
			s[scnt].pos=t*m2;
		}
	}
	if(m1>1)
	{
		s[++scnt].p=m1;
		s[scnt].pos=m2;
	}
	for(int i=1;i<=n;i++)
	{
		int judge=0,t=0,tt,c;
		for(int j=1;j<=scnt;j++)
		{
			c=0;
			if(a[i]%s[j].p!=0)
			{
				judge=1;
				break;
			}
			tt=a[i];
			while(tt%s[j].p==0)
			{
				tt/=s[j].p;
				c++;
			}
			c=ceil(s[j].pos*1.0/c);
			t=max(t,c);
		}
		if(!judge)
		{
			flag=1;
			minn=min(minn,t);
		}
	}
	if(flag)
	cout<<minn;
	else
	cout<<-1;
	return 0;
}