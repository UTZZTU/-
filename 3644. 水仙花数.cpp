#include <bits/stdc++.h>
using namespace std;
bool judge(int n)
{
	if(n==pow(n%10,3)+pow(n/10%10,3)+pow(n/100,3))
	return true;
	else
	return false;
}
int main ()
{
	int m,n;
	while(cin>>m>>n)
	{
		if(m==0&&n==0)
		break;
		vector<int> vec;
		for(int i=m;i<=n;i++)
		{
			if(judge(i))
			vec.push_back(i);
		}
		if(vec.empty())
		cout<<"no"<<endl;
		else
		{
			for(int i=0;i<vec.size();i++)
			{
				if(i!=0)
				cout<<" ";
				cout<<vec[i];
			}
			cout<<endl;
		}
	}
	return 0;
}