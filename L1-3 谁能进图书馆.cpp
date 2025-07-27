#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
struct p
{
    int a,b;
}u[100010];
bool cmp(p x,p y)
{
    return x.a<y.a;
}
int main ()
{
    int n,k,s,a[100010],sum=0,i,q,h;
    memset(a,0,sizeof(a));
    cin>>n>>k>>s;
    for(i=1;i<=n;i++)
    {
    	
    	scanf("%d %d",&u[i].a,&u[i].b);
	}
	sort(u+1,u+1+n,cmp);
	while(k--)
	{
		int qz=-1;
		for(i=1;u[i].a<175||a[i]==1;i++)
		;
		for(i;i<=n;i++)
		{
			if(a[i]==1)
			continue;
			else
			{
				if(u[i].a>=175)
				{
					if(q==-1)
					{
						sum++;
						qz=u[i].a;
						a[i]=1;
					}
					else
					{
						if(u[i].a==qz)
						{
							if(u[i].b>=s)
							{
								sum++;
								a[i]=1;
							}
						}
						else
						{
							qz=u[i].a;
							sum++;
							a[i]=1;
						}
					}
				}
			}
		}
	}
	printf("%d",sum);
	return 0;
}