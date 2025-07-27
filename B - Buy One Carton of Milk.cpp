#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,s,m,l,minn=0x3f3f3f3f;
signed main ()
{
	cin>>n>>s>>m>>l;
	for(int i=0;i<=50;i++)
	{
		for(int j=0;j<=50;j++)
		{
			for(int k=0;k<=50;k++)
			{
				if(6*i+8*j+12*k>=n)
				{
					minn=min(minn,i*s+j*m+k*l);
				}
			}
		}
	}
	cout<<minn;
	return 0;
}