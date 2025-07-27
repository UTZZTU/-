//有的东西你可以不用但是不能没有
//比如说本……子任务处理装置
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<typeinfo>
#define ll long long
#define ull usigned long long
namespace Math{
	template<typename T>
	inline T min(T a,T b){return a<b?a:b;}
	template<typename T>
	inline T max(T a,T b){return a>b?a:b;}
	template<typename T>
	inline void swap(T a,T b){T x=a;a=b,b=x;}
	template<typename T>
	inline void GetMin(T &a,T b){a=b<a?b:a;}
	template<typename T>
	inline void GetMax(T &a,T b){a=b>a?b:a;}
	template<typename T>
	inline T gcd(T a,T b){return b==0?a:gcd(b,a%b);}
	template<typename T>
	inline T lcm(T a,T b){return (a*b)/gcd(a,b);}
	template<typename T>
	inline T abs(T x){return x<0?-x:x;}
	#define double long double
	#define eps 1e-200
	inline double fabs(double x){return x+eps<=0?-x:x;}
	#undef eps
	#undef double
	#define eps 1e-80
	inline double fabs(double x){return x+eps<=0?-x:x;}
	#undef eps
	template<typename T>
	inline T pow(T x,T n){
		T res=1;while(n){
			if(n&1) res=res*x;
			n>>=1;x=x*x;
		}return res;
	}
	template<typename T>
	inline T pow(T x,T n,const T Mode){
		T res=1;while(n){
			if(n&1) res=(res*x)%Mode;
			n>>=1;x=(x*x)%Mode;
		}return res%Mode;
	}
	#define double long double
	template<typename T>
	inline double pow(double x,T n){
		double res=1.0;
		while(n){
			if(n&1) res=res*x;
			n>>=1;x=x*x;
		}return res;
	}
	#undef double
	template<typename T>
	inline double pow(double x,T n){
		double res=1.0;
		while(n){
			if(n&1) res=res*x;
			n>>=1;x=x*x;
		}return res;
	}
	#define int __int128
	inline int min(int a,int b){return a<b?a:b;}
	inline int max(int a,int b){return a>b?a:b;}
	inline void swap(int a,int b){int x=a;a=b,b=x;}
	inline void GetMin(int &a,int b){a=b<a?b:a;}
	inline void GetMax(int &a,int b){a=b>a?b:a;}
	inline int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
	inline int lcm(int a,int b){return (a*b)/gcd(a,b);}
	inline int abs(int x){return x<0?-x:x;}
	inline int pow(int x,int n){
		int res=1;while(n){
			if(n&1) res=res*x;
			n>>=1;x=x*x;
		}return res;
	}
	inline int pow(int x,int n,const int Mode){
		int res=1;while(n){
			if(n&1) res=(res*x)%Mode;
			n>>=1;x=(x*x)%Mode;
		}return res%Mode;
	}
	#define double long double
	#define eps 1e-200
	inline double pow(double x,int n){
		double res=1.0;
		while(n){
			if(n&1) res=res*x;
			n>>=1;x=x*x;
		}return res;
	}
	inline double fmin(double a,double b){
		return a+eps<=b?a:b;
	}
	inline double fmax(double a,double b){
		return a-eps>=b?a:b;
	}
	#undef double
	#undef eps
	#define eps 1e-80
	inline double ceil(double x){
		int X=x;
		if(fabs((double)X-x)<=eps) return x;
		else return (double)X+1;
	}
	inline double floor(double x){
		int X=x;return (double)X;
	}
	inline double fmin(double a,double b){
		return a+eps<=b?a:b;
	}
	inline double fmax(double a,double b){
		return a-eps>=b?a:b;
	}
	#undef eps
	inline double pow(double x,int n){
		double res=1.0;
		while(n){
			if(n&1) res=res*x;
			n>>=1;x=x*x;
		}return res;
	}
	#define double long double
	#define eps 1e-200
	inline double ceil(double x){
		int X=x;
		if(fabs((double)X-x)<=eps) return x;
		else return (double)X+1;
	}
	inline double floor(double x){
		return (ll)x;
	}
	#undef double
	#undef eps
	#undef int
}
namespace Char{
	inline int strlen(const char *str){
		int res=0;
		while(str[res]!=0)
			++res;
		return res;
	}
	inline int size(const char *str){
		return strlen(str);
	}
	inline void memset(char *str){
		int len=strlen(str);
		#define int register int
		for(int i=0;i<len;++i)
			str[i]=0;
		#undef int
	}
}
using namespace Char;
using namespace Math;
namespace BigNum{
	struct Num{
		#define N 25
		int num[N],cnt,f;
		inline int getnum(int x[],int cnt,int f){
			int num=0;
			for(int i=cnt;i>=1;i--)
				num=num*10+x[i];
			return num;
		}
		inline void copy(int x1[], int cnt1, int f1, int x2[], int& cnt2, int& f2) {//把高精度数x1完全复制给高精度数ans
			for (int i = 1; i <= cnt1; i++) x2[i] = x1[i];
			cnt2 = cnt1; f2 = f1;
		}template<typename T>
		inline void copynum(int x[],int &cnt,int &f,T num){
			if(num<0) f=-1,num=-num;else f=1;cnt=0;
			while(num>0) x[++cnt]=num%10,num/=10;
			while(x[cnt]==0&&cnt>0) cnt--;
			if(cnt==0) cnt++,x[cnt]=0;
		}
		inline bool ismax(int x1[], int cnt1, int f1, int x2[], int cnt2, int f2) {//判断数x1是不是更大
			if (f1 > f2) return true;
			else if (cnt1 > cnt2) return true;
			else if (f1 < f2) return false;
			else if (cnt1 < cnt2) return false;
			bool ismax = true;
			for (int i = cnt1; i >= 1; i--) if (x1[i] < x2[i]) return false;
			return true;
		}
		inline bool ismin(int x1[], int cnt1, int f1, int x2[], int cnt2, int f2) {//判断数x1是不是更小
			if (f1 > f2) return false;
			else if (cnt1 > cnt2) return false;
			else if (f1 < f2) return true;
			else if (cnt1 < cnt2) return true;
			bool ismax = true;
			for (int i = cnt1; i >= 1; i--) if (x1[i] > x2[i]) return false;
			return true;
		}
		inline void add(int x1[],int cnt1,int x2[],int cnt2,int ans[],int &cnt){
			int anscnt=cnt;int anst[N];int x=0;
			for(int i=1;i<=cnt;i++) anst[i]=ans[i];
			int len=max(cnt1,cnt2);anscnt=0;
			if(len==cnt1) for(int i=cnt2+1;i<=len;i++) x2[i]=0;
			else for(int i=cnt1+1;i<=len;i++) x1[i]=0;
			for(int i=1;i<=len;i++){
				anst[++anscnt]=(x1[i]+x2[i]+x)%10;
				x=(x1[i]+x2[i]+x)/10;
			}
			if(x>0) anst[++anscnt]=x;
			while(!anst[anscnt]&&anscnt>0) anscnt--;
			if(anscnt==0) anscnt=1;cnt=anscnt;
			for(int i=1;i<=anscnt;i++) ans[i]=anst[i];
		}
		inline void minus(int x1[],int cnt1,int x2[],int cnt2,int anst[],int &cnt,int &ansf){
			int cntans=cnt;int ans[N];int f=ansf;
			for(int i=1;i<=cnt;i++) ans[i]=anst[i];
			if (ismin(x1, cnt1, 1, x2, cnt2, 1)) {
				copy(x2, cnt2, 1, ans, cntans, f); f = -f;
				for (int i = cnt1; i >= 1; i--) {
					if (ans[i] < x1[i]) {
						int cnt = i + 1; ans[i] = ans[i] + 10 - x1[i];
						while (ans[cnt] == 0 && cnt <= cntans) ans[cnt] = 9, cnt++;
						ans[cnt]--; while (ans[cntans] == 0) cntans--;
					}
					else ans[i] -= x1[i];
				}while (cntans > 0 && ans[cntans] == 0) cntans--; if (cntans == 0) cntans++;
			}
			else {
				copy(x1, cnt1, 1, ans, cntans, f);
				for (int i = cnt2; i >= 1; i--) {
					if (ans[i] < x2[i]) {
						int cnt = i + 1; ans[i] = ans[i] + 10 - x2[i];
						while (ans[cnt] == 0 && cnt <= cntans) ans[cnt] = 9, cnt++;
						ans[cnt]--; while (ans[cntans] == 0) cntans--;
					}
					else ans[i] -= x2[i];
				}while (ans[cntans] == 0) cntans--; if (cntans == 0) cntans++;
			}
			cnt=cntans;ansf=f;if(cnt==1&&ans[1]==0) ansf=1;
			for(int i=1;i<=cntans;i++) anst[i]=ans[i];
		}
		inline void multiply(int x1[],int cnt1,int f1,int x2[],int cnt2,int f2,int ans[],int &cnt,int &f){
			f=f1*f2;cnt=cnt1+cnt2+1;int anst[N],ansf=f,cntans=cnt;
			for(int i=1;i<=cntans;i++) anst[i]=0;
			for(int i=1;i<=cnt1;i++){
				int temp=0;
				for(int j=1;j<=cnt2;j++){
					anst[i+j-1]=(x1[i]*x2[j]+temp+anst[i+j-1]);
					temp=(x1[i]*x2[j]+anst[i+j-1]+temp)/10;
					anst[i+j-1]%=10;
				}
				anst[i+cnt2]=temp;
			}
			while(anst[cntans]==0&&cntans>0) cntans--;
			if(cntans==0) cntans=1,ansf=1;
			for(int i=1;i<=cntans;i++) ans[i]=anst[i];
			cnt=cntans;f=ansf;return;
		}
		inline void operator += (Num b){
			if (f < 0 && b.f>0) minus(b.num, b.cnt, num, cnt, num, cnt, f);
			else if (f > 0 && b.f < 0) minus(num, cnt, b.num, b.cnt, num, cnt, f);
			else {add(num, cnt, b.num, b.cnt, num, cnt); }
		}
		inline void operator -= (Num b){
			if (b.f < 0 && f>0) { f = 1; add(num, cnt, b.num, b.cnt, num, cnt); }
			else if (f < 0 && b.f>0) { f = -1; add(num, cnt, b.num, b.cnt, num, cnt); }
			else if (f > 0 && b.f > 0) minus(num, cnt, b.num, b.cnt, num, cnt, f);
			else if (f < 0 && b.f < 0) minus(b.num, b.cnt, num, cnt, num, cnt, f);
		}
		inline Num operator + (Num b){
			Num c;if (f < 0 && b.f>0) minus(b.num, b.cnt, num, cnt, c.num, c.cnt, c.f);
			else if (f > 0 && b.f < 0) minus(num, cnt, b.num, b.cnt, c.num, c.cnt, c.f);
			else {add(num, cnt, b.num, b.cnt, c.num, c.cnt); }return c;
		}
		inline Num operator - (Num b){
			Num c;if (b.f < 0 && f>0) { f = 1; add(num, cnt, b.num, b.cnt, c.num, c.cnt); }
			else if (f < 0 && b.f>0) { f = -1; add(num, cnt, b.num, b.cnt, c.num, c.cnt); }
			else if (f > 0 && b.f > 0) minus(num, cnt, b.num, b.cnt, c.num, c.cnt, c.f);
			else if (f < 0 && b.f < 0) minus(b.num, b.cnt, num, cnt, c.num, c.cnt, c.f);
			return c;
		}
		inline void operator = (Num b){copy(b.num,b.cnt,b.f,num,cnt,f);}
		template<typename T>inline void operator = (T b){copynum(num,cnt,f,b);}
		inline void operator ++ (){
			Num c;c=1;
			if (f < 0 && c.f>0) minus(c.num, c.cnt, num, cnt, num, cnt, f);
			else if (f > 0 && c.f < 0) minus(num, cnt, c.num, c.cnt, num, cnt, f);
			else {add(num, cnt, c.num, c.cnt, num, cnt); }
		}
		inline void operator -- (){
			Num c;c=-1;
			if (f < 0 && c.f>0) minus(c.num, c.cnt, num, cnt, num, cnt, f);
			else if (f > 0 && c.f < 0) minus(num, cnt, c.num, c.cnt, num, cnt, f);
			else {add(num, cnt, c.num, c.cnt, num, cnt); }
		}
		inline bool operator >= (Num b){return ismax(num,cnt,f,b.num,b.cnt,b.f);}
		template<typename T>inline bool operator >= (T b){
			Num c;c=b;return ismax(num,cnt,f,c.num,c.cnt,c.f);
		}
		inline bool operator <= (Num b){return ismin(num,cnt,f,b.num,b.cnt,b.f);}
		template<typename T>inline bool operator <= (T b){
			Num c;c=b;return ismin(num,cnt,f,c.num,c.cnt,c.f);
		}
		inline bool operator == (Num b){
			return ismax(num,cnt,f,b.num,b.cnt,b.f)&&ismin(num,cnt,f,b.num,b.cnt,b.f);
		}
		template<typename T>inline bool operator == (T b){
			Num c;c=b;
			return ismin(num,cnt,f,c.num,c.cnt,c.f)&&ismax(num,cnt,f,b.num,b.cnt,b.f);
		}
		inline bool operator > (Num b){return !ismin(num,cnt,f,b.num,b.cnt,b.f);}
		inline bool operator < (Num b){return !ismax(num,cnt,f,b.num,b.cnt,b.f);}
		template<typename T>inline bool operator > (T b){
			Num c;c=b;return !ismin(num,cnt,f,c.num,c.cnt,c.f);
		}
		template<typename T>inline bool operator < (T b){
			Num c;c=b;return !ismax(num,cnt,f,c.num,c.cnt,c.f);
		}
		inline Num operator * (Num b){
			Num c;
			multiply(num,cnt,f,b.num,b.cnt,b.f,c.num,c.cnt,c.f);
			return c;
		}
		inline void operator *= (Num b){multiply(num,cnt,f,b.num,b.cnt,b.f,num,cnt,f);}
	};
	inline int GetNum(Num a){return a.getnum(a.num,a.cnt,a.f);}
	inline void read(Num &a){
		a.cnt=0;a.f=1;char ch=getchar();
		while(ch<'0'||ch>'9'){if(ch=='-') a.f=-a.f;ch=getchar();}
		while(ch>='0'&&ch<='9'){a.num[++a.cnt]=ch-'0';ch=getchar();}
		for(int i=1;i<=a.cnt/2;i++) swap(a.num[i],a.num[a.cnt-i+1]);
	}
	inline void write(Num x){
		if(x.f<0) putchar('-');
		for(int i=x.cnt;i>=1;i--)
			putchar(x.num[i]+'0');
		putchar('\n');return;
	}
	#undef N
}
namespace Read{
	//不能读入char
//	char buf[1<<20],*p1,*p2;
//	#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,1<<20,stdin), p1 == p2) ? 0 : *p1++)
	inline void read128(__int128 &x){
	    bool f=1;x=0;char ch=getchar();
	    while(ch<'0'||ch>'9'){if(ch=='-') f=!f;ch=getchar();}
	    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	    x=(f?x:-x);return;
	}
    inline void write128(__int128 x){
        if(x<0) putchar('-'),x=-x;
        if(x>9) write128(x/10);
        putchar(x%10+'0');return;
    }
 
