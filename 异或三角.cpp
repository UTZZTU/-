#include <iostream>
using namespace std;
int main ()
{
	int n,ans=0,r;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(k>=i+j)
				break;
				r=i^j^k;
				if(r==0&&i+j>k&&i+k>j&&j+k>i)
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}