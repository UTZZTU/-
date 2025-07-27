#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,k,xx,yy,maxx;
string u;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		getchar();
		cin>>u;
		xx=yy=0;
		maxx=0;
		for(int i=0;i<n;i++)
		{
			if(u[i]=='L')
			{
				xx--;
			}
			else if(u[i]=='R')
			{
				xx++;
			}
			else if(u[i]=='U')
			{
				yy++;
			}
			else
			{
				yy--;
			}
			maxx=max(maxx,abs(xx)+abs(yy));
		}
		xx*=(k-1),yy*=(k-1);
		for(int i=0;i<n;i++)
		{
			if(u[i]=='L')
			{
				xx--;
			}
			else if(u[i]=='R')
			{
				xx++;
			}
			else if(u[i]=='U')
			{
				yy++;
			}
			else
			{
				yy--;
			}
			maxx=max(maxx,abs(xx)+abs(yy));
		}
		cout<<maxx<<endl;
	}
	return 0;
}