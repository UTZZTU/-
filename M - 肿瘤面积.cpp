#include <bits/stdc++.h>
using namespace std;
int k,s,x,z,y,n;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&k);
			if(!k)
			{
				if(!s)
				s=i;
				else
				s=min(s,i);
				if(!x)
				x=i;
				else
				x=max(x,i);
				if(!z)
				z=j;
				else
				z=min(z,j);
				if(!y)
				y=j;
				else
				y=max(y,j);
			}
		}
	}
	if(n==1)
	cout<<0<<endl;
	else
	cout<<(x-s-1)*(y-z-1);
	return 0;
}