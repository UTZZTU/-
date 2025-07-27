#include <bits/stdc++.h>
using namespace std;
int n,m,maxx;
string a[1010];
int main ()
{
	cin>>n>>m;
	getchar();
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='#')
			{
				maxx=max(maxx,i+j);
			maxx=max(maxx,n-1-i+m-1-j);
			maxx=max(maxx,n-1-i+j);
			maxx=max(maxx,i+m-1-j);
			}
		}
	}
	cout<<maxx;
	return 0;
}