#include <bits/stdc++.h>
using namespace std;
int t,n,f[1000010][2],maxx;
string u;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>u;
		maxx=0;
		for(int i=0;i<n;i++)
		{
			if(u[i]=='0')
			{
				f[i+1][0]=f[i][0]+1;
				f[i+1][1]=0;
				maxx=max(maxx,f[i+1][0]);
			}
			else if(u[i]=='1')
			{
				f[i+1][1]=f[i][1]+1;
				f[i+1][0]=0;
				maxx=max(maxx,f[i+1][1]);
			}
			else
			{
				f[i+1][0]=f[i][0]+1;
				maxx=max(maxx,f[i+1][0]);
				f[i+1][1]=f[i][1]+1;
				maxx=max(maxx,f[i+1][1]);
			}
		}
		cout<<maxx<<endl;
	}
	return 0;
}