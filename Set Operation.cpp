#include<cstdio>
#include<bitset>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=10000;
bitset<1010>s[maxn+10];
int read()
{
    char c=getchar(); int res;
    while(c>'9'||c<'0') c=getchar();
    for(res=0;c>='0'&&c<='9';c=getchar()) res=(res<<3)+(res<<1)+c-'0';
    return res;
}
int main()
{
    int N,Q,i,num,x,y;
    while(~scanf("%d",&N)){
        for(i=1;i<=maxn;i++) s[i].reset();
        for(i=1;i<=N;i++){
            num=read();
            while(num--){
                x=read();
                s[x][i]=1; //s[x].set(i);
            }
        }
        Q=read();
        while(Q--){
            x=read(); y=read();
            if((s[x]&s[y]).count()) puts("Yes"); //.any()
            else puts("No");
        }
    }
    return 0;
}