#include <bits/stdc++.h>
using namespace std;
int a,b,c,t;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(b>a)
		{
			if(b==15)
			c=14;
			else
			c=b+1;
		}
		else
		{
			if(b==0)
			c=1;
			else
			c=b-1;
		}
		cout<<c<<endl;
	}
	return 0;
}