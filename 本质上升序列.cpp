#include <iostream>

using namespace std;

int dp[220];

int main()
{
    string str ="tocyjkdzcieoiodfpbgcncsrjbhmugdnojjddhllnofawllbhfiadgdcdjstemphmnjihecoapdjjrprrqnhgccevdarufmliqijgihhfgdcmxvicfauachlifhafpdccfseflcdgjncadfclvfmadvrnaaahahndsikzssoywakgnfjjaihtniptwoulxbaeqkqhfwl";
    for(int i = 0;i<200;i++){
        dp[i] = 1;
        for(int j=0;j<i;j++){
            if(str[i]>str[j]){
                dp[i] += dp[j];
            }else if(str[i] == str [j]){
                dp[i] -= dp[j];
            }
        }
    }

    long long ans = 0;
    for(int i=0;i<200;i++){
        ans+=dp[i];
    }
    cout<<ans<<endl;
    return 0;
}