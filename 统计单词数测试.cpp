#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
string s,sf;
int t;
int main(){
    getline(cin,sf);
    getline(cin,s);
    int j;
    for(j=0;j<=sf.size();j++)
        sf[j]=tolower(sf[j]);
    for(j=0;j<=s.size();j++)
        s[j]=tolower(s[j]);
    sf=' '+sf+' ';
    s=' '+s+' ';
    int posi=-1;
    int fpos=0;
    if(s.find(sf)==string::npos){
        cout<<"-1";
        return 0;
        }
    fpos=s.find(sf);
    while(s.find(sf,posi+1)!=string::npos){
        posi=s.find(sf,posi+1);
        t++;
    }
    cout<<t<<" "<<fpos;
    return 0;
}