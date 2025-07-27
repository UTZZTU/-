#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 100000007;
ll n,k,f[20];
int main ()
{
	cin>>n>>k;
	for(int i=1;i<=(ll)pow(10,n-1)*9;i++)
	{
		f[i%k]++;
	}
	for(int i=0;i<k;i++)
	cout<<f[i]<<" ";
	return 0;
}