#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,x,y,flag;
signed main ()
{
	cin>>t;
	while(t--)
	{
		cin>>x>>y;
		flag=0;
		for(int i=x;i<=y;i+=x)
		{
			if((x*y)%i==0&&__gcd((x*y)/i,i)==x)
			{
				cout<<i<<" "<<(x*y)/i<<endl;
				flag=1;
				break;
			}
			
		}
		if(!flag) cout<<"-1"<<endl;
	}
	return 0;
}