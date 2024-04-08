/*
                                                          Program No:4.1
                   CLIENT SERVER COMMUNICATION USING SOCKET PROGRAMMING AND UDP AS TRANSPORT LAYER PROTOCOL(Client)
                                                 (Server and client on same machine)
                                                 ===================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
void main()
{
   int sockid,valsend;
   char buffer[1024];
   struct sockaddr_in server;
   server.sin_family=AF_INET;
   server.sin_port=htons(8080);
   server.sin_addr.s_addr=INADDR_ANY;
   
   sockid=socket(AF_INET,SOCK_DGRAM,0);
   if(sockid<0)
       printf("Socket creation is not successful!!!\n");
   else
       printf("Socket creation is successful!!!\n");
   
   printf("Enter the data to send:");
   fgets(buffer,1024,stdin);
       
   valsend=sendto(sockid,buffer,sizeof(buffer),0,(struct sockaddr*)&server,sizeof(server));
   if(valsend<0)
       printf("There is a problem in sending!!!\n");
   else
       printf("Message sended successfully!!!\n");
       
   close(sockid);
}
/*
OUTPUT
======
Socket creation is successful!!!
Enter the data to send:hello albin
Message sended successfully!!!
*/