#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int t,n,m,k,cnt[N];
int p[N],s[N];
int find1(int x){
	if(x!=p[x]) p[x]=find1(p[x]);
	return p[x];
}
int find2(int x){
	if(x!=s[x]) s[x]=find2(s[x]);
	return s[x];
}
signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) p[i]=s[i]=i;
	//园路 
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		x=find1(x);
		y=find1(y);
		if(x!=y) p[x]=y;
	}
	
	//交流会 
	scanf("%d",&k);
	while(k--){
		int x,y;
		scanf("%d%d",&x,&y);
		int xx=find1(x);
		int yy=find1(y);
		if(xx==yy){
			int xxx=find2(x);
			int yyy=find2(y);
			if(xxx!=yyy) s[xxx]=yyy;
		}
	}
	
	for(int i=1;i<=n;i++){
		cnt[find2(i)]++;
	}
	int maxx=0,minn=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		if(s[i]==i){
			maxx=max(maxx,cnt[i]);
			minn=min(minn,cnt[i]);
		}
	}
	cout<<maxx<<" "<<minn;
	return 0;
}