#include <bits/stdc++.h>
using namespace std;
int p,x,y,xx,yy;
int main ()
{
	cin>>p>>x>>y>>xx>>yy;
	if(p==1)
	{
		if(x==xx||y==yy)
		cout<<"Yes";
		else
		cout<<"No";
	}
	else if(p==2)
	cout<<"No";
	else if(p==3)
	{
		if(abs(x-xx)==2&&abs(y-yy)==1||abs(x-xx)==1&&abs(y-yy)==2)
		cout<<"Yes";
		else
		cout<<"No";
	}
	else
	{
		if(abs(x-xx)==2&&abs(y-yy)==2)
		cout<<"Yes";
		else
		cout<<"No";
	}
	return 0;
}