#include <bits/stdc++.h>
using namespace std;
int t,p,q;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>p>>q;
		if(p==q)
		cout<<"sc"<<endl;
		else if(q==2*p)
		cout<<"scts"<<endl;
		else
		cout<<"Noooooooo!"<<endl;
	}
	return 0;
}