#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = -1e18;
int n,m;
int w[600];
int dp[510][510];
int ans;
void solve(){
    cin>>n>>m;
    for(int i = 1;i<=n;i++)cin>>w[i];
	//dp[2][0] = (w[2] - w[1])*(w[2]-w[1]);
    for(int i = 2;i<=n;i++){
        int c = min(m,i-2);
        for(int j = 0;j<=c;j++)
		{	
            for(int k = i - j - 1;k<i;k++)
			{
                int op = j - i + k + 1;
            	dp[i][j] = max(dp[i][j],dp[k][op] + (w[i]-w[k])*(w[i]-w[k]));
          		// cout<<"i =  "<<i<<"  j = "<<j<<"  k = "<<k<< "  "<<"dp[i][j] = "<<dp[i][j]<<endl;
            }
   	    }
    }
    
	cout<<dp[n][m]<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	//cin>>T;
	T = 1;
	while(T--){
		solve();
	}

}