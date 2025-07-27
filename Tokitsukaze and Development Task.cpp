#include <bits/stdc++.h>
using namespace std;
int t,a,b,c,d,x1,x2,x3,x4,res,dx[6]={1,-1,10,-10,100,-100};
int sum(int x,int y){
	if(x==y)
	return 0;
	int vis[301]={0};
	queue<pair<int,int>> q;
	q.push({y,0});
	while(!q.empty()){
		pair<int,int> p;
		p=q.front();
		q.pop();
		if(p.first==x){
			return p.second;
		}
		if(vis[p.first]){
			continue;
		}
		vis[p.first]=1;
		if(!vis[300])
		q.push({300,p.second+1});
		for(int i=0;i<6;i++){
			int xx=p.first+dx[i];
			if(xx<10||xx>300||vis[xx])
			continue;
			q.push({xx,p.second+1});
		}
	}
	
	return res;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;
		res=0,x1=x2=x3=x4=10;
		res+=sum(a,x1);
		res+=sum(b,x2);
		res+=sum(c,x3);
		res+=sum(d,x4);
		cout<<res<<endl;
	}
	return 0;
}