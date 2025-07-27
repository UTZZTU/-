#include<iostream>
#include<vector>
#include<algorithm>
typedef long long int ll;
using namespace std;
int c[1000010];
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,sum=0;
        cin>>a>>b;
        vector<int> A;
        for(int i=0;i<b;i++)
        {
            cin>>c[i];
            sum=sum+c[i];
        }
        if((sum%a)!=0)
            cout<<"impossible"<<endl;
        else
        {
            ll ave=sum/a;
            for(int i=0;i<b;i++)
            {
                if(c[i]!=ave)
                    A.push_back(c[i]);
            }
            int len=A.size();
            if((len%2)==1)
                cout<<"impossible"<<endl;
            else
            {
                int flat=1;
                sort(A.begin(),A.end());
                for(int i=0;i<len;i++)
                {
                    if(A[i]+A[len-i-1]!=ave)
                    {
                        flat=0;
                        cout<<"impossible"<<endl;
                        break;
                    }
                }
                if(flat)
                    cout<<"possible"<<endl;
            }
        }
        A.clear();
    }
    return 0;
}
