#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string.h>
using namespace std;
int a[60],b[60];
int main ()
{
    int n,i,k,mx=0,js=0,wz,q=-1,h=-1,pd2=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
    	cin>>k;
    	if(k&1)
    	{
    		a[1+(k-1)/2]=1;
		}
    	else
    	b[k/2]=1;	
	}
	for(i=1;i<=50;i++)
	{
		if(a[i]==1&&h==-1)
		continue;
		else if(a[i]==1&&h!=-1)
		{
			q=h;
			h=i-1;
			if(h-q>mx)
			{
				mx=h-q;
				wz=q;
			}
			q=-1;
			h=-1;
			js=0;
		}
		else if(a[i]==0&&h==-1)
		{
			h=i;
			js++;
		}
		else
		{
			js++;
			if(i==50&&js!=0)
			{
				q=h;
			h=50;
			if(h-q>mx)
			{
				mx=h-q;
				wz=q;
			}
			q=-1;
			h=-1;
			js=0;
			}
		}
	}
	q=-1;
			h=-1;
			js=0;
	for(i=1;i<=50;i++)
	{
		if(b[i]==1&&h==-1)
		continue;
		else if(b[i]==1&&h!=-1)
		{
			q=h;
			h=i-1;
			if(h-q>mx)
			{
				mx=h-q;
				wz=q;
				pd2=1;
			}
			q=-1;
			h=-1;
			js=0;
		}
		else if(b[i]==0&&h==-1)
		{
			h=i;
			js++;
		}
		else
		{
			js++;
			if(i==50&&js!=0)
			{
				q=h;
			h=50;
			if(h-q>mx)
			{
				mx=h-q;
				wz=q;
				pd2=1;
			}
			q=-1;
			h=-1;
			js=0;
			}
		}
	}
	if(pd2==0)
	printf("%d %d",(wz-1)*2+1,mx+1);
	else
	printf("%d %d",wz*2,mx+1);
	return 0;
}