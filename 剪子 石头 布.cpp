#include <bits/stdc++.h>
using namespace std;
int main ()
{
	string a="Rock",b="Scissors",c="Cloth";
	string s1,s2;
	int pd;
	cin>>s1>>s2;
	if(s1==s2)
	pd=0;
	else if(s1==a&&s2==b||s1==b&&s2==c||s1==c&&s2==a)
	pd=1;
	else
	pd=-1;
	if(pd==1)
	cout<<"Win";
	else if(pd==0)
	cout<<"Equal";
	else
	cout<<"Lose";
	return 0;
}