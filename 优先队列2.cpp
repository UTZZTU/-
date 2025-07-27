//  Created by ZYD in 2015.
//  Copyright (c) 2015 ZYD. All rights reserved.
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define Size 100000
#define ll long long
#define mk make_pair
#define pb push_back
#define mem(array) memset(array,0,sizeof(array))
typedef pair<int,int> P;
int n1,n2,n;
// int a[5000005];
priority_queue<long long > big,small;
long long sum,a;
int main()
{
    while(~scanf("%d %d %d",&n1,&n2,&n)){
        if(n1==0 && n2==0 && n==0) break;
        // memset(a,0,sizeof(a));
        sum=0;
        for(int i=1;i<=n;i++) 
        {
            scanf("%lld",&a);
            sum+=a;
            big.push(-a);
            if(big.size()>n1) big.pop();
            small.push(a);
            if(small.size()>n2) small.pop();
        }       
        for(int i=0;i<n1;i++){
            sum+=big.top();
            big.pop();
        }
        for(int i=0;i<n2;i++){
            sum-=small.top();
            small.pop();
        }
        printf("%.6f\n",(sum*1.0)/(n-n1-n2));
    }
    return 0;
}


