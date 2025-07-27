#include<bitsdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int t,p,n,a[N];
int qmi(int m,int k,int p){
	int res=1%p,t=m;
	while(k){
		if(k&1) res=res*t%p;
		t=t*t%p;
		k>>=1;
	}
	return res;
}
signed main(){
	scanf("%lld%lld",&t,&p);
	a[0]=1;
	for(int i=1;i<=p;i++){
		a[i]=a[i-1]*i%p;
//		cout<<i<<" "<<a[i]<<endl;
	}
	while(t--){
		scanf("%lld",&n);
		int x=n/p;
		n%=p;
		
		int res=qmi(a[p-1],x,p)*a[n]%p;
		res%=p;
		int cnt=1;
		while(x>p){
			cnt=(cnt*qmi(a[p-1],x/p,p)%p)%p*a[x%p]%p;
			x/=p;
			cnt%=p;
		}
		cnt*=a[x%p]%p;
		cnt%=p;
		printf("%lld\n",res*cnt%p);
		
	}
	return 0;
}
