#include<stdio.h>
#include"Data_Manipulation.h"
#include"Showing_Program.h"
int main(){
	char ip[16];
	char netmask[16];
	adress ip1 ;
	int netmask_verify = 0 , bits_number = 1 , class = 1;
	int ip_class = 0;
	
	showing(ip , netmask);
	netmask_verify = verify_netmask(netmask);
	bits_number = bits_host(netmask_verify);
	indexed_IP(ip , &ip1);
	verify_IP_validity(&ip1);
	ip_class =  verify_IP_class(&ip1);
	class = compatibility_IP_class( netmask_verify , ip_class);
	network_adress(class , &ip1);
	broadcast_adress( class , &ip1);
	number_of_machine(bits_number);
	
	return 0;
}




