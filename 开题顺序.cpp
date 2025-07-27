#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,t,p,a[10],b[10],c[10],x[10],y[10],maxx,dd[10]={0,1,2,3,4,5,6,7,8,9};
int main ()
{
	scanf("%lld%lld%lld",&n,&t,&p);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld%lld%lld",&a[i],&b[i],&c[i],&x[i],&y[i]);
	}
	do{
		ll ti=0,res=0;
		for(int i=1;i<=n;i++){
			if(ti+x[dd[i]]<=t){
				ti+=x[dd[i]];
				res+=max(c[dd[i]],a[dd[i]]-ti*b[dd[i]]-y[dd[i]]*p);
				maxx=max(maxx,res);
			}
		}
	}while(next_permutation(dd+1,dd+10));
	cout<<maxx;
	return 0;
}