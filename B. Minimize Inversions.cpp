#include <bits/stdc++.h>
using namespace std;
const double Eps = 1e-8;
const double PI = atan(-1.0);
const int N = 2e5+5;
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
}S1[N],S2[N];

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
int n,a[200010],b[200010],temp[200010],tempp[200010]; 
ll sum;
void Merge(int s1,int e1,int s2,int e2)  
{  
    int p = 0 ;  
    int p1 = s1 ;  
    int p2 = s2 ; 
    while(p1<=e1&&p2<=e2)  
    {  
        if(temp[p1]<=temp[p2])  
        {  
            tempp[p++] = temp[p1++] ;  
        }  
        else  
        {  
            tempp[p++] = temp[p2++] ;  
            sum+=(e1-p1+1); //这里不懂的，就这样写就行；因为是这个题的缘故。真正的归并排序算法中国m，没有这个得。  
        }  
    }  
    //如果mid前面的元素数目比mid后面的元素数目少，那么后面就剩下了很多的元素；  
    while(p1<=e1)  
    {  
        tempp[p++] = temp[p1++] ;  //这里就是为了把后面余下的mid前面元素放进temp中;  
    }  
    while(p2<=e2)  
    {  
        tempp[p++] = temp[p2++] ; //这里就是为了把后面余下的mid后面元素放进temp中;  
    }  
    int i ;  
    for(i=s1;i<=e2;i++)  
    {  
        temp[i] = tempp[i-s1] ;  //用temp数组对a数组进行更新;  
    }  
}  
  
  
void Merge_sort(int s ,int e)  
{  
    int mid ;  
    if(s<e)  
    {  
        mid = (s+e)/ 2 ;  
        Merge_sort(s,mid); //左边递归到最小；  
        Merge_sort(mid+1,e);//右边递归到最小；  
        Merge(s,mid,mid+1,e) ;  
    }  
}  

ll judge1()
{
	for(int i=1;i<=n;i++)
	{
		temp[i]=b[S1[i].pos];
	}
	sum=0;
	Merge_sort(1,n);
	return sum;
	
}
ll judge2()
{
	for(int i=1;i<=n;i++)
	{
		temp[i]=a[S2[i].pos];
	}
	sum=0;
	Merge_sort(1,n);
	return sum;
} 
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		S1[i].num=a[i];
		S1[i].pos=i;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		S2[i].num=b[i];
		S2[i].pos=i;
	}
	sort(S1+1,S1+1+n,cmp);
	sort(S2+1,S2+1+n,cmp);
	if(judge1()<=judge2())
	{
		for(int i=1;i<=n;i++)
		{
			cout<<i<<" ";
		}
		cout<<endl;
		for(int i=1;i<=n;i++)
		{
			cout<<b[S1[i].pos]<<" ";
		}
		cout<<endl;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cout<<a[S2[i].pos]<<" ";
		}
		cout<<endl;
		for(int i=1;i<=n;i++)
		{
			cout<<i<<" ";
		}
		cout<<endl;
	}
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