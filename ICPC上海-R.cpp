#include<iostream>
 
#include<algorithm>
 
#include<cmath>
 
using namespace std;
 
const double esp = 1e-9;
 
double n,v1,v2,d1,d2;
 
double ans;
 
double check(double mid){
 
    double pos1 = max(mid*v1-2*d1,(mid*v1-d1)/2)+d1;
 
    double pos2 = max(mid*v2-2*(n-d2),(mid*v2-(n-d2))/2)+(n-d2);
 
    pos2 = n-pos2;
 
    if(pos2 <= pos1) return true;
 
    return false;
 
}
 
double fmax(double x,double y){
 
    if(x > y)    return x;
 
    else return y;
 
}
 
double fmin(double x,double y){
 
    if(x > y)    return y;
 
    else return x;
 
}
 
int main(){
 
    int t;
 
    cin >> t;
    while(t--){
 
        cin >> n >> d1 >> v1 >> d2 >> v2;    
        if(d1 > d2){
 
            double t = d1;
 
            d1 = d2;
 
            d2 = t;
 
            t = v1;
 
            v1 = v2;
 
            v2 = t;        
 
        }
 
        // first:
 
        double x1 = fmin(n-d1,d1);
 
        double x2 = fmin(n-d2,d2);
 
        x1+=n,x2+=n;
 
        ans = fmin(x1/v1,x2/v2);
 
        //second:
 
        ans = fmin(ans,fmax((n-d1)/v1,d2/v2));
 
        //third:
 
        double l = max(d1/v1,(n-d2)/v2),r = ans;
//        cout<<ans<<endl;
 
        while(fabs(r-l) > esp){
 
            double mid = (l+r)/2;
 
            if(check(mid)){
 
                r = mid;           
 
                ans = min(ans,mid);
 
            }
 
            else l = mid;
 
             
 
        }
 
        printf("%.10lf\n",ans);
 
    }  
 
    return 0;
 
}