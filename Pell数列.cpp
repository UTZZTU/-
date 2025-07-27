#include <bits/stdc++.h>
using namespace std;
const int Mod = 32767;
int n,k,a[1000010];
int main ()
{
	a[1]=1;
	a[2]=2;
	for(int i=3;i<=1000000;i++)
	{
		a[i]=2*a[i-1]+a[i-2];
		a[i]%=Mod;
	}
	cin>>n;
	while(n--)
	{
		cin>>k;
		cout<<a[k]<<endl;
	}
	return 0;
}