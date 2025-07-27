#include <bits/stdc++.h>
using namespace std;
int n;
int main ()
{
	while(cin>>n)
	{
		if(n==0)
		break;
		vector<int> vec;
		for(int i=1;i<=n;i++)
		vec.push_back(i);
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<vec.size();j++)
			{
				if(j!=0)
				cout<<" ";
				cout<<vec[j];
			}
			cout<<endl;
			vec.pop_back();
			vec.insert(vec.begin(),i+1);
		}
		cout<<endl;
	}
	return 0;
}