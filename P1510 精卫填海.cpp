#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define int long long
#define MAXN 10000+3
using namespace std;

inline int read(){//（推销一波）如老衲所见 必有大数据 所以还是有必要来个快读优化的QAQ 
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0'; ch=getchar();}
    return x*f;
}

int vn,n,c,sum;//vn：need—v（所需总体积） n：石子个数 c：总体力 
int v[MAXN],w[MAXN],f[MAXN];//v：石子体积 w：所需体力  

signed main()
{
	vn=read(),n=read(),c=read();
	for(int i=1;i<=n;i++){
		v[i]=read(),w[i]=read();
//		cout<<v[i]<<" "<<w[i]<<endl;
		sum+=v[i];
//		cout<<sum<<endl;
	}
	if(sum<vn){//若石子总体积<vn，直接输出Impossible （特判一波）
		cout<<"Impossible"<<endl;
		return 0;
	}
//	cout<<"ha"<<endl;静态测试 检查代码在哪里出的锅QAQ 
	for(int i=1;i<=n;i++){
		for(int j=c;j>=w[i];j--){
			f[j]=max(f[j],f[j-w[i]]+v[i]);
		}
	}
	for(int i=0;i<=vn;i++){//从小到大搜 第一个大于vn的直接输出
		if(f[i]>=vn){
			cout<<c-i<<endl;
			return 0;
		}
	}
	cout<<"Impossible"<<endl;
	return 0;
}