	inline void readD(double &x){scanf("%lf",&x);}
 
	inline void writeD(double x){printf("%lf",x);}
 
	inline void writeD(double x,int len){printf("%.*lf",len,x);}
 
	template<typename T>inline void readT(T &x){
	    bool f=1;x=0;char ch=getchar();
	    while(ch<'0'||ch>'9'){if(ch=='-') f=!f;ch=getchar();}
	    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	    x=(f?x:-x);return;
	}
	template<typename T>
	inline void writeT(T x){
	    if(x<0) putchar('-'),x=-x;
	    if(x>9) writeT(x/10);
	    putchar(x%10+'0');return;
	}
 
	inline void readS(std::string &s){
		char ch=getchar();
		while(ch==' '||ch=='\n') ch=getchar();
		while(ch!=' '&&ch!='\n') s+=ch,ch=getchar();
	}
 
	inline void readSL(std::string &s){
		char ch=getchar();
		while(ch=='\n') ch=getchar();
		while(ch!='\n') s+=ch,ch=getchar();
	}
 
	inline void writeS(std::string s){
		int len=s.length();
		for(int i=0;i<len;i++)
			putchar(s[i]);
	}
 
	inline int readC(char s[]){
		int tot=0;char ch=getchar();
		while(ch==' '||ch=='\n') ch=getchar();
		while(ch!=' '&&ch!='\n') s[tot++]=ch,ch=getchar();
		return tot;
	}
	inline void writeC(char s[],int len){
		for(int i=0;i<len;i++)
			putchar(s[i]);
	}
 
