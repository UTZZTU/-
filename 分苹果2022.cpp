#include <bits/stdc++.h>
using namespace std;
int t,n,m,k;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		if(n%m==0)
		cout<<"YES"<<endl;
		else
		{
			n%=m;
			if(k>=m-n)
			cout<<"YES"<<endl;
			else
			cout<<"NO"<<endl;
		}
	}
	return 0;
}