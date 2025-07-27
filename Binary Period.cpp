#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
#define mst(a) memset(a,0,sizeof a)
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		string a;
		cin>>a;
		int f1=0,f2=0;
		for(int i=0;i<a.size();i++)
			if(a[i]=='0') f1=1;
			else f2=1;
		if(f1&&f2){
		 for(int i=0;i<2*a.size();i++)
					printf("%c",'0'+(i%2));
					puts("");
				}
		else cout<<a<<endl;
	}
	return 0;
} 