#include <bits/stdc++.h>
using namespace std;
string u,v;
int t,n;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		getchar();
		cin>>u>>v;
		int i=0;
		for(i;i<n&&u[i]==v[i];i++)
		;
		if(i==0)
		{
			if(u[i]<v[i])
			{
				cout<<2<<" "<<2<<endl;
			}
			else
			{
				cout<<1<<" "<<1<<endl;
			}
		}
		else
		{
			if(u[i]<v[i])
			{
				cout<<1<<" "<<1<<endl;
			}
			else
			{
				cout<<i+1<<" "<<i+1<<endl;
			}
		}
	}
	return 0;
}