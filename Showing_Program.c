#include<stdio.h>
#include"Showing_Program.h"

void showing(char *ip , char *netmask){
	/*Cette fonction est utilisée pour l'entrée des donnée venant de l'utilisateur*/
	/*On leur demande de saisir leur adresse IP ainsi que le masque de sous réseau*/
	
		printf("Enter your IP adress and the netmask.\n");
		printf("\t1) Your IP adress: ");
		scanf("%s", ip);
		printf("\t2) The netmaks: ");
		scanf("%s", netmask);
}
