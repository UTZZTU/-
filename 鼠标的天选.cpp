#include <bits/stdc++.h>
using namespace std;
int n,ans;
string u,v="month";
int main ()
{
	scanf("%d",&n);
	getchar();
	for(int i=1;i<=n;i++)
	{
		cin>>u;
		int pos=u.find(v);
		if(pos!=-1)
		ans++;
	}
	cout<<ans;
	return 0;
}