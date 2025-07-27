#include <bits/stdc++.h>
using namespace std;
string p;
int l,r,a,b;
int main ()
{
	cin>>p;
	for(auto c:p)
	{
		if(c=='(')
		l++;
		else
		r++;
	}
	if(l==r)
	cout<<0<<endl;
	else if(r>l)
	{
		a=0,b=0;
		for(auto c:p)
		{
			if(c=='(')
			a++;
			else
			{
				b++;
				if(b>a)
				{
					cout<<b<<endl;
					break;
				}
			}
		}
	}
	else
	{
		a=0,b=0;
		reverse(p.begin(),p.end());
		for(auto c:p)
		{
			if(c==')')
			a++;
			else
			{
				b++;
				if(b>a)
				{
					cout<<b<<endl;
					break;
				}
			}
		}
	}
	return 0;
}