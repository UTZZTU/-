#include <bits/stdc++.h>
using namespace std;
#define se second
#define fi first
typedef long long ll;
const ll N = 1e5 + 10;
vector<ll> p[N];
ll st[105];
ll a;
map<ll,ll>ma;
ll num;
ll n,m;
int main()
{
    ios::sync_with_stdio(false);//关闭同步流
    cin >> n >> m;//n为剧情点个数，m为游戏操作
    for(ll i = 1;i <= n;i++){
        cin >> num;//num表示第i个剧情点能到的剧情点个数
        for(ll j = 0;j < num;j++){
            cin >> a;
            p[i].push_back(a);
            //将第i个剧情点能到达的剧情点存入第i个动态数组
        }
    }
    ll ch;
    ll now = 1;//当前在的剧情点
    ll j;
    while(m--){
        cin >> ch >> j;
        if(ch == 0){
            now = p[now][j - 1];
        }
        else if(ch == 1){
            ma[j] = now;
            cout << now  << endl;
        }
        else if(ch == 2){
            now = ma[j];
        }
    }
    cout << now;
    return 0;
}

