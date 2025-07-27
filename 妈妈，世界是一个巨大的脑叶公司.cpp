#include<bits/stdc++.h>
using namespace  std;
using i64 = long long;
int main(){
    i64 n,m,k;
    cin >> n >> m >> k;
    vector<i64> a(n + 1),b(n + 1),hp(n + 1);
    set<pair<i64,i64>> se;
    i64 sum = 0,old = 0;
    for(int i = 1;i <= n; i  ++)
        cin >> a[i];
    for(int i = 1;i <= n ;i  ++)
        cin >> b[i];
    int cnt = n;
    for(int i = 1;i <= n; i ++){        
        hp[i] = b[i];
        se.insert({b[i],i});
        sum += a[i];
    }
    while(k --){
        int op;cin >> op;
        if(op == 1){
            int x;cin >> x;
            sum += a[x];
            se.insert({hp[x] = old + b[x],x});
        }else if(op == 2){
            int x;cin >> x;
            sum -= a[x];
            se.erase({hp[x],x});
        }else if(op == 3){
            int y;cin >> y;
            old += y;
            while(se.size() && se.begin() -> first <= old){
                cnt --;
                sum -= a[se.begin()->second];
                se.erase(se.begin());
            }
        }else{
            int x,h;
            cin >> x >> h;
            se.erase({hp[x],x});
            se.insert({hp[x] = min(old + b[x],hp[x] + h),x});
        }
        m -= sum;
        if(m <= 0)break;
    }
    if(m > 0){
        cout <<"NO\n";
    }else {
        cout <<"YES\n";
        cout << cnt <<"\n";
    }
}