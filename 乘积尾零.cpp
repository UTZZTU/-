#include <bits/stdc++.h>
using namespace std;
int res,a,b,k;
int main ()
{
	for(int i=1;i<=100;i++)
	{
		cin>>k;
		while(k%10==0) k/=10,res++;
		while(k%2==0) k/=2,a++;
		while(k%5==0) k/=5,b++;
	}
	cout<<res+min(a,b);
	return 0;
}