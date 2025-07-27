#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <bitset>
#include <set>
#include <utility>
#include <sstream>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define inf 0x3f3f3f3f
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define lep(i,l,r) for(int i=l;i>=r;i--)
#define ms(arr) memset(arr,0,sizeof(arr))
//priority_queue<int,vector<int> ,greater<int> >q;
const int maxn = (int)1e5 + 5;
const ll mod = 1e9+7;
int main() 
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0),cin.tie(0);
	string s1,s2;
	while(cin>>s1>>s2)
	{
		int len1=s1.size();
		int len2=s2.size();
		if(len1!=len2){cout<<"NO"<<endl;continue;}
		map<char,int> ss1; ss1.clear();
		map<char,int> ss2; ss2.clear();
		multiset<int> num1; num1.clear();
		multiset<int> num2; num2.clear();
		rep(i,0,len1-1) ss1[s1[i]]++;
		rep(i,0,len2-1) ss2[s2[i]]++;
		bool ju=false;
		for(char c='A';c<='Z';c++) {num1.insert(ss1[c]);num2.insert(ss2[c]);}
		multiset<int>::iterator ite1=num1.begin();
	 	multiset<int>::iterator ite2=num2.begin();
		for(;ite1!=num1.end();ite1++,ite2++) if(*ite1!=*ite2) ju=true;
		if(ju) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
    return 0;
}