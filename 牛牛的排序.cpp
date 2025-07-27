#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int a[101],b[101];
int main()
{
	cin>>n;
	int min=1000,max=-1000;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
		if(min>a[i]){
			min=a[i];
		}
		if(max<a[i]){
			max=a[i];
		}
	}
	sort(b,b+n);
	int flag=0;
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]){
			flag=1;
			break;
		}
	}
	if(flag==0){
		cout<<0<<endl;
	}
	else{
		if(a[0]==min||a[n-1]==max){
			cout<<1<<endl;
		}
		else if(a[0]==max&&a[n-1]==min){
			cout<<3<<endl;
		}
		else{
			cout<<2<<endl;
		}
	}
	return 0;
}
