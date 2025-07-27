#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1,x;i<=n;i++)
	{
		cin>>x;
		a.insert(upper_bound(a.begin(),a.end(),x),x);
		if(i%2==1)
		cout<<a[(i-1)/2]<<endl;
	}
	return 0;
}