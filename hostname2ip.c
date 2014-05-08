#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s hostname/ipaddress\n", argv[0]);
        exit(1);
    }

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

        char **pptr;
        for (pptr = host_ent->h_addr_list; *pptr != NULL; pptr++)
        {
            memcpy(&addr.s_addr, *pptr, host_ent->h_length);
            printf("argv[1] is a domain name, not IP address. %u, %d\n", **pptr, host_ent->h_length);
            printf("\t%u, %s\n", addr.s_addr, inet_ntoa(addr));
        }
	}
    else
    {
        // addr.s_addr is unsigned int, network byte ordered(big endian) 
        printf("%u, %s\n", addr.s_addr, inet_ntoa(addr));
    }

	return 0;
}
