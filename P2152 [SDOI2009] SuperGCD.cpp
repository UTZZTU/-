#include<bits/stdc++.h>
#define int long long
#define N 100000000
using namespace std;
int A[100005];
namespace bigint{
	using namespace std;
	struct cal{
		int n;
		int a[5005];
		inline void clear(){
			memset(a,0,sizeof(a));
			n=0;
		}
		inline void work(){
			while(n>1&&!a[n])
				n--;
		}
		inline cal read(){
			memset(A,0,sizeof(A));
			clear();
			char ch=getchar();
			while(ch<'0'||ch>'9')
				ch=getchar();
			while(ch<='9'&&ch>='0')
				A[++n]=ch-'0',ch=getchar();
			for(int i=1; i+i<=n; ++i)
				swap(A[i],A[n-i+1]);
			for(int i=1; i<=n; i+=8){
				int j=(i+7)/8;
				a[j]=(A[i]+A[i+1]*10+A[i+2]*100+A[i+3]*1000+A[i+4]*10000+A[i+5]*100000+A[i+6]*1000000+A[i+7]*10000000);
			}
			n=(n+7)/8;
			return *this;
		}
		inline cal write() const{
			printf("%lld",a[n]);
			for(int i=n-1; i>=1; --i)
				printf("%08lld",a[i]);
			putchar('\n');
			return *this;
		}
		inline bool operator < (const cal &nt) const{
			if(n<nt.n)
				return 1;
			if(n>nt.n)
				return 0;
			for(int i=n; i>=1; --i)
				if(a[i]!=nt.a[i])
					return a[i]<nt.a[i];
			return 0;
		}
		inline bool operator > (const cal &nt) const{
			return nt<*this;
		}
		inline bool operator != (const cal &nt) const{
			return (*this<nt) || (nt<*this);
		}
		inline bool operator == (const cal &nt) const{
			return !(*this!=nt);
		}
		inline cal operator = (const int &nt){
			n=0;
			int x=nt;
			while(x){
				a[++n]=x%N;
				x/=N;
			}
			return *this;
		}
		inline cal operator + (const cal &nt) const{
			cal tmp;
			tmp.clear();
			tmp.n=max(n,nt.n)+1;
			for(int i=1; i<=tmp.n; ++i){
				tmp.a[i]+=a[i]+nt.a[i];
				tmp.a[i+1]+=tmp.a[i]/N;
				tmp.a[i]%=N;
			}
			tmp.work();
			return tmp;
		}
		inline cal operator - (const cal &nt) const{
			cal tmp;
			tmp.clear();
			int x=0;
			tmp.n=n;
			for(int i=1; i<=tmp.n; ++i){
				x+=a[i]-nt.a[i];
				if(x<0)
					tmp.a[i]=x+N,x=-1;
				else
					tmp.a[i]=x,x=0;
			}
			tmp.work();
			return tmp;
		}
		inline cal operator * (const cal &nt) const{
			cal tmp;
			tmp.clear();
			tmp.n=n+nt.n;
			for(int i=1; i<=n; ++i)
				for(int j=1; j<=nt.n; ++j){
					tmp.a[i+j-1]+=a[i]*nt.a[j];
					tmp.a[i+j]+=tmp.a[i+j-1]/N;
					tmp.a[i+j-1]%=N;
				}
			for(int i=1; i<=tmp.n; ++i){
				tmp.a[i+1]+=tmp.a[i]/N;
				tmp.a[i]%=N;
			}
			tmp.work();
			return tmp;
		}
		inline cal operator / (const int &nt) const{
			cal tmp;
			tmp.clear();
			int x=0;
			tmp.n=n;
			for(int i=n; i>=1; --i){
				x=x*N+a[i];
				tmp.a[i]=x/nt;
				x%=nt;
			}
			tmp.work();
			return tmp;
		}
		inline cal operator += (const cal &nt){
			return *this=*this+nt;
		}
		inline cal operator -= (const cal &nt){
			return *this=*this-nt;
		}
		inline cal operator *= (const cal &nt){
			return *this=*this*nt;
		}
		inline cal operator /= (const int &nt){
			return *this=*this/nt;
		}
	};
	inline cal gcd(cal a,cal b){
		int na=0,nb=0;
		while(!(a.a[1]&1))
			na++,a/=2;
		while(!(b.a[1]&1))
			nb++,b/=2;
		int x=min(na,nb);
		while(a!=b){
			if(a<b)
				swap(a,b);
			a=a-b;
			while(!(a.a[1]&1))
				a/=2;N
		}
		cal t;
		t=2;
		while(x--)
			a*=t;
		return a;
	}
}
using namespace bigint;
cal a,b;
signed main(){
	a.read();
	b.read();
	gcd(a,b).write();
	return 0;
}
/*
import fractions
print(fractions.gcd(int(input()),int(input())))
pypy3
*/