#include <stdio.h>
#include <algorithm>
using namespace std;
struct number
{
	int ch;
	int ma;
	int en;
	int ph;
	int sum;
	int num;
}w[100010];
bool cmp(number a,number b)
{
	if(a.sum>b.sum)
	return true;
	else if(a.sum<b.sum)
	return false;
	else
	{
		if(a.ma>b.ma)
		return true;
		else if(a.ma<b.ma)
		return false;
		else
		{
			if(a.ph>b.ph)
			return true;
			else if(a.ph<b.ph)
			return false;
			else
			{
				if(a.ch>b.ch)
				return true;
				else if(a.ch<b.ch)
				return false;
				else
				{
					if(a.num<b.num)
					return true;
					else
					return false;
				}
			}
			
		}
	}
}
int main ()
{
	int n,a,b,i;
	scanf("%d%d%d",&n,&a,&b);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d %d %d",&w[i].ch,&w[i].ma,&w[i].en,&w[i].ph);
		w[i].sum=w[i].ch+w[i].ma+w[i].en+w[i].ph;
		w[i].num=i;
	}
	sort(w+1,w+n+1,cmp);
	for(i=a;i<b;i++)
	{
		printf("%d %d\n",w[i].num,w[i].sum);
	}
	printf("%d %d",w[b].num,w[b].sum);
	return 0;
}
