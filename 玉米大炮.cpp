#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+6;
struct A{ ll s,t; }in[N];
ll n,ask;
bool f( ll mid )
{
    ll sum=0;			// LL
    if(ask<=0)
    return true;
    for( int i=1;i<=n;i++ )
    {
        sum+=mid/in[i].t*in[i].s;
    }
    return ( sum>=ask ) ;
}
int main()
{
    ll i,x,y,mid,sum;

    while( ~scanf("%lld%lld",&n,&ask) )
    {
    	sum=0;
        for( i=1;i<=n;i++ ) 
        {
        	scanf("%lld%lld",&in[i].s,&in[i].t );
        	sum+=in[i].s;
		}
		ask-=sum;
		
        x=0; y=2e18;                // MAX
        while( x<y )
        {
            mid=( x+y +1)>>1;
            if( f( mid ) )  y=mid;
            else            x=mid+1;
        }
        printf("%lld\n",x);			// lld
    }
    return 0;
}