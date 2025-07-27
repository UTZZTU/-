#include <bits/stdc++.h>
using namespace std;
int t,n,sum;
int gz(int level,int n)
{
	int maxx=0;
	int a[100]={0},pos=0,res=1,num=0;
	while(n)
	{
		a[pos]=n%level;
		maxx=max(maxx,a[pos]);
		pos++;
		n/=level;
	}
	maxx++;
	for(int i=0;i<pos;i++)
	{
		num+=res*a[i];
		res*=maxx;
	}
	return num;
}
int main ()
{
	cin>>t;
	while(t--)
	{
		sum=0;
		cin>>n;
		for(int i=2;i<=n;i++)
		{
			sum+=gz(i,n);
		}
		cout<<sum<<endl;
	}
	return 0;
}