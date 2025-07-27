#include <bits/stdc++.h>
using namespace std;
int t,n,flag;
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		flag=0;
		long long num=4;
		while(num<1000000000)
		{
			if(num-1==n)
			{
				flag=1;
				break;
			}
			num*=2;
		}
		if(flag) cout<<1<<endl;
		else cout<<0<<endl;
	}
	return 0;
}