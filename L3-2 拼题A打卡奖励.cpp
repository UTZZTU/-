#include <iostream>
using namespace std;
int f[1010000],money[1010],time[1010];
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>time[i];
	for(i=1;i<=n;i++)
	cin>>money[i];
	for(i=1;i<=n;i++)
	{
		for(j=m;j>=time[i];j--)
		{
			f[j]=max(f[j],f[j-time[i]]+money[i]);
		}
	}
	cout<<f[m];
	return 0;
}