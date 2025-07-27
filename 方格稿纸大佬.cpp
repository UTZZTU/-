#include<bits/stdc++.h>
using namespace std;
#define N 303
int w,b,n,m,ans;
int a[N][N],white[N][N],black[N][N];
inline void read(int &x)
{
    x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
}
int main()
{
    read(n),read(m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            read(a[i][j]);
            white[i][j]=white[i-1][j]+white[i][j-1]-white[i-1][j-1]+(a[i][j]?0:1);
            black[i][j]=black[i-1][j]+black[i][j-1]-black[i-1][j-1]+(a[i][j]?1:0);
        }        
    for(int k=2;k<=min(n,m);k++)
        for(int i=k;i<=n;i++)
            for(int j=k;j<=m;j++)
            {
                w=white[i][j]-white[i-k][j]-white[i][j-k]+white[i-k][j-k];
                b=black[i][j]-black[i-k][j]-black[i][j-k]+black[i-k][j-k];
                if(abs(w-b)<=1)ans++;
            }    
    printf("%d\n",ans);
    return 0;
}
