/*
                                                             Program No:5
                                                    FILE TRANSFER PROTOCOL(Client)
                                                 (Server and client on same machine)
                                                 ===================================
*/
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
void main()
{
   int sockid,k,valwrite;
   char buffer[1024],filecontent[1024];
   struct sockaddr_in server;
   server.sin_family=AF_INET;
   server.sin_port=htons(8087);
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
       
   printf("Enter the filename:");
   fgets(buffer,1024,stdin);
   
   valwrite=write(sockid,buffer,sizeof(buffer));
   if(valwrite<0)
       printf("There is a problem in sending!!!\n");
   else
       printf("Filename sended successfully!!!\n");
   
   printf("Contents of the received file is:\n");
   while(read(sockid,buffer,sizeof(buffer))!=0)
   	printf("%s ",buffer);    
       
   close(sockid);
}
/*
OUTPUT
======
Socket creation is successful!!!
Connected successfully!!!
Enter the filename:ftp_file.dat
Filename sended successfully!!!
Contents of the received file is:
This  is a file to show File Transfer Protocol


Contents of ftp_file.dat
************************
This  is a file to show File Transfer Protocol
*/