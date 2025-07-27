#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,cnt,primes[1000010];
bool st[1000010];
void init(int x){
	st[1]=true;
	for(int i=2;i<=x;i++){
		if(!st[i]) primes[cnt++]=i;
		for(int j=0;primes[j]*i<=x;j++){
			st[primes[j]*i]=true;
			if(i%primes[j]==0) break;
		}
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	init(1000000);
	cin>>n;
	while(n--){
		cin>>k;
		if((ll)sqrt(k)*(ll)sqrt(k)==k&&!st[(ll)sqrt(k)])
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
	return 0;
}