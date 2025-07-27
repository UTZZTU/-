#include <iostream>
using namespace std;
int f[1010][1010];
int main ()
{
	int n,m,t,w,v;
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>w>>v;
		for(int j=m;j>=w;j--)
		{
			for(int k=t;k>=v;k--)
			{
				f[j][k]=max(f[j][k],f[j-w][k-v]+1);
			}
		}
	}
	cout<<f[m][t];
	return 0;
}