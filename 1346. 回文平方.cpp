#include <bits/stdc++.h>
using namespace std;
int b;
void judge(int n)
{
	int k=n*n,num;
	string u,v;
	while(k)
	{
		num=k%b;
		if(num>=0&&num<=9)
		u+='0'+num;
		else
		u+='A'+num-10;
		k/=b;
	}
	v=u;
	reverse(v.begin(),v.end());
	if(u==v)
	{
		k=n;
		u.clear();
	    while(k)
	    {
		  num=k%b;
		  if(num>=0&&num<=9)
		  u+='0'+num;
		  else
		  u+='A'+num-10;
		  k/=b;
	    }
	    reverse(u.begin(),u.end());
		cout<<u<<" "<<v<<endl;
	}
}
int main ()
{
	cin>>b;
	for(int i=1;i<=300;i++)
	judge(i);
	return 0;
}