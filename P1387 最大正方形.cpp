#include <iostream>
using namespace std;
int a[105][105];
int s[105][105];
int main ()
{
	int n,m,i,j,pd=0,q,t;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==1)
			s[i][j]=s[i-1][j]+s[i][j-1]+1-s[i-1][j-1];
			else
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}
	}
	q=min(n,m);
	while(pd==0)
	{
		for(i=q;i<=n;i++)
		{
			for(j=q;j<=m;j++)
			{
				t=s[i][j]-s[i-q][j]-s[i][j-q]+s[i-q][j-q];
				if(t==q*q)
				{
					pd=1;
					break;
				}
			}
			if(pd==1)
			break;
		}
		if(pd==1)
		break;
		else
		q--;
	}
	printf("%d",q);
	return 0;
}