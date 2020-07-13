#include <stdio.h>
#include <time.h>
int mint(int a,int b,int c)
{
  if (a<=b && a<=c)
  return a;	
  if (b<=a && b<=c)
  return b;	
  if (c<=b && c<=a)
  return c;	
}
int len_arr(int *x)
{
	//sleep (5);
	//printf("\n Entered to find the length the length of the array");
	//sleep (2);
    int count =0;
    int count0=0;
    while(count0<=2)
    {    	
        if(x[count]==0)
        count0++;
        count++;      
        if(count0==2)
         break;
    }
    //printf("\n returning the length of %d",count-2);
    //sleep (5);
   return count-2;
}
int sumt(int *x)
{
	//printf("\n entered to find the sum of the element in the array");
	//sleep (5);
	int i=0,sum=0;
	for(i=0;i<len_arr(x);i++)
	{
		sum+=x[i];
	}
	//printf("\n The sum obtained is %d",sum);
//	sleep (5);
	return (sum);
}
void shift(int *x,int v)
{     //printf("\n THE CONTROL IS INSIDE SHIFT FUNCTION AND THE VALUE WHICH NEEDS TO BE REMOVVED IS %d",v);
     int j=0;
	
	
	
   //printf("	the position of the match found is %d",i);
	for(j=0;j<len_arr(x)-1;j++)
	x[j]=x[j+1];
	x[len_arr(x)-1]=0;
      
      
	//bubbleSort(x,len_arr(x));
     
	//mediant(x);
   //	return x;
}

void trim(int *x,int sum)
{
  //	printf("\n entered the trim function where the sum of the elementsd of the arraay are %d and the SUM which we have to get is %d",sumt(x),sum);
  
  //sleep (5);
  int k=sumt(x);
  //int f=1;
  //while(f=1)
  //{
  	if(k<=sum)
  	{
  		
  		
	  //printf("\n present value of k before exiting the trim  is %d and the sum is %d",k,sum);
	  //f=0;
	  //return 1;
          }
  	else
  	{
  	//	sleep (5);
  		//printf("\n present no. of elements %d",len_arr(x));
  	
		  shift(x,x[0]);
  		//x[len_arr(x)-1]=0;
  			//printf("\n after eliminating the no of array is %d",len_arr(x));
  		k=sumt(x);
  		//printf("\n the present sum after elimaination is %d",k);
  	   trim(x,sum);
	  }
  
  //return 0;
}
	

int equalStack(int *n1,int *n2,int *n3)
{
	//printf("\n the command is inside output function");

	int sum1=sumt(n1);
	int sum2=sumt(n2);
	int sum3=sumt(n3);
	if(sum1==sum2 && sum2==sum3 && sum3==sum1)
	{ //printf("\n returning the sum value to the the main");
	return sum1;
     }
	if(sum1==0 || sum2==0  || sum3==0)
	{ //printf("\n returning the valuye of 0 to the main");
	
	return 0;
    }
	int min=mint(sum1,sum2,sum3);
	if(sum1==min)
	{   //printf("\n The sum of array N1 is least");
	//sleep (5);
	//printf("\n Going t trim N2");
		trim(n2,min);
			//printf("\n Going t trim N3");
		trim(n3,min);
	}
	else if(sum2==min)
	{    //printf("\n The sum of array N2 is least");
//	sleep (5);
   //	printf("\n Going t trim N1");
		trim(n1,min);
		//	printf("\n Going t trim N3");
		trim(n3,min);
	}
	else if(sum3==min)
	{
		//printf("\n The sum of array N3 is least");
	//	sleep (5);
		//printf("\n Going t trim N1");
		trim(n1,min);
			//printf("\n Going t trim N2");
		trim(n2,min);
	}
    return(equalStack(n1,n2,n3));
}

int main()
{
	int n1[200];
	int n2[200];
	int n3[200];
	int i=0;
	for(i=0;i<200;i++)
	n1[i]=0;
	for(i=0;i<200;i++)
	n2[i]=0;
	for(i=0;i<200;i++)
	n3[i]=0;
		int len1=0;
	//printf("\nEnter the number of elements in the n1 ");
	scanf("%d",&len1);
	//sleep (3);

	int len2=0;
		//printf("\nEnter the number of elements in the n2 ");
	scanf("%d",&len2);
	//sleep (3);
		//return 1;
	int len3=0;
		//printf("\nEnter the number of elements in the n3 ");
	scanf("%d",&len3);
//	sleep (3);
	
	//printf("\n Enter the values of n1");
	for(i=0;i<len1;i++)
	    scanf("%d",&n1[i]);
		//printf("\n Enter the values of n2");
	for(i=0;i<len2;i++)
	    scanf("%d",&n2[i]);
		//printf("\n Enter the values of n3");
	for(i=0;i<len3;i++)
	     scanf("%d",&n3[i]);
	      int outputt=equalStack(n1,n2,n3);
	printf("%d",outputt);
}

