#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
void fun(string a)
{
	stack<char>s;
	int l=a.size(),flag=1;
	if(l%2!=0)
	 cout<<"NO"<<endl;
	 else
	 {
	 	for(int i=0;i<l;i++)
	{
		if(a[i]=='('||a[i]=='{'||a[i]=='['||a[i]=='<')
		s.push(a[i]);//进栈
		else if(!s.empty())
		{
			if(a[i]==')'&&s.top()=='(')
			s.pop();//弹出
			if(a[i]=='}'&&s.top()=='{')
			s.pop();
			if(a[i]==']'&&s.top()=='[')
			s.pop();
			if(a[i]=='>'&&s.top()=='<')
			s.pop();
		}
		else
		{
			flag=0;
			break;
		}
	}
	if(s.empty()&&flag)
	cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	 }
}
int main()
{
	int n,i;
	cin>>n;
	while(n--)
	{
		string a;
		cin>>a;
		fun(a);
	}
	return 0;
 } 
