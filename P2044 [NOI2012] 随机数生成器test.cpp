#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
struct s
{
    long long a[3][3];
}A,B;
long long n,mod,t,c,x0,g,b;
long long mul(long long a,long long b)
{
    long long res=0;
    for(;b;b>>=1) 
    {
        if(b&1)res=(res+a)%mod;
        a=(a<<1)%mod;
    }
    return res;
}
s ml(s t1,s t2)
{
    s t3;
    memset(t3.a,0,sizeof(t3.a));
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
            for(int k=1;k<=2;k++)
            {
                t3.a[i][j]+=(mul(t1.a[i][k],t2.a[k][j]))%mod;
                t3.a[i][j]%=mod;
                if(t3.a[i][j]<0)t3.a[i][j]+=mod;
            }
    for(int i=1;i<=2;i++)
    {
    	for(int j=1;j<=2;j++)
    	cout<<t3.a[i][j]<<" ";
    	cout<<endl;
	}
    return t3;
}
s ksm(long long t)
{
    s C;
    memset(C.a,0,sizeof(C.a));
    for(int i=1;i<=2;i++)C.a[i][i]=1;
    while(t)
    {
        if(t&1)C=ml(C,B);
        B=ml(B,B);
        t>>=1;
    }
    return C;
}
int main()
{
    cin>>mod>>t>>c>>x0>>n>>g;
    A=(s){{{},{0,x0,1},{0,0,0}}};
    B=(s){{{},{0,t,0},{0,c,1}}};
    B=ksm(n);
    A=ml(A,B);
    cout<<A.a[1][1]%g;
    return 0;
}