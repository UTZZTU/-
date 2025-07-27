#include <bits/stdc++.h>
using namespace std;
int n,ans;
int main ()
{
	while(scanf("%d",&n)!=EOF);
	{
	ans=n/4;
	if(n%4==0)
	ans--;
	cout<<ans<<endl;
	}
	return 0;
}