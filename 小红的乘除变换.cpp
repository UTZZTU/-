#include <bits/stdc++.h>
using namespace std;
int t,x,y,pos,cnt,flag;
bool judge(int x,int &cnt)
{
	cnt=0;
	while(x%5==0)
	{
		x/=5;
		cnt++;
	}
	return x==1;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&x,&y);
		flag=pos=cnt=0;
		if(x==y)
		{
			puts("0");
			continue;
		}
		else if(x<y)
		{
			if(y%x==0)
			{
				if(judge(y/x,cnt))
				{
					flag=1;
				}
			}
			if(!flag)
			{
				while(x%6==0)
				{
					x/=6;
					pos++;
					if(y%x==0)
					{
						if(judge(y/x,cnt))
						{
							flag=1;
						}
					}
					if(flag) break;
				}
			}
		}
		else
		{
			while(x%6==0)
			{
				x/=6;
				pos++;
				if(y%x==0)
				{
					if(judge(y/x,cnt))
					{
						flag=1;
					}
				}
				if(flag) break;
			}
		}
		if(!flag)
		{
			puts("-1");
		}
		else
		{
			printf("%d\n",pos+cnt);
		}
	}
	return 0;
}