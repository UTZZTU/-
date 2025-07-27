#include<iostream>
#include<stack>
#include<vector>
using namespace std;
const int N = 50010, M = 200010, Q = 1010;
int n,m,d;
int f[N];
bool book[N];//点是否为已删除状态
struct Edge{
	int u,v;
};
vector<int> g[N];//邻接表 
vector<Edge> query;//询问离线化 
vector<int> alg,erap;//alg某个询问的个数 era删除的点 
stack<int> res;//结果 
int getf(int v){
	if(f[v] == v) return v;
	else return f[v] = getf(f[v]);
}
void merge(int a,int b){
	int t1 = getf(a);
	int t2 = getf(b);
	if(t1 != t2){
		f[t2] = t1;
	}
}
bool ismerge(int a,int b){
	return getf(a) == getf(b);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,d;
	cin>>n>>m>>d;
	for(int i = 1; i <= n; i++) f[i] = i;
	//离线操作 
	for(int i = 0 ; i < m; i++){
		int u,v;
		cin>>u>>v;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for(int i = 0; i < d; i++){
		int c,q;
		cin>>c>>q;
		book[c] = true;
		erap.push_back(c); 
		alg.push_back(q);
		for(int j = 0; j < q; j++){
			int u,v;
			cin>>u>>v;
			query.push_back({u,v});
		}
	}
	//将没被删除的相关点生成并查集
	for(int i = 1; i <= n; i++){ 
		if(!book[i]){
			for(auto p:g[i]){
				if(!book[p]) merge(i,p);
			}
		}
	}
	
	for(int i = alg.size()-1; i >= 0; i--){
		int count = 0;
		for(int j = 0; j < alg[i]; j++){
			Edge tmp = query[query.size()-1];
			if(!ismerge(tmp.u,tmp.v)){
				count++;
			}
			if(query.size()) query.pop_back();
		}
		res.push(count);
		//插入点 
		int p = erap[i];
		book[p] = false;
		for(int x:g[p]){
			if(!book[x]) merge(x,p);
		}
	} 
	while(res.size()){
		cout<<res.top(); res.pop();
		if(res.size()) cout<<'\n';
	} 
	return 0;
}