#include <bits/stdc++.h>
using namespace std;
int n,m,q,a,b,fa[20010],c,d;
int find(int x){
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
	return x;
}
int main ()
{
	for(int i=1;i<=20000;i++){
		fa[i]=i;
	}
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&a,&b);
		c=find(a),d=find(b);
		if(c!=d){
			fa[c]=d;
		}
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&a,&b);
		c=find(a),d=find(b);
		if(c==d){
			printf("Yes\n");
		}else {
			printf("No\n");
		}
	}
	return 0;
}