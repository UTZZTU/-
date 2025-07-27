#include <bits/stdc++.h>
using namespace std;
map<int,int> mp1,mp2;
int m,op,x,tt1,tt2;
int main ()
{
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&op,&x);
		if(op==1)
		{
			if(x<0)
			{
				tt1++;
				x*=-1;
			}
			for(int j=2;j*j<=x;j++)
			{
				if(x%j==0)
				{
					while(x%j==0)
					{
						x/=j;
						mp1[j]++;
					}
				}
			}
			if(x>1) mp1[x]++;
		}
		else
		{
			if(x<0)
			{
				tt1++;
				x*=-1;
			}
			for(int j=2;j*j<=x;j++)
			{
				if(x%j==0)
				{
					while(x%j==0)
					{
						x/=j;
						mp1[j]--;
					}
				}
			}
			if(x>1) mp1[x]--;
		}
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&op,&x);
		if(op==1)
		{
			if(x<0)
			{
				tt2++;
				x*=-1;
			}
			for(int j=2;j*j<=x;j++)
			{
				if(x%j==0)
				{
					while(x%j==0)
					{
						x/=j;
						mp2[j]++;
					}
				}
			}
			if(x>1) mp2[x]++;
		}
		else
		{
			if(x<0)
			{
				tt2++;
				x*=-1;
			}
			for(int j=2;j*j<=x;j++)
			{
				if(x%j==0)
				{
					while(x%j==0)
					{
						x/=j;
						mp2[j]--;
					}
				}
			}
			if(x>1) mp2[x]--;
		}
	}
	int flag1=1,flag2=1,u,v;
	for(auto it=mp1.begin();it!=mp1.end();it++)
	{
		u=it->first,v=it->second;
		if(mp2[u]!=v)
		{
			flag1=0;
			break;
		}
	}
	for(auto it=mp2.begin();it!=mp2.end();it++)
	{
		u=it->first,v=it->second;
		if(mp1[u]!=v)
		{
			flag2=0;
			break;
		}
	}
	if(flag1&&flag2&&(tt1%2==tt2%2)) printf("YES");
	else printf("NO");
	return 0;
}