#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Array{
	private:
		T *p;
		int n;
	public:
		Array(int _n){
			n=_n;
			p=new T[n];
		}
		int sizeOfArray(){
			return n;
		}
		T operator[](int index){
			return p[index];
		}
		void setElement(int index,T item){
			p[index]=item;
		}
};
int main(){
	int ch,n;
	cin>>ch>>n;
	if(ch==1){
		Array<int>ans(n);
		int temp;
		for(int i=0;i<n;i++){
			cin>>temp;
			ans.setElement(i,temp);
		}
		for(int i=0;i<n;i++){
			cout<<ans[i];
			if(i!=n-1)
				cout<<" ";
		}
	}	
	else if(ch==2){
		Array<double>ans(n);
		double temp;
		for(int i=0;i<n;i++){
			cin>>temp;
			ans.setElement(i,temp);
		}
		for(int i=0;i<n;i++){
			cout<<ans[i];
			if(i!=n-1)
				cout<<" ";
		}
	}
	else{
		Array<char>ans(n);
		char temp;
		for(int i=0;i<n;i++){
			cin>>temp;
			ans.setElement(i,temp);
		}
		for(int i=0;i<n;i++){
			cout<<ans[i];
			if(i!=n-1)
				cout<<" ";
		}
	}
	
	return 0;
}