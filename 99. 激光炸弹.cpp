#include <bits/stdc++.h>
using namespace std;
int n,r,x,y,w,pos[5010][5010],maxx;
int main ()
{
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		pos[x+1][y+1]+=w;
	}
	for(int i=1;i<=5001;i++)
	{
		for(int j=1;j<=5001;j++)
		{
			pos[i][j]+=pos[i-1][j]+pos[i][j-1]-pos[i-1][j-1];
			maxx=max(maxx,pos[i][j]-pos[max(0,i-r)][j]-pos[i][max(0,j-r)]+pos[max(0,i-r)][max(0,j-r)]);
		}
	}
	cout<<maxx;
	return 0;
}