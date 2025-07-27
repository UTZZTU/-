#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int t,n,m,a[N]; 
int p[N],vis[N],d[N],flag;
vector<pair<int,int> >v;
int find(int x){
	if(x!=p[x]) p[x]=find(p[x]);
	return p[x];
}
int h[N],e[N],w[N],ne[N],idx;
void add(int a,int b,int c){
	e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
signed main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) p[i]=i,h[i]=-1;
		for(int i=1;i<=m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			v.push_back({x,y});
			vis[x]=1;
			vis[y]=1;
			
			x=find(x),y=find(y);
			flag=0;
			idx=0;
			if(x==y){
				flag=0;
				memset(d,0,sizeof d);
				for(int j=0;j<i;j++){
					add(v[j].first,v[j].second,j+1);
					add(v[j].second,v[j].first,j+1);
					d[v[j].first]++;
					d[v[j].second]++;
//					cout<<v[j].first<<" "<<v[j].second<<" "<<j+1<<endl;
				}				
				
				queue<int>q;				
				for(int j=1;j<=n;j++){
					if(d[j]==1) q.push(j),vis[x]=0;
//					cout<<d[j]<<" ";
				}
				while(q.size()){
					puts("------------------");
					int x=q.front();
//					cout<<x<<endl;
					q.pop();
					vis[x]=0;
					for(int j=h[x];~j;j=ne[j]){
						int k=e[j];
//						cout<<k<<" ";
						if(--d[k]==1){
							q.push(k);
						}
//						cout<<k<<" "<<d[k]<<endl;
					}
				}
//				for(int i=1;i<=n;i++) cout<<vis[i]<<" ";
				set<int>res;
				for(int j=1;j<=n;j++){
					if(vis[j]){
//						cout<<j<<endl;
						for(int k=h[j];~k;k=ne[k]){
							int pp=e[k];
//							cout<<j<<" "<<pp<<" "<<w[k]<<" "<<vis[pp]<<endl;
							if(vis[pp])
							{
								res.insert(w[k]);
//								cout<<w[pp]<<endl;
							}
						}
//						vis[j]=0;
					}
				}
//				sort(res.begin(),res.end());
				int ff=1;
				for(auto it:res){
					if(ff) ff=0;
					else printf(" ");
					printf("%d",it);
				}
				puts("");
				flag=1;
				break;
			}
			else p[x]=y;
		}
		if(!flag) puts("-1");
	}
	return 0;
}
