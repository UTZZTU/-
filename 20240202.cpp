#include<algorithm>
#include<cstdio>
const long long mod = 1e9+7;
#define G 3
#define Maxn 270000
using namespace std;
int n,k,r[Maxn<<2];
long long invn,invG;
long long fac[Maxn],inv[Maxn];
long long powM(long long a,long long t=mod-2)
{
  long long ans=1,buf=a;
  while(t){
  	if(t&1)ans=(ans*buf)%mod;
  	buf=(buf*buf)%mod;
  	t>>=1;
  }return ans;
}
void NTT(long long *f,bool op,int n)
{
  for (int i=0;i<n;i++)
    if (r[i]<i)swap(f[r[i]],f[i]);
  for (int len=1;len<n;len<<=1){
    int w=powM(op==1 ? G:invG,(mod-1)/len/2);
  	for (int p=0;p<n;p+=len+len){
  	  long long buf=1;
  	  for (int i=p;i<p+len;i++){
  	  	int sav=f[i+len]*buf%mod;
  	  	f[i+len]=f[i]-sav;
  	  	if (f[i+len]<0)f[i+len]+=mod;
  	  	f[i]=f[i]+sav;
  	  	if (f[i]>=mod)f[i]-=mod;
  	  	buf=buf*w%mod;
	    }//F(x)=FL(x^2)+x*FR(x^2)
	     //F(W^k)=FL(w^k)+W^k*FR(w^k)
	     //F(W^{k+n/2})=FL(w^k)-W^k*FR(w^k)
    }
  }
}
long long g[Maxn<<2];
void rev(long long *f,int len)
{
  for (int i=0;i<len;i++)g[i]=f[i];
  for (int i=0;i<len;i++)f[len-i-1]=g[i];
}
//令f=f*g (mod x^lim) 
void times(long long *f,long long *gg,int len,int lim)
{
  int m=len+len,n;
  for(int i=0;i<len;i++)g[i]=gg[i];
  for(n=1;n<m;n<<=1);invn=powM(n);
  for(int i=len;i<n;i++)g[i]=0;
  for(int i=0;i<n;i++)
    r[i]=(r[i>>1]>>1)|((i&1)?n>>1:0);
  NTT(f,1,n);NTT(g,1,n);
  for(int i=0;i<n;++i)f[i]=(f[i]*g[i])%mod;
  NTT(f,0,n);
  for(int i=0;i<lim;++i)f[i]=(f[i]*invn)%mod;
  for(int i=lim;i<n;++i)f[i]=0;
}
void Init(int lim)
{
  inv[1]=inv[0]=fac[0]=1;
  for (int i=1;i<=lim;i++)fac[i]=fac[i-1]*i%mod;
  for (int i=2;i<=lim;i++)
  	inv[i]=inv[mod%i]*(mod-mod/i)%mod;
  for (int i=2;i<=lim;i++)inv[i]=inv[i-1]*inv[i]%mod;
  for (int i=1;i<=lim;i++)inv[i]=powM(fac[i]);
}
long long p[Maxn<<2];
//求出F(x-c) 
void fminus(long long *s,long long *f,int len,int c)
{
  c=mod-c;
  for (int i=0;i<len;i++)
    p[len-i-1]=f[i]*fac[i]%mod;
  long long buf=1;
  for (int i=0;i<len;i++,buf=buf*c%mod)
    s[i]=buf*inv[i]%mod;
  times(p,s,len,len);
  for (int i=0;i<len;i++)s[len-i-1]=p[i]*inv[len-i-1]%mod;
  for (int i=len;i<len+len;i++)s[i]=0;
}
long long f[Maxn<<2],s[Maxn<<2];
void solve(long long *f,int n)
{
  if (n==1){f[0]=0;f[1]=1;}
  else if (n&1){
    solve(f,n-1);f[n]=0;
    //再乘上(x-n+1)就好了
    for (int i=n;i>0;i--)
      f[i]=(f[i-1]+(mod-n+1)*f[i])%mod;
    f[0]=f[0]*(mod-n+1)%mod;
  }else {
    solve(f,n/2);
    //S(x)=F(x+n/2)
    fminus(s,f,n/2+1,n/2);
    times(f,s,n/2+1,n+1);
  }
}
void invp(long long *f,int len)
{
  for (int i=0;i<k+1;i++)s[i]=p[i]=0;
  //注意清空 
  long long *r=s,*rr=p;
  int n=1;for(;n<len;n<<=1);
  rr[0]=powM(f[0]);
  for (int len=2;len<=n;len<<=1){
  	for (int i=0;i<len;i++)
  	  r[i]=rr[i]*2%mod;
  	times(rr,rr,len/2,len);
  	times(rr,f,len,len);
  	for (int i=0;i<len;i++)
  	  rr[i]=(r[i]-rr[i]+mod)%mod;
  }for (int i=0;i<len;i++)
    f[i]=rr[i];
}
int main()
{
  scanf("%d%d",&n,&k);
  if (k>n){
    for (int i=0;i<=n;i++)printf("0 ");
    return 0;
  }invG=powM(G);
  Init(k);solve(f,k+1);
  for (int i=0;i<k+1;i++)f[i]=f[i+1];
  rev(f,k+1);
  for (int i=n-k+1;i<k+1;i++)f[i]=0;
  for (int i=k+1;i<n-k+1;i++)f[i]=0;
  invp(f,n-k+1);
//  for (int i=0;i<k;i++)printf("0 ");
//  for (int i=0;i<n-k+1;i++)printf("%lld ",f[i]);
printf("%lld\n",f[n-k]);
  return 0;
}