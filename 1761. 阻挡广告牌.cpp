#include <bits/stdc++.h>
using namespace std;
int a[3000][3000];
int main ()
{
	int x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6;
	cin>>x1>>y1>>x2>>y2;
	cin>>x3>>y3>>x4>>y4;
	cin>>x5>>y5>>x6>>y6;
	int ans=0;
	for(int i=0;i<2010;i++)
	{
		for(int j=0;j<2010;j++)
		{
			if(i>x1+1000&&i<=x2+1000&&j>y1+1000&&j<=y2+1000)
			a[i][j]=1;
			if(i>x3+1000&&i<=x4+1000&&j>y3+1000&&j<=y4+1000)
			a[i][j]=1;
			if(i>x5+1000&&i<=x6+1000&&j>y5+1000&&j<=y6+1000)
			a[i][j]=0;
			if(a[i][j])
			ans++;
		}
	}
	cout<<ans;
	return 0;
}