#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

/* Usage: ./a.out www.baidu.com
 *  or ./a.out 192.168.2.1
 */
int main(int argc, char *argv[])
{
	struct in_addr addr; // { in_addr_t s_addr; };
	struct hostent *host_ent;

    //convert the Internet host address from numbers-and-dots notation into binary data in network byte order.
	if ((addr.s_addr = inet_addr(argv[1])) == -1)
	{
        //if the "argv[1]" is not a IPv4 address in standard dot notation.It is a host name,or an IPv6 address in colon,or sth.
		if (!(host_ent = gethostbyname(argv[1])))
		{
			printf("Error occur!\n");
			return -1;
		}
		memcpy(&addr.s_addr, host_ent->h_addr, host_ent->h_length);
		printf("argv[1] is a domain name, not IP address. %d\n", host_ent->h_addr);
	}

    // addr.s_addr is unsigned int, network byte ordered(big endian) 
	printf("%u, %s\n", addr.s_addr, inet_ntoa(addr));

	return 0;
}
