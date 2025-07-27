#include <bits/stdc++.h>
using namespace std;
int f[110],t,n,flag;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>f[i];
		}
		if(f[1]&1)
		{
			cout<<0<<endl;
		}
		else
		{
			flag=0;
			for(int i=2;i<=n;i++)
			{
				if(f[1]>f[i]&&f[i]&1)
				{
					cout<<1<<endl;
					flag=1;
					break;
				}
			}
			if(!flag)
			cout<<-1<<endl;
		}
	}
	return 0;
}