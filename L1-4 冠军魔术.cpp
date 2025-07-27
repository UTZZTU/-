#include <bits/stdc++.h>
using namespace std;
int a,b;
int main ()
{
	cin>>a>>b;
	for(int i=1;i<=b;i++)
	{
		if(i%2==0)
		a*=2;
	}
	cout<<b%2<<" "<<a;
	return 0;
}