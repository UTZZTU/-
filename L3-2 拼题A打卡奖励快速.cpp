#include <iostream>
#include <string.h>
using namespace std;
int v[1010],w[1010],f[30010];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(f,30000,sizeof(f));
    f[0]=0;
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>w[i];
    for(int i=1;i<=n;i++)
    {
    	cin>>v[i];
    	sum+=v[i];
	}
    for(int i=1;i<=n;i++)
    {
    	for(int j=sum;j>=v[i];j--)
    	{
    		f[j]=min(f[j],f[j-v[i]]+w[i]);
		}
	}
	int ans;
	for(int i=sum;i>=0;i--)
	{
		if(f[i]<=m)
		{
			ans=i;
			break;
		}
	}
	cout<<ans;
	return 0;
}