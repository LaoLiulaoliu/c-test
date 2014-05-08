#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	if (argc < 3) {
		printf("Usage: %s IP_address Port\n", argv[0]);
		exit(1);
	}

	struct sockaddr_in IP;
	bzero (&IP, sizeof(IP));

	IP.sin_family = AF_INET;
	IP.sin_port = htons((unsigned short)atoi(argv[2]));// uint16_t, NBO
	IP.sin_addr.s_addr = inet_addr(argv[1]);// uint32_t, NBO

	printf("%u,%X :%u,%X\n", IP.sin_addr.s_addr, IP.sin_addr.s_addr, IP.sin_port, IP.sin_port);
	printf("%s\n", inet_ntoa(IP.sin_addr));//NBO, inverse of inet_addr

	return 0;
}
