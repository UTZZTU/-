#include <bits/stdc++.h>
using namespace std;
int fa[10010],select[10010],k,n,m,cx[10010],ls[10010];
struct people
{
	int num;
	int ts;
	int s;
}w[10010];
struct fp
{
	int zxbh,rs,sy;
	double ts,mj;
}q[10010];
int find(int x)
{
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
	return x;
}
set<int> p;
bool cmp(fp a,fp b)
{
	if(a.sy!=b.sy)
	return a.sy>b.sy;
	else if(a.mj!=b.mj)
	return a.mj>b.mj;
	else
	return a.zxbh<b.zxbh;
}
int main ()
{
	cin>>n;
	for(int i=0;i<=10000;i++)
    fa[i]=i;
    for(int i=1;i<=n;i++)
    {
    	int dad,mum;
    	scanf("%d",&w[i].num);
    	select[w[i].num]=i;
    	cx[w[i].num]=1;
    	scanf("%d %d %d",&dad,&mum,&k);
    	if(dad!=-1&&mum!=-1)
    	{
    		int eu=find(dad),ev=find(mum);
    		if(eu!=ev)
    		fa[ev]=eu;
		}
		if(!(dad==-1&&mum==-1))
		{
			if(dad==-1)
			{
				int eu=find(w[i].num),ev=find(mum);
				if(eu!=ev)
				fa[eu]=ev;
				cx[mum]=1;
			}
			else
			{
				cx[dad]=1;
				if(mum!=-1)
				cx[mum]=1;
				int eu=find(dad),ev=find(w[i].num);
				if(eu!=ev)
				fa[ev]=eu;
			}
		}
		for(int j=1;j<=k;j++)
		{
			scanf("%d",&ls[j]);
			if(ls[j]!=-1)
			{
				cx[ls[j]]=1;
			int eu=find(ls[j]),ev=find(w[i].num);
				if(eu!=ev)
				fa[eu]=ev;
			}
		}
		scanf("%d %d",&w[i].ts,&w[i].s);
	}
	for(int i=0;i<=10000;i++)
	{
		if(cx[i])
		{
			p.insert(find(i));
		}
	}
	for(int i=0;i<=10000;i++)
	{
		q[i].rs=0;
		q[i].sy=0;
		q[i].zxbh=0x3f3f3f3f;
		q[i].mj=0;
		q[i].ts=0;
	}
	for(int i=0;i<=10000;i++)
	{
		if(cx[i])
		{
			int eu=find(i);
			q[eu].sy=1;
			if(q[eu].zxbh==0x3f3f3f3f)
			q[eu].zxbh=i;
			q[eu].rs++;
			if(select[i]!=0)
			{
				q[eu].ts+=w[select[i]].ts;
				q[eu].mj+=w[select[i]].s;
			}
		}
	}
	for(auto it=p.begin();it!=p.end();it++)
	{
		q[*it].ts=q[*it].ts*1.0/q[*it].rs;
		q[*it].mj=q[*it].mj*1.0/q[*it].rs;
	}
	sort(q,q+10001,cmp);
	cout<<p.size()<<endl;
	for(int i=0;i<p.size();i++)
	printf("%04d %d %.3f %.3f\n",q[i].zxbh,q[i].rs,q[i].ts,q[i].mj);
	return 0;
}