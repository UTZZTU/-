#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,res,f[1010][1010];
void solve(int x,int y)
{
	while(y%2==0)
	{
		x=x*x;
		y/=2;
		if(x<=n&&y>=2)
		{
			if(!f[x][y])
			{
				f[x][y]=1;
				res--;
			}
		}
		else break;
	}
}
int main ()
{
	cin>>n>>m;
	res=(n-1)*(m-1);
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			solve(i,j);
		}
	}
	cout<<res;
	return 0;
}