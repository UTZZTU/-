#include <bits/stdc++.h>
using namespace std;
string a;
int main ()
{
	int d,n=0;
	string x;
	cin>>x>>d;
	if(d==10)
	{
		for(int i=0;i<x.size();i++)
		{
			n=n*10+x[i]-'0';
		}
		int u;
		if(n==0)
		{
			cout<<"0";
			return 0;
		}
		while(n!=0)
		{
			u=n%27;
			n/=27;
			if(u>=0&&u<=9)
			a+='0'+u;
			else
			a+='A'+u-10;
		}
		reverse(a.begin(),a.end());
		cout<<a;
	}
	else
	{
		int tot=0,jc=1;
		for(int i=x.size()-1;i>=0;i--)
		{
			if(x[i]>='A')
			tot+=(x[i]-'A'+10)*jc;
			else
			tot+=(x[i]-'0')*jc;
			jc*=27;
		}
		cout<<tot;
	}
	return 0;
}