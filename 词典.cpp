#include<iostream>
#include<cstdio>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<list>
using namespace std;
int read(){
    char ch;
    int res=0,f=1;
    ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        res=res*10+(ch-'0');
        ch=getchar();
    }
    return res*f;
}
map<string,string>u;
string s,k,g;
int y;
int main(){
    while(1){
        getline(cin,s);
        y=s.find(' ');
        if(y!=s.npos){
            k=s.substr(0,y+1);
            g=s.substr(y+1);
            u.insert(make_pair(g,k));
        }
        else break;
    }
    while(cin>>s){
        if(u.count(s))cout<<u[s]<<endl;
        else cout<<"eh"<<endl;
    }
    return 0;
}