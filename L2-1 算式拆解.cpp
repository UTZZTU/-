#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
	int num;
	bool flag;
};
stack<node> num;
string s;
stack<char> fh;
int main ()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(')
		{
			fh.push(s[i]);
		}
		else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
		{
			fh.push(s[i]);
		}
		else if(s[i]>='0'&&s[i]<='9')
		{
			int numm=0;
			int j=i;
			while(s[j]>='0'&&s[j]<='9')
			{
				numm=numm*10+(s[j]-'0');
				j++;
			}
			num.push({numm,false});
			i=j-1;
		}
		else if(s[i]==')')
		{
			if(num.empty()) break;
			node nh=num.top();
			num.pop();
			node nq=num.top();
			num.pop();
			char cz=fh.top();
			fh.pop();
			fh.pop();
			int pp;
			if(cz=='+')
			{
				if(nq.flag==false) cout<<nq.num;
				cout<<"+";
				if(nh.flag==false) cout<<nh.num;
				cout<<endl;
				num.push({nq.num+nh.num,true});
			}
			else if(cz=='-')
			{
				if(nq.flag==false) cout<<nq.num;
				cout<<"-";
				if(nh.flag==false) cout<<nh.num;
				cout<<endl;
				num.push({nq.num-nh.num,true});
			}
			else if(cz=='*')
			{
				if(nq.flag==false) cout<<nq.num;
				cout<<"*";
				if(nh.flag==false) cout<<nh.num;
				cout<<endl;
				num.push({nq.num*nh.num,true});
			}
			else
			{
				if(nq.flag==false) cout<<nq.num;
				cout<<"/";
				if(nh.flag==false) cout<<nh.num;
				cout<<endl;
				num.push({nq.num/nh.num,true});
			}
		}
	}
	return 0;
}
