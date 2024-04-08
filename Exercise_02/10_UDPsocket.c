/*
                                                               Program No:2.10
                                                              UDP SOCKET CREATION
                                                              ===================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
void main()
{
   int sockid;
   sockid=socket(AF_INET,SOCK_DGRAM,0);
   if(sockid<0)
       printf("Socket creation is not successful!!!\n");
   else
       printf("Socket creation is successful!!!\n");
   close(sockid);
}
/*
OUTPUT
======
Socket creation is successful!!!
*/