	inline void readc(char &c){
		c=getchar();
		while(c==' '||c=='\n')
			c=getchar();
	}inline void writec(char c){putchar(c);}
 
	const std::string c="c";
	const std::string i="i";
	const std::string j="j";
	const std::string X="x";
	const std::string y="y";
	const std::string b="b";
	const std::string s="s";
	const std::string Ss="Ss";
 
	template<class T>
	inline void read(T &x) {
		if(typeid(x).name()==i) readT(x);
		else if(typeid(x).name()==j) readT(x);
		else if(typeid(x).name()==X) readT(x);
		else if(typeid(x).name()==y) readT(x);
		if(typeid(x).name()==b){
			int k;readT(k);
			x=(k>0?true:false);
		}else if(typeid(x).name()==s) readT(x);
		else if(typeid(x).name()==c){char ch;readc(ch);x=ch;}
	}
	template<class T,class... Ts>
	inline void read(T &x,Ts&... xx){
		if(typeid(x).name()==i) readT(x);
		else if(typeid(x).name()==j) readT(x);
		else if(typeid(x).name()==X) readT(x);
		else if(typeid(x).name()==y) readT(x);
		if(typeid(x).name()==b){
			int k;readT(k);
			x=(k>0?true:false);
		}else if(typeid(x).name()==s) readT(x);
		else if(typeid(x).name()==c){char ch;readc(ch);x=ch;}
		read(xx...);
	}
	inline void read(std::string &x){readS(x);}
 
