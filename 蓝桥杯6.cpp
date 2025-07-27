#include <bits/stdc++.h>
using namespace std;
int s,t,ans;
int main ()
{
	cin>>s>>t;
	t%=7;
	for(int i=s+1;;i++)
	{
		ans++;
		if(i%7==t)
		break;
	}
	cout<<ans;
	return 0;
}