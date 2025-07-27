#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;
int xys[100100],ds[100100];
int fun(int n)
{
    if(n==2||n==3)
        return 1;
    else if(n%6!=1&&n%6!=5)
        return 0;
    else
    {
        for(int i=5;i<=floor(sqrt(n));i+=6)
            if(n%i==0||n%(i+2)==0)
                return 0;
    }
    return 1;
}
int main ()
{
    int a,b,i,pd;
    cin>>a>>b;
    memset(xys,1,sizeof(xys));
    for(i=a;i<=b;i++)
    {
        if(xys[i]==0)
            continue;
        int k,t=100,m;
        pd=0;
        vector<int> s;
        k=i;
        while(t--)
        {
            m=0;
            while(k!=0)
            {
                m+=(k%10)*(k%10);
                k/=10;
            }
            if(m==1)
            {
                pd=1;
                break;
            }
            k=m;
            vector<int>::iterator it=find(s.begin(),s.end(),m);
            if(it!=s.end())
                break;
            s.push_back(m);
        }
        if(pd==1)
        {
            ds[i]=s.size()+1;
            if(fun(i))
                ds[i]*=2;
        }
        for(auto it=s.begin();it!=s.end();it++)
        {
            xys[*it]=0;
        }
        s.clear();
    }
    pd=0;
    for(i=a;i<=b;i++)
    {
        if(xys[i]&&ds[i]!=0)
        {
            pd=1;
            printf("%d %d\n",i,ds[i]);
        }
    }
    if(pd==0)
        printf("SAD");
    return 0;
}