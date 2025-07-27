#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 100010
int bit[maxn],ans[maxn],n;
struct node
{
	int s,e,id;
}cow[maxn];
 
int cmp(node a,node b)
{
	if(a.e==b.e)
		return a.s<b.s;
	return a.e>b.e;
}
 
int sum(int x)
{
	int cnt=0;
	while(x>0)
	{
		cnt+=bit[x];
		x-=(x&-x);
	}
	return cnt;
}
 
void add(int x)
{
	while(x<maxn)
	{
		bit[x]+=1;
		x+=(x&-x);
	}
}
 
int main()
{
	int i;
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;++i)
		{
			scanf("%d%d",&cow[i].s,&cow[i].e);
			cow[i].s++;//因为s的值可以为0，防止0的出现 
			cow[i].id=i;//保存初始位置 
		}
		sort(cow,cow+n,cmp);
		memset(ans,0,sizeof(ans));
		memset(bit,0,sizeof(bit));
		ans[cow[0].id]=0;//排完序的第一个牛 
		add(cow[0].s);
		for(i=1;i<n;++i)
		{
			if(cow[i].s==cow[i-1].s&&cow[i].e==cow[i-1].e)//两个牛区间完全相同 
				ans[cow[i].id]=ans[cow[i-1].id];
			else
				ans[cow[i].id]=sum(cow[i].s);
			add(cow[i].s);
		}
		for(i=0;i<n-1;++i)
			printf("%d ",ans[i]);
		printf("%d\n",ans[i]);
	}
	return 0;
}