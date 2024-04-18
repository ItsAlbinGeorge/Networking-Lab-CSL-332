/*
                                                            Program No:8
                                                     STOP AND WAIT ARQ(Server)
                                                    ==========================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
typedef struct packet
{
	char data[1024];
}Packet;
typedef struct frame
{
	int frame_kind;
	int sq_no;
	int ack;
	Packet packet;
}Frame;
int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("Usage: %s <port>",argv[0]);
		exit(0);
	}
	int port=atoi(argv[1]);
	int sockid;
	struct sockaddr_in server,client;
	char buffer[1024];
	socklen_t addr_size;
	int frame_id=0;
	Frame frame_recv;
	Frame frame_send;
	sockid=socket(AF_INET,SOCK_DGRAM,0);
	memset(&server,'\0',sizeof(server));
	server.sin_family=AF_INET;
	server.sin_port=htons(port);
	server.sin_addr.s_addr=INADDR_ANY;
	bind(sockid,(struct sockaddr*)&server,sizeof(server));
	addr_size=sizeof(client);
	while(1)
	{
		int f_recv_size=recvfrom(sockid,&frame_recv,sizeof(Frame),0,(struct sockaddr*)&client,&addr_size);
		if(f_recv_size>0&&frame_recv.frame_kind==1&&frame_recv.sq_no==frame_id)
		{
			printf("[+]Frame Received: %s\n",
			frame_recv.packet.data);
			frame_send.sq_no=0;
			frame_send.frame_kind=0;
			frame_send.ack=frame_recv.sq_no+1;
			sendto(sockid,&frame_send,sizeof(frame_send),0,(struct sockaddr*)&client,addr_size);
			printf("[+]Ack Send\n");
		}
		else
		{
			printf("[+]Frame Not Received\n");
		}
		frame_id++;
	}
    close(sockid);
	return 0;
}
/*
OUTPUT
======
[+]Frame Received: 1234
[+]Ack Send
[+]Frame Received: abcd
[+]Ack Send
[+]Frame Received: 123
[+]Ack Send
[+]Frame Received: 6789
[+]Ack Send
[+]Frame Received: 5
[+]Ack Send
*/