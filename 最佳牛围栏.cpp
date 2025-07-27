#include<iostream>
#include <algorithm>
using namespace std;
const int N =100010;
int n,m,i;
int cow[N];
double s[N];
bool check(double avge)
{
    for(i=1;i<=n;i++)
    s[i]=s[i-1]+cow[i]-avge;
    int i,j;
    double mixv=0;
    for(i=0,j=m;j<=n;j++,i++)
    {
        mixv=min(mixv,s[i]);
        if(s[j]>=mixv)
        return true;
    }
    return false;
}
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=n;i++)
    cin>>cow[i];
    double l=0,r=2000;
    while(r-l>1e-5)
    {
        double mid=(r+l)*1.0/2;
        if(check(mid)) l=mid;
        else  r=mid;
    }
    printf("%d",int(r*1000));
    return 0;
}