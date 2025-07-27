#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <bitset>
#include <cmath>
#include <numeric>
#include <ctime>
#include <cstdlib>
#include <iomanip>

//#define endl '\n'

#define ft first
#define sd second

#define yes cout << "yes\n"
#define no cout << "no\n"

#define Yes cout << "Yes\n"
#define No cout << "No\n"

#define YES cout << "YES\n"
#define NO cout << "NO\n"

#define pb push_back
#define eb emplace_back

#define all(x) x.begin(), x.end()
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define sort_all(x) sort(all(x))
#define reverse_all(x) reverse(all(x))
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

#define INF 0x7fffffff
#define INFLL 0x7fffffffffffffffLL

#define RED cout << "\033[91m"
#define GREEN cout << "\033[92m"
#define YELLOW cout << "\033[93m"
#define BLUE cout << "\033[94m"
#define MAGENTA cout << "\033[95m"
#define CYAN cout << "\033[96m"
#define RESET cout << "\033[0m"


#define DEBUG1(x)                     \
    RED;                              \
    cout << #x << " : " << x << endl; \
    RESET;


#define DEBUG2(x)                     \
    GREEN;                            \
    cout << #x << " : " << x << endl; \
    RESET;


#define DEBUG3(x)                     \
    BLUE;                             \
    cout << #x << " : " << x << endl; \
    RESET;


#define DEBUG4(x)                     \
    MAGENTA;                          \
    cout << #x << " : " << x << endl; \
    RESET;


#define DEBUG5(x)                     \
    CYAN;                             \
    cout << #x << " : " << x << endl; \
    RESET;


#define DEBUG6(x)                     \
    YELLOW;                           \
    cout << #x << " : " << x << endl; \
    RESET;

using namespace std;

const double Eps = 1e-8;
const double PI = atan(-1.0);
const int N = 1e6+5;
const int MOD = 1e9+7;
const int M = 30;

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef pair<string, int> psi;
typedef pair<string, ll> psl;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pss> vpss;

typedef vector<vi> vvi;
typedef vector<vl> vvl;

typedef queue<int> qi;
typedef queue<ll> ql;
typedef queue<pii> qpii;
typedef queue<pll> qpll;
typedef queue<psi> qpsi;
typedef queue<psl> qpsl;

typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;
typedef priority_queue<string> pqs;
typedef priority_queue<pii> pqpii;
typedef priority_queue<psi> pqpsi;
typedef priority_queue<pll> pqpl;
typedef priority_queue<psi> pqpsl;

typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<ll, ll> mll;
typedef map<ll, bool> mlb;
typedef map<char, int> mci;
typedef map<char, ll> mcl;
typedef map<char, bool> mcb;
typedef map<string, int> msi;
typedef map<string, ll> msl;
typedef map<int, bool> mib;

typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> uml;
typedef unordered_map<char, int> umci;
typedef unordered_map<char, ll> umcl;
typedef unordered_map<string, int> umsi;
typedef unordered_map<string, ll> umsl;

template <typename T>
inline void read(T &x)
{
    T f = 1;
    x = 0;
    char ch = getchar();
    while (0 == isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (0 != isdigit(ch))
        x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
    x *= f;
}

template <typename T>
inline void write(T x)
{
    if (x < 0)
    {
        x = ~(x - 1);
        putchar('-');
    }
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
int cwin;  //拥塞窗口 
int ssthresh;  //初始阈值 
int height[M+5],pos,st[M+5],po[M+5];    //cwin的大小以及长度 
int limits[5],op[5];  //三个限制  三个限制的分类 
int status;    //当前网络的状态 

void show()
{
	cout<<"下列为本次丢失数据的随机位置以及种类"<<endl;
	cout<<"位置是： "<<endl;
	for(int i=1;i<=3;i++)
	{
		cout<<limits[i]<<" ";	
	} 
	cout<<endl;
	cout<<"种类是： "<<endl;
	for(int i=1;i<=3;i++)
	{
		if(op[i]) cout<<"超时    "<<endl;
		else cout<<"重复确认  "<<endl;
	} 
	cout<<endl;
	cout<<endl;
	cout<<"传输次数: "; 
	for(int i=0;i<=M;i++)
	{
		cout<<setw(3)<<i<<"  ";
	}
	cout<<endl;
	cout<<endl;
	cout<<"阻塞窗口: "; 
	for(int i=0;i<=M;i++)
	{
		cout<<setw(3)<<height[i]<<"  ";
	}
	cout<<endl;
	cout<<endl;
	cout<<"是否异常: "; 
	for(int i=0;i<=M;i++)
	{
		if(st[i]) cout<<setw(3)<<1<<"  ";
		else cout<<setw(3)<<0<<"  "; 
	}
	cout<<endl;
	cout<<endl;
}

void init()
{
	memset(st,0,sizeof st);
	cout<<"请输入拥塞窗口大小以及初始阈值"<<endl;
	cin>>cwin>>ssthresh;
	status=0;
	height[0]=cwin;
	pos=1;
	for(int i=1;i<=M;i+=10)
	{
		limits[(i+9)/10]=rand()%10+i;
		op[(i+9)/10]=rand()%2;
		st[limits[(i+9)/10]]=1;
		po[limits[(i+9)/10]]=op[(i+9)/10];
	}
}
void solve()
{
	init();
	for(pos;pos<=M;pos++)
	{
		if(!status)
		{
			if(cwin*2<ssthresh)
			{
				cwin*=2;	
			}
			else
			{
				cwin=ssthresh;
				status=1;
			}
			if(st[pos])
			{
				height[pos]=cwin;
				if(po[pos])
				{
					ssthresh=max(cwin/2,2);
					cwin=1;
					status=0;
					height[++pos]=cwin;
				}
				else
				{
					ssthresh=max(cwin/2,2);
					cwin=ssthresh;
					status=1;
					height[++pos]=cwin;
				}
				continue;
			}
		}
		else
		{
			cwin++;
			if(st[pos])
			{
				height[pos]=cwin;
				if(po[pos])
				{
					ssthresh=max(cwin/2,2);
					cwin=1;
					status=0;
					height[++pos]=cwin;
				}
				else
				{
					ssthresh=max(cwin/2,2);
					cwin=ssthresh;
					status=1;
					height[++pos]=cwin;
				}
				continue;
			}
		}
		height[pos]=cwin;
	}
	show();
}

int main()
{
	IOS;
	cout<<"请输入要执行的总次数"<<endl;
	int _=1;
	cin>>_;
	while(_--)
	{
		srand((unsigned)time(NULL));
		solve();
	}
	return 0;
}

