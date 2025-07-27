#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,w[10],res;
int main ()
{
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	cin>>w[i];
	sort(w+1,w+1+k);
	if(k==1)
	{
		cout<<"Ginger666";
	}
	else
	{
	    if(n%3==1)
	    res+=w[2];
	    else if(n%3==2)
	    res+=w[1]+w[2];
	    res+=(n/3)*(w[1]+w[1]+w[2]);
	    cout<<res;
	}
	return 0;
}