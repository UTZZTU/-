#include <bits/stdc++.h>
using namespace std;
int m,n,s;
double f[1010][1010];
string op[1010],tt[1010];
int main ()
{
	scanf("%d%d%d",&m,&n,&s);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			scanf("%lf",&f[i][j]);
		}
	}
	getchar();
	for(int i=1;i<=n;i++)
	{
		cin>>op[i];
	}
	if(s>0)
	{
		getchar();
		for(int i=1;i<=s;i++)
		{
			cin>>tt[i];
		}
	}
	cout<<setw(6)<<m<<setw(6) <<n<<setw(6) <<s<<endl;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
//			if(j==1)
//			{
//				cout<<f[i][j];
//			}
//			else
			cout<<setw(6)<<f[i][j];
		}
		cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{
//		if(i==1)
//		cout<<op[i];
//		else
		cout<<" "<<op[i];
	}
	cout<<endl;
	for(int i=1;i<=s;i++)
	{
//		if(i==1)
//		cout<<tt[i];
//		else
		cout<<" "<<tt[i];
	}
	return 0;
}