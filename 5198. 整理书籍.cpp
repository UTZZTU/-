#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
string u;
int s[3],a[N],b[N],n,m,e[3][3];
int main ()
{
	cin>>u;
	n=u.size();
	for(int i=0;i<u.size();i++)
	{
		if(u[i]=='L') a[i+1]=0;
		else if(u[i]=='M') a[i+1]=1;
		else a[i+1]=2;
		s[a[i+1]]++;
	}
	for(int i=0,k=1;i<3;i++)
	{
		for(int j=1;j<=s[i];j++,k++)
		{
			b[k]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		e[a[i]][b[i]]++;
	}
	for(int i=0;i<3;i++)
	{
		m+=e[i][i];
	}
	for(int i=0;i<3;i++)
	{
		for(int j=i+1;j<3;j++)
		{
			int t=min(e[i][j],e[j][i]);
			m+=t;
			e[i][j]-=t,e[j][i]-=t;
		}
	}
	m+=e[1][0]+e[0][1];
	printf("%d",n-m);
	return 0;
}