#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e6+10;
int fa[N],a[N],n,s[N],maxx,pri[N],cnt;
bool isp[N];
void init(){
    for(int i = 2;i<N;i++){
        if(!isp[i]) pri[cnt++] = i;
        for(int j = 0;i*pri[j]<N;j++){
            isp[i*pri[j]] = 1;
            if(i%pri[j]==0) break;
        }
    }
    for(int i = 0;i<cnt;i++){
        for(ll j = 1;j<N;j*=pri[i]) isp[j] = false;
    }
}
int find(int x)
{
	while(x!=fa[x])
	x=fa[x]=fa[fa[x]];
	return x;
}
bool judge(int x,int y)
{
	int t=__gcd(x,y);
	return isp[t];
}
int main ()
{
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		s[i]=1;
		scanf("%d",&a[i]);
	}
	int k=n-1,l,r,tx,ty;
	while(k--)
	{
		scanf("%d%d",&l,&r);
			if(judge(a[l],a[r]))
			{
				tx=find(l),ty=find(r);
				fa[ty]=tx;
				s[tx]+=s[ty];
			}
	}
	for(int i=1;i<=n;i++)
	{
		maxx=max(maxx,s[i]);
	}
	cout<<maxx;
	return 0;
}