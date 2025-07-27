#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<ll,int> P;
#define fi first
#define se second
#define pb push_back
#define dbg(x) cerr<<(#x)<<":"<<x<<" ";
#define dbg2(x) cerr<<(#x)<<":"<<x<<endl;
#define SZ(a) (int)(a.size())
#define sci(a) scanf("%d",&(a))
#define pt(a) printf("%d",a);
#define pte(a) printf("%d\n",a)
#define ptlle(a) printf("%lld\n",a)
#define debug(...) fprintf(stderr, __VA_ARGS__)
typedef unsigned ui;
//typedef __uint128_t L;
typedef unsigned long long L;
typedef unsigned long long ull;
const int N=1e6+10,Q=(1<<19)+5,M=320;
const double PI=acos(-1.0);
int t,n;
struct Point{
	ll x,y;
}e[N*2];
db det(Point a,Point b){
	return a.x*b.y-a.y*b.x;
}
bool cmp(Point a,Point b){
	if(!det(a,b))return a.x<b.x;
	return det(a,b)>=0;
}
int f(Point a){
	if(a.x>0 && a.y>=0)return 1;
	if(a.x<=0 && a.y>0)return 2;
	if(a.x<0 && a.y<=0)return 3;
	if(a.x>=0 && a.y<0)return 4;
	return 0;
}
bool cmp2(Point a,Point b){
	if(f(a)!=f(b))return f(a)<f(b);
	return cmp(a,b);
}
int main(){
	sci(t);
	while(t--){
		sci(n);
		rep(i,1,n){
			scanf("%lld%lld",&e[i].x,&e[i].y);
		}
		sort(e+1,e+n+1,cmp2);
		int m=2*n;
		rep(i,n+1,m){
			e[i]=e[i-n];
		}
		int j=1,ans=0;
		rep(i,1,n){
			j=max(j,i);
			Point c;
			c.x=-e[i].x;
			c.y=-e[i].y;
			while(j+1<=i+n-1 && det(c,e[j+1])<=0){
				j++;
			}
			//printf("i:%d (%lld,%lld) fan:(%lld,%lld) j:%d\n",i,e[i].x,e[i].y,c.x,c.y,j);
			ans=max(ans,j-i+1);
		}
		printf("%d\n",n-ans);
	}
	return 0;
}
