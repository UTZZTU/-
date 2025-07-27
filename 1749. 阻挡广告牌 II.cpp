#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int x1,y1,x2,y2,x3,y3,x4,y4;
	cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
	if(x3<=x1&&y3<=y1&&x4>=x2&&y4>=y2)
	cout<<"0";
	else if(x3<=x1&&x4>=x2&&(y4>=y2&&y3<y2||y3<=y1&&y4>y1))
	{
		cout<<(x2-x1)*(y2-y1-(min(y4,y2)-max(y1,y3)));
	}
	else if(y3<=y1&&y4>=y2&&(x4>=x2&&x3<x2||x3<=x1&&x4>x1))
	{
		cout<<(y2-y1)*(x2-x1-(min(x4,x2)-max(x1,x3)));
	}
	else
	cout<<(x2-x1)*(y2-y1);
	return 0;
}