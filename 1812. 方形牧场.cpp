#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int x1,y1,x2,y2,x3,y3,x4,y4;
	cin>>x1>>y1>>x2>>y2;
	cin>>x3>>y3>>x4>>y4;
	cout<<pow(max((max(x2,x4)-min(x1,x3)),(max(y2,y4)-min(y1,y3))),2);
	return 0;
}