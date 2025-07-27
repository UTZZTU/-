#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int read()                            //读入优化 
{
    char ch=getchar();
    int a=0,x=1;
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') x=-x;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        a=(a<<3)+(a<<1)+(ch-'0');
        ch=getchar();
    }
    return a*x;
}
int n,m1,m2,minx,gcdd,m,s,q,t,flag,tot,ans,tots,totq;        //t代表q能分解成多少个s         
int S[10001];
int gcd(int a,int b)                  //欧几里得算法求最大公约数 
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main()
{
    n=read();
    m1=read();
    m2=read();
    minx=1e9;
    if(m1==1)                             //这里一定要注意特判m1==1的情况，不然会TLE 
    {
        cout<<0;                          //无需等待，因为任何数都是1的倍数 
        return 0;
    }
    for(int i=1;i<=n;i++) S[i]=read();
    for(int i=1;i<=n;i++)                 
    {
        tot=0;
        m=m1;                             //拷贝一份m1的值
        s=S[i];                           //拷贝一份S[i]的值 
        flag=1;                           //判断是否有解 
        t=0;                              //记录最大公约数要减几个m2 
        while(m!=1)
        {
            gcdd=gcd(m,s);                //第一小步，求最大公约数 
            if(gcdd==1) {flag=0;break;}   //如果互质，那么肯定无解，直接跳出 
            m/=gcdd;                      //左边剩下了m/gcdd 
            q=s/gcdd;                     //q就是s除以gcdd后剩下的数 
            s=gcdd;                       //右边剩下了gcdd         
            t++;                          //每进入一次循环，就要多减1个m2   
        } 
        if(flag)
        {
            int gc=gcd(q,s);        //先求出gcd(q,s) 
            if(gc!=1&&gc!=s)        //单独讨论第三种情况 
            {
                totq=0;tots=0;      //注意清空 
                while(q%gc==0)      //如果q中含有gc就分离 
                {
                    totq++;         //q中含有gc的个数 
                    q/=gc;
                }
                while(s%gc==0)      //如果s中含有gc就分离 
                {
                    tots++;         //s中含有gc的个数 
                    s/=gc;
                }
                if((t*m2*tots+totq*(t-1)*m2)%(tots+totq)==0)    //这种情况的公式，注意向上取整 
				   ans=(t*m2*tots+totq*(t-1)*m2)/(tots+totq);   
                else ans=(t*m2*tots+totq*(t-1)*m2)/(tots+totq)+1;
                minx=min(minx,ans);
            }
            else                   //第一，二种情况 
            {
                while(q%s==0)      //如果q里面含有s，分离出来 
                {
                    tot++;         //tot表示能分离出来多少个s，第一种情况就是tot=0的情况 
                    q/=s;           
                }
                if((t*m2+tot*(t-1)*m2)%(tot+1)==0)    //我不知道为什么ceil出来的答案不对，只能自己模拟向上取整了 
                   ans=(t*m2+tot*(t-1)*m2)/(tot+1);   //没余数说明正好整除 
                else ans=(t*m2+tot*(t-1)*m2)/(tot+1)+1;//如果有余数就要+1(这个1就是余数除成小数后再向上取整后得到的) 
                minx=min(minx,ans);        //题目要求整体最小时间 
            }
        }
    }
    if(minx==1e9) cout<<-1;        //如果minx没被更新，说明无解 
    else cout<<minx;
    return 0;
} 