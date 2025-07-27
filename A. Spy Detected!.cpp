#include <bits/stdc++.h>
using namespace std;
int t,n,a[110];
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(a[2]!=a[1]&&a[2]==a[3])
		{
			cout<<1<<endl;
		}
		else if(a[n]!=a[n-1]&&a[n-1]==a[n-2])
		{
			cout<<n<<endl;
		}
		else
		{
			for(int i=2;i<=n-1;i++)
			{
				if(a[i]!=a[i-1]&&a[i]!=a[i+1])
				{
					cout<<i<<endl;
					break;
				}
			}
		}
	}
	return 0;
}