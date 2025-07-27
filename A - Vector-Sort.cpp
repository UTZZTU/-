#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main ()
{
	vector<int> p;
	int n,k,i,m;
	cin>>n;
	m=n;
	while(m--){
		cin>>k;
		p.push_back(k);
	}
	sort(p.begin(),p.end());
	vector<int>::iterator it;
	for(it=p.begin();it!=p.end();it++)
	cout<<*it<<" ";
	return 0;
}