/*
                                                            Program No:8
                                                     STOP AND WAIT ARQ(Client)
                                                    ==========================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
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
	struct sockaddr_in server;
	char buffer[1024];
	socklen_t addr_size;
	int frame_id=0;
	Frame frame_send;
	Frame frame_recv;
	int ack_recv=1;
	sockid=socket(AF_INET,SOCK_DGRAM,0);
	memset(&server,'\0',sizeof(server));
	server.sin_family=AF_INET;
	server.sin_port=htons(port);
	server.sin_addr.s_addr=INADDR_ANY;
	while(1)
	{
		if(ack_recv==1)
		{
			frame_send.sq_no=frame_id;
			frame_send.frame_kind=1;
			frame_send.ack=0;
			printf("Enter Data to send: ");
			scanf("%s",buffer);
			strcpy(frame_send.packet.data,buffer);
			sendto(sockid,&frame_send,sizeof(Frame),0,
			(struct sockaddr*)&server,sizeof(server));
			printf("[+]Frame Send\n");
		}
		int addr_size=sizeof(server);
		int f_recv_size=recvfrom(sockid,&frame_recv,
		sizeof(frame_recv),0,(struct sockaddr*)&server,&addr_size);
		if(f_recv_size>0&&frame_recv.sq_no==0&&frame_recv.ack==frame_id+1)
		{
			printf("[+]Ack Received\n");
			ack_recv=1;
		}
		else
		{
			printf("[-]Ack Not Received\n");
			ack_recv=0;
		}
		frame_id++;
	}
	close(sockid);
	return 0;
}
/*
OUTPUT
======
Enter Data to send: 1234
[+]Frame Send
[+]Ack Received
Enter Data to send: abcd
[+]Frame Send
[+]Ack Received
Enter Data to send: 123
[+]Frame Send
[+]Ack Received
Enter Data to send: 6789
[+]Frame Send
[+]Ack Received
Enter Data to send: 5
[+]Frame Send
[+]Ack Received
*/