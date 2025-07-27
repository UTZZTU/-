#include<bits/stdc++.h>
using namespace std;
int f[100][100]={};
int m;
bool k[1001]={};
void in(){//读入
    for(int i=1;i<=m*m;i++)
        for(int j=1;j<=m*m;j++)
            cin>>f[i][j];
}
bool hang(){//检查每一行是否有重复
    for(int i=1;i<=m*m;i++){
        memset(k,0,sizeof(k));
        for(int j=1;j<=m*m;j++){
            if(f[i][j]<0||f[i][j]>m*m)
                return false;
            if(k[f[i][j]])
                return false;
            k[f[i][j]]=true;
        }
    }
    return true;
}
bool lie(){//检查每一列是否有重复
    for(int i=1;i<=m*m;i++){
        memset(k,0,sizeof(k));
        for(int j=1;j<=m*m;j++){
            if(f[j][i]<0||f[j][i]>m*m)
                return false;
            if(k[f[j][i]])
                return false;
            k[f[j][i]]=true;
        }
    }
    return true;
}
bool gong(){//检查每一宫是否有重复
    for(int i=1;i<=m*m;i+=m)
        for(int j=1;j<=m*m;j+=m){
            memset(k,0,sizeof(k));
            for(int x=0;x<m;x++){
                for(int y=0;y<m;y++){
                    if(f[i+x][j+y]<0||f[i+x][j+y]>m*m)//如果数字太大，就判错
                        return false;
                    if(k[f[i+x][j+y]])
                        return false;
                    k[f[i+x][j+y]]=true;
                }
            }
        }
    return true;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m;
        in();
        printf("Case #%d: ",i);
        if(hang()&&lie()&&gong())cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}