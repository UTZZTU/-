#include<stdio.h>
#include<string.h>

int Haab(void){
	char hms[8];
	int hm,hd,hy,num;
	scanf("%d. %s %d",&hd,hms,&hy);
	if(!strcmp(hms,"pop")) hm = 0;
	else if(!strcmp(hms,"no")) hm = 1;
	else if(!strcmp(hms,"zip")) hm = 2;
	else if(!strcmp(hms,"zotz")) hm = 3;
	else if(!strcmp(hms,"tzec")) hm = 4;
	else if(!strcmp(hms,"xul")) hm = 5;
	else if(!strcmp(hms,"yoxkin")) hm = 6;
	else if(!strcmp(hms,"mol")) hm = 7;
	else if(!strcmp(hms,"chen")) hm = 8;
	else if(!strcmp(hms,"yax")) hm = 9;
	else if(!strcmp(hms,"zac")) hm = 10;
	else if(!strcmp(hms,"ceh")) hm = 11;
	else if(!strcmp(hms,"mac")) hm = 12;
	else if(!strcmp(hms,"kankin")) hm = 13;
	else if(!strcmp(hms,"muan")) hm = 14;
	else if(!strcmp(hms,"pax")) hm = 15;
	else if(!strcmp(hms,"koyab")) hm = 16;
	else if(!strcmp(hms,"cumhu")) hm = 17;
	else if(!strcmp(hms,"uayet")) hm = 18;
	num = hy * 365 + hm * 20 + hd + 1;
	//printf("num=%d\n",num);
	return num;
}
void Tzolkin(int num){
	int tm,ty,td,tmp;
	char tds[8];
	ty = num / 260;
	tmp = num - ty * 260;
	if(tmp == 0) ty--;
	td = tmp % 20;
	tm = tmp % 13;
	if(tm == 0){
		tm = 13;
	}
	switch(td){
		case 0:strcpy(tds,"ahau");break;
		case 1:strcpy(tds,"imix");break;
		case 2:strcpy(tds,"ik");break;
		case 3:strcpy(tds,"akbal");break;
		case 4:strcpy(tds,"kan");break;
		case 5:strcpy(tds,"chicchan");break;
		case 6:strcpy(tds,"cimi");break;
		case 7:strcpy(tds,"manik");break;
		case 8:strcpy(tds,"lamat");break;
		case 9:strcpy(tds,"muluk");break;
		case 10:strcpy(tds,"ok");break;
		case 11:strcpy(tds,"chuen");break;
		case 12:strcpy(tds,"eb");break;
		case 13:strcpy(tds,"ben");break;
		case 14:strcpy(tds,"ix");break;
		case 15:strcpy(tds,"mem");break;
		case 16:strcpy(tds,"cib");break;
		case 17:strcpy(tds,"caban");break;
		case 18:strcpy(tds,"eznab");break;
		case 19:strcpy(tds,"canac");break;
		default:break;
	}
	printf("%d %s %d\n",tm,tds,ty);
}
int main(void){
	int n,nn,num;
	scanf("%d",&n);
	printf("%d\n",n);
	nn = n;
	while(nn--){
		num = Haab();
		Tzolkin(num);
	} 
	return 0;
}
