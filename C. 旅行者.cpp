#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y;
int main ()
{
	while(cin>>x>>y)
	{
		if(-10*x+28*y-1526<0&&27*x+9*y-702>0&&27*x+6*y-1347<0&&-10*x+25*y-590>0)
		{
			cout<<"Sumeru"<<endl;
		}
		else if(-13*x+12*y-349<0&&27*x+6*y-1347>0&&4*x+13*y-684>0&&-19*x+7*y+774>0&&25*x+14*y-2295<0)
		{
			cout<<"Liyue"<<endl;
		}
		else if(25*x+14*y-2295>0&&18*y-1440<0&&19*x+7*y-1795<0&&-6*x+11*y-239>0)
		{
			cout<<"Mondstadt"<<endl;
		}
		else
		cout<<"Inazuma"<<endl;
	}
	return 0;
}