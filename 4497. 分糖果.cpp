#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,d;
int main ()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>c;
		d=(a+b+c)/2;
		cout<<d<<endl;
	}
	return 0;
}