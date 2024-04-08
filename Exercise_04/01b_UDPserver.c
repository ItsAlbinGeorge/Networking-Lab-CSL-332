/*
                                                          Program No:4.1
                CLIENT SERVER COMMUNICATION USING SOCKET PROGRAMMING AND UDP AS TRANSPORT LAYER PROTOCOL(Server)
                                                 (Server and client on same machine)
                                                 ==================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
void main()
{
   int sockid,bin,valreceive;
   char buffer[1024];
   struct sockaddr_in server,client;
   server.sin_family=AF_INET;
   server.sin_port=htons(8080);
   server.sin_addr.s_addr=INADDR_ANY;
   socklen_t client_len=sizeof(client);
   
   sockid=socket(AF_INET,SOCK_DGRAM,0);
   if(sockid<0)
       printf("Socket creation is not successful!!!\n");
   else
       printf("Socket creation is successful!!!\n");
   
   bin=bind(sockid,(struct sockaddr*)&server,sizeof(server));
   if(bin<0)
       printf("There is a problem in binding!!!\n");
   else
       printf("Binding is successful!!!\n");
   
   valreceive=recvfrom(sockid,buffer,sizeof(buffer),0,(struct sockaddr*)&client,&client_len);
   if(valreceive<0)
       printf("There is a problem in receive!!!\n");
   else
   {
       printf("Data received successfully!!!\n");
       printf("Data received from client is %s\n",buffer);
   }
   
   close(sockid);
}
/*
OUTPUT
======
Socket creation is successful!!!
Binding is successful!!!
Data received successfully!!!
Data received from client is hello albin
*/