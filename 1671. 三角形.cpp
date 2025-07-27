#include <bits/stdc++.h>
using namespace std;
int x[110],y[110];
double s=0;
int hc,sc;
int main ()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	scanf("%d %d",&x[i],&y[i]);
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+1;j<=n-1;j++)
	    {
	    	for(int k=j+1;k<=n;k++)
	    	{
	    		int pd1=0,pd2=0;
	    		if(y[i]==y[j])
	    		{
	    			pd1=1;
	    			hc=abs(x[i]-x[j]);
				}
				if(y[i]==y[k])
	    		{
	    			pd1=1;
	    			hc=abs(x[i]-x[k]);
				}
				if(y[k]==y[j])
	    		{
	    			pd1=1;
	    			hc=abs(x[k]-x[j]);
				}
				if(x[i]==x[j])
	    		{
	    			pd2=1;
	    			sc=abs(y[i]-y[j]);
				}
				if(x[i]==x[k])
	    		{
	    			pd2=1;
	    			sc=abs(y[i]-y[k]);
				}
				if(x[k]==x[j])
	    		{
	    			pd2=1;
	    			sc=abs(y[k]-y[j]);
				}
				if(pd1+pd2==2)
				{
					s=max(s,hc*sc*1.0/2);
				}
			}
		}
	}
	int u=s*2;
	printf("%d",u);
	return 0;
}