#include <bits/stdc++.h>
using namespace std;
int n;
int main ()
{
	cin>>n;
	int i=1,j=n;
	while(i<j)
	{
		cout<<i<<" "<<j<<" ";
		i++,j--;
	}
	if(i==j) cout<<i;
	return 0;
}