/*
                                                                  Program No:2.6
                                                                    TCP SEND
                                                                    ========
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
void main()
{
   int sockid,k,valsend;
   char buffer[1024];
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
       
   printf("Enter the data to send:");
   fgets(buffer,1024,stdin);
   
   valsend=send(sockid,buffer,sizeof(buffer),0);
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
Connected successfully!!!
Enter the data to send:Albin
Message sended successfully!!!
*/