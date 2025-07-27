#include <bits/stdc++.h>
using namespace std;
vector<int> vec[1010];
int n,l,x,y,k;
void bfs(int x){
	int res=0,vis[1010]={0};
	queue<pair<int,int>> q;
	q.push({x,0});
	while(!q.empty()){
		pair<int,int> p;
		p=q.front();
		q.pop();
		if(vis[p.first]||p.second>l)
		continue;
		res++;
		vis[p.first]=1;
		for(int i=0;i<vec[p.first].size();i++){
			q.push({vec[p.first][i],p.second+1});
		}
	}
	cout<<res-1<<endl;
}
int main ()
{
	cin>>n>>l;
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>y;
			vec[y].push_back(i);
		}
	}
	cin>>k;
	while(k--){
		cin>>x;
		bfs(x);
	}
	return 0;
}