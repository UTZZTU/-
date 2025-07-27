#include <iostream>
using namespace std;
typedef long long ll;
int main ()
{
    ll i,ws=1,x,s;
    cin>>x;
    for(i=1;;i=i*10+1,ws++)
    {
        if(i%x==0)
        {
            s=i/x;
            break;
        }
        printf("%lld\n",i);
    }
    printf("%lld %lld",s,ws);
    return 0;
}