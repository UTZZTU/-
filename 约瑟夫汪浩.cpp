#include<stdio.h>
int main()
{
	int i, j = 1, k, m = 0, cont = 0, re, nu[30],huo,item,w=0;
	while (scanf("%d", &k) != EOF){
		if (k == 0)break;
		m = 0; w = 0;
		while (w==0){
			m+=1;
			item = 0;
		for (i = 0; i < 30; i++)nu[i] = 1;
		i = 0; cont = 0; re = 2 * k;//ÌßÈË¿ªÊ¼£¡
		while (re>k){
			if (i == 2 * k)i = 0;
			if (nu[i] != 0)cont += 1;
			if (cont == m){
				nu[i] = 0;
				re -= 1;
				cont = 0;
			}
			i += 1;
		}
		for (i = 0; i < 2 * k; i++){
			if (nu[i] == 0)
				if (i < k)item = 1;
		}
		if (item == 0){
			printf("%d\n", m);
			w = 1;
			break;
		}
		}
	}
	return 0;
}
