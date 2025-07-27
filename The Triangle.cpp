#include <iostream>
using namespace std;
int a[110][110];
int f[110][110];
int main ()
{
	int n;
	while(cin>>n)
	{
		int mx=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				cin>>a[i][j];
			}
		}
		f[1][1]=a[1][1];
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				f[i][j]=max(f[i-1][j-1],f[i-1][j])+a[i][j];
			}
		}
		for(int i=1;i<=n;i++)
		{
			mx=max(mx,f[n][i]);
		}
		cout<<mx<<endl;
	}
	return 0;
}