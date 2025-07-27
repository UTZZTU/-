#include<bits/stdc++.h>
#define MAXN 500010
#define EXP 32//32
const int INF=0x3f3f3f3f;
using namespace std;
typedef long long ll;

int root[MAXN],LSH[MAXN];
struct Tree{
    int tot;
    int L[MAXN*EXP],R[MAXN*EXP],SUM[MAXN*EXP];
    
    void init()
    {
        tot=0;
        memset(L,0,sizeof(L));
        memset(R,0,sizeof(R));
        memset(SUM,0,sizeof(SUM));
    }
    
    int build(int l,int r)
    {
        int id=++tot;
        if(l<r)
        {
            int mid=(l+r)/2;
            L[id]=build(l,mid);
            R[id]=build(mid+1,r);
        }
        return id;
    }
    
    int update(int pre,int l,int r,int x)
    {
        int id=++tot;
        L[id]=L[pre];R[id]=R[pre];SUM[id]=SUM[pre]+1;
        if(l<r)
        {
            int mid=(l+r)/2;
            if(x<=mid) L[id]=update(L[pre],l,mid,x);
            else R[id]=update(R[pre],mid+1,r,x);
        }
        return id;
    }
    
    int Kth(int u,int v,int l,int r,int k)//求第k小的数的下标
    {
        if (l >= r) return l;
        int x = SUM[L[v]] - SUM[L[u]];
        int mid=(l+r)/2;
        if (x >= k) return Kth(L[u], L[v], l, mid, k);
        else return Kth(R[u], R[v], mid+1, r, k-x);
    }

        
    int lessOrEqualK(int u,int v,int l,int r,int k)//求小于等于k的有多少个
    {
        int mid = (l + r) / 2;
        int ans = 0;
        if (l == r) {
            return SUM[v] - SUM[u];
        }
        if (k <= mid) {
            ans += lessOrEqualK(L[u], L[v], l, mid, k);
        } else {
            ans += SUM[L[v]] - SUM[L[u]];//左区间的全部符合题意，直接加上
            ans += lessOrEqualK(R[u], R[v], mid + 1, r, k);
        }
        return ans;
    }
}tree;

int n,m,a[MAXN];
ll l,r;
ll k;
int Fmax[MAXN][27];
int Fmin[MAXN][27];
void MM()
{
    for(int j=1;j<=floor(log(n)/log(2));j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            Fmax[i][j]=max(Fmax[i][j-1],Fmax[i+(1<<(j-1))][j-1]);
            Fmin[i][j]=min(Fmin[i][j-1],Fmin[i+(1<<(j-1))][j-1]);
		}
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){scanf("%d",&a[i]);LSH[i]=a[i]; Fmax[i][0]=a[i];Fmin[i][0]=a[i];}
    MM();
    sort(LSH+1, LSH+1+n);
    int N = unique(LSH+1, LSH+1+n)-LSH-1;//离散化
    tree.init();

    root[0]=tree.build(1,N);
    for(int i=1;i<=n;i++){
        int tmp = lower_bound(LSH+1, LSH+1+N, a[i])-LSH;
        root[i]=tree.update(root[i-1],1,N,tmp);
    }
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&l,&r,&k);
        int p=floor(log(r-l+1)/log(2));
        int maxx=max(Fmax[l][p],Fmax[r-(1<<p)+1][p]);
        int minn=min(Fmin[l][p],Fmin[r-(1<<p)+1][p]);
//        cout<<"maxx:"<<maxx<<" minn:"<<minn<<endl;
        if(k>maxx+5)
        {
        	printf("%lld\n",k+r-l);
		}
		else if(k<minn-5)
		{
			printf("%lld\n",k-1);
		}
		else
		{
			ll ll=0,rr=1e7+10,mid;
			while(ll<rr)
			{
				mid=ll+rr>>1;
				int tmp = upper_bound(LSH+1, LSH+1+N, mid)-LSH-1;
				int ans=tree.lessOrEqualK(root[l-1],root[r],1,N,tmp);
				if(tmp==0) ans=0;
				if((mid+1)-ans>=k)
				{
					rr=mid;
				}
				else
				{
					ll=mid+1;
				}
			}
			printf("%lld\n",ll);
		}
        
    }

    return 0;
}
