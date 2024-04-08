/*
                                                               Program No:3.3
                  CLIENT SERVER BIDIRECTIONAL COMMUNICATION USING SOCKET PROGRAMMING AND TCP AS TRANSPORT LAYER PROTOCOL(Server)
                                                   (Server and client on different machine)
                                                   ========================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
void main()
{
   int sockid,bin,lis,tempid,valreceive,valsend;
   char buffer[1024];
   struct sockaddr_in server;
   server.sin_family=AF_INET;
   server.sin_port=htons(8080);
   server.sin_addr.s_addr=inet_addr("192.168.2.4");
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
       
   valreceive=recv(tempid,buffer,sizeof(buffer),0);
   if(valreceive<0)
       printf("There is a problem in receive!!!\n");
   else
   {
       printf("Data received successfully!!!\n");
       printf("Data received from client is %s\n",buffer);
   }
   
   printf("Enter the data to send:");
   fgets(buffer,1024,stdin);
   
   valsend=send(tempid,buffer,sizeof(buffer),0);
   if(valsend<0)
       printf("There is a problem in sending!!!\n");
   else
       printf("Message sended successfully!!!\n");
   
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
Data received successfully!!!
Data received from client is Hello server

Enter the data to send:Hai client
Message sended successfully!!!
*/