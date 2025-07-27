#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char num[11];
    char n1[11]="- -- -----";  
    char n2[11]="|   ||| ||";  
    char n3[11]="|||||  |||";  
    char n4[11]="  ----- --";  
    char n5[11]="| |   | | ";  
    char n6[11]="|| |||||||";  
    char n7[11]="- -- -- --"; 
    int s;
    string n;
    while(cin>>s>>n){
        if (s == 0 && n == "0")
            break;

        //first step
        int i, j, k;
        int l = n.length();
        for(i = 0; i < l - 1; i ++){
            cout<<' ';
            for(j = 0; j < s; j ++){
                cout<<n1[n[i] - '0'];
            }
            cout<<"  ";
        }
        cout<<' ';
        for(j = 0; j < s; j ++){
            cout<<n1[n[l - 1] - '0'];
        }
        cout<<endl;

        //second and third step
        for(i = 0; i < s; i ++){
            for(j = 0; j < l - 1; j ++){
                cout<<n2[n[j] - '0'];
                for(k = 0; k < s; k ++){
                    cout<<' ';
                }
                cout<<n3[n[j] - '0'];
                cout<<' ';
            }
            cout<<n2[n[l - 1] - '0'];
            for(k = 0; k < s; k ++){
                cout<<' ';
            }
            cout<<n3[n[l - 1] - '0'];
            cout<<endl;
        }

        //forth step
        for(i = 0; i < l - 1; i ++){
            cout<<' ';
            for(j = 0; j < s; j ++){
                cout<<n4[n[i] - '0'];
            }
            cout<<"  ";
        }
        cout<<' ';
        for(j = 0; j < s; j ++){
            cout<<n4[n[l - 1] - '0'];
        }
        cout<<endl;

        //fifth and sixth step
        for(i = 0; i < s; i ++){
            for(j = 0; j < l - 1; j ++){
                cout<<n5[n[j] - '0'];
                for(k = 0; k < s; k ++){
                    cout<<' ';
                }
                cout<<n6[n[j] - '0'];
                cout<<' ';
            }
            cout<<n5[n[l - 1] - '0'];
            for(k = 0; k < s; k ++){
                cout<<' ';
            }
            cout<<n6[n[l - 1] - '0'];
            cout<<endl;
        }

        //seventh step
        for(i = 0; i < l - 1; i ++){
            cout<<' ';
            for(j = 0; j < s; j ++){
                cout<<n7[n[i] - '0'];
            }
            cout<<"  ";
        }
        cout<<' ';
        for(j = 0; j < s; j ++){
            cout<<n7[n[l - 1] - '0'];
        }
        cout<<endl;
        cout<<endl;
    }
    return 0;
} 

