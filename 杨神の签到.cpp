#include <bits/stdc++.h>
using namespace std;
int t,x;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>x;
		for(int i=2;;i++)
		{
			if(__gcd(i,i+x)==1)
			{
				cout<<i<<" "<<i+x<<endl;
				break;
			}
		}
	}
	return 0;
}