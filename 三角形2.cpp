#include <bits/stdc++.h>
using namespace std;
int xb,xc,yc,xp,yp;
int main ()
{
	cin>>xb>>xc>>yc>>xp>>yp;
	if(xp>0&&xp<xb)
	{
		if(xp<=xc)
		{
			double h=xp*1.0/xc*yc;
			if(yp>0&&yp<h)
			cout<<"yes";
			else
			cout<<"no";
		}
		else
		{
			double h=(xb-xp)*1.0/(xb-xc)*yc;
			if(yp>0&&yp<h)
			cout<<"yes";
			else
			cout<<"no";
		}
	}
	else
	cout<<"no";
	return 0;
}