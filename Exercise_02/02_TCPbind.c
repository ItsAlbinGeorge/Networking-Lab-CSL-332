/*
                                                                Program No:2.2
                                                                    TCP BIND
                                                                    ========
*/
#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
void main()
{
   int sockid,bin;
   struct sockaddr_in server;
   server.sin_family=AF_INET;
   server.sin_port=htons(8080);
   server.sin_addr.s_addr=INADDR_ANY;
   
   sockid=socket(AF_INET,SOCK_STREAM,0);
   if(sockid<0)
       printf("Socket creation is not successful!!!\n");
   else
       printf("Socket creation is successful!!!\n");
       
   bin=bind(sockid,(struct sockaddr*)&server,sizeof(server));
   if(bin<0)
       printf("There is a problem in binding!!!\n");
   else
       printf("Binding is successful!!!\n");
}
/*
OUTPUT
======
Socket creation is successful!!!
Binding is successful!!!
*/