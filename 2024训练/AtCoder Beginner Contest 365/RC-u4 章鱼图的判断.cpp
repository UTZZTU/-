#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int t,n,m;
int p[N],sz[N],d[N];
vector<int> g[N];
int find(int x){
	if(x!=p[x]) p[x]=find(p[x]);
	return p[x];
}
void solve(){
    
    cin>>n>>m;
    for(int i=1;i<=n;i++) g[i].clear(),p[i]=i,d[i]=-1,sz[i]=0;
    
    // sz 表示出现了环的数量
    int ans=0,st,ed;
    while(m--){
    	int a,b; cin>>a>>b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    	int fa = find(a),fb = find(b);
    	if(fa!=fb){ // 表示这写点还没有啥特殊关系
    		p[fa]=fb;
    		sz[fb] += sz[fa]; // a所在的连通块可能有环现在要和b连在一起要环的数量是会合并变多
    	}
    	else{ // 如果说这两个点本来就在一个连通块 那么这条边的出现就会是环的出现
    		sz[fa]++;
    		st = a, ed = b; // 这两个点肯定就是环上的点
    	}
    }
    
    // 只有一个环的才是 章鱼子图 题目定义 及是sz[i]==1
    
    // find(i) == i 表示和i在一个连通块的祖先信息 
    for(int i=1;i<=n;i++) if(find(i)==i and sz[i]==1) ans++;
    
    if(ans!=1){
    	cout << "No" << ' ' << ans << endl;
    	return ;
    }
    // st  和 ed 是环上的点 我只要不使用 st 和 ed 的边就可以用bfs找出环的数量
    queue<int> q;
    q.push(st);
    d[st] = 1;
    while(!q.empty()){
    	auto u = q.front(); q.pop();
    	for(auto&v:g[u]){
    		if(u==st and v==ed) continue;
    		if(d[v]==-1){
    			d[v]=d[u]+1;
    			q.push(v);
    		}
    	}
    }
    cout << "Yes" << ' ' << d[ed] << endl;
    return ;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}