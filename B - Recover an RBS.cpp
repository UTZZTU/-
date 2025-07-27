#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vec vector<int>
#define rep(i,l,r) for(int i=l;i<=r;++i)
#pragma GCC optimize(2)//
#pragma GCC optimize(3,"Ofast","inline")//
const int maxj=2e5+10,mod=1e9+7,nn=33554432,inf=0x7f7f7f7f7f7f7f;
int ksm(int a,int b){//快速幂
    int ans=1;
    while(b){
        if(b&1)ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans;
}
int log2(int a){
    return floor(log(a)/log(2));
}
int lower_bit(int x){
    return x&(-x);
}
// bool check(int x){//判断回文数
//     int y=x,t=0;
//     while(y){
//         t=t*10+y%10;
//         y/=10;
//     }return x==t;
// }
// bool cmp1(int a,int b){//从大到小
//     return a>b;
// }
// bool cmpp(pair<char,int>a,pair<char,int>b){
//     return a.second<b.second;
// }
// int pai(int x){//全排列
//     if(x==0||x==1)return 1;
//     return x*pai(x-1)%mod;
// }
// int e[maxj],nex[maxj],head[maxj],cnt=1;
// void add(int u,int v){//链式前向星
//     e[cnt]=v;
//     nex[cnt]=head[u];
//     head[u]=cnt++;
// }
// bool cmp(node a,node b){//结构体排序
//     return a.c>b.c;
// }
void solve(){
    string s;cin>>s;
    int cnt=0,now=0;
    rep(i,0,s.size()-1){//先考虑RBS，去配对，然后才考虑是否是唯一解
        if(s[i]=='(')cnt++;
        else if(s[i]==')'){
            cnt--;
            while(cnt<0){
                cnt++,now--;//（和？配对
            }
        }else now++;
        if(cnt==0&&now==1)now--,cnt++;//题目中保证有合法解
    }if(abs(cnt)==now)cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);//能不用c语言的输入输出，尽量不要用
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);//a为add
#endif
    int t;
    cin>>t;
    // t=1;
    while(t--)solve();
    return 0;
}