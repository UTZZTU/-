#include"bits/stdc++.h"
using namespace std;
int main(){
	map<string,int>mp;
	int n;
	while(cin>>n){
		string shop;
		int temp=n;
		while(temp--)cin>>shop;
		int m;
		cin>>m;
		while(m--){
			for(int i=0;i<n;i++){
				int price;
				cin>>price>>shop;
				mp[shop]+=price;
			}
			int no=1;
			map<string,int>::iterator it;//使用迭代器访问map
			for(it=mp.begin();it!=mp.end();it++){
    			if(it->second>mp["memory"])no++;//注意使用迭代器访问map的second值要使用->
    		}
			cout<<no<<endl;
		}
		mp.clear();//注意每次处理一组数据后要清空
	}
}
