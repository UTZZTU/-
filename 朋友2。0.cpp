#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[10001],m,n,x,y,head[1000000],tot,maxx;
struct node{
	int to,next;
}b[1000000];
void ljb(int x,int y){
	tot++;
	b[tot].to=y;
	b[tot].next=head[x];
	head[x]=tot;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		a[x]++;
		a[y]++;
		ljb(x,y);
		ljb(y,x);
	}
	for(int i=1;i<=n;i++){
		if(a[i]>maxx){
			maxx=a[i];
			x=i;
		}
	}
	y=0;
	for(int i=head[x];i;i=b[i].next){
		y++;
		a[y]=b[i].to;
	}
	sort(a+1,a+y+1);
	for(int i=1;i<=y;i++)cout<<a[i]<<' ';
	return 0;
}

