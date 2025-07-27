#include<bits/stdc++.h>
using namespace std;
vector<int> num;
vector<int> v1;
vector<int> v2;
int sum;
int n;
int fl[505];
int main(){
    cin>>n;
    int k;

    num.push_back(0);
    for(int i=1;i<=n;i++){
        cin>>k;
        num.push_back(k);
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            if(num[i]>num[j])
                sum++;
        }
    int summ=sum;
    for(int i=n;i>=1&&sum!=0;i--){
        if(sum>=i-1) {
            v1.push_back(i);
            sum-=i-1;
            fl[i]=1;
        }
        else {
            v1.push_back(sum+1);
            fl[sum+1]=1;
            sum=0;
        }
    }
    for(int i=1;i<=n;i++){
        if(fl[i]!=1) v1.push_back(i);
    }

    memset(fl,0,sizeof(fl));
    for(int i=n;i>=1&&summ!=0;i--){
        if(summ>=i-1) {
            v2.push_back(n-i+1);
            summ-=i-1;
            fl[n-i+1]=1;
        }
        else {
            v2.push_back(n-summ);
            fl[n-summ]=1;
            summ=0;
        }
    }
    for(int i=n;i>=1;i--){
        if(fl[i]!=1) v2.push_back(i);
    }
    std::reverse(v2.begin(), v2.end());
    num.erase(num.begin());
    if(v1!=num) {
        for(int i=0;i<n;i++)
            cout<<v1[i]<<" ";
        return 0;
    }
    else if(v2!=num) {
        for(int i=0;i<n;i++)
            cout<<v2[i]<<" ";
        return 0;
    }
    else cout<<"-1";
    return 0;
}

/*
10
1 2 3 4 5 6 7 8 9 10

 */