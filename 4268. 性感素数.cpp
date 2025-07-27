#include <bits/stdc++.h>
using namespace std;
int n;
bool fun(int x)
{
	if(x<=1)
	return false;
	if(x==2||x==3)
	return true;
	if(x%6!=1&&x%6!=5)
	return false;
	else
	{
		for(int i=5;i<=floor(sqrt(x));i+=6)
		{
			if(x%i==0||x%(i+2)==0)
			return false;
		}
		return true;
	}
}
int main ()
{
	cin>>n;
	if(fun(n)&&fun(n-6))
	{
		cout<<"Yes"<<endl<<n-6;
	}
	else if(fun(n)&&fun(n+6))
	{
		cout<<"Yes"<<endl<<n+6;
	}
	else
	{
		cout<<"No"<<endl;
		for(int i=n+1;;i++)
		{
			if(fun(i)&&(fun(i-6)||fun(i+6)))
			{
				cout<<i;
				return 0;
			}
		}
	}
	return 0;
}