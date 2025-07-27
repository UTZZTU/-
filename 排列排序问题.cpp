#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,a[N];
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	int res=0,p=0,f=0;
	for(int i=1;i<=n;i++){
		if(!p) p=a[i];
		else{
			if(f==1){
				if(a[i]==p+1){
					p=a[i];
					continue;
				}
				else{
					res++;
					p=a[i];
					f=0;
				}
			}
			else if(f==-1){
				if(a[i]==p-1){
					p=a[i];
					continue;
				}
				else{
					res++;
					p=a[i];
					f=0;
				}
			}
			else{
				if(a[i]==p+1) p=a[i],f=1;
				else if(a[i]==p-1) p=a[i],f=-1;
				else{
					res++;
					p=a[i];
					f=0;
				}
			}
		}
//		cout<<f<<" "<<p<<endl;;
	}
	cout<<res;
	return 0;
}