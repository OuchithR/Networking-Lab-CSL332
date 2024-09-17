#include<stdio.h>
int main()
{
  int in,out,n,bsize,bucket=0;
  printf("\nEnter the outgoing rate : ");
  scanf("%d",&out);

  printf("\nEnter the bucket size : ");
  scanf("%d",&bsize);

  printf("\nEnter the number of inputs : ");
  scanf("%d",&n);

  while(n!=0)
  {
    printf("\nEnter the incoming packet size : ");
    scanf("%d",&in);

    if(in<=(bsize-bucket))
      {
        bucket+=in;
        printf("\n Bucket status : %d out of %d ",bucket,bsize);
      }
    else
      {
        printf("\nDropped packets : %d",in-(bsize-bucket));
        printf("\n Bucket status : %d out of %d ",bucket,bsize);
        bucket=bsize;
      }
    bucket = bucket-out;
    printf("\n Bucket status after outgoing : %d out of %d ",bucket,bsize);
    n--;
  }
}
