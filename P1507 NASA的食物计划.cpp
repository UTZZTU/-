#include <iostream>
using namespace std;
int f[410][410],v[100],m[100],k[100];
int main ()
{
	int vx,mx,n,i,j,o;
	cin>>vx>>mx>>n;
	for(i=1;i<=n;i++)
	cin>>v[i]>>m[i]>>k[i];
	for(i=1;i<=n;i++)
	{
		for(j=vx;j>=v[i];j--)
		{
			for(o=mx;o>=m[i];o--)
			{
				f[j][o]=max(f[j][o],f[j-v[i]][o-m[i]]+k[i]);
			}
		}
	}
	cout<<f[vx][mx];
	return 0;
}