	inline void read(char x[]){readC(x);}
 
	inline void read(double &x){readD(x);}
 
	inline void write(double x){writeD(x);}
 
	inline void write(double x,int len){writeD(x,len);}
 
	inline void write(std::string x){writeS(x);}
 
	inline void write(char x[]){writeC(x,strlen(x));}
 
	inline void write(double x,char a){writeD(x);putchar(a);}
 
	inline void write(std::string x,char a){writeS(x);putchar(a);}
 
	inline void write(char x[],char a){writeC(x,strlen(x));putchar(a);}
 
	inline void write(double x,int len,char a){writeD(x,len);putchar(a);}
 
	template<class T>inline void write(T x,char a){
		if(typeid(x).name()==i) writeT(x);
		else if(typeid(x).name()==j) writeT(x);
		else if(typeid(x).name()==X) writeT(x);
		else if(typeid(x).name()==y) writeT(x);
		if(typeid(x).name()==b){
			if(x) writeT(1);
			else writeT(0);
		}else if(typeid(x).name()==s) writeT(x);
		else if(typeid(x).name()==c){writec(x);}
		putchar(a);
	}
	inline void write(double x,std::string a){writeD(x);writeS(a);}
 
	inline void write(std::string x,std::string a){writeS(x);writeS(a);}
 
