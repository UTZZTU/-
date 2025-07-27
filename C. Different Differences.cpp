#include <bits/stdc++.h>
using namespace std;
int t,k,n,x;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>k>>n;
		int i,j=1;
		for(i=1;i<k&&i*(i+1)/2+1+(k-i-1)<=n;i++)
		;
		cout<<1;
		k--;
		for(int x=1;x<i;x++)
		{
			cout<<" "<<j+x;
			j+=x;
			k--;
		}
		while(k)
		{
			cout<<" "<<j+1;
			j+=1;
			k--;
		}
		cout<<endl;
	}
	return 0;
}