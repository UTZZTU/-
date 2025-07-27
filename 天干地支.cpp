#include <iostream>
#include <string>
using namespace std;
int main ()
{
	std::string heavenly[10] = {"geng", "xin", "ren", "gui", "jia", "yi" , "bing", "ding", "wu", "ji"};
    std::string earthlyBranch[12] = {"shen", "you", "xu", "hai", "zi", "chou", "yin", "mou", "chen", "si", "wu", "wei"};
    int n;
    cin>>n;
    cout<<heavenly[n%10]<<earthlyBranch[n%12];
    return 0;
}