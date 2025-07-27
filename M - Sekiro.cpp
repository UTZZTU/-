#include <bits/stdc++.h>
using namespace std;
int t,n,k;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		while(k--)
		{
			n=ceil(n/2.0);
			if(n==1||n==0) break;
		}
		cout<<n<<endl;
	}
	return 0;
}