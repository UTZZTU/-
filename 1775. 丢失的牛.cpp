#include <bits/stdc++.h>
using namespace std;
int ans,k;
int main ()
{
	int x,y;
	cin>>x>>y;
	if(y>x)
	{
		k=1;
		while(1)
		{
			if(x+k>=y)
			{
				ans+=y-x;
				break;
			}
			else
			{
				ans+=2*k;
				k*=2;
				ans+=2*k;
				k*=2;
			}
		}
	}
	else if(y<x)
	{
		k=2;
		ans+=2;
		while(1)
		{
			if(x-k<=y)
		{
			ans+=x-y;
			break;
		}
		else
		{
			ans+=2*k;
			k*=2;
			ans+=2*k;
			k*=2;
		}
		}
	}
	cout<<ans;
	return 0;
}