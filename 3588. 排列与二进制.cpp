#include <bits/stdc++.h>
using namespace std;
int ans;
int main ()
{
	int n,m;
	while(cin>>n>>m)
	{
		if(n==0&&m==0)
		break;
		ans=0;
		for(int i=n;i>=n-m+1;i--)
		{
			int k=i;
			while(k%2==0)
			{
				k/=2;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}