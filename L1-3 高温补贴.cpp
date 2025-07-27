#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int T,s,t;
	cin>>T>>s>>t;
	if(T>35&&s==1||t>=33&&s==1)
	{
		cout<<"Bu Tie"<<endl;
		cout<<T;
	}
	else
	{
		if(T>35&&t>=33&&s==0)
		{
			cout<<"Shi Nei"<<endl;
			cout<<T;
		}
		else if(s==1&&(T<=35||t<33))
		{
			cout<<"Bu Re"<<endl;
			cout<<t;
		}
		else if(s==0&&(T<=35||t<33))
		{
			cout<<"Shu Shi"<<endl;
			cout<<t;
		}
	}
	return 0;
}
