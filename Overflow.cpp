#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e5+7 ;
#define ll long long
#define eps 1e-5 
#define open freopen("input.in","r",stdin);freopen("output.in","w",stdout);
int n,m,t,k,ans,cnt;
double l[mxn] , p[mxn] , s , h , v ;
bool check(double x)
{
    double sum = 0 ;
    for(int i=1;i<=n;i++){
        if(p[i]<1) sum+= p[i]*l[i]*l[i]*l[i];
        else sum+=min(h,l[i])*l[i]*l[i];
    }
    return v+sum < x*s ;
}
void solve() 
{
    scanf("%d",&t);
    for(;t;t--){
        scanf("%d",&n);
        ans = 0 ; k = 0 ; cnt = -1 ;
        for(int i=1;i<=n;i++){
            scanf("%lf %lf",&l[i],&p[i]);
        }
        scanf("%lf %lf %lf",&s,&h,&v);
        double L = v/s , R = h , mid ;
        while(R-L>eps){
            mid = (R+L)/2.0;
            if(check(mid)) R = mid ;
            else L = mid ;
        }
        printf("%.2f\n",L);
    }    
}
int main()
{
    /// open
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}