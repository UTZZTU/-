#include<bits/stdc++.h>
using namespace std;
int a[10],w[10]={0,1,2,5,10};//输入用的数组以及存储每种石头的重量的数组 
int dp[100005],ans;//拿来查看每个重量是否能够被称出的的数组以及最终答案 
int main(){
    for(int i=1;i<=4;i++)//输入 
        cin>>a[i];
    dp[0]=1; 
    for(int i=1;i<=4;i++){//第一个循环循环的内容是每种重量 
        for(int j=1;j<=a[i];j++){//第二个则是每种重量的石头的个数 
            for(int k=10000;k>=0;k--){//每个重量去试 
                if(dp[k]&&k+w[i]<=10000){ 
                    dp[abs(k+w[i])]=1;//加 
                    dp[abs(k-w[i])]=1;//减 
                }
            }
        }
    }
    for(int i=1;i<=10000;i++){
        if(dp[i])ans++;//遍历dp数组查找能够称出重量的数量 
    }
    printf("%d",ans);//输出答案 
    return 0;
} 
