/*
                                                                    Program No:2.1
                                                                 TCP SOCKET CREATION
                                                                 ===================
*/
#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
void main()
{
   int sockid;
   sockid=socket(AF_INET,SOCK_STREAM,0);
   if(sockid<0)
       printf("Socket creation is not successful!!!\n");
   else
       printf("Socket creation is successful!!!\n");
}
/*
OUTPUT
======
Socket creation is successful!!!
*/