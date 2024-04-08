/*
                                                                        Program No:3.3
                        CLIENT SERVER BIDIRECTIONAL COMMUNICATION USING SOCKET PROGRAMMING AND TCP AS TRANSPORT LAYER PROTOCOL(Client)
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
   int sockid,k,valsend,valreceive;
   char buffer[1024];
   struct sockaddr_in server;
   server.sin_family=AF_INET;
   server.sin_port=htons(8080);
   server.sin_addr.s_addr=inet_addr("192.168.2.2");
   
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
       
   valreceive=recv(sockid,buffer,sizeof(buffer),0);
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
Connected successfully!!!
Enter the data to send:Hello server    
Message sended successfully!!!
Data received successfully!!!
Data received from client is Hai client
*/