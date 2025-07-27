#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[1000100],res;
int main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i-=2){
		res+=a[i];
	}
	cout<<res;
	return 0;
}