#include <bits/stdc++.h>
using namespace std;
int n,a[100010],g[100010],pd,f;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	scanf("%d",&g[i]);
	for(int i=1;i<n;i++)
	{
		if(a[i]<=g[i+1])
		{
		pd=1;
		break;
		}
	}
	if(!pd)
	{
		cout<<"Yes";
	}
	else
	{
		pd=0;
		for(int i=n;i>1;i--)
	{
		if(a[i]<=g[i-1])
		{
		pd=1;
		break;
		}
	}
	if(!pd)
	{
		cout<<"Yes";
	}
	else
	{
		pd=0;
		for(int i=2;i<n;i++)
		{
		    if(!f)
		    {
		    	if(a[i]<=g[i-1])
		    	{f=1;
		    	if(a[i]<=g[i+1])
		    	{
		    		pd=1;
		    		break;
				}
				}
			}
			else
			{
				if(a[i]<=g[i+1])
				{
					pd=1;
					break;
				}
			}
		}
		if(!pd)
		cout<<"Yes";
		else
		cout<<"No";
	}
	}
	return 0;
}