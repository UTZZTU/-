#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second

map<vector<ll>,ll>ma;
pair<vector<ll> ,ll>p[10005];
ll n,m;
bool cmp(pair<vector<ll> ,ll> x,pair<vector<ll> ,ll> y)
{
    if(x.se == y.se){//如果两组数目相同
        for(ll i = 0;i < x.fi.size();i++){//遍历输出
            if(x.fi[i] != y.fi[i])//碰到输出不同的元素
                return x.fi[i] < y.fi[i];//按元素大小从小到大排序
        }
    }
    return x.se > y.se;//若数目不同，返回数目大的
}


int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    vector<ll>tmp;//输入临时存储数组
    ll num;
    for(ll i = 0;i < n;i++){
        tmp.clear();//将临时数组清空
        for(ll j = 0;j < m;j++){
            cin >> num;
            tmp.push_back(num);
        }
        ma[tmp]++;//记录输出相同的数目
    }
    ll idx = 1;//pair的下表，pair的first元素存储输出的数组，second元素存储这样输出的有多少组
    for(auto it = ma.begin();it != ma.end();it++,idx++){
        //遍历map，将map中元素存入pair数组中
        p[idx].fi = it->fi;
        p[idx].se = it->se;
    }
    idx--;//最后idx多遍历一次，减去
    sort(p + 1,p + idx + 1,cmp);//给pair数组排序，排序规则见cmp
    cout << ma.size() << endl;
    for(ll i = 1;i <= idx;i++){
        cout << p[i].se;
        for(ll j = 0;j < p[i].fi.size();j++){
            cout << " " << p[i].fi[j];
        }
        if(i != idx)
        cout << endl;
    }
}