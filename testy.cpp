#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e6+3;
int p[N],n;
char s[N];
int pre[5];
int a[N];
bool check(char a, char b) { // 判断两个字符能否合并
	if(a == 'Z') {
		if(b == 'Z' || b == 'U' || b == 'L' || b == 'I') return true;
		else return false;
	} 
	else if(a == 'U') {
		if(b == 'U' || b == 'L' || b == 'I') return true;
		else return false;
	} 
	else if(a == 'L') {
		if(b == 'L' || b == 'I') return true;
		else return false;
	} 
	else if(a == 'I') {
		if(b == 'I') return true;
		else return false;
	} 
	else return false;
}
int get(char a){
	if(a=='Z') return 1;
	else if(a=='U')return 2;
	else if(a=='L')return 3;
	else if(a=='I')return 4;
	return 0; 
}
int find (int x){
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}
void solve() {
	cin>>s+1;
	n=strlen(s+1);
	for(int i=1; i<=n; i++) {
		p[i]=i;
		a[i]=1;
	}
	for(int i=n; i>=1; i--) {
		if(!get(s[i]))continue;
		if(!pre[get(s[i])]) {
			pre[get(s[i])]=i;
			continue;
		}
		for(int j=1; j<=4; j++) {
			int u=pre[j];
			if(!u) continue;
	//		int a=u,b=i;
			int x=find(u),y=find(i);
			if(check(s[u],s[i])&&x!=y) {
				p[x]=y;
				a[y]+=a[x];
			}
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		if(p[i]==i) ans=max(ans,a[i]);
	}
	cout<<ans<<endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	int t;	cin>>t;	while(t--)
	solve();
	return 0;
}