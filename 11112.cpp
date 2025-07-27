
#include<iostream>
#include<cmath>
using namespace std;
const int N=1e7+10;
typedef long long ll;
ll cnt;//质数的数量 
ll primes[N];//从2到n的质数集 
bool st[N];//判断是否为质数 
void get_primes(ll n){
    for(ll i=2;i<=n;i++){
        if(!st[i]) primes[cnt++]=i;
        for(ll j=0;primes[j]<=n/i;j++){
        //primes[j]<=n/i:primes[j]*i<=n把大于n的合数都筛没啥意义了
            st[primes[j]*i]=true;//用最小质因子去筛合数
            if(i%primes[j]==0) break;
        }
    }

}
int main(){
	get_primes(10000000);
	ll t;scanf("%lld",&t);
	while(t--){
	    ll n;scanf("%lld",&n);
	    for(int i=0;i<cnt;i++){
	        if(n%primes[i]==0){
	            n/=primes[i];
	            if(n%primes[i]==0){
	                cout<<primes[i]<<' '<<n/primes[i]<<'\n';
	                break;
	            }
	            else cout<<(ll)sqrt(n)<<' '<<primes[i]<<'\n';
	            break;
	        }
	    }
	}
	
	return 0;
}