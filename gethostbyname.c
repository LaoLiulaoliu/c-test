#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	char *ptr, **pptr;
	struct hostent *host_ent;
	char str[16];

	ptr = argv[1];

	if (!(host_ent = gethostbyname(ptr)))
	{
		printf("Error occur for host: %s\n", ptr);
		return -1;
	}

	printf("Official hostname: %s\n", host_ent->h_name);
	for (pptr = host_ent->h_aliases; *pptr != NULL; pptr++)
		printf("aliases: %s\n", *pptr);
	
	switch (host_ent->h_addrtype)
	{
		case AF_INET:
		case AF_INET6:
			pptr = host_ent->h_addr_list;
			for (; *pptr != NULL; pptr++)
            {
				printf("address: %s\n", inet_ntop(host_ent->h_addrtype, *pptr, str, sizeof(str)));
                printf("\t%d, %s\n", *pptr, str);
            }
			break;
		default:
			printf("Unknow address type\n");
	}
	return 0;
}
