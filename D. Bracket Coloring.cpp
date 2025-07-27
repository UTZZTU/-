#include <bits/stdc++.h>
using namespace std;
int n,cnt,f[200010],p1[200010],p2[200010];
string s;
struct node
{
	char c;
	int pos;
};
bool check()
{
	int num1=0,num2=0,pp1=0,pp2=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(') num1++;
		else num2++;
		f[i+1]=-1;
		p1[i+1]=num1;
		if(num1>num2) pp1=1;
		else if(num1<num2) pp2=1;
	}
	if(num1!=num2) return false;
	if(!pp1||!pp2)
	{
		cnt=1;
		for(int i=1;i<=n;i++) f[i]=1;
		return true;
	}
	num2=0;
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]==')') num2++;
		p2[i+1]=num2;
	}
	p1[0]=0,p2[n+1]=0;
	for(int i=n;i>=1;i--)
	{
		if(p1[i]<=p2[i+1])
		{
			int j=i;
			for(j;j>=1;j--)
			{
				if(s[j-1]=='(') f[j]=1;
			}
			j=i+1;
			for(j;j<=n;j++)
			{
				if(s[j-1]==')') f[j]=1;
			}
			break;
		}
	}
	set<int> st;
	for(int i=1;i<=n;i++)
	{
		if(f[i]==-1) f[i]=2;
		st.insert(f[i]);
	}
	cnt=st.size();
	if(cnt==1)
	{
		for(int i=1;i<=n;i++) f[i]=1;
	}
	return true;
}
void solve()
{
	cin>>n>>s;
	if(check())
	{
		cout<<cnt<<endl;
		for(int i=1;i<=n;i++) cout<<f[i]<<" ";
		cout<<endl;
	}
	else cout<<-1<<endl;
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
/*
))()((
(()())
))(())(())()()((
(((()((())))))
((()))((()))((()))((()))
)))(((
())()(()
()))()))((((
))(())(())((()
*/