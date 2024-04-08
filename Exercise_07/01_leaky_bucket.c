/*
                                                             Program No:7
                                                        LEAKY BUCKET ALGORITHM
                                                        ======================
*/
#include<stdio.h>
void main()
{
   int n,b_size,out_rate,in_size,store=0;
   printf("Enter the bucket size:");
   scanf("%d",&b_size);
   printf("Enter the outgoing rate:");
   scanf("%d",&out_rate);
   printf("Enter the number of inputs:");
   scanf("%d",&n);
   while(n!=0)
   {
      printf("Enter the incoming packet size:");
      scanf("%d",&in_size);
      printf("Incoming packet size is %d\n",in_size);
      if(in_size<=b_size-store)
      {
         store+=in_size;
         printf("Bucket status %d out of %d\n",store,b_size);
      }
      else
      {
         printf("Dropped %d number of packets\n",in_size-(b_size-store));
         printf("Bucket status %d out of %d\n",store,b_size);
         store=b_size;
      }
      store=store-out_rate;
      printf("After outgoing, Bucket status:%d packets left out of %d\n",store,b_size);
      n--;
   }
}
/*
OUTPUT
======
Enter the bucket size:50
Enter the outgoing rate:100
Enter the number of inputs:3
Enter the incoming packet size:50
Incoming packet size is 50
Bucket status 50 out of 50
After outgoing, Bucket status:-50 packets left out of 50
Enter the incoming packet size:100
Incoming packet size is 100
Bucket status 50 out of 50
After outgoing, Bucket status:-50 packets left out of 50
Enter the incoming packet size:20
Incoming packet size is 20
Bucket status -30 out of 50
After outgoing, Bucket status:-130 packets left out of 50
*/