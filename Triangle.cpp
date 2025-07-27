#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b;
int main ()
{
	cin>>n>>a>>b;
	a=n-a+1;
	cout<<(char)('A'+(n*(n+1)/2-(a)*(a+1)/2+b-1)%26);
	return 0;
}