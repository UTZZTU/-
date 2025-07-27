#include<bits/stdc++.h>
using namespace std;
map<string,int >mp;
int main() {
  int n,m;
  cin>>n;
  string a;
  for(int i=0;i<n;i++) {
    cin>>a;
    mp[a]=1;
  }
  cin>>m;
  string b[10010];
  for(int i=0;i<m;i++) {
    cin>>b[i];
  }
  for(int i=0;i<m;i++) {
    if(mp[b[i]])
    cout<<b[i]<<endl;
  }
}


