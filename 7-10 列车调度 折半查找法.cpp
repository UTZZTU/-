#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int root[n];
	int len = 0;
	int k;
	while(n--){
		cin>>k;
		if(len == 0 || root[len-1] < k){
			root[len++] = k;
		}else{
			//折半查找法 
			int one = 0,two = len-1;
			while(one < two){
				int mid = one + (two-one)/2;
				if(root[mid] > k){
					two = mid - 1;
				}else{
					one = mid + 1;
				}
			}
			root[one] = k;
		}
	}
	cout<<len;
	return 0;
} 
