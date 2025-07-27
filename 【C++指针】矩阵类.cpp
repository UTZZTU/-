#include <iostream>
using namespace std;
int a[100][100],t=0;
void js(int n,int m)
{
	int sum=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]=sum;
			sum++;
			t+=a[i][j];
		}
	}
}
void at(int n)
{
	printf("%d",n);
}
void at(int n,int m)
{
	printf("%d",a[n][m]);
}
int main ()
{
	int n,m,*p;
	cin>>n>>m;
	js(n,m);
	at(4);
	printf(" ");
	at(3,4);
	printf(" ");
	cout<<t;
	return 0;
}