	inline void write(char x[],std::string a){writeC(x,strlen(x));writeS(a);}
 
	inline void write(double x,int len,std::string a){writeD(x,len);writeS(a);}
 
	inline void write(char a,std::string s){writec(a);writeS(s);}
 
	template<typename T>inline void write(T x,std::string a){
		if(typeid(x).name()==i) writeT(x);
		else if(typeid(x).name()==j) writeT(x);
		else if(typeid(x).name()==X) writeT(x);
		else if(typeid(x).name()==y) writeT(x);
		if(typeid(x).name()==b){
			if(x) writeT(1);
			else writeT(0);
		}else if(typeid(x).name()==s) writeT(x);
		else if(typeid(x).name()==c){writec(x);}
		writeS(a);
	}
	template<typename T>inline void write(T x){
		if(typeid(x).name()==i) writeT(x);
		else if(typeid(x).name()==j) writeT(x);
		else if(typeid(x).name()==X) writeT(x);
		else if(typeid(x).name()==y) writeT(x);
		if(typeid(x).name()==b){
			if(x) writeT(1);
			else writeT(0);
		}else if(typeid(x).name()==s) writeT(x);
		else if(typeid(x).name()==c) writec(x);
	}
	template<typename T,typename... Ts>
	inline void write(T x,Ts... xx){
		if(typeid(x).name()==i) writeT(x);
		else if(typeid(x).name()==j) writeT(x);
		else if(typeid(x).name()==X) writeT(x);
		else if(typeid(x).name()==y) writeT(x);
		if(typeid(x).name()==b){
			if(x) writeT(1);
			else writeT(0);
		}
		else if(typeid(x).name()==s) writeT(x);
		else if(typeid(x).name()==c){writec(x);}
		write(xx...);
	}
	inline void put(std::string s){
		int len=s.length();
		for(int i=0;i<len;i++){
			putchar(s[i]);
		}
	}
}
namespace File{
	inline void OpenInFile(const char *InName){
		freopen(InName,"r",stdin);
	}
	inline void OpenOutFile(const char *OutName){
		freopen(OutName,"r",stdin);
	}
	inline void OpenFile(const char *InName,const char *OutName){
		OpenInFile(InName);
		OpenOutFile(OutName);
	}
	inline void CloseInFile(){
		fclose(stdin);
	}
	inline void CloseOutFile(){
		fclose(stdout);
	}
	inline void CloseFile(){
		CloseInFile();
		CloseOutFile();
	}
	inline void Clear(){
		std::cin.clear();
		std::cout.clear();
	}
}//以上的东西可以不用，但是不能没有
inline void work(){
	
}signed main(){
	//这里加文件操作
	 
	work();
}