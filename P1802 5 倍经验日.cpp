#include <iostream>
using namespace std;
int f[1010],win[1010],lose[1010],need[1010];
int main ()
{
	int n,x;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	cin>>lose[i]>>win[i]>>need[i];
	for(int i=1;i<=n;i++)
	{
		int j;
		for(j=x;j>=need[i];j--)
		{
			f[j]=max(f[j]+lose[i],f[j-need[i]]+win[i]);
		}
		for(j;j>=0;j--)
		{
			f[j]+=lose[i];
		}
	}
	cout<<5*f[x];
	return 0;
}