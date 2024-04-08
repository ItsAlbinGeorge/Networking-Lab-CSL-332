/*
                                                             Program No:6
                                                        DISTANCE VECTOR ROUTING
                                                        =======================
*/
#include<stdio.h>
struct node
{
   int dist[20];
   int from[20];
}rt[10];
void main()
{
   int i,j,k,n,count=0,costmat[20][20];
   printf("Enter the number of nodes:");
   scanf("%d",&n);
   printf("Enter the cost Matrix:\n");
  for(i=0;i<n;i++)
  { 
     for(j=0;j<n;j++)
     {
        printf("Enter the cost at costmatrix[%d][%d]:",i+1,j+1);
        scanf("%d",&costmat[i][j]);
        costmat[i][i]=0;
        rt[i].dist[j]=costmat[i][j];
        rt[i].from[j]=j;
     }
  }
  do
  {
     count=0;
     for(i=0;i<n;i++)
     {
        for(j=0;j<n;j++)
        {
           for(k=0;k<n;k++)
           {
              if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j])
              {
                 rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
                 rt[i].from[j]=k;
                 count++;
              }
           }
        }
     }
  }while(count!=0);
  
  for(i=0;i<n;i++)
  {
     printf("\nFor Router%d\n***********",i+1);
     for(j=0;j<n;j++)
     {
        printf("\t\nnode %d via %d Distance %d",j+1,rt[i].from[j]+1,rt[i].dist[j]);
     }
     printf("\n");
  }
}
/*
OUTPUT
======
Enter the number of nodes:3
Enter the cost Matrix:
Enter the cost at costmatrix[1][1]:0
Enter the cost at costmatrix[1][2]:1
Enter the cost at costmatrix[1][3]:5
Enter the cost at costmatrix[2][1]:1
Enter the cost at costmatrix[2][2]:0
Enter the cost at costmatrix[2][3]:3
Enter the cost at costmatrix[3][1]:5
Enter the cost at costmatrix[3][2]:3
Enter the cost at costmatrix[3][3]:0

For Router1
***********	
node 1 via 1 Distance 0	
node 2 via 2 Distance 1	
node 3 via 2 Distance 4

For Router2
***********	
node 1 via 1 Distance 1	
node 2 via 2 Distance 0	
node 3 via 3 Distance 3

For Router3
***********	
node 1 via 2 Distance 4	
node 2 via 2 Distance 3	
node 3 via 3 Distance 0
*/