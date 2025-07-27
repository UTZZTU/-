#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long k)
{
    if(k == 0)
        return a;
    else
        return gcd(k,a%k);
}
int main()
{
        int n;
        cin>>n;
        long long k,cnt,a;
        a = cnt = 1;
        while(n--)
        {
            cin>>k;
            cnt = a/gcd(a,k)*k;
            a = cnt;
        }
        cout<<cnt<<endl;
}
