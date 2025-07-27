#include <bits/stdc++.h>
using namespace std;
#define int long long
const int p = 1e9+7;
//若p是质数，则对于任意整数 1<= m <= n，有：
//C(n,m)=C(n%p,m%p)*C(n/p,m/p) (mod p)
int n,x,y,z;
int qmi(int a, int k){       // 快速幂模板
    int res=1;
    while(k){
        if(k&1) res=res*a%p;
        a=a*a%p;
        k>>=1;
    }
    return res;
}
int C(int a, int b){     // 通过定理求组合数C(a, b)
    int res=1;
    for(int i=1,j=a;i<=b;i++,j--){
        res=res*j%p;
        res=res*qmi(i,p-2)%p;
    }
    return res;
}
int lucas(int a,int b){
    if(a<p&&b<p) return C(a,b);
    return C(a%p,b%p)*lucas(a/p,b/p)%p;
}
signed main ()
{
	cin>>n>>x>>y>>z;
	int res=((qmi((int)2,n)%p-1)%p+p)%p;
	res-=lucas(n,x);
	res-=lucas(n,y);
	res-=lucas(n,z);
	res=(res%p+p)%p;
	cout<<res;
	return 0;
}