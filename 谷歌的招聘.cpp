#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll fun(ll n)
{
    if(n==1)
        return 0;
    if(n==2||n==3)
        return 1;
    if(n%6!=1&&n%6!=5)
        return 0;
    else 
    {
        ll i,w;
        w=floor(sqrt(n));
        for(i=5;i<=w;i+=6)
        {
            if(n%i==0||n%(i+2)==0)
                return 0;
        }
    }
    return 1;
}
int main ()
{
    char s[1010];
    int l,k,i,pd=0;
    ll sum=0;
    cin>>l>>k;
    getchar();
    scanf("%s",s);
    for(i=0;i<k;i++)
    {
        sum=sum*10+s[i]-'0';
    }
    if(fun(sum))
    {
        printf("%lld",sum);
        return 0;
    }
    else
    {
        for(i;s[i]!='\0';i++)
        {
        	ll y;
        	y=pow(10,k-1);
            sum=sum%y;
            sum=sum*10+s[i]-'0';
            if(fun(sum))
            {
                printf("%lld",sum);
                return 0;
            }
        }
        printf("404");
    }
    return 0;
}