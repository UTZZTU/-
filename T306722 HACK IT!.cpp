#include <bits/stdc++.h>
using namespace std;
int x;
int main ()
{
	cin>>x;
	if(x==1)
	{
		cout<<2000000000<<" "<<2000000000<<endl;
	}
	else if(x==2)
	{
		for(int i=1;i<=1000000;i++)
		cout<<"a";
	}
	else
	{
		cout<<100<<endl;
		for(int i=1;i<=100;i++)
		cout<<i<<" ";
	}
	return 0;
}