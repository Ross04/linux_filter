#include <stdio.h>
#include <string.h>

int main () {
    char command[100];

    strcpy( command, "sudo iptables -F" );
    system(command);
    strcpy( command, "echo '1' > /proc/sys/net/ipv4/ip_forward" );
    system(command);
    strcpy( command, "sudo iptables -t nat -A OUTPUT -p tcp --dport 80 -j DNAT --to-destination 192.168.1.9:8080" );
    system(command);
    strcpy( command, "sudo iptables -t nat -A OUTPUT -p tcp --dport 443 -j DNAT --to-destination 192.168.1.9:8080" );
    system(command);
    strcpy( command, "sudo iptables -t nat -A OUTPUT -p udp --dport 443 -j DNAT --to-destination 192.168.1.9:8080" );
    system(command);

    return(0);
}