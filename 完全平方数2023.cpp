#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,res,w;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		w=floor(sqrt(k));
		if(w*w==k) res++;
	}
	cout<<res;
	return 0;
}