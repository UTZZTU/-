#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e5+10;
struct edge{int to,w;edge(int a,int b):to(a),w(b){}};
struct node{
	int id,dis;
	node(int a,int b):id(a),dis(b){}
	bool operator<(const node &a)const{return dis>a.dis;}
};
int n,m,r;
vector<edge>e[N];
priority_queue<int>v;
void Dijkstra(){
	int s=1,dis[N],done[N];	
	for(int i=1;i<=n;i++)	dis[i]=INF,done[i]=0;
	dis[s]=0;
	priority_queue<node>q;
	q.push(node(s,dis[s]));
	while(!q.empty()){
		node u=q.top();
		q.pop();
		if(done[u.id]==1) continue;
		done[u.id]=1;
		for(int i=0;i<e[u.id].size();i++){
			edge x=e[u.id][i];
			if(done[x.to]) continue;
			if(dis[x.to]>x.w+u.dis){
				dis[x.to]=x.w+u.dis;
				q.push(node(x.to,dis[x.to]));
				v.push(x.w); 
			}
		}
	}
	int ans=dis[n];
	for(int i=0;i<r;i++){
		ans-=v.top();
		cout<<v.top()<<" ";
		v.pop();
	}
	cout<<ans;
}
int main(){
	cin>>n>>m>>r;
	for(int i=0,x,y,z;i<m;i++){
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	}
	Dijkstra();
	return 0;
}
