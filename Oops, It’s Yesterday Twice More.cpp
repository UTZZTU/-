#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b;
int main ()
{
	cin>>n>>a>>b;
	if(a>n/2)
	{
		if(b>n/2)
		{
			for(int i=1;i<n;i++) cout<<"R";
			for(int i=1;i<n;i++) cout<<"D";
			for(int i=n;i>a;i--) cout<<"U";
			for(int i=n;i>b;i--) cout<<"L";
		}
		else
		{
			for(int i=1;i<n;i++) cout<<"L";
			for(int i=1;i<n;i++) cout<<"D";
			for(int i=n;i>a;i--) cout<<"U";
			for(int i=1;i<b;i++) cout<<"R";
		}
	}
	else
	{
		if(b>n/2)
		{
			for(int i=1;i<n;i++) cout<<"R";
			for(int i=1;i<n;i++) cout<<"U";
			for(int i=1;i<a;i++) cout<<"D";
			for(int i=n;i>b;i--) cout<<"L";
		}
		else
		{
			for(int i=1;i<n;i++) cout<<"L";
			for(int i=1;i<n;i++) cout<<"U";
			for(int i=1;i<a;i++) cout<<"D";
			for(int i=1;i<b;i++) cout<<"R";
		}
	}
	return 0;
}