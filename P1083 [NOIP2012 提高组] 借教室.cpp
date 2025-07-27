#include <stdio.h>
#include <string.h>
int a[1000010],s[1000010],ks[1000010],js[1000010],sj[1000010],q[1000010],n;
bool check(int x)
{
	memset(s,0,sizeof(s));
	int i;
	for(i=1;i<=x;i++)
	{
		s[ks[i]]+=sj[i];
		s[js[i]+1]-=sj[i];
	}
	for(i=1;i<=n;i++)
	{
		q[i]=q[i-1]+s[i];
		if(q[i]>a[i])
		return 0;
	}
	return 1;
}
int main ()
{
	int m,i,k,begin,end;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
	scanf("%d %d %d",&sj[i],&ks[i],&js[i]);
	begin=1;
	end=m;
	if(check(m))
	{
		printf("0");
		return 0;
	}
	while(begin<end)
	{
		int mid=(begin+end)/2;
		if(check(mid))begin=mid+1;
		else
		end=mid;
	}
	printf("-1\n");
	printf("%d",begin);
	return 0;
}