#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
	ll time,type,x;
}s[1010];
ll f[10]={-1},h1,h2,m,mm,ss,type,sum,flag;
int main ()
{
	scanf("%lld%lld%lld",&h1,&h2,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld:%lld %lld",&mm,&ss,&type);
		s[i].time=mm*60+ss;
		s[i].type=type;
		if(type==3)
		scanf("%lld",&s[i].x);
	}
	sum=h1;
	for(int i=1;i<=m;i++)
	{
		if(s[i].type==2)
		{
			sum+=h2;
		}
		else if(s[i].type==1)
		{
			sum+=800;
			flag=1;
		}
		else
		{
			if(flag)
			{
				if(f[s[i].x]==-1||s[i].time-f[s[i].x]>=30)
				{
					sum+=floor((125+(double)sum*0.06)*0.1);
					f[s[i].x]=s[i].time;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}