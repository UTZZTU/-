#include <iostream>
using namespace std;
int pre[30010],nextt[30010],fa[30010],t;
string s;
int pre_find(int x){
	while(x!=pre[x]) x=pre[x]=pre[pre[x]];
	return x;
}
int next_find(int x){
	while(x!=nextt[x]) x=nextt[x]=nextt[nextt[x]];
	return x;
}
int find(int x){
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
	return x;
}
int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=1;i<=30000;i++){
		pre[i]=nextt[i]=fa[i]=i;
	}
	cin>>t;
	
	getchar();
	while(t--){
		int i,j;
		cin>>s>>i>>j;
		if(s=="M"){
			int prex=pre_find(i),nextx=next_find(j);
			pre[prex]=nextx;
			nextt[nextx]=prex;
			int fx=find(i),fy=find(j);
			if(fx!=fy)
			fa[fx]=fy;
		} else {
			if(fa[i]!=fa[j])
			cout<<-1<<endl;
			else{
				bool flag=false;
				int res=0,x=i;
				while(x!=pre[x]){
					res++;
					x=pre[x];
					if(x==j){
						flag=true;
						break;
					}
				}
				if(!flag){
					res=0,x=i;
					while(x!=nextt[x]){
						res++;
						x=nextt[x];
						if(x==j){
							flag=true;
							break;
						}
					}
				}
				cout<<res<<endl;
			}
		}
	}
	return 0;
}