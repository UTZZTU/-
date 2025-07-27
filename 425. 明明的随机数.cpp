#include <bits/stdc++.h>
using namespace std;
set<int> st;
int n,k;
int main ()
{
	cin>>n;
	while(n--)
	{
		cin>>k;
		st.insert(k);
	}
	cout<<st.size()<<endl;
	for(auto it=st.begin();it!=st.end();it++)
    cout<<*it<<" ";
    return 0;
}