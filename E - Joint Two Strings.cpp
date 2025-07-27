#include <iostream>
using namespace std;
const int N = 500010;
long long res;
int n,f1[N],f2[N],l,tr[N],ff;
string t,s[N];
int get1(string s)
{
	int cnt=0,j=0;
	for(int i=0;i<s.size()&&j<l;i++)
	{
		if(s[i]==t[j])
		{
			cnt++;
			j++;
		}
	}
	return cnt;
}
int get2(string s)
{
	int cnt=0,j=l-1;
	for(int i=s.size()-1;i>=0&&j>=0;i--)
	{
		if(s[i]==t[j])
		{
			cnt++;
			j--;
		}
	}
	return cnt;
}
int lowbit(int x)
{
	return x & -x;
}
void add(int x,int c)
{
	for(int i=x;i<=l;i+=lowbit(i)) tr[i]+=c;
}
int sum(int x)
{
	int cnt=0;
	for(int i=x;i;i-=lowbit(i)) cnt+=tr[i];
	return cnt;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>t;
	l=t.size();
//	cout<<n<<" "<<t<<endl;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
//		cout<<s[i]<<endl;
		f1[i]=get1(s[i]);
		f2[i]=get2(s[i]);
		if(f2[i])
		add(f2[i],1);
//		cout<<f2[i]<<endl;
//		cout<<"YES"<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		int pos=l-f1[i];
//		cout<<pos<<endl;
		int cnt;
		if(pos-1<0) cnt=n;
		else
		cnt=sum(l)-sum(pos-1);
//		cout<<cnt<<endl;
		res+=cnt;
//		cout<<res<<endl;
//		if(f2[i]>=pos) res--;
	}
	cout<<res;
	return 0;
}