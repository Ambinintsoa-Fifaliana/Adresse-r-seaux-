#include<stdio.h>
#include"Struct.h"
int bits_host(int netmask_verify);
void indexed_IP(char *ip , adress *divided);
int verify_IP_class(adress *ip1);
int verify_netmask(char *netmask);
void verify_IP_validity(adress *ip1);
int compatibility_IP_class(int netmask_verify , int ip_class);
void network_adress(int class , adress *ip1);
void broadcast_adress(int class , adress *ip1);
void number_of_machine(int bits_number);
