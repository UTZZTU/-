#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n;
string u;
int main ()
{
	cin>>t;
	while(t--){
		cin>>n;
		getchar();
		cin>>u;
		map<pair<ll,ll>,ll>mp;
		ll x=0,y=0,cnt=0;
		mp[{x,y}]=1;
		for(int i=0;i<n;i++){
			if(u[i]=='0'){
				x++,y++;
			}
			else if(u[i]=='1'){
				x--;
			}
			else{
				y--;
			}
			cnt+=mp[{x,y}];
			mp[{x,y}]++;
		}
		printf("%lld\n",cnt);
	}
	return 0;
}