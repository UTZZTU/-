#include <bits/stdc++.h>
using namespace std;
int f[10],n,a,b;
int main ()
{
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		if(a==0)
		{
			int maxx=max(f[b],f[b+1]);
			f[b]=maxx+3,f[b+1]=maxx+1;
		}
		else if(a==90)
		{
			int maxx=max(f[b+1],f[b+2]);
			if(maxx>=f[b]+1)
			{
				f[b]=f[b+1]=f[b+2]=maxx+1;
			}
			else
			{
				f[b+1]=f[b+2]=f[b]+2;
				f[b]+=2;
			}
		}
		else if(a==180)
		{
			if(f[b]>=f[b+1]+2)
			{
				f[b]=f[b+1]=f[b]+1;
			}
			else
			{
				f[b]=f[b+1]=f[b+1]+3;
			}
		}
		else
		{
			int maxx=max(f[b],max(f[b+1],f[b+2]));
			f[b]=maxx+1,f[b+1]=maxx+1,f[b+2]=maxx+2;
		}
	}
	for(int i=1;i<=8;i++)
	printf("%d ",f[i]);
	return 0;
}