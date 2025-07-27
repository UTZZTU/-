#include <bits/stdc++.h>
using namespace std;
int f[1010],cnt,n,m;
int main ()
{
	cin>>n;
	while(n--)
	{
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>f[i];
		}
		cnt=0;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				for(int k=1;k<=m;k++)
				{
					if(f[i]+f[j]==f[k])
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}