#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
#define mem(x,y) memset(x,y,sizeof(x))
#define SI(x) scanf("%d",&x)
#define SL(x) scanf("%lld",&x)
#define PI(x) printf("%d",x)
#define PL(x) printf("%lld",x)
#define P_  printf(" ")
#define T_T while(T--)
typedef long long LL;
LL dp[40];
int main(){
    int T,N;
    dp[0]=0;
    for(int i=1;i<=35;i++)dp[i]=3*dp[i-1]+2;
    while(~SI(N))PL(dp[N]),puts("");
    return 0;
}