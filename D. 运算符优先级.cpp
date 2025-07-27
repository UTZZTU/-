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

//#define endl '\n'

#define fi first
#define se second
#define pf push_front
#define cl clear
#define bg begin
#define ed end
#define sz size
#define fd find
#define is insert
#define pr(x) cout<<x<<'\n'

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

// 红色
#define DEBUG1(x)                     \
    RED;                              \
    cout << #x << " : " << x << endl; \
    RESET;

// 绿色
#define DEBUG2(x)                     \
    GREEN;                            \
    cout << #x << " : " << x << endl; \
    RESET;

// 蓝色
#define DEBUG3(x)                     \
    BLUE;                             \
    cout << #x << " : " << x << endl; \
    RESET;

// 品红
#define DEBUG4(x)                     \
    MAGENTA;                          \
    cout << #x << " : " << x << endl; \
    RESET;

// 青色
#define DEBUG5(x)                     \
    CYAN;                             \
    cout << #x << " : " << x << endl; \
    RESET;

// 黄色
#define DEBUG6(x)                     \
    YELLOW;                           \
    cout << #x << " : " << x << endl; \
    RESET;

using namespace std;

const double Eps = 1e-8;
const double PI = acos(-1.0);
const int N = 1e6+5;
const int MOD = 1e9+7;

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
int n;
void solve()
{
	cin>>n;
	for(int i=-2;i<=2;i++)
	{
		for(int j=-2;j<=2;j++)
		{
			for(int k1=-2;k1<=2;k1++)
			{
				for(int k2=-2;k2<=2;k2++)
				{
//					for(int k3=-5;k3<=5;k3++)
//					{
//						for(int k4=-5;k4<=5;k4++)
//						{
//							if(i*j+k1*k2+k3*k4==i*(j+k1)*(k2+k3)*k4&&i*j+k1*k2+k3*k4!=0&&i!=0&&j!=0&&k1!=0&&k2!=0&&k3!=0&&k4!=0&&i==k4&&j==k3&&k1==k2)
//							{
//								cout<<i<<" "<<j<<" "<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<endl;
//							}
//						}
//					}
//					if(i*j+k1*k2==i*(j+k1)*k2&&i*j+k1*k2!=0&&i!=0&&j!=0&&k1!=0&&k2!=0&&i==k2&&j==k1)
//					{
//						cout<<i<<" "<<j<<" "<<k1<<" "<<k2<<endl;
//					}
					for(int k3=-2;k3<=2;k3++)
					{
						for(int k4=-2;k4<=2;k4++)
						{
							for(int k5=-2;k5<=2;k5++)
							{
								for(int k6=-2;k6<=2;k6++)
								{
//									if(i*j+k1*k2+k3*k4+k5*k6==i*(j+k1)*(k2+k3)*(k4+k5)*k6&&i*j+k1*k2+k3*k4+k5*k6!=0&&i!=0&&j!=0&&k1!=0&&k2!=0&&k3!=0&&k4!=0&&k5!=0&&k6!=0&&i==k6&&j==k5&&k1==k4&&k2==k3)
//									{
//										cout<<i<<" "<<j<<" "<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<" "<<k5<<" "<<k6<<" "<<i*j+k1*k2+k3*k4+k5*k6<<endl;
//									}	
									if(i*j+k1*k2+k3*k4+k5*k6==i*(j+k1)*(k2+k3)*(k4+k5)*k6&&i*j+k1*k2+k3*k4+k5*k6!=0&&i!=0&&j!=0&&k1!=0&&k2!=0&&k3!=0&&k4!=0&&k5!=0&&k6!=0)
									{
										cout<<i<<" "<<j<<" "<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<" "<<k5<<" "<<k6<<" "<<i*j+k1*k2+k3*k4+k5*k6<<endl;
									}	
								}
							}
						}
					}
				}
			}
		}
	}
}
int main()
{
	IOS;
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}
/*
-2 3 -4 -4 3 -2
-1 -4 1 1 -4 -1
-1 4 -3 -3 4 -1
1 -4 3 3 -4 1
1 4 -1 -1 4 1
2 -3 4 4 -3 2

1 -5 -5 1
1 -4 -4 1
1 -3 -3 1
1 -2 -2 1
1 -1 -1 1
1 1 1 1
1 2 2 1
1 3 3 1
1 4 4 1
1 5 5 1

*/

