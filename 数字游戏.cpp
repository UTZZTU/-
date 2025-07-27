//#pragma GCC optimize(2)
//#pragma GCC optimize("Ofast","inline","-ffast-math")
//#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<unordered_map>
#define ll long long
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define int  ll
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
int read()
{
int res = 0,flag = 1;
char ch = getchar();
while(ch<'0' || ch>'9')
{
if(ch == '-') flag = -1;
ch = getchar();
}
while(ch>='0' && ch<='9')
{
res = (res<<3)+(res<<1)+(ch^48);//res*10+ch-'0';
ch = getchar();
}
return res*flag;
}
const int maxn = 1e6+5;
const int mod = 1e9+7;
const double pi = acos(-1);
const double eps = 1e-8;
int n,cnt,pri[maxn],num[maxn],a[maxn];
bool vis[maxn];
int qpow(int a,int b)
{
int res = 1;
while(b)
{
if(b&1) res *= a;
a *= a;
b >>= 1;
}
return res;
}
signed main()
{
for(int i = 2;i < maxn;i++)
{
if(!vis[i]) pri[++cnt] = i;
for(int j = 1;j<=cnt && i*pri[j]<maxn;j++)
{
vis[i*pri[j]] = 1;
if(i%pri[j] == 0) break;
}
}
n = read();
for(int i = 1;i <= n;i++) a[i] = read();
for(int i = 1;i <= n;i++)
{
for(int j = 1;pri[j] <= a[i];j++)
{
if(a[i]%pri[j]) continue;
while(a[i]%pri[j]==0)
{
num[j]++;
a[i] /= pri[j];
}
}
}
ll res = 1;
for(int i = 1;i <= cnt;i++) if(num[i]) res *= qpow(pri[i],num[i]/n);
cout<<res<<endl;
return 0;
}
