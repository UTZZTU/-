#include <bits/stdc++.h>
using namespace std;
int n,m;
int main ()
{
	cin>>n>>m;
	cout<<min(n,m)+(max(n,m)-min(n,m)+1)/2;
	return 0;
}