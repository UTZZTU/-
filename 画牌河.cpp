#include <bits/stdc++.h>
using namespace std;
int x;
int main (){
	cin>>x;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=6;j++){
			if(x>=(i-1)*6+j)
			cout<<1;
			else
			cout<<0;
		}
		cout<<endl;
	}
	return 0;
}