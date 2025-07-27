#include <iostream>
#include <algorithm>
using namespace std;
const int N = 55;
int a[N];
int s[N];
int main ()
{
	int n,m,i,q=0,mx=0,mn=100000000,t,sum;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	while(q<n)
	{
		sum=1;
		if(q!=0)
		{
			s[1]=a[n-q+1];
			for(i=2;i<=n-1;i++)
			{
				if(i-q+1>=1)
				s[i]+=s[1]-a[i-q+1];
				else
				s[i]+=s[1]-a[i-q+1+n];
			}
		}
		for(i=1;i<=n;i++)
		cout<<s[i]<<endl;
		t=n/m;
		for(i=t;i<=n;i+=t)
		{
			sum*=(s[i]-s[i-t])%10;
		}
		if(sum>mx)
		mx=sum;
		if(sum<mn)
		mn=sum;
		q++;
	}
	cout<<mn<<endl;
	cout<<mx;
	return 0;
}