#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=1e6+100;
int qmi(int a,int b,int mod)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}

int qmi(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a;
		b>>=1;
		a=a*a;
	}
	return res;
}

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
struct Node{
    int to;
    int ne;
}e[maxn];
int head[maxn];
ll f[maxn][3],n,x,y; 
int cnt=0;
void add(int u,int v);
void dfs(int u,int fa);
int main(){
    memset(head,-1,sizeof(head));
    cin>>n;
    for(int i=1;i<=n-1;i++){
        cin>>x>>y;
		add(y,x);
        add(x,y);
        
    }
    dfs(1,-1);
    cout<<(f[1][1]+f[1][0])%mod<<endl; 
}
void add(int u,int v){
    e[cnt].to=v;
    e[cnt].ne=head[u];
    head[u]=cnt++;
} 
void dfs(int u,int fa){
    f[u][1]=1;
    f[u][0]=1; 
    for(int i=head[u];~i;i=e[i].ne){
        int v=e[i].to;
        if(fa==v){
            continue;
        }
        dfs(v,u);
        ll sum1=(f[v][1]+f[v][0])%mod;
        ll sum2=(f[v][0])%mod; 
        f[u][1]=(f[u][1]*sum2)%mod;
        f[u][0]=(f[u][0]*sum1)%mod;
    }
}