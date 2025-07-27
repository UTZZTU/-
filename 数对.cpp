#include<iostream>
typedef long long int ll;
using namespace std;
int main(){
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,sum=0;
        cin>>a>>b;
        for(int i=1;i<=b/i;i++)
        {
            if(b%i==0&&i+b/i==a)
            {
                if(b/i==i)
                    sum++;
                else
                    sum+=2;
            }
        }
        cout<<sum<<endl;
    }
}
