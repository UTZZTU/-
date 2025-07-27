#include <bits/stdc++.h>
using namespace std;
int t,n,m,a[10],b[10],c[10],maxx;
int main ()
{
	cin>>t;
	while(t--){
		maxx=0;
		cin>>n>>m;
		int pos[10];
		for(int i=1;i<=n;i++){
			pos[i]=i;
			cin>>a[i]>>b[i]>>c[i];
		}
		do{
			
			int ti=0,res=0;
			for(int i=1;i<=n;i++){
				if(ti+b[pos[i]]<=m){
					ti+=b[pos[i]];
					res+=max(a[pos[i]]*0.3,a[pos[i]]-c[pos[i]]*50-a[pos[i]]*0.004*ti);
				}
			}
			maxx=max(maxx,res);
		}while(next_permutation(pos+1,pos+1+n));
		cout<<maxx;	
	}
	return 0;
}