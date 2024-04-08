/*
                                                            Program No:4.2
            CLIENT SERVER BIDIRECTIONAL COMMUNICATION USING SOCKET PROGRAMMING AND UDP AS TRANSPORT LAYER PROTOCOL(Client)
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
   int sockid,valsend,valreceive;
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
   
   valreceive=recvfrom(sockid,buffer,sizeof(buffer),0,NULL,NULL);
   if(valreceive<0)
       printf("There is a problem in receive!!!\n");
   else
   {
       printf("Data received successfully!!!\n");
       printf("Data received from server is %s\n",buffer);
   }
       
   close(sockid);
}
/*
OUTPUT
======
Socket creation is successful!!!
Enter the data to send:hello server
Message sended successfully!!!
Data received successfully!!!
Data received from server is hai client
*/