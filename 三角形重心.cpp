#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int N = 1e5+5;
int x[N],y[N];
map<pair<int,int>,vector<int>>mp;
bool flag = 0;
int main(){
    int n;  cin>>n;
    for(int i = 1;i<=n;i++)cin>>x[i]>>y[i];
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            for(int k = j+1;k<=n;k++){
                int sum_x = x[i]+x[j]+x[k];
                int sum_y = y[i]+y[j]+y[k];
                pair pa = make_pair(sum_x,sum_y);
                if(mp.count(pa)){
                    cout<<"YES"<<endl;
                    cout<<i<<' '<<j<<' '<<k<<endl;
                    for(auto s:mp[pa])cout<<s<<' ';
                    return 0;
                }
                else {
                    mp[pa].push_back(i);
                    mp[pa].push_back(j);
                    mp[pa].push_back(k);
                }
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}