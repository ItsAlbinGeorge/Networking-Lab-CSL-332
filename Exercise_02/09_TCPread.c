/*
                                                                         Program No:2.9
                                                                            TCP READ
                                                                            ========
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
void main()
{
   int sockid,bin,lis,tempid,valread;
   char buffer[1024];
   struct sockaddr_in server;
   server.sin_family=AF_INET;
   server.sin_port=htons(8080);
   server.sin_addr.s_addr=INADDR_ANY;
   struct sockaddr_in client;
   socklen_t len;
   len=sizeof(client);
   
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
       
   lis=listen(sockid,3);
   if(lis<0)
       printf("There is a problem in listening!!!\n");
   else
       printf("Listen is successful!!!\n");
   
   tempid=accept(sockid,(struct sockaddr*)&client,&len);
   if(tempid<0)
       printf("There is a problem in accept!!!\n");
   else
       printf("Accept is successful!!!\n");
       
   valread=read(tempid,buffer,sizeof(buffer));
   if(valread<0)
       printf("There is a problem in read!!!\n");
   else
   {
       printf("Data readed successfully!!!\n");
       printf("Data readed from client is %s\n",buffer);
   }
   
   close(tempid);
   close(sockid);
}
/*
OUTPUT
======
Socket creation is successful!!!
Binding is successful!!!
Listen is successful!!!
Accept is successful!!!
Data readed successfully!!!
Data readed from client is Albin
*/