#include <bits/stdc++.h>
using namespace std;
const double Eps = 1e-8;
const double PI = atan(-1.0);
const int N = 1e5+5;
const int MOD = 1e9+7;

#define pb push_back
#define pf push_front
#define cl clear
#define fi first
#define se second
#define bg begin
#define ed end
#define sz size
#define fd find
#define is insert
#define PI pair<int,int>
#define PS pair<string,string>
#define Um unordered_map
#define Us unordered_set
#define Mul multiset<int>
#define VI vector<int>
#define VII vector< vector<int> > 
#define VS vector<string>
#define VN vector<node>
#define VP vector< pair<int,int> >
#define debug(x) cout<<"x"<<endl
#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define Mem(x) memset(x,0,sizeof x)
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define pr(x) cout<<x<<endl

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;

struct node
{
	int num,pos;
}S[N];

bool cmp(node x,node y)
{
	return x.num<y.num;
}

int qmi(int a,int b,int mod)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}

int qmi(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a;
		b>>=1;
		a=a*a;
	}
	return res;
}

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

int n,k,f[200010],t[200010],flag,k1,pos;
VI v[200010];
VI vec;
bool judge()
{
//	for(auto c:vec)
//	{
//		cout<<c<<" ";
//	}
//	cout<<endl;
	for(int i=2;i<=k;i++)
	{
		int cnt=0;
		for(int j=0;j<n;j++)
		{
			if(vec[j]==t[i]) continue;
			if(vec[j]!=v[i][cnt])
			{
				return false;
			}
			cnt++;
		}
	}
	return true;
}
void solve()
{
	vec.cl();
	flag=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		if(i==1) k1=f[i];
		else vec.emplace_back(f[i]);
	}
	if(k==1)
	{
		flag=1;
	}
	else
	{
		for(int i=2;i<=k;i++)
		{
			v[i].cl();
			for(int j=1;j<=n;j++)
			{
				cin>>f[j];
				if(j==1)
				{
					t[i]=f[j];
				}
				else
				v[i].emplace_back(f[j]);
			}
		}
		if(n==1)
		{
			flag=1;
		}else
		{
			auto it=find(v[2].bg(),v[2].ed(),k1);
			int k2=t[2];
			auto pn=it;
			advance(pn,1);
			auto pr=it;
			advance(pr,-1);
//			cout<<"pn:pr:"<<*pn<<" "<<*pr<<endl;
			if(it==v[2].bg())
			{
				
				if(pn!=v[2].ed())
				{
					int post=*pn;
//					cout<<"1"<<endl;
					auto fit1=find(vec.bg(),vec.ed(),k2);
					vec.insert(fit1,k1);
					if(judge()) flag=1;
					auto fd1=find(vec.bg(),vec.ed(),k1);
					vec.erase(fd1);
					auto fit2=find(vec.bg(),vec.ed(),k2);
					advance(fit2,1);
					vec.insert(fit2,k1);
					if(judge()) flag=1;
					auto fd2=find(vec.bg(),vec.ed(),k1);
					vec.erase(fd2);
					auto fit3=find(vec.bg(),vec.ed(),post);
					vec.insert(fit3,k1);
					if(judge()) flag=1;
					auto fd3=find(vec.bg(),vec.ed(),k1);
					vec.erase(fd3);
					vec.insert(vec.bg(),k1);
					if(judge()) flag=1;
				}
				else
				{
//					cout<<"2"<<endl;
					flag=1;
				}
			}
			else
			{
				
				if(pn!=v[2].ed())
				{
					int post=*pn;
					int pre=*pr;
//					cout<<k1<<" "<<k2<<endl;
//					cout<<"3"<<endl;
					auto fit1=find(vec.bg(),vec.ed(),k2);
					vec.insert(fit1,k1);
					if(judge()) flag=1;
					auto fd1=find(vec.bg(),vec.ed(),k1);
					vec.erase(fd1);
					auto fit2=find(vec.bg(),vec.ed(),k2);
//					cout<<*fit2<<endl;
//					cout<<"3"<<endl;
					auto pnn=fit2;
					advance(pnn,1);
//					cout<<*pnn<<endl;
					vec.insert(pnn,k1);
					if(judge()) flag=1;
					auto fd2=find(vec.bg(),vec.ed(),k1);
					vec.erase(fd2);
//					cout<<"3"<<endl;
					auto fit3=find(vec.bg(),vec.ed(),post);
					vec.insert(fit3,k1);
					if(judge()) flag=1;
//					cout<<"3"<<endl;
					auto fd3=find(vec.bg(),vec.ed(),k1);
					vec.erase(fd3);
					auto fit4=find(vec.bg(),vec.ed(),pre);
					advance(fit4,1);
					vec.insert(fit4,k1);
					if(judge()) flag=1;
				}
				else
				{
					int pre=*pr;
//					cout<<"4"<<endl;
					auto fit1=find(vec.bg(),vec.ed(),k2);
					vec.insert(fit1,k1);
					if(judge()) flag=1;
					auto fd1=find(vec.bg(),vec.ed(),k1);
					vec.erase(fd1);
					auto fit2=find(vec.bg(),vec.ed(),k2);
					advance(fit2,1);
					vec.insert(fit2,k1);
					if(judge()) flag=1;
					auto fd2=find(vec.bg(),vec.ed(),k1);
					vec.erase(fd2);
					vec.insert(vec.ed(),k1);
					if(judge()) flag=1;
					auto fd3=find(vec.bg(),vec.ed(),k1);
					vec.erase(fd3);
					auto fit3=find(vec.bg(),vec.ed(),pre);
					advance(fit3,1);
					vec.insert(fit3,k1);
					if(judge()) flag=1;
				}
			}
		}
	}
	if(flag) yes;
	else no;
}
int main ()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	IOS;
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}