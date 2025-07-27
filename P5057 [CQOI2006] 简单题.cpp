#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int tr[N],n,m,l,r,idx,op;
int lowbit(int x)
{
	return x & -x;
}
void add(int u,int c)
{
	for(int i=u;i<=n;i+=lowbit(i)) tr[i]+=c;
}
int sum(int u)
{
	int res=0;
	for(int i=u;i;i-=lowbit(i)) res+=tr[i];
	return res;
}
int main ()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&l,&r);
			add(l,1);
			add(r+1,-1);
		}else
		{
			scanf("%d",&idx);
			printf("%d\n",sum(idx)%2);
		}
	}
	return 0;
}