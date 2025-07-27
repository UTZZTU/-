#include <bits/stdc++.h>
using namespace std;
int n;
int main ()
{
	cin>>n;
    if(n&1)
        cout<<n/2;
    else
	    cout<<n/2-1;
	return 0;
}