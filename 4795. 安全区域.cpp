#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,xx[100010],yy[100010],x,y,tx,ty,res;
int main ()
{
	cin>>n>>m;
	res=n*n;
	while(m--)
	{
		cin>>x>>y;
		if(!xx[x])
		{
			tx++;
			xx[x]=1;
		}
		if(!yy[y])
		{
			ty++;
			yy[y]=1;
		}
		cout<<res-tx*n-(n-tx)*ty<<endl;
	}
	return 0;
}