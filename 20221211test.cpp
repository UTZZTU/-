#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <bitset>
#include <vector>
void fre() { system("clear"), freopen("A.txt", "r", stdin); freopen("Ans.txt","w",stdout); }
void Fre() { system("clear"), freopen("A.txt", "r", stdin);}
void Run(int x = 0)      
{// 宏定义免注释 freopen
#ifdef ACM 
    if(! x) fre(); else Fre();
#endif
}
#define ios ios::sync_with_stdio(false)
#define Pi acos(-1)
#define pb push_back
#define fi first
#define se second
#define db double
#define ll long long
#define ull unsigned long long
#define Pir pair<ll, ll>
#define m_p make_pair
#define for_(i, s, e) for(ull i = (ll)(s); i <= (ll)(e); i ++)
#define rep_(i, e, s) for(ll i = (ll)(e); i >= (ll)(s); i --)
#define memset(ar, b, c) memset(ar, (int)b, c);
#define size() size() * 1LL
#define sc scanf
#define pr printf
#define sd(ar) scanf("%lld", &ar)
#define ss(ar) scanf("%s", ar)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define esp 1e-7
#define mod (ll)(1000)
using namespace std;
/*=========================ACMer===========================*/

void print(__int128 x)
{
    if(x < 0)
    {
        x = -x;
        putchar('-');
    }
    if(x > 9) print(x/10);
    putchar(x%10 + '0');
}

void scan(__int128 &x)
{
    x = 0;
    int f = 1;
    char ch;
    if((ch = getchar()) == '-') f = -1;
    else x = x * 10 + ch - '0';
    while((ch = getchar()) >= '0' && ch <= '9') x = x * 10 + ch - '0';
    x *= f;
}

int main()
{
    __int128 a = 1;
    __int128 b = (a << 64);
    print(b);

    return 0;
}