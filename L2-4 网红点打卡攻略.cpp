#include <iostream>
using namespace std;
int p[210][210];
int main ()
{
	int n,m,i,a,b,c,k,j;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
		if(p[a][b]==0)
		{
				p[a][b]=c;
				p[b][a]=c;
		}
	
		else
		{
			if(c<p[a][b])
			{
				p[a][b]=c;
				p[b][a]=c;
			}
			
		}
	}
	cin>>k;
	int zhf=10000000,fhf,cs[1010],sum=0,wz,pd[210],zd=0;
	for(i=1;i<=k;i++)
	{
		memset(pd,0,sizeof(pd));
		zd=0;
		fhf=0;
		cin>>m;
		for(j=1;j<=m;j++)
		{
			cin>>cs[j];
		}
		if(p[0][cs[1]]==0)
		continue;
		fhf+=p[0][cs[1]];
		for(j=1;j<m;j++)
		{
			if(p[cs[j]][cs[j+1]]==0)
			break;
			else
			{
				fhf+=p[cs[j]][cs[j+1]];
				pd[cs[j]]++;
			}
		}
		if(j!=m)
		continue;
		if(p[cs[m]][0]!=0)
		{
			pd[cs[m]]++;
			for(j=1;j<=n;j++)
			{
				if(pd[j]!=1)
				{
					zd=1;
					break;
				}
			}
			if(zd==0)
			{
				fhf+=p[cs[m]][0];
			sum++;
			if(fhf<zhf)
			{
				zhf=fhf;
				wz=i;
			}
			}
			
		}
	}
	printf("%d\n",sum);
	printf("%d %d",wz,zhf);
	return 0;
}