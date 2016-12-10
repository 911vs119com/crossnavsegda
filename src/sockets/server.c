#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
	int buf[100];
	int sock = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
	if (sock < 0)
	{
		printf("socket error\n");
		exit(0);
	}
	struct sockaddr_in server;
	memset(&server,0,sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(1100);
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock,&server,sizeof server))
	{
		printf("bind error\n");
		close(sock);
		exit(0);
	}
	if (listen(sock,10))
	{
		printf("listen error\n");
		close(sock);
		exit(0);
	}

	while(1)
	{
		int msgsock = accept(sock,NULL,NULL);
		if (msgsock < 0)
		{
			printf("accept error\n");
			close(sock);
			exit(0);
		}
		read(msgsock,buf,100);
		if (shutdown(msgsock, SHUT_RDWR) == -1)
		{
			perror("shutdown error");
			close(msgsock);
			close(sock);
			exit(0);
		}
		close(msgsock);
	}
	close(sock);

	return 0;
}
