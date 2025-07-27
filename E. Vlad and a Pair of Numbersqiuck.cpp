#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,x,a,b,c;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>x;
		if((x*2)%4!=0)
		cout<<-1<<endl;
		else
		{
			a=x/2*3,b=x/2;
			c=a^b;
			if(c!=x||(a+b)%2||(a+b)/2!=x)
			cout<<-1<<endl;
			else
			cout<<a<<" "<<b<<endl;
		}
	}
	return 0;
}