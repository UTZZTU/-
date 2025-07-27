#include <bits/stdc++.h>
using namespace std;
int t,a,b,c;
bool check(int a,int b,int c)
{
	if(a+b>c&&a+c>b&&b+c>a)
	return true;
	else
	return false;
}
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c;
		if(a==b&&b==c)
		cout<<"equilateral"<<endl;
		else if(!check(a,b,c))
		cout<<"error"<<endl;
		else if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a)
		cout<<"right"<<endl;
		else
		cout<<"normal"<<endl;
	}
	return 0;
}