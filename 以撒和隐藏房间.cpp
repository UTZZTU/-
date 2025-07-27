#include <bits/stdc++.h>
using namespace std;
string a[1010],u,v;
int n,m,cnt,dirx[4]={0,0,-1,1},diry[4]={-1,1,0,0};
bool judge(int x,int y)
{
	int t1=0,t2=0;
	for(int i=0;i<4;i++)
	{
		int xx=dirx[i]+x,yy=diry[i]+y;
		if(a[xx][yy]=='1') t1++;
		if(a[xx][yy]=='2') t2++;
	}
	if(t1==3&&t2==0) return true;
	return false;
}
int main ()
{
	cin>>n>>m;
	getchar();
	for(int i=1;i<=m+1;i++) v+="0";
	a[0]=v;
	for(int i=1;i<=n;i++)
	{
		cin>>u;
		a[i]="0"+u;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='0'&&judge(i,j))
			{
				cnt++;
			}
		}
	}
	if(!cnt) printf("NO");
	else printf("YES\n%d",cnt);
	return 0;
}