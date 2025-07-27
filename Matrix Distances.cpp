#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,cnt;
struct node
{
	int num,op,pos;
}s[2000100];
bool cmp(node x,node y)
{
	if(x.num!=y.num) return x.num<y.num;
	else if(x.op!=y.op) return x.op<y.op;
	else return x.pos<y.pos;
}
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&k);
			s[++cnt].num=k;
			s[cnt].op=0;
			s[cnt].pos=i;
			s[++cnt].num=k;
			s[cnt].op=1;
			s[cnt].pos=j;
		}
	}
	sort(s+1,s+1+cnt,cmp);
//	for(int i=1;i<=cnt;i++)
//	{
//		cout<<s[i].num<<" "<<s[i].op<<" "<<s[i].pos<<endl;
//	}
	ll sum=0;
	for(int i=1;i<=cnt;i++)
	{
		int j=i+1;
		ll x=0,y=1;
		while(j<=cnt&&s[i].num==s[j].num&&s[i].op==s[j].op)
		{
			j++;
			y++;
		}
		j--;
		int k=i+1;
		x++,y--;
		while(k<=j)
		{
			if(s[k].pos==s[k-1].pos)
			{
				x++,y--;
			}
			else
			{
				sum+=x*y*((ll)s[k].pos-s[k-1].pos);
				x++,y--;
			}
			k++;
		}
		i=j;
	}
	printf("%lld",sum*2ll);
	return 0;
}
/*
2 2
1 1
2 2


1 0 1
1 0 1
1 1 1
1 1 2
2 0 2
2 0 2
2 1 1
2 1 2

4 4
1 3 2 4
2 1 2 3
1 3 3 2
3 2 1 4
*/