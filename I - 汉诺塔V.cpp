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
LL dp[65][65];
int main(){
    int T,N,k,cur;
    for(int i=1;i<=60;i++){
        cur=0;
        for(int j=i;j>=1;j--){
            dp[i][j]=(LL)1<<cur;
            cur++;
        }
    }
    SI(T);
    T_T{
        SI(N);SI(k);
    PL(dp[N][k]);puts("");
    }
    return 0;
}