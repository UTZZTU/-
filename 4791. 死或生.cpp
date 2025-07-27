#include <bits/stdc++.h>
using namespace std;
int n,t,x,y,a[3],b[3];
int main ()
{
	cin>>n;
	while(n--)
	{
		cin>>t>>x>>y;
		b[t]+=x,a[t]+=y;
	}
	for(int i=1;i<=2;i++)
	{
		if(b[i]>=a[i])
		cout<<"LIVE"<<endl;
		else
		cout<<"DEAD"<<endl;
	}
	return 0;
}