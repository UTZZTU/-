#include <bits/stdc++.h>
using namespace std;
int t,n,a,b,minn;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n-1;i++)
		{
			cin>>a>>b;
			if(i==1)
			minn=a+b;
			else
			minn=min(minn,a+b);
		}
		cout<<minn<<endl;
	}
	return 0;
}