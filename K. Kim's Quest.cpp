#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(),(x).end()
 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MAX=2e5+10,P=998244353;
const ll INF=0x3f3f3f3f,oo=0x3f3f3f3f3f3f3f3f;

ll n;
ll dp[MAX][4];
bool a[MAX];
ll cnt[4]={0,0,0,0};
ll sgl[2]={0,0};

int main() {
	speed;
	cin>>n;
	for (int i=1;i<=n;i++) {
		ll x;
		cin>>x;
		a[i]=(x&1);
	}
	memset(dp,0,sizeof(dp));
	for (int i=1;i<=n;i++) {
		if (a[i]) {
			dp[i][0]=dp[i-1][0];
			dp[i][1]=dp[i-1][1]+dp[i-1][2]+cnt[2];
			dp[i][2]=dp[i-1][2];
			dp[i][3]=dp[i-1][3]+dp[i-1][1]+cnt[1];
		} else {
			dp[i][0]=dp[i-1][0]+dp[i-1][0]+cnt[0];
			dp[i][1]=dp[i-1][1];
			dp[i][2]=dp[i-1][2]+dp[i-1][3]+cnt[3];
			dp[i][3]=dp[i-1][3];
		}
		for (int k=0;k<4;k++) {
			dp[i][k]%=P;
//			cout<<dp[i][k]<<" ";
		}
//		cout<<"\n";
		cnt[a[i]]+=sgl[0];
		cnt[2+a[i]]+=sgl[1];
		sgl[a[i]]++;
	}
	cout<<(dp[n][0]+dp[n][1]+dp[n][2]+dp[n][3])%P<<"\n";
	return 0;
}