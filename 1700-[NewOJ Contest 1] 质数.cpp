#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x)
{
	if(x<=1) return false;
	else if(x==2||x==3) return true;
	else if(x%2==0||x%3==0) return false;
	else
	{
		for(int i=5;i<=floor(sqrt(x));i+=6)
		{
			if(x%i==0||x%(i+2)==0) return false;
		}
		return true;
	}
}
int main ()
{
	for(int i=20222022;i;i++)
	{
		if(isPrime(i))
		{
			cout<<i;
			return 0;
		}
	}
	return 0;
}