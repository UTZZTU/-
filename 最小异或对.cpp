#include <bits/stdc++.h>
using namespace std;
int n,num;
string s;
multiset<int> mul1,mul2;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(s=="ADD"){
			cin>>num;
			auto it=mul1.lower_bound(num);
			if(it!=mul1.end()){
				mul2.insert(*it ^ num);
			}
			if(it!=mul1.begin()){
				mul2.insert(*(prev(it)) ^ num);
			}
			if(it!=mul1.end()&&it!=mul1.begin()){
				mul2.erase(mul2.lower_bound(*(prev(it)) ^ *it));
			}
			mul1.insert(num);
			
		} else if(s=="DEL"){
			cin>>num;
			mul1.erase(mul1.lower_bound(num));
			auto it=mul1.lower_bound(num);
			if(it!=mul1.end()){
				mul2.erase(mul2.lower_bound(*it ^ num));
			}
			if(it!=mul1.begin()){
				mul2.erase(mul2.lower_bound(*(prev(it)) ^ num));
			}
			if(it!=mul1.end()&&it!=mul1.begin()){
				mul2.insert(*it ^ *(prev(it)));
			}
			
		} else {
			cout<<*mul2.begin()<<endl;
		}
	}
	return 0;
}