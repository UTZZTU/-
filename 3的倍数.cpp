#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,r,t;
int main ()
{
    cin>>t;
    while(t--)
    {
    	cin>>l>>r;
    	if((r-l+1)%3==0||(r+l)%3==0)
    	cout<<"YES"<<endl;
    	else
    	cout<<"NO"<<endl;
	}
	return 0;
}