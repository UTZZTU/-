#include <iostream>
using namespace std;
int main ()
{
	int T,n,m,i;
	long long a[21],b[21];
	a[0]=1;a[1]=1;a[2]=2;
	for(i=3;i<21;i++)
	{
		a[i]=a[i-1]*i;
	}
	b[0]=0;b[1]=1;b[2]=1;b[3]=2;
	for(i=4;i<21;i++)
	{
		b[i]=(i-1)*(b[i-1]+b[i-2]);
	}
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		cout<<a[n]/a[m]/a[n-m]*b[m]<<endl;
	}
	return 0;
}
