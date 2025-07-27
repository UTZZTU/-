#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
int n,e,m;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const int N=405;
long long dp[N][N];
void input()
{
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=e;i++)
	{
		int u,v;
		ll w;
		cin>>u>>v>>w;
		dp[u][v]=min(dp[u][v],w);
	}
}
void floyd()
{
	for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]);
}
void output(){
    int s, t;
    while(m--){
        cin>>s>>t;
        if(dp[s][t]==INF) cout <<"No solution"<<endl;
        else if(s==t) cout << "0" <<endl;
        else          cout <<dp[s][t]<<endl;
    }
}
int main ()
{
	while(cin>>n>>e>>m)
	{
		input();
    floyd();
    output();
	}
    return 0;
}