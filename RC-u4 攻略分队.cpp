#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#pragma GCC optmize(3)
#pragma GCC optmize(2)
using namespace std;

int num[8],flag=-1,re=10000,l=-1;
bool st[8];
int cnt[8][3];
// mt, gong, zhihui
vector<int>a,b,s;

bool check(vector<int>&x,vector<int>&y)  
{   
    if(x.empty()||y.empty())return false;
    
    int res=-1,r1=0,r2=0;
    static int q[3],e[3];
    memset(q,0,sizeof q);memset(e,0,sizeof e);
    for(int i=0;i<x.size();i++)
    {
        int u=x[i];
        r1+=num[u];
        
        for(int j=0;j<3;j++)
        {
            if(cnt[u][j])q[j]++;    
        }
    }
    for(int i=0;i<y.size();i++)
    {
        int u=y[i];
        r2+=num[u];
        for(int j=0;j<3;j++)
        {
            if(cnt[u][j])e[j]++;    
        }
    }
 
    if(q[0]&&e[0]&&q[1]&&q[2]&&e[1]&&e[2]){
        if(flag<2){
            flag=2;
            re=abs(r1-r2);
            l=r1-r2>0?1:0;
            return true;
        }
        res=2;
    }
    else if(q[0]&&e[0]&&e[2]&&q[2]){
        if(flag<1){
            flag=1;
            re=abs(r1-r2);
            l=r1-r2>0?1:0;
            return true;
        }
        res=1;
    }
     else if(q[0]&&e[0]){
        if(flag<0){
            re=abs(r1-r2);
            l=r1-r2>0?1:0;
            flag=0;
            return true;
        }
        res=0;
    }
    else return false;
    
    if(res==flag)
    {
        if(abs(r1-r2)<re){
            
            re=abs(r1-r2);
            l=r1-r2>0?1:0;
            return true;
        }
        else if(abs(r1-r2)==re)
        {

            int j=r1-r2>0?1:0;
            if(l<j){
                l=j;
                return true;
            }
            else if(l==j){
                return x<a;
            }
        }
    }
 
    return false;
}

int main(){
   
    for(int i=1;i<=6;i++){
    scanf("%d",&num[i]);
    if(num[i]!=0)s.push_back(i);
    }
 
    for(int i=1;i<=6;i++)
    {
        string x;
        cin>>x;
        for(int j=0;j<3;j++)
        cnt[i][j]=x[j]-'0';
    }
    int t=s.size();
    
    for(int i=1;i<1<<t;i++){
        vector<int>x,y;   
        for(int j=0;j<s.size();j++)
        {   
            if(i>>j&1)
            x.push_back(s[j]);
            else y.push_back(s[j]);
        }
        if(check(x,y))a=x,b=y;
    } 
    if(!a.size()||!b.size())return puts("GG"),0;
    for(int i=0;i<a.size();i++){
        if(i)printf(" ");
        cout<<a[i];
    }
    cout<<endl;
    for(int i=0;i<b.size();i++){
        if(i)printf(" ");
        cout<<b[i];
    }
    exit(0);
}
