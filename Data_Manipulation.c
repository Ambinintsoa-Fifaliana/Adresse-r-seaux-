#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include"Data_Manipulation.h"


int bits_host(int netmask_verify){
	/*Cette fonction return le nombre des bits pour les hôtes apres avoir verifié la class du masque de sous reseau*/
	
		if(netmask_verify == 1){
			return 24;
			}
		else if(netmask_verify == 2){
			return 16;
			}
		else if(netmask_verify == 3){
			return 8;
			}
}


void indexed_IP(char *ip , adress *divided){
	/*On utlise cette fonction pour diviser l'adresse IP entrer par l'utilisateur pour mieux l'analyser*/
	/*On stocke chaque valeur devant les . de l'adresse dans chacun des membres du structure declarer en-desssus*/
	
	int n1;
	char *IP = NULL;
	
	IP = strtok(ip , ".");
	n1 = atoi(IP);
	divided->firstpart = n1;
	
	IP = strtok(NULL , ".");
	n1 = atoi(IP);
	divided->secondpart = n1;
	
	IP = strtok(NULL , ".");
	n1 = atoi(IP);
	divided->thirdpart = n1;
	
	IP = strtok(NULL , ".");
	n1 = atoi(IP);
	divided->fourthpart = n1;
	
}


int verify_IP_class(adress *ip1){
	/*Cette fonction verifie à quel classe appartient l'adresse IP*/
	
		if(ip1->firstpart >= 0 &&  ip1->firstpart <= 127 ){
			return 1;
		}
		else if(ip1->firstpart >= 128 &&  ip1->firstpart <= 191 ){
			return 2;
		}
		else if(ip1->firstpart >= 192 &&  ip1->firstpart <= 223 ){
			return 3;
		}
		else{
			return 0;
			}
}

int verify_netmask(char *netmask){
	/*Cette fonction est conçue pour découvrir le type de masque de sous réseau entrer par l'utilisateur*/
	/*On verifie aussi s'il est valide*/
	
		if ((strcmp(netmask , "255.0.0.0")) == 0){
			return 1; /*The netmask class is A*/
			}
		else if ((strcmp(netmask , "255.255.0.0")) == 0){
			return 2;  /*The netmask class is B*/
			}
		else if ((strcmp(netmask , "255.255.255.0")) == 0){
			return 3;  /*The netmask class is B*/
			}
		else{
			printf("Invalid netmask\n");
			exit(1);
			}
}

void verify_IP_validity(adress *ip1){
	/*Cette fonction verifie si les adresse IP sont valide*/
	
		if(ip1->firstpart < 0 || ip1->secondpart < 0 ||  ip1->thirdpart < 0 || ip1->fourthpart < 0){
			printf("IP Adress invalid\n");
			exit(1);
		}
		if(ip1->firstpart > 255 || ip1->secondpart > 255 ||  ip1->thirdpart > 255 || ip1->fourthpart > 255){
			printf("IP Adress invalid\n");
			exit(1);
		}
}

int compatibility_IP_class(int netmask_verify , int ip_class){
	/*Cette fonction verifie si l'adresse IP et la masque de sous reseau appartient au meme classe*/
	printf("\n\t\t***RESULT***\n");
	printf("\t1)IP class:");
		if(netmask_verify == 1 && ip_class == 1){
			printf("\n⇒ A\n");
			return 1;
			}
		else if(netmask_verify == 2 && ip_class == 2){
			printf("\n⇒ B\n");
			return 2;
			}
		else if(netmask_verify == 3 && ip_class == 3){
			printf("\n⇒ C\n");
			return 3;
			}
		else{
			printf("The IP adress and the netmask are incompatible\n");
			exit(1);
			}
}
void network_adress(int class , adress *ip1){
	/*Apres tous ces etapes , cette fonction affiche l'adresse reseau de l'adresse IP donnée*/
	printf("\t2)Adress network: ");
	if(class == 1){
		printf("\n⇒ %d.0.0.0\n ", ip1->firstpart);
		}
	if(class == 2){
		printf("\n⇒ %d.%d.0.0\n ", ip1->firstpart , ip1->secondpart);
		}
	if(class == 3){
		printf("\n⇒ %d.%d.%d.0\n ", ip1->firstpart , ip1->secondpart , ip1->thirdpart);
		}
}
void broadcast_adress(int class , adress *ip1){
	/*Cette fonction affiche l'adresse broadcast du reseau*/
	printf("\t3)Adress broadcast: ");
	if(class == 1){
		printf("\n⇒ %d.255.255.255\n ", ip1->firstpart);
		}
	if(class == 2){
		printf("\n⇒ %d.%d.255.255\n ", ip1->firstpart , ip1->secondpart);
		}
	if(class == 3){
		printf("\n⇒ %d.%d.%d.255\n ", ip1->firstpart , ip1->secondpart , ip1->thirdpart);
		}
}
void number_of_machine(int bits_number){
	/*Cette fonction affiche le nombre d'adresse IP ou nombre de machine utilisable pour le reseau donnée*/
	printf("\t4)...");
	if(bits_number == 24){
		printf("\n⇒ The number of the machine that we can use is 16 777 214\n");
		}
	if(bits_number == 16){
		printf("\n⇒ The number of the machine that we can use is 65 534\n");
		}
	if(bits_number == 8){
		printf("\n⇒ The number of the machine that we can use is 254\n");
		}
}
