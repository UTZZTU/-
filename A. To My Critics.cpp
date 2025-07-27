#include <bits/stdc++.h>
using namespace std;
int t,f[4];
int main ()
{
	cin>>t;
	while(t--)
	{
		for(int i=1;i<=3;i++)
		cin>>f[i];
		sort(f+1,f+1+3);
		if(f[3]+f[2]>=10) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}