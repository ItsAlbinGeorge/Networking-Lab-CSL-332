/*
                                                            Program No:2.5
                                                             TCP  CONNECT
                                                             ============
*/
#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
void main()
{
   int sockid,k;
   struct sockaddr_in server;
   server.sin_family=AF_INET;
   server.sin_port=htons(8080);
   server.sin_addr.s_addr=INADDR_ANY;
   
   sockid=socket(AF_INET,SOCK_STREAM,0);
   if(sockid<0)
       printf("Socket creation is not successful!!!\n");
   else
       printf("Socket creation is successful!!!\n");
       
   k=connect(sockid,(struct sockaddr*)&server,sizeof(server));
   if(k<0)
       printf("There is a problem in connect!!!\n");
   else
       printf("Connected successfully!!!\n");
}
/*
OUTPUT
======
Socket creation is successful!!!
Connected successfully!!!
*/