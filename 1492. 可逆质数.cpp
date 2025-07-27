#include <bits/stdc++.h>
using namespace std;
int n,d,t;
int get_num(int n,int d)
{
	int x=n,res=0,t=1;
	vector<int> vec;
	while(x)
	{
		vec.push_back(x%d);
		x/=d;
	}
	reverse(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++)
	{
		res+=vec[i]*t;
		t*=d;
	}
	return res;
}
bool is_prime(int x)
{
	if(x<2)
	return false;
	for(int i=2;i<=x/i;i++)
	{
		if(x%i==0)
		return false;
	}
	return true;
}
int main ()
{
	while(cin>>n)
	{
		if(n<0)
		break;
		cin>>d;
		if(is_prime(n))
		{
			t=get_num(n,d);
			if(is_prime(t))
			cout<<"Yes"<<endl;
			else
			cout<<"No"<<endl;
		}
		else
		cout<<"No"<<endl;
	}
	return 0;
}