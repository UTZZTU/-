#include <bits/stdc++.h>
using namespace std;
int n,m;
int main ()
{
	cin>>n>>m;
	if(m>2*n+2||m<n-1)
	cout<<"-1";
	else
	{
		if(m==n-1)
		{
			for(int i=1;i<=n-1;i++)
			printf("01");
			printf("0");
		}
		else
		{
			while(m>n&&m>0&&n>0)
			{
				printf("110");
				m-=2,n-=1;
			}
			if(n==0)
			{
				for(int i=1;i<=m;i++)
				printf("1");
			}
			else
			{
				for(int i=1;i<=n;i++)
				printf("10");
			}
		}
	}
	return 0;
}