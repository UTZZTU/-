#include <iostream>
using namespace std;
typedef long long ll;
int main ()
{
	int a[101]={0},i,j,t;
	for(i=2;i<=100;i++)
	{
		t=i;
		for(j=2;j*j<=i;j++)
		{
			for(;t%j==0;t/=j)
			a[j]++;
		}
		if(t>1)
		a[t]++;
	}
	ll sum=1;
	for(i=2;i<=100;i++)
	{
		if(a[i])
		sum*=a[i]+1;
	}
	cout<<sum;
	return 0;
}