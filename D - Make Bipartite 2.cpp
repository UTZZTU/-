#include<iostream>
#include<cstdio>
#include<cstring>
#define _for(i,a,b) for (int i=(a);i<=(b);i++)
using namespace std;
typedef long long ll;
const int N=2e5+10,M=4e5+10;//N是点的上限，M是边的
int h[N],e[M],ne[M],idx;//单链表
int color[N];//染成i色的点
void init(){
    idx=0;
    memset(h,-1,sizeof(h));
}
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
bool dfs(int u,int c){
    color[u]=c;
    for (int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        if (!color[j]){
            if (!dfs(j,3-c)){
                return false;
            }
        }else if (color[j]==c){
            return false;
        }
    }
    return true;
}
int main(){
    init();
    int n,m,t;
    scanf("%d%d",&n,&m);
    t=m;
    while (m--){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b),add(b,a);
    }
    _for(i,1,n){
        if (!color[i]){
            if (!dfs(i,1)){
                printf("0");
                return 0;
            }
        }
    }
    ll res1=0,res2=0,res3=0;
    for(int i=1;i<=n;i++)
    {
    	if(h[i]==-1)
    	res3++;
    	else if(color[i]==1)
    	res1++;
    	else if(color[i]==2)
    	res2++;
	}
	if(res3>=2)
	{
		printf("0");
        return 0;
	}
	else if(res3==1)
	{
		cout<<res1+res2;
	}
	else
	{
		cout<<res1*res2-t;
	}
    return 0;
}