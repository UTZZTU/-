#include <bits/stdc++.h>
using namespace std;
string s;
bool judge(string s)
{
	if(s[0]!='R') return false;
	int pos=s.find('C');
	if(pos==-1) return false;
	if(pos==1) return false;
	for(int i=1;i<pos;i++)
	{
		if(s[i]<'0'||s[i]>'9') return false;
	}
	if(pos==s.size()-1) return false;
	for(int i=pos+1;i<s.size();i++)
	{
		if(s[i]<'0'||s[i]>'9') return false;
	}
	return true;
}
string get_str(int num)
{
	string v;
	while(1)
	{
		int m=num%26;
		num/=26;
		if(m) v+='A'+m-1;
		else
		{
			v+='Z';
			num--;
		}
		if(!num) break;
	}
	reverse(v.begin(),v.end());
	return v;
}
int get_num(string s)
{
	int p=1,num=0;
	for(int i=s.size()-1;i>=0;i--)
	{
		num+=(s[i]-'A'+1)*p;
		p*=26;
	}
	return num;
}
void solve()
{
	cin>>s;
	if(judge(s))
	{
		int num1=0,num2=0;
		int i=1;
		for(i;;i++)
		{
			if(s[i]>='0'&&s[i]<='9')
			{
				num1=num1*10+(s[i]-'0');
			}
			else break;
		}
		i++;
		for(i;i<s.size();i++)
		{
			if(s[i]>='0'&&s[i]<='9')
			{
				num2=num2*10+(s[i]-'0');
			}
			else break;
		}
		string t=get_str(num2);
		cout<<t<<num1<<endl;
	}
	else
	{
		int i=s.size()-1;
		for(i;;i--)
		{
			if(s[i]>='0'&&s[i]<='9') ;
			else break;
		}
		string t=s.substr(0,i+1);
		int num1=get_num(t),num2=0;
		i++;
		for(i;i<s.size();i++)
		{
			num2=num2*10+(s[i]-'0');
		}
		cout<<"R"<<num2<<"C"<<num1<<endl;
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}