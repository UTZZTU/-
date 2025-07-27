#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	int n,m,i,j,k,u,min,t;
	int w[10001]={0},ss[101]={0};
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>w[i];
	for(i=1;i<=n;i++){
		min=99999999;
		for(j=1;j<=m;j++){
			if(ss[j]<min)  {u=j; min=ss[j];}
		}
		ss[u]+=w[i];
	}
	t=ss[1];
	for(i=2;i<=m;i++){
		t=max(t,ss[i]);
	}
	cout<<t<<endl;
}