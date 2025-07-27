#include <bits/stdc++.h>
using namespace std;
int t,n;
string u;
int main ()
{
	cin>>t;
	while(t--)
	{
		int maxx=0,sum=0;
		cin>>n;
		getchar();
		cin>>u;
		for(int i=0;i<u.size();i++)
		{
			if(u[i]=='1')
			{
				maxx=max(maxx,sum);
				sum=0;
			}
			else
			sum++;
		}
		maxx=max(maxx,sum);
		sum=0;
		for(int i=0;i<u.size();i++)
		{
			if(u[i]=='0')
			{
				maxx=max(maxx,sum);
				sum=0;
			}
			else
			sum++;
		}
		maxx=max(maxx,sum);
		printf("%d\n",maxx);
	}
	return 0;
}