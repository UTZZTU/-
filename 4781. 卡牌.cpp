#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,res=1,n;
string u;
int main ()
{
	cin>>n;
	getchar();
	cin>>u;
	for(int i=0;i<n;i++)
	{
		if(u[i]=='B')
		{
			x+=res;
		}
		res*=2;
	}
	cout<<x;
	return 0;
}