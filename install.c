#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main () {
    /* declare variables */
    char command[100];
    char ip[25];
    char novarcmd[100];
    char novarcmd0[100];
    char novarcmd1[100];

    FILE *fp;

    /* check if file .filterdata exists */
    if ( access ( "/usr/local/bin/.filterdata", F_OK ) != -1 ) {
	/* open and read the file */
	fp = fopen("/usr/local/bin/.filterdata", "r");
	fgets(ip, 25, (FILE*)fp);
	fclose(fp);
    } else {
	/* print request for proxy data from user (when not found in file). */
	printf("Welcome to Linux_filter.  Please enter proxy ip address and port in this format: xxx.xxx.xxx.xxx:XXXX:");
	scanf(" %s", ip);
	printf("\n");
	/* and write it to a file */
	fp = fopen("/usr/local/bin/.filterdata", "w+");
	fprintf(fp, "%s\n", ip);
	fclose(fp);
    }

    /* actually use the data starting by flushing iptable nat (currently not working). */
    strcpy( command, "iptables -t nat -F" );
    system(command);
    /* enable forwarding */
    strcpy( command, "echo '1' > /proc/sys/net/ipv4/ip_forward" );
    system(command);
    /* next few lines set proxy */
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