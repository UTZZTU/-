#include<vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
	vector<int> vec;
	int n,k,m;
	cin>>n;
	while(n--)
	{
		cin>>k;
		vec.push_back(k);
	}
	cin>>k;
	vec.erase(vec.begin()+k-1);
	cin>>n>>m;
	vec.erase(vec.begin()+n-1,vec.begin()+m-1);
	cout<<vec.size()<<endl;
	for(auto it=vec.begin();it!=vec.end();it++)
	{
		cout<<*it<<" ";
	}
	return 0;
}