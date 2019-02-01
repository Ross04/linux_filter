#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
    char command[100];
    char ip[25];
    char novarcmd[100];
    char novarcmd0[100];
    char novarcmd1[100];

    printf("Welcome to Linux_filter.  Please enter proxy ip address and port in this format: xxx.xxx.xxx.xxx:XXXX:");
    scanf(" %s", ip);
    printf("\n");

    strcpy( command, "iptables -t nat -F" );
    system(command);
    strcpy( command, "echo '1' > /proc/sys/net/ipv4/ip_forward" );
    system(command);
    strcpy( novarcmd, "iptables -t nat -A OUTPUT -p tcp --dport 80 -j DNAT --to-destination " );
    strcpy( command, strcat( novarcmd, ip ));
    system(command);
    strcpy( novarcmd0, "iptables -t nat -A OUTPUT -p tcp --dport 443 -j DNAT --to-destination " );
    strcpy( command, strcat( novarcmd0, ip ));
    system(command);
    strcpy( novarcmd1, "iptables -t nat -A OUTPUT -p udp --dport 443 -j DNAT --to-destination " );
    strcpy( command, strcat( novarcmd1, ip ));
    system(command);

    return(0);
}