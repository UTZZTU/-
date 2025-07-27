#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int tr[N+10],n,m,p,x,a[N+10];
int lowbit(int x)
{
	return x&-x;
}
void add(int u,int c)
{
	for(int i=u;i<=N;i+=lowbit(i)) tr[i]+=c;
}
int sum(int x)
{
	int res=0;
	for(int i=x;i;i-=lowbit(i)) res+=tr[i];
	return res;
}
bool check(int x)
{
	return sum(x)>=(n+1)/2;
}
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		add(a[i],1);
	}
	while(m--)
	{
		scanf("%d%d",&p,&x);
		add(a[p],-1);
		a[p]=x;
		add(a[p],1);
		int l=1,r=1e6;
		while(l<r)
		{
			int mid=l+r>>1;
			if(check(mid)) r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}