#include <bits/stdc++.h>
using namespace std;
string s[1000010],w;
int cnt,pos,flag;
int main ()
{
	while(getline(cin,w))
	{
		if(w.size()==1&&w[0]=='#')
		break;
		flag=0;
		string words;
		for(int i=0;i<w.size();i++)
		{
			if(w[i]==' ')
			{
				if(words=="NEUQ")
				{
					s[pos]+="WOW NEUQ ";
				}
				else
				{
					s[pos]+=words+" ";
				}
				if(words!="NEUQ"&&words.size()==4&&(words[0]=='N'||words[0]=='n')&&(words[1]=='E'||words[1]=='e')&&(words[2]=='U'||words[2]=='u')&&(words[3]=='Q'||words[3]=='q'))
				cnt++;
				words.clear();
			}
			else
			words+=w[i];
		}
		if(words=="NEUQ")
				{
					s[pos]+="WOW NEUQ";
				}
				else
				{
					s[pos]+=words;
				}
				if(words!="NEUQ"&&words.size()==4&&(words[0]=='N'||words[0]=='n')&&(words[1]=='E'||words[1]=='e')&&(words[2]=='U'||words[2]=='u')&&(words[3]=='Q'||words[3]=='q'))
				cnt++;
		pos++;
	}
	cout<<cnt<<endl;
	for(int i=0;i<pos;i++)
	{
		cout<<s[i]<<endl;
	}
	return 0;
}