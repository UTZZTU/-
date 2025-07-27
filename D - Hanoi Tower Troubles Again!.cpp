#include <bits/stdc++.h>
using namespace std;
int f[55],pos=4,t,n;
int main ()
{
	f[1]=1;
	f[2]=3;
	for(int i=2;i<=25;i++)
	{
		f[2*i-1]=f[2*i-2]+pos;
		f[2*i]=f[2*i-1]+pos;
		pos+=2;
	}
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<f[n]<<endl;
	}
	return 0;
}